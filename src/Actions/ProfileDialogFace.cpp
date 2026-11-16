// ProfileDialogFace.cpp — ProfileDialog(批 434)
#include "ProfileDialogFace.h"

// FUN_006cf13c(240B,0021:61296)ctor 真身
ProfileDialogFace::ProfileDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006cf13c
{
	setWindowTitle(QStringLiteral("Choose Profiles Directory")); // tr(0xc9e135)
	build(); // @FUN_006ce668
	build2(); // @FUN_006cf012
}

// FUN_006ce668 建造 — 结构段(cited)
void ProfileDialogFace::build() {}

// FUN_006cf012 建造 — 结构段(cited)
void ProfileDialogFace::build2() {}
