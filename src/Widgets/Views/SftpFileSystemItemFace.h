#pragma once

#include "Widgets/Views/FileSystemItemFace.h"

// SftpFileSystemItemFace — 远程(SFTP)文件树条目(FileSystemItem 派生,**不新增字段**)。
//
// 出处:RTTI "SftpFileSystemItem";sizeof = **0x98**
// (deleting 0x00635414 的 operator_delete(_,0x98))—— **与基类同尺寸**,
// 说明本类纯做类型区分,不加任何字段。
// 同样是语料名错位:称为 `_metaObject`(0x006351c0,596B)的是 non-deleting 析构,
// 称为 `_qt_metacast`(0x00635414,621B)的是 deleting 析构;两者都把 vptr
// 写回 `&FileSystemItem_vtable` ⇒ 基类 = FileSystemItem。
class SftpFileSystemItemFace : public FileSystemItemFace {
	Q_OBJECT

public:
	explicit SftpFileSystemItemFace(QObject *parent = nullptr);
	~SftpFileSystemItemFace() override; // 0x006351c0 / deleting 0x00635414
};
