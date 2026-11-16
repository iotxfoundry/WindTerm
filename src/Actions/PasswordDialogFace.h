#pragma once

#include <QDialog>

// PasswordDialogFace — 语料 PasswordDialog(批 433)。
//
// ctor FUN_006c9e70(227B,0021:57818) asm 实测:
//   QDialog(parent, 0) → vtable PasswordDialog_vtable + 副 011a1a90 →
//   setWindowTitle(tr("Password")(0xc9d743)) →
//   build()(FUN_006c955c)。
//   与 MasterPasswordDialog 同 title 串
class PasswordDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit PasswordDialogFace(QWidget *parent = nullptr);

protected:
	QWidget *m_f40 = nullptr; // +0x40
	QWidget *m_f48 = nullptr; // +0x48
	QWidget *m_f50 = nullptr; // +0x50
	void build();    // FUN_006c955c — 结构段(cited)
};

