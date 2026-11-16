#pragma once

#include <QByteArray>
#include <QHash>
#include <QObject>
#include <QString>
#include <QVariantMap>

class QAction;

// ActionRegistryFace — 语料动作注册表(② 菜单/动作树的地基,批 391/392/393)。
//
// 语料三件套(全部为"名 → 动作"的 DSL 装载):
//   actionFactory_getOrCreate(856B,0020.c:50071)
//   FUN_0066613a(2882B,0020.c:50229)  属性应用
//   wind_actions_build(7702B,0020.c:50811) 整树装载
class ActionRegistryFace : public QObject {
	Q_OBJECT
public:
	// actionFactory_getOrCreate(856B) getOrCreate(name):
	//   ① name = QByteArray(name).trimmed();
	//   ② 表在 **this+0x10 = QHash<QByteArray, QAction*>**(共享则 detach);
	//      h = qHash(name, this+0x10 的 seed);FUN_0066b584(hash, name, h) 查;
	//   ③ 命中 → 直接返回该 QAction*;
	//   ④ 未命中按名字形态分两路建:
	//      含 "::"(菜单族)→ **new 0x20 + FUN_0055bbce(this, 父)**(菜单型动作);
	//      否则 → **new QAction(0x10, 父)**;
	//      两路均 connect(triggered → 闭包 impl) 并插入哈希表。
	QAction *getOrCreate(const QByteArray &name);

	// FUN_0066613a(2882B) applyAttributes(name, attrMap):
	//   ① name 空(trimmed 后长度 0)→ 直返;
	//   ② act = getOrCreate(name);
	//   ③ 逐属性取面(键名 .rodata 实读):
	//      **"script"**(6) → toString().trimmed() → 脚本面(赋值腿,cited);
	//      **"text"**(4)   → toString().trimmed() → **tr(该串)** → setText;
	//      **"tooltip"**(7) → 同上 → setToolTip;
	//      **"state"**(5)   → toString().trimmed() → setEnabled/setVisible 面(cited);
	//      另:icon(QIcon 11 处)/shortcut/setData 面(顺序见 .cpp 注)。
	QAction *applyAttributes(const QByteArray &name, const QVariantMap &attrMap);

	// wind_actions_build(7702B) build(rootMap):
	//   ① *root 空(+0x10 == 0)→ 直返;
	//   ② 遍历 map 条目:(key, value) → applyAttributes(key, value.toMap());
	//   ⇒ **7.7KB 中约 1.4K 行是 QMap/QVariant/QString 的内联析构展开**
	//     (逐节点 unref),真正的语义只有上述两行。
	void build(const QVariant &root);

private:
	QHash<QByteArray, QAction *> m_actions10; // +0x10
};
