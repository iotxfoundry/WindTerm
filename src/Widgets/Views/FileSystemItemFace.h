#pragma once

#include <QString>

#include "Widgets/Views/TreeListModelFace.h"

// FileSystemItemFace — 文件树条目(本地/远程共用的节点元数据)。
//
// 出处:RTTI "FileSystemItem";sizeof = **0x98**
// (deleting 析构里的 operator_delete(_,0x98));
// 两个析构:0x00622e78(621B,**deleting**)/ 0x006230f0(596B,**non-deleting**)
//   —— 语料把这两个名字错标成 FileSystemItem_qt_metacast / _metaObject。
// 元对象 0x0090304c(24B)→ &PTR_staticMetaObject_011a05e0(class="TreeListModel");
// 虚面 vt2 0x0057cfa0(33B) = 取一个引用计数的字符串(带引用加一)。
//
// 字段(两个析构逐字段实读,index 按 8 字节步长):
//   +0x10 QString
//   +0x48 int      行号 —— 由 0x00622e74(4B)`return *(int*)(this+0x48)` 证实
//   +0x60 QString
//   +0x68 QString
//   +0x70 QString
//   +0x78 QString
//   +0x80 QString
//   +0x88 QString
//   +0x90 QString
class FileSystemItemFace : public TreeListModelFace {
	Q_OBJECT

public:
	explicit FileSystemItemFace(QObject *parent = nullptr);
	~FileSystemItemFace() override; // 0x006230f0 / deleting 0x00622e78

	int row() const { return m_row48; } // 0x00622e74
	void setRow(int r) { m_row48 = r; }

protected:
	// vt2 0x0057cfa0(33B):返回 +0x10 处字符串的引用计数加一副本
	QString refString() const;

	QString m_f10;   // +0x10
	int m_row48 = 0; // +0x48
	QString m_f60;   // +0x60
	QString m_f68;   // +0x68
	QString m_f70;   // +0x70
	QString m_f78;   // +0x78
	QString m_f80;   // +0x80
	QString m_f88;   // +0x88
	QString m_f90;   // +0x90
};
