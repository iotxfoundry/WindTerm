// 鼠标模式回归（原 /tmp/opencode/f2diag/mousetest.cpp）：本地 bash 依赖，缺则 SKIP
#include <QCoreApplication>
#include <QFile>
#include <QTimer>
#include <cstdio>
#include "core/LocalSession.h"
#include "core/ScreenModel.h"
#include "core/VtParser.h"

static int g_failed = 0;
static void check(bool ok, const char *what)
{
    std::printf("%s %s\n", ok ? "PASS" : "FAIL", what);
    if (!ok)
        ++g_failed;
}
int main(int argc, char **argv) {
    if (!QFile::exists(QStringLiteral("/bin/bash"))) {
        std::printf("SKIP: /bin/bash not available\n");
        return 0;
    }
    QCoreApplication app(argc, argv);
    auto *session = new LocalSession(40, 120);
    auto *screen = new ScreenModel(40, 120);
    auto *parser = new VtParser(screen);
    QObject::connect(session, &Session::output, [&](const QByteArray &d) { parser->feed(d); });
    if (!session->start("/bin/bash", "-i"))
        return 2;
    QTimer::singleShot(600, [&] { session->write("clear; vim -u NONE -c 'set mouse=a' /etc/hostname\n"); });
    QTimer::singleShot(2200, [&] {
        std::printf("mouse1000=%d mouse1006=%d alt=%d\n",
                    screen->mode(1000) ? 1 : 0, screen->mode(1006) ? 1 : 0,
                    screen->alternateScreen() ? 1 : 0);
        check(screen->mode(1000), "vim mouse=a enables mode 1000");
        check(screen->mode(1006), "SGR mouse mode 1006 enabled");
        check(screen->alternateScreen(), "vim in alt screen");
        session->write("\x1b[<0;5;1M");  // 模拟 view 发出的 SGR 点击(col5,row1)
        session->write("\x1b[<64;1;1M"); // 滚轮上
        QTimer::singleShot(500, [&] {
            session->write(":q!\r");
            QTimer::singleShot(400, [&] {
                const bool altOut = screen->alternateScreen();
                std::printf("exit alt=%d\n", altOut);
                check(!altOut, ":q! restores main screen");
                session->close();
                std::printf("TEST_TERMINAL_MOUSE %s (%d failures)\n",
                            g_failed == 0 ? "PASSED" : "FAILED", g_failed);
                QTimer::singleShot(300, [&] {
                    session->deleteLater();
                    QCoreApplication::exit(g_failed == 0 ? 0 : 1);
                });
            });
        });
    });
    return app.exec();
}
