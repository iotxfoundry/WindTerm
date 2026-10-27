#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#pragma once

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// TextEdit = command-forwarding shell (same sendEditor architecture as
// TextView): 51 of 66 slots are direct command forwards; the remaining
// real logic bodies are cited below. metacall: 0x8f267a.
// Full table: TEXTEDIT-COMMANDS.md.

#include <QVariant>

class TextEdit
{
public:
	void *m_editor;      // +0x58: editor backend (vtable slot 0x1c0)
	QVariant m_result;

	// FUN_005b5d68: (*(*editor)->vtable[0x1c0])(result, editor, cmd, w, l)
	void sendEditor(QVariant &result, int command, const QVariant &w,
	                const QVariant &l);

	void cancelSnippet()
	{
		// WT 0x75ba
		sendEditor(m_result, 0x75ba, QVariant(), QVariant());
	}

	void canExpandSnippet()
	{
		// WT 0x75bb
		sendEditor(m_result, 0x75bb, QVariant(), QVariant());
	}

	void canSelectSnippetStop(const QVariant & arg0)
	{
		// WT 0x75bc
		sendEditor(m_result, 0x75bc, QVariant(), arg0, QVariant());
	}

	void comment()
	{
		// EXT 0x4e4b
		sendEditor(m_result, 0x4e4b, QVariant(), QVariant());
	}

	void convertSpaceToTab()
	{
		// EXT 0x4ee5
		sendEditor(m_result, 0x4ee5, QVariant(), QVariant());
	}

	void convertTabToSpace()
	{
		// EXT 0x4ee6
		sendEditor(m_result, 0x4ee6, QVariant(), QVariant());
	}

	void cut()
	{
		// SCI SCI_CUT
		sendEditor(m_result, 0x881, QVariant(), QVariant());
	}

	void decreaseLineIndent(const QVariant & arg0)
	{
		// EXT 0x4e2f
		sendEditor(m_result, 0x4e2f, QVariant(), arg0, QVariant());
	}

	void decreaseLineIndent()
	{
		// EXT 0x4e2f
		sendEditor(m_result, 0x4e2f, QVariant(), QVariant());
	}

	void deleteBack()
	{
		// SCI SCI_DELETEBACK
		sendEditor(m_result, 0x916, QVariant(), QVariant());
	}

	void deleteChar()
	{
		// SCI SCI_CLEAR
		sendEditor(m_result, 0x884, QVariant(), QVariant());
	}

	void deleteLine()
	{
		// EXT 0x4ed9
		sendEditor(m_result, 0x4ed9, QVariant(), QVariant());
	}

	void deleteLineToEnd()
	{
		// EXT 0x4edb
		sendEditor(m_result, 0x4edb, QVariant(), QVariant());
	}

	void deleteLineToStart()
	{
		// EXT 0x4eda
		sendEditor(m_result, 0x4eda, QVariant(), QVariant());
	}

	void deleteWord()
	{
		// EXT 0x4edc
		sendEditor(m_result, 0x4edc, QVariant(), QVariant());
	}

	void deleteWordToEnd()
	{
		// EXT 0x4ede
		sendEditor(m_result, 0x4ede, QVariant(), QVariant());
	}

	void deleteWordToStart()
	{
		// EXT 0x4edd
		sendEditor(m_result, 0x4edd, QVariant(), QVariant());
	}

	void duplicate()
	{
		// EXT SCI_SELECTIONDUPLICATE
		sendEditor(m_result, 0x9a5, QVariant(), QVariant());
	}

	void expandSnippet(const QVariant & arg0)
	{
		// WT 0x75bd
		sendEditor(m_result, 0x75bd, QVariant(), arg0, QVariant());
	}

	void expandSnippet()
	{
		// WT 0x75bd
		sendEditor(m_result, 0x75bd, QVariant(), QVariant());
	}

	void formatSelection()
	{
		// EXT 0x4e26
		sendEditor(m_result, 0x4e26, QVariant(), QVariant());
	}

	void increaseLineIndent(const QVariant & arg0)
	{
		// EXT 0x4e2e
		sendEditor(m_result, 0x4e2e, QVariant(), arg0, QVariant());
	}

	void increaseLineIndent()
	{
		// EXT 0x4e2e
		sendEditor(m_result, 0x4e2e, QVariant(), QVariant());
	}

	void insertData(const QVariant & arg0, const QVariant & arg1)
	{
		// WT 0x7555
		sendEditor(m_result, 0x7555, QVariant(), arg0, arg1, QVariant());
	}

	void isSnippetMode()
	{
		// WT 0x75bf
		sendEditor(m_result, 0x75bf, QVariant(), QVariant());
	}

	void isTextMultiChangeEventEnabled()
	{
		// WT 0x757b
		sendEditor(m_result, 0x757b, QVariant(), QVariant());
	}

	void makeInverseCase()
	{
		// EXT 0x4e22
		sendEditor(m_result, 0x4e22, QVariant(), QVariant());
	}

	void makeLowerCase()
	{
		// SCI SCI_LOWERCASE
		sendEditor(m_result, 0x924, QVariant(), QVariant());
	}

	void makeTitleCase()
	{
		// EXT 0x4e21
		sendEditor(m_result, 0x4e21, QVariant(), QVariant());
	}

	void makeUpperCase()
	{
		// SCI SCI_UPPERCASE
		sendEditor(m_result, 0x925, QVariant(), QVariant());
	}

	void newLine()
	{
		// SCI SCI_NEWLINE
		sendEditor(m_result, 0x919, QVariant(), QVariant());
	}

	void redo(const QVariant & arg0)
	{
		// SCI SCI_REDO
		sendEditor(m_result, 0x7db, QVariant(), arg0, QVariant());
	}

	void redo()
	{
		// SCI SCI_REDO
		sendEditor(m_result, 0x7db, QVariant(), QVariant());
	}

	void replaceData(const QVariant & arg0, const QVariant & arg1, const QVariant & arg2)
	{
		// WT 0x7557
		sendEditor(m_result, 0x7557, QVariant(), arg0, arg1, arg2, QVariant());
	}

	void selectSnippetStop(const QVariant & arg0)
	{
		// WT 0x75c0
		sendEditor(m_result, 0x75c0, QVariant(), arg0, QVariant());
	}

	void selectSnippetStop()
	{
		// WT 0x75c0
		sendEditor(m_result, 0x75c0, QVariant(), QVariant());
	}

	void setTextMultiChangeEventEnabled(const QVariant & arg0)
	{
		// WT 0x757c
		sendEditor(m_result, 0x757c, QVariant(), arg0, QVariant());
	}

	void tabify()
	{
		// EXT 0x4ee3
		sendEditor(m_result, 0x4ee3, QVariant(), QVariant());
	}

	void transposeChar(const QVariant & arg0)
	{
		// EXT 0x4ed6
		sendEditor(m_result, 0x4ed6, QVariant(), arg0, QVariant());
	}

	void transposeChar()
	{
		// EXT 0x4ed6
		sendEditor(m_result, 0x4ed6, QVariant(), QVariant());
	}

	void transposeWord(const QVariant & arg0)
	{
		// EXT 0x4ed7
		sendEditor(m_result, 0x4ed7, QVariant(), arg0, QVariant());
	}

	void transposeWord()
	{
		// EXT 0x4ed7
		sendEditor(m_result, 0x4ed7, QVariant(), QVariant());
	}

	void transposeLine(const QVariant & arg0)
	{
		// EXT 0x4ed8
		sendEditor(m_result, 0x4ed8, QVariant(), arg0, QVariant());
	}

	void transposeLine()
	{
		// EXT 0x4ed8
		sendEditor(m_result, 0x4ed8, QVariant(), QVariant());
	}

	void trimLeading(const QVariant & arg0, const QVariant & arg1)
	{
		// EXT 0x4e37
		sendEditor(m_result, 0x4e37, QVariant(), arg0, arg1, QVariant());
	}

	void trimLeading(const QVariant & arg0)
	{
		// EXT 0x4e37
		sendEditor(m_result, 0x4e37, QVariant(), arg0, QVariant());
	}

	void trimLeading()
	{
		// EXT 0x4e37
		sendEditor(m_result, 0x4e37, QVariant(), QVariant());
	}

	void uncomment()
	{
		// EXT 0x4e4c
		sendEditor(m_result, 0x4e4c, QVariant(), QVariant());
	}

	void undo(const QVariant & arg0)
	{
		// SCI SCI_UNDO
		sendEditor(m_result, 0x880, QVariant(), arg0, QVariant());
	}

	void undo()
	{
		// SCI SCI_UNDO
		sendEditor(m_result, 0x880, QVariant(), QVariant());
	}

	void untabify()
	{
		// EXT 0x4ee4
		sendEditor(m_result, 0x4ee4, QVariant(), QVariant());
	}
	// --- real logic bodies (classified 2026-10-27) ---
	void duplicate()
	{
		// FUN_005cb7d4: selection -> QTextCodec::fromUnicode -> send
		sendText(codec()->fromUnicode(selectionText()));   // FUN_005cb75a
	}
	void setFlagOne()   // FUN_005cc4d4
	{
		toggleState(1);    // FUN_005cc4a0
	}
	void setFlagZero()  // FUN_005cc578
	{
		toggleState(0);    // FUN_005cc4a0
	}
	void sendCodecTriple(const QVariant &a, const QVariant &b)  // FUN_005cc7f6
	{
		sendEditor(m_result, 0x7557, codec()->fromUnicode(a.toString()),
		           b);   // via FUN_005cc6f0
	}
	void applyFlag(bool on)  // FUN_005cc0ac
	{
		applyFlagImpl(on);   // FUN_005beeac
	}

	// thin-wrapper delegates
	void sendText(const QByteArray &data);       // FUN_005cb75a
	void toggleState(int which);                 // FUN_005cc4a0
	void applyFlagImpl(bool on);                 // FUN_005beeac
	class QTextCodec *codec();
	// 0x5cc94e/0x5d28b6: 32.6K twins - config-map builders (QMap+QVariant
	//   storm, int-arg variant; same family as 0x5d0a4e: ~80% inlined
	//   QMap destructor noise, e.g. "shuffle" key at 0xd0cf05)
	// 0x5cebe6: 31.2K config-map builder (same family)
	// 0x5d0a4e: 31K config-map builder ("reverse"/"type" keys) - classified
	//   --- giant config builders NOT transcribed (no business value in
	//   the destructor-dominated bodies)

	// insert(canSelectSnippetStop,position) (0x5cb7d4)
	// redoList() (0x5cc4d4)
	// removeDuplicateLines(?) (0x5cc94e)
	// replace(canSelectSnippetStop,decreaseLineIndent,end) (0x5cc7f6)
	// reverseLines() (0x5d0a4e)
	// setUndoEnabled(cancelSnippet) (0x5cc0ac)
	// shuffleLines() (0x5cebe6)
	// sortLines(?) (0x5d28b6)
	// trim(canSelectSnippetStop,startLine) (0x5cc406)
	// trim(canSelectSnippetStop) (0x5cc406)
	// trim() (0x5cc406)
	// trimTrailing(canSelectSnippetStop,startLine) (0x5cc38a)
	// trimTrailing(canSelectSnippetStop) (0x5cc38a)
	// trimTrailing() (0x5cc38a)
	// undoList() (0x5cc578)
};

#endif // TEXTEDIT_H
