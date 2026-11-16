#pragma once

#include <QDialog>

// DefaultEditorDialogFace — 语料 DefaultEditorDialog(批 429 / 454)。
//
// ctor FUN_006b22e6(165B,0021:42122) asm 实测:
//   QDialog(parent, 0) → vtable DefaultEditorDialog_vtable + 副 011a26f0 →
//   setWindowTitle(tr("Default Editor")(0xc9d4db)) →
//   **装配 = s_filer_defaultEditor_6b0ab0(3723B)** + **接线 = FUN_006b0962(334B)**。
//
// 装配(s_filer_defaultEditor_6b0ab0,3723B)实证:
//   **QTabWidget** 三平台页:键 `linux`/标题 `&Linux`、`macos`/`&macOS`、
//   `windows`/`&Windows`;标签 **tr("&Choose a default editor:")(0xc9d4b1)**;
//   配置键 **"filer.defaultEditor"**;**模板 "%1.%2"**(形如
//   `filer.defaultEditor.linux` = 平台.子键);7 个 0x30 件 + 1 个 0x80 件。
//
// 接线(FUN_006b0962,334B):**+0x30 QDialogButtonBox** 的
//   accepted → 闭包 FUN_006b23b0(槽偏移 0x1b9)/ rejected → **FUN_006b2420**(0x1c1)。
class DefaultEditorDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit DefaultEditorDialogFace(QWidget *parent = nullptr);
	void build();   // s_filer_defaultEditor_6b0ab0(3723B) — 结构段
	void wire();    // FUN_006b0962(334B)

protected:
	QWidget *m_buttons30 = nullptr; // +0x30(QDialogButtonBox)
};
