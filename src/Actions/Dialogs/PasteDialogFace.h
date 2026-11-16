#pragma once

#include <QDialog>

// PasteDialogFace — 语料 PasteDialog(批 433)。
//
// ctor FUN_006caf18(221B,0021:58520) asm 实测:
//   QDialog(parent, 0) → vtable PasteDialog_vtable + 副 011a3350 →
//   setWindowTitle(tr("Paste")(0xc9df92)) →
//   setAttribute(0x37, true) →
//   字段 +0x78 = 0 →
//   build()(FUN_006ca710)。
//   字段 +0x78 清 0(页容器槽)
class PasteDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit PasteDialogFace(QWidget *parent = nullptr);

protected:
	QWidget *m_f50 = nullptr; // +0x50
	QWidget *m_f60 = nullptr; // +0x60
	QWidget *m_f70 = nullptr; // +0x70
	QWidget *m_f78 = nullptr; // +0x78(ctor 清 0)
	void build();    // FUN_006ca710 — 结构段(cited)
};

