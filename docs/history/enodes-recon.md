# enodes-recon — eNodes 节点层侦察(批 135,M10-②)

> ⚠ 2026-11-16:`tests/` 已删除(用户令),
> 本文中"ctest 通过"类判据**不再适用**;本文转为历史方案书,结论引用前查 `tools/re/handoff.md` 勘正谱系。

> 侦察批:只侦察不转写产品码。产出 = 方案书,供后续建模车道**免侦察直接执行**(KitWindow 判例批 131 格式)。
> 语料:tools/re/decomp/decomp-part-NNNN.c(`grep -n "entry=…"` 落点);kuna 直反编译(地址即 Ghidra VA)。
> typeinfo/vtable 为 ELF .data.rel.ro 实读(RW 段 file = VA − 0x600000;.rodata name 串 file = VA − 0x400000)。

## Q1 eNodes 对象全貌

### 1.0 载体定性(两级对象,勿混)
- **Map 载体 = E+0x2d8**:QMapDataBase 手工树(ctor `editor_engineCtor` FUN_00929bf8 @0030.c:25864
  写 `param_1[0x5b] = &QMapDataBase::shared_null`,0030.c:25941)。
  **键型 = char(1B kind)**,非 QString:FUN_0092b56e(306B,0030.c:27031)插入
  `QMapDataBase::createNode(db,0x28,8,…)` + `*(char*)(node+0x18)=kind` + `*(long*)(node+0x20)=value`
  (kuna 实读);FUN_0092586c(105B,0030.c:20835 前)树走查比较 `a1 <= *(char*)(node+0x18)`。
  节点 = 0x28(QMapNodeBase 0x18 头 + char key + void* value)。
  ⚠ 我方 `EditorContext.h:419 QMap<QString, void *> eNodes` **键型失配**(0x75cb 判例已登记)——建模批首改。
- **值对象 = 多态任务对象两族**(typeinfo 实读):
  - 基类 **DocumentTask**:TI 对象 **0x11ad4b0**(si_vptr 0x11b1a90,name "12DocumentTask"@0xce93d8),
    **vptr 0x11ad4e8**(vtable 头 @0x11ad4d8:{ott=0, TI=0x11ad4b0}),**sizeof = 0x30**(ctor FUN_00963590
    只写 0x30 域,kuna)。
  - 派生 **ScanTask**:TI **0x11ad588**(si_vptr 0x11b1c00,name "8ScanTask"@0xce94c8),
    **vptr 0x11ad650**(vtable 头 @0x11ad640:{ott=0, TI=0x11ad588}),**sizeof = 0xb0**
    (`operator_new(0xb0)` @92b56e + FUN_0096f606 扩展段)。
  - 语料全链 `__dynamic_cast(v,0x11ad4b0,0x11ad588,0)` = DocumentTask* → ScanTask* 下行转换
    (930226/9258b2/9264ba/92e368 一致;vtable 槽 18 处 0x11ad4b0 副链接实读)。
  - 派生 ctor 序:96f606 先调 963590(基类 DocumentTask 形,0x30 对象时 vptr=0x11ad4e8)再覆
    0x11ad650 —— 与 KitWindow(批 131)同构的「基 ctor + 覆 vptr」。
- **TaskRunner = QRunnable 包装 0x28**:FUN_009638d2(vptr=**0x11ad508**,TI=**0x11ad4c0**
  "8DocumentTaskRunner";+0x10=E,+0x18=node,+0x20=serial int);vtable 0x11ad508 实读
  (slot10=0x96aca0/slot11=0x96b200 等,run 载体)。

### 1.1 DocumentTask 字段清单(FUN_00963590 55B,kuna 全读 @0x963590)

| 偏移 | 型 | 初值/语义 |
|---|---|---|
| +0x00 | vptr | 0x11ad4e8(ScanTask 扩展 ctor 96f606 覆 0x11ad650) |
| +0x08 | char | **kind**(遍历门 0x754d `value+8∈[5,8]`;92e524 `kind==*(char*)(v+8)`) |
| +0x0c | int | 0(963590 字面;ScanTask kind=8 腿 9637b8 置 = mode) |
| +0x10 | u8 | 0;**kind∈[5,7] → 2**(963590);ScanTask 后被 9637b8 重置:kind∈{5,6,7,0xc}→1,kind==8→2;**遍历门 009635d8 = +0x10∈[1,2]**(0x754e/0x75aa 门) |
| +0x18 | u64 | ctor 参 a2(调用面传 0) |
| +0x20/+0x24 | u64 | 0(+0x24 = 9637da 分发门读:`((int*)v)[9]==0`) |
| +0x28 | u8 | **1**;=「已停」旗:**9264ba 见非 0 跳过**;009637ea 停机置 1 + 自旋等待 +0x20 锁;009637da 清 0 并返回 +0x24==0(可分发) |

vtable 槽(0x11ad4e8 实读):slot0 = 0x9638a6(D1:写 vptr + 尾调 009637ea 停机)、
slot1 = 0x9638ba(D0 同构)、slot4/5/6 = 0x96376e/0x963a5a/0x963a6e(零消费,转写批定名)。

### 1.2 ScanTask 扩展字段(FUN_0096f606 82B,kuna 全读;行面消费 96d0a0/96d620/96d022/96d094/96fb1e)

| 偏移 | 型 | 初值/语义 |
|---|---|---|
| +0x2c | u32 | 4(96f606 字面) |
| +0x30/+0x38 | 2×ptr | **run 列表 begin/end**(0096d094 = [6]!=[7] 非空门;96fb1e 按 0x20 步进走 QList<QArrayData*>,逐元素 +0x18 数据 + +0x10/+0xc 引用计数清偿) |
| +0x40..+0x58 | 4×u64 | 0 |
| +0x60 | u64 | **0x1000000**(96f606 字面;96d022 属性比对辅助面引用) |
| +0x68..+0x68 | u64 | 0 |
| +0x70 | u8 | **自旋锁字节**(0096d0a0/96d620/96d022 首行 0069e8ac 锁 + 尾 `+0x70=0` 解锁) |
| +0x78 | s64 | **脏区 lo**(初 0;96d620 min 更新;**96cef2 复位 = INT64_MAX**;96d0a0 `a1==+0x78` 门) |
| +0x80 | s64 | **脏区 hi**(96d620 max;96cef2 → 0;96d0a0 `+0x80 != a2`) |
| +0x88 | s64 | 游标(96d620 = a1;96cef2 → 0) |
| +0x90..+0xa0 | 3×u64 | 0 |
| +0xa8 | ptr | `operator_new(0x18){回指 this,+0x10:0}`(96f606 尾 + 00970870 面) |

### 1.3 已知锚对账
- FUN_00926ddc(31B)/009e975a(539B)busy 去重腿 = **doc+0xb8 标记引擎对象**,与 eNodes(E+0x2d8)
  **两个载体勿并**(EditorContext.h:472-478 批 115/117 定案在案;92bb20 槽面 0x90..0x200 不含 0x2d8)。
  本侦察将两者边界重申于 Q2。

## Q2 生命周期

- **构造(全懒式,唯一工厂 = FUN_0092b56e)**:kind≠8:92586c 树找首 key≥kind 命中 → 复用;
  未命中 → kind∈[1,4] `operator_new(0x30)`+963590(DocumentTask);否则 `operator_new(0xb0)`+96f606(ScanTask)。
  kind==8:mode∈[9,11] 先 9258b2(doc,8) 找现存 kind-8 → 命中复用;否则 ScanTask(8)+9637b8(mode)。
  插入前 FUN_00939f06(16B,0031.c:190;ref≥2 → 939e7a detach)→ createNode。
- **持有 = E(session/editor ctx)对象**:E+0x2d8 树;伴随面:
  - **E+0x110 = 池 A**(kind∈[1,4] 任务)、**E+0x118 = 池 B**(kind∈[5,8] 任务):engine ctor
    0092a08e..0092a0ee(0030.c:26039-26071)`operator_new(0x10)+QThreadPool::QThreadPool(0)+
    setMaxThreadCount(idealThreadCount)` ×2 —— 我方 ePool 单槽 nullptr(批 69),建模批拆双槽。
  - **E+0x124 = 序列计数**(kind∈[1,4] 取号)、**E+0x128 = stopCount/序列**(0x754d ++ 取号;
    92596c kind∈[5,8] 读它作 task serial —— 同槽两用怪癖,原样登记)。
- **分发 = FUN_0092596c(232B,0030.c:20900)**:9637da(node)门(kind∈[1,4] → 0x28 包装
  9638d2(E,node,*(E+0x124)++)→ 池 A start;kind∈[5,8] → 96d094 非空门 → serial=*(E+0x128)
  → 池 B)。
- **销毁 = 与 doc 锁死**:engine dtor FUN_0092f62e(0030.c:29917;批 128 已登记)→ 92e512
  (=92ba4e+92e44e 全停)→ 树遍历逐值 `**(vptr+8)()` **虚 D1**(Itanium 单独析构,非 deleting)
  → QMapDataBase::freeTree/freeData(kuna 全读 @0x92f62e)。**无独立 delete 权**,节点生存期 ⊂ E。
- **与批 117 busy 判定的边界**:`*(ctx+8)` = doc+0xb8 标记引擎(去重 busy 位 +0xb8/分页表 +0x20
  面,009e975a 读),属 doc 批处理通知器 92bb20 槽族;**eNodes = E+0x2d8 任务树**,两者唯一交集
  是都挂 E、生命周期同锁死于 doc —— 载体、构造点、消费族完全不相交(92bb20 槽面实读无 0x2d8)。

## Q3 应用族消费清单(只列不建模;全 kuna 实读)

| 命令/函数 | 节点消费(字段/函数) |
|---|---|
| **0x75aa**(a282b8→a20680→**930226** 274B,0030.c:30279) | 遍历:939e7a detach→树走→dynamic_cast(4b0→588)→**9635d8(+0x10∈[1,2])**→**96d0a0(+0x78==rs && +0x80!=re 区间门,+0x70 锁)**→9264ba→**96d620(+0x78/+0x80/+0x88 min/max)**→92596c |
| **0x7581** false 腿(**92e5e8** 280B,0030.c:29237;0034.c:5609 调) | 9258b2 找 kind=7 → 空:9264ba+926356(emit cmd 0x3f0)+9263fa+**92e524(同 kind 全清:kind 键匹配→9635d0(+0xc==a2)→虚槽 +8 停→939f20 摘树)**;有:96d022(**+0x30 run 列表逐项 a837f6 属性比对**门)→9264ba→**96fb1e(旧 run 清偿)**→**96f80a(run 插入:+0x30 列表尾插/+0x60 旗位 |= /+0x70 锁)**→96d620→92596c |
| **0x75cb/0x75cc**(9301a8→**92fb40** 634B,0030.c:30038) | 9258b2(doc,**6**,0) kind-6 → 命中:9264ba+92e524(6,0);逐条目:92b56e 懒建 kind-6 → **96f80a** 插 run → 尾 **96d620+92596c** → 9c934e 发布 |
| **0x754d**(92e44e 195B) | ++E+0x128;池 B clear;遍历:**+0x08 kind∈[5,8]** → 9264ba(内含 **9263fa:kind∈[5,7] 换 cmd 0x3f8/0x3f9 emit;9637ea 自旋停机**);waitForDone |
| **0x754e**(92e368 212B) | 遍历:dynamic_cast→**9635d8(+0x10∈[1,2])**→**96cef2({+0x78=MAX,+0x80=0,+0x88=0})**→92596c |
| **0x75cb 旧前腿 0x75c8**(92759a→927558) | 9258b2(doc,6,0) → 92753c→926b1c 入容器(kind-6 查找消费) |
| **0x75f6**(933830 1544B,0030.c:32465) | M+0x2b8 门后:E+0x2d8 **type==8** 遍历(dynamic_cast + +0x08==8)→**96d89e(+0x30 run 列表 → QHash 收集,逐记录 +0x18/+4 计数面)** |
| **0x7545**(933366)③序列化腿 | 节点收集腿 = 933446 门(批次 129 已登记空占位);type-8 树消费同 0x75f6 族 |
| (扩谱参考)0034.c:5684(a284xx) | 9258b2(doc,**5**,0) kind-5 查找 → a283a4 |

共性面(所有应用族共用,**建模价值最高**):
dynamic_cast(0x11ad4b0→0x11ad588)/ 92586c 树找 / 9258b2 kind 查 / 92b56e 懒建 /
9264ba 停广播(9263fa emit + 9637ea 自旋)/ 92e524 同类清 / 96d620·96cef2 脏区 /
96f80a·96fb1e run 灌清 / 92596c 重排(池)/ 9635d8·9635d0·9637da·9637b8 门族。

## Q4 最小建模方案书(照 KitWindowFace 判例;建模车道照此直执)

**判定**:eNodes = 数据承载层(非窗口 face),骨架落 **src/Editor/ENodes.h**(MarkersStore.h
同侧;EditorEngine.cpp 只改 case 腿)。基/派生两级 C++ 继承即可复刻 dynamic_cast 语义
(KitWindow Q3 先例:跨类一致性由同库编译保证,不复刻 TI 地址)。

### 步骤 1:src/Editor/ENodes.h(新;声明壳 + ctor 转写体)

```cpp
#pragma once
#include <QVector>
#include <QtGlobal>
namespace wt {
// ENodeTask — 语料 DocumentTask(TI 0x11ad4b0,0x30B;ctor FUN_00963590 55B 全读)
struct ENodeTask {
    void   *vtbl = nullptr;          // +0x00 cited — 0x11ad4e8(我方读路不经 vt,槽面由成员体承载)
    qint8   kind  = 0;               // +0x08 kind 键值(0x754d [5,8] 门)
    qint32  modeC = 0;               // +0x0c(9637b8 kind==8 腿 = mode;9635d0 ==a2 门)
    quint8  state = 0;               // +0x10 kind∈[5,7]→2;ScanTask 9637b8 重置(1/2);9635d8 门 ∈[1,2]
    quint8  _r11[3] = {};
    quint64 p18 = 0;                 // +0x18 ctor 参(调用面恒 0)
    quint64 p20 = 0;                 // +0x20
    quint32 p24 = 0;                 // +0x24(9637da 分发门 ==0)
    quint8  stopped = 1;             // +0x28 963590 字面 1;9264ba 非零跳;9637ea 置 1;9637da 清 0
    void ctor00963590(qint8 k, quint64 a2) {   // 真身转写(全字面)
        vtbl = nullptr;              // cited — 0x11ad4e8
        kind = k; modeC = 0; state = 0;
        p18 = a2; p20 = 0; p24 = 0; stopped = 1;
        if (quint8(k - 5) < 3) state = 2;      // 963590 尾
    }
};
// ENodeScan — 语料 ScanTask(TI 0x11ad588,0xB0;ctor 96f606=963590+扩展段)
struct ENodeScan : ENodeTask {
    quint32 c2c = 0;                 // +0x2c 96f606 字面 4
    quint8  _r30[4] = {};
    QVector<void*> runs;             // +0x30.. 语料 begin/end QList(0x20 步进记录)→ QVector 承载
                                     //   (96d094 非空门 = !isEmpty;96fb1e 清偿 → clear;怪癖登记)
    quint64 f40 = 0, f48 = 0, f50 = 0, f58 = 0;
    quint64 f60 = 0x1000000;         // +0x60 96f606 字面(96d022 辅助面)
    quint64 f68 = 0;
    quint8  spin = 0;                // +0x70 自旋字节(我方单线程 → 常 0,锁面 cited)
    quint8  _r71[7] = {};
    qint64  dirtyLo = 0;             // +0x78 96d620 min;96cef2 → INT64_MAX
    qint64  dirtyHi = 0;             // +0x80 96d620 max;96cef2 → 0
    qint64  cursor  = 0;             // +0x88
    quint64 f90 = 0, f98 = 0, fa0 = 0;
    void   *inner = nullptr;         // +0xa8 0x18{回指,+0x10:0}+970850 — cited — wave-2(壳期 nullptr)
    void ctor0096f606(qint8 k) {     // 真身转写(字面全读)
        ctor00963590(k, 0);
        c2c = 4;
        runs.clear(); f40 = f48 = f50 = f58 = 0;
        f60 = 0x1000000; f68 = 0; spin = 0;
        dirtyLo = dirtyHi = cursor = 0;
        f90 = f98 = fa0 = 0;
        inner = nullptr;             // operator_new(0x18)+970850 — cited — wave-2
        ctor009637b8(0);             // ⚠ 语料 92b56e 落 kind==8 才调;非 8 不调(见建模细则)
    }
    void ctor009637b8(qint32 mode) { // 9637b8(45B 全读):+0xc=mode;+0x10 分派
        modeC = mode;
        if (quint32(mode - 5) >= 2 && mode != 0xc) state = (mode == 8) ? 2 : 0;
        else state = 1;
    }
};
} // namespace wt
```

车道执行细则:
- **9637b8 的 `(mode==8)?2:0` 分支勘注**:语料 `(a1==8)*'\x02'` → kind 8 且 mode∉[5,6]/≠0xc 时
  state=2;上面括注的 0 为语料字面(非 8 且非 [5,6] 区间)——按字面转写,勿"修"成 1。
- **不加 Q_OBJECT**:节点为纯数据/虚析构对象,无信号槽(坑 14/19 规避);虚 D1 槽由
  `virtual ~ENodeTask()` 承载(销毁面 = engine dtor 遍历逐值 D1,C++ 默认析构链同构)。
- inner(+0xa8)壳期恒 nullptr(970850 词法面 cited — wave-2);runs 的 QList 0x20 记录布局
  我方 QVector<void*> 坍缩(批 127 载体缝同款怪癖登记)。

### 步骤 2:EditorContext.h 接线(两行)

- `QMap<QString, void *> eNodes;` → **`QMap<int, void *> eNodes;`**(键型勘正:语料 key = char
  kind,92b56e `*(char*)(node+0x18)=a1` / 92586c `a1 <= *(char*)(node+0x18)` 实读;QMap<int>
  保序语义同构)。全仓 eNodes 消费 7 处(0x754d/0x754e/0x75aa + cited 壳)键面零依赖 QString →
  改型无涟漪(批 136 建模车道首动作,grep 实证 EditorContext.h:419 单点)。
- `void *ePool = nullptr;`(E+0x118)→ 建模批拆 `ePoolA/ePoolB` 两槽(ctor 证据 0030.c:26039/26051;
  现单槽 nullptr 为批 69 壳,0x754d 池腿未接线故拆分无行为回归)。

### 步骤 3:可转写族清单(建模车道队列;每函数全读在案,免再侦察)

| 波次 | 函数(体积/语料落点) | 去向 |
|---|---|---|
| W1 纯机械门族 | 9635d8(22B)/9635d0(12B)/9637da(30B)/9637b8(45B)/96cef2(30B)/96d094(18B) | ENodes.h inline 成员体 |
| W1 树面 | 92586c(105B,0030.c:20835)/9258b2(185B,0030.c:20859)/92b56e(306B,0030.c:27031) | EditorContext 自由函数(939f06 detach ≈ QMap 写时分离,我方 QMap 坍缩直写) |
| W2 脏区/run 面 | 96d620(57B)/96d0a0(64B)/96f80a(172B,0031.c:44076)/96fb1e(部分已读) | ENodes.h 成员体(runs QVector 承载) |
| W2 应用族 | 9264ba(64B)/9263fa(96B)/926356(73B)/9637ea(自旋)/92e524(138B)/92e368(212B)/92e44e(195B)/930226(274B)/92e5e8(280B) | EditorEngine case 腿(emit 腿 9263fa/926356 = invokeMethod 事件投递 → 委托面,照 SCI 承接惯例) |
| W3 池/重排 | 92596c(232B,0030.c:20900)/9638d2(33B)/DocumentTaskRunner vtable 面 | QRunnable 委托(QThreadPool 真库,外库边界惯例);serial = E+0x124/E+0x128 计数 |
| W4 kind-8 快照 | 96d89e(部分已读)/933830(1544B,0030.c:32465)/92fb40 节点腿(0030.c:30060-30140 已读) | 0x75cb·cc/0x75f6/0x7545 节点腿 cited 摘除 |

**暂缓(如实)**:96d022 的 a837f6 属性比对(体未读,W2 前补读);92601a 投递底座体未读
(9263fa/926356 转写前补);00970870 inner 面(W1 不触)。

### 步骤 4:验证门
`cmake -S . -B build && cmake --build build -j && ctest` 19/19 + dlopen OK;ENodes.h 无
Q_OBJECT → 零 moc 面;markerstest 壳态(eNodes 恒空)全腿同相,现有 19 测试零改。

## 证据索引(免再 grep)

| 项 | 地址 | 落点 |
|---|---|---|
| Map ctor 初始化 | editor_engineCtor 00929bf8 | 0030.c:25941(param_1[0x5b]=shared_null) |
| 键值节点布局 | 92b56e createNode(0x28,8) key=char@+0x18 val@+0x20 | 0030.c:27031 + kuna |
| 树找首 | 92586c 105B | 0030.c:20835 前(kuna @0x92586c) |
| kind 查找(含 k=8 mode 腿) | 9258b2 185B | 0030.c:20859 |
| 懒建工厂 | 92b56e 306B | 0030.c:27031 |
| detach | 939f06 16B / 939e7a | 0031.c:190 / kuna |
| DocumentTask ctor | 963590 55B | kuna @0x963590(0x30B 布局) |
| ScanTask ctor | 96f606 82B(+963590) | kuna @0x96f606(0xB0 布局) |
| kind8 mode 腿 | 9637b8 45B | kuna @0x9637b8 |
| TI/vptr 实读 | Doc 0x11ad4b0/0x11ad4e8;Scan 0x11ad588/0x11ad650;Runner 0x11ad4c0/0x11ad508 | ELF RW 段(file=VA−0x600000),name 串 .rodata(file=VA−0x400000) |
| 遍历应用 | 930226 274B | 0030.c:30279 + kuna |
| kind 清 | 92e524 138B | kuna @0x92e524 |
| 停广播 | 9264ba 64B / 9263fa 96B / 9637ea | kuna |
| emit(0x3f0/0x3f8/0x3f9) | 926356 73B / 9263fa | kuna(cmd 常量字面) |
| 脏区 | 96d620 57B / 96d0a0 64B / 96cef2 30B / 96d094 18B / 96d022(属性门) | kuna |
| run 灌/清 | 96f80a 172B / 96fb1e | 0031.c:44076 / kuna |
| 重排分发 | 92596c 232B / 9638d2 33B(Runnable 0x28) | 0030.c:20900 / kuna |
| 池 ctor ×2 | engine ctor 尾 | 0030.c:26039-26071(E+0x110/E+0x118) |
| stopAll | 92e44e 195B / 92e512 | kuna |
| engine dtor 销毁链 | 92f62e | kuna 全读(逐值虚 D1 + freeTree) |
| 0x75cb 节点腿 | 92fb40 634B | 0030.c:30060-30140 |
| kind-5 消费例 | 0034.c:5684(a284xx) | 0034.c:5684 |

## 未解(如实登记,不猜)
1. **96d022 的 a837f6**(run 记录属性比对)与 **96f80a 尾部 +0x60 旗位精确语义**(+0x61..位
   `v1>>n&1` 链读至 0x64 截断)——W2 转写前补读两体。
2. **92601a 投递底座**(9263fa/926356 共用)体未读:emit cmd 0x3f0/0x3f8/0x3f9 的接收端
   (疑 QObject 队列事件)未定性;委托面选型(invokeMethod vs postEvent)待该体补读后定。
3. **+0x24 的分发面语义**(9637da 读 `==0`):写侧未定位(疑 runner 完成回写),W3 池批补。
4. **inner(+0xa8)/970850** 词法面(W1 不触,持续 cited — wave-2)。
5. kind∈[1,4] 族的**具体命令语义**(margin 族?)仅消费面在案(92596c/0x754e 门),构造面
   调用者清单未全扫(92b56e 全部 xref 未穷举——已知 92e5e8/92fb40/0034.c:5684 三处)。
