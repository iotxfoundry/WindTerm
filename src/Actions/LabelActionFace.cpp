// LabelActionFace.cpp — 文字型工具栏行动作。

#include "Actions/LabelActionFace.h"

#include <QHBoxLayout>
#include <QWidget>

LabelActionFace::LabelActionFace(QObject *parent)
    : QWidgetAction(parent)
{
}

// vt14 0x005711f0(369B)createWidget 真身。逐句:
//   row = new QWidget(parent)(0x30)
//   layout = new QHBoxLayout(parent)
//   m = layout->contentsMargins()
//   按 flag 三档改四值(见头注):
//     (a) 两个位都 0 → top/4、bottom/4,负值先 +3 再 >>2
//     (b) 0x20=0、0x40!=0 → top/2,bottom 原值
//     (c) 0x20!=0 → 原样
//   然后 addWidget 依次加各件、row 装 layout,返回 row。
// 说明:三档分支是为了让同一控件在"紧凑/宽松/自定"三种工具栏密度下
//   都能对齐 —— 除以 4 而不是 2,是因为 margins 本身已经是双倍值。
QWidget *LabelActionFace::createWidget(QWidget *parent)
{
	auto *row = new QWidget(parent);
	auto *layout = new QHBoxLayout(parent);

	const QMargins m = layout->contentsMargins();
	int top = m.top();
	int bottom = m.bottom();

	if ((m_flags10 & 0x20) == 0) {
		if ((m_flags10 & 0x40) == 0) {
			top = (top < 0) ? (top + 3) / 4 : top / 4;       // 语料:负值 +3 后 >>2
			bottom = (bottom < 0) ? (bottom + 3) / 4 : bottom / 4;
		} else {
			top = top / 2;
		}
	}
	layout->setContentsMargins(m.left(), top, m.right(), bottom);

	if (row != nullptr)
		row->setLayout(layout);
	return row;
}
