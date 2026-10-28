#ifndef TERMINALWIDGET_H
#define TERMINALWIDGET_H

#pragma once

// 终端部件组装(TERMINALWIDGET-IMPL.md;metacall 0x910a98,idx 即该表)。
// 全 58+ 槽覆盖:守卫+查询 / 输入 / 清屏 / 复位 / CMD 直传 / 日志 /
// modem / FreeType / 会话组。渲染层与深子系统腿(对话框/全局管理器/
// 会话栈)按注释 cited,随 Phase-4 后续接线。

#include "SuperCommander.h"

#include <QWidget>

class TerminalView;

class TerminalWidget : public QWidget
{
	Q_OBJECT

public:
	explicit TerminalWidget(QWidget *parent = nullptr);

	void setCommander(SuperCommander *commander) { m_commander = commander; }
	SuperCommander *commander() const { return m_commander; }
	void setTmuxMode(bool on) { m_tmuxMode = on; }

	// 视图装配(Phase 4b 渲染层):创建 TerminalView 并接入
	// Screen::m_view 写回通道(vtable+0x70)
	TerminalView *attachView();

	// --- 状态查询组 ---
	bool isAltScreen() const;      // idx 34 → 0083c4c8
	bool isMainScreen() const;     // idx 41 → 0083c696
	bool isConnected() const;      // idx 35 → 0083c524
	bool isUnconnected() const;    // idx 44 → 0083c6fc
	QString protocolName() const;  // idx 53 → 0083cb0c
	bool canWrite() const;         // idx 20 → 0083cdcc

	// --- 复位组 ---
	void resetCharacterSet();      // idx 56 → 0083cbc8(命令 6)
	void resetHard();              // idx 57 → 0083cc00(命令 7)
	void resetSoft();              // idx 58 → 0083cc38

	// --- 输入/清屏组 ---
	void write(const QString &text);            // idx 74/75 → 0083e286
	void clearScreen();                         // idx 22 → 00840438
	void clearScreenAndScrollback();            // idx 23 → 00840532
	void clearScrollback();                     // idx 24 → 0083fc2c

	// --- CMD 直传组(0x75xx 视图命令经 sendScreenCommand)---
	int caretVirtualSpace() const;              // idx 21 → CMD 0x75df
	int promptLine() const;                     // idx 51 → CMD 0x75dd
	int promptPosition() const;                 // idx 52 → CMD 0x75de
	int scrollbackLimit() const;                // idx 60 → CMD 0x75f2
	int scrollbackLines() const;                // idx 61 → CMD 0x75f3
	void setScrollbackLimit(int v);             // idx 67 → CMD 0x75f4
	long localBaseTime() const;                 // idx 45 → CMD 0x75f9
	void setLocalBaseTime(int v);               // idx 63 → CMD 0x75fd
	void setRemoteBaseTime(int v);              // idx 64 → CMD 0x75ff
	void setTimestampFormat(const QByteArray &f);      // idx 68 → CMD 0x75fc
	void setTimestampLongFormat(const QByteArray &f);  // idx 69 → CMD 0x75fe
	bool isFreeTypeMode() const;                // idx 36 → CMD 0x75e2

	// --- FreeType 组 ---
	void cancelFreeTypeMode();                  // idx 18 → 0083cf68
	void eraseFreeTypeRange();                  // idx 29 → 00842d34

	// --- 日志组(+0x148 文件 / +0x150 状态)---
	bool isLogFileExists() const;               // idx 37 → 0083c5c8
	bool isLoggerPaused() const;                // idx 38 → 0083c63a
	bool isLoggerStarted() const;               // idx 39 → 0083c5e6
	bool isLoginWizardVisible() const;          // idx 40 → 0083c674
	void openLogFolder();                       // idx 46 → 0083c8b4
	void openLogFile();                         // idx 47 → 0083c970
	void startLogger(const QString &name = {}); // idx 70/71 → 008439ec
	void stopLogger();                          // idx 72 → 0083dc18
	void pauseLogger();                         // idx 50 → 0083c9be
	void resumeLogger();                        // idx 59 → 0083cc70
	QString logFilePath() const { return m_logFilePath; }

	// --- modem/zmodem 组(+0x120 modem 对象)---
	bool isModemSupported(const QString &protocol = {}) const;  // idx 42
	bool isModemTransmitting() const;           // idx 43 → 0083c6a8
	void cancelModemTransmitting();             // idx 19 → 00842172
	void receiveBinary(const QByteArray &data); // idx 54 → FUN_00848d6a(0)
	void sendBinary(const QByteArray &data);    // idx 62 → FUN_00848d6a(1)

	// --- 会话/命令组 ---
	void executeCommand(bool disconnected);     // idx 30 → 0083ffde
	void pasteText(bool disconnected);          // idx 49 → 00843050
	QString commandText(const QString &command) const;  // idx 25 → 0083c7f2
	void completeHistory();                     // idx 27 → 0083df86
	void detectShellCwd();                      // idx 28 → 0083dc90
	bool supportsDetectShellCwd() const;        // idx 73 → 0083dc72
	void disconnectSession();                   // idx 31 → 0083c330
	void reconnectSession();                    // idx 55 → 0083d97a
	void setRightClickAction(bool disconnected);// idx 65 → 0083d0a6

private:
	SuperCommander *m_commander = nullptr;
	TerminalView *m_viewWidget = nullptr;   // 渲染视图(attachView)
	bool m_tmuxMode = false;        // +0x160 tmux 状态标志
	bool m_modemActive = false;     // +0x120 modem 对象非空
	QString m_logFilePath;          // +0x148 日志文件
	bool m_loggerStarted = false;   // +0x150 日志状态
	bool m_loggerPaused = false;
	bool m_freeTypeMode = false;
	int m_scrollbackLimitValue = 0;
	int m_promptLineValue = 0;
	int m_promptPositionValue = 0;
	int m_caretVirtualSpace = 0;
	bool m_loginWizardVisible = false;
};

#endif // TERMINALWIDGET_H
