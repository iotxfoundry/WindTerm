// SettingDialogFace.cpp — SettingDialog(批 437)
#include "Actions/Dialogs/SettingDialogFace.h"

#include <QAbstractButton>
#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QStackedWidget>
#include <QVBoxLayout>

// FUN_006ea66e(318B,0022:14440)ctor 真身
SettingDialogFace::SettingDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006ea66e
{
	setWindowTitle(QStringLiteral("Settings")); // tr(0xc9f084)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build();     // @FUN_006ea37a(683B)
	shortLeg();  // @FUN_006dd310(56B)
}

// FUN_006ea37a(683B)装配真身(结构段)
void SettingDialogFace::build()
{
	auto *vbox = new QVBoxLayout(this);
	auto *hbox = new QHBoxLayout;
	auto *stack = new QStackedWidget(this);
	auto *hint = new QLabel(QStringLiteral("Requires a restart to take affect")); // 实读
	auto *box = new QDialogButtonBox(this);
	if (QAbstractButton *close = box->addButton(QStringLiteral("Close"),
	                                            QDialogButtonBox::AcceptRole))
		Q_UNUSED(close);                            // 按钮文案 "Close"(实读)
	hbox->addWidget(hint);
	vbox->addWidget(stack);
	vbox->addLayout(hbox);
	vbox->addWidget(box);
	setLayout(vbox);
}

// FUN_006dd310(56B)短腿真身(结构段)
void SettingDialogFace::shortLeg()
{
	// 仅动 +0x50(单字段;疑页签/栈切换) — cited
}
