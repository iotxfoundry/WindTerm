// EnvironmentDialogFace.cpp — EnvironmentDialog(批 429;批 313 装配体已并入)
#include "Widgets/Dialogs/EnvironmentDialogFace.h"

#include <QComboBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QPlainTextEdit>
#include <QProcessEnvironment>

// FUN_006b35a6(175B,0021:43065)ctor 真身
EnvironmentDialogFace::EnvironmentDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006b35a6
{
	setWindowTitle(QStringLiteral("Environment Variable")); // tr(0xc9d50b)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // envDialog_setupUi(0x006b3100)
	wire();  // @FUN_006b2cd2(592B)
}

// envDialog_setupUi(1109B,0021.c:42909 入口 0x006b3100)装配真身(批 313 转写)
void EnvironmentDialogFace::build()
{
	m_edit48 = new QPlainTextEdit(this);      // @006b3124(0x30, +0x48)
	m_combo40 = new QComboBox(this);          // @006b3140(combo_makeSearchCombo 壳, +0x40)
	m_buttons30 = new QDialogButtonBox(this); // @006b315c(0x30, +0x30)
	auto *form = new QFormLayout();           // @006b3179(0x20)
	Q_UNUSED(form);                           // 行装配腿 cited(后续体未转写)
	// FUN_0075d6e8(app, this)@006b31xx — cited(对话框公共腿)
	// setMinimumWidth/Height(实参折叠)— cited
	m_edit48->setWordWrapMode(QTextOption::WrapAnywhere); // 3 @006b32xx
	const QStringList keys = QProcessEnvironment::systemEnvironment().keys(); // @006b3203
	// keys 逐项入组合框(+ 后续过滤/排序腿)— cited(体未转写)
	Q_UNUSED(keys);
}

// FUN_006b2cd2(592B)接线真身
void EnvironmentDialogFace::wire()
{
	if (auto *combo = qobject_cast<QComboBox *>(m_combo40)) { // +0x40
		connect(combo, &QComboBox::editTextChanged, this, [](const QString &) {
			// 闭包 impl FUN_006b2c36 — cited
		});
		connect(combo, &QComboBox::currentTextChanged, this, [](const QString &) {
			// 闭包 FUN_006b36e0 → 槽 FUN_006b2f2c — cited
		});
	}
	if (auto *box = qobject_cast<QDialogButtonBox *>(m_buttons30)) { // +0x30
		connect(box, &QDialogButtonBox::accepted, this, &QDialog::accept);
		connect(box, &QDialogButtonBox::rejected, this, &QDialog::reject);
	}
}
