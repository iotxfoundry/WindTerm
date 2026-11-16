// EnvironmentDialogFace.cpp — EnvironmentDialog(批 429)
#include "EnvironmentDialogFace.h"

// FUN_006b35a6(175B,0021:43065)ctor 真身
EnvironmentDialogFace::EnvironmentDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006b35a6
{
	setWindowTitle(QStringLiteral("Environment Variable")); // tr(0xc9d50b)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_b2cd2
}

// FUN_b2cd2 建造 — 结构段(cited)
void EnvironmentDialogFace::build() {}
