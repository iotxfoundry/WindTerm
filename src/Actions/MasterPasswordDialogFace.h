#pragma once

#include <QDialog>

// MasterPasswordDialogFace — 语料 MasterPasswordDialog(批 431)。
//
// ctor FUN_006b9e92(157B,0021:47139) asm 实测:
//   QDialog(parent, 0) → vtable MasterPasswordDialog_vtable + 副 011a1090 →
//   setWindowTitle(tr("Password")(0xc9d743)) →
//   build()(FUN_006b9346)。
//   title 用 tr(\"Password\") —— 与 PasswordDialog 同串
class MasterPasswordDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit MasterPasswordDialogFace(QWidget *parent = nullptr);
	void build();    // FUN_006b9346 — 结构段(cited)
};

