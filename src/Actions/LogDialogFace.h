#pragma once

#include <QDialog>

// LogDialogFace — 语料 LogDialog(批 431)。
//
// ctor FUN_006b874c(206B,0021:46211) asm 实测:
//   QDialog(parent, 0) → vtable LogDialog_vtable + 副 0118a1c8 →
//   setWindowTitle(tr("Log Dialog")(0xc9d724)) →
//   setAttribute(0x37, true) →
//   字段 +0x30 = uVar1(入参) →
//   build()(FUN_006b73a2)。
//   字段 +0x30 = uVar1(构造入参)
class LogDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit LogDialogFace(QWidget *parent = nullptr);

protected:
	QWidget *m_f30 = nullptr; // +0x30(ctor 入参写入)
	QWidget *m_f40 = nullptr; // +0x40
	QWidget *m_f48 = nullptr; // +0x48
	QWidget *m_f70 = nullptr; // +0x70
	void build();    // FUN_006b73a2 — 结构段(cited)
};

