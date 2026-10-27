#include "SuperCommander.h"
#include "Screen.h"

// 第一/二批转写:光标/擦除/滚动族 + DEC 模式/字符集/SGR/插入删除族(221 个真实现体)。
// 三层洋葱:this -> m_screen(+0x80, 0x7e 层) -> TerminalCore(0x7a 层)。
// 每体注明 moc 索引与实现地址;其余槽为后续批次占位。
// 信号 5 个由 moc 生成不定义。phase-1 参考还原,不编译。

SuperCommander::SuperCommander(QObject *parent)
	: QObject(parent), m_screen(nullptr)
{
}

void SuperCommander::vt52Mode()
{
	// moc[256] -> 0x7e5a02
	m_screen->isVt52Mode();
	// 取值函数(+0x124),槽调用丢弃返回值
}

void SuperCommander::vt52Identify()
{
	// moc[255] -> 0x7edc22
	m_screen->vt52Identify();
	// 应答 ESC / Z
}

void SuperCommander::vt52EnterGraphicsMode()
{
	// moc[253] -> 0x7e5a90
	m_screen->vt52EnterGraphicsMode();
}

void SuperCommander::vt52ExitGraphicsMode()
{
	// moc[254] -> 0x7e5ab0
	m_screen->vt52ExitGraphicsMode();
}

void SuperCommander::vt52MoveCursor(int column, int line)
{
	// moc[257] -> 0x7e4f38
	m_screen->cursorMoveRaw(column - 32, line - 32);
	// 适配器 0x7cd9b6:FUN_007e4f38(screen, column-0x20, line-0x20) 直通 moveCursorRaw
}

void SuperCommander::moveCursor()
{
	// moc[73] -> 0x7e4fdc
	m_screen->moveCursor(m_screen->originTop(), m_screen->originLeft());
	// 适配器 0x7cbeda,缺省参 1,1 -> 原点 home
}

void SuperCommander::moveCursor(int position)
{
	// moc[72] -> 0x7e4fdc
	m_screen->moveCursor(m_screen->originTop(), m_screen->originLeft() - 1 + position);
	// 适配器 0x7cbeda 为双参;单参槽取列位,参数序待动态验证
}

void SuperCommander::moveCursor(int column, int line)
{
	// moc[71] -> 0x7e4fdc
	if (line < 1)
		line = 1;
	if (column < 1)
		column = 1;
	m_screen->moveCursor(m_screen->originTop() - 1 + line, m_screen->originLeft() - 1 + column);
	// 适配器 0x7cbeda:第一参进 Y,第二参进 X(originTop/originLeft 为原点基)
}

void SuperCommander::moveCursorColumn()
{
	// moc[77] -> 0x7e4fdc
	m_screen->moveCursor(m_screen->currentLine(), m_screen->originLeft());
	// 适配器 0x7cbe1e,缺省参 1 -> originLeft
}

void SuperCommander::moveCursorColumn(int column)
{
	// moc[76] -> 0x7e4fdc
	if (column < 0)
		return;
	if (column == 0)
		column = 1;
	m_screen->moveCursor(m_screen->currentLine(), m_screen->originLeft() - 1 + column);
}

void SuperCommander::moveCursorColumnRelative()
{
	// moc[81] -> 0x7e4fdc
	m_screen->moveCursor(m_screen->currentLine(), m_screen->currentColumn() + 1);
	// 适配器 0x7cb282,缺省参 1
}

void SuperCommander::moveCursorColumnRelative(int columns)
{
	// moc[80] -> 0x7e4fdc
	if (columns < 0)
		return;
	if (columns == 0)
		columns = 1;
	m_screen->moveCursor(m_screen->currentLine(), m_screen->currentColumn() + columns);
}

void SuperCommander::moveCursorColumnBackward()
{
	// moc[79] -> 0x7e4fdc
	m_screen->moveCursor(m_screen->currentLine(), m_screen->currentColumn() - 1);
	// 适配器 0x7cb1f6,缺省参 1
}

void SuperCommander::moveCursorColumnBackward(int columns)
{
	// moc[78] -> 0x7e4fdc
	if (columns < 0)
		return;
	if (columns == 0)
		columns = 1;
	m_screen->moveCursor(m_screen->currentLine(), m_screen->currentColumn() - columns);
}

void SuperCommander::moveCursorForward(int columns)
{
	// moc[84] -> 0x7e484a
	if (columns < 0)
		return;
	if (columns == 0)
		columns = 1;
	m_screen->moveCursorForward(columns);
}

void SuperCommander::moveCursorBackward()
{
	// moc[75] -> 0x7e4832
	m_screen->moveCursorBackward(1);
	// 适配器带守卫,缺省参 1
}

void SuperCommander::moveCursorBackward(int columns)
{
	// moc[74] -> 0x7e4832
	if (columns < 0)
		return;
	if (columns == 0)
		columns = 1;
	m_screen->moveCursorBackward(columns);
}

void SuperCommander::moveCursorUp()
{
	// moc[101] -> 0x7e4856
	m_screen->moveCursorUp(1);
	// 适配器带守卫,缺省参 1
}

void SuperCommander::moveCursorUp(int lines)
{
	// moc[100] -> 0x7e4856
	if (lines < 0)
		return;
	if (lines == 0)
		lines = 1;
	m_screen->moveCursorUp(lines);
}

void SuperCommander::moveCursorDown()
{
	// moc[83] -> 0x7e483e
	m_screen->moveCursorDown(1);
	// 适配器带守卫,缺省参 1
}

void SuperCommander::moveCursorDown(int lines)
{
	// moc[82] -> 0x7e483e
	if (lines < 0)
		return;
	if (lines == 0)
		lines = 1;
	m_screen->moveCursorDown(lines);
}

void SuperCommander::moveCursorLine()
{
	// moc[87] -> 0x7e4fdc
	m_screen->moveCursor(m_screen->originTop(), m_screen->currentColumn());
	// 适配器 0x7cbf28,缺省参 1 -> originTop
}

void SuperCommander::moveCursorLine(int line)
{
	// moc[86] -> 0x7e4fdc
	if (line < 0)
		return;
	if (line == 0)
		line = 1;
	m_screen->moveCursor(m_screen->originTop() - 1 + line, m_screen->currentColumn());
}

void SuperCommander::moveCursorLineRelative()
{
	// moc[91] -> 0x7e4fdc
	m_screen->moveCursor(m_screen->currentLine() + 1, m_screen->currentColumn());
	// 适配器 0x7cb3b0,缺省参 1
}

void SuperCommander::moveCursorLineRelative(int lines)
{
	// moc[90] -> 0x7e4fdc
	if (lines < 0)
		return;
	if (lines == 0)
		lines = 1;
	m_screen->moveCursor(m_screen->currentLine() + lines, m_screen->currentColumn());
}

void SuperCommander::moveCursorLineBackward()
{
	// moc[89] -> 0x7e4fdc
	m_screen->moveCursor(m_screen->currentLine() - 1, m_screen->currentColumn());
	// 适配器 0x7cb30c,缺省参 1
}

void SuperCommander::moveCursorLineBackward(int lines)
{
	// moc[88] -> 0x7e4fdc
	if (lines < 0)
		return;
	if (lines == 0)
		lines = 1;
	m_screen->moveCursor(m_screen->currentLine() - lines, m_screen->currentColumn());
}

void SuperCommander::moveCursorNextLine()
{
	// moc[93] -> 0x7e4fdc
	m_screen->moveCursor(m_screen->currentLine() + 1, 0);
	// 适配器 0x7cb454,缺省参 1
}

void SuperCommander::moveCursorNextLine(int lines)
{
	// moc[92] -> 0x7e4fdc
	if (lines < 0)
		return;
	if (lines == 0)
		lines = 1;
	m_screen->moveCursor(m_screen->currentLine() + lines, 0);
}

void SuperCommander::moveCursorPrecedingLine()
{
	// moc[97] -> 0x7e4fdc
	m_screen->moveCursor(m_screen->currentLine() - 1, 0);
	// 适配器 0x7cb572,缺省参 1
}

void SuperCommander::moveCursorPrecedingLine(int lines)
{
	// moc[96] -> 0x7e4fdc
	if (lines < 0)
		return;
	if (lines == 0)
		lines = 1;
	m_screen->moveCursor(m_screen->currentLine() - lines, 0);
}

void SuperCommander::moveCursorNextTabstop()
{
	// moc[95] -> 0x7e4fdc
	m_screen->moveCursor(m_screen->currentLine(), m_screen->nextTabstop(m_screen->currentColumn(), 1));
	// 适配器 0x7cb4dc,缺省参 1
}

void SuperCommander::moveCursorNextTabstop(int count)
{
	// moc[94] -> 0x7e4fdc
	if (count < 0)
		return;
	if (count == 0)
		count = 1;
	m_screen->moveCursor(m_screen->currentLine(), m_screen->nextTabstop(m_screen->currentColumn(), count));
}

void SuperCommander::moveCursorPrecedingTabstop()
{
	// moc[99] -> 0x7e4fdc
	m_screen->moveCursor(m_screen->currentLine(), m_screen->prevTabstop(m_screen->currentColumn(), 1));
	// 适配器 0x7cb5fc,缺省参 1
}

void SuperCommander::moveCursorPrecedingTabstop(int count)
{
	// moc[98] -> 0x7e4fdc
	if (count < 0)
		return;
	if (count == 0)
		count = 1;
	m_screen->moveCursor(m_screen->currentLine(), m_screen->prevTabstop(m_screen->currentColumn(), count));
}

void SuperCommander::backspace()
{
	// moc[10] -> 0x7e4f44
	m_screen->backspace();
	// 逆向回绕逻辑在 Screen::backspace(0x7e4f44)
}

void SuperCommander::carriageReturn()
{
	// moc[13] -> 0x7e4fc8
	m_screen->carriageReturn();
}

void SuperCommander::lineFeed()
{
	// moc[61] -> 0x7e55fc
	m_screen->lineFeed();
	// 三槽同指 0x7e55fc
}

void SuperCommander::formFeed()
{
	// moc[50] -> 0x7e55fc
	m_screen->lineFeed();
	// 三槽同指 0x7e55fc
}

void SuperCommander::verticalTab()
{
	// moc[252] -> 0x7e55fc
	m_screen->lineFeed();
	// 三槽同指 0x7e55fc
}

void SuperCommander::horizontalTab()
{
	// moc[54] -> 0x7e5d7c
	m_screen->horizontalTab();
}

void SuperCommander::bell()
{
	// moc[11] -> 0x4bc0d0
	// 未转写(后续批次)
}

void SuperCommander::repeatCharacter()
{
	// moc[127] -> 0x7e7cf6
	m_screen->repeatCharacter(1);
}

void SuperCommander::repeatCharacter(int count)
{
	// moc[126] -> 0x7e7cf6
	m_screen->repeatCharacter(count);
}

void SuperCommander::insertCharacter()
{
	// moc[56] -> 0x7e3ace
	m_screen->insertCharacter(1);
	// 缺省参 1,守卫在实现内
}

void SuperCommander::insertCharacter(int count)
{
	// moc[55] -> 0x7e3ace
	m_screen->insertCharacter(count);
	// 守卫在 core 实现内
}

void SuperCommander::deleteCharacter()
{
	// moc[21] -> 0x7e3784
	m_screen->deleteCharacter(1);
	// 缺省参 1,守卫在实现内
}

void SuperCommander::deleteCharacter(int count)
{
	// moc[20]
	m_screen->deleteCharacter(count);
	// 守卫在 core 实现内
}

void SuperCommander::eraseCharacter()
{
	// moc[36] -> 0x7e385a
	m_screen->eraseCharacter(1);
	// 适配器 0x7c8c3c,缺省参 1
}

void SuperCommander::eraseCharacter(int count)
{
	// moc[35] -> 0x7e385a
	m_screen->eraseCharacter(count);
	// 守卫在实现内(FUN_007e385a)
}

void SuperCommander::insertLine()
{
	// moc[60] -> 0x7e3ae6
	m_screen->insertLine(1);
	// 缺省参 1,守卫在实现内
}

void SuperCommander::insertLine(int count)
{
	// moc[59] -> 0x7e3ae6
	m_screen->insertLine(count);
	// 守卫在 core 实现内
}

void SuperCommander::deleteLine()
{
	// moc[25] -> 0x7e379c
	m_screen->deleteLine(1);
	// 缺省参 1,守卫在实现内
}

void SuperCommander::deleteLine(int count)
{
	// moc[24] -> 0x7e379c
	m_screen->deleteLine(count);
	// 守卫在 core 实现内
}

void SuperCommander::insertColumn()
{
	// moc[58] -> 0x7e3ada
	m_screen->insertColumn(1);
	// 缺省参 1,守卫在实现内
}

void SuperCommander::insertColumn(int count)
{
	// moc[57] -> 0x7e3ada
	m_screen->insertColumn(count);
	// 守卫在 core 实现内
}

void SuperCommander::deleteColumn()
{
	// moc[23] -> 0x7e3790
	m_screen->deleteColumn(1);
	// 缺省参 1,守卫在实现内
}

void SuperCommander::deleteColumn(int count)
{
	// moc[22] -> 0x7e3790
	m_screen->deleteColumn(count);
	// 守卫在 core 实现内
}

void SuperCommander::eraseLine()
{
	// moc[38] -> 0x7e4ba2
	m_screen->eraseLine(m_screen->currentLine(), 0, false);
	// 适配器 0x7cb106:T3,行参取当前行
}

void SuperCommander::eraseLine(int mode)
{
	// moc[37] -> 0x7e4ba2
	m_screen->eraseLine(m_screen->currentLine(), mode, false);
}

void SuperCommander::eraseScreen()
{
	// moc[41] -> 0x7e606a
	m_screen->eraseScreen(0, false);
	// 适配器 0x7c8c68,缺省参 0
}

void SuperCommander::eraseScreen(int mode)
{
	// moc[40] -> 0x7e606a
	m_screen->eraseScreen(mode, false);
}

void SuperCommander::eraseSelectiveLine()
{
	// moc[43] -> 0x7e4ba2
	m_screen->eraseLine(m_screen->currentLine(), 0, true);
	// 适配器 0x7cb17c:同上,DECSED 选择擦除
}

void SuperCommander::eraseSelectiveLine(int mode)
{
	// moc[42] -> 0x7e4ba2
	m_screen->eraseLine(m_screen->currentLine(), mode, true);
}

void SuperCommander::eraseSelectiveScreen()
{
	// moc[45] -> 0x7e606a
	m_screen->eraseScreen(0, true);
	// 适配器 0x7c8c76
}

void SuperCommander::eraseSelectiveScreen(int mode)
{
	// moc[44] -> 0x7e606a
	m_screen->eraseScreen(mode, true);
}

void SuperCommander::eraseRectangularArea(const QString &area)
{
	// moc[39] -> 0x7eb1c4
	m_screen->eraseRectangularArea(area, false);
	// 补录
}

void SuperCommander::selectiveEraseRectangularArea(const QString &area)
{
	// moc[188] -> 0x7eb1c4
	m_screen->eraseRectangularArea(area, true);
	// 适配器 0x7c8c56:同 0x7c8c48,selective=1
}

void SuperCommander::scrollUp()
{
	// moc[175] -> 0x7e5546
	m_screen->scroll(1, false, false);
	// 适配器 0x7c8db6(n,0,0),缺省参 1
}

void SuperCommander::scrollUp(int lines)
{
	// moc[174] -> 0x7e5546
	if (lines < 0)
		return;
	if (lines < 1)
		lines = 1;
	m_screen->scroll(lines, false, false);
}

void SuperCommander::scrollDown()
{
	// moc[168] -> 0x7e5546
	m_screen->scroll(1, true, false);
	// 适配器 0x7c8d96(n,1,0)
}

void SuperCommander::scrollDown(int lines)
{
	// moc[167] -> 0x7e5546
	if (lines < 0)
		return;
	if (lines < 1)
		lines = 1;
	m_screen->scroll(lines, true, false);
}

void SuperCommander::scrollLeft()
{
	// moc[170] -> 0x7e4d3c
	m_screen->scrollHorizontal(1);
	// 适配器 0x7c8dd4 正参
}

void SuperCommander::scrollLeft(int columns)
{
	// moc[169] -> 0x7e4d3c
	if (columns < 1)
		return;
	m_screen->scrollHorizontal(columns);
}

void SuperCommander::scrollRight()
{
	// moc[173] -> 0x7e4d3c
	m_screen->scrollHorizontal(-1);
	// 适配器 0x7c8e06 传 -n
}

void SuperCommander::scrollRight(int columns)
{
	// moc[172] -> 0x7e4d3c
	if (columns < 1)
		return;
	m_screen->scrollHorizontal(-columns);
}

void SuperCommander::scrollCursorUp()
{
	// moc[166] -> 0x7e563e
	m_screen->indexUp();
	// RI,适配器 0x7cc4a0
}

void SuperCommander::scrollCursorDown()
{
	// moc[165] -> 0x7e55b6
	m_screen->indexDown();
	// IND,适配器 0x7cc47e
}

void SuperCommander::scrollNextLine()
{
	// moc[171] -> 0x7e562c
	m_screen->nextLine();
	// NEL,适配器 0x7cc4c2
}

void SuperCommander::nextPage()
{
	// moc[109] -> 0x7ef16a
	m_screen->movePage(m_screen->currentPage() + 1, true);
	// 适配器 0x7cc0ce:n<1 取 1,回原点
}

void SuperCommander::nextPage(int pages)
{
	// moc[108] -> 0x7ef16a
	if (pages < 0)
		return;
	if (pages < 1)
		pages = 1;
	m_screen->movePage(m_screen->currentPage() + pages, true);
}

void SuperCommander::precedingPage()
{
	// moc[124] -> 0x7ef16a
	m_screen->movePage(m_screen->currentPage() - 1, true);
	// 适配器 0x7cc112:n<1 取 1,回原点
}

void SuperCommander::precedingPage(int pages)
{
	// moc[123] -> 0x7ef16a
	if (pages < 0)
		return;
	if (pages < 1)
		pages = 1;
	m_screen->movePage(m_screen->currentPage() - pages, true);
}

void SuperCommander::page()
{
	// moc[121] -> 0x7e48f8
	m_screen->currentPage();
	// 取值函数(0x7e48f8),槽调用丢弃返回值
}

void SuperCommander::pages()
{
	// moc[122] -> 0x7e4900
	// 取值函数(0x7e4900 总页数),槽调用丢弃返回值
}

void SuperCommander::forwardIndex()
{
	// moc[51] -> 0x7e4d82
	m_screen->forwardIndex();
}

void SuperCommander::backIndex()
{
	// moc[9] -> 0x7e4d48
	m_screen->backIndex();
}

void SuperCommander::marginTop()
{
	// moc[67] -> 0x7e4456
	m_screen->marginTop();
	// 实现为取值函数,槽调用丢弃返回值(适配器纯转发)
}

void SuperCommander::marginBottom()
{
	// moc[64] -> 0x7e4426
	m_screen->marginBottom();
	// 实现为取值函数,槽调用丢弃返回值(适配器纯转发)
}

void SuperCommander::marginLeft()
{
	// moc[65] -> 0x7e443e
	m_screen->marginLeft();
	// 实现为取值函数,槽调用丢弃返回值(适配器纯转发)
}

void SuperCommander::marginRight()
{
	// moc[66] -> 0x7e444a
	m_screen->marginRight();
	// 实现为取值函数,槽调用丢弃返回值(适配器纯转发)
}

void SuperCommander::setTopBottomMargins()
{
	// moc[224] -> 0x7e5fa6
	m_screen->setTopBottomMargins(-1, -1);
}

void SuperCommander::setTopBottomMargins(int top)
{
	// moc[223] -> 0x7e5fa6
	m_screen->setTopBottomMargins(top, -1);
}

void SuperCommander::setTopBottomMargins(int top, int bottom)
{
	// moc[222] -> 0x7e5fa6
	m_screen->setTopBottomMargins(top, bottom);
}

void SuperCommander::setLeftRightMargins()
{
	// moc[215] -> 0x7e5bd4
	m_screen->setLeftRightMargins(-1, -1);
}

void SuperCommander::setLeftRightMargins(int left)
{
	// moc[214] -> 0x7e5bd4
	m_screen->setLeftRightMargins(left, -1);
}

void SuperCommander::setLeftRightMargins(int left, int right)
{
	// moc[213] -> 0x7e5bd4
	m_screen->setLeftRightMargins(left, right);
}

void SuperCommander::setHorizontalTabstop()
{
	// moc[210] -> 0x7e52fc
	m_screen->setTabstop(-1, true);
	// -1 -> 当前列(HTS)
}

void SuperCommander::setHorizontalTabstop(int column)
{
	// moc[209] -> 0x7e52fc
	m_screen->setTabstop(column, true);
}

void SuperCommander::clearTabstop()
{
	// moc[17] -> 0x7e5df0
	m_screen->clearTabstop(0);
	// TBC 0:清除当前列制表位
}

void SuperCommander::clearTabstop(int column)
{
	// moc[16] -> 0x7e5df0
	m_screen->clearTabstop(column);
}

void SuperCommander::saveCursor()
{
	// moc[163] -> 0x7e4aa2
	m_screen->saveCursor();
	// DECSC,适配器 0x7cc45c
}

void SuperCommander::restoreCursor()
{
	// moc[157] -> 0x7f6426
	m_screen->restoreCursor();
	// DECRC,适配器 0x7cc40a
}

void SuperCommander::setMode()
{
	// moc[221] -> 0x7edce6
	m_screen->setMode(QString(), true);
}

void SuperCommander::setMode(int mode)
{
	// moc[220] -> 0x7edce6
	m_screen->setMode(QString::number(mode), true);
}

void SuperCommander::resetMode()
{
	m_screen->setMode(QString(), false);
}

void SuperCommander::resetMode(int mode)
{
	// moc[153] -> 0x7edce6
	m_screen->setMode(QString::number(mode), false);
}

void SuperCommander::requestMode(int mode)
{
	// moc[141] -> 0x7f17c2
	m_screen->requestMode(mode);
	// DECRQM;未知模式上报不支持
}

void SuperCommander::setDecMode()
{
	// moc[207] -> 0x7f5d2e
	m_screen->setDecMode(QString(), true);
}

void SuperCommander::setDecMode(int mode)
{
	// moc[206] -> 0x7f5d2e
	m_screen->setDecMode(QString::number(mode), true);
	// 适配器 0x7c8d4c:FUN_007f5d2e(screen, mode, 1)
}

void SuperCommander::resetDecMode(int mode)
{
	// moc[149] -> 0x7f5d2e
	m_screen->setDecMode(QString::number(mode), false);
	// 适配器 0x7c8d3e
}

void SuperCommander::saveDecMode(int mode)
{
	// moc[164] -> 0x7f427a
	m_screen->saveDecMode(QString::number(mode));
	// 适配器 0x7c8d8a
}

void SuperCommander::restoreDecMode(int mode)
{
	// moc[158] -> 0x7f64a6
	m_screen->restoreDecMode(QString::number(mode));
	// 适配器 0x7c8d7e
}

void SuperCommander::requestDecMode(int mode)
{
	// moc[136] -> 0x7f13a0
	// 未转写(后续批次)
}

void SuperCommander::selectCharacterAttribute()
{
	// moc[185] -> 0x7eebd4
	m_screen->selectCharacterAttribute(0);
}

void SuperCommander::selectCharacterAttribute(int attribute)
{
	// moc[184] -> 0x7eebd4
	m_screen->selectCharacterAttribute(attribute);
}

void SuperCommander::selectGraphicRendition()
{
	// moc[187] -> 0x7ef95c
	m_screen->selectGraphicRendition(QString());
}

void SuperCommander::selectGraphicRendition(int rendition)
{
	// moc[186] -> 0x7ef95c
	m_screen->selectGraphicRendition(QString::number(rendition));
	// 适配器 0x7c8de6 -> 0x7ef95c(SGR 位域状态机)
}

void SuperCommander::selectAttributeChangeExtent()
{
	// moc[183] -> 0x7e4e74
	m_screen->selectAttributeChangeExtent();
}

void SuperCommander::selectAttributeChangeExtent(int extent)
{
	// moc[182] -> 0x7e4e74
	m_screen->selectAttributeChangeExtent();
	// 实现忽略 extent 参(适配器 0x7cc530)
}

void SuperCommander::reverseScreen()
{
	// moc[162] -> 0x7e4a94
	m_screen->isReverseScreen();
	// 取值函数(DECSCNM 标志)
}

void SuperCommander::changeAttributesInRectangularArea(const QString &area)
{
	m_screen->changeAttributesInRectangularArea(area);
}

void SuperCommander::reverseAttributesInRectangularArea(const QString &area)
{
	m_screen->reverseAttributesInRectangularArea(area);
}

void SuperCommander::copyRectangularArea(const QString &area)
{
	m_screen->copyRectangularArea(area);
}

void SuperCommander::fillRectangularArea(const QString &fill)
{
	// moc[49] -> 0x7eb20a
	m_screen->fillRectangularArea(fill);
}

void SuperCommander::fillRectangularArea(const QString &fill, const QString &area)
{
	// moc[48] -> 0x7eb20a
	m_screen->fillRectangularArea(fill);
	// area 参由实现内解析,适配器只传 fill
}

void SuperCommander::eraseRectangularArea(const QString &area, int mode)
{
	// 未转写(后续批次)
}

void SuperCommander::requestChecksumOfRectangularArea(const QString &area, int pid)
{
	// moc[135] -> 0x7eced6
	// 未转写(后续批次)
}

void SuperCommander::select94CharacterSet(int count, int graphic)
{
	// moc[178] -> 0x7e4dbc
	m_screen->select94CharacterSet(count, graphic);
	// SCS:count 为槽字符,G0..G3
}

void SuperCommander::select96CharacterSet(int count, int graphic)
{
	// moc[179] -> 0x7e4e16
	m_screen->select96CharacterSet(count, graphic);
	// SCS:G1..G3 96 集
}

void SuperCommander::shiftSingleTwo()
{
	// moc[246] -> 0x7e5254
	m_screen->shiftSingle(2);
	// 适配器 0x7cd0c8
}

void SuperCommander::shiftSingleThree()
{
	// moc[247] -> 0x7e5254
	m_screen->shiftSingle(3);
	// 适配器 0x7cd0da
}

void SuperCommander::shiftLockingZero()
{
	// moc[245] -> 0x7e521c
	m_screen->shiftLocking(true, 0);
	// 适配器 0x7cd0b4:FUN_007e521c(p,1,0)
}

void SuperCommander::shiftLockingOne()
{
	// moc[239] -> 0x7e521c
	m_screen->shiftLocking(true, 1);
	// 0x7cd036
}

void SuperCommander::shiftLockingOneRight()
{
	// moc[240] -> 0x7e521c
	m_screen->shiftLocking(false, 1);
	// 0x7cd04c
}

void SuperCommander::shiftLockingTwo()
{
	// moc[243] -> 0x7e521c
	m_screen->shiftLocking(true, 2);
	// 0x7cd060
}

void SuperCommander::shiftLockingTwoRight()
{
	// moc[244] -> 0x7e521c
	m_screen->shiftLocking(false, 2);
	// 0x7cd076
}

void SuperCommander::shiftLockingThree()
{
	// moc[241] -> 0x7e521c
	m_screen->shiftLocking(true, 3);
	// 0x7cd08a
}

void SuperCommander::shiftLockingThreeRight()
{
	// moc[242] -> 0x7e521c
	m_screen->shiftLocking(false, 3);
	// 0x7cd0a0
}

void SuperCommander::assignUserPreferredSupplementalSet(int set, int type)
{
	// moc[8] -> 0x7e4ac2
	m_screen->assignUserPreferredSupplementalSet(set, type);
}

void SuperCommander::singleLineWidth()
{
	// moc[248] -> 0x7e41e4
	m_screen->setLineDoubleWidth(false);
	// DECSWL,适配器 0x7cd0ec
}

void SuperCommander::doubleLineWidth()
{
	// moc[28] -> 0x7e41e4
	m_screen->setLineDoubleWidth(true);
	// DECDWL
}

void SuperCommander::doubleLineHeightTop()
{
	// moc[27] -> 0x7e4282
	m_screen->setLineDoubleHeightTop(true);
	// DECDHL 顶半行
}

void SuperCommander::doubleLineHeightBottom()
{
	// moc[26] -> 0x7e4236
	m_screen->setLineDoubleHeightBottom(true);
	// DECDHL 底半行
}

void SuperCommander::setAnsiConformanceLevelOne()
{
	// moc[194] -> 0x7e5b12
	m_screen->setAnsiConformanceLevel(1);
}

void SuperCommander::setAnsiConformanceLevelTwo()
{
	// moc[195] -> 0x7e5b12
	m_screen->setAnsiConformanceLevel(2);
}

void SuperCommander::setAnsiConformanceLevelThree()
{
	// moc[196] -> 0x7e5b12
	m_screen->setAnsiConformanceLevel(3);
}

void SuperCommander::setConformanceLevel()
{
	m_screen->setConformanceLevel(0, 0);
}

void SuperCommander::setConformanceLevel(int level)
{
	// moc[201] -> 0x7eecc0
	m_screen->setConformanceLevel(level, 0);
}

void SuperCommander::setConformanceLevel(int level, int type)
{
	// moc[200] -> 0x7eecc0
	m_screen->setConformanceLevel(level, type);
}

void SuperCommander::select7BitC1Control()
{
	// moc[176] -> 0x7e5aec
	m_screen->select7BitC1Control(false);
	// 适配器 0x7cc4e4 传 0
}

void SuperCommander::select8BitC1Control()
{
	// moc[177] -> 0x7e5aec
	m_screen->select7BitC1Control(true);
	// 适配器 0x7cc4f2 传 1(共用实现)
}

void SuperCommander::exitAnsiMode()
{
	// moc[47] -> 0x7e88e8
	m_screen->exitAnsiMode();
	// 进入 VT52(FUN_007e87c8(p,0))
}

void SuperCommander::enterAltKeypadMode()
{
	// moc[33] -> 0x7e37e8
	m_screen->enterAltKeypadMode();
}

void SuperCommander::exitAltKeypadMode()
{
	// moc[46] -> 0x7e3896
	m_screen->exitAltKeypadMode();
}

void SuperCommander::refreshScreen()
{
	// moc[125] -> 0x61324e
	m_screen->refreshNeeded();
	// 视图标志位取反,FUN_0061324e
}

void SuperCommander::setColumnsPerPage()
{
	// moc[199] -> 0x7e61fa
	m_screen->setColumnsPerPage(0);
}

void SuperCommander::setColumnsPerPage(int columns)
{
	// moc[198] -> 0x7e61fa
	m_screen->setColumnsPerPage(columns);
}

void SuperCommander::setLinesPerPage()
{
	// moc[217] -> 0x7e5eb2
	m_screen->setLinesPerPage(0);
	// 缺省参 0
}

void SuperCommander::setLinesPerPage(int lines)
{
	// moc[216] -> 0x7e5eb2
	m_screen->setLinesPerPage(lines);
}

void SuperCommander::selectNumberOfLinesOnScreen(int lines)
{
	// moc[190] -> 0x7e5ba2
	m_screen->selectNumberOfLinesOnScreen(lines);
	// DECSNLS
}

void SuperCommander::setCursorStyle()
{
	// moc[203] -> 0x7e4ffa
	m_screen->setCursorStyle(1, false);
	// DECSCUSR,缺省参 1
}

void SuperCommander::setCursorStyle(int style)
{
	// moc[202] -> 0x7e4ffa
	m_screen->setCursorStyle(style, false);
}

void SuperCommander::setCursorVisibility()
{
	// moc[205] -> 0x7e5090
	m_screen->setCursorVisibility(1);
	// DECTCEM,缺省参 1
}

void SuperCommander::setCursorVisibility(bool visible)
{
	// moc[204] -> 0x7e5090
	m_screen->setCursorVisibility(visible ? 1 : 0);
}

void SuperCommander::adjustScreenAlignment()
{
	// moc[5] -> 0x7e5f24
	m_screen->adjustScreenAlignment();
	// DECALN:全屏填 E
}

void SuperCommander::allowScrollback()
{
	// moc[6] -> 0x7e4036
	m_screen->isScrollbackAllowed();
	// 取值函数,槽调用丢弃返回值
}

void SuperCommander::setAllowScrollback(const QString &allowed)
{
	// moc[193] -> 0x7e4f1c
	m_screen->setAllowScrollback(allowed == QStringLiteral("1"));
	// 补录:此前注入失败
}

void SuperCommander::originTop()
{
	// moc[120] -> 0x7e48e0
	m_screen->originTop();
	// 实现为取值函数,槽调用丢弃返回值(适配器纯转发)
}

void SuperCommander::originBottom()
{
	// moc[117] -> 0x7e48b0
	m_screen->originBottom();
	// 实现为取值函数,槽调用丢弃返回值(适配器纯转发)
}

void SuperCommander::originLeft()
{
	// moc[118] -> 0x7e48c8
	m_screen->originLeft();
	// 实现为取值函数,槽调用丢弃返回值(适配器纯转发)
}

void SuperCommander::originRight()
{
	// moc[119] -> 0x7e48d4
	m_screen->originRight();
	// 实现为取值函数,槽调用丢弃返回值(适配器纯转发)
}

void SuperCommander::movePagePositionAbsolute()
{
	// moc[103] -> 0x7ef16a
	m_screen->movePage(0, false);
	// 缺省参 0
}

void SuperCommander::movePagePositionAbsolute(int page)
{
	// moc[102] -> 0x7ef16a
	if (page < 0)
		return;
	m_screen->movePage(page, false);
}

void SuperCommander::movePagePositionBackward()
{
	// moc[105] -> 0x7ef16a
	m_screen->movePage(m_screen->currentPage() - 1, false);
}

void SuperCommander::movePagePositionBackward(int pages)
{
	// moc[104] -> 0x7ef16a
	if (pages < 0)
		return;
	m_screen->movePage(m_screen->currentPage() - pages, false);
}

void SuperCommander::movePagePositionRelative()
{
	// moc[107] -> 0x7ef16a
	m_screen->movePage(m_screen->currentPage() + 1, false);
}

void SuperCommander::movePagePositionRelative(int pages)
{
	// moc[106] -> 0x7ef16a
	if (pages < 0)
		return;
	m_screen->movePage(m_screen->currentPage() + pages, false);
}

void SuperCommander::setMarginBellVolume()
{
	// moc[219] -> 0x7e5190
	// 未转写(后续批次)
}

void SuperCommander::setMarginBellVolume(int volume)
{
	// moc[218] -> 0x7e5190
	// 未转写(后续批次)
}

void SuperCommander::setWarningBellVolume()
{
	// moc[231] -> 0x7e520c
	// 未转写(后续批次)
}

void SuperCommander::setWarningBellVolume(int volume)
{
	// moc[230] -> 0x7e520c
	// 未转写(后续批次)
}

void SuperCommander::selectStatusLineType()
{
	// moc[192] -> 0x7f0346
	m_screen->selectStatusLineType(0);
}

void SuperCommander::selectStatusLineType(int type)
{
	// moc[191] -> 0x7f0346
	m_screen->selectStatusLineType(type);
}

void SuperCommander::selectActiveStatusDisplay()
{
	// moc[181] -> 0x7ef86e
	m_screen->selectActiveStatusDisplay(0);
}

void SuperCommander::selectActiveStatusDisplay(int display)
{
	// moc[180] -> 0x7ef86e
	m_screen->selectActiveStatusDisplay(display);
}

void SuperCommander::reportDeviceAttributesOne()
{
	// moc[128] -> 0x7ea806
	m_screen->reportDeviceAttributes(0);
	// DA1,容器首元素
}

void SuperCommander::reportDeviceAttributesTwo()
{
	// moc[129] -> 0x7ea806
	m_screen->reportDeviceAttributes(1);
	// DA2
}

void SuperCommander::reportDeviceAttributesThree()
{
	// moc[130] -> 0x7ea806
	m_screen->reportDeviceAttributes(2);
	// DA3
}

void SuperCommander::reportDeviceStatus(const QString &status)
{
	// moc[131] -> 0x7f0ae6
	m_screen->reportDeviceStatus(status);
	// DSR 应答装配
}

void SuperCommander::reportDecDeviceStatus(const QString &status)
{
	// moc[132] -> 0x7f0d7c
	m_screen->reportDecDeviceStatus(mode);
}

void SuperCommander::reportTerminalParameters()
{
	// moc[134] -> 0x7ecdc2
	m_screen->reportTerminalParameters();
}

void SuperCommander::reportTerminalParameters(int mode)
{
	// moc[133] -> 0x7ecdc2
	m_screen->reportTerminalParameters();
}

void SuperCommander::requestTerminalStateReport()
{
	// moc[145] -> 0x7f0434
	m_screen->requestTerminalStateReport();
}

void SuperCommander::requestTerminalStateReport(int mode)
{
	// moc[144] -> 0x7f0434
	m_screen->requestTerminalStateReport();
}

void SuperCommander::requestPresentationStateReport(int state)
{
	// moc[142] -> 0x7ed35a
	// 未转写(后续批次)
}

void SuperCommander::requestUserPreferredSupplementalSet()
{
	// moc[146] -> 0x7ed7f6
	m_screen->requestUserPreferredSupplementalSet();
}

void SuperCommander::requestDisplayedExtent()
{
	// moc[137] -> 0x7ed148
	m_screen->requestDisplayedExtent();
	// 应答 "%d;%d;1;1;1"w"
}

void SuperCommander::requestWindowSelections(const QString &which)
{
	// moc[147] -> 0x4c3220
	// 未转写(后续批次)
}

void SuperCommander::setWindowSelections(const QString &which, const QString &selections)
{
	// moc[236] -> 0x4beac0
	// 未转写(后续批次)
}

void SuperCommander::requestXtermTerminfoData(const QString &name)
{
	// moc[148] -> 0x7f3518
	m_screen->requestXtermTerminfoData(name);
}

void SuperCommander::setXtermTerminfoData(const QString &name)
{
	// moc[238] -> 0x7f07d8
	// 未转写(后续批次)
}

void SuperCommander::requestKeyModifier()
{
	// 未转写(后续批次)
}

void SuperCommander::requestKeyModifier(int modifier)
{
	// moc[138] -> 0x7ed282
	m_screen->requestKeyModifier(modifier);
	// 应答 ESC[>%d;%dm
}

void SuperCommander::setKeyModifier()
{
	m_screen->setKeyModifier();
}

void SuperCommander::setKeyModifier(int modifier)
{
	// moc[212] -> 0x7e5152
	m_screen->setKeyModifier();
}

void SuperCommander::setKeyModifier(int modifier, int type)
{
	// moc[211] -> 0x7e5152
	// 未转写(后续批次)
}

void SuperCommander::resetKeyModifier()
{
	// moc[152] -> 0x7e498c
	m_screen->resetKeyModifier();
}

void SuperCommander::resetKeyModifier(int modifier)
{
	// moc[151] -> 0x7e498c
	m_screen->resetKeyModifier();
}

void SuperCommander::enableLocatorReports()
{
	// 未转写(后续批次)
}

void SuperCommander::enableLocatorReports(int unit)
{
	// moc[31] -> 0x7e37a8
	// 未转写(后续批次)
}

void SuperCommander::enableLocatorReports(int unit, int mode)
{
	// moc[30] -> 0x7e37a8
	// 未转写(后续批次)
}

void SuperCommander::filterRectangle(int top, int left, int bottom, int right)
{
	// 未转写(后续批次)
}

void SuperCommander::requestLocatorPosition()
{
	// moc[140] -> 0x7ebd6a
	// 未转写(后续批次)
}

void SuperCommander::requestLocatorPosition(int mode)
{
	// moc[139] -> 0x7ebd6a
	m_screen->requestLocatorPosition(mode);
}

void SuperCommander::selectLocatorEvents(const QString &events)
{
	// moc[189] -> 0x7e4e80
	m_screen->selectLocatorEvents(events);
	// 补录
}

void SuperCommander::highlightTracking(int mode, int type)
{
	// moc[53] -> 0x7eac52
	// 未转写(后续批次)
}

void SuperCommander::enableFilterRectangle(const QString &filter)
{
	// moc[29] -> 0x7eb8fe
	// 未转写(后续批次)
}

void SuperCommander::setWindowTitle(const QString &title)
{
	// moc[237] -> 0x7cd366
	m_screen->setWindowTitleBuffer(title);
}

void SuperCommander::windowTitle()
{
	// moc[261] -> 0x4c29d0
	m_screen->setWindowTitleBuffer(QString());
	// 适配器 0x4c29d0 为 PLT 桩
}

void SuperCommander::setWindowIcon(const QString &icon)
{
	// moc[234] -> 0x4c29d0
	m_screen->setWindowTitleBuffer(icon);
	// 同 0x7cd366 锁缓冲路径
}

void SuperCommander::windowIcon()
{
	// moc[259] -> 0x4c29d0
	// PLT 桩(0x4c29d0),实际逻辑在适配器内联
}

void SuperCommander::setWindowIconAndTitle(const QString &iconAndTitle)
{
	// moc[235] -> 0x7cd902
	m_screen->setWindowIconAndTitle(iconAndTitle);
	// 0x7cd902:+0x118 缓冲交换+视图通知
}

void SuperCommander::setWindowColor(int index, const QString &color)
{
	// moc[233] -> 0x7f24ae
	// 未转写(后续批次)
}

void SuperCommander::setWindowColor(int index, const QString &color, int type)
{
	// 未转写(后续批次)
}

void SuperCommander::resetWindowColor()
{
	// 未转写(后续批次)
}

void SuperCommander::resetWindowColor(int index)
{
	// moc[156] -> 0x7f0858
	// 未转写(后续批次)
}

void SuperCommander::setWindowAttributes(const QString &attributes)
{
	// moc[232] -> 0x7f298e
	// 未转写(后续批次)
}

void SuperCommander::windowColumns()
{
	// moc[258] -> 0x7e5b96
	// 未转写(后续批次)
}

void SuperCommander::windowRows()
{
	// moc[260] -> 0x7e5f18
	// 未转写(后续批次)
}

void SuperCommander::startGuardedArea()
{
	// moc[249] -> 0x7e5278
	m_screen->startGuardedArea();
}

void SuperCommander::endGuardedArea()
{
	// moc[32] -> 0x7e37dc
	m_screen->endGuardedArea();
}

void SuperCommander::mediaCopy()
{
	// moc[69] -> 0x7f0530
	// 未转写(后续批次)
}

void SuperCommander::mediaCopy(int mode)
{
	// moc[68] -> 0x7f0530
	// 未转写(后续批次)
}

void SuperCommander::mediaCopyDec(int mode)
{
	// moc[70] -> 0x7f063a
	// 未转写(后续批次)
}

void SuperCommander::setCodec(const QString &name)
{
	// moc[197] -> -0x3efdef14
	// 未转写(后续批次)
}

void SuperCommander::toUnicode(const QString &text)
{
	// moc[251] -> 0x4c29d0
	m_screen->codecToUnicode(data);
	// 0x4c29d0 PLT;编码转换在调用方
}

void SuperCommander::fromUnicode(const QString &text)
{
	// moc[52] -> 0x4c29d0
	m_screen->codecFromUnicode(text);
}

void SuperCommander::notifyCommand(const QString &command)
{
	// moc[110] -> 0x4c3110
	m_screen->notifyCommand(command);
	// 适配器经 qstrcmp PLT(0x4c3110),非 Screen 逻辑
}

void SuperCommander::notifyMessage(int message)
{
	m_screen->notifyMessageEx(message, 0, 0);
	// 单参变体
}

void SuperCommander::notifyMessage(int message, int type)
{
	// moc[114] -> 0x5444ac
	m_screen->notifyMessageEx(message, type, 0);
}

void SuperCommander::notifyRemoteDirectory(const QString &directory)
{
	// moc[115] -> 0x7cd366
	m_screen->setWindowTitleBuffer(dir);
	// 同 setWindowTitle 路径(0x7cd366)
}

void SuperCommander::notifyHyperlink(const QString &url)
{
	// moc[112] -> 0x4c3290
	m_screen->notifyOsc(8, content);
}

void SuperCommander::notifyIterm2(const QString &content)
{
	// moc[113] -> 0x4c3290
	m_screen->notifyOsc(1337, content);
}

void SuperCommander::notifyFig(const QString &content)
{
	// moc[111] -> 0x4c3290
	m_screen->notifyOsc(0, content);
	// 与 notifyHyperlink/Iterm2 同指 0x4c3290(split PLT)
}

void SuperCommander::option(const QString &name)
{
	// moc[116] -> 0x7d5538
	// 未转写(后续批次)
}

void SuperCommander::checkControlCharacter()
{
	// moc[15] -> 0x7e3568
	m_checkControlChars = true;
	// 适配器 0x7cadda 直写 Commander+0x101,不经 Screen
}

void SuperCommander::dataType()
{
	// moc[19] -> 0x7e3784
	// 未转写(后续批次)
}

void SuperCommander::testConfidence(const QString &data)
{
	// moc[250] -> 0x7f0a5e
	// 未转写(后续批次)
}

void SuperCommander::setUserDefinedKeys()
{
	// moc[229] -> 0x7ef0e8
	m_screen->setUserDefinedKeys();
	// DECDLD
}

void SuperCommander::setUserDefinedKeys(int key)
{
	// moc[228] -> 0x7ef0e8
	m_screen->setUserDefinedKeys();
}

void SuperCommander::setUserDefinedKeys(int key, int clear)
{
	// moc[227] -> 0x7ef0e8
	m_screen->setUserDefinedKeys();
}

void SuperCommander::setUserDefinedKeys(int key, int clear, int modifier)
{
	// moc[226] -> 0x7ef0e8
	m_screen->setUserDefinedKeys();
}

void SuperCommander::loadLeds()
{
	// moc[63] -> 0x7eadba
	// 未转写(后续批次)
}

void SuperCommander::loadLeds(const QString &leds)
{
	// moc[62] -> 0x7eadba
	// 未转写(后续批次)
}

void SuperCommander::enterTmuxControlMode()
{
	// moc[34] -> 0x7e9a06
	// 未转写(后续批次)
}

void SuperCommander::zmodemSend()
{
	// moc[263] -> 0x7e6844
	m_screen->zmodemSend();
	// notifyView(2,1)
}

void SuperCommander::zmodemReceive()
{
	// moc[262] -> 0x7e676c
	m_screen->zmodemReceive();
	// QTimer 状态机编排
}

void SuperCommander::bracketedPasteMode()
{
	// moc[12] -> 0x7e355a
	m_screen->isBracketedPaste();
	// 取值函数(DEC 2004 标志)
}
