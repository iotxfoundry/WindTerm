# Phase 10 发现 — 图标生成器复现验证（动态 strace + 色板模板提取）

日期：2026-10-22 · 方法：**动态 strace 真机离屏运行**（本机 /opt/WindTerm_2.7.0）+ 二进制模板提取（REA 已 close）

## 1. 决定性动态证据（strace 真程序，1278 个 openat）

- 真程序在**本机离屏跑通**（QT_QPA_PLATFORM=offscreen，exit 由 timeout 正常截断）
- 启动期实际加载的图标文件仅 7 个 chrome SVG：button-up/down、close-unactivated、king、session（default 主题）+ radiobox×2（当前主题）
- **king:: 动作图标（add/autoSync/...）零文件加载** —— 与 phase5 静态结论闭环：动作图标 = 编译期 QPainter 生成器，无数据实体

## 2. 色板生成器（colorXXX）**完整复现**

二进制内嵌 3 个 SVG 模板（`%1`=颜色，`%2`=半径/透明度，`%3`=附加元素占位）：

```svg
<svg><rect fill='none' width='418' height='418'/>
  <circle stroke='%1' stroke-width='36' cx='209' cy='209' r='%2'/>%3</svg>      ← 圆环
<svg>…<circle fill='%1' fill-opacity='0.8' stroke='%1' stroke-width='18' …/>…</svg> ← 实心圆
<svg>…<rect fill='%1' fill-opacity='%2' x='103' y='103' width='212' height='212'/></svg> ← 方块
```

已移植为 `src/widgets/SwatchIcons.h`（QPainter 等价实现，418→16 逻辑坐标缩放）：`ring()/filledCircle()/square()`。
**这是首个像素级忠实还原的原版图标生成器**（色板 13 个：colorRed/colorGoldenrod/…）。

## 3. 动态方法沉淀（AGENTS.md 铁律的最佳实践）

QT_QPA_PLATFORM=offscreen + strace -f -e trace=openat 直接跑真程序 = 行为级证据源：
本次一举回答"图标从哪来"（文件 or 代码），无需再静态猜。

## 4. 87 生成器复现的可行性结论

| 路径 | 成本 | 评估 |
|---|---|---|
| 逐个反编译绘制函数 | 87 × 数小时 | 不建议（此前已定性） |
| 真机显示 + 像素裁剪（用户截图/显示环境） | 低 | 可选：从 docs/imgs/WindTerm2.7.0.png 裁剪图标区做像素对照 |
| 语义 QPainter 图标（已实施） | 已完成 | 覆盖日常观感，维持 |

## 5. 边界

- 色板图标接入点：wind.actions 中 `king::colorXXX` 目前未被骨架动作使用（它们是会话树颜色标记的调色板），暂为库函数待用
- chrome SVG（button/close/session/king/radiobox）走文件加载，骨架已覆盖
