#pragma once

#include <QWidget>

// SideSeparatorFace — 侧栏分隔条(纯尺寸件)。
//
// 出处:RTTI "SideSeparator";QMetaObject 0x01198ae0
// (**methods=0 / signals=0 / props=0 / superdata=0** ⇒ 无元方法);
// sizeof = **0x30**(deleting 0x008f7126 的 operator_delete(_,0x30));
// dtor 0x008f70e8(29B)/deleting 0x008f7126(47B);
// sizeHint = vt14 0x0058d638(105B);metacast 0x008f70a0 / metacall 0x008f70e2(5B,空)。
//
// 字段:无(dtor 只有 vptr 复位 + QWidget 析构两行)。
class SideSeparatorFace : public QWidget {
	Q_OBJECT

public:
	explicit SideSeparatorFace(QWidget *parent = nullptr);
	~SideSeparatorFace() override; // 0x008f70e8

	QSize sizeHint() const override; // vt14 0x0058d638
};
