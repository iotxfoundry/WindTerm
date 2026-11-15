// KitDockFace.cpp — 语料 KitDock 两段转写(批 207)
#include <QEvent>
#include <QRect>
#include <QSplitter>
#include <QTimer>
#include <QToolButton>
#include <QVBoxLayout>

#include "Actions/KitDockFace.h"
#include "Actions/KitWindowAssemblyFace.h"
#include "Actions/KitWindowFace.h"
#include "Actions/TabGroup.h"
#include "Actions/MuxPaneView.h"
#include "Actions/ThemeIcons.h"

// FUN_008b81b0(109B,0027.c:75478)ctor:
//   QWidget::QWidget(this,param_3,0)@008b81b8;+0x38 = param_2 @008b81c8;
//   +0x39 = 0 @008b81d0;+0x3c = 0;+0x44 = -1;+0x4c = -1 @008b81d8-1f4;
//   setFocusPolicy(0)@008b8215;s_ExpandButton_8b7dd4(this);FUN_008b7f60(this)。
KitDockFace::KitDockFace(bool withExpand, QWidget *parent)
	: QWidget(parent, Qt::WindowFlags(0))  // @008b81b8(param_3 = parent)
	, m_withExpand(withExpand)             // @008b81c8(+0x38,bool)
	, m_f39(false)                        // @008b81d0(+0x39)
{
	setFocusPolicy(Qt::NoFocus); // @008b8215(esi=0)
	assembleChildren();           // s_ExpandButton_8b7dd4 @008b821x(真身,批 212)
	wireTabGroup(m_tabs);         // FUN_008b7f60 @008b821x(真身,批 211)
}

// s_ExpandButton_8b7dd4(371B,0027.c:75331)子件装配真身(函数名取自其
//   首个被调函数,实际语义 = KitDock 装配):
//   TabGroup(0xa8)@008b7df1(s_TabGroup_5af896,tabs parent=0)→
//   +0x30 写回 → setObjectName("PaneGroup")@008b7e2c →
//   +0x38 非空 → createButton("ExpandButton",1)@008b7e6x →
//   createButton("ConfigButton",1) → createButton("CloseButton",1) →
//   QVBoxLayout(0x20)@008b7e98 → setContentsMargins(0)/setSpacing(0)
//   (asm 0x8b7eb4/0x8b7ebe 实证)→ addWidget(tabs)@008b7ece →
//   addWidget(tabs->stack())(FUN_005ab6e8)@008b7f0x → setLayout @008b7f3x。
void KitDockFace::assembleChildren()
{
	m_tabs = new TabGroup(nullptr);              // @008b7df1
	m_tabs->setObjectName(QStringLiteral("PaneGroup")); // @008b7e2c
	if (m_withExpand)                            // @008b7e5x(+0x38 门)
		m_tabs->createButton(QStringLiteral("ExpandButton"), true);
	m_tabs->createButton(QStringLiteral("ConfigButton"), true); // @008b7e8x
	m_tabs->createButton(QStringLiteral("CloseButton"), true);  // @008b7e9x
	auto *box = new QVBoxLayout();               // @008b7e98
	box->setContentsMargins(0, 0, 0, 0); // @008b7eb4(QMargins 两半清零实证)
	box->setSpacing(0);                  // @008b7ebe(esi=0)
	box->addWidget(m_tabs);              // @008b7ece(addWidget(w,0,0) 实证)
	box->addWidget(m_tabs->stack());     // @008b7ee6(FUN_005ab6e8,同样 0/0)
	setLayout(box);                              // @008b7f3x
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
					kit->refreshAfterDockChange(); // 008cb0c0 @008b8738
					return;
				}
			}
		}
	}
	deleteLater(); // @008b8718
	if (KitWindowFace *kit = kitWindowAncestor(this)) // @008b8730
		kit->refreshAfterDockChange();                // 008cb0c0 @008b8738
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
		emitExpandRequested(expanding); // 0091a7d8
}

// s_ExpandButton_5ab32a(584B,0018.c:25117)真身:
//   btn = findChild<QToolButton>("ExpandButton",递归=1)@005ab37e,空 → 返;
//   图标名 expanded ? "king::expand" : "king::shrink"@005ab3b0
//   (0xc8b03a/0xc8aff4 实读)→ theme_icon_load_svg(app,名,"")@005ab3fe
//   → setIcon@005ab405;tooltip expanded ? tr("Shrink") : tr("Expand")
//   (0xc8b041/0xc8afe8 实读)@005ab45e/@005ab514 → setToolTip@005ab47a;
//   setProperty("expanded", QVariant(expanded))@005ab4b6。
void KitDockFace::updateExpandButton(bool expanded)
{
	if (m_tabs == nullptr)
		return;
	QToolButton *btn = m_tabs->findChild<QToolButton *>(
	    QStringLiteral("ExpandButton")); // @005ab37e(递归=1)
	if (btn == nullptr)
		return;
	const QString iconName = expanded ? QStringLiteral("king::expand")
	                                  : QStringLiteral("king::shrink"); // @005ab3b0
	btn->setIcon(ThemeIcons::loadSvg(iconName, QString())); // @005ab3fe-405
	btn->setToolTip(expanded ? tr("Shrink") : tr("Expand")); // @005ab45e/0x514
	btn->setProperty("expanded", QVariant(expanded));        // @005ab4b6
}

// 008b9092(375B,0027.c:76287)切分页真身(结构段):
//   p = parentWidget(this) → 须 cast QSplitter,否则 0 @008b9092-а0;
//   index = QSplitter::indexOf(this)@008b90xx;
//   withExpand = *(byte*)(this+0x38)(= m_withExpand,与批 216 勘正一致);
//   kit = 008b8694(this);dock = 89d860(kit, withExpand)@008b90xx;
//   splitter->insertWidget(index+1, dock)@008b90xx;
//   随后:count/orientation → 每格尺寸 = (extent+1)/count
//   (d+0x14/0x18/0x1c/0x20 rect 面,私有 → cited)→ 尺寸表
//   (FUN_0064a7a8/FUN_008b9590)→ setSizes — cited 整段未落。
void KitDockFace::splitPane()
{
	auto *splitter = dynamic_cast<QSplitter *>(parentWidget()); // @008b9092
	if (splitter == nullptr)
		return;
	const int index = splitter->indexOf(this); // @008b90xx
	const bool withExpand = m_withExpand;      // +0x38
	KitWindowFace *kit = kitWindowAncestor(this); // 008b8694
	KitDockFace *dock = kitCreateDock(withExpand, kit); // 89d860 @008b90xx
	if (dock == nullptr)
		return;
	splitter->insertWidget(index + 1, dock); // @008b90xx
	// 尺寸平分腿 @008b910x-921x:
	//   count = sp->count();orientation == Qt::Horizontal(1)→ d+0x1c-d+0x14
	//   (= width),否则 d+0x20-d+0x18(= height);
	//   cell = (extent + 1) / count;cell < 2 → 1;
	//   FUN_0064a7a8(&table, count, &cell)(表填充)+ FUN_008b9590 展开为
	//   int 表 → setSizes。(两个表助手以 QList<int> 直填等价。)
	const int count = splitter->count();
	const int extent = (splitter->orientation() == Qt::Horizontal)
	                       ? splitter->width()
	                       : splitter->height();
	int cell = (extent + 1) / count;
	if (cell < 2)
		cell = 1;
	QList<int> sizes;
	for (int i = 0; i < count; ++i)
		sizes.append(cell);
	splitter->setSizes(sizes);
}

// dock_toggleFloat(866B)真身(asm/反编译双读):
//   @008b8ce6 if (+0x39 == 新值) return;
//   归位(!floating):slot = 008ca096(kit,+0x4c)@008b8d0x;非空 →
//     记录矩形 → setWindowFlags(0) → insertWidget(+0x50) → show;
//   浮出:父 cast QSplitter 失败 → 整腿跳过;否则:
//     @008b8dxx 若 (+0x44 < +0x3c || +0x48 < +0x40) → 重算矩形;
//     +0x4c = 008ca0b8(kit, sp);+0x50 = sp->indexOf(this);
//     若 sp->count()==1 且 sp 父 cast QSplitter(gp)成功:
//       sizes = sp->sizes();gi = gp->indexOf(sp);
//       gi==0 → sizes[1]+=sizes[0];否则 sizes[gi-1]+=sizes[gi];
//       sizes[gi]=0;gp->setSizes(sizes)@008b8e16-9042;
//     setParent(0)(实参丢,浮窗无父)@008b90xx;
//     setWindowFlags(d->flags | 1)(Qt::Window)@008b90xx;
//     show();QTimer::singleShot(0,this,FUN_008b7cdb)@008b90xx;
//   尾:+0x39 = 新值 → 0091a80c(this,新值)(信号 idx1)。
void KitDockFace::setFloating(bool floating)
{
	if (m_f39 == floating) // @008b8ce6
		return;
	if (!floating) {
		KitWindowFace *kit = kitWindowAncestor(this);
		QSplitter *slot = kit != nullptr ? kit->kitSlotSplitter(m_slot4c) : nullptr;
		if (slot != nullptr) {
			const QRect g(mapToGlobal(QPoint(0, 0)), size());
			m_left3c = g.left();      // +0x3c
			m_top40 = g.top();        // +0x40
			m_right44 = g.right();    // +0x44 = x + (right-left)
			m_bottom48 = g.bottom();  // +0x48
			setWindowFlags(Qt::Widget); // 语料 setWindowFlags(0)
			slot->insertWidget(m_splitIndex50, this);
			show();
		}
	} else {
		auto *sp = dynamic_cast<QSplitter *>(parentWidget());
		if (sp != nullptr) {
			if (m_right44 < m_left3c || m_bottom48 < m_top40) {
				const QRect g(mapToGlobal(QPoint(0, 0)), size());
				m_left3c = g.left();
				m_top40 = g.top();
				m_right44 = g.right();
				m_bottom48 = g.bottom();
			}
			KitWindowFace *kit = kitWindowAncestor(this);
			if (kit != nullptr)
				m_slot4c = kit->kitSlotIdOf(sp); // 008ca0b8
			m_splitIndex50 = sp->indexOf(this);
			if (sp->count() == 1) {
				if (auto *gp = dynamic_cast<QSplitter *>(sp->parentWidget())) {
					QList<int> sizes = sp->sizes();
					const int gi = gp->indexOf(sp);
					if (gi == 0)
						sizes[1] = sizes[1] + sizes[0];
					else if (gi > 0)
						sizes[gi - 1] = sizes[gi - 1] + sizes[gi];
					if (gi >= 0 && gi < sizes.size())
						sizes[gi] = 0;
					gp->setSizes(sizes);
				}
			}
			setParent(nullptr); // 语料实参 Ghidra 丢(浮窗 = 无父)
			setWindowFlags(windowFlags() | Qt::Window);
			show();
			// QTimer::singleShot(0, this, FUN_008b7cdb)@008b90xx —
			//   闭包体(45B)= setGeometry(闭包携带 rect)(QRect::setGeometry
			//   入参面);rect = 本类 +0x3c..+0x48 四边。
			QTimer::singleShot(0, this, [this]() {
				setGeometry(QRect(QPoint(m_left3c, m_top40),
				                  QPoint(m_right44, m_bottom48)));
			});
		}
	}
	m_f39 = floating;                  // +0x39 写
	emitFloatingChanged(floating);     // 0091a80c(信号 idx1)
}

// 008b9050(66B,0027.c:76265)changeEvent 真身:
//   @008b9050 *(short*)(event+0x10) != 0x69(QEvent::WindowStateChange)→ 返;
//   @008b905a windowState() & 1(WindowMinimized)== 0 → 返;
//   hide() → setWindowState(0) → show() → dock_toggleFloat(this,0)。
void KitDockFace::changeEvent(QEvent *event)
{
	if (event == nullptr)
		return;
	if (event->type() != QEvent::WindowStateChange) // 0x69
		return;
	if ((windowState() & Qt::WindowMinimized) == 0) // & 1
		return;
	hide();
	setWindowState(Qt::WindowNoState); // 0
	show();
	setFloating(false); // dock_toggleFloat(this, 0) — 归位
}

// FUN_008b8be4(125B,0027.c:76070)真身:
//   @008b8be4 if ((*(byte*)(*(this+0x28)+9) & 0x80) == 0) return 0;
//     语料直读 QWidget d+9 bit 0x80(私有位,疑 WA_WState_Hidden)——
//     本面以 isHidden() 承接(cited 等价,待核)。
//   @008b8bex 父空 → 1;父 cast QSplitter 失败 → 1;
//   @008b8bfx kit = 祖先;id = kitSlotIdOf(kit, sp);
//     return kitSlotVisible(kit, id)(008ca0de)。
bool KitDockFace::isSlotVisible() const
{
	if (!isHidden()) // 语料 d+9 & 0x80 == 0 → 0(cited 等价面)
		return false;
	QWidget *p = parentWidget();
	if (p == nullptr)
		return true;
	auto *sp = dynamic_cast<QSplitter *>(p);
	if (sp == nullptr)
		return true;
	auto *kit = kitWindowAncestor(const_cast<KitDockFace *>(this)); // 008b8694
	if (kit == nullptr)
		return true;
	const int id = kit->kitSlotIdOf(sp); // 008ca0b8
	return kit->kitSlotVisible(id);      // 008ca0de
}

// FUN_008d972e(53B)+FUN_008d9764(33B)内层页真身:
//   @008d972e w = FUN_005ab316(*(this+0x30))(= TabGroup::currentWidget)
//     → cast 011ac070(页类);空 → 0;
//   @008d9764 v = 008d972e(this);非空 → 008dfe24(v)(195B:focusWidget 上溯
//     cast 011abb90 / 011abe10(+0x78/+0x80 缓存)→ 内层视图,cited)。
QWidget *KitDockFace::innerPage()
{
	if (m_tabs == nullptr)
		return nullptr;
	QWidget *w = m_tabs->currentWidget(); // @008d972e(FUN_005ab316)
	if (w == nullptr)
		return nullptr;
	// cast 011ac070 面(页类未定位 → 以 QWidget 承接)+ 008dfe24(v) 焦点
	//   收敛腿 — cited(195B 体未转写)。
	return w;
}

// FUN_0091a7d8(52B)/FUN_0091a80c(55B)真身:
//   QMetaObject::activate(this, smo 011ab100, 0/1, args{bool}).
void KitDockFace::emitExpandRequested(bool expanding)
{
	emit expandRequested(expanding); // idx0
}

void KitDockFace::emitFloatingChanged(bool floating)
{
	emit floatingChanged(floating); // idx1
}
