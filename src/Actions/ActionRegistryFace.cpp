// ActionRegistryFace.cpp — 动作注册表/属性应用/整树装载(批 391/392/393)
#include "ActionRegistryFace.h"

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

	// "script"(6)@006661f7:trimmed 后与 0xc91698(0x7f 字节)正则匹配
	//   —— 该式为"箭头函数 / 匿名 function"识别(内含 GBK 中文注释)→
	//   QAction::setData(脚本串)(语料唯一 setData 调用点) — cited
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
	// "state"(5)@00666568:toString().trimmed() → **setEnabled + setVisible**
	//   (state 一个键控两个属性)—— cited(取值语义未定,不猜)
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
