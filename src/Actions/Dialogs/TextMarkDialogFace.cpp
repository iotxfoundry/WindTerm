// TextMarkDialogFace.cpp — 语料 TextMarkDialog(批 438;批 191 SettingsFace
// 误收的 ctor/布局体已归位 —— FUN_006f1036 内直接调 search_page_build_layout)
#include "Actions/Dialogs/TextMarkDialogFace.h"

#include <QComboBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QIcon>
#include <QLineEdit>
#include <QPushButton>
#include <QTimer>
#include <QVBoxLayout>

// === S1 FUN_006f1036(175B,0022:18703;汇编 006f1036-006f10ce)===
TextMarkDialogFace::TextMarkDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags())   // QDialog(param_2,0)@006f1043
{
	setWindowTitle(tr("Text Mark"));           // tr 0xc9faaa @006f106d-89
	setAttribute(Qt::WA_DeleteOnClose, true);  // (0x37,1)@006f10b1
	searchPageBuildLayout();                   // @006f10b9
	// options_connectSignals @006f10c1 → cited:006edc90(0022:16933)
}

// === S3 FUN_006f09ba(1498B,0022:18501;汇编 006f09ba-006f0ea4)===
void TextMarkDialogFace::searchPageBuildLayout()
{
	QVBoxLayout *vbox = new QVBoxLayout;                       // @006f09db
	QFormLayout *form1 = new QFormLayout;                      // @006f09f4
	QFormLayout *form2 = new QFormLayout;                      // @006f0a0b
	QGroupBox *gMatch = new QGroupBox(tr("Match"));            // 0xc9dfcb@006f0a3b
	QGroupBox *gStyle = new QGroupBox(tr("Style"));            // 0xd0c6c2@006f0a85

	// +0x38 TriggerActionEditPanel(0xe000 字面@006f0ad3)→ 类本体 cited。
	m_panel = new QWidget;
	m_panelField = m_panel;                                    // panel+0x40→+0x40@006f0ae4
	m_pattern = new QLineEdit;                                 // @006f0afe
	m_textColor = new QWidget;   // ColorButton cited@006f0b19
	m_bgColor = new QWidget;     // ColorButton cited@006f0b34
	m_lineColor = new QWidget;   // ColorButton cited@006f0b4f
	// +0x68 searchCombo(FUN_006f088a 271B;FUN_0094e9cc 14 项枚举,
	// data=int(byte@item+8)@006f0906;逐项 0xca0371..0xce8d85):
	m_searchCombo = new QComboBox;
	static const struct { const char *name; int id; } kItems[] = {
		{"None", 0},           // 0xca0371
		{"Solid", 2},          // 0xce8d32
		{"Double", 3},         // 0xce8d38
		{"Thick", 4},          // 0xce8d3f
		{"Strike", 10},        // 0xce8d45
		{"Wavy", 11},          // 0xce8d4c
		{"Dot", 6},            // 0xce8d51
		{"Dash", 7},           // 0xce8d55
		{"Dash dot", 8},       // 0xce8d5a
		{"Dash dot dot", 9},   // 0xce8d63
		{"Box", 15},           // 0xceeac4
		{"Round box", 16},     // 0xce8d70
		{"Dashed box", 17},    // 0xce8d7a
		{"Dotted box", 18},    // 0xce8d85
	};
	for (const auto &it : kItems)
		m_searchCombo->addItem(QIcon(), QLatin1String(it.name), it.id); // @006f0930-45
	// +0x70 preview(FUN_006ee0b8 134B;0055a260 p2=1 类本体 cited;
	// setText "Preview"@006ee0df-0fb):
	m_preview = new QLineEdit;
	m_preview->setText(QStringLiteral("Preview"));
	m_buttons = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel);      // 0x400400@006f0b7f
	m_lineColor->setEnabled(false);                            // @006f0b90-96
	// Ok enable = preview 文本非空(语料 document()->toPlainText() 空
	// 测试@006f0bb0-0x6f0bd3;preview 域 QLineEdit → text() 语义)。
	m_buttons->button(QDialogButtonBox::Ok)->setEnabled(
		!m_preview->text().isEmpty());

	// form1 行(@006f0bf6-0c6b):&Pattern:→panel(语料 R15=+0x38@006f0bf6)、
	// &Description:→+0x48@006f0c42:
	form1->addRow(tr("&Pattern:"), m_panel);
	form1->addRow(tr("&Description:"), m_pattern);
	// form2 行(@006f0c8e-0d93):&Text Color:→+0x50、&Background Color:
	// →+0x58、&Line Style:→+0x68、&Line Color:→+0x60:
	form2->addRow(tr("&Text Color:"), m_textColor);
	form2->addRow(tr("&Background Color:"), m_bgColor);
	form2->addRow(tr("&Line Style:"), m_searchCombo);
	form2->addRow(tr("&Line Color:"), m_lineColor);
	form2->addRow(m_preview);                                  // addRow(QWidget)@006f0dbd
	gMatch->setLayout(form1);                                  // @006f0dcf(RSP+0x8)
	gStyle->setLayout(form2);                                  // @006f0dcc(RSP+0x10)
	vbox->addWidget(gMatch);                                   // @006f0dee
	vbox->addWidget(gStyle);                                   // @006f0dfd
	vbox->addWidget(m_buttons);                                // +0x30@006f0e0a
	setLayout(vbox);                                           // @006f0e18
	QWidget::setTabOrder(m_panelField, m_pattern);             // @006f0e1d(+0x40,+0x48)
	QWidget::setTabOrder(m_pattern, m_textColor);              // @006f0e32
	QWidget::setTabOrder(m_textColor, m_bgColor);              // @006f0e3f
	QWidget::setTabOrder(m_bgColor, m_searchCombo);            // (+0x58,+0x68)@006f0e44
	QWidget::setTabOrder(m_searchCombo, m_lineColor);          // (+0x68,+0x60)@006f0e4c
	// singleShot(0,this,FUN_006edad0):闭包体 setFocus(+0x40,3)@006edad0-0x6f0e87:
	QTimer::singleShot(0, this, [this]() {
		if (m_panelField)
			m_panelField->setFocus(Qt::BacktabFocusReason);    // 3@006edad8
	});
	// FUN_0075c132(app,0.0,0.0,this)@006f0e8c-0x6f0e9f:实参 (0,0) →
	// width/height 分支均 JBE 跳过(@0075c160/@0075c189),仅
	// setSizeGripEnabled(1)@0075c1a3:
	setSizeGripEnabled(true);
}
