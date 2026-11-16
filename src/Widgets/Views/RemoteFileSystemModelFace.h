#pragma once

#include <QAbstractItemModel>

// RemoteFileSystemModelFace — 远程(会话侧)文件系统条目模型。
//
// 出处:RTTI "RemoteFileSystemModel";index/parent/hasChildren 三个覆盖:
//   index        = vt12 0x00624eae(339B)
//   parent       = vt13 0x006251f2(323B)
//   hasChildren  = vt15 0x0062537a(273B)
// 析构体 0x00626248(313B)+ dtor 0x006249fe(19B)/ deleting 0x00624a12(37B,
// operator_delete(_,**0x38**))。
//
// **三个覆盖共用同一把内联自旋锁**:每个函数体前半都是同一段模板 ——
//   读 +0x10 字节;非 0 则进自旋:置 +0x11 = 1,比对旧值,
//   未抢到就 sched_yield 若干次,再 nanosleep(100ns / 10us)指数退避;
//   拿到后在函数尾把 +0x11 写回 0。
// 这不是 Qt 的 QMutex(布局对不上),是 WindTerm 自有的自旋锁,
// 被编译器内联进了每个访问器 —— 所以三个函数体看起来高度雷同。
//
// 字段(实读):
//   +0x10 u8   锁字
//   +0x11 u8   抢锁标志
//   +0x18 void*  0x20 字节的辅助件(析构时 FUN_00625fb6 + operator_delete(_,0x20))
//   +0x28 QHash  d-pointer(析构走 QHashData::free_helper)
//   +0x80/+0x88  析构里被读/清的一对(类型未定,Ghidra 按 8 字节步长索引)
class RemoteFileSystemModelFace : public QAbstractItemModel {
	Q_OBJECT

public:
	explicit RemoteFileSystemModelFace(QObject *parent = nullptr);
	~RemoteFileSystemModelFace() override; // 0x00626248

	QModelIndex index(int row, int column,
	                  const QModelIndex &parent = QModelIndex()) const override; // vt12
	QModelIndex parent(const QModelIndex &child) const override;                   // vt13
	bool hasChildren(const QModelIndex &parent = QModelIndex()) const override;    // vt15

private:
	void spinLock() const;   // 内联段,+0x10/+0x11
	void spinUnlock() const; // 内联段,尾写 +0x11 = 0

	void *m_helper18 = nullptr; // +0x18
	void *m_hash28 = nullptr;   // +0x28
	mutable quint8 m_lock10 = 0; // +0x10
	mutable quint8 m_lockFlag11 = 0; // +0x11
};
