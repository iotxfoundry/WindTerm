// PasswordDialogFace.cpp — PasswordDialog(批 433)
#include "PasswordDialogFace.h"

// FUN_006c9e70(227B,0021:57818)ctor 真身
PasswordDialogFace::PasswordDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006c9e70
{
	setWindowTitle(QStringLiteral("Password")); // tr(0xc9d743)
	build(); // @FUN_006c955c
}

// FUN_006c955c 建造 — 结构段(cited)
void PasswordDialogFace::build() {}
