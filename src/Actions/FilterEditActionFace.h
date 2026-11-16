#pragma once

#include <QList>
#include <QWidgetAction>

class QWidget;

// FilterEditActionFace — 过滤器输入框动作。
//
// 出处:RTTI "FilterEditAction";dtor 0x005b2c26(19B)/deleting 0x005b2c3a(37B);
// requestWidget = vt14 0x005b3180(87B)。无自有 Q_OBJECT。
//
// 字段:+0x18 被返回的控件(单件包装成 QList)
class FilterEditActionFace : public QWidgetAction {
public:
	explicit FilterEditActionFace(QObject *parent);

	QWidget *requestWidget(QWidget *parent) override; // vt14 0x005b3180

private:
	QWidget *m_w18 = nullptr; // +0x18
};
