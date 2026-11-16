// SessionTriggerDialogFace.cpp — SessionTriggerDialog(批 437)
#include "SessionTriggerDialogFace.h"

// FUN_006da816(270B,0022:6430)ctor 真身
SessionTriggerDialogFace::SessionTriggerDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006da816
{
	setWindowTitle(QStringLiteral("Session Triggers")); // tr(0xc9e4f1)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_006d9d8a
	build2(); // @FUN_006da092
	// QTimer::singleShot(0, this, 闭包) — cited
}

// FUN_006d9d8a 建造 — 结构段(cited)
void SessionTriggerDialogFace::build() {}

// FUN_006da092 建造 — 结构段(cited)
void SessionTriggerDialogFace::build2() {}
