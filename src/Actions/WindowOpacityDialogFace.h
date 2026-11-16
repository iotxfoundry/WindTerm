#pragma once

#include <QDialog>

// WindowOpacityDialogFace — 语料 WindowOpacityDialog(批 438)。
//
// ctor FUN_00704dd2(175B,0022:30666) asm 实测:
//   QDialog(parent, 0) → vtable WindowOpacityDialog_vtable + 副 0118d1b0 →
//   setWindowTitle(tr("Window Opacity")(0xca0270)) →
//   setAttribute(0x37, true) →
//   build()(FUN_0070496e)。
class WindowOpacityDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit WindowOpacityDialogFace(QWidget *parent = nullptr);
	void build();    // FUN_0070496e — 结构段(cited)
};

