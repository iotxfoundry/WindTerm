#pragma once

#include <QDialog>

// EnvironmentDialogFace — 语料 EnvironmentDialog(批 429)。
//
// ctor FUN_006b35a6(175B,0021:43065) asm 实测:
//   QDialog(parent, 0) → vtable EnvironmentDialog_vtable + 副 011a2970 →
//   setWindowTitle(tr("Environment Variable")(0xc9d50b)) → setAttribute(0x37,true) →
//   build()(FUN_b2cd2)。
class EnvironmentDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit EnvironmentDialogFace(QWidget *parent = nullptr);
	void build();   // FUN_b2cd2 — 结构段(cited)
};
