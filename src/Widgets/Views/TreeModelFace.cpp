// TreeModelFace.cpp — 树模型(见头注)。

#include "Widgets/Views/TreeModelFace.h"

// 同族节点操作(0x0064xxxx 区,尚未开批):
static void *childAt(const void *node, int row);   // 0x00643c2a
static void *nodeParent(const void *node);         // 0x00643cd0
static int nodeRowOf(const void *node);            // 0x00643cd4

// 出处:QMetaObject 0x011a0400(methods=0 signals=0);ctor 内联在调用点。
TreeModelFace::TreeModelFace(QObject *parent)
    : QAbstractItemModel(parent)
{
}

// dtor 0x00644107(67B)真身:唯一字段 +0x10 的节点树整体释放 →
// QAbstractItemModel 析构;deleting 0x0064414c(23B)真身。
TreeModelFace::~TreeModelFace() = default;

// vt12 0x00643d90(161B)index 真身:
//   hasIndex 门 → 父索引无效则从根(+0x10)、有效则从 internalPointer 取子节点
//   → QModelIndex(row, col, node, this);取不到 → 全 -1。
QModelIndex TreeModelFace::index(int row, int column, const QModelIndex &parent) const
{
	if (!hasIndex(row, column, parent))
		return QModelIndex();
	const void *src = parent.isValid() ? parent.internalPointer() : m_root10;
	void *const node = childAt(src, row);
	if (node == nullptr)
		return QModelIndex();
	return createIndex(row, column, node);
}

// vt13 0x00643e38(135B)parent 真身:
//   child 有效 → p = nodeParent(child.internalPointer());
//   **p == 根(+0x10)** 则返回无效(根无父);否则 QModelIndex(row(p), 0, p, this)。
QModelIndex TreeModelFace::parent(const QModelIndex &child) const
{
	if (!child.isValid())
		return QModelIndex();
	void *const p = nodeParent(child.internalPointer());
	if (p == m_root10)
		return QModelIndex();
	return createIndex(nodeRowOf(p), 0, p);
}

static void *childAt(const void *, int) { return nullptr; }
static void *nodeParent(const void *) { return nullptr; }
static int nodeRowOf(const void *) { return -1; }
