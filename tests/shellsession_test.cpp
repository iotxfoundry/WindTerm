// 会话装配冒烟(loop goal):UnixPty + SuperCommander + Screen 端到端
// 进程 → pty → ANSI 解析 → 屏幕格子 —— 会话数据路径首次贯通
#include <cstdio>
#include <QCoreApplication>
#include <QTimer>
#include "UnixPty.h"
#include "SuperCommander.h"
#include "Screen.h"
#include "TerminalCore.h"

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    TerminalCore core; core.resizeCore(31, 89);
    core.m_flags |= 0x02;   // DECAWM
    Screen screen; screen.m_core = &core;
    SuperCommander cmd; cmd.m_screen = &screen;

    UnixPty pty;
    if (!pty.createProcess(QLatin1String("/bin/echo"),
                           QLatin1String("MARK_42 DONE42"),
                           QLatin1String("/tmp"), QProcessEnvironment(),
                           31, 89)) {
        printf("createProcess FAIL: %s\n", qPrintable(pty.errorString()));
        return 1;
    }

    QByteArray acc;
    QObject::connect(&pty, &Pty::readyRead, [&] {
        const QByteArray d = pty.readAll();
        acc += d;
        cmd.processOutput(d);   // 会话数据路径:pty → 解析器 → Screen
    });
    QObject::connect(&pty, &Pty::errorOccurred, [&] { app.exit(3); });

    QTimer::singleShot(5000, [&] {
        printf("timeout: acc=%d bytes\n", acc.size());
        app.exit(2);
    });

    const int rc = app.exec();
    // 屏幕格子校验:两条标记行(ANSI 解析后的 Screen 状态)
    struct Row *r0 = core.row(0);
    struct Row *r1 = core.row(1);
    auto rowText = [](struct Row *r) {
        QString s;
        if (!r) return s;
        const unsigned short *heads = (const unsigned short *)r->attrArray;
        for (int x = 0; x < r->length; ++x)
            s += QChar(heads[x]);
        return s;
    };
    const QString l0 = rowText(r0);
    const QString l1 = rowText(r1);
    printf("row0=%s\n", qPrintable(l0));
    int fails = 0;
    if (!l0.contains(QLatin1String("MARK_42"))) {
        printf("row0 MARK_42: FAIL\n");
        ++fails;
    }
    if (!l0.contains(QLatin1String("DONE42"))) {
        printf("row0 DONE42: FAIL\n");
        ++fails;
    }
    printf("shellsession_test fails=%d\n", fails);
    return fails != 0;
}
