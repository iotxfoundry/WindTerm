#ifndef EDITORENGINE_H
#define EDITORENGINE_H

#pragma once

#include "EditorContext.h"
#include <QByteArray>
#include <QList>
#include <QPoint>
#include <QRect>
#include <QString>
#include <QVariant>

class ScintillaEditBase;

// Reconstructed WindTerm editor backend — HYBRID architecture (2026-10-28):
//   standard SCI_* (cmd <= 4033)  → delegated to REAL Scintilla 4.4.6
//                                   (src/Scintilla, static libs)
//   WindTerm EXT (20163-20228)    → custom layer below (fork features)
//   WindTerm WT  (30001-30166)    → custom layer
// Reverse-engineered internals (selection transactions, runnodes,
// gap-buffer lookups…) were retired with the delegation; the forensic
// record lives in EDITOR-ENGINE-COMMANDS.md / EDITOR-SCINTILLA-MAP.md.
class EditorEngine
{
public:
	EditorEngine();
	~EditorEngine();

	// sendEditor landing shape (was vtable+0x1c0): (ret, engine, cmd, a, b)
	QVariant dispatch(uint cmd, const QVariant &a = QVariant(),
	                  const QVariant &b = QVariant());

	// the real editor widget (ScintillaEditBase, offscreen-capable)
	ScintillaEditBase *widget() const { return m_edit; }

private:
	QVariant scintillaDelegate(uint cmd, const QVariant &a, const QVariant &b);
	QVariant customDispatch(uint cmd, const QVariant &a, const QVariant &b);

	EditorContext m_ctx;          // 编辑器上下文状态(Phase-3 模型)
	ScintillaEditBase *m_edit;
	// 分隔符双槽(FUN_009279ec:+0x280/+0x288;语义为词/行分隔符组)
	QString m_separators0;
	QString m_separators1;   // owned
};

#endif // EDITORENGINE_H
