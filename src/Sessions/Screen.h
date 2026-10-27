#ifndef SCREEN_H
#define SCREEN_H

#pragma once

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// The VT screen object: SuperCommander's +0x80 target (the middle layer
// of the Commander -> Screen -> TerminalCore onion). Holds mode flags and
// the scrollback machinery; forwards buffer work to TerminalCore (+0x80).
// Batch 1: cursor movement, erase, scroll, tabs, margins, DECSC/DECRC.

#include "TerminalCore.h"

class QString;

class Screen
{
public:
	Screen();

	// --- object layout (offsets observed in the 0x7e functions) ----------
	void *m_viewSettings;           // +0x10 (scrollback limit at +0x104)
	TerminalCore *m_core;           // +0x80 visible screen core
	TerminalCore *m_history;        // +0x88 scrollback/history buffer
	void *m_scrollView;             // +0x98 scrollback view
	int m_savedCursorStyle;         // +0xa8 (-1 = none)
	unsigned short m_eraseAttr;     // +0x110 current SGR erase attribute
	bool m_leftRightMarginEnabled;  // +0x11a (DECLRMM)
	bool m_scrollbackEnabled;       // +0x11c
	bool m_eraseProtectedMode;      // +0x129 (DECSCA-protected erase skip)
	bool m_newlineMode;             // +0x12f (LNM)
	bool m_reverseWraparound;       // +0x134 (reverse wrap for backspace)

	// --- position & bounds (aliases into the core) ------------------------
	int currentColumn() const;         // FUN_007e368e (core +0xc8)
	int currentLine() const;           // FUN_007e369c (core +0xc4)
	int marginBottom() const;          // FUN_007e4426 -> FUN_007a4bb4
	int marginLeft() const;            // FUN_007e443e -> FUN_007a493c
	int marginRight() const;           // FUN_007e444a -> FUN_007a490e
	int marginTop() const;             // FUN_007e4456 -> FUN_007a4be2
	int originBottom() const;          // FUN_007e48b0 -> FUN_007a5304
	int originLeft() const;            // FUN_007e48c8 -> FUN_007a4962
	int originRight() const;           // FUN_007e48d4 -> FUN_007a49c6
	int originTop() const;             // FUN_007e48e0 -> FUN_007a4c08
	int windowColumns() const;         // FUN_007e5b96 -> FUN_007a4906
	int rowCount() const;              // FUN_007e5f18 -> FUN_007a4b4a

	// --- cursor commands ----------------------------------------------------
	void cursorMoveRaw(int y, int x);  // FUN_007e4f38 -> FUN_007a538a
	void moveCursor(int y, int x);     // FUN_007e4fdc -> FUN_007a54f8
	void moveCursorBackward(int n);    // FUN_007e4832 -> cursorBackward
	void moveCursorDown(int n);        // FUN_007e483e -> cursorDown
	void moveCursorForward(int n);     // FUN_007e484a -> cursorForward
	void moveCursorUp(int n);          // FUN_007e4856 -> cursorUp
	void carriageReturn();             // FUN_007e4fc8
	void backspace();                  // FUN_007e4f44
	void lineFeed();                   // FUN_007e55fc
	void horizontalTab();              // FUN_007e5d7c
	void backIndex();                  // FUN_007e4d48 (DECBI)
	void forwardIndex();               // FUN_007e4d82 (DECFI)
	void saveCursor();                 // FUN_007e4aa2 -> core DECSC
	void restoreCursor();              // FUN_007f6426 (DECRC + fallback)
	void setCursorStyle(int style, bool save);   // FUN_007e4ffa (DECSCUSR)
	void setCursorVisibility(int mode);          // FUN_007e5090 (DECTCEM)

	// --- tabs -----------------------------------------------------------------
	int nextTabstop(int from, int count) const;  // FUN_007e5d1e
	int prevTabstop(int from, int count) const;  // FUN_007e5ce4
	bool isTabstop(int column) const;            // FUN_007e5c98
	void setTabstop(int column, bool on);        // FUN_007e52fc (HTS)
	void clearTabstop(int mode);                 // FUN_007e5df0 (TBC)

	// --- scroll -----------------------------------------------------------------
	void indexDown();                  // FUN_007e55b6 (IND)
	void indexUp();                    // FUN_007e563e (RI)
	void nextLine();                   // FUN_007e562c (NEL)
	void scroll(int count, bool down, bool fillTemplate);  // FUN_007e5546
	void scrollHorizontal(int delta);  // FUN_007e4d3c -> FUN_007a68ae

	// --- erase -----------------------------------------------------------------
	void eraseCells(int line, int from, int count, bool selective);  // FUN_007e37f8
	void eraseCharacter(int count);    // FUN_007e385a (ECH)
	int eraseLine(int line, int mode, bool selective);  // FUN_007e4ba2 (EL)
	int eraseScreen(int mode, bool selective);          // FUN_007e606a (ED)

	// --- rectangular areas (DECERA/DECFRA/DECRARA/DECCRA) -----------------------
	void eraseRectangularArea(const QString &area, bool selective);  // FUN_007eb1c4
	void fillRectangularArea(const QString &fill);                   // FUN_007eb20a (DECFRA)
	void copyRectangularArea(const QString &area);                   // FUN_007eb2f2 (DECCRA)
	void changeAttributesInRectangularArea(const QString &area);     // FUN_007eb17e
	void reverseAttributesInRectangularArea(const QString &area);    // FUN_007eb2ac

	// --- margins -------------------------------------------------------------------
	void setTopBottomMargins(int top, int bottom);   // FUN_007e5fa6 (DECSTBM)
	void setLeftRightMargins(int left, int right);   // FUN_007e5bd4 (DECSLRM)

	// --- scrollback ------------------------------------------------------------------
	bool isScrollbackAllowed() const;          // FUN_007e4036
	void pushLinesToScrollback(int count);     // FUN_007e53b6
	void clearScrollback();                    // FUN_0091318c (ED 3)

	// --- cited helpers (call sites proven, bodies not yet transcribed) ---
	void setDecMode(const char *mode, bool on);      // FUN_007f5d2e
	int currentCursorStyle() const;                  // FUN_007e36aa
	void notifyCursorStyle(void *cursor, int shape); // FUN_00913592
	void setCursorVisible(bool on);                  // FUN_007e506a
	bool scrollbackModeCheck() const;                // FUN_007e4028
	void markRowErased(int row);                     // FUN_007e41ca
	void *buildFillAux();                            // FUN_007e4c90
	void parseRect(const QString &area, int *top, int *left, int *bottom, int *right);  // FUN_007eaeee
};

#endif // SCREEN_H
