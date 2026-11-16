// WindowOpacityDialogFace.cpp — WindowOpacityDialog(批 438)
#include "WindowOpacityDialogFace.h"

// FUN_00704dd2(175B,0022:30666)ctor 真身
WindowOpacityDialogFace::WindowOpacityDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @00704dd2
{
	setWindowTitle(QStringLiteral("Window Opacity")); // tr(0xca0270)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_0070496e
}

// FUN_0070496e 建造 — 结构段(cited)
void WindowOpacityDialogFace::build() {}
