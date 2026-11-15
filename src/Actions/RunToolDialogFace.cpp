// RunToolDialogFace.cpp — 运行工具对话框装配转写(批 314)
#include "RunToolDialogFace.h"

#include <QCheckBox>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QToolButton>
#include <QVBoxLayout>
#include <QVariant>

// RunToolDialog_setupUi(1098B,0022.c:35199 区)装配真身
void RunToolDialogFace::setupUi()
{
	m_check30 = new QCheckBox(this);          // @00707afd(0x30)
	m_buttons38 = new QDialogButtonBox(this); // @00707b18(0x30)
	m_label48 = new QLabel(this);             // @00707b35(0x30)
	m_combo40 = new QComboBox(this);          // @00707b50(combo_makeSearchCombo 壳)
	m_tool50 = new QToolButton(this);         // @00707b6b(0x30)
	m_group58 = new QGroupBox(this);          // @00707b86(0x30)
	m_group60 = new QGroupBox(this);          // @00707ba1(0x30)

	// 两轮组装配 @00707bc7-00707cx:
	//   pass1 → +0x58 组,项表 = +0x68(+0x68 表空 → 仅 addStretch);
	//   pass2 → +0x60 组,项表 = +0x70。
	struct Pass {
		QGroupBox *box;
		const QStringList *items;
	};
	const Pass passes[2] = {{m_group58, &m_items68}, {m_group60, &m_items70}};
	for (const Pass &pass : passes) {
		auto *box = new QVBoxLayout(); // @00707bc7(0x20)
		for (const QString &item : *pass.items) {
			auto *radio = new QRadioButton(); // @00707c03(0x30)
			radio->setProperty("data", QVariant(item)); // 0xc8977d @00707c3e
			box->addWidget(radio);            // @00707cxx
		}
		box->addStretch();                    // @00707bef
		pass.box->setLayout(box);             // @00707cxx
	}
	// FUN_00707320(this, this)@00707cxx — cited(文案/行装配体)
	m_check30->setChecked(false);             // 实参折叠 — cited
	m_buttons38->addButton(QDialogButtonBox::Ok);    // 0x400
	m_buttons38->addButton(QDialogButtonBox::Apply); // 0x400000
	// FUN_0075263e(0x406e000000000000, app, this) 换算宽度 — cited
	// FUN_0053d596(m_combo40, 1) — cited(组合框面)
	if (QLineEdit *le = m_combo40->lineEdit())
		le->setPlaceholderText(tr("Program [Arguments]...")); // 0xca0359 @00707d2a
}

RunToolDialogFace::RunToolDialogFace(QWidget *parent)
	: QDialog(parent)
{
	setupUi(); // ctor 00707f8e(批 315 承接)
}
