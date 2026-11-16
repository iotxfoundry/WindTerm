#pragma once

#include <QDialog>

// QuickDialogFace — 语料 QuickDialog(批 435)。
//
// ctor FUN_006d3630(125B,0022:1844) asm 实测:
//   QDialog(parent, 0) → vtable QuickDialog_vtable + 副 011a30d0 →
//   **不设窗口标题**(语料无 setWindowTitle)→
//   setAttribute(0x37, true) →
//   build()(FUN_006cfe98)。
//   **无标题**;最短 ctor(125B)
class QuickDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit QuickDialogFace(QWidget *parent = nullptr);
	void build();    // FUN_006cfe98 — 结构段(cited)
};

