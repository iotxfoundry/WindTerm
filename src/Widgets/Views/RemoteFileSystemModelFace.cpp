// RemoteFileSystemModelFace.cpp — 远程文件系统模型。

#include "Widgets/Views/RemoteFileSystemModelFace.h"

#include <QModelIndex>
#include <sched.h>
#include <time.h>

// 三个被调件(节点层,同属 0x0062xxxx 区,尚未开批):
static void *nodeForIndex(const RemoteFileSystemModelFace *self, const QModelIndex &parent); // 0x00624e8a
static int nodeRow(const void *node);       // 0x00624c48
static bool nodeHasChildren(const void *node); // 0x00624c9c
static void helperDestroy(void *p);          // 0x00625fb6

RemoteFileSystemModelFace::RemoteFileSystemModelFace(QObject *parent)
    : QAbstractItemModel(parent)
{
}

// 0x00626248(313B)析构体真身。逐句:
//   vptr = &PTR_FileSystemItem_vt10_011a0458(注意:语料符号挂在 FileSystemItem
//     名下 —— 远程模型与本地模型共用这一族 vtable 段)
//   +0x18 非空 → helperDestroy(+0x18) → operator_delete(_, 0x20)
//   +0x88 = 0
//   +0x28 QHash d-pointer 引用计数减一,归零走 QHashData::free_helper
//   QAbstractItemModel::~QAbstractItemModel
// dtor 0x006249fe(19B):同上去掉 operator_delete;
// deleting 0x00624a12(37B):operator_delete(this, 0x38)。
RemoteFileSystemModelFace::~RemoteFileSystemModelFace()
{
	if (m_helper18 != nullptr) {
		helperDestroy(m_helper18);
		operator delete(m_helper18); // 语料:operator_delete(_, 0x20)
		m_helper18 = nullptr;
	}
}

// 内联自旋锁(三段共用同一模板,见头注):
//   读 +0x10;非 0 才进自旋。自旋里先把 +0x11 置 1,读旧值;
//   旧值为 0 表示抢到;否则 2 次内 sched_yield,16 次内 nanosleep(100ns),
//   之后 nanosleep(10us),逐次递增重试计数。
// ⚠ 这是**逐句转写**,不是发明:退避阶梯 2 / 0x10 / 0x20 与
//   100ns / 10us 均取自语料字面。
void RemoteFileSystemModelFace::spinLock() const
{
	if (m_lock10 == 0)
		return;
	unsigned tries = 0;
	for (;;) {
		const quint8 old = m_lockFlag11;
		m_lockFlag11 = 1;
		if (old == 0)
			return; // 抢到
		if (tries < 2) {
			++tries;
		} else if (tries < 0x10) {
			sched_yield();
			++tries;
		} else {
			timespec ts { 0, (tries < 0x20) ? 100L : 10000L };
			while (nanosleep(&ts, &ts) == -1 && errno == 4 /*EINTR*/) { }
			++tries;
		}
	}
}

void RemoteFileSystemModelFace::spinUnlock() const
{
	if (m_lock10 != 0)
		m_lockFlag11 = 0;
}

// vt12 0x00624eae(339B)index() 真身。逐句:
//   if (!hasIndex(row, column, parent)) return QModelIndex();   ← 无效(全 -1/0)
//   spinLock();
//   node = nodeForIndex(this, parent.internalPointer())  (0x00624e8a)
//   if (!node) return QModelIndex();
//   return QModelIndex(row, column, node, this)
//     (语料:`*out = row; out[1] = column; *(long*)(out+2) = node;
//            *(long*)(out+4) = this` —— QModelIndex 四字段)
//   spinUnlock();
QModelIndex RemoteFileSystemModelFace::index(int row, int column, const QModelIndex &parent) const
{
	if (!hasIndex(row, column, parent))
		return QModelIndex();

	spinLock();
	void *const node = nodeForIndex(this, parent);
	spinUnlock();
	if (node == nullptr)
		return QModelIndex();
	return createIndex(row, column, node);
}

// vt13 0x006251f2(323B)parent() 真身。逐句:
//   门:child 行/列任一 < 0 或 internalPointer == 0 → 返回无效索引
//   spinLock();
//   node = child.internalPointer();
//   若 node == this 的根哨兵 → 返回无效索引
//   否则:row = nodeRow(node)(0x00624c48);返回 QModelIndex(row, 0, node, this)
//   spinUnlock();
QModelIndex RemoteFileSystemModelFace::parent(const QModelIndex &child) const
{
	if (!child.isValid())
		return QModelIndex();

	spinLock();
	void *const node = child.internalPointer();
	const bool isRoot = (node == m_helper18); // 语料:与 +0x18 比对
	const int row = node ? nodeRow(node) : -1;
	spinUnlock();

	if (isRoot || node == nullptr)
		return QModelIndex();
	return createIndex(row, 0, node);
}

// vt15 0x0062537a(273B)hasChildren() 真身。逐句:
//   门:**有效索引** 且 column != 0 → 直接 0(只有第 0 列有子)
//   spinLock();
//   node = nodeForIndex(this, parent)
//   has = nodeHasChildren(node)(0x00624c9c)
//   spinUnlock();
//   return has
bool RemoteFileSystemModelFace::hasChildren(const QModelIndex &parent) const
{
	if (parent.isValid() && parent.column() != 0)
		return false;

	spinLock();
	void *const node = nodeForIndex(this, parent);
	const bool has = node ? nodeHasChildren(node) : false;
	spinUnlock();
	return has;
}

static void *nodeForIndex(const RemoteFileSystemModelFace *, const QModelIndex &)
{
	return nullptr;
}
static int nodeRow(const void *) { return -1; }
static bool nodeHasChildren(const void *) { return false; }
static void helperDestroy(void *) { }
