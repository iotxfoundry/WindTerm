#pragma once

#include <QDialog>

// HighlightTextDialogFace — 语料 HighlightTextDialog(批 430)。
//
// ctor FUN_006b6bfe(175B,0021:45187) asm 实测:
//   QDialog(parent, 0) → vtable HighlightTextDialog_vtable + 副 011a0e10 →
//   setWindowTitle(tr("Highlight Text")(0xc9fb3c)) →
//   setAttribute(0x37, true) →
//   build()(FUN_006b6840) + build2()(FUN_006b698e)。
// 两腿分工(批 457):
//   FUN_006b698e(567B)=**装配**:QVBoxLayout + QLabel 文案
//     **tr("&Text Marks:")(实读)** + **QDialogButtonBox,按钮文案 tr("Ok")/
//     tr("Cancel")**。
//   FUN_006b6840(334B)=**接线**:字段 **+0x38** 一路 connect,闭包
//     FUN_006b2420(按钮盒 PMF 壳)。
class HighlightTextDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit HighlightTextDialogFace(QWidget *parent = nullptr);
	void build();    // FUN_006b698e(567B) — 装配
	void wire();     // FUN_006b6840(334B)

protected:
	QWidget *m_f38 = nullptr; // +0x38
};

