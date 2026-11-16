#pragma once

#include <QPushButton>

// ColorButtonFace — 颜色按钮(QPushButton 派生,**零字段**)。
//
// 出处:RTTI "ColorButton";QMetaObject 0x01194020
// (rev=8,class="ColorButton",methods=1,**signals=1**,props=0,superdata=0);
// sizeof = **0x30**(deleting 0x008f03d8 的 operator_delete(_,0x30))
//   —— 与 QPushButton 同尺寸 ⇒ 零字段;
// dtor 0x008f039a(29B)/deleting 0x008f03d8(47B);
// metacast 0x008f02fc / metacall 0x008f033e(91B)。
//
// 唯一条信号:`colorChanged(?)` 1 参。
class ColorButtonFace : public QPushButton {
	Q_OBJECT

public:
	explicit ColorButtonFace(QWidget *parent = nullptr);
	~ColorButtonFace() override; // 0x008f039a

signals:
	void colorChanged(const QColor &color); // #0
};
