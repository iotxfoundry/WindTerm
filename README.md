# WindTerm GUI Skeleton

WindTerm 2.7.0 主窗口的 Qt Widgets 界面壳还原：菜单栏、四组停靠面板、彩色会话标签、命令按钮栏与状态栏。
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

资产缺失时 `ThemeManager` 静默跳过，界面仍可正常显示。

## 结构

- `src/MainWindow.*` — 主窗口组装（菜单/停靠/状态栏）
- `src/panes/` — FilerPane、SessionPane、OutlinePane、SenderPane、TransferPane
- `src/widgets/` — MuxPaneGroup、CommandButtonBar
- `src/core/` — ThemeManager、LocaleManager
- `src/dialogs/` — MasterPasswordDialog、SessionSettingsDialog

## 声明

这是界面骨架，仅用于还原布局与外观；不实现任何业务功能。
