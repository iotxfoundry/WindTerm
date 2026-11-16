#pragma once

#include <QDialog>

class QComboBox;
class QDialogButtonBox;
class QPlainTextEdit;

// EnvironmentDialogFace — 语料 EnvironmentDialog(批 429;批 313 的 EnvDialogFace
// 已合并入本类 —— 同一个二进制类,勿再拆)。
//
// ctor FUN_006b35a6(175B,0021:43065) asm 实测:
//   QDialog(parent, 0) → vtable EnvironmentDialog_vtable(0x11a2788,
//   typeinfo "17EnvironmentDialog")+ 副 011a2970 →
//   setWindowTitle(tr("Environment Variable")(0xc9d50b)) → setAttribute(0x37,true) →
//   build() → wire()。
class EnvironmentDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit EnvironmentDialogFace(QWidget *parent = nullptr);

protected:
	QWidget *m_buttons30 = nullptr;          // +0x30(QDialogButtonBox)
	QWidget *m_combo40 = nullptr;            // +0x40(QComboBox,可编辑)
	QPlainTextEdit *m_edit48 = nullptr;      // +0x48

	// envDialog_setupUi(1109B,0021:42909 入口 0x006b3100)装配真身:
	//   +0x48 QPlainTextEdit(parent)(0x30)@006b3124 →
	//   +0x40 combo_makeSearchCombo(parent)(0x48)@006b3140 →
	//   +0x30 QDialogButtonBox(parent)(0x30)@006b315c → QFormLayout(0x20)@006b3179 →
	//   FUN_0075d6e8(app, this)(对话框公共腿,cited)。
	//   随后:setMinimumWidth/Height(实参 Ghidra 折叠)+
	//   setWordWrapMode(+0x48, 3 = WrapAnywhere)+
	//   QProcessEnvironment::systemEnvironment().keys() → 逐项入组合框。
	void build();

	// FUN_006b2cd2(592B)**接线**(非装配):
	//   **+0x40 QComboBox::editTextChanged** → 闭包 FUN_006b2c36;
	//   **+0x40 QComboBox::currentTextChanged** → 闭包 FUN_006b36e0
	//     (转发槽 FUN_006b2f2c);
	//   **+0x30 QDialogButtonBox** accepted → 闭包 FUN_006b3750(槽偏移 0x1b9);
	//   rejected → 同族(0x1c1)。
	//   ⇒ +0x30 按钮盒 / +0x40 名字下拉(可编辑)。
	//   同行标签实读:**tr("&Variable:")(0xc9d4f8)** / **tr("V&alue:")(0xc9d503)**。
	void wire();
};
