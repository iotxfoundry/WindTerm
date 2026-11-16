// ListFaces.cpp — CheckList / ExplorerList(批 487)
#include "ListFaces.h"

// s_CompleterButton_58dad4(819B)ctor
CompleterButtonFace::CompleterButtonFace(QWidget *parent)
	: QWidget(parent)
{
	// +0x40 字段 + 819B 体(补全菜单/接线)— cited
}

// s_CloseButton_585528(897B)ctor
CloseButtonFace::CloseButtonFace(QWidget *parent)
	: QWidget(parent)
{
	// +0x30 / +0x38 / +0x40 三字段 + 897B 体(图标/接线)— cited
}

// s_CheckList_534e62(344B)ctor
CheckListFace::CheckListFace(QWidget *parent)
	: QWidget(parent)                  // vtable CheckList_vtable
{
	// +0x10(副 vptr 位)/ +0x30 初始化 — cited
}

// s_ExplorerList_55456a(291B)ctor
ExplorerListFace::ExplorerListFace(QWidget *parent)
	: QWidget(parent)                  // vtable ExplorerList_vtable
{
	// +0x10 / +0x30 / +0x60 初始化 — cited
}
