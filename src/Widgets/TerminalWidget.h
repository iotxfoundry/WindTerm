#ifndef TERMINALWIDGET_H
#define TERMINALWIDGET_H

#pragma once

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// The Qt widget hosting a terminal session: 18 signals + 58 slots.
// Mixed forms: WT command forwards (sendEditor space >= 30173),
// Screen-cluster guards (m_screen +0x1f8), session API (+0x118,
// 0x7d36a0 family), QFileInfo log path, composites.
// metacall 0x910a98. Full table: TERMINALWIDGET-IMPL.md.

#include <QVariant>
#include <QString>
#include <QTimer>
#include "Screen.h"

class TerminalWidget
{
public:
	// --- object layout (offsets proven) ---------------------------------
	void *m_session;        // +0x118
	void *m_modem;          // +0x120
	QString m_logFilePath;  // +0x148
	int m_state;            // +0x150
	unsigned char m_flags;  // +0x160 (tmux/protocol mode)
	void *m_timer;          // +0x1a8
	QString m_widgetId;     // +0x1b0
	void *m_ptr1b8;         // +0x1b8
	void *m_ptr1c0;         // +0x1c0
	void *m_sessionRef;     // +0x1e0 (refcounted)
	void *m_sessionRaw;     // +0x1e8
	void *m_screenRef;      // +0x1f0 (refcounted)
	Screen *m_screen;       // +0x1f8
	QVariant m_result;

	bool isConnected() const { return m_sessionRef && m_state != 0 && m_sessionRaw; }
	bool isLogFileExists() const { return m_logFilePath.size() > 0; }

	// FUN_005b5d68 (same editor command space)
	template <typename... A>
	void sendEditor(QVariant &result, int command, const A &...args)
	{ (void)result; (void)command; }  // vtable +0x1c0 dispatch
	void deleteModem();
	void de16Forward(int which);   // FUN_0083de16

	bool sessionStackValid() const { return m_sessionRef && m_sessionRaw; }
	bool canWriteImpl();               // FUN_0083cdb8
	void sessionTextPath();            // FUN_0083ffde tail
	int sessionQuery6736();            // FUN_007d6736
	int sessionQuery6722();            // FUN_007d6722
	int sessionProtocol();            // FUN_007cabf8
	QString sessionProtocolName();     // FUN_007d5d2a
	void paneRegister(void *pane);     // FUN_00699088
	void openTriggersDialog();         // FUN_0083c616
	const void *schemeRegistry();      // FUN_005b97cc
	int rangeClassify(const QVariant &a);  // FUN_005b8fcc
	void rangeOp(int kind);            // FUN_005b9110
	bool cursorSnapshotCheck();        // FUN_00842d34 inner
	void armTimer();                   // FUN_0083dc90 inner
	void globalRegister(void *w);      // FUN_00810d6e
	void *globalQuery();               // FUN_0080c76e
	void applyRightClick(void *cfg);   // FUN_0083d074
	void showErrorCategory();          // FUN_0083d97a inner
	void executeCommandImpl(const QString &t);  // FUN_00843050 inner
	void sessionStringOp(const QVariant &a);    // FUN_008439ec inner
	void promptCompareClear();         // FUN_00840438 inner
   // FUN_00842110 (0x38-byte modem object)

	// --- private delegates (cited impls) ---
	void resetImpl(int which);            // FUN_0083cee2
	void sessionDisconnect();             // FUN_007d36a0
	void sessionReconnect();              // FUN_007d3d28
	void sessionResetCharset();           // FUN_007d377c
	void screenPauseLogger(Screen *s);    // FUN_007e33ea
	void binaryTransfer(int direction);   // FUN_00848d6a

	// --- signals (moc-generated; emit stubs 0x9107-0x910a) --------------

	void cancelFreeTypeMode()
	{
		// 0x0083cf68
		resetImpl(0);   // FUN_0083cee2(this, 0)
	}

	void cancelModemTransmitting()
	{
		// 0x00842172: Screen 守卫 -> 取消 modem 命令 2 + 释放 modem 对象
		if (!m_screenRef)
			return;
		m_screen->sendScreenCommand(2);
		deleteModem();
	}

	bool canWrite()
	{
		// FUN_0083cdcc: 状态查询(FUN_0083cdb8) + 会话栈守卫
		return m_sessionRef && m_sessionRaw && m_state != 0;
	}

	int caretVirtualSpace()
	{
		// 0x0083c710 -> CMD 0x75df
		sendEditor(m_result, 0x75df, QVariant(), QVariant());
	}

	void clearScreen()
{
	// FUN_00840438: 光标位置(FUN_008403a6/0x5b8576)与提示行(CMD
	// 0x75dd 经 0x83c9e2)比较后经 FUN_005be68c 发命令 — 复合体
	promptCompareClear();   // cited composite
}

	void clearScreenAndScrollback()
	{
		// FUN_00840532: clearScreen 后 500ms 延迟清滚动缓冲
		clearScreen();
		// cited: QTimer::singleShot(500ms, FUN_0083fd35) -> clearScrollback
	}

	void clearScrollback()
	{
		// FUN_0083fc2c: tmux 特例(标志 0x160==1 发 'clear-history -t %1' 文本)
		// 否则 CMD 0x75f1
		if (m_flags == 1) {
			// tmux: inject text command via screen (cited)
		} else {
			sendEditor(m_result, 0x75f1, QVariant(), QVariant());
		}
	}

	QString commandText(const QVariant & arg0)
	{
		// 0x0083c7f2
		int kind = rangeClassify(arg0);   // FUN_005b8fcc
		rangeOp(kind);   // FUN_005b9110
	}

	void completeHistory()
	{
		// 0x0083df86
		de16Forward(1);   // FUN_0083de16(this, 1)
	}

	void detectShellCwd()
	{
		// 0x0083dc90
		// QTimer 编排(+0x1a8):栈守卫 + 标志 0x160
		if (!m_screenRef || m_flags != 1)
			return;
		armTimer();   // cited
	}

	bool eraseFreeTypeRange()
	{
		// 0x00842d34
		// Screen 栈守卫 + 光标快照(FUN_00840316)复合判断
		if (!m_screenRef)
			return false;
		return cursorSnapshotCheck();   // cited
	}

	void executeCommand(const QVariant & arg0)
	{
		// 0x0083ffde
		// 三重守卫(+0x118/+0x1e0/+0x1e8)
		if (!(m_session && m_sessionRef && m_sessionRaw))
			return;
		sessionTextPath();   // cited tail
	}

	void disconnectSession(const QVariant & arg0)
	{
		// 0x0083c330
		globalRegister(this);   // FUN_00810d6e(this, 0x11c2200, +0x1b0, 0)
	}

	bool isAltScreen()
	{
		// 0x0083c4c8: 备用屏标志查询(FUN_007e4028)
		return m_screen ? m_screen->isAltScreenActive() : false;
	}

	bool isConnected()
	{
		// 0x0083c524
		if (!m_session)
			return 0;
		return sessionQuery6736();   // FUN_007d6736
	}

	bool isFreeTypeMode()
	{
		// 0x0083c538 -> CMD 0x75e2
		sendEditor(m_result, 0x75e2, QVariant(), QVariant());
	}

	void isLogFileExists()
	{
		// 0x0083c5c8
		// +0x148 引用守卫 -> QFileInfo::exists (inline elsewhere)
	}

	bool isLoggerPaused()
	{
		// 0x0083c63a
		if (!isConnected())
			return 0;
		return sessionProtocol();   // FUN_007cabf8
	}

	bool isLoggerStarted()
	{
		// FUN_0083c674: +0x1b8/+0x1c0 智能指针对守卫
		return m_ptr1b8 && m_ptr1c0;
	}

	bool isLoginWizardVisible()
	{
		// 0x0083c674: +0x1b8/+0x1c0 对守卫
		return m_ptr1b8 && m_ptr1c0;
	}

	bool isMainScreen()
	{
		// 0x0083c696: FUN_0083c4c8 取反(主屏)
		// 引用级占位,形态注记见 TERMINALWIDGET-IMPL.md
	}

	bool isModemSupported(const QVariant & arg0, const QVariant & arg1)
	{
		// 0x0083cb36: 标志 0x160==0 时仅 'Telnet'(QString::compare)支持 modem;带标志走类型范围
		// 引用级占位,形态注记见 TERMINALWIDGET-IMPL.md
	}

	bool isModemTransmitting()
	{
		// 0x0083c6a8: modem 对象非空 -> 1;否则 Screen 命令 3 查询
		if (m_modem)
			return true;
		return m_screenRef != nullptr;   // FUN_007e31ec cited
	}

	bool isUnconnected()
	{
		// 0x0083c6fc
		if (!m_session)
			return 0;
		return sessionQuery6722();   // FUN_007d6722
	}

	int localBaseTime()
	{
		// 0x0083c822 -> CMD 0x75f9
		sendEditor(m_result, 0x75f9, QVariant(), QVariant());
	}

	void openLogFolder()
	{
		// 0x0083c8b4: 无日志 -> 全局默认(0x11c2200);有 -> QFileInfo(+0x148).absolutePath()
		// 引用级占位,形态注记见 TERMINALWIDGET-IMPL.md
	}

	void openLogFile()
	{
		// 0x0083c970
		if (!isModemTransmitting())
			return;
		openTriggersDialog();   // FUN_0083c616
	}

	void openSessionTriggersDialog()
	{
		// 0x0083c9a4
		paneRegister(this);   // FUN_00699088(0x11c1a60, +0x1b0, this)
	}

	void pasteText(const QVariant & arg0)
	{
		// 0x00843050
		// 6K 复合体:光标快照 + 编辑器文本装备 + 发送 — 深段引用
		executeCommandImpl(arg0.toString());   // cited
	}

	void pauseLogger()
	{
		// FUN_0083cc38: Screen 栈守卫 -> FUN_007e33ea(日志暂停命令)
		if (!m_screenRef)
			return;
		screenPauseLogger(m_screen);
	}

	void promptLine()
	{
		// 0x0083c9e2 -> CMD 0x75dd
		sendEditor(m_result, 0x75dd, QVariant(), QVariant());
	}

	int promptPosition()
	{
		// 0x0083ca74 -> CMD 0x75de
		sendEditor(m_result, 0x75de, QVariant(), QVariant());
	}

	QString protocolName()
	{
		// 0x0083cb0c
		if (!m_session)
			return QString();
		return sessionProtocolName();   // FUN_007d5d2a
	}

	void receiveBinary(const QVariant & arg0)
	{
		// 0x008496da
		binaryTransfer(0);   // FUN_00848d6a(this, data, 0)
	}

	void reconnectSession()
	{
		// FUN_0083cc70: isConnected 守卫 -> FUN_007d3d28
		if (!isConnected())
			return;
		sessionReconnect();
	}

	void resetCharacterSet()
	{
		// FUN_0083dc18: isConnected -> FUN_007d377c + 释放 +0x150
		if (!isConnected())
			return;
		sessionResetCharset();
		m_state = 0;
	}

	bool resetHard()
	{
		// FUN_0083cf68 -> FUN_0083cee2(this, 0)
		resetImpl(0);
	}

	bool resetSoft()
	{
		// FUN_0083cf68 族 -> FUN_0083cee2(this, 1)
		resetImpl(1);
	}

	bool resumeLogger()
	{
		// 0x0083cc70: isConnected 守卫 -> FUN_007d3d28(+0x118, +0x150)
		// 引用级占位,形态注记见 TERMINALWIDGET-IMPL.md
	}

	bool scrollbackLimit()
	{
		// 0x0083cc94 -> CMD 0x75f2
		sendEditor(m_result, 0x75f2, QVariant(), QVariant());
	}

	bool scrollbackLines()
	{
		// 0x0083cd26 -> CMD 0x75f3
		sendEditor(m_result, 0x75f3, QVariant(), QVariant());
	}

	bool sendBinary(const QVariant & arg0)
	{
		// 0x008496e2
		binaryTransfer(1);   // FUN_00848d6a(this, data, 1)
	}

	bool setLocalBaseTime(const QVariant & arg0)
	{
		// 0x0083cf70 -> CMD 0x75fd
		sendEditor(m_result, 0x75fd, QVariant(), QVariant());
	}

	bool setRemoteBaseTime(const QVariant & arg0)
	{
		// 0x0083cff2 -> CMD 0x75ff
		sendEditor(m_result, 0x75ff, QVariant(), QVariant());
	}

	bool setRightClickAction(const QVariant & arg0)
	{
		// 0x0083d0a6
		void *cfg = globalQuery();   // FUN_0080c76e(0x11c2200)
		applyRightClick(cfg);   // FUN_0083d074
	}

	bool setScrollbackLimit(const QVariant & arg0)
	{
		// 0x0083d0c6 -> CMD 0x75f4
		sendEditor(m_result, 0x75f4, QVariant(), QVariant());
	}

	bool setTimestampFormat(const QVariant & arg0)
	{
		// 0x0083d2cc -> CMD 0x75fc
		sendEditor(m_result, 0x75fc, QVariant(), QVariant());
	}

	bool setTimestampLongFormat(const QVariant & arg0)
	{
		// 0x0083d34e -> CMD 0x75fe
		sendEditor(m_result, 0x75fe, QVariant(), QVariant());
	}

	bool startLogger(const QVariant & arg0)
	{
		// 0x008439ec
		// 会话感知 QString 复合体 — cited
		sessionStringOp(arg0);
	}


	bool stopLogger()
	{
		// 0x0083dc18: isConnected + 会话 FUN_007d377c(+0x118, +0x150, 0) + 释放 +0x150
		// 引用级占位,形态注记见 TERMINALWIDGET-IMPL.md
	}

	bool supportsDetectShellCwd()
	{
		// 0x0083dc72
		const void *sc = schemeRegistry();   // FUN_005b97cc
		return sc ? *((const unsigned char *)sc + 0x30) : 0;
	}

	void write(const QVariant & arg0, const QVariant & arg1)
	{
		// 0x0083e286
		// 静态初始化守卫 + FUN_009109fa 信号接线 — moc 基础设施
	}

	void write(const QVariant & arg0)
	{
		// 0x0083e286: 静态初始化守卫 + FUN_009109fa 信号接线
		// 引用级占位,形态注记见 TERMINALWIDGET-IMPL.md
	}
};

#endif // TERMINALWIDGET_H
