# Phase 8 发现 — 面板插入引擎破译（FUN_005a277a）与布局重建方案

日期：2026-10-22 · 方法：反编译引擎全文 + 调用链追踪（REA 已 close）

## 1. 插入引擎语义（反编译全文，非推断）

`FUN_005a277a(anchorChild, …, direction)`——**相对锚点的四方向插入**：

```
direction ∈ {0,1} → 新 splitter 取 Qt::Horizontal（左/右兄弟）
direction ∈ {2,3} → 新 splitter 取 Qt::Vertical（上/下兄弟）
若 anchor 所在 splitter count < 2：直接 setOrientation 到目标方向
若 count ≥ 2 且方向不同：replaceWidget(anchor) → 新建子 splitter → addWidget 再嵌套一层
插入点：direction 偶数=插到 anchor 前(indexOf)，奇数=之后(indexOf+1)
随后 sizes 均分并扣除 handleWidth
```

即经典的**二分停靠算法**：任意面板相对任意锚点向四方向插入，splitter 树随插入动态演化——**静态二进制里不存在固定的"面板→槽位"表**。

## 2. 启动序列为何不可静态恢复

- 引擎唯一显式调用点是 `FUN_008e041e` 薄包装（读 this+0x70 成员）→ 经虚表/JS 桥分发
- `togglePane` 字符串（JS 桥方法名）无静态 xref——方法表运行时构造
- 默认面板来自 `wind.config: startupSessions="LastSessions"` + 用户保存状态（QSplitter::restoreState ×7）
- 用户 profile 不在本机（截图来自工作机），无 saveState 实体可解析

## 3. 布局重建方案（本轮实施）

不再静态摆放——**移植引擎算法 + 复现启动插入序列**：

1. `PaneManager`（移植 FUN_005a277a 语义）：`insert(anchor, pane, direction)`，含自动嵌套与 sizes 均分
2. 默认布局用插入序列复现实机观感（docs/imgs/WindTerm2.7.0.png）：
   1. MuxPaneGroup 为中心锚点
   2. 左侧列(Explorer|Session 标签组) 插到 Mux **左**（dir=0）
   3. FilerPane 插到左侧列 **下**（dir=2）
   4. OutlinePane 插到 Mux **右**（dir=1）后 `hideIndex`（默认隐藏）
   5. 底部五标签组插到 Mux **下**（dir=3）后隐藏（实机默认不可见）
3. 比例用已证实的 [1000,4000,1000] 风格 setSizes（Splitter::showIndex 的 ratio=0.18 与 1/6≈0.167 一致）
4. `Dock.TogglePane*` 语义免费获得：toggle = showIndex/hideIndex

## 4. 证据与边界

- 引擎语义/方向编码/嵌套规则：反编译全文（本轮，确定）
- 插入序列：无静态实体（配置+JS 驱动，确定不存在于二进制）；所用序列为**按引擎语义对实机截图的复现**，与"从截图推算结构"的区别：结构仍来自反汇编的 splitter 骨架与引擎规则，序列只决定运行时演化路径
- 中央 Splitter 骨架（phase7 的 FUN_008cd068 树）保持有效：引擎在其上工作
