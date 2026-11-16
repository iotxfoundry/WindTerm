// InsertFileDialogFace.cpp — 插入文件对话框(批 425)
#include "Actions/Dialogs/InsertFileDialogFace.h"

#include <QDialogButtonBox>
#include <QLabel>

// FUN_0072facc(74B)ctor 真身
InsertFileDialogFace::InsertFileDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @0072facc
{
	buildA();                             // @FUN_0072f7b2(716B)
	wire();                               // @FUN_0072f49e(229B)
}

// FUN_0072f7b2(716B)装配 A — 结构段(cited)
void InsertFileDialogFace::buildA() {}

// FUN_0072f49e(229B)接线真身
void InsertFileDialogFace::wire()
{
	// +0x50 信号 FUN_008fa97a → 闭包 impl FUN_0072f350(smeta 0119d160) — cited
	if (auto *box = qobject_cast<QDialogButtonBox *>(m_buttons40)) { // +0x40
		connect(box, &QDialogButtonBox::accepted, this, &QDialog::accept);
		connect(box, &QDialogButtonBox::rejected, this, &QDialog::reject);
	}
}

// FUN_0072f584(517B)标签/标题真身
void InsertFileDialogFace::applyLabels(const QString &a, const QString &b)
{
	setWindowTitle(QStringLiteral("Insert File"));    // tr(0xca1ab1)
	if (auto *l = qobject_cast<QLabel *>(m_label48))
		l->setText(QStringLiteral("&File:"));          // tr(0xc9e39f)
	if (auto *w = qobject_cast<QLabel *>(m_f60))
		w->setText(a);                                 // @+0x60 setText
	if (auto *w = qobject_cast<QLabel *>(m_f68))
		w->setText(b);                                 // @+0x68 setText
}
