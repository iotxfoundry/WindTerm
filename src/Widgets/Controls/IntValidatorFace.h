#pragma once

#include <QIntValidator>
#include <QString>

// IntValidatorFace — 整数校验器(QIntValidator 派生,**validate 会改写输入**)。
//
// 出处:RTTI "IntValidator";sizeof = **0x18**
// (deleting 0x00726f9a 的 operator_delete(_,0x18));
// dtor 0x00726f86(19B)/deleting 0x00726f9a(37B)
//   —— dtor 只有 QIntValidator::~QIntValidator,零自有析构;
// vt13 0x007270ce(124B)= `validate` 重写。
//
// 字段:QIntValidator 自带的 bottom/top 落在 **+0x10 / +0x14**(int)。
//
// **validate 的语义不是"校验后报错",而是"就地夹紧"**:
//   v = QString::toInt(input)
//   if (top    <= v) v = top;
//   v2 = bottom;
//   if (bottom <= v) v2 = v;      ← 最终 v2 = clamp(v, bottom, top)
//   input = QString::number(v2)   ← **直接把输入框内容改写成夹紧后的值**
// 也就是说输入 999 而上限 100 时,用户看到的是文本框被改成 100,
// 不是"拒绝输入"。这一条与 Qt 的标准 validate(返回 Acceptable/Invalid)
// 语义完全不同,必须原样保留。
class IntValidatorFace : public QIntValidator {
	Q_OBJECT

public:
	explicit IntValidatorFace(QObject *parent = nullptr);
	~IntValidatorFace() override; // 0x00726f86

	// QValidator::validate 重写 —— vt13 0x007270ce
	State validate(QString &input, int &pos) const override;
};
