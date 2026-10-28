#include "Screen.h"

#include <QElapsedTimer>
#include <QDateTime>
#include <QTextDecoder>
#include <QCursor>
#include <QGuiApplication>
#include <cstring>

// Bodies transcribed from decompilation (0x7e cluster); comments cite the
// source function. Phase-1 restoration (reference, not compiled).

// FUN_007cadba: bytes the view codec needs for one char starting at the
// lead byte (UTF-8 shape shown; the binary asks the codec itself)
static int codecBytesFor(char lead)
{
	const unsigned char b = (unsigned char)lead;
	if (b < 0xe0)
		return b < 0xc0 ? 1 : 2;
	if (b < 0xf0)
		return 3;
	if (b < 0xf8)
		return 4;
	return 1;
}

// FUN_007e2202: release an owned cell aux object — heap payload at +8
// when not the embedded tail, then the 0x18 object itself
static void releaseCellAux(char *auxSlot)
{
	void *aux = *(void **)auxSlot;
	if (aux) {
		if (*(void **)((char *)aux + 8) != (char *)aux + 0x10)
			free(*(void **)((char *)aux + 8));
		operator delete(aux, 0x18);
		*(void **)auxSlot = nullptr;
	}
}

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
	// FUN_007f17c2 (DECRQM, ANSI variant): format "%d;%d$y" (no '?',
	// DAT_00ca98ec); unknown modes log the notice and still reply 0
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
		state = (char)(m_srmModeInv != 0) + 1; // SRM (+0x12c, inverted)
		break;
	case 20:
		state = (char)(m_newlineMode == 0) + 1; // LNM (+0x12f)
		break;
	default:
		reportUnsupported(QStringLiteral("Request Modes (DECRQM), Mode %1").arg(mode));
		state = 0;
		break;
	}
	sendResponse(QStringLiteral("\x1b[%1;%2$y").arg(mode).arg(state).toLatin1());
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

char Screen::queryDecMode(int mode)
{
	// FUN_007f13a0 (terminal_handleDECRQM): DEC-mode flag table. State
	// 0 = tracked-but-off/not-recognized, 1 = set, 2 = reset; the third
	// corpus arg is the "respond" flag (requestDecMode sends the reply).
	const char *f = (const char *)this;
	char state = 0;
	// ext-capable fast paths (FUN_007e2c72 +0x58) — modes ≥1000 and the
	// core-table queries; everything else falls into the big switch
	if (protocolExtCapable()) {
		char c = 0;
		bool hit = true;
		if (mode == 1003) c = f[0x147];                 // m_mouseAny
		else if (mode == 1015) c = f[0x143];            // m_mouseUrxvt
		else if (mode == 1005) c = f[0x145];            // m_mouseUtf8
		else if (mode == 1004) c = f[0x142];            // m_focusedReport
		else if (mode == 1006) c = f[0x144];            // m_mouseSgr
		else if (mode == 1007) c = f[0x141];            // m_mouseAltScroll
		else if (mode == 1046) c = f[0x118];            // m_altScreenEnabled
		else if (mode == 1047 || mode == 1049) c = f[0x139]; // altScreenActive
		else if (mode == 2004) c = f[0x120];            // m_bracketedPaste
		else if (mode == 45) c = f[0x134];              // m_reverseWraparound
		else if (mode == 9) c = f[0x146];               // m_mouseX10
		else if (mode == 30) c = f[0x135];              // m_scrollbarVisible
		else if (mode == 40) c = f[0x11d];              // m_colModeAllowed
		else if (mode == 1000) c = f[0x14a];            // m_mouseNormal
		else if (mode == 1001) c = f[0x149];            // m_mouseHighlight
		else if (mode == 1002) c = f[0x148];            // m_mouseButton
		else if (mode == 1048) {
			// FUN_007a44da: core +0x28 bit0 (saved-cursor latch)
			return (char)(m_core->hasSavedCursor() == false) + 1;
		}
		else if (mode == 12) {
			// FUN_007a44c0: 6-bit table 0x2b indexed by core +0xcc
			const unsigned style = (unsigned)m_core->m_cursorStyle;
			const unsigned bit = style < 6 ? (0x2bu >> style) & 1u : 0u;
			return (char)(bit == 0) + 1;
		}
		else hit = false;
		if (hit)
			return (char)(c == 0) + 1;                  // LAB_007f140f
	}
	switch (mode) {
	default:
		reportUnsupported(QStringLiteral("Request Dec Modes (DECRQM), Mode %1").arg(mode));
		return 0;
	case 1:   // DECCKM: 1 when the cursor-key flag reads exactly 1
		return m_cursorKeyMode == 1 ? 1 : 2;            // LAB_007f15cd
	case 2:   // ANM: set when not in VT52 mode
		return (char)(isVt52Mode() != 0) + 1;
	case 3:   // DECCOLM: 132-column check
		return (char)(windowColumns() != 132) + 1;
	case 4:   // smooth scroll (inverted flag store)
		return (char)(m_smoothScrollInv != 0) + 1;
	case 5:   // DECSCNM
		return (char)(m_reverseScreenMode == 0) + 1;
	case 6:   // core flags & 0x40
		return (char)((m_core->m_flags2 & 0x40) == 0) + 1;
	case 7:   // core flags & 2
		return (char)((m_core->m_flags2 & 2) == 0) + 1;
	case 8:   // auto repeat
		return (char)(m_autoRepeatKeys == 0) + 1;
	case 18:  return (char)(m_printFormFeedInv != 0) + 1;
	case 19:  return (char)(m_printExtentInv != 0) + 1;
	case 25:  return (char)(m_cursorVisible == 0) + 1;
	case 42:  // DECNRCM
		return (char)(m_nrcMode == 0) + 1;
	case 43:  return (char)(m_mode67Flag != 0) + 1;
	case 66:  // DECNKM keypad
		return m_keypadNumericMode == 1 ? 1 : 2;
	case 69:  // DECLRMM
		return (char)(m_leftRightMarginEnabled == 0) + 1;
	case 95:  return (char)(m_1046Flag != 0) + 1;
	case 10: case 11: case 13: case 14: case 16: case 34: case 36:
	case 38: case 44: case 53: case 57: case 60: case 61:
	case 64: case 68: case 73: case 81: case 96: case 97: case 98:
	case 99: case 100: case 101: case 102: case 103: case 104:
	case 106: case 108: case 109: case 110: case 111: case 112:
	case 113: case 114: case 115: case 116: case 117:
		return 0;   // tracked as off
	}
	return state;
}

void Screen::requestDecMode(int mode)
{
	// FUN_007f13a0 tail (respond=1): "?%d;%d$y" (DAT_00ca98eb) after the
	// queryDecMode table (including its unsupported notice + state 0)
	const char state = queryDecMode(mode);
	sendResponse(QStringLiteral("\x1b[?%1;%2$y").arg(mode).arg(state).toLatin1());
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
	notifyNamedAttribute(sgrKey(), params.toLatin1());   // FUN_007ee9e2(static key)
}

void Screen::selectCharacterAttribute(int attr)
{
	// FUN_007eebd4: named attribute (attrKey = 0xdca26230091f1ca6 store)
	// applied via FUN_007ee9e2; then FUN_007e51ca toggles the attribute
	// enable (1 for attr 0/2, 0 for attr 1)
	applyNamedAttribute(attrKey(), QString::number(attr));
	if ((attr & 0xfffffffd) == 0)
		setAttributeEnabled(1);        // FUN_007e51ca(p1, 1)
	else if (attr == 1)
		setAttributeEnabled(0);
}

void Screen::setConformanceLevel(int a, int b)
{
	// FUN_007eecc0: builds "%1;%2" and pushes it through the named
	// attribute registry (conformanceKey = 0x5b3b8ddd279e6bf4 store)
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
	m_locator.mode = (char)mode;
	m_locator.units = (char)arg;
	markLocatorChanged();     // FUN_007e2f3e(+0x160) — cited
}

void Screen::selectLocatorEvents(const QString &list)
{
	// FUN_007e4e80 (DECRQLT): per event char sets bits in the +0x160
	// locator container ('0' button, ...); cited
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
	// sets its flag byte (|1), wires timeout -> FUN_007e22fa with a
	// 0x18-byte context whose +0x10 is this Screen, and starts it.
	// The parented-QTimer wiring needs the Phase-4 QObject conversion;
	// cited until then
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

// writeText inner helpers (bodies from FUN_007e6f42 inline regions)
int Screen::decodeChunk(const char *data, int len, unsigned int *cp)
{
	// 0x7e6f42 inline 0x7e7338..0x7e73d1: byte count from
	// FUN_007cadba(view, data[0]) (codec min bytes for one char);
	// decode via the codec vtable +0x18 call = QTextDecoder::toUnicode
	// (import _ZN12QTextDecoder9toUnicodeEPKci). Output is UTF-16: one
	// unit is the codepoint; two units fold a surrogate pair as
	// high*0x400 + low + 0xfca02400 (0x7e73a8; = -0x35fdc00). U+FFFD
	// with more than one unit marks a truncated sequence (see
	// incompleteSequence).
	const int eaten = codecBytesFor(data[0]);   // FUN_007cadba — cited
	QByteArray raw(data, eaten > 0 ? eaten : 1);
	const QString out = m_decoder
	                        ? ((QTextDecoder *)m_decoder)->toUnicode(raw)
	                        : QString::fromLatin1(raw);
	m_lastDecodedUnits = out.length();
	m_lastEatenBytes = eaten > 0 ? eaten : 1;
	if (m_lastDecodedUnits == 2) {
		const uint hi = out.at(0).unicode();
		const uint lo = out.at(1).unicode();
		*cp = hi * 0x400 + lo + 0xfca02400u;
	} else if (m_lastDecodedUnits == 1) {
		*cp = out.at(0).unicode();
	} else {
		*cp = 0xfffd;
		m_lastDecodedUnits = 1;
	}
	return m_lastEatenBytes;
}
bool Screen::incompleteSequence(unsigned int cp, int eaten)
{
	// 0x7e735a: U+FFFD with more than one decoded unit = sequence cut by
	// the buffer end — consume one byte and retry the remainder
	(void)eaten;
	return cp == 0xfffd && m_lastDecodedUnits > 1;
}
int Screen::eatenBytes(int width) { return m_lastEatenBytes; (void)width; }
void Screen::appendClusterUnits(void *cell, unsigned int cp)
{
	// 0x7e74e0..0x7e76a0: the cluster array is the cell aux ushort
	// vector {cap/refcount@0, count@4, data@8, embedded tail @0x10},
	// grown ×2 (FUN_007aa1bc) when full. High surrogates are stored
	// split — 0xd7c0 + (cp>>10) then 0xdc00 + (cp&0x3ff); BMP units
	// as-is. The binary selects the target cell (col-1, or the prior
	// row's last cell across a wrap) in the writeText body.
	unsigned short units[2];
	int n = 0;
	if (cp - 0xd800u < 0x800) {
		units[n++] = (unsigned short)((cp >> 10) + 0xd7c0);
		units[n++] = (unsigned short)((cp & 0x3ff) + 0xdc00);
	} else {
		units[n++] = (unsigned short)cp;
	}
	int **auxSlot = (int **)((char *)cell + 0x10);
	int *aux = *auxSlot;
	if (!aux) {
		aux = (int *)::operator new(0x18);
		aux[0] = 1;
		aux[1] = 0;
		*(void **)(aux + 2) = aux + 4;
		*auxSlot = aux;
	}
	for (int i = 0; i < n; i++) {
		if (aux[1] == aux[0])
			m_core->resizeUshortVector(aux, aux[1], aux[1] * 2);
		((unsigned short *)*(void **)(aux + 2))[aux[1]++] = units[i];
	}
}
void Screen::shiftCellsRight(struct Row *row, int col, int width)
{
	// 0x7e7453 (IRM insert): release the last on-screen cell's aux (it
	// falls off the shift, FUN_007e2202), memmove cells (+0x20 stride)
	// and heads (+2) right one slot, clear the vacated aux pointer
	int n = m_core->columnCount() - col - 1;
	if (n <= 0)
		return;
	releaseCellAux((char *)m_core->cellAt(row, col + n) + 0x10);
	memmove(m_core->cellAt(row, col + 1), m_core->cellAt(row, col),
	        (size_t)n * 0x20);
	memmove(m_core->attrHeadAt(row, col + 1), m_core->attrHeadAt(row, col),
	        (size_t)n * 2);
	*(void **)((char *)m_core->cellAt(row, col) + 0x10) = nullptr;
}
bool Screen::sCharClass(unsigned int cp)
{
	// DAT_011c1fe0: per-ASCII-byte special flags (C0 controls); a set
	// entry re-enters the control dispatch at 0x7e7746 instead of being
	// written as a glyph
	return cp < 0x80 && ((const char *)0x11c1fe0)[cp] != 0;
}
void *Screen::nextCell(void *cell) { return (char *)cell + 0x20; }
unsigned short *Screen::nextHead(unsigned short *head) { return head + 1; }
QByteArray Screen::takePendingMultibyte()
{
	// 0x7e6f7f prologue: the carry buffer empties into the new chunk
	QByteArray out = m_pendingTail;
	m_pendingTail.clear();
	return out;
}
void Screen::savePendingMultibyte(const char *data, int len)
{
	// 0x7e7338 tail: store the unconsumed bytes as their own QByteArray
	m_pendingTail = QByteArray(data, len);
}
void *Screen::buildFillAux()
{
	// FUN_007e4c90 — the same builder buildWriteTemplate wraps; DECFRA
	// (FUN_007eb20a) passes the fresh template to the core filler
	// (FUN_007a6eec) with an aux body carrying the fill char
	buildWriteTemplate();
	return &m_writeTemplate;
}
void *Screen::sgrPayload()
{
	// FUN_007e38ac: raw SGR attribute bits (core+0xb8) — they travel as
	// the template payload and land in cell+0x18
	return (void *)(unsigned long long)m_core->m_sgrBits;
}
// Qt/config primitives (binary addresses noted; reference tier thunks)
static void sessionConfigGet(QVariant *out, const Screen *s, const QByteArray &key)
{ (void)s; (void)key; *out = QVariant(); }   // session config getter (session_optGet family)
static void *codecLookupGlobal(const QByteArray &name)
{ (void)name; return nullptr; }              // FUN_00807144 over registry DAT_011c2200
static void installCodec(Screen *s, void *codec)
{ (void)s; (void)codec; }                    // FUN_007e8770
static void bellEmit(const void *view, const QString &message)
{ (void)view; (void)message; }               // FUN_00913274

void Screen::writeBackToView(const QByteArray &data)
{
	// FUN_007e66c6 tail: QByteArrayList join already done by
	// sendResponse; push through the view's vtable slot +0x70 (the
	// terminal write-back channel; adjacent +0x78 is a second channel,
	// FUN_007e673c)
	typedef void (*PushFn)(void *, void *, const QByteArray &);
	(*(PushFn *)(*(void ***)m_view + 0x70 / 8))(m_view, this, data);
}
QString Screen::keyboardDialects() const
{
	// DECDSR case 26 (0x7f0f05..0x7f0f23, level > 1): payload += three
	// QByteArray fields read from a config/keymap object — the object
	// and field offsets are not yet anchored (keymap layout dig pending)
	return QString();
}
QString Screen::keyboardType() const
{
	// DECDSR case 56 (0x7f0f44 region, level > 2): one byte appended
	// from the same config object — keymap layout dig pending
	return QString();
}
QVariant Screen::configValue(const char *key)
{
	// session config getter (session_optGet family; Ghidra labels the
	// shared reader config_sshIdentityFile_get)
	QVariant v;
	QByteArray k(key);
	sessionConfigGet(&v, this, k);
	return v;
}
void Screen::playBell(const QVariant &style)
{
	// FUN_007cbc46 tail: build the message — "beep", or the
	// terminal.bellFilePath sound file when style==2 — and emit via
	// FUN_00913274(view, message)
	QString message = QStringLiteral("beep");
	if (style.toInt() == 2) {
		QByteArray k("terminal.bellFilePath");
		QVariant v;
		sessionConfigGet(&v, this, k);
		message = v.toString();
	}
	bellEmit(m_view, message);
}
void Screen::setCodec(const QByteArray &name)
{
	// FUN_007e87a2 (38B): codec lookup in the global registry
	// (DAT_011c2200) via FUN_00807144, install via FUN_007e8770
	void *codec = codecLookupGlobal(name);
	if (codec)
		installCodec(this, codec);
}
void Screen::notifyScrollbar(bool visible)
{
	// FUN_00913508 (55B): QMetaObject::activate(this, Screen
	// staticMetaObject 0x11a82e0, signal 20, {visible})
	(void)visible;
}

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
	notifyScrollbar(m_scrollbarVisible);   // FUN_00913508 — signal 20
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
	// FUN_007cbc46 (390B): style = terminal.bellStyle (int); 0 = off;
	// rate-limited by terminal.bellInterval against +0xa8 (epoch secs);
	// message "beep", style 2 swaps in terminal.bellFilePath; updates
	// the timestamp then emits via FUN_00913274
	const int style = configValue("terminal.bellStyle").toInt();
	if (style == 0)
		return;
	const long now = QDateTime::currentSecsSinceEpoch();
	const int interval = configValue("terminal.bellInterval").toInt();
	if (now - m_lastBellSecs < interval)
		return;
	m_lastBellSecs = now;
	playBell(style);
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

// ---------------------------------------------------------------------------
// Phase 1a: DEC/VT report family (report requests and locator machinery)
// ---------------------------------------------------------------------------

// FUN_007f0346/7eecc0/7eebd4 guard inits: every named-attribute key is
// splitmix64(0x396cfeb8 ^ 0xbe4ba423 ^ site_literal) — verified against the
// precomputed constants Ghidra shows (e.g. DECSSDT 0x910265f6a06002be).
static quint64 attrMix64(quint32 v)
{
	quint64 x = v;
	x *= 0xc2b2ae3d27d4eb4fULL;
	x ^= x >> 29;
	x *= 0x165667b19e3779f9ULL;
	x ^= x >> 32;
	return x;
}

static quint64 namedAttributeKey(quint32 literal)
{
	return attrMix64(0x396cfeb8u ^ 0xbe4ba423u ^ literal);
}

quint64 Screen::sgrKey()
{
	// FUN_007ef95c guard: FUN_007e2123("m", 1) — 4-char anagram hash
	// (('m'<<16)|(1<<8)|'m'|('m'<<24)) ^ 0x87275a9b, then the avalanche
	const quint64 v = ((quint64)'m' << 16) | (1u << 8) | (quint64)'m'
	                  | ((quint64)'m' << 24);
	return attrMix64((quint32)(v ^ 0x87275a9bULL));
}

quint64 Screen::attrKey()
{
	// FUN_007eebd4 guard, literal 0x71220271 -> 0xdca26230091f1ca6
	return namedAttributeKey(0x71220271u);
}

quint64 Screen::conformanceKey()
{
	// FUN_007eecc0 guard, literal 0x70220270 -> 0x5b3b8ddd279e6bf4
	return namedAttributeKey(0x70220270u);
}

void Screen::notifyNamedAttribute(quint64 key, const QByteArray &value)
{
	// FUN_007ee9e2: QMap<quint64,QByteArray> at +0x78. An empty value
	// erases the entry; otherwise the value is stored (the corpus swaps
	// the previous value out into the caller, which then drops it).
	if (value.isEmpty())
		m_namedAttributes.remove(key);
	else
		m_namedAttributes.insert(key, value);
}

void Screen::applyNamedAttribute(quint64 key, const QString &value)
{
	// FUN_007eebd4/7eecc0 call FUN_007ee9e2 with the formatted value
	notifyNamedAttribute(key, value.toLatin1());
}

void Screen::selectStatusLineType(int type)
{
	// FUN_007f0346: DECSSSL value stored under its hash key, then the
	// notice is logged as unsupported
	notifyNamedAttribute(namedAttributeKey(0x7e24027eu),   // 0x910265f6a06002be
	                     QByteArray::number(type));
	reportUnsupported(QStringLiteral("Select Status Line Type (DECSSDT)"));
}

void Screen::requestTerminalStateReport()
{
	// FUN_007f0434 (DECRQTSR, mode 1 only in the corpus caller): echoes
	// the DCS 1$s frame and logs the report as unsupported
	sendResponse(QByteArrayLiteral("\x1bP1$s\x1b\\"));
	reportUnsupported(QStringLiteral("Request Terminal State Report (DECRQTSR)"));
}

void Screen::requestUserPreferredSupplementalSet()
{
	// FUN_007ed7f6 (DECRQUPSS): DCS frame carrying the manager charset
	// id (+0x10 via FUN_00802bd6): 6 -> "0!u%5", else "1!uA"
	const int id = m_core ? m_core->m_userPreferredSet : 0;
	sendResponse(QByteArrayLiteral("\x1bP")
	             + (id == 6 ? QByteArrayLiteral("0!u%5")
	                        : QByteArrayLiteral("1!uA"))
	             + QByteArrayLiteral("\x1b\\"));
}

void Screen::setUserPreferredCharset(int setId)
{
	// FUN_00801a3e (4B): manager charset id slot (+0x10) = setId
	if (m_core)
		m_core->m_userPreferredSet = setId;
}

void Screen::requestDisplayedExtent()
{
	// FUN_007ed148 (DECRQDE): CSI rows;cols;1;1;1"w
	sendResponse(QStringLiteral("\x1b[%1;%2;1;1;1\"w")
	                 .arg(rowCount()).arg(windowColumns()).toLatin1());
}

void Screen::requestKeyModifier(int key)
{
	// FUN_007ed282: CSI >key;state m — state read from the keymap
	// modifier slots via FUN_007a2bd4 (0->+0x14 1->+0x18 2->+0x1c
	// 4->+0x20, anything else -1); ESI still holds `key` at the call
	int state = -1;
	if (m_keymap) {
		const char *km = (const char *)m_keymap;
		switch (key) {
		case 0:  state = *(const int *)(km + 0x14); break;
		case 1:  state = *(const int *)(km + 0x18); break;
		case 2:  state = *(const int *)(km + 0x1c); break;
		case 4:  state = *(const int *)(km + 0x20); break;
		}
	}
	sendResponse(QStringLiteral("\x1b[>%1;%2m").arg(key).arg(state).toLatin1());
}

void Screen::markLocatorChanged()
{
	// FUN_007e2f3e -> FUN_007e2efe(this+0x160, -1,-1,-1,-1): rect reset
	// (all -1 -> not all >= 0, so the valid bit 3 is cleared)
	m_locator.left = m_locator.top = m_locator.right = m_locator.bottom = -1;
	m_locator.flags &= (unsigned char)~8;
}

int Screen::locatorRowFromPixel(double x, double y) const
{
	// FUN_007e3136 -> FUN_00913608 (view pixel->cell): failure default
	// is the -1 the caller initialized; body not transcribed
	(void)x; (void)y;
	return -1;
}

int Screen::locatorColFromPixel(double x, double y) const
{
	// FUN_007e30f4 -> FUN_009135d8: same shape as the row mapper
	(void)x; (void)y;
	return -1;
}

quint64 Screen::locatorUnitTransform(double x, double y) const
{
	// FUN_007e3114 -> FUN_00913638 (pixel units report): failure
	// default is the 0 the caller initialized
	(void)x; (void)y;
	return 0;
}

void Screen::requestLocatorPosition(int mode)
{
	// FUN_007ebd6a (DECLRP): when locator reports are on (+0x161 mode,
	// else the filter-rect valid check FUN_007e2ec2) report the global
	// cursor pos and mouse buttons; otherwise a zero event
	(void)mode;
	const LocatorState &loc = m_locator;
	const bool on = loc.mode != 0
	                || ((loc.flags & 8) != 0
	                    && loc.left >= 0 && loc.top >= 0
	                    && loc.right >= 0 && loc.bottom >= 0);
	if (on) {
		const QPoint pos = QCursor::pos();
		reportLocatorEvent(1, (int)QGuiApplication::mouseButtons(),
		                   pos.x(), pos.y(), -1, -1);
	} else {
		reportLocatorEvent(0, 0, 0.0, 0.0, -1, -1);
	}
}

void Screen::reportLocatorEvent(int kind, int buttons, double x, double y,
                                int row, int col)
{
	// FUN_007eb4d6: button normalization (Qt codes -> DEC), pixel->cell
	// fill for missing row/col, bounds check, then the CSI ...&w report
	if ((buttons & 2) != 0) {
		buttons = 1;
	} else {
		if ((buttons & 4) != 0)
			buttons = 2;
		else if ((buttons & 1) != 0)
			buttons = 4;
		else
			buttons &= 8;
		if (row == -1)
			row = locatorRowFromPixel(x, y);   // FUN_007e3136
		if (col == -1)
			col = locatorColFromPixel(x, y);   // FUN_007e30f4
	}
	if (row < 0 || col < 0 || rowCount() <= row || windowColumns() <= col) {
		row = -1;
		col = -1;
	} else if (m_locator.units == 2) {
		row++;
		col++;
	} else if (m_locator.units == 1) {
		const quint64 pack = locatorUnitTransform(x, y);   // FUN_007e3114
		row = (int)(pack & 0xffffffffu);
		col = (int)(pack >> 32);
	}

	QByteArray payload;
	if (kind == 0) {
		// reset report
		if (m_locator.mode == 2)
			m_locator.mode = 0;
		payload = QByteArrayLiteral("0&w");
	} else {
		if (m_locator.mode == 2)
			m_locator.mode = 0;
		int event = kind & 1;
		if ((kind & 1) == 0) {
			if ((kind & 2) == 0) {
				if ((kind & 4) == 0) {
					if ((kind & 8) == 0) {
						payload = QByteArrayLiteral("0&w");
						goto send;
					}
					event = 10;
				} else if (buttons == 4) {
					event = 3;
				} else if (buttons == 2) {
					event = 5;
				} else if (buttons == 1) {
					event = 7;
				} else if (buttons == 8) {
					event = 9;
				} else {
					payload = QByteArrayLiteral("0&w");
					goto send;
				}
			} else if (buttons == 4) {
				event = 2;
			} else if (buttons == 2) {
				event = 4;
			} else if (buttons == 1) {
				event = 6;
			} else if (buttons == 8) {
				event = 8;
			} else {
				payload = QByteArrayLiteral("0&w");
				goto send;
			}
		}
		payload = QStringLiteral("%1;%2;%3;%4;%5&w")
		              .arg(event).arg(buttons)
		              .arg(row == -1 ? QString() : QString::number(row))
		              .arg(col == -1 ? QString() : QString::number(col))
		              .arg(m_pageCurrent).toLatin1();
	}
send:
	sendResponse(QByteArrayLiteral("\x1b[") + payload);
}

void Screen::setUserDefinedKeys()
{
	// FUN_007ef0e8 (DECDLD): protocol level read dropped by the
	// decompiler, then the unsupported notice
	(void)protocolLevel();
	reportUnsupported(QStringLiteral("Set User Defined Keys"));
}

// ---------------------------------------------------------------------------
// Phase 1b: notification family — SuperTerm signal emitters (0x0091xxxx
// cluster). Screen is not a QObject in this rebuild yet; the emit points
// carry the proven activate() index and stay inert until the Phase-4
// wiring. Signal names follow the 39-name pool with idx = pool - 2
// (verified on idx7 caretVisibleChanged, idx18 screenReversed, idx20
// scrollBarVisibleChanged, idx30 transferBinary).
// ---------------------------------------------------------------------------

void Screen::notifyZmodem(int modemType, int transmitType)
{
	// FUN_0091378a: QMetaObject::activate(this, SuperTerm::staticMetaObject,
	// 30, {modemType, transmitType}) — signal 30 transferBinary
	// (King::ModemType, King::TransmitType)
	(void)modemType; (void)transmitType;
}

void Screen::notifyCursorStyle(void *cursor, int style)
{
	// FUN_00913592: activate(..., 6, {cursor(bool), style}) — signal 6
	// caretStyleChanged(bool, int)
	(void)cursor; (void)style;
}

void Screen::zmodemTick(int event, void *context)
{
	// FUN_007e22fa: zmodem timer callback — event 0 deletes the 0x18-byte
	// context; event 1 reports transferBinary(2, 0) on the screen object
	// stored at context+0x10
	if (event == 0) {
		if (context)
			::operator delete(context);
		return;
	}
	if (event == 1) {
		Screen *screen = *(Screen **)((char *)context + 0x10);
		screen->notifyZmodem(2, 0);
		return;
	}
}

void Screen::markRowErased(int row)
{
	// FUN_007e41ca: row flag byte &= 0xc5 (keeps bits 7,6,2,0) then |= 2
	// (erased/dirty mark); the flag byte is the Row object head
	unsigned char *flags = (unsigned char *)rowFlagsPtr(row);
	*flags = (unsigned char)((*flags & 0xc5) | 2);
}

// ---------------------------------------------------------------------------
// Phase 1c: decode/style family — codepoint width tables (FUN_007a4692)
// ---------------------------------------------------------------------------

#include "width_tables.inc"

// lower_bound over {start,end} pairs on the end field (FUN_007a4692's
// hand-rolled search); returns the first entry with end >= cp or the
// one-past-end slot
static const int *widthLowerBound(const int *t, int n, unsigned int cp)
{
	while (n > 0) {
		const int half = n >> 1;
		if ((unsigned int)t[half * 2 + 1] < cp) {
			t += (half + 1) * 2;
			n -= half + 1;
		} else {
			n = half;
		}
	}
	return t;
}

static bool widthInRange(const int *table, int n, const int *sentinel,
                         unsigned int cp)
{
	const int *p = widthLowerBound(table, n, cp);
	return p != sentinel && (unsigned int)p[0] <= cp;
}

int Screen::widthFromTables(unsigned int cp)
{
	// FUN_007a4692: seven sorted range tables.
	//   T1 private-use -> 1; T2/T3 combining -> 0; T4 wide -> 2;
	//   T5 ambiguous -> 1; T6 narrow letters -> 1; T7 emoji -> 2;
	//   default (incl. ASCII) -> 1
	if (cp <= 0x7f)
		return 1;
	if (widthInRange(&width_t1[0][0], 3, &width_t1[3][0], cp))
		return 1;
	if (widthInRange(&width_t2[0][0], 23, &width_t2[23][0], cp))
		return 0;
	if (widthInRange(&width_t3[0][0], 280, &width_t3[280][0], cp))
		return 0;
	if (widthInRange(&width_t4[0][0], 95, &width_t4[95][0], cp))
		return 2;
	if (widthInRange(&width_t5[0][0], 180, &width_t5[180][0], cp))
		return 1;
	if (widthInRange(&width_t6[0][0], 675, &width_t6[675][0], cp))
		return 1;
	if (widthInRange(&width_t7[0][0], 51, &width_t7[51][0], cp))
		return 2;
	return 1;
}

// ---------------------------------------------------------------------------
// Phase 1c: splitParams (reconstruction seam for the inline
// QByteArray::split(';') pattern at each corpus call site)
// ---------------------------------------------------------------------------

QStringList Screen::splitParams(const QString &params) const
{
	QStringList out;
	for (const QByteArray &part : params.toLatin1().split(';'))
		out << QString::fromLatin1(part);
	return out;
}

// ---------------------------------------------------------------------------
// Phase 1c: charset registry (FUN_00801a58 registration walk) and the
// lookup/disabled pair (FUN_00802a26 / FUN_008034a4)
// ---------------------------------------------------------------------------

#include "charset_registry.inc"

int Screen::charsetLookup(const QString &name, bool set96)
{
	// FUN_00802a26: walk the registry in registration order; the name
	// must fully match and the entry flag stored at +0x10 (registration
	// param_4, "set96" column) must equal the selector; returns the id
	// or 0. Duplicate names disambiguate through the flag column.
	const QByteArray raw = name.toLatin1();
	for (const auto &e : charsetRegistry)
		if (e.set96 == (set96 ? 1 : 0) && raw == e.name)
			return e.id;
	return 0;
}

bool Screen::charsetDisabled(int setId)
{
	// FUN_008034a4: the id-slot table (FUN_008034f2, later duplicate id
	// wins) resolves the row; the flag at +0x11 (registration param_5)
	// is the "disabled" bit. Empty slots read the sentinel entry as 0.
	const int row = charsetRowById(setId);
	return row < 0 ? false : charsetRegistry[row].disabled != 0;
}

// ---------------------------------------------------------------------------
// Phase 1c (cont): keymap modifier slots, protocol level proxy,
// scrollback mode check
// ---------------------------------------------------------------------------

void Screen::setKeyModifier(int which, int value)
{
	// FUN_007e5152 (19B): RDI = m_keymap, then a tail jump into
	// FUN_007a2c94 — the which/value args pass straight through
	keymapSetModifier(m_keymap, which, value);
}

void Screen::resetKeyModifier()
{
	// FUN_007e498c: full body consults the +0x100 view member before
	// resetting; the reset leg forwards into FUN_007a2c02 with the
	// full -1 reset — cited (param-dependent branch not transcribed)
	keymapResetModifier(m_keymap, -1);
}

void Screen::keymapSetModifier(void *keymap, int which, int value)
{
	// FUN_007a2c94: slots +0x14/+0x18/+0x1c/+0x20 for which 0/1/2/4;
	// INT_MAX value means the per-slot default (0, 2, 2, 0)
	if (!keymap)
		return;
	int *km = (int *)keymap;
	switch (which) {
	case 0: km[5] = value == 0x7fffffff ? 0 : value; break;   // +0x14
	case 1: km[6] = value == 0x7fffffff ? 2 : value; break;   // +0x18
	case 2: km[7] = value == 0x7fffffff ? 2 : value; break;   // +0x1c
	case 4: km[8] = value == 0x7fffffff ? 0 : value; break;   // +0x20
	}
}

void Screen::keymapResetModifier(void *keymap, int which)
{
	// FUN_007a2c02: -1 resets everything (+0x18 packs {2,2}); single
	// slots reset to the same defaults the setter uses
	if (!keymap)
		return;
	int *km = (int *)keymap;
	switch (which) {
	case -1:
		km[5] = 0;
		*(long *)((char *)km + 0x18) = 0x200000002LL;   // {2, 2}
		km[8] = 0;
		break;
	case 0:  km[5] = 0; break;          // +0x14
	case 1:  km[6] = 2; break;          // +0x18
	case 2:  km[7] = 2; break;          // +0x1c
	case 4:  km[8] = 0; break;          // +0x20
	}
}

bool Screen::scrollbackModeCheck() const
{
	// FUN_007e4028 (13B): the alternate-screen latch at +0x139 —
	// identical to isAltScreenActive (same function in the binary)
	return m_altScreenActive;
}

int Screen::queryProtocolLevelProxy()
{
	// FUN_007e2e42: with the params' charset slot registered as a
	// 94-set (FUN_007e2c6a), the level is strtol(paramsText + 2) / 100
	// where paramsText is the QByteArray at protocol-obj +0x18;
	// otherwise ext-capable -> 4, else -1. The protocol params object
	// build path is not transcribed yet, so only the fallback runs.
	// cited — wave-2
	return protocolExtCapable() ? 4 : -1;
}

// ---------------------------------------------------------------------------
// Phase 1d: scroll/region family
// ---------------------------------------------------------------------------

void Screen::mediaCopyDec(int mode)
{
	// FUN_007f063a (DEC MC): 4/5 toggle the auto-print latch (+0x11e);
	// every other mode is reported as an unsupported media-copy variant
	switch (mode) {
	case 4: m_decAutoPrint = false; break;
	case 5: m_decAutoPrint = true; break;
	case 1:
		reportUnsupported(QStringLiteral("Media Copy: Print Cursor Line"));
		break;
	case 8: case 9:
		reportUnsupported(QStringLiteral("Media Copy: Printer To Host"));
		break;
	case 10:
		reportUnsupported(QStringLiteral("Media Copy: Print Composed Main Display"));
		break;
	case 0xb:
		reportUnsupported(QStringLiteral("Media Copy: Print All Pages"));
		break;
	case 0x12: case 0x13:
		reportUnsupported(QStringLiteral(
			"Media Copy: Printer To Active Host Session"));
		break;
	default:
		reportUnsupported(QStringLiteral("Media Copy Type %1").arg(mode));
		break;
	}
}

void Screen::selectNumberOfLinesOnScreen(int lines)
{
	// FUN_007e5ba2 (DECSNLS): 1..255 lines, then a DIRECT core resize
	// (FUN_007a604a(m_core, lines, cols)) — no full resizeBuffer path
	if ((unsigned int)(lines - 1) > 0xfe)
		return;
	m_core->resizeCore(lines, windowColumns());
}

// ---------------------------------------------------------------------------
// Phase 1d (cont): resize family
// ---------------------------------------------------------------------------

void Screen::resizeScreen(int rows, int cols, int flag)
{
	// terminal_resizeBuffer (FUN_007e5688): dims guards, shrink-first
	// history scroll, then history/saved-primary core resizes, the dim
	// cache +0x1c0/+0x1c4, and the windowSizeChanged emit (FUN_00913540,
	// signal 34 — this also resolves notifyMessageEx's identity)
	if (rows < 2 || cols < 8)
		return;
	const int oldRows = m_history->rowCount();
	const int oldCols = m_history->columnCount();
	if (oldRows != rows || oldCols != cols) {
		if (oldRows > rows) {
			// shrink: scroll the excess out first — count = max(cursorY+1,
			// last non-empty row) - rows (FUN_007a5618); the corpus wraps
			// FUN_007e5546 in std::function RAII guards (FUN_007e2107
			// family) — cited
			int excess = m_core->m_cursorY + 1;
			const int trailing = m_core->lastNonEmptyRow();
			if (excess < trailing)
				excess = trailing;
			if (excess - rows >= 1)
				scroll(excess - rows, false, false);   // FUN_007e5546
		}
	}
	m_history->resizeCore(rows, cols);
	if (m_savedPrimary)
		m_savedPrimary->resizeCore(rows, cols);
	m_resizeRows = rows;
	m_resizeCols = cols;
	notifyMessageEx(m_core->rowCount(), m_core->columnCount(), flag);
}

void Screen::notifyMessageEx(int type, int a, int b)
{
	// FUN_00913540: QMetaObject::activate(this, staticMetaObject, 34,
	// {a, b, type}) — signal 34 windowSizeChanged(int, int, bool);
	// emit point inert until the Phase-4 wiring. Identity proven by the
	// terminal_resizeBuffer tail call.
	(void)type; (void)a; (void)b;
}

void Screen::setColumnsPerPage(int columns)
{
	// FUN_007e61fa (DECSCPP): needs the DECCOLM allow flag (+0x11d);
	// only 80 (default for 0) / 132; then resize + cursor re-pin
	if (!m_colModeAllowed)
		return;
	if (columns == 0)
		columns = 0x50;
	else if (columns != 0x50 && columns != 0x84)
		return;
	resizeScreen(rowCount(), columns, 0);
	cursorMoveRaw(currentLine(), currentColumn());   // FUN_007e4f38
}

void Screen::setLinesPerPage(int lines)
{
	// FUN_007e5eb2 (DECSLPP): mask 0x1000001001003 admits 24/25/36/48/72
	// in the 0x18..0x48 band plus the 0x90 catch-all; then resize +
	// cursor re-pin
	if ((unsigned int)(lines - 0x18) < 0x31) {
		if (((0x1000001001003ULL >> ((lines - 0x18) & 0x3f)) & 1) == 0)
			return;
	} else if (lines != 0x90) {
		return;
	}
	resizeScreen(lines, windowColumns(), 0);
	cursorMoveRaw(currentLine(), currentColumn());
}

void Screen::selectActiveStatusDisplay(int which)
{
	// FUN_007ef86e (DECSASD): value stored under the guard-computed key
	// 0x151373d5c3e56760 (same splitmix64 scheme as the 1a keys), then
	// the unsupported notice
	notifyNamedAttribute(0x151373d5c3e56760ULL, QByteArray::number(which));
	reportUnsupported(QStringLiteral("Select Active Status Display (DECSASD)"));
}

void Screen::appendHistoryBlock(int at, int count, void *style, bool cont, bool dwl)
{
	// FUN_007e4368: a contiguous run appends into the +0x1d0 pending
	// byte; a flush broadcasts the accumulated {len, data} range to the
	// view-list sinks (FUN_007e42da walks +0x1e0 and hands each sink
	// FUN_007c1f2c), otherwise a fresh {count-1, at} range goes out
	// directly. The sink registry is a Phase-4 concern, so the broadcast
	// helper below stays inert (cited).
	if (cont) {
		m_pendingHistory.append((char)at);
		return;
	}
	if (!m_pendingHistory.isEmpty()) {
		m_pendingHistory.append((char)at);
		const long range[2] = { (long)m_pendingHistory.size(),
		                        (long)(const char *)m_pendingHistory.constData() };
		historySinkBroadcast(range, style, 2, dwl);   // FUN_007e42da — cited
		m_pendingHistory.clear();
		return;
	}
	const long fresh[2] = { count - 1, at };
	historySinkBroadcast(fresh, style, 2, dwl);       // FUN_007e42da — cited
}

void Screen::historySinkBroadcast(const long *range, void *style, int kind, bool dwl)
{
	// FUN_007e42da: walk the view list (+0x1e0) and hand each live sink
	// FUN_007c1f2c(sink, range, style, kind, dwl) — same broadcast shape
	// as FUN_007eefbe. Sink registry wiring is Phase-4 (spdlog layer).
	(void)range; (void)style; (void)kind; (void)dwl;
}

// ---------------------------------------------------------------------------
// Phase 1a (deferred): XTGETTCAP (FUN_007f3518)
// ---------------------------------------------------------------------------

#include "terminfo_caps.inc"

void Screen::requestXtermTerminfoData(const QString &data)
{
	// FUN_007f3518: ';'-separated hex capability names; Co -> 256,
	// TN -> "xterm", RGB -> "8/8/8"; table hits resolve their angle
	// notation (<F1> etc.) through the keymap slots on the +0x58
	// params object (FUN_007e27a0, "Num" variant; keymap layer not
	// transcribed — cited, unresolved hits skip). Values append
	// hex-encoded, ';'-joined. Reply DCS 0/1+r ... ST; an empty or
	// echoed-back request additionally logs the unsupported notice.
	const QByteArray request = data.toLatin1();
	QByteArray result;
	const QList<QByteArray> parts = request.split(';');
	for (const QByteArray &raw : parts) {
		const QByteArray cap = QByteArray::fromHex(raw);
		QByteArray value;
		if (cap == "Co")
			value = QByteArray::number(0x100);
		else if (cap == "TN")
			value = QByteArrayLiteral("xterm");
		else if (cap == "RGB")
			value = QByteArrayLiteral("8/8/8");   // FUN_007e27a0 路径 cited
		else {
			for (const auto &e : terminfoCaps) {
				if ((cap == e.cap || cap == e.alias) && e.value[0] != '\0') {
					// keys_parseAngleNotation + keymap slot resolve — cited
					value = QByteArray();
					break;
				}
			}
		}
		if (value.isEmpty())
			continue;
		if (!result.isEmpty())
			result.append(';');
		result.append(value.toHex());
	}
	const bool miss = result.isEmpty()
	                  || (result.size() == request.size() && result == request);
	if (request.isEmpty() || miss)
		reportUnsupported(QStringLiteral(
			"XTerm Request Termcap/Terminfo String %1").arg(data));
	sendResponse(QByteArrayLiteral("\x1bP") + (miss ? "0" : "1")
	             + QByteArrayLiteral("+r") + result + QByteArrayLiteral("\x1b\\"));
}
