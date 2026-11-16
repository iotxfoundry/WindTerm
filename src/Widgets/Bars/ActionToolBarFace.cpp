// ActionToolBarFace.cpp —— 从 Widgets/Faces 拆出(按 UI 架构归位)
#include "Widgets/Bars/ActionToolBarFace.h"

// s_ActionButton_56e540(1291B)**QToolBar** 构建腿
ActionToolBarFace::ActionToolBarFace(QWidget *parent)
	: QToolBar(parent)
{
	// 1291B 体:动作装载/按钮插入 — cited
}
