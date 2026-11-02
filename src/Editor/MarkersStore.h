// MarkersStore — markers 对象读侧真身化(批 67a;布局与函数全部语料实证)
// 布局还原:FUN_0099cxxx/009a0xxx 存储族 16 函数(台账见 docs/PHASE5.md 批 67)。
// 写侧构建者批已落地(mk3):markersCtxInit(009a2e1e 尾段)/bankCtor 族(009cc22c/
// 009cc264/009cc29c)/runstylesUpgrade(009cd554)/coreWriteRange(0099c8d6)/
// markWrite(009a62c0)/publishOutline(009a2766)+ rsValue* 委托真身(§7)。
// 值迁移腿六函数已落地(批 86):migrateLayer 参数化体(009cee86/009cf8c2/009cf69e/
// 009cf0b0/009cfae6/009cfd0a 六体同构)+ migU* 六入口,runstylesUpgrade 接真身调用。
// builder C 级 regex 执行机已落地(批 101):builderRegexRun(00a83c7a 400B)调用面
// 转写 + Onigmo-改 底座(EXT-BOUNDARY 2026-10-29 第一方组件条目:委托 src/Onigmo);
// kwMatchCache 装载侧真身(kwCacheFill 0099d27e 600B)→ 击中面仍 cited(QHash
// 底座改版定性:语料 QHashData 手工节点布局,我方 QHash 承载 — 怪癖登记)。
// regionScan 0099d072 关键词腿返回门落地(批 88 挂账;keywordsLoad 自由函数 +
// MarkersStore::keywordsLoadGate 包装 — EditorEngine.cpp 0x7543 接线一行随
// 主批次,写域禁改未接)。行为测试须等写入侧接线。
// 语料地址均为 Ghidra 基址(非 PIE 直通)。
#pragma once

#include <QtGlobal>
#include <QList>
#include <QVector>
#include <QMap>
#include <QHash>
#include <QString>
#include <QStringList>
#include <memory>
#include <stddef.h>
#include <cstddef>
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
// rsFill64:RS64 实例化暂缓(见 rsValue64),占位 — cited — wave-2
inline bool rsFill8(void *h, qint64 pos, quint8 v, qint64 len)
{ return h && static_cast<RS8 *>(holderRs(h))->FillRange(int(pos), char(v), int(len)).changed; }
inline bool rsFill16(void *h, qint64 pos, quint16 v, qint64 len)
{ return h && static_cast<RS16 *>(holderRs(h))->FillRange(int(pos), int(v), int(len)).changed; }
inline bool rsFill32(void *h, qint64 pos, quint32 v, qint64 len)
{ return h && static_cast<RS32 *>(holderRs(h))->FillRange(int(pos), int(v), int(len)).changed; }   // u32 窄存 int,位型等价(mk3 §7)
// rsFill64:RS64 实例化暂缓(见 rsValue64),占位 — cited — wave-2
inline bool rsFill64(void *, qint64, quint64, qint64) { return false; }

// 升宽换层公共尾(LAB_009cd775):holders[slot]=新;delegate=新;kind=slot。
// 值迁移腿批 86 已转写(下行 migU* 六入口;语料六函数全读)。
inline void mkLayer(ValueTable *b, int slot, void *newHolder)
{ b->holders[slot] = newHolder; b->delegate = newHolder; b->kind = quint32(slot); }
// mkU 族 — operator_new(0x20){vt 占位;0;0;0}(009cd898 形)+ ctor cited(FUN_009ceabe/
// 009cf2da/009cebe6/009cf400 形);内层 = 我方对应宽度 RS(+0x10 直存,§1 同怪癖)
inline void mkU16 (ValueTable *b, int slot) { mkLayer(b, slot, makeHolder0x20(new RS16())); }  // 009ceabe 形 plain u16
inline void mkU32 (ValueTable *b, int slot) { mkLayer(b, slot, makeHolder0x20(new RS32())); }  // 009cf2da 形 plain u32
inline void mkU16S(ValueTable *b, int slot) { mkLayer(b, slot, makeHolder0x20(new RS16())); }  // 009cebe6 形 Skip u16
inline void mkU32S(ValueTable *b, int slot) { mkLayer(b, slot, makeHolder0x20(new RS32())); }  // 009cf400 形 Skip u32

// ============ 值迁移腿六函数(批 86 落地;0032.c 全读:009cee86@69181/009cf0b0@69265/
//              009cf69e@69501/009cf8c2@69585/009cfae6@69669/009cfd0a@69753)============
// 六体逐行同构(各 505-510B;仅 ctor 入口/旧层读函数/写宽度三处差)→ 模板参数化单体:
//   OLDRS = 旧层读宽(FUN_0088ff00 → RS8 / runstyles_value_at16 → RS16);NEWRS = 新层写宽。
// 语料体(以 009cee86 为代表,行号 = 0032.c):
//   ① ctor:FUN_009ceabe(param_1,0,…) 形(upgrade 调点先建新层;mkU* 承载)
//   ② 69190-95 槽面搬运:uVar1=*(旧+0x08)/plVar2=*(旧+0x10)(旧层 face);旧 +0x08/+0x10 清 0
//   ③ 69196-201:新 +0x08 非空 → vt+0x08 析构(ctor 所建 pieceTable)→ 新 +0x08 = uVar1
//      (我方 threadCtx cited 恒 0,赋值同构)
//   ④ 69202-10 长度差尾:旧长 = plVar2[2];新长 = 新层 +0x10 面;新短 → Uint1xRunStyles_fill
//      (新face,新长,0,差)(68208)—— 委托 InsertSpace 零值扩(RunStyles.cxx:188)
//   ⑤ 69212+ 逐位搬运 for u in [0,旧长):v = 读旧层 → 零扩展窄升 → 直写新层 DATA(GB 密排路
//      threadLocalGet/runstyles_threadData+part1/gap 三段判断)—— 委托 NEWRS SetValueAt
//      (≡ FillRange(u,v,1),RunStyles.cxx:185;run 合并语义差,怪癖登记)
//   ⑥ 69260-4 尾:vt+0x08 析构旧层 face(我方 delete;语料 D1 单独调,释放权在 D0 链 —
//      委托态收尾等价);析构旧 holder;*param_2 = 0(旧槽清)
template <class OLDRS, class NEWRS>
inline void migrateLayer(void *newHolder, void **oldSlot, quint32 srcMask)
{
    RsHolder20 *nu  = static_cast<RsHolder20 *>(newHolder);
    RsHolder20 *old = static_cast<RsHolder20 *>(*oldSlot);          // 69189 lVar8 = *param_2
    nu->threadCtx = old->threadCtx;                                 // ③ 69201(我方 cited 恒 0)
    old->threadCtx = nullptr;                                       // ③ 69194
    OLDRS *oldRs = static_cast<OLDRS *>(old->rs);                   // ③ 69192 plVar2(旧层 face)
    old->rs = nullptr;                                              // ③ 69195
    const int oldLen = oldRs ? int(oldRs->Length()) : 0;            // ④ 69197 plVar2[2]
    const int nuLen  = int(static_cast<NEWRS *>(nu->rs)->Length()); // ④ 69198 新层长面
    if (nuLen < oldLen)                                             // ④ 68207-9 零填尾
        static_cast<NEWRS *>(nu->rs)->InsertSpace(nuLen, oldLen - nuLen);
    for (int u = 0; u < oldLen; ++u) {                              // ⑤ 逐位搬运(窄升)
        const quint32 v = quint32(oldRs->ValueAt(u)) & srcMask;     // 零扩展(byte/ushort 字面)
        static_cast<NEWRS *>(nu->rs)->SetValueAt(u, int(v));        // 直写新层
    }
    delete oldRs;                                                   // ⑥ 69260 旧层 face D1
    delete old;                                                     // ⑥ 69261-3 旧 holder
    *oldSlot = nullptr;                                             // ⑥ 69264 *param_2 = 0
}
// migU* 六入口(009cd554 迁移腿调用点字面:<OLDRS,NEWRS> 分派;oldSlot 传 holders 槽址)
inline void migU16 (ValueTable *b) { mkU16 (b, 1); migrateLayer<RS8 , RS16>(b->holders[1], &b->holders[0], 0xffu);   }  // 009cee86 u8→u16(ctor 009ceabe)
inline void migU32 (ValueTable *b) { mkU32 (b, 2); migrateLayer<RS8 , RS32>(b->holders[2], &b->holders[0], 0xffu);   }  // 009cf8c2 u8→u32(ctor 009cf2da)
inline void migU32b(ValueTable *b) { mkU32 (b, 2); migrateLayer<RS16, RS32>(b->holders[2], &b->holders[1], 0xffffu); }  // 009cf69e u16→u32(ctor 009cf2da)
inline void migU16S(ValueTable *b) { mkU16S(b, 4); migrateLayer<RS8 , RS16>(b->holders[4], &b->holders[3], 0xffu);   }  // 009cf0b0 u8S→u16S(ctor 009cebe6)
inline void migU32S(ValueTable *b) { mkU32S(b, 5); migrateLayer<RS8 , RS32>(b->holders[5], &b->holders[3], 0xffu);   }  // 009cfae6 u8S→u32S(ctor 009cf400)
inline void migU32Sb(ValueTable *b){ mkU32S(b, 5); migrateLayer<RS16, RS32>(b->holders[5], &b->holders[4], 0xffffu); }  // 009cfd0a u16S→u32S(ctor 009cf400)

// ============ runstylesUpgrade — FUN_009cd554(920B @0032.c:68157)分段转写 ============
// plain 梯 kind0/1/2=holders[0..2],Skip 梯 kind3/4/5=holders[3..5];迁移腿不返回 true
// (q5)/goto 直灌,返回值 = 灌值腿结果。
inline bool runstylesUpgrade(ValueTable *b, qint64 pos, quint32 v, qint64 len)
{
    switch (b->kind) {
    case 0:
        if (v < 0x100)   return rsFill8 (b->holders[0], pos, quint8(v), len);   // gapbuffer_get_chars_locked 密排直写(委托 RS8)
        if (v < 0x10000) { migU16(b); }                                         // 009ceabe ctor + 009cee86 u8→u16 迁移(批 86)
        else             { migU32(b); }                                         // 009cf2da ctor + 009cf8c2 u8→u32(批 86);直落 LAB_009cd775
        break;
    case 1:
        if (v >= 0x10000) migU32b(b);                                           // 009cf69e u16→u32 迁移(批 86)
        break;                                                                  // 否则直灌 u16
    case 2: break;                                                              // 直灌 u32
    case 3:
        if (v < 0x100)   return rsFill8 (b->holders[3], pos, quint8(v), len);   // Uint8SkipRunStyles_h962e10(0032:68227)
        if (v < 0x10000) { migU16S(b); }                                        // 009cebe6 ctor + 009cf0b0(批 86)
        else             { migU32S(b); }                                        // 009cf400 ctor + 009cfae6(批 86)
        break;
    case 4:
        if (v >= 0x10000) migU32Sb(b);                                          // 009cfd0a u16S→u32S(批 86)
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

// ============ ScannerX — lexer/scanner 对象(buffer+0x108;批 markers 翻真②)============
// FUN_00a1092a(403B @0033.c:43953)ctor 全读;分配 0x70,vt=PTR_scanner_freeEntries_
// 011ae108;+0x58/+0x60 = 两个 Uint32Bimap(0x20 holder:{vt;+4 u32;+c spin;+0x10
// QListData;+0x18 0})— 我方 QVector<quint32> 双表承载(styleProps190 同款先例,
// EXT-BOUNDARY:metacall 体未读 — 查得即返/miss 追加,怪癖登记)。
// 生产者 = FUN_009de20a(3051B,yaml lexer 装载)— cited;消费面 = tlist(D+0x18)≡ 同指针。
// Uint32Bimap_qt_metacall 承载(值→idx;查得即返,miss 追加)— styleProps190 同款:
inline quint32 bimapPut(QVector<quint32> &t, quint32 v)
{
    const int i = t.indexOf(v);
    if (i < 0) { t.append(v); return quint32(t.size() - 1); }
    return quint32(i);
}

struct ScannerX {                        // 0x70 布局照 ctor 语料(分配 0x70,00a1092a)
    void    *vtbl = nullptr;             // +0x00 cited — PTR_scanner_freeEntries_011ae108
    quint64  _r08 = 0;                   // +0x08/+0x10 FUN_00a12910 基 ctor 段 — cited — wave-2
    quint64  _r10 = 0;
    quint8   typeB11 = 0;                // +0x11 ctor 字面 0(00a10941;"syntax" 装载同值,0033:6537)
    quint8   _r12[6] = {};               // +0x12..+0x17 对齐残隙
    quint64  _r18 = 0;                   // +0x18/+0x20/+0x28 param_1[3..5]=0
    quint64  _r20 = 0;
    quint64  _r28 = 0;
    QVector<quint64> kwVec30;            // +0x30..+0x40 语料三指针向量(param_1[6..8])QVector
                                         //   等价承载(SelStoreX.extras 同款先例);ctor 尾
                                         //   FUN_009e1af0 入一个 0;FUN_00a10472 门读 size>0xf
                                         //   (关键词装载面,生产者 FUN_009de20a — cited)
    void    *obj48 = nullptr;            // +0x48 operator_new(0x18){0,0,0}(00a10983)壳体 —
                                         //   cited — wave-2(词法引擎句柄族 FUN_00a12ab6/
                                         //   FUN_0098fdbc ctor/dtor;kwCacheFill 记录
                                         //   探测经此句柄 — 恒 nullptr 壳期同相)
    quint64  _r50 = 0;                   // +0x50 param_1[10]=0(ctor 字面;tl"+0x50 域名 map"
                                         //   与字面冲突,以语料为准 — 批 85 勘误流程)
    QVector<quint32> list58;             // +0x58 Uint32Bimap(props 打包值→id;0099c750 插值面)
    QVector<quint32> list60;             // +0x60 Uint32Bimap(值表 id↔值;keyProps 读面)
    qint32   seed68 = 0;                 // +0x68 seed 条目 idx<<2(ctor 尾 metacall 链)
    quint32  _r6c = 0;                   // +0x6c 0x70 分配尾

    // ===== kwMatchCache 装载侧(FUN_0099d27e 600B @0032.c:33028,批 101 真身化)=====
    // ⚠ 33204 调用点键序勘定(production 重读):FUN_0099d27e(D, lex, mode,
    //   lineNo) 形参 Ghidra 签名 (param_3=u32 mode,param_4=u32 lineNo),33051
    //   CONCAT44(param_3,param_4) = key 低 32=mode/高 32=lineNo;本填充方按此
    //   键序承载。语料:memo = *(D+0x38)(M+0x38 QHashData 手工布局;>1 项时
    //   FUN_0099c3a4 rehash 面 — 我方 QHash 容器坍缩免手工 rehash,EXT-BOUNDARY
    //   规则 4:读写面等价,布局怪癖登记);FUN_009a3916(127B)查找(命中即返
    //   33133 节点值;miss → 33060 FUN_00a12ab6 句柄 ctor + 逐记录 FUN_00a11f02
    //   探测循环 33064..33074 — 记录源 *(lex+0x18..0x20) 列表,词法引擎面
    //   cited — wave-2;33108..33131 QHashData::allocateNode/rehash/取模链 ≈
    //   QHash insert;33134 FUN_0098fdbc 句柄 dtor)。
    // 返回 = 记录表指针(空表也非空指针 — d4de 命中腿 for 循环零迭代同相;
    //   d4de 消费 = 33228 puVar16[0]/[1] begin/end 对 + 逐记录 u16 字段面 —
    //   指针稳定性:QHash 重插可能重哈希失效 — 语料 QHashData 节点稳定同域,
    //   我方 QStringList 深拷贝值,单扫描窗口内安全 — 怪癖登记)。
    QStringList *kwCacheFill(QHash<quint64, QStringList> &memo, void *lex,
                             quint32 mode, quint32 lineNo)
    {
        const quint64 key = (quint64(lineNo) << 32) | mode;      // 33051 CONCAT44(param_3,param_4)
        auto it = memo.constFind(key);                           // 33056..33066 FUN_009a3916 查找腿
        if (it != memo.constEnd())
            return const_cast<QStringList *>(&it.value());       // 33133..33135 命中 → 节点+0x18 直返
        QStringList recs;                                        // 33077..33082 miss:新记录表
        if (lex) {
            for (int i = 0; ; ++i) {                             // 33064..33074 逐记录探测循环
                // FUN_00a11f02(句柄,lineNo,tag&0x1ff) — cited — wave-2
                //   (词法引擎面未解;壳期记录源空表 → 循环零迭代同相)
                break;                                           // cited:探测体恒 false → 零记录
            }
        }
        memo.insert(key, recs);                                  // 33108..33131 节点插入(QHashData 链 ≈ insert)
        return &memo.find(key).value();                          // 33133..33135 新节点值
    }

    // FUN_00a1092a(403B)ctor 转写(0033.c:43953;字段字面见上):
    void ctor00a1092a()
    {
        vtbl = nullptr;                  // cited
        typeB11 = 0;                     // 00a10941
        _r18 = _r20 = _r28 = 0;          // param_1[3..5]=0
        kwVec30.clear();                 // param_1[6..8]=0(QVector 零承载)
        obj48 = nullptr;                 // operator_new(0x18){0,0,0} — cited(壳期)
        _r50 = 0;                        // param_1[10]=0
        list58.clear(); list60.clear();  // 0x20 holder×2(00a109b0/00a109f8)→ QVector 承载
        // seed 链(00a10a42..00a10a58):metacall(list58,0) → v=v&0xffc7ffff|0x80000
        //   → metacall 回读 idx → +0x68 = idx<<2;list60 只 metacall 不回读
        //   (00a10a5e — 未 seed,语料字面怪癖原样)
        const quint32 i0 = bimapPut(list58, 0);
        seed68 = qint32(bimapPut(list58, (i0 & 0xffc7ffffu) | 0x80000u)) << 2;
        bimapPut(list60, 0);
        kwVec30.append(0);               // 00a10a68..86:尾判满 → FUN_009e1af0 入 local_30[0]=0
    }
    // FUN_00a10472(16B)关键词计数门:(+0x38−+0x30)>>3 > 0xf
    bool kwLoaded() const { return kwVec30.size() > 0xf; }
    // FUN_00a10482(55B)插值腿:mode==0 → *(+0x68) seed;否则 metacall(list58,
    //   CONCAT12(8,mode&0x1f) 命令字,00a10490)→ idx<<2。0x800 = metacall 命令位
    //   (体未读,不承载);miss 即插(bimapPut 与 0099c750 同 op — 怪癖登记)。
    quint32 interpValue(quint32 mode)
    {
        if (mode == 0) return quint32(seed68);
        return bimapPut(list58, mode & 0x1f) << 2;
    }
};

// —— 行面真身(FUN_009f887e/009f88a4/009f88c8,0033.c:26475/26505/26535;slot10 =
//    *(session+0xa0) 0x48 doc-scan obj — 批④挂账):门 = *(s10+0x10) inner;
//    inner+0x00 = lineFace;lineFace+0x08 = ValueTable*(bd 笔记 §2 结构定案;
//    下游 thunk 00a04ad4/00a04ae0/00a04b04 = 0033.c:35109-35156,各 12B)。
//    slot10 承载定性(批 90 接线勘定,全链语料读):s10 = FUN_009f98a2(103B,
//    0033.c:27347)0x48 obj — +0x00 = inner 0x20{+0x00=s10 回指,+0x08=lineFace20
//    (FUN_009fa968 334B 0033.c:28108 建:Uint8RunStyles holder 0x20,piecetable
//    0x60+GB 0x30;= publishOutline 面 FUN_009f839c/958a 读 *(inner+0x10) 槽,
//    新建为 0),+0x10=0,+0x18=0x80 flag};+0x08 = session(E);
//    +0x10 = 门 door = FUN_009f98a2 param_3 = *(session+0x98) 0x80 lexer face
//    (FUN_00a0a1da 687B,0033.c:38753);door+0x00 = face10 0x10{+0x00=door 回指,
//    +0x08 = ValueTable(FUN_009cc264 K4 ≠0 腿 00a0a370 / FUN_009cc1bc K1 ==0 腿
//    00a0a474;K1=FUN_009cc1bc 55B,0032.c:66953 — kind=1 plain u16)}
//    = 行面 bank —— 与 markers A+0x18 同一 ValueTable 实现(批 89 复用定案)。
//    ⚠ slot10 ≠ ScannerX:ScannerX = buffer+0x108(D+0x18 ≡ A+0x08 同指针双槽,
//    E4' 定性);slot10 = doc-scan 伴随对象,两轨独立勿并。
//    写入点:唯一 = editor_initDoc param_1[2]=param_3(0032.c:36931);驱动 =
//    FUN_0092f0f6 0030.c:29770 editor_initDoc(new 0x70, session, *(session+0xa0));
//    s10 建/拆 = 0030.c:29676-29686(operator_new(0x48)+FUN_009f98a2(session,
//    *(session+0x98));旧体 FUN_009f82a2 63B 0033.c:25969 + delete 0x48 0030.c:29790)
//    + 0030.c:29572-29578 FUN_0092ef06 拆链。ctor/工场均 cited → 我方壳 nullptr,
//    接线经 MarkersStore::setSlot10 + EditorContext::docScan48 注入(0x7543 驱动批)。
//    可达前提 = FUN_009de20a 关键词装载(cited)+ slot10 接线,两批齐落前恒不可达(同相)。
// 6 路取值自由面(真体在 struct MarkersStore 后——成员体名字查找只看类定义前的声明):
inline quint64 lineValueWord10(const ValueTable *b, int idx);
// FUN_0092801a — cited — wave-2(E 面行表惰性重建/长度种子,体未读;EditorEngine.cpp:2859
//   注 =*(doc+0xf8)+0x28 长度面)。88c8 空面腿字面调用(壳期恒不可达)。
inline qint64 lineFaceRebuild10(void *) { return 0; }
// 行面 ValueTable 直针:lineFace = *inner;bank = *(lineFace+0x08)(thunk 族字面 *(*(inner)+8))
inline ValueTable *lineBank10(void *inner)
{
    void *lineFace = *reinterpret_cast<void **>(inner);
    return *reinterpret_cast<ValueTable **>(reinterpret_cast<char *>(lineFace) + 8);
}
// FUN_009f887e(17B):门空 → 0(语料字面,无 s10 空判);门内 → 00a04ad4 →
//   FUN_009cd3da(bank, idx)= 行 run 值(≡ 行起 offset;runs=行界,bd 笔记 §2 值语义)
inline qint64 lineStartOf10(void *s10, qint64 idx)
{
    if (!s10) return 0;                                  // 壳期守卫(d4de 调用点自持 scanFace 门;测试/接线批直呼防崩)
    void *inner = *reinterpret_cast<void **>(reinterpret_cast<char *>(s10) + 0x10);
    if (!inner) return 0;
    return qint64(lineValueWord10(lineBank10(inner), int(idx)));
}
// FUN_009f88a4(17B):门内 → 00a04ae0 → FUN_009cc396 = delegate vt+0x28(pos→run/line idx)
inline qint64 lineIdxOf10(void *s10, qint64 pos)
{
    if (!s10) return 0;                                  // 壳期守卫(同 887e)
    void *inner = *reinterpret_cast<void **>(reinterpret_cast<char *>(s10) + 0x10);
    if (!inner) return 0;
    return vcallSlotArg(lineBank10(inner)->delegate, 0x28, pos);
}
// FUN_009f88c8(26B):门内 → 00a04b04 → delegate vt+0x40 = 行止;
//   空面腿:FUN_0092801a(*(s10+0x08))(E)行表惰性重建,rax 透传为返回值(语料字面)
inline qint64 lineEndOf10(void *s10, qint64 idx)
{
    if (!s10) return 0;                                  // 壳期守卫(同 887e)
    void *inner = *reinterpret_cast<void **>(reinterpret_cast<char *>(s10) + 0x10);
    if (!inner)
        return lineFaceRebuild10(*reinterpret_cast<void **>(reinterpret_cast<char *>(s10) + 8));
    return vcallSlotArg(lineBank10(inner)->delegate, 0x40, idx);
}
// builder attr setter 对(0035.c:12/25;同构 19B,仅偏移差):b = builder 裸指针
// (D+0x40,通用 matcher 上下文,≥7 实例共用 facade;我方无 BuilderX struct →
// 按语料原样裸偏移直写,不触 ValueTable 0x40 布局)。+0x60/+0x61 attr 字节
// (初值 0x0101,00a833e8 reset 实证);+0x58 u64 缓存(-1=无效,双 setter + reset 三源定案)。
// FUN_00a83494(19B):*(char*)(b+0x60) != v 才写 + 缓存失效
inline void builderSetAttr4(void *b, quint8 v)
{
    char &a = *reinterpret_cast<char *>(reinterpret_cast<char *>(b) + 0x60);
    if (a != char(v)) {
        a = char(v);
        *reinterpret_cast<quint64 *>(reinterpret_cast<char *>(b) + 0x58) = ~quint64(0);
    }
}
// FUN_00a83480(19B):同构,偏移 +0x61
inline void builderSetAttr5(void *b, quint8 v)
{
    char &a = *reinterpret_cast<char *>(reinterpret_cast<char *>(b) + 0x61);
    if (a != char(v)) {
        a = char(v);
        *reinterpret_cast<quint64 *>(reinterpret_cast<char *>(b) + 0x58) = ~quint64(0);
    }
}
// builder 面(00a836f8/00a83e0a)— cited — wave-2;subPos/subEnd 真身见下
inline bool   builderMatchRun(void *, qint64)               { return false; }   // 00a836f8
inline qint64 builderScan(void *, void *, qint64, qint64)   { return -1; }      // 00a83e0a

// —— builderSubPos/SubEnd 双态读真身(00a839cc 75B/00a83bd0 76B 同构,0035.c:518/620)——
// b = builder 裸指针(D+0x40;BuilderX 未建模 → 裸偏移直写,同 builderSetAttr4/5 先例)。
// 双态(状态由 builderRegexRun(00a83c7a,批 101)regex 执行机置位 — 状态 1 腿
// c7a 委托接线前不可达,字面转写同相):
//   1 = 匹配完成:i < *(int*)(b+0xa8)(捕获数)→ v = 捕获数组(*(resB0+0x18))[2i]
//       (resB0 = *(b+0xb0) 结果表;偶槽=起/奇槽=止);v==-1 → -1;否则 + *(long*)(b+0x98)
//       (region 基)。⚠ 语料状态 1 腿无负 i 守卫(quirk 原样;腿不可达期无风险)。
//   2 = 流式:f = *(b+0x18) 简表 {+4 int count;+8 起表 arr;+0x10 止表 arr},
//       负/越界 i → -1(FUN_00a839ae/00a83bb2 字面)。
//   其余状态 → -1。
// FUN_00a839ae(29B,0035.c:506)+0x18 简表起读
inline qint64 builderSubPos18(void *f, int i)
{
    if (i < 0 || i >= *reinterpret_cast<int *>(reinterpret_cast<char *>(f) + 4))
        return -1;
    return *reinterpret_cast<qint64 *>(
        reinterpret_cast<char *>(*reinterpret_cast<void **>(reinterpret_cast<char *>(f) + 8))
        + static_cast<long>(i) * 8);
}
// FUN_00a83bb2(29B,0035.c:608)+0x18 简表止读(读 +0x10 数组)
inline qint64 builderSubEnd18(void *f, int i)
{
    if (i < 0 || i >= *reinterpret_cast<int *>(reinterpret_cast<char *>(f) + 4))
        return -1;
    return *reinterpret_cast<qint64 *>(
        reinterpret_cast<char *>(*reinterpret_cast<void **>(reinterpret_cast<char *>(f) + 0x10))
        + static_cast<long>(i) * 8);
}
// FUN_00a839cc(75B,0035.c:518)— builderSubPos(捕获 i 起)
inline qint64 builderSubPos(void *b, quint32 idx)
{
    char *p = reinterpret_cast<char *>(b);
    const int i = int(idx);                                  // 语料形参 int(0035.c:520)
    if (*reinterpret_cast<int *>(p + 0xb8) == 1) {                       // 523 状态 1
        if (i < *reinterpret_cast<int *>(p + 0xa8)) {                    // 525 i < 捕获数
            const long v = *reinterpret_cast<long *>(                    // 527 偶槽 = 起
                *reinterpret_cast<long *>(*reinterpret_cast<long *>(p + 0xb0) + 0x18)
                + static_cast<long>(i * 2) * 8);
            if (v == -1) return -1;                                      // 529
            return v + *reinterpret_cast<long *>(p + 0x98);              // 531 + region 基
        }
    } else if (*reinterpret_cast<int *>(p + 0xb8) == 2) {                // 534 状态 2:流式
        return builderSubPos18(*reinterpret_cast<void **>(p + 0x18), i); // → FUN_00a839ae
    }
    return -1;                                                           // 539
}
// FUN_00a83bd0(76B,0035.c:620)— builderSubEnd(捕获 i 止):与 39cc 同构,三处差
// (奇槽 +8 / 止表 +0x10 / 辅助 00a83bb2)
inline qint64 builderSubEnd(void *b, quint32 idx)
{
    char *p = reinterpret_cast<char *>(b);
    const int i = int(idx);                                  // 语料形参 int(0035.c:622)
    if (*reinterpret_cast<int *>(p + 0xb8) == 1) {                       // 625 状态 1
        if (i < *reinterpret_cast<int *>(p + 0xa8)) {                    // 627
            const long v = *reinterpret_cast<long *>(                    // 629 奇槽 = 止
                *reinterpret_cast<long *>(*reinterpret_cast<long *>(p + 0xb0) + 0x18)
                + 8 + static_cast<long>(i * 2) * 8);
            if (v == -1) return -1;                                      // 631
            return v + *reinterpret_cast<long *>(p + 0x98);              // 633 + region 基
        }
    } else if (*reinterpret_cast<int *>(p + 0xb8) == 2) {                // 636 状态 2:流式
        return builderSubEnd18(*reinterpret_cast<void **>(p + 0x18), i); // → FUN_00a83bb2
    }
    return -1;                                                           // 641
}
inline qint64 builderAnchor(void *, qint64)                 { return 0; }       // builder vt+0x00 双参尾调(0099d6ac)— cited
// 0xc00 腿 lexer 引擎逐行探测(FUN_00a11f02;句柄 FUN_00a12ab6/FUN_0098fdbc ctor/dtor
// 亦 cited,我方无句柄承载)— cited — wave-2
inline bool kwProbeLine(void *, quint32, quint16, quint64)  { return false; }

// ============ builder C 级 regex 执行机(批 101;FUN_00a83c7a 400B @0035.c:679)============
// 定性(铁律 6 前置核对,三源互证):
//   ① c7a 尾调 FUN_00ad74a0(431B,0035.c:50226)— 语料名化显示 Onigmo 修改层:
//      内部 FUN_00aa39f0(78B)= 栈上 0x8000 匹配上下文 + 函数指针直调;上游
//      FUN_00ad7360(304B)/FUN_00ad2ae0(17929B)= Onigmo 惰性编译栈(与
//      src/Onigmo/regexec.c match_at 族同构,REG_ 错误码 0xffffffcd/d3/d0 同域)。
//   ② 同族 0033.c:37370/37412/38340(FUN_00a9c780 22391B 编译栈)= Onigmo-改
//      全套编译器(xpressive 字符串仅 0021/0025/0026/0032/0033 段出现,37 段
//      零命中 → c7a 底座非 xpressive)。
//   ③ onig_vm_exec(871B)/onig_emitImm/onig_compileOp 直接名化(0035.c:14247/
//      28224/37809)+ src/Onigmo 第一方组件在册(EXT-BOUNDARY 2026-10-29 条目)
//      → EXT-BOUNDARY 定案:**Onigmo-改 委托边界**,WindTerm 侧只保留调用面。
//   注:regex_nfa_compile(00b3cc80 20839B)族与 onig_ 符号并存 — 二级引擎
//      (QHashData/pcre2_configGet 面 0034.c 混在),不在本批定性范围;c7a
//      只触 ①②③ 链路。
// 语料体(0035.c:681-746,参数 param_1=builder b;param_2=regex 条目 {regex*};
// param_3=anchor;param_4=region 起;param_5=region 止):
//   681 pbVar2 = *param_2(regex 对象)→ 空 → 686/694 b+0xb8=0 返 -1(未装载)
//   690 门:*(reg+0x18)(编译体)!=0 且 (anchor==regionStart 或 *reg&8==0)
//   694..704 region 基入界:lVar5 = *(b+0x98);anchor 越界 [0x98,0xa0+0x98)
//     → 回调 *(b+0x80)(vt 函数指针,见下)重置再读;
//     *reg&4 → anchor-1<0 归 0(字面前跳)
//   705..709 长度门:*(u32)(reg+4) <= anchor-regionBase 且
//     *(u32)(reg+8)+delta <= *(b+0xa0)(region 长)—— 否则落 729 流式腿
//   710..712 止界钳制:param_5-regionBase 超长 → 截到 region 长
//   713..716 **FUN_00ad74a0**(regex 体,线程上下文,钳长,flags=*(b+0xac),
//     捕获表 *(resB0+8)/0x10)— Onigmo 委托执行 — 唯一外部调用
//   717 捕获数 *(int*)(b+0xa8) = 返回;==-1 → 未中(686 同相);>0 →
//   721..724 b+0xb8=1(完成态)+ 返 FUN_00a83c3c(b,0)(62B 已真身:捕获 0
//     起-止 = 匹配长度,MarkersStore 无此壳 — 补 builderMatchLen 下)
//   729..731 流式腿:FUN_00a835e4(b+0x80)(24B 已真身同构:清缓存)+ b+0xb8=2
//   733..738 FUN_00b421c0(regex 条目+0x10,flags…) 流式执行 — 同 Onigmo 底座
//     (32546 220B:FUN_00b41ee0 捕获数组扩容 244B/regex_nfa_compile 编译 —
//     二级引擎面,同批定性注记,不触)
// 我方落法(EXT-BOUNDARY 规则 2/3):调用面结构逐行转写;Onigmo 底座以
//   src/Onigmo 真库委托(OnigRegex 前置声明;壳期 regex 未装载恒走 -1 腿,
//   与语料 681 空门同相 — builder 壳 nullptr,regionScan 命中腿不可达)。
// regex 条目 = *param_2 指向的 {OnigRegex body@+0x18, u32 minLen@+4,
//   u32 maxLen@+8, u32 flags@+0} 最小面(语料字面;全布局 cited — wave-2)。
struct RegexEntryX {
    void   *vtbl;                        // +0x00 cited(条件门 *reg&4/&8 flags 位读)
    quint32 flags;                       // +0x04 语料 *pbVar2 位测(4=anchor 前跳/8=非锚)
    quint32 minLen;                      // +0x08 语料 *(u32*)(reg+4)
    quint32 maxLen;                      // +0x0c 语料 *(u32*)(reg+8)
    quint8  _r10[0x08];                  // +0x10..0x17 未触(cited)
    void   *compiled;                    // +0x18 OnigRegex 编译体(FUN_00ad74a0 参 1)— 委托
};
// FUN_00a83c3c(62B,0035.c:657)状态读匹配长(0 号捕获止-起;= c7a 723 返回面);
//   状态 2 腿 → FUN_00a83c1c(32B,0035.c:644:简表 {+4 count;+8 起表;+0x10 止表}
//   止-起;越界/负 → 0 — 00a83c1c 语料字面无 -1 守卫,return 0 原样)
inline qint64 builderMatchLenState2(void *f, int idx)    // FUN_00a83c1c
{
    char *q = reinterpret_cast<char *>(f);
    if (idx >= 0 && idx < *reinterpret_cast<int *>(q + 4))       // 648
        return *reinterpret_cast<qint64 *>(*reinterpret_cast<qint64 *>(q + 0x10)
                   + static_cast<long>(idx) * 8)                 // 650 止表
             - *reinterpret_cast<qint64 *>(*reinterpret_cast<qint64 *>(q + 8)
                   + static_cast<long>(idx) * 8);                // 650 起表
    return 0;                                                    // 653 语料字面
}
inline qint64 builderMatchLen(void *b, int idx)
{
    char *p = reinterpret_cast<char *>(b);
    if (*reinterpret_cast<int *>(p + 0xb8) == 1) {                       // 661
        if (idx < *reinterpret_cast<int *>(p + 0xa8)) {                  // 662
            const long *t = *reinterpret_cast<long *const *>(
                *reinterpret_cast<long *const *>(p + 0xb0) + 0x18);      // 663 捕获表
            return t[idx * 2 + 1] - t[idx * 2];                          // 665 止-起
        }
    } else if (*reinterpret_cast<int *>(p + 0xb8) == 2) {                // 667 状态 2
        return builderMatchLenState2(*reinterpret_cast<void **>(p + 0x18), idx);  // 668
    }
    return 0;                                                            // 671
}
// FUN_00a83c7a(400B)调用面真身 — Onigmo 委托(执行腿 cited 壳期恒 -1 同相):
//   b = builder 裸指针(D+0x40,同 builderSubPos 先例);re = regex 条目;
//   anchor/regionStart/regionEnd 三参直通。
inline qint64 builderRegexRun(void *b, void *reEntry, qint64 anchor,
                              qint64 regionStart, qint64 regionEnd)
{
    if (!b || !reEntry) return -1;                       // 681..686(壳期 builder 空)
    char *p = reinterpret_cast<char *>(b);
    RegexEntryX *re = static_cast<RegexEntryX *>(reEntry);
    if (re->compiled == nullptr)                         // 688 *(reg+0x18)!=0 门
        return -1;                                       // 686/694:未装载同相
    if (!(anchor == regionStart || (re->flags & 8) == 0))// 690 anchor==p4 || !(*reg&8)
        return -1;                                       //   → 落 729 流式腿(壳期同相 -1;
                                                         //   流式腿 FUN_00b421c0 cited)
    // 694..704 region 基重置回调 *(b+0x80) — cited(wt 槽面,未读;壳期不可达)
    const qint64 base = *reinterpret_cast<qint64 *>(p + 0x98);   // 694
    const qint64 delta = anchor - base;                          // 705
    if (quint64(re->minLen) > quint64(delta) ||                  // 706..708 长度门
        quint64(re->maxLen) + quint64(delta) > quint64(*reinterpret_cast<qint64 *>(p + 0xa0)))
        return -1;                                       // → 729 流式腿(同相)
    qint64 limit = regionEnd - base;                     // 710
    if (limit > *reinterpret_cast<qint64 *>(p + 0xa0))   // 711 钳制
        limit = *reinterpret_cast<qint64 *>(p + 0xa0);
    // 713 FUN_00ad74a0(Onigmo 执行)— 委托:src/Onigmo onig_search 族。
    //   cited — wave-2(签名含 flags=*(b+0xac)/捕获表 *(resB0+8)/0x10;委托
    //   接线须 RegexEntryX 全布局 + onig 上下文,接线批落)。壳期占位 n=0:
    //   零捕获 → 729 流式腿(cited)→ 恒 -1,与 681 builder 空门同相。
    const int n = 0;                                     // 委托占位:壳期恒 0 捕获
    (void)limit;
    *reinterpret_cast<int *>(p + 0xa8) = n;              // 717 捕获数回写
    if (n == -1) return -1;                              // 718
    if (n > 0) {                                         // 720
        *reinterpret_cast<int *>(p + 0xb8) = 1;          // 722 状态 1 置位
        return builderMatchLen(b, 0);                    // 723..724 FUN_00a83c3c(b,0)
    }
    // 729..738 流式腿:FUN_00a835e4(b+0x80) 清缓存(24B 同构内联)+ 状态 2 +
    //   FUN_00b421c0 流式执行(220B,二级引擎)— cited — wave-2(状态 2 读侧
    //   39cc/83c3c 已真身,执行侧须 NFA 引擎定性 — 单列批)
    return -1;
}

// FUN_0099d072 关键词腿(387B @0032.c:32946,批 88 挂账返回门;批 101 落地)
// 语料体(32948..32985;param_1 = D):lVar5 = FUN_00930d1c(*(D+0x08),0)(lexer
//   词法面;我方 bufferLexer 平铺 — 由 EditorContext 调用方传 lex);空 → 返 1
//   (32951 空 guard 直通 — 注意:语料 lexer 空 = 装载成功同相,region 循环照进);
//   32952 editor_line_at(*(D+0x08),0)(行 0 face — cited 面);
//   32953 uVar2 = FUN_00a0e23c(lVar5)(188B 全读:= lVar5+0x58 holder 自旋锁内
//     *(+0x58+8) u32 = 词表行数上界);
//   32954 uVar3 = FUN_00a12b8a(*(D+0x18))(195B 全读:= tlist+0x10 自旋锁内
//     FUN_00a120b4(*(tlist+8)) 计数);
//   32955 门 uVar3 < uVar2;循环体 32957..32983:
//     32959 (uVar3%100==0) 且 FUN_0099cfb6(D)(停机)→ 返 0;
//     32961..32965 local_3c[0] = uVar3*8;*(byte*)(lVar6+0xa8)&2 → FUN_00a0e4bc;
//     32966 uVar4 = FUN_00929a3a(*(D+0x08),lVar8)(87B 行→索引);
//     32967 uVar7 = FUN_00930f9e(*(D+0x08),uVar4)(26B 行 face→lexer);
//     32969/32972 local_3c[0] = (v&~2)|2 / (v&~2)|4 → FUN_00a1017a(*(D+0x18),
//       uVar4,uVar7,lVar5,mode)(9B → FUN_00a1295c 转发 — 两模式装载);
//     32974 ++uVar3 循环。
//   尾 32985 返 1(全装载)。
// 我方落法:门/循环骨架逐行;词表计数两锁面 cited(壳期 lex=null → 语料
//   32951 空门同相返 1);FUN_00a1017a 装载转发 cited(体 9B 转发已读,但
//   FUN_00a1295c 目标体未读 — 两模式装载机制单列批);行面 editor_line_at
//   cited 面(同 887e 族先例);FUN_00929a3a 87B 半读(行→索引映射体未读 —
//   字面计数承载)。stopPending = &D.stopFlag(32959 停机门参数化注入,
//   自由函数不触 this — MarkersStore::keywordsLoadGate 包装)。
inline bool keywordsLoad(bool *stopPending, void *lex)
{
    if (!lex) return true;                       // 32951 lVar5==0 → 落 32985 返 1
    // 32953 词表行数(FUN_00a0e23c 锁面)— cited — wave-2(壳期不可达:
    //   词表由 FUN_009de20a yaml 装载 cited,未接线恒空 → 计数 0)
    const quint32 tableRows = 0;                 // 32953 占位(锁内 u32 读,cited)
    // 32954 已装载计数(FUN_00a12b8a 锁面)— cited — wave-2(tlist+0x10 面)
    quint32 loaded = 0;                          // 32954 占位(同上)
    for (quint32 i = loaded; i < tableRows; ++i) {   // 32955..32983 循环骨架
        if (i % 100 == 0 && stopPending && *stopPending)   // 32959 FUN_0099cfb6 → 返 0
            return false;
        // 32961..32972 逐行两模式装载(FUN_00a0e4bc/FUN_00929a3a/FUN_00930f9e/
        //   FUN_00a1017a ×2)— cited — wave-2(行面 + 装载转发,机制未解不承载;
        //   壳期 tableRows=0 循环体不可达,与语料同相)
    }
    return true;                                 // 32985
}
// — keywordsLoad 为自由函数(成员声明区前;stopFlag 经 stopPending 注入,
//   包装 = MarkersStore::keywordsLoadGate,见 struct 内)—
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
struct MarkersStore {                    // M ≡ D = doc-state(0x70B 语料尾;mk3 全偏移核;
                                         //   批 101 kwcMemo 挂尾超载 — 见尾注)
    MarkersArray *arr;                   // +0x000 A(0x38;*A=D 回指)
    void         *doc;                   // +0x008 E(折叠 +0xe0 族 / 层级 +0xa0 / 行数 +0xf8)
    quint64      slot10;                 // +0x010 原始入参槽(initDoc param_3;0x48 doc-scan
                                         //   obj = FUN_009f98a2 产出 — 定性见上 §行面真身);
                                         //   0099c8d6 低 4B 用作 u32 滚动计数 — 同槽两用,
                                         //   语料字面怪癖
    ValueTable   *tlist;                 // +0x018 T(FUN_00a101a0)/ lexerSnap(initDoc
                                         //   FUN_00930f9e(E,0) 同槽;0099c75a 读侧为准)
    quint64      scanCursor;             // +0x020 扫描游标(initDoc param_1[4]=0)
    quint32      idAlloc;                // +0x028 id 分配器(markWrite 009a62c0 取用)
    quint8       stopFlag;               // +0x02c 停机标志(0099cfb6 置 1)
    quint8       _r2d[0x03];             // +0x02d..0x2f 对齐残隙(语料未触)
    void        *bucketTab;              // +0x030 桶表(initDoc param_1[6]=0)
    void        *memo;                   // +0x038 memo QHashData 手工布局语料槽(=shared_null;
                                         //   真承载迁 kwcMemo 挂尾 — 见 0x70 尾注;q3)
    void        *builder;                // +0x040 builder(initDoc param_1[8]=0)
    quint8       spin;                   // +0x048 读侧自旋字节(0069e8ac;解锁=写0)
    quint8       _r49[0x07];
    quint64      visibleSnap;            // +0x050 可见快照槽(0099d1f6 返回 &此;initDoc 不清零,q3)
    SpBase      *curSnap;                // +0x058 当前快照
    quint64      stagedSnap;             // +0x060 暂存快照(publishOutline 写 model 指针 — q4
                                         //   勘正:指针槽,位形等价)
    SpBase      *pendSnap;               // +0x068 待发布快照(0x70 止)
    // ⚠ 0x70 分配止:以下为我方超语料承载字段(偏移不进布局 — QHash 坍缩
    //   替代 D+0x38 memo 的 QHashData 手工布局;0x70 static_assert 锚定语料
    //   尾,字段挂结构尾不破坏偏移)。memo(void*)保留原槽 — 承载迁至
    //   kwcMemo(memo 恒 nullptr = 语料 shared_null 位形;读侧 tblRead 不经此)。
    QHash<quint64, QStringList> kwcMemo; // = D+0x38 memo 真承载(kwMatchCache 批 101;
                                         //   key=CONCAT44(mode,lineNo) 33051;值=记录表)

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

    // ============ slot10(D+0x10)接线对(批 90 接线批)============
    // 写侧:editor_initDoc param_1[2]=param_3(0032.c:36931)= markersCtxInit
    //   markersCtxInit 已转写同槽(reinterpret_cast 按位存,D+0x10 现字段);
    //   驱动 = FUN_0092f0f6(0030.c:29770)editor_initDoc(new 0x70, session,
    //   *(session+0xa0))。setter 供 0x7543 驱动批注入 doc-scan obj(FUN_009f98a2
    //   产出 — cited);getter 供 regionScan 行面门(/现有 reinterpret_cast 读位)。
    //   壳期 slot10==0 → 行面 ×3 零守卫(regionScan 内 !scanFace 门同相)。
    void setSlot10(void *docScanObj)
    {
        slot10 = reinterpret_cast<quint64>(docScanObj);   // param_1[2] 009a2e93 形(同 markersCtxInit)
    }
    void *slot10Obj() const { return reinterpret_cast<void *>(slot10); }   // d4de 0099d4de 读 *(param_1+0x10) 形
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
        return runValueWordAt(arr->bank, idx);           // 同面换元素(批 82:runvector 复用)
    }
    // 六路取值参数化版(批 82:0x7576 runvector 元素 = ValueTable 复用)
    static quint64 runValueWordAt(const ValueTable *b, int idx)
    {
        if (!b)                                          // runvector 壳期守卫
            return 0;
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
        if (e->sel == '\0') {
            // RS 未建(壳期 styles==nullptr)→ 0;rsOf 解引 +0x10 须非空
            // (批 76 markerstest 上报守卫)
            if (!e->u64Obj || !e->u64Obj->styles)
                return 0;
            return rsValue64(rsOf(e->u64Obj->styles), pos);      // Uint64RunStyles_valueAt
        }
        if (!e->u32Obj || !e->u32Obj->styles)
            return 0;
        const quint32 v = rsValue32(rsOf(e->u32Obj->styles), pos);
        // QUIRKS 26 定案(批 85 三源复核):cur 读源 = tlist(D+0x18;
        //   39463 *param_1=A→D 回指;bank 0x40 无 +0x60 槽不可能作 arg)
        const quint32 props = tlist
            ? keyPropsOf(tlist, v & 0x1fff) : 0;                 // FUN_00a10384
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
    // FUN_0099d072 返回门包装(批 88 挂账收口;批 101):kw 装载腿自由函数
    //   keywordsLoad(stopPending=&stopFlag, lex) — 009a2cbf 门内首调(32948 形:
    //   lVar5 = FUN_00930d1c(*(D+0x08),0) = EditorContext::bufferLexer)。
    //   返 false → 驱动跳 region 循环直落发布腿(009a2cac 前置门语料字面);
    //   壳期 lex=null 恒 true(32951 空词表同相)。
    bool keywordsLoadGate(void *lex)
    {
        bool pending = stopped() || stopFlag != 0;               // 32959 FUN_0099cfb6(D) 门参
        return keywordsLoad(&pending, lex);                      // 009a2c uVar3 = FUN_0099d072(D)
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
        D->tlist = nullptr;                                      // param_1[3] +0x18 = FUN_00930f9e(E,0)
                                                                 //   — 工厂已真身化(EditorContext::
                                                                 //   lexerSnap,①);接线待 buffer 面
                                                                 //   驱动批 — 参数位仍 nullptr(读侧 T 同槽)
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

    // ============ FUN_0099d4de(1407B @0032.c:33144)regionScan — region 扫描游走器 ============
    // 驱动 = FUN_009a2b90(mode-4 Outlining DocumentTask,0032.c:36875)循环调
    //   (D, lexerMode, from, to);返回值 = local_69(语料全路径 '\0')。
    // lex 形参:语料 FUN_0099c874(D)=FUN_00930f9e(*(D+0x08))=lexerSnap(D->doc);
    //   E 面平铺后由 EditorContext::regionScan 供 bufferLexer。
    quint8 regionScan(quint32 lexerMode, qint64 from, qint64 to, void *lex)
    {
        if (!arr || !arr->bank) return 0;        // 壳期守卫(语料均在 initDoc 后)
        ScannerX *sx = static_cast<ScannerX *>(lex);
        quint32 base = 0;
        if (sx) base = sx->interpValue(lexerMode);           // FUN_00a10482 插值腿
        if (!sx || !sx->kwLoaded()) {                        // FUN_00a10472 门(>0xf)
            coreWriteRange(from, to - from, base, 1);        // 0099d50c 整段灌基值
            scanCursor = quint64(to);                        // *(D+0x20)
            return 0;
        }
        void *scanFace = reinterpret_cast<void *>(slot10);   // 0x48 doc-scan obj(FUN_009f98a2 产出 —
                                                             //   定性/写入点见 slot10 字段注;批④挂账)
        if (!scanFace) return 0;     // 壳期守卫:主循环须 FUN_009de20a 装载(cited)+slot10
                                     //   接线齐备 — 恒不可达(同相);cited 行面 stub 恒 0,
                                     //   无此门则 636 推行 while 死旋,故防崩门先于行面
        int i8 = int(runIndexOfLine(quint64(from)));         // FUN_0099c9c2
        const qint64 last = (to - 1 >= from) ? to - 1 : from;   // 0099d54e
        int i9 = int(runIndexOfLine(quint64(last)));
        if (i8 <= i9) {
            do {                                             // LAB_0099d5c0
                if (stopped()) return 0;                     // FUN_0099cfb6
                if (runValueAt(i8) == 0) {                   // FUN_0099c974:素 run 才扫
                    qint64 lo = qint64(vcallSlotArg(arr->bank->delegate, 0x38, i8));  // FUN_0099ca60
                    if (lo < from) lo = from;
                    qint64 hi = qint64(vcallSlotArg(arr->bank->delegate, 0x40, i8));  // FUN_0099ca6c
                    if (to < hi) hi = to;
                    int li = int(lineIdxOf10(scanFace, lo));         // FUN_009f88a4 — cited 面
                    qint64 le = lineEndOf10(scanFace, li);           // FUN_009f88c8 — cited 面
                    scanCursor = quint64(lo);                        // *(D+0x20)
                    qint64 cur = lo;                                 // lVar13(lVar23 636 处重置)
                    while (cur < hi) {                               // LAB_0099d636
                        if (stopped()) return 0;
                        if (cur - qint64(scanCursor) > 0xa000) {     // 40KB 分块冲刷
                            coreWriteRange(qint64(scanCursor), cur - qint64(scanCursor), base, 1);
                            scanCursor = quint64(cur);
                        }
                        while (le <= cur) { ++li; le = lineEndOf10(scanFace, li); }   // 推行
                        const quint32 ch = quint32(lineStartOf10(scanFace, li));      // FUN_009f887e — cited 面(33226 uVar11 u32)
                        // 33227 kwMatchCache 查询 → 装载侧真身(批 101 ScannerX::
                        //   kwCacheFill;memo = D+0x38 → 我方 kwcMemo QHash 承载):
                        QStringList *matches = sx->kwCacheFill(kwcMemo, lex, lexerMode, ch);
                        if (matches->isEmpty()) {                // 33229 puVar16==0(miss 腿同相:空表=零记录)
                            cur = le;                            // miss → 跳行尾(0099d628)
                            if (hi <= le) break;                 // → LAB_0099d6b3
                            continue;
                        }
                        // —— 命中处理腿(0099d6ab..0099da5d;壳期不可达:记录源空表
                        //    恒零记录)。记录 face 由消费点反推,字面照抄:+0x00 u16
                        //    tag;+0x01 attr byte;+0x10/+0x18 run 列表界(元素步长 3
                        //    long);+0x28 子表 ptr(元素 0x10,u32@+8)。kwcMemo 值 =
                        //    原始 u16* 记录指针数组的 QStringList 索引化占位(cited:
                        //    词法引擎面未落,记录构造恒空 — 壳期同相)。
                        void *builder = this->builder;               // D+0x40(initDoc 0;驱动链装载 — cited)
                        if (!builder) {                              // 壳期守卫(语料此处必非空)
                            cur = le;
                            if (hi <= le) break;
                            continue;
                        }
                        const qint64 anchor = builderAnchor(builder, cur);   // builder vt 双参尾调 — cited(33231 uVar6)
                        (void)anchor;                        // 记录构造 cited 恒空;anchor 消费腿随记录真身化恢复
                        qint64 next = cur + 1;                       // 未中默认腿(0099d6ab: +1)
                        // 记录遍历(33232..):kwcMemo 值 = QStringList 索引化承载;
                        //   原始记录 = u16* face(tag@+0x00/attr@+0x01/run 界
                        //   +0x10/+0x18 步长 3 long/子表 +0x28 元素 0x10 — 消费点
                        //   反推字面)。记录构造腿 cited(词法引擎面未落)→ 空表,
                        //   本循环恒零迭代 — 壳期同相;0xc00 搜尾(builderScan)/
                        //   灌值/子表重打包腿(33246..33400)随记录真身化批按
                        //   face 直读恢复(builderSubPos/End 真身已就位)。
                        for (int ridx = 0; ridx < matches->size(); ++ridx) {
                            const quint16 tag = quint16(matches->at(ridx).toUShort());  // u16 tag(占位承载;cited)
                            quint8 attr = 0;                      // +0x01 attr byte(cited 构造恒 0)
                            builderSetAttr4(builder, quint8((attr >> 4) & 1));   // 00a83494 真身
                            builderSetAttr5(builder, quint8((attr >> 5) & 1));   // 00a83480 真身
                            void *sub = nullptr;                  // +0x28 子表 ptr(cited 恒空)
                            *(bool *)(reinterpret_cast<char *>(builder) + 0x10) = (sub != nullptr);  // 33244 字面
                            (void)tag; (void)sub;                 // cited 面恒零记录;哑参消音保留语义锚
                        }
                        cur = next;                                  // 636:lVar23 = lVar13
                        continue;
                    }
                    // LAB_0099d6b3 尾冲刷
                    if (qint64(scanCursor) < hi) {
                        coreWriteRange(qint64(scanCursor), hi - qint64(scanCursor), base, 1);
                        scanCursor = quint64(hi);
                    }
                    i8 = int(runIndexOfLine(scanCursor));            // FUN_0099c9c2
                    i9 = int(runIndexOfLine(quint64(to)));
                    if (i8 < i9) continue;                           // goto LAB_0099d5c0
                }
                ++i8;                                                // 已着色 run / 区间尽 → 下一 run
            } while (i8 <= i9);
        }
        scanCursor = quint64(to);                                    // *(D+0x20) = to
        return 0;
    }

    // FUN_0092e44e(0x754d 体)已迁 EditorEngine case 0x754d —— 批 69
    // 勘正:stopCount/nodes 属 E 面,不在 D(本结构)
};

// ⚠ 批 101:kwcMemo(QHash)挂结构尾 → sizeof > 0x70。语料 D 分配 0x70(裸
//   内存零化);kwcMemo = D+0x38 memo 承载坍缩(EXT-BOUNDARY 规则 4 读侧面
//   等价),超尾承载不进语料偏移域 — static_assert 改语料尾锚(mk2 勘正链)。
//   0x70 内偏移(+0x00..+0x68)全部不变(QHash 成员挂尾)。
static_assert(offsetof(MarkersStore, pendSnap) + sizeof(void*) == 0x70,
              "D 语料尾 0x70 锚(+0x00..+0x68 偏移域;批 101 kwcMemo 挂尾承载)");

// lineValueWord10 定义(runValueWordAt 真身可见处;复用 markers 值表六路实现 —
// bd 笔记 §2:行面 bank 与 markers 值表同源,009cd3da 直接复用实证)
inline quint64 lineValueWord10(const ValueTable *b, int idx)
{
    return MarkersStore::runValueWordAt(b, idx);
}

} // namespace wt
