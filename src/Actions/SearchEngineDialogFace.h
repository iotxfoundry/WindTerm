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

	// FUN_006d9290(670B)**装配**:QFormLayout + QLineEdit ×2 + QDialogButtonBox;
	//   两行文案实读 **"&Search engine:"** /
	//   **"&URL with {q} in place of query:"**(查询占位符 **{q}**)。
	void build();

	// FUN_006d906a(550B)**接线**:字段 +0x30 / +0x40 / +0x48,
	//   闭包 FUN_006b2420 / FUN_006d8ff5 / FUN_006d902f。
	void wire();

protected:
	QWidget *m_f30 = nullptr; QWidget *m_f40 = nullptr; QWidget *m_f48 = nullptr;
};

