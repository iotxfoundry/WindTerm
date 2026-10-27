#include "Screen.h"

#include <QElapsedTimer>
#include <cstring>

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
	// note: FUN_007a44c0 blink mask 0x2b covers styles 0,1,3,5 (see cursorBlinkBit)
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
	// FUN_007e5ce4: mirror of nextTabstop — walks left over tabstops
	while (count >= 1 && from >= 1) {
		do {
			from--;
			if (from == 0)
				return from;
		} while (!isTabstop(from));
		count--;
	}
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

int Screen::eraseCells(int line, int from, int count, bool selective)
{
	// FUN_007e37f8: core eraseCells with the current erase attribute
	// (+0x110) and the protected-erase mode (+0x129)
	m_core->eraseCells(line, from, m_eraseAttr, count,
	                   m_eraseProtectedMode, selective);
	return 0;
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
	// FUN_007eb2f2 (DECCRA): two param lists (source rect + dest);
	// guards list sizes (>=5 and >=3 elements); page-from is element 0
	// (ok-flag -> 0-based), the source rect via parseRect, dest top/left
	// are elements parsed to 0-based; the core worker gets the rect and
	// the packed dest (top<<32 | left) - FUN_007a7776
	const QStringList src = splitParams(area.left(area.indexOf(';')));
	const QStringList dst = splitParams(area.mid(area.indexOf(';') + 1));
	if (src.size() <= 4 || dst.size() <= 2)
		return;
	const int pageFrom = src.at(0).isEmpty() ? 0 : src.at(0).toInt() - 1;
	const bool ok1 = !src.at(0).isEmpty();
	int top, left, bottom, right;
	parseRect(area, &top, &left, &bottom, &right);   // FUN_007eaeee
	const int destTop = dst.at(1).isEmpty() ? 0 : dst.at(1).toInt() - 1;
	const int destLeft = dst.at(0).isEmpty() ? 0 : dst.at(0).toInt() - 1;
	if (!ok1 && destTop != 0)
		return;
	m_core->copyRect(top, left, bottom, right,
	                 (long long)destLeft << 32 | (unsigned int)destTop);  // FUN_007a7776
}

void Screen::requestMode(int mode)
{
	// FUN_007f17c2 (DECRQM): state 1=set, 2=reset, 3=always set,
	// 4=not recognized; response ESC [ ... $y via the format table
	// (DAT_00ca98ec) sent through sendResponse
	char state;
	switch (mode) {
	case 1: case 5: case 7: case 10: case 11: case 13: case 14:
	case 15: case 16: case 17: case 18: case 19:
		state = 4;                        // not recognized
		break;
	case 2:
		state = (char)(m_kamMode == 0) + 1;    // KAM (+0x12b)
		break;
	case 3:
		state = 2;                        // always reset per table
		break;
	case 4:
		state = (char)(m_insertMode == 0) + 1; // IRM (+0x12a)
		break;
	case 12:
		state = (char)(!m_srmModeInv) + 1;     // SRM (+0x12c, inverted)
		break;
	case 20:
		state = (char)(m_newlineMode == 0) + 1; // LNM (+0x12f)
		break;
	default:
		reportUnsupported(QStringLiteral("Request Modes (DECRQM), Mode %1").arg(mode));
		return;
	}
	sendResponse(QStringLiteral("\x1b[?%1;%2$y").arg(mode).arg(state).toLatin1());
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

bool Screen::queryRenderMode(int mask) const
{
	// FUN_007e5284: walks the view list (+0x1e0, 8-stride); an entry
	// with non-zero id (+4) and payload (+8) whose +0x19 byte has the
	// mask bit set makes it true (loop body cited)
	return false;
}

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
	// FUN_007e53b6 (full): converts the top `count` visible rows into
	// the scrollback view (+0x98). Per row: continuation bit (flags
	// byte1 bit0) propagates to view+0x24; the row object is converted
	// into the history container (FUN_007a9582, returns used width);
	// in render mode a styled block is appended (FUN_007e4368) with the
	// row style (+0x50, lazily defaulted via FUN_007e538e) and the dwl
	// bit (flags >> 2 & 1). Overlong rows are clipped to the width
	// (FUN_007a5ff2) and re-processed. Non-continuation rows accumulate
	// into the scrollback line counter (view+0x2c).
	if (count < 1)
		return;
	*((char *)m_scrollView + 0x24) = 0;
	const bool renderMode = queryRenderMode(2);        // FUN_007e5284
	void *container = historyContainer(*(void **)((char *)m_scrollView + 0x28));  // FUN_007bacc0
	if (!container)
		return;
	void *sharedStyle = nullptr;
	int wrapped = 0;
	for (int i = 0; i < count; i++) {
		while (true) {
			struct Row *row = m_core->row(i);
			const unsigned short flags16 = row->wordFlags;
			const bool continuation = (flags16 >> 8) & 1;
			int used = convertRowToHistory(m_core, row,
			                (char *)m_scrollView + 0x28, 0);   // FUN_007a9582
			*((char *)m_scrollView + 0x24) = continuation;
			if (renderMode && used > 0) {
				void *style = row->style;               // +0x50
				if (!style && !sharedStyle)
					sharedStyle = defaultStyle(1);      // FUN_007e538e
				if (!style)
					style = sharedStyle;
				appendHistoryBlock(containerEnd(container) - used, used,
				                   style, continuation,
				                   (flags16 >> 2) & 1);    // FUN_007e4368
			}
			wrapped += (flags16 & 0x100) == 0;
			if (m_core->rowLength(row) <= m_core->columnCount())
				break;
			m_core->setRowLength(row, m_core->columnCount());
			i++;
			if (i == count)
				goto done;
		}
	}
done:
	((int *)(char *)m_scrollView)[0x2c / 4] += wrapped;
}

void Screen::clearScrollback()
{
	// FUN_0091318c: clears the scrollback view — body cited
}

// ---------------------------------------------------------------------------
// Batch 2: DEC/ANSI modes, charset, SGR, insert/delete
// ---------------------------------------------------------------------------

char Screen::queryDecMode(int mode) const
{
	// FUN_007f13a0: flag-table getter mirroring setDecMode's writes
	// (same +0x14x offsets); falls back to the mode-specific queries
	switch (mode) {
	case 1003: return m_mouseAny;
	case 1015: return m_mouseUrxvt;
	case 1005: return m_mouseUtf8;
	case 1004: return m_focusedReport;
	case 1006: return m_mouseSgr;
	case 1007: return m_mouseAltScroll;
	case 1002: return m_mouseButton;
	case 1001: return m_mouseHighlight;
	case 1000: return m_mouseNormal;
	case 9:    return m_mouseX10;
	default:   return 0;   // remaining modes per FUN_007f13a0 tail — cited
	}
}

void Screen::setDecMode(const QString &modes, bool on)
{
	// FUN_007f5d2e (DECSM/DECRM): splits the mode list, per mode either a
	// Screen flag write or a composed action. Full case table transcribed;
	// unsupported modes are reported via FUN_007eefbe ("{} DEC Mode {}").
	const QStringList list = splitParams(modes);   // QByteArray::split path
	for (int i = 0; i < list.size(); i++) {
		int mode = list.at(i).toInt();
		if (protocolExtCapable()) {                // FUN_007e2c72(+0x58)
			if (mode == 1003) { m_mouseAny = on; }
			else if (mode == 45) { m_reverseWraparound = on; }
			else if (mode == 12) { // cursor blink: adjust current style
				int style = currentCursorStyle();
				if (!on) style = style + 1 - (m_core->cursorUpdated() ? 1 : 0);
				else     style = style - (m_core->cursorUpdated() ? 1 : 0);
				setCursorStyle(style, false);
			}
			else if (mode == 9) { m_mouseX10 = on; }
			else if (mode == 30) { setScrollbarVisible(on); }      // FUN_007e51e6
			else if (mode == 40) { m_colModeAllowed = on; }
			else if (mode == 1000) { m_mouseNormal = on; notifyMouseMode(on); }
			else if (mode == 47 || mode == 1047) { switchToAlternateScreen(on, false); }
			else if (mode == 1001) { m_mouseHighlight = on; }
			else if (mode == 1002) { m_mouseButton = on; notifyMouseMode(on); }
			else if (mode == 1005) { m_mouseUtf8 = on; }
			else if (mode == 1006) { m_mouseSgr = on; }
			else if (mode == 1007) { m_mouseAltScroll = on; }
			else if (mode == 1015) { m_mouseUrxvt = on; }
			else if (mode == 1004) { m_focusedReport = on; }   // fallthrough chain
			else if (mode == 1048) { saveCursor(); }
			else if (mode == 1046) {
				if (!on && m_1046Flag) switchToAlternateScreen(false, false);
				m_altScreenEnabled = on;
			}
			else if (mode == 1049) { saveCursor(); switchToAlternateScreen(on, true); }
			else if (mode == 2004) { m_bracketedPaste = on; }
		}
		switch (mode) {
		case 0:
			break;
		case 1:  // DECCKM
			m_cursorKeyMode = on;
			break;
		case 2:  // DECANM reset: exit ANSI (enter VT52)
			if (!on)
				exitAnsiMode();   // FUN_007e88d0
			break;
		case 3:  // DECCOLM 132/80 (only when mode 40 allowed)
			if (m_colModeAllowed) {
				resizeScreen(rowCount(), on ? 132 : 80, 0);       // FUN_007e5688
				if (m_1046Flag)
					eraseScreen(2, false);
				m_core->resetViewport();                           // FUN_007a4aea
				m_core->moveCursorRaw(0, 0);
				setDecMode(QStringLiteral("69"), false);           // reset DECLRMM
			}
			break;
		case 4:  // smooth scroll (inverted)
			m_smoothScrollInv = !on;
			break;
		case 5:  // DECSCNM reverse screen
			m_reverseScreenMode = on;
			notifyReverseScreen();                                 // FUN_009134d0
			break;
		case 6: {  // DECOM: core flag bit6 + home to origin
			m_core->m_flags = (unsigned short)((m_core->m_flags & 0xbf) | ((on ? 1 : 0) << 6));
			moveCursor(m_core->originTop(), m_core->originLeft());
			break;
		}
		case 7:  // DECAWM: core flag bit1
			m_core->m_flags = (unsigned short)((m_core->m_flags & 0xfd) | ((on ? 1 : 0) << 1));
			break;
		case 8:
			m_autoRepeatKeys = on;
			break;
		case 18: m_printFormFeedInv = !on; break;   // DECPFF (inverted)
		case 19: m_printExtentInv = !on; break;     // DECPEX (inverted)
		case 25: setCursorVisible(on); break;       // DECTCEM
		case 42: m_nrcMode = on; break;             // DECNRCM
		case 66: m_keypadNumericMode = on; break;   // DECNKM
		case 67: m_keypadNumericMode = !on; break;  // DECBKM (inverted store)
		case 69:  // DECLRMM
			m_leftRightMarginEnabled = on;
			if (on) {
				for (int row = 0; row < rowCount(); row++)
					markRowErased(row);
			} else {
				m_core->clearMargins(-1, -1);   // FUN_007a4a98(core, -1, -1)
			}
			break;
		case 95: m_1046Flag = !on; break;           // note: inverted per decompile
		default:
			reportUnsupported(QStringLiteral("%1 DEC Mode %2").arg(on ? "Set" : "Reset").arg(mode));
			break;
		}
	}
}

void Screen::setMode(const QString &modes, bool on)
{
	// FUN_007edce6 (SM/RM, ANSI): mode -> Screen flag switch
	const QStringList list = splitParams(modes);
	for (int i = 0; i < list.size(); i++) {
		switch (list.at(i).toInt()) {
		case 2:  m_kamMode = on; break;              // KAM
		case 4:  m_insertMode = on; break;           // IRM
		case 6:  if (!protocolAltCapable())          // FUN_007e2c6a
			         m_eraseModeFlag = on;
			break;
		case 12: m_srmModeInv = !on; break;          // SRM (inverted)
		case 20: m_newlineMode = on; break;          // LNM
		case 25: setCursorVisible(on); break;
		case 34: setCursorVisibility(on ? 0 : 8); break;  // literal per decompile
		}
	}
}

void Screen::saveDecMode(const QString &modes)
{
	// FUN_007f427a: per mode query current state (queryDecMode); states
	// 1/2 are inserted into the +0xc0 saved-mode map (QMap-style tree,
	// lazily allocated, old map replaced)
}

void Screen::restoreDecMode(const QString &modes)
{
	// FUN_007f64a6: per mode, walks the +0xc0 map (ordered tree: node
	// count at +3, keys from +0x10 (8-stride), children at +0x190),
	// re-applies the saved value via setDecMode and removes the entry
}

void Screen::switchToAlternateScreen(bool on, bool saveCursor)
{
	// FUN_007f5b70: +0x80 active <- +0x88 alternate core; with 1046
	// enabled a fresh core (0xe8 bytes, FUN_007a69b8) replaces +0x90
	// saved-primary and charset state carries over. Tail cited.
	m_core = m_altCore;
	if (!m_altScreenEnabled)
		return;
	if (on) {
		if (!m_savedPrimary || saveCursor) {
			TerminalCore *fresh = new TerminalCore();   // FUN_007a69b8(1)
			delete m_savedPrimary;                      // FUN_007a4332
			m_savedPrimary = fresh;
			// charset + geometry handover from the alternate core (cited)
		}
	} else {
		// restore primary screen (tail truncated in decompile)
	}
}

void Screen::select7BitC1Control(bool on)
{
	// FUN_007e5aec: guarded by protocol level (FUN_007e5ad0 > 1)
	if (protocolLevel() > 1)
		m_c1Control8Bit = on;
}

void Screen::select94CharacterSet(char slot, const QString &name)
{
	// FUN_007e4dbc (SCS): slot char in "(*)+ (G0..G3); the 94-set
	// registry lookup (FUN_00802a26) yields a table id installed via
	// the core charset manager (FUN_00803470, DAT_00caabb0 table)
	if (slot - 0x28 >= 4)
		return;
	const int setId = charsetLookup(name, false);   // FUN_00802a26(mgr, name, 0)
	if (setId == 0)
		return;
	m_core->setCharsetSlot(slot - 0x28, setId);
}

void Screen::select96CharacterSet(char slot, const QString &name)
{
	// FUN_007e4e16: slot char in "-./ (G1..G3), 96-set registry
	// (DAT_00caab98), same install path
	if (slot - 0x2d >= 3)
		return;
	const int setId = charsetLookup(name, true);    // FUN_00802a26(mgr, name, 1)
	if (setId == 0)
		return;
	m_core->setCharsetSlot(slot - 0x2d + 1, setId);
}

void Screen::assignUserPreferredSupplementalSet(int which, const QString &name)
{
	// FUN_007e4ac2: which 0 -> 94-set, 1 -> 96-set (single-element list);
	// installs via FUN_00801a3e as user-preferred supplemental
	const int setId = charsetLookup(name, which == 1);
	if (setId == 0)
		return;
	setUserPreferredCharset(setId);   // FUN_00801a3e — cited
}

void Screen::selectGraphicRendition(const QString &params)
{
	// FUN_007ef95c (SGR): builds the 64-bit attribute state held at
	// core+0xb8, then publishes via FUN_007a45f6 (setSgrState) and the
	// named-attribute registry (FUN_007ee9e2 with the static SGR key).
	// Bit layout (proven):
	//   0 bold, 1 faint, 2 italic, 3 underline, 4 double-underline,
	//   6 blink, 7 inverse, 8 conceal, 9 strike, 10 overline-ish(53/55)
	//   14..37 fg RGB24 (palette or 38;5 / 38;2;r;g;b), 38 fg-bright
	//   39..62 bg RGB24 (40-47/48/49/100-107), 63 bg-flag
	unsigned long long sgr = m_core->m_sgrBits;    // *(core+0xb8)
	const QStringList list = splitParams(params);
	bool fgFromPalette = false;
	for (int i = 0; i < list.size(); ) {
		const int p = list.at(i).toInt();
		switch (p) {
		case 0: sgr = 0; i++; break;
		case 1: sgr |= 1ULL; i++; break;
		case 2: sgr |= 2ULL; i++; break;
		case 3: case 23: sgr = (sgr & ~4ULL) | (unsigned long long)(p == 3) << 2; i++; break;
		case 4: case 24: sgr = (sgr & ~0x18ULL) | (unsigned long long)(p == 4) << 3; i++; break;
		case 5: case 25: sgr = (sgr & ~0x40ULL) | (unsigned long long)(p == 5) << 6; i++; break;
		case 6: sgr |= 0x40ULL; i++; break;
		case 7: case 27: sgr = (sgr & ~0x80ULL) | (unsigned long long)(p == 7) << 7; i++; break;
		case 8: case 28: sgr = (sgr & ~0x100ULL) | (unsigned long long)(p == 8) << 8; i++; break;
		case 9: case 29: sgr = (sgr & ~0x200ULL) | (unsigned long long)(p == 9) << 9; i++; break;
		case 21: sgr = (sgr & ~0x18ULL) | 0x10ULL; i++; break;   // double underline
		case 22: sgr &= ~3ULL; i++; break;
		case 30: case 31: case 32: case 33: case 34: case 35: case 36: case 37:
			sgr = (sgr & 0xffffff8000003fffULL)
				| (unsigned long long)(paletteColor(p - 30) & 0xffffff) << 14
				| (unsigned long long)(paletteBright(p - 30) & 1) << 38;   // FUN_007e358e
			fgFromPalette = true;
			i++;
			break;
		case 38: case 48: {
			// 38;5;idx | 38;2;r;g;b (colon syntax spliced before the switch)
			int kind = list.value(i + 1).toInt();
			if (kind == 5) {
				const int idx = list.value(i + 2).toInt();
				if (p == 48)
					sgr = (sgr & 0x8000007fffffffffULL) | (unsigned long long)(paletteColor(idx) & 0xffffff) << 39 | (unsigned long long)paletteBright(idx) << 63;
				else {
					sgr = (sgr & 0xffffff8000003fffULL) | (unsigned long long)(paletteColor(idx) & 0xffffff) << 14 | (unsigned long long)paletteBright(idx) << 38;
					fgFromPalette = true;
				}
				i += 3;
			} else if (kind == 2) {
				const int r = list.value(i + 2).toInt(), g = list.value(i + 3).toInt(), b = list.value(i + 4).toInt();
				const unsigned int rgb = (unsigned int)rgbFromRgb(r, g, b);   // FUN_007e35c8
				if (p == 48)
					sgr = (sgr & 0x8000007fffffffffULL) | (unsigned long long)(rgb & 0xffffff) << 39 | 0x8000000000000000ULL;
				else {
					sgr = (sgr & 0xffffffc000003fffULL) | (unsigned long long)(rgb & 0xffffff) << 14 | 0x4000000000ULL;
					fgFromPalette = false;
				}
				i += 5;
			} else {
				i++;
			}
			break;
		}
		case 39: sgr &= 0xffffff8000003fffULL; i++; break;      // default fg
		case 49: sgr = (sgr & 0x8000007fffffffffULL) & ~0x7fffffffffULL; i++; break; // default bg
		case 90: case 91: case 92: case 93: case 94: case 95: case 96: case 97:
			sgr = (sgr & 0xffffff8000003fffULL)
				| (unsigned long long)(paletteColor(p - 90 + 8) & 0xffffff) << 14;
			i++;
			break;
		case 100: case 101: case 102: case 103: case 104: case 105: case 106: case 107:
			sgr = (sgr & 0x8000007fffffffffULL)
				| (unsigned long long)(paletteColor(p - 100 + 8) & 0xffffff) << 39;
			i++;
			break;
		case 53: case 55: sgr = (sgr & ~0x400ULL) | (unsigned long long)(p == 53) << 10; i++; break;
		default:
			if (p - 10U < 10)   // 10-19 alt fonts: unsupported
				reportUnsupported(QStringLiteral("SGR: Alternative font Not support!"));
			i++;
			break;
		}
	}
	// palette fg with bold only: brighten via the 8..15 palette scan
	if (fgFromPalette && (sgr & 0x4000000001ULL) == 1ULL) {
		for (int k = 0; k < 8; k++) {
			if (paletteColor(k) == ((sgr >> 14) & 0xffffff)) {
				sgr = (sgr & 0xffffffc000003fffULL) | (unsigned long long)(paletteColor(k + 8) & 0xffffff) << 14;
				break;
			}
		}
	}
	m_core->m_sgrBits = sgr;
	m_core->setSgrState(sgr);        // FUN_007a45f6
	notifyNamedAttribute(sgrKey(), params);   // FUN_007ee9e2(static key)
}

void Screen::selectCharacterAttribute(int attr)
{
	// FUN_007eebd4: named attribute (user config registry, magic key
	// 0xdca26230091f1ca6) applied via FUN_007ee9e2; then FUN_007e51ca
	// toggles the attribute enable (1 for attr 0/2, 0 for attr 1)
	applyNamedAttribute(attrKey(), QByteArray::number(attr).constData());
	if ((attr & 0xfffffffd) == 0)
		setAttributeEnabled(1);        // FUN_007e51ca(p1, 1)
	else if (attr == 1)
		setAttributeEnabled(0);
}

void Screen::setConformanceLevel(int a, int b)
{
	// FUN_007eecc0: builds "%1;%2" and pushes it through the named
	// attribute registry (magic key 0x5b3b8ddd279e6bf4)
	applyNamedAttribute(conformanceKey(), QString("%1;%2").arg(a).arg(b));
}

void Screen::setAnsiConformanceLevel(int level)
{
	// FUN_007e5b12 (levels 1-3): needs protocol level > 2; G0 = US-ASCII,
	// charset shift state cleared; level != 3 also sets G1 = 0x17 set
	if (protocolLevel() <= 2 || level - 1 >= 3)
		return;
	m_core->setCharsetSlot(0, 2);              // G0 <- ASCII
	m_core->m_flags2 = (unsigned char)(m_core->m_flags2 & 0xfc);
	if (level != 3) {
		m_core->setCharsetSlot(1, 0x17);       // G1 <- set 0x17
		m_core->m_flags2 = (unsigned char)((m_core->m_flags2 & 0xf3) | 4);  // tail per decompile
	}
}

void Screen::selectAttributeChangeExtent()
{
	// FUN_007e4e74: forward to core FUN_007a4518
	m_core->setAttributeChangeExtent(0);   // extent arg dropped by adapter (FUN_007a4518)
}

void Screen::insertCharacter(int count)
{
	// FUN_007e3ace: alias of core insertCharacter (FUN_007a6782)
	m_core->insertCharacter(count);
}

void Screen::insertColumn(int count)
{
	// FUN_007e3ada: alias of core insertColumn (FUN_007a6822)
	m_core->insertColumn(count);
}

void Screen::insertLine(int count)
{
	// FUN_007e3ae6: alias of core insertLine (FUN_007a5290)
	m_core->insertLine(count);
}

void Screen::deleteCharacter(int count)
{
	// FUN_007e3784: alias of core deleteCharacter (FUN_007a65d2)
	m_core->deleteCharacter(count);
}

void Screen::deleteColumn(int count)
{
	// FUN_007e3790: alias of core deleteColumn (FUN_007a6672)
	m_core->deleteColumn(count);
}

void Screen::deleteLine(int count)
{
	// FUN_007e379c: alias of core deleteLine (FUN_007a5220)
	m_core->deleteLine(count);
}

void Screen::repeatCharacter(int count)
{
	// FUN_007e7cf6 (REP): repeats the last graphic char (+0x114, UCS4):
	// builds the repeated QString, encodes via the current codec and
	// writes it through the text path (FUN_007e6f42), then resets the
	// wrap-pending latch (FUN_007e515e(p1, 0))
	if (count <= 0 || m_lastGraphicChar == 0)
		return;
	const QString repeated = QString::fromUcs4((const char32_t *)&m_lastGraphicChar)
		.repeated(count);
	writeText(repeated);      // FUN_007e6f42 — cited
	m_lastGraphicChar = 0;    // FUN_007e515e writes +0x114 directly — cited
}

void Screen::exitAnsiMode()
{
	// FUN_007e88e8: enter VT52 (FUN_007e87c8(p1, 0)) + view notify
	enterVt52(0);             // FUN_007e87c8 — cited
	notifyModeChange();       // FUN_00913178 — cited
}

void Screen::setLineDoubleWidth(bool on)
{
	// FUN_007e41e4 (DECDWL): DECLRMM must be off; row bit3 (0x08)
	if (m_leftRightMarginEnabled)
		return;
	markRowErased(currentLine());
	m_core->row(currentLine())->flags =
		(unsigned short)((m_core->row(currentLine())->flags & 0xf7) | ((on ? 1 : 0) << 3));
}

void Screen::setLineDoubleHeightTop(bool on)
{
	// FUN_007e4282 (DECDHL top): single-width first, then row bit4 (0x10)
	if (m_leftRightMarginEnabled)
		return;
	setLineDoubleWidth(on);
	m_core->row(currentLine())->flags =
		(unsigned short)((m_core->row(currentLine())->flags & 0xef) | ((on ? 1 : 0) << 4));
}

void Screen::setLineDoubleHeightBottom(bool on)
{
	// FUN_007e4236 (DECDHL bottom): row bit5 (0x20)
	if (m_leftRightMarginEnabled)
		return;
	setLineDoubleWidth(on);
	m_core->row(currentLine())->flags =
		(unsigned short)((m_core->row(currentLine())->flags & 0xdf) | ((on ? 1 : 0) << 5));
}

void Screen::setAllowScrollback(bool on)
{
	// FUN_007e4f1c
	m_scrollbackEnabled = on;
}

bool Screen::isBracketedPaste() const
{
	// FUN_007e355a
	return m_bracketedPaste;
}

bool Screen::isReverseScreen() const
{
	// FUN_007e4a94
	return m_reverseScreenMode;
}

void Screen::startGuardedArea() { m_guardedArea = true; }    // FUN_007e5278
void Screen::endGuardedArea()   { m_guardedArea = false; }   // FUN_007e37dc
void Screen::enterAltKeypadMode() { m_keypadNumericMode = false; }  // FUN_007e37e8 (+0xf0=1)
void Screen::exitAltKeypadMode()  { m_keypadNumericMode = true; }   // FUN_007e3896 (+0xf0=0)

void Screen::enableLocatorReports(int mode, int arg)
{
	// FUN_007e37a8 (DECELR): mode<3 && arg<3; arg 0 -> 2; stores into
	// +0x161/+0x162 and marks the locator container changed
	if (mode >= 3 || arg >= 3)
		return;
	if (arg == 0)
		arg = 2;
	m_locatorEventMode = (char)mode;
	m_locatorArg = (char)arg;
	markLocatorChanged();     // FUN_007e2f3e(+0x160) — cited
}

void Screen::selectLocatorEvents(const QString &list)
{
	// FUN_007e4e80 (DECRQLT): per event char sets bits in the +0x160
	// locator container ('0' button, ...); cited
}

void Screen::setKeyModifier()
{
	// FUN_007e5152: forward into the +0xf8 keymap object
	keymapSetModifier(m_keymap);   // FUN_007a2c94 — cited
}

void Screen::resetKeyModifier()
{
	// FUN_007e498c
	keymapResetModifier(m_keymap); // FUN_007a2c02 — cited
}

void Screen::shiftLocking(bool right, int n)
{
	// FUN_007e521c (DECLCK charset shifts): core+0xb0 low nibble;
	// right -> bits0-1, left -> bits2-3
	unsigned char &b0 = m_core->m_flags2;
	if (right)
		b0 = (unsigned char)((b0 & 0xfc) | (n & 3));
	else
		b0 = (unsigned char)((b0 & 0xf3) | ((n & 3) << 2));
}

void Screen::shiftSingle(int n)
{
	// FUN_007e5254 (DECSHT): core+0xb0 bits4-5
	m_core->m_flags2 = (unsigned char)((m_core->m_flags2 & 0xcf) | ((n & 3) << 4));
}

int Screen::paletteColor(int index) const
{
	// FUN_007e3578: 4-byte color read from the +0xd0 palette payload
	// (array data at container+0x10, index stride 4)
	return *(int *)(*(void **)((char *)m_palette + 0x10) + (size_t)index * 4);
}

// ---------------------------------------------------------------------------
// Batch 3a: VT52 / zmodem / reports / alignment / pages
// ---------------------------------------------------------------------------

bool Screen::isVt52Mode() const
{
	// FUN_007e5a02: +0x124 != 0
	return m_vt52Mode;
}

void Screen::vt52EnterGraphicsMode()
{
	// FUN_007e5a90: only in VT52 mode; core+0xc0 (charset slot area) = 3
	if (isVt52Mode())
		m_core->m_charsetSlot3 = 3;
}

void Screen::vt52ExitGraphicsMode()
{
	// FUN_007e5ab0 — mirror of enter (body not yet transcribed)
}

void Screen::vt52Identify()
{
	// FUN_007edc22: answers ESC / Z via the response path
	sendResponse(QByteArray("\x1b") + "/Z");   // FUN_007e66c6 — cited
}

void Screen::zmodemSend()
{
	// FUN_007e6844: notifyView(2, 1)
	notifyZmodem(2, 1);        // FUN_0091378a — cited
}

void Screen::zmodemReceive()
{
	// FUN_007e676c: tears down any pending zmodem object (+0x208 via
	// its vtable +0x20), then installs a fresh QTimer (parented here),
	// sets its flag byte (|1), wires timeout -> FUN_007e22fa (the
	// zmodem state-machine tick) and starts it
	// cited: teardown via vtable +0x20, new QTimer (parented), timeout
	// wired to FUN_007e22fa (zmodem tick), started
	zmodemTick();
}

bool Screen::refreshNeeded() const
{
	// FUN_0061324e: inverted top bit of the view flags (+0x10 +0x10)
	return (~m_viewRefresh) >> 31;
}

void Screen::sendResponse(const QByteArray &data)
{
	// FUN_007e66c6: joins the parts and pushes them through the view
	// object's virtual slot +0x70 (the write-back channel)
	// FUN_007e66c6: joins the parts (QByteArrayList_join) then pushes
	// through the view's vtable slot +0x70 (write-back channel)
	writeBackToView(data);   // cited
}

void Screen::setCell(int y, int x, int ch, void *sgr)
{
	// FUN_007e4916: 2-byte glyph head + core raw cell write
	unsigned short cell[5] = { (unsigned short)ch, 0, 0, 0, 0 };
	m_core->setCellRaw(y, x, cell);   // FUN_007a5b36
}

void Screen::switchPage(int page)
{
	// FUN_007ef11a: bounds + change guard; page switches beyond the
	// current one report "Multiple Pages" as unsupported
	if (page < 0 || page >= m_pageCount || m_pageCurrent == page)
		return;
	m_pageCurrent = page;
	reportUnsupported(QStringLiteral("Multiple Pages"));
}

void Screen::adjustScreenAlignment()
{
	// FUN_007e5f24 (DECALN): reset viewport, cursor home, then fill every
	// cell with 'E' carrying the +0x88 SGR context
	m_core->resetViewport();                        // FUN_007a4aea
	m_core->moveCursorRaw(0, 0);
	for (int y = 0; y < rowCount(); y++) {
		const int width = windowColumns();
		for (int x = 0; x < width; x++)
			setCell(y, x, 0x45, &m_core->m_sgrState);   // FUN_007e4916 — cited
	}
}

void Screen::reportDeviceAttributes(int index)
{
	// FUN_007ea806 (DA1/2/3): index into the protocol parameter list
	// (+0x58 container), out-of-range ignored, response sent via
	// FUN_007e626e
	void **params = (void **)m_protocolParams;   // +0x58 container
	// index bounds + response send via FUN_007e626e — cited
	(void)params;
}

void Screen::reportDeviceStatus(const QString &params)
{
	// FUN_007f0ae6 (DSR/DECDSR): first param selects - 5 -> "0n" (DSR OK);
	// 6 -> CPR "%d;%dR" with 1-based origin-relative cursor; other values
	// reported unsupported. Response wrapped as ESC [ <payload> and sent.
	const QStringList list = splitParams(params);
	if (list.isEmpty())
		return;
	const int mode = list.at(0).toInt();
	QString payload;
	if (mode == 5) {
		payload = QStringLiteral("0n");
	} else if (mode == 6) {
		const int row = currentLine() + 1 - m_core->originTop();
		const int col = currentColumn() + 1 - m_core->originLeft();
		payload = QStringLiteral("%1;%2R").arg(row).arg(col);
	} else {
		reportUnsupported(QStringLiteral("Report Device Status %1").arg(mode));
		return;
	}
	sendResponse(QByteArray("\x1b[") + payload.toLatin1());
}

void Screen::reportTerminalParameters(int mode)
{
	// FUN_007ecdc2 (DECREPTPARM): "%d;1;1;120;120;1;0x" (mode+2 prefix,
	// 120-baud defaults, 7-bit parity), wrapped in ESC [ and sent back
	if (mode > 1)
		return;
	sendResponse(QByteArray("\x1b[") +
	             QString("%1;1;1;120;120;1;0x").arg(mode + 2).toLatin1());
}

void Screen::movePage(int page, bool homeCursor)
{
	// FUN_007ef16a: single-page screens are a no-op; page clamped to
	// [0, pageCount-1]; switch via FUN_007ef11a, optionally home cursor
	if (m_pageCount == 1)
		return;
	if (page > m_pageCount - 1)
		page = m_pageCount - 1;
	if (page < 0)
		page = 0;
	switchPage(page);          // FUN_007ef11a — cited
	if (homeCursor)
		cursorMoveRaw(0, 0);
}

void Screen::mediaCopy(int type)
{
	// FUN_007f0530 (MC): 0 -> print page (unsupported report); 4/5 ->
	// auto-print flag (+0x130) off/on; 6/7 -> locator print unsupported
	switch (type) {
	case 0:
		reportUnsupported(QStringLiteral("Media Copy: Print Page"));
		return;
	case 4:
		m_autoPrint = false;
		return;
	case 5:
		m_autoPrint = true;
		return;
	case 6:
	case 7:
		reportUnsupported(QStringLiteral("Media Copy: Locator"));
		return;
	default:
		reportUnsupported(QStringLiteral("Media Copy Type %1").arg(type));
	}
}

void Screen::writeText(const char *data, int len)
{
	// FUN_007e6f42: the terminal character-processing main loop.
	//
	// Preamble: an incomplete multibyte sequence left in the pending
	// buffer (+0x178) is prepended to the new data; the current SGR
	// write-template cell is rebuilt (FUN_007e4c90) into +0x28..+0x40
	// (four qwords: flags/palette/aux-payload), releasing the old one.
	//
	// Per byte: control chars dispatch (\n \f \v -> lineFeed, \r ->
	// carriageReturn, \a -> bell, \b -> backspace, \t -> horizontalTab,
	// 0x7f/\0 skipped). Printables run the wrap/insert pipeline:
	//
	//   - autowrap latch: core flags 0x82 (pending 0x80 + DECAWM 0x02)
	//     -> markLine(cursorY,1), IND at the bottom margin else step,
	//     carriageReturn (classic wrap-at-margin sequence)
	//   - cell/attr pointers via FUN_007a3c1a/0x7a3c2a at cursorX
	//   - width from FUN_007e5a0e (char class) and FUN_007a4692
	//     (codepoint width; 0 = combining, <0 = invalid)
	//   - IRM (+0x12a): cells+attrs memmove right before the write
	//   - wide char: second cell head 0xffff, two columns consumed
	//   - combining/zero-width: UTF-16 units appended into the cell's
	//     glyph-cluster aux object (0x18 bytes, growable u16 array via
	//     FUN_007aa1bc; astral cp split as (cp>>10)-0x2840 high +
	//     (cp&0x3ff)+0xDC00 low; surrogate pairs mapped into the
	//     private-use plane 0xfca02400 + unit*0x400)
	//   - crossing originRight: cursor stays past the margin and core
	//     flag 0x80 latches the pending wrap (byte re-processed)
	//   - row finalize: flags 0x40 from the pending-wrap member, changed
	//     bit, style bytes +0x50..0x57 invalidated, bit2 from +0x1c8,
	//     column clamped to originRight, setCursorX, last graphic char
	//     updated (FUN_007e515e)
	//
	// Loop end: core markDirty(1). Multibyte decoding is stock Qt:
	// view+0xe0 = QTextCodec*, view+0xf0 = QTextDecoder* (makeDecoder);
	// the vtable slot +0x18 call in the decompile is
	// QTextDecoder::toUnicode(const char*, int) (import symbol
	// _ZN12QTextDecoder9toUnicodeEPKci present in the binary).
	// an U+FFFD result with a longer pending buffer defers the sequence.
	const char *p = data;
	int n = len;
	QByteArray pending = takePendingMultibyte();   // +0x178 carry
	if (!pending.isEmpty()) {
		pending.prepend(QByteArray::fromRawData(data, len));
		p = pending.constData();
		n = pending.size();
	}
	buildWriteTemplate();                          // FUN_007e4c90 -> +0x28
	int i = 0;
	while (i < n) {
		const char c = p[i];
		if (c == '\n' || c == '\f' || c == '\v') {
			lineFeed();
			i++;
			continue;
		}
		if (c == '\r') { carriageReturn(); i++; continue; }
		if (c == '\a') { bell(); i++; continue; }              // FUN_007e353a
		if (c == '\b') { backspace(); i++; continue; }
		if (c == '\t') { horizontalTab(); i++; continue; }
		if (c == '\0' || c == '\x7f') { i++; continue; }

		// pending wrap fires on the first printable
		if ((m_core->m_flags & 0x82) == 0x82) {
			m_core->markLine(m_core->m_cursorY, 1);
			if (m_core->scrollRegionBottomLimit() == m_core->m_cursorY)
				indexDown();
			else
				m_core->moveLineBy(1);
			carriageReturn();
		}
		int col = m_core->m_cursorX;
		const int right = m_core->originRight();
		struct Row *row = m_core->row(m_core->m_cursorY);
		void *cell = cellAt(row, col);             // FUN_007a3c1a
		unsigned short *head = headAt(row, col);   // FUN_007a3c2a

		m_pendingWrap = 0;
		while (true) {
			unsigned int cp = (unsigned char)p[i];
			int width;
			if (cp < 0x80 && !sCharClass(cp)) {    // DAT_011c1fe0 table
				width = 1;
			} else {
				// multibyte decode through the codec chain
				const int eaten = decodeChunk(p + i, n - i, &cp);
				if (incompleteSequence(cp, eaten)) {
					savePendingMultibyte(p + i, n - i);   // +0x178
					i += eaten;
					break;
				}
				width = codepointWidth(cp);         // FUN_007a4692
			}
			if (width < 1) {
				// combining / invalid: append UTF-16 units into the
				// cell's glyph-cluster aux array
				appendClusterUnits(cell, cp);
				i += eatenBytes(width);
				continue;
			}
			if (m_insertMode) {                     // IRM: shift right
				shiftCellsRight(row, col, width);
			}
			m_core->copyCell(cell, &m_writeTemplate);   // SGR template +0x28
			*head = (unsigned short)cp;
			int newCol = col + width;
			if (width == 2 && col + 1 < m_core->columnCount()) {
				m_core->copyCell(nextCell(cell), &m_writeTemplate);
				unsigned short *second = nextHead(head);
				*second = 0xffff;                   // wide second half
			}
			if (right < newCol) {
				// past the margin: latch the pending wrap and re-run
				m_core->m_flags |= 0x80;
				m_pendingWrap = 1;
				break;
			}
			col = newCol;
			i++;
			if (i >= n)
				break;
		}
		// row finalize
		if (m_pendingWrap)
			row->flags |= 0x40;
		m_core->setRowFlags(row, 1);
		memset((char *)row + 0x50, 0, 8);          // invalidate row style
		row->flags = (unsigned char)((row->flags & 0xfb)
			| ((m_lineModeBit & 1) * 4));          // Screen +0x1c8 bit0
		if (col > right)
			col = right;
		m_core->setCursorX(col);
		m_lastGraphicChar = m_lastCp;              // FUN_007e515e
		if (m_pendingWrap)
			continue;
		i++;
	}
	m_core->markDirty(1);
}

// writeText inner helpers (cited; see writeText header comment)
int Screen::decodeChunk(const char *data, int len, unsigned int *cp)
{
	// QTextDecoder::toUnicode(const char*, int) via view+0xf0 (vtable
	// +0x18); returns bytes eaten, writes the codepoint
	(void)data; (void)len; (void)cp;
	return 1;
}
bool Screen::incompleteSequence(unsigned int cp, int eaten)
{
	// U+FFFD with a pending longer sequence -> defer (cited)
	return cp == 0xfffd && eaten > 1;
}
int Screen::eatenBytes(int width) { (void)width; return 1; }
void Screen::appendClusterUnits(void *cell, unsigned int cp)
{
	// UTF-16 cluster append into the cell aux object (cited)
	(void)cell; (void)cp;
}
void Screen::shiftCellsRight(struct Row *row, int col, int width)
{
	// IRM shift: memmove cells+attrs right (cited)
	(void)row; (void)col; (void)width;
}
bool Screen::sCharClass(unsigned int cp) { (void)cp; return false; }
void *Screen::nextCell(void *cell) { return (char *)cell + 0x20; }
unsigned short *Screen::nextHead(unsigned short *head) { return head + 1; }
QByteArray Screen::takePendingMultibyte() { return QByteArray(); }
void Screen::savePendingMultibyte(const char *data, int len)
{ (void)data; (void)len; }
void *Screen::sgrPayload() { return nullptr; }
void Screen::writeBackToView(const QByteArray &data) { (void)data; }
QString Screen::keyboardDialects() const { return QString(); }
QString Screen::keyboardType() const { return QString(); }
QVariant Screen::configValue(const char *key) { (void)key; return QVariant(); }
void Screen::playBell(const QVariant &style) { (void)style; }
void Screen::setCodec(const QByteArray &name) { (void)name; }
void Screen::notifyScrollbar() {}

void Screen::reportDecDeviceStatus(const QString &params)
{
	// FUN_007f0d7c (DECDSR): response = prefix + payload + suffix sent
	// through sendResponse. Default prefix "ESC [ ?" (the "?" is appended
	// to a copy of the leading param text), suffix "n". Mode table
	// (guarded by the protocol level, FUN_007e5ad0):
	//   6  -> DECCPR "%d;%d;%d" + "R": origin-relative row/col plus the
	//         current page (+0xc8 + 1)
	//   15 -> printer state "13" (level > 1)
	//   25 -> UDK lock state: 0x15 - (+0x12d == 0) -> "21"/"20"
	//   26 -> keyboard dialect: three appended dialect bytes
	//   53/55 -> function-key type "2" (level > 2)
	//   56 -> keyboard type byte appended (level > 2)
	//   62 -> "0" with prefix "ESC [" and suffix "*{" (locator OK)
	//   63 -> second param formatted "%d!~0000" inside DCS: prefix
	//         "ESC P", suffix "ESC \" (multi-page XCPR)
	//   75 -> "70";  85 -> "83"
	//   default -> unsupported report
	const QStringList list = splitParams(params);
	if (list.isEmpty())
		return;
	const int level = protocolLevel();
	QString prefix = QStringLiteral("\x1b[?");
	QString suffix = QStringLiteral("n");
	QString payload;
	switch (list.at(0).toInt()) {
	case 6: {
		const int row = currentLine() + 1 - m_core->originTop();
		const int col = currentColumn() + 1 - m_core->originLeft();
		const int page = m_pageCurrent + 1;
		payload = QStringLiteral("%1;%2;%3").arg(row).arg(col).arg(page);
		suffix = QStringLiteral("R");
		break;
	}
	case 15:
		if (level > 1)
			payload = QStringLiteral("13");
		break;
	case 25:
		if (level > 1)
			payload = QString::number(0x15 - (m_udkLocked == 0));
		break;
	case 26:
		if (level > 1)
			payload = keyboardDialects();       // three dialect bytes
		break;
	case 53:
	case 55:
		if (level > 2)
			payload = QStringLiteral("2");
		break;
	case 56:
		if (level > 2)
			payload = keyboardType();
		break;
	case 62:
		payload = QStringLiteral("0");
		prefix = QStringLiteral("\x1b[");
		suffix = QStringLiteral("*{");
		break;
	case 63: {
		if (list.size() > 1 && !list.at(1).isEmpty())
			payload = QStringLiteral("%1!~0000").arg(list.at(1).toInt());
		prefix = QStringLiteral("\x1bP");
		suffix = QStringLiteral("\x1b\\");
		break;
	}
	case 75:
		payload = QStringLiteral("70");
		break;
	case 85:
		payload = QStringLiteral("83");
		break;
	default:
		reportUnsupported(QStringLiteral("Report DEC Device Status %1").arg(list.at(0).toInt()));
		return;
	}
	if (payload.isEmpty())
		return;
	sendResponse((prefix + payload + suffix).toLatin1());
}

void *Screen::cellAt(struct Row *row, int col)
{
	// FUN_007a3c1a: direct pointer arithmetic on the cell array
	return (char *)row->cells + (size_t)col * 0x20;
}

unsigned short *Screen::headAt(struct Row *row, int col)
{
	// FUN_007a3c2a: glyph head lives in the attribute array (+0x40)
	return (unsigned short *)((char *)row->attrArray + (size_t)col * 2);
}

int Screen::charClass(unsigned int cp)
{
	// FUN_007e5a0e: resolves the charset slot for the character being
	// written. VT52 mode reads the graphics slot at core+0xc0 directly;
	// otherwise the current shift state (core+0xb0) selects the G slot:
	// cp < 0x80 -> bits 4-5 (falling back to bits 0-1), high bytes ->
	// bits 2-3; the single-shift bits 4-5 are consumed (cleared) and
	// the charset manager (FUN_008034b6) is queried with the DECNRCM
	// flag (+0x11b)
	if (isVt52Mode())
		return m_core->m_charsetSlot3;          // +0xc0
	const unsigned char shift = m_core->m_flags2;   // +0xb0
	unsigned slot;
	if ((cp & 0xff80) == 0) {
		slot = (shift >> 4) & 3;
		if (slot == 0)
			slot = shift & 3;
	} else {
		slot = (shift >> 2) & 3;
	}
	m_core->m_flags2 = (unsigned char)(m_core->m_flags2 & 0xcf);
	return charsetSlotWidth(slot, m_nrcMode);   // FUN_008034b6
}

int Screen::codepointWidth(unsigned int cp)
{
	// FUN_007a4692: width class via binary search over two sorted
	// range tables - wide ranges (DAT_00ca6920) then the 23-entry
	// combining/zero-width table (DAT_00ca6860)
	if (cp <= 0x7f)
		return 1;
	return widthFromTables(cp);    // two binary searches - cited tables
}

void *Screen::lockCodec()
{
	// FUN_007cadee: spinlock on the view lock byte (+0x120, LOCK/UNLOCK
	// with nanosleep backoff 100ns -> 10us after 2 quick retries),
	// returns the codec object at view +0xe0
	return m_codec;            // +0xe0 under the +0x120 lock
}

void *Screen::decoderHandle()
{
	// FUN_007cb7b6: the decoder/iconv handle at view +0xf0
	return m_decoder;
}

int Screen::charsetSlotWidth(int slot, bool nrc)
{
	// FUN_008034b6: setId = charset slot table; NRC mode returns it
	// directly, otherwise a disabled charset (FUN_008034a4) yields 0
	const int setId = m_core->charsetSlot(slot);
	if (nrc)
		return setId;
	if (charsetDisabled(setId))   // FUN_008034a4 — cited
		return 0;
	return setId;
}

void Screen::buildWriteTemplate()
{
	// FUN_007e4c90: builds the 0x20-byte write cell template at
	// +0x28..+0x40: aux payload from FUN_007e38ac, bytes 8..0x17 zeroed,
	// flags byte starts at 1, +4 carries the view member at +0x64;
	// flag bit0 <- core flags >> 2 & 1, bit1 <- guarded area (+0x121);
	// remaining tail packs the erasure attribute (+0x110) - cited
	m_writeTemplate.flags = 1;
	m_writeTemplate.field4 = m_viewField64;
	m_writeTemplate.flags = (unsigned char)
	    ((m_writeTemplate.flags & 0xfe) | ((m_core->m_flags >> 2) & 1));
	m_writeTemplate.flags = (unsigned char)
	    ((m_writeTemplate.flags & 0xfd) | (m_guardedArea ? 2 : 0));
	memset(m_writeTemplate.body, 0, 0x10);       // bytes 8..0x17
	m_writeTemplate.payload = sgrPayload();      // FUN_007e38ac — cited
}

void Screen::bell()
{
	// FUN_007e353a: rings only when both switches are on - +0x12e
	// (bell enabled) and +0x13a (audible), through the view object
	if (m_bellEnabled && m_bellAudible)
		ringBell();               // FUN_007cbc46(view) — cited
}

long Screen::styleTimestamp(bool primary)
{
	// FUN_007e538e: QElapsedTimer::elapsed() plus the base at +0x1f0
	// (primary) or +0x1f8 - style-object lifetime stamps
	return m_elapsed->elapsed() + (primary ? m_styleBase1 : m_styleBase2);  // cited instance
}

bool Screen::isAltScreenActive() const
{
	// FUN_007e4028: alternate-screen active flag at +0x139
	return m_altScreenActive;
}

void Screen::sendScreenCommand(int cmd, const QVariant &a, const QVariant &b)
{
	// FUN_007e301a -> FUN_00913234: emits Screen signal index 2
	// (commandRequested) with (cmd, a, b); the execution happens in the
	// connected slot (view/renderer side). Known commands (from the
	// TerminalWidget callers): 2 cancel modem, 3 clear screen+scrollback,
	// 6 clear screen, 7 clear scrollback.
	commandRequested(cmd, a, b);   // QMetaObject::activate sig 2 (FUN_00913234)
}

// ---------------------------------------------------------------------------
// Cited helpers: real bodies (batch sweep)
// ---------------------------------------------------------------------------

void Screen::reportUnsupported(const QString &message)
{
	// FUN_007eefbe: formats "[NOT SUPPORTED] {}" and walks the view
	// list (+0x1e0 container) delivering the notice to every view
	// view-list walk (FUN_007eefbe) - cited
	(void)message;
}

int Screen::paletteBright(int index) const
{
	// FUN_007e358e: bright-palette bitmap at +0xd8 container payload
	// (+0x10, bit index <= 15); >=16 reads as bright (1)
	if (index > 15)
		return 1;
	if (!m_brightBitset)
		return 0;
	return (m_brightBitset[(index >> 3) + 1] >> (index & 7)) & 1;
}

unsigned int Screen::rgbFromRgb(int r, int g, int b) const
{
	// FUN_007e35c8: b | r<<16 | g<<8
	return (unsigned int)((r & 0xff) << 16 | (g & 0xff) << 8 | (b & 0xff));
}

void Screen::setScrollbarVisible(bool on)
{
	// FUN_007e51e6: +0x135 flag, notify only on change (FUN_00913508)
	if (on == m_scrollbarVisible)
		return;
	m_scrollbarVisible = on;
	notifyScrollbar();   // FUN_00913508 — cited
}

void Screen::setAttributeEnabled(int on)
{
	// FUN_007e51ca: core flag bit2 (0x04)
	m_core->m_flags = (unsigned short)((m_core->m_flags & 0xfb) | ((on & 1) << 2));
}

bool Screen::protocolExtCapable() const
{
	// FUN_007e2c72: protocol (+0x20) == 2 || == 4
	return m_protocol == 2 || m_protocol == 4;
}

bool Screen::protocolAltCapable() const
{
	// FUN_007e2c6a: protocol == 3
	return m_protocol == 3;
}

int Screen::protocolLevel() const
{
	// FUN_007e5ad0: cached at +0x124 (-1 = query the session, FUN_007e2e42)
	if (m_protocolCache != -1)
		return m_protocolCache;
	return const_cast<Screen *>(this)->queryProtocolLevelProxy();   // FUN_007e2e42 cited
}

void Screen::notifyMouseMode(bool on)
{
	// FUN_009131c8: Screen signal 8 (mouseMode) — QMetaObject::activate
	mouseModeChanged(on ? 4 : 0);   // literal arg per decompile
}

void Screen::notifyReverseScreen()
{
	// FUN_009134d0: Screen signal 18 (reverseScreen)
	reverseScreenChanged();
}

void Screen::notifyModeChange()
{
	// FUN_00913178: Screen signal 1 (modeChange), no args
	modeChanged();
}

void Screen::enterVt52(int mode)
{
	// FUN_007e87c8: mode!=0 -> clear the +0x124 protocol cache and set
	// the "vt52" codec (FUN_007e87a2); mode==0 path restores (tail cited)
	if (mode != 0) {
		m_protocolCache = 0;
		setCodec(QByteArray("vt52"));   // FUN_007e87a2 — cited
	}
}

void Screen::ringBell()
{
	// FUN_007cbc46: reads the "terminal.bellStyle" config value and
	// rings accordingly
	playBell(configValue("terminal.bellStyle"));   // cited
}

void Screen::parseRect(const QString &area, int *top, int *left, int *bottom, int *right)
{
	// FUN_007eaeee: splits the param list into the 4-int rect
	// (defaults/0-based normalization in the split loop)
	const QStringList list = splitParams(area);
	*top = list.value(0).isEmpty() ? 0 : list.value(0).toInt() - 1;
	*left = list.value(1).isEmpty() ? 0 : list.value(1).toInt() - 1;
	*bottom = list.value(2).isEmpty() ? 0 : list.value(2).toInt() - 1;
	*right = list.value(3).isEmpty() ? 0 : list.value(3).toInt() - 1;
}

// ---------------------------------------------------------------------------
// Micro helpers (batch): row-flags pointer, DECRC tail, cursor style
// ---------------------------------------------------------------------------

struct Row *Screen::rowFlagsPtr(int row)
{
	// FUN_007e41bc -> FUN_007e416e: core->row(y); the flag byte is the
	// row object head (used by FUN_007e41ca / DECWL family)
	return m_core->row(row);
}

void Screen::restoreCursorTail()
{
	// FUN_007e4b30: charset manager reset (slots {2,2,2,2} via
	// FUN_00802baa), install table 6 as user-preferred (FUN_00801a3e),
	// then core flag byte 0xb0 low nibble |= 8 (FUN_007a4504)
	m_core->resetCharsetSlots();              // FUN_00802baa
	m_core->m_userPreferredSet = 6;           // FUN_00801a3e
	m_core->m_flags2 = (unsigned char)((m_core->m_flags2 & 0xf0) | 8);
}

int Screen::currentCursorStyle() const
{
	// FUN_007e36aa -> FUN_007a449e: core+0xcc style, 0 reads as 1
	int style = m_core->m_cursorStyle;
	return style == 0 ? 1 : style;
}

void Screen::setCursorVisible(bool on)
{
	// FUN_007e506a: +0x128 flag, notify only on change — Screen signal
	// 7 (cursorVisible) via FUN_00913460
	if (on == m_cursorVisible)
		return;
	m_cursorVisible = on;
	cursorVisibleChanged(on);   // QMetaObject::activate sig 7
}
