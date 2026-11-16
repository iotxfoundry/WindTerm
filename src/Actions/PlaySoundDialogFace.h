#pragma once

#include <QDialog>

// PlaySoundDialogFace — 语料 PlaySoundDialog(批 434)。
//
// ctor FUN_006cc63e(175B,0021:59501) asm 实测:
//   QDialog(parent, 0) → vtable PlaySoundDialog_vtable + 副 011a1f28 →
//   setWindowTitle(tr("Play Sound")(0xc9fb4c)) →
//   setAttribute(0x37, true) →
//   build()(FUN_006cbbbe) + build2()(FUN_006cc276)。
class PlaySoundDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit PlaySoundDialogFace(QWidget *parent = nullptr);
	void build();    // FUN_006cbbbe — 结构段(cited)
	void build2();   // FUN_006cc276 — 结构段(cited)
};

