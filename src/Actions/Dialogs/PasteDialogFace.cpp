// PasteDialogFace.cpp — PasteDialog(批 433)
#include "Actions/Dialogs/PasteDialogFace.h"

// FUN_006caf18(221B,0021:58520)ctor 真身
PasteDialogFace::PasteDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006caf18
{
	setWindowTitle(QStringLiteral("Paste")); // tr(0xc9df92)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	wire();  // @FUN_006ca710(570B)
}

// FUN_006ca710(570B)接线真身(结构段)
void PasteDialogFace::wire()
{
	// +0x50 / +0x60 / +0x70 三路 connect;闭包 FUN_006ca260 / FUN_006ca2de /
	//   FUN_006cb230 / FUN_006b2420 — cited
}
