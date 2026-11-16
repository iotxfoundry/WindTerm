// ButtonBarPanelFace.cpp — 按钮条的面板面。

#include "Widgets/Bars/ButtonBarPanelFace.h"

// 出处:QMetaObject 0x01193440(class="ButtonBarPanel",signals=17,superdata=0);
// ctor 无独立语料条目(内联在调用点),仅转发 QFrame 基构造。
ButtonBarPanelFace::ButtonBarPanelFace(QWidget *parent)
    : QFrame(parent)
{
}

// 0x008efd6e(29B)dtor 真身:
//   vptr = &ButtonBarPanel_vtable;*(this+0x10) = &PTR_FUN_011933e8;
//   QFrame::~QFrame —— 无自有字段要释放(见头注 ②)。
// deleting 0x008efdac(47B):同上 + operator_delete(this, size)。
ButtonBarPanelFace::~ButtonBarPanelFace() = default;

// 信号桥 0x008ef9ea(740B)与 ButtonBarFrame 的 0x008ef1ea 逐字节同构:
// 17 条 emit 腿、17 条反查腿、同样的形参宽度。故此处不再重复展开,
// 语义见 ButtonBarFace.h 的信号表。
