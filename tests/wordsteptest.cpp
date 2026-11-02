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

	printf("fail=%d\n", g_fail);
	return g_fail == 0 ? 0 : 1;
}
