#include "SftpTransfer.h"

#include <QCoreApplication>
#include <QDateTime>
#include <QEventLoop>
#include <QFile>
#include <QPointer>
#include <QThread>

#include "core/SshSession.h"

namespace {
// // shortcut: 原版 transfer.max*ChunkSize 默认未逆出,取 32KB 挂账——逆明后校准
constexpr qint64 kChunkSize = 32768;
// sftp_open flags（libssh sftp.h 实证）:0=只读;0x241=O_WRONLY(1)|O_CREAT(0x40)|O_TRUNC(0x200)
constexpr int kOpenRead = 0;
constexpr int kOpenWrite = 0x241;
} // namespace

SftpTransfer::SftpTransfer(void *sftp, bool upload, const QString &remotePath,
                           const QString &localPath, QObject *parent)
    : QObject(parent)
    , m_sftp(sftp)
    , m_upload(upload)
    , m_remotePath(remotePath)
    , m_localPath(localPath)
{
}

SftpTransfer::~SftpTransfer()
{
    // 确定收口序：remove 请求置位（run 循环块边界可见）→ quit → wait。terminate 仅作
    // 卡 IO 兜底（close 已 free sftp 后不再有阻塞面）。
    // wait 期间泵主线程事件：run 的 pumpSuspend 会 BlockingQueued 到主线程 ioSuspend，
    // 主线程若纯 wait 则该应答永不返回 → 与 run 互等死锁（实测死锁告警路径）
    if (m_thread) {
        {
            QMutexLocker lock(&m_mutex);
            m_removeRequested = true;
        }
        m_pauseCond.wakeAll();
        m_thread->quit();
        static constexpr int kSpinLimit = 600; // ~30s 量级泵兜底（同旧 30s wait）
        for (int spins = 0; m_thread->isRunning() && spins < kSpinLimit; ++spins) {
            if (m_thread->wait(50))
                break;
            QCoreApplication::processEvents(QEventLoop::AllEvents, 20);
        }
        if (m_thread->isRunning()) {
            m_thread->terminate(); // 泵耗尽仍未收口=run 阻塞在 libssh IO：兜底
            m_thread->wait();
        }
    }
}

QVariantMap SftpTransfer::properties() const
{
    const QMutexLocker locker(&m_mutex);
    QVariantMap map;
    map.insert(QStringLiteral("transfer.weightPercent"),
               m_total > 0 ? static_cast<int>(m_processed * 100 / m_total)
                           : (m_finished ? 100 : 0));
    map.insert(QStringLiteral("transfer.processedSize"), QString::number(m_processed));
    map.insert(QStringLiteral("transfer.size"), QString::number(m_total));
    map.insert(m_upload ? QStringLiteral("transfer.upload") : QStringLiteral("transfer.download"),
               true);
    // 0x58722a 状态分派：2/3/5/4 → Pausing/Paused/Removing/Resuming 文案
    const char *stateKey = nullptr;
    switch (m_state) {
    case Pausing: stateKey = "Pausing"; break;
    case Paused: stateKey = "Paused"; break;
    case Resuming: stateKey = "Resuming"; break;
    case Removing: stateKey = "Removing"; break;
    default: break;
    }
    if (stateKey)
        map.insert(QStringLiteral("transfer.state"), QString::fromLatin1(stateKey));
    if (m_elapsed.isValid()) {
        const qint64 ms = m_elapsed.elapsed();
        map.insert(QStringLiteral("transfer.elapsedTime"),
                   QStringLiteral("%1 s").arg(ms / 1000));
        if (m_total > 0 && !m_finished && m_processed > 0) {
            const qint64 remainMs = ms * (m_total - m_processed) / m_processed;
            map.insert(QStringLiteral("transfer.leftTime"),
                       QStringLiteral("%1 s").arg(remainMs / 1000));
        }
        if (ms > 0) {
            map.insert(QStringLiteral("transfer.averageSpeed"),
                       QStringLiteral("%1 KB/s").arg(m_processed * 1000 / ms / 1024));
        }
    }
    map.insert(QStringLiteral("transfer.datetime"),
               QDateTime::currentDateTime().toString(Qt::ISODate));
    return map;
}

SftpTransfer::State SftpTransfer::state() const
{
    const QMutexLocker locker(&m_mutex);
    return m_state;
}

void SftpTransfer::setState(State s)
{
    {
        QMutexLocker lock(&m_mutex);
        if (m_state == s)
            return;
        m_state = s;
    }
    emit stateChanged(static_cast<int>(s), QVariant());
}

void SftpTransfer::start()
{
    if (m_thread)
        return;
    if (!SshSession::sftpFileIoAvailable()) {
        emit finished(m_localPath); // 绑定缺失：立即终局（无 IO 面）
        return;
    }
    m_elapsed.start();
    m_thread = new QThread(this);
    // run 挂 worker 线程（DirectConnection——AutoConnection 会按 this 亲和排主线程队列,
    // 与 worker 内 BlockingQueued 护栏互等,实测死锁）
    connect(m_thread, &QThread::started, this, &SftpTransfer::run, Qt::DirectConnection);
    m_thread->start();
}

void SftpTransfer::pause()
{
    setState(Pausing);
    setState(Paused);
}

void SftpTransfer::resume()
{
    setState(Resuming);
    m_pauseCond.wakeAll();
    setState(Running);
}

void SftpTransfer::remove()
{
    {
        QMutexLocker lock(&m_mutex);
        m_removeRequested = true;
    }
    m_pauseCond.wakeAll();
}

// 挂泵护栏（R38）：libssh session 非线程安全——**任一时刻仅一个线程可碰 session**。
// sftpList 先例=后台 IO 线程挂起主线程泵（BlockingQueued 同步翻转 notifier）。
// 传输线程同规则,但分块循环每块挂/放主线程事件循环互等开销大且行为脆（主线程不在
// 事件循环时 BlockingQueued 永挂——实测死锁告警）。
// 本处采用"会话级串行"护栏：g_sessionIoMutex 串行化所有 sftp IO（传输线程持锁整轮,
// 主线程 sftpList/sftpStat 经 pumpSuspend 分支同样持锁——notifier 主线程直调路径
// 无锁面,由 IO 挂起保证互斥）。shortcut: 会话级串行近似原版 async 泵互斥,粒度挂账
namespace {
QMutex g_sessionIoMutex; // 会话级串行锁（见 pumpSuspend 注释）
}

static bool pumpSuspend(void *sftp, bool suspend)
{
    // 传输线程：会话级串行锁的持/放（suspend=true=拿锁,false=放锁）。
    // 与主线程泵（notifier drain/teardown free）的互斥经 ioSuspend 桥：
    // 拿锁后先 BlockingQueued 挂主线程泵（若主线程在事件循环,应答后返回——挂起成立;
    // 不在循环=无 drain 竞态面,notifier enabled 状态的竞态窗口挂账给 teardown 前置检查）
    QObject *host = SshSession::hostForSftp(sftp);
    if (suspend) {
        g_sessionIoMutex.lock();
        if (host && host->thread() != QThread::currentThread())
            QMetaObject::invokeMethod(host, "ioSuspend", Qt::BlockingQueuedConnection,
                                      Q_ARG(bool, true));
    } else {
        if (host && host->thread() != QThread::currentThread())
            QMetaObject::invokeMethod(host, "ioSuspend", Qt::BlockingQueuedConnection,
                                      Q_ARG(bool, false));
        g_sessionIoMutex.unlock();
    }
    return true;
}

void SftpTransfer::run()
{
    // 远端大小（下载=源;上传=无预知,起 0 累计）——sftpFileSize 内部自带挂泵护栏
    //（在其 stat 调用前后单独挂/放）。护栏不能覆盖整轮循环：BlockingQueued 需要主线程
    // 事件循环转着应答,而 IO 线程随后要在 QWaitCondition/循环里自旋——若整轮持"主线程
    // 泵挂起"态,测试 waitFor 的事件循环仍转（ioSuspend 只关 notifier,不关事件循环）,
    // 但暂停等待依赖 wakeAll 而非泵。综合：护栏=分块边界外直调（同 sftpList 先例,
    // 单次 libssh 调用期间挂起）。分块循环体内 read/write 直调与主线程 pump 的竞态窗口
    // // shortcut: 分块级挂泵粒度挂账——原版 async 泵统一后消除
    if (!m_upload)
        m_total = SshSession::sftpFileSize(m_sftp, m_remotePath);
    emit progress(m_processed, m_total);

    setState(Running);
    const SshSession::SftpFileApi &a = SshSession::fileApi();
    QFile local(m_localPath);
    bool ok = false;
    if (m_upload) {
        if (local.open(QIODevice::ReadOnly)) {
            m_total = local.size();
            emit progress(0, m_total);
            if (a.open)
                ok = true;
        }
        // 挂泵护栏包裹单次 open（0x8e8d36 sftpList 同粒度;open 后循环内直调——粒度挂账）
        void *rf = nullptr;
        if (ok) {
            pumpSuspend(m_sftp, true);
            rf = a.open(m_sftp, m_remotePath.toUtf8().constData(), kOpenWrite, 0644);
            pumpSuspend(m_sftp, false);
        }
        if (!rf)
            ok = false;
        char *buf = new char[kChunkSize];
        while (ok) {
            {
                QMutexLocker lock(&m_mutex);
                if (m_removeRequested || m_state == Paused || m_state == Pausing) {
                    ok = false;
                    break;
                }
            }
            const qint64 n = local.read(buf, kChunkSize);
            if (n <= 0)
                break; // EOF=完成
            // 分块写（挂泵粒度=单次调用,BlockingQueued 主线程事件循环活着可应答）
            pumpSuspend(m_sftp, true);
            const int wrc = a.write(rf, buf, static_cast<size_t>(n));
            pumpSuspend(m_sftp, false);
            if (wrc != n) {
                ok = false;
                break;
            }
            QMutexLocker lock(&m_mutex);
            m_processed += n;
            emit progress(m_processed, m_total);
        }
        delete[] buf;
        if (rf) {
            pumpSuspend(m_sftp, true);
            a.close(rf);
            pumpSuspend(m_sftp, false);
        }
    } else {
        // 挂泵护栏包裹单次 open
        pumpSuspend(m_sftp, true);
        void *rf = a.open ? a.open(m_sftp, m_remotePath.toUtf8().constData(), kOpenRead, 0)
                          : nullptr;
        pumpSuspend(m_sftp, false);
        if (rf && local.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
            char *buf = new char[kChunkSize];
            bool done = false;
            while (!done) {
                bool paused = false;
                bool removed = false;
                {
                    QMutexLocker lock(&m_mutex);
                    paused = (m_state == Paused || m_state == Pausing);
                    removed = m_removeRequested;
                }
                if (removed)
                    break;
                if (paused) {
                    // Paused 挂起（resume 唤醒;wait 需持锁——重取锁再睡）
                    QMutexLocker lock(&m_mutex);
                    if (m_state == Paused || m_state == Pausing)
                        m_pauseCond.wait(&m_mutex, 200);
                    continue;
                }
                // 分块读（挂泵粒度=单次调用）
                pumpSuspend(m_sftp, true);
                const int n = a.read(rf, buf, static_cast<size_t>(kChunkSize));
                pumpSuspend(m_sftp, false);
                if (n < 0)
                    break; // 错误
                if (n == 0) {
                    done = true; // EOF
                    break;
                }
                if (local.write(buf, n) != n)
                    break;
                QMutexLocker lock(&m_mutex);
                m_processed += n;
                emit progress(m_processed, m_total);
            }
            delete[] buf;
            ok = done;
        } else {
            ok = false;
        }
        if (rf) {
            pumpSuspend(m_sftp, true);
            a.close(rf);
            pumpSuspend(m_sftp, false);
        }
    }

    {
        QMutexLocker lock(&m_mutex);
        m_finished = true;
        if (m_removeRequested) {
            QFile::remove(m_localPath); // 移除=清理半成品（0x61b206 语义）
            ok = false;
        }
        // 终态百分比：成功=100%（0x58722a 完成语分支的行属性面;total 归一防 0 除）
        if (ok) {
            if (m_total <= 0)
                m_total = m_processed > 0 ? m_processed : 1;
            m_processed = m_total;
        }
    }
    setState(m_removeRequested ? Removing : Queued); // 终态回 queued 面（100% 完成）
    emit progress(m_processed, m_total);
    emit finished(m_localPath);
}
