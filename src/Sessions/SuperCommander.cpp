#include "SuperCommander.h"

// 全量转写(165 有实现 + 19 未解析):由 tools/re/data/supercommander_adapters.json 生成。
// 信号 5 个由 moc 生成,不定义。模板:T1 纯转发,T2 参数守卫,T3 复合。
// 函数体为转发占位(phase-1 参考还原,不编译)。

SuperCommander::SuperCommander(QObject *parent)
	: QObject(parent)
{
}

void SuperCommander::vt52Mode()
{
	// 适配器未解析(直接调用变体)
}

void SuperCommander::vt52Identify()
{
	// moc[255] (T1) -> 0x7edc22
}

void SuperCommander::vt52EnterGraphicsMode()
{
	// moc[253] (T1) -> 0x7e5a90
}

void SuperCommander::vt52ExitGraphicsMode()
{
	// moc[254] (T1) -> 0x7e5ab0
}

void SuperCommander::vt52MoveCursor(int column, int line)
{
	// moc[257] (T1) -> 0x7e4f38
}

void SuperCommander::moveCursor()
{
	// moc[71] (T1) -> 0x7e4fdc
}

void SuperCommander::moveCursorColumn()
{
	// moc[76] (T1) -> 0x7e4fdc
}

void SuperCommander::moveCursorColumnRelative()
{
	// moc[80] (T2) -> 0x7e4fdc
}

void SuperCommander::moveCursorColumnBackward()
{
	// moc[78] (T2) -> 0x7e4fdc
}

void SuperCommander::moveCursorForward(int columns)
{
	// moc[84] (T2) -> 0x7e484a
	if (columns < 0)
		return;
	if (columns == 0)
		columns = 1;
}

void SuperCommander::moveCursorBackward()
{
	// moc[74] (T2) -> 0x7e4832
}

void SuperCommander::moveCursorUp()
{
	// moc[100] (T2) -> 0x7e4856
}

void SuperCommander::moveCursorDown()
{
	// moc[82] (T2) -> 0x7e483e
}

void SuperCommander::moveCursorLine()
{
	// moc[86] (T1) -> 0x7e4fdc
}

void SuperCommander::moveCursorLineRelative()
{
	// moc[90] (T1) -> 0x7e4fdc
}

void SuperCommander::moveCursorLineBackward()
{
	// moc[88] (T1) -> 0x7e4fdc
}

void SuperCommander::moveCursorNextLine()
{
	// moc[92] (T1) -> 0x7e4fdc
}

void SuperCommander::moveCursorPrecedingLine()
{
	// moc[96] (T1) -> 0x7e4fdc
}

void SuperCommander::moveCursorNextTabstop()
{
	// moc[94] (T2) -> 0x7e4fdc
}

void SuperCommander::moveCursorPrecedingTabstop()
{
	// moc[98] (T2) -> 0x7e4fdc
}

void SuperCommander::backspace()
{
	// moc[10] (T1) -> 0x7e4f44
}

void SuperCommander::carriageReturn()
{
	// moc[13] (T1) -> 0x7e4fc8
}

void SuperCommander::lineFeed()
{
	// moc[61] (T1) -> 0x7e55fc
}

void SuperCommander::formFeed()
{
	// moc[50] (T1) -> 0x7e55fc
}

void SuperCommander::verticalTab()
{
	// moc[252] (T1) -> 0x7e55fc
}

void SuperCommander::horizontalTab()
{
	// moc[54] (T1) -> 0x7e5d7c
}

void SuperCommander::bell()
{
	// moc[11] (T1) -> 0x4bc0d0
}

void SuperCommander::repeatCharacter()
{
	// moc[126] (T1) -> 0x7e7cf6
}

void SuperCommander::insertCharacter()
{
	// moc[55] (T1) -> 0x7e3ace
}

void SuperCommander::deleteCharacter()
{
	// moc[20] (T1) -> 0x7e3784
}

void SuperCommander::eraseCharacter()
{
	// moc[35] (T1) -> 0x7e385a
}

void SuperCommander::insertLine()
{
	// moc[59] (T1) -> 0x7e3ae6
}

void SuperCommander::deleteLine()
{
	// moc[24] (T1) -> 0x7e379c
}

void SuperCommander::insertColumn()
{
	// moc[57] (T1) -> 0x7e3ada
}

void SuperCommander::deleteColumn()
{
	// moc[22] (T1) -> 0x7e3790
}

void SuperCommander::eraseLine()
{
	// moc[37] (T1) -> 0x7e4ba2
}

void SuperCommander::eraseScreen()
{
	// moc[40] (T2) -> 0x7e606a
}

void SuperCommander::eraseSelectiveLine()
{
	// moc[42] (T1) -> 0x7e4ba2
}

void SuperCommander::eraseSelectiveScreen()
{
	// moc[44] (T1) -> 0x7e606a
}

void SuperCommander::eraseRectangularArea(const QString &area)
{
	// moc[39] (T2) -> 0x7eb1c4
	if (&area < 0)
		return;
	if (&area == 0)
		&area = 1;
}

void SuperCommander::selectiveEraseRectangularArea(const QString &area)
{
	// moc[188] (T1) -> 0x7eb1c4
}

void SuperCommander::scrollUp()
{
	// moc[174] (T2) -> 0x7e5546
}

void SuperCommander::scrollDown()
{
	// moc[167] (T2) -> 0x7e5546
}

void SuperCommander::scrollLeft()
{
	// moc[169] (T2) -> 0x7e4d3c
}

void SuperCommander::scrollRight()
{
	// moc[172] (T2) -> 0x7e4d3c
}

void SuperCommander::scrollCursorUp()
{
	// moc[166] (T1) -> 0x7e563e
}

void SuperCommander::scrollCursorDown()
{
	// moc[165] (T1) -> 0x7e55b6
}

void SuperCommander::scrollNextLine()
{
	// moc[171] (T1) -> 0x7e562c
}

void SuperCommander::nextPage()
{
	// moc[108] (T2) -> 0x7ef16a
}

void SuperCommander::precedingPage()
{
	// moc[123] (T2) -> 0x7ef16a
}

void SuperCommander::page()
{
	// 适配器未解析(直接调用变体)
}

void SuperCommander::pages()
{
	// 适配器未解析(直接调用变体)
}

void SuperCommander::forwardIndex()
{
	// moc[51] (T1) -> 0x7e4d82
}

void SuperCommander::backIndex()
{
	// moc[9] (T1) -> 0x7e4d48
}

void SuperCommander::marginTop()
{
	// 适配器未解析(直接调用变体)
}

void SuperCommander::marginBottom()
{
	// 适配器未解析(直接调用变体)
}

void SuperCommander::marginLeft()
{
	// 适配器未解析(直接调用变体)
}

void SuperCommander::marginRight()
{
	// 适配器未解析(直接调用变体)
}

void SuperCommander::setTopBottomMargins()
{
	// moc[222] (T1) -> 0x7e5fa6
}

void SuperCommander::setLeftRightMargins()
{
	// moc[213] (T1) -> 0x7e5bd4
}

void SuperCommander::setHorizontalTabstop()
{
	// moc[208] (T1) -> 0x7e52fc
}

void SuperCommander::clearTabstop()
{
	// moc[16] (T1) -> 0x7e5df0
}

void SuperCommander::setMode()
{
	// moc[220] (T1) -> 0x7edce6
}

void SuperCommander::resetMode()
{
	// moc[153] (T2) -> 0x7edce6
}

void SuperCommander::requestMode(int mode)
{
	// moc[141] (T1) -> 0x7f17c2
}

void SuperCommander::setDecMode()
{
	// moc[206] (T1) -> 0x7f5d2e
}

void SuperCommander::resetDecMode(int mode)
{
	// moc[149] (T2) -> 0x7f5d2e
	if (mode < 0)
		return;
	if (mode == 0)
		mode = 1;
}

void SuperCommander::saveDecMode(int mode)
{
	// moc[164] (T1) -> 0x7f427a
}

void SuperCommander::restoreDecMode(int mode)
{
	// moc[158] (T1) -> 0x7f64a6
}

void SuperCommander::requestDecMode(int mode)
{
	// moc[136] (T1) -> 0x7f13a0
}

void SuperCommander::selectCharacterAttribute()
{
	// moc[184] (T1) -> 0x7eebd4
}

void SuperCommander::selectGraphicRendition()
{
	// moc[186] (T1) -> 0x7ef95c
}

void SuperCommander::selectAttributeChangeExtent()
{
	// moc[182] (T1) -> 0x7e4e74
}

void SuperCommander::reverseScreen()
{
	// 适配器未解析(直接调用变体)
}

void SuperCommander::changeAttributesInRectangularArea(const QString &area)
{
	// moc[14] (T1) -> 0x7eb17e
}

void SuperCommander::reverseAttributesInRectangularArea(const QString &area)
{
	// moc[161] (T1) -> 0x7eb2ac
}

void SuperCommander::copyRectangularArea(const QString &area)
{
	// moc[18] (T1) -> 0x7eb2f2
}

void SuperCommander::fillRectangularArea(const QString &fill)
{
	// moc[48] (T1) -> 0x7eb20a
}

void SuperCommander::requestChecksumOfRectangularArea(const QString &area, int pid)
{
	// moc[135] (T1) -> 0x7eced6
}

void SuperCommander::select94CharacterSet(int count, int graphic)
{
	// moc[178] (T1) -> 0x7e4dbc
}

void SuperCommander::select96CharacterSet(int count, int graphic)
{
	// moc[179] (T1) -> 0x7e4e16
}

void SuperCommander::shiftSingleTwo()
{
	// moc[246] (T1) -> 0x7e5254
}

void SuperCommander::shiftSingleThree()
{
	// moc[247] (T1) -> 0x7e5254
}

void SuperCommander::shiftLockingZero()
{
	// moc[245] (T2) -> 0x7e521c
}

void SuperCommander::shiftLockingOne()
{
	// moc[239] (T1) -> 0x7e521c
}

void SuperCommander::shiftLockingOneRight()
{
	// moc[240] (T1) -> 0x7e521c
}

void SuperCommander::shiftLockingTwo()
{
	// moc[243] (T1) -> 0x7e521c
}

void SuperCommander::shiftLockingTwoRight()
{
	// moc[244] (T1) -> 0x7e521c
}

void SuperCommander::shiftLockingThree()
{
	// moc[241] (T1) -> 0x7e521c
}

void SuperCommander::shiftLockingThreeRight()
{
	// moc[242] (T1) -> 0x7e521c
}

void SuperCommander::assignUserPreferredSupplementalSet(int set, int type)
{
	// moc[8] (T1) -> 0x7e4ac2
}

void SuperCommander::singleLineWidth()
{
	// moc[248] (T1) -> 0x7e41e4
}

void SuperCommander::doubleLineWidth()
{
	// moc[28] (T1) -> 0x7e41e4
}

void SuperCommander::doubleLineHeightTop()
{
	// moc[27] (T1) -> 0x7e4282
}

void SuperCommander::doubleLineHeightBottom()
{
	// moc[26] (T1) -> 0x7e4236
}

void SuperCommander::setAnsiConformanceLevelOne()
{
	// moc[194] (T1) -> 0x7e5b12
}

void SuperCommander::setAnsiConformanceLevelTwo()
{
	// moc[195] (T1) -> 0x7e5b12
}

void SuperCommander::setAnsiConformanceLevelThree()
{
	// moc[196] (T1) -> 0x7e5b12
}

void SuperCommander::setConformanceLevel()
{
	// moc[200] (T1) -> 0x7eecc0
}

void SuperCommander::select7BitC1Control()
{
	// moc[176] (T1) -> 0x7e5aec
}

void SuperCommander::select8BitC1Control()
{
	// moc[177] (T1) -> 0x7e5aec
}

void SuperCommander::exitAnsiMode()
{
	// moc[47] (T1) -> 0x7e88e8
}

void SuperCommander::enterAltKeypadMode()
{
	// moc[33] (T1) -> 0x7e37e8
}

void SuperCommander::exitAltKeypadMode()
{
	// moc[46] (T1) -> 0x7e3896
}

void SuperCommander::refreshScreen()
{
	// moc[125] (T1) -> 0x61324e
}

void SuperCommander::setColumnsPerPage()
{
	// moc[198] (T1) -> 0x7e61fa
}

void SuperCommander::setLinesPerPage()
{
	// moc[216] (T1) -> 0x7e5eb2
}

void SuperCommander::selectNumberOfLinesOnScreen(int lines)
{
	// moc[190] (T1) -> 0x7e5ba2
}

void SuperCommander::setCursorStyle()
{
	// moc[202] (T2) -> 0x7e4ffa
}

void SuperCommander::setCursorVisibility()
{
	// moc[204] (T1) -> 0x7e5090
}

void SuperCommander::adjustScreenAlignment()
{
	// moc[5] (T1) -> 0x7e5f24
}

void SuperCommander::allowScrollback()
{
	// 适配器未解析(直接调用变体)
}

void SuperCommander::setAllowScrollback(const QString &allowed)
{
	// moc[193] (T1) -> 0x7e4f1c
}

void SuperCommander::originTop()
{
	// 适配器未解析(直接调用变体)
}

void SuperCommander::originBottom()
{
	// 适配器未解析(直接调用变体)
}

void SuperCommander::originLeft()
{
	// 适配器未解析(直接调用变体)
}

void SuperCommander::originRight()
{
	// 适配器未解析(直接调用变体)
}

void SuperCommander::movePagePositionAbsolute()
{
	// moc[102] (T2) -> 0x7ef16a
}

void SuperCommander::movePagePositionBackward()
{
	// moc[104] (T2) -> 0x7ef16a
}

void SuperCommander::movePagePositionRelative()
{
	// moc[106] (T2) -> 0x7ef16a
}

void SuperCommander::setMarginBellVolume()
{
	// moc[218] (T1) -> 0x7e5190
}

void SuperCommander::setWarningBellVolume()
{
	// moc[230] (T1) -> 0x7e520c
}

void SuperCommander::selectStatusLineType()
{
	// moc[191] (T1) -> 0x7f0346
}

void SuperCommander::selectActiveStatusDisplay()
{
	// moc[180] (T1) -> 0x7ef86e
}

void SuperCommander::reportDeviceAttributesOne()
{
	// moc[128] (T1) -> 0x7ea806
}

void SuperCommander::reportDeviceAttributesTwo()
{
	// moc[129] (T1) -> 0x7ea806
}

void SuperCommander::reportDeviceAttributesThree()
{
	// moc[130] (T1) -> 0x7ea806
}

void SuperCommander::reportDeviceStatus(const QString &status)
{
	// moc[131] (T1) -> 0x7f0ae6
}

void SuperCommander::reportDecDeviceStatus(const QString &status)
{
	// moc[132] (T1) -> 0x7f0d7c
}

void SuperCommander::reportTerminalParameters()
{
	// moc[133] (T1) -> 0x7ecdc2
}

void SuperCommander::requestTerminalStateReport()
{
	// moc[144] (T1) -> 0x7f0434
}

void SuperCommander::requestPresentationStateReport(int state)
{
	// moc[142] (T1) -> 0x7ed35a
}

void SuperCommander::requestUserPreferredSupplementalSet()
{
	// moc[146] (T1) -> 0x7ed7f6
}

void SuperCommander::requestDisplayedExtent()
{
	// moc[137] (T1) -> 0x7ed148
}

void SuperCommander::requestWindowSelections(const QString &which)
{
	// moc[147] (T?) -> -
}

void SuperCommander::setWindowSelections(const QString &which, const QString &selections)
{
	// moc[236] (T1) -> 0x4beac0
}

void SuperCommander::requestXtermTerminfoData(const QString &name)
{
	// moc[148] (T1) -> 0x7f3518
}

void SuperCommander::setXtermTerminfoData(const QString &name)
{
	// moc[238] (T1) -> 0x7f07d8
}

void SuperCommander::requestKeyModifier()
{
	// moc[138] (T1) -> 0x7ed282
}

void SuperCommander::setKeyModifier()
{
	// moc[211] (T1) -> 0x7e5152
}

void SuperCommander::resetKeyModifier()
{
	// moc[151] (T1) -> 0x7e498c
}

void SuperCommander::enableLocatorReports()
{
	// moc[30] (T1) -> 0x7e37a8
}

void SuperCommander::filterRectangle(int top, int left, int bottom, int right)
{
	// 适配器未解析(直接调用变体)
}

void SuperCommander::requestLocatorPosition()
{
	// moc[139] (T1) -> 0x7ebd6a
}

void SuperCommander::selectLocatorEvents(const QString &events)
{
	// moc[189] (T1) -> 0x7e4e80
}

void SuperCommander::highlightTracking(int mode, int type)
{
	// moc[53] (T1) -> 0x7eac52
}

void SuperCommander::enableFilterRectangle(const QString &filter)
{
	// moc[29] (T1) -> 0x7eb8fe
}

void SuperCommander::setWindowTitle(const QString &title)
{
	// moc[237] (T1) -> 0x7cd366
}

void SuperCommander::windowTitle()
{
	// moc[261] (T?) -> -
}

void SuperCommander::setWindowIcon(const QString &icon)
{
	// moc[234] (T?) -> -
}

void SuperCommander::windowIcon()
{
	// moc[259] (T?) -> -
}

void SuperCommander::setWindowIconAndTitle(const QString &iconAndTitle)
{
	// moc[235] (T1) -> 0x7cd902
}

void SuperCommander::setWindowColor(int index, const QString &color)
{
	// moc[233] (T1) -> 0x7f24ae
}

void SuperCommander::resetWindowColor()
{
	// moc[155] (T1) -> 0x7f0858
}

void SuperCommander::setWindowAttributes(const QString &attributes)
{
	// moc[232] (T1) -> 0x7f298e
}

void SuperCommander::windowColumns()
{
	// 适配器未解析(直接调用变体)
}

void SuperCommander::windowRows()
{
	// 适配器未解析(直接调用变体)
}

void SuperCommander::startGuardedArea()
{
	// moc[249] (T1) -> 0x7e5278
}

void SuperCommander::endGuardedArea()
{
	// moc[32] (T1) -> 0x7e37dc
}

void SuperCommander::mediaCopy()
{
	// moc[68] (T1) -> 0x7f0530
}

void SuperCommander::mediaCopyDec(int mode)
{
	// moc[70] (T1) -> 0x7f063a
}

void SuperCommander::setCodec(const QString &name)
{
	// moc[197] (T3) -> -0x3efdef14
}

void SuperCommander::toUnicode(const QString &text)
{
	// moc[251] (T?) -> -
}

void SuperCommander::fromUnicode(const QString &text)
{
	// moc[52] (T?) -> -
}

void SuperCommander::notifyCommand(const QString &command)
{
	// moc[110] (T1) -> 0x4c3110
}

void SuperCommander::notifyMessage(int message)
{
	// 适配器未解析(直接调用变体)
}

void SuperCommander::notifyRemoteDirectory(const QString &directory)
{
	// moc[115] (T1) -> 0x7cd366
}

void SuperCommander::notifyHyperlink(const QString &url)
{
	// moc[112] (T1) -> 0x4c3290
}

void SuperCommander::notifyIterm2(const QString &content)
{
	// moc[113] (T1) -> 0x4c3290
}

void SuperCommander::notifyFig(const QString &content)
{
	// moc[111] (T1) -> 0x4c3290
}

void SuperCommander::option(const QString &name)
{
	// moc[116] (T1) -> 0x7d5538
}

void SuperCommander::checkControlCharacter()
{
	// moc[15] (T1) -> 0x7e3568
}

void SuperCommander::dataType()
{
	// 适配器未解析(直接调用变体)
}

void SuperCommander::testConfidence(const QString &data)
{
	// moc[250] (T1) -> 0x7f0a5e
}

void SuperCommander::setUserDefinedKeys()
{
	// moc[225] (T1) -> 0x7ef0e8
}

void SuperCommander::loadLeds()
{
	// moc[62] (T1) -> 0x7eadba
}

void SuperCommander::enterTmuxControlMode()
{
	// moc[34] (T1) -> 0x7e9a06
}

void SuperCommander::zmodemSend()
{
	// moc[263] (T1) -> 0x7e6844
}

void SuperCommander::zmodemReceive()
{
	// moc[262] (T1) -> 0x7e676c
}

void SuperCommander::bracketedPasteMode()
{
	// 适配器未解析(直接调用变体)
}
