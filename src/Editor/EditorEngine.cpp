#include "EditorEngine.h"

#include "ScintillaEditBase.h"
#include "Scintilla.h"

// HYBRID EditorEngine: standard SCI_* delegates to real Scintilla
// (src/Scintilla static libs); WindTerm EXT/WT stays in customDispatch.

struct RetEntry { unsigned cmd; char kind; };
static const RetEntry scintilla_returns[] =
{
#include "scintilla_returns.inc"
};

EditorEngine::EditorEngine()
	: m_edit(new ScintillaEditBase)
{
}

EditorEngine::~EditorEngine() { delete m_edit; }

QVariant EditorEngine::scintillaDelegate(uint cmd, const QVariant &a,
                                         const QVariant &b)
{
	// numeric-first marshalling; text params marshal through UTF-8
	// buffers kept alive for the send call
	QByteArray a8, b8;
	uptr_t w = 0;
	sptr_t l = 0;
	if (a.isValid()) {
		if (a.type() == QVariant::String) { a8 = a.toString().toUtf8(); w = (uptr_t)a8.constData(); }
		else if (a.type() == QVariant::ByteArray) { a8 = a.toByteArray(); w = (uptr_t)a8.constData(); }
		else w = static_cast<uptr_t>(a.toLongLong());
	}
	if (b.isValid()) {
		if (b.type() == QVariant::String) { b8 = b.toString().toUtf8(); l = (sptr_t)b8.data(); }
		else if (b.type() == QVariant::ByteArray) { b8 = b.toByteArray(); l = (sptr_t)b8.data(); }
		else l = static_cast<sptr_t>(b.toLongLong());
	}
	const sptr_t r = m_edit->send(cmd, w, l);
	const RetEntry *p = scintilla_returns;
	for (; p->cmd; ++p) {
		if (p->cmd != cmd)
			continue;
		switch (p->kind) {
		case 'b': return QVariant(r != 0);
		case 'p':
		case 'i': return QVariant(static_cast<int>(r));
		case 't': return QVariant(QByteArray(reinterpret_cast<const char *>(r)));
		default:  return QVariant(0);
		}
	}
	return QVariant(static_cast<long long>(r));
}

QVariant EditorEngine::dispatch(uint cmd, const QVariant &a, const QVariant &b)
{
	// standard SCI_* -> real Scintilla; WindTerm EXT/WT -> custom layer
	if (cmd >= 20163)   // EXT 20163-20228 / WT 30001-30166
		return customDispatch(cmd, a, b);
	return scintillaDelegate(cmd, a, b);
}

QVariant EditorEngine::customDispatch(uint cmd, const QVariant &a,
                                      const QVariant &b)
{
	// WindTerm 扩展命令(EXT 20163-20228 / WT 30001-30166)。
	// 逆向语义(EDITOR-ENGINE-COMMANDS.md)经真 Scintilla 公共 API 实现;
	// 无上游等价的 fork 特性按文档桩保留。
	auto send = [this](uint msg, uptr_t w = 0, sptr_t l = 0) {
		return m_edit->send(msg, w, l);
	};
	switch (cmd) {
	// --- 文本 ---
	case 0x7551: {   // appendText(0x75ab 变体;w=长度 l=文本)
		QByteArray t = a.toByteArray();
		send(SCI_ADDTEXT, t.size(), (sptr_t)t.constData());
		return QVariant(0);
	}
	case 0x7554: {   // subString(start,end) = SCI_GETTEXTRANGE
		const long long s = a.toLongLong(), e = b.toLongLong();
		Sci_TextRange tr;
		tr.chrg.cpMin = (Sci_PositionCR)s;
		tr.chrg.cpMax = (Sci_PositionCR)e;
		QByteArray out(e - s + 1, 0);
		tr.lpstrText = out.data();
		send(SCI_GETTEXTRANGE, 0, (sptr_t)&tr);
		return QVariant(QByteArray(out.constData(), e - s));
	}
	case 0x757e: {   // indexOf(5参列表: pattern/start/end/options/nth)
		const QVariantList args = a.toList();
		if (args.size() < 5)
			return QVariant(0);
		const QByteArray pat = args.at(0).toString().toUtf8();
		send(SCI_SETSEARCHFLAGS,
		     (args.at(3).toInt() & 1 ? SCFIND_MATCHCASE : 0) |
		     (args.at(3).toInt() & 2 ? SCFIND_REGEXP : 0) |
		     (args.at(3).toInt() & 4 ? SCFIND_WHOLEWORD : 0));
		send(SCI_SETTARGETRANGE, args.at(1).toLongLong(), args.at(2).toLongLong());
		int nth = qMax(1, args.at(4).toInt());
		sptr_t pos = -1;
		for (int i = 0; i < nth; ++i) {
			pos = send(SCI_SEARCHINTARGET, pat.size(), (sptr_t)pat.constData());
			if (pos < 0)
				return QVariant((long long)-1);
			send(SCI_SETTARGETRANGE, pos + 1, args.at(2).toLongLong());
		}
		// 命中:nth 项的 start/end(与二进制结果形状一致)
		QVariantMap m;
		m["start"] = (long long)pos;
		m["end"] = (long long)send(SCI_GETTARGETEND);
		return QVariant(m);
	}
	// --- 导航 ---
	case 0x75ab:     // gotoLine(line u64 in a, column int in b)
		send(SCI_GOTOLINE, a.toULongLong());
		return QVariant(0);
	case 0x75ac:     // gotoPosition
		send(SCI_GOTOPOS, a.toLongLong());
		return QVariant(0);
	// --- 选择 ---
	case 0x75b8: {   // selectionText(sep, useSep) = SCI_GETSELTEXT
		const int len = (int)send(SCI_GETSELTEXT, 0, 0);
		QByteArray buf(len + 1, 0);
		send(SCI_GETSELTEXT, 0, (sptr_t)buf.data());
		return QVariant(QString::fromUtf8(buf.constData()));
	}
	case 0x7571:     // fold(line) = SCI_TOGGLEFOLD
		send(SCI_TOGGLEFOLD, a.toLongLong());
		return QVariant(0);
	case 0x756f:     // fold range = SCI_FOLDLINE 展开/折叠
		send(SCI_FOLDLINE, a.toLongLong(), b.toLongLong() ? SC_FOLDACTION_EXPAND : SC_FOLDACTION_CONTRACT);
		return QVariant(0);
	// --- 编辑设置(与 doc+0x270/274 对应的公共 API)---
	case 0x75c1:     // tabSize read
		return QVariant((int)send(SCI_GETTABWIDTH));
	case 0x75c4:     // setTabSize(拒 n<1,0x75c1 读对)
		send(SCI_SETTABWIDTH, a.toInt());
		return QVariant(0);
	case 0x75c2:     // indentSize read
		return QVariant((int)send(SCI_GETINDENT));
	case 0x75c5:     // setIndentSize
		send(SCI_SETINDENT, a.toInt());
		return QVariant(0);
	case 0x7577:     // eolString(kind) = 行尾串查询
		return QVariant(QByteArray(send(SCI_GETEOLMODE) == SC_EOL_CRLF ? "\r\n" : "\n"));
	// --- 探针 ---
	case 0x75af:     // canRedo 家族
		return QVariant(send(SCI_CANREDO) != 0);
	case 0x75b1:
		return QVariant(send(SCI_CANUNDO) != 0);
	case 0x754f:     // capability 8 探针(只读)
		return QVariant(send(SCI_GETREADONLY) == 0);
	// --- 编辑器上下文 setter 批(Phase-3;EditorContext 模型)---
	case 0x759a:     // setHexBase(FUN_00a28e7c)
		m_ctx.setHexBase(a.toInt());
		return QVariant(0);
	case 0x759e:     // setHexMode(FUN_00a30c2e)
		m_ctx.setHexMode(a.toBool());
		return QVariant(0);
	case 0x7597:     // setMarginTrackChange(FUN_00a1fd8c)
		m_ctx.setMarginTrackChange(a.toBool());
		return QVariant(0);
	case 0x759b: {   // hexBase 读(语料 0x759a 邻位;vt 读)
		return QVariant(m_ctx.hexBase);
	}
	case 0x75d6: {   // setWordSeparators(FUN_009279ec:flag 选 +0x288/+0x280 槽)
		const QString text = b.toString();
		if (a.toBool())
			m_separators1 = text;   // +0x288
		else
			m_separators0 = text;   // +0x280
		return QVariant(0);
	}
	default:
		// 其余 ~44 个 fork 特性(scrollbar marks/margin 链表/
		// std::string 返回族/hexBase…):真名与语义锚见
		// EDITOR-ENGINE-COMMANDS.md,按需逐个接
		(void)a; (void)b;
		return QVariant(0);
	}
}
