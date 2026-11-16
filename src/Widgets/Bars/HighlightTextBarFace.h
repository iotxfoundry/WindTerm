#pragma once

#include <QWidget>

// HighlightTextBarFace — 高亮文本条(QWidget 派生,1 信号 / 0 槽)。
//
// 出处:RTTI "HighlightTextBar";QMetaObject 0x011950a0
// (rev=8,class="HighlightTextBar",methods=1,**signals=1**,props=0,superdata=0);
// sizeof = **0x48**(deleting 0x008f0d24 的 operator_delete(_,0x48));
// dtor 0x008f0c56(55B)/deleting 0x008f0d24(68B);
// event = vt6 0x0055b83a(858B);metacast 0x008f0bb4 / metacall 0x008f0bf6(95B)。
//
// 唯一条信号(串表实读):`markToggled(...)` —— 按 2 个实参发射
//   (metacall 里 `FUN_008f0b38(this, *(u8*)args[1], args[2])`)
//   ⇒ 形参为 bool + 宽类型(标记开关 + 标记标识)。
//
// 字段(dtor 实读):
//   +0x30 <子对象>    走 FUN_00556570 释放(非指针析构语义)
//   +0x40 QSharedDataPointer(qt_shared_data_unref)
class HighlightTextBarFace : public QWidget {
	Q_OBJECT

public:
	explicit HighlightTextBarFace(QWidget *parent = nullptr);
	~HighlightTextBarFace() override; // 0x008f0c56

signals:
	void markToggled(bool on, const QVariant &mark); // #0

protected:
	bool event(QEvent *event) override; // vt6 0x0055b83a(858B)

private:
	char m_f30[0x10] = {};  // +0x30 子对象(类型未复原)
	void *m_shared40 = nullptr; // +0x40
};
