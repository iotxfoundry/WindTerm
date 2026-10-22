# Phase 2 发现 — 二进制恢复的窗口结构事实

日期：2026-10-22 · 方法：REA/Ghidra 12.1.4，RTTI→vtable→构造函数链 + 字符串注册表提取
二进制：sha256 `9491b87e…` · Evidence：本次会话（已 close）

## 1. 应用命名空间与类注册表

- **应用命名空间：`king`**（字符串 `king::gotoFiler` 可见）

### 主窗口栏注册表（FUN_008a1106，70KB 伪代码，7 个栏）
`MenuBar` `QuickBar` `KitBar` `ToolBar` `AppletBar` `StatusBar` `TransferBar`

### 主窗口面板注册表（同函数，9 个面板）
`ExplorerPane` `FilerPane` `OutlinePane` `OutputPane` `SenderPane` `SessionPane` `TransferPane` `SearchPane` `ShellPane`

→ 与截图对照：左=FilerPane/ExplorerPane，右=SessionPane+OutlinePane，底部标签组=SenderPane/TransferPane/OutputPane/SearchPane/ShellPane，顶部第二行=ToolBar，快捷按钮组=AppletBar（即骨架中的 CommandButtonBar，需更名）。

## 2. MainWindow 构造函数实测（0x768f44，C1；0x76bffc 为 C2）

```
MainWindow::MainWindow(QWidget*, Qt::WindowFlags):
  1. QMainWindow 基类构造
  2. 双 vtable 初始化（0x11a69f8 主 + 0x11a6bb0 次 → 有第二基类/接口）
  3. 读配置 "application.windowOpacity"，(0,1) 区间内则 setWindowOpacity
  4. setAttribute(Qt::WA_DeleteOnClose)        // 0x37
  5. FUN_00768cb6：创建 QTimer 并 connect timeout→FUN_00767195
     （延迟初始化：真正的会话恢复/加载在定时器回调，不在构造函数）
```

**对骨架的含义**：
- 构造保持薄：布局初始化 + 单发 QTimer 延迟"恢复布局/会话"占位
- 配置读取模式：`application.windowOpacity` 键名风格 `application.*` / `FilerPane.*`
- `WA_DeleteOnClose` 应设置

## 3. 其他可恢复事实（字符串证据）

| 事实 | 证据字符串 |
|---|---|
| 类 | `OutlineTree`（typeinfo 名）、`FilerButton` |
| 配置键 | `application.windowOpacity`、`FilerPane.AutoSyncTerminalFolder`、`FilerPane.SyncTerminalFolder`、`FilerPane.CopyDirectoryPathToTerminal` |
| 信号 | `highlightOutlineRequested`、`schemeOutlineChanged` |
| 方法 | `MainWindow::loadHistory(uint, const QByteArray&, int, lambda)` |
| 设置中心 | AppletBar/KitBar/… 每项配 QObject::tr() 标题（设置对话框的显示/隐藏栏来源） |

## 4. 未能恢复 / 留待 Phase 3

- 菜单结构未走字符串 route：菜单标题带编号（截图 `Session (1)`），由代码拼接，需后续对 QMenuBar::addMenu 调用点做调用图分析
- qss/样式为代码拼接，未提取
- 第二基类身份（0x11a6bb0 次级 vtable）未解析

## 5. 骨架 Phase-2 修改清单（已交 fixer 执行）

1. 补齐缺失面板：`ExplorerPane` `OutputPane` `SearchPane` `ShellPane`
2. `CommandButtonBar` → `AppletBar`（原名）；新增 `QuickBar`/`KitBar`/`ToolBar`/`TransferBar` 占位（可先常量表登记）
3. MainWindow 模式对齐：`WA_DeleteOnClose` + `application.windowOpacity` 读取 + 单发 QTimer 延迟恢复占位
4. 菜单文案走 `LocaleManager`（zh-CN 验证）
