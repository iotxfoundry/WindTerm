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
	// WindTerm 扩展命令(逆向:EDITOR-ENGINE-COMMANDS.md EXT/WT 段)。
	// 已知锚点(选录;真名与地址见对照文档):
	//  0x7545 addScrollBarMark   0x7551 appendText
	//  0x7591 margins()          0x75c4 setTabSize
	//  0x75d6 setWordSeparators …其余见文档
	(void)cmd; (void)a; (void)b;
	return QVariant(0);
}
