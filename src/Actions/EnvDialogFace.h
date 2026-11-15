#pragma once

#include <QDialog>

class QComboBox;
class QDialogButtonBox;
class QPlainTextEdit;

// EnvDialogFace — 语料环境变量对话框装配面(批 313)。
// envDialog_setupUi(1109B,0021.c:42909):
//   +0x48 QPlainTextEdit(parent)(0x30)@006b3124 →
//   +0x40 combo_makeSearchCombo(parent)(0x48)@006b3140 →
//   +0x30 QDialogButtonBox(parent)(0x30)@006b315c → QFormLayout(0x20) →
//   FUN_0075d6e8(app, this)(对话框公共腿,cited)—— 装配序。
//   随后:setMinimumWidth/Height(实参 Ghidra 折叠)+
//   setWordWrapMode(+0x48, 3 = WrapAnywhere)+
//   QProcessEnvironment::systemEnvironment().keys() → 逐项入组合框。
// ctor 未定位 → 本类构造即执行装配(cited 注记)。
class EnvDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit EnvDialogFace(QWidget *parent = nullptr);

	// envDialog_setupUi 真身
	void setupUi();

private:
	QDialogButtonBox *m_buttons30 = nullptr; // +0x30
	QComboBox *m_combo40 = nullptr;          // +0x40
	QPlainTextEdit *m_edit48 = nullptr;      // +0x48
};
