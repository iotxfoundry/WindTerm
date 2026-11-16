#pragma once

#include <QToolBar>

// 语料两个 "ActionButton"(批 488)。**两个都名不副实**:
//
// s_ActionButton_56e540(**1291B**):基类是 **QToolBar**(不是按钮)——
//   即"动作工具条"的构建腿(工具栏容器 + 动作装载)。
//
// s_ActionButton_733f60(942B):基类 **QToolButton**,字段 **+0x58**——
//   这才是真正的动作按钮。
class ActionToolBarFace : public QToolBar {   // 名不副实:非 button
	Q_OBJECT
public:
	explicit ActionToolBarFace(QWidget *parent = nullptr);
};
