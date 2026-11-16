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
	void buildB();   // FUN_0072f49e(229B) — 结构段

protected:
	QString m_f30;   // +0x30
};
