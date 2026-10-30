#include "TelnetSession.h"
#include "Screen.h"

namespace {
constexpr unsigned char kIac = 0xff;   // telnet.protocol refs 默认(IAC)
constexpr unsigned char kSb = 0xfa;    // SB
constexpr unsigned char kSe = 0xf0;    // SE
constexpr unsigned char kWill = 0xfb;
constexpr unsigned char kWont = 0xfc;
constexpr unsigned char kDo = 0xfd;
constexpr unsigned char kDont = 0xfe;
} // namespace

TelnetSession::TelnetSession(QObject *parent)
	: SuperSession(parent)
	, m_commander()
{
	m_commander.m_screen = nullptr;
	QObject::connect(&m_socket, &QTcpSocket::readyRead, this,
	                 &TelnetSession::onReadyRead);
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
	// 1) 会话层协商响应(RFC 854 默认拒绝);2) 整段原始流进 IAC 状态机
	const QByteArray reply = rfcReply(in);
	if (reply.isEmpty() == false)
		m_socket.write(reply);
	const QByteArray data = m_commander.feed(in);
	if (data.isEmpty() == false) {
		m_commander.processOutput(data);   // 会话数据路径:状态机 → 解析器
		emit dataReceived(data);
	}
}

// RFC 854 默认拒绝:DO x → WONT x,WILL x → DONT x;WONT/DONT 不回。
// IAC IAC = 字面 0xFF;IAC SB … IAC SE 整段跳过;半截序列留 m_iacTail。
QByteArray TelnetSession::rfcReply(const QByteArray &in)
{
	m_iacTail += in;
	QByteArray out;
	int i = 0;
	while (i < m_iacTail.size()) {
		if ((unsigned char)m_iacTail[i] != kIac) {
			++i;
			continue;
		}
		if (i + 1 >= m_iacTail.size())
			break;                                  // 半截 IAC
		const unsigned char cmd = (unsigned char)m_iacTail[i + 1];
		if (cmd == kIac) {
			i += 2;
			continue;
		}
		if (cmd == kSb) {
			int se = -1;
			for (int j = i + 2; j + 1 < m_iacTail.size(); ++j)
				if ((unsigned char)m_iacTail[j] == kIac &&
				    (unsigned char)m_iacTail[j + 1] == kSe) {
					se = j;
					break;
				}
			if (se < 0)
				break;                          // 子协商未闭合
			i = se + 2;
			continue;
		}
		if (cmd == kWill || cmd == kDo) {
			if (i + 2 >= m_iacTail.size())
				break;                          // 缺 option 字节
			out += (char)kIac;
			out += (char)(cmd == kDo ? kWont : kDont);
			out += m_iacTail[i + 2];
			i += 3;
			continue;
		}
		if (cmd == kWont || cmd == kDont) {
			if (i + 2 >= m_iacTail.size())
				break;
			i += 3;
			continue;
		}
		i += 2;                                     // 其他 2 字节命令
	}
	m_iacTail = m_iacTail.mid(i);
	return out;
}
