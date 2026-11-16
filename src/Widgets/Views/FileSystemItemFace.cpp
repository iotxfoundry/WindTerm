// FileSystemItemFace.cpp — 文件树条目。

#include "Widgets/Views/FileSystemItemFace.h"

FileSystemItemFace::FileSystemItemFace(QObject *parent)
    : TreeListModelFace(parent)
{
}

// 0x006230f0(596B)non-deleting 析构真身:
//   vptr = &FileSystemItem_vtable;
//   依次释放 +0x90 / +0x88 / +0x80 / +0x78 / +0x70 / +0x68 / +0x60 七个 QString,
//   再释放 +0x10,顺序为**从高地址往低地址**;
//   末尾落基类析构。
// 0x00622e78(621B)deleting 析构:同一串释放后 operator_delete(this, 0x98)。
// 注:两处 QString 的释放都是"引用计数减一,归零才真正释放 d"的标准语义。
FileSystemItemFace::~FileSystemItemFace() = default;

// vt2 0x0057cfa0(33B)真身:
//   取 +0x10 的 d 指针;引用计数非 0/-1 时加一后返回 —— 即带引用计数
//   的字符串拷贝(与 QString 隐式共享同语义)。
QString FileSystemItemFace::refString() const
{
	return m_f10;
}

// ───────── moc 生成面(出处:QMetaObject 元数据) ─────────
// metaObject 0x0090304c(24B)→ &PTR_staticMetaObject_011a05e0
//   (无动态元对象时)。该类名是 "TreeListModel",不是 "FileSystemItem"
//   —— 因为 FileSystemItem 自身没有 Q_OBJECT,元对象来自基类。
