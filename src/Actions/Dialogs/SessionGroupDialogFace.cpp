// SessionGroupDialogFace.cpp — SessionGroupDialog(批 436)
#include "Actions/Dialogs/SessionGroupDialogFace.h"

#include <QDialogButtonBox>
#include <QFormLayout>

// FUN_006d9a66(175B,0022:5807)ctor 真身
SessionGroupDialogFace::SessionGroupDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006d9a66
{
	setWindowTitle(QStringLiteral("Session Group")); // tr(0xc9e491)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_006d991e(293B)
	wire();  // @FUN_006d97d0(334B)
}

// FUN_006d991e(293B)装配真身(结构段;无本地文案)
void SessionGroupDialogFace::build()
{
	auto *form = new QFormLayout;                      // 表单(行标签来自别处)
	auto *box = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	form->addRow(box);
	// 并入布局(实参折叠) — cited
}

// FUN_006d97d0(334B)接线真身(结构段)
void SessionGroupDialogFace::wire()
{
	// +0x30 一路 connect;闭包 FUN_006b2420 — cited
}
