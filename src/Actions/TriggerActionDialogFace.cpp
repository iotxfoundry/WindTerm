// TriggerActionDialogFace.cpp — 触发器动作对话框(批 476)
#include "TriggerActionDialogFace.h"

// FUN_006ff1a0(647B)工厂型 ctor 真身
TriggerActionDialogFace::TriggerActionDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006ff1c9(new 0x48)
{
	// vtable TriggerActionDialog_vtable / 副 0118bef0(C++ 自洽)
	setWindowTitle(QStringLiteral("Action"));             // tr(0xc9fcf1)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);     // @006ff22c
	build();                                              // @FUN_006fe066(393B)
	body();                                               // @FUN_006f9f3c(1369B)
	// connect(finished → 闭包 impl FUN_0070331a)@006ff2xx — cited
}

// FUN_006fe066(393B)装配 — 结构段(cited)
void TriggerActionDialogFace::build() {}

// FUN_006f9f3c(1369B)主体(= TriggerActionWidget 页栈宿主面)— 结构段(cited)
void TriggerActionDialogFace::body() {}
