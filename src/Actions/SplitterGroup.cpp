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

// === toggleZoomPage(QWidget*,bool) ===
// 转写 FUN_005a2518(0018:18651,585B,asm 005a2518-005a2769 全读;Ghidra
//   参 register 丢失已逐槽勘补):
//   param_2(page)==0 → 直返 @005a2518(无 rollback);
//   段头:functor {this, FUN_005a2251(setUpdatesEnabled(false))} 起手,尾
//   FUN_005a2244(setUpdatesEnabled(true))(QScopedValueRollback 同构,
//   直译调用序 @005a25b5/005a2602 尾)。中间 functor 槽(005a21f0/005a221a
//   = Qt 值语义 meta 调用器)无业务行为。
//   ph = +0x40(占位页槽)@005a25ea。
//   zoom 腿(param_3!=0)@005a25f3:
//     ph!=0 → 已在 zoom → 仅尾(见下);
//     ph==0 → page->parentWidget() cast<QSplitter> @005a26e5-00(011b8958
//       QSplitter typeinfo)非空:
//       idx = splitter->indexOf(page) @005a270c(_ZNK9QSplitter7indexOfE);
//       new QWidget(0x30, 无 parent) @005a2714-28(_ZN7QWidgetC1EPS_i flags0)
//         → 存 +0x40 @005a272d;
//       splitter->replaceWidget(idx, ph) @005a273a;
//       (+0x38 stack)->addWidget(ph) @005a273f-46(_ZN14QStackedLayout9addWidgetE);
//       stack->setCurrentWidget(ph) @005a274b-52(4c1ae0 = setCurrentWidget)。
//   unzoom 腿(param_3==0)@005a264b:
//     ph==0 → 尾;
//     ph!=0 → parentWidget(ph) cast<QSplitter> @005a265d-6d 非空:
//       idx = splitter->indexOf(ph) @005a2680;
//       stack->removeWidget(page) @005a2687-8e(page 非本 stack 页 → Qt no-op,
//         语料原样调用照抄);
//       stack->setCurrentWidget(m_f30) @005a2693-9b(rsi=+0x30 splitter =
//         切回 splitter 页);
//       splitter->replaceWidget(idx, page) @005a26a0-a8(page 回 splitter);
//       page->setVisible(true) @005a26ad-b9(vtable +0x68 = setVisible 槽 13);
//       ph->deleteLater() @005a26bc-c0;+0x40 ← 0 @005a26c5。
//   尾(两腿汇合)@005a25fc:FUN_005a236c(this,page)(0018:18556,90B asm 全读:
//     page 为 QSplitter 时 widget(0) 深潜至非 splitter 部件 →
//     QWidget::setFocus(deep,3 = ActiveWindowFocusReason)@005a23af-4c1660)。
void SplitterGroup::toggleZoomPage(QWidget *page, bool zoom)
{
	if (page == nullptr)                       // 005a2518 首卫(无 rollback 直返)
		return;
	setUpdatesEnabled(false);                  // FUN_005a2251 @005a25b5
	QWidget *ph = m_f40;                       // 005a25ea
	if (zoom) {                                // 005a25ee/5f3
		if (ph == nullptr) {                   // 005a25f6(空才进)
			QSplitter *sp = dynamic_cast<QSplitter *>(page->parentWidget()); // 005a26e5-2700(011b8958)
			if (sp != nullptr) {               // 005a26fd-2700
				const int idx = sp->indexOf(page);       // 005a270c
				ph = new QWidget(nullptr);               // operator_new(0x30)+QWidget(0,0) @005a2714-28
				m_f40 = ph;                              // 005a272d
				sp->replaceWidget(idx, ph);              // 005a273a
				m_f38->addWidget(ph);                    // 005a273f-46
				m_f38->setCurrentWidget(ph);             // 005a274b-52
			}
		}
	} else if (ph != nullptr) {                // 005a264b-51
		QSplitter *sp = dynamic_cast<QSplitter *>(ph->parentWidget()); // 005a265d-6d
		if (sp != nullptr) {                   // 005a2675-8
			const int idx = sp->indexOf(ph);             // 005a2680
			m_f38->removeWidget(page);                   // 005a2687-8e(page 非 stack 页 → no-op,语料原样)
			m_f38->setCurrentWidget(m_f30);              // 005a2693-9b(切回 splitter 页)
			sp->replaceWidget(idx, page);                // 005a26a0-a8
			page->setVisible(true);                      // 005a26ad-b9(vt+0x68 = setVisible(1))
			ph->deleteLater();                           // 005a26bc-c0
			m_f40 = nullptr;                             // 005a26c5
		}
	}
	// FUN_005a236c(this,page)@005a25fc-602:page 为 QSplitter → widget(0) 深潜;
	//   非 splitter 件 → setFocus(ActiveWindowFocusReason)@005a23af。
	for (QWidget *w = page; w != nullptr;) {   // 005a239a-a5 循环照抄
		QSplitter *sp = dynamic_cast<QSplitter *>(w); // 005a23a5(QSplitter typeinfo)
		if (sp == nullptr) {
			w->setFocus(Qt::ActiveWindowFocusReason); // 005a23af-bb(原因 3)
			break;
		}
		w = sp->widget(0);                     // 005a2388-8d(4bca30 = QSplitter::widget;空 → 5a23c0 直返)
	}
	setUpdatesEnabled(true);                   // FUN_005a2244 @005a2607-61 尾撤防
}
