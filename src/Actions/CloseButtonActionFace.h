#pragma once

#include <QWidgetAction>

class QWidget;

// CloseButtonActionFace — 带关闭按钮的工具栏行动作。
//
// 出处:RTTI "CloseButtonAction";dtor 0x005b2bec(19B)/deleting 0x005b2c00(37B);
// createWidget = vt12 0x005b2c60(222B)。
// 与六个零字段同族一样没有自己的 Q_OBJECT(vptr 写 PTR_metaObject_01184688)。
//
// 字段(createWidget 实读):
//   +0x10 QWidget* 行容器(createWidget 的返回值)
//   +0x18 QWidget* 首个控件(加时带边距折半)
//   +0x20 QWidget* 第二个控件
//   +0x28 QWidget* 第三个控件(关闭按钮)
class CloseButtonActionFace : public QWidgetAction {
public:
	explicit CloseButtonActionFace(QObject *parent);

	QWidget *createWidget(QWidget *parent) override; // vt12 0x005b2c60

private:
	QWidget *m_row10 = nullptr;  // +0x10
	QWidget *m_w18 = nullptr;    // +0x18
	QWidget *m_w20 = nullptr;    // +0x20
	QWidget *m_close28 = nullptr; // +0x28
};
