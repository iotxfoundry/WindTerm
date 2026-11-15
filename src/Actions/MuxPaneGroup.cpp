#include "MuxPaneGroup.h"

#include <QColor>
#include <QDataStream>

#include "KitWindowAssemblyFace.h"
#include "KitWindowFace.h"

#include "KitWindowFace.h"
#include "MuxPaneView.h"
#include "MuxWindow.h"
#include "TabGroup.h"

#include <QVBoxLayout>
#include <QStackedWidget>
#include <QTabBar>
#include <QToolButton>
#include <QMenu>
#include <QEvent>
#include <QCoreApplication>
#include <QInputDialog>
#include <QLineEdit>
#include <QRegularExpression>

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
// 转写 FUN_008dfa8c(0028:26729,21B,asm 全读):FUN_008de3b2(currentPane)
//   → 尾 jmp pane_confirmClose(this,pane)@008dfa9c。pane_confirmClose
//   (0028:26554,915B)asm 全读 → 归辖 MuxWindow::confirmPaneClose
//   (批 106 真身;上溯 MuxWindow(011ac070)在此处对位):
//   上溯命中 → win->confirmPaneClose(pane);未命中 → 语料早返 @008df709-14。
void MuxPaneGroup::confirmCloseCurrentPane()
{
	MuxPaneView *pane = currentPane(); // FUN_008de3b2 @008dfa8c
	for (QWidget *w = this; w != nullptr; w = w->parentWidget()) {
		if (auto *win = dynamic_cast<MuxWindow *>(w)) { // 011ac070 @008df6f1-fc
			win->confirmPaneClose(pane);                // pane_confirmClose @008dfa9c
			return;
		}
	}
	// 上溯尽未命中 MuxWindow → 语料直返(008df709-14);pane 值弃(原样)
	(void)pane;
}

// === closeCurrentPane(int) ===
// 转写 FUN_008dfa76(0028:26716,21B,asm 全读):FUN_008def86(stack widget
//   currentIndex,同 confirmClose 的 currentPane 面)→ 尾 jmp
//   pane_confirmClose(this,pane)@008dfa86。index 实参语料未消费,照抄。
void MuxPaneGroup::closeCurrentPane(int index)
{
	(void)index;                               // 语料 param_2 未消费 @008dfa76
	MuxPaneView *pane = paneAtCurrentIndex();  // FUN_008def86 @008dfa7a
	for (QWidget *w = this; w != nullptr; w = w->parentWidget()) {
		if (auto *win = dynamic_cast<MuxWindow *>(w)) { // 011ac070 @008df6f1-fc
			win->confirmPaneClose(pane);           // pane_confirmClose @008dfa86
			return;
		}
	}
	(void)pane;                                // 同上,语料早返
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
// 转写 s_MuxPaneGroup_8de2d4(0028:25588,214B,asm 008de2d4-008de3a3 全读):
//   qcoreapp_self_get 值弃 @008de2e1 → 父链上溯 dynamic_cast<KitWindow>
//   (011ab390)@008de2f1-30f;未命中 → 直返 @008de319(无任何菜单操作);
//   命中 → FUN_006926a0(kitwin vcall +0x1f0 = menu() 槽 62 取容器)→
//   QByteArray("MuxPaneGroup",@0xd0ea78)→ FUN_00692ef0 → 尾
//   FUN_005ac790(pane+0x38 = TabGroup,"ConfigButton",menu)。
// 三段真身:kitFindOrCreateGroupMenu(FUN_00692ef0)/kitPopupConfigButton
//   (FUN_005ac790)见文件尾;KitWindow 上溯腿 = 本仓库 KitWindowFace
//   (批 133 入库,011ab390 对位)。
// 批 189 升级:FUN_00692ef0 升真(KitWindowFactory.cpp,容器面 = face
//   m_groups,KITWINDOW-RECON §未解 1 收口)→ 本处传 face 容器,S2 查建
//   腔由真身承载(组命中 → 缓存 QMenu;未命中 → 散建,不发明)。
void MuxPaneGroup::showConfigMenu()
{
	// S1:qcoreapp_self_get() 值弃 @008de2e1(原样)
	KitWindowFace *kit = nullptr;
	for (QWidget *w = this; w != nullptr; w = w->parentWidget()) {
		if ((kit = dynamic_cast<KitWindowFace *>(w)) != nullptr) // 011ab390 @008de2f1-30f
			break;
	}
	if (kit == nullptr)
		return;                                  // @008de319(直返,无菜单操作)
	CGlobalConfigFace *container = kit->menu();  // FUN_006926a0 @008de331(+0x1f0 槽 62)
	// S2:FUN_00692ef0(容器,QByteArray("MuxPaneGroup"),this)@008de33b-57
	QMenu *menu = kitFindOrCreateGroupMenu(container,
	                                      QByteArrayLiteral("MuxPaneGroup"),
	                                      this); // 0021.c:18914(批 189 真身)
	// S3:FUN_005ac790(+0x38,"ConfigButton",menu)@008de389
	kitPopupConfigButton(m_f38, QStringLiteral("ConfigButton"), menu); // 0018.c:26415
}

// === onTabBlankRequested() ===
// 转写 FUN_008df5f8(0028:26480,193B,asm 008df5f8-008df6b4 全读)=
//   thunk 同体(008df6ba,5B jmp):
//   S1:qcoreapp_self_get() 值弃 @008df603;
//   S2:父链上溯 dynamic_cast<MuxWindow>(011ac070)@008df60b-2c;未命中
//     → return @008df63e-46;
//   S3:zoom = FUN_008e01a2(win)(FUN_005a23c6 +0x40 占位槽;本仓库
//     MuxWindow::isZoomed)@008df647-4a;
//   S4:+0x30(expandable)==0 腿 @008df651-74:FUN_008de3b2(currentPane)
//     → 尾 FUN_008e04ae(win,pane,~zoom)(1095B asm 全读 → 本仓库
//     MuxWindow::setPaneZoom 真身);
//   S5:expandable!=0 腿 @008df679-b4:currentPane 空 → return;
//     cast<TerminalWidget>(pane)(011abb90→011a7470)空 → return;
//     非空 → FUN_0083fb6e(pane,~zoom)(0026:32899,166B asm 全读:
//     "resize-pane" 0xcb76ac,zoom 时追加 " -Z" 0xcb76b8(FUN_0069e842
//     = qstring_append_ascii)," -t %%1" 0xcb7589 .arg(pane+0x30) →
//     FUN_0083eaa6(pane,cmd)(0026:32168,25B asm 全读:pane+0x160==1
//     且串非空 → FUN_00910898 = QMetaObject::activate(pane,
//     staticMetaObject 011a7c00 = TerminalWidget,idx 0xd = 13 =
//     tmuxCommandWritten(QString),qmo 权威))。MuxPaneView 无 +0x160
//     tmux 位成员、信号面未落库 → S5 尾链 cited(同 sendSelectPane
//     先例,不发明;S1-S4 落真身)。
void MuxPaneGroup::onTabBlankRequested()
{
	// S2:MuxWindow 上溯
	MuxWindow *win = nullptr;
	for (QWidget *w = this; w != nullptr; w = w->parentWidget()) {
		if ((win = dynamic_cast<MuxWindow *>(w)) != nullptr) // 011ac070 @008df624
			break;
	}
	if (win == nullptr)
		return;                                            // 008df63e-46
	const bool zoom = win->isZoomed();                     // S3 FUN_008e01a2 @008df647
	if (!m_f30) {                                          // S4 expandable==0 @008df651
		win->setPaneZoom(currentPane(), !zoom);            // FUN_008de3b2 → FUN_008e04ae @008df65b-74
		return;
	}
	// S5:tmux resize-pane 腿 — 尾链 cited(见上注)
	(void)zoom;
	MuxPaneView *pane = currentPane();                     // FUN_008de3b2 @008df67c
	// cast<TerminalWidget>(pane) → FUN_0083fb6e(pane,~zoom) →
	//   FUN_0083eaa6 → FUN_00910898 activate — TerminalWidget 落点在库
	//   但 MuxPaneView +0x160 tmux 位未建模 → 发射不可达,cited 保留。
	(void)pane;
}

// === renamePane(int) ===
// 转写 FUN_008df466(0028:26325,87B,asm 全读):out 初始化 shared_null →
//   mux_renamePaneDialog(this,index,&out)→ out 弃(LOCAL 弦外无消费,
//   dealloc 路径 = 语料原样)。
// mux_renamePaneDialog(008df0a4,904B,asm 008df0a4-008df254 全读):
//   S1:index==-1 → FUN_005ab5ca(+0x38)(asm:rdi=[this+0x38];+0x58 tabbar;
//     4c2720 = QTabBar::currentIndex)@008df267-70;
//   S2:pane = FUN_008def86(this,index);空 → return @008df0cf-d5;
//   S3:tabText = FUN_005ab180(&tabText,this+0x38,index,1)(4c2720 同面
//     = QTabBar::tabText)@008df0db-ef;
//   S4/S5 预填序(expandable 分叉只影响预填方式,汇合同一交互面):
//     expandable==0 @008df0f4-8:out 非空早跳 S6 @008df0fe-07
//       (FUN_008df466 的 out 恒空 → 必走);否则落 getText @008df10d;
//     expandable!=0 @008df278-c8:
//       re = QRegularExpression("\\d+:(?<paneName>.+?)( \\[Synced\\])?
//         ( \\[Zoomed\\])?$",NoPatternOption)(pattern 0xcba4b0,0x31 字节);
//       m = re.match(tabText,0,Normal,无 options)@008df2c8-de;
//       m.hasMatch()@008df2e3-eb → tabText = m.captured("paneName")
//         @008df2f3-2a(name 0xcba536);再 out 非空跳 S6 @008df38e-97;
//         out 仍空 → 同落 getText @008df39d(→008df10d);
//     getText @008df10d-91:result = QInputDialog::getText(this,title,
//       label,Normal(0),tabText,ok=nullptr,flags=0,hints=0)(4bcea0;
//       label tr 0xcba4e8/title tr 0xcba53f);out ← result(指针交换)
//       @008df184-91;
//   S6(两腿汇合 @008df1eb):out == tabText → 尾 @008df1f6-8;
//     out 空 → 尾 @008df1fa-203;
//     expandable==0 → FUN_008df06e(this,pane,out)@008df400-09(53B asm
//       全读:stackIndexOf(pane)!=-1 → FUN_005ab09e(+0x38,idx,out)
//       = setTabText;本仓库 setTabTitle 同面);
//     expandable!=0 → FUN_0091dde0(pane,pane->+0x30,out)@008df20f-1a
//       (0030:13684,59B asm 全读:QMetaObject::activate(pane,smo
//       011abde0 = MuxPane,idx 1 = requestTmuxRenamePane(qmo 权威),
//       args{paneIndex,name})。MuxPaneView 信号面仅 nameChanged(idx0)
//       → idx1 无承载 → cited(不发明)。
void MuxPaneGroup::renamePane(int index)
{
	QString out;                                           // FUN_008df466 @008df472(shared_null)
	if (index == -1)                                       // S1 @008df0b8
		index = m_f38->tabBar()->currentIndex();           // FUN_005ab5ca @008df267
	MuxPaneView *pane = paneAtCurrentIndex();              // S2 FUN_008def86 @008df0ca
	if (pane == nullptr)
		return;                                            // @008df0d5
	QString tabText = m_f38->tabBar()->tabText(index);     // S3 FUN_005ab180 @008df0db(QTabBar::tabText)
	if (m_f30 != 0) {                                      // S5 @008df278
		static const QRegularExpression re(
		    QStringLiteral("\\d+:(?<paneName>.+?)( \\[Synced\\])?( \\[Zoomed\\])?$")); // 0xcba4b0,0x31
		QRegularExpressionMatch m = re.match(tabText, 0,
		                                    QRegularExpression::NormalMatch); // @008df2c8
		if (m.hasMatch())                                  // @008df2e3
			tabText = m.captured(QStringLiteral("paneName")); // @008df2f3(name 0xcba536)
		// @008df38e-97:out 非空 → S6(恒假,FUN_008df466 面 out 恒空);
		//   out 空 → 同落 getText @008df39d(→008df10d)— 直落。
	}
	{                                                      // S4 尾/S5 尾汇合 @008df10d-91
		const QString label = tr("Input a new name for this pane:"); // 0xcba4e8 @008df11a
		const QString title = tr("Rename Pane");           // 0xcba53f @008df13d
		out = QInputDialog::getText(this, title, label,
		                            QLineEdit::Normal, tabText,
		                            nullptr, 0, 0);        // @008df153-7f(ok=null,flags=0,hints=0)
	}
	// S6 @008df1eb
	if (out == tabText)                                    // @008df1eb-8(相等 → 尾)
		return;
	if (out.isEmpty())                                     // @008df1fa-203(out 空 → 尾)
		return;
	if (m_f30 == 0) {                                      // @008df205-9
		const int idx = m_f38->stackIndexOf(pane);         // FUN_008df06e @008df07e
		if (idx != -1)                                     // @008df083
			m_f38->setTabTitle(idx, out);                  // FUN_005ab09e @008df08e
		return;
	}
	// FUN_0091dde0(pane,pane->paneIndex(),out)— MuxPane 信号 idx1
	//   requestTmuxRenamePane 发射;MuxPaneView 无该信号承载 → cited。
	(void)pane;
}

// === kitFindOrCreateGroupMenu(void*,QByteArray,QWidget*) ===
// 转写 FUN_00692ef0(0021:18914,310B,asm 00692ef0-00693030 全读):
//   S1:name 空(id==0)→ 返回 nullptr @00692ef7-a;
//   S2:容器非空 → FUN_006926c2(&it,容器,容器+0x28,name)遍历
//     +0x28 QList(006926c2 164B @0021:18568 全读:元素 = 迭代器对
//     [begin,end] 返回;命中键 memcmp(qs->size()==name.size() &&
//     memcmp(qs data))→ [hit,hit+1])→ [begin,end) 非空(未尾)→
//     取 *begin 之 +0x20 槽对象 → QMetaObject::tr(串)→ 命中;
//   S3:未命中 → QMetaObject::tr(name)(QObject 域)→ operator_new(0x30)
//     QMenu::QMenu(menu,tr,parent)@00692fbf-0069301d → 返回新菜单。
// 批 189 升真:容器类定案(KITWINDOW-RECON §未解 1 收口,批 140 face)
//   → 真身落 KitWindowFactory.cpp kitFindOrCreateGroupMenu(face 容器,
//   组查 + FUN_00692a70 缓存面);本壳 = 壳态替位(容器 void* 卫原样,
//   语义同相:S1/S3 与真身逐句一致;S2 cited 腔由真身承载)。壳保留 =
//   mwctest 133 批断言面(壳态直返腿)不破。
//   容器内部表示(定案批 189):容器 = menu() 返回 Config 系单例
//     (CGlobalConfigFace,m_groups = +0x28 节点树);节点 QMenu 缓存 =
//     SharedConfigHandlerFace::m_menu(FUN_006926c2 命中读/
//     FUN_00692a70 建新写回)。
QMenu *MuxPaneGroup::kitFindOrCreateGroupMenu(void *container,
                                              const QByteArray &name,
                                              QWidget *pane)
{
	if (name.isEmpty())                        // S1 @00692ef7(*(int*)(name+4)==0)
		return nullptr;
	// S2:@00692efc-27 — 容器 +0x28 QList 遍历查 → 真身承载(批 189,
	//   KitWindowFactory.cpp;壳态 void* 不可达 — 无 KitWindow 实例时
	//   本腿不被调,showConfigMenu 早退同相)。
	Q_UNUSED(container);
	// S3:@00692f68-030 — QMetaObject::tr(name) → operator_new(0x30)
	//   QMenu::QMenu(menu,tr串,pane)照抄(新建腿全读)
	return new QMenu(QObject::tr(name.constData()), pane); // @00692fbf-0069301d
}

// === kitPopupConfigButton(QWidget*,QString,QMenu*) ===
// 转写 FUN_005ac790(0018:26415,275B,asm 005ac790-005ac8a3 全读):
//   name 空 → findChild("") 同相(语料 strlen 面裸 NULL 卫 → -1 →
//     fromAscii_helper(0,-1) = 空 QByteArray 语义,Qt findChild 同效);
//   findChild<QToolButton*>(name) → 空 → 返回 @005ac7fd;
//   非空:setAutoRaise(false)@005ac81f(SUB81 = this 调,真值反汇编
//     勘正)→ mapToGlobal(QPoint(0,btn->width()+1))(QPoint(0,w+1)
//     @005ac802-16,Ghidra 形态 = 第二参折叠)→ QMenu::exec(pos,nullptr)
//     @005ac83c → setAutoRaise(true)@005ac849 → new QEvent(0xb=Leave)
//     → QCoreApplication::postEvent(btn,ev,0)@005ac84e-70。
void MuxPaneGroup::kitPopupConfigButton(QWidget *pane, const QString &name,
                                        QMenu *menu)
{
	QToolButton *btn = pane->findChild<QToolButton *>(name); // qt_qFindChild_helper @005ac7cc
	if (btn == nullptr)                        // @005ac7fd(空直返)
		return;
	btn->setAutoRaise(false);                  // @005ac81f
	// QPoint(0,btn->width()+1)@005ac802-16(crect x2-x1+1)→ mapToGlobal
	const QPoint pos = btn->mapToGlobal(QPoint(0, btn->width() + 1)); // @005ac82a
	menu->exec(pos, nullptr);                  // QMenu::exec @005ac83c(壳态
	                                           //   早退腿保证本行测试不可达)
	btn->setAutoRaise(true);                   // @005ac849
	QCoreApplication::postEvent(btn, new QEvent(QEvent::Leave), 0); // @005ac84e-70(0xb=Leave)
}


// FUN_008b9890(149B,0027.c:76790)第 index 页真身:
//   w = FUN_005abbd0(this+0x38)(= TabGroup::stackWidgetAt)@008b9890-9a;
//   cast 011925c8 命中 → 该页;否则 cast 011ab930 → FUN_008da7a8 取内层
//   → 再 cast 011925c8(KitDock 内层腿,cited 不落);未命中 → 0。
MuxPaneView *MuxPaneGroup::paneAtIndex(int index) const
{
	QWidget *w = m_f38 != nullptr ? m_f38->stackWidgetAt(index) : nullptr; // @008b9890
	if (w == nullptr)
		return nullptr;
	if (auto *view = dynamic_cast<MuxPaneView *>(w)) // 011925c8 面
		return view;
	// 011ab930(KitDock)腿:内层页取面 FUN_008da7a8 — cited(未转写)。
	return nullptr;
}

// FUN_008c5578(59B,0028.c:7611)页名真身:
//   FUN_008c54a4(item, "Url")(键 0xcb6fcc 实读)→ QVariant::toString。
//   注:批 228 起走 m_meta20(+0x20 QMap)真身面,不再用动态属性适配。
QString MuxPaneGroup::paneUrl(const MuxPaneView *pane)
{
	if (pane == nullptr)
		return QString();
	return pane->metaValue(QStringLiteral("Url")).toString(); // @008c5578
}

// FUN_008c5534(59B,0028.c:7617)页状态真身:同面,键 "State"。
QString MuxPaneGroup::paneState(const MuxPaneView *pane)
{
	if (pane == nullptr)
		return QString();
	return pane->metaValue(QStringLiteral("State")).toString(); // @008c5534
}

// s_RenamedTitle_8bbab6(850B,0028.c:226)组会话帧真身(函数名取自其内
//   重命名标题腿,实际 = 组标题/会话序列化):
//   @008ba210 owner = 祖先 pane menu() 的 configSelfName(vt+0x1f0 → vt+8);
//   @008b9b34 iVar4 = 当前索引(tabbar_currentIndex(+0x38));
//   @008b9b2a iVar5 = 页数(TabGroup::count);
//   收集腿:item = 008b9890(group,i) 空 → (i<cur) cur--;url = 008c5578(item)
//     空 → 同上;startsWith("::")(0089e8c8,0xd99dd1 实读)→ 跳过;
//     否则 append(008bf254);
//   << cur;<< list.count();逐项:
//     << QString(url);<< KitView_vt9(item)(会话态 BA,cited);
//     << 颜色(008b9bf4 → 005aba32(+0x38,idx),cited);
//     owner == "Terminal" → << property("RenamedTitle").toString();
QByteArray MuxPaneGroup::sessionTitleBlob() const
{
	QByteArray blob;
	QDataStream os(&blob, QIODevice::WriteOnly); // @008bbae9(WriteOnly=2)
	// owner 名(008ba210):祖先 KitWindow → menu() → configSelfName(vt+8)
	QString owner;
	if (KitWindowFace *kit = kitWindowAncestor(const_cast<MuxPaneGroup *>(this))) {
		if (CGlobalConfigFace *cfg = kit->menu())
			owner = QString::fromLatin1(cfg->configSelfName());
	}
	int current = m_f38 != nullptr ? m_f38->tabBar()->currentIndex() : -1; // @008b9b34
	const int n = m_f38 != nullptr ? m_f38->count() : 0;                   // @008b9b2a
	QList<MuxPaneView *> keep;
	for (int i = 0; i < n; ++i) {
		MuxPaneView *item = paneAtIndex(i); // 008b9890
		if (item == nullptr) {              // @008bbb70 空页
			if (i < current)
				--current;
			continue;
		}
		const QString url = paneUrl(item);  // 008c5578
		if (url.isEmpty()) {
			if (i < current)
				--current;
			continue;
		}
		if (url.startsWith(QStringLiteral("::"), Qt::CaseInsensitive)) // 0089e8c8
			continue;
		keep.append(item);                  // 008bf254
	}
	os << current;                          // @008bbbf9(调整后索引)
	os << keep.size();                      // @008bbc0x(项数)
	for (MuxPaneView *item : keep) {
		os << paneUrl(item);                 // QString @008bbcce
		// KitView_vt9(item) 会话态 BA @008bbcf6 — 虚槽未转写,cited:
		//   本波写空 BA(与无会话态页同相),真身化后替换。
		os << QByteArray();
		// 颜色 008b9bf4 → 005aba32(TabBar,idx)@008bbdxx — cited:
		os << QColor();
		if (owner == QLatin1String("Terminal"))
			os << item->property("RenamedTitle").toString(); // @008bbd4f
	}
	return blob;
}

// 008b9b2a(9B,0027.c:76957):TabGroup::count(+0x38)(FUN_005abbda)。
int MuxPaneGroup::paneCountEx() const
{
	return m_f38 != nullptr ? m_f38->count() : 0; // @008b9b2a
}

// 008b9b34(9B,0027.c:76967):TabBar::currentIndex(FUN_005a...8d860 系
//   tabbar_currentIndex 包装,实参 = +0x38)。
int MuxPaneGroup::currentPaneIndexEx() const
{
	return m_f38 != nullptr ? m_f38->tabBar()->currentIndex() : -1; // @008b9b34
}

// FUN_008b99f6(221B,0027.c:76894)页索引真身:
//   pane == 0 → stackIndexOf(0)@008b99f6;
//   否则 stackIndexOf(cast 011925c8 → QWidget)@008b9a1x;== -1 →
//   parent 链找 cast 011ab930(KitDock)@008b9a4x → stackIndexOf(dock)。
//   (KitDock 面 = MuxWindow 族;我方以 MuxWindow 承接 — 同址 +0x70 splitter)
int MuxPaneGroup::indexOfPane(QWidget *pane) const
{
	if (m_f38 == nullptr)
		return -1;
	const int idx = m_f38->stackIndexOf(pane); // FUN_005ab6c2 @008b99f6
	if (idx != -1)
		return idx;
	for (QWidget *p = pane; p != nullptr; p = p->parentWidget()) {
		if (auto *win = dynamic_cast<MuxWindow *>(p)) // 011ab930 cast
			return m_f38->stackIndexOf(win);           // @008b9a4x
	}
	return -1;
}
