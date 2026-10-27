#ifndef TRANSFERPANE_H
#define TRANSFERPANE_H

#pragma once

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// metacall 0x909c8a. Classification sweep result: 6 small bodies, shared-buffer walks (0x734398 container + global 0x11c1680)
// NOTE: slots are REAL business logic (not command forwards) —
//       bodies need per-function transcription; listed with form notes.

class TransferPane
{
public:
	// slot[0] 0x73452e — 选中项 -> 全局动作(选中列表非空分支)
	// slot[1] 0x7345a4 — bool 查询(CoW 分离后扫描)
	// slot[2] 0x734656 — 选中操作(同 0 的空列表分支)
	// slot[3] 0x7346c4 — 共享体 A(CoW + 遍历)
	// slot[4] 0x734764 — 共享体 B(同构)
	// slot[5] 0x734804 — 共享体 C(同构)
};

#endif // TRANSFERPANE_H
