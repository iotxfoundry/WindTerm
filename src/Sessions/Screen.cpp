#include "Screen.h"

// Bodies transcribed from decompilation (0x7e cluster); comments cite the
// source function. Phase-1 restoration (reference, not compiled).

Screen::Screen()
	: m_core(nullptr), m_history(nullptr), m_savedCursorStyle(-1),
	  m_eraseAttr(0), m_leftRightMarginEnabled(false),
	  m_scrollbackEnabled(false), m_eraseProtectedMode(false),
	  m_newlineMode(false), m_reverseWraparound(false)
{
}

// ---------------------------------------------------------------------------
// Position & bounds (pure aliases into the core)
// ---------------------------------------------------------------------------

int Screen::currentColumn() const { return m_core->m_cursorX; }        // FUN_007e368e
int Screen::currentLine() const { return m_core->m_cursorY; }          // FUN_007e369c
int Screen::marginBottom() const { return m_core->scrollRegionBottomLimit(); } // FUN_007e4426
int Screen::marginLeft() const { return m_core->leftMargin(); }        // FUN_007e443e
int Screen::marginRight() const { return m_core->rightMargin(); }      // FUN_007e444a
int Screen::marginTop() const { return m_core->scrollRegionTopLimit(); } // FUN_007e4456
int Screen::originBottom() const { return m_core->originBottom(); }    // FUN_007e48b0
int Screen::originLeft() const { return m_core->originLeft(); }        // FUN_007e48c8
int Screen::originRight() const { return m_core->originRight(); }      // FUN_007e48d4
int Screen::originTop() const { return m_core->originTop(); }          // FUN_007e48e0
int Screen::windowColumns() const { return m_core->columnCount(); }    // FUN_007e5b96
int Screen::rowCount() const { return m_core->rowCount(); }            // FUN_007e5f18

// ---------------------------------------------------------------------------
// Cursor commands
// ---------------------------------------------------------------------------

void Screen::cursorMoveRaw(int y, int x)
{
	// FUN_007e4f38: alias of TerminalCore::moveCursorRaw (vt52MoveCursor
	// adapter passes column-32 / line-32 straight through)
	m_core->moveCursorRaw(y, x);
}

void Screen::moveCursor(int y, int x)
{
	// FUN_007e4fdc: alias of TerminalCore::moveCursor (CUP/HPA/VPA target)
	m_core->moveCursor(y, x);
}

void Screen::moveCursorBackward(int n) { m_core->cursorBackward(n); }  // FUN_007e4832
void Screen::moveCursorDown(int n) { m_core->cursorDown(n); }         // FUN_007e483e
void Screen::moveCursorForward(int n) { m_core->cursorForward(n); }   // FUN_007e484a
void Screen::moveCursorUp(int n) { m_core->cursorUp(n); }             // FUN_007e4856

void Screen::carriageReturn()
{
	// FUN_007e4fc8: column <- originLeft (0 when margins are off)
	m_core->setCursorX(originLeft());
}

void Screen::backspace()
{
	// FUN_007e4f44: step left; at the left margin with reverse
	// wraparound enabled, wrap to the end of the previous line
	if (currentColumn() != marginLeft()) {
		m_core->moveColumnBy(-1);
		return;
	}
	if (currentLine() > 0 && m_reverseWraparound)
		m_core->moveCursorRaw(currentLine() - 1, marginRight());
}

void Screen::lineFeed()
{
	// FUN_007e55fc: clear wrap pending, index down, then also CR when
	// newline mode (LNM, +0x12f) is set
	m_core->resetWrapPending();   // FUN_007a4564
	indexDown();
	if (!m_newlineMode)
		return;
	carriageReturn();
}

void Screen::horizontalTab()
{
	// FUN_007e5d7c: next tabstop, clamped to the right margin while the
	// cursor line is inside the scroll region
	int col = nextTabstop(currentColumn(), 1);
	if (m_core->inScrollRegion(currentLine())
	    && currentColumn() <= marginRight()) {
		if (marginRight() < col)
			col = marginRight();
	}
	m_core->setCursorX(col);
}

void Screen::backIndex()
{
	// FUN_007e4d48 (DECBI): left of the margin -> move; at the margin
	// the region shifts (scrollHorizontal(1))
	if (marginLeft() < currentColumn()) {
		m_core->moveColumnBy(-1);
		return;
	}
	scrollHorizontal(1);
}

void Screen::forwardIndex()
{
	// FUN_007e4d82 (DECFI): right of the margin -> move; else shift -1
	if (currentColumn() < marginRight()) {
		m_core->moveColumnBy(1);
		return;
	}
	scrollHorizontal(-1);
}

void Screen::saveCursor()
{
	// FUN_007e4aa2: alias of core DECSC
	m_core->saveCursor();
}

void Screen::restoreCursor()
{
	// FUN_007f6426 (DECRC): restore when a save exists; otherwise reset
	// DECOM (mode "6") and re-run the wrap/line cleanup
	if (m_core->hasSavedCursor()) {   // FUN_007a44da
		m_core->restoreCursor();      // FUN_007a5d20
		return;
	}
	setDecMode("6", false);           // FUN_007f5d2e(p1, "6", 0)
	m_core->resetWrap(0);             // FUN_007a45f6(core, 0) — name unverified
	// FUN_007e4b30(p1): tail call, not yet transcribed
}

void Screen::setCursorStyle(int style, bool save)
{
	// FUN_007e4ffa (DECSCUSR): no-op when unchanged unless `save`; core
	// style update + cursor refresh, then the view gets the shape class
	// (>4 -> blink flag, else 3)
	if (currentCursorStyle() == style && !save)   // FUN_007e36aa
		return;
	m_core->setCursorStyle(style);                // FUN_007a45ee
	void *cursor = m_core->cursorUpdated();       // FUN_007a44c0
	notifyCursorStyle(cursor, style > 4 ? (style > 6 ? 1 : 0) : 3);  // FUN_00913592
}

void Screen::setCursorVisibility(int mode)
{
	// FUN_007e5090 (DECTCEM variants): 0 = show (restoring a saved
	// style from +0xa8), 1 = hide, 8 = save style then hide. Remaining
	// modes truncated in the decompile.
	if (mode == 0) {
		setCursorVisible(true);         // FUN_007e506a(p1, 1)
		if (m_savedCursorStyle != -1) {
			setCursorStyle(m_savedCursorStyle, false);
			m_savedCursorStyle = -1;
		}
	} else if (mode == 1) {
		setCursorVisible(false);        // FUN_007e506a(p1, 0)
	} else if (mode == 8) {
		if (m_savedCursorStyle == -1)
			m_savedCursorStyle = currentCursorStyle();
		setCursorVisible(true);
		// FUN_007e4ffa tail call truncated in the decompile
	}
}

// ---------------------------------------------------------------------------
// Tabs
// ---------------------------------------------------------------------------

int Screen::nextTabstop(int from, int count) const
{
	// FUN_007e5d1e: advance `count` tabstops from `from`, bounded by
	// window width-1
	const int last = windowColumns() - 1;
	int col = from;
	while (count >= 1 && last > col) {
		do {
			col++;
			if (col == last)
				return col;
		} while (!isTabstop(col));
		count--;
	}
	return col;
}

int Screen::prevTabstop(int from, int count) const
{
	// FUN_007e5ce4: mirror of nextTabstop — body not yet transcribed
	return from;
}

bool Screen::isTabstop(int column) const
{
	// FUN_007e5c98: bitmap bit at core+0x18 payload
	if (windowColumns() <= column)
		return false;
	return m_core->m_tabstops.test(column);
}

void Screen::setTabstop(int column, bool on)
{
	// FUN_007e52fc (HTS): -1 -> current column
	if (column == -1)
		column = currentColumn();
	m_core->m_tabstops.set(column, on);
}

void Screen::clearTabstop(int mode)
{
	// FUN_007e5df0 (TBC): 0 = clear at cursor, 3 = clear all
	if (mode == 0) {
		m_core->m_tabstops.set(currentColumn(), false);
		return;
	}
	if (mode == 3)
		m_core->m_tabstops.clear();
}

// ---------------------------------------------------------------------------
// Scroll
// ---------------------------------------------------------------------------

void Screen::indexDown()
{
	// FUN_007e55b6 (IND): above the bottom margin -> plain move; at it
	// -> scroll the region up by one
	if (currentLine() != marginBottom()) {
		m_core->moveLineBy(1);
		return;
	}
	scroll(1, false, false);
}

void Screen::indexUp()
{
	// FUN_007e563e (RI): mirror of indexDown
	if (currentLine() != marginTop()) {
		m_core->moveLineBy(-1);
		return;
	}
	scroll(1, true, false);
}

void Screen::nextLine()
{
	// FUN_007e562c (NEL): CR + IND
	carriageReturn();
	indexDown();
}

void Screen::scroll(int count, bool down, bool fillTemplate)
{
	// FUN_007e5546: scrolling up at absolute top pushes lines into the
	// scrollback first (when enabled), bounded by the region height
	if (count == 0)
		return;
	const int top = marginTop();
	if (!down && top == 0 && isScrollbackAllowed()) {
		int n = m_core->scrollRegionHeight();   // FUN_007e4432 -> FUN_007a4c48
		if (n < count)
			count = n;
		pushLinesToScrollback(count);           // FUN_007e53b6
	}
	m_core->scrollRegion(top, count, down, fillTemplate);  // FUN_007a4c6c
}

void Screen::scrollHorizontal(int delta)
{
	// FUN_007e4d3c: alias of the core horizontal scroll (SL/SR share it
	// with opposite signs)
	m_core->scrollHorizontal(delta);            // FUN_007a68ae
}

// ---------------------------------------------------------------------------
// Erase
// ---------------------------------------------------------------------------

void Screen::eraseCells(int line, int from, int count, bool selective)
{
	// FUN_007e37f8: core eraseCells with the current erase attribute
	// (+0x110) and the protected-erase mode (+0x129)
	m_core->eraseCells(line, from, m_eraseAttr, count,
	                   m_eraseProtectedMode, selective);
}

void Screen::eraseCharacter(int count)
{
	// FUN_007e385a (ECH): guard here (impl-level), erase from cursor
	if (count < 0)
		return;
	if (count < 1)
		count = 1;
	eraseCells(currentLine(), currentColumn(), count, false);
}

int Screen::eraseLine(int line, int mode, bool selective)
{
	// FUN_007e4ba2 (EL 0/1/2): the line is first normalized to the
	// screen width (FUN_007a5ff2); mode 0 erases from the cursor (a
	// pending wide-char wrap at the right margin extends by one cell),
	// mode 1 erases start..cursor inclusive, mode 2 the whole line.
	if (mode > 2)
		return 0;
	struct Row *row = m_core->row(line);
	int length = m_core->rowLength(row);
	const int width = windowColumns();
	if (width < length) {
		m_core->setRowLength(row, width);   // FUN_007a5ff2
		length = width;
	}
	int from, count;
	if (mode == 0) {
		from = currentColumn();
		if (from == m_core->originRight() && (m_core->m_flags & 0x80))
			from++; // FUN_007e4b9a: wide-wrap pending (core flag sign bit)
		count = length - from;
	} else if (mode == 1) {
		from = 0;
		count = currentColumn() + 1;
	} else {
		from = 0;
		count = length;
	}
	int erased = eraseCells(line, from, count, selective);
	m_core->markLine(line, 0);   // FUN_007a463c
	return erased;
}

int Screen::eraseScreen(int mode, bool selective)
{
	// FUN_007e606a (ED 0/1/2/3): with scrollback enabled the replaced
	// rows are pushed into it first — mode 2 pushes the buffered
	// content rows, mode 0 only when the cursor is home, mode 1 the
	// rows above the cursor (+1 with a pending wide wrap at the last
	// column). Mode 3 clears the scrollback instead of the screen.
	if (isScrollbackAllowed() && !selective) {
		int push = 0;
		if (mode == 2) {
			push = m_history->lastContentRowCount();  // FUN_007a5618(+0x88)
		} else if (mode == 0) {
			if (currentLine() == 0 && currentColumn() == 0)
				push = m_history->lastContentRowCount();
		} else if (mode == 1) {
			if (currentColumn() == 0)
				push = currentLine();
			else if (currentColumn() == windowColumns() - 1)
				push = currentLine() + 1;
		}
		if (push >= 1)
			pushLinesToScrollback(push);
	}
	if (mode > 2) {
		if (mode != 3)
			return 0;
		clearScrollback();   // FUN_0091318c
		return 0;
	}
	int erased = 0;
	for (int row = 0; row < rowCount(); row++) {
		if (mode == 0) {
			if (row < currentLine())
				continue;
		} else if (mode == 1) {
			if (row > currentLine())
				continue;
		}
		if (!selective)
			markRowErased(row);   // FUN_007e41ca: flags = (flags & 0xc5) | 2
		erased += eraseLine(row, 2, selective);
	}
	return erased;
}

// ---------------------------------------------------------------------------
// Rectangular areas
// ---------------------------------------------------------------------------

void Screen::eraseRectangularArea(const QString &area, bool selective)
{
	// FUN_007eb1c4 (DECERA): rect parsed from the string param
	// (FUN_007eaeee), bounds guard, then the core worker
	int top, left, bottom, right;
	parseRect(area, &top, &left, &bottom, &right);   // FUN_007eaeee — cited
	if (top <= bottom && left <= right)
		m_core->eraseRect(top, left, bottom, right, selective);  // FUN_007a6d98
}

void Screen::fillRectangularArea(const QString &fill)
{
	// FUN_007eb20a (DECFRA): fill char must be in [0x20..0x7e] or
	// [0xa0..0xff]; the blank cell is built from the current attribute
	// (FUN_007e4c90) and handed to the core worker with an aux buffer
	const int ch = fill.isEmpty() ? 0 : fill.at(0).toLatin1();
	if (ch - 0x20 > 0x5e && ch - 0xa0 > 0x5f)
		return;
	void *aux = buildFillAux();   // FUN_007e4c90 — cited
	// FUN_007a6eec(core, rect, cell, aux) — rect via FUN_007eaeee (cited)
}

void Screen::copyRectangularArea(const QString &area)
{
	// FUN_007eb2f2 (DECCRA): params arrive as a QByteArray that is
	// split and re-parsed (QByteArray::split + container lookups
	// FUN_0067dffe/FUN_0075bd66/FUN_00763334); the copy itself is the
	// cited core path. Body beyond the parse not yet transcribed.
}

void Screen::changeAttributesInRectangularArea(const QString &area)
{
	// FUN_007eb17e (DECCARA): same bounds guard as DECERA
	int top, left, bottom, right;
	parseRect(area, &top, &left, &bottom, &right);   // FUN_007eaeee — cited
	if (top <= bottom && left <= right)
		m_core->changeRectAttrs(top, left, bottom, right, 0);  // FUN_007a748e
}

void Screen::reverseAttributesInRectangularArea(const QString &area)
{
	// FUN_007eb2ac (DECRARA): same bounds guard as DECERA
	int top, left, bottom, right;
	parseRect(area, &top, &left, &bottom, &right);   // FUN_007eaeee — cited
	if (top <= bottom && left <= right)
		m_core->reverseRectAttrs(top, left, bottom, right, 0);  // FUN_007a721e
}

// ---------------------------------------------------------------------------
// Margins
// ---------------------------------------------------------------------------

void Screen::setTopBottomMargins(int top, int bottom)
{
	// FUN_007e5fa6 (DECSTBM): 1-based params, -1/absent -> extremes;
	// bottom is clamped under rowCount; tail (core set + cursor home
	// per DECSTBM semantics) truncated in the decompile
	if (top == -1)
		top = 0;
	else {
		top = top - 1;
		if (top < 0)
			top = 0;
	}
	if (bottom == -1)
		bottom = rowCount() - 1;
	else
		bottom = bottom - 1;   // + clamp vs rowCount (partially decoded)
	m_core->setTopBottomMargins(top, bottom);   // FUN_007a4672
	m_core->moveCursorRaw(m_core->originTop(), m_core->originLeft());  // homes per DECSTBM
}

void Screen::setLeftRightMargins(int left, int right)
{
	// FUN_007e5bd4 (DECSLRM): ignored unless DECLRMM (+0x11a) is on;
	// same normalization as DECSTBM but against the column count
	if (!m_leftRightMarginEnabled)
		return;
	if (left == -1)
		left = 0;
	else {
		left = left - 1;
		if (left < 0)
			left = 0;
	}
	if (right == -1)
		right = windowColumns() - 1;
	else
		right = right - 1;
	m_core->m_leftMargin = left;    // tail truncated — core margin write
	m_core->m_rightMargin = right;
	m_core->moveCursorRaw(m_core->originTop(), m_core->originLeft());
}

// ---------------------------------------------------------------------------
// Scrollback
// ---------------------------------------------------------------------------

bool Screen::isScrollbackAllowed() const
{
	// FUN_007e4036: +0x11c flag && FUN_007e4028 mode check && the view
	// setting (+0x10)+0x104 (scrollback limit) is non-zero
	if (!m_scrollbackEnabled)
		return false;
	if (!scrollbackModeCheck())   // FUN_007e4028 — cited
		return false;
	return *(int *)((char *)m_viewSettings + 0x104) != 0;
}

void Screen::pushLinesToScrollback(int count)
{
	// FUN_007e53b6: moves the top `count` rows of the visible core into
	// the scrollback view (+0x98): resets the view flag (+0x24), queries
	// the render mode (FUN_007e5284(p1, 2)), takes the history container
	// (*(view+0x28)), then per row converts the row object
	// (FUN_007a9582) and appends rendered blocks (FUN_007e4368) with the
	// row's wrap/attribute bits. Inner loop cited.
	if (count < 1)
		return;
}

void Screen::clearScrollback()
{
	// FUN_0091318c: clears the scrollback view — body cited
}
