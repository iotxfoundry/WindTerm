# Phase 11 — 原版图标取证捕获（真机离屏 + LD_PRELOAD 钩子）

日期：2026-10-22 · 方法：LD_PRELOAD 符号插入（QWidget::show 触发）+ QT_QPA_PLATFORM=offscreen 真程序自截图

## 1. 采集成果（docs/imgs/original/，29 张 + menu-icons/ 10 条）

| 采集物 | 内容 |
|---|---|
| `orig_16_MainWindow.png` | **原版主窗口完整渲染**（本机、NoSessions、dige-black-and-white） |
| `orig_menu_0..9.png` | **全部 10 个菜单弹出态**（含每项图标/快捷键/禁用态） |
| `menu-icons/icons_*.png` | 每菜单左侧图标列裁剪（像素级图标真值） |
| `orig_25_QMenuBar.png`、`orig_12_BreadEdit.png`、`orig_7_AddressBar.png`、`orig_1_KitGroup.png`、`orig_4_TabGroup.png`、`orig_19_StatusBar.png`、`orig_26_TerminalWindow.png`、各 Splitter/TabBar/QToolBar | 原版内部组件逐一渲染图 |

## 2. 结构性新证据（原版真实类名）

截图文件名即原版 QObject 类名：**BreadEdit**（路径面包屑，即我们 AddressBar 的对应物）、**AddressBar**、**KitGroup**、**TabGroup**、**TerminalWindow**、**StatusBar**——可与骨架类名对照校准。

主窗口渲染确认默认布局：左列 `[资源管理器|会话] 标签组 + 文件管理器`（与骨架一致）；无会话时中央空、文件管理器显示"没有可用的文件管理器"；状态栏 就绪 · 日期时间 · WindTerm Issues · 锁屏。

## 3. 菜单图标来源定论（证据链完整）

1. strace：菜单弹出时**零新文件打开** → 非文件
2. zlib 全量扫描：无内嵌压缩资源 → 非内嵌 SVG
3. QAction::icon() 为空 → 图标由**菜单委托(QItemDelegate)在绘制时直接渲染**（内存生成）
4. 像素真值已捕获（menu-icons/）——如需逐个复刻，参照裁剪图绘制即可

## 4. 对骨架的影响

- 保持现状（语义 QPainter 占位 + 文字回退）合理；如需像素级忠实，按 menu-icons/ 裁剪图逐个临摹
- 采集钩子（/tmp/opencode/hook.cpp）可复用：改延时即可抓任意状态的更多组件

## 5. 方法论

LD_PRELOAD 插入 `QWidget::show`（首个 ≥400px 顶层窗口显示时武装 10s 定时器）——避开 exec/show 事件循环插入的崩溃陷阱（见 wt-run*.log 三次失败记录）；抓取走 QWidget::grab（offscreen 平台可用）。
