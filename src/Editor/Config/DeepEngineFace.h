#pragma once
// 批 156(M16-③):深引擎底座头最小集 — 声明层。
// 判例链:ext-boundary src/Ext 规则(底座头定 API 面,实现不逆向)
// + 批 111/117 piecetable/线程池底座"重开需改版底座头"挂账即本头。
// 内容 = 结构偏移锁(语料实读 static_assert)+ 调面声明;实现 cited,
// 行为由 ENodes 承载替/字段前奏真身承接(ENodes.h 批 156 段)。
// 语料地址均为 Ghidra 基址;出处逐字段标注。
#include <QtGlobal>
#include <QThread>
#include <QReadWriteLock>
#include <QHash>
#include <stddef.h>
#include "Editor/Engine/MarkersStore.h"  // RS8(RunStyles 委托)/vcallSlot 槽尾调(批 152 判例)

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

// 97142a 尾面声明(批 164 升真 — DeepEngineFace.cpp 定义;SkipPartition50
//   见下方 struct — 声明置于其后由使用点约束)

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

// 97142a 尾面(批 164 升真 — 123B @0031.c:45510;声明紧随 SkipPartition50;
//   批 176:45534 runstyles_insert_space_b RS8 灌入面升真 — 现役 RS 判例)
void tail97142a(SkipPartition50 *sp, quint64 seed);

// editctx_initThread 字段前奏真身(9714b6 @0031.c:45556-45596 逐字面;
//   尾 FUN_0097142a(123B @0031.c:45510)深引擎腿 — piecetable_init 真身 +
//   runstyles_insert_space_b 批 183 升真 insertSpaceB00940400(850B 全读,
//   45534 灌链真调面 0x971493 CALL 0x940400;字段面 seedCnt28 停在
//   prologue 值 1)。
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

// ---- vt 槽承载面(批 164:M18-③)— 函数指针槽形态 ----
// 语料 bank+0x20 delegate = Uint8RunStyles wrapper 0x20 对象 {vt,+8 RS,+0x10
//   条目 GB}(尾链 5345 operator_delete(dlg,0x20) + 0027.c:39381 vt14 96B 同
//   体三源:93fc60 尾链 5328-5345 / 41586-41600 / 42638-42652);vt 槽消费 =
//   CMP 恒等检查 → 快路真身 / 慢路 vcall(asm 判例:kuna 0x93fc60
//   MOV RDX,[RAX]; MOV RDX,[RDX+0x30]; CMP RDX,0x889872)。我方承载 =
//   函数指针槽(语料调用形态;恒等检查 = 槽指针同一 — MarkerEntryObj fx_*
//   判例;单承载面恒等恒真 → 慢路同槽注记)。
// --- GB20 — 语料 GB face(delegate+0x10 条目 GB / bank+0x18 字节 GB 同形
//     0x20 分配:93fc60 密排消费 {+8 data,+0x14 len,+0x18 gapPos,+0x1c
//     gapLen} 5275-5284 / 88e5a0 门内重排 43247-43310 / 尾链 free(+8)+
//     delete 0x20 5341-5343)---
struct GB20 {
	void    *f00 = nullptr;    // +0x00(未触)
	void    *data = nullptr;   // +0x08 条目/字节数组基(free 面 5302/39391)
	quint32  f10 = 0;          // +0x10 cap 面(0088a016 读写字面)
	quint32  len14 = 0;        // +0x14 长度(5278 门/43232 门)
	quint32  gapPos18 = 0;     // +0x18 gap 位(5276 门/gapbuf_shrink 写)
	quint32  gapLen1c = 0;     // +0x1c gap 长(5280 偏移/43248 门)
};
static_assert(sizeof(GB20) == 0x20, "GB 0x20 分配(5342/39392 delete 字面)");
static_assert(offsetof(GB20, data)     == 0x08, "gb +0x08 data");
static_assert(offsetof(GB20, len14)    == 0x14, "gb +0x14 len");
static_assert(offsetof(GB20, gapPos18) == 0x18, "gb +0x18 gapPos");
static_assert(offsetof(GB20, gapLen1c) == 0x1c, "gb +0x1c gapLen");

// --- CacheEntry30 — 线程缓存 RWLock 条目(88e5a0 构造 43523-43530 字面:
//     {[0]=0,+8 data 0,[2..5]=0,QReadWriteLock(0)@+0x20,+0x28 byte=0,
//     +0x2c 0};93fc60 释放 5301-5304:~RWLock(+0x20)/free(+8)/delete 0x30)---
struct CacheEntry30 {
	void          *f00 = nullptr;  // [0] 字面 0(43524)
	void          *data = nullptr; // +0x08(43525;free 面 5302)
	quint64        _r10[2] = {};   // +0x10..+0x1f(43526/43527 字面 0)
	QReadWriteLock rw{};           // +0x20 QReadWriteLock(0) 真库就地(43528)
	quint8         f28 = 0;        // +0x28 字节(43529)
	quint8         _r29[3] = {};
	quint32        flag2c = 0;     // +0x2c(43530;5298 门消费)
	// 0x30 分配尾(operator_delete(e,0x30) 5303)
};
static_assert(sizeof(CacheEntry30) == 0x30, "条目 0x30(88e5a0 43523/93fc60 5303)");

// --- LexDelegate20 — bank+0x20 delegate 承载 face({vt,+8 RS,+0x10 GB} 0x20;
//     93fc60 计数源 5262 delegate+8 = RS(vt14 D1 面 5316);密排源 5274
//     delegate+0x10 = GB;构造三源恒 null → 本 ctor 仅承载/测试面)---
	struct LexDelegate20 {
	void *vtbl = nullptr;      // +0x00 cited — PTR_FUN_01192288 族;承载 = 槽指针面
	void *rs = nullptr;        // +0x08 RS(承载 RS8* — 怪癖 #35 同物异计)
	void *gb = nullptr;        // +0x10 条目 GB(GB20 承载)
	void *_r18 = nullptr;      // +0x18 分配尾(0x20 字面 — 39381 族)
};
static_assert(sizeof(LexDelegate20) == 0x20, "delegate 0x20(5345 delete 字面)");

// 槽承载(CMP 恒等对象;快路 = 具名承载函数,慢路 = 同槽 vcall 注记):
qint64 lexDelegateRuns00889872(void *self);   // vt+0x30 — 00889860/00889872 18B
                                              //   同体(0027.c:39335/39347:
                                              //   runstyles_runs_count(*(self+8)));
                                              //   承载 RS8::Runs()(怪癖 #35)
void   lexDelegateDtor008898d0(void *self);   // vt+8 D1 — Uint8RunStyles_vt14 96B
                                              //   (0027.c:39381 字面:换面+RS D1
                                              //   +GB free/delete+本体 delete)
// vt+0x28 fill_range(008897ae)/vt+0x38 run_start_at(00889810)槽 — 88e5a0/
//   007b5270 门内臂消费,体未读 → cited 不落(铁律 3)。
extern qint64 (*lexVtRunsSlot)(void *);       // 5262 CMP 0x889872 恒等面
extern void   (*lexVtDtorSlot)(void *);       // 5311 CMP vt14 恒等面

// 承载构造面(语料 delegate 构造点在深腿 cited;空 RS8 + 空 GB20 — 测试/后批)
inline LexDelegate20 *makeLexDelegate20()
{
	LexDelegate20 *d = new LexDelegate20{};
	d->rs = new RS8();          // +8 RS 承载(RS8 直存怪癖)
	d->gb = new GB20{};         // +0x10 条目 GB(0x20 字面)
	return d;
}

// 条目释放臂真身(5301-5304 逐字面:~RWLock/free(+8)/operator_delete 0x30)
void cacheEntryRelease(void *ent);
// GB 密排 helper 真身(gapbuf_shrink 8B 版 95B @0027.c:39714 / FUN_0088a016
//   realloc 扩 221B @39819 — 逐字面;shrink4 = ×4 元素版另一 GB 族不落)
void gbShrink00889e2e(GB20 *g, int to);
void gbGrow0088a016(GB20 *g, int grow);
// FUN_00933738(240B)@0030.c:32409 hash remove 深面 — QHash 承载真身
//   (分离担查 009250ac detach 面 + 深桶 rehash 真库同相注记 — 批 178
//   升真注记;param_1 = &hashData 槽(单指针承载:
//   QHash<u64,CacheEntry30*> 形 — 键 u64 = GB 条目指针值,桶链值字面),
//   param_2 = &键(local_50 密排 {key});返回移除计数。
//   5260 delegate vt+0x30 计数源语料形态见 lexStackClear 注。
//   批 183 rehash 真库内部定性确认(kuna asm 抽验):32457 CALL 0x4c13c0
//   = PLT JMP [0x11bd158] → nm `U _ZN9QHashData6rehashEi@Qt_5` —
//   QHashData::rehash 真库符号导入,非语料自有面;同相注记收账
//   (ext-boundary 判例:真库内部不逆向),无自有转写腿。
qint64 hashRemove00933738(void **hashSlot, const void *keyPacked);
// 批 178:QHash 分离担查真身(009250ac 98B 全读 = QHashData::detach_helper
//   → ref--/free_helper → 新 d 挂回;我方 QHash 隐式共享值语义承载面 —
//   节点表 O(n) 重建 = QHash detacher 同相,键 u64 直读直比 0088a25c 同构)。
void detachShadowQHash(QHash<void *, void *> &h);
// 批 183:45534 灌链余段升真(97142a 45529 邻域读体 — 逐成员出处):
// FUN_00889e90 GapBuffer_reallocate1(371B)@0027.c:39737 全读 — GB 8B 删段
//   真身(39750 pos<0 → 0 / 39754 门 / 39755-39757 clamp / 39758 wipe 臂
//   free+全零 39806-39810 / 39761-39771 gap 移动两臂 / 39775-39777 计数 ±/
//   39779-39803 0x100000*0.6 收缩臂(gbShrink00889e2e — asm 0x889f69
//   CMP ESI,[RBP+0x18] ESI=n14 面 + 负长 runtime_error 字面 39787)/
//   39804 返 1)。
// FUN_00940400 runstyles_insert_space_b(850B)@0031.c:5641 全读 — 45534 灌链
//   深面真身(kuna asm 0x971493 CALL 0x940400:RDI=*(sp+0x20)/ESI=0(971491
//   XOR)/RDX=len f10*2>>1):inner20!=0 臂(5765)= gbDeleteRange 真身 +
//   f10/mask 尾计(5768-5771);inner20==0 全臂(5662-5762)= 三门(5663)+
//   delegate vt+0x28/0x40/0x38 槽分派(5666-5688/5735-5740 — 批 176 承载
//   slot 面;fill 两处调面 Ghidra 丢参同相)+ 逐 run 清偿循环(5690-5730:
//   dlg GB 密排选取同 lexStackClear 形 + spinlock 坍缩注记(批 145 判例)+
//   00933738 hashRemove + cacheEntryRelease 真身)+ 尾计(5744-5748)/
//   0x2000001 分臂(5749-5762 — GapBuffer_dtor 1421B @42087/
//   gapbuffer_build_line_index 2773B @42390/LOCK 计数 cited);
//   bank+0x28 管理器 = f28 — 构造三源 [5]=0(44925-44938/45567/39077)
//   → 深腿构造非零 cited,我方清偿臂不达同相。
bool gbDeleteRange00889e90(GB20 *g, int pos, int len);                    // ODR — 批 183
void insertSpaceB00940400(Bank30 *bank, qint64 pos, qint64 len);          // ODR — 批 183
// FUN_007b5270(601B)@0024.c:21889 — GB 段删除(bank, pos, len;96a280 种子
//   腿 39045 调面 (bank,0,len))— 骨架门真身(21919-21923);段插体
//   0x18!=0 臂(FUN_007abef6 324B GB 删段)f10 尾计 cited。
void sectionRemove007b5270(Bank30 *bank, qint64 pos, qint64 len);         // ODR — 批 164

// ---- 批 176:007b5270 门内段插体 delegate vt+0x28·0x38·0x40 槽承载 ----
// 语料门内臂(21926-21972 逐字面):vt+0x28 fill_range 恒等 007a9c50 /
// vt+0x40 run_start_at 恒等 007a9d82(idx+1 面)/ vt+0x38 run_start_at
// 恒等 007a9d76(idx 面)— 快路直调 (dlg+8) RS 面函数,慢路 vcall 同槽。
// 我方承载 = 函数指针槽(批 164 vt 判例);RS 面 = RS8 承载(怪癖 #35):
//   fill_range = FillRange(pos,char(0),remaining) 首参形态(21928 语料
//   Ghidra 丢参 — 5641 insert_space_b 同体形 pos 承载;fill 返 run 索引
//   = PartitionFromPosition,RS8 FillRange 后 StartRun 对位);
//   run_start_at = StartRun(idx 面)/+1 槽 = 次-run 面语料同相。
//   深臂(007a7d76 删条 176B/007b3960 325B/RunStyles32_removeRange
//   007ae172 564B/007b4c50 519B/007b4e70 984B)仍 cited(铁律 3)。
qint64 lexVtFillRangeSlot008897ae(void *self);    // vt+0x28 — 008897ae 18B
                                                  //   @0027.c:39227:
                                                  //   runstyles_fill_range(
                                                  //   *(self+8)) 承载
qint64 lexVtRunStartSlot00889810(void *self, qint64 idx);  // vt+0x38 —
                                                  //   00889810 12B:run_
                                                  //   start_at(*(self+8),idx)
qint64 lexVtRunStartNextSlot0088981c(void *self, qint64 idx); // vt+0x40 —
                                                  //   0088981c 15B:run_
                                                  //   start_at(*(self+8),
                                                  //   idx+1) 同体三源
                                                  //   (007a9d76/007a9d82
                                                  //   0024.c:13509 同形)


// ---- 调面声明(批 160:ODR 定义落 src/Editor/DeepEngineFace.cpp;
//   可读段真身,深引擎腿逐处标注 cited — 见 .cpp 逐行出处)----
// FUN_0096a2f8 piecetable_init(248B @0031.c:39050)— 0x60 Partitioning
//   形底座,含 0x30 wrapper + Uint32PieceTable + 种子腿 96a280;
//   尾 007b5270/0096a400 cited(批 111 判例)。
void pieceTableInit(PieceTable60 *pt, quint64 seed);                      // ODR — 批 160
// FUN_0088e5a0 gapbuffer_reallocate(3525B @0027.c:43226)— 缓冲重排:
//   (gb, pos, w, len);容量门 0x4000000(43239)+ GB face *(gb+0x18);
//   可达面真身(判空/门/守卫早退),门内重排体/超门 cache 腿 cited。
//   批 183 超门 0x3fffff 分段族收账注记(批 178 定性:上游 GapBuffer
//   算法面 = 外库边界,ext-boundary 判例 — 不逆向,逐成员行号收账):
//   • 0x5fffff 条目 GB 收缩臂:43415 `0x5fffff < *(lVar22+0x14)` →
//     43416 runbounds_get_a(param_1,local_88+0x400000);
//     gapbuffer_get_chars_locked 44843-44846 同臂(00890880 @44684)
//   • 0x400000 分段灌循环:43433 `0x3fffff < param_4` → 43434 pos 界;
//     43436-43572 逐段 operator_new(0x30){0…}+QReadWriteLock(0)@+0x20
//     (43441-43448)+ 0x400000 memset(43568)+ 计数 ±(43569-43571);
//     43575-43577 fill_range/fill_value_range/gapbuf_insert;
//     43797-43804 LAB_0088e759 段进位(43798 pos+0x400000/43803 界门)
//   • runbounds_get_a 尾段:43432 全段腿 + 43179-43191 superbuf_insertRuns
//     收缩循环(43181 +0x3fffff/43183 >>0x16/43187 调面;entry 0088bb40
//     1247B @0027.c:41144 — 外库边界同相收账)
//   • 旧缓存清偿族:0088c088(115B @41341;QMap remove-all:qmap_detach
//     41355/freeNodeAndRebalance 41382)、0088c0fc(437B @41390;spinlock
//     backoff 41406-41442 + 0088c088 消费 41490 + 清零 + operator_delete
//     0x38 @41493)、GapBuffer_dtor(1421B @42087;inner20 free/delete
//     42113-42117 + 0x38 旧缓存 0088c088 消费 42290-42292 + QMap/QHash/
//     QList dispose 42193-42300)
void gapBufferReallocate(Bank30 *gb, quint64 pos, quint8 w, quint64 len); // ODR — 批 160
// FUN_0093fc60(546B @0031.c:5247)— 词法栈老 runs/线程缓存清偿 walker:
//   早退门(5257-5259)+ 逐槽清偿循环 + 尾 vt 换面析构链(5328-5345)+
//   尾槽清零(5347)— 批 164 vt 槽承载后升真(清偿臂/析构链转写;
//   RWLock/spin 单线程坍缩注记 — 批 145/152 判例;深 hash 面 00933738
//   240B@0030.c:32409 QHashData::freeNode/rehash cited)。
void lexStackClear(Bank30 *gb);                                           // ODR — 批 160/164

} // namespace wt
