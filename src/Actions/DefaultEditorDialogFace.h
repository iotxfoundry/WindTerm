#pragma once

#include <QDialog>

// DefaultEditorDialogFace — 语料 DefaultEditorDialog(批 429)。
//
// ctor FUN_006b22e6(165B,0021:42122) asm 实测:
//   QDialog(parent, 0) → vtable DefaultEditorDialog_vtable + 副 011a26f0 →
//   setWindowTitle(tr("Default Editor")(0xc9d4db)) →
//   build()(FUN_00962)。
class DefaultEditorDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit DefaultEditorDialogFace(QWidget *parent = nullptr);
	void build();   // FUN_00962 — 结构段(cited)
};
