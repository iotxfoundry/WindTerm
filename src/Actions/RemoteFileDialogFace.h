#pragma once

#include <QDialog>

// RemoteFileDialogFace — 语料 RemoteFileDialog(批 435)。
//
// ctor FUN_006d8cfe(247B,0022:5146) asm 实测:
//   QDialog(parent, 0) → vtable RemoteFileDialog_vtable + 副 011a2470 →
//   **不设窗口标题**(语料无 setWindowTitle)→
//   setAttribute(0x37, true) →
//   字段 +0x38 = param_3 →
//   字段 +0x40 = 0 →
//   字段 +0x48 = 0 →
//   字段 +0x50 = 0 →
//   字段 +0x58 = 0 →
//   字段 +0x60 = 0 →
//   字段 +0x68 = 0 →
//   字段 +0x70 = 0 →
//   字段 +0x78 = 0 →
//   字段 +0x88 = 0 →
//   字段 +0x90 = *param_4 →
//   build()(FUN_006d5eec) + build2()(FUN_006d6bf2)。
//   **无标题**;+0x38 与 +0x90 为入参,其余 0x40..0x88 清 0
class RemoteFileDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit RemoteFileDialogFace(QWidget *parent = nullptr);
	void build();    // FUN_006d5eec — 结构段(cited)
	void build2();   // FUN_006d6bf2 — 结构段(cited)
};

