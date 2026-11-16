#include "Actions/Menu/ToolBarBuilder.h"

#include "Widgets/Faces/BreadCrumbFace.h"
#include "Widgets/Faces/SearchEditFace.h"

#include <QAction>
#include <QLabel>
#include <QMenu>
#include <QStyle>
#include <QToolBar>
#include <QToolButton>
#include <QVariant>

#include "Actions/Menu/ActionFactory.h"
#include "Actions/Kit/KitWindowFace.h"
#include "Actions/Kit/KitWindowFactory.h"
#include "Actions/Kit/MainWindowFace.h"
#include "Editor/Config/CGlobalConfigFace.h"

// SharedConfigHandlerFace 是 CGlobalConfigFace 的公开嵌套型(批 147);
// 头内以全局名前置引用 — 此处 using 对齐(CGlobalConfigFace 头实读,
// 类体定义于 CGlobalConfigFace 域外平铺 — CGlobalConfigFace.h:51)。
using CGlobalConfigFace::SharedConfigHandlerFace;

namespace ToolBarBuilder {

// ======== 组菜单查/建(FUN_00692ef0 消费同型;新建腿 = 批 133 真身)========
// 语料:views 容器 +0x60 handler children 逐节点键比较(FUN_006926c2 键
//   面,mValue==name)→ 命中取缓存 QMenu;未命中 tr(name) → new QMenu。
//   views 树菜单缓存载体 = 现役 kitFindOrCreateGroupMenu 同判(容器
//   节点面未定型 → 查建腔:每 buildToolbar 现查现建,cited — wave-2)。
static QMenu *findOrMakeGroupMenu(QMainWindow *mainWindow,
                                  const QByteArray &name,
                                  QWidget *parent)
{
	if (name.isEmpty())
		return nullptr;                          // S1 @00692ef7(空名 null)
	// S2 缓存查腔 cited(容器 QMenu 节点缓存面未定型;每次新建同相于
	//   未命中腿 — 语义与批 133 判一致)
	return new QMenu(QObject::tr(name.constData()), parent); // S3 @00692fbf-0069301d
}

// ======== case3 动作条目(语料 006946bc-00694995 区段转写)========
// S1 克隆 mw+0x60 工厂动作(FUN_00767b40 → FUN_00666de2,744B):
//   getOrCreate(名)→ 新 QAction{text,icon,toolTip,shortcut 拷} +
//   setProperty("dynamic",QVariant(action*)) + triggered → 0066a148
//   (sender→QAction cast → js_actionFire;仓库 ActionFactory 触发链
//   同构 — 复用 getOrCreate,克隆腿语义在案)。
//   仓库 ActionFactory = wind.actions 装配域的 00665dc2/00666de2 同体
//   转写(批 35);工厂宿主语料 *(mw+0x60) 槽未建模(KitBar.h 布局
//   缺口注同款)→ 静态表承载先例(KitBar.cpp actionFactoryGetOrCreate)。
//   本批:轻克隆腿 = 语料语义直接转写(库内 ActionFactory::getOrCreate
//   返回表内 QAction 本体,非克隆 — 与 00666de2 "每次新 QAction" 差异
//   由 cloneFactoryAction 显式补齐)。
static QAction *cloneFactoryAction(QMainWindow *mainWindow,
                                   const QByteArray &name)
{
	Q_UNUSED(mainWindow);                    // 语料 mw+0x60 槽未建模(见上)
	// FUN_00666de2 @00666e12-6e:actionFactory_getOrCreate(name)→
	//   新 QAction(text)→ icon/icon 拷 → toolTip 拷 → shortcut 拷。
	QAction *proto = ActionFactory::getOrCreate(name);   // @00666de2 首句
	if (proto == nullptr)
		return nullptr;                          // 语料空名短路同相(00665e70)
	QAction *action = new QAction(proto->text(), mainWindow); // @00666e23(text 构造)
	action->setIcon(proto->icon());          // @00666e59-5d
	action->setToolTip(proto->toolTip());    // @00666e79-7d
	action->setShortcut(proto->shortcut());  // @00666eaf-b3
	// @00666ef4-f8:setProperty("dynamic",QVariant(QAction*,action))
	//   (DAT_011c0b04 = QAction* metatype 注册一次;QVariant 承接同型)
	action->setProperty("dynamic", QVariant::fromValue(action));
	// @0066704x-709:connectImpl(triggered → FUN_0066a148)。
	//   FUN_0066a148(103B,全读):sender→QMetaObject::cast(QAction)
	//   → QJSValue(1)→ js_actionFire(out,sender,"state",undefined)
	//   — js 触发链 = ActionFactory::getOrCreate 现役 connect 同构
	//   (ActionFactory.cpp:124,批 37/50 转写);克隆体 data() 未设
	//   script → js_actionFire 的 data 门同相空转(00669860 门)。
	return action;
}

// ======== case3 popupMode 择位(FUN_00767c4a → action_registerDataType)========
// action_registerDataType(0066598c,902B,0020.c:49878 全读):
//   property("dynamic") QAction* 门(QVariant::canConvert(dat_11c0b04)
//   + QMetaObject::cast 双门)→ QAction::data();null → 0;canConvert
//   (QString=10)→ 1;否则 canConvert(QJSValue)(dat_011c18dc 注册)。
//   返回 char 语义 = data 可转串/JS → 1:InstantPopup(2);
//   0 → MenuButtonPopup(1)。语料式:~-(uint)(c==0)+2 = c?1:2。
//   QJSValue canConvert 腿面(cited — wave-2;clone data 恒空 → 恒 0 腿)。
static int popupModeFor(QAction *action)
{
	// 语料门全相:dynamic 门(clone 体恒有)→ data() 判。
	const QVariant dv = action->property("dynamic");   // @006659a4
	if (!dv.canConvert<QAction *>())
		return 1;                                // 门败腿 = c==0 → mode 1
	QAction *linked = dv.value<QAction *>();
	if (linked == nullptr)
		return 1;                                // QMetaObject::cast 败腿
	const QVariant data = linked->data();         // @00665a14-1c
	const char c = (!data.isNull()
	                && (data.typeId() == QMetaType::QString
	                    || data.canConvert<QString>()))
	                   ? 1 : 0;                  // canConvert(10)/QJSValue 腿
	                                           //   (QJSValue 腿 cited — wave-2)
	return (c == 0) ? 2 : 1;                     // ~-(uint)(c==0)+2 @006946d2
}

QWidget *buildActionEntry(QMainWindow *mainWindow, QToolBar *bar,
                          const SharedConfigHandlerFace &node)
{
	const QByteArray name = node.m_value.toByteArray();   // +0x20 值槽(键名)
	// S1 克隆 + reparent(mainWindow 域)@00694610-40。
	QAction *action = cloneFactoryAction(mainWindow, name);
	if (action == nullptr)
		return nullptr;
	action->setParent(mainWindow);                    // QObject::setParent @0069462x

	// --- popup 位面腿(@00694a1a-a32):+0x11 bit3 置 → 子菜单查建 ---
	if (node.popupFlag()) {                           // *(byte+0x11)&8
		QMenu *sub = findOrMakeGroupMenu(mainWindow, node.popupName(), mainWindow); // FUN_00692ef0(views +0x28→views 树)
		if (sub != nullptr) {
			// @00694a3e-aaa:new QToolButton → setDefaultAction →
			//   setMenu → setPopupMode(menu-button/instant 择位)→
			//   addWidget 腿(经出口 @0069455e)。
			auto *btn = new QToolButton(mainWindow);  // operator_new(0x30)@00694a42
			btn->setDefaultAction(action);            // @00694a4b 区
			btn->setMenu(sub);                        // @00694a5x
			btn->setPopupMode(static_cast<QToolButton::ToolButtonPopupMode>(
			    popupModeFor(action)));               // @006946bc 择位(2/1)
			return btn;                               // → addWidget 出口
		}
		// 子菜单 null(空名)→ 重复 bit3 判语料重读 @00694ac5(unreachable
		//   块同相)→ addAction 腿(见尾 addAction 出口)。
		return nullptr;                               // addAction 腿标记
	}

	// --- 空间不足钮腿(@0069472e-95 区;popupFlag 清)---
	if (node.columns() != 0) {                        // *(int*)(*(lVar15+8)+4)!=0
		                                              //   (语料 +0x10 高 nibble Columns 面)
		auto *btn = new QToolButton(mainWindow);      // operator_new(0x30)@0069472e
		btn->setDefaultAction(action);                // @00694768-bc(ExternalRefCount
		                                              //   卫 = Qt5 值语义承接)
		// @006947ca-f9:setProperty("Popup",QByteArray 名)+
		//   setProperty("Columns",uint 高 nibble)— 弹出菜单消费面
		//   (s_ToolBarPopup @0069362x 读同名属性)数据腿,本批真身。
		btn->setProperty("Popup", QVariant(node.popupName()));
		btn->setProperty("Columns", QVariant(uint(node.columns())));
		// @00694895-911:connectImpl(action::triggered → FUN_006941d5,
		//   functor{1,006941d5,refdata,button})。
		QObject::connect(action, &QAction::triggered, btn,
		                 [action] { actionTriggered(action); });
		return btn;                                   // → addWidget 出口
	}

	// --- addAction 腿(@006949a6-ae else 腿 / @00694a32 unreachable 重读)---
	return nullptr;                                   // 出口调用方 addAction
}

// ======== 触发槽 — FUN_006941d5(152B,0021.c:19615 全读)========
// param_1==1(激活):functor 存的 button(+0x18)→ defaultAction →
//   property("Popup") 名首字节(@0069420e)**语料直读第一字符作名**
//   (uVar1 = **(char**)(param_4+8) 单字节;真名槽读面为 0069422x 邻域
//   3293B 弹出体 — 单字节入参形态照录;弹出体 cited — wave-2)→
//   s_ToolBarPopup_693470(&out,uVar1)。
// param_1==0(析构):functor 消偿(Qt5 连接托管承接,无手写)。
void actionTriggered(QAction *action)
{
	// s_ToolBarPopup_693470(3293B,0021.c:19155)— cited — wave-2:
	//   Grid 弹出菜单体(QGridLayout + "Popup"/"Columns" 属性消费)。
	//   本批落:property("Popup") 名读出(0069362x 同面),弹出网格体
	//   不发明;名空短路同相(体首门)。
	const QByteArray popup = action->property("Popup").toByteArray();
	if (popup.isEmpty())
		return;                                   // 体首门同相(空名短路)
	// cited — wave-2:s_ToolBarPopup_693470(popup)网格弹出体未转写。
}

// ======== 主面 — toolbar_build(00694276,2164B,0021.c:19664)========
// 全读序(kuna 复核 2026-11-16):
//   S0 @006942a1-30x:*out = shared_null;qcoreapp_self_get();向上走
//     parentWidget() 链 __dynamic_cast 至 "10MainWindow"(typeinfo
//     0x11a69d0 ELF 实读);param_4 null / 链尽 → return;views 树空
//     (*(long*)param_2==0)→ return。
//   S1 @0069430d-311:new QToolBar(parent)。
//   S2 @00694324-3x:style_getPixelMetric(0x41)(FUN_00752766,74B,
//     0023.c:17901 全读:style() vcall vt+0xe0 metric=0x41;null →
//     0x1000000010)→ setIconSize(QSize(m,m))。
//   S3 @00694375-84:QMetaObject::tr(组名)→ simplified → setWindowTitle。
//   S4 @006943f6-0d:setObjectName("ToolBar")(DAT_1182680 → 0xcb9b17
//     "ToolBar" ELF 实读)。
//   S5 @0069444c:FUN_006926c2(views 树,组名)子节点定位(命中段/
//     未命中 = 全树;遍历 [begin,end))。
//   S6 逐节点 switch(*(byte*)(node+2)&0xf) — kind 位面(批 147 权威):
//     0 addSeparator;1 Spacer QWidget(SizePolicy 0x570000 = Fixed×
//     Expanding?语料字面 + vtable+0x68 setMaximumHeight?(**(vt+0x68))
//     (w,1) 直 vcall 照录 — cited 语义);2 递归 toolbar_build(子栏)
//     → 出列 append;3 动作(case3 见 buildActionEntry);4 Label
//     (tr(名) new QLabel);5 AddressBar(FUN_005211fe ctor cited);
//     6 FilterEdit(FUN_0057eb0c ctor cited)→ 各 addWidget 出口;
//     default 跳过。
//   S7 @00694a9x-c0x:actions() 空判 — 空 → delete bar(vt+0x20 vcall
//     = dtor);非空 → 出列 append(FUN_00694d14)。
// 返回 *out(QList<QString> 出列面;空 = 失败/空栏判)。
static QList<QToolBar *> buildOne(QMainWindow *mainWindow,
                                  const SharedConfigHandlerFace &root,
                                  const QByteArray &groupName,
                                  QWidget *parent)
{
	QList<QToolBar *> out;                   // *param_1 = shared_null @00694278
	// --- S0 主窗上溯(语料 param_4 链走;语料逐层 +8/+0x10 = parentWidget
	//     装箱面,Qt5 面等价 parentWidget() 链 — KitBar::addKit S0 同判)---
	QWidget *mw = mainWindow;
	for (QWidget *w = parent; w != nullptr; w = w->parentWidget()) {
		if (dynamic_cast<MainWindowFace *>(w) != nullptr
		    || dynamic_cast<QMainWindow *>(w) != nullptr) { // 0x11a69d0 链走
			mw = w;
			break;
		}
	}
	if (dynamic_cast<QMainWindow *>(mw) == nullptr)
		return out;                              // 链尽/无主窗 → return @006942bx
	if (root.m_begin == root.m_end)
		return out;                              // views 树空 @00694303

	// --- 定位组节点(FUN_006926c2 键面,0021.c:18568 全读):
	//     children 逐节点 m_value==groupName;命中返回迭代器对 — 语义
	//     = 命中节点(组);其 children [+0x8,+0x10) 为后续遍历段
	//     (0069444x 段 local_50 = *(hit+8) 起,哨兵 *(hit+0x10))。
	//     未命中 → 返回 [end,end)(全树尾),children 空 → 零条目空栏。
	const SharedConfigHandlerFace *group = nullptr;
	{
		const auto *p = root.m_begin;
		const auto *end = root.m_end;
		for (; p != end; ++p) {
			const QByteArray k = (*p)->m_value.toByteArray(); // +0x20 值槽键面
			if (k == groupName) {                 // size==n && memcmp @0069270x
				group = *p;
				break;
			}
		}
	}
	if (group == nullptr)
		return out;                               // 未命中 [end,end) 段空同相

	// --- S1 new QToolBar(parent)@0069430d ---
	auto *bar = new QToolBar(parent);

	// --- S2 setIconSize(style metric 0x41)@00694324 ---
	// 字面 0x41 照录(铁律"语料字面照抄,语义名不发明";5.15.2 表
	//   0x41=PM_SpinBoxSliderHeight/别名折叠表 0x45=PM_ToolBarIconSize
	//   — 版本表差,字面权威)。
	const int m = mw->style()->pixelMetric(QStyle::PixelMetric(0x41)); // FUN_00752766 @0069432x
	bar->setIconSize(QSize(m, m));            // QSize 双同值(SHL 32|OR 实证)

	// --- S3 tr(组名).simplified → windowTitle @00694375 ---
	bar->setWindowTitle(
	    QObject::tr(groupName.constData()).simplified()); // @00694375-84

	// --- S4 objectName("ToolBar")@006943f6 ---
	bar->setObjectName(QStringLiteral("ToolBar"));   // DAT_1182680→"ToolBar"

	// --- S5/S6 逐节点构建(组节点 children [+0x8,+0x10) 段)---
	bool any = false;                          // actions() 空判对位(零条目)
	for (auto **p = group->m_begin; p != group->m_end; ++p) {
		const SharedConfigHandlerFace &node = **p;
		switch (node.kind()) {                 // *(byte*)(node+2)&0xf @0069444x
		case 0:                                // Separator @0069445x
			bar->addSeparator();               // QToolBar::addSeparator
			any = true;
			break;
		case 1: {                              // Spacer @006946bc-702
			auto *w = new QWidget(bar);        // operator_new(0x30)+QWidget
			w->setSizePolicy(QSizePolicy(0x570000)); // 语料字面 @006946e2
			// (**(vt+0x68))(w,1) 直 vcall — cited — wave-2(槽语义
			//   未解;0x570000 = Fixed 横向/Expanding 纵向?不发明)。
			bar->addWidget(w);                 // 出口 @0069455x
			any = true;
			break;
		}
		case 2: {                              // ToolBar 递归子栏 @00694675
			// toolbar_build(out,views,子节点,parent)@0069470x:
			//   子节点键 = node.m_value;子段 = node children。
			QByteArray childName = node.m_value.toByteArray();
			QList<QToolBar *> subs = buildOne(mainWindow, root, childName, parent);
			out.append(subs);                  // FUN_00694de0 出列 append
			break;                             // 子栏不入本栏(出列直收)
		}
		case 3: {                              // Action @00694610-995
			QWidget *entry = buildActionEntry(mainWindow, bar, node);
			if (entry != nullptr) {
				bar->addWidget(entry);         // 钮腿出口 @0069455e
			} else if (node.popupFlag() && node.columns() == 0) {
				// addAction 腿(clone 后无钮面):@00694a32/@006949ae。
				const QByteArray nm2 = node.m_value.toByteArray();
				QAction *a2 = cloneFactoryAction(mainWindow, nm2);
				if (a2 != nullptr) {
					a2->setParent(mainWindow);
					bar->addAction(a2);
				}
			}
			any = true;                        // 条目消费(clone 败同相吞)
			break;
		}
		case 4: {                              // Label @006945b3-5f6
			const QByteArray t = node.m_value.toByteArray();
			auto *lab = new QLabel(QObject::tr(t.constData()), bar); // @006945c8
			bar->addWidget(lab);               // 出口 @0069455x
			any = true;
			break;
		}
		case 5: {                              // AddressBar @0069453f
			// FUN_005211fe(162B)ctor(cited → 批 253 真身 AddressBarFace;
			//   BreadCrumb 基座 48 字节 = operator_new(0x48) 同相)。
			auto *addr = new AddressBarFace(bar); // @0069453f new + ctor
			bar->addWidget(addr);                 // 出口 @0069455x
			any = true;
			break;
		}
		case 6: {                              // FilterEdit @006946a0
			// FUN_0057eb0c(200B)ctor(cited → 批 255 真身 FilterEditFace;
			//   operator_new(0x80) + +0x78 QTimer 同相)。
			auto *filter = new FilterEditFace(bar); // @006946a0
			bar->addWidget(filter);                 // 出口同 case 5
			any = true;
			break;
		}
		default:
			break;                             // default 跳过 @0069457f
		}
	}

	// --- S7 空栏判 @00694a9x-afx:actions() 空 → delete bar;非空 → 出列 ---
	const QList<QAction *> acts = bar->actions();
	if (acts.isEmpty() && !any) {
		delete bar;                                // vt+0x20 vcall dtor @00694aex
		return out;                                // 空栏不收
	}
	out.append(bar);                               // FUN_00694d14 append
	return out;
}

// 8bade2 工具栏段(0027.c:77809-788x)全组遍历转写:
//   menu() 容器(lVar8 → FUN_006926a0 = kit->menu())views 树(+0x60)
//   children 逐组 toolbar_build(out,views,组名,this)→ 出列逐栏
//   addToolBar + 每栏 qt_qFindChildren(QToolButton/邻型)布局微调腿
//   (findChildren 消费段 = 0x8bb07d-88x,cited — wave-2:样式位腿)。
void buildAllToolbars(QMainWindow *mainWindow)
{
	if (mainWindow == nullptr)
		return;
	// 容器 = menu() 虚槽(批 140 face 面):mainWindow 上溯 KitWindowFace。
	KitWindowFace *kit = nullptr;
	for (QWidget *w = mainWindow; w != nullptr; w = w->parentWidget()) {
		if ((kit = dynamic_cast<KitWindowFace *>(w)) != nullptr) // 011ab390 @008b9d2x
			break;
	}
	if (kit == nullptr)
		return;                                    // 容器缺 → 直返(语料 lVar8 null 同相)
	CGlobalConfigFace *cfg = kit->menu();          // FUN_006926a0 @008b9d5x
	if (cfg == nullptr)
		return;
	const SharedConfigHandlerFace &views = cfg->m_views; // +0x60
	// 8bade2 传组名 "Kit"(DAT_11826e0 → 0xd0e715 "Kit" ELF 实读)单组腿:
	//   本公开面 = 全组遍历(m_views 逐顶层节点;同名组只首命中段 —
	//   FUN_006926c2 单段语义)。"Kit" 单组腿另有 buildToolbar 公开。
	for (auto **p = views.m_begin; p != views.m_end; ++p) {
		const QByteArray groupName = (*p)->m_value.toByteArray(); // 组名键面
		QList<QToolBar *> bars = buildOne(mainWindow, views, groupName, mainWindow);
		for (QToolBar *bar : bars) {
			mainWindow->addToolBar(bar);           // QMainWindow::addToolBar @008bb07d
			// @008bb0b0-88x findChildren 布局微调腿 — cited — wave-2
			//   (样式位 4/5/3 置位腿,呈 QToolButton/QWidget 双表消费)。
		}
	}
}

QToolBar *buildToolbar(QMainWindow *mainWindow, const QByteArray &groupName)
{
	if (mainWindow == nullptr)
		return nullptr;
	// 同 buildAllToolbars 容器腿;单组版本(0x8bb018 调用点同名直传 "Kit")。
	KitWindowFace *kit = nullptr;
	for (QWidget *w = mainWindow; w != nullptr; w = w->parentWidget()) {
		if ((kit = dynamic_cast<KitWindowFace *>(w)) != nullptr)
			break;
	}
	if (kit == nullptr)
		return nullptr;
	CGlobalConfigFace *cfg = kit->menu();
	if (cfg == nullptr)
		return nullptr;
	const QList<QToolBar *> bars =
	    buildOne(mainWindow, cfg->m_views, groupName, mainWindow);
	return bars.isEmpty() ? nullptr : bars.first(); // 单组首栏(多栏仅递归子栏态)
}

} // namespace ToolBarBuilder
