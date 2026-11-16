#pragma once

#include <QDialog>

// SessionTriggerDialogFace — 语料 SessionTriggerDialog(批 437)。
//
// ctor FUN_006da816(270B,0022:6430) asm 实测:
//   QDialog(parent, 0) → vtable SessionTriggerDialog_vtable + 副 0118adb8 →
//   setWindowTitle(tr("Session Triggers")(0xc9e4f1)) →
//   setAttribute(0x37, true) →
//   build()(FUN_006d9d8a) + build2()(FUN_006da092) → QTimer::singleShot(闭包)。
//   setAttribute + singleShot
class SessionTriggerDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit SessionTriggerDialogFace(QWidget *parent = nullptr);

	// FUN_006da092(644B)**装配**:QVBoxLayout + QHBoxLayout + **QLabel +
	//   QPushButton** + QDialogButtonBox(无 tr 字符串 —— 按钮文案复用)。
	void build();
	// FUN_006d9d8a(776B)**接线**:字段 +0x30 / +0x38 / +0x48,
	//   闭包 FUN_006b2420 / **FUN_006db5b0**。
	void wire();

protected:
	QWidget *m_f30 = nullptr; QWidget *m_f38 = nullptr; QWidget *m_f48 = nullptr;
};

