#include "TerminalCore.h"
#include <cstdlib>
#include <new>

// charset registry accessors (mirror of Screen's charset_registry.inc;
// internal linkage per TU is acceptable duplication for now)
#include "charset_registry.inc"
static int charsetRegistryRow(int id)
{
	int row = -1;
	for (int i = 0; i < 31; ++i)
		if (charsetRegistry[i].id == id)
			row = i;
	return row;
}


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
	// FUN_007a44f8: *(Row**)(m_rows + y*8)
	return m_rows[y];
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
	// FUN_007a3dc0: bits!=0 -> (old & 0xfc) | bit1 (also clears bit0);
	// bits==0 -> clear bit1 only
	if (bits != 0)
		row->flags = (unsigned char)((row->flags & 0xfc) | ((bits & 1) << 1));
	else
		row->flags = (unsigned char)(row->flags & 0xfd);
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
	memset(row->attrArray, 0, (size_t)row->length * 2);   // +0x40 array, count at +0x3c
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

void TerminalCore::notifyChanged(int level)
{
	// FUN_007a4532: core flag byte bit0
	m_flags = (unsigned short)((m_flags & 0xfe) | (level & 1));
}

void TerminalCore::markLine(int line, int arg)
{
	// FUN_007a463c: row = row(line); rowHook(row, arg); arg==0 clears
	// the cached working row (+0xa8), otherwise the row is cached
	struct Row *r = row(line);
	rowHook(r, arg);
	m_workRow = arg ? r : nullptr;
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
	m_saved2 = m_sgrBits;                   // *(u64*)(this+0x30) = *(u64*)(this+0xb8)
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
	m_sgrBits = m_saved2;
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
// Cursor setters (一行真身,TERMINAL-CORE.md)
// ---------------------------------------------------------------------------
void TerminalCore::setCursorX(int x)
{
	// FUN_007a5452: tail into FUN_007a538a with the current row
	setCursorYX(m_cursorY, x);
}

void TerminalCore::setCursorY(int y)
{
	// FUN_007a5570: tail into FUN_007a538a with the current column
	setCursorYX(y, m_cursorX);
}

void TerminalCore::setCursorYX(int y, int x)
{
	// FUN_007a538a (199B): clamps both axes; a double-width row halves
	// the column span. The pending-wrap latch (flags 0x80) survives a
	// same-position set (the margin-cross finalize re-pins the cursor)
	// and a target past the right margin; any real move clears it and
	// sets the moved bit (0x08).
	const int oldY = m_cursorY;
	const int oldX = m_cursorX;
	if (y >= rowCount())
		y = rowCount() - 1;
	if (y < 0)
		y = 0;
	m_cursorY = y;
	int span = m_columnCount;
	if (m_rows[y] && (m_rows[y]->flags & 8))
		span >>= 1;                       // double-width line
	if (x > span - 1)
		x = span - 1;
	if (x < 0)
		x = 0;
	if (oldY == y && oldX == x)
		return;                           // same position: latch kept
	if (oldY == y && rightMargin() < x)
		return;                           // past the margin: latch kept
	m_cursorX = x;
	m_flags &= 0x7f;                      // real move: clear the latch
	markDirty(1);                         // moved bit
}

void TerminalCore::removeRow(int y)
{
	// FUN_007a463c: rows 数组管理(0x7e6f42 写路径调用)
	if (y >= 0 && y < rowCount())
		m_rows[y] = nullptr;
	markDirty(1);
}

// ---------------------------------------------------------------------------
// Row cell operations (TERMINAL-CORE.md cited helpers)
// ---------------------------------------------------------------------------
void TerminalCore::writeBlankCell(struct Row *row, int i, unsigned short attr,
                                  void *blankTemplate)
{
	// FUN_007e4916 内联尾:attr 头 + copyCell(body) 对;attr 写入
	// attrHeadAt(row,i),copyCell(cellAt(row,i), blankTemplate);
	*(unsigned short *)attrHeadAt(row, i) = attr;
	copyCell(cellAt(row, i), blankTemplate);
}

void TerminalCore::copyRowCells(struct Row *dst, struct Row *src, int from,
                                int count)
{
	// FUN_007a44f8 辅助: memmove cells+attrs from src to dst
	if (from < 0 || count < 1)
		return;
	memmove((char *)dst->cells + from * 0x20,
	        (const char *)src->cells + from * 0x20,
	        (size_t)count * 0x20);
	memmove((char *)dst->attrArray + from,
	        (const char *)src->attrArray + from,
	        (size_t)count * 2);
}

void TerminalCore::preserveRowFlags(struct Row *dst, struct Row *src)
{
	// 0x7a 辅助(滚动): flags 高位保留自 src(避免行级标志丢失)
	dst->flags = (unsigned char)((dst->flags & 0x0f) | (src->flags & 0xf0));
}

void TerminalCore::clearRowCells(struct Row *row, int from, int count)
{
	// FUN_007e4916 内联: 按当前 erase attr 空白化
	if (from < 0 || count < 1)
		return;
	for (int i = from; i < from + count; i++)
		*(unsigned short *)attrHeadAt(row, i) = 0;
	memset((char *)row->cells + from * 0x20, 0, (size_t)count * 0x20);
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

bool TerminalCore::setCellRaw(int y, int x, const void *cell)
{
	// FUN_007a5b36: bounds-check y, write via FUN_007a5aac, mark
	// dirty; returns flag bit3 (0x08)
	if (y >= rowCount())
		return false;
	setRowCell(m_rows[y], x, cell, nullptr);   // FUN_007a5aac
	markDirty(1);
	return (m_flags >> 3) & 1;
}

void TerminalCore::eraseRect(int top, int left, int bottom, int right, bool selective)
{
	// FUN_007a6d98 (DECERA): collects the rect's cells
	// (FUN_007a6ab0 mode 1), erases each non-empty glyph (skipping
	// protected cells when selective: cell flag &1), then notifies the
	// changed rect (FUN_007a4590) and frees the list
	Rect r = { top, left, bottom, right };
	// per-cell erase walk (glyph != 0, protected skip when selective)
	// — cited (FUN_007a6ab0 list walk)
	notifyRectChanged(&r, 0);
}

void TerminalCore::changeRectAttrs(int top, int left, int bottom, int right, int what)
{
	// FUN_007a748e (DECCARA): parses the attribute list
	// (FUN_007a712b, auto-extends when empty), iterates rect cells
	// (FUN_007a6ab0 mode 2) applying the SGR change, then notifies.
	// Inner attribute transform cited.
	Rect r = { top, left, bottom, right };
	void *attrs = parseAttrList(&what, nullptr);
	void *it = collectRectCells(&r, nullptr, 2);
	// per-cell SGR application — cited
	notifyRectChanged(&r, 0);
}

void TerminalCore::reverseRectAttrs(int top, int left, int bottom, int right, int what)
{
	// FUN_007a721e (DECRARA): same skeleton as DECCARA with the
	// reversal transform; mode 2 iteration + notify
	Rect r = { top, left, bottom, right };
	void *attrs = parseAttrList(&what, nullptr);
	void *it = collectRectCells(&r, nullptr, 2);
	// per-cell attribute reversal — cited
	notifyRectChanged(&r, 0);
}

void TerminalCore::fillRect(int top, int left, int bottom, int right,
                            const void *cell, void *aux)
{
	// FUN_007a6eec (DECFRA): iterates rect cells (mode 1), writes the
	// 2-byte glyph head and copyCell's the fill template; when the
	// template carries a glyph payload (+0xa/+0x10) an extra pass
	// handles the wide-cell columns (tail cited)
	Rect r = { top, left, bottom, right };
	// per-cell fill walk (glyph head + copyCell template)
	// — cited; wide-cell extra pass cited
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

int TerminalCore::cursorStyleBit() const
{
	// FUN_007a44c0 (26B): 6-bit table 0x2b indexed by the cursor style
	// (+0xcc); out-of-range styles read 0. Bit set for styles 0,1,3,5
	// (the blink mask — also the DECRQM mode-12 probe)
	return (unsigned)m_cursorStyle < 6 ? (int)((0x2bu >> (unsigned)m_cursorStyle) & 1u) : 0;
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
	// FUN_007a45f6: stores +0xb8; flag bit4 (0x10) makes the blank-row
	// template (+0xa0) follow the SGR "look" (low 14 bits stripped),
	// otherwise the template is zeroed
	m_sgrBits = sgr;
	if (m_flags & 0x10)
		m_blankTemplateSgr = sgr & 0xffffffffffffc000ULL;
	else
		m_blankTemplateSgr = 0;
}

void TerminalCore::setAttributeChangeExtent(int extent)
{
	// FUN_007a4518 (DECSACE): extent==2 sets flags byte1 bit0,
	// extent<2 clears it, other values ignored
	if (extent < 2) {
		m_flags2 = (unsigned char)(m_flags2 & 0xfe);
		return;
	}
	if (extent == 2)
		m_flags2 = (unsigned char)(m_flags2 | 1);
}

void TerminalCore::resetViewport()
{
	// FUN_007a4aea: clears horizontal margins and resets the scroll
	// region (trailing args dropped by Ghidra, -1/-1 per clearMargins)
	clearMargins(-1, -1);
	setTopBottomMargins(-1, -1);
}

void TerminalCore::clearMargins(int left, int right)
{
	// FUN_007a4a98: writes +0xd8/+0xdc and re-evaluates flag bit5
	// (0x20) = "horizontal margins effective"
	m_leftMargin = left;
	m_rightMargin = right;
	bool effective;
	if (left < 1) {
		effective = right >= 1 && right < m_columnCount - 1;
	} else {
		effective = true;
	}
	m_flags = (unsigned short)((m_flags & 0xdf) | ((effective ? 1 : 0) << 5));
}

bool TerminalCore::columnInRange(int column) const
{
	// FUN_007a4970: leftMargin() <= column <= rightMargin()
	if (column < leftMargin())
		return false;
	return column <= rightMargin();
}

// ---------------------------------------------------------------------------
// Row-level cell workers (innermost layer, batch 4)
// ---------------------------------------------------------------------------

void TerminalCore::rowDeleteCells(struct Row *row, int at, int count)
{
	// FUN_007a5dce: removes `count` cells at `at` by shifting the rest
	// left (0x20-stride cell copies via FUN_007aa2e2), then the freed
	// tail is reset (blank-fill tail truncated in the decompile)
	const int length = rowLength(row);
	int n = length - at;
	if (count < n)
		n = count;
	if (n <= 0)
		return;
	char *cells = (char *)row->cells;
	for (int i = at; i < at + n; i++)
		copyCell(cells + (size_t)i * 0x20, cells + (size_t)(i + n) * 0x20);   // FUN_007aa2e2
	// tail [length-n..length) blank reset — cited
}

void TerminalCore::rowInsertBlanks(struct Row *row, int at, int count, void *sgrCtx)
{
	// FUN_007a641a: grows the cell/attribute arrays to at least
	// length+count (FUN_007aa3a6 keeps capacity), builds a blank cell
	// from the SGR context (FUN_007aa2e2 local), shifts cells from the
	// end down to `at` right by `count`, then writes `count` blanks
	if (at < 0 || at > rowLength(row))
		return;
	if (count == 0)
		return;
	growRowArrays((char *)row + 8, rowLength(row) + count,
	              rowLength(row) + count);   // FUN_007aa3a6 (array header at row+8)
	unsigned char blank[16];
	buildBlankCell(blank, sgrCtx);                    // FUN_007aa2e2
	char *cells = (char *)row->cells;
	for (int i = rowLength(row) - 1; i >= at; i--)
		copyCell(cells + (size_t)(i + count) * 0x20, cells + (size_t)i * 0x20);
	for (int i = 0; i < count; i++)
		writeCell(cells + (size_t)(at + i) * 0x20, blank);
}

void TerminalCore::copyRowFromTemplate(struct Row *row, void *templateRow)
{
	// FUN_007a3c9a tail: every cell's +0x18 domain is seeded with the
	// template pointer and the row takes flag 0x40 (payload present)
	char *cells = (char *)row->cells;
	for (char *p = cells; p != cells + (size_t)row->length * 0x20; p += 0x20)
		*(void **)(p + 0x18) = templateRow;
	row->flags |= 0x40;
}

// ---------------------------------------------------------------------------
// Cell copy / row-array growth primitives
// ---------------------------------------------------------------------------

void TerminalCore::copyCell(void *dst, const void *src)
{
	// FUN_007aa2e2: field-wise cell copy (offsets 0,4,8,10,0x18) plus a
	// deep copy of the auxiliary glyph object at +0x10 (0x18-byte object
	// with an optional heap buffer at +8); the destination's own aux
	// object is released first
	unsigned char *d = (unsigned char *)dst;
	const unsigned char *s = (const unsigned char *)src;
	d[0] = s[0];
	*(int *)(d + 4) = *(const int *)(s + 4);
	*(unsigned short *)(d + 10) = *(const unsigned short *)(s + 10);
	*(unsigned long long *)(d + 0x18) = *(const unsigned long long *)(s + 0x18);
	*(unsigned short *)(d + 8) = *(const unsigned short *)(s + 8);
	void *oldAux = *(void **)(d + 0x10);
	if (oldAux) {
		if (*(void **)((char *)oldAux + 8) != (char *)oldAux + 0x10)
			free(*(void **)((char *)oldAux + 8));
		operator delete(oldAux, 0x18);
	}
	if (*(const void *const *)(s + 0x10)) {
		const char *srcAux = (const char *)*(const void *const *)(s + 0x10);
		int *fresh = (int *)::operator new(0x18);
		fresh[0] = 1;                            // refcount
		*(void **)(fresh + 2) = (char *)fresh + 0x10;   // payload -> embedded tail
		cloneGlyphPayload(fresh, *(const void *const *)(srcAux + 8),
		                  *(const int *)(srcAux + 4));
		*(void **)(d + 0x10) = fresh;
	} else {
		*(void **)(d + 0x10) = nullptr;
	}
}

// FUN_007aa1bc: ushort-vector {cap@0, count@4, data@8} resize to len with
// capacity cap; embedded tail (header+0x10) when cap < 2; preserves
// min(len, count) entries and zero-fills the grown region
void TerminalCore::resizeUshortVector(int *hdr, int len, int cap)
{
	int *src = *(int **)(hdr + 2);
	int keep = hdr[1] < len ? hdr[1] : len;
	int *embedded = hdr + 4;
	if (hdr[0] != cap) {
		int *dst;
		if (cap < 2) {
			*(int **)(hdr + 2) = embedded;
			hdr[0] = 1;
			dst = embedded;
		} else {
			dst = (int *)malloc((size_t)cap * 2);
			*(int **)(hdr + 2) = dst;
			hdr[0] = cap;
		}
		hdr[1] = 0;
		memcpy(dst, src, (size_t)keep * 2);
	}
	hdr[1] = keep;
	if (src != embedded && src != *(int **)(hdr + 2))
		free(src);
	for (int i = hdr[1]; i < len; i++) {
		hdr[1] = i + 1;
		((unsigned short *)*(void **)(hdr + 2))[i] = 0;
	}
}

// QList-shaped span {alloc, count, data} helpers for the rect collector
// (inline append / FUN_007aa5ca reserve) and parseAttrList
// (qlist_uint_append); the binary uses QListData, this tier keeps the
// span shape used throughout the file
struct IntList { int alloc; int count; void *data; };

static void reserveList(void *list, int need)
{
	IntList *l = (IntList *)list;
	if (need > l->alloc) {
		int cap = l->alloc * 2 < need ? need : l->alloc * 2;
		l->data = realloc(l->data, (size_t)cap * 16);
		l->alloc = cap;
	}
}

static void appendCellPair(void *list, const void *head, const void *cell)
{
	IntList *l = (IntList *)list;
	reserveList(l, l->count + 1);
	char *slot = (char *)l->data + (size_t)l->count * 16;
	*(const void **)slot = head;
	*(const void **)(slot + 8) = cell;
	l->count++;
}

static void appendInt(void *list, int v)
{
	IntList *l = (IntList *)list;
	reserveList(l, l->count + 1);
	*(int *)((char *)l->data + (size_t)l->count * 16) = v;
	l->count++;
}

void TerminalCore::cloneGlyphPayload(void *dstAux, const void *srcPayload, int words)
{
	// FUN_007aa28a: appends `words` ushorts from the source payload to the
	// aux payload vector, growing to max(2*count, count+words) first
	int *hdr = (int *)dstAux;
	if (words < 1)
		return;
	int old = hdr[1];
	if (hdr[0] < old + words) {
		int cap = old * 2;
		if (cap < old + words)
			cap = old + words;
		resizeUshortVector(hdr, old, cap);
	}
	const unsigned short *src = (const unsigned short *)srcPayload;
	for (int i = hdr[1]; i < old + words; i++) {
		((unsigned short *)*(void **)(hdr + 2))[i] = *src++;
		hdr[1] = i + 1;
	}
}

void TerminalCore::buildBlankCell(unsigned char blank[16], void *sgrCtx)
{
	// FUN_007aa2e2 (same primitive): the blank cell is a copy of the
	// SGR context cell
	copyCell(blank, sgrCtx);
}

void TerminalCore::writeCell(void *dst, const unsigned char blank[16])
{
	// FUN_007aa2e2 (same primitive)
	copyCell(dst, blank);
}

void TerminalCore::growRowArrays(void *arrayHeader, int newLen, int minCap)
{
	// FUN_007aa3a6: Qt-style cell vector header {cap, count, data};
	// grows to minCap (0x20-byte cells, embedded storage for <2),
	// preserving min(newLen, count) cells (ownership-aware copy)
	struct CellArray { int cap; int count; unsigned char *data; };
	CellArray *arr = (CellArray *)arrayHeader;
	int preserve = arr->count < newLen ? arr->count : newLen;
	unsigned char *oldData = arr->data;
	if (arr->cap != minCap) {
		if (minCap < 2) {
			arr->data = (unsigned char *)(arr + 1);   // embedded storage
			arr->cap = 1;
		} else {
			arr->data = (unsigned char *)malloc((size_t)minCap << 5);
			arr->cap = minCap;
		}
		arr->count = 0;
		for (int i = 0; i < preserve; i++)
			copyCell(arr->data + (size_t)i * 0x20, oldData + (size_t)i * 0x20);
		// release old storage - cited
	}
	arr->count = preserve;
}

void *TerminalCore::cellAt(struct Row *row, int x)
{
	// FUN_007a3c1a
	return (char *)row->cells + (size_t)x * 0x20;
}

unsigned short *TerminalCore::attrHeadAt(struct Row *row, int x)
{
	// FUN_007a3c2a
	return (unsigned short *)row->attrArray + x;
}

void TerminalCore::setRowCell(struct Row *row, int x, const void *cell, void *aux)
{
	// FUN_007a5aac: x < length guard; writes the 2-byte glyph head into
	// the attribute array (2-byte stride) and copyCell's the full cell
	// body from aux into the cell slot; wide-char flags 0x80
	// (cell+10/0x10 non-zero) and 0x40 (cell+0x18 non-zero); marks the
	// row changed and invalidates the per-row render style bytes
	// (+0x50..+0x55)
	if (x >= rowLength(row))
		return;
	*attrHeadAt(row, x) = *(const unsigned short *)cell;
	copyCell(cellAt(row, x), aux);
	const unsigned short *c16 = (const unsigned short *)cell;
	if (c16[5] != 0 || *(const void *const *)((const char *)cell + 0x10) != nullptr)
		row->flags |= 0x80;
	if (*(const void *const *)((const char *)cell + 0x18) != nullptr)
		row->flags |= 0x40;
	setRowFlags(row, 1);
	memset((char *)row + 0x50, 0, 6);
}

void TerminalCore::notifyRectChanged(const void *rect, int dwlFlag)
{
	// FUN_007a4590: per row in rect[+4..+0xc]: sets row flag 0x40 when
	// dwlFlag, marks the row changed; then core markDirty(1)
	const int *r = (const int *)rect;
	for (int y = r[1]; y <= r[3]; y++) {
		struct Row *row = m_rows[y];
		if (dwlFlag)
			row->flags |= 0x40;
		setRowFlags(row, 1);
	}
	markDirty(1);
}

void *TerminalCore::collectRectCells(const void *rect, void *outList, int mode)
{
	// FUN_007a6ab0 (549 bytes, full): mode 2 takes stream-vs-rectangle
	// from flags byte1 bit0 (DECSACE); validates left>=0, top>=0,
	// left<=right, top<=bottom; origin mode (0x40) offsets the rect by
	// originTop/originLeft and restricts collection to the margin area
	// (inScrollRegion && columnInRange); bottom clamped to rowCount()-1;
	// reserve (h+2)*(w+2) slack. Rect mode collects only [left,right];
	// stream mode additionally trims just the first row's left overhang
	// and the last row's right overhang, keeping middle rows whole.
	const int *r = (const int *)rect;   // {left, top, right, bottom}
	int sel = mode;
	if (mode == 2)
		sel = (m_flags >> 8) & 1;   // core byte1 bit0 — DECSACE extent
	int left = r[0], top = r[1], right = r[2], bottom = r[3];
	if (top < 0 || left < 0 || left > right || top > bottom)
		return outList;
	if (m_flags & 0x40) {
		left += originLeft();
		top += originTop();
		right += originLeft();
		bottom += originTop();
	}
	if (bottom >= rowCount())
		bottom = rowCount() - 1;
	int width = sel ? (right - left) + 2 : m_columnCount;   // reserve slack
	reserveList(outList, (bottom - top + 2) * width);       // FUN_007aa5ca
	for (int y = top; y <= bottom; y++) {
		struct Row *row = m_rows[y];
		int len = rowLength(row);                            // FUN_007a3dfc
		for (int x = 0; x < len; x++) {
			if (m_flags & 0x40 &&
			    !(inScrollRegion(y) && columnInRange(x)))
				continue;
			if (x < left || x > right) {
				if (sel != 0)
					continue;
				if (y == top && x < left)
					continue;
				if (y == bottom && x > right) {
					if (x + 1 >= len)
						return outList;   // bottom row exhausted
					continue;
				}
				// stream, middle rows: collected even outside [left,right]
			}
			appendCellPair(outList, attrHeadAt(row, x), cellAt(row, x));
		}
	}
	return outList;
}

void *TerminalCore::parseAttrList(const void *params, void *out)
{
	// FUN_007a712b: QByteArray::split(';') — separator 0x3b verified in
	// disassembly at 0x7a714b — then toInt(base 10, &ok) per element
	// (ok-flag checked at 0x7a71b0); invalid entries are dropped, not
	// defaulted. Raw tier: src = QByteArray {ptr, size} (Qt 5 header is
	// {d, size} with data at d+16); out = QList<int>.
	const int *src = (const int *)params;
	const char *base = *(const char *const *)src;
	int size = src[2];
	for (int i = 0, start = 0; i <= size; i++) {
		if (i == size || base[i] == ';') {
			bool ok = false;
			int v = 0;
			if (i > start) {
				ok = true;
				int neg = 0;
				int p = start;
				if (base[p] == '-' || base[p] == '+') {
					neg = base[p] == '-';
					p++;
				}
				v = 0;
				for (; p < i; p++) {
					if (base[p] < '0' || base[p] > '9') {
						ok = false;
						break;
					}
					v = v * 10 + (base[p] - '0');
				}
				if (neg)
					v = -v;
			}
			if (ok)
				appendInt(out, v);   // qlist_uint_append — 0x7a71b0 path
			start = i + 1;
		}
	}
	return out;
}


unsigned int TerminalCore::cursorBlinkBit() const
{
	// FUN_007a44c0: styles 0..5 lookup in the 0x2b bitmask (0b101011 ->
	// styles 0,1,3,5 are the blinking ones); >=6 steady
	if (m_cursorStyle < 6)
		return (0x2b >> m_cursorStyle) & 1;
	return 0;
}


void TerminalCore::copyRect(int top, int left, int bottom, int right, long long packedDest)
{
	// FUN_007a7776 (DECCRA core, 882 bytes): validates all coords, offsets
	// by originTop/originLeft in origin mode (0x40), clamps bottom to
	// rowCount()-1, then per source row collects the attr heads (memcpy
	// span, FUN_007a5f3e) and cell bodies (copyCell list, FUN_007a5f86),
	// and pastes each pair into the destination row at destLeft
	// (FUN_007a5b8e semantics); markDirty(1) at the end.
	// packedDest: low 32 = dest column, high 32 = dest row.
	if (top < 0 || left < 0 || top > right || left > bottom)
		return;
	int destLeft = (int)packedDest;
	int destTop = (int)((unsigned long long)packedDest >> 32);
	if (destLeft < 0 || destTop < 0)
		return;
	if (m_flags & 0x40) {
		top += originTop();
		left += originLeft();
		right += originLeft();
		bottom += originTop();
		destLeft += originLeft();
		destTop += originTop();
	}
	if (bottom >= rowCount())
		bottom = rowCount() - 1;
	const int count = right - left + 1;
	const int rows = bottom - top + 1;

	// per source row: two {cap, count, data} spans — heads (2-byte attr
	// heads) and cells (0x20-byte bodies with owned aux clones); the
	// binary uses QListData spans here
	struct HeadSpan { int cap; int count; unsigned short *data; };
	struct CellSpan { int cap; int count; unsigned char *data; };
	HeadSpan *heads = (HeadSpan *)calloc((size_t)rows, sizeof(HeadSpan));
	CellSpan *cells = (CellSpan *)calloc((size_t)rows, sizeof(CellSpan));
	if (!heads || !cells) {
		free(heads);
		free(cells);
		return;
	}
	for (int i = 0; i < rows; i++) {
		struct Row *row = m_rows[top + i];
		resizeUshortVector((int *)&heads[i], count, count);   // FUN_007a5f3e
		memcpy(heads[i].data, (const unsigned short *)row->attrArray + left,
		       (size_t)count * 2);
		growRowArrays((int *)&cells[i], count, count);        // FUN_007a5f86
		for (int x = 0; x < count; x++)
			copyCell(cells[i].data + (size_t)x * 0x20, cellAt(row, left + x));
	}
	for (int i = 0; destTop + i < rowCount(); i++) {
		struct Row *row = m_rows[destTop + i];
		// FUN_007a5b8e: copyCell each body, memcpy the heads, flag the
		// wide/continuation bits, mark changed, zero +0x50..+0x57
		int n = rowLength(row) - destLeft;
		if (count < n)
			n = count;
		for (int x = 0; x < n; x++) {
			copyCell(cellAt(row, destLeft + x), cells[i].data + (size_t)x * 0x20);
			if (((const unsigned short *)(cells[i].data + (size_t)x * 0x20))[5] != 0 ||
			    *(const void *const *)(cells[i].data + (size_t)x * 0x20 + 0x10) != nullptr)
				row->flags |= 0x80;
			if (*(const void *const *)(cells[i].data + (size_t)x * 0x20 + 0x18) != nullptr)
				row->flags |= 0x40;
		}
		if (n > 0) {
			memcpy((unsigned short *)row->attrArray + destLeft, heads[i].data,
			       (size_t)n * 2);
			setRowFlags(row, 1);
			memset((char *)row + 0x50, 0, 8);
		}
	}
	markDirty(1);
	for (int i = 0; i < rows; i++) {
		resizeUshortVector((int *)&heads[i], 0, 0);   // QList dtor — cited
		growRowArrays((int *)&cells[i], 0, 0);        // QList dtor — cited
	}
	free(heads);
	free(cells);
}

void TerminalCore::rowHook(struct Row *row, int arg)
{
	// FUN_007a3dde: flags byte1 bit0 <- arg (with the change bit1 set)
	// when the bit actually differs
	if ((row->byte1 & 1) != (arg & 1))
		row->byte1 = (unsigned char)((row->byte1 & 0xfe) | (arg & 1) | 2);
}

// ---------------------------------------------------------------------------
// Charset manager (batch: the +0x8 manager object's slot table)
// ---------------------------------------------------------------------------

int TerminalCore::charsetSlot(int slot) const
{
	// FUN_00801a46: slots[0..3] at manager+slot*4; >=4 yields 0
	if (slot < 0 || slot >= 4)
		return 0;
	return m_charsetSlots[slot];
}

void TerminalCore::setCharsetSlot(int slot, int tableId)
{
	// FUN_00803470: slot<4; the G0 slot (0) is rejected when the table
	// id fails the guard FUN_00802c80 (reserved/default id check)
	if (slot < 0 || slot >= 4)
		return;
	if (slot == 0 && !slot0Allowed(tableId))   // FUN_00802c80 — cited
		return;
	m_charsetSlots[slot] = tableId;
}

bool TerminalCore::charsetDisabled(int tableId) const
{
	// FUN_008034a4: registry row (+0x11 flag) via the id-slot table
	// (FUN_00802bda); rebuilt against the static registry — see the
	// identical Screen::charsetDisabled
	const int r = charsetRegistryRow(tableId);
	return r < 0 ? false : charsetRegistry[r].disabled != 0;
}

// registry lookup (FUN_00802a26): walks the 0x18-stride registry table
// comparing entry names (memcmp over the QByteArray payload) and the
// set flag (94/96); returns the table id on match, 0 on miss.
// user-preferred install (FUN_00801a3e): manager+0x10 = tableId.

bool TerminalCore::slot0Allowed(int tableId) const
{
	// FUN_00802c96: the config root's id slot (+0x10, the
	// user-preferred set) must read 1, or the table is 6 (default
	// supplemental set)
	return m_userPreferredSet == 1 || tableId == 6;
}

const void *TerminalCore::charsetConfigRoot() const
{
	// FUN_00802bda: id→entry slot-table accessor over the lazily grown
	// container; the rebuild resolves rows through charsetRegistryRow
	// — cited
	return nullptr;
}

// ---------------------------------------------------------------------------
// Phase 1d cited helpers (resize path)
// ---------------------------------------------------------------------------





bool TerminalCore::rowHasContent(Row *row) const
{
	// FUN_007a4a06: width = rowUsedWidth(row, 0); the dirty flag (bit0)
	// trusts the count directly, otherwise clamp to originRight()+1
	int n = rowUsedWidth(row, 0);
	if (!(row->flags & 1)) {
		const int w = originRight();
		if (w + 1 < n)
			n = w + 1;
	}
	return n > 0;
}

int TerminalCore::rowUsedWidth(Row *row, int withStyle) const
{
	// FUN_007a41d6 (323B, SSE tail scan): index of the last non-zero
	// 16-bit head + 1; withStyle && flags&0x40 additionally walks the
	// 0x20-byte payload cells downward; flags&8 drops a trailing zero —
	// payload walk cited — wave-2. The corpus count lives at row+0x3c
	// with the head array at +0x40.
	(void)withStyle;
	if (!row || !row->attrArray)
		return 0;
	int i = row->length - 1;
	unsigned short *heads = (unsigned short *)row->attrArray;
	while (i >= 0 && heads[i] == 0)
		--i;
	return i + 1;
}

// ---------------------------------------------------------------------------
// Phase 2a: state copy (FUN_007aa2e2)
// ---------------------------------------------------------------------------

void TerminalCore::copyState(void **dst, void **src)
{
	// FUN_007aa2e2 (172B): copies the state record fields (+0 u64,
	// +4 u32, +8/+0xa u16, +0x18 u64); dst's heap node at +0x10 is
	// released (data buffer free, then the 0x18-byte node deleted) and
	// replaced by a clone of src's node (fresh refcount 1, payload via
	// FUN_007aa28a) — the node payload clone body is cited
	unsigned char *d = (unsigned char *)dst;
	const unsigned char *s = (const unsigned char *)src;
	*(unsigned long long *)(d + 0) = *(const unsigned long long *)(s + 0);
	*(unsigned int *)(d + 4) = *(const unsigned int *)(s + 4);
	*(unsigned short *)(d + 8) = *(const unsigned short *)(s + 8);
	*(unsigned short *)(d + 0xa) = *(const unsigned short *)(s + 0xa);
	*(unsigned long long *)(d + 0x18) = *(const unsigned long long *)(s + 0x18);
	void *node = *(void **)(d + 0x10);
	if (node) {
		void *buf = *(void **)((char *)node + 8);
		if (buf != (char *)node + 0x10)
			free(buf);
		::operator delete(node);
	}
	// clone of src's +0x10 node (FUN_007aa28a) — cited
	*(void **)(d + 0x10) = nullptr;
}

void TerminalCore::resetCharsetSlots()
{
	// FUN_00802baa (18B): slots {2,2,2,2} as two packed qwords
	// (0x200000002 twice) — matches the keymapResetModifier packed form
	m_charsetSlots[0] = m_charsetSlots[1] = 2;
	m_charsetSlots[2] = m_charsetSlots[3] = 2;
}

// ---------------------------------------------------------------------------
// Phase 2: row ctor + tabstop re-arm + resizeCore (FUN_007a604a family)
// ---------------------------------------------------------------------------

TerminalCore::TerminalCore()
{
	// 全成员显式清零(原版由 0x7e69b8 构造族保证;漏初始化会让
	// m_flags/滚动区/SGR 等读堆垃圾,行为非确定)
	m_flags = 0;
	m_rowCount = 0;
	m_rowCapacity = 0;
	m_rows = nullptr;
	m_cursorY = 0;
	m_cursorX = 0;
	m_columnCount = 0;
	m_tabstops.payload = nullptr;
	m_savedCursorY = 0;
	m_savedCursorX = 0;
	m_saveByte28 = 0;
	m_saveByte29 = 0;
	m_saved2 = 0;
	for (int i = 0; i < 4; ++i)
		m_savedCharsets[i] = 0;
	m_blankRowTemplate = nullptr;
	m_blankTemplateSgr = 0;
	m_charsetSaved = nullptr;
	m_sgrState = nullptr;
	m_flags2 = 0;
	m_sgrBits = 0;
	m_workRow = nullptr;
	m_userPreferredSet = 0;
	for (int i = 0; i < 4; ++i)
		m_charsetSlots[i] = 0;
	m_scrollRegionTop = 0;
	m_scrollRegionBottom = 0;
	m_leftMargin = 0;
	m_rightMargin = 0;
	m_50 = nullptr;
	m_58 = 0;
	m_5c = nullptr;
	m_66 = 0;
}

void TerminalCore::makeRow(struct Row *row, int cols)
{
	// FUN_007a5670 (291B): flags 0, length = cols, cells allocated
	// (inline spare at +0x18 then heap when cols > 1), each 0x20-byte
	// cell zeroed with byte0 = 1; heads likewise with the count at
	// +0x38. The rebuild allocates both arrays plainly.
	memset(row, 0, 0x58);
	row->length = cols;
	row->cells = ::operator new((size_t)cols * 0x20);
	memset(row->cells, 0, (size_t)cols * 0x20);   // 全零:aux 槽 (+0x10) 必须为 null
	for (int i = 0; i < cols; ++i)
		((unsigned char *)row->cells)[i * 0x20] = 1;
	row->attrArray = ::operator new((size_t)cols * 2);
	memset(row->attrArray, 0, (size_t)cols * 2);
}

void Tabstops::resizeDefault(int cols)
{
	// FUN_007a604a tail: bitmap resize to cols, then bit set when
	// (col & 7) == 0, else cleared — the every-8th default tabstops
	if (payload)
		delete[] payload;
	payload = new unsigned char[(cols + 7) / 8 + 1]();
	// byte 0 is the meta byte in the corpus layout; keep column bits
	// from byte 1 (per Tabstops::test's (column >> 3) + 1 convention)
	for (int c = 0; c < cols; ++c) {
		const int byte = (c >> 3) + 1;
		if (c % 8 == 0)
			payload[byte] |= (unsigned char)(1 << (c & 7));
		else
			payload[byte] &= (unsigned char)~(1 << (c & 7));
	}
}

void TerminalCore::resizeCore(int rows, int cols)
{
	// FUN_007a604a (967B): rows>=2/cols>=8; dims land at +0xe0/+0xe4;
	// per existing row: unchanged length is a no-op, otherwise the
	// reflow-off path marks the row dirty (bit0) when the old width
	// overhangs both rowLength and rowUsedWidth(+1), else clips via
	// setRowLength; the row vector grows with new Rows (FUN_007a5670)
	// under doubling capacity or shrinks with the 0x58-row teardown
	// (attr free + FUN_007aa108 payload dtor); finally the tabstop
	// bitmap resizes with the every-8th default.
	if (rows < 2 || cols < 8)
		return;
	const int oldCols = m_columnCount;
	const int oldCount = m_rowCount;
	m_columnCount = cols;         // +0xe4
	// the corpus writes the row target to +0xe0 (a dims field distinct
	// from the live count +0x74); keep the live count authoritative and
	// grow the vector below
	for (int i = 0; i < oldCount && m_rows[i]; ++i) {
		struct Row *r = m_rows[i];
		const int len = rowLength(r);
		if (len == cols)
			continue;
		if (oldCols <= len && oldCols < rowUsedWidth(r, 1))
			r->flags |= 1;
		else
			setRowLength(r, cols);
	}
	// vector grow (capacity doubling per the corpus +0x70/+0x74/+0x78
	// block) or shrink (extra rows torn down: attr free + payload dtor
	// + 0x58 delete)
	if (m_rowCapacity < rows) {
		int cap = m_rowCapacity < 2 ? 2 : m_rowCapacity;
		while (cap < rows)
			cap *= 2;
		struct Row **grown = (struct Row **)malloc((size_t)cap * sizeof(struct Row *));
		if (m_rows && m_rowCount > 0)
			memcpy(grown, m_rows, (size_t)m_rowCount * sizeof(struct Row *));
		for (int i = m_rowCount; i < cap; ++i)
			grown[i] = nullptr;
		free(m_rows);
		m_rows = grown;
		m_rowCapacity = cap;
	}
	for (int i = 0; i < rows; ++i) {
		if (!m_rows[i]) {
			struct Row *r = (struct Row *)::operator new(0x58);
			makeRow(r, cols);
			m_rows[i] = r;
		}
	}
	for (int i = rows; i < m_rowCount; ++i) {
		struct Row *r = m_rows[i];
		if (r) {
			free(r->attrArray);   // +0x40 buffer (corpus frees +0x40)
			::operator delete(r->cells);
			::operator delete(r);
		}
		m_rows[i] = nullptr;
	}
	m_rowCount = rows;
	// fresh-buffer default: the scroll region covers the full screen
	// (the original core ctor family seeds +0xd4 = rows-1; DECSLPP/DECSTBM
	// users overwrite it later)
	if (m_scrollRegionBottom == 0)
		m_scrollRegionBottom = rows - 1;
	m_tabstops.resizeDefault(cols);
}
