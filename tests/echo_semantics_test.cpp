// 回显语义测试(批 31):checkControlCharacter 门(+0x101)
// 语料锚:007d1f5a 主循环尾(0025 语料 1714-1749)/ setter 007cadda
// (moc[15] case 0xf)/ QUIRKS 21(字面 ESC = 1 列字形)
#include <cstdio>
#include <QCoreApplication>
#include "Screen.h"
#include "TerminalCore.h"
#include "SuperCommander.h"

static int fails = 0;

static void expect(bool ok, const char *what)
{
	printf("%s: %s\n", ok ? "OK" : "FAIL", what);
	if (!ok)
		++fails;
}

// 注入 hex 序列(批尾 FIFO 自动排空)
static void injectHex(SuperCommander &cmd, const char *hex)
{
	QByteArray bytes;
	for (int p = 0; hex[p] && hex[p + 1]; p += 2) {
		int v;
		sscanf(hex + p, "%2x", &v);
		bytes.append((char)v);
	}
	cmd.processOutput(bytes);
}

static bool row0HasGlyphs(TerminalCore &core, const QByteArray &want,
                          int at)
{
	struct Row *r0 = core.row(0);
	if (!r0)
		return false;
	const unsigned short *heads = (const unsigned short *)r0->attrArray;
	for (int k = 0; k < want.size(); ++k) {
		if (at + k >= r0->length
		    || heads[at + k] != (unsigned char)want[k])
			return false;
	}
	return true;
}

int main(int argc, char **argv)
{
	QCoreApplication app(argc, argv);

	TerminalCore core;
	core.resizeCore(31, 89);
	core.m_flags |= 0x02;
	Screen s;
	s.m_core = &core;

	// 1) 门开:置位槽(007cadda)→ CSI 序列整段回显字面 + 自清
	{
		SuperCommander cmd;
		cmd.m_screen = &s;
		cmd.checkControlCharacter();
		expect(cmd.checkControlCharsActive(), "slot sets +0x101 flag");
		injectHex(cmd, "1b5b3367");   // CSI 3g(TBC all)
		expect(row0HasGlyphs(core, QByteArray("\x1b[3g", 4), 0),
		       "gate echoes matched CSI as literal glyphs");
		expect(!cmd.checkControlCharsActive(),
		       "gate clears flag (one-shot)");
	}

	// 2) 门关:同序列无回显
	{
		TerminalCore core2;
		core2.resizeCore(31, 89);
		core2.m_flags |= 0x02;
		Screen s2;
		s2.m_core = &core2;
		SuperCommander cmd;
		cmd.m_screen = &s2;
		injectHex(cmd, "1b5b3367");
		struct Row *r0 = core2.row(0);
		bool clean = true;
		if (r0)
			for (int x = 0; x < r0->length; ++x)
				if (((const unsigned short *)r0->attrArray)[x]
				    == 0x1b)
					clean = false;
		expect(clean, "no echo when flag unset");
	}

	// 3) 触发面:E7 实证锚 —— ESC-single 挂起 + HT 批 → 排队
	//    元调用置位(发射点 cited — wave-2;此处经事件循环交付)
	{
		SuperCommander cmd;
		cmd.m_screen = &s;
		injectHex(cmd, "1b44");        // ESC D(IND)→ escPending
		injectHex(cmd, "09");          // HT 批(排队发射)
		QCoreApplication::processEvents();
		expect(cmd.checkControlCharsActive(),
		       "HT with pending ESC-single queues setter");
		// 门由后批消费:下批首序列回显(落点 = CUP home 后光标;
		// row0 此前无墨 —— ESC D/HT 均不落字形)
		injectHex(cmd, "1b5b48");  // CSI H(CUP home)
		expect(row0HasGlyphs(core, QByteArray("\x1b[H", 3), 0),
		       "next batch first sequence echoed");
	}

	printf("echo_semantics_test fails=%d\n", fails);
	return fails != 0;
}
