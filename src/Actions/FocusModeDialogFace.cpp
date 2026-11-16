// FocusModeDialogFace.cpp — FocusModeDialog(批 430)
#include "FocusModeDialogFace.h"

// FUN_006b6676(157B,0021:44929)ctor 真身
FocusModeDialogFace::FocusModeDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006b6676
{
	setWindowTitle(QStringLiteral("Focus Mode")); // tr(0xc9d5b2)
	build(); // @FUN_006b3a40
	build2(); // @FUN_006b639e
}

// FUN_006b3a40 建造 — 结构段(cited)
void FocusModeDialogFace::build() {}

// FUN_006b639e 建造 — 结构段(cited)
void FocusModeDialogFace::build2() {}
