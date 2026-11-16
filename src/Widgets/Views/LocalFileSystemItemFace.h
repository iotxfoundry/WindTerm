#pragma once

#include "Widgets/Views/FileSystemItemFace.h"

// LocalFileSystemItemFace — 本地文件树条目(FileSystemItem 派生)。
//
// 出处:RTTI "LocalFileSystemItem";sizeof = **0xa0**
// (deleting 0x00634c74 的 operator_delete(_,0xa0));基类 0x98 ⇒ **多 8 字节**,
// 即 +0x98 处一个额外字段。
// 语料名又错位了:称为 `_metaObject`(0x00634a20,596B)的是 **non-deleting 析构**,
// 称为 `_qt_metacast`(0x00634c74,621B)的是 **deleting 析构**
// —— 两者函数体与 FileSystemItem 的对应析构逐句同构,只是 vptr 写回
// `&FileSystemItem_vtable`(⇒ 基类是 FileSystemItem)。
//   `_dtor`(0x00633d10,4B)= `return *(int*)(this+0x48)`,即 **row()**;
//   `_qt_metacall`(0x00633d18,27B)= 取 +0x10 字符串并加引用(vt2 同构)。
class LocalFileSystemItemFace : public FileSystemItemFace {
	Q_OBJECT

public:
	explicit LocalFileSystemItemFace(QObject *parent = nullptr);
	~LocalFileSystemItemFace() override; // 0x00634a20 / deleting 0x00634c74

private:
	void *m_f98 = nullptr; // +0x98(基类之外的唯一字段)
};
