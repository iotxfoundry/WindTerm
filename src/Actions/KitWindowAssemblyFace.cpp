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

#include "Actions/KitWindowAssemblyFace.h"
#include "Actions/KitWindowFactory.h"
#include "Actions/StatusBarFace.h"
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
