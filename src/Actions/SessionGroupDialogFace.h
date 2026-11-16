#pragma once

#include <QDialog>

// SessionGroupDialogFace — 语料 SessionGroupDialog(批 436)。
//
// ctor FUN_006d9a66(175B,0022:5807) asm 实测:
//   QDialog(parent, 0) → vtable SessionGroupDialog_vtable + 副 0118ab78 →
//   setWindowTitle(tr("Session Group")(0xc9e491)) →
//   setAttribute(0x37, true) →
//   build()(FUN_006d97d0) + build2()(FUN_006d991e)。
//   title 串在 0xc9e491(非 tr 直取)
class SessionGroupDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit SessionGroupDialogFace(QWidget *parent = nullptr);
	void build();    // FUN_006d97d0 — 结构段(cited)
	void build2();   // FUN_006d991e — 结构段(cited)
};

