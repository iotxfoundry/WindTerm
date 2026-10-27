#ifndef SESSIONPANE_H
#define SESSIONPANE_H

#pragma once

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// metacall 0x90a0aa. Classification sweep result: session tree model: 5 monolith bodies (Node-tree walk, 1.2K-14K) + 3 tiny
// NOTE: slots are REAL business logic (not command forwards) —
// verified by probe (FUN_007415fc): Qt model-view tree operations —
//   model() -> dynamic_cast custom model (typeinfo 0x119fa70)
//   -> 0x18-byte closure (model/this/Node-tree + fnptrs 0x742de0/0x7424ef)
//   -> selectionModel()->selectedRows() iteration -> Node-tree walk
//      (+0x14 child count, +0x20 flag, children at +8)
// The five monoliths are this shape; transcription is model-level work.
//       bodies need per-function transcription; listed with form notes.

class SessionPane
{
public:
	// slot[0] 0x740472 — LOGIC 12.9K — 会话树构建/刷新(Node 树)
	// slot[1] 0x73e756 — LOGIC 5.0K — 树节点操作
	// slot[2] 0x73cdaa — QAbstractItemView::selectionModel + hasSelection
	// slot[3] 0x7400aa — LOGIC 2.5K — 全局配置(0x805b1a)分支流
	// slot[4] 0x73eb92 — LOGIC 12.6K — 树重建大件
	// slot[5] 0x73cdc4 — LOGIC 7.1K — 树操作
	// slot[6] 0x7415fc — LOGIC 8.1K — 节点遍历
	// slot[7] 0x73d836 — LOGIC 14.3K — 共享体×3(字符串参树操作)
};

#endif // SESSIONPANE_H
