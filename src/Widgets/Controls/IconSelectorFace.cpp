// IconSelectorFace.cpp — 图标选择按钮。

#include "Widgets/Controls/IconSelectorFace.h"

// 出处:QMetaObject 0x0119cf00(superdata=SideButton);
// ctor 内联在调用点,仅转发基构造。
IconSelectorFace::IconSelectorFace(QWidget *parent)
    : SideButtonFace(parent)
{
}

// 0x008fa8b8(103B)dtor 真身(两级链):
//   vptr = &IconSelector_vtable;*(this+0x10) = &PTR_FUN_0119cec0;
//   +0x38 QString 引用计数递减;
//   vptr = &SideButton_vtable(PTR_FUN_01198898);→ QPushButton::~QPushButton
// deleting 0x008fa75a(116B):同上 + operator_delete(this, 0x48)。
// 注:SideButton 的 dtor 是 29B(只有 vptr 复位 + 基类析构),所以
// 这里第二跳之后直接落 QPushButton —— 与 SideButtonFace 头注一致。
IconSelectorFace::~IconSelectorFace() = default;
