#pragma once

#include <QDialog>
#include <QList>

class QCheckBox;
class QComboBox;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QToolButton;

// RunToolDialogFace — 语料"运行外部工具"对话框装配面(批 314)。
// RunToolDialog_setupUi(1098B,0022.c:35199 区)字段/装配序:
//   +0x30 QCheckBox(0x30)@00707afd → +0x38 QDialogButtonBox(0x30)@00707b18 →
//   +0x48 QLabel(0x30)@00707b35 → +0x40 搜索组合框(0x48)@00707b50 →
//   +0x50 QToolButton(0x30)@00707b6b → +0x58/+0x60 QGroupBox(0x30×2)
//   @00707b86/00707ba1;
//   两轮 VBox 装配(pass1→+0x58 用 +0x68 表,pass2→+0x60 用 +0x70 表):
//     逐项 new QRadioButton(0x30)+setProperty("data" 0xc8977d, 项值)
//     → addWidget → addStretch → groupBox->setLayout;
//   FUN_00707320(this,this)(文案面,cited);
//   +0x30 setChecked(实参折叠);+0x38 addButton(0x400)/addButton(0x400000);
//   +0x40 setMinimumWidth(FUN_0075263e 0x406e000000000000 常量)+
//     FUN_0053d596(combo,1)+ lineEdit()->setPlaceholderText(
//       tr("Program [Arguments]...")(0xca0359));
class RunToolDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit RunToolDialogFace(QWidget *parent = nullptr); // ctor 00707f8e
	void setupUi();                                        // 00707ada

	// 语料 ctor(00707f8e 1116B)两张表(+0x68 6 项 / +0x70 8 项,
	//   每项 = {值 BA,标签 BA},FUN_00708c5e(count) 装配):
	//   +0x68:""/&None、${CurrentChar}/Current &Char、${CurrentWordText}/
	//     Current &Word、${CurrentLineText}/Current &Line、${Selection}/
	//     &Selection、${BufferText}/&Buffer;
	//   +0x70:ignore/&Ignore、insertText/&Insert Text、newBuffer/&New Buffer、
	//     replaceBuffer/&Replace Buffer、replaceSelection/&Replace Selection、
	//     showOutput/Show &Output、showTooltip/Show &Tooltip、
	//     showHtml/Show &Html。
	struct Entry {
		const char *value;
		const char *label;
	};
	static const Entry kArgTokens[6];
	static const Entry kOutputActions[8];
	QList<Entry> m_items68; // 语料 +0x68
	QList<Entry> m_items70; // 语料 +0x70

private:
	QCheckBox *m_check30 = nullptr;          // +0x30
	QDialogButtonBox *m_buttons38 = nullptr; // +0x38
	QComboBox *m_combo40 = nullptr;          // +0x40(搜索组合框)
	QLabel *m_label48 = nullptr;             // +0x48
	QToolButton *m_tool50 = nullptr;         // +0x50
	QGroupBox *m_group58 = nullptr;          // +0x58
	QGroupBox *m_group60 = nullptr;          // +0x60
};
