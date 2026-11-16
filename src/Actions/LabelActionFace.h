#pragma once

#include <QWidgetAction>

class QWidget;

// LabelActionFace — 带一行文字(+可选左右件)的工具栏行动作。
//
// 出处:RTTI "LabelAction";dtor 0x00570ad8(19B)/deleting 0x00570aec(37B);
// createWidget = vt14 0x005711f0(369B)。无自有 Q_OBJECT。
//
// **边距算法按两个标志位分三档**(全部实读,不是猜):
//   flag(+0x10) & 0x20 == 0 且 & 0x40 == 0 → 上下边距 **/4**(带负数修正 +3)
//   flag & 0x20 == 0 且 & 0x40 != 0        → 上边距 **/2**,下边距原值
//   flag & 0x20 != 0                      → 四值原样
//   (语料用 `(long)v < 0` 做向下取整修正 → 对负值等价于算术右移)
//
// 字段:+0x10 uint 标志位;其余控件槽在 createWidget 里按实参取。
class LabelActionFace : public QWidgetAction {
public:
	explicit LabelActionFace(QObject *parent);

	QWidget *createWidget(QWidget *parent) override; // vt14 0x005711f0

private:
	quint32 m_flags10 = 0; // +0x10
};
