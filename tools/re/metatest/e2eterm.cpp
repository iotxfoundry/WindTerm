// 端到端终端路径:CTerminalConfig → Screen → TerminalCore → 单元格
#include "Screen.h"
#include "TerminalCore.h"
#include "CTerminalConfig.h"
#include <cstdio>
#include <QTextCodec>

static int fails = 0;
static void expect(const char *what, long long got, long long want)
{
	printf("%-40s got=%lld want=%lld%s\n", what, got, want,
	       got == want ? "" : "  FAIL");
	fails += got != want;
}

int main()
{
	// 1) resize: 24x80
	TerminalCore core;
	core.resizeCore(24, 80);
	core.m_flags |= 0x02;   // DECAWM: terminals default autowrap on (RIS/resetHard)
	Screen s;
	s.m_core = &core;
	s.m_history = new TerminalCore();
	s.m_history->resizeCore(24, 80);
	// codec install (corpus: view+0xe0 codec, +0xf0 decoder)
	QTextCodec *utf8 = QTextCodec::codecForName("UTF-8");
	s.m_codec = (void *)utf8;
	s.m_decoder = (void *)utf8->makeDecoder();

	// 2) writeText ASCII
	s.writeText("hello", 5);
	expect("cursorX after 'hello'", s.currentColumn(), 5);
	expect("cursorY", s.currentLine(), 0);
	struct Row *row = core.row(0);
	unsigned short *heads = (unsigned short *)row->attrArray;
	for (int i = 0; i < 5; i++) {
		if (heads[i] != (unsigned short)("hello"[i])) {
			printf("head[%d]=%04x want '%c'  FAIL\n", i, heads[i], "hello"[i]);
			fails++;
		}
	}
	printf("cells 'hello' written OK\n");

	// 3) newline + second line
	s.writeText("\r\nworld", 7);
	expect("cursorY after NL+world", s.currentLine(), 1);
	expect("cursorX after NL+world", s.currentColumn(), 5);

	// 4) wrap at column 80: write 78 more chars → pending wrap → next
	for (int i = 0; i < 75; i++)
		s.writeText("x", 1);
	// 75th x lands on col 79 (the last column) and latches the wrap;
	// the cursor clamps at 79 (0-based last column)
	expect("cursorX at right edge", s.currentColumn(), 79);
	s.writeText("Y", 1);
	expect("cursorY after wrap write", s.currentLine(), 2);
	expect("cursorX after wrap write", s.currentColumn(), 1);
	struct Row *r1 = core.row(1);
	unsigned short *h1 = (unsigned short *)r1->attrArray;
	printf("row1[79] = %c (want x)%s\n", (char)h1[79], h1[79] == 'x' ? "" : "  FAIL");
	fails += h1[79] != 'x';
	struct Row *r2 = core.row(2);
	unsigned short *h2 = (unsigned short *)r2->attrArray;
	printf("row2[0] = %c (want Y)%s\n", (char)h2[0], h2[0] == 'Y' ? "" : "  FAIL");
	fails += h2[0] != 'Y';

	// 4b) tab / backspace on a fresh 10x40 screen
	{
		TerminalCore c2;
		c2.resizeCore(10, 40);
		c2.m_flags |= 0x02;
		Screen s2;
		s2.m_core = &c2;
		s2.m_history = new TerminalCore();
		s2.writeText("ab", 2);
		s2.writeText("\t", 1);
		expect("tab to next stop", s2.currentColumn(), 8);
		s2.writeText("\b", 1);
		expect("backspace", s2.currentColumn(), 7);
		// scroll region 1;3 (1-based) -> rows 0..2; walk to bottom, LF scrolls
		s2.setTopBottomMargins(1, 3);
		s2.writeText("\r\nab\r\ncd", 8);

		s2.writeText("\r\n", 2);
		expect("at region bottom row", s2.currentLine(), 2);
				expect("row after scroll", s2.currentLine(), 2);
		struct Row *r1s = c2.row(1);
		unsigned short *h1s = (unsigned short *)r1s->attrArray;
		// after scroll: old row2 ('cd') becomes row1
		printf("scroll: row1[0]=%04x (want 'cd'=0063)%s\n", h1s[0],
		       h1s[0] == 0x63 ? "" : "  FAIL");
		fails += h1s[0] != 0x63;
	}

	// 5) UTF-8 multibyte: 你好 = two wide chars (folded cp, 0xffff trail)
	s.writeText("\xe4\xbd\xa0\xe5\xa5\xbd", 6);
	expect("cursorX after CJK x2", s.currentColumn(), 5);
	struct Row *rc = core.row(2);
	unsigned short *hc = (unsigned short *)rc->attrArray;
	// BMP chars decode to one unit: heads keep the raw codepoints with
	// the 0xffff trail on the second column (the 0xfca02400 fold is for
	// astral surrogate pairs only)
	// CJK lands at row2 cols 1..4 (after 'Y' at col 0)
	printf("CJK head[1]=%04x (want 4f60)%s\n", hc[1], hc[1] == 0x4f60 ? "" : "  FAIL");
	fails += hc[1] != 0x4f60;
	printf("CJK head[2]=%04x (want ffff trail)%s\n", hc[2], hc[2] == 0xffff ? "" : "  FAIL");
	fails += hc[2] != 0xffff;
	printf("CJK head[3]=%04x (want 597d)%s\n", hc[3], hc[3] == 0x597d ? "" : "  FAIL");
	fails += hc[3] != 0x597d;
	printf("CJK head[4]=%04x (want ffff trail)%s\n", hc[4], hc[4] == 0xffff ? "" : "  FAIL");
	fails += hc[4] != 0xffff;

	// 6) SGR template: payload (cell+0x18) carries the core SGR bits
	core.m_sgrBits = 0x1122334455667788ULL;
	s.writeText("S", 1);
	struct Row *rs = core.row(2);
	const unsigned long long gotSgr =
	    *(const unsigned long long *)((const char *)core.cellAt(rs, 5) + 0x18);
	printf("SGR payload cell+0x18 = %016llx (want 1122334455667788)%s\n",
	       gotSgr, gotSgr == 0x1122334455667788ULL ? "" : "  FAIL");
	fails += gotSgr != 0x1122334455667788ULL;
	core.m_sgrBits = 0;

	// 7) config-driven bell style read through the singleton
	CTerminalConfig::instance()->setConfigPath(
	    QStringLiteral("/opt/WindTerm_2.7.0/global/wind.config"));
	const QVariant v = CTerminalConfig::instance()->value(QStringLiteral("terminal.historySize"));
	printf("terminal.historySize present=%d\n", v.isValid());

	printf(fails ? "E2E RESULT: %d FAILS\n" : "E2E RESULT: ALL PASS\n", fails);
	return fails != 0;
}
