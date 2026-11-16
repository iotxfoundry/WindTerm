#pragma once

#include <QDialog>
#include <QString>

// InsertFileDialogFace — 语料 **InsertFileDialog**(批 425)。
//
// ctor FUN_0072facc(74B,0022.c:...) asm 实测:
//   QDialog(parent, 0) → vtable **InsertFileDialog_vtable** + 副 011a3d30 →
//   **+0x30 = 空 QString** → buildA()(FUN_0072f7b2,716B)+ buildB()(FUN_0072f49e,229B)。
//   注:本 ctor **不设 windowTitle**(沿用宿主/空标题)。
class InsertFileDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit InsertFileDialogFace(QWidget *parent = nullptr);

	void buildA();   // FUN_0072f7b2(716B) — 结构段
	// FUN_0072f49e(229B)**接线**(非装配):
	//   +0x50 信号 FUN_008fa97a → 闭包 impl FUN_0072f350(smeta 0119d160);
	//   +0x40 "2accepted()" → accept;"2rejected()" → reject。
	void wire();
	// FUN_0072f584(517B)标签/标题:
	//   setWindowTitle(tr("Insert File")(0xca1ab1));
	//   **+0x48 setText(tr("&File:")(0xc9e39f))**;+0x60 / +0x68 setText(实参折叠)。
	void applyLabels(const QString &a, const QString &b);

protected:
	QString m_f30;     // +0x30
	QWidget *m_buttons40 = nullptr; // +0x40(QDialogButtonBox)
	QWidget *m_label48 = nullptr;   // +0x48(标签,"&File:")
	QWidget *m_sig50 = nullptr;     // +0x50(信号宿主,smeta 0119d160)
	QWidget *m_f60 = nullptr;       // +0x60
	QWidget *m_f68 = nullptr;       // +0x68
};
