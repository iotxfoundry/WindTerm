#pragma once

#include <QProgressBar>

// PasswordMeterFace — 密码强度条(QProgressBar 派生,**零字段**)。
//
// 出处:RTTI "PasswordMeter";QMetaObject 0x0119b120
// (**methods=0 / signals=0 / props=0 / superdata=0**);
// sizeof = **0x30**(deleting 0x008f8c0c 的 operator_delete(_,0x30))
// —— **与 QProgressBar 同尺寸**,即本类不加任何字段,纯样式/行为定制。
// dtor 0x008f8bce(29B)/deleting 0x008f8c0c(47B)。
class PasswordMeterFace : public QProgressBar {
	Q_OBJECT

public:
	explicit PasswordMeterFace(QWidget *parent = nullptr);
	~PasswordMeterFace() override; // 0x008f8bce
};
