#pragma once

#include <QDialog>

// SettingDialogFace — 语料 SettingDialog(批 437)。
//
// ctor FUN_006ea66e(318B,0022:14440) asm 实测:
//   QDialog(parent, 0) → vtable SettingDialog_vtable + 副 011a4230 →
//   setWindowTitle(tr("Settings")(0xc9f084)) →
//   setAttribute(0x37, true) →
//   字段 +0x30 = param_2 →
//   字段 +0x38 = 0 →
//   字段 +0x60 = 0 →
//   字段 +0x68 = 0 →
//   build()(FUN_006dd310) + build2()(FUN_006ea37a)。
//   另有两串:tr(\"Terminal Settings\")(0xc9f07b) / tr(\"Editor Settings\")(0xc9f06b)
class SettingDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit SettingDialogFace(QWidget *parent = nullptr);
	void build();    // FUN_006dd310 — 结构段(cited)
	void build2();   // FUN_006ea37a — 结构段(cited)
};

