// MuxWindowFace.cpp — 分屏窗口。

#include "Windows/Mux/MuxWindowFace.h"

// 出处:QMetaObject 0x011ac2a0(class="MuxWindow",methods=1,signals=1);
// ctor 内联在调用点,仅转发 QWidget 基构造。
MuxWindowFace::MuxWindowFace(QWidget *parent)
    : QWidget(parent)
{
}

// 0x0091e4ca(196B)dtor 真身:
//   vptr = &MuxWindow_vtable;*(this+0x10) = &PTR_FUN_011ac248;
//   +0x78 引用计数减一,归零 operator_delete;
//   +0x60 / +0x58 / +0x30 三个 QString 依次减引用;
//   QWidget::~QWidget
// deleting 0x0091e740(209B):同上 + operator_delete(this, 0x88)。
MuxWindowFace::~MuxWindowFace() = default;

// ───────── moc 生成面(出处:QMetaObject 元数据) ─────────
// metaObject 0x0091e3b0 → &PTR_staticMetaObject_011ac2a0
// qt_metacast 0x0091e42c(strcmp "MuxWindow" → QWidget::qt_metacast)
// qt_metacall 0x0091e46e(91B):1 条记录转发到 0x0091e3c8(nameChanged,1 参);
//   超出则返回 (index - 1)。
