#pragma once

#include <QDialog>

// EnvironmentDialogFace — 语料 EnvironmentDialog(批 429)。
//
// ctor FUN_006b35a6(175B,0021:43065) asm 实测:
//   QDialog(parent, 0) → vtable EnvironmentDialog_vtable + 副 011a2970 →
//   setWindowTitle(tr("Environment Variable")(0xc9d50b)) → setAttribute(0x37,true) →
//   build()(FUN_006b2cd2,592B)。
class EnvironmentDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit EnvironmentDialogFace(QWidget *parent = nullptr);

protected:
	QWidget *m_buttons30 = nullptr; // +0x30(QDialogButtonBox)
	QWidget *m_combo40 = nullptr;   // +0x40(QComboBox,可编辑)
	void build();   // FUN_006b2cd2(592B)

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
