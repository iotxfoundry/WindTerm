// 段 8 跳选行为门测试(批 100 批 C 风险裁决:s_wordStep 单字节 docBytes
// 承载下词类恒 0 → 单步近似恒等 —— 本批行为门裁决)。
// 铁律 5:断言语料行为,每条断言带语料锚;逐条手工写。
//
// 语料锚(Ghidra 基址;decomp-part-0032.c / decomp-part-0034.c):
//   FUN_00a2de1c(1663B)@0034:9644 — 游标落点搜索。段 8 边界校验腿 =
//   LAB_00a2e406(9838):界内 → 命中腿移选区(9807/9819/9832/9837 →
//   LAB_00a2e159/2ed,9826);界外 → FUN_00925304(doc,candEnd,±1)
//   跳选单步(9843;返回值即弃)+ cc=2→1(9846/9850)内环重入登记。
//   后向包夹 9803-9819(00a1ff9c→0096bbc0 selStart / 00a20050→selEnd);
//   前向包夹 9829-9837。段 7 门 9774-9800(force/flags&8/docLen<1)。
//   FUN_00925304(12B)@0030:20331 thunk → FUN_009988e2(176B)@0032:28889
//   (n 步跳词:首步 0xffffffff 回咬 28908 + 逐步跳 28910/界钳
//   28911-28918);FUN_0099881e(196B)@0032:28849 — 单步基元
//   (advance 28859 / 词类 28860 / 连跳环 28861-28869 / CRLF 尾
//   28872-28876 / 界钳 28878-28884)。
//   FUN_00998678(298B)@0032:28760 — 词类宽度:28775 表空门 / 28778
//   byteAt(009284aa)/ 28779 多字节臂(28780-28816 宽度表查 —
//   cited — wave-2)/ 28818 ASCII 早退返 0。
//
// 语料行号补记:上述 9xxx/130xx/127xx 行号均为 decomp-part-0034.c
// (FUN_00a2de1c/editor_replaceText)/decomp-part-0027.c 语料行;
// 段 B/段 D 转写行号(3047/3052/3062-3101)为 EditorEngine.cpp 行。
//
// 裁决(批 100 批 C 风险项,本门登记):
//   ① s_wordStep/s_wordClass 为 EditorEngine.cpp 文件级 static(内部
//      链接,无公有面)→ 仅可经 dispatch(0x4f00) 段 8 间接激活。
//   ② 段 8 在当前占位下运行时不可达:canOld = FUN_0089a756 占位恒真
//      (CodecMemo.cpp:63-72;s_codecMemo.codec=nullptr → 针 null →
//      true)→ 针搜腿 FUN_0092547e cited 恒 -1(CodecMemo.cpp:256-264 →
//      MatchEngine.cpp:155-161 bufferScan00b422d0 cited 返 -1)→ 语料
//      9852-9858 恒 step → 段 7/8 界面(LAB_00a2e0c1)永不达;掩码腿
//      (canOld=false)亦不可注入:0x4f00 段 A 载体 needleCar 首八字 =
//      literal 0x01(伪指针)→ scanMask 2626d 解引即崩腿。
//      → "wordClass 恒 0 → wordStep 每步 ±1(CRLF ±1 / 界钳 [0,len])
//      恒等近似"在转写层成立(EditorEngine.cpp:95-137,语料锚齐),
//      运行时断言随搜索/codec 引擎落地批(段 8 激活)补门 — 本批
//      登记,不虚构(铁律 3)。
//   ③ 本文件钉住 0x4f00 可达前缀契约(回归绊线:段 8 一旦激活,
//      命中腿移选区 9826 / 界外单步 9843 将破坏下列不变量):
//      返回 -1 / hits(op+0x3c)不污染 / 选区不变量 / 段 F 懒建
//      (flags&8,13057-13089)/ 重试标记(flags&0x20 → op+0x38|=4,
//      13050 — 真身可达腿)。
//
// 测试专用可达缝:#define private public 仅本 TU(markerstest 同款;
// EditorEngine/EditorContext 均无 Q_OBJECT,不触发 moc ABI 面)。
#define private public
#include "EditorEngine.h"
#include "CodecMemo.h"   // 批 118 g 组:scanMask 直呼(0x448 契约钉住)
#include "MatchEngine.h" // 批 119 h 组:engDispatch 活性腿直验(vt 槽真身)
#undef private
#include "Scintilla.h"
#include <QApplication>
#include <cstdio>
#include <cstring>
#include <stddef.h>

static int g_fail = 0;
static void expect(bool ok, const char *name)
{
	printf("%s: %s\n", ok ? "OK" : "FAIL", name);
	if (!ok)
		g_fail++;
}

// ============ 夹具:ReplaceOp 桥面缓冲(0x4f00 case 头 toULongLong 桥面;
//               语料 op 体偏移直读:EditorEngine.cpp:3006-3013)============
struct OpBridge {
	quint8  pad00[0x0c];   // +0x00..+0x0b(语料自旋锁/+0x08 区;桥面未消费)
	quint32 flags;         // +0x0c(段 7 门 bit3 / 段 C bit4 / 重试门 bit5)
	quint8  type;          // +0x10(12792 bVar1;12793 selMode = (type&0xfd)==1)
	quint8  pad11[0x38 - 0x11];
	quint8  retryMark;     // +0x38(13050 *(op+0x38)|=4 重试标记)
	quint8  pad39[3];
	quint32 hits;          // +0x3c(9781/12659 命中计数 ++ 面)
};
static_assert(offsetof(OpBridge, flags) == 0x0c, "op+0x0c flags");
static_assert(offsetof(OpBridge, type) == 0x10, "op+0x10 type");
static_assert(offsetof(OpBridge, retryMark) == 0x38, "op+0x38 重试标记");
static_assert(offsetof(OpBridge, hits) == 0x3c, "op+0x3c 命中计数");

// 预填 ASCII 文档 + 选区夹具(载体 docBytes ≡ FUN_0092801a 长度面适配,
// markerstest m 组同款;真选区面 = 委托真 Scintilla,段 D/段 E send 承接)
static void fillAscii(EditorEngine &e, const char *text, qint64 selA,
                      qint64 selB)
{
	e.m_ctx.docBytes = QByteArray(text);
	e.dispatch(SCI_ADDTEXT, (qlonglong)strlen(text), QByteArray(text));
	if (selB > selA)
		e.dispatch(SCI_SETSEL, selA, selB);
}

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	// ======== a. 桥面守卫(0x4f00 case 头;EditorEngine.cpp:3009-3010)========
	// 语料:opb = a.toULongLong();我方空判早退(非语料行为 — 登记,
	//   取语料早退值 -1 同形;宿主桥未建对象时壳期安全面)。
	{
		EditorEngine e;
		expect(e.dispatch(0x4f00) == QVariant((qlonglong)-1),
		       "a: opb=null → -1(3009-3010 我方守卫登记;非语料行为)");
	}

	// ======== b. 空文档 type=3 走查(任务要点 ①:不崩 + 返回占位)========
	// 语料链(全可达前缀):12792 type 读 → 12793 selMode=(3&0xfd)==1
	//   → true(前向)→ 12816 canOld 占位恒真(CodecMemo.cpp:63-72)
	//   → 12820 oldLen=1 门不触发 → 段 B textLen=0 → runlist=[{n0=0,
	//   n1=0}](3047-3052)→ 段 E pos=selEnd=0 → lambda 前向 idx=0:
	//   段 4 前向门 9756-9763(hi=re_=0,cur=0<=0 → enter)→ 段内体:
	//   9851-9853 FUN_0092547e cited 恒 -1 → LAB_00a2e1c6 步进 9867-9872
	//   → 扫尽 return -1。段 7/8(LAB_00a2e0c1 界面)不达 — 命中计数/
	//   选区移置/界外单步全死(裁决 ②)。
	{
		EditorEngine e;
		OpBridge op{};                               // 值初始化全零
		op.type = 3;                                 // 12793 selMode=true(前向)
		QVariant r = e.dispatch(
		    0x4f00, QVariant((qlonglong)(quintptr)&op));
		expect(r == QVariant((qlonglong)-1),
		       "b: 空文档 type=3 → -1(9851-9853 searchNeedle cited 恒 -1"
		       " → 步进 9867-9872 扫尽)");
		expect(op.hits == 0,
		       "b: hits(op+0x3c)==0(9781 命中腿 ++ 不达 — 段 7/8 死路登记)");
		expect(e.dispatch(SCI_GETSELECTIONSTART) == QVariant(0)
		       && e.dispatch(SCI_GETSELECTIONEND) == QVariant(0),
		       "b: 选区 (0,0) 不变(9826 命中移选区 FUN_00a20eb2 cited 不达)");
		expect(e.m_ctx.docBytes.isEmpty(),
		       "b: docBytes 空态不变(9843 界外单步返回值即弃 — 不写 doc;"
		       "死路登记下壳态同相)");
	}

	// ======== c. 预填 ASCII "abc" + 选区 [0,2) 走查(任务要点 ②)========
	// 语料链:段 B textLen=3(runnode_init(3,0,0)/runnode_init(0,0,0),
	//   3047-3052)→ 段 D 含选区门 12978(rs=n0.pos=3<=selStart=0 false
	//   → 不触发)→ 段 E pos=selEnd=2 → lambda 段 4 前向门 9756-9763:
	//   hi=re_=0,cur=2<=0 false → enter=false → 步出 9863-9872 → -1。
	//   段 8 界外腿(9838→9843)若激活:单字节 wordClass 恒 0(28818
	//   ASCII 早退 / 28780-28816 宽度表 cited → 0)→ wordStep 每步 ±1
	//   (CRLF 尾 28872-28876 ±1 / 界钳 28878-28884 [0,len])→ 恒等
	//   近似 — 返回值即弃(9843)→ doc/选区均不被破坏;当前死路 →
	//   不变量同相成立。
	{
		EditorEngine e;
		fillAscii(e, "abc", 0, 2);
		OpBridge op{};
		op.type = 3;
		QVariant r = e.dispatch(
		    0x4f00, QVariant((qlonglong)(quintptr)&op));
		expect(r == QVariant((qlonglong)-1),
		       "c: 预填 abc+选区[0,2) → -1(段 4 前向门 9756-9763"
		       " cur=2>hi=0 → 步出 9863-9872)");
		expect(e.dispatch(SCI_GETSELECTIONSTART) == QVariant(0)
		       && e.dispatch(SCI_GETSELECTIONEND) == QVariant(2),
		       "c: 选区 [0,2) 不变(9829-9837 前向包夹/9843 界外单步均"
		       "不达 — 语料 9843 返回值即弃 → 选区状态不被破坏)");
		expect(op.hits == 0,
		       "c: hits==0(9781 命中腿不达;段 8 激活后此断言应随"
		       "命中腿行为批重审 — 登记绊线)");
		expect(e.m_ctx.docBytes == QByteArray("abc"),
		       "c: docBytes 保持 \"abc\"(单字节恒等近似的载体不变量;"
		       "9843 即弃锚 — wordStep 不写 doc)");
	}

	// ======== c2. 后向 type=2 走查(selMode 假臂 — 后向包夹载体)========
	// 语料:12793 selMode=(2&0xfd)==1 → false(后向);type!=3 → 段 B
	//   runlist 空 → lambda 后向 9678-9681 idx=size-1=-1 → return -1。
	//   后向包夹(9803-9819)经 0x4f00 type 载体不可与非空 runlist 并存
	//   (runlist 仅 type==3 建,type==3 又恒前向)— 互斥死路登记
	//   (铁律 2 不修;后向界面激活须 runlist 源改 flags&0x10 extras,
	//   12927-12934 — 随搜索/codec 引擎批一并可达)。
	{
		EditorEngine e;
		fillAscii(e, "abc", 1, 2);
		OpBridge op{};
		op.type = 2;                                 // selMode 假臂(后向)
		QVariant r = e.dispatch(
		    0x4f00, QVariant((qlonglong)(quintptr)&op));
		expect(r == QVariant((qlonglong)-1),
		       "c2: type=2 后向登记 → -1(9678-9681 idx=-1;runlist 空"
		       " — 后向包夹 9803-9819 不可构造,登记)");
		expect(e.dispatch(SCI_GETSELECTIONSTART) == QVariant(1)
		       && e.dispatch(SCI_GETSELECTIONEND) == QVariant(2),
		       "c2: 选区 [1,2) 不变(段 D/命中腿均不达 — type!=3 门)");
	}

	// ======== d. flags&8 段 E/F 腿(0x4f00 可达的最深状态写入)========
	// 语料:13057-13061 段 F 懒建门(flags&8)→ 13063-13075 store 懒建
	//   (selStoreOn 置位)+ 13082-13089 锚 7 long 写回;段 E flags&8 腿
	//   13035-13044:anchor = store 锚(默认 {-1,-1})→ pos = anchor
	//   .n0.pos = -1(13044 FUN_0096c18e)→ lambda 前向段 4:cur=-1<=
	//   re_=0 true → lo=(rs<cur)?cur:rs=0 → enter=(0<=0) true → 段内体
	//   9851-9853 cited 恒 -1 → 步出 → -1。命中腿门 9777(flags&8 同
	//   force 腿)不达 — hits 不污染。
	{
		EditorEngine e;
		OpBridge op{};
		op.type = 3;
		op.flags = 8;                                // bit3 → 段 E/F 腿
		QVariant r = e.dispatch(
		    0x4f00, QVariant((qlonglong)(quintptr)&op));
		expect(e.m_ctx.selStoreOn == true,
		       "d: flags&8 → selStoreOn 置位(13057-13061 懒建门真身)");
		expect(e.m_ctx.selStore.anchor.n0.pos == -1
		       && e.m_ctx.selStore.anchor.n1.pos == -1,
		       "d: anchor {-1,-1}(13012 锚初始化 + 13082-13089 写回;"
		       "FUN_0096bd82 a=b={-1} 同相)");
		expect(r == QVariant((qlonglong)-1),
		       "d: flags&8 → -1(9756-9763 enter 真 → 9851-9853 恒未"
		       "命中 → 步出)");
		expect(op.hits == 0,
		       "d: flags&8 命中腿门(9777)不达 → hits==0(段 7 死路登记)");
	}

	// ======== d2. flags&0x20 重试门(13047-13061;真身可达腿)========
	// 语料:13045 首扫 -1 → 13047-13049 重试门(flags&0x20)→ 13050
	//   *(op+0x38)|=4(真身写入 — 本组核心断言)→ 13052-13058 selMode
	//   ==0 → pos = FUN_0092801a 长度面(docBytes.size();空文档 = 0)
	//   → 13059-13061 二次 force 调 → 段内体仍死于 9851-9853 → -1。
	{
		EditorEngine e;
		OpBridge op{};
		op.type = 3;
		op.flags = 0x20;                             // bit5 → 重试门
		QVariant r = e.dispatch(
		    0x4f00, QVariant((qlonglong)(quintptr)&op));
		expect((op.retryMark & 4) != 0,
		       "d2: op+0x38 |=4 置位(13050 重试标记真身 — 可达腿)");
		expect(r == QVariant((qlonglong)-1),
		       "d2: 重试后仍 -1(13059 二次 force 调 → 9851-9853 恒"
		       "未命中;force 不越过搜索腿 — 9777 界面仅命中后可达)");
		expect(op.hits == 0,
		       "d2: force 重试命中腿(9778-9793)不达 → hits==0");
	}

	// ======== e. 段 8 包夹判定外层契约(任务要点 ③;死路登记下的 ========
	// ========      回归绊线:三选区构型 × 语料 9803-9819/9829-9837)====
	// 语料包夹语义:后向(9803-9819)selStart>cand 或 selEnd>candEnd →
	//   界内命中(9826 移选区);否则 LAB_00a2e406 界外 → 9843 单步 +
	//   cc=2→1(9850)。前向(9829-9837)对称(selStart<cand /
	//   selEnd<candEnd → 界内)。当前搜索腿死 → cand 恒不存在 → 两腿
	//   均不可构造;下列断言钉住外层契约(返回/选区不变量):段 8 一旦
	//   激活,界内构型应触发移选区(破坏不变量)、界外构型应触发单步
	//   (cc=2→1 登记腿)— 断言即绊线。
	{
		// e1 覆盖构型(界内侧):sel=[0,3) 全覆盖候选域;前向
		//   (selMode 真)pos=selEnd=3 > re_=0 → 段 4 enter=false
		EditorEngine e;
		fillAscii(e, "abc", 0, 3);
		OpBridge op{};
		op.type = 3;
		QVariant r = e.dispatch(
		    0x4f00, QVariant((qlonglong)(quintptr)&op));
		expect(r == QVariant((qlonglong)-1),
		       "e1: 覆盖构型 sel=[0,3) → -1(9803-9819 包夹界面不达;"
		       "段 4 cur=3>hi=0 → 步出)");
		expect(e.dispatch(SCI_GETSELECTIONSTART) == QVariant(0)
		       && e.dispatch(SCI_GETSELECTIONEND) == QVariant(3),
		       "e1: 选区 [0,3) 不变(界内命中腿 9826 移选区 — 激活后"
		       "必破坏此断言,绊线登记)");
	}
	{
		// e2 界外构型:sel=[1,2) 完全落于候选域外
		EditorEngine e;
		fillAscii(e, "abc", 1, 2);
		OpBridge op{};
		op.type = 3;
		QVariant r = e.dispatch(
		    0x4f00, QVariant((qlonglong)(quintptr)&op));
		expect(r == QVariant((qlonglong)-1),
		       "e2: 界外构型 sel=[1,2) → -1(9838 e406 界面不达;"
		       "9843 单步/cc=2→1 登记腿 — 激活后应触发,当前死)");
		expect(e.dispatch(SCI_GETSELECTIONSTART) == QVariant(1)
		       && e.dispatch(SCI_GETSELECTIONEND) == QVariant(2),
		       "e2: 选区 [1,2) 不变(界外单步即弃锚 9843 — 选区不变量)");
	}
	{
		// e3 段 D 互斥登记:type!=3 → runlist 空 → 前向包夹载体缺失
		EditorEngine e;
		fillAscii(e, "abc", 0, 1);
		OpBridge op{};
		op.type = 1;                                 // selMode 真臂+段 B 空
		QVariant r = e.dispatch(
		    0x4f00, QVariant((qlonglong)(quintptr)&op));
		expect(r == QVariant((qlonglong)-1),
		       "e3: type=1 前向登记 → -1(9884-9886 size==0;段 B 空"
		       "runlist — 前向包夹 9829-9837 需 type=3 建表,载体互斥"
		       "外此构型仅登记)");
		expect(e.dispatch(SCI_GETSELECTIONSTART) == QVariant(0)
		       && e.dispatch(SCI_GETSELECTIONEND) == QVariant(1),
		       "e3: 选区 [0,1) 不变(段 D/命中腿均不达 — type!=3 门)");
	}

	// ======== f. 段 D notify 挂点走查(观测缝 selStoreOn 预置)========
	// 语料:段 D 逐 run 腿 12939-13011:type==3 → send 选区 → 12978
	//   含选区门(rs<=selStart && selEnd<=re_)。空文档 run={n0=0,n1=0}
	//   + 空选区 (0,0) → 门真 → delLen=0 → 12987 1:1 守卫恒真 →
	//   insLen=0 → 12998-13005 notify 挂点(selStart,0,0)。vt8 平移面
	//   (EditorContext.h:347-367):anchor {-1} 无效 → 跳;extras 空 →
	//   零遍历 → store 不变(no-op 同相)。
	{
		EditorEngine e;
		e.m_ctx.selStoreOn = true;                   // 观测缝:启用 vt8 面
		OpBridge op{};
		op.type = 3;
		QVariant r = e.dispatch(
		    0x4f00, QVariant((qlonglong)(quintptr)&op));
		expect(e.m_ctx.selStore.extras.isEmpty()
		       && e.m_ctx.selStore.anchor.n0.pos == -1
		       && e.m_ctx.selStore.anchor.n1.pos == -1,
		       "f: 段 D 门真(12978:0<=0&&0<=0)→ notify(0,0,0) → "
		       "anchor {-1}/extras 空 不变(12998-13005 挂点 cited 面 "
		       "no-op 同相)");
		expect(r == QVariant((qlonglong)-1),
		       "f: 段 D 后 lambda 走查同 b → -1(9851-9853 死路同锚)");
	}

	// ======== g. scanMask 掩码腿直呼(批 118;needlePair 契约钉住)========
	// 语料:FUN_0092a596(467B)@0030:26261;2626c lVar4 = *param_4 —
	//   param_4 = wrapper 槽,解引一次得针对象(0x4eff 12006 调用点传
	//   &local_88 = FUN_0089a0a0 出参槽同形);0x4f00 段 5/0x4eff 掩码
	//   臂 EditorEngine 载体 needleCar 首八字 = literal(值字节)→
	//   直呼即伪指针 — 语料路径本体不入 wrapper 解引面(批 100 裁决②
	//   同锚)。批 116b 契约:针对象 = 单层指针,wrapper→针恰一次解引。
	{
		// g1 wrapper 形态:pair[0] = &needle(语料 2626c 单次解引)
		GrepNeedle448 needle{};                      // 壳态:len=0 literal=1
		const void *pair[1] = { &needle };
		expect(CodecMemo::scanMask(pair, 0, 8) == -1,
		       "g1: len=0 → -1(26272 nlen<=0 门真身)");
		// g2 正常针 + 占位引擎:唯一安全直呼构型 = 首扫即哨兵(engScan
		//   34634 to<=from 门先于 engVt50Block/表解引 — tbl 承载为
		//   convCtor cited 空(null),越门构型必崩:原版表由编码器
		//   折叠面/广播面填充,占位零值不可解引 — 占位活性不可达
		//   同相证明:两产品调用面均门先行,0x4f00 len=0(26272)/
		//   0x4eff 针 null(12665),表腿永不达)
		needle.len = 2;
		needle.allowedBits = 0;                      // 262b4 门恒收(不达)
		expect(CodecMemo::scanMask(pair, 0, 1) == -1,
		       "g2: scanEnd=to-(nlen-1)<=from → -1(26274/34634 边界哨兵"
		       "先于引擎表腿;表 null 承载占位 — convCtor cited 面)");
		// g3 区间界(非 case 档 caseFlag=0 → 双表 literal 引擎 3830d;
		//   同哨兵序)
		needle.len = 16;
		expect(CodecMemo::scanMask(pair, 4, 16) == -1,
		       "g3: to-(nlen-1)<=from → -1(26274 scanEnd 边界;engScan "
		       "34634 门同相)");
	}

	// ======== h. vt 槽真身直呼(批 119 转储定案;engScan 承载直验)========
	// 语料:buffer vtable .data.rel.ro 转储 + ctor imm/typeinfo 两源
	//   (MatchEngine.cpp 批 119 头注;decomp-part-0032.c 槽行号)。
	//   MatchEngine 内部 static 无公有面 → 经 engDispatch 活性腿直验:
	//   针 simdBlocks 手填(literal=1 短针 3632d 单表腿;blockquote =
	//   engVt50Block 真身 16B 读),断言命中位/步进越过 34634 门 —
	//   modAttachRunFace 装置判例(语料构造腿 cited → 装置注入)。
	{
		// h1 block16 直验:charAt/block16 越界→0(00981b2a :10583
		//   DAT_011c26b1 面 / 00982212 尾填 0)
		GrepNeedle448 needle{};                      // 壳态
		needle.literal = 1;
		needle.len = 1;
		const char docBytes[] = {'a'};
		QByteArray doc(docBytes, 1);
		needle.simdBlocks = new char[0x10]();        // 单字节广播 'a'(54430 形)
		for (int i = 0; i < 0x10; ++i)
			static_cast<char *>(needle.simdBlocks)[i] = 'a';
		// 首窗 = doc[0]='a' == tbl[0]='a' → lane0 命中 nlen=1 → tail:
		// pack = hi16<<0x30 | 0(命中位 0 + 窗 0)
		const quint64 p1 = MatchEngine::engDispatch(&doc, &needle, 0, 1);
		expect(p1 == (quint64(1) << 0x30),
		       "h1: 1B doc 'a' 单字节针 → lane0 命中(3632d lane0 34639/"
		       "vt+0x50 真身 16B 读;36125 tail pack hi16=1)");
		// h2 非命中:'b' 针 → lane0 掩码 0 → miss 步进 pos+=0x10 → 34634
		//   门 to(1)<=from(0x10) → 哨兵
		static_cast<char *>(needle.simdBlocks)[0] = 'b';
		for (int i = 1; i < 0x10; ++i)
			static_cast<char *>(needle.simdBlocks)[i] = 'b';
		const quint64 p2 = MatchEngine::engDispatch(&doc, &needle, 0, 1);
		expect(p2 == Q_UINT64_C(0xffffffffffff),
		       "h2: 'b' 针 1B doc → miss 34673 → 36216 步进 → 34634 门 →"
		       "哨兵(vt+0x50 真身承载下 engScan 全活性)");
		// h3 skip 腿 charAt 真身:2B 针 len>=2 走 lane1(+0x10 门 36124 前
		//   lane1=doc 越界 → 0 → 掩码 0 → miss);UseSkip 腿(36cf1)经
		//   vt+0x28 charAt(nlen+pos+0xf=0x21 越界→0)→ skip[0]=2 →
		//   from=0x10+0xf=0x1f → 门 → 哨兵(有界推进,无整型回卷)
		needle.len = 2;
		needle.skip['b'] = 2;                        // convCtor 54445 覆写形
		const quint64 p3 = MatchEngine::engDispatch(&doc, &needle, 0, 0x40);
		expect(p3 == Q_UINT64_C(0xffffffffffff),
		       "h3: len=2 'b' 针 1B doc → 36cf1 skip 腿:vt+0x28 charAt"
		       "(0x21)越界→0(批 119 真身)→ skip[0]=2 有界推进 → 哨兵");
		delete[] static_cast<char *>(needle.simdBlocks);
	}

	// ======== i. scanMask 活性接线(批 127;+0xf8 buffer 承载建模)========
	//   语料:engDispatch 消费者 = CodecMemo::scanMask(FUN_0092a596
	//   26276/26314 *param_1+0xf8 解引);载体 ctor = editor_engineCtor
	//   00929fdd..00929fe1(buffer32 即建)/ 置换 0x755b(00927f16)/
	//   拆链 0092f852。我方 RAII:EditorContext ctor 挂线 &docBytes。
	{
		EditorContext ctx;
		expect(ctx.superBufferAttached
		       && ctx.scanLineDoc() == static_cast<const void *>(&ctx.docBytes),
		       "i1: ctor 挂线(00929fe1 面)→ scanLineDoc = &docBytes"
		       "(批 119 vt 槽真身承载;真载体活性)");
		// 活性穿透:engDispatch(null,…) → 缝承接 → docBytes 直读
		ctx.docBytes = QByteArray("xab");            // 3B 载体
		GrepNeedle448 needle{};                      // literal=1 短针腿
		needle.len = 1;
		needle.simdBlocks = new char[0x10]();        // 'b' 单字节广播
		for (int i = 0; i < 0x10; ++i)
			static_cast<char *>(needle.simdBlocks)[i] = 'b';
		// 首窗 [x,a,b,0…]:lane2='b' 命中 → nlen=1 → tail:hi16=bit2,
		// lo48=窗 0(262b0 = lane+lo48 消费面)
		const quint64 pi = MatchEngine::engDispatch(
		    static_cast<const void *>(nullptr), &needle, 0, 3);
		expect(pi == (quint64(4) << 0x30),
		       "i2: engDispatch(null)→ 缝承接 &docBytes → 'b'@2 lane2 命中"
		       "(scanMask 产品调点真活性;36125 tail pack hi16=4)");
		// skip 腿活性(charAt 真身,批 119 对账):36cf1 长针
		needle.len = 2;
		needle.skip['x'] = 2;                        // convCtor 覆写形
		// convCtor 54421 广播面:len<<4 = 0x20B(每 lane 16B 全 'x');
		//   批 128 勘误:旧只填 0x10 → lane1 表越界读堆(36265
		//   tbl0+0x10)→ 断言时好时坏(批 126 transient 真因定位)
		delete[] static_cast<char *>(needle.simdBlocks);
		needle.simdBlocks = new char[0x20]();
		for (int i = 0; i < 0x20; ++i)
			static_cast<char *>(needle.simdBlocks)[i] = 'x';
		// 首窗 [x,a,…]:lane0='x' 命中,lane1='a'≠'x'(tbl1 全 'x')
		// → 掩码 0 → miss → vt+0x28 charAt(2+0+0xf=0x11 越界)→ 0 →
		// skip[0]=2 → from=0x11+0xf=0x20 → 门(0x20>=3)→ 哨兵
		{
			needle.skip[0] = 2;
			const quint64 ps = MatchEngine::engDispatch(
			    static_cast<const void *>(nullptr), &needle, 0, 3);
			expect(ps == Q_UINT64_C(0xffffffffffff),
			       "i3: 36cf1 skip 腿活性:charAt(0x11)越界→0 → skip[0]=2"
			       "有界推进 → 哨兵(批 119 CALIBRATION 对账)");
		}
		delete[] static_cast<char *>(needle.simdBlocks);
		{
			MatchEngine::detachScanCarrier();    // 0092f852 拆链面直验
			EditorContext d;                     // ctor 00929fe1 面 → 重挂(缝活性)
			MatchEngine::detachScanCarrier();    // 再拆 → 壳态
			expect(ctx.scanLineDoc() == nullptr,
			       "i4: detachScanCarrier(0092f852 拆链)→ 缝 null → "
			       "engDispatch(null)回壳态守卫");
			// 拆链后 null 壳态:1B doc 'a' 无载体 → 恒零块 → miss
			GrepNeedle448 n2{};
			n2.literal = 1; n2.len = 1;
			n2.simdBlocks = new char[0x10]();
			for (int i = 0; i < 0x10; ++i)
				static_cast<char *>(n2.simdBlocks)[i] = 'a';
			expect(MatchEngine::engDispatch(
			           static_cast<const void *>(nullptr), &n2, 0, 1)
			       == Q_UINT64_C(0xffffffffffff),
			       "i5: 拆链后 engDispatch(null)→ 壳态恒零块 → miss →"
			       "哨兵(批 118 同相守卫)");
			delete[] static_cast<char *>(n2.simdBlocks);
		}
		MatchEngine::attachScanCarrier(&ctx.docBytes); // 恢复缝(ctx 尾 dtor 再拆,幂等)

		// ======== i6/i7. initDoc 驱动挂线活性(批 128;0x7543 面)========
		//   语料:0x7543 = FUN_0092f0f6 setCurrentBuffer(editor_initDoc
		//   唯一调用点 0030.c:29770,经 doc+0x108 门 29757);拆建腿
		//   FUN_0092ef06(0030.c:29560-29627)只放 +0x98..+0xd0 七槽
		//   (+0xf8 buffer 不在列)→ 换缓冲全程缝持续;engine dtor
		//   FUN_0092f62e 0030.c:29917 ***(param_1+0xf8) vt+8 才拆。
		//   挂线点 = engine ctor(00929fdd..00929fe1 建 32 型)→ 我方
		//   EditorContext RAII(批 127)即语料时序;本组经 0x7543
		//   dispatch 直验驱动活性(wordsteptest 无需测试装置即走真载体)。
		{
			EditorEngine e;                          // ctor 挂线(缝活性)
			expect(e.m_ctx.scanLineDoc()
			       == static_cast<const void *>(&e.m_ctx.docBytes),
			       "i6: 0x7543 驱动前缝已活(engine ctor 00929fe1 即建 32 型,"
			       "RAII 挂线 = 语料时序;FUN_0092ef06 不拆 +0xf8)");
			e.m_ctx.docBytes = QByteArray("xab");    // 3B 载体(缝直读)
			e.dispatch(0x7543, (qlonglong)1);        // initDoc 驱动面
			expect(e.m_ctx.scanLineDoc()
			       == static_cast<const void *>(&e.m_ctx.docBytes),
			       "i7: 0x7543 后缝持续(FUN_0092ef06 只放 +0x98..0xd0,"
			       "buffer 缝不拆 — 0030.c:29560-29627 全读)");
			// 驱动活性穿透:dispatch 后 engDispatch(null) → 缝 → 真载体
			GrepNeedle448 n3{};                      // literal 短针腿
			n3.len = 1;
			n3.simdBlocks = new char[0x10]();
			for (int i = 0; i < 0x10; ++i)
				static_cast<char *>(n3.simdBlocks)[i] = 'b';
			expect(MatchEngine::engDispatch(
			           static_cast<const void *>(nullptr), &n3, 0, 3)
			       == (quint64(4) << 0x30),
			       "i8: 0x7543 后 engDispatch(null)→ 缝承接 → 'b'@2 命中"
			       "(wordsteptest 免装置真载体;scanMask 产品调点同相)");
			delete[] static_cast<char *>(n3.simdBlocks);
		}                                        // e 尾 dtor 拆链(29917 面)
	}

	printf("fail=%d\n", g_fail);
	return g_fail == 0 ? 0 : 1;
}
