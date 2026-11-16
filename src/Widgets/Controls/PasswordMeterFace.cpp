// PasswordMeterFace.cpp — 密码强度条。

#include "Widgets/Controls/PasswordMeterFace.h"

// 出处:QMetaObject 0x0119b120(methods=0);ctor 内联在调用点。
PasswordMeterFace::PasswordMeterFace(QWidget *parent)
    : QProgressBar(parent)
{
}

// 0x008f8bce(29B)dtor 真身:
//   vptr = &PasswordMeter_vtable;*(this+0x10) = &PTR_FUN_0119b0d0;
//   QProgressBar::~QProgressBar —— 无自有字段(见头注)。
// deleting 0x008f8c0c(47B):同上 + operator_delete(this, 0x30)。
PasswordMeterFace::~PasswordMeterFace() = default;

// metasurface:metaObject 0x008f8b6e → &PTR_staticMetaObject_0119b120;
// qt_metacast 0x008f8b86;qt_metacall 0x008f8bc8(5B)= 纯转发。
