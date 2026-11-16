#pragma once

#include <QDialog>

// TextMarkDialogFace — 语料 TextMarkDialog(批 438)。
//
// ctor FUN_006f1036(175B,0022:18703) asm 实测:
//   QDialog(parent, 0) → vtable TextMarkDialog_vtable + 副 011a4730 →
//   setWindowTitle(tr("Text Mark")(0xc9faaa)) →
//   setAttribute(0x37, true) →
//   **无独立装配腿**(ctor 内直接落字段)。
//   **无独立装配腿**;setAttribute 0x37
class TextMarkDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit TextMarkDialogFace(QWidget *parent = nullptr);
};

