// NameDialogFace.cpp — 通用 Create 名字对话框(批 347)
#include "NameDialogFace.h"

#include <QFormLayout>
#include <QLayoutItem>

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
	// FUN_006bd50c(670B)+FUN_006bd34a(449B) — cited(输入行/按钮行装配未逐句转写)
}

// FUN_006bd250(242B,0021.c:50039)真身
void nameDialogAddFormRow(QWidget *dlg, QWidget *field)
{
	if (dlg == nullptr || field == nullptr)
		return;
	auto *form = dlg->findChild<QFormLayout *>(); // @006bd282(空名递归)
	if (form == nullptr)
		return;
	form->addRow(field);                          // @006bd2a8

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
