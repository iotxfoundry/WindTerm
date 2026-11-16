#pragma once

#include <QDialog>

// TableItemDialogFace — 语料 TableItemDialog(批 432)。
//
// ctor FUN_006c7080(254B,0021:55897) asm 实测:
//   QDialog(parent, 0) → vtable TableItemDialog_vtable + 副 0118a878 →
//   **不设窗口标题**(语料无 setWindowTitle)→
//   setAttribute(0x37, true) →
//   字段 +0x30 = *param_2 →
//   字段 +0x38 = *param_3 →
//   **无独立装配腿**(ctor 内直接写 +0x30/+0x38 两入参,不调 FUN_)。
//   **不设标题**;+0x30/+0x38 两个入参指针入字段
class TableItemDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit TableItemDialogFace(QWidget *parent = nullptr);
};

