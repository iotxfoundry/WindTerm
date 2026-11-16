// HighlightTextDialogFace.cpp — HighlightTextDialog(批 430)
#include "HighlightTextDialogFace.h"

// FUN_006b6bfe(175B,0021:45187)ctor 真身
HighlightTextDialogFace::HighlightTextDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006b6bfe
{
	setWindowTitle(QStringLiteral("Highlight Text")); // tr(0xc9fb3c)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_006b6840
	build2(); // @FUN_006b698e
}

// FUN_006b6840 建造 — 结构段(cited)
void HighlightTextDialogFace::build() {}

// FUN_006b698e 建造 — 结构段(cited)
void HighlightTextDialogFace::build2() {}
