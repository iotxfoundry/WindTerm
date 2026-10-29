// Phase 5 我方对称 dump:同序列经 Screen::writeText(组合解析器),
// 与原版 writeSplitData 链产物同格式落盘对比。
#include "Screen.h"
#include "TerminalCore.h"
#include "SuperCommander.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextCodec>
#include <cstdio>
#include <fstream>
#include <QFile>

struct Row;


// 格子验尸:aux 非 null 时必须为合法 0x18 对象(ref∈[1,0x10000])
static const char *verifyCells(TerminalCore &core)
{
	for (int y = 0; y < core.rowCount(); ++y) {
		struct Row *row = core.row(y);
		if (!row)
			continue;
		for (int x = 0; x < row->length; ++x) {
			void *aux = *(void **)((const char *)core.cellAt(row, x)
			                       + 0x10);
			if (aux == nullptr)
				continue;
			if ((unsigned long)aux < 0x1000
			    || *(const int *)aux < 1 || *(const int *)aux > 0x10000) {
				fprintf(stderr,
				        "[p5] JUNK y=%d x=%d aux=%p {%d,%d,%p} "
				        "offCells=%ld offTabs=%ld\n",
				        y, x, aux, *(const int *)aux,
				        *(const int *)((const char *)aux + 4),
				        *(void *const *)((const char *)aux + 8),
				        (long)((const char *)aux
				               - (const char *)core.row(y)->cells),
				        (long)((const char *)aux
				               - (const char *)core.m_tabstops.payload));
				return "junk-aux";
			}
			if (*(const void *const *)((const char *)aux + 8)
			        == nullptr
			    && *(const int *)((const char *)aux + 4) != 0)
				return "null-payload";
		}
	}
	return nullptr;
}

static void dumpSeq(SuperCommander &cmd, Screen &s, TerminalCore &core,
                    const char *name, const char *hex, std::ofstream &out)
{
	// hex → bytes
	QByteArray bytes;
	for (const char *p = hex; p[0] && p[1]; p += 2) {
		int v;
		sscanf(p, "%2x", &v);
		bytes.append((char)v);
	}
	if (!bytes.isEmpty())
		cmd.processOutput(bytes);   // 解析链(writeSplitData)
	const char *bad = verifyCells(core);
	if (bad)
		fprintf(stderr, "[p5] VERIFY %s: %s (cursor %d,%d)\n", name,
		        bad, s.currentLine(), s.currentColumn());
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
	out << "]}}" << ",\n";
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
	// 会话装配镜像:原版会话必有调色板容器(+0xd0)——装默认表
	{
		static const quint32 defs[16] = {
			0x000000, 0xcd0000, 0x00cd00, 0xcdcd00, 0x0000ee,
			0xcd00cd, 0x00cdcd, 0xe5e5e5, 0x7f7f7f, 0xff0000,
			0x00ff00, 0xffff00, 0x5c5cff, 0xff00ff, 0x00ffff,
			0xffffff,
		};
		s.installPalette(QVector<quint32>(defs, defs + 16));
	}
	// 与原版对齐:序列走解析链 processOutput(→ writeSplitData)
	SuperCommander cmd;
	cmd.m_screen = &s;

	QJsonDocument doc = QJsonDocument::fromJson(
	    QByteArrayLiteral(
	        R"SEQFILE(/tmp/opencode/phase5_seq.json)SEQFILE"));
	Q_UNUSED(doc);
	QFile f(QStringLiteral("/tmp/opencode/phase5_seq.json"));
	f.open(QIODevice::ReadOnly);
	QJsonDocument seqDoc = QJsonDocument::fromJson(f.readAll());
	const QJsonArray arr = seqDoc.array();
	bool first = true;
	bool cleared = false;
	for (const QJsonValue &v : arr) {
		const QJsonObject o = v.toObject();
		const QByteArray name = o["name"].toString().toUtf8();
		const QByteArray hex = o["bytes"].toString().toUtf8();
		if (!cleared) {   // 与原版一致:先清屏归零
			dumpSeq(cmd, s, core, "clear",
			        "1b5b324a1b5b48", out);
			cleared = true;
		}
		if (!first)
			out << ",\n";
		first = false;
		dumpSeq(cmd, s, core, name.constData(), hex.constData(), out);
	}
	out << "]";
	std::printf("written /tmp/opencode/phase5_ours.json\n");
	return 0;
}
