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
	void *m_obj10a0;      // +0x10a0 (param_2[0x214]) — 0x7543 success path
	void *m_marginBegin;  // +0xd58 (param_2[0x1ab]) margin node list
	void *m_marginEnd;    // +0xd60 (param_2[0x1ac]) stride 24
	char m_pairEnabled;   // +0xd92 (0x7583)
	char m_docFlag1067;   // engine +0x1067 (0x7543 mode gate, ==2 check)
	unsigned char m_flags1db; // +0x1db bitfield (0x755c/0x755d)
	int m_intDd0;         // +0xdd0 (0x755f)
	double m_zoomFactor;  // +0xdd8 (0x7560)
	int m_intD80;         // +0xd80 (0x7e4/0x7e5, repaint on change)
	bool m_flagEc5;       // +0xec5 (0x7f2/0x7f3)
	bool m_flagEc2;       // +0xec2 (0x873 change-detect + repaint)
	int m_intFd4;         // +0xfd4 (0x857)
	int m_intEa4;         // +0xea4 pair (0x862 write / sibling read)
	int m_intEa8;         // +0xea8 (0x864)
	char m_gate1128;      // +0x1128 ([0x225]) — coordinate mode gate
	int m_mod1118;        // +0x1118 ([0x223]) — column modulo base
	void *m_styleCtx;     // +0x8: style/hit-test context (packed 32-slot
	                      // int table, 11-byte stride at 0x7f8)
	// doc object (+0x1098) internal offsets: tabSize@+0x270 (0x75c4),
	// indent@+0x274 (0x75c2/c5), flag279@+0x279 (0x75c3/c6)

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
	QVariant cmdRenderPixmap(qreal scale);          // 0x7544 CMD_30020 (QPixmap)
	bool cmdVtE8Probe(int which);                   // 0x7546/0x7548 vt+0xe8
	void cmdVtD0();                                 // 0x754a vt+0xd0
	void cmdDocMark(long long pos);                 // 0x7543 (FUN_0092f0f6)
	bool cmdDocFlag();                              // 0x7556 (FUN_00927ec8)
	QString cmdDocCollect(const QVariantList &a);   // 0x7559 (FUN_00929076)
	void cmdDocSetString(const QString &s);         // 0x755a (FUN_00927efc)
	int cmdFlag1dbBit1();                           // 0x755c
	int cmdFlag1dbHigh();                           // 0x755d
	int cmdIntDd0();                                // 0x755f
	double cmdZoomFactor();                         // 0x7560
	void cmdSetBoolD5a0(bool on);                   // 0x7561 (FUN_00a2d5a0)
	void cmdCancelSnippet();                        // 0x75ba (FUN_00a28ee8)
	long long cmdVtE0Read(int arg);                 // 0x75b3 vt+0xe0 → +0x40
	bool cmdProbe28398();                           // 0x75af (FUN_00a28398)
	int cmdProbe224e4();                            // 0x75b1 (FUN_00a224e4)
	bool cmdSetTabSize(int n);                      // 0x75c4 CMD_30148
	int cmdIndentSize();                            // 0x75c2
	bool cmdSetIndentSize(int n);                   // 0x75c5
	bool cmdDocFlag279();                           // 0x75c3
	void cmdSetDocFlag279(bool on);                 // 0x75c6
	void cmdSetWordSeparators(const QString &s, bool keep);  // 0x75d6 CMD_30166
	void cmdSetRegister(long long key);             // 0x75cb (FUN_009301a8)
	QVariant cmdGetRegisterList();                  // 0x75c9 (FUN_00926b28)
	bool cmdRegisterFlag();                         // 0x75ca (FUN_00926afe)
	long long cmdUllFrom10a0(long long v);          // 0x75cf (FUN_009589f0)
};

#endif // EDITORENGINE_H
