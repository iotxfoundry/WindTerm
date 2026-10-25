#pragma once

#include <QElapsedTimer>
#include <QObject>
#include <QString>
#include <QVariantMap>
#include <QWaitCondition>
#include <QMutex>
#include <QThread>

// 原版 SftpTransfer（0x91e8c8 SuperTransfer 家族,SftpTransfer 15 槽——骨架简化核心集）：
// 单文件 SFTP 上传/下载任务。状态机 queued/running/2 Pausing/3 Paused(king::paused
// 图标)/4 Resuming/5 Removing（0x58722a 刷新读 FUN_006183de 值 2/3/5/4 切文案）；进度=
// weightPercent（100=完成）。信号：progress(processed,total)/stateChanged(int,QVariant)/
// finished(path)。分块 32768（// shortcut: 原版 transfer.max*ChunkSize 默认未逆出,挂账）；
// open flags 0=读 / 0x241=写（O_WRONLY|O_CREAT|O_TRUNC）。
// // shortcut: 原版 sftp_async_read 泵未照搬,阻塞 IO 在独立线程等效（同 SftpFolder 先例）
// // shortcut: 断点续传 seek64 定位未接（首版不支持,绑定已挂 SshSession 表）
class SftpTransfer : public QObject
{
    Q_OBJECT

public:
    enum State { Queued = 0, Running = 1, Pausing = 2, Paused = 3, Resuming = 4, Removing = 5 };
    Q_ENUM(State)

    // direction=true=上传（本地 src→远端 dst）/false=下载（远端 src→本地 dst）
    // （transfer.download/transfer.upload 属性语义,0x58722a 动词分派）
    SftpTransfer(void *sftp, bool upload, const QString &remotePath, const QString &localPath,
                 QObject *parent = nullptr);
    ~SftpTransfer() override;

    void start();
    void pause();  // Pausing→Paused（原版 TransferCenter::pause 0x61b176 收口）
    void resume(); // Paused→Resuming→Running
    void remove(); // 标志+清理（0x61b206）

    QString path() const { return m_localPath; } // 行键=本地路径（TransferBar 行对齐）
    State state() const;
    bool isFinished() const { return m_finished; }
    qint64 processed() const { return m_processed; }
    qint64 total() const { return m_total; }
    QVariantMap properties() const; // transfer.* 属性 map（tooltip/label 刷新源）

signals:
    void progress(qint64 processed, qint64 total);
    void stateChanged(int state, const QVariant &data);
    void finished(const QString &path);

private:
    void run(); // 后台线程循环（QThread::started DirectConnection 直跑）
    void setState(State s);

    void *m_sftp;
    const bool m_upload;
    const QString m_remotePath;
    const QString m_localPath;
    QThread *m_thread = nullptr;

    mutable QMutex m_mutex;
    QWaitCondition m_pauseCond;
    State m_state = Queued;
    bool m_removeRequested = false;
    bool m_finished = false;
    qint64 m_processed = 0;
    qint64 m_total = 0;
    QElapsedTimer m_elapsed;
};
