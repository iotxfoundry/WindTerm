#ifndef SHELLSESSION_H
#define SHELLSESSION_H

#pragma once

#include "SuperSession.h"
#include "../Pty/UnixPty.h"

#include "SuperCommander.h"
class Screen;

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// Phase 4a:本地会话装配 —— UnixPty(进程传输)+ SuperCommander(ANSI
// 解析 → Screen)数据路径:pty.readyRead → 解析器;write → pty。
// Screen 由视图侧 attachScreen 挂入(会话不持有格子)。
class ShellSession : public SuperSession
{
	Q_OBJECT

public:
	ShellSession(QObject *parent = nullptr);
	virtual ~ShellSession(void);

	// 本地会话:起 shell 进程并接通数据路径;成功后
	// dataReceived 携带进程输出(已过解析器)
	bool startLocal(const QString &shell, const QString &arguments,
	                const QString &workingDirectory);
	bool write(const QByteArray &data);              // UI 输入 → pty
	void stop();                                     // 会话停止:pty + 数据路径
	void attachScreen(Screen *screen);               // 视图挂格子
	UnixPty *pty() { return &m_pty; }
	SuperCommander *commander() { return &m_commander; }

signals:
	void dataReceived(const QByteArray &data);       // 解析后数据(UI 复制面)

private:
	Q_DISABLE_COPY(ShellSession)

	UnixPty m_pty;
	SuperCommander m_commander;
	QMetaObject::Connection m_ptyConn;   // readyRead → 解析器(停止时断)
};

#endif // SHELLSESSION_H
