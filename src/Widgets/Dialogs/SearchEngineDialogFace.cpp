// SearchEngineDialogFace.cpp — SearchEngineDialog(批 436)
#include "Widgets/Dialogs/SearchEngineDialogFace.h"

#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLineEdit>

// FUN_006d9574(175B,0022:5538)ctor 真身
SearchEngineDialogFace::SearchEngineDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006d9574
{
	setWindowTitle(QStringLiteral("Search Engine")); // tr(0xc9e45d)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // @FUN_006d9290(670B)
	wire();  // @FUN_006d906a(550B)
}

// FUN_006d9290(670B)装配真身
void SearchEngineDialogFace::build()
{
	auto *form = new QFormLayout;                     // 表单
	auto *name = new QLineEdit;                        // 引擎名
	auto *url = new QLineEdit;                         // URL 模板
	auto *box = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	form->addRow(QStringLiteral("&Search engine:"), name);                     // tr 实读
	form->addRow(QStringLiteral("&URL with {q} in place of query:"), url);     // tr 实读
	Q_UNUSED(box);
	// 表单一并入布局(实参折叠) — cited
}

// FUN_006d906a(550B)接线真身(结构段)
void SearchEngineDialogFace::wire()
{
	// +0x30 / +0x40 / +0x48 三路 connect;闭包 FUN_006b2420 / FUN_006d8ff5 /
	//   FUN_006d902f — cited
}
