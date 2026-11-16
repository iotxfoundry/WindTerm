// QuickDialogFace.cpp — QuickDialog(批 435)
#include "QuickDialogFace.h"

// FUN_006d3630(125B,0022:1844)ctor 真身
QuickDialogFace::QuickDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006d3630
{
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_006cfe98
}

// FUN_006cfe98 建造 — 结构段(cited)
void QuickDialogFace::build() {}
