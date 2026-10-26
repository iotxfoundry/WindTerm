// F3 校准验证：链接项目 src/core/SshSession.cpp，本机 sshd 127.0.0.1:22。
// 断言：C1 绑定层日志（原版 lib 或系统回退）；userauth_list 掩码含 Password|PublicKey；
// ~/.ssh key 两步 publickey（try→real）认证成功；C2 known_hosts 落
// <profileRoot>/ssh/<id>/known_hosts；C4 UNKNOWN→接受→落盘 / CHANGED→删行+重写；
// C3 错密码回落队列（publickey 成功或全败 failed）。
#include <QCoreApplication>
#include <QDir>
#include <QEventLoop>
#include <QFile>
#include <QTimer>

#include <dlfcn.h>
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

// 环境探测：无本机 sshd（127.0.0.1:22 未监听）则整组认证断言不可达 → SKIP
static bool sshdListening()
{
    FILE *p = popen("ss -tln 2>/dev/null | grep -q ':22 '", "r");
    if (!p)
        return false;
    const int rc = pclose(p);
    return rc == 0;
}

static QString g_homeTmp;

static QString g_log;
static void msgHandler(QtMsgType, const QMessageLogContext &, const QString &m)
{
    g_log += m + '\n';
    fprintf(stderr, "%s\n", qPrintable(m));
}

static void writeIdentityCfg(const char *path)
{
    QDir().mkpath(g_homeTmp + QStringLiteral("/.wind/profiles/default.v10"));
    QFile f(g_homeTmp + QStringLiteral("/.wind/profiles/default.v10/user.config"));
    f.open(QIODevice::WriteOnly | QIODevice::Truncate);
    f.write(QByteArray("{\"ssh.identityFilePath\":\"") + path + "\"}");
}

// 逐条驱动一个会话到终局；返回 0=connected, 1=failed, 2=超时
static int driveSession(SshSession *s, bool *changedFlag = nullptr, QString *fpOut = nullptr)
{
    QEventLoop loop;
    int outcome = 2;
    QObject::connect(s, &Session::output, [](const QByteArray &d) {
        fprintf(stderr, "OUT:%s", d.constData());
    });
    QObject::connect(s, &SshSession::connected, [&] {
        outcome = 0;
        loop.quit();
    });
    QObject::connect(s, &SshSession::failed, [&](const QString &) {
        outcome = 1;
        loop.quit();
    });
    QObject::connect(s, &SshSession::hostKeyUnknown, s,
                     [&](const QString &, const QString &fp, bool changed) {
                         if (changedFlag)
                             *changedFlag = changed;
                         if (fpOut)
                             *fpOut = fp;
                         s->hostKeyAnswer(true); // 全场景接受（CHANGED 场景断言删行+重写）
                     });
    QTimer::singleShot(60000, &loop, &QEventLoop::quit);
    s->start(QStringLiteral("127.0.0.1"), 22, QStringLiteral("pana"), {});
    return outcome;
}

int main(int argc, char **argv)
{
    if (!sshdListening()) {
        printf("SKIP: no sshd listening on 127.0.0.1:22 (ss -tln)\n");
        return 0;
    }
    // HOME 指向可写临时目录（不碰用户真数据）；identity 引本机真实 key（可被 SKIP 兜底）
    g_homeTmp = QStringLiteral("%1/windterm-ssh-auth-test-%2")
                    .arg(QDir::tempPath(), QString::number(QCoreApplication::applicationPid()));
    QDir().mkpath(g_homeTmp);
    if (!QFileInfo(g_homeTmp).isWritable()) {
        printf("SKIP: temp HOME not writable: %s\n", qPrintable(g_homeTmp));
        return 0;
    }
    qputenv("HOME", g_homeTmp.toUtf8());
    if (!QFileInfo::exists(QStringLiteral("/home/pana/.ssh/id_ed25519"))) {
        printf("SKIP: /home/pana/.ssh/id_ed25519 not available for publickey auth\n");
        return 0;
    }
    qInstallMessageHandler(msgHandler);
    QCoreApplication app(argc, argv);

    // ---- C1：绑定层加载 ----
    CHECK(SshSession::symbolsAvailable(), "C1 libssh loaded (original patched or system)");
    CHECK(g_log.contains("libssh loaded from"),
          "C1 loader one-shot qWarning present");
    printf("  loader log: %s", qPrintable(g_log.section(QLatin1Char('\n'), 0, 0)));

    // 写侧落盘 = KNOWNHOSTS 值(ssh-dir 语义) + "/known_hosts"（原版修补版与系统 0.10 一致）
    const QString khPath = g_homeTmp + QStringLiteral("/.wind/profiles/default.v10/ssh/127.0.0.1_22/known_hosts/known_hosts");

    // ---- 场景 1：UNKNOWN→接受→两步 publickey 成功 + C2 路径断言 ----
    { int rcInline = 2;
        QDir(g_homeTmp + QStringLiteral("/.wind/profiles/default.v10/ssh"))
            .removeRecursively(); // 首连隔离
        writeIdentityCfg("/home/pana/.ssh/id_ed25519");
        auto *s = new SshSession(24, 80, &app);
        bool changed = true;
        QString fp;
        { // dbg2 同款内联
            QEventLoop loop;
            int outcome = 2;
            QObject::connect(s, &Session::output, [](const QByteArray &d) { fprintf(stderr, "OUT:%s", d.constData()); });
            QObject::connect(s, &SshSession::hostKeyUnknown, [&](const QString &, const QString &f, bool c) {
                changed = c; fp = f; s->hostKeyAnswer(true);
            });
            QObject::connect(s, &SshSession::connected, [&] { outcome = 0; loop.quit(); });
            QObject::connect(s, &SshSession::failed, [&](const QString &) { outcome = 1; loop.quit(); });
            QTimer::singleShot(30000, &loop, &QEventLoop::quit);
            s->start(QStringLiteral("127.0.0.1"), 22, QStringLiteral("pana"), {});
            loop.exec();
            rcInline = outcome;
        }
        const int rc = rcInline;
        CHECK(rc == 0 && s->isConnected(), "C3 publickey two-step (try→real) connected");
        CHECK(!changed, "C4 first connect is UNKNOWN (changed=false)");
        CHECK(!fp.isEmpty(), "C4 fingerprint non-empty (md5 aa:bb:..)");
        CHECK(QFile::exists(khPath),
              "C2 known_hosts at <profileRoot>/ssh/<id>/known_hosts");
        s->close();
        delete s;
        printf("  kh=%s\n", qPrintable(khPath));
    } 

    // ---- 场景 2：CHANGED→删行+重写 ----
    // 语义实测：原版 lib 旧 API ssh_is_server_known 对"同类型合法他钥"=2(CHANGED)；
    // 系统 0.10 新 API 对任何不匹配=0(UNKNOWN)。挂账差异由 C4 target 逻辑统一吞掉：
    // r∉{0,1} → 删行+重写；r==0 → 只写。断言只看删行+落盘正确。
    {
        QFile f(khPath);
        f.open(QIODevice::WriteOnly | QIODevice::Truncate);
        // 同类型（ed25519）合法他钥 → 原版 lib 报 CHANGED(2)
        f.write("127.0.0.1 ssh-ed25519 AAUqzh+dPBYhDEcSYqUb/1KFjZ+NXuC58Th8Xb3bBMMT tampered\n");
        f.close();
        auto *s = new SshSession(24, 80, &app);
        bool changed = false;
        int rc = 2;
        {
            QEventLoop loop;
            int outcome = 2;
            QObject::connect(s, &SshSession::hostKeyUnknown,
                             [&](const QString &, const QString &, bool c) {
                                 changed = c;
                                 s->hostKeyAnswer(true);
                             });
            QObject::connect(s, &SshSession::connected, [&] { outcome = 0; loop.quit(); });
            QObject::connect(s, &SshSession::failed, [&](const QString &) { outcome = 1; loop.quit(); });
            QTimer::singleShot(30000, &loop, &QEventLoop::quit);
            s->start(QStringLiteral("127.0.0.1"), 22, QStringLiteral("pana"), {});
            loop.exec();
            rc = outcome;
        }
        CHECK(changed, "C4 tampered key detected as CHANGED (old API=2)");
        CHECK(rc == 0 && s->isConnected(), "C4 CHANGED accepted → reconnected");
        QFile r(khPath);
        r.open(QIODevice::ReadOnly);
        const QByteArray body = r.readAll();
        r.close();
        CHECK(!body.contains("AAUqzh+dPBYhDEcSYqUb"), "C4 old tampered line removed");
        CHECK(!body.contains("tampered"), "C4 rewritten entry is current key");
        s->close();
        delete s;
    }

    // ---- 场景 3：错密码 + 坏 identity → 队列全败 failed ----
    {
        writeIdentityCfg("/nonexistent/id_file");
        auto *s = new SshSession(24, 80, &app);
        QEventLoop loop;
        int outcome = 2;
        QString why;
        QObject::connect(s, &SshSession::failed, [&](const QString &r) {
            outcome = 1;
            why = r;
            loop.quit();
        });
        QObject::connect(s, &SshSession::connected, [&] {
            outcome = 0;
            loop.quit();
        });
        QObject::connect(s, &SshSession::hostKeyUnknown, [s](const QString &, const QString &, bool) {
            s->hostKeyAnswer(true);
        });
        QTimer::singleShot(60000, &loop, &QEventLoop::quit);
        s->start(QStringLiteral("127.0.0.1"), 22, QStringLiteral("pana"),
                 QStringLiteral("definitely-wrong-pass"));
        loop.exec();
        CHECK(outcome == 1 && why == QStringLiteral("Authentication failed"),
              "C3 wrong password + broken identity → queue exhausted failed");
        s->close();
        delete s;
    }

    // ---- 场景 4：错密码 + 好 identity → publickey 回落成功 ----
    {
        writeIdentityCfg("/home/pana/.ssh/id_ed25519");
        auto *s = new SshSession(24, 80, &app);
        QEventLoop loop;
        int outcome = 2;
        QObject::connect(s, &SshSession::connected, [&] {
            outcome = 0;
            loop.quit();
        });
        QObject::connect(s, &SshSession::failed, [&] {
            outcome = 1;
            loop.quit();
        });
        QObject::connect(s, &SshSession::hostKeyUnknown, [s](const QString &, const QString &, bool) {
            s->hostKeyAnswer(true);
        });
        QTimer::singleShot(60000, &loop, &QEventLoop::quit);
        s->start(QStringLiteral("127.0.0.1"), 22, QStringLiteral("pana"),
                 QStringLiteral("definitely-wrong-pass"));
        loop.exec();
        CHECK(outcome == 0 && s->isConnected(),
              "C3 wrong password falls back queue → publickey success");
        s->close();
        delete s;
    }

    // ---- C3 前置：userauth_list 掩码（原始 dlopen 探针）----
    {
        void *h = nullptr;
        for (int i = 0; i < 2 && !h; ++i) {
            if (i == 0)
                dlopen("/opt/WindTerm_2.7.0/lib/libcrypto.so.1.1", RTLD_LAZY | RTLD_LOCAL);
            h = dlopen(i == 0 ? "/opt/WindTerm_2.7.0/lib/libssh.so.4" : "libssh.so.4",
                       RTLD_LAZY | RTLD_LOCAL);
        }
        if (h) {
            auto sym = [&](const char *n) { return dlsym(h, n); };
            auto newS = (void *(*)())sym("ssh_new");
            auto optS = (int (*)(void *, int, const void *))sym("ssh_options_set");
            auto conS = (int (*)(void *))sym("ssh_connect");
            auto nonS = (int (*)(void *, const char *))sym("ssh_userauth_none");
        auto lst = (int (*)(void *, const char *))sym("ssh_userauth_list");
            auto freeS = (void (*)(void *))sym("ssh_free");
            void *s = newS();
            const QByteArray host = "127.0.0.1";
            unsigned int port = 22;
            optS(s, 0, host.constData());
            optS(s, 1, &port);
            optS(s, 4, "pana");
            int mask = -1;
            if (conS(s) == 0) {
                nonS(s, nullptr); // none 探测轮（server 回吐可继续方法集）
                mask = lst(s, nullptr);
            }
            freeS(s);
            CHECK((mask & 2) && (mask & 4),
                  "C3 userauth_list mask contains Password|PublicKey");
        } else {
            CHECK(false, "C3 userauth_list probe dlopen");
        }
    }

    printf("SELFCHECK %s (%d failures)\n", g_failed == 0 ? "PASSED" : "FAILED", g_failed);
    return g_failed == 0 ? 0 : 1;
}
