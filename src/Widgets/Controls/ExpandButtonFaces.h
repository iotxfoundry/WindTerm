#pragma once

#include <QWidget>

// 语料两个 "ExpandButton"(批 491)。注意与 s_ExpandButton_8b7dd4(371B =
// KitDock 装配,**名不副实**)区分:这里两个才是真正的展开钮。
//
// s_ExpandButton_5984be(**1021B**):字段 **+0x30 / +0x38 / +0x40**
//   —— 展开/收起钮(三角 + 标题 + 容器三件)。
// s_ExpandButton_5ab32a(584B):无自有字段(纯行为:切换 + 信号)。
class ExpandButtonFace : public QWidget {
	Q_OBJECT
public:
	explicit ExpandButtonFace(QWidget *parent = nullptr);

protected:
	QWidget *m_f30 = nullptr; // +0x30
	QWidget *m_f38 = nullptr; // +0x38
	QWidget *m_f40 = nullptr; // +0x40
};

class ExpandToggleFace : public QWidget {
	Q_OBJECT
public:
	explicit ExpandToggleFace(QWidget *parent = nullptr);
};
