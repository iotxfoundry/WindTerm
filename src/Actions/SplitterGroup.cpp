#include "SplitterGroup.h"

#include <QSplitter>
#include <QStackedLayout>

// === SplitterGroup(QWidget*) ===
// 转写 FUN_005a2314(0018:18539,79B):QWidget::QWidget(parent,flags0)→
//   +0x30/+0x38/+0x40 ← 0 → 尾调 FUN_005a2266(装配)。
SplitterGroup::SplitterGroup(QWidget *parent)
	: QWidget(parent)
	, m_f30(nullptr)
	, m_f38(nullptr)
	, m_f40(0)
{
	// *(this+0x30)=*(this+0x38)=*(this+0x40)=0 @005a2333-2347(经初始化列表)
	// FUN_005a2266 @005a2357(带 catch 005a2363)
	// === 装配 FUN_005a2266(0018:18513,158B)===
	m_f30 = new QSplitter(nullptr);                 // operator_new(0x30)@005a2281
	m_f38 = new QStackedLayout;                     // operator_new(0x20)@005a229a(无 parent)
	m_f30->setOrientation(Qt::Orientation(2));      // 005a22b8(语料常量 2 = Qt::Vertical)
	m_f30->setChildrenCollapsible(false);           // 005a22c2(SUB81(...,0))
	// QLayout::setSpacing(实参 Ghidra 折叠)— cited — wave-2
	// QLayout::setContentsMargins(实参 Ghidra 折叠)— cited — wave-2
	m_f38->addWidget(m_f30);                        // QStackedLayout::addWidget @005a22e8
	setLayout(m_f38);                               // QWidget::setLayout @005a22f2
}

// === addPage(QWidget*) ===
// 转写 FUN_005a225c(0018:18503,9B)= QSplitter::addWidget(+0x30) 透传。
void SplitterGroup::addPage(QWidget *w)
{
	m_f30->addWidget(w); // 005a225f
}
