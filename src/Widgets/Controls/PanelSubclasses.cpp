// PanelSubclasses.cpp — 三个零字段面板/列表子类(见头注对照表)。

#include "Widgets/Controls/PanelSubclasses.h"

#include <QEvent>
#include <QKeyEvent>

// 出处:三者 QMetaObject 的 metacall 均 5 字节纯转发;
// ctor 均内联在调用点,只转发基构造。

// dtor 0x008f01dc(29B)真身:零字段(vptr 复位 + 基类析构两行);
// deleting 0x008f021a(47B)真身。
CheckListPanelFace::CheckListPanelFace(QWidget *parent) : ButtonBarPanelFace(parent) { }
CheckListPanelFace::~CheckListPanelFace() = default;

// vt6 0x00535ace(54B)真身:watched == +0x40 且 KeyPress → 返回 1(吞键),
// 否则落基类 eventFilter。
bool CheckListPanelFace::eventFilter(QObject *watched, QEvent *event)
{
	if (watched == m_keySource40 && event->type() == QEvent::KeyPress)
		return true;
	return ButtonBarPanelFace::eventFilter(watched, event);
}

// dtor 0x008f7650(29B)真身:零字段;deleting 0x008f768e(47B)真身。
ListPanelFace::ListPanelFace(QWidget *parent) : ButtonBarPanelFace(parent) { }
ListPanelFace::~ListPanelFace() = default;

// dtor 0x008f087c(29B)真身:零字段;deleting 0x008f08ba(47B)真身。
ExplorerListFace::ExplorerListFace(QWidget *parent) : WidgetListFace(parent) { }
ExplorerListFace::~ExplorerListFace() = default;
