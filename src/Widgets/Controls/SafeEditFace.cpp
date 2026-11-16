// SafeEditFace.cpp — 安全输入框。

#include "Widgets/Controls/SafeEditFace.h"

// 出处:RTTI "SafeEdit";ctor 内联在调用点(基类逐个转发)。
SafeEditFace::SafeEditFace(QWidget *parent)
    : PathEditFace(parent)
{
}

// 0x008fadc0(147B)dtor 真身(三级链,见头注):
//   vptr = &SafeEdit_vtable;*(this+0x10) = &PTR_FUN_0119d368;
//   +0x88 QString 引用计数递减;
//   vptr = &PathEdit_vtable(PTR_FUN_01198458);*(this+0x10) = PTR_FUN_01198608;
//   +0x50 / +0x30(PathEdit 层)释放;
//   QLineEdit::~QLineEdit。
// deleting 0x008fac84(160B):同上 + operator_delete(this, 0x90)。
SafeEditFace::~SafeEditFace() = default;
