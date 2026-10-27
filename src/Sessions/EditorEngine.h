#ifndef EDITORENGINE_H
#define EDITORENGINE_H

#pragma once

#include <QByteArray>
#include <QList>
#include <QString>
#include <QVariant>

// Reconstructed from WindTerm 2.7.0 disassembly. The editor backend
// behind TextView+0x58 — a Scintilla-derived engine (RTTI: Sci* event
// classes). Two-level command dispatch:
//   level 1  0x00a5205e (1113B): SCI fast range 0x833-0x8a6 + 0x7531/2
//   level 2  0x00a418c4 (37951B): full SCI/EXT/WT space — this file
// Signature both levels:
//   QVariant* f(QVariant *ret, Engine*, uint cmd, QVariant *a, QVariant *b)
// = the sendEditor (FUN_005b5d68) vtable+0x1c0 tail-call landing shape.
// Full command map: EDITOR-ENGINE-COMMANDS.md (336 leaves).

class EditorEngine
{
public:
	// --- object layout (partial, offsets proven in the dispatcher) ---
	void *vtable;
	void *m_doc;          // +0x1098 (param_2[0x213]) — buffer/document
	void *m_field10a8;    // +0x10a8 (param_2[0x215]) — 0x7548 path
	bool m_flag11e8;      // +0x11e8
	long long m_pos11f0;  // +0x11f0
	void *m_sub1148;      // +0x1148 (FUN_00a740xx cluster)
	void *m_ptr1240;      // +0x1240
	char m_flag1b2;       // +0x1b2
	int m_style;          // +0x1238 (0x840/0x834 writes)
	int m_stylePair;      // +0x123c (0x83c write / 0x83d read)
	void *m_foldMgr;      // +0x10b8 (param_2[0x217]) — fold operations
	void *m_pairObj;      // +0x10e0 (param_2[0x21c]) — pair highlight
	void *m_obj10c8;      // +0x10c8 (param_2[0x219]) — 0x75b5 path
	void *m_marginBegin;  // +0xd58 (param_2[0x1ab]) margin node list
	void *m_marginEnd;    // +0xd60 (param_2[0x1ac]) stride 24
	char m_pairEnabled;   // +0xd92 (0x7583)

	// --- dispatchers (the two vtable+0x1c0 landing functions) --------
	QVariant dispatchLevel1(uint cmd, const QVariant &a, const QVariant &b);
	QVariant dispatchLevel2(uint cmd, const QVariant &a, const QVariant &b);

	// edit transaction: editctx_beginIter(ctx, engine, &flags) at
	// 0x7551; flags bit layout seen: 0x2 (no cursor move) / 0x200
	// (move cursor to end); ctx committed by FUN_00a161d8

	// --- level-2 command bodies (first batch) -----------------------
	void cmdAppendText(const QVariantList &args);   // 0x7551 CMD_30033
	void cmdReplaceText(const QVariantList &args);  // 0x7552 (5-arg form)
	void cmdSubString(long long start, long long end, QVariant *ret);  // 0x7554
	void cmdIndexOf(const QVariantList &args, QVariant *ret);   // 0x757e CMD_30078
	void cmdSetFlagF8(int which, bool on);          // 0x754b/0x754c vt+0xf8
	void cmdGotoPosition(long long pos);            // 0x75ac CMD_30124
	void cmdFoldRange(long long start, long long end);  // 0x756f CMD_30063
	void cmdFoldLine(long long line, bool expand);  // 0x7571 CMD_30065
	QByteArray cmdEolString(long long eol);         // 0x7577 CMD_30071
	void cmdSetEol(int eol);                        // 0x757a (FUN_00a21b6a)
	QStringList cmdMargins();                       // 0x7591 CMD_30097
	QString cmdSelectionText(const QString &sep, bool useSep);    // 0x75b8 CMD_30136
	QByteArray cmdSelectionTextBytes(const QByteArray &sep, bool useSep);  // 0x75b7
	void cmdSetPairHighlight(bool on);              // 0x7583
};

#endif // EDITORENGINE_H
