#include "SuperKeymap.h"

// 语料内部:FUN_0067db40(60B,QList 容量确保)/ FUN_0067ce4c(49B,
// 槽交换销毁)/ FUN_0067ce30(项销毁走查)—— Qt QListData 管理形,
// Qt5 QList 原生等价操作承载(同源等价,非缺口)。
//
// ── 匹配体 FUN_0067500e(9978B)勘察记录(批 54,零猜测)──────
// 签名:(out, configTree(shared_ptr 节点数组), map(Rb_tree),
//        mode flag)—— 递归(自调 ×2)。
// 结构:重度优化(30+ unreachable 警告;150+ 行寄存变量;
//   shared_ptr/_Rb_tree_node_base 走查)—— YAML 配置树经
//   0067 包装族遍历(可见段零 Qt 直调):
//   FUN_0067faa0×3 / FUN_00683ad6 / FUN_0067e3dc×2 /
//   FUN_00686134 / FUN_006857f4 / FUN_00681a40 / FUN_006809c0 /
//   FUN_00673ecc(项销毁)。
// 转写路径:包装族逐个转写(FUN_0067faa0 等体量未知)→
//   树行走语义还原 → 匹配/分发本体落位。体量 = 专用多轮批。
// ──────────────────────────────────────────────────────────

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
