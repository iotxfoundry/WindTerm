// MasterPasswordDialogFace.cpp — MasterPasswordDialog(批 431)
#include "MasterPasswordDialogFace.h"

// FUN_006b9e92(157B,0021:47139)ctor 真身
MasterPasswordDialogFace::MasterPasswordDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006b9e92
{
	setWindowTitle(QStringLiteral("Password")); // tr(0xc9d743)
	build(); // @FUN_006b9346
}

// FUN_006b9346 建造 — 结构段(cited)
void MasterPasswordDialogFace::build() {}
