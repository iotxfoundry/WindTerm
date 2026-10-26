// 用 reference/symbols.tsv 为 Ghidra 项目批量改名（此后反编译输出带真实名）
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.listing.*;
import java.io.*;

public class RenameSymbols extends GhidraScript {
    public void run() throws Exception {
        String tsv = getScriptArgs()[0];
        int renamed = 0, skipped = 0;
        BufferedReader br = new BufferedReader(new FileReader(tsv));
        String line;
        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty() || line.startsWith("#")) continue;
            String[] p = line.split("\t");
            if (p.length < 2) continue;
            Address a = currentProgram.getAddressFactory().getAddress(p[0]);
            String name = p[1];
            Function f = getFunctionAt(a);
            try {
                if (f != null) {
                    f.setName(name, SourceType.USER_DEFINED);
                } else {
                    createLabel(a, name, true);
                }
                renamed++;
            } catch (Exception e) {
                skipped++;
                println("SKIP " + p[0] + " " + name + " : " + e.getMessage());
            }
        }
        br.close();
        println("RENAMED=" + renamed + " SKIPPED=" + skipped);
    }
}
