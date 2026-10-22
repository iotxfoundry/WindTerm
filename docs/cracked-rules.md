# 破解规则汇总（cracked-rules）

每条规则 = 反汇编证据 → 应用落点。细则见 `docs/phase*.md`，原始反编译在 `reference/asm/`。

## 界面结构
| # | 规则 | 证据函数 | 代码落点 |
|---|---|---|---|
| R1 | 中央区 = 嵌套 QSplitter（非 QDockWidget）：root(V)[col(V 1:4:1 bands), bottom(H)] | `FUN_008cd068` | `MainWindow::createCentral` |
| R2 | 面板插入 = 相对锚点四方向 + 自动嵌套（dir<2→H，≥2→V） | `FUN_005a277a` | `PaneManager::insert` |
| R3 | 栏注册表 7 项 / 面板注册表 9 项 | `FUN_008a1106` | `Bars.h`、9 个 Pane 类 |
| R4 | MenuBar objectName="MenuBar"，注册表驱动 | `FUN_00693036` | `MainWindow` |

## 配置与主题
| # | 规则 | 证据 | 代码落点 |
|---|---|---|---|
| R5 | 构造顺序：windowOpacity→WA_DeleteOnClose→延迟恢复(QTimer 单发) | `FUN_00768f44` | `MainWindow` ctor |
| R6 | 配置键 `application.windowOpacity` 经 config 单例读取 | 同上 | `WindConfig` |
| R7 | 菜单图标色 = 主题 icon.theme `.pixmap .pen stroke`（浅壳 black/暗壳 #A1A1A1/激活 #007acc） | icon.theme 数据 + strace | `ActionIcons::themeIconColor` |

## 图标系统
| # | 规则 | 证据 | 代码落点 |
|---|---|---|---|
| R8 | king.svg 精灵表 302 元素，id=king:: 名；icon.theme 为其 CSS | king.svg + strace | `KingIcons` |
| R9 | 工厂：QSvgRenderer(elementExists→boundsOnElement→render)，未给尺寸默认 0x20=32 | `FUN_007572ac` | `KingIcons::icon` |
| R10 | 面板图标 `king::%1`，名字 toLower，Pane 后缀特判 | `FUN_0089e584` | phase10 记录 |
| R11 | 无 icon 字段动作 = 纯文字（原版无图标） | orig_menu_0 像素统计 | `makeAction` |

## 快捷键
| # | 规则 | 证据 | 代码落点 |
|---|---|---|---|
| R12 | keymaps 按动作 id 查绑定，按【焦点部件 keyMode】过滤 modes 后 setShortcut | `FUN_006a872d`/`FUN_008cb962` | `KeymapConfig`+`makeAction` |
| R13 | 显示规则：空 modes=全局；否则须含 `remote`；滤 Meta；同 id 取最后条 | keymaps 数据 7 样本 | 同上 |
| R14 | 菜单条目助记符显示为 `(X)` 后缀（CJK） | orig_menu_0 | `displayActionText` |

## 文案
| # | 规则 | 证据 | 代码落点 |
|---|---|---|---|
| R15 | 动作文本 = locale 查表（键=EN 去尾部 `...`）；CJK 下补 `(X)` 助记符 | zh-CN.locale + orig_menu_0 | `makeAction` |

## 主题与对象树（界面还原反哺）
| # | 规则 | 证据 | 代码落点 |
|---|---|---|---|
| R16 | 主题三件套：`global/themes/<名>/{gui.theme(QSS 893行), scheme.theme(61键配色JSON), icon.theme}`；profile `application.themeGui/themeText` 选主题；用户实机=dige-black-and-white（GUI 浅 + 终端 Monokai #272822） | `/opt/WindTerm_2.7.0/global/themes/*` + `~/.wind/profiles` | `ThemeManager`/`SchemeManager` |
| R17 | QSS 类型选择器只匹配 C++ 类名——原版自定义类（TabGroup/KitBar/TextView/AppletBar/MuxPane…）是真实子类；骨架以 objectName 挂名时需把选择器改写为 `#名` 才命中 | Qt5 探针实测 + 反编译对象树 | `ThemeManager::apply()` 改写层 |
| R18 | gui.theme 类名 ↔ setObjectName 对照（50 点）已回填 symbols.tsv：`Theme_loadGuiTheme`(0x007563c0)、`Scheme_loadSchemeTheme`(0x00752c8e)、`TabGroup_initUi`(0x005af896)、`KitBar_ctor`(0x008b31b6)、`TextView_ctor`(0x005c6d16)、`BreadButton_setTypeProperty`(0x0054c8b8) 等 | explorer 对象树查证（rg 类名字面量→宿主函数） | `reference/symbols.tsv` 反哺节 |
| R19 | 终端配色链：scheme.theme `terminal.ansi*` 16 色 + `line.background` 终端底 + `margin.number`(#2B91AF)/`margin.timestamp`(gray)；字体 = wind.config `text.fontFamily1/fontSize` | dige-black-and-white/scheme.theme + wind.config | `ScreenModel::color256`/`TerminalView` |

## 排版树（0x008cd068 布局还原反哺）
| # | 规则 | 证据 | 代码落点 |
|---|---|---|---|
| R20 | 中央区树：root V [col, bottom] 2:1；col H [left V, center V, right V] 1:4:1；center V [muxRow H(collapsible✕)] 2:1。setOrientation(2) 仅 0x38/0x40/0x60/0x68——0x58(col)/0x50(bottom) 未设=默认 H。全树零 margins/spacing/stretch/handleWidth | `King::assembleCentralSplitters`(0x008cd068) 逐条 | `MainWindow::createCentral` 显式树 |
| R21 | 面板插入均分：count>1 时按 size/count setSizes（非固定像素）；初始 setSizes 在空树设置、插入覆盖 | 0x008d03ea | `PaneManager::insert`（运行时路径） |
| R22 | AppletBar=QStatusBar 子类经 setStatusBar 装入（非 splitter 子件）；MuxPaneGroup/TabGroup/MuxPane 布局全部 margins=0 spacing=0，TabGroup sizePolicy hExpanding/vFixed，高度由 QSS QTabBar::tab 定 | 0x008c9f8c / 0x008de936 / 0x005aec28 | `MainWindow::statusBar()` / `MuxPaneGroup` |
| R23 | 菜单图标列：原版无 QProxyStyle/PM 覆盖痕迹（rg 0 命中）→ Qt 默认 PM_SmallIconSize(16)；King::iconFactory(0x007572ac) 渲染 rect 由动态调用方传入，静态调用图不可达（挂账） | rg + 0x007572ac 无静态调用点 | `ActionIcons::iconFor`(16) |
