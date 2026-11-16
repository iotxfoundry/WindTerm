// WindowOpacityDialogFace.cpp — WindowOpacityDialog(批 438)
#include "WindowOpacityDialogFace.h"

#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QSlider>

// FUN_00704dd2(175B,0022:30666)ctor 真身
WindowOpacityDialogFace::WindowOpacityDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @00704dd2
{
	setWindowTitle(QStringLiteral("Window Opacity")); // tr(0xca0270)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_0070496e
}

// FUN_0070496e(452B)接线 + 滑杆面真身(结构段)
void WindowOpacityDialogFace::build()
{
	auto *slider = new QSlider(Qt::Horizontal, this);   // QSlider ×4(语料)
	auto *label = new QLabel(this);                     // QLabel ×4
	auto *hbox = new QHBoxLayout;                       // QHBoxLayout ×3
	auto *box = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	hbox->addWidget(slider);
	hbox->addWidget(label);
	setLayout(hbox);
	Q_UNUSED(box);
	// 按钮 accepted(0x1b9)/rejected(0x1c1)两路 connect — cited
}
