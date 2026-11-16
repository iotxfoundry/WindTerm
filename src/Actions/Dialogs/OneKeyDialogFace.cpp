// OneKeyDialogFace.cpp — OneKeyDialog(批 432)
#include "Actions/Dialogs/OneKeyDialogFace.h"

#include <QAbstractButton>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QStackedWidget>
#include <QTabBar>
#include <QVBoxLayout>

// FUN_006c55c0(206B,0021:54635)ctor 真身
OneKeyDialogFace::OneKeyDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006c55c0
{
	setWindowTitle(QStringLiteral("OneKey Manager")); // tr(0xc9dcb9)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_006c5300
	// QTimer::singleShot(0, this, 闭包) — cited
}

// FUN_006c5300(639B)装配真身(结构段)
void OneKeyDialogFace::build()
{
	auto *tabs = new QTabBar(this);
	auto *stack = new QStackedWidget(this);
	auto *grid = new QGridLayout;                 // 页内网格
	auto *vbox = new QVBoxLayout(this);
	auto *box = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	if (QAbstractButton *ok = box->button(QDialogButtonBox::Ok))
		ok->setText(QStringLiteral("Ok"));        // tr("Ok")
	if (QAbstractButton *cancel = box->button(QDialogButtonBox::Cancel))
		cancel->setText(QStringLiteral("Cancel"));// tr("Cancel")
	vbox->addWidget(tabs);
	vbox->addWidget(stack);
	vbox->addWidget(box);
	setLayout(vbox);
	Q_UNUSED(grid);
	// singleShot 收尾(ctor 侧)见 FUN_006c55c0 — cited
}
