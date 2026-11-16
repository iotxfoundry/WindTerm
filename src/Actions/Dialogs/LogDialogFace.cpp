// LogDialogFace.cpp — LogDialog(批 431)
#include "Actions/Dialogs/LogDialogFace.h"

// FUN_006b874c(206B,0021:46211)ctor 真身
LogDialogFace::LogDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006b874c
{
	setWindowTitle(QStringLiteral("Log Dialog")); // tr(0xc9d724)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	wire();  // @FUN_006b73a2(700B)
}

// FUN_006b73a2(700B)接线真身(结构段)
void LogDialogFace::wire()
{
	// +0x40 / +0x48 / +0x70 三路 connect;闭包 FUN_006b6d12 / FUN_006b90f0 /
	//   FUN_006b2420 — cited
}
