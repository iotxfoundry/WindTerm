// NameDialogFace.cpp — 通用 Create 名字对话框(批 347)
#include "Actions/Dialogs/NameDialogFace.h"

#include "SearchEditFace.h"

#include <QAbstractButton>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLabel>
#include <QLayoutItem>
#include <QVBoxLayout>

// FUN_006bd7f6(319B,0021.c:50242)ctor 真身:
//   @006bd80d QDialog(parent, 0);
//   @006bd812 vptr 0x11a13b8 / 副 0x11a1590;
//   @006bd82a +0x30 = byte 0;  @006bd832 +0x38 = 名字 QString(引用计数拷贝);
//   @006bd86x setWindowTitle(tr("Create")(0xc9da96) + " "(0xd992f9) + 名字);
//   @006bd8xx setAttribute(0x37 /*WA_DeleteOnClose*/, true);
//   FUN_006bd50c(this)(670B)/FUN_006bd34a(this)(449B) — 装配腿 cited。
NameDialogFace::NameDialogFace(const QString &name, QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006bd80d
	, m_name38(name)                      // +0x38
{
	setWindowTitle(QStringLiteral("Create") + QStringLiteral(" ") + name); // tr(0xc9da96)+" "+name
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);                     // @006bd8df
	build();                                                               // @006bd8xx(FUN_006bd50c)
	wire();                                                                // @006bd8xx(FUN_006bd34a)
}

// FUN_006bd50c(670B,0021.c:50140)装配真身
void NameDialogFace::build()
{
	auto *vbox = new QVBoxLayout(this);                       // @006bd52d(0x20)
	auto *form = new QFormLayout;                             // @006bd544(0x20,父 0)

	const QString hint = QStringLiteral("Enter a name for the new %1.") // tr(0xc9da79)
		.arg(m_name38);                                       // @006bd581(.arg(+0x38))
	m_label48 = new QLabel(hint);                             // @006bd58b(0x30)

	m_edit50 = new SearchEditFace(this);                      // @006bd5f3(0x70,searchEdit_init)
	m_buttons40 = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel); // @006bd6xx(0x400400)
	if (QAbstractButton *ok = m_buttons40->button(QDialogButtonBox::Ok))
		ok->setText(QStringLiteral("Create"));                // tr(0xc9da96)

	vbox->addWidget(m_label48);                               // 装配序(实参折叠)
	vbox->addLayout(form);
	vbox->addWidget(m_buttons40);
	form->addRow(QStringLiteral("&Name:"), m_edit50);         // tr(0xc9da9d)
	setLayout(vbox);                                          // @006bd7xx
	// FUN_0075c132(0.35, 0, qApp, this)@006bd7xx — cited(窗口尺寸比例腿)
}

// FUN_006bd34a(449B)接线真身(结构段):
//   connect(?, ?, 闭包 impl FUN_006bdced);(**回车/文本变化腿,cited**)
//   connect(+0x40 QDialogButtonBox::accepted → this accept,闭包 FUN_006b2420);
//   connect(+0x40 QDialogButtonBox::rejected → this reject,闭包 FUN_006b2420)。
void NameDialogFace::onTextChanged(const QString &text)
{
	if (m_f30 != 0)                     // +0x30 = 允许空名 → 不做校验
		return;
	setAcceptEnabled(!text.isEmpty());  // FUN_006bdbc6(this, len != 0)
}

// FUN_006bdbc6(29B)Ok 按钮启停真身
void NameDialogFace::setAcceptEnabled(bool on)
{
	if (m_buttons40 == nullptr)
		return;
	if (QAbstractButton *ok = m_buttons40->button(QDialogButtonBox::Ok)) // 0x400
		ok->setEnabled(on);                                              // QWidget::setEnabled
}

void NameDialogFace::wire()
{
	// connect(+0x50 searchEdit 的文本变化 → 闭包 impl FUN_006bdced)@006bd34a
	//   — 编辑器件(searchEdit_init)未建模 ⇒ cited(不发明信号面);
	//   行为面已由 onTextChanged 承载。
	connect(m_buttons40, &QDialogButtonBox::accepted, this, &QDialog::accept);
	connect(m_buttons40, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

// FUN_006bd250(242B,0021.c:50039)真身(三实参:dlg / 标签 / 字段)
void nameDialogAddFormRow(QWidget *dlg, const QString &label, QWidget *field)
{
	if (dlg == nullptr || field == nullptr)
		return;
	auto *form = dlg->findChild<QFormLayout *>(); // @006bd282(空名递归)
	if (form == nullptr)
		return;
	form->addRow(label, field);                   // @006bd2a8

	QLayoutItem *it = form->itemAt(0, QFormLayout::FieldRole); // @006bd2xx(role 1)
	if (it == nullptr)
		return;
	QWidget *prev = it->widget();
	const int rows = form->rowCount();            // @006bd2xx
	for (int i = 1; i < rows; ++i) {              // @006bd2xx(1 < rowCount 才进循环)
		QLayoutItem *ci = form->itemAt(i, QFormLayout::FieldRole);
		if (ci == nullptr)
			continue;
		QWidget *cur = ci->widget();
		QWidget::setTabOrder(prev, cur);          // @006bd2xx
		prev = cur;
	}
}
