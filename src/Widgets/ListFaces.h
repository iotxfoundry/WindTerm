#pragma once

#include <QWidget>

// 语料两个"清单"控件(批 487)。
//
// CheckList — s_CheckList_534e62(344B):vtable **CheckList_vtable**;
//   字段 **+0x10**(副 vptr 位)/ **+0x30**。带勾选项的列表件。
//
// ExplorerList — s_ExplorerList_55456a(291B):vtable **ExplorerList_vtable**;
//   字段 **+0x10** / **+0x30** / **+0x60**。文件浏览器列表(与 ExplorerPane 族同源)。
class CheckListFace : public QWidget {
	Q_OBJECT
public:
	explicit CheckListFace(QWidget *parent = nullptr);

protected:
	QWidget *m_f30 = nullptr; // +0x30
};

class ExplorerListFace : public QWidget {
	Q_OBJECT
public:
	explicit ExplorerListFace(QWidget *parent = nullptr);

protected:
	QWidget *m_f30 = nullptr; // +0x30
	QWidget *m_f60 = nullptr; // +0x60
};
