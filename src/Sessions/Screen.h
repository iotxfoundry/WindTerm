#ifndef SCREEN_H
#define SCREEN_H

#pragma once

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// The VT screen object (Commander +0x80): holds mode flags and the
// scrollback machinery; forwards buffer work to TerminalCore.
// (Canonical rebuild after multi-batch drift; offsets proven.)

#include "TerminalCore.h"

#include <QString>
#include <QStringList>
#include <QByteArray>
#include <QMap>
#include <QVariant>

class Screen
{
public:
	Screen();

	void *m_viewSettings; // +0x10 (scrollback limit at +0x104)
	TerminalCore *m_core; // +0x80 visible screen core
	TerminalCore *m_history; // +0x88 scrollback/history buffer
	TerminalCore *m_altCore; // +0x88 alternate-screen note
	TerminalCore *m_savedPrimary; // +0x90 primary core while on alt screen
	void *m_scrollView; // +0x98 scrollback view
	void *m_keymap; // +0xf8
	void *m_keymap2;
	bool m_keypadNumericMode;      // +0xf0 (DECKPAM/DECKPNM, alt-keypad inverse)
	bool m_cursorKeyMode;          // +0xf1 (DECCKM)
	bool m_altScreenEnabled;       // +0x118 (DEC 1046)
	bool m_1046Flag;               // +0x122 (set with DECCOLM path)
	bool m_leftRightMarginEnabled;  // +0x11a (DECLRMM)
	bool m_scrollbackEnabled;       // +0x11c
	bool m_nrcMode;                // +0x11b (DECNRCM, DEC 42)
	bool m_guardedArea;            // +0x121 (DECSACE start/end)
	bool m_bracketedPaste;         // +0x120 (DEC 2004, FUN_007e355a)
	bool m_reverseWraparound;       // +0x134 (reverse wrap for backspace)
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
	bool m_protectedErase; // +0x129 (eraseCells path)
	bool m_newlineMode;             // +0x12f (LNM)
	bool m_eraseProtectedMode;      // +0x129 (DECSCA-protected erase skip)
	int m_savedCursorStyle;         // +0xa8 (-1 = none)
	unsigned short m_eraseAttr;     // +0x110 current SGR erase attribute
	bool m_lastGraphicChar;        // +0x114 (UCS4, repeatCharacter)
	int m_palette;                // +0xd0 (color table, FUN_007e3578)
	unsigned *m_brightBitset; // +0xd8 payload
	bool m_scrollbarVisible; // +0x135
	void *m_view;            // +0x10 view object (write-back vtable +0x70/+0x78)
	long m_lastBellSecs;     // +0xa8 bell rate-limit timestamp (epoch secs)
	int m_protocol; // +0x20
	int m_protocolCache; // +0x124
	void *m_sessionParams; // +0x58
	// DEC locator state (+0x160; FUN_007e2efe/eea/ec2):
	//   flags bit3 = rect valid; +1 mode (0=off,1=on,2=one-shot,
	//   reset to 0 by FUN_007eb4d6); +2 units (2=cell,1=pixel);
	//   rect ints at +4/+8/+0xc/+0x10
	struct LocatorState {
		unsigned char flags;   // +0x160
		char mode;             // +0x161 enabled / one-shot
		char units;            // +0x162
		char pad;
		int left, top, right, bottom;  // +0x164.. (write order p2,p4,p3,p5)
	};
	LocatorState m_locator = { 0, 0, 2, 0, -1, -1, -1, -1 };   // FUN_007e2f52 reset state
	bool m_udkLocked;               // +0x12d (DECDSR 25)
	bool m_mode67Flag;              // +0x11f (DECRQM 67 reads, name unknown)
	bool m_autoPrint; // +0x130
	bool m_bellEnabled; // +0x12e
	bool m_bellAudible; // +0x13a
	void *m_codec; // view +0xe0
	void *m_decoder; // view +0xf0
	int m_viewField64; // view +0x64
	long m_styleBase1; // +0x1f0
	long m_styleBase2; // +0x1f8
	int m_pageCount;                // +0xcc
	int m_pageCurrent;              // +0xc8 (FUN_007ef11a)
	QString m_sessionUuid; // +0x218
	void *m_zmodemTimer; // +0x208
	int m_pendingWrap;                   // +0x40 (wrap-pending row flag)
	int m_lineModeBit;                   // +0x1c8 bit0 source
	unsigned int m_lastCp;               // decode latch for REP
	QByteArray m_pendingTail;            // +0x178 carry (unconsumed tail)
	int m_lastDecodedUnits;              // UTF-16 units of the last decode
	int m_lastEatenBytes;                // bytes the last decode consumed
	unsigned int m_viewRefresh;                 // view flags via +0x10
	void *m_protocolParams; // +0x58 param list
	void **m_views; // +0x1e0 view list
	QMap<quint64, QByteArray> m_namedAttributes; // +0x78 (FUN_007ee9e2 store)
	// locator report chain (FUN_007ebd6a -> FUN_007eb4d6)
	void reportLocatorEvent(int kind, int buttons, double x, double y, int row, int col);
	int locatorRowFromPixel(double x, double y) const;   // FUN_007e3136 — cited
	int locatorColFromPixel(double x, double y) const;   // FUN_007e30f4 — cited
	quint64 locatorUnitTransform(double x, double y) const;  // FUN_007e3114 — cited
	unsigned m_altSlot;
	struct WriteTemplate {         // +0x28..+0x40 (FUN_007e4c90)
		unsigned char flags;
		unsigned char pad[3];
		int field4;
		unsigned char body[0x10];
		void *payload;
	};
	WriteTemplate m_writeTemplate;

	bool m_reverseWraparound2;     // +0x134 note: shared with reverse wrap (DEC 45)
	bool m_altScreenActive;       // +0x139 (FUN_007e4028)
	bool m_vt52Mode;                // +0x124
	bool m_autoPrint2;              // alias guard

	QVariant m_result;

	void adjustScreenAlignment();                 // FUN_007e5f24 (DECALN 'E' grid)
	void allowScrollback();
	void appendClusterUnits(void *cell, unsigned int cp);
	void appendHistoryBlock(int at, int count, void *style, bool cont, bool dwl);   // FUN_007e4368
	void applyNamedAttribute(quint64 key, const QString &value);   // FUN_007ee9e2 set path
	void assignUserPreferredSupplementalSet(int which, const QString &name);   // FUN_007e4ac2
	void backIndex();                   // FUN_007e4d48 (DECBI)
	void backspace();                   // FUN_007e4f44
	void bell();
	void bracketedPasteMode(); 

	// --- cited helpers (call sites proven, bodies not yet transcribed) ---
	void buildWriteTemplate();            // FUN_007e4c90 -> +0x28 cell
	void carriageReturn();              // FUN_007e4fc8
	void changeAttributesInRectangularArea(const QString &area);      // FUN_007eb17e
	int charClass(unsigned int cp);        // FUN_007e5a0e (charset slot)
	bool charsetDisabled(int setId);            // FUN_008034a4
	int charsetLookup(const QString &name, bool set96);   // FUN_00802a26
	int charsetSlotWidth(int slot, bool nrc);   // FUN_008034b6
	void checkControlCharacter();
	void clearScrollback();                     // FUN_0091318c (ED 3)
	void clearTabstop(int mode);                  // FUN_007e5df0 (TBC)
	void clearWrapLatch();                 // FUN_007e515e
	int codepointWidth(unsigned int cp);   // FUN_007a4692
	QVariant configValue(const char *key);  // FUN_007cbb36
	int containerEnd(void *container);           // container +0xc
	int convertRowToHistory(TerminalCore *core, struct Row *row, void *container, int flag);   // FUN_007a9582
	void copyRectangularArea(const QString &area);                    // FUN_007eb2f2 (DECCRA)
	int currentColumn() const;          // FUN_007e368e (core +0xc8)
	int currentCursorStyle() const;                   // FUN_007e36aa
	struct Row *rowFlagsPtr(int row);                 // FUN_007e41bc -> FUN_007e416e
	void restoreCursorTail();                         // FUN_007e4b30
	void cursorVisibleChanged(bool on) { (void)on; }  // Screen signal 7
	bool m_cursorVisible = false;                     // +0x128
	int currentLine() const;            // FUN_007e369c (core +0xc4)
	void cursorMoveRaw(int y, int x);   // FUN_007e4f38 -> FUN_007a538a
	void dataType();
	int decodeChunk(const char *data, int len, unsigned int *cp);   // codec chain +0x18
	void deleteCharacter(int count);    // FUN_007e3784 -> FUN_007a65d2
	void deleteColumn(int count);       // FUN_007e3790 -> FUN_007a6672
	void deleteLine(int count);         // FUN_007e379c -> FUN_007a5220
	void doubleLineHeightBottom();
	void doubleLineHeightTop();
	void doubleLineWidth();
	int eatenBytes(int width);
	void enableFilterRectangle(const QString &filter); 	// 0x7eb8fe
	void enableLocatorReports(int mode, int arg);   // FUN_007e37a8
	void endGuardedArea();                  // FUN_007e37dc
	void enterAltKeypadMode();              // FUN_007e37e8
	void enterTmuxControlMode();
	void enterVt52(int mode);              // FUN_007e87c8
	int eraseCells(int line, int from, int count, bool selective);   // FUN_007e37f8
	void eraseCharacter(int count);     // FUN_007e385a (ECH)
	int eraseLine(int line, int mode, bool selective);   // FUN_007e4ba2 (EL)
	void eraseRectangularArea(const QString &area, bool selective);   // FUN_007eb1c4
	int eraseScreen(int mode, bool selective);           // FUN_007e606a (ED)
	void eraseSelectiveLine();
	void eraseSelectiveScreen();
	void exitAltKeypadMode();               // FUN_007e3896
	void exitAnsiMode();                // FUN_007e88e8 (enter VT52)
	void fillRectangularArea(const QString &fill);                    // FUN_007eb20a (DECFRA)
	void formFeed();
	void forwardIndex();                // FUN_007e4d82 (DECFI)
	void fromUnicode(const QString &text); 	// 0x4c29d0
	void highlightTracking(int mode, int type); 	// 0x7eac52
	void horizontalTab();               // FUN_007e5d7c
	bool incompleteSequence(unsigned int cp, int eaten);
	void indexDown();                   // FUN_007e55b6 (IND)
	void indexUp();                     // FUN_007e563e (RI)
	void insertCharacter(int count);    // FUN_007e3ace -> FUN_007a6782
	void insertColumn(int count);       // FUN_007e3ada -> FUN_007a6822
	void insertLine(int count);         // FUN_007e3ae6 -> FUN_007a5290
	bool isAltScreenActive() const;         // FUN_007e4028 (+0x139)
	bool isBracketedPaste() const;          // FUN_007e355a
	int currentPage() const { return m_pageCurrent; }
	bool isReverseScreen() const;           // FUN_007e4a94
	bool isScrollbackAllowed() const;           // FUN_007e4036
	bool isTabstop(int column) const;             // FUN_007e5c98
	bool isVt52Mode() const;                      // FUN_007e5a02 (+0x124)
	void keymapResetModifier(void *keymap, int which);  // FUN_007a2c02
	void keymapSetModifier(void *keymap, int which, int value);    // FUN_007a2c94
	void lineFeed();                    // FUN_007e55fc
	void loadLeds();
	int marginBottom() const;           // FUN_007e4426 -> FUN_007a4bb4
	int marginLeft() const;             // FUN_007e443e -> FUN_007a493c
	int marginRight() const;            // FUN_007e444a -> FUN_007a490e
	int marginTop() const;              // FUN_007e4456 -> FUN_007a4be2
	void markLocatorChanged();             // FUN_007e2f3e
	void markRowErased(int row);                      // FUN_007e41ca
	void mediaCopy(int type);                     // FUN_007f0530 (MC)
	void mediaCopyDec(int mode); 	// 0x7f063a
	void moveCursor(int y, int x);      // FUN_007e4fdc -> FUN_007a54f8
	void moveCursorBackward(int n);     // FUN_007e4832 -> cursorBackward
	void moveCursorColumn();
	void moveCursorColumnBackward();
	void moveCursorColumnRelative();
	void moveCursorDown(int n);         // FUN_007e483e -> cursorDown
	void moveCursorForward(int n);      // FUN_007e484a -> cursorForward
	void moveCursorLine();
	void moveCursorLineBackward();
	void moveCursorLineRelative();
	void moveCursorNextLine();
	void moveCursorNextTabstop();
	void moveCursorPrecedingLine();
	void moveCursorPrecedingTabstop();
	void moveCursorUp(int n);           // FUN_007e4856 -> cursorUp
	void movePage(int page, bool homeCursor);     // FUN_007ef16a
	void movePagePositionAbsolute();
	void movePagePositionBackward();
	void movePagePositionRelative();
	void nextLine();                    // FUN_007e562c (NEL)
	void nextPage();
	int nextTabstop(int from, int count) const;   // FUN_007e5d1e
	void notifyCommand(const QString &msg);       // body 未定位(旧注 0x4c3110 是 qstrcmp PLT,误)
	void notifyCursorStyle(void *cursor, int shape);  // FUN_00913592 信号6 caretStyleChanged(bool,int)
	void notifyFig(const QString &content); 	// body 未定位(0x4c3290 是 QByteArray PLT,误)
	void notifyHyperlink(const QString &url); 	// body 未定位(同上)
	void notifyIterm2(const QString &content); 	// body 未定位(同上)
	void notifyMessage(int message); 	// body 未定位
	void notifyMessageEx(int type, int a, int b);  // body 未定位(候选 00913540=信号34 windowSizeChanged,未证)
	void notifyModeChange();               // FUN_00913178
	void notifyMouseMode(bool on);         // thunk FUN_009131c8 (arg 4)
	void notifyNamedAttribute(quint64 key, const QByteArray &value);   // FUN_007ee9e2
	void notifyOsc(int kind, const QString &payload);   // body 未定位(0x4c3290 是 QByteArray PLT,误)
	void notifyRemoteDirectory(const QString &directory); 	// 0x7cd366
	void notifyReverseScreen();            // FUN_009134d0
	void notifyScrollbar(bool visible);       // FUN_00913508 (Screen signal 20)
	void notifyZmodem(int a, int b);             // FUN_0091378a
	void option(const QString &name); 	// 0x7d5538
	int originBottom() const;           // FUN_007e48b0 -> FUN_007a5304
	int originLeft() const;             // FUN_007e48c8 -> FUN_007a4962
	int originRight() const;            // FUN_007e48d4 -> FUN_007a49c6
	int originTop() const;              // FUN_007e48e0 -> FUN_007a4c08
	void page();
	void pages();
	int paletteBright(int index) const;    // FUN_007e358e
	int paletteColor(int index) const;     // FUN_007e3578
	void parseRect(const QString &area, int *top, int *left, int *bottom, int *right);   // FUN_007eaeee
	void playBell(const QVariant &style);   // FUN_007cbc46 tail
	void precedingPage();
	int prevTabstop(int from, int count) const;   // FUN_007e5ce4
	bool protocolAltCapable() const;       // FUN_007e2c6a(+0x58)
	bool protocolExtCapable() const;       // FUN_007e2c72(+0x58)
	int protocolLevel() const;             // FUN_007e5ad0
	void pushLinesToScrollback(int count);      // FUN_007e53b6
	char queryDecMode(int mode);                // FUN_007f13a0 (respond flag = 0)
	int queryProtocolLevelProxy();              // FUN_007e2e42 wrapper
	bool queryRenderMode(int arg) const;         // FUN_007e5284
	bool refreshNeeded() const;                   // FUN_0061324e (view flag)
	void refreshScreen();
	void repeatCharacter(int count);    // FUN_007e7cf6
	void reportDecDeviceStatus(const QString &params);   // FUN_007f0d7c
	void reportDeviceAttributes(int index);       // FUN_007ea806
	void reportDeviceAttributesOne();
	void reportDeviceAttributesThree();
	void reportDeviceAttributesTwo();
	void reportDeviceStatus(const QString &params);  // FUN_007f0ae6
	void reportTerminalParameters(int mode);      // FUN_007ecdc2
	void reportUnsupported(const QString &message);        // FUN_007eefbe
	void requestChecksumOfRectangularArea(const QString &area);   // FUN_007eced6
	void requestDecMode(int mode); 	// 0x7f13a0
	void requestDisplayedExtent();                // FUN_007ed148 ("w response)
	void requestKeyModifier(int key);             // FUN_007ed282 (ESC [ >k;km)
	void requestLocatorPosition(int mode);        // FUN_007ebd6a
	void requestMode(int mode);                   // FUN_007f17c2 (DECRQM, full)
	void requestPresentationStateReport();        // FUN_007ed35a
	void requestSelectionOrSetting();             // FUN_007f194e
	void requestTerminalStateReport();            // FUN_007f0434
	void requestUserPreferredSupplementalSet();   // FUN_007ed7f6
	void requestWindowSelections();               // 0x4c3220 (QString helper PLT)
	void requestXtermTerminfoData(const QString &data);   // FUN_007f3518
	void resetDecMode(int mode); 	// 0x7f5d2e
	void resetHard();                             // FUN_007ea73c (RIS)
	void resetKeyModifier();                // FUN_007e498c
	void resetMode();
	void resetSoft();                             // FUN_007ea7e6 (DECSTR)
	void resetWindowColor();
	void resizeScreen(int rows, int cols, int flag);       // FUN_007e5688
	void restoreCursor();               // FUN_007f6426 (DECRC + fallback)
	void restoreDecMode(const QString &modes);         // FUN_007f64a6
	void restorePresentationState();              // FUN_007ef1b6
	void reverseAttributesInRectangularArea(const QString &area);     // FUN_007eb2ac
	void reverseScreen();
	unsigned int rgbFromRgb(int r, int g, int b) const;    // FUN_007e35c8
	void ringBell();                            // FUN_007cbc46
	int rowCount() const;               // FUN_007e5f18 -> FUN_007a4b4a
	bool sCharClass(unsigned int cp);      // DAT_011c1fe0 table
	void saveCursor();                  // FUN_007e4aa2 -> core DECSC
	void saveDecMode(const QString &modes);            // FUN_007f427a
	void savePendingMultibyte(const char *data, int len);
	void scroll(int count, bool down, bool fillTemplate);   // FUN_007e5546
	void scrollCursorDown();
	void scrollCursorUp();
	void scrollDown();
	void scrollHorizontal(int delta);   // FUN_007e4d3c -> FUN_007a68ae
	void scrollLeft();
	void scrollNextLine();
	void scrollRight();
	void scrollUp();
	bool scrollbackModeCheck() const;                 // FUN_007e4028
	void select7BitC1Control(bool on);                 // FUN_007e5aec
	void select8BitC1Control();
	void select94CharacterSet(char slot, const QString &name);    // FUN_007e4dbc
	void select96CharacterSet(char slot, const QString &name);    // FUN_007e4e16
	void selectActiveStatusDisplay(int which);    // FUN_007ef86e (DECSASD)
	void selectAttributeChangeExtent();                   // FUN_007e4e74
	void selectCharacterAttribute(int attr);              // FUN_007eebd4
	void selectGraphicRendition(const QString &params);   // FUN_007ef95c
	void selectLocatorEvents(const QString &list);  // FUN_007e4e80
	void selectNumberOfLinesOnScreen(int lines);  // FUN_007e5ba2 (DECSNLS)
	void selectStatusLineType(int type);          // FUN_007f0346 (DECSSSL)
	void selectiveEraseRectangularArea(const QString &area); 	// 0x7eb1c4
	void sendResponse(const QByteArray &data);   // FUN_007e66c6
	void setAllowScrollback(bool on);       // FUN_007e4f1c
	void setAnsiConformanceLevel(int level);              // FUN_007e5b12
	void setAnsiConformanceLevelOne();
	void setAnsiConformanceLevelThree();
	void setAnsiConformanceLevelTwo();
	void setAttributeEnabled(int on);      // FUN_007e51ca
	void setCell(int y, int x, int ch, void *sgr);   // FUN_007e4916
	void setCodec(const QString &name); 	// -0x3efdef14
	void setColumnsPerPage(int columns);          // FUN_007e61fa (DECSCPP)
	void setConformanceLevel(int a, int b);               // FUN_007eecc0
	void setCursorStyle(int style, bool save);    // FUN_007e4ffa (DECSCUSR)
	void setCursorVisibility(int mode);           // FUN_007e5090 (DECTCEM)
	void setCursorVisible(bool on);                   // FUN_007e506a
	void setDecMode(const QString &modes, bool on);    // FUN_007f5d2e
	void setHorizontalTabstop();
	void setKeyModifier(int which, int value);    // FUN_007e5152 (tail jump)
	void setLeftRightMargins(int left, int right);    // FUN_007e5bd4 (DECSLRM)
	void setLineDoubleHeightBottom(bool on); // FUN_007e4236 (row bit5)
	void setLineDoubleHeightTop(bool on);    // FUN_007e4282 (row bit4)
	void setLineDoubleWidth(bool on);   // FUN_007e41e4 (DECDWL, row bit3)
	void setLinesPerPage(int lines);              // FUN_007e5eb2 (DECSLPP)
	void setMarginBellVolume();
	void setMode(const QString &modes, bool on);       // FUN_007edce6 (SM/RM)
	void setScrollbarVisible(bool on);     // FUN_007e51e6
	void setTabstop(int column, bool on);         // FUN_007e52fc (HTS)
	void setTopBottomMargins(int top, int bottom);    // FUN_007e5fa6 (DECSTBM)
	void setUserDefinedKeys();                    // FUN_007ef0e8 (DECDLD)
	void setUserPreferredCharset(int setId);               // FUN_00801a3e
	void setWarningBellVolume();
	void setWindowAttributes(const QString &attributes); 	// 0x7f298e
	void setWindowColor(int index, const QString &color); 	// 0x7f24ae
	void setWindowIcon(const QString &icon); 	// 0x4c29d0
	void setWindowIconAndTitle(const QString &both);   // FUN_007cd902 (swap +0x118)
	void setWindowSelections(const QString &which, const QString &selections); 	// 0x4beac0
	void setWindowTitle(const QString &title); 	// 0x7cd366
	void setWindowTitleBuffer(const QString &title);   // FUN_007cd366 (locked +0xe0)
	void setXtermTerminfoData(const QString &name); 	// 0x7f07d8
	void shiftCellsRight(struct Row *row, int col, int width);
	void shiftLocking(bool right, int n);   // FUN_007e521c
	void shiftLockingOne();
	void shiftLockingOneRight();
	void shiftLockingThree();
	void shiftLockingThreeRight();
	void shiftLockingTwo();
	void shiftLockingTwoRight();
	void shiftLockingZero();
	void shiftSingle(int n);                // FUN_007e5254
	void shiftSingleThree();
	void shiftSingleTwo();
	void singleLineWidth();
	QStringList splitParams(const QString &params) const;    // QByteArray::split path
	void startGuardedArea();                // FUN_007e5278
	long styleTimestamp(bool primary);          // FUN_007e538e
	void switchPage(int page);                   // FUN_007ef11a
	void switchToAlternateScreen(bool on, bool saveCursor);   // FUN_007f5b70
	QByteArray takePendingMultibyte();    // +0x178 carry buffer
	void testConfidence(const QString &data); 	// 0x7f0a5e
	void toUnicode(const QString &text); 	// 0x4c29d0
	void verticalTab();
	void vt52EnterGraphicsMode();                 // FUN_007e5a90 (core+0xc0 = 3)
	void vt52ExitGraphicsMode();                  // FUN_007e5ab0 (mirror)
	void vt52Identify();                          // FUN_007edc22 (sends ESC / Z)
	void vt52Mode();
	void vt52MoveCursor(int column, int line); 	// 0x7e4f38
	int widthFromTables(unsigned int cp);  // FUN_007a4692 binary searches
	int windowColumns() const;          // FUN_007e5b96 -> FUN_007a4906
	void windowIcon();
	void windowRows();
	void windowTitle();
	void writeBackToView(const QByteArray &data);
	void writeText(const QString &text);          // codec wrapper
	void writeText(const char *data, int len);    // FUN_007e6f42 (main loop)
	void zmodemReceive();                         // FUN_007e676c (QTimer FSM)
	void zmodemSend();                            // FUN_007e6844 -> notify(2,1)
	static void zmodemTick(int event, void *context);   // FUN_007e22fa

	// --- cited helpers, emit points and writeText internals (canonical) ---
	void *buildFillAux();                       // FUN_007e4c90
	void *historyContainer(void *viewMember);   // FUN_007bacc0
	void *defaultStyle(int flag);               // FUN_007e538e
	// Named-attribute hash keys (splitmix64 of seed pair ^ site literal;
	// see FUN_007f0346/7eecc0/7eebd4 guard inits)
	quint64 sgrKey();                           // FUN_007e2123("m") hash
	quint64 attrKey();                          // literal 0x71220271
	quint64 conformanceKey();                   // literal 0x70222070
	void *cellAt(struct Row *row, int col);     // FUN_007a3c1a
	unsigned short *headAt(struct Row *row, int col);  // FUN_007a3c2a
	void *nextCell(void *cell);
	unsigned short *nextHead(unsigned short *head);
	void *sgrPayload();
	QString keyboardDialects() const;
	QString keyboardType() const;
	void setCodec(const QByteArray &name);
	void *lockCodec();                          // FUN_007cadee
	void *decoderHandle();                      // FUN_007cb7b6
	void sendScreenCommand(int cmd, const QVariant &a = QVariant(),
	                       const QVariant &b = QVariant());
	// signal emit points (metaObject 0x11a82e0):
	//   1 modeChange   2 commandRequested   8 mouseMode   18 reverseScreen
	void modeChanged() {}
	void commandRequested(int cmd, const QVariant &a, const QVariant &b)
	{ (void)cmd; (void)a; (void)b; }
	void mouseModeChanged(int mode) { (void)mode; }
	void reverseScreenChanged() {}
	class QElapsedTimer *m_elapsed;

	// --- SuperCommander forward-compat declarations (auto-derived) ---
	void codecFromUnicode(const QString &);  // SuperCommander forward compat
	void codecToUnicode(const QString &);  // SuperCommander forward compat
	void currentPage();  // SuperCommander forward compat
	void filterRectangle(int a0, int a1, int a2, int a3);  // SuperCommander forward compat
};

#endif // SCREEN_H
