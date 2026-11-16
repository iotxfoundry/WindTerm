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
	// 两腿分工(批 459):
	//   FUN_006cc276(859B)=**装配**:QVBoxLayout + **QFormLayout** +
	//     **QGroupBox** + **QLineEdit**;文案实读 **tr("&Pattern:")** /
	//     **tr("&Description:")** / **tr("Match")** / **tr("Sound")**;
	//     收尾 QDialogButtonBox。
	//   FUN_006cbbbe(627B)=**接线**:字段 +0x30 / +0x38 / +0x40 三路,
	//     闭包 FUN_006b2420 + FUN_006ce0c0。
	void build();    // FUN_006cc276(859B) — 装配
	void wire();     // FUN_006cbbbe(627B)

protected:
	QWidget *m_f30 = nullptr; // +0x30
	QWidget *m_f38 = nullptr; // +0x38
	QWidget *m_f40 = nullptr; // +0x40
};

