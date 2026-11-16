// EnvironmentDialogFace.cpp — EnvironmentDialog(批 429)
#include "EnvironmentDialogFace.h"

#include <QComboBox>
#include <QDialogButtonBox>

// FUN_006b35a6(175B,0021:43065)ctor 真身
EnvironmentDialogFace::EnvironmentDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006b35a6
{
	setWindowTitle(QStringLiteral("Environment Variable")); // tr(0xc9d50b)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);
	build(); // (装配)/
	wire();  // @FUN_006b2cd2(592B)
}

// 装配 — 结构段(cited;语料建造体未逐句转写)
void EnvironmentDialogFace::build() {}

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
