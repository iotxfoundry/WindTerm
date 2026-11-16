#pragma once

#include <QHash>
#include <QString>
#include <QThread>

class QReadWriteLock;

// FileWatcherFace — 轮询式文件监视线程(QThread 派生)。
//
// 出处:RTTI "FileWatcher";QMetaObject 0x0119ffc0
// (rev=8,class="FileWatcher",methods=2,signals=2,props=0,superdata=0);
// run() = vt12 0x0062b2d8(709B);dtor 0x0062b1e0(223B)/
// deleting 0x0062b2c0(23B,operator_delete(_,**0x38**));
// metacast 0x00902b88(strcmp "FileWatcher" → QThread);metacall 0x00902bca(93B)。
//
// 信号(串表实读):
//   #0 fileChanged(const QString &path)      发射器 0x00902ad8(39B,activate idx 0)
//   #1 directoryChanged(const QString &path) 发射器 0x00902b00(42B,activate idx 1)
//
// 字段(dtor/run 双向实读,size 0x38):
//   +0x18 QReadWriteLock*  堆上,dtor 里 delete
//   +0x20 QHash<?>         条目表(d-pointer,dtor 走 QHashData::free_helper)
//   +0x28 QHash<?>         快照表(同上;run 里以读锁保护并对它 detach)
//   +0x30 bool            停止标志(run 每条循环查一次)
//
// 每条目的布局(run 实读,相对节点基址):
//   +0x10 QString 路径
//   +0x18 bool    已通知
//   +0x20 qint64  上次大小
//   +0x28 qint64  上次 mtime(ms)
//   +0x30 u8      状态(0 = 未通知,1 = 已通知,2 = 已确认)
class FileWatcherFace : public QThread {
	Q_OBJECT

public:
	explicit FileWatcherFace(QObject *parent = nullptr);
	~FileWatcherFace() override; // 0062b1e0

	void addPath(const QString &path);    // 加入监视集(cited)
	void removePath(const QString &path); // 移出监视集(cited)

signals:
	void fileChanged(const QString &path);      // #0
	void directoryChanged(const QString &path); // #1

protected:
	void run() override; // vt12 0x0062b2d8(709B)

private:
	struct Entry {
		QString path;    // +0x10
		bool notified = false;   // +0x18
		qint64 size = 0;         // +0x20
		qint64 mtime = 0;        // +0x28
		quint8 state = 0;        // +0x30
	};

	bool m_stop = false;             // +0x30
	QReadWriteLock *m_lock = nullptr; // +0x18
	QHash<QString, Entry> m_entries;  // +0x20
	QHash<QString, Entry> m_snapshot; // +0x28
};
