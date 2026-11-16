// SideSeparatorFace.cpp — 侧栏分隔条。

#include "Widgets/Controls/SideSeparatorFace.h"

#include <QStyle>
#include <QStyleOption>

// 出处:QMetaObject 0x01198ae0(methods=0);ctor 内联在调用点。
SideSeparatorFace::SideSeparatorFace(QWidget *parent)
    : QWidget(parent)
{
}

// 0x008f70e8(29B)dtor 真身:
//   vptr = &SideSeparator_vtable;*(this+0x10) = &PTR_FUN_01198a98;QWidget::~QWidget
// deleting 0x008f7126(47B):同上 + operator_delete(this, 0x30)。
SideSeparatorFace::~SideSeparatorFace() = default;

// vt14 0x0058d638(105B)sizeHint 真身。逐句:
//   QStyleOption opt(1 = QStyleOption::SO_Widget, 0);initFrom(this)(0x0058d620)
//   v = style()->vtable+0xe0 = **QStyle::pixelMetric(0x38, &opt, this)**
//   返回 QSize(v, v) —— 宽高同为该像素度量值(语料 CONCAT44(v,v))
// 0x38 是 pixelMetric 的枚举值,按字面保留;它决定分隔条厚度。
QSize SideSeparatorFace::sizeHint() const
{
	QStyleOption opt(1, 0); // SO_Widget
	opt.initFrom(const_cast<SideSeparatorFace *>(this));

	const int v = style()->pixelMetric(QStyle::PixelMetric(0x38), &opt,
	                                   const_cast<SideSeparatorFace *>(this));
	return QSize(v, v);
}

// metasurface:metaObject 0x008f703e → &PTR_staticMetaObject_01198ae0;
// qt_metacast 0x008f70a0(strcmp "SideSeparator" → QWidget);
// qt_metacall 0x008f70e2(5B)= 纯转发 QWidget::qt_metacall(本类无自有记录)。
