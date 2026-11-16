// ActionButtonFaces.cpp — 动作工具条 / 动作按钮(批 488)
#include "ActionButtonFaces.h"

// s_ActionButton_56e540(1291B)**QToolBar** 构建腿
ActionToolBarFace::ActionToolBarFace(QWidget *parent)
	: QToolBar(parent)
{
	// 1291B 体:动作装载/按钮插入 — cited
}

// s_ActionButton_733f60(942B)QToolButton 子类
ActionButtonFace::ActionButtonFace(QWidget *parent)
	: QToolButton(parent)
{
	// +0x58 字段初始化 + 942B 体 — cited
}
