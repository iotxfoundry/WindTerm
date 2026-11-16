// SftpFileSystemItemFace.cpp — 远程文件树条目。

#include "Widgets/Views/SftpFileSystemItemFace.h"

// 出处:元对象继承自 FileSystemItem(析构里 vptr 写回 &FileSystemItem_vtable);
// ctor 内联在调用点。本类零字段,与 LocalFileSystemItem 的 0xa0 对照即证。
SftpFileSystemItemFace::SftpFileSystemItemFace(QObject *parent)
    : FileSystemItemFace(parent)
{
}

// non-deleting 析构 0x006351c0(596B)与 deleting 0x00635414(621B):
// 与基类析构逐句同构,后者末尾 operator_delete(this, **0x98**)。
SftpFileSystemItemFace::~SftpFileSystemItemFace() = default;
