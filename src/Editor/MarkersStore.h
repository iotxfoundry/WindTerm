// MarkersStore — markers 对象读侧真身化(批 67a;布局与函数全部语料实证)
// 布局还原:FUN_0099cxxx/009a0xxx 存储族 16 函数(台账见 docs/PHASE5.md 批 67)。
// 写侧构建者批已落地(mk3):markersCtxInit(009a2e1e 尾段)/bankCtor 族(009cc22c/
// 009cc264/009cc29c)/runstylesUpgrade(009cd554)/coreWriteRange(0099c8d6)/
// markWrite(009a62c0)/publishOutline(009a2766)+ rsValue* 委托真身(§7)。
// 行为测试须等写入侧接线。语料地址均为 Ghidra 基址(非 PIE 直通)。
#pragma once

#include <QtGlobal>
#include <QList>
#include <QMap>
#include <QString>
#include <memory>
#include <stddef.h>
#include <time.h>
#include <errno.h>
#include <sched.h>

#include "../Scintilla/include/Platform.h"   // SplitVector.h 依赖 PLATFORM_ASSERT(上游含序同 RunStyles.cxx)
#include "../Scintilla/src/SplitVector.h"
#include "../Scintilla/src/Partitioning.h"
#include "../Scintilla/src/RunStyles.h"
using RS8  = Scintilla::RunStyles<int, char>;        // FUN_0088ff00(u8 密排;读逐位等价)
using RS16 = Scintilla::RunStyles<int, int>;         // runstyles_value_at16(u16 值窄存 int,位型等价)
using RS32 = Scintilla::RunStyles<int, int>;         // Uint32RunStyles_valueAt
// using RS64 = Scintilla::RunStyles<int, long long>;  // 批 72:实例化须 rebuild_deps,暂缓(见 rsValue64)

namespace wt {

// --- 通用 vtable 槽尾调(语料各尾调点原样;槽序由语料锁定)---
inline qint64 vcallSlot(void *obj, int off)
{
    void **vt = *reinterpret_cast<void ***>(obj);        // vptr
    using Fn = qint64 (*)(void *);
    return reinterpret_cast<Fn>(vt[off / 8])(obj);
}
// 带一参版(FUN_009cc396/0099ca60/0099ca6c 尾调寄存器直通,line/ridx 作第 1 参)
inline qint64 vcallSlotArg(void *obj, int off, qint64 arg)
{
    void **vt = *reinterpret_cast<void ***>(obj);
    using Fn = qint64 (*)(void *, qint64);
    return reinterpret_cast<Fn>(vt[off / 8])(obj, arg);
}
inline void vcallSlotVoid(void *obj, int off)
{
    void **vt = *reinterpret_cast<void ***>(obj);
    using Fn = void (*)(void *);
    reinterpret_cast<Fn>(vt[off / 8])(obj);
}

// --- RS valueAt 真身(mk3 §7:委托 Scintilla::RunStyles,EXT-BOUNDARY)---
// 语料 007b7b70/007b5a30/007b6dd0/0088ff00 各 ~240B:直接数组快路 + 线程缓存回退,体已读。
// 语料 valueAt 的 arg = GB 句柄(0x30:{vt cited,+0x18 DATA},DATA 密排直读);我方委托 RS
//   实例(run 编码)读逐位等价,线程缓存路单线程直读等价 — 怪癖登记维持 mk2 §4。
template <class RS>
inline quint64 rsReadAt(const RS *rs, int pos)       // 语料越界→0(DAT_011c1edc 族);!rs 壳期守卫
{ return (!rs || pos < 0 || pos >= int(rs->Length())) ? 0 : quint64(rs->ValueAt(pos)); }
inline quint32 rsValue32(void *rs, int pos) { return quint32(rsReadAt(static_cast<const RS32 *>(rs), pos)); }  // 007b7b70
// RS64:<int,long long> 实例化缺失(RunStyles.cxx 属预构建 scintilla_core.a,
// 显式实例化须 rebuild_deps 才生效,批 72 裁决)—— 回退占位,启用随重建批
inline quint64 rsValue64(void *, int)      { return 0; }                                   // 007b5a30
inline quint16 rsValue16(void *rs, int pos) { return quint16(rsReadAt(static_cast<const RS16 *>(rs), pos)); }  // 007b6dd0
inline quint8  rsValue8 (void *rs, int pos) { return quint8 (rsReadAt(static_cast<const RS8  *>(rs), pos)); }  // 0088ff00

// cited — wave-2(E=M+0x08 折叠族)
// FUN_00927940(17B)→FUN_00997670(48B)→FUN_00a84242(36B)→FUN_00a84204(未读)
inline bool foldFoldable(void *, qint64)        { return false; }  // 行可折叠?
// FUN_009252d4(15B)→FUN_009987a2(123B)→FUN_00998678(298B)/009975de(59B)
inline int  foldStep(void *, qint64, int)       { return 1; }      // 折叠步进行数
// FUN_0092d500(193B)→0092801a/0092d242/009f846e/8566/95b2/8766(224–257B)
inline qint64 foldCollapseEnd(void *, qint64)   { return 0; }      // 层级塌缩定 end
// FUN_00a101a0/00a10384 的 holder vt+0x18 越界回退(QListData 补值)
inline quint64 listFallbackVt18(void *)         { return 0; }      // cited

// --- entry 内对象:类身份未解(E2 保留 a → 具体 struct 承载)---
struct MarkEntryObj {                    // 语料 vtable 槽:
    void  *vtbl;                         //   +0x08 dtor(0099cecc,Itanium D1)
                                         //   +0x28 firstIndex / +0x30 count
                                         //   +0x38 begin / +0x40 end(0099cf3e/5c/7a/98)
    quint8 _r08[0x08];                   // +0x08..0x0f 未触
    void  *styles;                       // +0x10 RunStyles(009a06ac valueAt 目标)
};

struct MarkEntry {                       // 24B — operator_delete(_,0x18)@0099cecc
    quint8       sel;                    // +0x00 0⇒+0x10 槽(u64 载体);≠0⇒+0x08 槽(u32)
    MarkEntryObj *u32Obj;                // +0x08(sel!=0)
    MarkEntryObj *u64Obj;                // +0x10(sel==0)
};

// --- 银行/值表复合对象(M+0x18 与 A+0x18 是两个不同实例,勿合并 — E2 保留 b)---
struct ValueTable {                      // FUN_009cd3da/009cc396/00a101a0/00a10384 实证
    quint32 kind;                        // +0x00 selector(<6;009cd3da switch 0..5)
    quint8  _r04[0x04];
    void   *delegate;                    // +0x08 多态委托:vt+0x28 run 索引/0x38 行起/
                                         //   0x40 行止(009cc396/0099ca60/ca6c);类身份未解
    void   *holders[6];                  // +0x10..0x38:*holder→内对象,+0x10=RunStyles
                                         //   (009cd3da 六路;宽度 8/16/16/8/16/32)
    quint8  _r40[0x18];                  // +0x40..0x57 未触
    void   *list58;                      // +0x58 FUN_00a101a0 读槽(T=M+0x18 用)
    void   *list60;                      // +0x60 FUN_00a10384 读槽(值表=A+0x18 用)
};

struct MarkersArray {                    // A = *(void**)M — 0099cecc/009a06ac/0099c9c2
    void        *core;                   // +0x00 写侧 shadow(0099c8d6 锁 *(A)+0x48)— cited
    void        *lexerSnap;              // +0x08 initDoc puVar6[1]=param_1[3](≡D+0x18 同指针;
                                         //   009a62c0 keyProps/bimap arg,q1)
    quint8      _r10[0x08];              // +0x10 puVar6[2](语料 u32 字面清零;mk3 落 nullptr)
    ValueTable  *bank;                   // +0x18 S1(6 路银行 + 值表 FUN_00a10384)
    // +0x20+8i:entry[i];条目总数未解,语料实证仅用槽 0..2(不设固定数组)
    MarkEntry *entryAt(int i) const
    {
        return *reinterpret_cast<MarkEntry *const *>(
            reinterpret_cast<const char *>(this) + 0x20 + size_t(i) * 8);
    }
    MarkEntry **entryPtr(int i)
    {
        return reinterpret_cast<MarkEntry **>(
            reinterpret_cast<char *>(this) + 0x20 + size_t(i) * 8);
    }
};
static_assert(sizeof(MarkersArray) == 0x20, "A 头 0x20 + entry[0..2] = 0x38 分配(mk3 §1)");

// libstdc++ _Sp_counted_base<Lock_policy 2>(0099d1f6 语料类型;libstdc++ 边界)
using SpBase = std::_Sp_counted_base<__gnu_cxx::_Lock_policy::_S_atomic>;

// ========================================================================
// 构建者批写侧辅助(mk3 落地;均在 struct MarkersStore 之前——成员体名字
// 查找只看类定义前的名字空间声明)
// ========================================================================

// holder 公共内层取 RS:*(holder+0x10)≡ 成员 rsOf(009cd3da 六路同构);
// RsHolder20/MarkEntryObj 同形(+0x10 均为 RS 槽)
inline void *holderRs(void *h)
{ return h ? *reinterpret_cast<void **>(reinterpret_cast<char *>(h) + 0x10) : nullptr; }

// holder 0x20(mk3 §1 RsWrap / §3 mkU 009cd898 形):{vtbl cited;+0x08 threadCtx/0;
//   +0x10 RS(我方委托形态直存,取代语料 GB+DATA 密排 — 009a30cd,怪癖登记);+0x18 分配尾}
struct RsHolder20 {
    void *vtbl;          // cited — 011ad300(Uint8SkipRunStyles)/各宽度层 vtbl;我方读路不经 vt
    void *threadCtx;     // initDoc 腿 = editctx_initThread(operator_new(0x50),FUN_0092801a(E)) — cited
    void *rs;            // +0x10 内层 RunStyles 实例(委托形态)
    void *_r18;          // 0x20 分配尾(operator_new(0x20) 语料字面)
};
inline RsHolder20 *makeHolder0x20(void *rs)
{
    RsHolder20 *h = new RsHolder20{};    // 语料 operator_new(0x20) 逐槽清(009cd898 形)
    h->vtbl = nullptr;                   // cited — wave-2
    h->threadCtx = nullptr;              // cited — editctx_initThread(initDoc 009a2ee0 形)
    h->rs = rs;
    h->_r18 = nullptr;
    return h;
}

// 灌值腿委托(EXT-BOUNDARY:体不自研)。FUN_007b7290/007b8000(1141/1137B 全读,
// 0024:23258/23837)= runstyles_fill_range + run 起止拆分/相邻合并 ≡ RunStyles::FillRange
// (RunStyles.cxx:132;changed 对应 *param_5)。⚠ 语料合并吸收路径返 1/普通写返 0/1,
// 委托 .changed 与之未必逐值同相 — 行为门裁决点(登记待测)。Skip/plain 委托同形,
// 分腿地址见 runstylesUpgrade 调用点。空守卫:壳期/前置期调用防崩(语料均在 init 后)。
inline bool rsFill8(void *h, qint64 pos, quint8 v, qint64 len)
{ return h && static_cast<RS8 *>(holderRs(h))->FillRange(int(pos), char(v), int(len)).changed; }
inline bool rsFill16(void *h, qint64 pos, quint16 v, qint64 len)
{ return h && static_cast<RS16 *>(holderRs(h))->FillRange(int(pos), int(v), int(len)).changed; }
inline bool rsFill32(void *h, qint64 pos, quint32 v, qint64 len)
{ return h && static_cast<RS32 *>(holderRs(h))->FillRange(int(pos), int(v), int(len)).changed; }   // u32 窄存 int,位型等价(mk3 §7)
// rsFill64:RS64 实例化暂缓(见 rsValue64),占位 — cited — wave-2
inline bool rsFill64(void *, qint64, quint64, qint64) { return false; }

// 升宽换层公共尾(LAB_009cd775):holders[slot]=新;delegate=新;kind=slot。
// 值迁移腿 cited — wave-2 未转写(009cee86 u8→u16 / 009cf8c2 u8→u32 / 009cf69e u16→u32 /
// 009cf0b0 u8S→u16S / 009cfae6 u8S→u32S / 009cfd0a u16S→u32S):升宽后旧值不搬,行为门待测。
inline void mkLayer(ValueTable *b, int slot, void *newHolder)
{ b->holders[slot] = newHolder; b->delegate = newHolder; b->kind = quint32(slot); }
// mkU 族 — operator_new(0x20){vt 占位;0;0;0}(009cd898 形)+ ctor cited(FUN_009ceabe/
// 009cf2da/009cebe6/009cf400 形);内层 = 我方对应宽度 RS(+0x10 直存,§1 同怪癖)
inline void mkU16 (ValueTable *b, int slot) { mkLayer(b, slot, makeHolder0x20(new RS16())); }  // 009ceabe 形 plain u16
inline void mkU32 (ValueTable *b, int slot) { mkLayer(b, slot, makeHolder0x20(new RS32())); }  // 009cf2da 形 plain u32
inline void mkU16S(ValueTable *b, int slot) { mkLayer(b, slot, makeHolder0x20(new RS16())); }  // 009cebe6 形 Skip u16
inline void mkU32S(ValueTable *b, int slot) { mkLayer(b, slot, makeHolder0x20(new RS32())); }  // 009cf400 形 Skip u32

// ============ runstylesUpgrade — FUN_009cd554(920B @0032.c:68157)分段转写 ============
// plain 梯 kind0/1/2=holders[0..2],Skip 梯 kind3/4/5=holders[3..5];迁移腿不返回 true
// (q5)/goto 直灌,返回值 = 灌值腿结果。
inline bool runstylesUpgrade(ValueTable *b, qint64 pos, quint32 v, qint64 len)
{
    switch (b->kind) {
    case 0:
        if (v < 0x100)   return rsFill8 (b->holders[0], pos, quint8(v), len);   // gapbuffer_get_chars_locked 密排直写(委托 RS8)
        if (v < 0x10000) mkU16(b, 1);                                           // 009ceabe ctor + 009cee86 u8→u16 迁移(cited)
        else             mkU32(b, 2);                                           // 009cf2da ctor + 009cf8c2 u8→u32(cited);直落 LAB_009cd775
        break;
    case 1:
        if (v >= 0x10000) mkU32(b, 2);                                          // 009cf69e u16→u32 迁移(cited)
        break;                                                                  // 否则直灌 u16
    case 2: break;                                                              // 直灌 u32
    case 3:
        if (v < 0x100)   return rsFill8 (b->holders[3], pos, quint8(v), len);   // Uint8SkipRunStyles_h962e10(0032:68227)
        if (v < 0x10000) mkU16S(b, 4);                                          // 009cebe6 ctor + 009cf0b0(cited)
        else             mkU32S(b, 5);                                          // 009cf400 ctor + 009cfae6(cited)
        break;
    case 4:
        if (v >= 0x10000) mkU32S(b, 5);                                         // 009cfd0a u16S→u32S(cited)
        break;
    case 5: break;
    default: return false;                                                      // kind≥6 → 0
    }
    // LAB_009cd676 / LAB_009cd978 共尾:灌当前宽度层
    switch (b->kind) {
    case 1: return rsFill16(b->holders[1], pos, quint16(v), len);   // FUN_007b7290 ≡ RS16 FillRange
    case 2: return rsFill32(b->holders[2], pos, v,          len);   // FUN_007b8000 ≡ RS32 FillRange
    case 4: return rsFill16(b->holders[4], pos, quint16(v), len);   // Uint16SkipRunStyles_h9ce42e
    case 5: return rsFill32(b->holders[5], pos, v,          len);   // runstyles_fill_range_u8(语料标注原样,q7 同构佐证)
    }
    return false;
}

// ============ bankCtor 族(FUN_009cc22c/009cc264/009cc29c,各 55B @0032.c:66987+)============
// 语料:*p=kind;+0x08 delegate;holders[0..5](+0x10..0x38):除 delegate 与自身路 holder 外全 0。
// initDoc 只调 K3(009a310x);K4/K5 为 upgrade 迁移后的形态同构。
inline void bankCtorK3(ValueTable *b, void *rs)   // FUN_009cc22c
{ b->kind = 3; b->delegate = rs;
  b->holders[0] = b->holders[1] = b->holders[2] = nullptr;
  b->holders[3] = rs; b->holders[4] = b->holders[5] = nullptr; }
inline void bankCtorK4(ValueTable *b, void *rs)   // FUN_009cc264
{ b->kind = 4; b->delegate = rs;
  b->holders[0] = b->holders[1] = b->holders[2] = b->holders[3] = nullptr;
  b->holders[4] = rs; b->holders[5] = nullptr; }
inline void bankCtorK5(ValueTable *b, void *rs)   // FUN_009cc29c
{ b->kind = 5; b->delegate = rs;
  b->holders[0] = b->holders[1] = b->holders[2] = b->holders[3] = b->holders[4] = nullptr;
  b->holders[5] = rs; }

// FUN_009a3116 editor_freeDocState4 — cited — wave-2(旧 doc-state 条目清理,体未转写)
inline void editor_freeDocState4(void *, int) {}
// bimapReg — FUN_00a1028e — cited — wave-2(props 值<0x2000 → 13bit 键注册;壳期返 0)
inline quint32 bimapReg(void *, quint32) { return 0; }
// FUN_009a5f80(733B)u32→u64 批量重建 — cited — wave-2(仅读头;mk3 §9)
inline void remapU32toU64(MarkEntryObj *, MarkEntryObj *) {}
// u64 载体腿 stubs — cited — wave-2(迁移腿 cited 后 runs 恒 0,壳期不可达):
// runs_count = vt+0x30(vcall 直比 vt6 短路);valueAt = run 索引读(Ghidra 丢 pos 形);
// FUN_009a00ce(runs,styles,idx,1)/ FUN_007b5b50 ≡ SetValueAt(同值 run 合并;§9 未读体)
inline qint64   u64RunsCount(MarkEntryObj *)               { return 0; }
inline quint64  u64ValueAt(MarkEntryObj *, int)            { return 0; }
inline void     u64DelRun(MarkEntryObj *, int)             {}
inline void     u64SetValue(MarkEntryObj *, int, quint64)  {}
// makeU64Styles — 009a6452 形:operator_new(0x20)+FUN_007b6480(,0,0) ctor(cited)+vt(cited);
// 我方委托形态 = MarkEntryObj 壳 + 内层 RS64(+0x10 直存,§1 同怪癖)
inline MarkEntryObj *makeU64Styles()
{
    MarkEntryObj *o = new MarkEntryObj{};
    o->vtbl = nullptr;                   // cited — Uint64RunStyles vt
    o->styles = nullptr;                 // RS64 实例化暂缓(批 72;构建者批接线时随 rebuild_deps 启用)
    return o;
}

// ⚠ 批 69 勘正(mk2 构建者勘察):M ≡ D = doc-state(0x70B,挂
// E+0xc0);pool/stopCount/serialEntries/name/nodes 实属 E 对象
// (+0x118/+0x128/+0x250/+0x2b8/+0x2d8),已迁 EditorContext 平铺。
// A=0x38/bank=0x40 全在 editor_initDoc(009a2e1e,956B)尾构建。
// tlist(+0x18):0099c75a 读侧实证 vs mk2"lexerSnap"说冲突,以读侧
// 为准,构建者批复核。
struct MarkersStore {                    // M ≡ D = doc-state(0x70B;mk3 全偏移核)
    MarkersArray *arr;                   // +0x000 A(0x38;*A=D 回指)
    void         *doc;                   // +0x008 E(折叠 +0xe0 族 / 层级 +0xa0 / 行数 +0xf8)
    quint64      slot10;                 // +0x010 原始入参槽(initDoc param_3);0099c8d6 低 4B
                                         //   用作 u32 滚动计数 — 同槽两用,语料字面怪癖
    ValueTable   *tlist;                 // +0x018 T(FUN_00a101a0)/ lexerSnap(initDoc
                                         //   FUN_00930f9e(E,0) 同槽;0099c75a 读侧为准)
    quint64      scanCursor;             // +0x020 扫描游标(initDoc param_1[4]=0)
    quint32      idAlloc;                // +0x028 id 分配器(markWrite 009a62c0 取用)
    quint8       stopFlag;               // +0x02c 停机标志(0099cfb6 置 1)
    quint8       _r2d[0x03];             // +0x02d..0x2f 对齐残隙(语料未触)
    void        *bucketTab;              // +0x030 桶表(initDoc param_1[6]=0)
    void        *memo;                   // +0x038 memo QHash(initDoc =&QHashData::shared_null;
                                         //   Qt 内部地址 — cited,壳期 nullptr)
    void        *builder;                // +0x040 builder(initDoc param_1[8]=0)
    quint8       spin;                   // +0x048 读侧自旋字节(0069e8ac;解锁=写0)
    quint8       _r49[0x07];
    quint64      visibleSnap;            // +0x050 可见快照槽(0099d1f6 返回 &此;initDoc 不清零,q3)
    SpBase      *curSnap;                // +0x058 当前快照
    quint64      stagedSnap;             // +0x060 暂存快照(publishOutline 写 model 指针 — q4
                                         //   勘正:指针槽,位形等价)
    SpBase      *pendSnap;               // +0x068 待发布快照(0x70 止)

    MarkersStore()
    {
        // 语料 M 为裸内存零化;此处含 Qt 成员,禁 memset(析构崩)——
        // POD 显式清零,Qt 成员走默认构造(mk3 新字段 +0x10..0x47 一并入)
        arr = nullptr; doc = nullptr; slot10 = 0; tlist = nullptr;
        scanCursor = 0; idAlloc = 0; stopFlag = 0;
        bucketTab = nullptr; memo = nullptr; builder = nullptr;
        spin = 0; visibleSnap = 0; curSnap = nullptr;
        stagedSnap = 0; pendSnap = nullptr;
    }
    // ⚠ M+0x50/+0x58 与观测 holder(+0x8 ptr/+0x10 flag)对位差待复核;
    //   按 FUN_0099d1f6 字面(+0x50 快照值/+0x58 shared_ptr)落,构建者批复核。

    // ============ FUN_0069e8ac spinlock_lock_backoff(164B,全读)============
    static void spinlock_lock_backoff(quint8 *p)
    {
        for (unsigned n = 0;;) {
            // 0069e8bc: LOCK; old=*p; *p=1
            const quint8 old = __atomic_exchange_n(p, quint8(1), __ATOMIC_SEQ_CST);
            if (old == 0) return;                        // 得锁
            if (n < 2) { ++n; continue; }                // 0069e908 忙测×2
            if (n > 0xf) {                               // 0069e914:100ns(<0x20)/10µs
                timespec t{0, (n < 0x20) ? 100L : 10000L};
                while (nanosleep(&t, &t) == -1 && errno == EINTR) {}
                ++n; continue;
            }
            sched_yield(); ++n;                          // 0069e93c
        }
    }

    // ============ FUN_0099cec0(12B)= A entry[2] != 0 ============
    bool buildPending() const { return arr->entryAt(2) != nullptr; }  // 构建待就绪

    // ============ FUN_0099cecc(114B)swap-then-delete ============
    // swap A[i]↔A[j];毁 swap 后 A[i](vt+0x08 D1 dtor + operator_delete 0x18)。
    // QUIRKS:仅 +0x08 内对象析构(+0x10 路线不析构)——语料原样。
    void moveEntry(int i, int j)
    {
        MarkEntry *tmp    = *arr->entryPtr(i);
        *arr->entryPtr(i) = *arr->entryPtr(j);
        *arr->entryPtr(j) = tmp;
        MarkEntry *e = *arr->entryPtr(i);
        if (e) {
            if (e->u32Obj)                               // 语料只走 +0x08 路线
                vcallSlotVoid(e->u32Obj, 0x08);          // vt+0x08 = D1 dtor
            ::operator delete(e, std::size_t(24));       // operator_delete(_,0x18)
            *arr->entryPtr(i) = nullptr;
        }
    }

    // ============ FUN_0099c9c2(12B)行→run 索引 ============
    // →FUN_009cc396(10B):银行对象 +0x08 委托 vt+0x28 尾调(line 第 1 参)
    qint64 runIndexOfLine(quint64 line)
    { return vcallSlotArg(arr->bank->delegate, 0x28, qint64(line)); }

    // ============ FUN_0099c974(12B)→FUN_009cd3da(155B)6 路取值 ============
    static void *rsOf(void *holder)                      // *(holder)→内对象;内+0x10→RS
    { return *reinterpret_cast<void **>(reinterpret_cast<char *>(holder) + 0x10); }
    quint64 runValueAt(int idx) const
    {
        ValueTable *b = arr->bank;                       // *(A+0x18)
        if (b->kind < 6) {
            switch (b->kind) {                           // 每路:*holder→内对象,+0x10→RS
            case 0: return rsValue8 (rsOf(b->holders[0]), idx);   // FUN_0088ff00  u8
            case 1: return rsValue16(rsOf(b->holders[1]), idx);   // runstyles_value_at16
            case 2: return rsValue32(rsOf(b->holders[2]), idx);   // Uint32RunStyles_valueAt
            case 3: return rsValue8 (rsOf(b->holders[3]), idx);
            case 4: return rsValue16(rsOf(b->holders[4]), idx);
            case 5: return rsValue32(rsOf(b->holders[5]), idx);
            }
        }
        return 0;                                        // kind≥6 → 0(009cd3da 尾)
    }

    // ============ FUN_00a101a0/00a10384 twin(232B 全读)holder 表读 ============
    // holder 槽:+0x58(T=M+0x18)/ +0x60(值表=A+0x18);holder+0xc 字节自旋;
    // QListData::Data(begin@+8,end@+0xc,槽@+0x10,槽宽 8B);越界→holder vt+0x18。
    static quint64 tblRead(quint8 *holderLoc, quint32 key)
    {
        quint8 *h = *reinterpret_cast<quint8 **>(holderLoc);
        for (unsigned n = 0;;) {
            const quint8 old = __atomic_exchange_n(h + 0xc, quint8(1), __ATOMIC_SEQ_CST);
            if (old == 0) {                              // 得锁
                quint8 *d = *reinterpret_cast<quint8 **>(h + 0x10);
                const int begin = *reinterpret_cast<int *>(d + 8);
                const int end   = *reinterpret_cast<int *>(d + 0xc);
                quint64 v = 0;
                if (unsigned(key) < unsigned(end - begin))
                    v = *reinterpret_cast<quint64 *>(d + 0x10 + size_t(key + begin) * 8);
                else
                    v = listFallbackVt18(h);             // vt+0x18 — cited
                __atomic_store_n(h + 0xc, quint8(0), __ATOMIC_SEQ_CST);
                return v;
            }
            if (n < 2) { ++n; continue; }
            if (n > 0xf) {
                timespec t{0, (n < 0x20) ? 100L : 10000L};
                while (nanosleep(&t, &t) == -1 && errno == EINTR) {}
                ++n; continue;                           // 语料成功才 ++
            }
            sched_yield(); ++n;
        }
    }
    // FUN_0099c75a(9B):T@M+0x18,holder@+0x58,key = v>>2 → u32 props
    quint32 propsOf(quint64 v) const
    { return quint32(tblRead(reinterpret_cast<quint8 *>(tlist) + 0x58, quint32(v >> 2))); }
    // FUN_00a10384 包装:值表(A+0x18),holder@+0x60,key = v&0x1fff
    static quint32 keyPropsOf(ValueTable *vt, quint32 key)
    { return quint32(tblRead(reinterpret_cast<quint8 *>(vt) + 0x60, key)); }

    // ============ FUN_0099cf3e/5c/7a/98(各 29B)条目 4 槽尾调 ============
    // 公共选路(语料字面):取 entry[slot](无空判,原样);sel!=0→+0x08,否则→+0x10
    MarkEntryObj *slotObj(int slot) const
    {
        MarkEntry *e = arr->entryAt(slot);
        return e->sel != '\0' ? e->u32Obj : e->u64Obj;
    }
    qint64 entryFirstIndex(int slot) const { return vcallSlot(slotObj(slot), 0x28); }  // 0099cf3e
    qint64 entryCount(int slot)      const { return vcallSlot(slotObj(slot), 0x30); }  // 0099cf5c
    qint64 entryBegin(int slot)      const { return vcallSlot(slotObj(slot), 0x38); }  // 0099cf7a
    qint64 entryEnd(int slot)        const { return vcallSlot(slotObj(slot), 0x40); }  // 0099cf98

    // ============ FUN_009a06ac(99B)读条目行值 ============
    // sel==0→u64 原值;否则 u32 拆 {id:v>>13, key:v&0x1fff},key 过值表 → {hi=id,lo=props}
    quint64 entryValueAt(int pos, int slot) const
    {
        MarkEntry *e = arr->entryAt(slot);
        if (e->sel == '\0')
            return rsValue64(rsOf(e->u64Obj->styles), pos);      // Uint64RunStyles_valueAt
        const quint32 v = rsValue32(rsOf(e->u32Obj->styles), pos);
        const quint32 props = keyPropsOf(arr->bank, v & 0x1fff); // FUN_00a10384
        return (quint64(v >> 13) << 32) | props;                 // CONCAT44(v>>0xd, props)
    }

    // ============ FUN_009a0710(45B)邻值比较(sameRun 谓词)============
    bool sameRunValue(int pos, quint64 v, int slot) const
    {
        if (pos < 1) return true;                                // 语料:param_2<1 → 1
        const quint64 u = entryValueAt(pos - 1, slot);           // FUN_009a06ac
        return (v & Q_UINT64_C(0xfffffffffff8001f)) !=           // ChangeMask(009a0710)
               (u & Q_UINT64_C(0xfffffffffff8001f));
    }

    // ============ FUN_009a073e(154B)含 pos 的 run 终行 ============
    int runEndLine(int pos, int slot) const
    {
        const quint64 v0 = entryValueAt(pos, slot);              // FUN_009a06ac
        const int last = int(entryCount(slot));                  // FUN_0099cf5c(vt+0x30)
        if (pos < last) {
            int i = pos;
            int nx = i;
            do {
                nx = i + 1;
                const quint64 v = entryValueAt(nx, slot);
                // 掩码:hi32 全保 + 低 32 位 &0xfff8001f
                if ((quint64(v & Q_UINT64_C(0xffffffff00000000)) |
                     quint64(quint32(v) & 0xfff8001fu)) !=
                    (v0 & Q_UINT64_C(0xfffffffffff8001f)))
                    return pos;                                  // 失配 → pos 即终
                i = nx;
            } while (nx != last);                                // 语料 while(iVar4!=iVar1)
        } else if (pos != last) {
            return pos;
        }
        return last - 1;                                         // 全 run 等值 → count-1
    }

    // ============ FUN_009a07d8(82B)反向扫最近 id ============
    // 入口 FUN_00926e52(24B):*out=0 后调本函数;槽参数 Ghidra 丢参,按消费点=0
    void nearestIdFrom(qint64 from, quint32 *out)
    {
        spinlock_lock_backoff(&spin);                            // +0x48
        int i = int(entryFirstIndex(0));                         // FUN_0099cf3e(vt+0x28)
        if (i >= 0) {
            do {
                const quint64 v = entryValueAt(i, 0);            // FUN_009a06ac
                if ((v >> 32) != 0) { *out = quint32(v >> 32); break; }  // id = hi32
                --i;
            } while (i != -1);
        }
        spin = 0;                                                // 解锁 = 写 0
        (void)from;                                              // Ghidra 丢参保留
    }

    // ============ FUN_009a0830(94B)slot0 线性找首行 ============
    // 语料字面:比较 RAX 低 32 位 == target(字面怪癖,原样;行为测试裁决)
    int findLineSlot(int target) const
    {
        const int n = int(entryCount(0));                        // FUN_0099cf5c
        if (n > 0) {
            for (int i = 0; i != n; ++i)
                if (quint32(entryValueAt(i, 0)) == quint32(target))
                    return i;
        }
        return -1;
    }

    // ============ FUN_009a088e(215B)行→区间解析 ============
    void lineSpan(quint32 line, quint64 out[2])
    {
        spinlock_lock_backoff(&spin);
        const int i = findLineSlot(int(line));                   // FUN_009a0830
        if (i == -1) { spin = 0; return; }                       // LAB_009a0910 空手解锁
        out[0] = quint64(entryBegin(i));                         // FUN_0099cf7a(vt+0x38)
        const int n    = int(entryCount(0));                     // FUN_0099cf5c(slot0)
        const quint64 v = entryValueAt(i, 0);                    // FUN_009a06ac
        quint64 end;
        if ((quint8(v >> 0x18) & 0xf0) == 0x50) {                // bits28-31 == 5 分支
            const int e = runEndLine(i, 0) + 1;                  // FUN_009a073e +1 起
            if (n <= e) {
                end = quint64(foldCollapseEnd(doc, qint64(out[0])));      // cited
            } else {                                             // 向末扫:hi32(v)==低32
                int j = e; bool hit = false;                     // (语料字面比较,原样)
                do {
                    if (quint32(v >> 32) == quint32(entryValueAt(j, 0))) { hit = true; break; }
                    ++j;
                } while (j != n);
                if (hit)
                    end = quint64(entryEnd(runEndLine(j, 0)));   // 009a073e→FUN_0099cf98
                else
                    end = quint64(foldCollapseEnd(doc, qint64(out[0])));  // cited
            }
        } else if (i == n) {
            end = quint64(foldCollapseEnd(doc, qint64(out[0])));          // cited
        } else {
            end = quint64(entryEnd(runEndLine(i, 0)));           // FUN_009a073e→FUN_0099cf98
        }
        out[1] = end;                                            // param_3[1]
        spin = 0;
    }

    // ============ FUN_009a096a(215B)按行剪枝/解析 ============
    // ⚠ 哨兵极性勘正:语料 `if ((props & 0x38) != 0x28) break;` = 非 0x28 即断
    long resolveLine(quint64 line)
    {
        quint64 span[2];
        lineSpan(quint32(line), span);                           // FUN_009a088e
        spinlock_lock_backoff(&spin);
        long cur = long(span[0]);                                // local_38
        const long end = long(span[1]);                          // local_30
        while (cur < end) {                                      // 折叠区间整块推进
            if (!foldFoldable(doc, cur)) break;                  // FUN_00927940 cited
            cur += foldStep(doc, cur, 1);                        // FUN_009252d4 cited
        }
        int r0 = int(runIndexOfLine(cur));                       // FUN_0099c9c2(vt+0x28)
        const int r1 = int(runIndexOfLine(end));
        if (r0 < r1) {
            do {
                const quint64 v = runValueAt(r0);                // FUN_0099c974(6 路)
                const quint32 props = propsOf(v >> 2);           // FUN_0099c75a(T 表)
                if ((props & 0x38) != 0x28) break;               // 语料字面:!=0x28 break
                if ((props & 0x1c0) == 0x100) {                  // 特型:行起,终止
                    cur = long(vcallSlotArg(arr->bank->delegate, 0x38, r0));  // 0099ca60
                    break;
                }
                ++r0;
            } while (r0 != r1);
        }
        spin = 0;
        return cur;
    }

    // ============ FUN_009a62c0(821B @0032.c:39421)markWrite(param_1=A;挂 D 成员,this=D)
    //              ============ 深腿 cited;id 分配:旧值 → bits28-31==0xd 不 ++,否则存回
    //              旧+1;packed 用加后值(q2)。勘正(对 mk2):param_1 = A 非 D。
    void markWrite(qint64 start, qint64 len, quint64 props)
    {
        if (len < 1) return;                                     // 39421+
        MarkEntry *e = arr->entryAt(1);                          // param_1[5] = A+0x28
        MarkEntryObj *obj = e->sel != '\0' ? e->u32Obj : e->u64Obj;
        const int last = int(vcallSlot(obj, 0x28));              // vt+0x28 firstIndex(0099cf3e 形)
        const qint64 end = vcallSlotArg(obj, 0x40, last);        // vt+0x40 end(0099cf98 形)
        if (end < start + len) return;                           // 39470:越出既有区间 → 弃

        quint64 cur = 0;                                         // 末 run 现值(Ghidra 丢 pos 参,同 009a06ac)
        if (e->sel == '\0') {
            cur = rsValue64(rsOf(e->u64Obj->styles), last);
        } else {
            const quint32 v32 = rsValue32(rsOf(e->u32Obj->styles), last);
            // FUN_00a10384;语料 arg = A+0x08 lexerSnap(≡D+0x18 同指针,q1)— 与 landed
            //   entryValueAt(arr->bank)不同源(冲突登记,待行为门);tlist 空为壳期守卫
            //   (工厂 FUN_00930f9e cited 未接线,tblRead 解引会崩)
            cur = (quint64(v32 >> 13) << 32) |
                  (tlist ? keyPropsOf(tlist, v32 & 0x1fff) : 0);
        }

        quint32 id;
        if ((props & 0x7c000) == 0) {                            // 无 props 位 → 建新条目腿
            if (cur != 0) return;                                // 已有值不覆盖
            id = idAlloc;                                        // D+0x28
            if ((quint8(props >> 0x18) & 0xf0) != 0xd0)          // bits28-31==0xd → 不占 id
                idAlloc = ++id;                                  // 存回旧+1;packed 用加后值
        } else {
            if (cur == 0) return;                                // 无宿主 run 不注
            id = idAlloc;
        }

        if (e->sel != '\0') {                                    // u32 载体腿
            void *lex = *reinterpret_cast<void **>(reinterpret_cast<char *>(arr) + 0x08);  // A+0x08(=D+0x18)
            bool ok32 = id < 0x80000;
            quint32 key = 0;
            if (ok32) { key = bimapReg(lex, quint32(props)); ok32 = key < 0x2000; }  // FUN_00a1028e(cited:值<0x2000→13bit)
            if (ok32) {
                rsFill32(e->u32Obj, start, (key & 0x1fff) | (id << 13), len);  // FUN_007b8000 ≡ RS32 FillRange
                return;                                          // 语料:写后 *e 仍 sel!=0 → 39464 直接返回
            }
            // 溢出(id≥0x80000 或 key≥0x2000)→ 迁移 u64 载体(009a6452..)
            e->sel = '\0';
            if (e->u64Obj) vcallSlotVoid(e->u64Obj, 0x08);       // 旧 +0x10 侧析构(vt+0x08 D1)
            e->u64Obj = makeU64Styles();                         // new 0x20 + FUN_007b6480(,0,0) ctor(cited)+vt(cited)
            remapU32toU64(e->u64Obj, e->u32Obj);                 // FUN_009a5f80(733B,cited:u32→u64 批量重建)
            // 重建后逐 run 重映射(语料字面 39474..39520;迁移腿 cited 后 runs=0,壳期不可达):
            const int runs = int(u64RunsCount(e->u64Obj));       // vt+0x30 runs_count(vcall 直比 vt6 短路)
            if (runs > 0) {
                for (quint32 i = 0; i != quint32(runs - 1) + 1; ++i) {   // do{}while(iVar2-1!=i)
                    quint64 v = u64ValueAt(e->u64Obj, int(i));   // plVar6[2] valueAt
                    const quint32 pr = keyPropsOf(tlist, quint32(v) & 0x1fff);  // FUN_00a10384(q1 同上;tlist 壳期已由上游 cur 腿守卫)
                    v = ((v >> 13 & Q_UINT64_C(0x7ffff)) << 32) | pr;   // id<<32 | props
                    if (i + 1 < quint32(runs) && v == u64ValueAt(e->u64Obj, int(i) + 1))
                        u64DelRun(e->u64Obj, int(i) + 1);        // FUN_009a00ce(runs,styles,idx,1)(cited leg)
                    if (i == 0 || v != u64ValueAt(e->u64Obj, int(i) - 1))
                        u64SetValue(e->u64Obj, int(i), v);       // FUN_007b5b50 ≡ SetValueAt(自带同值 run 合并)
                    else
                        u64DelRun(e->u64Obj, int(i));            // FUN_009a00ce
                }
            }
            if (e->sel != '\0') return;                          // 语料字面(迁移后 sel==0,直落)
        }
        // 尾插(LAB_009a65a0 形):u64 值 = id<<32 | props 低 32(原始 props,不过 bimap)
        rsFill64(e->u64Obj, start, (quint64(id) << 32) | quint32(props), len);  // Uint64RunStyles_insert ≡ FillRange(委托,同 §3)
    }

    // ---- publishOutline cited 腿(分派/工厂未读;mk3 §6/§9;壳期恒惰值)----
    // FUN_0099cfb6(60B @0032.c:32877):FUN_00925b44(*(D+0x08)) 非零 → *(D+0x2c)=1
    //   + 日志,返回该值;FUN_00925b44 体 cited — wave-2(壳期恒 0)
    bool stopped()
    {
        const void *hit = nullptr;                               // FUN_00925b44(doc) — cited
        if (hit) stopFlag = 1;                                   // 0099cfb6 字面(壳期不可达)
        return hit != nullptr;
    }
    static void  *makeOutlineModel(void *)          { return nullptr; }  // 009a2768..009a27dc model(0x38) 构造 — cited
    static void  *lazyStack(void *)                 { return nullptr; }  // FUN_00643e32(006443xx 惰性栈)— cited
    static int    entryCountOf(void *)              { return 0; }        // FUN_009f839c(*(D+0x10)) — cited 面
    static quint8 levelAt(void *, int)              { return 0; }        // FUN_009f958a — cited 面
    static void   stackPopHigher(void *, quint8)    {}                   // 槽尾 -0x10 byte,步长 0x18 回退(元素 struct 未解)— cited
    static void  *lexerSnapSnap(void *)             { return nullptr; }  // FUN_0099c874(9B)= FUN_00930f9e(*(D+0x08)) — cited
    static void  *docArg(void *, int)               { return nullptr; }  // doc 条目取值(未解)— cited
    static void  *docEnd(void *, int)               { return nullptr; }  // doc 条目止界(未解)— cited
    static void    outlineScan2(void *, void *, void **, void *, void *, void *) {}  // FUN_009a129c — cited
    static void    outlineScan3(void *, void *, void **) {}              // FUN_009a1fba — cited
    static void    outlineScan4(void *, void *, void **) {}              // FUN_009a23b4 — cited
    static void    outlineScanOther()                    {}              // FUN_009a14d4 — cited(空体疑义;体未读)
    static quint64 releaseAll(void *, void *, int)  { return 0; }        // 停机释放腿(LAB_009a28ec 返 0)— cited

    // ============ FUN_009a2766(585B @0032.c:36581)publishOutline ============
    // model(0x38)={vt=PTR_FUN_011adb78(cited);+8={1,1} refcnt;+0x10=&OutlineTreeModel_vtable;
    //   +0x28=*(D+0x08)(E);+0x30=&QHashData::shared_null} — 构造 cited(壳期 nullptr,尾段空守卫)。
    quint64 publishOutline()
    {
        void *model = makeOutlineModel(doc);                     // 009a2768..009a27dc(构造 cited)
        void *stack = lazyStack(model);                          // FUN_00643e32 — cited
        const int n = entryCountOf(doc);                         // FUN_009f839c(*(D+0x10))(cited 面)
        for (int i = 0; i != n; ++i) {
            if (stopped())                                       // FUN_0099cfb6:停机 → LAB_009a28ec 返 0
                return releaseAll(model, stack, 0);              // cited
            const quint8 lvl = levelAt(doc, i);                  // FUN_009f958a(cited 面)
            stackPopHigher(stack, lvl & 0x1f);                   // 语料:槽尾 -0x10 取 byte,步长 0x18 回退
            void *lex = lexerSnapSnap(doc);                      // FUN_0099c874(9B)= FUN_00930f9e(*(D+0x08))(cited)
            if (lex) {
                const char t = *reinterpret_cast<const char *>(
                    static_cast<char *>(lex) + 0x11);            // lexerSnap+0x11 类型字节
                if (t == 2)      outlineScan2(this, lex, &stack, nullptr, docArg(doc, i), docEnd(doc, i));  // cited;stackCtx 语料未解
                else if (t == 3) outlineScan3(this, lex, &stack);   // cited
                else if (t == 4) outlineScan4(this, lex, &stack);   // cited
                else             outlineScanOther();                // cited(空体疑义;体未读)
            }
        }
        if (stopped()) return releaseAll(model, stack, 0);       // FUN_0099cfb6 — cited
        spinlock_lock_backoff(&spin);                            // D+0x48
        stagedSnap = reinterpret_cast<quint64>(model);           // D+0x60 = model(指针槽!q4 勘正,009a2986)
        if (model != pendSnap) {                                 // D+0x68
            if (model)
                __atomic_add_fetch(reinterpret_cast<int *>(
                    static_cast<char *>(model) + 8), 1, __ATOMIC_SEQ_CST);  // LOCK ++refcnt(+8)
            if (pendSnap) pendSnap->_M_release();
            pendSnap = static_cast<SpBase *>(model);
        }
        moveEntry(1, 2);                                         // FUN_0099cecc(已落地)
        spin = 0;
        if (stack) ::operator delete(stack);
        if (model) reinterpret_cast<SpBase *>(model)->_M_release();  // 平衡构造引用(壳期跳过;语料字面无守卫)
        return 1;
    }

    // ============ FUN_0099d1f6(130B)发布快照 ============
    // +0x50/+0x58 语义对位差待复核;按语料字面。
    quint64 *publishSnapshot()
    {
        spinlock_lock_backoff(&spin);                            // +0x48
        if (buildPending()) {                                    // FUN_0099cec0:entry[2]!=0
            visibleSnap = stagedSnap;                            // +0x50 = +0x60
            SpBase *pend = pendSnap;                             // +0x68
            SpBase *cur  = curSnap;                              // +0x58
            if (pend != cur) {
                if (pend) {
                    // LOCK; ++*(int*)(pend+8) — _Sp_use_count++(0099d225)
                    __atomic_add_fetch(reinterpret_cast<int *>(
                        reinterpret_cast<char *>(pend) + 8), 1, __ATOMIC_SEQ_CST);
                    cur = curSnap;
                }
                if (cur) cur->_M_release();                      // _Sp_counted_base
                curSnap = pend;
            }
            moveEntry(2, 0);                                     // FUN_0099cecc:entry[2]→[0]
        }
        spin = 0;
        return &visibleSnap;                                     // 返回 &M+0x50
    }

    // ============ markersCtxInit — editor_initDoc 尾段转写(009a2e93..009a311a;
    //              0032.c:36911;editor_initDoc 009a2e1e 956B 的精读段)============
    // 分配尾逐偏移;D+0x50 语料不清零(q3,构造器清零属构造语境与此无涉)。
    static void markersCtxInit(MarkersStore *D, void *E, void *param3, void *lexerSnap)
    {
        D->doc = E;                                              // param_1[1] 009a2e93
        D->slot10 = reinterpret_cast<quint64>(param3);           // param_1[2](原始入参槽;指针按位存)
        D->scanCursor = 0;                                       // param_1[4] +0x20 扫描游标
        D->idAlloc = 0;                                          // *(u32*)(D+0x28)=0 id 分配器
        D->stopFlag = 0;                                         // *(u8*)(D+0x2c)=0 停机标志
        D->tlist = nullptr;                                      // param_1[3] +0x18 = FUN_00930f9e(E,0) — cited(工厂未转写;读侧 T 同槽)
        D->bucketTab = nullptr;                                  // param_1[6] +0x30 桶表
        D->memo = nullptr;                                       // param_1[7] +0x38 =&QHashData::shared_null(cited Qt 边界)
        D->builder = nullptr;                                    // param_1[8] +0x40 builder
        D->spin = 0;                                             // *(u8*)(D+0x48)=0 自旋字节
        D->curSnap = nullptr;                                    // param_1[0xb] +0x58
        D->stagedSnap = 0;                                       // param_1[0xc] +0x60
        D->pendSnap = nullptr;                                   // param_1[0xd] +0x68
        // q3:param_1[0xa](+0x50)语料不清零 — 原样跳过

        MarkersArray *A = static_cast<MarkersArray *>(::operator new(0x38));   // 009a2eb2
        A->core = D;                                             // *A = D 回指 009a2eb6
        A->lexerSnap = lexerSnap;                                // puVar6[1]=param_1[3](≡D+0x18 同指针)
        A->_r10[0] = A->_r10[1] = A->_r10[2] = A->_r10[3] = 0;   // *(u32*)(puVar6+2)=0(+0x10 u32 字面)
        *A->entryPtr(0) = nullptr;                               // puVar6[4..6]=0
        *A->entryPtr(1) = nullptr;
        *A->entryPtr(2) = nullptr;

        // RS 包装(0x20)009a2ed7:{vt=&PTR_FUN_011ad300 占位 → 009a30e0 换
        //   Uint8SkipRunStyles_vtable(cited);+0x08 = editctx_initThread(operator_new(0x50),
        //   FUN_0092801a(E))(cited 线程 ctx)}。
        // GB(0x30)009a2f31:{vt=&PTR_FUN_01192288(cited);puVar9[1]=0x100000000;
        //   *(u32*)(GB+0x14)&=0x80000000;puVar9[3..5]=0};FUN_0093fc60(546B)残留释放腿
        //   009a2fa5..009a30a4(cited);009a30a9 DATA=operator_new(0x20) 全零;
        //   009a30c6 GB+0x18=DATA;009a30cd RS+0x10=GB;009a2f90 gapbuffer_reallocate(gb,0,0,2)
        //   (cited)—— 以上 GB 腿整体 cited:我方委托形态由内层 RS 实例直存 holder+0x10
        //   取代 GB+DATA 密排(读逐位等价,mk3 §1 怪癖登记)。
        RsHolder20 *rs = makeHolder0x20(new RS8());              // 009a2ed7/009a30cd;内层 = RunStyles<int,char>(委托)

        ValueTable *bank = static_cast<ValueTable *>(::operator new(0x40));    // 009a3107(bank 分配 0x40 语料字面)
        bankCtorK3(bank, rs);                                    // FUN_009cc22c(kind=3,holders[3]=rs)
        A->bank = bank;                                          // puVar6[3] 009a3110
        editor_freeDocState4(A, 0);                              // cited 009a3116(旧 doc-state 条目清理)
        D->arr = A;                                              // *param_1 = puVar6 009a311a
    }

    // ============ FUN_0099c8d6(140B @0032.c:32421)coreWriteRange ============
    // core=*(A)=D 回指;锁 core+0x48;滚动低 2bit 由 D+0x10 计数供给(q5 语义:重灌
    // 条件 = 灌值腿返回值);滚动 2bit 怪癖原样。
    void coreWriteRange(qint64 start, qint64 len, quint32 value, char rolling)
    {
        if (len < 1) return;                                     // 0099c8d8
        MarkersArray *A = arr;                                   // param_1 = *(long*)param_1
        quint8 *core = reinterpret_cast<quint8 *>(A->core);      // *(A) = D(回指)
        spinlock_lock_backoff(core + 0x48);                      // 0099c8ea(= &spin)
        if (rolling == '\0') {
            do {
                quint32 roll = *reinterpret_cast<quint32 *>(core + 0x10);  // D+0x10 滚动计数
                *reinterpret_cast<quint32 *>(core + 0x10) = roll + 1;
                value = (value & 0xfffffffcu) | (roll & 3);      // 低 2bit 滚动供给
            } while (runstylesUpgrade(A->bank, start, value, len));  // A+0x18;真 → 重灌
        } else {
            runstylesUpgrade(A->bank, start, value, len);        // 单发
        }
        spin = 0;                                                // *(core+0x48)=0 解锁
    }

    // FUN_0092e44e(0x754d 体)已迁 EditorEngine case 0x754d —— 批 69
    // 勘正:stopCount/nodes 属 E 面,不在 D(本结构)
};

static_assert(sizeof(MarkersStore) == 0x70, "D 0x70B (mk2 勘正;mk3 全偏移核)");

} // namespace wt
