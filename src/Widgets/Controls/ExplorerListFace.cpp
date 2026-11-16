// ExplorerListFace.cpp —— 从 Widgets/Faces/ListFaces 拆出(按 UI 架构归位)
#include "Widgets/Controls/ExplorerListFace.h"

// s_ExplorerList_55456a(291B)ctor
ExplorerListFace::ExplorerListFace(QWidget *parent)
	: QWidget(parent)                  // vtable ExplorerList_vtable
{
	// +0x10 / +0x30 / +0x60 初始化 — cited
}
