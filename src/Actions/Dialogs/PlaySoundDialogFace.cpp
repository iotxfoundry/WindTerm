// PlaySoundDialogFace.cpp — PlaySoundDialog(批 434)
#include "Actions/Dialogs/PlaySoundDialogFace.h"

#include <QDialogButtonBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QVBoxLayout>

// FUN_006cc63e(175B,0021:59501)ctor 真身
PlaySoundDialogFace::PlaySoundDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006cc63e
{
	setWindowTitle(QStringLiteral("Play Sound")); // tr(0xc9fb4c)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_006cc276(859B)
	wire();  // @FUN_006cbbbe(627B)
}

// FUN_006cc276(859B)装配真身(结构段)
void PlaySoundDialogFace::build()
{
	auto *vbox = new QVBoxLayout(this);
	auto *form = new QFormLayout;                  // 表单
	auto *group = new QGroupBox(QStringLiteral("Sound")); // tr("Sound")
	auto *pattern = new QLineEdit;                 // 行:&Pattern:
	auto *desc = new QLineEdit;                    // 行:&Description:
	form->addRow(QStringLiteral("&Pattern:"), pattern);      // tr 实读
	form->addRow(QStringLiteral("&Description:"), desc);     // tr 实读
	auto *box = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	group->setLayout(form);
	vbox->addWidget(group);
	vbox->addWidget(box);
	setLayout(vbox);
	// "Match" 文案(0x…)与其余件 — cited
}

// FUN_006cbbbe(627B)接线真身(结构段):+0x30/+0x38/+0x40 三路,闭包两枚。
void PlaySoundDialogFace::wire()
{
	// 三路 connect — cited
}
