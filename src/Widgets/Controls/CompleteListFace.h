#ifndef WIDGETS_CONTROLS_COMPLETELISTFACE_H
#define WIDGETS_CONTROLS_COMPLETELISTFACE_H

#pragma once

// CompleteList — 补全列表件。RTTI 类名 "CompleteList";
// dtor 0x00955042(29B)/ deleting 0x00955066(23B)。
//
// 继承链(dtor 实读 + ctor 首句实读,**已勘误**):
//     QListView → HtmlList → CompleteList
//     QListView → ListView          ← 兄弟分支,Completer 用的是这条
// 依据:
//   · CompleteList_dtor 把 vptr 写成 `&HtmlList_vtable` ⇒ 基是 HtmlList
//   · HtmlList ctor 首句是 `QListView::QListView(...)` ⇒ HtmlList 直挂 QListView
//   (早先误判为 QListView→ListView→HtmlList→CompleteList,已按上述两条改正)

#include "Widgets/Controls/HtmlListFace.h"

class CompleteListFace : public HtmlListFace {
	Q_OBJECT

public:
	explicit CompleteListFace(QWidget *parent = nullptr);
	~CompleteListFace() override; // 00955042
};

#endif // WIDGETS_CONTROLS_COMPLETELISTFACE_H
