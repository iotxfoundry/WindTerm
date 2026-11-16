#ifndef WIDGETS_CONTROLS_HTMLLISTFACE_H
#define WIDGETS_CONTROLS_HTMLLISTFACE_H

#pragma once

// HtmlList — HTML 条目列表(QListView 直接派生,自研 delegate)。
// RTTI 类名 "HtmlList";ctor FUN_0058222a(0x0058222a,131B);dtor 0x008f754e(29B)。
//
// **继承关系勘误(2026-11-16)**:HtmlList 的 ctor 首句是
// `QListView::QListView(this, parent)`,不是 `ListView::ListView` ⇒
//   HtmlList 的基是 **QListView**,与 ListView 是**兄弟**,不是父子。
// 而 CompleteList 的 dtor 写 `&HtmlList_vtable` ⇒ CompleteList 的基是 HtmlList。
// 因此正确链是:
//   QListView → HtmlList → CompleteList
//   QListView → ListView            (兄弟分支,Completer 用的就是这条)
//
// 字段(ctor 实读):
//   +0x30 void*  0
//   +0x38 qint64 -1

#include <QListView>

class HtmlListFace : public QListView {
	Q_OBJECT

public:
	explicit HtmlListFace(QWidget *parent = nullptr); // 0058222a
	~HtmlListFace() override;                        // 008f754e

private:
	void *m_f30 = nullptr;   // +0x30
	qint64 m_f38 = -1;       // +0x38
};

#endif // WIDGETS_CONTROLS_HTMLLISTFACE_H
