// CloseButtonActionFace.cpp — 带关闭按钮的工具栏行动作。

#include "Actions/CloseButtonActionFace.h"

#include <QHBoxLayout>
#include <QWidget>

CloseButtonActionFace::CloseButtonActionFace(QObject *parent)
    : QWidgetAction(parent)
{
}

// vt12 0x005b2c60(222B)createWidget 真身。逐句:
//   layout = new QHBoxLayout(+0x10 行容器)
//   **取一次 contentsMargins,把左右边距各折半**(语料两次 contentsMargins
//   读同一对象、两次 /2,分别落在 left 与 right 上)
//   setContentsMargins(折半后四值)
//   addWidget(+0x18, 带 out 边距 iVar1/iVar2)  ← 首个控件带额外边距
//   addWidget(+0x20) / addWidget(+0x28)
//   返回 +0x10
QWidget *CloseButtonActionFace::createWidget(QWidget *parent)
{
	Q_UNUSED(parent);
	auto *layout = new QHBoxLayout(m_row10);
	const QMargins m = layout->contentsMargins();
	layout->setContentsMargins(m.left() / 2, m.top(), m.right() / 2, m.bottom());

	if (m_w18 != nullptr)
		layout->addWidget(m_w18, 0, 0);
	if (m_w20 != nullptr)
		layout->addWidget(m_w20, 0, 0);
	if (m_close28 != nullptr)
		layout->addWidget(m_close28, 0, 0);
	return m_row10;
}
