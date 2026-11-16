#ifndef WIDGETS_CONTROLS_COMPLETELISTFACE_H
#define WIDGETS_CONTROLS_COMPLETELISTFACE_H

#pragma once

// CompleteList — 补全列表件。RTTI 类名 "CompleteList";dtor 0x00955042(29B) /
// deleting 0x00955066(23B)。
//
// **继承链实读(重要)**:CompleteList 的 dtor 把 vptr 写成 `&HtmlList_vtable`,
// 而 HtmlList 的基是 ListView(ListView ctor = FUN_00583bac / 0x00583bac,703B,
// vptr 写 `&ListView_vtable`,字段占到 +0x68)。即:
//
//     QListView → ListView(703B 自有字段) → HtmlList → CompleteList
//
// 这也解释了 Completer 里那个「0x78B 的列表件」:它不是裸 QListView,
// 而是这条三层链的末端。三层里 ListView / HtmlList **尚未建模**,
// 本类暂以 QListView 为基承载,等 ListView 落地后再改基(会连带改尺寸与虚面)。

#include <QListView>

class CompleteListFace : public QListView {
	Q_OBJECT

public:
	CompleteListFace(QWidget *parent = nullptr);
	~CompleteListFace() override; // 00955042

private:
	// 注:真实基类为 HtmlList(其 vptr 即 dtor 里写入的 HtmlList_vtable)。
	// 建模 HtmlList/ListView 后,本类基类应改为 HtmlListFace。
};

#endif // WIDGETS_CONTROLS_COMPLETELISTFACE_H
