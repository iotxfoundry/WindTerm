import java.net.URL;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.Map;

import ghidra.app.script.GhidraScript;
import ghidra.features.bsim.query.BSimClientFactory;
import ghidra.features.bsim.query.FunctionDatabase;
import ghidra.features.bsim.query.description.DatabaseInformation;
import ghidra.features.bsim.query.description.DescriptionManager;
import ghidra.features.bsim.query.description.ExecutableRecord;
import ghidra.features.bsim.query.description.FunctionDescription;
import ghidra.features.bsim.query.file.BSimH2FileDBConnectionManager;
import ghidra.features.bsim.query.protocol.InsertRequest;
import ghidra.features.bsim.query.protocol.QueryNearest;
import ghidra.features.bsim.query.protocol.ResponseNearest;
import ghidra.features.bsim.query.protocol.SimilarityNote;
import ghidra.features.bsim.query.protocol.SimilarityResult;
import ghidra.framework.model.DomainFile;
import ghidra.framework.protocol.ghidra.GhidraURL;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;

//@category BSim

/**
 * Headless BSim 双模式：add（当前程序签名入库）/ apply（FUN_ 函数查询应用 BSim_<参考名>）。
 * 用法（analyzeHeadless -postScript）：
 *   BSimApply.java add    <h2db file:/path/x.hdb>
 *   BSimApply.java apply  <h2db file:/path/x.hdb> [相似度阈值=0.7] [显著性阈值=5.0]
 */
public class BSimApply extends GhidraScript {

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            println("用法: add <db> | apply <db> [simThresh=0.7] [sigThresh=5.0]");
            return;
        }
        String mode = args[0];
        java.net.URL dbUrl = BSimClientFactory.deriveBSimURL(args[1]);
        try (FunctionDatabase db = BSimClientFactory.buildClient(dbUrl, false)) {
            if (!db.initialize()) {
                println("DB init failed: " + db.getLastError().message);
                return;
            }
            DatabaseInformation info = db.getInfo();
            ghidra.features.bsim.query.GenSignatures gensig =
                new ghidra.features.bsim.query.GenSignatures(info.trackcallgraph);
            try {
                gensig.setVectorFactory(db.getLSHVectorFactory());
                gensig.addExecutableCategories(info.execats);
                gensig.addFunctionTags(info.functionTags);
                gensig.addDateColumnName(info.dateColumnName);
                DomainFile dFile = currentProgram.getDomainFile();
                URL fileURL = dFile.getSharedProjectURL(null);
                if (fileURL == null) {
                    fileURL = dFile.getLocalProjectURL(null);
                }
                String repo = GhidraURL.getProjectURL(fileURL).toExternalForm();
                gensig.openProgram(currentProgram, null, null, null, repo, "/");

                if ("add".equals(mode)) {
                    FunctionManager fman = currentProgram.getFunctionManager();
                    gensig.scanFunctions(fman.getFunctions(true), fman.getFunctionCount(), monitor);
                    DescriptionManager manager = gensig.getDescriptionManager();
                    manager.listAllFunctions().forEachRemaining(fd -> fd.sortCallgraph());
                    InsertRequest req = new InsertRequest();
                    req.manage = manager;
                    if (req.execute(db) == null) {
                        println("Insert failed: " + db.getLastError().message);
                        return;
                    }
                    println("ADDED signatures: " + manager.numFunctions());
                }
                else if ("apply".equals(mode)) {
                    double simThresh = args.length > 2 ? Double.parseDouble(args[2]) : 0.7;
                    double sigThresh = args.length > 3 ? Double.parseDouble(args[3]) : 5.0;
                    FunctionManager fman = currentProgram.getFunctionManager();
                    // 只查未具名函数；同签名（重复模板实例）会被 BSim 合并，
                    // 应用名时按源函数地址对齐
                    Map<Long, Function> todo = new LinkedHashMap<>();
                    for (Function f : fman.getFunctions(true)) {
                        if (f.getName().startsWith("FUN_") && !f.isThunk()) {
                            todo.put(f.getEntryPoint().getOffset(), f);
                        }
                    }
                    println("FUN_ candidates: " + todo.size());
                    // scanFunctions 全量后过滤查询结果
                    gensig.scanFunctions(fman.getFunctions(true), fman.getFunctionCount(), monitor);
                    DescriptionManager manager = gensig.getDescriptionManager();
                    QueryNearest query = new QueryNearest();
                    query.manage = manager;
                    query.max = 3;
                    query.thresh = simThresh;
                    query.signifthresh = sigThresh;
                    ResponseNearest resp = query.execute(db);
                    if (resp == null) {
                        println("Query failed: " + db.getLastError().message);
                        return;
                    }
                    int applied = 0;
                    int multiBest = 0;
                    Iterator<SimilarityResult> it = resp.result.iterator();
                    while (it.hasNext()) {
                        SimilarityResult sim = it.next();
                        FunctionDescription base = sim.getBase();
                        long addr;
                        try {
                            addr = base.getAddress();
                        }
                        catch (Exception e) {
                            addr = -1;
                        }
                        Function src = addr >= 0 ? todo.get(addr) : null;
                        if (src == null) {
                            continue; // 已具名函数的匹配（参考侧）跳过
                        }
                        Iterator<SimilarityNote> notes = sim.iterator();
                        SimilarityNote best = null, second = null;
                        while (notes.hasNext()) {
                            SimilarityNote n = notes.next();
                            if (best == null || n.getSignificance() > best.getSignificance()) {
                                second = best;
                                best = n;
                            }
                        }
                        if (best == null) {
                            continue;
                        }
                        // 唯一性：第二名显著低于第一名才算数
                        if (second != null && second.getSignificance() > best.getSignificance() * 0.9) {
                            multiBest++;
                            continue;
                        }
                        FunctionDescription ref = best.getFunctionDescription();
                        ExecutableRecord exe = ref.getExecutableRecord();
                        String refName = ref.getFunctionName();
                        if ("FUN_".startsWith(refName) || refName.startsWith("FUN_") ||
                            refName.startsWith("thunk_") || refName.startsWith("_") ||
                            refName.equals("_init") || refName.equals("_fini") ||
                            refName.startsWith("frame_dummy") ||
                            refName.startsWith("__do_global_dtors") ||
                            refName.startsWith("register_tm_clones") ||
                            refName.startsWith("deregister_tm_clones")) {
                            continue;
                        }
                        String newName = "BSim_" + refName.replaceAll("[^A-Za-z0-9_:]", "_");
                        try {
                            src.setName(newName, ghidra.program.model.symbol.SourceType.ANALYSIS);
                            src.setComment("BSim sim=" + best.getSimilarity() + " sig=" +
                                best.getSignificance() + " ref=" + exe.getNameExec() + "::" + refName);
                            applied++;
                        }
                        catch (Exception e) {
                            // 重名等冲突跳过
                        }
                    }
                    println("APPLIED: " + applied + " (ambiguous skipped: " + multiBest + ")");
                }
            }
            finally {
                gensig.dispose();
            }
        }
    }
}
