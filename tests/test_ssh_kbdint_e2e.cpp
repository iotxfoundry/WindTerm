// kbdint 应答链真服务器端到端验证：asyncssh 本地服务器（tools/kbdint_server.py）
// 两轮 keyboard-interactive 挑战，SshSession 走完整 connectFlow：
//   worker kbdint()rc==3 → getnprompts/getprompt 探测 → kbdintNeeded(queued) →
//   测试程序化 kbdintAnswer(QMap)（绕过 QDialog）→ setanswer 逐项提交 → 再入
//   rc==3 第二轮 → 终认 rc==0 → channel/pty/shell → connected。
// 断言：connected 且 shell 回显含 e2e-ok；服务端记录的 answers 与回执逐项一致
// （含 UTF-8 值 "tokéns"）；取消路径 kbdintCancel → failed 链。
// 服务器起不来（python3/asyncssh 缺失/端口输出异常）→ SKIP 并打印原因。
#include <QApplication>
#include <QDir>
#include <QEventLoop>
#include <QFile>
#include <QMap>
#include <QProcess>
#include <QTimer>

#include <cstdio>

#include "core/SshSession.h"

static int g_failed = 0;
#define CHECK(ok, what)                                     \
    do {                                                    \
        if (ok)                                             \
            printf("PASS: %s\n", what);                     \
        else {                                              \
            printf("FAIL: %s\n", what);                     \
            ++g_failed;                                     \
        }                                                   \
    } while (0)

static QString g_homeTmp;

// ---- 服务器进程管理：起 tools/kbdint_server.py，读首行端口 ----
struct ServerProc
{
    QProcess proc;
    QString recordPath;
    bool start()
    {
        // 服务器脚本定位：CWD（build）与源码树双探测
        const QString here = QCoreApplication::applicationDirPath();
        for (const QString &cand : QStringList {
                 here + QStringLiteral("/../tools/kbdint_server.py"),
                 QStringLiteral("/home/pana/go/src/github.com/kingtoolbox/"
                                "WindTermGuiSkeleton/tools/kbdint_server.py") }) {
            if (QFile::exists(cand)) {
                recordPath = QStringLiteral("%1/kbdint-e2e-answers-%2.json")
                                 .arg(QDir::tempPath(),
                                      QString::number(QCoreApplication::applicationPid()));
                QFile::remove(recordPath);
                proc.setProgram(QStringLiteral("python3"));
                proc.setArguments({cand, recordPath});
                proc.start();
                if (!proc.waitForStarted(5000)) {
                    printf("SKIP: kbdint_server.py failed to start: %s\n",
                           qPrintable(proc.errorString()));
                    return false;
                }
                // 端口 = stdout 首行
                QByteArray line;
                for (int i = 0; i < 100 && !proc.canReadLine(); ++i) {
                    if (proc.state() != QProcess::Running) {
                        printf("SKIP: kbdint_server.py exited early: %s\n",
                               proc.readAllStandardError().constData());
                        return false;
                    }
                    proc.waitForReadyRead(100);
                }
                if (!proc.canReadLine()) {
                    printf("SKIP: kbdint_server.py no port on stdout (asyncssh missing?)\n");
                    proc.kill();
                    return false;
                }
                line = proc.readLine().trimmed();
                bool okNum = false;
                line.toInt(&okNum);
                if (!okNum || line.isEmpty()) {
                    printf("SKIP: kbdint_server.py bad port line: %s\n", line.constData());
                    proc.kill();
                    return false;
                }
                port = line.toInt();
                return true;
            }
        }
        printf("SKIP: kbdint_server.py not found\n");
        return false;
    }
    void stop()
    {
        if (proc.state() == QProcess::Running) {
            proc.kill();
            proc.waitForFinished(3000);
        }
    }
    int port = 0;
    QByteArray record() const
    {
        QFile f(recordPath);
        f.open(QIODevice::ReadOnly);
        return f.readAll();
    }
};

// 驱动一个会话到终局；answerMode：程序化答（两轮脚本化）/取消（首轮即 cancel）
static int driveSession(SshSession *s, int port, bool cancelFirstRound,
                        QString *failReason = nullptr)
{
    QEventLoop loop;
    int outcome = 2; // 0=connected 1=failed 2=timeout
    int roundSeen = 0;
    QObject::connect(s, &Session::output, [](const QByteArray &d) {
        fprintf(stderr, "OUT:%s", d.constData());
    });
    QObject::connect(s, &SshSession::hostKeyUnknown, s,
                     [&](const QString &, const QString &, bool) {
                         s->hostKeyAnswer(true); // 首连接受（临时 HOME→必 UNKNOWN）
                     });
    QObject::connect(s, &SshSession::kbdintNeeded,
                     [&](const QString &name, const QString &instruction,
                         const QStringList &prompts) {
                         ++roundSeen;
                         printf("  kbdint round %d: name='%s' instruction='%s' prompts=%s\n",
                                roundSeen, qPrintable(name), qPrintable(instruction),
                                qPrintable(prompts.join(QLatin1Char('|'))));
                         if (cancelFirstRound) {
                             s->kbdintCancel();
                             return;
                         }
                         // 程序化回执：label(trimmed)→值（含 UTF-8 样本）
                         QMap<QString, QString> answers;
                         if (prompts.contains(QLatin1String("Token:"))) {
                             answers.insert(QStringLiteral("Token:"), QStringLiteral("tokéns"));
                             answers.insert(QStringLiteral("Site:"), QStringLiteral("hq"));
                         } else {
                             answers.insert(QStringLiteral("Code:"), QStringLiteral("777"));
                         }
                         s->kbdintAnswer(answers);
                     });
    QObject::connect(s, &SshSession::connected, [&] {
        outcome = 0;
        loop.quit();
    });
    QObject::connect(s, &SshSession::failed, [&](const QString &why) {
        outcome = 1;
        if (failReason)
            *failReason = why;
        loop.quit();
    });
    QTimer::singleShot(30000, &loop, &QEventLoop::quit);
    s->start(QStringLiteral("127.0.0.1"), port, QStringLiteral("e2euser"), {});
    loop.exec();
    printf("  rounds seen: %d\n", roundSeen);
    return outcome;
}

int main(int argc, char **argv)
{
    // QApplication：onWorkerKbdint 主线程槽弹 QDialog（QWidget 需 GUI 实例；offscreen 平台）
    QApplication app(argc, argv);

    // HOME 指向可写临时目录（不碰用户真 known_hosts）
    g_homeTmp = QStringLiteral("%1/windterm-kbdint-e2e-%2")
                    .arg(QDir::tempPath(), QString::number(QCoreApplication::applicationPid()));
    QDir().mkpath(g_homeTmp);
    qputenv("HOME", g_homeTmp.toUtf8());

    // asyncssh --user 安装依赖 HOME 定位 user site-packages——测 HOME 改临时目录后
    // 给服务器进程显式补真实用户 site（QProcess 继承当前 env，但 HOME 已被换）
    qputenv("PYTHONPATH", "/home/pana/.local/lib/python3.12/site-packages");

    if (!SshSession::symbolsAvailable()) {
        printf("SKIP: libssh.so.4 not loadable\n");
        return 0;
    }

    ServerProc srv;
    if (!srv.start())
        return 0; // SKIP 已打印

    printf("server on 127.0.0.1:%d\n", srv.port);

    // ---- 场景 1：两轮程序化应答 → 终认成功 → shell 回显 e2e-ok ----
    {
        auto *s = new SshSession(24, 80, &app);
        const int rc = driveSession(s, srv.port, false);
        CHECK(rc == 0 && s->isConnected(),
              "E2E: kbdint two-round programmatic answers -> connected");
        if (rc == 0) {
            // shell 通道写一行，等 e2e-ok 回显（会话真实建立证据）
            QByteArray got;
            QEventLoop shellLoop;
            QObject::connect(s, &Session::output, [&](const QByteArray &d) {
                got += d;
                if (got.contains(QByteArrayLiteral("e2e-ok")))
                    shellLoop.quit();
            });
            s->write("probe\n");
            QTimer::singleShot(10000, &shellLoop, &QEventLoop::quit);
            shellLoop.exec();
            CHECK(got.contains("e2e-ok"), "E2E: shell channel alive (echo e2e-ok)");
        }
        s->close();
        delete s;
    }

    // ---- 场景 2：服务端记录的 answers 与回执逐项一致（含 UTF-8）----
    {
        const QByteArray rec = srv.record();
        printf("  server record:\n%s", rec.constData());
        CHECK(rec.contains("\"answers\": [\"tok\\u00e9ns\", \"hq\"]"),
              "E2E: server round-1 answers match (UTF-8 tokéns + hq)");
        CHECK(rec.contains("\"answers\": [\"777\"]"),
              "E2E: server round-2 answer matches (777)");
    }

    // ---- 场景 3：取消路径（首轮 kbdintCancel → failed 链）----
    {
        auto *s = new SshSession(24, 80, &app);
        QString why;
        const int rc = driveSession(s, srv.port, true, &why);
        CHECK(rc == 1, "E2E: kbdintCancel -> session failed");
        CHECK(!why.isEmpty(), "E2E: cancel produced failure reason (auth failed)");
        printf("  cancel reason: %s\n", qPrintable(why));
        s->close();
        delete s;
    }

    srv.stop();
    printf("SELFCHECK %s (%d failures)\n", g_failed == 0 ? "PASSED" : "FAILED", g_failed);
    return g_failed == 0 ? 0 : 1;
}
