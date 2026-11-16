// CheckListFace.cpp —— 从 Widgets/Faces 拆出(按 UI 架构归位)
#include "Widgets/Controls/CheckListFace.h"

// s_CheckList_534e62(344B)ctor
CheckListFace::CheckListFace(QWidget *parent)
	: QWidget(parent)                  // vtable CheckList_vtable
{
	// +0x10(副 vptr 位)/ +0x30 初始化 — cited
}
