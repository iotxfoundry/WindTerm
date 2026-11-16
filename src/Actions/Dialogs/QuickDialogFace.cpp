// QuickDialogFace.cpp — QuickDialog(批 435)
#include "Actions/Dialogs/QuickDialogFace.h"

// FUN_006d3630(125B,0022:1844)ctor 真身
QuickDialogFace::QuickDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006d3630
{
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	wire();  // @FUN_006cfe98(1230B)
}

// FUN_006cfe98(1230B)接线真身(结构段)
void QuickDialogFace::wire()
{
	// +0x68 / +0x70 / +0x78 / +0x88 / +0x90 / +0x98 六路 connect;
	//   闭包 FUN_006cf7d1 / FUN_006d2576 / FUN_006d42c5 — cited
}
