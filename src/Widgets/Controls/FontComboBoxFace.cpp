// FontComboBoxFace.cpp — 字体选择下拉框。

#include "Widgets/Controls/FontComboBoxFace.h"

// 出处:QMetaObject 0x01194ac0(superdata=ComboBox);ctor 内联在调用点。
FontComboBoxFace::FontComboBoxFace(QWidget *parent)
    : ComboBoxFace(parent)
{
}

// 0x0055682e(112B)dtor 真身 —— **两级链**:
//   vptr = &FontComboBox_vtable;*(this+0x10) = &PTR_FUN_01194a78;
//   ① +0x48 独立块 operator_delete(_, 8),置 0      ← FontComboBox 自有
//   ② vptr = &ComboBox_vtable(语料 PTR_FUN_0119bd58);
//      *(this+0x10) = PTR_FUN_0119bf18;
//      +0x30 引用计数减一,归零 operator_delete       ← ComboBox 层
//   ③ QComboBox::~QComboBox                        ← Qt 层
// deleting 0x005568a4(23B):同上 + operator_delete(this, 0x50)。
// 这条 dtor 同时充当了 ComboBoxFace dtor 的证据源(见该文件注释)。
FontComboBoxFace::~FontComboBoxFace() = default;
