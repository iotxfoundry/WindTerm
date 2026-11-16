#pragma once

#include <QFrame>

#include "Widgets/Bars/ButtonBarPanelFace.h"
#include "Widgets/Controls/WidgetListFace.h"

// PanelSubclasses.h — 三个"零字段"的面板/列表子类。
//
// 三者 QMetaObject 的 metacall 都是 **5 字节纯转发** ⇒ 0 条自有信号槽;
// dtor 一律 **29B**(vptr 复位 + 基类析构)⇒ **零自有字段**。
//
// | 类 | superdata 实读 | dtor | deleting | 其他 |
// |---|---|---|---|---|
// | CheckListPanel | **0x01193440 ButtonBarPanel** | 0x008f01dc(29B) | 0x008f021a(47B) | vt6 0x00535ace(54B) |
// | ListPanel      | **0x01193440 ButtonBarPanel** | 0x008f7650(29B) | 0x008f768e(47B) | — |
// | ExplorerList   | **0x0119e5e0 WidgetList**      | 0x008f087c(29B) | 0x008f08ba(47B) | — |
//
// ⚠ CheckListPanel / ListPanel 的 dtor 末句调 **QFrame::~QFrame** ——
//   因为它们的基类 ButtonBarPanel 本身就派生自 QFrame(dtor 29B 只复位 vptr)。
//   ⇒ "看到 dtor 调 QFrame 就以为直接派生 QFrame"是错的,superdata 才是准的。
//
// CheckListPanel 的 vt6(54B)eventFilter:
//   门 `watched == +0x40 && KeyPress(6)` 后返回 **1**(吞键),
//   否则落基类。沿用前面几批同一套"键位来源件 + 吞键"写法。

class CheckListPanelFace : public ButtonBarPanelFace {
	Q_OBJECT
public:
	explicit CheckListPanelFace(QWidget *parent = nullptr);
	~CheckListPanelFace() override; // 0x008f01dc

protected:
	bool eventFilter(QObject *watched, QEvent *event) override; // vt6 0x00535ace

private:
	void *m_keySource40 = nullptr; // +0x40
};

class ListPanelFace : public ButtonBarPanelFace {
	Q_OBJECT
public:
	explicit ListPanelFace(QWidget *parent = nullptr);
	~ListPanelFace() override; // 0x008f7650
};

class ExplorerListFace : public WidgetListFace {
	Q_OBJECT
public:
	explicit ExplorerListFace(QWidget *parent = nullptr);
	~ExplorerListFace() override; // 0x008f087c
};
