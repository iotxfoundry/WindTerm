// 会话装配冒烟(loop:Phase 4a 真接线):ShellSession::startLocal
// 进程 → pty → SuperCommander 解析 → Screen 格子(attachScreen 挂入)
#include <cstdio>
#include <csignal>
#include <unistd.h>
#include <QCoreApplication>
#include <QThread>
#include <QTimer>
#include "ShellSession.h"
#include "Screen.h"
#include "TerminalCore.h"

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    TerminalCore core; core.resizeCore(31, 89);
    core.m_flags |= 0x02;   // DECAWM
    Screen screen; screen.m_core = &core;

    ShellSession session;
    session.attachScreen(&screen);   // 视图挂格子
    if (!session.startLocal(QLatin1String("/bin/echo"),
                            QLatin1String("MARK_42 DONE42"),
                            QLatin1String("/tmp"))) {
        printf("startLocal FAIL\n");
        return 1;
    }
    QByteArray acc;
    QObject::connect(&session, &ShellSession::dataReceived,
                     [&](const QByteArray &d) { acc += d; });
    QTimer::singleShot(5000, [&] {
        printf("timeout: acc=%d bytes\n", acc.size());
        app.exit(2);
    });
    const int rc = app.exec();

    struct Row *r0 = core.row(0);
    QString row0;
    if (r0) {
        const unsigned short *heads = (const unsigned short *)r0->attrArray;
        for (int x = 0; x < r0->length; ++x)
            row0 += QChar(heads[x]);
    }
    printf("row0=%s\n", qPrintable(row0));
    int fails = 0;
    if (!row0.contains(QLatin1String("MARK_42 DONE42"))) {
        printf("row0 MARK_42 DONE42: FAIL\n");
        ++fails;
    }

    // stop 冒烟:/bin/sleep 5 → stop() 终止 pty 进程(3s 内退出)
    {
        ShellSession s2;
        if (!s2.startLocal(QLatin1String("/bin/sleep"), QLatin1String("5"),
                           QLatin1String("/tmp"))) {
            printf("startLocal sleep: FAIL\n");
            ++fails;
        } else {
            const qint64 pid = s2.pty()->pid();
            s2.stop();
            bool alive = ::kill((pid_t)pid, 0) == 0;
            for (int i = 0; i < 30 && alive; ++i) {   // 3s
                QThread::msleep(100);
                alive = ::kill((pid_t)pid, 0) == 0;
            }
            printf("stop: pid=%lld alive=%d\n", (long long)pid, alive ? 1 : 0);
            if (pid <= 0 || alive) {
                printf("stop sleep exit: FAIL\n");
                ++fails;
            }
        }
    }

    printf("shellsession_test fails=%d\n", fails);
    return fails != 0;
}
