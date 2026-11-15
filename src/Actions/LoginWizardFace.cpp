// LoginWizardFace.cpp — 登录向导装配头部(批 319)
#include "LoginWizardFace.h"

#include <QCheckBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>

// LoginWizard_setupUi(1088B)真身(头部):
//   @00590f20 +0x50 = QDialogButtonBox(0x400400 = Ok|Cancel);
//   @00590f53 Ok 按钮 setText(tr("Continue")(0xc8ace9)@00590f63);
//   @00590fa5 Cancel 按钮 setText(tr("&Cancel")(0xc8a1b5)@00590fb6);
//   余段:QCheckBox/QHBoxLayout/QFrame/QFormLayout/QStackedWidget/QVBoxLayout
//   装配 — cited。
LoginWizardFace::LoginWizardFace(QWidget *parent)
	: QDialog(parent)
{
	setupUi();
}

void LoginWizardFace::setupUi()
{
	m_buttons50 = new QDialogButtonBox(
	    QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this); // @00590f20(0x400400)
	if (QAbstractButton *ok = m_buttons50->button(QDialogButtonBox::Ok))
		ok->setText(tr("Continue")); // 0xc8ace9 @00590f63
	if (QAbstractButton *cancel = m_buttons50->button(QDialogButtonBox::Cancel))
		cancel->setText(tr("&Cancel")); // 0xc8a1b5 @00590fb6
	// 复选/标签/Frame/Form/Stacked/VBox 装配(1088B 余段)— cited。
}
