#include "SuperKeymap.h"

// 语料内部(cited — wave-2,批 46):FUN_0067db40(60B,QList 容量
// 确保)/ FUN_0067ce4c(49B,槽交换销毁)/ FUN_0067ce30(项销毁走查)
// —— Qt QListData 管理形,Qt5 QList 原生等价操作承载。

// 00674648(161B)语料转写:
//   QObject(parent) → vtable → +0x10 槽列表(FUN_0067db7c,容量 2)
//   → +0x18 = QRegularExpression("meta\\+|\\+meta",
//   CaseInsensitive)(006746b9 字面实证)
SuperKeymap::SuperKeymap(QObject *parent)
	: QObject(parent)
	, m_metaRe(QStringLiteral("meta\\+|\\+meta"),
	           QRegularExpression::CaseInsensitiveOption)
{
	m_slots.reserve(2);   // FUN_0067db7c(+0x10,2)
}

// 0067461a(45B)语料转写:FUN_0067db40(+0x10)容量确保 →
// FUN_0067ce4c(mode 槽)清 —— mode*8 寻址超出当前容量则语料
// 无守卫(裸寻址),此处按容器界守卫(语义面标注)
void SuperKeymap::reset(int mode)
{
	if (mode < 0 || mode >= m_slots.size())
		return;
	m_slots[mode] = QVariant();   // FUN_0067ce4c(mode 槽清)
}
