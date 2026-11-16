#pragma once

#include <QDialog>

// FocusModeDialogFace — 语料 FocusModeDialog(批 430)。
//
// ctor FUN_006b6676(157B,0021:44929) asm 实测:
//   QDialog(parent, 0) → vtable FocusModeDialog_vtable + 副 011a2e08 →
//   setWindowTitle(tr("Focus Mode")(0xc9d5b2)) →
//   build()(FUN_006b3a40) + build2()(FUN_006b639e)。
class FocusModeDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit FocusModeDialogFace(QWidget *parent = nullptr);
	void build();    // FUN_006b3a40 — 结构段(cited)
	void build2();   // FUN_006b639e — 结构段(cited)
};

