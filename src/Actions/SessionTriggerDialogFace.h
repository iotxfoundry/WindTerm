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
	void build();    // FUN_006d9d8a — 结构段(cited)
	void build2();   // FUN_006da092 — 结构段(cited)
};

