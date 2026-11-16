#pragma once

#include <QString>

#include "Widgets/Views/TreeViewFace.h"

// FileTreeFace — 文件树(TreeView 派生,**零字段**)。
//
// 出处:RTTI "FileTree";QMetaObject 0x0119c560
// (rev=8,class="FileTree",methods=1,**signals=1**,
//  superdata=0x0119dc40 = **TreeView**);
// dtor 0x008f9b0e(29B)⇒ 零字段;deleting 0x008f9b4c(47B);
// 分发 0x008fb472(176B);metacast 0x008f9a70 / metacall 0x008f9ab2(92B)。
//
// 唯一信号:`aboutToRename(...)`。
class FileTreeFace : public TreeViewFace {
	Q_OBJECT
public:
	explicit FileTreeFace(QWidget *parent = nullptr);
	~FileTreeFace() override; // 0x008f9b0e

signals:
	void aboutToRename(const QString &path); // 唯一信号
};
