// CloseButtonFace.cpp —— 从 Widgets/Faces 拆出(按 UI 架构归位)
#include "Widgets/Controls/CloseButtonFace.h"

// s_CloseButton_585528(897B)ctor
CloseButtonFace::CloseButtonFace(QWidget *parent)
	: QWidget(parent)
{
	// +0x30 / +0x38 / +0x40 三字段 + 897B 体(图标/接线)— cited
}
