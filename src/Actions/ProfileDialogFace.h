#pragma once

#include <QDialog>

class QTranslator;

// ProfileDialogFace — 语料 ProfileDialog(批 434)。
//
// ctor FUN_006cf13c(240B,0021:61296) asm 实测:
//   QDialog(parent, 0) → vtable ProfileDialog_vtable + 副 011a35d0 →
//   setWindowTitle(tr("Choose Profiles Directory")(0xc9e135)) →
//   build()(FUN_006ce668) + build2()(FUN_006cf012)。
//   三腿装配;无 setAttribute
class ProfileDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit ProfileDialogFace(QWidget *parent = nullptr);
	void build();    // FUN_006ce668 — 结构段(cited)
	void build2();   // FUN_006cf012 — 结构段(cited)
};

