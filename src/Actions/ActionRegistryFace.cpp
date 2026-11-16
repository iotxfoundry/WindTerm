// ActionRegistryFace.cpp — 动作注册表/属性应用/整树装载(批 391/392/393)
#include "Actions/ActionRegistryFace.h"

#include <QAction>
#include <QCoreApplication>
#include <QIcon>
#include <QWidgetAction>

// HighlightTextBarAction ctor(41B)真身
HighlightTextBarActionFace::HighlightTextBarActionFace(QObject *parent)
	: QWidgetAction(parent)               // @0055bbce
{
	// vtable HighlightTextBarAction_vtable / +0x10 / +0x18 清 0(C++ 自洽;尺寸 0x20)
}

// actionFactory_getOrCreate(856B,0020.c:50071)真身(结构段):
//   @00665dc2 name = QByteArray::trimmed(name);
//   pQVar1 = this + 0x10(QHash<QByteArray,QAction*>);共享则 FUN_006658e6 detach;
//   h = qHash(name, *(uint*)(table+0x24));FUN_0066b584(table, name, h) 查;
//   命中 → 返回 *plVar6;未命中 → 建(见下)并插入。
QAction *ActionRegistryFace::getOrCreate(const QByteArray &name)
{
	const QByteArray key = name.trimmed();       // @00665dc2
	auto it = m_actions10.find(key);             // qHash + FUN_0066b584
	if (it != m_actions10.end())
		return it.value();                       // ③ 命中

	QAction *act = nullptr;
	if (key == QByteArray("Text.HighlightTextBar")) { // @00665f2x qstrcmp 唯一硬编码
		act = new HighlightTextBarActionFace(this);   // new 0x20 + FUN_0055bbce
	} else {
		act = new QAction(this);                     // new 0x10 QAction(父)
		act->setText(QString::fromLatin1(key));      // @00665f83 默认文案 = 原始名
	}
	// connect(act, triggered → 闭包 impl FUN_0066a148 → FUN_0066b3a0)@00665fea — cited
	m_actions10.insert(key, act);
	return act;
}

// FUN_0066613a(2882B,0020.c:50229)属性应用真身(键名实读)
QAction *ActionRegistryFace::applyAttributes(const QByteArray &name, const QVariantMap &attrMap)
{
	const QByteArray key = name.trimmed();       // @0066613a
	if (key.isEmpty())                           // ① 名空 → 直返
		return nullptr;
	QAction *act = getOrCreate(key);             // ② actionFactory_getOrCreate
	if (act == nullptr)
		return nullptr;

	// "script"(6)@006661f7:trimmed;
	//   **空 → QAction::setEnabled(false)**(@006669e2);
	//   非空 → QAction::setData(脚本串)(@006662c5),再与 0xc91698(0x7f 字节)
	//     正则匹配(箭头/匿名 function 识别);**命中 → setProperty("dynamic",
	//     true) + setVisible(…)**(@00666949/0066695f)。
	// "text"(4)@00666378:toString().trimmed() → **tr(该串)** → QAction::setText
	if (attrMap.contains(QStringLiteral("text"))) {
		const QString t = attrMap.value(QStringLiteral("text")).toString().trimmed();
		act->setText(QCoreApplication::translate("Actions", t.toUtf8().constData()));
	}
	// "tooltip"(7)@00666460:同上 → QAction::setToolTip
	if (attrMap.contains(QStringLiteral("tooltip"))) {
		const QString t = attrMap.value(QStringLiteral("tooltip")).toString().trimmed();
		act->setToolTip(QCoreApplication::translate("Actions", t.toUtf8().constData()));
	}
	// "state"(5)@00666568:toString().trimmed() → **落点未定** — cited
	//   (修复 404:原先归到它名下的 setEnabled/setVisible 实属 script 分支)
	// "icon"(4)@006664xx:setIcon(主题装载)— cited
	// "kits"(4)@006666xx:toStringList()(动作归属 kit 名表)— cited
	return act;
}

// wind_actions_build(7702B,0020.c:50811)整树装载真身:
//   @00667102 if (*(root + 0x10) == 0) return;
//   遍历 root 的 QMap 条目:applyAttributes(key.toUtf8(), value.toMap());
//   —— 其余 1.4K 行是 QMap/QVariant/QString 逐节点 unref 的内联展开。
void ActionRegistryFace::build(const QVariant &root)
{
	const QVariantMap map = root.toMap();
	for (auto it = map.constBegin(); it != map.constEnd(); ++it)
		applyAttributes(it.key().toUtf8(), it.value().toMap()); // @006671b5
}

// FUN_0066a148(103B)动作 triggered 槽真身
void ActionRegistryFace::onActionTriggered()
{
	// sender() → cast 到 QAction(@0066a148)
	auto *action = qobject_cast<QAction *>(sender());
	fireAction(action);                     // js_actionFire(…, QJSValue(true))
}

// js_actionFire(2282B)动作脚本执行 — 结构段(cited 深处)
bool ActionRegistryFace::fireAction(QAction *action)
{
	if (action == nullptr)
		return false;
	// 语料:取动作脚本(动作 setData 存的 script)→ QJSValue::isCallable →
	//   call(动作对象)→ QJSValue::isError 时组 "名 [行]" 报错串。
	//   全链路依赖 QJSEngine 装配面 → cited(不发明 JS 运行时)。
	return true;
}

// actions_from_config_list(4162B)配置表 → QAction 表真身(结构段)
QList<QAction *> ActionRegistryFace::actionsFromConfig(const QVariantList &list, QObject *parent)
{
	QList<QAction *> out;
	for (const QVariant &item : list) {          // 逐配置项
		const QVariantMap m = item.toMap();
		// name = m["text"];act = getOrCreate(name.toUtf8())@0066a1b8 —
		//   setSeparator(m 为分隔符项)/ setIcon(两处)/ setEnabled /
		//   data()/text() 读取;triggered → FUN_0066b3a0(PMF 壳)→
		//   FUN_0066a148 → js_actionFire。
		//   全部 cited(4162B 未逐句转写)
		Q_UNUSED(m);
	}
	Q_UNUSED(parent);
	return out;
}

// s_wind_actions_76b7c0(457B)② 数据源真身(结构段)
void ActionRegistryFace::loadFromConfig()
{
	// cfg = FUN_00a7e75e()(读入器) — cited
	// ① "wind.actions":FUN_005d7cf8(DAT_011c1240, 键) → FUN_00a7e78a(cfg, 值)
	// ② "user.actions":键实读 → FUN_00a7e866(cfg, 值)
	// ③ 注册表懒建:new 0x20 + FUN_00665948(this) 存 +0x60(cited)
	// ④ wind 层:FUN_00a7fdd8(cfg).toMap() → build(map)
	// ⑤ user 层:FUN_00a8017e(cfg).toMap() → build(map)
	//   (两层叠加,user 在后)
	build(QVariant());   // 承接:实际两层 map 体 cited
}
