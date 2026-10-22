# Phase 5 发现 — 图标架构定论 + 菜单组合调查收口

日期：2026-10-22 · 方法：发行包文件比对 + REA/Ghidra 导入表反查（已 close）

## 1. 图标架构定论：动作图标是程序化绘制的

证据链：
1. `wind.actions` 引用 89 个 `king::*` 图标名；发行包全部 SVG 仅 32 个，**交集为 0**
2. 二进制含路径模板 `images/%1.svg`（唯一 svg 相关串）——chrome 类图标（close/checkbox/radiobox/session/logo 等 22-32 个）走文件
3. `icon.theme` 含运行时状态类（`.brushActive` fill `#007acc`）——静态文件无法表达状态着色
4. `colorRed`/`colorGoldenrod` 等 13 个色板"图标"本质是色块绘制

**结论**：`king::*` 是图标**生成器**名（QPainter 绘制原语），样式由 icon.theme CSS 注入；像素级还原则需逐个逆向绘制函数——对"仅界面"骨架不值得，用占位方案（真实 chrome SVG + Qt 标准图标按主题色着色）。

## 2. 菜单组合顺序：调查收口（宣布关闭）

本轮新证据：
- 反查导入表：`QMenuBar::addMenu(QMenu*)` 全二进制**仅 1 个调用点**（0x6931ed）→ 唯一菜单栏构建器 `FUN_00693036`
- 该函数：objectName `"MenuBar"`（与 Bars 注册表一致）→ 调用 70KB 注册表构建器 `FUN_008a1106` → 通用查找迭代器填充
- `wind.actions` 字段仅 `text/script/state/icon/kits`（525/481/289/142/65）——**无菜单结构字段**

**结论**：菜单→动作组合内嵌于二进制注册表构建器的硬编码数据，不在任何数据文件。恢复它需模拟执行 70KB 构建器或逐表读取——骨架已有 9 个正确标题（`(&N)` 模式）+ 526 动作数据加载，组合顺序对"仅界面"无增量价值。**关闭此项。**

## 3. 附带收获

- `kits` 字段（65 个动作）→ KitBar 的分组数据源线索（Phase 3 的 QuickBar/KitBar 内容待用时可查）
- 导入表反查法（objdump -R → PLT → 唯一调用点）比字符串/xref 链更高效，记录备用

## 4. 骨架改造（已派发）

AppletBar 图标占位：按钮图标 = QStyle 标准图标（按语义近似映射：新增→ArrowUp/目录→Dir 等就近分配）+ 主题强调色 `#007acc`；`session.svg`/`logo.svg` 等真实 chrome SVG 名称匹配处优先用文件。

## 5. 未决（全部已定性，无进一步调查计划）

- 图标像素级还原（需逆向 N 个绘制函数，明确不做）
- 菜单组合（已关闭）
- icon.theme SVG 着色、scheme.theme 接入（依赖终端渲染层，不做）
