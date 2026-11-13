// 批 116:0x4eff 引擎腿 Onig 委托激活行为门(OnigSearch.cpp/bufferScan)。
// 铁律 5:断言语料行为/对账样例,每条带锚;逐条手工写。
//
// 语料锚:
//   FUN_00b422d0(2750B)@decomp-part-0037.c:32598 — 缓冲扫描引擎
//     (Onigmo-改 ≈onig_search);门 32611/32614 区间界;返回 -1 契约
//     (0x4eff 段 E 12719 LAB_00a33299 消费)。
//   FUN_00a83946(21B)@decomp-part-0035.c:454 — *param_2!=0 门,门不中
//     返 -1(needlePair null / 针空)。
//   MatchEngine::bufferScan00b422d0(MatchEngine.cpp)门同相转写。
//   OnigSearch.cpp 逐句映射见 CALIBRATION 批 116(onig_new regcomp.c:5941 /
//     onig_search regexec.c:3905 / onig_default_charat regexec.c:4375)。
//   语法假设 = ONIG_SYNTAX_RUBY:五真实样例对账(possessive ++ 与
//     \g<X> 同时要求 → RUBY 唯一;triggers.config/linux.lexer 原文)。
//
// 承载:MatchEngine::bufferScan00b422d0 需要 needlePair(GrepNeedle448*
//     包装)→ 测试直接喂 wrapper 同款门;样例对账直走 OnigSearch 面
//     (委托真身,无需 Qt 文档承载)。
#include "MatchEngine.h"
#include "CodecMemo.h"
#include "OnigSearch.h"
#include <QCoreApplication>
#include <cstdio>
#include <cstring>

static int g_fail = 0;
static void expect(bool ok, const char *name)
{
	printf("%s: %s\n", ok ? "OK" : "FAIL", name);
	if (!ok)
		g_fail++;
}

// needlePair 包装 = 语料 pair 双层解引(0089a0a0 *param_1 = 针对象
//   puVar11+2 = conv 基,0030:2626c lVar4 = *param_4 → GrepNeedle448*;
//   0x4eff case 12664 lVar7 = local_158 同形)。测试单线程 → 静态槽。
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
	return &g_car;                              // 语料 param_4 = 针对象指针(单层;
	                                            //   批 116 双层槽形态勘误,批 116b)
}

int main(int argc, char **argv)
{
	QCoreApplication app(argc, argv);

	// ======== a. literal 针命中位置(0x4eff 段 E 契约)========
	{
		OnigSearch::setSubject("hello world hello", 17);
		OnigRegex re = OnigSearch::compile("world", (int)strlen("world"), false, nullptr);
		expect(re != nullptr, "a1: compile(\"world\") 非空(onig_new 契约)");
		const qint64 hit = OnigSearch::search(re, 0, 17);
		expect(hit == 6,
		       "a2: \"world\" 命中位 6(onig_search 绝对字节位契约)");
		const qint64 hit2 = OnigSearch::search(re, 7, 17);
		expect(hit2 == -1,
		       "a3: from=7 → -1(start = 匹配起点下界;\"world\" 完整"
		       "匹配唯一 @6 < 7 — \"hello world hello\" 语义)");
		OnigSearch::freeRegex(re);
		OnigSearch::clearSubject();
	}

	// ======== b. 无匹配 -1(12719 LAB_00a33299 消费契约)========
	{
		OnigSearch::setSubject("abc", 3);
		OnigRegex re = OnigSearch::compile("xyz", (int)strlen("xyz"), false, nullptr);
		expect(OnigSearch::search(re, 0, 3) == -1,
		       "b1: 无匹配 → -1(ONIG_MISMATCH ≡ 语料 -1 同相)");
		OnigSearch::freeRegex(re);
		// 门同相:针空 / needlePair null → -1(00a83946;26272)
		expect(OnigSearch::bufferScan(nullptr, 0, false, 0, 3) == -1,
		       "b2: bufferScan pat=null → -1(00a83946 门同相)");
		expect(OnigSearch::bufferScan("ab", 0, false, 0, 3) == -1,
		       "b3: bufferScan len<=0 → -1(26272 门同相)");
		expect(MatchEngine::bufferScan00b422d0(nullptr, 0, 3) == -1,
		       "b4: needlePair=null → -1(00a83946 真身同相)");
		OnigSearch::clearSubject();
	}

	// ======== c. bufferScan00b422d0 wrapper(literal+case 契约)========
	{
		OnigSearch::setSubject("Ab Ab ab", 8);
		const void *p = makePair("Ab", 2, false);
		expect(MatchEngine::bufferScan00b422d0(p, 0, 8) == 0,
		       "c1: 大小写敏感 \"Ab\" 首命中 0");
		const void *pc = makePair("ab", 2, true);
		expect(MatchEngine::bufferScan00b422d0(pc, 0, 8) == 0,
		       "c2: case 档 \"ab\"(↔fold 表 0xd35f40 A-Z→a-z)首命中 0");
		expect(MatchEngine::bufferScan00b422d0(pc, 5, 8) == -1,
		       "c3: case 档 from=5 → -1(\"ab\" 完整命中 0 与 3,均 <5;"
		       "start = 匹配起点下界同相)");
		OnigSearch::clearSubject();
	}

	// ======== d. 语法样例对账(CALIBRATION 批 116 五条;RUBY 假设行)====
	{
		// d1: possessive ++(triggers.config 解压触发器域)
		//     pattern 剥自 (?x)\b[\w\-]++[^ ...]*?\.(?<suffix>...)\b(原文换行样例)
		OnigSearch::setSubject("see archive.tar.gz now", 22);
		int err = 0;
		OnigRegex re = OnigSearch::compile(
		    "(?x)\\b[\\w\\-]++[^ \\/:*?\"<>\\|\\r\\n]*?\\.(?<suffix>tar\\.gz|zip|gz)\\b",
		    (int)strlen("(?x)\\b[\\w\\-]++[^ \\/:*?\"<>\\|\\r\\n]*?\\.(?<suffix>tar\\.gz|zip|gz)\\b"), false, &err);
		expect(err == 0 && re != nullptr,
		       "d1: (?x)+ ++ + (?<suffix>) 编译成(RUBY op2 域)");
		expect(OnigSearch::search(re, 0, 22) == 4,
		       "d1r: 命中 \"archive.tar.gz\" 起 4");
		OnigSearch::freeRegex(re);
		OnigSearch::clearSubject();

		// d2: 超链接 (?ix)+ (# 注释)(triggers.config 原文形态)
		OnigSearch::setSubject("go https://example.com/x end", 28);
		re = OnigSearch::compile(
		    "(?ix)\\b((https?)://[-a-z0-9+&@#/%?=_~|!:,.;]*[-a-z0-9+&@#/%=_~|])(?=\\b|\\s|$)",
		    (int)strlen("(?ix)\\b((https?)://[-a-z0-9+&@#/%?=_~|!:,.;]*[-a-z0-9+&@#/%=_~|])(?=\\b|\\s|$)"), false, &err);
		expect(err == 0 && re != nullptr,
		       "d2: (?ix) 编译成(OPTION_RUBY i/x 域)");
		expect(OnigSearch::search(re, 0, 28) == 3,
		       "d2r: url 命中起 3");
		OnigSearch::freeRegex(re);
		OnigSearch::clearSubject();

		// d3: 子例程调用 \g<X> + 零宽组 (?<X>){0}(linux.lexer ip 原文形态)
		//     对账推演:'::1:…' 前导 \b 无词界,组2 ':' 起于 idx8
		//     ('1:2' 词/非词边界;手工推演 = 运行对账一致)
		OnigSearch::setSubject("host ::1:2:3:4:5:6:7:8 ok", 25);
		re = OnigSearch::compile(
		    "(?x)(?i)(?<X>[a-f0-9]{1,4}){0}\\b(:(\\g<X>:){0,6}\\g<X>)\\b",
		    (int)strlen("(?x)(?i)(?<X>[a-f0-9]{1,4}){0}\\b(:(\\g<X>:){0,6}\\g<X>)\\b"), false, &err);
		expect(err == 0 && re != nullptr,
		       "d3: \\g<X> 子例程 + (?<X>){0} 编译成(OP2_ESC_G_SUBEXP_CALL"
		       " — RUBY 唯一覆盖;Java/Perl 无此 op2 → 对账定案)");
		expect(OnigSearch::search(re, 0, 25) == 8,
		       "d3r: ipv6 命中起 8");
		OnigSearch::freeRegex(re);
		OnigSearch::clearSubject();

		// d4: (*UTF) 剥壳后 \x{...} 双字节窗(linux.lexer command 原文形态)
		OnigSearch::setSubject("$ prompt", 8);
		re = OnigSearch::compile(
		    "(?<=[\\|$#>\\x{e0b0}])[ \\t]{0,99}(?!\\d++\\.)([\\w\\.-]++)",
		    (int)strlen("(?<=[\\|$#>\\x{e0b0}])[ \\t]{0,99}(?!\\d++\\.)([\\w\\.-]++)"), false, &err);
		expect(err == 0 && re != nullptr,
		       "d4: \\x{e0b0}+lookbehind+ ++ 编译成(OP_ESC_X_BRACE_HEX8 域)");
		expect(OnigSearch::search(re, 0, 8) == 1,
		       "d4r: $ 后 \"prompt\" 命中起 1");
		OnigSearch::freeRegex(re);
		OnigSearch::clearSubject();

		// d5: datetime 字面族(linux.lexer 原文)— 基线 Ruby 语义回归
		OnigSearch::setSubject("on 2026/11/13 at log", 20);
		re = OnigSearch::compile(
		    "\\b\\d{4}[/-]\\d{1,2}[/-]\\d{1,2}(?:[ T]\\d{1,2}(?::\\d{2}){1,2}(?:\\.\\d+)?Z?(?: (GMT))?)?\\b",
		    (int)strlen("\\b\\d{4}[/-]\\d{1,2}[/-]\\d{1,2}(?:[ T]\\d{1,2}(?::\\d{2}){1,2}(?:\\.\\d+)?Z?(?: (GMT))?)?\\b"), false, &err);
		expect(err == 0 && re != nullptr, "d5: datetime 样例编译成");
		expect(OnigSearch::search(re, 0, 20) == 3,
		       "d5r: 日期命中起 3");
		OnigSearch::freeRegex(re);
		OnigSearch::clearSubject();
	}

	// ======== e. 委托缓存同相(00ad7360 惰性编译单槽承载)========
	{
		OnigSearch::setSubject("aaaa", 4);
		expect(OnigSearch::bufferScan("aa", 2, false, 0, 4) == 0,
		       "e1: bufferScan 首编+命中 0");
		// e2 同 pattern 缓存腿:命中 @0/@1("aaaa" 起 aa @0,自 2 起
		//   只剩 "aa"→2? aaaa[2..4)="aa" 完整 → 命中 2)
		expect(OnigSearch::bufferScan("aa", 2, false, 2, 4) == 2,
		       "e2: 同 pattern 缓存腿命中 2");
		expect(OnigSearch::bufferScan("bb", 2, false, 0, 4) == -1,
		       "e3: 换 pattern 释旧 → 无匹配 -1(契约同相)");
		OnigSearch::clearSubject();
	}

	printf("fail=%d\n", g_fail);
	return g_fail == 0 ? 0 : 1;
}
