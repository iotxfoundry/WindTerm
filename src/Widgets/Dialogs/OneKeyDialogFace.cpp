// OneKeyDialogFace.cpp — 一键执行配置对话框。

#include "Widgets/Dialogs/OneKeyDialogFace.h"

// 出处:QMetaObject 0x011a1860(methods=0 signals=0);ctor 内联在调用点。
OneKeyDialogFace::OneKeyDialogFace(QWidget *parent)
    : QDialog(parent)
{
}

// dtor 0x009049a2(49B)真身:
//   vptr = &OneKeyDialog_vtable;*(this+0x10) = &PTR_FUN_011a1810;
//   +0xd0 子对象走 FUN_00659460 释放 → QDialog::~QDialog
// deleting 0x00904a06(62B)真身:+ operator_delete(_, **0xd8**)。
OneKeyDialogFace::~OneKeyDialogFace() = default;
