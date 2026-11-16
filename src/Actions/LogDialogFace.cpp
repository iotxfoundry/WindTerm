// LogDialogFace.cpp — LogDialog(批 431)
#include "LogDialogFace.h"

// FUN_006b874c(206B,0021:46211)ctor 真身
LogDialogFace::LogDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006b874c
{
	setWindowTitle(QStringLiteral("Log Dialog")); // tr(0xc9d724)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_006b73a2
}

// FUN_006b73a2 建造 — 结构段(cited)
void LogDialogFace::build() {}
