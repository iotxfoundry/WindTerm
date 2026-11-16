// LocalFileSystemItemFace.cpp — 本地文件树条目。

#include "Widgets/Views/LocalFileSystemItemFace.h"

// 出处:QMetaObject 继承自 FileSystemItem(本类无独立 Q_OBJECT 元对象,
// 析构里 vptr 写回 &FileSystemItem_vtable 即证);ctor 内联在调用点。
LocalFileSystemItemFace::LocalFileSystemItemFace(QObject *parent)
    : FileSystemItemFace(parent)
{
}

// non-deleting 析构 0x00634a20(596B):与基类析构逐句同构 ——
//   七个 QString(+0x90..+0x60)+ +0x10 从高到低减引用,落基类析构。
// deleting 析构 0x00634c74(621B):同上 + operator_delete(this, **0xa0**)。
LocalFileSystemItemFace::~LocalFileSystemItemFace() = default;
