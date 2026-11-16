#pragma once

#include <QWidget>

// 语料两个"清单"控件(批 487)。
//
// CheckList — s_CheckList_534e62(344B):vtable **CheckList_vtable**;
//   字段 **+0x10**(副 vptr 位)/ **+0x30**。带勾选项的列表件。
//
// ExplorerList — s_ExplorerList_55456a(291B):vtable **ExplorerList_vtable**;
//   字段 **+0x10** / **+0x30** / **+0x60**。文件浏览器列表(与 ExplorerPane 族同源)。
// 补充(批 489):CloseButton(s_CloseButton_585528,897B)——**QToolButton 族**,
//   字段 +0x30 / +0x38 / +0x40;与 s_CloseButton_5a6d42(552B,页签关钮,批 474)
//   是两个不同的关闭钮(前者属 Explorer/KitDock 族)。
class CloseButtonFace : public QWidget {
	Q_OBJECT
public:
	explicit CloseButtonFace(QWidget *parent = nullptr);

protected:
	QWidget *m_f30 = nullptr; QWidget *m_f38 = nullptr; QWidget *m_f40 = nullptr;
};
