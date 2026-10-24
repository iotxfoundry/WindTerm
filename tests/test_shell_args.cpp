// 复核 LocalSession 全参路径下 "-i -l" 真的成为 bash 的两个 argv（-l 生效=login shell）
// 本地 bash 依赖，缺则 SKIP
#include <QCoreApplication>
#include <QFile>
#include <QTimer>
#include <cstdio>
#include "core/LocalSession.h"

int main(int argc, char **argv)
{
    if (!QFile::exists(QStringLiteral("/bin/bash"))) {
        printf("SKIP: /bin/bash not available\n");
        return 0;
    }
    QCoreApplication app(argc, argv);
    auto *sh = new LocalSession(24, 80);
    QByteArray all;
    QObject::connect(sh, &Session::output, [&](const QByteArray &d) { all += d; });
    sh->start(QStringLiteral("/bin/bash"), QStringLiteral("-i -l"));
    QTimer::singleShot(800, [&]() {
        // login shell 会 source profile；shopt login_shell 回答 yes 证明 -l 生效
        sh->write("shopt -q login_shell && echo LOGIN_YES || echo LOGIN_NO\n");
    });
    QTimer::singleShot(1600, [&]() {
        sh->close();
    });
    // 判定与输出统一放 finish/超时两条路径之外：短轮询直至答案出现（上限 5s）
    int polls = 0;
    QTimer poll;
    poll.setInterval(100);
    QObject::connect(&poll, &QTimer::timeout, [&]() {
        if (!all.contains("LOGIN_YES") && !all.contains("LOGIN_NO") && ++polls < 50)
            return;
        poll.stop();
        const bool ok = all.contains("LOGIN_YES");
        printf("login_shell=%s\n", ok ? "YES(-l applied as separate argv)" : "NO");
        sh->close();
        printf("TEST_SHELL_ARGS %s (%d failures)\n", ok ? "PASSED" : "FAILED", ok ? 0 : 1);
        QCoreApplication::exit(ok ? 0 : 1);
    });
    poll.start();
    return app.exec();
}
