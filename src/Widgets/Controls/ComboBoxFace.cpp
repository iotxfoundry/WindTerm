// ComboBoxFace.cpp — 带侧按钮的下拉框。

#include "Widgets/Controls/ComboBoxFace.h"

// 出处:QMetaObject 0x0119bf60(methods=2 signals=2 superdata=0);
// ctor 内联在调用点。
ComboBoxFace::ComboBoxFace(QWidget *parent)
    : QComboBox(parent)
{
}

// dtor 真身见 FontComboBox 的 dtor 里第二段(vptr 落回
// &PTR_FUN_0119bd58 / &PTR_FUN_0119bf18 之后):+0x30 引用计数减一,
// 归零 operator_delete,然后 QComboBox::~QComboBox。
// ⚠ 本类 dtor 在语料里没有独立 entry(被 FontComboBox 的 dtor 内联展开),
//   上面这段是从 FontComboBox_dtor(0x0055682e,112B)的第二段实读的。
ComboBoxFace::~ComboBoxFace() = default;

// metasurface:metaObject → &PTR_staticMetaObject_0119bf60;
// qt_metacast 0x008f961e;qt_metacall 0x008f0978(5B)= 纯转发 QComboBox::qt_metacall。
