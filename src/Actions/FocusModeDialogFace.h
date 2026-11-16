#pragma once

#include <QDialog>

// FocusModeDialogFace — 语料 FocusModeDialog(批 430)。
//
// ctor FUN_006b6676(157B,0021:44929) asm 实测:
//   QDialog(parent, 0) → vtable FocusModeDialog_vtable + 副 011a2e08 →
//   setWindowTitle(tr("Focus Mode")(0xc9d5b2)) →
//   build()(FUN_006b3a40) + build2()(FUN_006b639e)。
// 两条腿的实际分工(批 456 实测):
//   FUN_006b3a40(488B)=**接线**:字段 +0x30 / +0x38 / +0x48,闭包
//     FUN_006b2420(按钮盒 PMF 壳)+ FUN_006b6730(页签→栈同步)。
//   FUN_006b639e(656B)=**装配**:QTabBar + QStackedWidget + QVBoxLayout/QHBoxLayout
//     + **QCheckBox**,文案 **tr("&Show this dialog when focus mode starts")**;
//     收尾 QDialogButtonBox。
class FocusModeDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit FocusModeDialogFace(QWidget *parent = nullptr);
	void build();    // FUN_006b639e(656B) — 装配
	void wire();     // FUN_006b3a40(488B)

protected:
	QWidget *m_f30 = nullptr; // +0x30
	QWidget *m_f38 = nullptr; // +0x38
	QWidget *m_f48 = nullptr; // +0x48
};

