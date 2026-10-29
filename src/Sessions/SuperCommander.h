#ifndef SUPERCOMMANDER_H
#define SUPERCOMMANDER_H

#pragma once

#include <QObject>
#include "../Utility/KingEnums.h"

class Screen;

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// The terminal command interpreter: the full VT/ANSI/DEC escape-sequence
// command surface (260+ entries, overloads collapsed where the moc table
// lists parameterless/parametered variants of the same command).
// Base class of Ssh/Shell/Telnet/Tcp/Serial commanders.
class SuperCommander : public QObject
{
	Q_OBJECT

public:
	SuperCommander(QObject *parent = nullptr);
	virtual ~SuperCommander(void) = default;

	// +0x80: the VT screen (onion: this -> Screen(+0x80) -> TerminalCore)
	QByteArray processOutput(const QByteArray &data);  // SuperCommander_vt14(007d1348)
	void writeSplitData(const char *data, int len);    // 007d1f5a(解析链入口)
	Screen *m_screen;

	// 动作 FIFO 队列(批 21 pending-v3;probe15 实锤:E5 字面先行/
	// 动作后至、E4 字节序 FIFO、tbc_all 88 需 3g 先于 \t)。队列项 =
	// 原始序列字节,flush 时经 writeSplitData 重放(m_replaying 门)。
	// m_seqTail = +0xd8 挂起尾(007d1f5a 1647;probe15 E7:partial
	// 序列如 ESC[1;88T 整段入尾,本批不执行,下批入口前拼)。
	void flushPendingActions();
	QVector<QByteArray> m_pendingActions;
	QVector<QByteArray> m_escPending;   // ESC D/E/M 专队列:下次入口 flush
	QByteArray m_seqTail;
	bool m_replaying = false;
	void execCsi(const QString &params, char finalByte, bool priv);
	void execEsc(char e1);

protected:
	bool m_checkControlChars;   // +0x101 (adapter 0x7cadda writes it directly)

signals:
	void charsetChanged(const QString &name);
	void shellCwdChanged(const QString &info);
	void asyncMessage(int type, int wParam, int lParam);
	void syncMessage(int type, int commanderMessage, int wParam, int lParam);
	void error(const QString &context, int code);

public slots:
	// VT52 mode
	void vt52Mode();
	void vt52Identify();
	void vt52EnterGraphicsMode();
	void vt52ExitGraphicsMode();
	void vt52MoveCursor(int column, int line);

	// Cursor movement
	void moveCursor();
	void moveCursor(int position);
	void moveCursor(int column, int line);
	void moveCursorColumn();
	void moveCursorColumn(int column);
	void moveCursorColumnRelative();
	void moveCursorColumnRelative(int columns);
	void moveCursorColumnBackward();
	void moveCursorColumnBackward(int columns);
	void moveCursorForward(int columns);
	void moveCursorBackward();
	void moveCursorBackward(int columns);
	void moveCursorUp();
	void moveCursorUp(int lines);
	void moveCursorDown();
	void moveCursorDown(int lines);
	void moveCursorLine();
	void moveCursorLine(int line);
	void moveCursorLineRelative();
	void moveCursorLineRelative(int lines);
	void moveCursorLineBackward();
	void moveCursorLineBackward(int lines);
	void moveCursorNextLine();
	void moveCursorNextLine(int lines);
	void moveCursorPrecedingLine();
	void moveCursorPrecedingLine(int lines);
	void moveCursorNextTabstop();
	void moveCursorNextTabstop(int count);
	void moveCursorPrecedingTabstop();
	void moveCursorPrecedingTabstop(int count);

	// Character/line operations
	void backspace();
	void carriageReturn();
	void lineFeed();
	void formFeed();
	void verticalTab();
	void horizontalTab();
	void bell();
	void repeatCharacter();
	void repeatCharacter(int count);
	void insertCharacter();
	void insertCharacter(int count);
	void deleteCharacter();
	void deleteCharacter(int count);
	void eraseCharacter();
	void eraseCharacter(int count);
	void insertLine();
	void insertLine(int count);
	void deleteLine();
	void deleteLine(int count);
	void insertColumn();
	void insertColumn(int count);
	void deleteColumn();
	void deleteColumn(int count);

	// Erasing
	void eraseLine();
	void eraseLine(int mode);
	void eraseScreen();
	void eraseScreen(int mode);
	void eraseSelectiveLine();
	void eraseSelectiveLine(int mode);
	void eraseSelectiveScreen();
	void eraseSelectiveScreen(int mode);
	void eraseRectangularArea(const QString &area);
	void selectiveEraseRectangularArea(const QString &area);

	// Scrolling
	void scrollUp();
	void scrollUp(int lines);
	void scrollDown();
	void scrollDown(int lines);
	void scrollLeft();
	void scrollLeft(int columns);
	void scrollRight();
	void scrollRight(int columns);
	void scrollCursorUp();
	void scrollCursorDown();
	void scrollNextLine();
	void nextPage();
	void nextPage(int pages);
	void precedingPage();
	void precedingPage(int pages);
	void page();
	void pages();

	// Indexing
	void forwardIndex();
	void backIndex();

	// Margins
	void marginTop();
	void marginBottom();
	void marginLeft();
	void marginRight();
	void setTopBottomMargins();
	void setTopBottomMargins(int top);
	void setTopBottomMargins(int top, int bottom);
	void setLeftRightMargins();
	void setLeftRightMargins(int left);
	void setLeftRightMargins(int left, int right);

	// Tabstops
	void setHorizontalTabstop();
	void setHorizontalTabstop(int column);
	void clearTabstop();
	void clearTabstop(int column);
	void saveCursor();
	void restoreCursor();

	// Modes (ANSI)
	void setMode();
	void setMode(int mode);
	void resetMode();
	void resetMode(int mode);
	void requestMode(int mode);

	// Modes (DEC private)
	void setDecMode();
	void setDecMode(int mode);
	void resetDecMode(int mode);
	void saveDecMode(int mode);
	void restoreDecMode(int mode);
	void requestDecMode(int mode);

	// Attributes / rendition
	void selectCharacterAttribute();
	void selectCharacterAttribute(int attribute);
	void selectGraphicRendition();
	void selectGraphicRendition(int rendition);
	void selectAttributeChangeExtent();
	void selectAttributeChangeExtent(int extent);
	void reverseScreen();
	void changeAttributesInRectangularArea(const QString &area);
	void reverseAttributesInRectangularArea(const QString &area);
	void copyRectangularArea(const QString &area);
	void fillRectangularArea(const QString &fill);
	void fillRectangularArea(const QString &fill, const QString &area);

	// Rectangular area
	void eraseRectangularArea(const QString &area, int mode);
	void requestChecksumOfRectangularArea(const QString &area, int pid);

	// Character sets
	void select94CharacterSet(int count, int graphic);
	void select96CharacterSet(int count, int graphic);
	void shiftSingleTwo();
	void shiftSingleThree();
	void shiftLockingZero();
	void shiftLockingOne();
	void shiftLockingOneRight();
	void shiftLockingTwo();
	void shiftLockingTwoRight();
	void shiftLockingThree();
	void shiftLockingThreeRight();
	void assignUserPreferredSupplementalSet(int set, int type);

	// Line size / width
	void singleLineWidth();
	void doubleLineWidth();
	void doubleLineHeightTop();
	void doubleLineHeightBottom();

	// Conformance / C1 controls
	void setAnsiConformanceLevelOne();
	void setAnsiConformanceLevelTwo();
	void setAnsiConformanceLevelThree();
	void setConformanceLevel();
	void setConformanceLevel(int level);
	void setConformanceLevel(int level, int type);
	void select7BitC1Control();
	void select8BitC1Control();
	void exitAnsiMode();

	// Keypad
	void enterAltKeypadMode();
	void exitAltKeypadMode();

	// Screen / pages
	void refreshScreen();
	void setColumnsPerPage();
	void setColumnsPerPage(int columns);
	void setLinesPerPage();
	void setLinesPerPage(int lines);
	void selectNumberOfLinesOnScreen(int lines);
	void setCursorStyle();
	void setCursorStyle(int style);
	void setCursorVisibility();
	void setCursorVisibility(bool visible);
	void adjustScreenAlignment();
	void allowScrollback();
	void setAllowScrollback(const QString &allowed);
	void originTop();
	void originBottom();
	void originLeft();
	void originRight();
	void movePagePositionAbsolute();
	void movePagePositionAbsolute(int page);
	void movePagePositionBackward();
	void movePagePositionBackward(int pages);
	void movePagePositionRelative();
	void movePagePositionRelative(int pages);
	void setMarginBellVolume();
	void setMarginBellVolume(int volume);
	void setWarningBellVolume();
	void setWarningBellVolume(int volume);

	// Status line
	void selectStatusLineType();
	void selectStatusLineType(int type);
	void selectActiveStatusDisplay();
	void selectActiveStatusDisplay(int display);

	// Reports
	void reportDeviceAttributesOne();
	void reportDeviceAttributesTwo();
	void reportDeviceAttributesThree();
	void reportDeviceStatus(const QString &status);
	void reportDecDeviceStatus(const QString &status);
	void reportTerminalParameters();
	void reportTerminalParameters(int mode);
	void requestTerminalStateReport();
	void requestTerminalStateReport(int mode);
	void requestPresentationStateReport(int state);
	void requestUserPreferredSupplementalSet();
	void requestDisplayedExtent();
	void requestWindowSelections(const QString &which);
	void setWindowSelections(const QString &which, const QString &selections);
	void requestXtermTerminfoData(const QString &name);
	void setXtermTerminfoData(const QString &name);
	void requestKeyModifier();
	void requestKeyModifier(int modifier);
	void setKeyModifier();
	void setKeyModifier(int modifier);
	void setKeyModifier(int modifier, int type);
	void resetKeyModifier();
	void resetKeyModifier(int modifier);

	// Locator (DEC Locator Mode)
	void enableLocatorReports();
	void enableLocatorReports(int unit);
	void enableLocatorReports(int unit, int mode);
	void filterRectangle(int top, int left, int bottom, int right);
	void requestLocatorPosition();
	void requestLocatorPosition(int mode);
	void selectLocatorEvents(const QString &events);
	void highlightTracking(int mode, const QString &spec);
	void enableFilterRectangle(const QString &filter);

	// Window title / icon / colors
	void setWindowTitle(const QString &title);
	void windowTitle();
	void setWindowIcon(const QString &icon);
	void windowIcon();
	void setWindowIconAndTitle(const QString &iconAndTitle);
	void setWindowColor(int index, const QString &color);
	void setWindowColor(int index, const QString &color, int type);
	void resetWindowColor();
	void resetWindowColor(int index);
	void setWindowAttributes(const QString &attributes);
	void windowColumns();
	void windowRows();

	// Guarded areas
	void startGuardedArea();
	void endGuardedArea();

	// Media copy (printing)
	void mediaCopy();
	void mediaCopy(int mode);
	void mediaCopyDec(int mode);

	// Charset conversion
	void setCodec(const QString &name);
	void toUnicode(const QString &text);
	void fromUnicode(const QString &text);

	// Notifications
	void notifyCommand(const QString &command);
	void notifyMessage(int message);
	void notifyMessage(int message, int type);
	void notifyRemoteDirectory(const QString &directory);
	void notifyHyperlink(const QString &url);
	void notifyIterm2(const QString &content);
	void notifyFig(const QString &content);
	void option(const QString &name);

	// Check control character / misc
	void checkControlCharacter();
	void dataType();
	void testConfidence(const QString &data);
	void setUserDefinedKeys();
	void setUserDefinedKeys(int key);
	void setUserDefinedKeys(int key, int clear);
	void setUserDefinedKeys(int key, int clear, int modifier);
	// setUserDefinedKeys(int, int) 重复重载已合并(五槽同指 0x7ef0e8)
	void loadLeds();
	void loadLeds(const QString &leds);

	// tmux / ZModem integration
	void enterTmuxControlMode();
	void zmodemSend();
	void zmodemReceive();

	// Paste
	void bracketedPasteMode();
};

#endif // SUPERCOMMANDER_H
