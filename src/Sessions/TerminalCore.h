#ifndef TERMINALCORE_H
#define TERMINALCORE_H

#pragma once

#include <cstddef>
#include <cstring>

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// The terminal screen interpreter core: called from SuperCommander's VT/ANSI
// slots via a two-hop forward chain (Commander +0x80 -> Screen +0x80 -> this).
// See TERMINAL-CORE.md for the evidence chain.
//
// Call chain (proven, moveCursorDown example):
//   SuperCommander::moveCursorDown   0x7c8cc6  (guard adapter)
//     -> Screen::moveCursorDown      0x7e483e  (alias forward)
//       -> TerminalCore::cursorDown  0x7a5588  (real logic)

struct Row;

// Row layout (offsets proven in FUN_007a538a / FUN_007a4c6c / FUN_007a3dfc):
// +0x00 flag byte (0x08 double-width line, 0x80 wrap pending), +0x02 flag
// word (0x40 dwl travels with scrolled source rows), +0x0c cell count,
// +0x10 cell array (0x20 stride), +0x50 spare buffer.
struct Row {
	unsigned short flags;     // +0x00 (bit0/1 changed, bit3 dwl, bit5 dhb, bit7 wrap)
	unsigned short wordFlags; // +0x00 as u16: byte1 bit0 = continuation
	unsigned char byte1;      // +0x01 (DECSACE extent bit0 etc.)
	int length;               // +0x0c cell count
	char _pad0[4];           // +0x10 area
	void *cells;              // +0x10
	void *attrArray;          // +0x40 glyph-head array (2-byte stride)
	void *style;              // +0x50 render style (pushLinesToScrollback)
	void *spare;              // +0x58 spare
};

// Tabstop bitmap embedded at core +0x18 (FUN_007e52f0): payload at +0x10,
// bit for column N lives at byte (N>>3)+1 (FUN_007e5c98 / FUN_007e52fc).
struct Tabstops
{
	unsigned char *payload;

	bool test(int column) const;   // FUN_007e5c98 bit extraction
	void set(int column, bool on); // FUN_007e52fc / FUN_007e5df0
	void clear();                  // FUN_007e5df0 mode 3 (clear all)
	void resizeDefault(int cols);  // QBitArray::resize + every-8th re-arm (007a604a tail)
};

// Rect used by the rectangular-area workers (FUN_007a6ab0 family)
struct Rect { int top, left, bottom, right; };

class TerminalCore
{
public:
	TerminalCore();   // buffer state zero-init (FUN_007a69b8 family)

	// --- flags (+0x00) ---------------------------------------------------
	// bit3 (0x08): cursor moved since last flush
	// bit5 (0x20): horizontal margins active — scroll operates on cells
	//              inside [leftMargin..rightMargin] instead of whole rows
	// bit6 (0x40): origin mode (DECOM/DECSLRM) — clamps against margins
	// bit7 (0x80): wide-char wrap pending (FUN_007e4b9a checks sign)
	unsigned short m_flags;

	// --- saved cursor block (+0x20..+0x68, saveCursor FUN_007a5c70) -------
	int m_savedCursorY;           // +0x20
	int m_savedCursorX;           // +0x24
	unsigned char m_saveByte28;   // +0x28: bit0 = "saved", packed flag bits
	unsigned char m_saveByte29;   // +0x29: packed flag bits
	unsigned long long m_saved2;  // +0x30 mirror of the SGR bits (+0xb8)
	int m_savedCharsets[4];       // +0x58 charset slot snapshots

	// --- screen buffer (+0x74/+0x78) --------------------------------------
	// +0x78: array of row objects, +0x74: row count (FUN_007a4332).
	// Row layout: +0x0c = cell count, +0x10 = cell array (0x20 stride,
	// 32 bytes per cell: glyph + SGR attributes + flags), +0x40 = spare
	// buffer freed on row destruction.
	int m_rowCount;               // +0x74 (FUN_007a4b4a)
	int m_rowCapacity;            // +0x70 (doubling growth, FUN_007a604a)
	struct Row **m_rows;          // +0x78: array of row POINTERS (8-byte stride, FUN_007a44f8)

	// --- reset state group (+0x50..+0x66, FUN_007a4b0a reset sequence) ---
	void *m_50;
	unsigned char m_58;
	void *m_5c;
	int m_66;                     // reset writes 2

	// --- blank template / charset / SGR ------------------------------------
	void *m_blankRowTemplate;     // +0xa0: template for reset rows (FUN_007a3c9a)
	unsigned long long m_blankTemplateSgr;  // +0xa0 as SGR (FUN_007a45f6)
	void *m_charsetSaved;         // +0x38: saved SGR/charset state (DECSC)
	void *m_sgrState;             // +0x88: current SGR/charset state
	unsigned char m_flags2;       // +0xb0: G-led style flags (DECSC packs)
	// +0xb8 m_sgrBits is declared below; DECSC mirrors it to +0x30
	// (m_saved2), and the write template carries it raw at cell+0x18

	// --- tabstops (+0x18) ---------------------------------------------------
	Tabstops m_tabstops;
	bool isTabstop(int column) const { return m_tabstops.test(column); }

	// --- cursor & scroll region --------------------------------------------
	int m_cursorY;                // +0xc4 (FUN_007a538a)
	int m_cursorX;                // +0xc8 (FUN_007a538a)

	// --- 光标/行操作一行真身(TERMINAL-CORE.md 地址表)---
	void removeRow(int y);                     // FUN_007a463c
	int m_scrollRegionTop;        // +0xd0 (FUN_007a4672)
	int m_scrollRegionBottom;     // +0xd4 (FUN_007a4bb4)
	int m_leftMargin;             // +0xd8 (FUN_007a493c)
	int m_rightMargin;            // +0xdc (FUN_007a490e)
	int m_columnCount;            // +0xe4 (FUN_007a4906)
	int m_cursorStyle;            // +0xcc (FUN_007a45ee)
	void *m_workRow;              // +0xa8 cached working row (FUN_007a463c)
	unsigned long long m_sgrBits; // +0xb8 SGR attribute state (FUN_007ef95c)
	int m_charsetSlot3;           // +0xc0 (VT52 graphics charset, FUN_007e5a90)

	// --- sizes & limits -----------------------------------------------------
	int rowCount() const;                  // FUN_007a4b4a
	int columnCount() const;               // FUN_007a4906
	void makeRow(struct Row *row, int cols);        // FUN_007a5670 (Row ctor)
	int scrollRegionBottomLimit() const;   // FUN_007a4bb4 (raw +0xd4)
	int scrollRegionTopLimit() const;      // FUN_007a4be2 (clamped under bottom-1)
	int scrollRegionHeight() const;        // FUN_007a4c48 (bottom-top+1)
	int regionWidth() const;               // FUN_007a49a2 (right-left+1)
	int leftMargin() const;                // FUN_007a493c (clamped under right-1)
	int rightMargin() const;               // FUN_007a490e (defaults to width-1)
	int originLeft() const;                // FUN_007a4962 (0 or leftMargin)
	int originRight() const;               // FUN_007a49c6 (width-1 or rightMargin)
	int originTop() const;                 // FUN_007a4c08 (0 or topLimit)
	int originBottom() const;              // FUN_007a5304 (rowCount-1 or bottomLimit)
	bool inScrollRegion(int line) const;   // FUN_007a4c16

	// --- cursor movement ------------------------------------------------------
	void cursorDown(int lines);            // FUN_007a5588
	void cursorUp(int lines);              // FUN_007a55d2
	void cursorForward(int columns);       // FUN_007a54b4
	void cursorBackward(int columns);      // FUN_007a546c
	void moveColumnBy(int delta);          // FUN_007a5460 (no clamp)
	void moveLineBy(int delta);            // FUN_007a557c (no clamp)
	void setCursorY(int y);                // FUN_007a5570
	void setCursorYX(int y, int x);        // FUN_007a538a (the real mover)
	void setCursorX(int x);                // FUN_007a5452
	void moveCursorRaw(int y, int x);      // FUN_007a538a (clamp to screen)
	void moveCursor(int y, int x);         // FUN_007a54f8 (clamp to origin bounds)

	// --- rows ------------------------------------------------------------------
	struct Row *row(int y);                // FUN_007a44f8 (m_rows[y])
	int rowLength(struct Row *row) const;  // FUN_007a3dfc (+0x0c)
	void setRowLength(struct Row *row, int length);          // FUN_007a5ff2
	void setRowFlags(struct Row *row, int bits);             // FUN_007a3dc0
	void resetRow(struct Row *row, void *templateRow);       // FUN_007a3c9a
	void resetWrapPending();               // FUN_007a4564
	void markDirty(int level);             // FUN_007a454e
	void markLine(int line, int arg);      // FUN_007a463c
	int lastContentRowCount() const;       // FUN_007a5618 (rows to last non-blank)

	// --- save/restore cursor (DECSC/DECRC) --------------------------------------
	bool hasSavedCursor() const;           // FUN_007a44da (+0x28 bit0)
	void saveCursor();                     // FUN_007a5c70
	void restoreCursor();                  // FUN_007a5d20

	// --- erase ---------------------------------------------------------------------
	int eraseCells(int line, int from, unsigned short attr, int count,
	               bool skipProtected, bool selective,
	               void *blankTemplate);                    // FUN_007a596c
	int rowEraseCells(struct Row *row, int from, unsigned short attr,
	                  int count, bool skipProtected, bool selective,
	                  void *blankTemplate);                    // FUN_007a579c

	// --- scroll ---------------------------------------------------------------------
	void scrollRegion(int top, int count, bool down, bool fillTemplate);  // FUN_007a4c6c
	void scrollHorizontal(int delta);      // FUN_007a68ae

	// --- rectangular areas (DECERA/DECFRA/DECRARA/DECCRA workers) ---------------------
	bool setCellRaw(int y, int x, const void *cell);           // FUN_007a5b36
	void setRowCell(struct Row *row, int x, const void *cell, void *aux);  // FUN_007a5aac
	void eraseRect(int top, int left, int bottom, int right, bool selective);   // FUN_007a6d98
	void changeRectAttrs(int top, int left, int bottom, int right, int what);   // FUN_007a748e
	void reverseRectAttrs(int top, int left, int bottom, int right, int what);  // FUN_007a721e
	void fillRect(int top, int left, int bottom, int right,
	              const void *cell, void *aux);                                 // FUN_007a6eec

	// --- margins / reset ---------------------------------------------------------------
	void setTopBottomMargins(int top, int bottom); // FUN_007a4672 (DECSTBM core)
	void setCursorStyle(int style);                // FUN_007a45ee (+0xcc)
	int cursorStyle() const { return m_cursorStyle; }   // +0xcc 读取
	unsigned int cursorBlinkBit() const;           // FUN_007a44c0 (0x2b mask)
	void rowHook(struct Row *row, int arg);        // FUN_007a3dde
	int cursorStyleBit() const;                    // FUN_007a44c0: (0x2b >> style) & 1
	void reset();                                  // FUN_007a4b0a

	// --- insert/delete (0x7e3a aliases forward here) ---
	void insertCharacter(int count);      // FUN_007a6782 (ICH)
	void insertColumn(int count);         // FUN_007a6822 (DECIC)
	void insertLine(int count);           // FUN_007a5290 (IL)
	void deleteCharacter(int count);      // FUN_007a65d2 (DCH)
	void deleteColumn(int count);         // FUN_007a6672 (DECDC)
	void deleteLine(int count);           // FUN_007a5220 (DL)
	void setSgrState(unsigned long long sgr);       // FUN_007a45f6
	void setAttributeChangeExtent(int extent);       // FUN_007a4518
	void resetViewport();                            // FUN_007a4aea
	void clearMargins(int left, int right);          // FUN_007a4a98
	bool columnInRange(int column) const;            // FUN_007a4970

	// --- cited helpers (call sites proven, bodies not yet transcribed) ---
	void copyState(void **dst, void **src);        // FUN_007aa2e2 (16-byte state copy)
	int charsetSlot(int i) const;                  // FUN_00801a46
	void setCharsetSlot(int i, int v);             // FUN_00803470
	bool slot0Allowed(int tableId) const;          // FUN_00802c80
	const void *charsetConfigRoot() const;         // FUN_00802bda
	int m_charsetSlots[4];    // manager slots G0..G3 (FUN_00801a46)
	int m_userPreferredSet;   // manager +0x10 (FUN_00801a3e)
	bool charsetDisabled(int tableId) const;       // FUN_008034a4 (Screen.h 同名)
	void resetCharsetSlots();  // FUN_00802baa
	bool rowHasContent(struct Row *row) const;     // FUN_007a4a06
	int rowUsedWidth(struct Row *row, int withStyle) const;   // FUN_007a41d6 — cited
	void copyRowFromTemplate(struct Row *row, void *templateRow);  // FUN_007a3c9a tail
	int cellFlags(struct Row *row, int i) const;   // FUN_007a3c68
	void writeBlankCell(struct Row *row, int i, unsigned short attr, void *blankTemplate);
	void copyRowCells(struct Row *dst, struct Row *src, int from, int count);
	void preserveRowFlags(struct Row *dst, struct Row *src);
	void clearRowCells(struct Row *row, int from, int count);
	void notifyChanged(int level);                 // FUN_007a4532
	void rowDeleteCells(struct Row *row, int at, int count);          // FUN_007a5dce
	void rowInsertBlanks(struct Row *row, int at, int count, void *sgr);  // FUN_007a641a
	void copyCell(void *dst, const void *src);     // FUN_007aa2e2 (deep, aux clone)
	void buildBlankCell(unsigned char blank[0x20], void *sgrCtx);  // FUN_007aa2e2
	void writeCell(void *dst, const unsigned char blank[0x20]);
	void growRowArrays(void *arrayHeader, int newLen, int minCap);  // FUN_007aa3a6
	static void resizeUshortVector(int *hdr, int len, int cap);  // FUN_007aa1bc
	void resizeCore(int rows, int cols);   // FUN_007a604a — cited (row reflow)
	// lastNonEmptyRow == lastContentRowCount (FUN_007a5618, alias)
	int lastNonEmptyRow() const { return lastContentRowCount(); }
	void cloneGlyphPayload(void *dstAux, const void *srcPayload, int words);  // FUN_007aa28a
	void *cellAt(struct Row *row, int x);          // FUN_007a3c1a: cells + x*0x20
	unsigned short *attrHeadAt(struct Row *row, int x);  // FUN_007a3c2a: attrArray + x*2
	void *collectRectCells(const void *rect, void *outList, int mode);  // FUN_007a6ab0
	// mode 2 honors DECSACE (flags byte1 bit0: stream vs rectangle) and
	// offsets the rect by originTop/originLeft in origin mode (0x40)
	void notifyRectChanged(const void *rect, int arg);   // FUN_007a4590
	void *parseAttrList(const void *params, void *out);  // FUN_007a712b
	void copyRect(int top, int left, int bottom, int right, long long packedDest);  // FUN_007a7776
};

#endif // TERMINALCORE_H
