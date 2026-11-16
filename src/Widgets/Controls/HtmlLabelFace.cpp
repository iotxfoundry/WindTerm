// HtmlLabelFace.cpp — 富文本标签。

#include "Widgets/Controls/HtmlLabelFace.h"

// 出处:QMetaObject 0x0119ca20(methods=0);ctor 内联在调用点。
HtmlLabelFace::HtmlLabelFace(QWidget *parent)
    : QLabel(parent)
{
}

// 0x008fa41a(86B)dtor 真身:
//   vptr = &HtmlLabel_vtable;*(this+0x10) = &PTR_FUN_0119c9c8;
//   +0x30 QString 引用计数递减,归零释放 d;
//   QLabel::~QLabel
// deleting 0x008fa306(92B):同上 + operator_delete(this, 0x48)。
HtmlLabelFace::~HtmlLabelFace() = default;

// metasurface:metaObject 0x008fa2a6 → &PTR_staticMetaObject_0119ca20;
// qt_metacast 0x008fa2be;qt_metacall 0x008fa300(5B)= 纯转发。
