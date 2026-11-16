#pragma once

// s_ActionButton_733f60(942B):基类 **QToolButton**,字段 **+0x58** —— 真正的动作按钮。

#include <QToolButton>

class ActionButtonFace : public QToolButton {
	Q_OBJECT
public:
	explicit ActionButtonFace(QWidget *parent = nullptr);

protected:
	QWidget *m_f58 = nullptr; // +0x58
};
