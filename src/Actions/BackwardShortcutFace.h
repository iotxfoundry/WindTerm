#pragma once

#include <QWidget>

// s_BackwardButton_53e936(753B):**基类 = QShortcut**(不是按钮!)——
//   即"后退"快捷键的绑定族,字段 **+0x38 / +0x40 / +0x48 / +0x50 / +0x58**。
//   与前缀 BackwardButton 的字面("按钮")不符 —— **名不副实**。
class BackwardShortcutFace : public QWidget {   // 基类未直接声明 QShortcut
	Q_OBJECT
public:
	explicit BackwardShortcutFace(QWidget *parent = nullptr);

protected:
	QWidget *m_f38 = nullptr; QWidget *m_f40 = nullptr; QWidget *m_f48 = nullptr;
	QWidget *m_f50 = nullptr; QWidget *m_f58 = nullptr;
};
