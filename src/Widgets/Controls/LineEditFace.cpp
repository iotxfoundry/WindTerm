// LineEditFace.cpp — 输入框基座。

#include "Widgets/Controls/LineEditFace.h"

// 出处:QMetaObject 0x01198660(methods=2 signals=2 superdata=0);
// ctor 内联在调用点,仅转发 QLineEdit 基构造。
LineEditFace::LineEditFace(QWidget *parent)
    : QLineEdit(parent)
{
}

// 本类零字段 ⇒ dtor 只有 vptr 复位 + QLineEdit::~QLineEdit。
LineEditFace::~LineEditFace() = default;

// metasurface:metaObject → &PTR_staticMetaObject_01198660;
// qt_metacast 0x008f6e2e(strcmp "LineEdit" → QLineEdit::qt_metacast);
// qt_metacall 0x008f6e70(93B):2 条记录转发(记录 10 反查,超出则 index-2)。
