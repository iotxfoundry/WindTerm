// telnet 会话装配冒烟(loop:Phase 4a 网络接线):本地 QTcpServer 回环
// server 发 IAC DO 24 + IAC WILL 3 + 文本 → 会话层回 WONT/DONT,
// 文本经 IAC 状态机到 dataReceived。
#include <cstdio>
#include <QCoreApplication>
#include <QEventLoop>
#include <QTimer>
#include <QTcpServer>
#include <QTcpSocket>
#include "TelnetSession.h"

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
        // 含 \x00 的流也用显式长度(踩坑 #18)
        static const char lit[] = "\xff\xfd\x18"   // IAC DO 24
                                  "\xff\xfb\x03"   // IAC WILL 3
                                  "hello";
        peer->write(QByteArray(lit, sizeof(lit) - 1));
    });

    TelnetSession session;
    QByteArray acc;
    QObject::connect(&session, &TelnetSession::dataReceived,
                     [&](const QByteArray &d) { acc += d; });
    session.connectToHost(QLatin1String("127.0.0.1"), server.serverPort());

    QEventLoop loop;
    QTimer poll;
    poll.setInterval(20);
    QObject::connect(&poll, &QTimer::timeout, [&] {
        if (got.size() >= 6 && acc.contains("hello"))
            loop.quit();
    });
    poll.start();
    QTimer::singleShot(3000, &loop, &QEventLoop::quit);   // 硬超时
    loop.exec();

    int fails = 0;
    const QByteArray expect = QByteArray("\xff\xfc\x18"    // WONT 24
                                         "\xff\xfe\x03",6); // DONT 3
    printf("reply=%s (sz=%d)\n", got.toHex().constData(), got.size());
    if (got.startsWith(expect) == false) {
        printf("WONT/DONT reply: FAIL\n");
        ++fails;
    }
    printf("acc=%s\n", acc.constData());
    if (!acc.contains("hello")) {
        printf("dataReceived hello: FAIL\n");
        ++fails;
    }
    session.disconnect();
    printf("telnetsocket_test fails=%d\n", fails);
    return fails != 0;
}
