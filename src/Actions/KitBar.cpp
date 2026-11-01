#include "KitBar.h"

#include <QAbstractButton>
#include <QAction>
#include <QButtonGroup>
#include <QKeySequence>
#include <QMap>
#include <QSizePolicy>
#include <QToolButton>
#include <QVariant>

#include "ActionFactory.h"
#include "ThemeIcons.h"

// === KitBar(QWidget*) ===
// 转写 FUN_008b31b6(0027:71172,420B):
//   QToolBar::QToolBar(param_1,param_2)→ vtable=KitBar →
//   +0x30 QList(shared_null)→ +0x38/+0x40 ← 0 →
//   objectName("KitBar")@008b321b-34 → King::registerBarsAndPanes(&out,"KitBar")
//   → setWindowTitle(out)@008b3287 → setAttribute(0x37,1)@008b32cc →
//   setAllowedAreas(3)@008b32d8 → setFloatable(false)@008b32e2 →
//   FUN_008b3178(尾装)。
// 注:setAttribute 第二参 0x37 = Qt::WA_ 常量(0x37 = 55 = WA_StyledBackground
//   邻域;语料字面照抄,语义名不发明);setFloatable(false) = SUB81(...,0)。
KitBar::KitBar(QWidget *parent)
	: QToolBar(parent)
	, m_f30()   // *(this+0x30) = QListData::shared_null @008b31e2
	, m_f38(0)  // *(this+0x38) = 0 @008b31ea
	, m_f40(0)  // *(this+0x40) = 0 @008b31f2
{
	setObjectName(QStringLiteral("KitBar"));       // @008b321b-34
	// King::registerBarsAndPanes(&out,QString("KitBar"))@008b3269-8b →
	//   QWidget::setWindowTitle(out)@008b3287 — cited — wave-2
	//   (King::registerBarsAndPanes 未落库,标题合成面不发明)
	setAttribute(Qt::WidgetAttribute(0x37), true); // @008b32cc(语料字面 0x37)
	setAllowedAreas(Qt::ToolBarAreas(3));          // @008b32d8(语料字面 3)
	setFloatable(false);                           // SUB81(param_1,0)@008b32e2
	tailAssemble();                                // FUN_008b3178 @008b32ec
}

// === tailAssemble() ===
// 转写 FUN_008b3178(0027:71156,62B):layout() 非空 →
//   QLayout::setContentsMargins / QLayout::setSpacing(实参 Ghidra 折叠)。
void KitBar::tailAssemble()
{
	if (layout() != nullptr) { // QWidget::layout @008b3182
		// QLayout::setContentsMargins / QLayout::setSpacing
		//   (实参 Ghidra 折叠)— cited — wave-2
	}
}

// === makeToolButton() ===
// 转写 FUN_008b30f2(0027:71137,126B):new 0x30 QToolButton(param_1)
//   → setIcon/setText/setToolTip/setCheckable(p5)/setFocusPolicy(0=NoFocus)。
// 实参序经汇编 008b3122-008b3159 定案(四参:text,toolTip,icon,checkable;
//   Ghidra 源内折叠为单参形)。调用点 addKit@008b3ec8:
//   FUN_008b30f2(param_1,&local_108(tr 标题),&local_f8(tooltip),
//   &local_100(icon),1)。
QToolButton *KitBar::makeToolButton(const QString &text,
                                    const QString &toolTip,
                                    const QIcon &icon, bool checkable)
{
	auto *btn = new QToolButton(this);            // QToolButton::QToolButton @008b3122
	btn->setIcon(icon);                           // QAbstractButton::setIcon @008b3129
	btn->setText(text);                           // QAbstractButton::setText @008b312f
	btn->setToolTip(toolTip);                     // QWidget::setToolTip @008b3135
	btn->setCheckable(checkable);                 // QAbstractButton::setCheckable @008b313b(语料 SUB81(this,0)→ false 恒定,实参 p5)
	btn->setFocusPolicy(Qt::NoFocus);             // QWidget::setFocusPolicy(this,0)@008b3141
	return btn;                                   // @008b3159
}

// === addKitButtonToBar() ===
// 转写 FUN_008b305c(0027:71110,141B):+0x38 空 → new 0x30 QWidget(this)
//   → setSizePolicy(0x750000 语料字面)→ QToolBar::addWidget(spacer)
//   → +0x38 = 返回值;force || spacer==0 → addWidget(btn),否则
//   insertWidget(在 spacer 之前)。语料形参 param_1 = this(param_1+0x38
//   /QToolBar 基上调用,param_2 折叠 — 汇编 008b30a6-008b30d4 三参序
//   (this,btn,force)实证)。
void KitBar::addKitButtonToBar(QWidget *btn, bool force)
{
	QWidget *spacer = m_f38;                     // *(this+0x38)@008b3062
	if (spacer == nullptr) {
		spacer = new QWidget(this);              // operator_new(0x30)+QWidget::QWidget @008b30a6
		QSizePolicy sp;                          // 语料 0x750000 打包(序列化形参折叠)
		spacer->setSizePolicy(sp);               // setSizePolicy(0x750000)@008b30b2(语料字面,Ghidra 打包折叠 — Qt5 面缺逐字段值,cited 形参)
		m_f38 = spacer;                          // @008b30c4
		QToolBar::addWidget(spacer);             // @008b30c8
	}
	if (force || spacer == nullptr) {
		QToolBar::addWidget(btn);                // @008b30d4(语料 force || spacer 缺失分支)
	} else {
		// @008b30e1(spacer 之前):语料 Qt4 面整数索引插入;Qt5 面
		//   以 actions() 定位 spacer 的 QAction 后 before 插入。
		const auto acts = actions();
		for (QAction *a : acts) {
			if (QToolBar::widgetForAction(a) == spacer) { // widgetForAction 反查(spacer 即 widget)
				QToolBar::insertWidget(a, btn);
				return;
			}
		}
		QToolBar::addWidget(btn);                // 兜底(语料 spacer 缺失分支同路)
	}
}

// === buttonForIndex() ===
// 转写 FUN_008b337e(0027:71240,67B):遍历 +0x30 QList(尾→头,
//   puVar5 自 begin(=d+0x10+begin*8) 起)→ 节点 *piVar4 == param_2
//   → 返回 *(piVar4+4)(节点 +0x20 按钮);未命中 → 0。
//   语料 begin/end 槽 = +8/+0xc(QListData::begin 略高 — 行为面同遍历)。
QToolButton *KitBar::buttonForIndex(int index) const
{
	for (int i = m_f30.size() - 1; i >= 0; --i) {
		if (m_f30.at(i).index == index)          // 节点 +0 == index
			return m_f30.at(i).button;           // *(piVar4+4)
	}
	return nullptr;
}

// === buttonForTitle() ===
// 转写 FUN_008b33c2(0027:71271,100B):自 begin 头起遍历 +0x30 →
//   operator==(节点 +8 QString,param_2)→ 返回节点 +0x10;未命中 0。
QToolButton *KitBar::buttonForTitle(const QString &title) const
{
	for (int i = 0; i < m_f30.size(); ++i) {
		if (m_f30.at(i).title == title)          // operator== @008b33e9
			return m_f30.at(i).button;           // *(lVar3+0x10)
	}
	return nullptr;
}

// === setCheckedByIndex() ===
// 转写 FUN_008b3426(0027:71298,36B):lVar1 = FUN_008b337e(this,param_2)
//   → 非空 → QAbstractButton::setChecked(lVar1,p3)。
// 注:36B 体量装不下第二参传递,Ghidra 折叠(SUB81(this,0));
//   汇编 008b3442 edx = p3 实证第二参为透传。查得即 setChecked。
void KitBar::setCheckedByIndex(int index, bool checked)
{
	QWidget *btn = buttonForIndex(index);         // FUN_008b337e @008b3432
	if (btn != nullptr)
		static_cast<QAbstractButton *>(btn)->setChecked(checked); // @008b3439
}

// === setCheckedByTitle() ===
// 转写 FUN_008b344a(0027:71314,36B):同 FUN_008b3426,查面换
//   FUN_008b33c2(标题)。
void KitBar::setCheckedByTitle(const QString &title, bool checked)
{
	QWidget *btn = buttonForTitle(title);         // FUN_008b33c2 @008b3456
	if (btn != nullptr)
		static_cast<QAbstractButton *>(btn)->setChecked(checked); // @008b345d
}

// === addKit() ===
// 转写 FUN_008b346e(0027:71330,9743B)= KitBar::addKit(int index,
//   const QString &title, const QString &iconName):
//   S0 卫(71335-71392)→ S1 tr+图标(71393-71415)→ S2/S3 键值 map
//   (71416-72640,Ghidra 内联展开 — QMap 委托,外库边界先例)→
//   S4 find(72640-72690)→ S5 actionFactory(72588,FUN_00767b36)→
//   S6 快捷键/tooltip(72980-73060)→ S7 按钮+setProperty("kit")
//   (73064-73085,DAT_00c8b3d1="kit" 二进制实证)→ S8 登记 +0x30
//   (73086-73095)→ S9 按钮组+挂载(73098-73111)→ S10 connect
//   (73113-73121)→ S11 清理。
// 唯一调用者:s_HistoryHints_7664a2(0023:33200)。
void KitBar::addKit(int index, const QString &title, const QString &iconName)
{
	// --- S0 卫(71335-71392)---
	// 语料:*(long *)(*(long *)(param_1+8)+0x10) == 0 → return;
	//   __dynamic_cast(·,&QWidget::typeinfo,&PTR_PTR_011a69d0,0)==0 →
	//   return(71351-71392)。语义:parentWidget 链取子 Widget,
	//   dynamic_cast 失败即弃。Qt5 面等价 = parentWidget() 判空 +
	//   qobject_cast<QWidget*>(语料 +8/+0x10 链为 Qt5 QObject::children
	//   装箱面,行为取 parent Widget 直接卫)。
	QWidget *pw = parentWidget();                 // 语料 *(this+8) 链 @71335
	if (pw == nullptr)
		return;                                   // @71336(链空)
	if (qobject_cast<QWidget *>(pw) == nullptr)
		return;                                   // __dynamic_cast @71351

	// --- S1 标题/图标(71393-71415)---
	QString trTitle = tr(title.toUtf8().constData()); // toUtf8_helper+QMetaObject::tr @008b3500-14
	QIcon icon = ThemeIcons::loadSvg(iconName, QString()); // theme_icon_load_svg(&local_100,DAT_011c1ce0,param_4,"")@008b3552 — 委托(00756cd6 落库 ThemeIcons)

	// --- S2/S3 QMap 装配(71416-72640)---
	// 语料:fromAscii("Editor")/QByteArray("Window.ActivateEditor")/
	//   fromAscii("Terminal")/QByteArray("Window.ActivateTerminal")
	//   → QMapDataBase::createData/FUN_008b7ba8(rebalance)/createNode
	//   两次插入;整段 ~1200 行为 Ghidra 内联展开(含释放墙)→
	//   委托真 QMap(外库边界,同 yaml-cpp 先例; cited — Ghidra 展开)。
	QMap<QString, QByteArray> cmdMap;
	cmdMap.insert(QStringLiteral("Editor"),
	              QByteArrayLiteral("Window.ActivateEditor"));   // @008b35a3-8b
	cmdMap.insert(QStringLiteral("Terminal"),
	              QByteArrayLiteral("Window.ActivateTerminal")); // @008b35ed-0e

	// --- S4 查找(72558-72590)---
	// 语料:map find(operator< 二分,key=+0x18,value=+0x20)
	//   → local_d0(命中 value 引用计数 +1;未命中 shared_null)。
	const QByteArray cmdKey = cmdMap.value(title);   // operator< 查找 @72558-72590

	// --- S5 actionFactory(72588)---
	// 语料:lVar10 = FUN_00767b36(lVar8,&local_d0)(9B 转发)→
	//   actionFactory_getOrCreate(*(lVar8+0x60)) — 依赖面未落库 →
	//   cited 占位。
	QAction *action = nullptr; // FUN_00767b36 → actionFactory_getOrCreate(*(this+0x60)) — cited — wave-2

	// --- S6 快捷键/图标覆盖/tooltip(72980-73060)---
	// 语料:lVar10(value ptr)非 0 → King__buildKeySequence(&local_c8,
	//   lVar8,lVar10,1) → QAction::icon() 覆盖 local_100 →
	//   QtPrivate::argToQString("%1 (%2)",{tr 标题,seq})@008b3e6d-71。
	// 依赖面 King__buildKeySequence 未落库 → cited 占位(快捷键合成
	//   不发明);tooltip/icon 覆盖面转写留于占位分支内。
	QString toolTip = trTitle;
	if (!cmdKey.isEmpty()) {
		// King__buildKeySequence(&seq,action,cmdKey,1)@008b3d7e — cited — wave-2
		// icon = action->icon()(覆盖 svg)@008b3d91 — cited — wave-2(挂 action 空)
		toolTip = QStringLiteral("%1 (%2)").arg(trTitle, cmdKey.constData()); // QtPrivate::argToQString @008b3e6d
	}

	// --- S7 造按钮+属性(73064-73085)---
	QToolButton *btn = makeToolButton(trTitle, toolTip, icon, true); // FUN_008b30f2 @008b3ec8(p5=1)
	btn->setProperty("kit", QVariant(index));        // DAT_00c8b3d1="kit"(0xc8b3d1,len3 二进制实证)@008b3ef0

	// --- S8 登记 +0x30(73086-73095)---
	// 语料:FUN_008b5d90(this+0x30,{param_2,param_3,pcVar13})
	//   → 0x18 节点{int index,QString title,QWidget* btn} append
	//   (size<2 append : FUN_008b5ae0 detach_grow)。
	KitEntry entry;
	entry.index = index;                             // local_58 = CONCAT44(…,param_2)@008b3f04
	entry.title = title;                             // local_50 = *(param_3)@008b3f08(引用 +1)
	entry.button = btn;                              // local_48 = pcVar13 @008b3f1d
	m_f30.append(entry);                             // FUN_008b5d90 @008b3f32

	// --- S9 按钮组+挂载(73098-73111)---
	// 语料:+0x40 空 → operator_new(0x10)+QButtonGroup(this)→
	//   存 +0x40;QButtonGroup::addButton(btn);FUN_008b305c(this,btn,0)。
	if (m_f40 == nullptr) {                          // @008b4db6
		m_f40 = new QButtonGroup(this);              // QButtonGroup::QButtonGroup @008b4dc4
	}
	m_f40->addButton(btn);                           // @008b3f80
	addKitButtonToBar(btn, false);                   // FUN_008b305c @008b3fa4(force=0)

	// --- S10 connect(73113-73121)---
	// 语料:connectImpl(btn::toggled → functor 0x20{1,FUN_008b2f80,
	//   this,index});lambda 体 FUN_008b2f80(59B,全读):checked
	//   → FUN_0091a518(this,index)= emit kitActivated(index)
	//   (QMetaObject::activate,信号 0,51B 全读;kitActivated
	//   字符串区 0xce43e0 — moc 承接)。
	connect(btn, &QAbstractButton::toggled, this,
	        [this, index](bool checked) {
		        if (checked)                             // FUN_008b2f80 @008b2f9c
			        emit kitActivated(index);            // FUN_0091a518 @008b2fa8
	        });
	// --- S11 清理(73123-73126)---
	// 语料:unref local_f8/local_100/local_108(tr 标题/icon/tooltip)
	//   — Qt5 RAII 承接(无手动 unref)。
}
