// ModTrack — M 修改行跟踪器(doc+0xf0;批 104 建模 + markerBand 00927a78 前置)
// 生命周期(语料锚):
//   构造 = editor_engineCtor FUN_00929bf8(1625B @0030.c:25864)00929fab..00929fe1:
//     operator_new(0x10) → FUN_0099b142(p,5)(初始旗标 5)→ E+0xf0(param_1[0x1e]);
//     旧体 = FUN_0099a362 + operator_delete(0x10)。
//   复位/重建腿 = FUN_0099b07a(191B @0032.c:31119;引擎侧 thunk_FUN_00927be6
//     0030.c:23639/23649 直调同体)。
// 布局(批 103 定案 + 本批复核):
//   M(0x10) = {+0x00 inner, +0x08 默认旗标字节(b142 param_2)};
//   inner(0x20) = {+0x00 回指 M, +0x08 累计行数(bbb0 头 *(inner+8)+=len),
//                  +0x10 RS8 游程面(null=flat 回退), +0x18 文档面};
//   面(0x20) = {+0x00 vt cited, +0x08 字节数组, +0x14 int 总行数,
//               +0x18 int 段界, +0x1c int 尾段偏移}(两段读语义 0099b36c)。
//   游程面 H(0x20,bbb0 迁移腿 puVar7 形)= {+0x00 vt cited(Uint8RunStyles 族;
//     身份槽 +0x28/+0x30/+0x38/+0x40 = vt5/6/7/8 — a47a/a4b2/a4ea/a448 检查),
//     +0x08 runs 面(委托形态直存 RS8 — MarkersStore §1 同怪癖), +0x10 D2 面。
//     语料 D2 = GB 0x30 壳{+0x18 subface}(bbb0 puVar9+puVar10);我方坍缩直存
//     subface(kwcMemo QHash 坍缩同款怪癖登记),GB 密排路随壳消失。
// 七函数(0032.c):0099a3c0(30434)/0099a448(30475)/0099a47a(30498)/
//   0099a4b2(30521)/0099a4ea(30544)/0099b36c(31287)/0099b4c8(31363)。
// cited — wave-2:zstd 压缩腿 FUN_00889cde(280B @0027.c:39620)、QReadWriteLock
//   锁腿、FUN_0088a016/gapbuf_shrink 容量两段机、bbb0 0xfffff 迁移腿与 run 模式
//   灌值腿(LAB_0099bf2b)——本批不建模(任务书批 104 裁定)。
//   写侧族(b152/b15e/flagmask_set_range/bbb0 增量)不在七函数 — 单列批。
#pragma once

#include <QtGlobal>
#include <QPair>
#include <string_view>
#include <vector>
#include <memory>
#include <stdexcept>
#include <stddef.h>
#include "../Scintilla/include/Platform.h"   // 含序同 MarkersStore.h(RunStyles 链)
#include "../Scintilla/src/SplitVector.h"
#include "../Scintilla/src/Partitioning.h"
#include "../Scintilla/src/RunStyles.h"

namespace wt {

struct ModTrackInner;
struct ModTrackFace;

// 行旗标文档面(0x20;0099bbb0 puVar5 形)
struct ModTrackFace {
    void    *vt = nullptr;               // +0x00 cited — wave-2(GB 面 vt;我方读路不经)
    quint8  *bytes = nullptr;            // +0x08 字节数组(bbb0 尾 gapbuf 直写面)
    quint32 _r10 = 0;                    // +0x10 语料分区缓存面 — cited(密排路不触)
    int      total = 0;                  // +0x14 总行数(bbb0 尾 *(f+0x14)+=len)
    int      segBound = 0;               // +0x18 段界(两段读第一段界)
    int      tailOff = 0;                // +0x1c 尾段偏移(第二段基 = idx+tailOff)
};

// 游程面 H = Uint8RunStyles(0x20;bbb0 迁移腿 puVar7 形)
struct ModTrackRunFace {
    void *vt = nullptr;                  // +0x00 cited — Uint8RunStyles_vtable(身份检查
                                         //   槽 vt5/6/7/8;我方直存直调不经 vt — 怪癖登记)
    Scintilla::RunStyles<int, char> *rs = nullptr;   // +0x08 runs 面(委托形态直存)
    ModTrackFace *runFlags = nullptr;    // +0x10 D2 subface(per-run 旗标;GB 0x30 壳坍缩)
    void *_r18 = nullptr;                // +0x18 分配尾(0x20)
};

// inner(0x20;bbb0 puVar4 形)
struct ModTrackInner {
    struct ModTrack  *back = nullptr;    // +0x00 回指 M(bbb0 *puVar4 = param_1)
    qint64           lineCount = 0;      // +0x08 累计行数(bbb0 头 *(inner+8)+=len)
    ModTrackRunFace *runs = nullptr;     // +0x10(a3c0 模态门:非零 = 游程)
    ModTrackFace    *flat = nullptr;     // +0x18 文档面(flat 模式)
};

// M(0x10;editor_engineCtor operator_new(0x10))
struct ModTrack {
    ModTrackInner *inner = nullptr;      // +0x00
    quint8         defaultFlag = 0;      // +0x08(b142 param_2;ctor 落 5 = bit0|bit2)
    quint8         _r9[7] = {};          // +0x09..0x0f 分配尾

    ModTrack() { modInit(5); }           // ctor 链 00929fab..00929fe1(头注)
    ~ModTrack() { modDtor(); }           // FUN_0099a362(94B @0032.c:30408;调用点 0030.c:29905)

    // FUN_0099b142(16B @0032.c:31163):*p=0;*(p+1)=flag;FUN_0099b07a()
    void modInit(quint8 flag)
    {
        inner = nullptr;
        defaultFlag = flag;                          // 31165 *(param_1+1) = param_2
        modRebuild();                                // 31166 FUN_0099b07a()
    }

    // FUN_0099b07a(191B @0032.c:31119):旧体拆除 + 新 inner/flat + bbb0(0,1,flag)
    void modRebuild()
    {
        modTeardownInner();                          // 31122..31133(与 a362 同构,语料各自内联)
        inner = new ModTrackInner;                   // 31134 operator_new(0x20)
        inner->back = this;                          // 31135 *puVar4 = param_1
        inner->flat = new ModTrackFace;              // 31139 puVar5 operator_new(0x20) 全零
        inner->runs = nullptr;                       // 31136..31138 puVar4[1..2] = 0
        modAppendRange(0, 1, defaultFlag);           // 31155 FUN_0099bbb0(inner,0,1,flag)
    }

    // FUN_0099bbb0(1296B @0032.c:31704)flat 追加腿 — ctor 可达路(新面 pos=0/len=1)。
    //   头部 31718..31719:*(inner+8) += len;31720 迁移门(0xfffff)— cited —
    //   wave-2;31721 run 模式灌值腿(LAB_0099bf2b)— cited — wave-2。
    //   31872..31905 gapbuf 容量/两段机(FUN_0088a016/gapbuf_shrink)— cited —
    //   wave-2;ctor 可达路(新面 segBound=0/tailOff=0/pos==segBound)直写同相
    //   (怪癖登记:承载坍缩为数组重分配,两段机随写侧批升级)。
    void modAppendRange(int pos, int len, quint8 flag)
    {
        if (len < 1 || pos < 0 || inner->flat->total < pos)
            return;                                  // 31866..31871 门(len<1/pos<0/越界)
        inner->lineCount += len;                     // 31718..31719 *(inner+8) += len
        ModTrackFace *f = inner->flat;
        // 31872..31905 容量腿 — cited;承载等价:重分配容纳 [head|tail] 全量
        // (怪癖登记:gap 空洞布局不承载,两段读语义由 segBound/tailOff 保留)
        quint8 *nb = new quint8[size_t(f->total) + size_t(len)];
        if (f->bytes) {
            for (int i = 0; i < f->total; ++i) nb[i] = f->bytes[i];
            delete[] f->bytes;
        }
        f->bytes = nb;
        for (int i = 0; i < len; ++i)                // 31906..31910 *__s = flag(memset 同相)
            f->bytes[pos + i] = flag;
        f->total    += len;                          // 31911 *(f+0x14) += len
        f->segBound += len;                          // 31912 *(f+0x18) += len
        f->tailOff  -= len;                          // 31913 *(f+0x1c) -= len
    }

    // FUN_0099a362(94B @0032.c:30408)— M 析构腿(b07a 前缀同构 31122..31133)
    void modDtor()
    {
        modTeardownInner();
        inner = nullptr;
    }

    // a362/b07a 共有拆除骨架(30414..30423 / 31122..31133;语料两处内联)
    void modTeardownInner()
    {
        if (!inner)
            return;                                  // 30414 pvVar1 == 0 → return
        if (inner->flat) {                           // 30415 *(inner+0x18)
            delete[] inner->flat->bytes;             // 30416 free(*(face+8))
            delete inner->flat;                      // 30417 operator_delete(face,0x20)
        }
        inner->flat = nullptr;                       // 30418 *(inner+0x18) = 0
        if (inner->runs) {                           // 30419 vt+8 释放虚调 — 语料 vtbl cited
                                                     //   恒 null 壳期同相;我方委托拆除:
            delete inner->runs->rs;                  //   RS8 承载(migrateLayer ⑥ 同构)
            if (inner->runs->runFlags) {
                delete[] inner->runs->runFlags->bytes;
                delete inner->runs->runFlags;        //   D0 链内部面(D2 GB 壳坍缩)
            }
            delete inner->runs;                      //   H 本体(deleting dtor 008913d0 同相)
        }
        delete inner;                                // 30423 operator_delete(inner,0x20)
        inner = nullptr;
    }
};

// ============ 七函数族(0032.c;inline 转写)============

// FUN_0099a3c0(12B @0032.c:30434)模态:*(*param_1+0x10) != 0 = 游程
inline bool mtRunMode(const ModTrack *m)
{ return m && m->inner && m->inner->runs != nullptr; }

// 两段读骨架(语料 0099b36c 31300..31308 字面):
//   idx < segBound → bytes[idx](idx<0 → 0);idx < total → bytes[idx+tailOff];越界 0
inline quint8 mtFaceRead(const ModTrackFace *f, int idx)
{
    if (!f)
        return 0;                                    // 壳期守卫(语料无;调点均在 init 后)
    if (idx < f->segBound) {
        if (idx < 0)
            return 0;                                // 31304 语料字面
        return f->bytes[idx];                        // 31305
    }
    if (idx < f->total)                              // 31306
        return f->bytes[idx + f->tailOff];           // 31307
    return 0;                                        // 31308
}

// runstyles_run_start_at(009698d0 64B @0031.c:38484)委托等价:
//   count 钳制(38488..38492)后取界位 b_run ≡ 最小界 > run-1
//   (public API 无 PartitionFromPosition — FindNextChange 界走等价,怪癖登记)
inline qint64 mtRunStartPos(const Scintilla::RunStyles<int, char> *rs, int run)
{
    if (!rs)
        return 0;                                    // 壳期守卫
    const int count = int(rs->Runs());               // 38488 runstyles_runs_count
    if (count <= run)
        run = count;                                 // 38489..38490
    if (run < 0)
        run = 0;                                     // 38491..38492
    if (run == 0)
        return 0;                                    // b_0 = 0(空界)
    return rs->FindNextChange(run - 1, rs->Length());// b_run(界走等价)
}

// runstyles_fill_range(RS,pos)(00969910 514B @0031.c:38506)≡ RunFromPosition
// (RunStyles.cxx:33;0032.c:37040 调点同参互证)— 委托承载:界走计数等价
inline int mtRunIndexOf(const Scintilla::RunStyles<int, char> *rs, int pos)
{
    if (!rs || pos < 0)
        return 0;
    int run = 0;
    qint64 b = 0;
    for (;;) {
        const qint64 nxt = rs->FindNextChange(b, rs->Length());
        if (nxt <= b || nxt > pos)
            break;
        b = nxt;
        ++run;
    }
    return run;
}

// FUN_0099a47a(56B @0032.c:30498)runAt:line → run 索引
//   flat:param_2 直通(30505);游程:vt+0x28 → runstyles_fill_range(30510)
inline int mtRunAt(const ModTrack *m, int line)
{
    if (!m || !m->inner)
        return line;                                 // 壳期守卫
    if (!m->inner->runs)
        return line;                                 // 30505
    return mtRunIndexOf(m->inner->runs->rs, line);   // 30510
}

// FUN_0099a4b2(56B @0032.c:30521)runCount
//   flat:*(doc+0x14)(30524);游程:vt+0x30 → runstyles_runs_count(30528)
inline int mtRunsCount(const ModTrack *m)
{
    if (!m || !m->inner)
        return 0;                                    // 壳期守卫
    if (!m->inner->runs)
        return m->inner->flat->total;                // 30524
    return m->inner->runs->rs
        ? int(m->inner->runs->rs->Runs()) : 0;       // 30528(委托 Runs())
}

// FUN_0099a4ea(46B @0032.c:30544)runStart
//   flat:param_2 直通(30549);游程:vt+0x38 → run_start_at(run)(30554)
inline qint64 mtRunStart(const ModTrack *m, int run)
{
    if (!m || !m->inner)
        return run;                                  // 壳期守卫
    if (!m->inner->runs)
        return run;                                  // 30549
    return mtRunStartPos(m->inner->runs->rs, run);   // 30554
}

// FUN_0099a448(49B @0032.c:30475)runEnd = run_start_at(run+1)
//   flat:param_2 直通(30580);游程:vt+0x40 → run_start_at(run+1)(30584)
inline qint64 mtRunEnd(const ModTrack *m, int run)
{
    if (!m || !m->inner)
        return run;                                  // 壳期守卫
    if (!m->inner->runs)
        return run;                                  // 30580
    return mtRunStartPos(m->inner->runs->rs, run + 1);   // 30584
}

// FUN_0099b36c(339B @0032.c:31287)行标志读
//   flat:文档面两段读(31298..31308);游程:runAt → D2 subface 两段读
//   (31299..31327;GB 密排/zstd 00889cde/QReadWriteLock 腿 — cited — wave-2,
//    我方构造恒 subface 非空同相)
inline quint8 mtLineFlag(const ModTrack *m, int line)
{
    const ModTrackRunFace *h = m->inner->runs;       // 31295 *(inner+0x10)
    if (!h)                                          // 31296
        return mtFaceRead(m->inner->flat, line);     // 31298..31308
    const int run = mtRunAt(m, line);                // 31301..31302
    return mtFaceRead(h->runFlags, run);             // 31304..31327(坍缩注记)
}

// FUN_0099b4c8(262B @0032.c:31363)游程旗标
//   flat:文档面直读(run=行号,31372..31376);游程:D2 subface 直读(31378..31395)
inline quint8 mtRunFlag(const ModTrack *m, int run)
{
    const ModTrackRunFace *h = m->inner->runs;       // 31371
    if (!h)                                          // 31372
        return mtFaceRead(m->inner->flat, run);      // 31373..31376
    return mtFaceRead(h->runFlags, run);             // 31378..31395
}

// FUN_00927a78(365B @0030.c:23559..23632)markerBand — 双模首带查询。
//   返回 {start, end+1}(半开收尾 23597..23599);saved/unsaved 出参 =
//   f&1 / (f>>1)&1(23586..23587)。门:from >= lineCount → {-1,-1}(23566)。
inline QPair<qint64, qint64> mtMarkerBand(const ModTrack *m, qint64 from,
                                          qint64 lineCount,
                                          quint8 *saved = nullptr,
                                          quint8 *unsaved = nullptr)
{
    if (from >= lineCount)                           // 23566 param_2 < FUN_00925570()
        return {-1, -1};
    if (!mtRunMode(m)) {                             // 23568 cVar1 == '\0' → 线性支
        quint8 band = 0;                             // 23569 bVar3
        qint64 st = -1, en = -1;                     // 23570..23571 lVar7/lVar9
        qint64 cur = from;                           // 23572 param_2
        for (;;) {                                   // 23572 do-while
            const quint8 v = mtLineFlag(m, int(cur));    // 23574..23576
            if (band != 0) {                         // 23577 带延续检查
                if (v != band)                       // 23580 短路:带断 → 收尾(en 不延)
                    break;
                en = cur;                            // 23581 lVar9 = lVar6
                ++cur;                               // 23581 param_2 = cur+1
                if (cur == lineCount)                // 23582 lVar6+1 == lVar5
                    break;                           //   → LAB_00927b3a
                continue;
            }
            if ((v & 3) != 1) {                      // 23585 非 saved-only → 开带
                if (saved)
                    *saved = quint8(v & 1);          // 23586
                if (unsaved)
                    *unsaved = quint8(v >> 1 & 1);   // 23587
                st = cur;                            // 23588 lVar7 = lVar6
                en = cur;                            // 23589 lVar9 = lVar6
                band = v;                            // 23590 bVar3 = bVar2
            }
            ++cur;                                   // 23592 param_2 = lVar6+1
            if (cur == lineCount)                    // 23593 while 条
                break;
        }
        if (en != -1)                                // 23597..23598
            en = en + 1;                             // 23599 半开收尾
        return {st, en};                             // 23601 LAB_00927aa9
    }
    // 游程支(23603..23623)
    const int run = mtRunAt(m, int(from));           // 23603 FUN_0099a47a
    const int count = mtRunsCount(m);                // 23605 FUN_0099a4b2
    for (qint64 u = run; u < count; ++u) {           // 23608..23622 do-while
        const quint8 v = mtRunFlag(m, int(u));       // 23610 FUN_0099b4c8
        if ((v & 3) != 1) {                          // 23612 非 saved-only
            if (saved)
                *saved = quint8(v & 1);              // 23613
            if (unsaved)
                *unsaved = quint8(v >> 1 & 1);       // 23614
            qint64 st = mtRunStart(m, int(u));       // 23615 FUN_0099a4ea
            if (st <= from)                          // 23617 钳到查询点
                st = from;
            return {st, mtRunEnd(m, int(u))};        // 23618..23619 FUN_0099a448
        }
    }
    return {-1, -1};                                 // 23625..23627 全 skip 腿
}

} // namespace wt
