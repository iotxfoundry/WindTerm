// IntValidatorFace.cpp — 整数校验器(就地夹紧)。

#include "Widgets/Controls/IntValidatorFace.h"

// 出处:RTTI "IntValidator";ctor 内联在调用点,仅转发基构造。
IntValidatorFace::IntValidatorFace(QObject *parent)
    : QIntValidator(parent)
{
}

// 0x00726f86(19B)dtor:只有 QIntValidator::~QIntValidator。
// deleting 0x00726f9a(37B):+ operator_delete(_, 0x18)。
IntValidatorFace::~IntValidatorFace() = default;

// vt13 0x007270ce(124B)validate 真身 —— **就地改写输入**(见头注):
//   v  = toInt(input)
//   若 top    <= v → v = top
//   v2 = bottom;若 bottom <= v → v2 = v
//   input = QString::number(v2)
// 返回值语料未取(函数以 return 结束但不构造 State),此处按 Acceptable 落,
// 并标注:真正起作用的是对 input 的改写。
QValidator::State IntValidatorFace::validate(QString &input, int &pos) const
{
	Q_UNUSED(pos);
	int v = input.toInt();
	if (top() <= v)
		v = top();
	int v2 = bottom();
	if (bottom() <= v)
		v2 = v;
	input = QString::number(v2);
	return Acceptable;
}
