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
	// FUN_006c5300(639B)**装配**(批 458 实测):**QTabBar + QStackedWidget +
	//   QGridLayout + QVBoxLayout**,收尾 **QDialogButtonBox**(按钮文案
	//   tr("Ok")/tr("Cancel") 实读)。⇒ 多页"一键"管理器(页签 + 网格页)。
	void build();    // FUN_006c5300(639B)
};

