// SessionTriggerDialogFace.cpp — SessionTriggerDialog(批 437)
#include "SessionTriggerDialogFace.h"

#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

// FUN_006da816(270B,0022:6430)ctor 真身
SessionTriggerDialogFace::SessionTriggerDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006da816
{
	setWindowTitle(QStringLiteral("Session Triggers")); // tr(0xc9e4f1)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_006da092(644B)
	wire();  // @FUN_006d9d8a(776B)
	// QTimer::singleShot(0, this, 闭包) — cited
}

// FUN_006da092(644B)装配真身(结构段)
void SessionTriggerDialogFace::build()
{
	auto *vbox = new QVBoxLayout(this);
	auto *hbox = new QHBoxLayout;
	auto *label = new QLabel;                       // 说明行
	auto *button = new QPushButton;                 // 动作钮
	auto *box = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	hbox->addWidget(label);
	hbox->addWidget(button);
	vbox->addLayout(hbox);
	vbox->addWidget(box);
	setLayout(vbox);
}

// FUN_006d9d8a(776B)接线真身(结构段)
void SessionTriggerDialogFace::wire()
{
	// +0x30 / +0x38 / +0x48 三路 connect;闭包 FUN_006b2420 / FUN_006db5b0 — cited
}
