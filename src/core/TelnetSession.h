#pragma once

#include <QByteArray>
#include <QString>

#include "Session.h"
#include "protocols/TelnetProtocol.h"

// 协商循环：开源仓库 TelnetProtocol 仅提供命令/选项表与选项状态向量（GetOptionVector），
// 协商逻辑属闭源 Session 层未开源——本类按 RFC 854/855 标准实现，选项状态走开源向量。
class TelnetSession : public Session
{
    Q_OBJECT

public:
    TelnetSession(const QString &target, int port, int rows, int columns,
                  QObject *parent = nullptr);
    ~TelnetSession() override;

    // 透传前 IAC 转义（0xFF→0xFF 0xFF）。简化：无论 BINARY 是否协商成功都转义
    //（RFC 856 边界：BINARY 激活后应透传 0xFF，真机 BINARY 会话出问题再分状态）
    void write(const QByteArray &data) override;
    void resize(int rows, int columns) override;
    void close() override;

private slots:
    void onConnected();
    void onReadyRead();
    void onDisconnected();

private:
    // 命令流字节状态机（RFC 854）：Normal 数据 / Iac 见 IAC / IacOpt 等
    // WILL/WONT/DO/DONT 后的选项字节 / Sb 收子协商体 / SbIac 收 SB 内转义或 SE
    enum ParseState { Normal, Iac, IacOpt, Sb, SbIac };

    TelnetOption *option(uchar opt, TelnetSide side);
    void setState(uchar opt, TelnetSide side, TelnetOptionState state);
    void sendCommand(uchar cmd, uchar opt);
    void sendNaws();
    void dispatchCommand(uchar cmd, uchar opt);
    void handleSubnegotiation(uchar opt, const QByteArray &body);
    void finishOnce();

    class QTcpSocket *m_socket;
    ParseState m_state = Normal;
    QByteArray m_pending;
    QByteArray m_sb;
    int m_sbOption = 0;
    int m_command = 0; // IacOpt 态等待选项字节时的 WILL/WONT/DO/DONT
    int m_rows;
    int m_columns;
    TelnetProtocol m_protocol; // GetOptionVector 为成员函数，需实例持向量单例
    bool m_finished = false;
};
