// KitWindowAssemblyFace.cpp — KitWindow 延迟装配链语料转写(批 192,P1)
//
// 语料:tools/re/decomp/decomp-part-0028.c(0021.c 状态栏腿)+
//   /opt/WindTerm_2.7.0/WindTerm 反汇编(vaddr 直读;Ghidra 丢接收者/
//   实参处一律以 asm 补,地址 = 文件内 vaddr,无基址差)。
//
// 链序(FUN_008d3cc2 全读 + asm 0x8d3cc2-0x8d3ddf):
//   gate(+0x30) → 008c9ee4 菜单栏 → 008c9f8c 状态栏 →
//   King::assembleCentralSplitters(008cd068) → 钩 +0x210 →
//   008cd822 三连线(cited) → 008c9fc2 +0xa0 懒件(cited) → 清 gate →
//   property "History"/"HistoryHints" → s_kit_startupSessions_8d2f7e →
//   失败腿 +0x208 → 尾钩 +0x250。
#include <QDataStream>
#include <QMenuBar>
#include <QSplitter>
#include <QStatusBar>
#include <QVariant>

#include "Actions/KitDockFace.h"
#include "Actions/KitWindowAssemblyFace.h"
#include "Actions/KitWindowFactory.h"
#include "Actions/StatusBarFace.h"
#include "Actions/TabGroup.h"
#include "WorkspaceLoader.h"
#include "Widgets/Splitter.h"

// 008c9ee4(159B,0028.c:11376)菜单栏装配腿:
//   menuBar = King::MenuBar::MenuBar(menu(),"Kit",this) @0x8c9f22(批 189
//   kitMenuBarBuild 真身;组名 "Kit" = .rodata 0x11826e0 实读);
//   cornerWidget = (*this+0x218)(this) @0x8c9f3e;非空 →
//   setCornerWidget(w, Qt::TopRightCorner=1) @0x8c9f54;
//   setMenuBar(bar) @0x8c9f5f。
QMenuBar *kitMenubarAssemble(KitWindowFace *host)
{
	QMenuBar *bar = kitMenuBarBuild(host->menu(), host); // @0x8c9f22
	if (QWidget *corner = host->kitCornerWidget()) {     // @0x8c9f3e
		bar->setCornerWidget(corner, Qt::TopRightCorner); // @0x8c9f54(edx=1)
	}
	host->setMenuBar(bar); // @0x8c9f5f
	return bar;
}

// FUN_00692766(493B,0021.c:18604)状态栏构建:
//   operator_new(0x48) @0x692778 + FUN_005a2d26(obj,parent) = 状态栏子类
//   ctor(批 196 真身 StatusBarFace);objectName "StatusBar" @0x6927b0-c7;
//   King::registerBarsAndPanes("StatusBar") 标题 → setWindowTitle @0x692819
//   (cited 腿 = 12455B 巨型注册面,批 189 menuBar 同函数);
//   FUN_005a2e58(bar,QString(),0) @0x692877 = 空消息 → tr("Ready")
//   (批 196 真身 showFaceMessage);cfg 非空 → QTimer::singleShotImpl(
//   0,0,0,{FUN_006933ea,bar,cfg}) @0x6928d5(cited 回调体)。
QStatusBar *kitStatusbarBuild(CGlobalConfigFace *container, QWidget *hostPane)
{
	Q_UNUSED(container); // 语料:仅作 singleShot 闭包第二实参(cited 腿)
	StatusBarFace *bar = new StatusBarFace(hostPane); // @0x692778(FUN_005a2d26)
	bar->setObjectName(QStringLiteral("StatusBar"));  // @0x6927b0-7c7(语料重赋同值)
	bar->showFaceMessage(QString(), 0);               // @0x692877(FUN_005a2e58)
	return bar;                                       // @rax → setStatusBar 实参
}

// 008c9f8c(54B,0028.c:11401)状态栏装配腿:00692766 返回 → setStatusBar。
//   asm:call 0x692766 @0x8c9fab → rax;setStatusBar(rax) @0x8c9fb6。
void kitStatusbarAssemble(KitWindowFace *host)
{
	host->setStatusBar(kitStatusbarBuild(host->menu(), host)); // @0x8c9fab-b6
}

// King::assembleCentralSplitters(1010B,0028.c:13782)中央 splitter 树:
//   七槽 new(+0x38..+0x50 QSplitter / +0x58..+0x68 Splitter)@0x8cd08b-ac12d;
//   setChildrenCollapsible(+0x48,false) @0x8cd13c;
//   FUN_005a1c6c(+0x58,1) @0x8cd14a = raw store +0x30 → Splitter::setMainIndex
//   (src/Widgets/Splitter.cpp:117 同构);
//   三条 connect(+0x58/+0x60/+0x68:信号 FUN_008f6af8 → 宿主信号 0x229,
//     smeta 011981a0)@0x8cd14f-8cd30b — 槽体未转写 → cited 不落接线;
//   setOrientation Vertical(2):+0x38/+0x40/+0x60/+0x68 @0x8cd310-343
//   (+0x48/+0x50 保持默认 Horizontal);addWidget 六条 @0x8cd348-391;
//   setSizes:+0x58←[1000,4000,1000] @0x8cd412,+0x60←[4000,2000] @0x8cd41e,
//     +0x68←[4000,2000] @0x8cd42a;
//   setCentralWidget(+0x68) @0x8cd436。
// 树形(asm 接收者还原):
//   +0x68(Splitter,V)[sizes 4000,2000]
//     ├─ +0x58(Splitter,V)[1000,4000,1000]
//     │    ├─ +0x38(QSplitter,V)
//     │    ├─ +0x60(Splitter,V)[4000,2000]
//     │    │    └─ +0x48(QSplitter,H,不可折叠)
//     │    └─ +0x40(QSplitter,V)
//     └─ +0x50(QSplitter,H)
void kitCentralSplittersAssemble(KitWindowFace *host)
{
	host->m_split0x38 = new QSplitter(nullptr);        // @0x8cd08b
	host->m_split0x40 = new QSplitter(nullptr);        // @0x8cd0a6
	host->m_split0x48 = new QSplitter(nullptr);        // @0x8cd0c1
	host->m_split0x50 = new QSplitter(nullptr);        // @0x8cd0dc
	host->m_split0x58 = new Splitter(nullptr);         // @0x8cd0f7
	host->m_split0x60 = new Splitter(nullptr);         // @0x8cd112
	host->m_split0x68 = new Splitter(nullptr);         // @0x8cd12d
	host->m_split0x48->setChildrenCollapsible(false);   // @0x8cd13c(esi=0)
	host->m_split0x58->setMainIndex(1);                // @0x8cd14a(+0x30=1)
	host->m_split0x38->setOrientation(Qt::Vertical);    // @0x8cd310-319
	host->m_split0x40->setOrientation(Qt::Vertical);    // @0x8cd31e-327
	host->m_split0x60->setOrientation(Qt::Vertical);    // @0x8cd32c-335
	host->m_split0x68->setOrientation(Qt::Vertical);    // @0x8cd33a-343
	host->m_split0x60->addWidget(host->m_split0x48);    // @0x8cd348-350
	host->m_split0x58->addWidget(host->m_split0x38);    // @0x8cd355-35d
	host->m_split0x58->addWidget(host->m_split0x60);    // @0x8cd362-36a
	host->m_split0x58->addWidget(host->m_split0x40);    // @0x8cd36f-377
	host->m_split0x68->addWidget(host->m_split0x58);    // @0x8cd37c-384
	host->m_split0x68->addWidget(host->m_split0x50);    // @0x8cd389-391
	host->m_split0x58->setSizes({1000, 4000, 1000});    // @0x8cd412
	host->m_split0x60->setSizes({4000, 2000});          // @0x8cd41e
	host->m_split0x68->setSizes({4000, 2000});          // @0x8cd42a
	host->setCentralWidget(host->m_split0x68);          // @0x8cd436
}

// s_kit_startupSessions_8d2f7e(3122B,0028.c:17278)— cited 契约占位,体属批 193:
//   已核契约(asm 0x8d2f8f 起):gate +0x30 != 0 → return 0;payload 空 →
//   return 0;否则以魔数 0xb9e7e615 / 0xb9e7e621 / 0xb9e7e622 三段恢复
//   (splitter state / 会话槽 / MenuBar·StatusBar·ToolBar 可见性,后者
//   = 虚槽 +0x1d0(名,+bool 取反))+ 尾钩 +0x240(默认 FUN_008d5bee
//   return 1)。当前调用点 payload 恒空(History 属性未设)→ 返回 0 与
//   语料同相;整体真身化后替换本占位。
bool KitWindowFace::kitWindowStartupSessions(const QByteArray &history, int hints)
{
	Q_UNUSED(history);
	Q_UNUSED(hints);
	return false; // cited — 3122B 体前两段未转写(payload 空腿同相)
}

// s_kit_startupSessions_8d2f7e 尾段(栏可见性)— 0028.c:17450-17540 域,
//   asm 0x8d3433-0x8d3576 全核。帧结构 = outer >> QByteArray(帧三)
//   @0x8d346b → QDataStream(frame) @0x8d347b → 连续 BOOL:
//     MenuBar(名 @0x11826a0→0xd0e6e8)← @0x8d348b,值 = 取反 ^1 @0x8d34a3;
//     StatusBar(名 @0x1182668→0xd0e6b2)← @0x8d34d6,取反 @0x8d34ee;
//     ToolBar(名 @0x1182680→0xcb9b17)← @0x8d3534,取反 @0x8d354c。
//   门:外层 (flags & 4) != 0 || magic > 0xb9e7e621 @0x8d3433/0x8d343e;
//   ToolBar 另有 (flags & 4) != 0 || magic > 0xb9e7e622 @0x8d3519-0x8d3528。
//   三腿均经虚槽 +0x1d0(名,bool)→ kitSetBarVisible。
//   前置段(splitter state 恢复 @0x8d2ff9-0x8d344x / 会话槽恢复 LastSessions
//   @0x8d3461-0x8d3430 域)= cited,未落;尾钩 +0x240 @0x8d358a 亦 cited。
bool KitWindowFace::kitWindowBarsRestore(const QByteArray &frame, quint32 magic,
                                         quint32 flags)
{
	if ((flags & 4u) == 0 && magic <= 0xb9e7e621u) // @0x8d3433/0x8d343e
		return false;
	QDataStream in(frame);     // @0x8d347b
	bool hiddenFlag = false;
	in >> hiddenFlag;          // @0x8d348b
	kitSetBarVisible(QStringLiteral("MenuBar"), !hiddenFlag); // @0x8d34c3(*0x1d0)
	in >> hiddenFlag;          // @0x8d34d6
	kitSetBarVisible(QStringLiteral("StatusBar"), !hiddenFlag); // @0x8d350e
	if ((flags & 4u) != 0 || magic > 0xb9e7e622u) { // @0x8d3519/0x8d351d
		in >> hiddenFlag;      // @0x8d3534
		kitSetBarVisible(QStringLiteral("ToolBar"), !hiddenFlag); // @0x8d356c
	}
	return true;               // 语料块尾继续(尾钩 cited)@0x8d358a
}

// FUN_008d3cc2(296B,0028.c:17649)延迟装配门(asm 0x8d3cc2-0x8d3ddf 全核)。
void KitWindowFace::kitWindowAssembleDeferred()
{
	if (m_assemble0x30 == 0) // cmpb $0x0,0x30(%rdi) @0x8d3cc2 / ret @0x8d3cc8
		return;
	kitMenubarAssemble(this);          // @0x8d3cd8 → 008c9ee4
	kitStatusbarAssemble(this);        // @0x8d3ce0 → 008c9f8c
	kitCentralSplittersAssemble(this); // @0x8d3ce8 → 008cd068
	kitAssembleHook();                 // +0x210(非默认才调)@0x8d3cf0/0x8d3de5
	// 008cd822(494B,0028.c:14039)三连线 — 槽体皆未转写 → cited 不落接线:
	//   ① sender=this 信号 FUN_0091b376 → 槽 FUN_008d5c6f,smeta 011ab660
	//   ② sender=qApp QApplication::focusChanged → 槽 FUN_008cd4a2(856B)
	//   ③ sender=qApp 信号 FUN_0090e084 → 宿主信号 0x221 → FUN_008d5fbc,
	//      smeta 011a6ce0
	// 008c9fc2(55B,0028.c:11418):+0xa0 懒建 0x20 字节对象
	//   (operator_new+FUN_006741a0 ctor)@0x8d3d12 — 类未建模,cited。
	m_assemble0x30 = 0; // movb $0x0,0x30(%rbx) @0x8d3d17
	// property 名实读:.data.rel.ro 0x11820e8→0xc9e544 = "History"(QByteArray 值)
	//   / 0x11820e0→0xd0df48 = "HistoryHints"(int 值)。
	const QByteArray history = property("History").toByteArray(); // @0x8d3d1b-4b
	const int hintValue = property("HistoryHints").toInt();       // @0x8d3d50-6f
	setProperty("History", QVariant());                           // @0x8d3d8b-94(清值)
	// s_kit_startupSessions(this,&history,hintValue) @0x8d3daa:
	//   失败 → +0x208 @0x8d3db9;尾钩 +0x250 恒调 @0x8d3dc5。
	if (!kitWindowStartupSessions(history, hintValue))
		kitAssembleFailHook();
	kitAssembleFinishHook();
}

// ── 槽位访问族(批 198;0028.c:11461-11600,asm 0x8ca096-0x8ca17a 全核)──
// 008ca096(33B)槽 id → splitter:1→+0x38 @0x8ca0a0 / 2→+0x40 @0x8ca0b5 /
//   8→+0x50 @0x8ca0ae / 其他 → 0 @0x8ca0b2。
QSplitter *KitWindowFace::kitSlotSplitter(int id)
{
	if (id == 1)
		return m_split0x38;
	if (id == 2)
		return m_split0x40;
	if (id == 8)
		return m_split0x50;
	return nullptr;
}

// 008ca0b8(37B)widget → 槽 id:+0x38→1 @0x8ca0c2 / +0x40→2 @0x8ca0cb /
//   +0x50→8 @0x8ca0d5(cmp 结果 <<3,未命中 0)。
int KitWindowFace::kitSlotIdOf(QWidget *widget)
{
	if (m_split0x38 == widget)
		return 1;
	if (m_split0x40 == widget)
		return 2;
	return m_split0x50 == widget ? 8 : 0;
}

// 008ca0de(65B)槽可见性(asm 0x8ca0de-0x8ca11a):
//   id 1 → +0x58 isIndexVisible(0);id 2 → +0x58 isIndexVisible(2)
//   (0x8ca10b/0x8ca116:esi = id 残留);id 8 → (+0x70==1 ? +0x68 : +0x60)
//   isIndexVisible(1) @0x8ca0f1-106;其他 false @0x8ca0ed。
bool KitWindowFace::kitSlotVisible(int id)
{
	switch (id) {
	case 1:
		return m_split0x58->isIndexVisible(0); // @0x8ca10b-11
	case 2:
		return m_split0x58->isIndexVisible(2); // @0x8ca116
	case 8:
		return (m_flag0x70 == 1 ? m_split0x68 : m_split0x60)->isIndexVisible(1); // @0x8ca0f1
	default:
		return false;
	}
}

// 008ca120(72B)槽可见性设置(同 id 分派;FUN_005a2096 = 可见→showIndex /
//   不可见→hideIndex,与 Splitter::setIndexVisible 同构)。
void KitWindowFace::kitSlotSetVisible(int id, bool visible)
{
	switch (id) {
	case 1:
		m_split0x58->setIndexVisible(0, visible);
		return;
	case 2:
		m_split0x58->setIndexVisible(2, visible);
		return;
	case 8:
		(m_flag0x70 == 1 ? m_split0x68 : m_split0x60)->setIndexVisible(1, visible);
		return;
	default:
		return; // 语料:非 1/2/8 直接 return
	}
}

// 008ca168(7B)/008ca170(10B):隐藏/显示 = kitSlotSetVisible(id, 0/1)。
void KitWindowFace::kitSlotHide(int id) { kitSlotSetVisible(id, false); }
void KitWindowFace::kitSlotShow(int id) { kitSlotSetVisible(id, true); }

// 008b8694(79B,0027.c:75790)KitWindow 祖先上溯:dynamic_cast<011ab390>
//   ("9KitWindow" RTTI)逐级 parentWidget 链;未命中 0 @008b86d?。
KitWindowFace *kitWindowAncestor(QObject *object)
{
	while (object != nullptr) {
		if (auto *kit = dynamic_cast<KitWindowFace *>(object))
			return kit; // @008b86b? dynamic_cast 命中
		object = object->parent();
	}
	return nullptr;
}

// 008ca002(87B,0028.c:11430)TabGroup 弹菜单真身:
//   FUN_006926a0 → menu() @008ca002;QByteArray "TabGroup Popup" @008ca03d;
//   FUN_00692ef0(容器,名,host)= kitFindOrCreateGroupMenu(批 189 真身)。
QMenu *kitTabGroupPopupMenu(KitWindowFace *host)
{
	return kitFindOrCreateGroupMenu(host->menu(),
	                                QByteArrayLiteral("TabGroup Popup"),
	                                host); // @008ca03d
}

// ── 面板工厂腿(批 203)──────────────────────────────────────────────
// 0089ede8(232B)先把 "Pane" 后缀喂给 0089ebe2(278B):
//   @0089ebe2 QString::endsWith(name,"Pane",cs=1) 假 → name.append("Pane");
//   随后首字符:空串 resize(1,' '),否则取首 QChar → QChar::toUpper →
//   写回首字符(ushort 直写)。语义 = "explorer" → "ExplorerPane"。
QString kitPaneNameNormalized(const QString &rawName)
{
	QString name = rawName;
	if (!name.endsWith(QStringLiteral("Pane"), Qt::CaseInsensitive)) // @0089ebe2
		name.append(QStringLiteral("Pane"));
	if (name.isEmpty())
		name.resize(1, QLatin1Char(' '));
	name[0] = name.at(0).toUpper(); // QChar::toUpper 写回首字符
	return name;
}

// s_ExplorerPane_89eed8 compare 链(全部 QString::compare_helper(...,1),
//   即 CaseInsensitive)+ operator_new 字节 + ctor 地址:
//   ExplorerPane 0x58 s_ExplorerPane_72fbee @0089efa2
//   FilerPane    0x78 s_FilerPane_730c20    @0089f145
//   OutlinePane  0x90 s_OutlinePane_745dea  @0089f128(守卫 cast 0119ee10|011a7c40)
//   OutputPane   0x48 s_OutputPane_7489c0   @0089f18d
//   SearchPane   0x148 s_SearchPane_74efe6  @0089f1f7
//   SenderPane   0xa8 s_SenderPane_734dc2   @0089f269(守卫 011a7c40)
//   SessionPane  0x68 s_SessionPane_73cb1e  @0089f2db(守卫 011a7c40)
//   ShellPane    0x60 s_ShellPane_74feb4    @0089f30e
//   TransferPane 0x60 s_TransferPane_733a18 @0089f36f(守卫 011a7c40)
static const KitPaneSpec kKitPaneSpecs[] = {
    {"ExplorerPane", 0x58, "s_ExplorerPane_72fbee"},
    {"FilerPane", 0x78, "s_FilerPane_730c20"},
    {"OutlinePane", 0x90, "s_OutlinePane_745dea"},
    {"OutputPane", 0x48, "s_OutputPane_7489c0"},
    {"SearchPane", 0x148, "s_SearchPane_74efe6"},
    {"SenderPane", 0xa8, "s_SenderPane_734dc2"},
    {"SessionPane", 0x68, "s_SessionPane_73cb1e"},
    {"ShellPane", 0x60, "s_ShellPane_74feb4"},
    {"TransferPane", 0x60, "s_TransferPane_733a18"},
};

const KitPaneSpec *kitPaneSpecs(int *count)
{
	if (count != nullptr)
		*count = static_cast<int>(sizeof(kKitPaneSpecs) / sizeof(kKitPaneSpecs[0]));
	return kKitPaneSpecs;
}

// 查面腿 @0089ef1b:qt_qFindChild_helper(kit, 归一名, QWidget smo 011ab900,
//   Flags=1 递归)命中即返;未命中 → 建面(cited:我方 FilerPane/OutputPane/
//   SessionPane/TransferPane 非 QWidget 子类,造 glue = 自造,不做)。
QWidget *kitPanelFindOrCreate(QWidget *kit, const QString &rawName)
{
	const QString name = kitPaneNameNormalized(rawName); // @0089ede8
	if (kit == nullptr)
		return nullptr;
	if (QWidget *found = kit->findChild<QWidget *>(name)) // @0089ef1b(递归=1)
		return found;
	// 建面分派 + 尾部 hide/双 connect @0089efa2-0089f3c1 — cited 未落。
	return nullptr;
}

// 008b8226(399B,0027.c:75484)页挂真身:
//   @008b8230 panel 空 → -1;title = panel->windowTitle()@008b826b;
//   icon = panel->windowIcon()@008b827b;tooltip = windowTitle()@008b8295;
//   idx = FUN_005abe1c(tabs,index,panel,title,icon,tooltip)@008b825x
//   (= TabGroup::insertPage);idx != -1 → connect(panel 的
//   QWidget::windowIconChanged → host,FUN_008b842d,host smo 承接)
//   @008b830x — 槽体 cited 不落接线;param_4 != 0 →
//   FUN_005ab5d4(tabs,idx)@008b83xx = tabBar 当前页切换。
int kitPanelAdd(TabGroup *tabs, QWidget *panel, int index, bool select)
{
	if (tabs == nullptr || panel == nullptr) // @008b8230
		return -1;
	const QString title = panel->windowTitle(); // @008b826b
	const QIcon icon = panel->windowIcon();     // @008b827b
	const QString tooltip = panel->windowTitle(); // @008b8295
	const int idx = tabs->insertPage(index, panel, title, icon, tooltip); // @008b8255
	// connect(panel, &QWidget::windowIconChanged, host, FUN_008b842d)
	//   @008b830x — 槽体未转写,cited 不落接线。
	if (select && idx != -1)
		tabs->tabBar()->setCurrentIndex(idx); // FUN_005ab5d4 @008b83xx
	return idx;
}

// 008b881c(485B,0027.c:75873)页恢复真身:
//   @008b883x blob 空 → 0;@008b884a QDataStream(blob);
//   @008b8856/60 >>int count(local_80)>>int current(local_7c);
//   循环(0 < count):>>QString(panelName)>>QByteArray(propBA)@008b8878-88x;
//   tabs->blockSignals(current != i)@008b8899-a3(setne 实证);
//   panel = 工厂(008b8694 祖先 + 89eed8 归一名 find-or-create)@008b88ab-8d3;
//   panel 非空 → setProperty("History", QVariant(propBA))@008b892d
//   (名 0xc9e544 = "History" ELF 实读)+ kitPanelAdd(tabs,panel,-1,current==i)
//   @008b8901(FUN_008b83ce = 008b8226(idx=-1));尾 blockSignals(false);
//   返回 1 @008b89c6。
bool kitPanelsRestore(TabGroup *tabs, const QByteArray &blob)
{
	if (tabs == nullptr || blob.isEmpty()) // @008b883x
		return false;
	QDataStream in(blob); // @008b884a
	int count = 0;
	int current = 0;
	in >> count >> current; // local_80 / local_7c @008b8856-60
	KitWindowFace *kit = kitWindowAncestor(tabs); // 008b8694 @008b88ab
	for (int i = 0; i < count; ++i) { // @008b887x
		QString panelName;
		QByteArray propBlob;
		in >> panelName >> propBlob; // @008b8878-88x
		tabs->blockSignals(current != i); // setne @008b8899-a3
		QWidget *panel = kitPanelFindOrCreate(kit, panelName); // 89eed8 @008b88d3
		if (panel != nullptr) {
			panel->setProperty("History", QVariant(propBlob)); // @008b892d
			kitPanelAdd(tabs, panel, -1, current == i); // 008b83ce @008b8901
		}
	}
	tabs->blockSignals(false); // 尾复原
	return true;               // @008b89c6
}

// 008b8a26(143B,0027.c:75960)页显真身:
//   kit = 008b8694(this)@008b8a2x;panel = 89eed8(名, kit)@008b8a5f;
//   panel != 0 → FUN_008b8226(this,panel,param_3,param_4)@008b8a7d
//   (008b83ce = 同面 idx=-1 包装 @008b83ce 13B)。
int kitPanelShow(TabGroup *tabs, const QString &name, int index, bool select)
{
	if (tabs == nullptr)
		return -1;
	QWidget *panel = kitPanelFindOrCreate(kitWindowAncestor(tabs), name); // @008b8a5f
	if (panel == nullptr)
		return -1;
	return kitPanelAdd(tabs, panel, index, select); // @008b8a7d(返回 idx 透传)
}

int kitPanelShowBack(TabGroup *tabs, const QString &name, bool select)
{
	return kitPanelShow(tabs, name, -1, select); // 008b8abe → 008b8a26(idx=-1)
}

// 008b8acc(175B,0027.c:76005)批量页恢复:
//   FUN_005abbda(tabs) 前置计数调用 @008b8acc(值未消费);名表空 → -1;
//   逐 i:blockSignals(实参 Ghidra 丢,循环内 true / 尾 false 同相)+
//   kitPanelShowBack(name[i], currentIndex==i)@008b8b1x;
//   currentIndex 命中项记录返回 idx。尾 blockSignals(false)。
int kitPanelsRestoreList(TabGroup *tabs, const QList<QString> &names,
                         int currentIndex)
{
	if (tabs == nullptr || names.isEmpty()) // @008b8axx(<1 → 0xffffffff)
		return -1;
	int ret = -1;
	for (int i = 0; i < names.size(); ++i) {
		tabs->blockSignals(true); // cited 实参(循环内)
		if (kitPanelShowBack(tabs, names.at(i), currentIndex == i) != -1
		    && currentIndex == i)
			ret = currentIndex;
	}
	tabs->blockSignals(false); // 尾(实参 cited 同相)
	return ret;
}

// 005abce4(301B,0018.c:25843)页位说明真身:
//   QString::toInt(&ok) 成功腿直返 n @005abce4-cf;
//   compare("First")==0 → 0(返回值即 0);"Last"(0xd0d1c3 实读)==0 → -1(尾插,
//   与 QStackedWidget::insertWidget(-1) 同相);"Before" → max(cur-1,0);
//   "After" → min(count, cur+1);其余 -1。
int kitTabPositionIndex(TabGroup *tabs, const QString &spec)
{
	bool ok = false;
	const int numeric = spec.toInt(&ok);
	if (ok)
		return numeric;
	if (spec == QLatin1String("First"))
		return 0;
	if (spec == QLatin1String("Last"))
		return -1;
	if (tabs == nullptr)
		return -1;
	const int cur = tabs->tabBar()->currentIndex();
	if (spec == QLatin1String("Before"))
		return cur - 1 < 0 ? 0 : cur - 1;
	if (spec == QLatin1String("After")) {
		const int next = cur + 1;
		return tabs->count() < next ? tabs->count() : next;
	}
	return -1;
}

// 008b8bb8(44B,0027.c:7604x)真身:uVar1 = FUN_005abce4(tabs,spec)@008b8bb8;
//   FUN_008b8a26(this,name,uVar1,param_4)@008b8bc8。
int kitPanelShowAt(TabGroup *tabs, const QString &name, const QString &spec,
                   bool select)
{
	const int index = kitTabPositionIndex(tabs, spec); // @008b8bb8
	return kitPanelShow(tabs, name, index, select);     // @008b8bc8
}

// 008b84b6(251B,0027.c:75629)按名查页真身:
//   归一名(0089ede8)→ 逐 i<count(005abbda):w = 008b83ee(this,i)
//   (QStackedWidget::widget + 0x30 空判)→ w->objectName() == 名 → i;
//   循环完 → -1。
int kitPanelIndexByName(TabGroup *tabs, const QString &rawName)
{
	if (tabs == nullptr)
		return -1;
	const QString name = kitPaneNameNormalized(rawName); // @008b84b6(0089ede8)
	const int n = tabs->count();
	for (int i = 0; i < n; ++i) {
		QWidget *w = tabs->stackWidgetAt(i); // 008b83ee @008b84f4
		if (w != nullptr && w->objectName() == name)
			return i;
	}
	return -1;
}

// 008b83dc(17B)摘页 = FUN_005ab2cc(this,index,0) 透传:
//   @005ab2cc QStackedWidget::widget(+0x60) 空 → 返;param_3(此处 0)非 0
//   腿 = close() 失败即返 + deleteLater;否则 stack->removeWidget(w)。
void kitPanelRemoveAt(TabGroup *tabs, int index)
{
	if (tabs == nullptr || index == -1) // @008b83dc 门
		return;
	QWidget *w = tabs->stackWidgetAt(index); // QStackedWidget::widget @005ab2cc
	if (w == nullptr)
		return;
	tabs->stack()->removeWidget(w); // @005ab2cc 尾
}

// 008b8b7c(60B)面板开关真身:
//   i = 008b84b6(this)@008b8b7c;!= -1 → 008b83dc(this,i)
//   (摘页)@008b8b8x;== -1 → 008b8abe(this,name,1)(尾插 + 选中)@008b8b8x。
int kitPanelToggle(TabGroup *tabs, const QString &name)
{
	const int i = kitPanelIndexByName(tabs, name); // @008b8b7c
	if (i != -1) {
		kitPanelRemoveAt(tabs, i); // 008b83dc
		return i;
	}
	return kitPanelShowBack(tabs, name, true); // 008b8abe
}

// s_tabbar_selectionBehaviorOnRemove_89d860(1346B,0027.c:55345)真身:
//   @5534x panel 空 → 0;配置键 "tabbar.selectionBehaviorOnRemove"
//   (QMetaEnum 0x1180860 valueToKey→global_setting_get→keyToValue,
//   缺省 2 — WorkspaceLoader::tabBarSelectionBehaviorOnRemove 真身复用);
//   dock = operator_new(0x58)@0089d9d8 + KitDock ctor(panel,parent);
//   FUN_008b8680(dock)@0089d9e0 = FUN_005abbc6(tabs) =
//   QTabBar::setSelectionBehaviorOnRemove(behavior)(公开 API);
//   双 connect:KitDock 信号 idx0(FUN_0091a7d8)→ FUN_008ce100;
//   idx1(FUN_0091a80c)→ FUN_008ca17a — 槽体未转写,cited 不落;
//   尾 connect(panel, &QObject::destroyed, dock, &QObject::deleteLater)
//   @0089daxx(sender=panel / receiver=dock 实证)。
KitDockFace *kitCreateDock(QWidget *panel, QWidget *parent)
{
	if (panel == nullptr) // @5534x 空卫
		return nullptr;
	const int behavior = Workspace::tabBarSelectionBehaviorOnRemove(); // 配置腿
	KitDockFace *dock = new KitDockFace(panel, parent); // @0089d9d8(0x58)
	dock->tabGroup()->tabBar()->setSelectionBehaviorOnRemove(
	    static_cast<QTabBar::SelectionBehavior>(behavior)); // @0089d9e0
	// idx0 → FUN_008ce100(= KitWindowFace::kitSetSlotExpanded,真身);
	// idx1 → FUN_008ca17a(= kitRestoreSlotOfChild,cited 接线 — 信号名未取证)。
	if (KitWindowFace *kit = kitWindowAncestor(dock)) {
		QObject::connect(dock, &KitDockFace::expandRequested, kit,
		                 &KitWindowFace::kitSetSlotExpanded);
	}
	QObject::connect(panel, &QObject::destroyed, dock,
	                 &QObject::deleteLater); // @0089daxx
	return dock; // @5534x 返回
}

// 008ce100(244B,0028.c:14347)展开/收起真身:
//   splitter = (+0x70 == 1 ? +0x68 : +0x60)@008ce10x;
//   param_2 == 0 → FUN_005a1cfc(splitter,0)(= Splitter::showIndex(0))
//   @008ce13x;否则 FUN_005a1ebc(splitter)(= hideIndex)@008ce14x;
//   随后 this+0x50 下 findChildren<KitDock>(smo 011ab100,递归)@008ce165
//   逐个 FUN_008b8c68(dock,on)(13B:tabGroup->ExpandButton 状态,584B
//   图标腿 cited)@008ce1aa。
void KitWindowFace::kitSetSlotExpanded(bool expanded)
{
	Splitter *sp = (m_flag0x70 == 1 ? m_split0x68 : m_split0x60); // @008ce10x
	if (sp == nullptr)
		return;
	if (!expanded)
		sp->showIndex(0); // FUN_005a1cfc @008ce13x
	else
		sp->hideIndex(0); // FUN_005a1ebc(索引位语料丢,按同槽 0 落)
	// findChildren<KitDock>(+0x50 容器,递归)@008ce165 逐个同步展开钮
	//   (FUN_008b8c68 13B → s_ExpandButton_5ab32a 584B,批 215 真身)
	//   @008ce1aa。
	if (QWidget *box = m_split0x50) { // +0x50 容器(findChildren 根)
		const QList<KitDockFace *> docks = box->findChildren<KitDockFace *>();
		for (KitDockFace *dock : docks)
			dock->updateExpandButton(expanded);
	}
}

// 008ca17a(110B,0028.c:11586)子件槽恢复真身:
//   信号 arg 非 0 → 直返(仅 false 腿动作);sender 空 → 返;sender cast
//   011aaed0 命中 → parentWidget → dynamic_cast<QSplitter*> →
//   kitSlotIdOf(sp)@008ca1xx → kitSlotShow(id)(FUN_008ca170)@008ca1xx。
void KitWindowFace::kitRestoreSlotOfChild(QWidget *child)
{
	if (child == nullptr)
		return;
	QWidget *p = child->parentWidget();
	QSplitter *sp = p != nullptr ? dynamic_cast<QSplitter *>(p) : nullptr;
	const int id = kitSlotIdOf(sp); // FUN_008ca0b8
	kitSlotShow(id);                // FUN_008ca170
}
