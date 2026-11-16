// SyncInputDialogFace.cpp — 同步输入对话框(批 424)
#include "SyncInputDialogFace.h"

// FUN_0072abce(239B)ctor 真身
SyncInputDialogFace::SyncInputDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @0072abce
{
	setWindowTitle(QStringLiteral("Sync Input"));          // tr(0xc89b32)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);     // @0072ac5b
	buildMain();                                           // @FUN_00729f1e(3005B)
	buildExtra();                                          // @FUN_00729616(867B)
	// QTimer::singleShot(0, this, 闭包 FUN_0072b69e)@0072acxx — cited
}

// FUN_00729f1e(3005B)主装配 — 结构段(cited)
void SyncInputDialogFace::buildMain() {}

// FUN_00729616(867B)副装配 — 结构段(cited)
void SyncInputDialogFace::buildExtra() {}
