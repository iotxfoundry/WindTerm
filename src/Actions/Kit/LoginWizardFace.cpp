// LoginWizardFace.cpp — 登录向导装配头部(批 319)
#include "Actions/Kit/LoginWizardFace.h"

#include <QCheckBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QAbstractButton>

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
	m_check60 = new QCheckBox(tr("&Auto login next time")); // 0xc8acf2 @00591007
	m_check68 = new QCheckBox(tr("&Remember this step"));   // 0xc8ad08 @0059105c
	m_label70 = new QLabel();                               // @00591096
	m_label78 = new QLabel(tr("Login"));                    // 0xd0d9ac @005910d0
	m_label78->setAlignment(Qt::AlignCenter);               // 0x84 @005910f6
	m_check60->setChecked(false); // 实参折叠 — cited
	// FUN_00590ee0(this)@005910xx — cited
	m_hbox = new QHBoxLayout();            // @00591127
	m_hbox->addWidget(m_check60);          // +0x60
	m_hbox->addWidget(m_check68);          // +0x68
	m_hbox->addWidget(m_buttons50);        // +0x50
	m_frame = new QFrame();                // @00591170
	m_frame->setFrameShape(QFrame::HLine); // 4
	// setFrameShadow(实参折叠)— cited
	m_form = new QFormLayout();                       // @005911a1(0x20)
	m_form->setContentsMargins(-1, 0, -1, 0);         // 语料 (-1,0,-1)
	// addRow ×3(asm 0x5911bc-0x5911d9 实参):
	//   ① addRow(+0x70 QLabel)(rsi = 0x70(%rbx))
	//   ② addRow(<widget r14>)(组件面,cited)
	//   ③ addRow(<layout r13>)(布局面,cited)
	m_form->addRow(m_label70); // ①@0x5911c3
	auto *host = new QWidget();                       // @005911f2(0x30)
	host->setLayout(m_form);
	m_stack = new QStackedWidget();                   // @00591214(0x30)
	m_stack->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred); // 0x770000
	m_vbox = new QVBoxLayout();                       // @00591236(0x20)
	m_vbox->addWidget(m_stack);                       // @0059125x
	m_vbox->addWidget(host);
	auto *panel = new QFrame();                       // @00591293
	panel->setFrameShape(QFrame::StyledPanel);        // 6
	panel->setLayout(m_vbox);
}
