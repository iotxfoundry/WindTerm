// ListFaces.cpp — CheckList / ExplorerList(批 487)
#include "ListFaces.h"

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
