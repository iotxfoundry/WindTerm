// P5 校验：LocalFolder 过滤/字段、FileSystemModel 本地懒加载、SftpFolder sftp 端到端
//（本机 sshd 127.0.0.1:22 + key，缺则 SKIP）、FilerPane 本地页默认态。
// HOME 全程指向临时目录（连接 known_hosts/identity/标记文件均落临时 HOME，不碰真实 HOME）。
#include <QApplication>
#include <QDir>
#include <QEventLoop>
#include <QFile>
#include <QFileInfo>
#include <QLabel>
#include <QStackedWidget>
#include <QTimer>

#include <cstdio>

#include "core/SshSession.h"
#include "filer/FileSystemItem.h"
#include "filer/FileSystemModel.h"
#include "filer/LocalFolder.h"
#include "filer/SftpFolder.h"
#include "panes/FilerPane.h"

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

// 环境探测：无本机 sshd（127.0.0.1:22 未监听）→ sftp 端到端段 SKIP
static bool sshdListening()
{
    FILE *p = popen("ss -tln 2>/dev/null | grep -q ':22 '", "r");
    if (!p)
        return false;
    const int rc = pclose(p);
    return rc == 0;
}

static void writeFile(const QString &path, const QByteArray &data)
{
    QFile f(path);
    f.open(QIODevice::WriteOnly | QIODevice::Truncate);
    f.write(data);
}

static bool containsName(const QVector<FileSystemItem *> &items, const QString &name)
{
    for (FileSystemItem *it : items)
        if (it->name == name)
            return true;
    return false;
}

template <typename F>
static bool waitFor(F cond, int timeoutMs = 15000)
{
    if (cond())
        return true;
    QEventLoop loop;
    QTimer poll;
    QObject::connect(&poll, &QTimer::timeout, [&] {
        if (cond())
            loop.quit();
    });
    QTimer::singleShot(timeoutMs, &loop, &QEventLoop::quit);
    poll.start(10);
    loop.exec();
    return cond();
}

int main(int argc, char **argv)
{
    qputenv("QT_QPA_PLATFORM", "offscreen");
    QApplication app(argc, argv);

    // ---- HOME 保护：临时 HOME（标记文件+profile 均落此处）----
    const QString tmpHome = QDir::tempPath() + QStringLiteral("/windterm-filer-sftp-%1")
                                .arg(QCoreApplication::applicationPid());
    QDir().mkpath(tmpHome);
    qputenv("HOME", tmpHome.toUtf8());
    const QString home = QDir::homePath();
    CHECK(home == tmpHome, "HOME redirected to temp dir");

    // 标记集：3 文件 + 1 目录 + 1 隐藏（先建标记再写 profile，LocalFolder 计数才精确）
    writeFile(tmpHome + QStringLiteral("/a.txt"), "hello");
    writeFile(tmpHome + QStringLiteral("/b.txt"), "x");
    writeFile(tmpHome + QStringLiteral("/c.txt"), "yz");
    writeFile(tmpHome + QStringLiteral("/.hidden"), "h");
    QDir(tmpHome).mkpath(QStringLiteral("subdir"));
    writeFile(tmpHome + QStringLiteral("/subdir/inner.txt"), "i");

    // ---- 1. LocalFolder 过滤/字段 ----
    {
        const QVector<FileSystemItem *> noHidden = LocalFolder::list(home, false);
        const QVector<FileSystemItem *> withHidden = LocalFolder::list(home, true);
        CHECK(noHidden.size() == 4,
              qPrintable(QStringLiteral("LocalFolder showHidden=false → 4 entries (got %1)")
                             .arg(noHidden.size())));
        CHECK(withHidden.size() == 5,
              qPrintable(QStringLiteral("LocalFolder showHidden=true → 5 entries (got %1)")
                             .arg(withHidden.size())));
        CHECK(!containsName(noHidden, QStringLiteral(".hidden")),
              "LocalFolder .hidden filtered when showHidden=false");
        CHECK(containsName(withHidden, QStringLiteral(".hidden")),
              "LocalFolder .hidden present when showHidden=true");
        FileSystemItem *a = nullptr;
        FileSystemItem *dir = nullptr;
        for (FileSystemItem *it : noHidden) {
            if (it->name == QStringLiteral("a.txt"))
                a = it;
            if (it->name == QStringLiteral("subdir"))
                dir = it;
        }
        CHECK(a && a->type == FileSystemItem::File && a->size == 5 && a->mtime.isValid(),
              "LocalFolder item fields (type/size/mtime)");
        CHECK(dir && dir->type == FileSystemItem::Folder,
              "LocalFolder directory item type");
        qDeleteAll(noHidden);
        qDeleteAll(withHidden);
    }

    // ---- 2. FileSystemModel 本地根加载 + 目录懒加载 ----
    {
        FileSystemModel model;
        model.setRootPath(home);
        CHECK(waitFor([&] { return model.rowCount() == 4; }),
              "FileSystemModel local root load → rowCount==4");
        int dirRow = -1;
        for (int r = 0; r < model.rowCount(); ++r)
            if (model.data(model.index(r, 0)).toString() == QStringLiteral("subdir"))
                dirRow = r;
        CHECK(dirRow >= 0, "FileSystemModel subdir row present");
        if (dirRow >= 0) {
            const QModelIndex dirIdx = model.index(dirRow, 0);
            CHECK(model.hasChildren(dirIdx), "hasChildren triggers async lazy load");
            CHECK(waitFor([&] { return model.rowCount(dirIdx) == 1; }),
                  "lazy child load → inner.txt row");
        }
    }

    // ---- 3. SFTP 端到端（gated：本机 sshd + key）----
    const bool keyAvailable = QFileInfo::exists(QStringLiteral("/home/pana/.ssh/id_ed25519"));
    if (!sshdListening() || !keyAvailable) {
        printf("SKIP: sftp e2e needs sshd on 127.0.0.1:22 + /home/pana/.ssh/id_ed25519\n");
    } else {
        QDir().mkpath(tmpHome + QStringLiteral("/.wind/profiles/default.v10"));
        writeFile(tmpHome + QStringLiteral("/.wind/profiles/default.v10/user.config"),
                  QByteArray("{\"ssh.identityFilePath\":\"/home/pana/.ssh/id_ed25519\"}"));

        auto *ssh = new SshSession(24, 80, &app);
        QEventLoop loop;
        bool ready = false;
        QString failWhy;
        QObject::connect(ssh, &SshSession::sftpReady, [&] {
            ready = true;
            loop.quit();
        });
        QObject::connect(ssh, &SshSession::sftpFailed, [&](const QString &why) {
            failWhy = why;
            loop.quit();
        });
        QObject::connect(ssh, &SshSession::failed, [&](const QString &why) {
            failWhy = QStringLiteral("connect: ") + why;
            loop.quit();
        });
        QObject::connect(ssh, &SshSession::hostKeyUnknown,
                         [ssh](const QString &, const QString &, bool) { ssh->hostKeyAnswer(true); });
        QTimer::singleShot(60000, &loop, &QEventLoop::quit);
        ssh->start(QStringLiteral("127.0.0.1"), 22, QString(), {}); // 空 user→libssh 默认登录名
        loop.exec();

        CHECK(ready && ssh->sftpSession() != nullptr,
              qPrintable(QStringLiteral("sftpReady + handle (%1)").arg(failWhy)));
        if (ready && ssh->sftpSession()) {
            void *sftp = ssh->sftpSession();
            const QVector<FileSystemItem *> remote = SftpFolder::list(sftp, home, false);
            bool hasA = containsName(remote, QStringLiteral("a.txt"));
            CHECK(remote.size() > 0 && hasA,                  qPrintable(QStringLiteral("sftp list home: %1 entries, marker a.txt present")
                                 .arg(remote.size())));
            CHECK(!containsName(remote, QStringLiteral(".hidden")), "sftp hidden filtered");
            qDeleteAll(remote);

            const QVector<FileSystemItem *> remoteH = SftpFolder::list(sftp, home, true);
            CHECK(containsName(remoteH, QStringLiteral(".hidden")),
                  "sftp hidden present when showHidden=true");
            qDeleteAll(remoteH);

            // C：sftp_canonicalize_path 绑定（"." →服务端绝对路径;"/subdir/.." 收敛）
            const QString canon = SshSession::sftpCanonicalizePath(sftp, QStringLiteral("."));
            CHECK(canon.startsWith(QLatin1Char('/')) && canon != QLatin1String("."),
                  qPrintable(QStringLiteral("sftp_canonicalize_path('.') → absolute (%1)")
                                 .arg(canon)));
            const QString canonUp = SshSession::sftpCanonicalizePath(
                sftp, QStringLiteral("%1/subdir/..").arg(home));
            CHECK(canonUp == home,
                  qPrintable(QStringLiteral("canonicalize '..' collapse (%1 == %2)")
                                 .arg(canonUp, home)));

            // R49 逆序插入序：模型行序=后端返回序的逆（finishLoad 逆序 append,0x634ef0）
            const QVector<FileSystemItem *> listing = SftpFolder::list(sftp, home, true);
            QStringList names;
            for (const FileSystemItem *it : listing)
                names << it->name;
            FileSystemModel revModel;
            revModel.setSftp(sftp);
            revModel.setShowHidden(true);
            revModel.setRootPath(home);
            const bool revOk = waitFor([&] {
                if (revModel.rowCount() != names.size())
                    return false;
                for (int r = 0; r < names.size(); ++r)
                    if (revModel.index(r, 0).data().toString()
                        != names.at(names.size() - 1 - r))
                        return false;
                return true;
            });
            CHECK(revOk, "model rows = backend listing reversed (R49 reverse insert)");
            qDeleteAll(listing);

            // 远程模型链（QtConcurrent 后端+sftp 句柄）
            FileSystemModel remoteModel;
            remoteModel.setSftp(sftp);
            remoteModel.setRootPath(home);
            CHECK(waitFor([&] { return remoteModel.rowCount() >= 4; }),
                  "FileSystemModel sftp backend root load");
        }
        ssh->close();
        delete ssh;
    }

    // ---- 4. FilerPane 本地页默认态 ----
    {
        FilerPane pane;
        pane.resize(400, 300);
        pane.show();
        auto *stack = pane.findChild<QStackedWidget *>();
        CHECK(stack && stack->currentIndex() == 0, "FilerPane local page default");
        auto *status = pane.findChild<QLabel *>();
        CHECK(status && status->text().contains(home),
              qPrintable(QStringLiteral("FilerPane status label contains path: '%1'")
                             .arg(status ? status->text() : QString())));
    }

    QDir(tmpHome).removeRecursively();
    printf("SELFCHECK %s (%d failures)\n", g_failed == 0 ? "PASSED" : "FAILED", g_failed);
    return g_failed == 0 ? 0 : 1;
}
