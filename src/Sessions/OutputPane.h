#ifndef OUTPUTPANE_H
#define OUTPUTPANE_H

#pragma once

// Reconstructed from WindTerm 2.7.0 (libWindTerm) disassembly.
// metacall 0x909e08. Classification sweep result: mixed real bodies
// NOTE: slots are REAL business logic (not command forwards) —
//       bodies need per-function transcription; listed with form notes.

class OutputPane
{
public:
	// slot[0] 0x749422 — LOGIC 2.0K — 类型分派
	// slot[1] 0x749878 — 标注:0x5ab5ca -> 0x5ab180 (写标记)
	// slot[2] 0x74a1ea — LOGIC 4.7K — 输出追加管线
	// slot[3] 0x74a728 — LOGIC 2.0K — 路径解析(0x57d555 复用 Filer)
	// slot[4] 0x74a8f6 — 组合:取列表(0x749b3e) + 路径归一(0x57d555)
	// slot[5] 0x74a946 — LOGIC 1.8K — QVariant 属性
	// slot[6] 0x749b3e — helper:列表收集器
};

#endif // OUTPUTPANE_H
