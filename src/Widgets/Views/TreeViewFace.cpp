// TreeViewFace.cpp — 树视图基座。

#include "Widgets/Views/TreeViewFace.h"

// 出处:QMetaObject 0x0119dc40(class="TreeView",methods=4,signals=2,props=1);
// ctor 内联在调用点,仅转发 QTreeView 基构造。
TreeViewFace::TreeViewFace(QWidget *parent)
    : QTreeView(parent)
{
}

// 槽体(实现区未开批;按元对象锚入口):
void TreeViewFace::onFilterChanged(const QString &filter) { Q_UNUSED(filter); }
void TreeViewFace::resizeColumnToContents() { }

// metasurface:prop `singleLine` 与 ListView 的同名属性同形 ——
// 两处都不占新字段,对应基类的位旗标。这类"属性不新增成员"的映射,
// 靠 dtor 里没有新字段来确认,不能只看 metaobject。
