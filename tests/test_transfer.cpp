// P6 校验：SftpTransfer 上传/下载 round-trip、TransferCenter 行/事件序列、
// TransferBar 每任务一行 TransferLabel、暂停/恢复状态机。
// 无本机 sshd（127.0.0.1:22 + key）则 SKIP。
// HOME 全程指向临时目录（known_hosts/identity 均落临时 HOME，不碰真实 HOME）。
#include <QApplication>
#include <QDir>
#include <QElapsedTimer>
#include <QEventLoop>
#include <QFile>
#include <QFileInfo>
#include <QLabel>
#include <QTemporaryFile>
#include <QTimer>
#include <QTreeView>

#include <cstdio>

#include "core/SshSession.h"
#include "panes/TransferPane.h"
#include "transfer/SftpTransfer.h"
#include "transfer/TransferCenter.h"
#include "transfer/TransferLabel.h"
#include "widgets/TransferBar.h"

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

// 环境探测：无本机 sshd → sftp 端到端段 SKIP（test_filer_sftp 同款）
static bool sshdListening()
{
    FILE *p = popen("ss -tln 2>/dev/null | grep -q ':22 '", "r");
    if (!p)
        return false;
    const int rc = pclose(p);
    return rc == 0;
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

// sftp 连接助手（test_filer_sftp 同款链）：返回 sftp 句柄（失败 nullptr）。
// HOME 先切临时目录再建 profile（qputenv 必须在 SshSession::start 前,否则 known_hosts
// 落真实 HOME;失败原因打 stderr 便于 CI 排障）
static void *connectSftp(QApplication &app, SshSession **outSession)
{
    const QString tmpHome = QDir::tempPath()
        + QStringLiteral("/windterm-transfer-%1").arg(QCoreApplication::applicationPid());
    QDir().mkpath(tmpHome + QStringLiteral("/.wind/profiles/default.v10"));
    {
        QFile cfg(tmpHome + QStringLiteral("/.wind/profiles/default.v10/user.config"));
        cfg.open(QIODevice::WriteOnly | QIODevice::Truncate);
        cfg.write("{\"ssh.identityFilePath\":\"/home/pana/.ssh/id_ed25519\"}");
    }
    qputenv("HOME", tmpHome.toUtf8());
    qputenv("USER", qgetenv("USER")); // 保 user 探测（空 user→libssh 默认登录名）

    auto *ssh = new SshSession(24, 80, &app);
    QEventLoop loop;
    bool ready = false;
    QString why;
    QObject::connect(ssh, &SshSession::sftpReady, [&] {
        ready = true;
        loop.quit();
    });
    QObject::connect(ssh, &SshSession::sftpFailed, [&](const QString &r) {
        why = QStringLiteral("sftpFailed: ") + r;
        loop.quit();
    });
    QObject::connect(ssh, &SshSession::failed, [&](const QString &r) {
        why = QStringLiteral("failed: ") + r;
        loop.quit();
    });
    QObject::connect(ssh, &SshSession::hostKeyUnknown,
                     [ssh](const QString &, const QString &, bool) { ssh->hostKeyAnswer(true); });
    QTimer::singleShot(60000, &loop, &QEventLoop::quit);
    ssh->start(QStringLiteral("127.0.0.1"), 22, QStringLiteral("pana"), {});
    loop.exec();
    if (!ready)
        fprintf(stderr, "connectSftp: %s\n", qPrintable(why));
    *outSession = ssh;
    return ready ? ssh->sftpSession() : nullptr;
}

int main(int argc, char **argv)
{
    qputenv("QT_QPA_PLATFORM", "offscreen");
    QApplication app(argc, argv);

    const QString pid = QString::number(QCoreApplication::applicationPid());
    const QString upPath = QStringLiteral("/tmp/%1_up.txt").arg(pid);
    const QString downPath = QStringLiteral("/tmp/%1_down.txt").arg(pid);

    // ---- 1. TransferCenter 纯逻辑（无 sshd 也可跑）----
    {
        TransferCenter *center = TransferCenter::instance();
        center->ensureTaskRow(QStringLiteral("/tmp/tc_row.txt"));
        CHECK(center->model()->rowCount() == 1, "TransferCenter ensureTaskRow → 1 row");
        // kind 0 事件序列
        {
            QStringList kinds;
            QObject c;
            QObject::connect(center, &TransferCenter::taskEvent, &c,
                             [&](const QString &, int kind) { kinds << QString::number(kind); });
            center->removeTaskRow(QStringLiteral("/tmp/tc_row.txt"));
            CHECK(kinds == QStringList { "2" }, "removeTaskRow → taskEvent kind=2");
        }
        // 0x617aea propertiesToHtml：键序+红字失败行
        QVariantMap map;
        map.insert(QStringLiteral("transfer.session"), QStringLiteral("ssh me@h"));
        map.insert(QStringLiteral("transfer.targetDirectory"), QStringLiteral("/tmp"));
        map.insert(QStringLiteral("transfer.currentItemName"), QStringLiteral("a.txt"));
        map.insert(QStringLiteral("transfer.processedCount"), QStringLiteral("1"));
        map.insert(QStringLiteral("transfer.count"), QStringLiteral("2"));
        map.insert(QStringLiteral("transfer.failedCount"), QStringLiteral("1"));
        map.insert(QStringLiteral("transfer.processedSize"), QStringLiteral("42"));
        const QString html = TransferCenter::propertiesToHtml(map);
        CHECK(html.startsWith(QStringLiteral("<tr><td align=right>Session: </td><td>ssh me@h")),
              "0x617aea html row format (Session first)");
        CHECK(html.contains(QStringLiteral("<td>1 of 2</td>")), "Items row synthesized %1 of %2");
        CHECK(html.contains(QStringLiteral("<font color=\"red\">1</font>")),
              "failedCount red-wrapped");
        const int failedAt = html.indexOf(QLatin1String("Failed items"));
        const int processedAt = html.indexOf(QLatin1String("Processed size"));
        CHECK(failedAt > 0 && processedAt > failedAt,
              "0x617aea key order (Failed items before Processed size)");
    }

    // ---- SFTP 端到端（gated）----
    const bool keyAvailable = QFileInfo::exists(QStringLiteral("/home/pana/.ssh/id_ed25519"));
    if (!sshdListening() || !keyAvailable) {
        printf("SKIP: transfer e2e needs sshd on 127.0.0.1:22 + /home/pana/.ssh/id_ed25519\n");
    } else {
        SshSession *ssh = nullptr;
        void *sftp = connectSftp(app, &ssh);
        CHECK(sftp && ssh, "sftp connected for transfer e2e");
        if (sftp && ssh) {
            // ① 上传：QTemporaryFile "TRANSFER_UP_TEST_42" → /tmp/<pid>_up.txt
            {
                QTemporaryFile src;
                src.setAutoRemove(false);
                src.open();
                src.write("TRANSFER_UP_TEST_42");
                const QString srcPath = src.fileName();
                src.close();
                TransferCenter *center = TransferCenter::instance();
                QList<int> kinds;
                QObject c;
                QObject::connect(center, &TransferCenter::taskEvent, &c,
                                 [&](const QString &, int kind) { kinds.append(kind); });
                auto *transfer = new SftpTransfer(sftp, true, upPath, srcPath, center);
                center->ensureTaskRow(srcPath);
                center->setTaskProperty(srcPath, QStringLiteral("transfer.upload"), true);
                center->setTaskProperty(srcPath, QStringLiteral("transfer.currentItemName"),
                                        QFileInfo(srcPath).fileName());
                bool done = false;
                // progress→行属性+Refresh（FilerPane::startTransfers 同构接线——独立版）
                QObject::connect(transfer, &SftpTransfer::progress, center,
                                 [center, srcPath](qint64 processed, qint64 total) {
                    center->setTaskProperty(srcPath, QStringLiteral("transfer.processedSize"),
                                            QString::number(processed));
                    center->setTaskProperty(srcPath, QStringLiteral("transfer.size"),
                                            QString::number(total));
                    center->setTaskProperty(srcPath, QStringLiteral("transfer.weightPercent"),
                                            total > 0 ? static_cast<int>(processed * 100 / total)
                                                      : 0);
                    emit center->taskEvent(srcPath, TransferCenter::Refresh);
                });
                QObject::connect(transfer, &SftpTransfer::finished,
                                 [&](const QString &) { done = true; });
                transfer->start();
                CHECK(waitFor([&] { return done; }), "upload finished signal");
                CHECK(QFile::exists(upPath), "remote file created via sftp write chain");
                CHECK(QFileInfo(upPath).size() == 19, "remote size == 19");
                // ③ taskEvent 序列断言（kind0 建→若干 4 刷新）
                CHECK(kinds.contains(TransferCenter::LabelCreate),
                      "taskEvent kind=0 (label create) seen");
                CHECK(kinds.contains(TransferCenter::Refresh),
                      "taskEvent kind=4 (refresh) seen");
                QFile(srcPath).remove();
            }
            // ② 下载回 /tmp/<pid>_down.txt → 内容 round-trip
            {
                const QString localDown = downPath;
                auto *transfer = new SftpTransfer(sftp, false, upPath, localDown);
                bool done = false;
                QObject::connect(transfer, &SftpTransfer::finished,
                                 [&](const QString &) { done = true; });
                transfer->start();
                CHECK(waitFor([&] { return done; }), "download finished signal");
                QFile f(localDown);
                f.open(QIODevice::ReadOnly);
                const QByteArray content = f.readAll();
                CHECK(content == "TRANSFER_UP_TEST_42",
                      qPrintable(QStringLiteral("round-trip content (%1)").arg(
                          QString::fromUtf8(content))));
            }
            // ④ TransferBar：任务开始后 findChild TransferLabel 存在;完成后文案含 downloaded
            {
                TransferBar bar;
                bar.hookTransferCenter(TransferCenter::instance());
                const QString srcPath = downPath; // 以刚下载的本地文件为任务
                TransferCenter *center = TransferCenter::instance();
                center->ensureTaskRow(srcPath);
                center->setTaskProperty(srcPath, QStringLiteral("transfer.upload"), true);
                center->setTaskProperty(srcPath, QStringLiteral("transfer.currentItemName"),
                                        QFileInfo(srcPath).fileName());
                center->setTaskProperty(srcPath, QStringLiteral("transfer.weightPercent"), 50);
                emit center->taskEvent(srcPath, TransferCenter::LabelCreate);
                waitFor([&] { return bar.findChildren<TransferLabel *>().size() == 1; }, 3000);
                CHECK(bar.findChildren<TransferLabel *>().size() == 1,
                      "TransferBar label created on taskEvent kind=0");
                TransferLabel *label = bar.findChildren<TransferLabel *>().value(0);
                CHECK(label && label->path() == srcPath, "label carries task path");
                // 方向副表同步（bar 第二连接在 kind 0 时读属性定 upload;属性在建行前已设）
                center->setTaskProperty(srcPath, QStringLiteral("transfer.currentItemName"),
                                        QFileInfo(srcPath).fileName());
                // 完成语（不等 30s——直接置 100% 刷文案断言 "uploaded";0x58722a 刷新链
                // =TransferCenter taskEvent(4)→bar refreshLabel→label refresh）
                center->setTaskProperty(srcPath, QStringLiteral("transfer.weightPercent"), 100);
                emit center->taskEvent(srcPath, TransferCenter::Refresh);
                app.processEvents();
                const QString labelText =
                    label ? (label->findChild<QLabel *>() ? label->findChild<QLabel *>()->text()
                                                          : QString())
                          : QString();
                CHECK(labelText.contains(QStringLiteral("uploaded")),
                      qPrintable(QStringLiteral("completed label text contains uploaded verb ('%1')")
                                     .arg(labelText)));
            }
            // ⑤ 暂停/恢复：5MB 文件上传中 pause→Paused→resume→完成
            {
                const QString bigFile = QStringLiteral("/tmp/%1_big.bin").arg(pid);
                {
                    QFile big(bigFile);
                    big.open(QIODevice::WriteOnly | QIODevice::Truncate);
                    QByteArray chunk(32768, 'B');
                    for (int i = 0; i < 160; ++i) // 5MB
                        big.write(chunk);
                }
                TransferCenter *center = TransferCenter::instance();
                auto *transfer = new SftpTransfer(sftp, true, QStringLiteral("/tmp/%1_big_remote.bin").arg(pid),
                                                  bigFile, center);
                bool done = false;
                QObject::connect(transfer, &SftpTransfer::finished,
                                 [&](const QString &) { done = true; });
                transfer->start();
                // 传一部分后暂停
                waitFor([&] { return transfer->processed() > 512 * 1024; }, 10000);
                transfer->pause();
                CHECK(transfer->state() == SftpTransfer::Paused, "pause → state Paused");
                const qint64 atPause = transfer->processed();
                QThread::msleep(300);
                CHECK(transfer->processed() - atPause < 32768 * 2,
                      "paused progress frozen");
                transfer->resume();
                CHECK(transfer->state() != SftpTransfer::Paused, "resume leaves Paused");
                CHECK(waitFor([&] { return done; }, 30000), "resume → completes");
                QFile(bigFile).remove();
                QFile(QStringLiteral("/tmp/%1_big_remote.bin").arg(pid)).remove();
            }
        }
        QFile(upPath).remove();
        QFile(downPath).remove();
        if (ssh) {
            ssh->close();
            delete ssh;
        }
    }

    // ---- TransferPane 空态/结构 ----
    {
        TransferPane pane;
        pane.hookModel(TransferCenter::instance()->model());
        pane.resize(400, 300);
        pane.show();
        auto *view = pane.findChild<QTreeView *>(QStringLiteral("TreeView"));
        CHECK(view && view->model() == TransferCenter::instance()->model(),
              "TransferPane TreeView bound to TransferCenter model");
        CHECK(view && view->selectionMode() == QAbstractItemView::ExtendedSelection
                  && view->isHeaderHidden(),
              "TreeView Extended selection + headerHidden (0x733a18)");
    }

    QDir(QDir::tempPath()
         + QStringLiteral("/windterm-transfer-%1").arg(QCoreApplication::applicationPid()))
        .removeRecursively();
    printf("SELFCHECK %s (%d failures)\n", g_failed == 0 ? "PASSED" : "FAILED", g_failed);
    return g_failed == 0 ? 0 : 1;
}
