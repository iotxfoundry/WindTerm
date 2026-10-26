# Phase 7 发现 — 布局模型证伪与真实 Splitter 树还原（反汇编级）

日期：2026-10-22 · 方法：开源源码比对 + 导入表分析 + PLT 反查 + 反汇编归属还原（REA 已 close）

## 1. 布局模型证伪：不是 QDockWidget，是嵌套 QSplitter

- 二进制导入表 **零** `addDockWidget/splitDockWidget/tabifyDockWidget`，仅 `QSplitter::saveState/restoreState/setSizes/…`
- 部分开源源码 `src/Widgets/Splitter.{h,cpp}`（Apache-2.0，可直接采用）证实：`Splitter : QSplitter`，`SPLITTER_RATIO` 属性 + `showIndex/hideIndex` 比例显隐（默认 0.18），`m_mainIndex` 主面板索引
- 此前骨架用 QDockWidget 组装 = **模型性错误**，本轮重写

## 2. 中央区装配函数反汇编还原（FUN_008cd068，调 QMainWindow::setCentralWidget）

逐条 `mov rsi/rdi` 归属还原（非伪代码推断）：

```
对象：+0x38/+0x40/+0x48/+0x50 = 裸 QSplitter（0x30 字节）
     +0x58/+0x60/+0x68 = 0x38 字节对象 = 开源 Splitter 子类（多 m_mainIndex）
       └ FUN_005a1c6c(+0x58, 1) ≡ setMainIndex(1)——中央列是主面板

setOrientation：+0x38=V  +0x40=V  +0x60=V  +0x68=V；+0x48 未设（默认 H）+ setChildrenCollapsible(false)

树（addWidget 归属逐条还原）：
root(+0x68 V)
 ├ col(+0x58 V, mainIndex=1)   setSizes=[1000,4000,1000]   → 1:4:1
 │   ├ leftCol(+0x38 V)          ← 面板运行时插入（Explorer/Filer/Session…）
 │   ├ center(+0x60 V)  [4000,2000]
 │   │   └ +0x48 (H, 不折叠)      ← 中央终端区（MuxPaneGroup）
 │   └ rightCol(+0x40 V)          ← Outline 等
 └ bottom(+0x50 H)                ← 底部条（Sender/Transfer 组）
```

- **[1000,4000,1000] 与实机截图左/中/右比例 1:4:1 精确吻合**（布局不再依赖截图，比例是反汇编出来的）
- 三个 Splitter 的 `splitterMoved` → FUN_008d5e00（移动分割条即持久化；对应 QSplitter::restoreState ×7 调用点）
- 布局持久化：saveState/restoreState，恢复 7 个 splitter 的状态
- 面板插入是运行时的：FUN_005a277a（引擎：insertWidget/replaceWidget/showIndex/hideIndex）——与 wind.actions 的 `Dock.TogglePane*` 动作对应

## 3. 其余装配函数（14 个 addWidget 站点归属）

每个区域有自己的装配函数（0x5a277a=面板引擎、0x5e97fa/0x5e9dce、0x735a0c、0x8cd068=中央、0x8d03ea/0x8d2f7e/0x8d3e3c=底/右列区）——与数据驱动架构一致，无需逐个还原：静态骨架已由 FUN_008cd068 唯一确定。

## 4. 骨架重写（已派发）

1. **Vendor 开源 Splitter.{h,cpp}**（原样复制自 WindTerm/src/Widgets，Apache-2.0）
2. 删除全部 QDockWidget 结构 → 按上述树用 Splitter 重组：leftCol=[Tab(Explorer|Session), Filer]、center=[MuxPaneGroup]、rightCol=[Outline]、bottom=[Sender/Transfer/Output/Search/Shell 五标签]
3. setSizes 1000/4000/1000 与 4000/2000、setMainIndex(1)、setChildrenCollapsible(false) 一一对齐
4. splitterMoved → QSettings 保存 saveState，启动时 restore（对齐 restoreState 语义）

## 5. 方法论沉淀

- 布局还原的正道：**导入表 → PLT → 调用点 → 反汇编 mov rdi/rsi 归属**，伪代码仅作导航（Ghidra 伪代码会丢 this 参数导致树归属歧义）
- 截图只用于验收对照，不用于推算结构（本轮 [1000,4000,1000] 与截图 1:4:1 巧合互证，但来源是反汇编）
