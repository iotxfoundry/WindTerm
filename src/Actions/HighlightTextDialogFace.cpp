// HighlightTextDialogFace.cpp — HighlightTextDialog(批 430)
#include "HighlightTextDialogFace.h"

#include <QAbstractButton>
#include <QDialogButtonBox>
#include <QLabel>
#include <QVBoxLayout>

// FUN_006b6bfe(175B,0021:45187)ctor 真身
HighlightTextDialogFace::HighlightTextDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006b6bfe
{
	setWindowTitle(QStringLiteral("Highlight Text")); // tr(0xc9fb3c)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_006b698e(567B)
	wire();  // @FUN_006b6840(334B)
}

// FUN_006b698e(567B)装配真身(结构段)
void HighlightTextDialogFace::build()
{
	auto *vbox = new QVBoxLayout(this);
	auto *label = new QLabel(QStringLiteral("&Text Marks:"));   // tr 实读
	auto *box = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	if (QAbstractButton *ok = box->button(QDialogButtonBox::Ok))
		ok->setText(QStringLiteral("Ok"));                     // tr("Ok")
	if (QAbstractButton *cancel = box->button(QDialogButtonBox::Cancel))
		cancel->setText(QStringLiteral("Cancel"));             // tr("Cancel")
	vbox->addWidget(label);
	vbox->addWidget(box);
	setLayout(vbox);
}

// FUN_006b6840(334B)接线真身(结构段):字段 +0x38 一路 connect,闭包 FUN_006b2420。
void HighlightTextDialogFace::wire()
{
	// 一路 connect(实参折叠)— cited
}
