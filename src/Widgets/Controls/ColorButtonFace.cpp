// ColorButtonFace.cpp — 颜色按钮。

#include "Widgets/Controls/ColorButtonFace.h"

#include <QColor>

// 出处:QMetaObject 0x01194020(methods=1 signals=1);
// ctor 内联在调用点,仅转发 QPushButton 基构造。
ColorButtonFace::ColorButtonFace(QWidget *parent)
    : QPushButton(parent)
{
}

// 0x008f039a(29B)dtor: vptr 复位 + QPushButton::~QPushButton(零字段)。
// deleting 0x008f03d8(47B): + operator_delete(_, 0x30)。
ColorButtonFace::~ColorButtonFace() = default;

// metasurface:metaObject 0x008f0280 → &PTR_staticMetaObject_01194020
// qt_metacast 0x008f02fc(strcmp "ColorButton" → QPushButton::qt_metacast)
// qt_metacall 0x008f033e(91B):1 条记录转发(colorChanged);超出 index - 1。
