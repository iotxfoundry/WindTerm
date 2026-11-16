// PasswordDialogFace.cpp — PasswordDialog(批 433)
#include "Actions/Dialogs/PasswordDialogFace.h"

// FUN_006c9e70(227B,0021:57818)ctor 真身
PasswordDialogFace::PasswordDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006c9e70
{
	setWindowTitle(QStringLiteral("Password")); // tr(0xc9d743)
	wire();  // @FUN_006c955c(627B)
}

// FUN_006c955c(627B)接线真身(结构段)
void PasswordDialogFace::wire()
{
	// +0x40 / +0x48 / +0x50 三路 connect;闭包 FUN_006ca1f0 / FUN_006b2420 — cited
}
