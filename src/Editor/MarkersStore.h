// MarkersStore — markers 对象读侧真身化(批 67a;布局与函数全部语料实证)
// 布局还原:FUN_0099cxxx/009a0xxx 存储族 16 函数(台账见 docs/PHASE5.md 批 67);
// 写侧(FUN_0099c8d6/0099d27e memo)与本包外 —— 构建者批。行为测试须等写入侧。
// 语料地址均为 Ghidra 基址(非 PIE 直通)。
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

// --- cited/委托腿(编译占位;逐个换真身)---
// 委托真 Scintilla RunStyles(标准行为边界;语料 007b7b70/007b5a30/007b6dd0/
// 0088ff00 各 ~240B:直接数组快路 + 线程缓存回退,体已读)—— 值域待接线
inline quint32 rsValue32(void *, int) { return 0; }  // Uint32RunStyles_valueAt — 委托
inline quint64 rsValue64(void *, int) { return 0; }  // Uint64RunStyles_valueAt — 委托
inline quint16 rsValue16(void *, int) { return 0; }  // runstyles_value_at16    — 委托
inline quint8  rsValue8 (void *, int) { return 0; }  // FUN_0088ff00(RS8)     — 委托

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
    quint8      _r08[0x10];              // +0x08..0x17 未解
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

// libstdc++ _Sp_counted_base<Lock_policy 2>(0099d1f6 语料类型;libstdc++ 边界)
using SpBase = std::_Sp_counted_base<__gnu_cxx::_Lock_policy::_S_atomic>;

// ⚠ 批 69 勘正(mk2 构建者勘察):M ≡ D = doc-state(0x70B,挂
// E+0xc0);pool/stopCount/serialEntries/name/nodes 实属 E 对象
// (+0x118/+0x128/+0x250/+0x2b8/+0x2d8),已迁 EditorContext 平铺。
// A=0x38/bank=0x40 全在 editor_initDoc(009a2e1e,956B)尾构建。
// tlist(+0x18):0099c75a 读侧实证 vs mk2"lexerSnap"说冲突,以读侧
// 为准,构建者批复核。
struct MarkersStore {                    // M ≡ D = doc-state(0x70B)
    MarkersArray *arr;                   // +0x000 A(0x38;*A=D 回指)
    void         *doc;                   // +0x008 E(折叠 +0xe0 族 / 层级 +0xa0 / 行数 +0xf8)
    quint8       _r10[0x08];             // +0x010 未解
    ValueTable   *tlist;                 // +0x018 T(FUN_00a101a0;与 bank 不同对象!)
    quint8       _r20[0x28];             // +0x020..0x047 未解
    quint8       spin;                   // +0x048 读侧自旋字节(0069e8ac;解锁=写0)
    quint8       _r49[0x07];
    quint64      visibleSnap;            // +0x050 可见快照槽(0099d1f6 返回 &此)
    SpBase      *curSnap;                // +0x058 当前快照
    quint64      stagedSnap;             // +0x060 暂存快照值
    SpBase      *pendSnap;               // +0x068 待发布快照(0x70 止)

    MarkersStore()
    {
        // 语料 M 为裸内存零化;此处含 Qt 成员,禁 memset(析构崩)——
        // POD 显式清零,Qt 成员走默认构造
        arr = nullptr; doc = nullptr; tlist = nullptr;
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

    // FUN_0092e44e(0x754d 体)已迁 EditorEngine case 0x754d —— 批 69
    // 勘正:stopCount/nodes 属 E 面,不在 D(本结构)
};

static_assert(sizeof(MarkersStore) == 0x70, "D 0x70B (mk2 勘正)");

} // namespace wt
