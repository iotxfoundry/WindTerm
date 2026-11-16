// PathEditFace.cpp — 路径输入框。

#include "Widgets/Controls/PathEditFace.h"

// 出处:QMetaObject 0x0119d160(superdata=LineEdit);ctor 内联在调用点。
PathEditFace::PathEditFace(QWidget *parent)
    : LineEditFace(parent)
{
}

// 0x008fab2e(75B)dtor 真身:
//   vptr = &PathEdit_vtable(语料符号 PTR_FUN_01198458);
//   *(this+0x10) = &PTR_FUN_01198608;
//   +0x50 原子引用计件释放(qatomic_unref_call_deleter2);
//   +0x30 引用计数减一,归零 operator_delete;
//   QLineEdit::~QLineEdit(LineEdit 层无字段,直接落 Qt)。
// deleting 0x008faa7c(88B):同上 + operator_delete(this, 0x80)。
PathEditFace::~PathEditFace() = default;
