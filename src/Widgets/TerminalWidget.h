#ifndef TERMINALWIDGET_H
#define TERMINALWIDGET_H

#pragma once

// 终端部件组装(TERMINALWIDGET-IMPL.md;metacall 0x910a98,idx 即该表)。
// 本轮落地"守卫+查询"组——形态一律为 Screen 栈守卫 + 既有
// Screen/SuperSession 方法调用;渲染/输入/日志/modem 组随后续轮次。

#include "SuperCommander.h"

#include <QWidget>

class TerminalWidget : public QWidget
{
	Q_OBJECT

public:
	explicit TerminalWidget(QWidget *parent = nullptr);

	// Screen 栈装配(会话创建时注入;对应 +0x118/+0x118 守卫的来源)
	void setCommander(SuperCommander *commander) { m_commander = commander; }
	SuperCommander *commander() const { return m_commander; }

	// --- 状态查询组(moc idx → TERMINALWIDGET-IMPL 表)---
	bool isAltScreen() const;      // idx 34 → 0083c4c8 → FUN_007e4028(+0x139)
	bool isMainScreen() const;     // idx 41 → 0083c696(取反)
	bool isConnected() const;      // idx 35 → 0083c524(FUN_007d6736)
	bool isUnconnected() const;    // idx 44 → 0083c6fc(FUN_007d6722)
	QString protocolName() const;  // idx 53 → 0083cb0c(FUN_007d5d2a)

	// --- 复位组(Screen 栈守卫 → sendScreenCommand)---
	// --- 输入/清屏组 ---
	void write(const QString &text);            // idx 74/75 → 0083e286
	void clearScreen();                         // idx 22 → 00840438
	void clearScreenAndScrollback();            // idx 23 → 00840532
	void clearScrollback();                     // idx 24 → 0083fc2c
	void setTmuxMode(bool on) { m_tmuxMode = on; }   // 标志 0x160

	void resetCharacterSet();      // idx 56 → 0083cbc8(命令 6)
	void resetHard();              // idx 57 → 0083cc00(命令 7)
	void resetSoft();              // idx 58 → 0083cc38(FUN_007e33ea)

private:
	SuperCommander *m_commander = nullptr;
	bool m_tmuxMode = false;       // +0x160 tmux 状态标志
};

#endif // TERMINALWIDGET_H
