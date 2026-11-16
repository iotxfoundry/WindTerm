// OneKeyDialogFace.cpp — OneKeyDialog(批 432)
#include "OneKeyDialogFace.h"

// FUN_006c55c0(206B,0021:54635)ctor 真身
OneKeyDialogFace::OneKeyDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006c55c0
{
	setWindowTitle(QStringLiteral("OneKey Manager")); // tr(0xc9dcb9)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_006c5300
	// QTimer::singleShot(0, this, 闭包) — cited
}

// FUN_006c5300 建造 — 结构段(cited)
void OneKeyDialogFace::build() {}
