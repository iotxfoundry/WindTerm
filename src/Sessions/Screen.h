#ifndef SCREEN_H
#define SCREEN_H

#pragma once

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// The VT screen object: SuperCommander's +0x80 target (the middle layer
// of the Commander -> Screen -> TerminalCore onion). Holds mode flags and
// the scrollback machinery; forwards buffer work to TerminalCore (+0x80).
// Batch 1: cursor movement, erase, scroll, tabs, margins, DECSC/DECRC.

#include "TerminalCore.h"

class QString;

class Screen
{
public:
	Screen();

	// --- object layout (offsets observed in the 0x7e functions) ----------
	void *m_viewSettings;           // +0x10 (scrollback limit at +0x104)
	TerminalCore *m_core;           // +0x80 visible screen core
	TerminalCore *m_history;        // +0x88 scrollback/history buffer
	void *m_scrollView;             // +0x98 scrollback view
	int m_savedCursorStyle;         // +0xa8 (-1 = none)
	unsigned short m_eraseAttr;     // +0x110 current SGR erase attribute
	bool m_leftRightMarginEnabled;  // +0x11a (DECLRMM)
	bool m_scrollbackEnabled;       // +0x11c
	bool m_eraseProtectedMode;      // +0x129 (DECSCA-protected erase skip)
	bool m_newlineMode;             // +0x12f (LNM)
	bool m_reverseWraparound;       // +0x134 (reverse wrap for backspace)

	// --- position & bounds (aliases into the core) ------------------------
	int currentColumn() const;         // FUN_007e368e (core +0xc8)
	int currentLine() const;           // FUN_007e369c (core +0xc4)
	int marginBottom() const;          // FUN_007e4426 -> FUN_007a4bb4
	int marginLeft() const;            // FUN_007e443e -> FUN_007a493c
	int marginRight() const;           // FUN_007e444a -> FUN_007a490e
	int marginTop() const;             // FUN_007e4456 -> FUN_007a4be2
	int originBottom() const;          // FUN_007e48b0 -> FUN_007a5304
	int originLeft() const;            // FUN_007e48c8 -> FUN_007a4962
	int originRight() const;           // FUN_007e48d4 -> FUN_007a49c6
	int originTop() const;             // FUN_007e48e0 -> FUN_007a4c08
	int windowColumns() const;         // FUN_007e5b96 -> FUN_007a4906
	int rowCount() const;              // FUN_007e5f18 -> FUN_007a4b4a

	// --- cursor commands ----------------------------------------------------
	void cursorMoveRaw(int y, int x);  // FUN_007e4f38 -> FUN_007a538a
	void moveCursor(int y, int x);     // FUN_007e4fdc -> FUN_007a54f8
	void moveCursorBackward(int n);    // FUN_007e4832 -> cursorBackward
	void moveCursorDown(int n);        // FUN_007e483e -> cursorDown
	void moveCursorForward(int n);     // FUN_007e484a -> cursorForward
	void moveCursorUp(int n);          // FUN_007e4856 -> cursorUp
	void carriageReturn();             // FUN_007e4fc8
	void backspace();                  // FUN_007e4f44
	void lineFeed();                   // FUN_007e55fc
	void horizontalTab();              // FUN_007e5d7c
	void backIndex();                  // FUN_007e4d48 (DECBI)
	void forwardIndex();               // FUN_007e4d82 (DECFI)
	void saveCursor();                 // FUN_007e4aa2 -> core DECSC
	void restoreCursor();              // FUN_007f6426 (DECRC + fallback)
	void setCursorStyle(int style, bool save);   // FUN_007e4ffa (DECSCUSR)
	void setCursorVisibility(int mode);          // FUN_007e5090 (DECTCEM)

	// --- tabs -----------------------------------------------------------------
	int nextTabstop(int from, int count) const;  // FUN_007e5d1e
	int prevTabstop(int from, int count) const;  // FUN_007e5ce4
	bool isTabstop(int column) const;            // FUN_007e5c98
	void setTabstop(int column, bool on);        // FUN_007e52fc (HTS)
	void clearTabstop(int mode);                 // FUN_007e5df0 (TBC)

	// --- scroll -----------------------------------------------------------------
	void indexDown();                  // FUN_007e55b6 (IND)
	void indexUp();                    // FUN_007e563e (RI)
	void nextLine();                   // FUN_007e562c (NEL)
	void scroll(int count, bool down, bool fillTemplate);  // FUN_007e5546
	void scrollHorizontal(int delta);  // FUN_007e4d3c -> FUN_007a68ae

	// --- erase -----------------------------------------------------------------
	void eraseCells(int line, int from, int count, bool selective);  // FUN_007e37f8
	void eraseCharacter(int count);    // FUN_007e385a (ECH)
	int eraseLine(int line, int mode, bool selective);  // FUN_007e4ba2 (EL)
	int eraseScreen(int mode, bool selective);          // FUN_007e606a (ED)

	// --- rectangular areas (DECERA/DECFRA/DECRARA/DECCRA) -----------------------
	void eraseRectangularArea(const QString &area, bool selective);  // FUN_007eb1c4
	void fillRectangularArea(const QString &fill);                   // FUN_007eb20a (DECFRA)
	void copyRectangularArea(const QString &area);                   // FUN_007eb2f2 (DECCRA)
	void changeAttributesInRectangularArea(const QString &area);     // FUN_007eb17e
	void reverseAttributesInRectangularArea(const QString &area);    // FUN_007eb2ac

	// --- margins -------------------------------------------------------------------
	void setTopBottomMargins(int top, int bottom);   // FUN_007e5fa6 (DECSTBM)
	void setLeftRightMargins(int left, int right);   // FUN_007e5bd4 (DECSLRM)

	// --- scrollback ------------------------------------------------------------------
	bool isScrollbackAllowed() const;          // FUN_007e4036
	void pushLinesToScrollback(int count);     // FUN_007e53b6
	void clearScrollback();                    // FUN_0091318c (ED 3)

	// --- mode flags (Screen offsets, set by setDecMode/setMode) ------------
	bool m_keypadNumericMode;      // +0xf0 (DECKPAM/DECKPNM, alt-keypad inverse)
	bool m_cursorKeyMode;          // +0xf1 (DECCKM)
	bool m_altScreenEnabled;       // +0x118 (DEC 1046)
	bool m_leftRightMarginEnabled; // +0x11a (DECLRMM, DEC 69)
	bool m_scrollbackEnabled;      // +0x11c (FUN_007e4f1c)
	bool m_nrcMode;                // +0x11b (DECNRCM, DEC 42)
	bool m_guardedArea;            // +0x121 (DECSACE start/end)
	bool m_1046Flag;               // +0x122 (set with DECCOLM path)
	bool m_bracketedPaste;         // +0x120 (DEC 2004, FUN_007e355a)
	bool m_reverseWraparound2;     // +0x134 note: shared with reverse wrap (DEC 45)
	bool m_smoothScrollInv;        // +0x136 (DEC 4, inverted)
	bool m_c1Control8Bit;          // +0x137 (DEC 7/8-bit C1)
	bool m_reverseScreenMode;      // +0x133 (DECSCNM, getter FUN_007e4a94)
	bool m_eraseModeFlag;          // +0x129 (ANSI SM/RM 6, read by eraseCells)
	bool m_insertMode;             // +0x12a (IRM, ANSI 4)
	bool m_kamMode;                // +0x12b (ANSI 2)
	bool m_srmModeInv;             // +0x12c (ANSI 12, inverted)
	bool m_autoRepeatKeys;         // +0x119 (DEC 8)
	bool m_colModeAllowed;         // +0x11d (DEC 40)
	bool m_focusedReport;          // +0x142 (DEC 1004)
	bool m_mouseUtf8;              // +0x145 (DEC 1005)
	bool m_mouseSgr;               // +0x144 (DEC 1006)
	bool m_mouseAltScroll;         // +0x141 (DEC 1007)
	bool m_mouseUrxvt;             // +0x143 (DEC 1015)
	bool m_mouseX10;               // +0x146 (DEC 9)
	bool m_mouseNormal;            // +0x14a (DEC 1000)
	bool m_mouseHighlight;         // +0x149 (DEC 1001)
	bool m_mouseButton;            // +0x148 (DEC 1002)
	bool m_mouseAny;               // +0x147 (DEC 1003)
	bool m_printFormFeedInv;       // +0x132 (DEC 18, inverted)
	bool m_printExtentInv;         // +0x131 (DEC 19, inverted)
	bool m_lastGraphicChar;        // +0x114 (UCS4, repeatCharacter)
	int  m_palette;                // +0xd0 (color table, FUN_007e3578)
	void *m_keymap;                // +0xf8 (key modifier object)
	char m_locatorEventMode;       // +0x160.. +0x162 (DEC locator events)
	char m_locatorArg;
	TerminalCore *m_altCore;       // +0x88 note: alternate-screen core
	TerminalCore *m_savedPrimary;  // +0x90 (primary core while on alt screen)
	void *m_savedDecModes;         // +0xc0 (saveDecMode container)

	// --- batch 2: DEC/ANSI modes, charset, SGR, insert/delete ----------------
	void setDecMode(const QString &modes, bool on);   // FUN_007f5d2e
	void setMode(const QString &modes, bool on);      // FUN_007edce6 (SM/RM)
	void saveDecMode(const QString &modes);           // FUN_007f427a
	void restoreDecMode(const QString &modes);        // FUN_007f64a6
	void switchToAlternateScreen(bool on, bool saveCursor);  // FUN_007f5b70
	void select7BitC1Control(bool on);                // FUN_007e5aec
	void select94CharacterSet(char slot, const QString &name);   // FUN_007e4dbc
	void select96CharacterSet(char slot, const QString &name);   // FUN_007e4e16
	void assignUserPreferredSupplementalSet(int which, const QString &name);  // FUN_007e4ac2
	void selectGraphicRendition(const QString &params);  // FUN_007ef95c
	void selectCharacterAttribute(int attr);             // FUN_007eebd4
	void setConformanceLevel(int a, int b);              // FUN_007eecc0
	void setAnsiConformanceLevel(int level);             // FUN_007e5b12
	void selectAttributeChangeExtent();                  // FUN_007e4e74
	void insertCharacter(int count);   // FUN_007e3ace -> FUN_007a6782
	void insertColumn(int count);      // FUN_007e3ada -> FUN_007a6822
	void insertLine(int count);        // FUN_007e3ae6 -> FUN_007a5290
	void deleteCharacter(int count);   // FUN_007e3784 -> FUN_007a65d2
	void deleteColumn(int count);      // FUN_007e3790 -> FUN_007a6672
	void deleteLine(int count);        // FUN_007e379c -> FUN_007a5220
	void repeatCharacter(int count);   // FUN_007e7cf6
	void exitAnsiMode();               // FUN_007e88e8 (enter VT52)
	void setLineDoubleWidth(bool on);  // FUN_007e41e4 (DECDWL, row bit3)
	void setLineDoubleHeightTop(bool on);   // FUN_007e4282 (row bit4)
	void setLineDoubleHeightBottom(bool on);// FUN_007e4236 (row bit5)
	void setAllowScrollback(bool on);      // FUN_007e4f1c
	bool isBracketedPaste() const;         // FUN_007e355a
	bool isReverseScreen() const;          // FUN_007e4a94
	void startGuardedArea();               // FUN_007e5278
	void endGuardedArea();                 // FUN_007e37dc
	void enterAltKeypadMode();             // FUN_007e37e8
	void exitAltKeypadMode();              // FUN_007e3896
	void enableLocatorReports(int mode, int arg);  // FUN_007e37a8
	void selectLocatorEvents(const QString &list); // FUN_007e4e80
	void setKeyModifier();                 // FUN_007e5152
	void resetKeyModifier();               // FUN_007e498c
	void shiftLocking(bool right, int n);  // FUN_007e521c
	void shiftSingle(int n);               // FUN_007e5254
	int  paletteColor(int index) const;    // FUN_007e3578

	bool m_vt52Mode;                // +0x124
	int m_pageCount;                // +0xcc
	int m_pageCurrent;              // +0xc8 (FUN_007ef11a)

	// --- batch 3a: VT52 / zmodem / reports / alignment / pages --------------
	bool isVt52Mode() const;                     // FUN_007e5a02 (+0x124)
	void vt52EnterGraphicsMode();                // FUN_007e5a90 (core+0xc0 = 3)
	void vt52ExitGraphicsMode();                 // FUN_007e5ab0 (mirror)
	void vt52Identify();                         // FUN_007edc22 (sends ESC / Z)
	void zmodemSend();                           // FUN_007e6844 -> notify(2,1)
	void zmodemReceive();                        // FUN_007e676c (QTimer FSM)
	bool refreshNeeded() const;                  // FUN_0061324e (view flag)
	void adjustScreenAlignment();                // FUN_007e5f24 (DECALN 'E' grid)
	void reportDeviceAttributes(int index);      // FUN_007ea806
	void reportDeviceStatus(const QString &params); // FUN_007f0ae6
	void movePage(int page, bool homeCursor);    // FUN_007ef16a

	// --- batch 3b: notify / window / reports ------------------------------
	void notifyCommand(const QString &msg);      // via 0x4c3110 (qstrcmp PLT)
	void notifyOsc(int kind, const QString &payload);  // 0x4c3290 (split PLT path)
	void notifyMessageEx(int type, int a, int b); // 0x5444ac refcount path
	void setWindowTitleBuffer(const QString &title);  // FUN_007cd366 (locked +0xe0)
	void setWindowIconAndTitle(const QString &both);  // FUN_007cd902 (swap +0x118)
	void requestMode(int mode);                  // FUN_007f17c2 (DECRQM)
	void requestDisplayedExtent();               // FUN_007ed148 ("w response)
	void requestKeyModifier(int key);            // FUN_007ed282 (ESC [ >k;km)
	void requestTerminalStateReport();           // FUN_007f0434
	void requestLocatorPosition(int mode);       // FUN_007ebd6a
	void requestUserPreferredSupplementalSet();  // FUN_007ed7f6
	void requestWindowSelections();              // 0x4c3220 (QString helper PLT)
	void requestXtermTerminfoData(const QString &data);  // FUN_007f3518
	void requestChecksumOfRectangularArea(const QString &area);  // FUN_007eced6
	void requestSelectionOrSetting();            // FUN_007f194e
	void requestPresentationStateReport();       // FUN_007ed35a
	void reportTerminalParameters();             // FUN_007ecdc2
	void reportDecDeviceStatus(int mode);        // FUN_007f0d7c

	// --- batch 3c: pages / UDK / page geometry ------------------------------
	int currentPage() const { return m_pageCurrent; }  // FUN_007e48f8 (+0xc8)
	void setUserDefinedKeys();                   // FUN_007ef0e8 (DECDLD)
	void setColumnsPerPage(int columns);         // FUN_007e61fa (DECSCPP)
	void setLinesPerPage(int lines);             // FUN_007e5eb2 (DECSLPP)
	void selectStatusLineType(int type);         // FUN_007f0346 (DECSSSL)
	void selectActiveStatusDisplay(int which);   // FUN_007ef86e (DECSASD)
	void selectNumberOfLinesOnScreen(int lines); // FUN_007e5ba2 (DECSNLS)
	void resetSoft();                            // FUN_007ea7e6 (DECSTR)
	void resetHard();                            // FUN_007ea73c (RIS)
	void restorePresentationState();             // FUN_007ef1b6


	// --- batch 3d: T1 forwards auto-generated (impl cited) ---
	void vt52Mode();
	void vt52MoveCursor(int column, int line);	// 0x7e4f38
	void moveCursorColumn();
	void moveCursorColumnRelative();
	void moveCursorColumnBackward();
	void moveCursorLine();
	void moveCursorLineRelative();
	void moveCursorLineBackward();
	void moveCursorNextLine();
	void moveCursorPrecedingLine();
	void moveCursorNextTabstop();
	void moveCursorPrecedingTabstop();
	void formFeed();
	void verticalTab();
	void bell();
	void eraseSelectiveLine();
	void eraseSelectiveScreen();
	void selectiveEraseRectangularArea(const QString &area);	// 0x7eb1c4
	void scrollUp();
	void scrollDown();
	void scrollLeft();
	void scrollRight();
	void scrollCursorUp();
	void scrollCursorDown();
	void scrollNextLine();
	void nextPage();
	void precedingPage();
	void page();
	void pages();
	void setHorizontalTabstop();
	void resetMode();
	void resetDecMode(int mode);	// 0x7f5d2e
	void requestDecMode(int mode);	// 0x7f13a0
	void reverseScreen();
	void shiftSingleTwo();
	void shiftSingleThree();
	void shiftLockingZero();
	void shiftLockingOne();
	void shiftLockingOneRight();
	void shiftLockingTwo();
	void shiftLockingTwoRight();
	void shiftLockingThree();
	void shiftLockingThreeRight();
	void singleLineWidth();
	void doubleLineWidth();
	void doubleLineHeightTop();
	void doubleLineHeightBottom();
	void setAnsiConformanceLevelOne();
	void setAnsiConformanceLevelTwo();
	void setAnsiConformanceLevelThree();
	void select8BitC1Control();
	void refreshScreen();
	void allowScrollback();
	void movePagePositionAbsolute();
	void movePagePositionBackward();
	void movePagePositionRelative();
	void setMarginBellVolume();
	void setWarningBellVolume();
	void reportDeviceAttributesOne();
	void reportDeviceAttributesTwo();
	void reportDeviceAttributesThree();
	void setWindowSelections(const QString &which, const QString &selections);	// 0x4beac0
	void setXtermTerminfoData(const QString &name);	// 0x7f07d8
	void highlightTracking(int mode, int type);	// 0x7eac52
	void enableFilterRectangle(const QString &filter);	// 0x7eb8fe
	void setWindowTitle(const QString &title);	// 0x7cd366
	void windowTitle();
	void setWindowIcon(const QString &icon);	// 0x4c29d0
	void windowIcon();
	void setWindowColor(int index, const QString &color);	// 0x7f24ae
	void resetWindowColor();
	void setWindowAttributes(const QString &attributes);	// 0x7f298e
	void windowRows();
	void mediaCopy();
	void mediaCopyDec(int mode);	// 0x7f063a
	void setCodec(const QString &name);	// -0x3efdef14
	void toUnicode(const QString &text);	// 0x4c29d0
	void fromUnicode(const QString &text);	// 0x4c29d0
	void notifyMessage(int message);	// 0x5444ac
	void notifyRemoteDirectory(const QString &directory);	// 0x7cd366
	void notifyHyperlink(const QString &url);	// 0x4c3290
	void notifyIterm2(const QString &content);	// 0x4c3290
	void notifyFig(const QString &content);	// 0x4c3290
	void option(const QString &name);	// 0x7d5538
	void checkControlCharacter();
	void dataType();
	void testConfidence(const QString &data);	// 0x7f0a5e
	void loadLeds();
	void enterTmuxControlMode();
	void bracketedPasteMode();

	// --- cited helpers (call sites proven, bodies not yet transcribed) ---
	int currentCursorStyle() const;                  // FUN_007e36aa
	void notifyCursorStyle(void *cursor, int shape); // FUN_00913592
	void setCursorVisible(bool on);                  // FUN_007e506a
	bool scrollbackModeCheck() const;                // FUN_007e4028
	void markRowErased(int row);                     // FUN_007e41ca
	void *buildFillAux();                            // FUN_007e4c90
	void parseRect(const QString &area, int *top, int *left, int *bottom, int *right);  // FUN_007eaeee
	QStringList splitParams(const QString &params) const;   // QByteArray::split path
	bool protocolExtCapable() const;      // FUN_007e2c72(+0x58)
	bool protocolAltCapable() const;      // FUN_007e2c6a(+0x58)
	int protocolLevel() const;            // FUN_007e5ad0
	int charsetLookup(const QString &name, bool set96);  // FUN_00802a26
	void setUserPreferredCharset(int setId);              // FUN_00801a3e
	int paletteBright(int index) const;   // FUN_007e358e
	unsigned int rgbFromRgb(int r, int g, int b) const;   // FUN_007e35c8
	const char *sgrKey();                 // DAT_011c2088 (0xdca26230091f1ca6)
	const char *attrKey();                // DAT_011c2098 (SGR attr key)
	const char *conformanceKey();         // DAT_011c2068 (0x5b3b8ddd279e6bf4)
	void applyNamedAttribute(const char *key, const QString &value);  // FUN_007ee9e2
	void setAttributeEnabled(int on);     // FUN_007e51ca
	void notifyNamedAttribute(const char *key, const QString &value);
	void reportUnsupported(const QString &message);       // FUN_007eefbe
	void setScrollbarVisible(bool on);    // FUN_007e51e6
	void resizeScreen(int rows, int cols, int flag);      // FUN_007e5688
	void notifyMouseMode(bool on);        // thunk FUN_009131c8 (arg 4)
	void notifyReverseScreen();           // FUN_009134d0
	void notifyModeChange();              // FUN_00913178
	void enterVt52(int mode);             // FUN_007e87c8
	void writeText(const QString &text);  // FUN_007e6f42
	void clearWrapLatch();                // FUN_007e515e
	void markLocatorChanged();            // FUN_007e2f3e
	void keymapSetModifier(void *keymap);   // FUN_007a2c94
	void sendResponse(const QByteArray &data);  // FUN_007e66c6
	void notifyZmodem(int a, int b);            // FUN_0091378a
	void setCell(int y, int x, int ch, void *sgr);  // FUN_007e4916
	void switchPage(int page);                  // FUN_007ef11a
	unsigned int m_viewRefresh;                 // view flags via +0x10
	void *m_protocolParams;                     // +0x58 parameter list
	void keymapResetModifier(void *keymap); // FUN_007a2c02
};

#endif // SCREEN_H
