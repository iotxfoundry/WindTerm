// telnet 会话装配冒烟(loop:Phase 4a 网络接线 + 批 33 协商策略):
// 本地 QTcpServer 回环,断言 = 实验锚 telnet_capture.json 原版字节。
#include <cstdio>
#include <QCoreApplication>
#include <QEventLoop>
#include <QTimer>
#include <QTcpServer>
#include <QTcpSocket>
#include "TelnetSession.h"
#include "Screen.h"
#include "TerminalCore.h"

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    QTcpServer server;
    if (!server.listen(QHostAddress::LocalHost, 0)) {
        printf("listen FAIL\n");
        return 1;
    }
    QByteArray got;   // 服务端收到(客户端协商响应)

    QObject::connect(&server, &QTcpServer::newConnection, [&] {
        QTcpSocket *peer = server.nextPendingConnection();
        QObject::connect(peer, &QTcpSocket::readyRead,
                         [&, peer] { got += peer->readAll(); });
        // 探针序列(捕获实验同款):DO 24 / WILL 3 / DO 31 /
        // SB TTYPE send / DO 39 + 文本(踩坑 #18 显式长度)
        static const char lit[] =
            "\xff\xfd\x18"                       // IAC DO 24 (TTYPE)
            "\xff\xfb\x03"                       // IAC WILL 3 (SGA)
            "\xff\xfd\x1f"                       // IAC DO 31 (NAWS)
            "\xff\xfa\x18\x01\xff\xf0"           // IAC SB 24,1 IAC SE
            "\xff\xfd\x27"                       // IAC DO 39 (NEW-ENV)
            "hello";
        peer->write(QByteArray(lit, sizeof(lit) - 1));
    });

    TelnetSession session;
    TerminalCore core;
    core.resizeCore(31, 89);                     // NAWS 断言:89x31
    Screen s;
    s.m_core = &core;
    session.attachScreen(&s);
    QByteArray acc;
    QObject::connect(&session, &TelnetSession::dataReceived,
                     [&](const QByteArray &d) { acc += d; });
    session.connectToHost(QLatin1String("127.0.0.1"), server.serverPort());

    QEventLoop loop;
    QTimer poll;
    poll.setInterval(20);
    QObject::connect(&poll, &QTimer::timeout, [&] {
        if (got.contains("hello"))
            loop.quit();
    });
    poll.start();
    QTimer::singleShot(3000, &loop, &QEventLoop::quit);   // 硬超时
    loop.exec();

    int fails = 0;
    printf("reply=%s\n", got.toHex().constData());
    // 1) 连接主动协商 = 捕获 client_init 原字节
    const QByteArray init = QByteArrayLiteral(
        "\xff\xfb\x1f\xff\xfb\x18\xff\xfd\x01\xff\xfd\x03\xff\xfb\x03");
    fails += !got.startsWith(init);
    printf("init negotiation: %s\n",
           got.startsWith(init) ? "OK" : "FAIL");
    // 2) DO 24 → 重发 init(捕获:response[0] got == init)
    fails += got.mid(init.size()).contains(init) == false;
    printf("DO24 resend init: %s\n",
           got.mid(init.size()).contains(init) ? "OK" : "FAIL");
    // 3) WILL 3 → 不应(捕获:got="");总长自洽(无 ff fe 03)
    fails += got.contains(QByteArray("\xff\xfe\x03", 3));
    printf("WILL3 silent: %s\n",
           !got.contains(QByteArray("\xff\xfe\x03", 3)) ? "OK" : "FAIL");
    // 4) DO 31 → SB NAWS 0 cols rows SE(89=0x59,31=0x1f)
    const QByteArray naws = QByteArrayLiteral(
        "\xff\xfa\x1f\x00\x59\x1f\xff\xf0");
    fails += !got.contains(naws);
    printf("NAWS 89x31: %s\n", got.contains(naws) ? "OK" : "FAIL");
    // 5) SB TTYPE send → SB 24,0 "xterm-256color" SE(捕获原字节)
    const QByteArray tt = QByteArrayLiteral(
        "\xff\xfa\x18\x00xterm-256color\xff\xf0");
    fails += !got.contains(tt);
    printf("TTYPE xterm-256color: %s\n",
           got.contains(tt) ? "OK" : "FAIL");
    // 6) DO 39 → WONT 39(捕获 fffc27)
    fails += !got.contains(QByteArray("\xff\xfc\x27", 3));
    printf("DO39 WONT: %s\n",
           got.contains(QByteArray("\xff\xfc\x27", 3)) ? "OK" : "FAIL");
    // 7) 数据路径:文本到 dataReceived
    if (!acc.contains("hello")) {
        printf("dataReceived hello: FAIL\n");
        ++fails;
    }
    session.disconnect();
    printf("telnetsocket_test fails=%d\n", fails);
    return fails != 0;
}
