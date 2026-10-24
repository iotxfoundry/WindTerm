#pragma once

#include <QByteArray>
#include <QSharedPointer>
#include <QString>

#include "Session.h"

class QSocketNotifier;
class QThread;
class SshWorker;
struct SshConnectState;

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

    // 自检用：libssh 是否加载且所有必需符号非空
    static bool symbolsAvailable();

    // hostKeyUnknown() 的回执落点（主线程对话框调用；worker 收到即继续/放弃）
    void hostKeyAnswer(bool accept);

signals:
    void connected();
    void failed(const QString &reason);
    // changed=true：KNOWN_CHANGED（MITM 嫌疑，警告默认拒绝）；false：UNKNOWN/NOT_FOUND 首连
    void hostKeyUnknown(const QString &host, const QString &fingerprint, bool changed);

private slots:
    void readChannel();
    // C5：worker 结果槽（queued 回主线程，对齐原版 ShellSession 信号 0x80 QueuedConnection）
    void onWorkerEstablished();                // 接管 worker 移交的 libssh 句柄：挂 notifier
    void onWorkerFailed(const QString &reason);
    void onWorkerHostKey(const QString &host, const QString &fingerprint, bool changed);

private:
    void teardown();
    void stopWorkerThread();

    void *m_session; // ssh_session（不透明指针，避免依赖头文件）
    void *m_channel; // ssh_channel
    QSocketNotifier *m_notifier;
    int m_rows;
    int m_columns;
    bool m_finished;
    QThread *m_thread = nullptr;
    SshWorker *m_worker = nullptr;
    QSharedPointer<SshConnectState> m_state; // 连接期非空；结果消费后清空
};
