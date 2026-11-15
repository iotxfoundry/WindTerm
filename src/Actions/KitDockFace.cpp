// KitDockFace.cpp — 语料 KitDock 两段转写(批 207)
#include <QSplitter>

#include "Actions/KitDockFace.h"
#include "Actions/KitWindowAssemblyFace.h"
#include "Actions/TabGroup.h"

// FUN_008b81b0(109B,0027.c:75478)ctor:
//   QWidget::QWidget(this,param_3,0)@008b81b8;+0x38 = param_2 @008b81c8;
//   +0x39 = 0 @008b81d0;+0x3c = 0;+0x44 = -1;+0x4c = -1 @008b81d8-1f4;
//   setFocusPolicy(0)@008b8215;s_ExpandButton_8b7dd4(this);FUN_008b7f60(this)。
KitDockFace::KitDockFace(QWidget *slot38, QWidget *parent)
	: QWidget(parent, Qt::WindowFlags(0)) // @008b81b8(param_3 = parent)
	, m_f38(slot38)                       // @008b81c8(+0x38)
	, m_f39(false)                        // @008b81d0(+0x39)
{
	setFocusPolicy(Qt::NoFocus); // @008b8215(esi=0)
	// s_ExpandButton_8b7dd4(this)@008b821x + FUN_008b7f60(this)@008b821x
	//   — 子件装配面未转写,cited 不落(铁律 6:不造子件)。
}

// FUN_008b86e4(153B,0027.c:75642)收起行为:
//   if (+0x39 == 0) {
//     p = parentWidget(this);                                    // @008b86ea-f4
//     if (!p) goto tail;
//     sp = dynamic_cast<QSplitter *>(p);                          // @008b86fe
//     if (!sp) goto tail;
//     if (sp->count() < 2) {                                      // @008b8712
//       kitA = kitWindowAncestor(this); kitB = kitWindowAncestor(this);
//       id = kitB->kitSlotIdOf(sp);                               // 008ca0b8
//       kitA->kitSlotHide(id);                                    // 008ca168
//       goto tail;
//     }
//   }
//   deleteLater();                                                // @008b8718
// tail: kit = kitWindowAncestor(this); if (kit) FUN_008cb0c0(kit,3);
void KitDockFace::closeWithCollapse()
{
	if (!m_f39) { // @008b86ea(+0x39 == 0)
		QWidget *p = parentWidget(); // @008b86f4
		if (p != nullptr) {
			if (auto *sp = dynamic_cast<QSplitter *>(p)) { // @008b86fe
				if (sp->count() < 2) {                     // @008b8712
					KitWindowFace *kit = kitWindowAncestor(this); // 008b8694
					if (kit != nullptr) {
						const int id = kit->kitSlotIdOf(sp); // 008ca0b8
						kit->kitSlotHide(id);                // 008ca168
					}
					// 尾刷新腿 FUN_008cb0c0(kit,3)@008b8738 — cited
					//   (24B 包装:008cad6a 门 + 008cb0a0 体未转写)
					return;
				}
			}
		}
	}
	deleteLater(); // @008b8718
	// 尾:kit = kitWindowAncestor(this) @008b8730;非空 →
	//   FUN_008cb0c0(kit,3)@008b8738 — cited(同上)。
}

// FUN_008b7f60(591B,0027.c:75393)四路接线真身(信号为 TabGroup 索引面,
//   0119dea0 = TabGroup smeta;槽体两真身两 cited):
//   tabs = this+0x30;connect(tabActivated@FUN_008fb5ac → FUN_008b7d08)
//   connect(closeRequested@FUN_008fb584 → FUN_008b86e4)
//   connect(configRequested@FUN_008fb598 → s_ConfigButton_8b877e)
//   connect(expandRequested@FUN_008fb690 → FUN_008b7ca0)
void KitDockFace::wireTabGroup(TabGroup *tabs)
{
	if (tabs == nullptr)
		return;
	m_tabs = tabs; // +0x30
	connect(tabs, &TabGroup::tabActivated, this, &KitDockFace::onTabActivated);
	connect(tabs, &TabGroup::closeRequested, this, &KitDockFace::closeWithCollapse);
	// configRequested → s_ConfigButton_8b877e(150B:KitWindow 菜单组 "Dock"
	//   + toolButtonPopupMenu(owner+0x30,"ConfigButton",menu)@008b87df)
	//   — toolButtonPopupMenu(FUN_005ac790)锚点用 QToolButton 私有尺寸面,
	//   cited 不落接线。
	connect(tabs, &TabGroup::expandRequested, this, &KitDockFace::onExpandRequested);
}

// FUN_008b7d08(187B,0027.c:75296)真身:
//   w = FUN_005abbd0(tabs)(stackWidgetAt)→ cast 011ab690(KitPane)命中 →
//   setFocus(3)@008b7d5x → setWindowIcon(w->windowIcon())@008b7d6x →
//   setWindowTitle(w->windowTitle())@008b7d8x。
void KitDockFace::onTabActivated(int index)
{
	if (m_tabs == nullptr)
		return;
	QWidget *w = m_tabs->stackWidgetAt(index); // FUN_005abbd0
	if (w == nullptr)
		return;
	w->setFocus(Qt::OtherFocusReason); // 3 @008b7d5x
	setWindowIcon(w->windowIcon());    // @008b7d6x
	setWindowTitle(w->windowTitle());  // @008b7d8x
}

// FUN_008b7ca0(59B,0027.c:75252)真身:闭包体 — +0x39 == 0(非浮停)→
//   FUN_0091a7d8(this, arg)(自身信号 idx0)@008b7ca0;浮停时不转发。
void KitDockFace::onExpandRequested(bool expanding)
{
	if (!m_f39)
		emit expandRequested(expanding);
}
