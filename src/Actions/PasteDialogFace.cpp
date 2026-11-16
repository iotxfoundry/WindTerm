// PasteDialogFace.cpp — PasteDialog(批 433)
#include "PasteDialogFace.h"

// FUN_006caf18(221B,0021:58520)ctor 真身
PasteDialogFace::PasteDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006caf18
{
	setWindowTitle(QStringLiteral("Paste")); // tr(0xc9df92)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_006ca710
}

// FUN_006ca710 建造 — 结构段(cited)
void PasteDialogFace::build() {}
