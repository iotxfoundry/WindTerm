#pragma once

#include <QWidget>

// WidgetListFace — 控件列表(模型变更 / 过滤完成两件事的通知源)。
//
// 出处:RTTI "WidgetList";QMetaObject 0x0119e5e0
// (rev=8,class="WidgetList",methods=2,**signals=2**,props=0,superdata=0);
// dtor 0x008f0092(66B,语料名错标 —— 该 66B 函数体是 strcmp 形式,
// 实为某个派生类的 qt_metacast);deleting 0x008f00d4(5B)。
//
// 两条信号(串表实读):
//   #0 modelChanged()
//   #1 filterFinished()
//
// ⚠ 本类的 ctor 与真正 dtor 在语料里没有独立 entry(内联在调用点),
//   字段布局暂不可得 —— 故本类**只落信号面**,不落字段,避免自造。
class WidgetListFace : public QWidget {
	Q_OBJECT

public:
	explicit WidgetListFace(QWidget *parent = nullptr);

signals:
	void modelChanged();   // #0
	void filterFinished(); // #1
};
