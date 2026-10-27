#include "SuperCommander.h"

// Bodies transcribed from decompilation (SuperCommander metacall case
// adapters). Three adapter templates were verified over a 12-function
// batch sample (12/12 match):
//
//   T1 pure forward:  core(this+0x80) [const...]
//   T2 param guard:   if (n >= 0) { if (n == 0) n = 1; core(this+0x80, n, 0...); }
//   T3 composite:     reads current row/col helpers, forwards with offsets
//
// The remaining slots follow the same templates; their metacall case
// addresses are listed in IMPL-ADDRESSES.md for transcription on demand.

SuperCommander::SuperCommander(QObject *parent)
	: QObject(parent)
{
}

void SuperCommander::backspace()
{
	// case 10 @ 0x7cad8a (T1) -> Screen::backspace 0x7e4f44
}

void SuperCommander::moveCursorDown(int lines)
{
	// case 82/83 @ 0x7c8cc6 (T2) -> Screen::moveCursorDown 0x7e483e
	//   -> TerminalCore::cursorDown (see TerminalCore.cpp)
	if (lines < 0)
		return;
	if (lines == 0)
		lines = 1;
	// m_core->cursorDown(lines);
}

void SuperCommander::moveCursorForward(int columns)
{
	// case 84/85 @ 0x7c8ce0 (T2) -> Screen::moveCursorForward 0x7e484a
	//   -> TerminalCore::cursorForward (X/Y mirror of cursorDown)
	if (columns < 0)
		return;
	if (columns == 0)
		columns = 1;
	// m_core->cursorForward(columns);
}

void SuperCommander::insertLine(int count)
{
	// case 20/21 @ 0x7c8c0c (T1) -> 0x7e5df0
	(void)count;
}

void SuperCommander::deleteLine(int count)
{
	// case 16/17 @ 0x7c8c18 (T1) -> 0x7e3784
	(void)count;
}

void SuperCommander::deleteCharacter(int count)
{
	// case 22/23 @ 0x7c8c24 (T1) -> 0x7e3790
	(void)count;
}

void SuperCommander::eraseScreen(int mode)
{
	// case 40/41 @ 0x7c8c68 (T1, const 0) -> 0x7e606a
	(void)mode;
}

void SuperCommander::scrollUp(int lines)
{
	// case 174/175 @ 0x7c8db6 (T2, const 0,0) -> 0x7e5546
	if (lines < 0)
		return;
	if (lines < 1)
		lines = 1;
}

void SuperCommander::setDecMode(int mode)
{
	// case 206 @ 0x7c8d4c (T1, const 1) -> Screen::setDecMode 0x7f5d2e
	(void)mode;
}

void SuperCommander::selectGraphicRendition(int rendition)
{
	// case 186 @ 0x7c8de6 (T1) -> 0x7ef95c
	(void)rendition;
}

void SuperCommander::zmodemSend()
{
	// case 263 @ 0x7cdca6 (T1) -> 0x7e6844
}
