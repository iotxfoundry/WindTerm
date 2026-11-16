#pragma once

#include <QDoubleSpinBox>
#include <QSpinBox>

// SpinBoxFaces.h — 两个零字段数值输入框。
//
// 出处(entry 地址逐一列):
//   SpinBox        dtor 0x0073910c(29B)/deleting 0x0073914a(47B,_,**0x30**)
//   DoubleSpinBox  dtor 0x0073906c(29B)/deleting 0x007390aa(47B,_,**0x30**)
//
// 两者 dtor 都只有"vptr 复位 + 基类析构"两行,deleting 的尺寸 0x30 又分别
// 等于 **QSpinBox / QDoubleSpinBox 本身的大小** ⇒ **零字段**。
// 按 §1.1「同组同层」放一处(两个都是纯行为/样式定制)。
// 注意二者是**兄弟**,不是派生:基类不同(QSpinBox / QDoubleSpinBox)。

class SpinBoxFace : public QSpinBox {
	Q_OBJECT
public:
	explicit SpinBoxFace(QWidget *parent = nullptr);
	~SpinBoxFace() override; // 0x0073910c
};

class DoubleSpinBoxFace : public QDoubleSpinBox {
	Q_OBJECT
public:
	explicit DoubleSpinBoxFace(QWidget *parent = nullptr);
	~DoubleSpinBoxFace() override; // 0x0073906c
};
