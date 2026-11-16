// TriggerPageFace.cpp — 触发器页族共有面(批 341/342)
#include "TriggerPageFace.h"

#include <QFormLayout>
#include <QHBoxLayout>
#include <QStackedLayout>
#include <QTabBar>
#include <QTableView>

// FUN_006f1966(45B,0022.c:19239)ctor 真身
TriggerPageFace::TriggerPageFace(QWidget *parent)
	: QWidget(parent, Qt::WindowFlags(0)) // @006f1966
{
	// +0x10 副 vptr / +0x30 = 0(C++ 自洽承载)
}

// FUN_006f1994(417B,0022.c:19240)装配真身(全量):
//   @006f1994 overlay = operator_new(0xa0) + overlay_makeBusyWidget(overlay,1,0,0)
//     → +0x30;                                    制件 0xa0 未建模(cited 承接为 QWidget)
//   @006f19c6 connect(overlay, 信号 FUN_008fae78, this, 槽 FUN_00909092,
//     闭包 impl FUN_006f6d60(0x20,捕获 page), smeta 0119d620);
//   @006f1a5x connect(overlay, 信号 FUN_008faeac(bool), this,
//     闭包 impl FUN_006f2be6(0x18,捕获 page), smeta 0119d620);
//   @006f1ae8 layout = operator_new(0x20) QHBoxLayout;
//   @006f1b05 QLayout::setContentsMargins(QMargins 全零 —— asm 0x6f1aed 两处 movq $0);
//   @006f1b0f QBoxLayout::addStretch(0);
//   @006f1b1e QBoxLayout::addWidget(overlay, 0, Qt::Alignment(0));
//   @006f1b23 return layout(语料无 setLayout)。
QHBoxLayout *TriggerPageFace::assembleBusyOverlay()
{
	// overlay_makeBusyWidget(0xa0, 1, 0, 0)@006f1994 — 遮罩件未建模,
	// 以裸 QWidget 承接占位(cited:样式/动画腿来自 overlay_makeBusyWidget)
	m_busy30 = new QWidget(this);

	// 两路 connect(信号 FUN_008fae78 / FUN_008faeac,闭包槽)@006f19c6/@006f1a5x
	// — 信号地址无 Qt 元对象名可引,cited(行为面已在 onBusyStateChanged 转写)。

	auto *lay = new QHBoxLayout;                 // @006f1ae8(0x20)
	lay->setContentsMargins(0, 0, 0, 0);         // @006f1b05
	lay->addStretch(0);                          // @006f1b0f
	lay->addWidget(m_busy30, 0, Qt::Alignment()); // @006f1b1e
	return lay;                                  // @006f1b23
}

// FUN_006f2be6(395B,0022.c:19952)遮罩信号槽真身:
//   入口 = QSlotObjectBase::impl(which):which==0 → delete 闭包(0x18);
//   which==1 → Call 体。
//   @006f2c08 v = *(bool*)(args[1])(信号唯一 bool 参,args[0] 为返回值槽);
//   @006f2c17 parent = *(闭包+0x10)(= page,捕获);
//   @006f2c50 qt_qFindChildren_helper(page, "", QWidget::smeta, 递归);
//   @006f2cb2 逐项 __dynamic_cast(w, QWidget::typeinfo, 0x1195cf0)
//     (0x1195cf0 = 本二进制内 QTableView 派生类 typeinfo);
//   @006f2cdd qt_qFindChild_helper(tv, "", 0x1194e40) 非空才动作;
//   @006f2cf9 v ? @006f2d05 selectRow(asm xor esi,esi → 0) : @006f2d46 clearSelection;
//   @006f2d0e w != *(page+0x30)(= 遮罩) → @006f2d1b setEnabled(v)(esi = v)。
void TriggerPageFace::onBusyStateChanged(bool v)
{
	const QList<QWidget *> ws = findChildren<QWidget *>(); // @006f2c50 递归
	for (QWidget *w : ws) {
		if (auto *tv = dynamic_cast<QTableView *>(w)) { // @006f2cb2 类型 0x1195cf0
			if (tv->findChild<QObject *>() != nullptr) { // @006f2cdd smeta 0x1194e40
				if (v)
					tv->selectRow(0); // @006f2d05(esi=0)
				else
					tv->clearSelection(); // @006f2d46
			}
		}
		if (w != m_busy30) // @006f2d0e 遮罩自身不参与启停
			w->setEnabled(v); // @006f2d1b
	}
}

// FUN_006fde04(210B,0022.c:26743)ConnectionTriggerPage 装配真身(结构段):
//   @006fde23 form = operator_new(0x20) + QFormLayout(父 0);
//   @006fde3d w = operator_new(0x78) + FUN_006fdcde(w, *(int*)(page+0x38), 0)
//     → +0x40(TriggerActionWidget,dtor 实测尺寸 0x78 一致);
//   @006fde5x QLayout::setContentsMargins(全零,Margins 由 Ghidra 折叠);
//   @006fde6x FUN_006f1994(page) —— 遮罩装配(本类 assembleBusyOverlay);
//   @006fde7x form->addRow(子件);form->addRow(第二行,Ghidra 折叠);
//   @006fdex  setLayout(form);setFocusProxy(page)。
void TriggerPageFace::assembleConnectionPage(int kind)
{
	auto *form = new QFormLayout;                  // @006fde23(0x20,父 0)
	m_action40 = new QWidget(this);                // @006fde3d 0x78 — cited(FUN_006fdcde 件未建模)
	Q_UNUSED(kind);                                // +0x38 = kind(FUN_006fdf10)
	form->setContentsMargins(0, 0, 0, 0);          // @006fde5x(全零)
	assembleBusyOverlay();                         // @006fde6x(FUN_006f1994)
	form->addRow(m_action40);                      // @006fde7x
	setLayout(form);                               // @006fdex
	setFocusProxy(this);                           // @006fdex
}

// FUN_006fdf10(281B,0022.c:26774)ConnectionTriggerPage ctor(1-4 共用):
//   FUN_006f1966(base)→ 自写 vtable ConnectionTriggerPage + 副 vptr 0118c100 →
//   +0x38 = kind → 标题按 kind 取 tr(1..4)否则 ascii(0xcb99b6,非串面 cited)→
//   setWindowTitle → 装配 FUN_006fde04。
static QString connTriggerTitle(int kind)
{
	switch (kind) {
	case 1: return QStringLiteral("&After connection");      // 0xc9fe89
	case 2: return QStringLiteral("&After disconnection");   // 0xc9fe9b
	case 3: return QStringLiteral("&Before connection");     // 0xc9feb0
	case 4: return QStringLiteral("&Before disconnection");  // 0xc9fec3
	default: return QString();                               // @0xcb99b6(cited 非串面)
	}
}

// 006f440e 逐 case 的标题(kind 5-12),地址见表:
static QString actionPageTitle(int kind)
{
	switch (kind) {
	case 5:  return QStringLiteral("&Custom Link");     // 0xc9fb21
	case 6:  return QStringLiteral("&Custom Menu");     // 0xc9fb2e
	case 8:  return QStringLiteral("&Highlight Text");  // 0xc9fb3b
	case 9:  return QStringLiteral("&Play Sound");      // 0xc9fb4b
	case 10: return QStringLiteral("Run &Command");     // 0xc9fb57
	case 11: return QStringLiteral("&Send Text");       // 0xc9fb64
	case 12: return QStringLiteral("&Show Tooltip");    // 0xc9fb6f
	default: return QString();
	}
}

// 006f440e 建页(switch 腿):kind 1-4 走 FUN_006fdf10(含装配);
// kind 5/6/8/9/10/11/12 各自 new + base ctor + 自写 vtable + tr 标题 +
// 各自装配腿(表见头注,均 cited —— 各页装配函数未逐句转写)。
QWidget *TriggerPageStackFace::createPage(int kind)
{
	TriggerPageFace *page = nullptr;
	switch (kind) {
	case 1: case 2: case 3: case 4:
		page = new TriggerPageFace;             // operator_new(0x48)
		page->setWindowTitle(connTriggerTitle(kind)); // FUN_006fdf10 tr 四串
		page->assembleConnectionPage(kind);     // FUN_006fde04
		return page;
	case 5: case 6: case 8: case 9: case 10: case 11: case 12:
		page = new TriggerPageFace;             // 0x58/0x60/0x40/0x48/0x50/0x68/0x60
		page->setWindowTitle(actionPageTitle(kind)); // 006f440e 逐 case tr
		// 各页装配腿(FUN_00703d3e / 00703fb0+006f79ec / 006f7c3c /
		//   00704340+006f7ea6 / 006fe290 / dialog_buildSpinForm /
		//   00703ab0)— cited。
		return page;
	default:
		return nullptr;                         // 语料无 case → caseD_0 直返
	}
}

// FUN_006f440e(1804B)页栈建页真身:
//   @006f44xx 命中 +0x88(QMap<int,page*>)→ 复用(pQVar6 = 节点+0x20);
//   未命中 → 建页 → 插表(createNode 0x28,键 @+0x18,值 @+0x20)→
//   QStackedLayout::addWidget(+0x40, page)(@006f4a78,实参 Ghidra 折叠);
//   合流:@006f4548 windowTitle(@006f453e tabBar = +0x30)→
//   @006f4555 setTabText(asm esi=0 → 恒第 0 页)→
//   @006f456a FUN_006f1b5a(page, state):page+0x30 非空 → FUN_0056672a(
//     page+0x30, state, 0, 1)(179B 自定义可切换件置态;param_4!=0 发
//     信号 FUN_008faeac(件, 态))— cited(该类未建模);
//   @006f4579 页虚槽 +0x1a0(基类 = __cxa_pure_virtual@0xbec350,各页覆写)— cited;
//   @006f4586 QStackedLayout::setCurrentWidget(+0x40, page)。
QWidget *TriggerPageStackFace::showPage(int kind, bool state, void *param4)
{
	QWidget *page = m_pages88.value(kind, nullptr); // +0x88 查
	if (page == nullptr) {
		page = createPage(kind);
		if (page == nullptr)
			return nullptr;                 // default → caseD_0 直返
		m_pages88.insert(kind, page);       // createNode(0x28)
		if (m_stack40)
			m_stack40->addWidget(page);     // @006f4a78
	}
	if (m_tabBar30)
		m_tabBar30->setTabText(0, page->windowTitle()); // @006f4555(esi=0)
	// FUN_006f1b5a(page, state)@006f456a — cited(FUN_0056672a 面)
	Q_UNUSED(state);
	// (**(*page+0x1a0))(page, param4)@006f4579 — 基类纯虚槽,各页覆写,cited
	Q_UNUSED(param4);
	if (m_stack40)
		m_stack40->setCurrentWidget(page);  // @006f4586
	return page;
}
