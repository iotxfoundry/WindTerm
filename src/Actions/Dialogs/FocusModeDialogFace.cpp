// FocusModeDialogFace.cpp — FocusModeDialog(批 430)
#include "Actions/Dialogs/FocusModeDialogFace.h"

#include <QCheckBox>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QTabBar>
#include <QVBoxLayout>

// FUN_006b6676(157B,0021:44929)ctor 真身
FocusModeDialogFace::FocusModeDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006b6676
{
	setWindowTitle(QStringLiteral("Focus Mode")); // tr(0xc9d5b2)
	build(); // @FUN_006b639e(656B)
	wire();  // @FUN_006b3a40(488B)
}

// FUN_006b639e(656B)装配真身(结构段)
void FocusModeDialogFace::build()
{
	auto *tabs = new QTabBar(this);                 // 页签
	auto *stack = new QStackedWidget(this);         // 栈
	auto *vbox = new QVBoxLayout;                   // 外框
	auto *hbox = new QHBoxLayout;                   // 行框
	auto *check = new QCheckBox(
		QStringLiteral("&Show this dialog when focus mode starts")); // tr 实读
	vbox->addWidget(tabs);
	vbox->addWidget(stack);
	hbox->addWidget(check);
	vbox->addLayout(hbox);
	setLayout(vbox);
	// QDialogButtonBox 收尾(实参折叠) — cited
}

// FUN_006b3a40(488B)接线真身(结构段):
//   字段 +0x30 / +0x38 / +0x48 三处 connect;
//   闭包 impl FUN_006b2420(按钮盒 PMF 壳)+ FUN_006b6730(`页签→栈同步`,
//   与 TriggerDialog 的 006b6730 同一实现)。
void FocusModeDialogFace::wire()
{
	// 三路 connect(实参折叠)+ 两个闭包 — cited
}
