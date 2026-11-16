// FileWatcherFace.cpp — 轮询式文件监视线程。

#include "Utility/FileWatcherFace.h"

#include <QDateTime>
#include <QFileInfo>
#include <QReadWriteLock>
#include <QReadLocker>
#include <QWriteLocker>

FileWatcherFace::FileWatcherFace(QObject *parent)
    : QThread(parent)
    , m_lock(new QReadWriteLock)
{
}

// 0x0062b1e0(223B)dtor 真身。逐句:
//   vptr = &FileWatcher_vtable;
//   requestInterruption();wait(0x7fffffffffffffff)  ← 先停线程再析构
//   +0x18 QReadWriteLock 释放(operator_delete(_, 8))
//   +0x28 / +0x20 两个 QHash 的 d 各减引用,归零走 QHashData::free_helper
//   QThread::~QThread
// deleting 0x0062b2c0(23B):同上 + operator_delete(this, 0x38)。
FileWatcherFace::~FileWatcherFace()
{
	requestInterruption();
	wait(); // 语料:wait(INT64_MAX)
	delete m_lock;
	m_lock = nullptr;
}

void FileWatcherFace::addPath(const QString &path)
{
	QWriteLocker lk(m_lock);
	m_entries.insert(path, Entry { path, false, 0, 0, 0 });
}

void FileWatcherFace::removePath(const QString &path)
{
	QWriteLocker lk(m_lock);
	m_entries.remove(path);
}

// vt12 0x0062b2d8(709B)run() 真身。逐句:
//   外层 do/while:
//     内层 while(!isInterruptionRequested()):
//       ① 读锁:lockForRead(+0x18)(语料用 (ptr|1) 位标记"已加锁")
//       ② 快照 detach:若 +0x28 的 QHash 引用计数 > 1 则 detach
//       ③ 逐个遍历快照条目(排除 detach 期间被挪走的节点):
//            if 中断请求 或 +0x30(停止标志) → break
//            fi = QFileInfo(path)
//            exists = fi.exists();size = fi.size();now = currentMSecsSinceEpoch()
//            mtime = exists ? fi.lastModified().toMSecsSinceEpoch() : now
//            若条目尚无基准(上次大小 == 0)→ 用本次值填基准
//            if (!notified) {
//                if (!exists) { if (已通知过) { 清通知; goto notify } }
//                else if ((now - mtime < 0x321 /*801*/) ||
//                         (上次大小 != size && (mtime - 上次mtime < 0xea61 /*60001*/))) {
//                    上次大小 = size; 本次"活跃"=exists      ← 文件还在写,先不报
//                } else {
//                    已通知 = true;
//                  notify:
//                    上次大小 = size;上次 mtime = mtime;状态 = 1;
//                    emit fileChanged(path);              ← 0x00902ad8
//                }
//            } else if (状态 == 2 && (已通知 != exists || 大小变 || mtime 变)) {
//                状态 = 0;                                 ← 允许再次通知
//            }
//       ④ unlock
//     若 !停止标志 → msleep((有任何活跃条目) ? 400 : 1000)
//
// 语义:debounce 轮询。- 文件 mtime 距今 < 801ms 视为"仍在写入",跳过;
//   - 写完后若大小变化 或 mtime 超过 60s,才判定变化并发出 fileChanged;
//   - 有活跃条目时 400ms 轮询,静止时 1000ms。
void FileWatcherFace::run()
{
	bool anyActive = false; // 语料:local_49(本轮是否有"活跃"条目)

	while (true) {
		while (!isInterruptionRequested()) {
			QHash<QString, Entry> snap;
			{
				QReadLocker lk(m_lock); // 语料:lockForRead(+0x18)
				snap = m_entries;
			}

			for (auto it = snap.begin(); it != snap.end(); ++it) {
				if (isInterruptionRequested() || m_stop)
					break;

				Entry &e = it.value();
				const QFileInfo fi(e.path);
				const bool exists = fi.exists();
				const qint64 size = fi.size();
				const qint64 now = QDateTime::currentMSecsSinceEpoch();
				qint64 mtime = now;
				if (exists)
					mtime = fi.lastModified().toMSecsSinceEpoch();

				if (e.size == 0) { // 语料:+0x28 == 0 时以本次值建立基准
					e.size = size;
					e.mtime = mtime;
				}

				bool report = false;
				if (!e.notified) {
					if (!exists) {
						if (e.state != 0)
							e.state = 0, report = true; // 语料:清通知后直接跳 notify
					} else if ((now - mtime < 0x321)
					           || (e.size != size && (mtime - e.mtime < 0xea61))) {
						e.size = size;      // 仍在写入,先记下大小
						anyActive = exists; // 下轮 400ms 再查
					} else {
						report = true;
					}
					if (report) {
						e.notified = true;
						e.size = size;
						e.mtime = mtime;
						e.state = 1;
						emit fileChanged(e.path); // 0x00902ad8
					}
				} else if (e.state == 2
				           && (e.notified != exists || e.size != size || e.mtime != mtime)) {
					e.state = 0; // 允许再次通知
				}
			}

			{
				QWriteLocker lk(m_lock); // 语料:遍历的就是快照节点,收尾并回
				for (auto it = snap.constBegin(); it != snap.constEnd(); ++it)
					m_entries.insert(it.key(), it.value());
			}
		}

		if (!m_stop)
			msleep(anyActive ? 400 : 1000); // 语料:(!(活跃)&600)+400
	}
}

// ───────── moc 生成面(出处:QMetaObject 元数据) ─────────
// metaObject → &staticMetaObject(0x0119ffc0)
// qt_metacast 0x00902b88(strcmp "FileWatcher" → QThread::qt_metacast)
// qt_metacall 0x00902bca(93B):两条记录(信号 ×2)转发到
//   0x00902b2a;记录 10 → 反查信号号(0 / 1)。
