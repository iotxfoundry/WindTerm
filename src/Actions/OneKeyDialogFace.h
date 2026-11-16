#pragma once

#include <QDialog>

// OneKeyDialogFace — 语料 OneKeyDialog(批 432)。
//
// ctor FUN_006c55c0(206B,0021:54635) asm 实测:
//   QDialog(parent, 0) → vtable OneKeyDialog_vtable + 副 011a1810 →
//   setWindowTitle(tr("OneKey Manager")(0xc9dcb9)) →
//   setAttribute(0x37, true) →
//   build()(FUN_006c5300) → QTimer::singleShot(闭包)。
//   singleShot 收尾(语料有)
class OneKeyDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit OneKeyDialogFace(QWidget *parent = nullptr);
	void build();    // FUN_006c5300 — 结构段(cited)
};

