// TreeListModelFace.cpp — 文件树模型基座(仅元对象身份)。

#include "Widgets/Views/TreeListModelFace.h"

// 出处:QMetaObject 0x011a05e0(class="TreeListModel",superdata=0)。
// 本类无自有虚函数:ctor 仅转发 QObject 基构造。
TreeListModelFace::TreeListModelFace(QObject *parent)
    : QObject(parent)
{
}
