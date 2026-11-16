#pragma once

#include <QDialog>

// SearchEngineDialogFace — 语料 SearchEngineDialog(批 436)。
//
// ctor FUN_006d9574(175B,0022:5538) asm 实测:
//   QDialog(parent, 0) → vtable SearchEngineDialog_vtable + 副 011a3fb0 →
//   setWindowTitle(tr("Search Engine")(0xc9e45d)) →
//   setAttribute(0x37, true) →
//   build()(FUN_006d906a) + build2()(FUN_006d9290)。
class SearchEngineDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit SearchEngineDialogFace(QWidget *parent = nullptr);
	void build();    // FUN_006d906a — 结构段(cited)
	void build2();   // FUN_006d9290 — 结构段(cited)
};

