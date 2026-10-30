// Pty 冒烟(loop Iter4):UnixPty createProcess → write → readAll
#include <cstdio>
#include <QCoreApplication>
#include <QTimer>
#include "UnixPty.h"

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    UnixPty pty;
    QString err;
    // sh -c:回显一行标记(登录态冒烟;rows/cols 常规)
    if (!pty.createProcess(QLatin1String("/bin/echo"),
                           QLatin1String("PTY_SMOKE_42"),
                           QLatin1String("/tmp"), QProcessEnvironment(),
                           24, 80)) {
        printf("createProcess: FAIL (%s)\n",
               qPrintable(pty.errorString()));
        return 1;
    }
    QByteArray acc;
    QTimer::singleShot(3000, [&] {
        printf("timeout: acc=%s\n", acc.constData());
        app.exit(2);
    });
    QObject::connect(&pty, &Pty::readyRead, [&] {
        acc += pty.readAll();
        if (acc.contains("PTY_SMOKE_42")) {
            printf("PTY_SMOKE_42: OK (acc=%d bytes)\n", acc.size());
            app.exit(0);
        }
    });
    pty.write(QByteArray("\n"));   // 触发输出冲洗
    const int rc = app.exec();
    printf("exit=%d fails=%d\n", rc, acc.contains("PTY_SMOKE_42") ? 0 : 1);
    return acc.contains("PTY_SMOKE_42") ? 0 : 1;
}
