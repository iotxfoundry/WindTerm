// MasterPasswordDialogFace.cpp — MasterPasswordDialog(批 431)
#include "Actions/Dialogs/MasterPasswordDialogFace.h"

// FUN_006b9e92(157B,0021:47139)ctor 真身
MasterPasswordDialogFace::MasterPasswordDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006b9e92
{
	setWindowTitle(QStringLiteral("Password")); // tr(0xc9d743)
	wire();  // @FUN_006b9346(788B)
}

// FUN_006b9346(788B)接线真身(结构段)
void MasterPasswordDialogFace::wire()
{
	// +0x48 / +0x50 / +0x58 / +0x60 四路 connect;闭包 FUN_00561a00 /
	//   FUN_006b9f60 / FUN_006b2420 — cited
}
