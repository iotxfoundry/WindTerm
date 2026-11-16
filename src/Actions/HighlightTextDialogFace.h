#pragma once

#include <QDialog>

// HighlightTextDialogFace — 语料 HighlightTextDialog(批 430)。
//
// ctor FUN_006b6bfe(175B,0021:45187) asm 实测:
//   QDialog(parent, 0) → vtable HighlightTextDialog_vtable + 副 011a0e10 →
//   setWindowTitle(tr("Highlight Text")(0xc9fb3c)) →
//   setAttribute(0x37, true) →
//   build()(FUN_006b6840) + build2()(FUN_006b698e)。
class HighlightTextDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit HighlightTextDialogFace(QWidget *parent = nullptr);
	void build();    // FUN_006b6840 — 结构段(cited)
	void build2();   // FUN_006b698e — 结构段(cited)
};

