#include "TerminalCore.h"

// Bodies transcribed from decompilation; comments cite the source
// function. Phase-1 restoration (reference, not compiled).

int TerminalCore::scrollRegionBottomLimit() const
{
	// FUN_007a4bb4
	return m_scrollRegionBottom;
}

int TerminalCore::columnLimit() const
{
	// FUN_007a490e — column counterpart of the row clamp
	return m_cursorX;
}

void TerminalCore::cursorDown(int lines)
{
	// FUN_007a5588
	if (lines < 1)
		return;
	int newY = m_cursorY + lines;
	if (m_flags & 0x40) { // DECOM: clamp to scroll region
		const int bottom = scrollRegionBottomLimit();
		if (m_cursorY <= bottom && bottom < newY)
			newY = bottom;
	}
	setCursorY(newY);
}

void TerminalCore::cursorForward(int columns)
{
	// FUN_007a54b4 — mirror structure of cursorDown (X/Y symmetry)
	if (columns < 1)
		return;
	int newX = m_cursorX + columns;
	if (m_flags & 0x40) { // DECOM: clamp to column limit
		const int right = columnLimit();
		if (m_cursorX <= right && right < newX)
			newX = right;
	}
	setCursorX(newX);
}

void TerminalCore::setTopBottomMargins(int top, int bottom)
{
	// FUN_007a4672 (DECSTBM)
	m_scrollRegionTop = top;
	m_scrollRegionBottom = bottom;
	if (bottom > 0)
		m_scrollRegionTop = top < bottom - 2 ? top : bottom - 2;
}

void TerminalCore::reset()
{
	// FUN_007a4b0a (resetSoft): original byte sequence preserved
	m_flags = 7;
	m_58 &= 0xcf;
	m_5c = nullptr;
	m_50 = nullptr;
	m_66 = 2;
}
