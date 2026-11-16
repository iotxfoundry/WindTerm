// SpinBoxFaces.cpp — 两个零字段数值输入框。

#include "Widgets/Controls/SpinBoxFaces.h"

// 出处:两者的 deleting 用 operator_delete(_, 0x30),与 QSpinBox /
// QDoubleSpinBox 同尺寸 ⇒ 零字段;ctor 内联在调用点,只转发基构造。

SpinBoxFace::SpinBoxFace(QWidget *parent) : QSpinBox(parent) { }
SpinBoxFace::~SpinBoxFace() = default;   // dtor 0x0073910c

DoubleSpinBoxFace::DoubleSpinBoxFace(QWidget *parent) : QDoubleSpinBox(parent) { }
DoubleSpinBoxFace::~DoubleSpinBoxFace() = default; // dtor 0x0073906c
