#pragma once

#include <QByteArray>
#include <QSharedPointer>
#include <QString>
#include <QVector>

#include "Session.h"

class QSocketNotifier;
class QThread;
class SshWorker;
struct SshConnectState;
struct FileSystemItem;

// SSH 远程会话：dlopen libssh（C1：优先原版自带修补版，回退系统库）；C5 线程模型对齐
// 原版 thread_worker_start（0027:00864972）：SshWorker QObject moveToThread，thread.started
// 驱动 connectFlow()（同步 ssh_connect），结果经 queued 信号回 SshSession；C3 认证队列
// （SshAuthOperator 0027:0086adc4 等效）；I/O notifier 驱动 read_nonblocking drain
// （0020:4592 数据泵）回主线程。host key 回执：worker 无事件循环推进时在 QWaitCondition
// 上等主线程 hostKeyAnswer()（定时醒检中止标志）。析构 wait() worker（close 先置中止）。
class SshSession : public Session
{
    Q_OBJECT

public:
    explicit SshSession(int rows, int columns, QObject *parent = nullptr);
    ~SshSession() override;

    // 异步连接：立即返回。成功 connected()（连接建立后才挂读 notifier）；任一步失败
    // failed(reason)（内部映射为 output(错误文本)+finished()，视图行为与旧同步版一致）。
    void start(const QString &host, int port, const QString &user, const QString &password = {});

    void write(const QByteArray &data) override;
    void resize(int rows, int columns) override;
    // teardown() 已含 notifier 断开+deleteLater、channel close/free、ssh_free/disconnect；
    // 连接期调用置中止位，worker 在检查点自清（host key 等待处 200ms 轮询）
    void close() override;

    bool isConnected() const;

    // P5：sftp_session 句柄（worker 线程建,handoff 后主线程只读值;libssh 操作仅限
    // 后台 IO 线程——线程边界见类注释）。未 ready=nullptr
    void *sftpSession() const { return m_sftp; }

    // P5 后台线程列目录后端（SftpFolder 委托入口;实现/绑定/attr 布局全在 SshSession.cpp）。
    // 入口处暂停主线程 socket 泵（libssh session 非线程安全,sftp 块读与 notifier drain
    // 并发会踩 packet 链）,出口恢复——IO 线程同步等主线程挂起后再动手
    static QVector<FileSystemItem *> sftpList(void *sftp, const QString &path, bool showHidden);

    // 自检用：libssh 是否加载且所有必需符号非空
    static bool symbolsAvailable();

    // hostKeyUnknown() 的回执落点（主线程对话框调用；worker 收到即继续/放弃）
    void hostKeyAnswer(bool accept);

signals:
    void connected();
    void failed(const QString &reason);
    // changed=true：KNOWN_CHANGED（MITM 嫌疑，警告默认拒绝）；false：UNKNOWN/NOT_FOUND 首连
    void hostKeyUnknown(const QString &host, const QString &fingerprint, bool changed);
    // P5（0x866372/0x8638f0 信号 0 语义）：成功带句柄/失败 null+统一文案
    // "SFTP failed to allocate. "。非致命：会话保持 connected
    void sftpReady();
    void sftpFailed(const QString &reason);

private slots:
    void readChannel();
    // P5：sftpList 期间由后台 IO 线程经 invokeMethod 切换（关/开 socket 泵）
    void ioSuspend(bool suspend);
    // C5：worker 结果槽（queued 回主线程，对齐原版 ShellSession 信号 0x80 QueuedConnection）
    void onWorkerEstablished();                // 接管 worker 移交的 libssh 句柄：挂 notifier
    void onWorkerFailed(const QString &reason);
    void onWorkerHostKey(const QString &host, const QString &fingerprint, bool changed);

private:
    void teardown();
    void stopWorkerThread();

    void *m_session; // ssh_session（不透明指针，避免依赖头文件）
    void *m_channel; // ssh_channel
    void *m_sftp = nullptr; // P5 sftp_session（worker 建,主线程只读值）
    bool m_ioSuspended = false; // P5：notifier 暂停标志（ioSuspend 翻转）
    QSocketNotifier *m_notifier;
    int m_rows;
    int m_columns;
    bool m_finished;
    QThread *m_thread = nullptr;
    SshWorker *m_worker = nullptr;
    QSharedPointer<SshConnectState> m_state; // 连接期非空；结果消费后清空
};
