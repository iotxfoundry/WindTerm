// SearchEngineDialogFace.cpp — SearchEngineDialog(批 436)
#include "SearchEngineDialogFace.h"

// FUN_006d9574(175B,0022:5538)ctor 真身
SearchEngineDialogFace::SearchEngineDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006d9574
{
	setWindowTitle(QStringLiteral("Search Engine")); // tr(0xc9e45d)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_006d906a
	build2(); // @FUN_006d9290
}

// FUN_006d906a 建造 — 结构段(cited)
void SearchEngineDialogFace::build() {}

// FUN_006d9290 建造 — 结构段(cited)
void SearchEngineDialogFace::build2() {}
