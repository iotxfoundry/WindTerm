// ActionButtonFace.cpp —— 从 Widgets/Faces 拆出(按 UI 架构归位)
#include "Widgets/Controls/ActionButtonFace.h"

// s_ActionButton_733f60(942B)QToolButton 子类
ActionButtonFace::ActionButtonFace(QWidget *parent)
	: QToolButton(parent)
{
	// +0x58 字段初始化 + 942B 体 — cited
}
