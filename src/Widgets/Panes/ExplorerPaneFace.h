#pragma once

#include <QWidget>

#include "Widgets/Panes/KitPaneFace.h"

// ExplorerPaneFace — 文件浏览器面板(KitPane 派生,size 0x58,零字段)。
//
// 出处:RTTI "ExplorerPane";QMetaObject 0x011a5180
// (rev=8,class="ExplorerPane",**methods=0 / signals=0 / props=0**,
//  superdata=0x011ab900 = **KitPane**);
// sizeof = **0x58**(deleting 0x00909bc2 的 operator_delete(_,0x58));
// dtor 0x00909b84(29B)⇒ **零自有字段**;
// 虚面:vt5 0x008c4c18(61B)/ vt6 0x008c4446(**1827B**)/ vt13 0x008c4bea(45B)。
//
// ⚠ **语料名把 K 班的两个函数挂到了这里**(本会话第 3 次同型错位):
//   称为 `KitPane_dtor`(0x00909b3c,66B)的实为 **ExplorerPane::qt_metacast**
//   (strcmp "ExplorerPane" 后落 KitPane::qt_metacast);
//   称为 `KitPane_dtor_deleting`(0x00909b7e,5B)的实为 **ExplorerPane::qt_metacall**。
//   判据:本类 superdata 就是 KitPane,而这两个函数体正是 ExplorerPane 的 moc 面。
//
// 三条虚面:
//   vt5 0x008c4c18(61B)  —— 事件腿
//   vt6 0x008c4446(**1827B**)—— 事件过滤主体(最大的一块,本批只锚入口)
//   vt13 0x008c4bea(45B) —— 小判定
class ExplorerPaneFace : public KitPaneFace {
	Q_OBJECT
public:
	explicit ExplorerPaneFace(QWidget *parent = nullptr);
	~ExplorerPaneFace() override; // 0x00909b84

protected:
	bool eventFilter(QObject *watched, QEvent *event) override; // vt6 0x008c4446(cited)
};
