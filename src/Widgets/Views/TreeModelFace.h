#pragma once

#include <QAbstractItemModel>

// TreeModelFace — 树模型的 index/parent/rowCount 覆盖(QAbstractItemModel 派生)。
//
// 出处:RTTI "TreeModel";QMetaObject 0x011a0400
// (**methods=0 / signals=0 / props=0**);
// dtor 0x00644107(67B)/deleting 0x0064414c(23B);
// 四条虚面:vt12 0x00643d90(161B,index)/ vt13 0x00643e38(135B,parent)/
// vt15 0x00643ec0(45B)/ vt2 0x00903044(5B);metaObject 0x00902fea(24B)。
//
// **字段只有一个:+0x10 = 根节点指针**。三条虚面都拿它当"根哨兵"用:
//   · vt12 `index()`:hasIndex 门通过后,
//       父索引**无效** → 从 `this+0x10`(根)取子节点;
//       父索引**有效** → 从其 internalPointer(+2 字)取子节点;
//       取到就返回 QModelIndex(row, col, node, this),取不到返回全 -1。
//   · vt13 `parent()`:child 有效时取 `FUN_00643cd0(child.internalPointer)`,
//       **若它等于 this+0x10(即已是根)** 则返回无效索引 —— 根没有父。
//   · vt15(45B)与 vt2(5B)是另两条小虚面。
//
// ⇒ 这套写法和 RemoteFileSystemModel 的三条访问器**结构同源**
//   (同样 hasIndex 门 + 同样 internalPointer 递推 + 同样全 -1 无效返回),
//   差别只在后者多了内联自旋锁。两处互相当参照。
class TreeModelFace : public QAbstractItemModel {
	Q_OBJECT

public:
	explicit TreeModelFace(QObject *parent = nullptr);
	~TreeModelFace() override; // 0x00644107

	QModelIndex index(int row, int column,
	                  const QModelIndex &parent = QModelIndex()) const override; // vt12
	QModelIndex parent(const QModelIndex &child) const override;                   // vt13

private:
	void *m_root10 = nullptr; // +0x10 根节点(兼作根哨兵)
};
