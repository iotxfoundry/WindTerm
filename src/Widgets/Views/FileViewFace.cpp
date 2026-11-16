// FileViewFace.cpp — 文件视图。

#include "Widgets/Views/FileViewFace.h"

// 出处:QMetaObject 0x0119c7c0(class="FileView",signals=4,superdata=0);
// ctor 无独立语料条目(内联在调用点),仅转发 QWidget 基构造。
FileViewFace::FileViewFace(QWidget *parent)
    : QWidget(parent)
{
}

// 0x008f9dc0(308B)dtor 真身。逐句:
//   vptr = &FileView_vtable;*(this+0x10) = &PTR_FUN_0119c768;
//   +0xb0 → +0xa0 → +0x88 → +0x60 四个引用计数件依次减一,归零即
//   operator_delete(件本体);
//   QWidget::~QWidget。
// deleting 0x008fa15c(328B):同上 + operator_delete(this, 0xc0)。
FileViewFace::~FileViewFace() = default;

// ───────── 信号桥 0x008f9c68(183B)(出处:dispatch switch) ─────────
// op=0:index 0 → 0 参 emit;1 → (int,int);2 → (bool);3 → 0 参。
// op=10:四个发射器反查,写回 0..3。
