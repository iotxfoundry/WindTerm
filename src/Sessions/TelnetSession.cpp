#include "TelnetSession.h"
#include "Screen.h"

TelnetSession::TelnetSession(QObject *parent)
	: SuperSession(parent)
	, m_commander()
{
	m_commander.m_screen = nullptr;
	QObject::connect(&m_socket, &QTcpSocket::readyRead, this,
	                 &TelnetSession::onReadyRead);
	// 连接即主动协商(实验锚 client_init:accept 后静默窗首包 =
	// init 原字节;批 33 响应策略入 Commander,会话层纯转发)
	QObject::connect(&m_socket, &QTcpSocket::connected, this, [this] {
		const QByteArray init = m_commander.initialNegotiation();
		if (!init.isEmpty())
			m_socket.write(init);
	});
	// 协商回写(Commander 生成,实验锚字节)
	QObject::connect(&m_commander, &TelnetCommander::negotiationReply,
	                 this, [this](const QByteArray &r) {
		                 if (!r.isEmpty())
		                 m_socket.write(r);
	         });
}

void TelnetSession::connectToHost(const QString &host, quint16 port)
{
	m_socket.connectToHost(host, port);
}

void TelnetSession::disconnect()
{
	m_socket.disconnectFromHost();
	m_commander.m_screen = nullptr;
}

bool TelnetSession::isConnected() const
{
	return m_socket.state() == QAbstractSocket::ConnectedState;
}

bool TelnetSession::write(const QByteArray &data)
{
	return m_socket.write(data) == data.size();
}

void TelnetSession::attachScreen(Screen *screen)
{
	m_commander.m_screen = screen;
}

void TelnetSession::onReadyRead()
{
	const QByteArray in = m_socket.readAll();
	if (in.isEmpty())
		return;
	// IAC 握手在 Commander(feed → 槽/信号 + 协商回写);非协议
	// 字节直通解析器
	const QByteArray data = m_commander.feed(in);
	if (data.isEmpty() == false) {
		m_commander.processOutput(data);   // 会话数据路径:状态机 → 解析器
		emit dataReceived(data);
	}
}
