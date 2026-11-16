// ButtonBarFace.cpp — 按钮条。

#include "Widgets/Bars/ButtonBarFace.h"

ButtonBarFace::ButtonBarFace(QWidget *parent)
    : QFrame(parent)
{
}

// 0x008ef56e(127B)dtor 真身:
//   vptr = &ButtonBar_vtable;*(this+0x10) = &PTR_FUN_01193188;
//   qt_shared_data_unref(+0x40)
//   +0x30 QMap:引用计数归零 → QMapDataBase::freeTree(根节点)+ freeData
//   QFrame::~QFrame
// deleting 0x008ef6ee(128B):同上 + operator_delete(this, 0x50)。
ButtonBarFace::~ButtonBarFace() = default;

// ───────── 信号桥 0x008ef1ea(740B)(出处:dispatch switch + 串表) ─────────
// op=0 逐索引 emit;op=10 反查发射器写回索引。17 条与头文件的表一一对应。
// 其中 5/6/7/8/14/15 取 *(u8*)args[1],10 也是字节 → 形参为 bool;
// 2 取 args[1] 整槽 → 形参为宽类型(captureGroup)。
