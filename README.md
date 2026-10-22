# WindTerm GUI Skeleton

WindTerm 2.7.0 主窗口的 Qt Widgets **界面壳还原**：真实菜单树、Standard 工具栏、嵌套 Splitter 树布局、彩色会话标签、命令按钮栏、主题 QSS 与配色方案、状态栏。
所有交互槽位为空（`Q_UNIMPLEMENTED()`），**不含任何连接、协议、终端或文件传输逻辑**——能看，不连接。

界面由 WindTerm 原版数据文件驱动，与原版数据层同构：

| 数据文件（assets/，见下） | 驱动的界面 | 加载器 |
|---|---|---|
| `uiconfigs/menu.config` | 全部 10 个菜单 + 子菜单/分隔符（Session 21 项、View 23 项…） | `MenuConfig` |
| `uiconfigs/toolbar.config` | Standard 工具栏（新建/断开/重连/地址栏/更多） | `ToolbarConfig` |
| `wind.actions` | 526 个动作的文案与图标名 | `ActionRegistry` |
| `wind.config` | 配置键（主题名、窗口透明度…） | `WindConfig` |
| `themes/<name>/gui.theme` | 完整 QSS 主题（~900 行，`${AppDir}`/`${SystemFonts}` 变量替换） | `ThemeManager` |
| `themes/<name>/scheme.theme` | 编辑器/终端配色（61 样式，Monokai 系） | `SchemeManager` |
| `locales/*.locale` | 1414 条界面文案 | `LocaleManager` |

## 构建

```bash
cmake -B build
cmake --build build -j4
./bin/WindTermGuiSkeleton
```

产物输出到 `bin/`。依赖：CMake >= 3.16、C++17、Qt 5.15（Qt6 亦可构建，自动探测）Widgets。无其他第三方依赖。

自截图：`QT_QPA_PLATFORM=offscreen ./bin/WindTermGuiSkeleton --screenshot /tmp/opencode/skeleton.png`（显示 400ms 后抓图并退出，省略路径则用默认值）。
配置覆盖：若 `~/.wind/profiles/default.v10/user.config` 存在，其键值覆盖 `assets/config/wind.config`（同样是 JSON、容忍 `//` 注释）。

## 资产（不随仓库提交）

主题/文案/配置均来自本机 WindTerm 2.7.0 发行包，由脚本复制为子集（约 6MB+配置）：

```bash
tools/fetch-assets.sh /path/to/WindTerm_2.7.0
```

运行时期望：`assets/themes/<name>/{gui.theme,scheme.theme,icon.theme,images/,fonts/}`、`assets/locales/*.locale`、`assets/config/{wind.config,wind.actions,uiconfigs/*.config}`。资产缺失时静默降级（无主题、无文案查表），界面仍可显示。

## 结构

- `src/MainWindow.*` — 主窗口组装（菜单/工具栏/状态栏）

## 布局

嵌套 Splitter 树：面板由 PaneManager 相对插入引擎布局（移植反编译算法），Dock.TogglePane 真实显隐。
- `src/panes/` — FilerPane、ExplorerPane、SessionPane、OutlinePane、SenderPane、TransferPane、OutputPane、SearchPane、ShellPane
- `src/widgets/` — MuxPaneGroup、AppletBar、ActionIcons.h（图标占位）、Bars.h（7 栏名登记）
- `src/core/` — MenuConfig、ToolbarConfig、ActionRegistry、WindConfig、ThemeManager、SchemeManager、LocaleManager、JsonText
- `src/dialogs/` — MasterPasswordDialog、SessionSettingsDialog
- `docs/` — 调查结论与各阶段发现（可行性、二进制证据、数据文件破译）

## 已知占位（有实证的边界，见 docs/）

- 动作图标：原版为程序化绘制（`king::*` 生成器名，0/89 对应文件），此处用主题 SVG/标准图标占位
- 菜单动作无下拉行为（`Menu` 字段语义未实现）；状态栏 JS（statusbar.config）不执行
- 终端区为只读占位，仅应用 scheme.theme 背景/前景

## 许可与定位

- 本仓库**代码**为独立编写，按 Apache-2.0 提供（与 WindTerm 开源部分许可一致）。
- `assets/` 内的数据文件（主题/文案/配置）**版权归 KingToolbox 所有**，来自 WindTerm 发行包（免费软件，GUI 闭源，见发行包 `license.txt`）。本仓库**不 redistribution** 这些文件——请自行从官方发行包运行 `tools/fetch-assets.sh` 获取。
- 本项目仅用于界面结构学习/参考/二次开发起点，不内嵌、不绕过原版任何保护。商业再发布前请自行确认对 KingToolbox 资产的使用条款。
