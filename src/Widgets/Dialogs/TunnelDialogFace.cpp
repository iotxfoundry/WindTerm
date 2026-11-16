// TunnelDialogFace.cpp — 隧道配置对话框。

#include "Widgets/Dialogs/TunnelDialogFace.h"

// 出处:QMetaObject 0x011a4ee0(methods=0 signals=0 props=0 superdata=0);
// ctor 内联在调用点(装配腿 0x009097b0),仅转发 QDialog 基构造。
TunnelDialogFace::TunnelDialogFace(QWidget *parent)
    : QDialog(parent)
{
}

// 0x00909a7c(82B)dtor 真身:
//   vptr = &TunnelDialog_vtable;*(this+0x10) = &PTR_FUN_011a4e90;
//   +0xb8 QString 引用计数减一,归零 → 0x009097b0(535B 收尾腿)
//   → QDialog::~QDialog
// deleting 0x009099c8(88B):同上 + operator_delete(this, 0xc0)。
TunnelDialogFace::~TunnelDialogFace() = default;

// metasurface:metaObject 0x00909750 → &PTR_staticMetaObject_011a4ee0(methods=0);
// qt_metacast 0x00909768(strcmp "TunnelDialog" → QDialog::qt_metacast);
// qt_metacall 0x009097aa(5B)= 纯转发。
//
// ⚠ 与 docs/pending-attribution.md §1 的关系:那里记的是
//   SettingsPageFace ↔ TunnelDialogFace 的 FUN_0072d0f2 / FUN_0072bf8a
//   真重复(0x48 行结构未裁)。本批只落 TunnelDialog **自身**的元对象与 dtor,
//   没有碰那条可疑的共享函数,该待办仍然挂着。
