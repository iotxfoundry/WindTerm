#pragma once

#include <QWidgetAction>

// SlipButtonActionFace — SlipButton 的菜单行动作(QWidgetAction 派生)。
//
// 出处:RTTI "SlipButtonAction";dtor 0x006a8cd6(19B)/deleting 0x006a8cea(37B);
// 虚面 vt14 0x006aa370(279B)= QWidgetAction::createWidget 的重写。
// sizeof = 0x30(deleting 的 operator_delete(_,0x30))。
//
// 字段(createWidget 实读):
//   +0x10 QWidget*  可选前置件(为 0 时跳过 addWidget)
//   +0x18 QWidget*  行文本(QLabel)
//   +0x20 QWidget*  右侧开关(SlipButtonFace)
//   +0x28 QWidget*  行容器(defaultWidget;createWidget 把布局挂到它上面)
class SlipButtonActionFace : public QWidgetAction {
	Q_OBJECT

public:
	explicit SlipButtonActionFace(QObject *parent);

	// QWidgetAction::createWidget 重写 — 0x006aa370(279B)
	QWidget *createWidget(QWidget *parent) override;

	// 版面字段(见头注)
	QWidget *m_lead10 = nullptr;   // +0x10
	QWidget *m_label18 = nullptr;  // +0x18
	QWidget *m_switch20 = nullptr; // +0x20
	QWidget *m_row28 = nullptr;    // +0x28
};
