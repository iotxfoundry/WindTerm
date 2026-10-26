#include "TelnetSession.h"

#include <QTcpSocket>

namespace {
// 客户端支持协商的选项：NAWS/TTYPE/SGA/BINARY（其余一律 WONT/DONT）
bool isSupported(uchar opt)
{
    return opt == TELOPT_NAWS || opt == TELOPT_TTYPE || opt == TELOPT_SGA
           || opt == TELOPT_BINARY;
}
} // namespace

TelnetSession::TelnetSession(const QString &target, int port, int rows, int columns,
                             QObject *parent)
    : Session(parent)
    , m_socket(new QTcpSocket(this))
    , m_rows(rows)
    , m_columns(columns)
{
    connect(m_socket, &QTcpSocket::connected, this, &TelnetSession::onConnected);
    connect(m_socket, &QTcpSocket::readyRead, this, &TelnetSession::onReadyRead);
    connect(m_socket, &QTcpSocket::disconnected, this, &TelnetSession::onDisconnected);
    // 错误路径（拒连/超时）：disconnected 不必然触发，errorOccurred 直达 finished
    connect(m_socket, &QTcpSocket::errorOccurred, this,
            [this](QAbstractSocket::SocketError) { finishOnce(); });

    m_socket->connectToHost(target, quint16(port));
}

TelnetSession::~TelnetSession() = default;

TelnetOption *TelnetSession::option(uchar opt, TelnetSide side)
{
    // 开源单例向量（call_once 初始化 NAWS/TTYPE/ECHO/SGA/BINARY 七项）
    for (TelnetOption &o : m_protocol.GetOptionVector()) {
        if (o.nTelnetOption == opt && o.eTelnetSide == side)
            return &o;
    }
    return nullptr;
}

void TelnetSession::setState(uchar opt, TelnetSide side, TelnetOptionState state)
{
    if (TelnetOption *o = option(opt, side))
        o->eOptionState = state;
}

void TelnetSession::sendCommand(uchar cmd, uchar opt)
{
    const uchar buf[3] = { TELCMD_IAC, cmd, opt };
    m_socket->write(reinterpret_cast<const char *>(buf), 3);
}

void TelnetSession::sendNaws()
{
    // RFC 1073：IAC SB NAWS W(16bit 大端) H(16bit 大端) IAC SE；字节=255 需 IAC 转义
    auto put16 = [this](int v) {
        const int hi = (v >> 8) & 0xFF;
        const int lo = v & 0xFF;
        m_socket->putChar(TELCMD_IAC);
        if (hi == TELCMD_IAC)
            m_socket->putChar(TELCMD_IAC);
        m_socket->putChar(hi);
        m_socket->putChar(lo);
    };
    m_socket->putChar(TELCMD_IAC);
    m_socket->putChar(TELCMD_SB);
    m_socket->putChar(TELOPT_NAWS);
    put16(m_columns);
    put16(m_rows);
    m_socket->putChar(TELCMD_IAC);
    m_socket->putChar(TELCMD_SE);
}

void TelnetSession::onConnected()
{
    // 按开源选项向量 Init 状态（INACTIVE_REQUESTED）主动协商：NAWS/TTYPE 是我方
    // WILL（TELNET_CLIENT 项），ECHO/SGA 是请对方开的 DO（TELNET_SERVER 项）
    sendCommand(TELCMD_WILL, TELOPT_NAWS);
    sendCommand(TELCMD_WILL, TELOPT_TTYPE);
    sendCommand(TELCMD_DO, TELOPT_ECHO);
    sendCommand(TELCMD_DO, TELOPT_SGA);
    sendNaws();
}

void TelnetSession::onReadyRead()
{
    m_pending += m_socket->readAll();
    QByteArray out;
    out.reserve(m_pending.size());
    int i = 0;
    while (i < m_pending.size()) {
        const uchar ch = uchar(m_pending.at(i));
        switch (m_state) {
        case Normal:
            if (ch == TELCMD_IAC)
                m_state = Iac;
            else
                out += char(ch);
            break;
        case Iac:
            if (ch == TELCMD_IAC) { // IAC IAC → 数据 0xFF 透传
                out += char(ch);
                m_state = Normal;
            } else if (ch == TELCMD_SB) {
                m_sb.clear();
                m_sbOption = 0;
                m_state = Sb;
            } else if (ch >= TELCMD_WILL && ch <= TELCMD_DONT) {
                m_command = ch;
                m_state = IacOpt;
            } else {
                m_state = Normal; // NOP/GA 等单字节命令：吞掉
            }
            break;
        case IacOpt:
            // WILL/WONT/DO/DONT + 选项 → 同策略回包；状态写回开源选项向量
            dispatchCommand(uchar(m_command), ch);
            m_state = Normal;
            break;
        case Sb:
            if (ch == TELCMD_IAC)
                m_state = SbIac;
            else
                m_sb += char(ch);
            break;
        case SbIac:
            if (ch == TELCMD_IAC) { // 子协商内转义的数据 0xFF
                m_sb += char(ch);
                m_state = Sb;
            } else { // SE：子协商结束（首字节=选项号，其余=体）
                handleSubnegotiation(m_sb.isEmpty() ? 0 : uchar(m_sb.at(0)),
                                     m_sb.mid(1));
                m_state = Normal;
            }
            break;
        }
        ++i;
    }
    if (!out.isEmpty())
        emit output(out);
    m_pending.clear();
}

void TelnetSession::dispatchCommand(uchar cmd, uchar opt)
{
    const bool yes = isSupported(opt);
    const bool amISender = (cmd == TELCMD_DO || cmd == TELCMD_DONT);
    // 状态写回：DO/WILL 确认激活，DONT/WONT 回落（REQUESTED 位清除）
    const TelnetOptionState st =
        (cmd == TELCMD_DO || cmd == TELCMD_WILL) ? TELOPT_STATE_ACTIVE
                                                 : TELOPT_STATE_INACTIVE;
    if (cmd == TELCMD_WILL || cmd == TELCMD_WONT) {
        setState(opt, TELNET_CLIENT, st);
        // 对端要开客户端侧选项：支持则 DO，否则 DONT
        sendCommand(yes ? TELCMD_DO : TELCMD_DONT, opt);
    } else {
        setState(opt, TELNET_SERVER, st);
        // 对端请求我方开服务端角色选项：支持则 WILL，否则 WONT
        sendCommand(yes ? TELCMD_WILL : TELCMD_WONT, opt);
    }
    Q_UNUSED(amISender);
}

void TelnetSession::handleSubnegotiation(uchar opt, const QByteArray &body)
{
    if (opt == TELOPT_TTYPE && !body.isEmpty() && uchar(body.at(0)) == TELSUB_SEND) {
        // RFC 1091：回 IS + 终端类型串（TERM 名挂账 "xterm"）
        QByteArray resp;
        resp += char(TELCMD_IAC);
        resp += char(TELCMD_SB);
        resp += char(TELOPT_TTYPE);
        resp += char(TELSUB_IS);
        resp += "xterm";
        resp += char(TELCMD_IAC);
        resp += char(TELCMD_SE);
        m_socket->write(resp);
    }
}

void TelnetSession::write(const QByteArray &data)
{
    // IAC 转义：0xFF→0xFF 0xFF（RFC 854）
    QByteArray esc;
    esc.reserve(data.size() * 2);
    for (char c : data) {
        esc += c;
        if (uchar(c) == TELCMD_IAC)
            esc += c;
    }
    m_socket->write(esc);
}

void TelnetSession::resize(int rows, int columns)
{
    m_rows = rows;
    m_columns = columns;
    if (m_socket->state() == QAbstractSocket::ConnectedState)
        sendNaws();
}

void TelnetSession::close()
{
    m_socket->disconnectFromHost();
}

void TelnetSession::onDisconnected()
{
    finishOnce();
}

void TelnetSession::finishOnce()
{
    if (!m_finished) {
        m_finished = true;
        emit finished();
    }
}
