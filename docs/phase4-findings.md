# Phase 4 发现 — 主题即 QSS 文件（修正 Phase 3 §3 结论）

日期：2026-10-22 · 方法：发行包数据文件分析 + REA 复核（已 close）

## 1. 关键修正：qss 在主题文件里，不在二进制里

Phase 3 §3 结论"不是 qss 驱动"**不成立**。事实：
- 二进制确实无 qss 模板字符串（该观察正确）
- 但 qss 以**主题文件**形式随发行包分发：`global/themes/<name>/gui.theme` 就是完整 Qt 样式表

## 2. 主题文件结构

| 文件 | 内容 |
|---|---|
| `gui.theme` | 完整 QSS：`ApplicationPalette { qproperty-link: … }` + 全控件规则（~900 行） |
| `icon.theme` | SVG 图标着色 CSS（`.brush/.pen/.brushActive` 类 → fill/stroke 色值） |
| `scheme.theme` | 编辑器/终端语法配色 JSON（Monokai 系，`fold.error #FF0000`…） |

- 主题三套：`dige-white`（896 行）、`dige-black`（905 行）、`dige-black-and-white`（893 行）
- `default/` 无 gui.theme——纯图标/字体/音效资产层
- `wind.config` 默认 `application.themeGui: "dige-black"`（与发行包默认一致）

## 3. 色值直接可用（无需逆向）

dige-black 主色（gui.theme 实测）：
- 背景 `#1c1c1c`，前景 `#bbbbbb`，强调/链接 `#007acc`，选中 `#333333`/`#80333333`，占位 `#444444`
- 变量替换仅两个：`${AppDir}`、`${SystemFonts}`

## 4. 图标系统

- 动作图标名 87 个（`king::add`、`king::autoSyncTerminalFolder`、`king::colorXXX` 色板…）
- SVG 实体在 `themes/<name>/images/*.svg`（default 23 个）+ `icon.theme` 着色规则
- `wind.actions` 的 `"icon"` 字段与上述名称对应

## 5. 骨架改造清单（已派发）

1. `ThemeManager` v2：读 `assets/themes/<name>/gui.theme` → 变量替换（`${AppDir}/global/themes` → `assets/themes` 映射到仓库布局；`${SystemFonts}` → 系统字体）→ `QApplication::setStyleSheet`
2. 主题名从 `WindConfig("application.themeGui")` 读取（真实默认 dige-black）
3. `fetch-assets.sh` 增拷三套 `*.theme`
4. 验证：离屏运行后 `QApplication::styleSheet()` 含 `#1c1c1c`、无 `${` 残留

## 6. 未决

- icon.theme 着色需要 QtSvg 运行时插件（开发环境系统 Qt 自带；交付部署时需附带）
- scheme.theme（终端/编辑器语法配色）骨架暂不接（无终端渲染层）
