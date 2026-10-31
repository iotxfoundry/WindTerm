#include "TabGroup.h"

#include "ThemeIcons.h"

#include <QHBoxLayout>
#include <QAction>
#include <QTimer>

// === TabBar(QWidget*) ===
// 转写 s_TextLabel_5a859a(0018:23040,605B):
//   QTabBar::QTabBar(parent) → +0x31 ← 1 → +0x38 ← "None" → +0x40 ← 1 →
//   +0x48/+0x50 ← 0 → 三 QList shared_null → +0x78 ← 0 →
//   new QLabel(this,"TextLabel") → +0x58 → hide() → FUN_005a81c6(cited) →
//   FUN_005a84f6(this,1) → connect currentChanged→FUN_005a8376(cited 槽体)→
//   connect tabMoved→FUN_005a7fa7(cited 槽体)。
TabBar::TabBar(QWidget *parent)
	: QTabBar(parent)
	, m_f30(false)
	, m_f31(true)
	, m_f38(QStringLiteral("None")) // @005a85e8
	, m_f40(1)
	, m_f48(0)
	, m_f50(0)
	, m_f58(nullptr)
{
	// QLabel::QLabel(label,this,0) @005a8628-65c;objectName "TextLabel" @005a8661
	m_f58 = new QLabel(this);
	m_f58->setObjectName(QStringLiteral("TextLabel"));
	m_f58->hide();                       // QWidget::hide @005a869d
	// FUN_005a81c6(134B)— cited — wave-2(体未读)
	setCloseButtonsVisible(true);        // FUN_005a84f6(this,1) @005a86a5
	// connect QTabBar::currentChanged → FUN_005a8376 @005a86c1-6e3
	connect(this, &QTabBar::currentChanged, this, &TabBar::onCurrentChanged);
	// connect QTabBar::tabMoved → FUN_005a7fa7(闭包)@005a86e8-706
	connect(this, &QTabBar::tabMoved, this, &TabBar::onTabMoved);
}

// === setCloseButtonsVisible(bool) ===
// 转写 FUN_005a84f6(0018:22994,163B):+0x30 ← param_2 → 遍历每 tab
//   增删关闭钮(循环体:s_CloseButton_5a6d42/FUN_005a824c/FUN_005a6c0e,
//   未读)→ QWidget::update()。循环体 cited,开尾照抄。
void TabBar::setCloseButtonsVisible(bool on) // FUN_005a84f6
{
	m_f30 = on; // *(this+0x30) = param_2 @005a84fb
	// 每 tab 关闭钮增删循环 @005a8501-856 — cited — wave-2(依赖未读)
	QWidget::update(); // @005a8567
}

// === insertTabWithMeta(int,QString,QIcon) ===
// 转写 FUN_005a7800(0018:22372,759B):
//   索引钳制(<0 或 >count → 尾插,count)→ +0x60/+0x68/+0x70 三 QList
//   定位插入(自定义 0x10/0x18 字节节点;tabbar_buildPropHash/FUN_005a690e/
//   FUN_005a6a80 合并流)→ QTabBar::insertTab → tabbar_assignMnemonics。
//   节点内部表示 cited(语料自定义,非 Qt 公开结构)。
int TabBar::insertTabWithMeta(int index, const QString &title,
                              const QIcon &icon) // FUN_005a7800
{
	int idx = index;
	if (idx < 0 || idx > count()) // 005a79ed/005a7806 钳制(append)
		idx = count();
	// 三 QList 节点插入 + buildPropHash/FUN_005a690e/FUN_005a6a80
	//   @005a7a0a-005a7939 — cited — wave-2(节点表示未解;icon 实参
	//   进合并流 @005a790c)
	m_f60.insert(idx, QVariant());
	m_f68.insert(idx, QVariant());
	m_f70.insert(idx, QVariant());
	idx = QTabBar::insertTab(idx, title); // 005a79c4
	// tabbar_assignMnemonics(this)— cited — wave-2(未读)
	return idx;
}

// === assignTabProperty(int,QString) ===
// 语料 FUN_005a8818(0018:23122,631B)体未读 → 整体 cited,
//   仅为 FUN_008de3e8("Normal"/"Pinned" 面)保调用形。
void TabBar::assignTabProperty(int index, const QString &value) // FUN_005a8818
{
	(void)index;   // cited — wave-2(体未读)
	(void)value;
}

// === onCurrentChanged(int) ===
// 语料 FUN_005a8376(0018:22922,383B)依赖 QTabBarPrivate
//   (normalizedScrollRect/makeVisible/layoutWidgets)→ Qt 私有类
//   不入库,槽体 cited;连接面已在 ctor 落。
void TabBar::onCurrentChanged(int index) // FUN_005a8376
{
	(void)index; // cited — wave-2(QTabBarPrivate 私有依赖)
}

// === onTabMoved(int,int) ===
// 语料 FUN_005a7fa7(0018:22729,251B)未读 → cited。
void TabBar::onTabMoved(int from, int to) // FUN_005a7fa7
{
	(void)from; // cited — wave-2(体未读)
	(void)to;
}

// === TabGroup(QWidget*) ===
// 转写 s_TabGroup_5af896(0018:28725,295B):
//   QFrame::QFrame(parent,flags0) → 成员清零(+0x40=-1,+0x68/69=0x0101)→
//   setObjectName("TabGroup") @005af95f-978 → 尾调
//   s_TabScrollRightButton_5aec28(全装配)@005af9a5。
TabGroup::TabGroup(QWidget *parent)
	: QFrame(parent)
	, m_f30(0)
	, m_f38()
	, m_f40(-1)      // *(this+0x40) = 0xffffffff @005af8b1
	, m_f48(nullptr)
	, m_f50(0)
	, m_f54(0)
	, m_f58(nullptr)
	, m_f60(nullptr)
	, m_f68(true)    // *(this+0x68) = 0x0101 低字节 @005af8bf
	, m_f69(true)    // 高字节 @005af8bf
	, m_f70(nullptr)
	, m_f78(nullptr)
	, m_f80(nullptr)
	, m_f88(nullptr)
	, m_f90(0)
	, m_f98(0)
	, m_fa0(nullptr)
{
	setObjectName(QStringLiteral("TabGroup")); // 005af95f-978
	fullAssemble();                            // s_TabScrollRightButton_5aec28 @005af9a5
}

// === createToolButton(parent,name,text,icon) ===
// 转写 FUN_005acaba(0018:26598,347B):QToolButton(parent) →
//   QAction(btn):setText/setToolTip → theme_icon_load_svg(icon)(recolor 空)
//   → setIcon → setProperty("iconFile") → setObjectName → setAutoRaise →
//   setDefaultAction → setToolButtonStyle(0) → [setSizePolicy(0x500000)
//   cited:位域打包值不可直译] → installEventFilter(btn 自筛)。
QToolButton *TabGroup::createToolButton(QWidget *parent, const QString &name,
                                        const QString &text, const QString &icon)
{
	QToolButton *btn = new QToolButton(parent);  // operator_new(0x30)@005acae9
	QAction *act = new QAction(btn);             // @005acb01
	act->setText(text);                          // QAction::setText @005acb09
	act->setToolTip(text);                       // QAction::setToolTip @005acb11
	act->setIcon(ThemeIcons::loadSvg(icon, QString())); // theme_icon_load_svg @005acb45(recolor 空→默认)
	act->setProperty("iconFile", icon);          // @005acb96
	btn->setObjectName(name);                    // @005acbc4
	btn->setAutoRaise(true);                     // SUB81(btn,0) @005acbcb
	btn->setDefaultAction(act);                  // @005acbd0
	btn->setToolButtonStyle(Qt::ToolButtonIconOnly); // 参数 0 @005acbd6
	// QWidget::setSizePolicy(btn,0x500000)@005acbdc — cited — wave-2
	//   (QSizePolicy 位域打包值不可直译)
	btn->installEventFilter(btn);                // 自筛 @005acbf8
	return btn;
}

// === createButton(name,grabFocus) ===
// 转写 s_TabGroupButton_5acc3e(0018:26645,2042B)= 按钮工厂:
//   表驱动(name→tr 文案/图标):CloseButton(king::close,"Close")/
//   ConfigButton(king::config,"Config")/ExpandButton(king::shrink,"Expand")/
//   TabGroupButton(空图标,"Group")/TabAddButton(king::addTab,"Add Tab")/
//   TabListButton(king::listTab,"List Tab")@005acc8e-005acd9c;
//   createToolButton 建钮 → grabFocus 时 setProperty("grabFocus",true)
//   @005ad019 → 按名分叉 connect( clicked→对应信号发射)→
//   addWidget(+0xa0)@005ad088。
//   connect 分叉(FUN_008fb548/570/584/598 = activate 1/5/7/8):
//     CloseButton→closeRequested  ConfigButton→configRequested
//     TabAddButton→tabAddRequested  TabGroupButton→tabGroupRequested
//     ExpandButton→FUN_005ab714(cited) TabListButton→s_MenuItemWidget_5b1c08(cited)
QToolButton *TabGroup::createButton(const QString &name, bool grabFocus)
{
	QString text;
	QString icon;
	if (name == QStringLiteral("CloseButton")) {         // 表项 @005acc8e
		text = tr("Close");                              // 0xc89b49
		icon = QStringLiteral("king::close");
	} else if (name == QStringLiteral("ConfigButton")) { // @005accce
		text = tr("Config");                             // 0xc8a3d2
		icon = QStringLiteral("king::config");
	} else if (name == QStringLiteral("ExpandButton")) { // @005acd0e
		text = tr("Expand");                             // 0xc8afe8
		icon = QStringLiteral("king::shrink");
	} else if (name == QStringLiteral("TabGroupButton")) { // @005acd53
		text = tr("Group");                              // 0xcb9f5f
		icon = QStringLiteral("");                       // DAT_00cb99b6(空串)
	} else if (name == QStringLiteral("TabAddButton")) { // @005acd98
		text = tr("Add Tab");                            // 0xc8b265
		icon = QStringLiteral("king::addTab");
	} else if (name == QStringLiteral("TabListButton")) { // @005acddd
		text = tr("List Tab");                           // 0xc8b27a
		icon = QStringLiteral("king::listTab");
	} else {
		return nullptr;                                  // 表未命中 pcVar3=0 @005ad006
	}

	QToolButton *btn = createToolButton(this, name, text, icon); // @005acf0b
	if (grabFocus)
		btn->setProperty("grabFocus", QVariant(true));   // @005ad019

	if (name == QStringLiteral("CloseButton")) {         // @005ad023
		connect(btn, &QAbstractButton::clicked, this, [this] { emit closeRequested(); });
	} else if (name == QStringLiteral("ConfigButton")) { // @005ad03d
		connect(btn, &QAbstractButton::clicked, this, [this] { emit configRequested(); });
	} else if (name == QStringLiteral("ExpandButton")) { // @005ad057
		// 闭包 FUN_005ab714(126B)— cited — wave-2(体未读;连接形保留)
		connect(btn, &QAbstractButton::clicked, this, [this] {
			(void)this; /* FUN_005ab714 — cited — wave-2 */
		});
	} else if (name == QStringLiteral("TabAddButton")) { // @005ad088
		connect(btn, &QAbstractButton::clicked, this, [this] { emit tabAddRequested(); });
	} else if (name == QStringLiteral("TabGroupButton")) { // @005ad0a2
		connect(btn, &QAbstractButton::clicked, this, [this] { emit tabGroupRequested(); });
	} else if (name == QStringLiteral("TabListButton")) { // @005ad0bc
		// s_MenuItemWidget_5b1c08 — cited — wave-2(体未读;连接形保留)
		connect(btn, &QAbstractButton::clicked, this, [this] {
			(void)this; /* s_MenuItemWidget_5b1c08 — cited — wave-2 */
		});
	}
	m_fa0->addWidget(btn);                               // QBoxLayout::addWidget @005ad088
	return btn;
}

// === fullAssemble() ===
// 转写 s_TabScrollRightButton_5aec28(0018:28375,3050B)。序列照抄:
//   双滚钮 → 隐藏/禁用/自重复关 → QStackedWidget(+0x60) → TabBar(+0x58)
//   → 四 connect → 滚钮子件回收(+0x80/0x88)→ 六设值 → CustomContextMenu
//   → QHBoxLayout(+0xa0) → 布局/焦点/尺寸策略。
void TabGroup::fullAssemble()
{
	// 左滚钮 @005aec79-005aecd2(tr 取自 TabGroup staticMetaObject 0xc8b2a1)
	m_f70 = createToolButton(this, QStringLiteral("TabScrollLeftButton"),
	                         tr("Scroll Left"), QStringLiteral("king::arrowLeft"));
	// 右滚钮 @005aed68-005aedae(0xc8b2be)
	m_f78 = createToolButton(this, QStringLiteral("TabScrollRightButton"),
	                         tr("Scroll Right"), QStringLiteral("king::arrowRight"));
	m_f70->hide();                       // 005aecb8 起(左钮 hide)
	m_f70->setEnabled(false);            // setEnabled(0)
	m_f70->setAutoRepeat(false);         // QAbstractButton::setAutoRepeat(0)
	m_f78->hide();                       // 右钮同三连 @005aece2 起
	m_f78->setEnabled(false);
	m_f78->setAutoRepeat(false);

	// new QStackedWidget(this) → +0x60 @005aee6d-71
	m_f60 = new QStackedWidget(this);
	// QFrame::setLineWidth(实参 Ghidra 折叠)— cited — wave-2
	// connect QStackedWidget::widgetRemoved → FUN_005aa720 @005aee78-8a
	connect(m_f60, &QStackedWidget::widgetRemoved, this, &TabGroup::onWidgetRemoved);

	// new TabBar → +0x58 @005aef45-49(s_TextLabel_5a859a)
	m_f58 = new TabBar(this);
	// QWidget::setSizePolicy(tabbar,0x70000)@005aef52 — cited — wave-2
	//   (位域打包值不可直译)
	m_f58->setElideMode(Qt::TextElideMode(1));   // 005aef59(ElideRight)
	m_f58->setAttribute(Qt::WidgetAttribute(2), true); // 005aef5f(WA_MouseTracking)
	m_f58->installEventFilter(this);             // 005aef67(filter=this;TabGroup::eventFilter 本体 cited)

	// connect QTabBar::currentChanged → FUN_005aa7b0 @005aef6f-91
	connect(m_f58, &QTabBar::currentChanged, this, &TabGroup::onCurrentChanged);
	// connect QTabBar::tabMoved → FUN_005aa72a @005aef96-b8
	connect(m_f58, &QTabBar::tabMoved, this, &TabGroup::onTabMoved);
	// connect QTabBar::tabCloseRequested → FUN_008fb5e0 @005aefbd-df
	connect(m_f58, &QTabBar::tabCloseRequested, this, &TabGroup::onTabCloseRequested);
	// connect FUN_008f6608(TabBar tabLayoutChanged)→ FUN_005ab7d8 @005aefe6-012
	//   (meta 01197f40 = TabBar)
	connect(m_f58, &TabBar::tabLayoutChanged, this, &TabGroup::onTabLayoutChanged);

	// TabBar 内 QToolButton 子件按 accessibleName 分拣 @005af256-005af3d0:
	//   ==tr("Scroll Left")(QTabBar 域 0xc8b2a1)→ +0x80;
	//   ==tr("Scroll Right")(0xc8b2be)→ +0x88;各 installEventFilter + clicked connect
	const QList<QToolButton *> btns = m_f58->findChildren<QToolButton *>();
	for (QToolButton *btn : btns) {
		const QString an = btn->accessibleName(); // QWidget::accessibleName @005af428
		if (an == m_f58->tr("Scroll Left")) {
			m_f80 = btn;
			btn->installEventFilter(this);        // 005af339
			// clicked → FUN_005b2ec0 闭包 — cited — wave-2(体未读;连接形保留)
			connect(btn, &QAbstractButton::clicked, this, [this](bool) {
				(void)this; /* FUN_005b2ec0 — cited — wave-2 */
			});
		} else if (an == m_f58->tr("Scroll Right")) {
			m_f88 = btn;
			btn->installEventFilter(this);        // 005af443
			// clicked → FUN_005b2ec0 闭包 — cited — wave-2
			connect(btn, &QAbstractButton::clicked, this, [this](bool) {
				(void)this; /* FUN_005b2ec0 — cited — wave-2 */
			});
		}
	}

	setMovable(true);                    // FUN_005aba04(this,1)@005af63c
	setTabsClosable(false);              // FUN_005ab8b4(this,0)@005af646
	setDocumentMode(false);              // FUN_005ac652(this,0)@005af650
	setDrawBase(false);                  // FUN_005ac8b4(this,0)@005af65a
	setExpanding(false);                 // FUN_005ac8c2(this,0)@005af664
	setUsesScrollButtons(false);         // FUN_005ac522(this,0)@005af66e
	setContextMenuPolicy(Qt::ContextMenuPolicy(3)); // CustomContextMenu @005af678

	// new QHBoxLayout → +0xa0 @005af639-63d
	m_fa0 = new QHBoxLayout;
	// QLayout::setContentsMargins / QBoxLayout::setSpacing(常量折叠)
	//   — cited — wave-2
	m_fa0->addWidget(m_f70);             // 005af663 起
	m_fa0->addWidget(m_f58);
	m_fa0->addWidget(m_f78);
	setLayout(m_fa0);                    // 005af6d1
	setFocusPolicy(Qt::FocusPolicy(1));  // 005af6d7(TabFocus)
	setFocusProxy(m_f58);                // 005af6dd
	// QWidget::setSizePolicy(this,0x70000)@005af6e3 — cited — wave-2
}

// === insertPage(int,page,title,icon,tooltip) ===
// 转写 FUN_005abe1c(0018:25913,237B):page 空直返 -1 →
//   QStackedWidget::insertWidget(+0x60,index)→ FUN_005a7800(insertTab)
//   → FUN_005abe12(setTabToolTip)→ +0x30 低字节为 0 时
//   QTimer::singleShot(0,闭包 FUN_005aa7ee)。
int TabGroup::insertPage(int index, QWidget *page, const QString &title,
                         const QIcon &icon, const QString &tooltip)
{
	if (page == nullptr) // param_3==0 → -1 @005abe2e
		return -1;
	int idx = m_f60->insertWidget(index, page);          // 005abe36
	idx = m_f58->insertTabWithMeta(idx, title, icon);    // FUN_005a7800 @005abe6c
	m_f58->setTabToolTip(idx, tooltip);                  // FUN_005abe12 @005abe87
	if ((m_f30 & 0xff) == 0)                             // 005abe98
		QTimer::singleShot(0, this, &TabGroup::showAfterInsert); // singleShotImpl @005abeb4
	return idx;
}

// === insertPageBack(...) ===
// 转写 FUN_005abf12(0018:25960,22B)= FUN_005abe1c(index=-1)透传。
int TabGroup::insertPageBack(QWidget *page, const QString &title,
                             const QIcon &icon, const QString &tooltip)
{
	return insertPage(-1, page, title, icon, tooltip); // 005abf1b
}

// === showAfterInsert() ===
// 转写 FUN_005aa7ee(0018:24506,116B)case1(单发闭包):hide →
//   tabbar vcall +0x70(=FUN_005a81c6 族)→ setFixedHeight(vcall 返回值)
//   → show → *(+0x30)=1。中间两步 cited。
void TabGroup::showAfterInsert()
{
	hide(); // 005aa7ee case1
	// plVar1 = *(ctx+0x10)+0x58 = tabbar;
	//   (**tabbar_vt+0x70)(tabbar) — vcall(FUN_005a81c6 族)— cited — wave-2
	//   QWidget::setFixedHeight(vcall 返回值)— cited — wave-2(实参未解,不发明)
	show();
	m_f30 = 1; // *(tabGroup+0x30)=1 @005aa802
}

// === onCurrentChanged(int) ===
// 转写 FUN_005aa7b0(0018:24492,62B):count 越界检查(index<count && ≥0)
//   → QStackedWidget::setCurrentIndex(+0x60)→ FUN_008fb5ac(activate 信号0
//   = tabActivated)。
void TabGroup::onCurrentChanged(int index)
{
	if (index < m_f60->count() && index >= 0) { // 005aa7bd-7d
		m_f60->setCurrentIndex(index);          // 005aa780
		emit tabActivated(index);               // FUN_008fb5ac @005aa78d
	}
}

// === onTabMoved(int,int) ===
// 转写 FUN_005aa72a(0018:24464,125B):stack blockSignals →
//   widget(from) → removeWidget → insertWidget(to) → blockSignals(false)。
void TabGroup::onTabMoved(int from, int to)
{
	if (m_f60 == nullptr) // 语料空判 @005aa730(stack 空时 iVar2=0 直穿)
		return;
	m_f60->blockSignals(true);          // 005aa75b
	QWidget *w = m_f60->widget(from);   // 005aa76d
	m_f60->removeWidget(w);             // 005aa77d(实参 Ghidra 折叠 = w)
	m_f60->insertWidget(to, w);         // 005aa78e
	m_f60->blockSignals(false);         // 005aa7a2
}

// === onWidgetRemoved() ===
// 语料 FUN_005aa720(0018:24454,9B)→ FUN_005a7db8(+0x58,495B)未读
//   → cited;连接面在 fullAssemble 落。
void TabGroup::onWidgetRemoved()
{
	/* FUN_005a7db8 — cited — wave-2(体未读) */
}

// === onTabLayoutChanged() ===
// 语料 FUN_005ab7d8(0018:25427,59B):+0x68 为 0 直返;否则按
//   +0x80/0x88 钮 underMouse 位分叉 FUN_005ab79a(...)。FUN_005ab79a
//   (62B)未读 → cited;连接面在 fullAssemble 落。
void TabGroup::onTabLayoutChanged()
{
	/* FUN_005ab7d8 → FUN_005ab79a — cited — wave-2(体未读) */
}

// === onTabCloseRequested(int) ===
// 语料连接面:QTabBar::tabCloseRequested → FUN_008fb5e0(activate 信号3
//   = tabCloseRequested)信号转发。
void TabGroup::onTabCloseRequested(int index)
{
	emit tabCloseRequested(index); // FUN_008fb5e0 @008fb5e0
}

// === onHoverTimeout() ===
// 语料 FUN_005aa91e(0018:24605,58B)未读 → cited;连接面在
//   setHoverTimer 落。
void TabGroup::onHoverTimeout()
{
	/* FUN_005aa91e — cited — wave-2(体未读) */
}

// === setHoverTimer(double) ===
// 转写 FUN_005ad4a6(0018:26917,270B):seconds>0 → 无表则
//   new QTimer(this)→+0x48 + connect timeout→FUN_005aa91e → setInterval
//   (实参折叠 cited);else → 表存时 vcall +0x20(停表面 cited)→ +0x48=0。
void TabGroup::setHoverTimer(double seconds)
{
	if (seconds > 0.0) {                          // 005ad4d2
		if (m_f48 == nullptr) {                   // 005ad4d7
			m_f48 = new QTimer(this);             // 005ad528
			connect(m_f48, &QTimer::timeout, this, &TabGroup::onHoverTimeout); // 005ad4f0
		}
		// QTimer::setInterval(实参 Ghidra 折叠)— cited — wave-2(刻度未解)
	} else if (m_f48 != nullptr) {
		// (**timer_vt+0x20)()@005ad4c0 — cited — wave-2(停表面,不发明)
		m_f48 = nullptr;                          // *(this+0x48)=0 @005ad4c8
	}
}

// === setTabShapeMode(int) ===
// 转写 FUN_005ab88a(0018:25502,8B):+0x50 ← param_2 → FUN_005ab814。
void TabGroup::setTabShapeMode(int mode)
{
	m_f50 = mode;      // *(this+0x50) = param_2 @005ab88d
	applyTabShape();   // FUN_005ab814 @005ab894
}

// === applyTabShape() ===
// 转写 FUN_005ab814(0018:25397 起,113B):+0x50==1 → shape =
//   +0x54?5:1;+0x50==0 → shape = +0x54?4:0;其余分支(+0x50 其他值)
//   未读 cited。shape 值 0/1/4/5 = QTabBar RoundedNorth/RoundedSouth/
//   TriangularNorth/TriangularSouth(照抄语料常量)。
void TabGroup::applyTabShape()
{
	if (m_f50 == 1) {                                   // 005ab81f
		m_f58->setShape(m_f54 != 0 ? (QTabBar::Shape)5
		                            : (QTabBar::Shape)1); // 005ab829(实参 5/1)
	} else if (m_f50 == 0) {                            // 005ab83b
		if (m_f54 != 0) {
			m_f58->setShape((QTabBar::Shape)4);     // 005ab849
			return;
		}
		m_f58->setShape((QTabBar::Shape)0);         // 005ab854
	}
	// 005ab85f 起其余分支 — cited — wave-2(+0x50 其余值未读)
}

// === setUsesScrollButtons(bool) ===
// 转写 FUN_005ac522(0018:26271,62B):tabbar setUsesScrollButtons →
//   on:+0x68=1;off:FUN_005ab79a(this,0)(cited)+ +0x68=0。
void TabGroup::setUsesScrollButtons(bool on)
{
	m_f58->setUsesScrollButtons(on); // 005ac52f
	if (on) {
		m_f68 = true;                // *(this+0x68) = param_2 @005ac53a
		return;
	}
	// FUN_005ab79a(this,0)— cited — wave-2(62B 未读)
	m_f68 = false;                   // @005ac54e
}

// === setTabsClosable(bool) ===
// 转写 FUN_005ab8b4(0018:25543,297B):closable 现值!=param_2 才动:
//   tabbar setTabsClosable → off 时 disconnect tabCloseRequested→FUN_008fb5e0,
//   on 时重连(语料双分支照抄)。
void TabGroup::setTabsClosable(bool on)
{
	if (m_f58->tabsClosable() == on) // FUN_005ab8aa @005ab8c1
		return;
	m_f58->setTabsClosable(on);      // 005ab8cf
	if (!on) {
		disconnect(m_f58, &QTabBar::tabCloseRequested,
		           this, &TabGroup::onTabCloseRequested); // 005ab8de
		return;
	}
	connect(m_f58, &QTabBar::tabCloseRequested,
	        this, &TabGroup::onTabCloseRequested);     // 005ab90b
}
