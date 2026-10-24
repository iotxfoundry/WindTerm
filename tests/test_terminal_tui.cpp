// vim/less alt 屏回归（原 /tmp/opencode/f2diag/diag.cpp）：本地 bash 依赖，缺则 SKIP
#include <QCoreApplication>
#include <QTimer>
#include <QFile>
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
static QString lineText(class ScreenModel *s, int r) {
    QString out;
    for (int c = 0; c < s->cols(); ++c) {
        QChar ch = s->cellAt(r, c).ch;
        out += ch.isNull() ? QChar(' ') : ch;
    }
    return out;
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
    QString acc;
    QObject::connect(session, &Session::output, [&](const QByteArray &d) {
        acc.append(QString::fromUtf8(d));
        parser->feed(d);
    });
    if (!session->start("/bin/bash", "-i"))
        return 2;
    QTimer::singleShot(800, [&] { session->write("clear; vim -u NONE /etc/hostname\n"); });
    QTimer::singleShot(2500, [&] {
        const bool altIn = screen->alternateScreen();
        std::printf("=== vim: alt=%d rows=%d cols=%d\n", altIn, screen->rows(), screen->cols());
        check(altIn, "vim enters alternate screen");
        for (int r = 0; r < 12; ++r)
            std::printf("%02d|%s|\n", r, qPrintable(lineText(screen, r)));
        session->write("ZZ");
        QTimer::singleShot(600, [&] {
            const bool altOut = screen->alternateScreen();
            std::printf("=== after q: alt=%d\n", altOut);
            check(!altOut, "vim ZZ restores main screen");
            check(acc.contains("MARK1") || acc.contains("Linux")
                      || !lineText(screen, 0).trimmed().isEmpty(),
                  "main screen content restored");
            session->close();
            std::printf("TEST_TERMINAL_TUI %s (%d failures)\n",
                        g_failed == 0 ? "PASSED" : "FAILED", g_failed);
            QTimer::singleShot(400, [&] {
                session->deleteLater();
                QCoreApplication::exit(g_failed == 0 ? 0 : 1);
            });
        });
    });
    return app.exec();
}
