// TableItemDialogFace.cpp — TableItemDialog(批 432)
#include "TableItemDialogFace.h"

// FUN_006c7080(254B,0021:55897)ctor 真身
TableItemDialogFace::TableItemDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006c7080
{
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_006c7xxx
}

// FUN_006c7xxx 建造 — 结构段(cited)
void TableItemDialogFace::build() {}
