// Phase 5 我方对称 dump:同序列经 Screen::writeText(组合解析器),
// 与原版 writeSplitData 链产物同格式落盘对比。
#include "Screen.h"
#include "TerminalCore.h"
#include <QTextCodec>
#include <cstdio>
#include <fstream>

struct Row;

static void dumpSeq(Screen &s, TerminalCore &core, const char *name,
                    const char *hex, std::ofstream &out)
{
	// hex → bytes
	QByteArray bytes;
	for (const char *p = hex; p[0] && p[1]; p += 2) {
		int v;
		sscanf(p, "%2x", &v);
		bytes.append((char)v);
	}
	if (!bytes.isEmpty())
		s.writeText(bytes.constData(), bytes.size());
	out << "{\"name\": \"" << name << "\", \"grid\": {";
	out << "\"rowCount\": " << core.rowCount();
	out << ", \"curY\": " << s.currentLine();
	out << ", \"curX\": " << s.currentColumn();
	out << ", \"lines\": [";
	const int n = core.rowCount() < 32 ? core.rowCount() : 32;
	for (int y = 0; y < n; ++y) {
		struct Row *row = core.row(y);
		if (!row) {
			out << "null" << (y + 1 < n ? ", " : "");
			continue;
		}
		const unsigned short *heads =
		    (const unsigned short *)row->attrArray;
		out << "[";
		for (int x = 0; x < row->length; ++x)
			out << heads[x] << (x + 1 < row->length ? ", " : "");
		out << "]" << (y + 1 < n ? ", " : "");
	}
	out << "]}}" << (strcmp(name, "clear_end") ? ",\n" : "\n");
}

int main()
{
	std::ofstream out("/tmp/opencode/phase5_ours.json");
	out << "[\n";

	TerminalCore core;
	core.resizeCore(24, 80);
	core.m_flags |= 0x02;   // DECAWM
	Screen s;
	s.m_core = &core;
	s.m_history = new TerminalCore();
	s.m_history->resizeCore(24, 80);
	QTextCodec *utf8 = QTextCodec::codecForName("UTF-8");
	s.m_codec = (void *)utf8;
	s.m_decoder = (void *)utf8->makeDecoder();

	dumpSeq(s, core, "clear", "1b5b324a1b5b48", out);   // 同原版:先清屏
	dumpSeq(s, core, "ascii", "68656c6c6f", out);
	dumpSeq(s, core, "crlf", "0d0a776f726c64", out);
	dumpSeq(s, core, "cjk", "e4bda0e5a5bd", out);
	dumpSeq(s, core, "sgr_red", "1b5b33316d52", out);
	dumpSeq(s, core, "clear_end", "1b5b306d", out);
	out << "]";
	std::printf("written /tmp/opencode/phase5_ours.json\n");
	return 0;
}
