#ifndef TELNETSESSION_H
#define TELNETSESSION_H

#pragma once

#include "SuperSession.h"
#include "TelnetCommander.h"

#include <QByteArray>
#include <QTcpSocket>

class Screen;

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// Phase 4a:telnet 会话装配 —— QTcpSocket(传输)+ TelnetCommander(IAC
// 状态机 → Screen)。数据路径:socket.readyRead → IAC 状态机 → 解析器;
// RFC 默认拒绝策略在会话层(收到 DO x → WONT x、WILL x → DONT x),
// Commander 只记录选项状态、不发响应。
class TelnetSession : public SuperSession
{
	Q_OBJECT

public:
	TelnetSession(QObject *parent = nullptr);
	virtual ~TelnetSession(void) = default;

	void connectToHost(const QString &host, quint16 port);
	void disconnect();
	// 传输层真态(基类 isConnected 为 cited 虚查询,此处按 socket 状态)
	bool isConnected() const;
	bool write(const QByteArray &data);              // UI 输入 → socket
	void attachScreen(Screen *screen);               // 视图挂格子
	QTcpSocket *socket() { return &m_socket; }
	TelnetCommander *commander() { return &m_commander; }

signals:
	void dataReceived(const QByteArray &data);       // 解析后数据(UI 复制面)

private:
	Q_DISABLE_COPY(TelnetSession)

	void onReadyRead();
	QByteArray rfcReply(const QByteArray &in);       // IAC 拒绝响应字节

	QTcpSocket m_socket;
	TelnetCommander m_commander;
	QByteArray m_iacTail;                            // 半截 IAC 序列
};

#endif // TELNETSESSION_H
