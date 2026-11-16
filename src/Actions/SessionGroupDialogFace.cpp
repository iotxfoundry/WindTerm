// SessionGroupDialogFace.cpp — SessionGroupDialog(批 436)
#include "SessionGroupDialogFace.h"

// FUN_006d9a66(175B,0022:5807)ctor 真身
SessionGroupDialogFace::SessionGroupDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006d9a66
{
	setWindowTitle(QStringLiteral("Session Group")); // tr(0xc9e491)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_006d97d0
	build2(); // @FUN_006d991e
}

// FUN_006d97d0 建造 — 结构段(cited)
void SessionGroupDialogFace::build() {}

// FUN_006d991e 建造 — 结构段(cited)
void SessionGroupDialogFace::build2() {}
