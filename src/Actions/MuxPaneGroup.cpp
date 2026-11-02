#include "MuxPaneGroup.h"

#include "MuxPaneView.h"
#include "TabGroup.h"

#include <QVBoxLayout>

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

// === confirmCloseCurrentPane() ===
// 转写 FUN_008dfa8c(0028:26729,21B):FUN_008de3b2 → pane_confirmClose。
//   pane_confirmClose 未读 → 尾调 cited。
void MuxPaneGroup::confirmCloseCurrentPane()
{
	MuxPaneView *pane = currentPane(); // FUN_008de3b2 @008dfa8c
	// pane_confirmClose(this,pane)— cited — wave-2(未读,不发明)
	(void)pane;
}

// === closeCurrentPane(int) ===
// 转写 FUN_008dfa76(0028:26716,21B):同上(sig3 路径;index 实参语料
//   未消费,照抄)。
void MuxPaneGroup::closeCurrentPane(int index)
{
	(void)index;                       // 语料 param_1 未消费 @008dfa76
	MuxPaneView *pane = currentPane(); // FUN_008def86 面
	// pane_confirmClose(this,pane)— cited — wave-2(未读,不发明)
	(void)pane;
}

// === focusCurrentPane() ===
// 转写 FUN_008defbc(0028:26100,36B):FUN_008def86(currentPane 同面)→
//   非空 QWidget::setFocus(pane,3)(= ActiveWindowFocusReason)。
void MuxPaneGroup::focusCurrentPane()
{
	MuxPaneView *pane = currentPane(); // FUN_008def86 @008defbc
	if (pane != nullptr)
		pane->setFocus(Qt::ActiveWindowFocusReason); // 008defc5(原因 3)
}

// === showConfigMenu() ===
// 语料 s_MuxPaneGroup_8de2d4(0028:25588,214B):qcoreapp_self_get →
//   父链上溯 dynamic_cast<KitWindow>(typeinfo 011ab390)→
//   FUN_006926a0/FUN_00692ef0(KitWindow 面,"MuxPaneGroup" QByteArray)
//   → FUN_005ac790(+0x38,"ConfigButton",menu)。KitWindow 未复刻、
//   FUN_006926a0/FUN_00692ef0/FUN_005ac790 未读 → 整体 cited。
void MuxPaneGroup::showConfigMenu()
{
	/* s_MuxPaneGroup_8de2d4 — cited — wave-2
	   (KitWindow dynamic_cast 011ab390 / FUN_006926a0 / FUN_00692ef0 /
	    FUN_005ac790 均未读,不发明) */
}

// === onTabBlankRequested() ===
// 语料 thunk_FUN_008df5f8 → FUN_008df5f8(0028:26480,193B):父链上溯
//   dynamic_cast<MuxWindow>(011ac070)→ FUN_008e01a2(zoom 判定)→
//   +0x30 分叉:FUN_008e04ae / dynamic_cast<TerminalWidget>(011a7470)
//   → FUN_0083fb6e。MuxWindow/TerminalWidget 未复刻、FUN_008e01a2/
//   FUN_008e04ae/FUN_0083fb6e 未读 → 整体 cited。
void MuxPaneGroup::onTabBlankRequested()
{
	/* FUN_008df5f8 — cited — wave-2
	   (MuxWindow 011ac070 / TerminalWidget 011a7470 cast 链与
	    FUN_008e01a2/FUN_008e04ae/FUN_0083fb6e 均未读,不发明) */
}

// === renamePane(int) ===
// 语料 FUN_008df466(0028:26325,87B):mux_renamePaneDialog(this,index,
//   &out QString)→ out 串 ref 处理(dealloc 路径;结果被弃 = 语料原样)。
//   mux_renamePaneDialog 未读 → 整体 cited。
void MuxPaneGroup::renamePane(int index)
{
	(void)index; /* mux_renamePaneDialog — cited — wave-2(未读,不发明) */
}
