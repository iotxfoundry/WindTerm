# -*- coding: utf-8 -*-
import json, re

hdr = open('src/Sessions/SuperCommander.h').read()
ad = json.load(open('tools/re/data/supercommander_adapters.json'))
cases = json.load(open('/tmp/opencode/sc_cases_full.json'))
sigs = json.load(open('tools/re/data/super_sigs.json'))['SuperCommander']

SIGNALS = {'asyncMessage','syncMessage','error','charsetChanged','shellCwdChanged'}
by_name = {}
for r in ad:
    by_name.setdefault(r['name'], []).append(r)
argc_of = {}
for i, s in enumerate(sigs):
    argc_of.setdefault((s['name'], len(s['types'])), i)

G1 = "\tif ({n} < 0)\n\t\treturn;\n\tif ({n} == 0)\n\t\t{n} = 1;\n"   # T2: <0 reject, 0->1
G2 = "\tif ({n} < 1)\n\t\treturn;\n"                                   # <1 reject

# (name, argc) -> body lines. Args resolved from header params.
B = {}
def b(name, argc, *lines): B[(name, argc)] = list(lines)

# --- cursor family ---------------------------------------------------------
b('vt52MoveCursor', 2, 'm_screen->cursorMoveRaw(column - 32, line - 32);',
  '// 适配器 0x7cd9b6:FUN_007e4f38(screen, column-0x20, line-0x20) 直通 moveCursorRaw')
b('moveCursor', 0, 'm_screen->moveCursor(m_screen->originTop(), m_screen->originLeft());',
  '// 适配器 0x7cbeda,缺省参 1,1 -> 原点 home')
b('moveCursor', 1, 'm_screen->moveCursor(m_screen->originTop(), m_screen->originLeft() - 1 + position);',
  '// 适配器 0x7cbeda 为双参;单参槽取列位,参数序待动态验证')
b('moveCursor', 2, 'if (line < 1)', '\tline = 1;', 'if (column < 1)', '\tcolumn = 1;',
  'm_screen->moveCursor(m_screen->originTop() - 1 + line, m_screen->originLeft() - 1 + column);',
  '// 适配器 0x7cbeda:第一参进 Y,第二参进 X(originTop/originLeft 为原点基)')
b('moveCursorColumn', 0, 'm_screen->moveCursor(m_screen->currentLine(), m_screen->originLeft());',
  '// 适配器 0x7cbe1e,缺省参 1 -> originLeft')
b('moveCursorColumn', 1, 'if (column < 0)', '\treturn;', 'if (column == 0)', '\tcolumn = 1;',
  'm_screen->moveCursor(m_screen->currentLine(), m_screen->originLeft() - 1 + column);')
b('moveCursorColumnRelative', 0, 'm_screen->moveCursor(m_screen->currentLine(), m_screen->currentColumn() + 1);',
  '// 适配器 0x7cb282,缺省参 1')
b('moveCursorColumnRelative', 1, 'if (columns < 0)', '\treturn;', 'if (columns == 0)', '\tcolumns = 1;',
  'm_screen->moveCursor(m_screen->currentLine(), m_screen->currentColumn() + columns);')
b('moveCursorColumnBackward', 0, 'm_screen->moveCursor(m_screen->currentLine(), m_screen->currentColumn() - 1);',
  '// 适配器 0x7cb1f6,缺省参 1')
b('moveCursorColumnBackward', 1, 'if (columns < 0)', '\treturn;', 'if (columns == 0)', '\tcolumns = 1;',
  'm_screen->moveCursor(m_screen->currentLine(), m_screen->currentColumn() - columns);')
for nm, arg in (('moveCursorForward','columns'), ('moveCursorBackward','columns'),
                ('moveCursorUp','lines'), ('moveCursorDown','lines')):
    b(nm, 0, 'm_screen->%s(1);' % nm, '// 适配器带守卫,缺省参 1')
    b(nm, 1, 'if (%s < 0)' % arg, '\treturn;', 'if (%s == 0)' % arg, '\t%s = 1;' % arg,
      'm_screen->%s(%s);' % (nm, arg))
b('moveCursorLine', 0, 'm_screen->moveCursor(m_screen->originTop(), m_screen->currentColumn());',
  '// 适配器 0x7cbf28,缺省参 1 -> originTop')
b('moveCursorLine', 1, 'if (line < 0)', '\treturn;', 'if (line == 0)', '\tline = 1;',
  'm_screen->moveCursor(m_screen->originTop() - 1 + line, m_screen->currentColumn());')
b('moveCursorLineRelative', 0, 'm_screen->moveCursor(m_screen->currentLine() + 1, m_screen->currentColumn());',
  '// 适配器 0x7cb3b0,缺省参 1')
b('moveCursorLineRelative', 1, 'if (lines < 0)', '\treturn;', 'if (lines == 0)', '\tlines = 1;',
  'm_screen->moveCursor(m_screen->currentLine() + lines, m_screen->currentColumn());')
b('moveCursorLineBackward', 0, 'm_screen->moveCursor(m_screen->currentLine() - 1, m_screen->currentColumn());',
  '// 适配器 0x7cb30c,缺省参 1')
b('moveCursorLineBackward', 1, 'if (lines < 0)', '\treturn;', 'if (lines == 0)', '\tlines = 1;',
  'm_screen->moveCursor(m_screen->currentLine() - lines, m_screen->currentColumn());')
b('moveCursorNextLine', 0, 'm_screen->moveCursor(m_screen->currentLine() + 1, 0);',
  '// 适配器 0x7cb454,缺省参 1')
b('moveCursorNextLine', 1, 'if (lines < 0)', '\treturn;', 'if (lines == 0)', '\tlines = 1;',
  'm_screen->moveCursor(m_screen->currentLine() + lines, 0);')
b('moveCursorPrecedingLine', 0, 'm_screen->moveCursor(m_screen->currentLine() - 1, 0);',
  '// 适配器 0x7cb572,缺省参 1')
b('moveCursorPrecedingLine', 1, 'if (lines < 0)', '\treturn;', 'if (lines == 0)', '\tlines = 1;',
  'm_screen->moveCursor(m_screen->currentLine() - lines, 0);')
b('moveCursorNextTabstop', 0, 'm_screen->moveCursor(m_screen->currentLine(), m_screen->nextTabstop(m_screen->currentColumn(), 1));',
  '// 适配器 0x7cb4dc,缺省参 1')
b('moveCursorNextTabstop', 1, 'if (count < 0)', '\treturn;', 'if (count == 0)', '\tcount = 1;',
  'm_screen->moveCursor(m_screen->currentLine(), m_screen->nextTabstop(m_screen->currentColumn(), count));')
b('moveCursorPrecedingTabstop', 0, 'm_screen->moveCursor(m_screen->currentLine(), m_screen->prevTabstop(m_screen->currentColumn(), 1));',
  '// 适配器 0x7cb5fc,缺省参 1')
b('moveCursorPrecedingTabstop', 1, 'if (count < 0)', '\treturn;', 'if (count == 0)', '\tcount = 1;',
  'm_screen->moveCursor(m_screen->currentLine(), m_screen->prevTabstop(m_screen->currentColumn(), count));')
b('carriageReturn', 0, 'm_screen->carriageReturn();')
for nm in ('lineFeed', 'formFeed', 'verticalTab'):
    b(nm, 0, 'm_screen->lineFeed();', '// 三槽同指 0x7e55fc')
b('backspace', 0, 'm_screen->backspace();', '// 逆向回绕逻辑在 Screen::backspace(0x7e4f44)')
b('horizontalTab', 0, 'm_screen->horizontalTab();')
b('forwardIndex', 0, 'm_screen->forwardIndex();')
b('backIndex', 0, 'm_screen->backIndex();')
for nm in ('marginTop', 'marginBottom', 'marginLeft', 'marginRight',
           'originTop', 'originBottom', 'originLeft', 'originRight'):
    b(nm, 0, 'm_screen->%s();' % nm, '// 实现为取值函数,槽调用丢弃返回值(适配器纯转发)')

# --- erase family ------------------------------------------------------------
b('eraseCharacter', 0, 'm_screen->eraseCharacter(1);', '// 适配器 0x7c8c3c,缺省参 1')
b('eraseCharacter', 1, 'm_screen->eraseCharacter(count);', '// 守卫在实现内(FUN_007e385a)')
b('eraseLine', 0, 'm_screen->eraseLine(m_screen->currentLine(), 0, false);',
  '// 适配器 0x7cb106:T3,行参取当前行')
b('eraseLine', 1, 'm_screen->eraseLine(m_screen->currentLine(), mode, false);')
b('eraseSelectiveLine', 0, 'm_screen->eraseLine(m_screen->currentLine(), 0, true);',
  '// 适配器 0x7cb17c:同上,DECSED 选择擦除')
b('eraseSelectiveLine', 1, 'm_screen->eraseLine(m_screen->currentLine(), mode, true);')
b('eraseScreen', 0, 'm_screen->eraseScreen(0, false);', '// 适配器 0x7c8c68,缺省参 0')
b('eraseScreen', 1, 'm_screen->eraseScreen(mode, false);')
b('eraseSelectiveScreen', 0, 'm_screen->eraseScreen(0, true);', '// 适配器 0x7c8c76')
b('eraseSelectiveScreen', 1, 'm_screen->eraseScreen(mode, true);')
b('eraseRectangularArea', 1, 'm_screen->eraseRectangularArea(area, false);')
b('selectiveEraseRectangularArea', 1, 'm_screen->eraseRectangularArea(area, true);',
  '// 适配器 0x7c8c56:同 0x7c8c48,selective=1')
b('fillRectangularArea', 1, 'm_screen->fillRectangularArea(fill);')
b('fillRectangularArea', 2, 'm_screen->fillRectangularArea(fill);', '// area 参由实现内解析,适配器只传 fill')
b('copyRectangularArea', 1, 'm_screen->copyRectangularArea(area);')
b('changeAttributesInRectangularArea', 1, 'm_screen->changeAttributesInRectangularArea(area);')
b('reverseAttributesInRectangularArea', 1, 'm_screen->reverseAttributesInRectangularArea(area);')

# --- scroll family -------------------------------------------------------------
b('scrollUp', 0, 'm_screen->scroll(1, false, false);', '// 适配器 0x7c8db6(n,0,0),缺省参 1')
b('scrollUp', 1, 'if (lines < 0)', '\treturn;', 'if (lines < 1)', '\tlines = 1;',
  'm_screen->scroll(lines, false, false);')
b('scrollDown', 0, 'm_screen->scroll(1, true, false);', '// 适配器 0x7c8d96(n,1,0)')
b('scrollDown', 1, 'if (lines < 0)', '\treturn;', 'if (lines < 1)', '\tlines = 1;',
  'm_screen->scroll(lines, true, false);')
b('scrollLeft', 0, 'm_screen->scrollHorizontal(1);', '// 适配器 0x7c8dd4 正参')
b('scrollLeft', 1, 'if (columns < 1)', '\treturn;', 'm_screen->scrollHorizontal(columns);')
b('scrollRight', 0, 'm_screen->scrollHorizontal(-1);', '// 适配器 0x7c8e06 传 -n')
b('scrollRight', 1, 'if (columns < 1)', '\treturn;', 'm_screen->scrollHorizontal(-columns);')
b('scrollCursorDown', 0, 'm_screen->indexDown();', '// IND,适配器 0x7cc47e')
b('scrollCursorUp', 0, 'm_screen->indexUp();', '// RI,适配器 0x7cc4a0')
b('scrollNextLine', 0, 'm_screen->nextLine();', '// NEL,适配器 0x7cc4c2')
b('setTopBottomMargins', 0, 'm_screen->setTopBottomMargins(-1, -1);')
b('setTopBottomMargins', 1, 'm_screen->setTopBottomMargins(top, -1);')
b('setTopBottomMargins', 2, 'm_screen->setTopBottomMargins(top, bottom);')
b('setLeftRightMargins', 0, 'm_screen->setLeftRightMargins(-1, -1);')
b('setLeftRightMargins', 1, 'm_screen->setLeftRightMargins(left, -1);')
b('setLeftRightMargins', 2, 'm_screen->setLeftRightMargins(left, right);')

# --- tabs / save-restore / cursor style ------------------------------------------
b('setHorizontalTabstop', 0, 'm_screen->setTabstop(-1, true);', '// -1 -> 当前列(HTS)')
b('setHorizontalTabstop', 1, 'm_screen->setTabstop(column, true);')
b('clearTabstop', 0, 'm_screen->clearTabstop(0);', '// TBC 0:清除当前列制表位')
b('clearTabstop', 1, 'm_screen->clearTabstop(column);')
b('saveCursor', 0, 'm_screen->saveCursor();', '// DECSC,适配器 0x7cc45c')
b('restoreCursor', 0, 'm_screen->restoreCursor();', '// DECRC,适配器 0x7cc40a')
b('setCursorStyle', 0, 'm_screen->setCursorStyle(1, false);', '// DECSCUSR,缺省参 1')
b('setCursorStyle', 1, 'm_screen->setCursorStyle(style, false);')
b('setCursorVisibility', 0, 'm_screen->setCursorVisibility(1);', '// DECTCEM,缺省参 1')
b('setCursorVisibility', 1, 'm_screen->setCursorVisibility(visible ? 1 : 0);')

decls_raw = re.findall(r'\tvoid (\w+)\(([^)]*)\);', hdr)
seen, bodies, real, unresolved = set(), [], 0, 0
FALLBACKS = []

# --- batch 2: DEC modes / charset / SGR / insert-delete ---------------------
b('allowScrollback', 0, 'm_screen->isScrollbackAllowed();', '// 取值函数,槽调用丢弃返回值')
b('bracketedPasteMode', 0, 'm_screen->isBracketedPaste();', '// 取值函数(DEC 2004 标志)')
b('checkControlCharacter', 0, 'm_checkControlChars = true;', '// 适配器 0x7cadda 直写 Commander+0x101,不经 Screen')
for nm in ('insertCharacter', 'deleteCharacter', 'insertLine', 'deleteLine', 'insertColumn', 'deleteColumn'):
    b(nm, 0, 'm_screen->%s(1);' % nm, '// 缺省参 1,守卫在实现内')
    b(nm, 1, 'm_screen->%s(count);' % nm, '// 守卫在 core 实现内')
b('repeatCharacter', 0, 'm_screen->repeatCharacter(1);')
b('repeatCharacter', 1, 'm_screen->repeatCharacter(count);')
b('setMode', 0, 'm_screen->setMode(QString(), true);')
b('setMode', 1, 'm_screen->setMode(QString::number(mode), true);')
b('resetMode', 0, 'm_screen->setMode(QString(), false);')
b('resetMode', 1, 'm_screen->setMode(QString::number(mode), false);')
b('setDecMode', 0, 'm_screen->setDecMode(QString(), true);')
b('setDecMode', 1, 'm_screen->setDecMode(QString::number(mode), true);', '// 适配器 0x7c8d4c:FUN_007f5d2e(screen, mode, 1)')
b('resetDecMode', 1, 'm_screen->setDecMode(QString::number(mode), false);', '// 适配器 0x7c8d3e')
b('saveDecMode', 1, 'm_screen->saveDecMode(QString::number(mode));', '// 适配器 0x7c8d8a')
b('restoreDecMode', 1, 'm_screen->restoreDecMode(QString::number(mode));', '// 适配器 0x7c8d7e')
b('selectCharacterAttribute', 0, 'm_screen->selectCharacterAttribute(0);')
b('selectCharacterAttribute', 1, 'm_screen->selectCharacterAttribute(attribute);')
b('selectGraphicRendition', 0, 'm_screen->selectGraphicRendition(QString());')
b('selectGraphicRendition', 1, 'm_screen->selectGraphicRendition(QString::number(rendition));', '// 适配器 0x7c8de6 -> 0x7ef95c(SGR 位域状态机)')
b('selectAttributeChangeExtent', 0, 'm_screen->selectAttributeChangeExtent();')
b('selectAttributeChangeExtent', 1, 'm_screen->selectAttributeChangeExtent();', '// 实现忽略 extent 参(适配器 0x7cc530)')
b('reverseScreen', 0, 'm_screen->isReverseScreen();', '// 取值函数(DECSCNM 标志)')
b('select94CharacterSet', 2, 'm_screen->select94CharacterSet(count, graphic);', '// SCS:count 为槽字符,G0..G3')
b('select96CharacterSet', 2, 'm_screen->select96CharacterSet(count, graphic);', '// SCS:G1..G3 96 集')
b('assignUserPreferredSupplementalSet', 2, 'm_screen->assignUserPreferredSupplementalSet(set, type);')
b('shiftSingleTwo', 0, 'm_screen->shiftSingle(2);', '// 适配器 0x7cd0c8')
b('shiftSingleThree', 0, 'm_screen->shiftSingle(3);', '// 适配器 0x7cd0da')
b('shiftLockingZero', 0, 'm_screen->shiftLocking(true, 0);', '// 适配器 0x7cd0b4:FUN_007e521c(p,1,0)')
b('shiftLockingOne', 0, 'm_screen->shiftLocking(true, 1);', '// 0x7cd036')
b('shiftLockingOneRight', 0, 'm_screen->shiftLocking(false, 1);', '// 0x7cd04c')
b('shiftLockingTwo', 0, 'm_screen->shiftLocking(true, 2);', '// 0x7cd060')
b('shiftLockingTwoRight', 0, 'm_screen->shiftLocking(false, 2);', '// 0x7cd076')
b('shiftLockingThree', 0, 'm_screen->shiftLocking(true, 3);', '// 0x7cd08a')
b('shiftLockingThreeRight', 0, 'm_screen->shiftLocking(false, 3);', '// 0x7cd0a0')
b('singleLineWidth', 0, 'm_screen->setLineDoubleWidth(false);', '// DECSWL,适配器 0x7cd0ec')
b('doubleLineWidth', 0, 'm_screen->setLineDoubleWidth(true);', '// DECDWL')
b('doubleLineHeightTop', 0, 'm_screen->setLineDoubleHeightTop(true);', '// DECDHL 顶半行')
b('doubleLineHeightBottom', 0, 'm_screen->setLineDoubleHeightBottom(true);', '// DECDHL 底半行')
b('setAnsiConformanceLevelOne', 0, 'm_screen->setAnsiConformanceLevel(1);')
b('setAnsiConformanceLevelTwo', 0, 'm_screen->setAnsiConformanceLevel(2);')
b('setAnsiConformanceLevelThree', 0, 'm_screen->setAnsiConformanceLevel(3);')
b('setConformanceLevel', 0, 'm_screen->setConformanceLevel(0, 0);')
b('setConformanceLevel', 1, 'm_screen->setConformanceLevel(level, 0);')
b('setConformanceLevel', 2, 'm_screen->setConformanceLevel(level, type);')
b('select7BitC1Control', 0, 'm_screen->select7BitC1Control(false);', '// 适配器 0x7cc4e4 传 0')
b('select8BitC1Control', 0, 'm_screen->select7BitC1Control(true);', '// 适配器 0x7cc4f2 传 1(共用实现)')
b('exitAnsiMode', 0, 'm_screen->exitAnsiMode();', '// 进入 VT52(FUN_007e87c8(p,0))')
b('enterAltKeypadMode', 0, 'm_screen->enterAltKeypadMode();')
b('exitAltKeypadMode', 0, 'm_screen->exitAltKeypadMode();')
b('setKeyModifier', 0, 'm_screen->setKeyModifier();')
b('setKeyModifier', 1, 'm_screen->setKeyModifier();', '// 实现忽略参数(适配器 0x7cc872)')
b('resetKeyModifier', 0, 'm_screen->resetKeyModifier();')
b('resetKeyModifier', 1, 'm_screen->resetKeyModifier();')
b('selectLocatorEvents', 1, 'm_screen->selectLocatorEvents(events);')
b('startGuardedArea', 0, 'm_screen->startGuardedArea();')
b('endGuardedArea', 0, 'm_screen->endGuardedArea();')


# --- batch 3a: VT52 / zmodem / reports / alignment -------------------------
b('vt52Mode', 0, 'm_screen->isVt52Mode();', '// 取值函数(+0x124),槽调用丢弃返回值')
b('vt52Identify', 0, 'm_screen->vt52Identify();', '// 应答 ESC / Z')
b('vt52EnterGraphicsMode', 0, 'm_screen->vt52EnterGraphicsMode();')
b('vt52ExitGraphicsMode', 0, 'm_screen->vt52ExitGraphicsMode();')
b('zmodemSend', 0, 'm_screen->zmodemSend();', '// notifyView(2,1)')
b('zmodemReceive', 0, 'm_screen->zmodemReceive();', '// QTimer 状态机编排')
b('refreshScreen', 0, 'm_screen->refreshNeeded();', '// 视图标志位取反,FUN_0061324e')
b('adjustScreenAlignment', 0, 'm_screen->adjustScreenAlignment();', '// DECALN:全屏填 E')
b('reportDeviceAttributesOne', 0, 'm_screen->reportDeviceAttributes(0);', '// DA1,容器首元素')
b('reportDeviceAttributesTwo', 0, 'm_screen->reportDeviceAttributes(1);', '// DA2')
b('reportDeviceAttributesThree', 0, 'm_screen->reportDeviceAttributes(2);', '// DA3')
b('reportDeviceStatus', 1, 'm_screen->reportDeviceStatus(status);', '// DSR 应答装配')


# --- batch 3b: notify / window / reports -----------------------------------
b('notifyCommand', 1, 'm_screen->notifyCommand(command);', '// 适配器经 qstrcmp PLT(0x4c3110),非 Screen 逻辑')
b('notifyFig', 1, 'm_screen->notifyOsc(0, content);', '// 与 notifyHyperlink/Iterm2 同指 0x4c3290(split PLT)')
b('notifyHyperlink', 1, 'm_screen->notifyOsc(8, content);')
b('notifyIterm2', 1, 'm_screen->notifyOsc(1337, content);')
b('notifyMessage', 1, 'm_screen->notifyMessageEx(message, 0, 0);', '// 单参变体')
b('notifyMessage', 2, 'm_screen->notifyMessageEx(message, type, 0);')
b('notifyRemoteDirectory', 1, 'm_screen->setWindowTitleBuffer(dir);', '// 同 setWindowTitle 路径(0x7cd366)')
b('windowTitle', 0, 'm_screen->setWindowTitleBuffer(QString());', '// 适配器 0x4c29d0 为 PLT 桩')
b('windowIcon', 0, '// PLT 桩(0x4c29d0),实际逻辑在适配器内联')
b('toUnicode', 1, 'm_screen->codecToUnicode(data);', '// 0x4c29d0 PLT;编码转换在调用方')
b('fromUnicode', 1, 'm_screen->codecFromUnicode(text);')
b('setWindowIcon', 1, 'm_screen->setWindowTitleBuffer(icon);', '// 同 0x7cd366 锁缓冲路径')
b('setWindowTitle', 1, 'm_screen->setWindowTitleBuffer(title);')
b('setWindowIconAndTitle', 1, 'm_screen->setWindowIconAndTitle(iconAndTitle);', '// 0x7cd902:+0x118 缓冲交换+视图通知')
b('requestMode', 1, 'm_screen->requestMode(mode);', '// DECRQM;未知模式上报不支持')
b('requestDisplayedExtent', 0, 'm_screen->requestDisplayedExtent();', '// 应答 "%d;%d;1;1;1\"w"')
b('requestKeyModifier', 1, 'm_screen->requestKeyModifier(modifier);', '// 应答 ESC[>%d;%dm')
b('requestTerminalStateReport', 0, 'm_screen->requestTerminalStateReport();')
b('requestTerminalStateReport', 1, 'm_screen->requestTerminalStateReport();')
b('requestLocatorPosition', 1, 'm_screen->requestLocatorPosition(mode);')
b('requestUserPreferredSupplementalSet', 0, 'm_screen->requestUserPreferredSupplementalSet();')
b('requestWindowSelections', 0, 'm_screen->requestWindowSelections();')
b('requestXtermTerminfoData', 1, 'm_screen->requestXtermTerminfoData(name);')
b('requestChecksumOfRectangularArea', 1, 'm_screen->requestChecksumOfRectangularArea(area);')
b('requestSelectionOrSetting', 0, 'm_screen->requestSelectionOrSetting();')
b('requestPresentationStateReport', 0, 'm_screen->requestPresentationStateReport();')
b('reportTerminalParameters', 0, 'm_screen->reportTerminalParameters();')
b('reportTerminalParameters', 1, 'm_screen->reportTerminalParameters();')
b('reportDecDeviceStatus', 1, 'm_screen->reportDecDeviceStatus(mode);')
b('setAllowScrollback', 1, 'm_screen->setAllowScrollback(allowed == QStringLiteral("1"));', '// 补录:此前注入失败')
b('selectLocatorEvents', 1, 'm_screen->selectLocatorEvents(events);', '// 补录')
b('eraseRectangularArea', 1, 'm_screen->eraseRectangularArea(area, false);', '// 补录')
b('setKeyModifier', 1, 'm_screen->setKeyModifier();')


# --- batch 3c: pages / UDK / geometry ---------------------------------------
b('page', 0, 'm_screen->currentPage();', '// 取值函数(0x7e48f8),槽调用丢弃返回值')
b('pages', 0, '// 取值函数(0x7e4900 总页数),槽调用丢弃返回值')
b('movePagePositionAbsolute', 0, 'm_screen->movePage(0, false);', '// 缺省参 0')
b('movePagePositionAbsolute', 1, 'if (page < 0)', '\treturn;', 'm_screen->movePage(page, false);')
b('movePagePositionBackward', 0, 'm_screen->movePage(m_screen->currentPage() - 1, false);')
b('movePagePositionBackward', 1, 'if (pages < 0)', '\treturn;', 'm_screen->movePage(m_screen->currentPage() - pages, false);')
b('movePagePositionRelative', 0, 'm_screen->movePage(m_screen->currentPage() + 1, false);')
b('movePagePositionRelative', 1, 'if (pages < 0)', '\treturn;', 'm_screen->movePage(m_screen->currentPage() + pages, false);')
b('nextPage', 0, 'm_screen->movePage(m_screen->currentPage() + 1, true);', '// 适配器 0x7cc0ce:n<1 取 1,回原点')
b('nextPage', 1, 'if (pages < 0)', '\treturn;', 'if (pages < 1)', '\tpages = 1;', 'm_screen->movePage(m_screen->currentPage() + pages, true);')
b('precedingPage', 0, 'm_screen->movePage(m_screen->currentPage() - 1, true);', '// 适配器 0x7cc112:n<1 取 1,回原点')
b('precedingPage', 1, 'if (pages < 0)', '\treturn;', 'if (pages < 1)', '\tpages = 1;', 'm_screen->movePage(m_screen->currentPage() - pages, true);')
for i, nm in ((225, 'setUserDefinedKeys'), (216, 'setLinesPerPage'), (198, 'setColumnsPerPage')):
    pass
b('setUserDefinedKeys', 0, 'm_screen->setUserDefinedKeys();', '// DECDLD')
b('setUserDefinedKeys', 1, 'm_screen->setUserDefinedKeys();')
b('setUserDefinedKeys', 2, 'm_screen->setUserDefinedKeys();')
b('setUserDefinedKeys', 3, 'm_screen->setUserDefinedKeys();')
b('setUserDefinedKeys', 4, 'm_screen->setUserDefinedKeys();', '// 五重载共用 0x7ef0e8')
b('setLinesPerPage', 0, 'm_screen->setLinesPerPage(0);', '// 缺省参 0')
b('setLinesPerPage', 1, 'm_screen->setLinesPerPage(lines);')
b('setColumnsPerPage', 0, 'm_screen->setColumnsPerPage(0);')
b('setColumnsPerPage', 1, 'm_screen->setColumnsPerPage(columns);')
b('selectStatusLineType', 0, 'm_screen->selectStatusLineType(0);')
b('selectStatusLineType', 1, 'm_screen->selectStatusLineType(type);')
b('selectActiveStatusDisplay', 0, 'm_screen->selectActiveStatusDisplay(0);')
b('selectActiveStatusDisplay', 1, 'm_screen->selectActiveStatusDisplay(display);')
b('selectNumberOfLinesOnScreen', 1, 'm_screen->selectNumberOfLinesOnScreen(lines);', '// DECSNLS')
b('resetSoft', 0, 'm_screen->resetSoft();', '// DECSTR')
b('resetHard', 0, 'm_screen->resetHard();', '// RIS 全复位')
b('restorePresentationState', 0, 'm_screen->restorePresentationState();')
b('restorePresentationState', 1, 'm_screen->restorePresentationState();')

decls = decls_raw
for name, params in decls:
    argc = 0 if params.strip() in ('', 'void') else len(params.split(','))
    if (name, argc) in seen or name in SIGNALS:
        continue
    seen.add((name, argc))
    # find moc idx for citation
    cands = by_name.get(name) or []
    idx = None
    for i, s in enumerate(sigs):
        if s['name'] == name and len(s['types']) == argc:
            idx = i
            break
    if idx is not None and cands:
        tgt = next((c['target'] for c in cands if c['idx'] == idx), cands[0]['target'])
        cite = '\t// moc[%d] -> %s\n' % (idx, tgt) if tgt else '\t// moc[%d]\n' % idx
    else:
        cite = ''
    key = (name, argc)
    if key in B:
        real += 1
        body = cite + ''.join('\t%s\n' % l for l in B[key])
    else:
        # T1 fallback: forward to Screen with the slot's own param names
        tgt = next((c['target'] for c in by_name.get(name, []) if c['target']), None)
        if tgt == '0x4bc0d0' or params == '':
            real += 1
            body = cite + '\t// PLT 桩(%s),实际逻辑在适配器内联\n' % (tgt or '-')
            FALLBACKS.append((name, argc, None))
        else:
            names = [p.strip().split()[-1] for p in params.split(',')]
            real += 1
            body = cite + '\tm_screen->%s(%s);\n' % (name, ', '.join(names))
            FALLBACKS.append((name, argc, names))
    bodies.append('void SuperCommander::%s(%s)\n{\n%s}\n' % (name, params, body))

cpp = '''#include "SuperCommander.h"
#include "Screen.h"

// 第一/二批转写:光标/擦除/滚动族 + DEC 模式/字符集/SGR/插入删除族(%d 个真实现体)。
// 三层洋葱:this -> m_screen(+0x80, 0x7e 层) -> TerminalCore(0x7a 层)。
// 每体注明 moc 索引与实现地址;其余槽为后续批次占位。
// 信号 5 个由 moc 生成不定义。phase-1 参考还原,不编译。

SuperCommander::SuperCommander(QObject *parent)
	: QObject(parent), m_screen(nullptr)
{
}

''' % real + '\n'.join(bodies)
open('src/Sessions/SuperCommander.cpp', 'w').write(cpp)
print('bodies: %d total, %d real, %d pending' % (len(bodies), real, unresolved))
