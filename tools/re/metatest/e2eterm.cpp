// 端到端终端路径:CTerminalConfig → Screen → TerminalCore → 单元格
#include "Screen.h"
#include "TerminalCore.h"
#include "CTerminalConfig.h"
#include <cstdio>

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

	// 5) config-driven bell style read through the singleton
	CTerminalConfig::instance()->setConfigPath(
	    QStringLiteral("/opt/WindTerm_2.7.0/global/wind.config"));
	const QVariant v = CTerminalConfig::instance()->value(QStringLiteral("terminal.historySize"));
	printf("terminal.historySize present=%d\n", v.isValid());

	printf(fails ? "E2E RESULT: %d FAILS\n" : "E2E RESULT: ALL PASS\n", fails);
	return fails != 0;
}
