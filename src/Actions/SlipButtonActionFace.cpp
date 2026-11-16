// SlipButtonActionFace.cpp — SlipButton 菜单行动作。

#include "Actions/SlipButtonActionFace.h"

#include <QHBoxLayout>
#include <QWidget>

SlipButtonActionFace::SlipButtonActionFace(QObject *parent)
    : QWidgetAction(parent)
{
}

// 0x006aa370(279B)createWidget 真身。逐句:
//   ① 行容器(+0x28)setParent(parent)  ← 实参为传入的 parent
//   ② layout = new QHBoxLayout(parent)
//   ③ 取 layout->contentsMargins(),把左右边距(zero)与上下边距折半:
//        top/2、left、right、bottom/2 —— 语料 CONCAT44(top/2, left) /
//        CONCAT44(bottom/2, right),字面保留
//   ④ +0x10 非 0 → addWidget(+0x10)
//   ⑤ addWidget(+0x18)  行文本
//   ⑥ addStretch()
//   ⑦ addWidget(+0x20)  右侧开关
//   ⑧ 行容器 setLayout(layout)
//   ⑨ 返回 QList<QWidget*>{ +0x28 }  ← qlist_appendDetach
QWidget *SlipButtonActionFace::createWidget(QWidget *parent)
{
	if (m_row28 != nullptr)
		m_row28->setParent(parent); // QWidget::setParent(*(param_2+0x28))

	auto *layout = new QHBoxLayout(parent);
	const QMargins m = layout->contentsMargins();
	layout->setContentsMargins(m.left(), m.top() / 2, m.right(), m.bottom() / 2);

	if (m_lead10 != nullptr)
		layout->addWidget(m_lead10, 0, 0);
	if (m_label18 != nullptr)
		layout->addWidget(m_label18, 0, 0);
	layout->addStretch();
	if (m_switch20 != nullptr)
		layout->addWidget(m_switch20, 0, 0);

	if (m_row28 != nullptr)
		m_row28->setLayout(layout);
	return m_row28; // 语料返回 QList{+0x28};单元素即 defaultWidget
}

// dtor 0x006a8cd6(19B)真身:
//   vptr = &PTR_metaObject_01184688(QWidgetAction 族元对象);QWidgetAction::~QWidgetAction
// deleting 0x006a8cea(37B):同上 + operator_delete(this, 0x30)。
