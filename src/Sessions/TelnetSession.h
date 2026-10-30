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
// 状态机 → Screen)。数据路径:socket.readyRead → feed → 解析器;
// 协商响应由 Commander 生成(实验锚 telnet_capture.json,批 33),
// 会话层仅转发(negotiationReply → socket;connected → 初始协商)。
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

	QTcpSocket m_socket;
	TelnetCommander m_commander;
};

#endif // TELNETSESSION_H
