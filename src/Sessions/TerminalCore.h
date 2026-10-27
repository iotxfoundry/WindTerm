#ifndef TERMINALCORE_H
#define TERMINALCORE_H

#pragma once

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// The terminal screen interpreter core: called from SuperCommander's
// VT/ANSI slots via a two-hop forward chain (Commander +0x80 -> Screen
// +0x80 -> this). See TERMINAL-CORE.md for the evidence chain.
//
// Call chain (proven, moveCursorDown example):
//   SuperCommander::moveCursorDown   0x7c8cc6  (1-line adapter)
//     -> Screen::moveCursorDown      0x7e483e  (1-line forward)
//       -> TerminalCore::cursorDown  0x7a5588  (real logic)

class TerminalCore
{
public:
	// --- flags (+0x00) ---------------------------------------------------
	// bit6 (0x40): DECOM-origin mode — cursor clamping against scroll
	// region (rows) or column limit (columns) is only applied when set.
	unsigned short m_flags;

	// --- screen buffer (+0x74/+0x78) --------------------------------------
	// +0x78: array of row objects, +0x74: row count (FUN_007a4332).
	// Row layout: +0x0c = cell count, +0x10 = cell array (0x20 stride,
	// 32 bytes per cell: glyph + SGR attributes + flags), +0x40 = spare
	// buffer freed on row destruction.
	int m_rowCount;               // +0x74
	struct Row *m_rows;           // +0x78

	// --- reset state group (+0x50..+0x66, FUN_007a4b0a reset sequence) ---
	void *m_50;
	unsigned char m_58;
	void *m_5c;
	int m_66;                     // reset writes 2

	// --- cursor & scroll region --------------------------------------------
	int m_cursorY;                // +0xc4 (FUN_007a5588)
	int m_cursorX;                // +0xc8 (FUN_007a54b4)
	int m_scrollRegionTop;        // +0xd0 (FUN_007a4672)
	int m_scrollRegionBottom;     // +0xd4 (FUN_007a4672)

	int scrollRegionBottomLimit() const;   // FUN_007a4bb4
	int columnLimit() const;               // FUN_007a490e

	void cursorDown(int lines);            // FUN_007a5588
	void cursorForward(int columns);       // FUN_007a54b4
	void setCursorY(int y);                // FUN_007a5570
	void setCursorX(int x);                // FUN_007a5452
	void setTopBottomMargins(int top, int bottom); // FUN_007a4672
	void reset();                          // FUN_007a4b0a
};

#endif // TERMINALCORE_H
