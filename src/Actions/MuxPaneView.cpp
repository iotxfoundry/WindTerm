#include "MuxPaneView.h"
#include "JsEngine.h"
#include "ThemeIcons.h"
#include <QCoreApplication>
#include <cstring>
#include <QMenu>
#include <QVBoxLayout>

// === MuxPaneView(QWidget,MuxPane::Type) ===
// 转写 s_MuxPane_8de0c0(decomp-part-0028.c:25440,202B):
//   QWidget::QWidget(parent) → vt 011abbb8 / 011abd90(vt 表示,不落成员)
//   +0x30 ← FUN_008de0b0(DAT_011be6c8 −1 面板计数;返回值语义未解)
//   +0x34 ← param_2(Type);+0x38 ← shared_null(QString);+0x40 ← 0
//   setObjectName("MuxPane") → FUN_008de052(QVBoxLayout 装配)
// ctor 声明为两参:语料第 3 参 parent 经 QWidget 基类链,QWidget(ptr)
//   惯例由 Qt 显式传递,不另设默认值(语料无默认参证据,不发明)。
MuxPaneView::MuxPaneView(QWidget *parent, MuxPaneType type)
	: QWidget(parent)
	, m_f30(0)   // FUN_008de0b0 计数返回值,值语义未解 — cited — wave-2
	, m_type(type)
{
	setObjectName(QStringLiteral("MuxPane")); // s_MuxPane_8de0c0 @008de12c

	// FUN_008de052(0028:25410,86B):new QVBoxLayout → setContentsMargins →
	// setSpacing → setLayout。两调参数值反编译体为裸调用(常量被 Ghidra
	// 折叠为寄存器传递,不可读)→ 按铁律 3 不发明,记 cited。
	{
		QVBoxLayout *layout = new QVBoxLayout(this); // FUN_008de052 @008de06b
		// QLayout::setContentsMargins(...) — cited — wave-2(参数不可读)
		// QBoxLayout::setSpacing(...)      — cited — wave-2(参数不可读)
		setLayout(layout);                           // FUN_008de052 @008de086
	}
}

// === setCentralView(QWidget*) ===
// 转写 FUN_008de1a8(0028:25489,124B):
//   +0x40 == 新件 → 直返;旧件非空 → deleteLater;
//   layout() dynamic_cast<QVBoxLayout*> → addWidget(view,0,0) →
//   setFocusProxy → 存 +0x40 → show();layout 缺失/非 VBox → 直返。
void MuxPaneView::setCentralView(QWidget *view) // FUN_008de1a8
{
	if (m_central == view) // @008de1b8(+0x40 比较)
		return;
	if (m_central != nullptr) // @008de1bf(旧件 deleteLater)
		m_central->deleteLater();

	QLayout *layout = QWidget::layout(); // @008de1d0
	if (layout == nullptr)
		return;
	QVBoxLayout *vbox = dynamic_cast<QVBoxLayout *>(layout); // @008de1d9(__dynamic_cast → QVBoxLayout typeinfo)
	if (vbox == nullptr)
		return;

	vbox->addWidget(view, 0, 0);                 // QBoxLayout::addWidget(lVar1,param_2,0,0)
	setFocusProxy(view);                         // QWidget::setFocusProxy(param_1)
	m_central = view;                            // 存 +0x40
	QWidget::show();                             // @008de1fd
}

// === attachJsEngine(JsEngine*,kingMeta,appBridge,windowBridge) ===
// cited 预留方法(无自研行为):唯一行为 = 语料 FUN_00766192
// (0023:33030-44)的调用面 —— 创建 JsEngine 后即调
// s_MuxPane_64b102(engine)(引导体 = JsEngine::bootstrap,批 68
// 收编);真实触发时机 = Application 信号 mainWindow_connectSignals
// (0023:36614),我方无 Application 类 → 不发明,本方法由宿主在
// 语料对应装配位显式调用。
void MuxPaneView::attachJsEngine(JsEngine *engine, QObject *kingMeta,
                                 QObject *appBridge, QObject *windowBridge)
{
	if (engine != nullptr) // FUN_00766192 @0023:33042(引擎非空即引导)
		engine->bootstrap(kingMeta, this, appBridge, windowBridge);
	// paneMeta = this(MuxPaneView::staticMetaObject 持有者):语料
	//   s_MuxPane_64b102 第 5 步 "MuxPane" newQMetaObject(muxPaneMeta->
	//   metaObject())(0020:30239)注册对象 = MuxPane widget 类元对象。
	// kingMeta 置 nullptr 形态见头注(KingEnums.h 无 Q_OBJECT 承载,
	//   cited — wave-2)。
}

// === initThemeDir() ===
// 装配期一次调用:setThemeDir(applicationDirPath() + "/global/themes/")
//   —— 目录串语料实证 = FUN_00753fc6(0023:19097,387B)对
//   ApplicationTheme +0x18 的构造;ThemeIcons::setThemeDir 已转写
//   (ThemeIcons.cpp:137 g_themeDir)。语料中该目录串进入主题容器
//   的确切调用函数未解(mp 笔记 §未解)→ 整方法 cited,不发明触发链。
void MuxPaneView::initThemeDir()
{
	ThemeIcons::setThemeDir(
	    QCoreApplication::applicationDirPath() +
	    QStringLiteral("/global/themes/")); // FUN_00753fc6 @0023:19097
}

// === setTitle(QString) ===
// 转写 FUN_008de224(0028:25516,57B):operator==(this+0x38,param_2)
//   相等即返 @008de22d;否则 QString::operator= 赋值 @008de23b →
//   FUN_0091ddb8(this,&m_title)(QMetaObject::activate,MuxPane
//   staticMetaObject 011abde0,idx0,&arg)@008de243-4f = nameChanged
//   (idx0 名按 qmo_extract QMetaObject 权威)。
void MuxPaneView::setTitle(const QString &title)
{
	if (m_title == title)                        // operator== @008de224-2d
		return;
	m_title = title;                             // QString::operator= @008de23b
	emit nameChanged(m_title);                   // FUN_0091ddb8 @008de243-4f
}

// FUN_008c54a4(58B,0028.c:7553)页元数据取值真身:
//   FUN_00a85f62(this+0x20, key, invalid)(0035:2595 qmap_lower_bound_find;
//   未命中 → 无效 QVariant)。本面 = QMap::value(键) 同相。
QVariant MuxPaneView::metaValue(const QString &key) const
{
	return m_meta20.value(key); // @008c54a4
}

// KitView_vt9(119B,0028.c:7156)会话态真身:
//   asm @008c4ec8:cmpb +0x08 旗标 == 0 → vcall 虚槽 +0xb0(未初始化腿,
//   本波 cited 空 BA);否则 property("History")(0x11820e8 实读)
//   → QVariant::toByteArray。
QByteArray MuxPaneView::historyBlob() const
{
	return property("History").toByteArray(); // @008c4f0d-28
}

// 008c3c6a(1044B,0028.c:6341)pane 弹出菜单真身(结构段):
//   @008c3c6a if (vt+0x1c0 == FUN_008c4eae) return;
//   @008c3c7x cVar5 = (**vt+0x1c0)(this);!cVar5 → return;
//   @008c3c8x ctx = FUN_008c3c1a(this);空 → return;
//   @008c3cxx mod = FUN_0075d96c(app, *(int*)(event+0x14));
//   前缀串:0x4000000 → "Shift "(0xcb76d1)/0x2000000 → "Ctrl "(0xcb76d8);
//   其余分支 "Alt "(0xcb76de)/"Meta "(0xcb76e3)。
//   后续(条目构建/图标/弹出)cited。
// 008c3c6a(1044B,0028.c:6341)pane 弹出菜单 **全量**真身:
//   @008c3c6a vt+0x1c0 == FUN_008c4eae(默认腿)→ return;
//   @008c3c7x (**vt+0x1c0)(this) == false → return;
//   @008c3c8x ctxObj = FUN_008c3c1a(this);空 → return;
//   @008c3cbf mod = FUN_0075d96c(qApp, *(int*)(event+0x14))(修饰键);
//     0x04000000 → "Ctrl "(0xcb76d8)/0x02000000 → "Shift "(0xcb76d1)/
//     0x08000000 → "Alt "(0xcb76de)/0x10000000 → "Meta "(0xcb76e3);
//   @008c3d6x ctx = FUN_006926a0(&c, ctxObj);
//   @008c3d6x fmt = QString::fromAscii("%1 %2Popup", 10)(**实读**);
//   @008c3d8x name = FUN_008c3684(&s, this);
//   @008c3dfx full = fmt.arg(前缀).arg(name)(QtPrivate::argToQString);
//   @008c3e4x menu = FUN_00692ef0(ctx, full, this)(注册表按名取菜单);
//   @008c3e8x 非空 → QMenu::exec(menu, *(QPoint*)(event+0x28))(即 globalPos)
//     → (**(*menu+0x20))(menu)(销毁/关闭腿)。
//   ⇒ 右键菜单**不在本函数里造条目**:名字 = "<修饰键> <动作名>Popup",
//     由动作/配置面注册后在运行期查表;无该名即无菜单。
void MuxPaneView::showPanePopupMenu(QMouseEvent *event)
{
	// 门:vt+0x1c0 默认实现 / 虚槽返回 false / ctx 为空 → 直返(cited 虚槽面)
	if (event == nullptr)
		return;
	const unsigned int mod = static_cast<unsigned int>(event->modifiers());
	QString prefix;
	switch (mod) {
	case 0x04000000u: prefix = QStringLiteral("Ctrl "); break;  // 0xcb76d8
	case 0x02000000u: prefix = QStringLiteral("Shift "); break; // 0xcb76d1
	case 0x08000000u: prefix = QStringLiteral("Alt "); break;  // 0xcb76de
	case 0x10000000u: prefix = QStringLiteral("Meta "); break; // 0xcb76e3
	default: break;
	}
	// ctx = FUN_006926a0(&c, ctxObj)@008c3d6x — cited
	const QString name = QLatin1String("%1 %2Popup").arg(prefix).arg(QString()); // @008c3d6x
	// menu = FUN_00692ef0(ctx, name, this)@008c3e4x — cited(注册表按名取菜单)
	// if (menu) { menu->exec(event->globalPos());delete menu; }
	if (!name.isEmpty()) {
		// 注册表未建模 → 本条腿 cited(不发明菜单项)
	}
}

// 008c3684(263B,0028.c:5993)pane 菜单基名真身
QString MuxPaneView::paneMenuBaseName() const
{
	QString n = objectName();                                   // @008c36xx
	n.remove(QStringLiteral("Pane"));                            // @008c36ba(fromAscii "Pane")
	return n;
}

// 006926a0(34B,0021.c:18550)动作上下文真身(虚槽 +0x1f0)
QObject *MuxPaneView::actionContext() const
{
	// @006926a0 obj 非空 → (**(*obj+0x1f0))(obj);否则 0
	//   虚槽实现按宿主类;本面以自身承接并注记(cited)。
	return const_cast<MuxPaneView *>(this);
}

// 00692ef0(310B,0021.c:18914)按名取/建菜单真身
QMenu *MuxPaneView::findOrCreateMenu(QObject *ctx, const QString &name, QWidget *parent)
{
	if (name.isEmpty())                                          // @00692ef8(名空 → 0)
		return nullptr;
	if (ctx != nullptr) {
		// FUN_006926c2 = 线性扫表比名(memcmp,见 findMenuItemIndex);
		// 命中则 FUN_00692a70(ctx, &desc, parent) 非空即返 — cited
	}
	// 未命中:new QMenu(0x30, tr(name), parent)@00692fd0
	return new QMenu(name, parent);
}

// 00692a70(1119B)按动作项建菜单真身(结构段)
QMenu *MuxPaneView::buildActionMenu(QObject *ctx, void *actionItem, QWidget *parent)
{
	// ① 向上找宿主窗(011a69d0)
	QWidget *w = parent;
	while (w != nullptr) {
		if (dynamic_cast<QMainWindow *>(w) != nullptr) // 宿主窗类型(cited)
			break;
		w = w->parentWidget();
	}
	if (w == nullptr)
		return nullptr;                    // ① 失败 → 0
	if (ctx == nullptr)                    // ② ctx 空 → 0
		return nullptr;
	if (actionItem == nullptr)
		return nullptr;

	// ③④ 菜单标题 = tr(动作项名);⑤ 内容在 aboutToShow 时懒填充
	auto *menu = new QMenu(QStringLiteral("actions"), parent); // @00692b12/25(tr 面 cited)
	connect(menu, &QMenu::aboutToShow, menu, [menu]( ) {
		// FUN_0076cb16(动作项子树 → 逐项 addAction/addMenu)@闭包 impl FUN_00694b90
		//   — cited(不发明条目)
		Q_UNUSED(menu);
	});
	return menu;
}

// 006926c2(164B)按名线性查找真身
int MuxPaneView::findMenuItemIndex(const QList<QByteArray> &names, const QByteArray &name)
{
	for (int i = 0; i < names.size(); ++i) {      // plVar6 逐项
		if (names.at(i).size() == name.size() &&
		    memcmp(names.at(i).constData(), name.constData(), name.size()) == 0) // @006926c2
			return i;                             // 命中
	}
	return names.size();                          // 未命中 = 末位
}
