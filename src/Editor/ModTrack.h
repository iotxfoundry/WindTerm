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
//   面(0x20) = {+0x00 vt cited, +0x08 字节数组, +0x10 int 容量(0088a016 步进),
//               +0x14 int 总行数, +0x18 int 段界, +0x1c int 尾段偏移}
//               (两段读语义 0099b36c;容量机 39853..39858)。
//   游程面 H(0x20,bbb0 迁移腿 puVar7 形)= {+0x00 vt cited(Uint8RunStyles 族;
//     身份槽 +0x28/+0x30/+0x38/+0x40 = vt5/6/7/8 — a47a/a4b2/a4ea/a448 检查),
//     +0x08 runs 面(委托形态直存 RS8 — MarkersStore §1 同怪癖), +0x10 D2 面。
//     语料 D2 = GB 0x30 壳{+0x18 subface}(bbb0 puVar9+puVar10);我方坍缩直存
//     subface(kwcMemo QHash 坍缩同款怪癖登记),GB 密排路随壳消失。
// 七函数(0032.c):0099a3c0(30434)/0099a448(30475)/0099a47a(30498)/
//   0099a4b2(30521)/0099a4ea(30544)/0099b36c(31287)/0099b4c8(31363)。
//   (批 114 增:0099b740 flagmask_set_range — 位面写侧,见 mtRunIndexOf 后)
// 写侧族(批 107):0099b152(31173,11B 追加转发)/0099b15e(31183,517B 单行置标志)
//   — 调用点:FUN_00926ac0(0030.c:21901,CSuperBufferBase_h9805cc 0032.c:9536 转发)
//   / session_stop_handlers(0030.c:28779,保存腿 flag&0xfb)/FUN_00957fb6
//   (0031.c:25592)/FUN_009597fa(0031.c:26962)/0095bexx(0031.c:28641)。
// bbb0 写尾两段机(31721..31871):segBound<pos → gapbuf_shrink(pos) 移位;
//   容量不足(tailOff<len)→ FUN_0088a016(221B @0027.c:39819,gap 机扩容:
//   cap<0x2000001→+cap/2 否则 +cap/4,realloc 后尾段 memmove 重建 gap);
//   pos==segBound 跳 shrink(3745/3758 kuna branch-flip 同相)。
//   ctor 可达路(pos=0/segBound=0)走 else 腿:shrink(0)+8a016 同序。
// cited — wave-2:zstd 压缩腿 FUN_00889cde(280B @0027.c:39620)、QReadWriteLock
//   锁腿、bbb0 0xfffff 迁移腿(puVar7 建 Uint8RunStyles + piecetable + GB
//   0099bc2c..0099be0a — piecetable_init 0096a2f8/FUN_0093fc60/GAP 壳全链
//   依赖外库承载,坍缩建模会破坏读路 invariants)。批 111 判定:不可脱离外库
//   转写 — piecetable_init 0096a2f8(0031.c:39050;Partitioning vt + Uint32PieceTable
//   0x60 内嵌 GB + QThread::currentThreadId + DAT_011be6f0 全局计数器)+ FUN_0093fc60
//   (546B,spinlock_lock_backoff/线程缓存)+ FUN_0088f940(1448B 线程缓存管理)三链
//   皆 QThreadPool/QReadWriteLock 形态,缺改版头不自造。运行时驱动改为测试装置:
//   tests/modtracktest e 组按坍缩承载注入等价面(RS8 + runFlags;装置非产品行为码),
//   与 run 灌值腿
//   (LAB_0099bf2b = Uint8RunStyles_dtor 008912e8 + gapbuffer_get_chars_locked
//   00890880 2599B — 委托形态 RunStyles FillRange 承载留游程激活批)互补。
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
    int      cap = 0;                    // +0x10 容量(0088a016 39854 步进)
    int      total = 0;                  // +0x14 总行数(bbb0 尾 *(f+0x14)+=len)
    int      segBound = 0;               // +0x18 段界(两段读第一段界)
    int      tailOff = 0;                // +0x1c 尾段偏移(第二段基 = idx+tailOff)
};

// ============ 两段容量机(0027.c;bbbo 写尾调用链)============

// gapbuf_shrink — FUN_00889e2e(95B @0027.c:39714):gap 推移到 param_2。
//   pos<segBound:尾段左移 [pos, segBound) → pos+tailOff(31719..31723);
//   否则尾段右移 [segBound,pos) → segBound+tailOff(31725..31729)。
//   两腿均 *0x18 = pos(31724/31730)。全零数组承载:同 memmove 语义直拷。
inline void gapShrink(ModTrackFace *f, int pos)
{
    if (pos < f->segBound) {                         // 39721
        for (int i = pos; i < f->segBound; ++i)      // memmove(tail+pos, head+pos, bound-pos)
            f->bytes[i + f->tailOff] = f->bytes[i];
    } else {
        for (int i = f->segBound; i < pos; ++i)      // memmove(head+bound, tail+bound, pos-bound)
            f->bytes[i] = f->bytes[i + f->tailOff];
    }
    f->segBound = pos;                               // 39724/39730
}

// FUN_0088a016(221B @0027.c:39819)gap 扩容。cap<0x2000001 → +cap/2,否则
//   +cap/4(39824..39828);负/零新容量 → runtime_error throw(39832..39845,
//   载体 new 抛 bad_alloc 同失效路径);realloc 成功后尾段 memmove 到
//   [oldTail+grow+segBound)(39852..39855)→ *0x1c = grow+oldTail(39858)。
//   增量回退腿 39864..39868(δ>>2<9 停)— 载体 new 单轮即终,不承载(怪癖登记)。
//   参数 = len(39853 v2=+a1);我方扩到 total+2*len+grow 界(全量数组承载
//   不留 gap 空洞,write 尾步进同相)。
inline void gapRealloc(ModTrackFace *f, int len)
{
    const int oldCap  = f->cap;                      // 语料 +0x10 容量(独立于 total)
    const int segB    = f->segBound;
    const int oldTail = f->tailOff;
    const int grow = oldCap < 0x2000001 ? oldCap / 2 : oldCap / 4;   // 39824..39828
    const int newTail = grow + len + oldTail;        // 39852 v3 = δ+len+oldTail
    quint8 *nb = new quint8[size_t(oldCap) + size_t(len) + size_t(grow) + 1];
    for (int i = 0; i < segB; ++i)                   // 头段原位
        nb[i] = f->bytes[i];
    for (int i = 0; i < f->total - segB; ++i)        // 39855 尾段搬新偏移
        nb[newTail + segB + i] = f->bytes[oldTail + segB + i];
    delete[] f->bytes;
    f->bytes   = nb;                                 // 39853 *0x08
    f->cap     = oldCap + len + grow;                // 39854 *0x10
    f->tailOff = newTail;                            // 39858 *0x1c = v3
}


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

    // FUN_0099bbb0(1296B @0032.c:31704)写侧主体。头部(31718..31720):
    //   *(inner+8)+=len;0xfffff 迁移门 — cited(见头注)。flat 腿 31721..31871:
    //   len<1/pos<0/pos>total → return(31866..31871);segBound<pos → shrink(pos)
    //   把 gap 推到写点(31838 gapbuf_shrink 0027.c:39714);容量不足 tailOff<len
    //   → FUN_0088a016 扩容(0027.c:39819);memset 灌值(31906..31910,1 字节特判
    //   同相);尾步进 total+=len/segBound+=len/tailOff-=len(31911..31913)。
    //   语料序:pos<segBound 腿 = 8a016 先(容量)→ shrink 后(31735..31741);
    //   pos>segBound 腿 = shrink 先 → 8a016(31744..31751)。kuna 0099bbb0
    //   branch-flip 互证(v14<=v1 → else 31746 直跳 cb)。
    void modAppendRange(int pos, int len, quint8 flag)
    {
        if (len < 1 || pos < 0 || inner->flat->total < pos)
            return;                                  // 31866..31871 门
        inner->lineCount += len;                     // 31718..31919 *(inner+8) += len
        ModTrackFace *f = inner->flat;
        const int bound = f->segBound;               // 31724 iVar13
        if (bound < pos) {
            gapShrink(f, pos);                       // 31744..31745 shrink 先
            if (f->tailOff < len)                    // 31746..31747
                gapRealloc(f, len);                  // 31748 8a016(返回即定界)
        } else {
            if (f->tailOff < len)                    // 31734..31735 容量先
                gapRealloc(f, len);                  // 31736 8a016
            if (pos != f->segBound)                  // 31739..31740(v14==v1 跳 cb)
                gapShrink(f, pos);                   // 31741 shrink 后
        }
        quint8 *s = f->bytes + f->segBound;          // 31903 __s = segBound+bytes
        if (len == 1)                                // 31904..31905 单字节特判同相
            *s = flag;
        else
            for (int i = 0; i < len; ++i)            // 31906..31910 memset 同相
                s[i] = flag;
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

// mtRunFlagAt — b15e 同构读辅助(FUN_0088ff00 31287 前置读面:两段字面同构)
inline quint8 mtRunFlagAt(const Scintilla::RunStyles<int, char> *, const ModTrackFace *f, int run)
{
    if (run < f->segBound)                           // 31302..31304
        return run < 0 ? quint8(0) : f->bytes[run];
    if (run < f->total)                              // 31305..31306
        return f->bytes[run + f->tailOff];           // 31307
    return 0;                                        // 31308
}

// ============ 写侧族(0032.c;批 107)============

// FUN_0099b152(11B @0032.c:31173):追加转发 — FUN_0099bbb0(*param_1,pos,len,flag)。
//   调用点:00926ac0(0030.c:21901)/FUN_00957fb6(0031.c:25592,flag=0x10|~)
//   /FUN_009597fa(0031.c:26962)/0095bexx(0031.c:28641)。
inline void mtAppendRange(ModTrack *m, int pos, int len, quint8 flag)
{ m->modAppendRange(pos, len, flag); }               // 31175 tail-call 同体

// modAttachRunFace — 批 111 测试装置(非产品行为码):语料 runs 面构造腿 =
//   bbb0 0xfffff 迁移门(lVar6>0xfffff 且 runs==0 → operator_new(0x20)+
//   piecetable_init+GB 壳 + Uint8RunStyles_vtable 挂 inner+0x10,31726..31865
//   全链 cited,见头注批 111 判定)。测试按坍缩承载注入等价面:RS8 委托 +
//   runFlags 两段 face(bbb0 灌值腿 LAB_0099bf2b 迁移值经 runFlags 承载)。
inline void modAttachRunFace(ModTrack *m, Scintilla::RunStyles<int, char> *rs,
                             ModTrackFace *runFlags)
{
    ModTrackRunFace *h = new ModTrackRunFace;        // 0099bc2c operator_new(0x20) 形
    h->rs = rs;                                      // puVar7[1](坍缩直存,怪癖登记)
    h->runFlags = runFlags;                          // puVar7[2](GB 0x30 壳坍缩)
    m->inner->runs = h;                              // *(param_1+0x10) = puVar7(31865)
}

// FUN_0099b15e(517B @0032.c:31183)单行置标志。语料全读(kuna 互证):
//   flat 支(31190..31200):pos<segBound(<0 拒)→ bytes[pos]=flag;
//   segBound<=pos<total → bytes[pos+tailOff]=flag;越界拒。
//   游程支(31202..31286):runAt(u+1)/runAt(u-1) 同值 → delete_chars+insert_space_b
//   run 合并(31210..31215/31260..31266);per-run 旗标直写(31230..31286,两段同构)。/FUN_0088f940 线程缓存腿 — cited;游程支运行承载(批 111 驱动,
//   测试经 modAttachRunFace 装置注入;产品侧迁移腿仍 cited):
//   合并腿 = RS DeleteRange+InsertSpace(0096a06e/00940400 委托同相;
//   语料 31210..31215/31260..31266,值域 009cd3da 内),旗标写 =
//   runFlags face 两段直写(31230..31286 同构 mtFaceRead 两段语义)。
//   批 114 复核:本转写 param_3 整字节写 = 语料 31183 字面同相(b15e 无
//   位面机 — 位面语义在调点层 0x958048/0x958108 → b740,见 mtBit4SetClr/
//   mtLineSlotClrBit3/flagmaskSetRange;EditorEngine 调点 rewire 下批解禁)。
inline void mtSetLineFlag(ModTrack *m, int line, quint8 flag)
{
    ModTrackInner *in = m->inner;                    // 31186 *(param_1+8)
    if (!in->runs) {                                 // 31187..31189 runs==0
        ModTrackFace *f = in->flat;                  // 31188 +0x18
        if (line < f->segBound) {                    // 31190..31192
            if (line < 0)                            // 31193..31195
                return;
        } else {
            if (f->total <= line)                    // 31196..31198
                return;
            line += f->tailOff;                      // 31199
        }
        f->bytes[line] = flag;                       // 31200
        return;
    }
    Scintilla::RunStyles<int, char> *rs = in->runs->rs;   // 31202 +0x08
    ModTrackFace *rf = in->runs->runFlags;           // 31204..31205 +0x10 面
    const int cnt = rs->Runs();                      // 31203 runs_count 00968a72
    // run(u+1) 同值 → 吸后 run(31208..31215):delete_chars(u+1,1)+insert_space_b(u+1,1)
    if (line + 1 < cnt && mtRunFlagAt(rs, rf, line + 1) == flag) {
        rs->DeleteRange(line + 1, 1);                // 31213 runstyles_delete_chars 0096a06e
        rs->InsertSpace(line + 1, 1);                // 31214 insert_space_b 00940400
    }
    // run(u-1) 同值 → 吸前 run 后返回(31257..31266)
    if (line >= 1) {
        if (mtRunFlagAt(rs, rf, line - 1) == flag) {
            rs->DeleteRange(line, 1);                // 31262
            rs->InsertSpace(line, 1);                // 31263
            return;                                  // 31264..31266 tail
        }
    }
    // per-run 旗标写(31230..31286 扁平化;两段同构 face 直写)
    if (line < rf->segBound) {
        if (line < 0)
            return;                                  // 31233..31236
        rf->bytes[line] = flag;                      // LAB_0099b1f6 31237
        return;
    }
    if (rf->total <= line)                           // 31283..31285 尾门
        return;
    rf->bytes[line + rf->tailOff] = flag;            // 31286
}

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
    if (run == count)                                // 38497 run==count → 尾界表
        return rs->Length();                         //   b_cnt = 尾界(009694fe
                                                     //   +0x20 尾哨腿同相)
    return rs->FindNextChange(run - 1, rs->Length());// b_run(界走等价)
}

// runstyles_fill_range(RS,pos)(00969910 514B @0031.c:38506)等价转写:
//   语料非直线二分:pos<Length 门(38586 param_2 < *(p+0x28) 直线腿)—
//   pos 超尾 → 不进二分,返回 lVar6 = runs-1(38576 cnt-1 起值)。批 114
//   复核:pos==Length 时二分腿 lVar6 收敛于 runs-1(38588..38599 界钳);
//   映射 = [0, Length] 闭区间单调,超界钳 cnt-1。RunFromPosition 上游
//   PartitionFromPosition 对 pos==Length 返回 Partitions()(=runs,越界)
//   — 直线钳腿同相:超界返回 runs-1(38576/38604 lVar6)。
inline int mtRunIndexOf(const Scintilla::RunStyles<int, char> *rs, int pos)
{
    if (!rs || pos < 0)
        return 0;
    const int count = int(rs->Runs());               // 38513 runs_count
    if (pos >= rs->Length())                         // 38586 门(超尾不进二分)
        return count > 0 ? count - 1 : 0;            // 38576 lVar6 起值/空守卫
    int run = 0;
    qint64 b = 0;
    for (;;) {                                       // 38588..38599 二分等价(线性)
        const qint64 nxt = rs->FindNextChange(b, rs->Length());
        if (nxt <= b || nxt > pos)
            break;
        b = nxt;
        ++run;
    }
    return run;
}

// FUN_0099b740 flagmask_set_range(1121B @0032.c:31520..31716;批 114,kuna 互证)。
//   位面写:(cur & ~clr) | set — 非整字节覆盖。返回 1 = 有变化(位面差才写,
//   同值 trim no-op 31548/31561/31568)。flat 支(31529..31578):M+0x18 文档面
//   逐行两段写;越界行(<0/≥total)set!=0 → 返回 1 但不写(31536/31576 语料字面)。
//   runs 支(31579..31716):inner+0x10 H 面 — fill_range(pos)→run0(31587
//   00969910 委托同 mtRunIndexOf),flag 面 = H+0x10 D2(索引空间 = run,
//   0088ff00(31287 前置)读/两段写;c10e 合并腿 31599 → FUN_0099c10e
//   31922:邻 run 同值 delete_chars+insert_space_b 摘界合并,委托 RS 同 b15e)。
//   GB 密排/0088f940 线程缓存腿 — cited — wave-2(头注批 111 同判定)。
//   runs 支承载(装置面,modAttachRunFace 注记):run0..end 边界经
//   mtRunIndexOf/mtRunStartPos 委托;头/中/尾三段位面写 31599..31716 字面同构。
//   (体在 mtRunIndexOf 定义之后 — 坑 3 依赖序;下行声明即定义点)
inline quint8 flagmaskSetRange(ModTrack *m, long pos, quint8 set, quint8 clr, long count)
{
    if (!m || !m->inner)
        return 0;                                    // 壳期守卫(语料调点均在 init 后)
    quint8 changed = 0;                              // uVar9
    if (!m->inner->runs) {                           // 31529 *(param_1+0x18)==0 flat 支
        ModTrackFace *f = m->inner->flat;            //   lVar11 = *(lVar1+0x18)
        const long end = pos + count;                // 31531 param_5 = p5+p2
        if (end <= pos)
            return 0;                                // 31532..31534 溢出门
        for (long i = pos; i < end; ++i) {           // 31535..31577 do-while 字面
            if (i < f->segBound) {                   // 31537..31540
                if (i < 0) {                         // 31541..31543
                    if (set != 0)
                        changed = 1;                 // 31543 LAB_0099b7ef(不写)
                    continue;
                }
                quint8 *p = &f->bytes[i];            // 31542 pbVar4
                const quint8 v = quint8((~clr & *p) | set);   // 31543 位面
                if (*p != v) { *p = v; changed = 1; }         // 31544/31553/31554
            } else if (i < f->total) {               // 31545..31547 尾段
                quint8 *p = &f->bytes[i + f->tailOff];        // 31546 +0x1c
                const quint8 v = quint8((~clr & *p) | set);
                if (*p != v) { *p = v; changed = 1; }         // 31553..31555
            } else {
                if (set != 0)
                    changed = 1;                        // 31575..31577(不写)
            }
        }
        return changed;                              // 31578
    }
    // runs 支(31579..31716)
    Scintilla::RunStyles<int, char> *rs = m->inner->runs->rs;      // +0x08
    ModTrackFace *rf = m->inner->runs->runFlags;     // +0x10 flag 面(D2 索引=run)
    const long end = pos + count;
    if (end < 2) {                                   // 31582..31583 单 run 特判腿
        if (end != 1)
            return 0;                                // 31584..31586 count<1
        const int run0 = mtRunIndexOf(rs, int(pos)); // 31587 runstyles_fill_range
        const quint8 cur = mtRunFlagAt(rs, rf, run0);// 31588 FUN_0088ff00
        const quint8 v = quint8((set | cur) & ~clr); // 31589
        if (cur == v)
            return 0;                                // 31590..31592
        rf->bytes[pos] = v;                          // 31593 gapbuffer_get_chars_locked
        return 1;                                    //   (lVar1,pos,v,1,0)→face[pos](1B)
    }
    const int run0 = mtRunIndexOf(rs, int(pos));     // 31597
    const int run1 = run0 + 1;                       // 31598 iVar12
    const qint64 r1End = mtRunStartPos(rs, run1);    // 31599 run_start_at(run1)
    const quint8 inv = quint8(~clr);                 // 31602 param_4 = ~clr
    quint8 v0 = 0;                                   // bVar10 头段值(两腿共用写)
    bool headWrite = false;                          // 31643 gapbuffer 触发
    if (r1End == end) {                              // 31603..31621 全程落 run0
        const qint64 r0Start = mtRunStartPos(rs, run0);       // 31607
        if (pos == r0Start) {                        // 31608 起点即界 → 单 run 写
            const quint8 cur = mtRunFlagAt(rs, rf, run0);     // 31609
            const quint8 v = quint8((set | cur) & inv);
            if (cur == v)
                return 0;                            // 31613..31614
            // FUN_0099c10e(H,run0,v,1)(31615)单 run 换值:合并腿 — 委托 RS 同相
            const int cnt = rs->Runs();              // 31931 runstyles_runs_count
            if (run1 < cnt && mtRunFlagAt(rs, rf, run1) == v) {  // 31937..31940
                rs->DeleteRange(run1, 1);            // 31942 runstyles_delete_chars
                rs->InsertSpace(run1, 1);            // 31943 insert_space_b(等价腿,
            }                                        //   RemovePartition 私有 — e3 注记同)
            if (run0 >= 1 && mtRunFlagAt(rs, rf, run0 - 1) == v) {// 31948..31953
                rs->DeleteRange(run0, 1);
                rs->InsertSpace(run0, 1);
                return 1;                            // 31956..31957
            }
            // 31959..31964 两段直写(run 索引 = rf 槽位;同 b15e 两段语义)
            if (run0 < rf->segBound)
                rf->bytes[run0] = v;
            else if (run0 < rf->total)
                rf->bytes[run0 + rf->tailOff] = v;
            return 1;                                // 31616
        }
        const quint8 cur = mtRunFlagAt(rs, rf, run0);// 31618
        v0 = quint8((cur | set) & inv);
        if (cur == v0)
            return 0;                                // 31621..31622(直返,非落 b887)
        headWrite = true;                            // → 31643 共写腿
    } else {                                         // 31624..31631 跨 run 头段
        const quint8 cur = mtRunFlagAt(rs, rf, run0);
        v0 = quint8((cur | set) & inv);
        if (cur == v0)
            ;                                        // 31630 → b887(不写,走尾判)
        else
            headWrite = true;
    }
    if (headWrite) {                                 // 31633..31646 共写腿
        const long n = (r1End - pos) < count ? (r1End - pos) : count;
        for (long i = pos; i < pos + n; ++i)         // 31636..31638 gapbuffer(face[pos],n)
            rf->bytes[i] = v0;
        changed = 1;                                 // 31639
    }
    if (end <= r1End)                                // LAB_0099b887 31640..31643

    if (end <= r1End)                                // LAB_0099b887 31640..31643
        return changed;
    // 中段腿(31644..31697):run1..fill(end)-1 逐 run 位面写(界每轮 fill(end)
    //   定;out-of-range+set!=0→1 不写 31685 语料字面同 flat 支;face 索引
    //   lVar5 与 run 号锁步 31695..31696)
    const int runAtEnd = mtRunIndexOf(rs, int(end)); // 31644 runstyles_fill_range(end)
    for (int u = run1, faceIdx = run1; u < runAtEnd; ++u, ++faceIdx) {
        const quint8 cur = mtRunFlagAt(rs, rf, u);   // 31653 FUN_0088ff00
        const quint8 v = quint8((set | cur) & inv);
        if (cur == v)                                // 31658..31661
            continue;
        if (faceIdx < rf->segBound) {                // 31664..31667 两段写
            if (faceIdx < 0) {
                if (set != 0)
                    changed = 1;                     // LAB_0099ba07(不写)
                continue;
            }
            rf->bytes[faceIdx] = v;                  // 31676
            changed = 1;
        } else if (faceIdx < rf->total) {            // 31681..31690
            rf->bytes[faceIdx + rf->tailOff] = v;    // 31688
            changed = 1;
        } else {
            if (set != 0)
                changed = 1;                         // 31691(不写)
        }
    }
    // 尾段腿(31700..31714):runAtEnd = fill(end)(中段循环计数,非重新查;
    //   cur 读 = face[runAtEnd 槽];位面差 → gapbuffer(face[run_start_at
    //   (runAtEnd)], end-run_start_at) = 尾 run 全段写,回 1
    const quint8 cur = mtRunFlagAt(rs, rf, runAtEnd);// 31700 FUN_0088ff00(lVar6,iVar3)
    const quint8 v = quint8((set | cur) & inv);      // 31701
    if (cur != v) {                                  // 31702..31704
        const long stEnd = mtRunStartPos(rs, runAtEnd);       // 31646 run_start_at
        for (long i = stEnd; i < end; ++i)           // 31705 gapbuffer(face[stEnd],end-stEnd)
            rf->bytes[i] = v;
        return 1;                                    // 31706..31707
    }
    return changed;                                  // 31708..31709
}

// ============ 0x95 face 调点辅助(0031.c:25618/25681;批 114)============
// M+0x28 行槽:0x95 引擎 face 标量字段(非外库面;消费点 0095809e 25695
//   *(ctx+0x28) 与行号比较/25693 写)。批 113 EditorEngine 调点(0x95c7a7/
//   0x95c7b4/0x95c88e)仍走整字节 mtSetLineFlag(本批禁写 EditorEngine.cpp —
//   约束登记);b15e 转写本身与语料同相(param_3 整字节 = 31183 字面),
//   分歧在 0x958048/0x958108 调点层,rewire 留下批 EditorEngine 解禁批。

// FUN_00958048(47B @0031.c:25618)bit4 位面:flag!=0 → b740(set 0x10,25630)
//   / flag==0 → b740(clr 0x10,25634);+0x168==0 → 直返(25623)。
inline void mtBit4SetClr(ModTrack *m, long line, quint8 flag)
{
    if (flag != 0)
        flagmaskSetRange(m, line, 0x10, 0, 1);       // 25630
    else
        flagmaskSetRange(m, line, 0, 0x10, 1);       // 25634
}

// FUN_00958108(78B @0031.c:25681)DL==0 腿(25691..25701):行槽 min 收敛
//   *(ctx+0x28)=min(line-1, *(ctx+0x28))(25693..25699 CMOV)+ b740(clr bit3);
//   DL!=0 → b740(set 8,25702)。槽 = 调用方面标量(引擎 ctx +0x28 承接)。
inline void mtLineSlotClrBit3(ModTrack *m, long *slot, long line)
{
    if (slot && line - 1 < *slot)
        *slot = line - 1;                            // 25695..25699(负向 min)
    flagmaskSetRange(m, line, 0, 8, 1);              // 25700
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
