#ifndef MATCHENGINE_H
#define MATCHENGINE_H

#include <QtGlobal>

class GrepNeedle448;   // CodecMemo.h(0x448 针对象;批 93 convCtor 构造链)

// 批 94 定案 1:1 方案:四匹配引擎 ENG<IsLiteral,UseSkip> 参数化单模板
// (P3 勘察 /tmp/opencode/p3_notes_eng.md:骨架 100% 同构,差异 2 维 —
//   针源单双表 / miss 步进短针 vs 跳表)。
// 语料:tools/re/decomp/decomp-part-0030.c
//   entry=0093632d(34587,任意类/短针)/ 00936cf1(36224,任意类/跳表)/
//   009376d1(37874,literal/短针)/ 0093830d(40274,literal/跳表)/
//   分派器 0092a596(26261)。
// 转写序:3632d(最纯)→ 376d1 → 36cf1 → 3830d → 2a596(批 94 定案)。

namespace MatchEngine {

// 16B 逐字节相等掩码 pack(34639-34672 auVar10 直译:-(eq)/字节 →
//   各字节最高位收 16bit;SUB161(>>7)&1 … [0xf]>>7 展开同构)。
//   eng 笔记 §3:语义等价直译免 SSE intrinsic(源码本为同模板展开)。
inline quint16 engCmp16(const char *blk, const char *tbl)
{
	quint16 m = 0;
	for (int i = 0; i < 0x10; ++i)
		m |= quint16(blk[i] == tbl[i]) << i;      // -(eq) 高位语义
	return m;
}

// 外部可见四符号(eng 笔记 §3:便于 xref 与断点对齐)= ENG<
//   IsLiteral,UseSkip> 模板四实例化(体在 MatchEngine.cpp;engScan
//   模板 + vt 承载占位同文件)。实例化矩阵:
//   ┌─────────────┬ IsLiteral=false(任意类,单表 +0x420)
//   │             ├ IsLiteral=true (literal,双表 OR +0x428|+0x430)
//   ├ UseSkip=false(短针,miss pos+=0x10)→ 0093632d / 009376d1
//   └ UseSkip=true (长针,bad-char 类跳表)   → 00936cf1 / 0093830d
//   签名统一 ulong ENG(long *lineDoc, long needle, ulong from, long to)
//   (eng 笔记 §0;返回 pack64:hi16 = 16-lane 候选掩码,lo48 = 窗口
//   起点(命中位 = 置位 lane i + lo48,分派器 262b0 消费);无命中 =
//   0xffffffffffff — 34634/36272/37953/40354 边界哨兵)。
quint64 engEntry0093632d(const void *lineDoc, const GrepNeedle448 *needle,
                         quint64 from, qint64 to);           // 任意类/短针
quint64 engEntry00936cf1(const void *lineDoc, const GrepNeedle448 *needle,
                         quint64 from, qint64 to);           // 任意类/跳表
quint64 engEntry009376d1(const void *lineDoc, const GrepNeedle448 *needle,
                         quint64 from, qint64 to);           // literal/短针
quint64 engEntry0093830d(const void *lineDoc, const GrepNeedle448 *needle,
                         quint64 from, qint64 to);           // literal/跳表

// 分派判式(0092a596 内 26276-26288/26314-26326 两处同构):literal 门
//   *(char*)(needle+0x01)==0 → literal 对;非 0 → 任意类对;各按
//   len<0xc 分短/长(体在 .cpp — 读针门字段需完整型)。
//   lineDoc 承载替:语料 param_1+0xf8 解引用(26280/26316)→ 直收
//   lineDoc 承载(EditorContext +0xf8 = 布尔位,布局不同构 — 登记;
//   活性消费面同 vt 承载占位注)。
quint64 engDispatch(const void *lineDoc, const GrepNeedle448 *needle,
                    quint64 from, qint64 winEnd);

// FUN_00b422d0(2750B)@decomp-part-0037.c:32598 — 缓冲扫描引擎
//   (regex NFA 面:regex_nfa_compile/regexp_match_dispatch/FUN_00b3bcf0
//   族;>500B 未解 — cited — wave-2)。thunk 链:0092547e → 00a8395c
//   (42B)→ 00a83946(21B 门)→ 00b42e10(28B)→ 本体。参数面 9 形参
//   映射未解(00a8395c 7 实参未恢复)— searchNeedle 三参直传承载(登记)。
qint64 bufferScan00b422d0(const void *needlePair, qint64 from, qint64 to);

} // namespace MatchEngine

#endif // MATCHENGINE_H
