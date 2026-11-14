#include "SplitterGroup.h"

#include <QList>
#include <QMargins>
#include <QSplitter>
#include <QStackedLayout>

// fwd: 静态函数集中前向声明区(AGENTS.md 坑 3)
static void focusPaneDeep(QWidget *page); // = FUN_005a236c 壳(体在文件尾)

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
	m_f38->setSpacing(0);                           // 005a22c7(ESI=0;import 实证
	                                                //   _ZN7QLayout10setSpacingEi@4c2a50;
	                                                //   批 148 升真身,原 cited 系 Ghidra 折叠)
	m_f38->setContentsMargins(QMargins(0, 0, 0, 0)); // 005a22cb-df([RSP]=0,[RSP+8]=0
	                                                 //   = QMargins(0,0,0,0);import 实证
	                                                 //   _ZN7QLayout18setContentsMarginsERK8QMargins;
	                                                 //   批 148 升真身)
	m_f38->addWidget(m_f30);                        // QStackedLayout::addWidget @005a22e8
	setLayout(m_f38);                               // QWidget::setLayout @005a22f2
}

// === removePage(QWidget*) ===
// 转写 FUN_005a29e6(0018:18817,690B,asm 005a29e6-005a2c9b 全读;批 148)。
// 逐段(asm 直读,DECOMP 布局引擎底座 Qt 委托 — 本函数是行为转写非外库边界):
//   page==0 → 直返 @005a29e6-9;
//   this->isAncestorOf(page) 门 @005a2a03(4c2a40);
//   sp = dynamic_cast<QSplitter *>(page->parentWidget()) @005a2a21-36
//     (011b8958 QSplitter typeinfo;[page+8]+0x10 = d->parent 直读同型);
//   idx = sp->indexOf(page) @005a2a48(4bc470);
//   sizes = sp->sizes() @005a2a5b(4bbb30;R13=&sizes);
//   page->close() 门 @005a2a63(4c1d80;失败 → sizes 析构 @005a2b1a 直返);
//   page->hide() @005a2a73(4bbc70);
//   page->setParent(nullptr) @005a2a7d(4be340,ESI=0);
//   delete page @005a2a88([vtable+0x20] = deleting dtor D0 槽;Qt5.15 本建
//     vtable:vt[0]=metaObject/[1]=qt_metacast/[2]=qt_metacall/[3]=D1/[4]=D0
//     ——libQt5Widgets _ZTV7QWidget 实证;批 148 勘定 vt+0x20=D0);
//   sp->count()==0 → 递归 removePage(this, sp) @005a2b2f(空父 splitter
//     deleteLater 自卷);
//   ==1 → gs = dynamic_cast<QSplitter *>(sp->parentWidget()) @005a2aac-ce:
//     gs 空 → FUN_005a236c(this, sp) @005a2bab;
//     gs 非 → w = sp->widget(0) @005a2ae4(4bca30);gs->replaceWidget(
//       gs->indexOf(sp), w) @005a2af2-ff;sp->deleteLater() @005a2b07
//       (4bec60);FUN_005a236c(this, w) @005a2b0c;
//   ≥2 → hw = sp->handleWidth() @005a2b3c(4ba260);
//     idx+1 < sizes.size() 腿 @005a2b56-bbb:R15D(hw) += sizes[idx]
//       (detach 5a2170 挂账照抄);sizes[idx+1] += R15D;w = sp->widget(idx)
//       @005a2bf1;
//     否则 idx>0 腿 @005a2b5d-fe:R15D(hw)+= sizes[idx];sizes[idx-1] +=
//       R15D;w = sp->widget(idx) @005a2c33;
//     否则 w = 0 @005a2b63;
//     idx∈[0,size) 时 sizes.removeAt(idx) @005a2b85(4baab0
//     QListData::remove);setSizes 无条件 @005a2b96(4bbde0);尾
//     FUN_005a236c(this, w) @005a2ba1。
// 归辖:语料调用点 = MuxWindow thunk FUN_008e01b6(0028:27463,15B:
//   page!=0 → FUN_005a29e6(*(+0x70),page);live 调用链 FUN_008e01c6/
//   FUN_008de260 闭包/0084dd5a)——thunk 本身批 148 cited 不落(MuxWindow
//   闭包腿 S7 既有 cited 决定同面,不单发明 MuxWindow API)。
void SplitterGroup::removePage(QWidget *page)
{
	if (page == nullptr)                                   // 005a29e6 首卫
		return;
	if (!isAncestorOf(page))                               // 005a2a03(4c2a40)
		return;
	QSplitter *sp = dynamic_cast<QSplitter *>(page->parentWidget()); // 005a2a21-36
	if (sp == nullptr)                                     // 005a2a3c
		return;
	const int idx = sp->indexOf(page);                     // 005a2a48
	QList<int> sizes = sp->sizes();                        // 005a2a5b(R13)
	if (!page->close()) {                                  // 005a2a63(4c1d80)
		return;                                            // 005a2b1a(sizes 析构)
	}
	page->hide();                                          // 005a2a73(4bbc70)
	page->setParent(nullptr);                              // 005a2a7d(ESI=0)
	delete page;                                           // 005a2a88(vt+0x20 = D0;
	                                                       //   vt 布局实证见头注)
	if (sp->count() == 0) {                                // 005a2a93(4c23b0)
		removePage(sp);                                    // 005a2b2f 递归自卷
		return;                                            // 005a2b3a→2b17
	}
	if (sp->count() == 1) {                                // 005a2aa3
		QSplitter *gs = dynamic_cast<QSplitter *>(sp->parentWidget()); // 005a2aac-ce
		if (gs == nullptr) {                               // 005a2ad9
			focusPaneDeep(sp);                             // 005a2bab(5a236c)
			return;                                        // 005a2bb6
		}
		QWidget *w = sp->widget(0);                        // 005a2ae4(4bca30)
		gs->replaceWidget(gs->indexOf(sp), w);             // 005a2af2-ff
		sp->deleteLater();                                 // 005a2b07(4bec60)
		focusPaneDeep(w);                                  // 005a2b0c
		return;                                            // 005a2b17
	}
	const int hw = sp->handleWidth();                      // 005a2b3c(4ba260)
	QWidget *w = nullptr;                                  // 005a2b63(EBX=0 缺省)
	if (idx + 1 < sizes.size()) {                          // 005a2b56
		sizes[idx + 1] += hw + sizes[idx];                 // 005a2bbd-e6(R15D+=sizes[idx] 后加)
		w = sp->widget(idx);                               // 005a2bf1(4bca30)
	} else if (idx > 0) {                                  // 005a2b5d
		sizes[idx - 1] += hw + sizes[idx];                 // 005a2c0f-29
		w = sp->widget(idx);                               // 005a2c33
	}
	if (idx >= 0 && idx < sizes.size())                    // 005a2b75-b0(两界各半,
		sizes.removeAt(idx);                               //   4baab0 removeAt)
	sp->setSizes(sizes);                                   // 005a2b96(无条件,4bbde0)
	focusPaneDeep(w);                                      // 005a2ba1
}

// focusPaneDeep —— 语料 FUN_005a236c 的命名壳(toggleZoomPage 尾部已有
//   逐行直译体;本函数独立消费点在 removePage 三处 @005a2b0c/005a2bab/
//   005a2ba1。转写体与 toggleZoomPage 尾循环同源:page 空→直返;沿
//   dynamic_cast<QSplitter> 链 widget(0) 深潜至非 splitter 部件 →
//   setFocus(ActiveWindowFocusReason) @005a23af(原因 3))。
static void focusPaneDeep(QWidget *page)
{
	for (QWidget *w = page; w != nullptr;) {   // 005a239a-a5
		QSplitter *sp = dynamic_cast<QSplitter *>(w); // 005a23a5
		if (sp == nullptr) {
			w->setFocus(Qt::ActiveWindowFocusReason); // 005a23af-bb(原因 3)
			break;
		}
		w = sp->widget(0);                     // 005a2388-8d(空 → 直返)
	}
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
