#pragma once

#include <QSharedPointer>
#include <QWidgetAction>

class QWidget;

// HighlightTextBarActionFace — 工具栏里的"高亮文本"行动作。
//
// 出处:RTTI "HighlightTextBarAction";sizeof = **0x20**
// (deleting 0x0055aef6 的 operator_delete(_,0x20));
// dtor 0x0055aeb0(70B)/deleting 0x0055aef6(23B);
// QWidgetAction 的两个重写:
//   vt12 0x0055cad0(280B) createWidget
//   vt14 0x0055c556(409B) requestWidget
//
// **本类没有自己的 Q_OBJECT**:dtor 末尾把 vptr 写回
// `&PTR_metaObject_01184688` —— 与 SlipButtonAction 用的是同一张
// QWidgetAction 族元对象。所以它靠继承拿到元对象,不是一个独立 moc 类。
//
// 字段(dtor/vt14 实读,一对 QSharedPointer):
//   +0x10 引用计数数据指针
//   +0x18 部件指针
class HighlightTextBarActionFace : public QWidgetAction {
public:
	explicit HighlightTextBarActionFace(QObject *parent);

	// QWidgetAction::createWidget 重写 —— vt12 0x0055cad0
	QWidget *createWidget(QWidget *parent) override;

protected:
	// QWidgetAction::requestWidget 重写 —— vt14 0x0055c556
	QWidget *requestWidget(QWidget *parent) override;

private:
	QSharedPointer<QWidget> m_widget; // +0x10/+0x18
};
