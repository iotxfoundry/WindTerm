#pragma once

#include <QTreeWidget>

// CategoryTreeFace — 分类树(QTreeWidget 派生)。
//
// 出处:RTTI "CategoryTree";sizeof = **0x78**
// (deleting 0x006ec31e 的 operator_delete(_,0x78));
// dtor 0x006ec2e0(29B)⇒ **零自有字段**;
// eventFilter = vt6 0x0058cad2(**437B**);metaObject = vt0 0x008fb2b0(24B)。
//
// eventFilter 语义(vt6 实读)—— **与 ListView / ListWidget 的写法同构**:
//   三连门:本件可见(byte[+9]&0x80)&& watched == +0x48 && KeyPress(6);
//   命中后走 `vtable+0x298`(moveCursor)而不是自定义动作。
//   (同族已落三家:ListWidget +0x38、ListView +0x38、本类 **+0x48** ——
//    键位来源件偏移不同,不能照抄偏移。)
class CategoryTreeFace : public QTreeWidget {
	Q_OBJECT
public:
	explicit CategoryTreeFace(QWidget *parent = nullptr);
	~CategoryTreeFace() override; // 0x006ec2e0

protected:
	bool eventFilter(QObject *watched, QEvent *event) override; // vt6 0x0058cad2

private:
	void *m_keySource48 = nullptr; // +0x48
};
