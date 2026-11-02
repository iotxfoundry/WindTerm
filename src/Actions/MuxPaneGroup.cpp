#include "MuxPaneGroup.h"

#include "MuxPaneView.h"
#include "TabGroup.h"

#include <QVBoxLayout>
#include <QStackedWidget>
#include <QTabBar>

// === MuxPaneGroup(bool,QWidget*) ===
// 转写 s_MuxPaneGroup_8dece0(0028:25950,189B):
//   QWidget::QWidget(parent,flags0) → +0x30 ← param_2(expandable;
//   构造点实证 0026:29939 传 1)→ +0x38 ← 0 → setObjectName("MuxPaneGroup")
//   @008ded37-4c → s_tabbar_doubleClickAction_8de936(子件装配)→
//   FUN_008de5a6(六条接线)。
MuxPaneGroup::MuxPaneGroup(bool expandable, QWidget *parent)
	: QWidget(parent)
	, m_f30(expandable)   // param_1[0x30] = param_2 @008ded24
	, m_f38(nullptr)      // *(this+0x38) = 0 @008ded2a
{
	setObjectName(QStringLiteral("MuxPaneGroup")); // @008ded37-50
	attachChildWidgets();   // s_tabbar_doubleClickAction_8de936 @008ded6a-76
	connectGroupSignals();  // FUN_008de5a6 @008ded7c-88
}

// === attachChildWidgets() ===
// 转写 s_tabbar_doubleClickAction_8de936(0028:25835,874B):
//   new QVBoxLayout(无 parent)→ new TabGroup(this)→+0x38 →
//   global_setting_get("tabbar.hoverToSelect",默认 QVariant(0))toDouble →
//   thunk_FUN_005ad4a6(悬停表)→ TabGroup objectName "PaneGroup" →
//   setFocusPolicy(0) → FUN_005ac652/005ab89c/005ab88a/005ac522 四连 →
//   setProperty("tabbar.doubleClickAction","RenameTab") → 按钮分叉
//   (+0x30==0:TabAdd/TabList/Config;否则 Config/Close(0))→
//   setContentsMargins/setSpacing(cited)→ addWidget(TabGroup)→
//   addWidget(FUN_005ab6e8 = TabGroup+0x60 stack)→ setLayout。
void MuxPaneGroup::attachChildWidgets()
{
	QVBoxLayout *vbox = new QVBoxLayout;   // operator_new(0x20)@008de948(无 parent,尾 setLayout 收养)

	m_f38 = new TabGroup(this);            // operator_new(0xa8)+s_TabGroup_5af896 @008de96f-73
	                                       //   (parent=this;W3 定案笔记 §2/§8)
	// global_setting_get(app,"tabbar.hoverToSelect",QVariant(0))
	//   @008de9a6-008de9ca — cited — wave-2(配置装载面未入库);
	//   QVariant::toDouble 结果 = FUN_005ad4a6 第 1 参(悬停秒数),
	//   默认路径 = QVariant(0) → 0.0 → 表关。
	double hoverSeconds = 0.0;             // = 默认 QVariant(0);global_setting_get cited

	m_f38->setObjectName(QStringLiteral("PaneGroup")); // @008dea33-37
	m_f38->setFocusPolicy(Qt::FocusPolicy(0));         // NoFocus @008dea3d
	m_f38->setDocumentMode(false);                     // FUN_005ac652(this,0)@008dea45
	m_f38->setAutoHide(false);                         // FUN_005ab89c(this,0)@008dea4f
	m_f38->setTabShapeMode(0);                         // FUN_005ab88a(this,0)@008dea59
	m_f38->setUsesScrollButtons(false);                // FUN_005ac522(this,0)@008dea63
	// thunk_FUN_005ad4a6(qcoreapp,tabGroup)@008dea6d(第 1 参 = toDouble 值)
	m_f38->setHoverTimer(hoverSeconds);
	m_f38->setProperty("tabbar.doubleClickAction",
	                   QStringLiteral("RenameTab"));   // qmap_detach_copy_qvariant @008deaea-01

	if (m_f30 == false) {                              // param_1[0x30]==0 分支 @008deb3e
		m_f38->createButton(QStringLiteral("TabAddButton"), true);   // @008deb4c
		m_f38->createButton(QStringLiteral("TabListButton"), true);  // @008deb58
		m_f38->createButton(QStringLiteral("ConfigButton"), true);   // @008deb64
	} else {                                           // expandable 非 0
		m_f38->createButton(QStringLiteral("ConfigButton"), true);   // @008deb78
		m_f38->createButton(QStringLiteral("CloseButton"), false);   // @008deb84(param_3=0)
	}

	// QLayout::setContentsMargins / QBoxLayout::setSpacing(常量折叠)
	//   — cited — wave-2
	vbox->addWidget(m_f38);                     // QBoxLayout::addWidget @008deb9e
	vbox->addWidget(m_f38->stack());            // FUN_005ab6e8(+0x60)@008debaa
	setLayout(vbox);                            // QWidget::setLayout @008debb6
}

// === connectGroupSignals() ===
// 转写 FUN_008de5a6(0028:25740,912B):发送者一律 +0x38(TabGroup),
//   meta = PTR_staticMetaObject_0119dea0(= TabGroup);六条 connectImpl:
//   FUN_008fb584(sig7 closeRequested)→FUN_008dfa8c;
//   FUN_008fb598(sig8 configRequested)→s_MuxPaneGroup_8de2d4;
//   FUN_008fb5ac(sig0 tabActivated)→FUN_008defbc;
//   FUN_008fb55c(sig2 tabBlankRequested)→thunk_FUN_008df5f8;
//   FUN_008fb5e0(sig3 tabCloseRequested)→FUN_008dfa76;
//   FUN_008fb616(sig6 tabRenameRequested)→FUN_008df466。
void MuxPaneGroup::connectGroupSignals()
{
	TabGroup *g = m_f38;
	// 六条的 functor 008dfab0/008dfb20/008dfb90/008dfc00 = Qt connectImpl
	//   通用调用器(转 Qt::AutoConnection 语义等价,无自研行为)。
	connect(g, &TabGroup::closeRequested, this, &MuxPaneGroup::confirmCloseCurrentPane);        // @008de5b5
	connect(g, &TabGroup::configRequested, this, &MuxPaneGroup::showConfigMenu);                // @008de5d5
	connect(g, &TabGroup::tabActivated, this, &MuxPaneGroup::focusCurrentPane);                 // @008de5f5
	connect(g, &TabGroup::tabBlankRequested, this, &MuxPaneGroup::onTabBlankRequested);         // @008de615
	connect(g, &TabGroup::tabCloseRequested, this, &MuxPaneGroup::closeCurrentPane);            // @008de635
	connect(g, &TabGroup::tabRenameRequested, this, &MuxPaneGroup::renamePane);                 // @008de655
}

// === addTab(MuxPaneView*,bool) ===
// 转写 FUN_008de3e8(0028:25642,373B;this = MuxPaneGroup):
//   lVar1 = +0x38(TabGroup);非空 → blockSignals(true)→
//   FUN_005abf12(tabGroup,page,页+0x38 标题,QIcon(),空串)→
//   "Normal"(param_3!=0)/"Pinned"(==0)→ FUN_005aca9a → blockSignals(false)。
void MuxPaneGroup::addTab(MuxPaneView *page, bool normal)
{
	TabGroup *g = m_f38;                 // lVar1 @008de3f5
	if (g != nullptr)
		g->blockSignals(true);           // QObject::blockSignals @008de3fd(true)

	// FUN_005abf12 @008de455:标题 = 页对象 +0x38(MuxPaneView::m_title 槽,
	//   语料直读页内偏移);QIcon() 空;tooltip 空 QByteArray。
	const int idx = g->insertPageBack(page, page->title(), QIcon(), QString());
	// FUN_005aca9a(tabGroup,idx,"Normal"/"Pinned")@008de4bc:
	//   param_3 != 0 → "Normal",== 0 → "Pinned"(语料原样);
	//   FUN_005aca9a → FUN_005a8818(+0x58)— cited — wave-2(体未读)
	g->tabBar()->assignTabProperty(idx, normal ? QStringLiteral("Normal")
	                                           : QStringLiteral("Pinned"));
	if (g != nullptr)
		g->blockSignals(false);          // @008de4d7(false)
}

// === detachPane(MuxPaneView*) ===
// 转写 FUN_008dedae(0028:25986,62B;addTab 的对偶 = 页拆):
//   FUN_005ab6c2(+0x38)(stackIndexOf(w))== -1 早退 →
//   FUN_005ab2cc(+0x38,idx,0)(stack 摘出:widget==0 早退,param_3=0
//   不走 close/deleteLater 腿 → 仅 QStackedWidget::removeWidget,
//   语料 0018:25074)→ QWidget::setParent(page,nullptr)(页脱管)。
void MuxPaneGroup::detachPane(MuxPaneView *page)
{
	const int idx = m_f38->stackIndexOf(page);   // FUN_005ab6c2 @008dedb0
	if (idx == -1)
		return;                                  // @008dedb6
	// FUN_005ab2cc(tabGroup,idx,0)@008dedbd:widget(idx)==0 早退 →
	//   param_3=0 → QStackedWidget::removeWidget @0018:25098-104(73B)
	m_f38->stack()->removeWidget(m_f38->stackWidgetAt(idx));
	// QWidget::setParent(page)@008dedcf — 语料 Ghidra 形态 setParent(param_2)
	//   = this 重载被弃,actual = page->setParent(nullptr)(QWidget::setParent
	//   (QWidget*) 单参 = 0 parent;页脱管)
	page->setParent(nullptr);
}

// === tabCount() ===
// 转写 FUN_008de59c(0028:25972,9B)= FUN_005abbda(+0x38)
//   = QTabBar::count。
int MuxPaneGroup::tabCount() const
{
	return m_f38->count(); // FUN_005abbda @008de59f
}

// === stackIndexOf(QWidget*) / setTabTitle(int,QString) ===
// 归辖转发面(FUN_008df06e 面板标题同步 @0028:26161 消费):
//   FUN_005ab6c2(tabGroup,w)= stack indexOf(0018:25321,9B);
//   FUN_005ab09e(tabGroup,idx,title)= TabBar::setTabText 面
//   (0018:24913,218B;真身在 TabBar::setTabText)。
int MuxPaneGroup::stackIndexOf(QWidget *w) const
{
	return m_f38->stackIndexOf(w); // FUN_005ab6c2(+0x38)@0018:25321
}

void MuxPaneGroup::setTabTitle(int index, const QString &title)
{
	m_f38->setTabTitle(index, title); // FUN_005ab09e(+0x38)@0018:24913
}

// === currentPane() ===
// 转写 FUN_008de3b2(0028:25616,53B):FUN_005ab316(+0x38)
//   = stack currentWidget → dynamic_cast<MuxPane>(typeinfo 011abb90 =
//   "7MuxPane" = 本仓库 MuxPaneView,避让命名见 MuxPaneView.h 注)。
MuxPaneView *MuxPaneGroup::currentPane() const
{
	QWidget *w = m_f38->currentWidget(); // FUN_005ab316 @008de3b5
	if (w == nullptr)
		return nullptr;
	return dynamic_cast<MuxPaneView *>(w); // __dynamic_cast @008de3c5
}

// === paneAtCurrentIndex() ===
// 转写 FUN_008def86(0028:26083,53B):FUN_005abbd0(+0x38)
//   = stack widget(currentIndex)(QStackedWidget::widget(+0x60)@0018:25762,
//   current index 由 Qt 重载解析)→ 非 null 时
//   dynamic_cast<MuxPane>(011abb90)→ 返回;空/不匹配返 0。
MuxPaneView *MuxPaneGroup::paneAtCurrentIndex() const
{
	QWidget *w = m_f38->stackWidgetAt(m_f38->tabBar()->currentIndex()); // FUN_005abbd0 @008def89
	if (w == nullptr)
		return nullptr;
	return dynamic_cast<MuxPaneView *>(w); // __dynamic_cast @008def95
}

// === confirmCloseCurrentPane() ===
// 转写 FUN_008dfa8c(0028:26729,21B):FUN_008de3b2(currentPane)→
//   pane_confirmClose(this,pane)。pane_confirmClose(0028:26736,915B)
//   已在库读体:父链上溯 dynamic_cast<MuxWindow>(011ac070)→
//   FUN_008e04ae(win,pane,confirm)(1095B 未读)确认弹面 →
//   MuxWindow 槽未入库 → 尾调 cited(体引用见 pane_confirmClose
//   @decomp-part-0028.c:26736)。
void MuxPaneGroup::confirmCloseCurrentPane()
{
	MuxPaneView *pane = currentPane(); // FUN_008de3b2 @008dfa8c
	// pane_confirmClose(this,pane)— cited — wave-2(915B:MuxWindow 011ac070
	//   上溯 + FUN_008e04ae 确认链;MuxWindow 槽未入库,不发明)
	(void)pane;
}

// === closeCurrentPane(int) ===
// 转写 FUN_008dfa76(0028:26716,21B):FUN_008def86(stack widget
//   currentIndex,同 confirmClose 的 currentPane 面)→
//   pane_confirmClose(this,pane)。index 实参语料未消费,照抄。
void MuxPaneGroup::closeCurrentPane(int index)
{
	(void)index;                           // 语料 param_2 未消费 @008dfa76
	MuxPaneView *pane = paneAtCurrentIndex(); // FUN_008def86 @008dfa79
	// pane_confirmClose(this,pane)— cited — wave-2(同上,0028:26736)
	(void)pane;
}

// === focusCurrentPane() ===
// 转写 FUN_008defbc(0028:26100,36B):FUN_008def86(stack widget
//   currentIndex,0028:26083)→ 非空 QWidget::setFocus(pane,3)
//   (= ActiveWindowFocusReason)。
void MuxPaneGroup::focusCurrentPane()
{
	MuxPaneView *pane = paneAtCurrentIndex(); // FUN_008def86 @008defbc
	if (pane != nullptr)
		pane->setFocus(Qt::ActiveWindowFocusReason); // 008defc5(原因 3)
}

// === showConfigMenu() ===
// 转写 s_MuxPaneGroup_8de2d4(0028:25588,214B)已读体:
//   qcoreapp_self_get → 父链上溯 dynamic_cast<KitWindow>(011ab390)
//   → FUN_006926a0(0021:18550,34B = KitWindow windowAction vcall
//   +0x1f0 取 QMenu*)→ QByteArray("MuxPaneGroup")→
//   FUN_00692ef0(0021:18914,310B = QMenu 查找/新建面)→
//   FUN_005ac790(0028:26415,275B):findChild<QToolButton*>("ConfigButton")
//   → setAutoRaise(true)→ mapToGlobal(btn)→ QMenu::exec →
//   setAutoRaise(true)→ postEvent(btn,QEvent(0xb = Leave))。
// KitWindow 未入库(011ab390 上溯无落点)→ 头尾照抄、KitWindow 面 cited。
void MuxPaneGroup::showConfigMenu()
{
	/* s_MuxPaneGroup_8de2d4 — cited — wave-2(KitWindow 上溯 011ab390 无落点;
	   可转写尾段:FUN_005ac790 = findChild<QToolButton*>("ConfigButton")
	   → mapToGlobal → QMenu::exec → postEvent(Leave),待 KitWindow
	   FUN_006926a0/00692ef0 菜单源入库后接线) */
}

// === onTabBlankRequested() ===
// 转写 FUN_008df5f8(0028:26480,193B)= thunk 同体(008df6ba,5B):
//   父链上溯 dynamic_cast<MuxWindow>(011ac070)→ FUN_008e01a2(0028:27309,
//   9B = FUN_005a23c6(+0x70 SplitterGroup 的 QStackedLayout +0x40)
//   = zoom 判定)→ *this+0x30(expandable)==0 腿:FUN_008de3b2(currentPane)
//   → FUN_008e04ae(win,pane,~zoom)(1095B 未读);
//   else 腿:currentPane → dynamic_cast<TerminalWidget>(011a7470)
//   → FUN_0083fb6e(pane,~zoom)(0026:32899,166B 已读:tmux
//   "resize-pane"+" -t %%1" 指令串 → FUN_0083eaa6)。MuxWindow/
//   TerminalWidget/008e04ae 未入库 → 全分支 cited(体引用在案)。
void MuxPaneGroup::onTabBlankRequested()
{
	/* FUN_008df5f8 — cited — wave-2
	   (MuxWindow 011ac070 上溯 + FUN_008e01a2 zoom 面 +
	    FUN_008e04ae(1095B)/FUN_0083fb6e(tmux resize-pane 面已读,
	    TerminalWidget 落点未入库)均无落点,不发明) */
}

// === renamePane(int) ===
// 转写 FUN_008df466(0028:26325,87B):mux_renamePaneDialog(this,index,
//   &out QString)→ out 串 ref 处理(dealloc 路径;结果被弃 = 语料原样)。
// mux_renamePaneDialog(008df0a4,904B)已在库读体:index==-1 时取
//   tabbar currentIndex → FUN_008def86 取 pane;FUN_005ab180(+0x38,
//   idx,1)取 tab 文 → *+0x30==0 腿:QInputDialog::getText(标题/标签
//   tr @011ac040,0xcba4e8/0xcba53f);else 腿:正则
//   "\d+:(?<paneName>.+?)( \[Synced\])?( \[Zoomed\])?$" 抽 paneName;
//   新文异于旧文 → *+0x30==0 时 FUN_008df06e(标题同步链)/else
//   FUN_0091dde0(pane,pane+0x30,name)(MuxPane 信号 1 发射面,
//   0030:13684)。dialog/QInputDialog/正则面均无入库落点 → 尾调 cited。
void MuxPaneGroup::renamePane(int index)
{
	(void)index; /* mux_renamePaneDialog — cited — wave-2(904B 已读:
	   QInputDialog::getText / 正则抽名 / FUN_008df06e 标题同步链,
	   dialog 与 KitWindow 落点未入库,不发明) */
}
