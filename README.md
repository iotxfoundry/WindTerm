# WindTerm GUI Skeleton

WindTerm 2.7.0 主窗口的 Qt Widgets 界面壳还原：菜单栏、四组停靠面板、彩色会话标签、命令按钮栏与状态栏。
已按 Phase 2 二进制发现对齐：9 个面板（Filer/Explorer/Session/Outline/Sender/Transfer/Output/Search/Shell）与 `Bars.h` 登记的 7 个栏名（MenuBar/QuickBar/KitBar/ToolBar/AppletBar/StatusBar/TransferBar），
`MainWindow` 采用 `WA_DeleteOnClose`、`application/windowOpacity` 配置与单发定时器延迟恢复布局，菜单文案经 `LocaleManager` 查表。
数据驱动层：`WindConfig` 读取 `assets/config/wind.config`（去 BOM，容忍 `//` 行注释），`ActionRegistry` 宽松解析 `assets/config/wind.actions`（净化字符串内控制字符，失败退化正则）；菜单由 `assets/config/uiconfigs/menu.config` 驱动（`MenuConfig` 按 `Kit` 顺序构建，Action/Separator/子菜单递归，加载失败回退内置 9 菜单）；菜单标题复刻二进制的 `标题 + " (&N)"` 模式（Help 为 0）。
所有交互槽位均为空（`Q_UNIMPLEMENTED()`），**不含任何连接、协议、终端或文件传输逻辑**。

## 构建

```bash
cmake -B build
cmake --build build
./build/WindTermGuiSkeleton
```

依赖：CMake >= 3.16、C++17、Qt 5.15（Widgets）。无其他第三方依赖。

## 资产

主题与界面文案来自 WindTerm 发行包，不随本仓库提交。构建完成后在仓库根目录运行
`tools/fetch-assets.sh`（由他人提供），把主题 `images/` 与 `locales/` 复制到 `assets/`。

运行时期望的目录结构：

```
assets/themes/<theme>/images/*.svg
assets/locales/<locale>.locale
```

资产缺失时 `ThemeManager` 静默跳过，界面仍可正常显示。`ThemeManager` 加载真实 WindTerm 主题 `assets/themes/<name>/gui.theme`（完整 QSS），替换 `${AppDir}`/`${SystemFonts}` 变量后 `setStyleSheet` 应用；主题名取自 `wind.config` 的 `application.themeGui`（默认 `dige-black`）。
AppletBar 按钮图标为占位方案：优先使用主题同名 SVG（`assets/themes/<theme>/images/<name>.svg`，回退 `default/images`），否则按语义映射 Qt 标准图标；真实 `king::*` 图标是程序化绘制的，未逆向。

## 结构

- `src/MainWindow.*` — 主窗口组装（菜单/停靠/状态栏）
- `src/panes/` — FilerPane、ExplorerPane、SessionPane、OutlinePane、SenderPane、TransferPane、OutputPane、SearchPane、ShellPane
- `src/widgets/` — MuxPaneGroup、AppletBar、Bars.h（栏名登记）
- `src/core/` — ThemeManager、LocaleManager
- `src/dialogs/` — MasterPasswordDialog、SessionSettingsDialog

## 声明

这是界面骨架，仅用于还原布局与外观；不实现任何业务功能。
