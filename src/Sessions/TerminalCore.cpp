#include "TerminalCore.h"

// Bodies transcribed from decompilation; comments cite the source
// function. Phase-1 restoration (reference, not compiled).

// ---------------------------------------------------------------------------
// Tabstops (core +0x18)
// ---------------------------------------------------------------------------

bool Tabstops::test(int column) const
{
	// FUN_007e5c98: bit at (column>>3)+1 inside the +0x10 payload
	return ((payload[(column >> 3) + 1] >> (column & 7)) & 1) != 0;
}

void Tabstops::set(int column, bool on)
{
	// FUN_007e52fc / FUN_007e5df0 mode 0: single bit flip; FUN_007c4392
	// grows the bitmap first (not shown)
	unsigned char mask = (unsigned char)(1 << (column & 7));
	if (on)
		payload[(column >> 3) + 1] |= mask;
	else
		payload[(column >> 3) + 1] &= (unsigned char)~mask;
}

void Tabstops::clear()
{
	// FUN_007e5df0 mode 3: clears every column up to the screen width
	// (loop over FUN_007e5b96 width, cited)
}

// ---------------------------------------------------------------------------
// Sizes & limits
// ---------------------------------------------------------------------------

int TerminalCore::rowCount() const
{
	// FUN_007a4b4a
	return m_rowCount;
}

int TerminalCore::columnCount() const
{
	// FUN_007a4906 (+0xe4)
	return m_columnCount;
}

int TerminalCore::scrollRegionBottomLimit() const
{
	// FUN_007a4bb4
	return m_scrollRegionBottom;
}

int TerminalCore::scrollRegionTopLimit() const
{
	// FUN_007a4be2: raw +0xd0, 0 when unset, never above bottom-1
	if (m_scrollRegionTop < 1)
		return 0;
	if (m_scrollRegionTop < m_scrollRegionBottom - 1)
		return m_scrollRegionTop;
	return m_scrollRegionBottom - 1;
}

int TerminalCore::scrollRegionHeight() const
{
	// FUN_007a4c48
	return scrollRegionBottomLimit() - scrollRegionTopLimit() + 1;
}

int TerminalCore::regionWidth() const
{
	// FUN_007a49a2
	return rightMargin() - leftMargin() + 1;
}

int TerminalCore::leftMargin() const
{
	// FUN_007a493c: +0xd8, floored at 0, capped under rightMargin-1
	if (m_leftMargin < 1)
		return 0;
	if (m_leftMargin < rightMargin() - 1)
		return m_leftMargin;
	return rightMargin() - 1;
}

int TerminalCore::rightMargin() const
{
	// FUN_007a490e: +0xdc; unset (<=0) means width-1
	if (m_rightMargin > 0) {
		if (m_rightMargin < m_columnCount - 1)
			return m_rightMargin;
		return m_columnCount - 1;
	}
	return m_columnCount - 1;
}

int TerminalCore::originLeft() const
{
	// FUN_007a4962
	if (!(m_flags & 0x40))
		return 0;
	return leftMargin();
}

int TerminalCore::originRight() const
{
	// FUN_007a49c6
	if (m_flags & 0x40)
		return rightMargin();
	return m_columnCount - 1;
}

int TerminalCore::originTop() const
{
	// FUN_007a4c08
	if (!(m_flags & 0x40))
		return 0;
	return scrollRegionTopLimit();
}

int TerminalCore::originBottom() const
{
	// FUN_007a5304
	if (m_flags & 0x40)
		return scrollRegionBottomLimit();
	return rowCount() - 1;
}

bool TerminalCore::inScrollRegion(int line) const
{
	// FUN_007a4c16
	if (line < scrollRegionTopLimit())
		return false;
	return line <= scrollRegionBottomLimit();
}

// ---------------------------------------------------------------------------
// Cursor movement
// ---------------------------------------------------------------------------

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

void TerminalCore::cursorUp(int lines)
{
	// FUN_007a55d2 — mirror of cursorDown, clamps at region top and only
	// when the cursor started at/inside the region
	if (lines < 1)
		return;
	int newY = m_cursorY - lines;
	if (m_flags & 0x40) { // DECOM: clamp to scroll region
		const int top = scrollRegionTopLimit();
		if (top <= m_cursorY && newY < top)
			newY = top;
	}
	setCursorY(newY);
}

void TerminalCore::cursorForward(int columns)
{
	// FUN_007a54b4 — mirror structure of cursorDown (X/Y symmetry)
	if (columns < 1)
		return;
	int newX = m_cursorX + columns;
	if (m_flags & 0x40) { // DECSLRM: clamp to right margin
		const int right = rightMargin();
		if (m_cursorX <= right && right < newX)
			newX = right;
	}
	setCursorX(newX);
}

void TerminalCore::cursorBackward(int columns)
{
	// FUN_007a546c — mirror of cursorForward, clamps at left margin
	if (columns < 1)
		return;
	int newX = m_cursorX - columns;
	if (m_flags & 0x40) { // DECSLRM: clamp to left margin
		const int left = leftMargin();
		if (left <= m_cursorX && newX < left)
			newX = left;
	}
	setCursorX(newX);
}

void TerminalCore::moveColumnBy(int delta)
{
	// FUN_007a5460: unclamped shift (backspace/backIndex/forwardIndex path)
	setCursorX(m_cursorX + delta);
}

void TerminalCore::moveLineBy(int delta)
{
	// FUN_007a557c: unclamped shift (IND/RI when inside the region)
	setCursorY(m_cursorY + delta);
}

void TerminalCore::moveCursorRaw(int y, int x)
{
	// FUN_007a538a: clamps to the screen (not margins); a double-width
	// row halves the usable width; flag 0x08 marks "cursor moved", flag
	// 0x80 (wide-wrap pending) is cleared when landing inside the line
	const int oldY = m_cursorY;
	const int oldX = m_cursorX;
	int width = m_columnCount;
	if (rowCount() - 1 <= y)
		y = rowCount() - 1;
	if (y < 0)
		y = 0;
	m_cursorY = y;
	if (m_rows[y]->flags & 0x8) // double-width line
		width >>= 1;
	int newX = width - 1;
	if (x < width - 1)
		newX = x;
	if (newX < 0)
		newX = 0;
	m_cursorX = newX;
	if (oldY == y && rightMargin() >= newX)
		m_flags &= (unsigned short)~0x80; // clear wide-wrap pending
	if (oldY == y && newX == oldX)
		return;
	m_flags |= 0x8; // cursor moved
}

void TerminalCore::moveCursor(int y, int x)
{
	// FUN_007a54f8: CUP/HPA/VPA endpoint — clamps to the origin-mode
	// bounds (margins) when flag 0x40 is set, else raw screen clamp
	if (!(m_flags & 0x40)) {
		moveCursorRaw(y, x);
		return;
	}
	if (y > scrollRegionBottomLimit())
		y = scrollRegionBottomLimit();
	if (y < scrollRegionTopLimit())
		y = scrollRegionTopLimit();
	if (x >= rightMargin())
		x = rightMargin();
	if (x < leftMargin())
		x = leftMargin();
	moveCursorRaw(y, x);
}

// ---------------------------------------------------------------------------
// Rows
// ---------------------------------------------------------------------------

struct Row *TerminalCore::row(int y)
{
	// FUN_007a44f8
	return m_rows + y;
}

int TerminalCore::rowLength(struct Row *row) const
{
	// FUN_007a3dfc (+0x0c)
	return row->length;
}

void TerminalCore::setRowLength(struct Row *row, int length)
{
	// FUN_007a5ff2: resizes the cell (+0x08) and attribute (+0x38)
	// arrays, marks the row changed and drops the spare buffer (+0x50)
	if (rowLength(row) == length)
		return;
	// FUN_007aa3a6 / FUN_007aa1bc resize both arrays (cited)
	setRowFlags(row, 1); // FUN_007a3dc0
	row->spare = nullptr; // +0x50
}

void TerminalCore::setRowFlags(struct Row *row, int bits)
{
	// FUN_007a3dc0: row flag update (bit 1 = changed/wrapped-related)
}

void TerminalCore::resetRow(struct Row *row, void *templateRow)
{
	// FUN_007a3c9a: frees per-cell auxiliary glyph objects (+0x10) when
	// the wrap bit (0x80) is set, clears both flag bytes, memsets the
	// cell array (+0x10) and the 2-byte attribute array (+0x40, count
	// at +0x3c), keeps bits 0x3f; a non-null template re-seeds the row
	// (copy tail truncated in decompile)
	void *cells = row->cells;
	const size_t bytes = (size_t)row->length * 0x20;
	if (row->flags & 0x80) {
		for (void *p = cells; p != (char *)cells + bytes; p = (char *)p + 0x20) {
			void *aux = *(void **)((char *)p + 0x10);
			if (aux) {
				if (*(void **)((char *)aux + 8) != (char *)aux + 0x10)
					free(*(void **)((char *)aux + 8));
				operator delete(aux, 0x18);
				*(void **)((char *)p + 0x10) = nullptr;
			}
		}
	}
	row->flags &= 0x3f;
	memset(cells, 0, bytes);
	memset(row->attrArray, 0, (size_t)row->attrCount * 2);   // +0x40/+0x3c
	if (templateRow)
		copyRowFromTemplate(row, templateRow);   // tail — cited
}

void TerminalCore::resetWrapPending()
{
	// FUN_007a4564 (lineFeed pre-step)
	setRowFlags(m_rows[m_cursorY], 1);
	markDirty(1);
}

void TerminalCore::markDirty(int level)
{
	// FUN_007a454e: core flag byte bit3 (0x08)
	m_flags = (unsigned short)((m_flags & 0xf7) | (level & 1) * 8);
}

void TerminalCore::markLine(int line, int arg)
{
	// FUN_007a463c: post-erase line notification — body cited
}

int TerminalCore::lastContentRowCount() const
{
	// FUN_007a5618: rows up to and including the last non-blank one
	// (FUN_007a4a06 checks a row for content)
	for (int i = rowCount() - 1; i >= 0; i--)
		if (rowHasContent(m_rows[i])) // FUN_007a4a06
			return i + 1;
	return 0;
}

// ---------------------------------------------------------------------------
// Save/restore cursor (DECSC/DECRC)
// ---------------------------------------------------------------------------

bool TerminalCore::hasSavedCursor() const
{
	// FUN_007a44da
	return (m_saveByte28 & 1) != 0;
}

void TerminalCore::saveCursor()
{
	// FUN_007a5c70 (DECSC): packs cursor, flag bytes, SGR/charset state
	// and the four charset slots into the +0x20..+0x68 save block
	m_savedCursorY = m_cursorY;             // *(u64*)(this+0x20) = *(u64*)(this+0xc4)
	m_savedCursorX = m_cursorX;
	copyState(&m_charsetSaved, &m_sgrState); // FUN_007aa2e2(+0x38, +0x88)
	unsigned char b0 = m_flags2;             // +0xb0
	m_saveByte29 = (unsigned char)((m_saveByte29 & 0xfc) | ((b0 >> 4) & 3));
	m_saved2 = m_stateB8;                    // *(u64*)(this+0x30) = *(u64*)(this+0xb8)
	m_saveByte28 = (unsigned char)((m_saveByte28 & 1)
		| ((b0 & 3) << 4)
		| (b0 >> 2) << 6
		| (m_flags & 2)
		| ((m_flags >> 4) & 4)
		| ((m_flags << 1) & 8));
	for (int i = 0; i < 4; i++)             // FUN_00801a46(charsetManager, i)
		m_savedCharsets[i] = charsetSlot(i);
	m_saveByte28 |= 1;
}

void TerminalCore::restoreCursor()
{
	// FUN_007a5d20 (DECRC): inverse of saveCursor
	moveCursorRaw(m_savedCursorY, m_savedCursorX);
	copyState(&m_sgrState, &m_charsetSaved); // FUN_007aa2e2(+0x88, +0x38)
	unsigned char s28 = m_saveByte28;
	m_flags2 = (unsigned char)((m_flags2 & 0xc0)
		| ((s28 >> 4) & 3)
		| ((s28 >> 6) << 2)
		| ((m_saveByte29 & 3) << 4));
	m_stateB8 = m_saved2;
	m_flags = (unsigned short)((m_flags & 0xb9)
		| (s28 & 2)
		| ((s28 & 4) << 4)
		| ((s28 >> 1) & 4));
	for (int i = 0; i < 4; i++)             // FUN_00803470(charsetManager, i, ...)
		setCharsetSlot(i, m_savedCharsets[i]);
}

// ---------------------------------------------------------------------------
// Erase
// ---------------------------------------------------------------------------

int TerminalCore::eraseCells(int line, int from, unsigned short attr, int count,
                             bool skipProtected, bool selective)
{
	// FUN_007a596c: delegates to rowEraseCells, marks dirty on change
	if (line >= rowCount())
		return 0;
	int n = rowEraseCells(m_rows[line], from, attr, count,
	                      skipProtected, selective, m_blankRowTemplate);
	if (n > 0)
		markDirty(1);
	return n;
}

int TerminalCore::rowEraseCells(struct Row *row, int from, unsigned short attr,
                                int count, bool skipProtected, bool selective,
                                void *blankTemplate)
{
	// FUN_007a579c: fills [from, from+n) with a blank cell built from
	// `attr`; skipProtected skips DECSCA-protected cells (flag &2),
	// selective keeps only "selectable" cells (flag &1). Cell flags via
	// FUN_007a3c68, cell template copy via FUN_007aa2e2, blank template
	// carried at +0x60 of the local context.
	const int length = rowLength(row);
	if (from >= length)
		return 0;
	int n = length - from;
	if (count < n)
		n = count;
	int written = 0;
	for (int i = from; i < from + n; i++) {
		if (skipProtected && (cellFlags(row, i) & 2))
			continue; // DECSCA protected
		if (selective && !(cellFlags(row, i) & 1))
			continue; // DECSED selective
		writeBlankCell(row, i, attr, blankTemplate); // cited helpers
		written++;
	}
	return written;
}

// ---------------------------------------------------------------------------
// Scroll
// ---------------------------------------------------------------------------

void TerminalCore::scrollRegion(int top, int count, bool down, bool fillTemplate)
{
	// FUN_007a4c6c: scrolls [top..bottomLimit] by `count` lines.
	// flag 0x20 clear: rotate the row-pointer array (m_rows) and reset
	// the vacated row from the +0xa0 template (or blank).
	// flag 0x20 set (left/right margins active): cell-level scroll
	// restricted to [leftMargin..rightMargin]; 0x20-byte cells plus a
	// 2-byte attribute array move between rows, wrap (0x80) and
	// double-width (0x40) flag bits travel with the source row.
	if (count < 1)
		return;
	const int bottom = scrollRegionBottomLimit();
	if (scrollRegionTopLimit() > top)
		top = scrollRegionTopLimit();
	if (count > scrollRegionHeight())
		count = scrollRegionHeight();
	if (!(m_flags & 0x20)) {
		for (; count > 0; count--) {
			struct Row *wrapped;
			if (!down) {
				wrapped = m_rows[top];
				memmove(m_rows + top, m_rows + top + 1,
				        (bottom - top) * sizeof(*m_rows));
				m_rows[bottom] = wrapped;
			} else {
				wrapped = m_rows[bottom];
				memmove(m_rows + top + 1, m_rows + top,
				        (bottom - top) * sizeof(*m_rows));
				m_rows[top] = wrapped;
			}
			resetRow(wrapped, fillTemplate ? m_blankRowTemplate : nullptr);
		}
	} else {
		const int left = leftMargin();
		const int width = rightMargin() - left + 1;
		if (!down) {
			for (int y = top + count; y <= bottom; y++) {
				copyRowCells(m_rows[y], m_rows[y - count], left, width);
				preserveRowFlags(m_rows[y], m_rows[y - count]);
			}
			for (int y = bottom; y > bottom - count; y--)
				clearRowCells(m_rows[y], left, width);
		} else {
			for (int y = bottom - count; y >= top; y--) {
				copyRowCells(m_rows[y], m_rows[y + count], left, width);
				preserveRowFlags(m_rows[y], m_rows[y + count]);
			}
			for (int y = top; y < top + count; y++)
				clearRowCells(m_rows[y], left, width);
		}
	}
	markDirty(1);     // FUN_007a454e
	notifyChanged(1); // FUN_007a4532
}

void TerminalCore::scrollHorizontal(int delta)
{
	// FUN_007a68ae: shifts cells within [leftMargin..rightMargin] on every
	// row of the scroll region; FUN_007a5dce removes cells at one edge and
	// FUN_007a641a inserts blanks (carrying the +0x88 SGR context) at the
	// other; sign selects the direction pair.
	if (delta == 0)
		return;
	int count = delta < 0 ? -delta : delta;
	if (count > regionWidth())
		count = regionWidth();
	for (int y = scrollRegionTopLimit(); y <= scrollRegionBottomLimit(); y++) {
		struct Row *row = m_rows[y];
		if (!row)
			continue;
		if (delta >= 0) {
			rowDeleteCells(row, rightMargin() - count + 1, count);        // FUN_007a5dce
			rowInsertBlanks(row, leftMargin(), count, &m_sgrState);       // FUN_007a641a
		} else {
			rowDeleteCells(row, leftMargin(), count);                     // FUN_007a5dce
			rowInsertBlanks(row, rightMargin() - count + 1, count, &m_sgrState);
		}
	}
	markDirty(1);
}

// ---------------------------------------------------------------------------
// Rectangular areas
// ---------------------------------------------------------------------------

void TerminalCore::eraseRect(int top, int left, int bottom, int right, bool selective)
{
	// FUN_007a6d98 — worker body not yet transcribed
}

void TerminalCore::changeRectAttrs(int top, int left, int bottom, int right, int what)
{
	// FUN_007a748e — worker body not yet transcribed
}

void TerminalCore::reverseRectAttrs(int top, int left, int bottom, int right, int what)
{
	// FUN_007a721e — worker body not yet transcribed
}

void TerminalCore::fillRect(int top, int left, int bottom, int right,
                            const void *cell, void *aux)
{
	// FUN_007a6eec — worker body not yet transcribed
}

// ---------------------------------------------------------------------------
// Margins / reset
// ---------------------------------------------------------------------------

void TerminalCore::setTopBottomMargins(int top, int bottom)
{
	// FUN_007a4672 (DECSTBM core)
	m_scrollRegionTop = top;
	m_scrollRegionBottom = bottom;
	if (bottom > 0)
		m_scrollRegionTop = top < bottom - 2 ? top : bottom - 2;
}

void TerminalCore::setCursorStyle(int style)
{
	// FUN_007a45ee — body cited
}

void *TerminalCore::cursorUpdated()
{
	// FUN_007a44c0: cursor display object refresh — body cited
	return nullptr;
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

// ---------------------------------------------------------------------------
// Insert/delete (batch 2)
// ---------------------------------------------------------------------------

void TerminalCore::insertCharacter(int count)
{
	// FUN_007a6782 (ICH): shift cells right at the cursor within the
	// right margin (delete at the right edge + insert blanks at cursor)
	if (count <= 0 || !columnInRange(m_cursorX))
		return;
	const int room = rightMargin() - m_cursorX + 1;
	if (count > room)
		count = room;
	struct Row *row = m_rows[m_cursorY];
	rowDeleteCells(row, rightMargin() - count + 1, count);           // FUN_007a5dce
	rowInsertBlanks(row, m_cursorX, count, &m_sgrState);             // FUN_007a641a
}

void TerminalCore::deleteCharacter(int count)
{
	// FUN_007a65d2 (DCH): remove cells at the cursor, blanks at the edge
	if (count <= 0 || !columnInRange(m_cursorX))
		return;
	const int room = rightMargin() - m_cursorX + 1;
	if (count > room)
		count = room;
	struct Row *row = m_rows[m_cursorY];
	rowDeleteCells(row, m_cursorX, count);                           // FUN_007a5dce
	rowInsertBlanks(row, rightMargin() - count + 1, count, &m_sgrState);
}

void TerminalCore::insertLine(int count)
{
	// FUN_007a5290 (IL): scroll [cursorY..bottom] down by count, cursor
	// to the left margin
	if (count < 1 || !inScrollRegion(m_cursorY) || !columnInRange(m_cursorX))
		return;
	const int room = scrollRegionBottomLimit() - m_cursorY + 1;
	if (count > room)
		count = room;
	scrollRegion(m_cursorY, count, true, true);   // FUN_007a4c6c(down, template)
	m_cursorX = leftMargin();
}

void TerminalCore::deleteLine(int count)
{
	// FUN_007a5220 (DL): scroll [cursorY..bottom] up by count
	if (count < 1 || !inScrollRegion(m_cursorY) || !columnInRange(m_cursorX))
		return;
	const int room = scrollRegionBottomLimit() - m_cursorY + 1;
	if (count > room)
		count = room;
	scrollRegion(m_cursorY, count, false, true);
	m_cursorX = leftMargin();
}

void TerminalCore::insertColumn(int count)
{
	// FUN_007a6822 (DECIC): insertCharacter on every row of the scroll
	// region, cursor row restored afterwards
	if (count < 1 || !inScrollRegion(m_cursorY) || !columnInRange(m_cursorX))
		return;
	const int savedY = m_cursorY;
	m_cursorY = scrollRegionTopLimit();
	for (int y = scrollRegionTopLimit(); y <= scrollRegionBottomLimit(); y++) {
		insertCharacter(count);
		m_cursorY++;
	}
	m_cursorY = savedY;
}

void TerminalCore::deleteColumn(int count)
{
	// FUN_007a6672 (DECDC): deleteCharacter across the scroll region
	if (count < 1 || !inScrollRegion(m_cursorY) || !columnInRange(m_cursorX))
		return;
	const int savedY = m_cursorY;
	m_cursorY = scrollRegionTopLimit();
	for (int y = scrollRegionTopLimit(); y <= scrollRegionBottomLimit(); y++) {
		deleteCharacter(count);
		m_cursorY++;
	}
	m_cursorY = savedY;
}

void TerminalCore::setSgrState(unsigned long long sgr)
{
	// FUN_007a45f6: publishes the 64-bit SGR state into the render
	// attribute context — body cited
}

void TerminalCore::setAttributeChangeExtent()
{
	// FUN_007a4518 — body cited
}

void TerminalCore::resetViewport()
{
	// FUN_007a4aea — body cited
}

void TerminalCore::clearMargins(int arg)
{
	// FUN_007a4a98 — body cited
}

bool TerminalCore::columnInRange(int column) const
{
	// FUN_007a4970: column within the usable line (double-width aware)
	return true;   // body cited
}
