#pragma once
// 批 156(M16-③):深引擎底座头最小集 — 声明层。
// 判例链:EXT-BOUNDARY src/Ext 规则(底座头定 API 面,实现不逆向)
// + 批 111/117 piecetable/线程池底座"重开需改版底座头"挂账即本头。
// 内容 = 结构偏移锁(语料实读 static_assert)+ 调面声明;实现 cited,
// 行为由 ENodes 承载替/字段前奏真身承接(ENodes.h 批 156 段)。
// 语料地址均为 Ghidra 基址;出处逐字段标注。
#include <QtGlobal>
#include <QThread>
#include <stddef.h>

namespace wt {

// --- Inner20 — operator_new(0x20){0,0,0,0} 字面内层(96a2f8
//     @0031.c:39070-39075 / 9714b6 @0031.c:45572-45577 / 970850
//     @0031.c:44985-44990 三处逐字面同构)---
struct Inner20 {
	quint64 w[4] = {};
};
static_assert(sizeof(Inner20) == 0x20, "0x20 内层分配字面(三处同构)");

// --- Bank30 — 词法栈 bank 面(PTR_FUN_01192288 族,0x30;96a2f8/
//     9714b6/970850 三处 operator_new(0x30) 同构字段形)---
struct Bank30 {
	void    *vtbl = nullptr;   // +0x00 cited — PTR_FUN_01192288/Uint8PieceTable_vtable 族
	quint64  packed8 = 0;      // +0x08 语料 `& 0xfffffffe00000000 | 0x100000000`(96a2f8 39062)
	quint32  f10 = 0;          // +0x10 u32(97142a 灌链计数源 45533/gapbuffer_reallocate 计数门 43239)
	quint32  mask14 = 0;       // +0x14 语料 `& 0x80000000`(96a2f8 39064)
	void    *inner20 = nullptr;// +0x18 [3] = operator_new(0x20) 内层(96a2f8 39076)
	void    *f20 = nullptr;    // +0x20 [4](96a2f8 39077 字面 0)
	void    *f28 = nullptr;    // +0x28 [5](970850 老线程缓存条目槽 — 44945 清偿消费)
};
static_assert(sizeof(Bank30) == 0x30, "bank 0x30(96a2f8/9714b6/970850 同构)");
static_assert(offsetof(Bank30, packed8) == 0x08, "bank +0x08 packed");
static_assert(offsetof(Bank30, mask14)  == 0x14, "bank +0x14 mask");
static_assert(offsetof(Bank30, inner20) == 0x18, "bank +0x18 [3] inner");
static_assert(offsetof(Bank30, f28)     == 0x28, "bank +0x28 [5]");

// 纯字段 ctor:operator_new(0x30){vt cited,packed=0x100000000,mask,
//   inner(0x20){0,0,0,0},0,0} — 96a2f8 39060-39077 / 9714b6 45562-45578 /
//   970850 44925-44938 逐字面三源(铁律:偏移语义 ≥2 源一致)。
inline Bank30 *makeBank30()
{
	Bank30 *b = new Bank30{};
	b->packed8 = 0x100000000ull;   // 96a2f8 39062 / 9714b6 45564 同字面
	b->inner20 = new Inner20{};    // 39070-39076
	return b;
}

// --- SkipPartition50 — editctx_initThread 产物(0x50;FUN_009714b6
//     272B @0031.c:45546 全读)---
struct SkipPartition50 {
	void    *vtbl = nullptr;   // +0x00 cited — SkipPartition_vtable(45556)
	quint64  flag08 = 0;       // +0x08 [1](97142a 尾置 1 @45540 — tail cited)
	void    *ptA = nullptr;    // +0x10 [2](97142a D1+重建槽 45523 — cited)
	void    *ptB = nullptr;    // +0x18 [3](97142a = piecetable_init 0x60 45530 — cited)
	Bank30  *bank = nullptr;   // +0x20 [4](runstyles 灌链 face — 97142a 45536 调面)
	quint64  seedCnt28 = 0;    // +0x28 [5] prologue 字面 1(45582;97142a 尾再 +1 45520 — cited)
	quint64  tid30 = 0;        // +0x30 [6] QThread::currentThreadId()(45584)
	quint64  f38 = 0;          // +0x38 [7] 字面 0(45586)
	quint64  serial40 = 0;     // +0x40 [8] 全局自增序(DAT_011be6f8 LOCK 面 45592-45596)
	quint8   spin48 = 0;       // +0x48 (param_1+9)字节 字面 0(45590)
};
static_assert(sizeof(SkipPartition50) == 0x50, "SkipPartition 0x50(9714b6 operator_new(0x50) 45561)");
static_assert(offsetof(SkipPartition50, bank)      == 0x20, "sp +0x20 [4] bank");
static_assert(offsetof(SkipPartition50, seedCnt28) == 0x28, "sp +0x28 [5] seedcnt");
static_assert(offsetof(SkipPartition50, tid30)     == 0x30, "sp +0x30 [6] tid");
static_assert(offsetof(SkipPartition50, serial40)  == 0x40, "sp +0x40 [8] serial");
static_assert(offsetof(SkipPartition50, spin48)    == 0x48, "sp +0x48 spin 字节");

// editctx_initThread 字段前奏真身(9714b6 @0031.c:45556-45596 逐字面;
//   尾 FUN_0097142a(123B @0031.c:45510)深引擎腿 cited — piecetable_init/
//   runstyles_insert_space_b 不落,字段面 seedCnt28 停在 prologue 值 1)。
inline SkipPartition50 *editctxInitThread009714b6()
{
	SkipPartition50 *p = new SkipPartition50{};
	p->bank = makeBank30();                                  // 45562-45578 纯字段
	p->seedCnt28 = 1;                                        // 45582 [5]=1
	p->tid30 = quint64(QThread::currentThreadId());          // 45584
	// [7]=0 / +0x48 spin=0:默认零(45586/45590 字面)
	static quint64 s_serial = 0;                             // DAT_011be6f8 面
	p->serial40 = s_serial++;                                // 45592-45596 LOCK 序
	// tail 97142a — cited(深引擎:piecetable_init 0x60 + runstyles 灌链)
	return p;
}

// --- PieceTable60 — piecetable_init 产物(0x60;FUN_0096a2f8 248B
//     @0031.c:39050 全读;种子腿 FUN_0096a280 120B @0031.c:39032)---
struct PieceTable60 {
	void    *vtbl = nullptr;   // +0x00 cited — Partitioning_vtable(39056)
	quint8   b08 = 0;          // +0x08 bool:tag < 0x100000000(96a280 39040)
	quint8   _r09[7] = {};
	qint64   v10 = 0;          // +0x10 96a280 字面 -1(39035)
	quint64  v18 = 0;          // +0x18 96a280 字面 0(39036)
	quint64  v20 = 0;          // +0x20 96a280 字面 0(39037)
	quint64  seed28 = 0;       // +0x28 [5] = param_2(96a280 39039)
	Bank30  *bank30 = nullptr; // +0x30 [6](0x30 wrapper + Uint32PieceTable inner — 39060-76 调面)
	quint64  cnt38 = 0;        // +0x38 [7] = 1(39078;96a280 尾 +1 → 2)
	quint64  tid40 = 0;        // +0x40 [8](39082)
	quint64  f48 = 0;          // +0x48 [9] = 0(39084)
	quint64  serial50 = 0;     // +0x50 [10] DAT_011be6f0 序(39090-92)
	quint8   spin58 = 0;       // +0x58 (param_1+0xb)字节(39086)
};
static_assert(sizeof(PieceTable60) == 0x60, "piecetable 0x60(97142a 45531 operator_new(0x60))");
static_assert(offsetof(PieceTable60, seed28)   == 0x28, "pt +0x28 seed");
static_assert(offsetof(PieceTable60, bank30)   == 0x30, "pt +0x30 [6] bank");
static_assert(offsetof(PieceTable60, tid40)    == 0x40, "pt +0x40 tid");
static_assert(offsetof(PieceTable60, serial50) == 0x50, "pt +0x50 serial");
static_assert(offsetof(PieceTable60, spin58)   == 0x58, "pt +0x58 spin 字节");

// ---- 调面声明(实现 cited — wave-2;无定义,不 ODR 使用)----
// FUN_0096a2f8 piecetable_init(248B @0031.c:39050)— 0x60 Partitioning
//   形底座,含 0x30 wrapper + Uint32PieceTable + 种子腿 96a280。
void pieceTableInit(PieceTable60 *pt, quint64 seed);                      // cited — wave-2
// FUN_0088e5a0 gapbuffer_reallocate(3525B @0027.c:43226)— 缓冲重排:
//   (gb, pos, w, len);容量门 0x4000000(43239)+ GB face *(gb+0x18)。
void gapBufferReallocate(Bank30 *gb, quint64 pos, quint8 w, quint64 len); // cited — wave-2
// FUN_0093fc60(546B @0031.c:5247)— 词法栈老 runs/线程缓存清偿 walker:
//   消费 bank+0x20 delegate(vt+0x30 runs 计数)+ bank+0x28 逐条目
//   (0x50:{+0x18 旧条目,+0x28 spin,+0x30,+0x38 QMap,+0x40 QHash,
//   +0x48 QList})清偿;尾 vt 换 PTR_Uint8RunStyles_vt13(5319)。
void lexStackClear(Bank30 *gb);                                           // cited — wave-2

} // namespace wt
