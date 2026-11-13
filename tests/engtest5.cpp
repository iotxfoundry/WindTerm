// 批 120:Phase 5b 我方侧 — 编辑引擎行为序列驱动器(engtest5)。
// 产出:与 phase5 同格式的编辑引擎行为序列 JSON(每序列一行
//   {seq_id, 命中位/选区/docBytes 摘要}),落 /tmp/opencode/
//   phase5_seq_editor.json(沿用 /tmp/opencode/ 前缀惯例 — HANDOFF:
//   engtest4 硬编码读 /tmp/opencode/phase5_seq.json 同前缀)。
// 用途:原版侧捕获批(Phase 5b 环境就绪后)以同序列集直接对表;
//   本测试断言 = 批 116/wordsteptest/markerstest 已定案语义自检 →
//   我方真身行为快照,对表前作为基线冻结(测试策略 docs/PLAN.md:
//   断言语料行为,不领先真身)。
// 序列集三族(全表+锚见 tools/re/phase5/ENG5-SEQS.md):
//   A. 0x4eff 正则搜索:5 RUBY 对账样例(triggers.config ×2 /
//      linux.lexer ×3,CALIBRATION 批 116)+ literal/icase/无命中/
//      越界 from 变体 + bufferScan00b422d0 wrapper 锚行;每行附带
//      0x4eff dispatch 占位链快照(needlePair null 门 12665 → 0,
//      op+0x3c hits 不污染)。
//   B. 0x4f00 词步进:空文档/预填选区/包夹构型(wordsteptest
//      b/c/c2/d/d2/e1/e2 构型一比一)。
//   C. markers/0x7576 插入样式:runvector 门/charUsed T 段
//      (markerstest p/q3 构型;批 83/115 面)。
// 铁律 5:断言语料行为,每条断言带语料锚;逐条手工写。
// 测试专用可达缝:#define private public 仅本 TU(wordsteptest/
// markerstest 同款;EditorEngine/EditorContext 无 Q_OBJECT,不触发
// moc ABI 面)。
#define private public
#include "EditorEngine.h"
#undef private
#include "CodecMemo.h"       // GrepNeedle448(0x448 针对象承载)
#include "MatchEngine.h"     // bufferScan00b422d0(A11 wrapper 锚行)
#include "OnigSearch.h"      // compile/search(批 116 激活引擎腿)
#include "MarkersStore.h"    // ValueTable/bankCtorK3/C 族
#include "Scintilla.h"
#include <QApplication>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <stddef.h>

static int g_fail = 0;
static int g_asserts = 0;
static void expect(bool ok, const char *name)
{
	++g_asserts;
	printf("%s: %s\n", ok ? "OK" : "FAIL", name);
	if (!ok)
		g_fail++;
}

// —— JSON 串转义(doc/needle 载体;全 ASCII 域)——
static QByteArray jesc(const char *s)
{
	QByteArray r;
	for (const char *p = s; *p; ++p) {
		switch (*p) {
		case '"':  r += "\\\""; break;
		case '\\': r += "\\\\"; break;
		case '\n': r += "\\n";  break;
		case '\t': r += "\\t";  break;
		default:   r += *p;     break;
		}
	}
	return r;
}
static void sep(std::ofstream &out, bool &first)
{
	if (!first)
		out << ",\n";
	first = false;
}

// ============ 夹具:ReplaceOp 桥面缓冲(wordsteptest 同款;
//               语料 op 体偏移直读:EditorEngine.cpp:3006-3013)============
struct OpBridge {
	quint8  pad00[0x0c];   // +0x00..+0x0b(自旋锁/+0x08 区;桥面未消费)
	quint32 flags;         // +0x0c(段 7 门 bit3 / 重试门 bit5 / canOld 门&5)
	quint8  type;          // +0x10(12792;12793 selMode=(type&0xfd)==1)
	quint8  pad11[0x38 - 0x11];
	quint8  retryMark;     // +0x38(13050 *(op+0x38)|=4 重试标记)
	quint8  pad39[3];
	quint32 hits;          // +0x3c(9781/12659 命中计数 ++ 面)
};
static_assert(offsetof(OpBridge, flags) == 0x0c, "op+0x0c flags");
static_assert(offsetof(OpBridge, type) == 0x10, "op+0x10 type");
static_assert(offsetof(OpBridge, retryMark) == 0x38, "op+0x38 重试标记");
static_assert(offsetof(OpBridge, hits) == 0x3c, "op+0x3c 命中计数");

// needlePair 包装(onigtest makePair 同款;批 116b 单层:针对象指针)
static QByteArray g_bytes;
static GrepNeedle448 g_car;
static const void *makePair(const char *needle, int len, bool icase)
{
	g_car = GrepNeedle448{};
	g_bytes = QByteArray(needle, len);
	g_car.bytes = g_bytes;
	g_car.len = len;
	g_car.literal = 0;                           // convCtor 置 1;canOld 门读位
	g_car.caseFlag = icase ? 1 : 0;
	return &g_car;
}

// 预填 ASCII 文档 + 选区夹具(wordsteptest fillAscii 同款)
static void fillAscii(EditorEngine &e, const char *text, qint64 selA,
                      qint64 selB)
{
	e.m_ctx.docBytes = QByteArray(text);
	e.dispatch(SCI_ADDTEXT, (qlonglong)strlen(text), QByteArray(text));
	if (selB > selA)
		e.dispatch(SCI_SETSEL, selA, selB);
}

// —— C 族 q3 构型 delegate vtable(markerstest fx 同款;槽序语料锁定:
//    vt+0x28 firstIndex/+0x30 count/+0x38 begin/+0x40 end)——
static qint64 fx_first(void *) { return 0; }
static qint64 fx_count0(void *) { return 0; }    // vt+0x30=0 → prune 门关
static qint64 fx_begin(void *) { return 0; }
static qint64 fx_end(void *)   { return 0; }
static void   fx_dtor(void *)  {}
static void  *fx_vtable[9] = {
	nullptr, (void *)fx_dtor, nullptr, nullptr, nullptr,
	(void *)fx_first, (void *)fx_count0, (void *)fx_begin, (void *)fx_end,
};

// ============ A 族序列表(0x4eff 正则搜索;锚 = CALIBRATION 批 116
//               五样例 + onigtest a-d 组)============
struct EffSeq {
	const char *id, *doc, *needle;
	bool icase;
	qint64 from, to, expectHit;
	bool wrapper;          // A11 = bufferScan00b422d0 锚行
	const char *anchor;
};
static const EffSeq EFF[] = {
	{"A1", "see archive.tar.gz now",
	 "(?x)\\b[\\w\\-]++[^ \\/:*?\"<>\\|\\r\\n]*?\\.(?<suffix>tar\\.gz|zip|gz)\\b",
	 false, 0, 22, 4, false,
	 "批 116 d1 triggers.config:possessive ++ RUBY op2 域"},
	{"A2", "go https://example.com/x end",
	 "(?ix)\\b((https?)://[-a-z0-9+&@#/%?=_~|!:,.;]*[-a-z0-9+&@#/%=_~|])(?=\\b|\\s|$)",
	 false, 0, 28, 3, false,
	 "批 116 d2 triggers.config:(?ix)+# 注释 OPTION_RUBY 域"},
	{"A3", "host ::1:2:3:4:5:6:7:8 ok",
	 "(?x)(?i)(?<X>[a-f0-9]{1,4}){0}\\b(:(\\g<X>:){0,6}\\g<X>)\\b",
	 false, 0, 25, 8, false,
	 "批 116 d3 linux.lexer:\\g<X> 子例程 — RUBY 唯一上游"},
	{"A4", "$ prompt",
	 "(?<=[\\|$#>\\x{e0b0}])[ \\t]{0,99}(?!\\d++\\.)([\\w\\.-]++)",
	 false, 0, 8, 1, false,
	 "批 116 d4 linux.lexer:\\x{e0b0}+lookbehind"},
	{"A5", "on 2026/11/13 at log",
	 "\\b\\d{4}[/-]\\d{1,2}[/-]\\d{1,2}(?:[ T]\\d{1,2}(?::\\d{2}){1,2}"
	 "(?:\\.\\d+)?Z?(?: (GMT))?)?\\b",
	 false, 0, 20, 3, false,
	 "批 116 d5 linux.lexer:datetime 字面基线"},
	{"A6", "hello world hello", "world", false, 0, 17, 6, false,
	 "onigtest a2:literal 命中绝对字节位 6"},
	{"A7", "Ab Ab ab", "ab", true, 0, 8, 0, false,
	 "onigtest c2 语义:case 档首命中 0(0xd35f40 折叠表)"},
	{"A8", "abc", "xyz", false, 0, 3, -1, false,
	 "onigtest b1:无匹配 ONIG_MISMATCH ≡ -1"},
	{"A9", "hello world hello", "world", false, 7, 17, -1, false,
	 "onigtest a3:from 越过唯一命中 → -1(start 下界)"},
	{"A10", "hello world hello", "world", false, 17, 17, -1, false,
	 "空域 [len,len):onig_search 空区不匹配(契约面)"},
	{"A11", "Ab Ab ab", "Ab", false, 0, 8, 0, true,
	 "onigtest c1:bufferScan00b422d0 wrapper 锚(承载注记见 ENG5-SEQS.md)"},
};

// ============ B 族序列表(0x4f00 词步进;构型 = wordsteptest
//               b/c/c2/d/d2/e1/e2 一比一)============
struct WordSeq {
	const char *id, *text;
	qint64 selA, selB;
	quint8 type;
	quint32 flags;
	qint64 eSelA, eSelB;
	const char *anchor;
};
static const WordSeq WORD[] = {
	{"B1", "",    0, 0, 3, 0,    0, 0,
	 "wordsteptest b:空文档步尽(9851-9853 恒 -1)"},
	{"B2", "abc", 0, 2, 3, 0,    0, 2,
	 "wordsteptest c:段 4 前向门 cur=2>hi=0 步出(9863-9872)"},
	{"B3", "abc", 0, 3, 3, 0,    0, 3,
	 "wordsteptest e1:覆盖构型(9803-9819 包夹界面不达)"},
	{"B4", "abc", 1, 2, 3, 0,    1, 2,
	 "wordsteptest e2:界外构型(9843 单步登记腿)"},
	{"B5", "abc", 1, 2, 2, 0,    1, 2,
	 "wordsteptest c2:type=2 后向(9678-9681 idx=-1)"},
	{"B6", "",    0, 0, 3, 8,    0, 0,
	 "wordsteptest d:flags&8 selStore 懒建(13057-13061)"},
	{"B7", "",    0, 0, 3, 0x20, 0, 0,
	 "wordsteptest d2:重试门(13050 op+0x38|=4)"},
};

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	std::ofstream out("/tmp/opencode/phase5_seq_editor.json");
	out << "[\n";
	bool first = true;

	// ======== A 族:0x4eff 正则搜索 ========
	{
		EditorEngine effEng;   // dispatch 占位链共享(每行 null 门早退,
		                       //   无跨行状态残留)
		for (const EffSeq &sq : EFF) {
			const QByteArray doc(sq.doc);
			OnigSearch::setSubject(doc.constData(), doc.size());
			qint64 hit = -1;
			if (sq.wrapper) {
				const void *p = makePair(sq.needle,
				    int(strlen(sq.needle)), sq.icase);
				hit = MatchEngine::bufferScan00b422d0(
				    p, sq.from, sq.to);
			} else {
				int err = 0;
				OnigRegex re = OnigSearch::compile(sq.needle,
				    int(strlen(sq.needle)), sq.icase, &err);
				hit = OnigSearch::search(re, sq.from, sq.to);
				OnigSearch::freeRegex(re);
			}
			OnigSearch::clearSubject();
			// 0x4eff dispatch 占位链快照:needlePair=null(cited 占位)
			//   → 12665 门真身接线 → 0;flags=5 → canOld 门不中臂真
			//   (不触针缓存 — CodecMemo.h canOld 注释);op+0x3c 不污染。
			OpBridge op{};
			op.flags = 5;
			const QVariant rv = effEng.dispatch(0x4eff,
			    QVariant((qlonglong)(quintptr)&op));
			expect(hit == sq.expectHit,
			    (QByteArray(sq.id) + ": hit==" +
			     QByteArray::number(qlonglong(sq.expectHit)) +
			     "(" + sq.anchor + ")").constData());
			expect(rv.toLongLong() == 0,
			    (QByteArray(sq.id) + ": 0x4eff dispatch 占位链 → 0"
			     "(12665 needlePair null 门真身;我方快照)"
			    ).constData());
			expect(op.hits == 0,
			    (QByteArray(sq.id) + ": op+0x3c hits==0(12659 命中"
			     "腿不达 — 占位链死路同相)").constData());
			fprintf(stderr, "[seq] %s hit=%lld\n", sq.id,
			    (long long)hit);
			sep(out, first);
			out << "{\"seq_id\": \"" << sq.id
			    << "\", \"family\": \"4eff-ruby\", \"doc\": \""
			    << jesc(sq.doc).constData()
			    << "\", \"docLen\": " << doc.size()
			    << ", \"needle\": \"" << jesc(sq.needle).constData()
			    << "\", \"icase\": "
			    << (sq.icase ? "true" : "false")
			    << ", \"range\": [" << sq.from << ", " << sq.to << "]"
			    << ", \"hit\": " << hit
			    << ", \"dispatchRet\": " << rv.toLongLong()
			    << ", \"opHits\": " << op.hits << "}";
		}
	}

	// ======== B 族:0x4f00 词步进 ========
	for (const WordSeq &sq : WORD) {
		EditorEngine e;
		fillAscii(e, sq.text, sq.selA, sq.selB);
		OpBridge op{};
		op.type = sq.type;
		op.flags = sq.flags;
		const QVariant rv = e.dispatch(0x4f00,
		    QVariant((qlonglong)(quintptr)&op));
		const qlonglong ss =
		    e.dispatch(SCI_GETSELECTIONSTART).toLongLong();
		const qlonglong se =
		    e.dispatch(SCI_GETSELECTIONEND).toLongLong();
		expect(rv.toLongLong() == -1,
		    (QByteArray(sq.id) + ": ret==-1(" + sq.anchor + ")"
		    ).constData());
		expect(ss == sq.eSelA && se == sq.eSelB,
		    (QByteArray(sq.id) + ": 选区不变 [" +
		     QByteArray::number(sq.eSelA) + "," +
		     QByteArray::number(sq.eSelB) + ")(语料选区不变量)"
		    ).constData());
		expect(op.hits == 0,
		    (QByteArray(sq.id) + ": hits==0(9781 命中腿不达)"
		    ).constData());
		if (sq.flags & 8)
			expect(e.m_ctx.selStoreOn
			    && e.m_ctx.selStore.anchor.n0.pos == -1
			    && e.m_ctx.selStore.anchor.n1.pos == -1,
			    "B6: selStoreOn 置位 + anchor {-1,-1}(13057-13061/"
			    "13082-13089 真身;wordsteptest d 同锚)");
		if (sq.flags & 0x20)
			expect((op.retryMark & 4) != 0,
			    "B7: op+0x38|=4 置位(13050 重试标记真身;"
			    "wordsteptest d2 同锚)");
		fprintf(stderr, "[seq] %s ret=%lld sel=(%lld,%lld)\n", sq.id,
		    (long long)rv.toLongLong(), (long long)ss, (long long)se);
		sep(out, first);
		out << "{\"seq_id\": \"" << sq.id
		    << "\", \"family\": \"4f00-wordstep\", \"doc\": \""
		    << jesc(sq.text).constData()
		    << "\", \"docLen\": " << strlen(sq.text)
		    << ", \"type\": " << int(sq.type)
		    << ", \"flags\": " << sq.flags
		    << ", \"sel\": [" << ss << ", " << se << "]"
		    << ", \"ret\": " << rv.toLongLong()
		    << ", \"opHits\": " << op.hits << "}";
	}

	// ======== C 族:markers/0x7576 插入样式(批 83/115 面)========
	{
		// C1 bare:runvector 空 → L29033 门 → 0(markerstest p 同锚)
		EditorEngine e;
		const QVariant rv = e.dispatch(0x7576, (qlonglong)0);
		expect(rv.toLongLong() == 0,
		    "C1: runvector 空 → 0(L29033 门;markerstest p 同锚)");
		sep(out, first);
		out << "{\"seq_id\": \"C1\", \"family\": \"7576-insertstyle\""
		    << ", \"ret\": " << rv.toLongLong()
		    << ", \"runVecSize\": 0, \"charUsedRuns\": -1"
		    << ", \"docLen\": 0}";
	}
	{
		// C2 +charUsedView:runvector 门先于 T 段 → 仍 0(p 组构型)
		EditorEngine e;
		RS8 *rs8 = new RS8();
		rs8->InsertSpace(0, 4);
		rs8->FillRange(1, 1, 2);
		e.m_ctx.charUsedView = rs8;
		const QVariant rv = e.dispatch(0x7576, (qlonglong)0);
		expect(rv.toLongLong() == 0,
		    "C2: runvector 门先于 T 段 → 0(L29033 前置;"
		    "markerstest p 骨架同构)");
		expect(int(rs8->Runs()) == 3,
		    "C2: charUsed runs=3([1,3)=1 三 run;T 段 0x95c656 前提)");
		e.m_ctx.charUsedView = nullptr;
		delete rs8;
		sep(out, first);
		out << "{\"seq_id\": \"C2\", \"family\": \"7576-insertstyle\""
		    << ", \"ret\": " << rv.toLongLong()
		    << ", \"runVecSize\": 0, \"charUsedRuns\": 3"
		    << ", \"docLen\": 0}";
	}
	{
		// C3 q3 构型 + charUsedView:主循环 props 门跳 → T 段行展开 → 1
		EditorEngine e;
		e.dispatch(0x7543, (qlonglong)1);   // arr 建(markerstest q3 锚)
		e.m_ctx.styleProps190 = QVector<quint32>{ 1 };  // 表门承载:
		                                                //   props=value(sv>>2)=1
		                                                //   ≠0 → 主循环过门
		                                                //   (L28813-28821)
		RS8 *rs8 = new RS8();
		rs8->InsertSpace(0, 4);
		rs8->FillRange(1, 1, 2);
		e.m_ctx.charUsedView = rs8;
		wt::ValueTable *re2 = new wt::ValueTable{};
		wt::MarkEntryObj *re2d = new wt::MarkEntryObj{};
		re2d->vtbl = fx_vtable;
		re2d->styles = nullptr;
		wt::bankCtorK3(re2, wt::makeHolder0x20(new RS8()));
		re2->delegate = re2d;
		e.m_ctx.runVector.append(re2);
		const QVariant rv = e.dispatch(0x7576, (qlonglong)0);
		expect(rv.toLongLong() == 1,
		    "C3: T 段行展开 ok=1(0x95c85f lnA>=lnB 直置;markerstest "
		    "p 唯一置 1 路径)");
		expect(int(rs8->Runs()) == 3,
		    "C3: charUsed runs=3(T 段 0x95c656 ln 环前提)");
		e.m_ctx.runVector.clear();
		e.m_ctx.charUsedView = nullptr;
		delete re2;
		delete re2d;
		delete rs8;
		sep(out, first);
		out << "{\"seq_id\": \"C3\", \"family\": \"7576-insertstyle\""
		    << ", \"ret\": " << rv.toLongLong()
		    << ", \"runVecSize\": 1, \"charUsedRuns\": 3"
		    << ", \"docLen\": 0}";
	}

	out << "]\n";
	std::printf("written /tmp/opencode/phase5_seq_editor.json\n");
	std::printf("fail=%d asserts=%d\n", g_fail, g_asserts);
	return g_fail == 0 ? 0 : 1;
}
