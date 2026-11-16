#pragma once

#include <QDialog>

class QTranslator;

// ProfileDialogFace — 语料 ProfileDialog(批 434 / 460)。
//
// ctor FUN_006cf13c(240B,0021:61296) asm 实测:
//   QDialog(parent, 0) → vtable ProfileDialog_vtable + 副 011a35d0 →
//   setWindowTitle(tr("Choose Profiles Directory")(0xc9e135)) →
//   build()(FUN_006ce668,602B)+ applyTheme()(FUN_006cf012,131B)+
//   installAutoTranslator()(FUN_006cf09e,137B)。
//   无 setAttribute。
class ProfileDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit ProfileDialogFace(QWidget *parent = nullptr);

	// FUN_006ce668(602B)**接线**:字段 +0x30 / +0x38 / +0x70 三路 connect,
	//   闭包 FUN_006b2420(按钮盒 PMF 壳)+ FUN_006ce130 + FUN_006cf580。
	void build();

	// FUN_006cf012(131B)应用主题:qApp + **"dige-black"**(fromAscii 实读)
	//   → FUN_00760ffe(qApp, 名)(主题装载面,cited)。
	void applyTheme();

	// FUN_006cf09e(137B)装翻译器:new 0x20 + FUN_006368e6(t, this, **"auto"**)
	//   → **+0x90 = t** → **QCoreApplication::installTranslator(t)**。
	void installAutoTranslator();

protected:
	QTranslator *m_translator90 = nullptr; // +0x90(QTranslator)
	QWidget *m_f30 = nullptr;              // +0x30
	QWidget *m_f38 = nullptr;              // +0x38
	QWidget *m_f70 = nullptr;              // +0x70
};
