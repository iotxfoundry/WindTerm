# 界面布局与操作 — 重建 vs 二进制一致性审计（2026-10-23）

方法：重建侧全量读码（MainWindow/widgets/panes/core/assets）对照 `reference/full` 反编译实锤（关键函数 objdump 复核 receiver）。
证据分级：**[实锤]**=反汇编/反编译；**[旁证]**=数据文件交叉。每条附二进制地址。

## 0. 既有认知更正（先读）

| 旧说法 | 实锤更正 |
|---|---|
| `0x8a1106` = "7 栏+9 面板注册表装配" | **`King_title`**：name→`tr(title)` 查找表（16 对：7 bar + 9 pane），零控件创建；调用者全是"setObjectName 后立即 setWindowTitle"的构造（`King::MenuBar 0x693036`、`QuickBar 0x56e26e`、`StatusBar 0x692766`、`KitPane 0x8c3bbe`…）。TSV 已更正。 |
| `0x8bade2` = KitWindow_setupBars | `KitGroup_setupBars`（此前已正名，本轮复核确认）。 |
| "7 个 bar 都挂主窗" | 只有 `MenuBar/StatusBar` 属 KitWindow 体系；`ToolBar` 属 KitGroup；**`KitBar` 是 QuickSwitcher 专用**（`setAllowedAreas(Left|Right)`，`QuickSwitcher_initUi 0x7662e6`）；`AppletBar` 是 **pane 内部条**（`StatusBar` 子类改名，`0x526a7c`→`0x5bf49e`）；`QuickBar/TransferBar` 是 TerminalWindow 底部外层竖 splitter（`+0xc8`）的独立条。 |

## A. 结构性不一致（布局错位）

### A1. 底部区域拓扑错 [实锤 0x85a7a6 / 0x858ff6 / 0x8cd068]
- **二进制**：`+0xc8` 竖 splitter 包住整个中央树，底部按 `[SearchPane, QuickBar, TransferBar]` 顺序 `insertWidget` —— **三条全宽独立条，上下堆叠**；SearchPane 本身就是底部条之一。
- **重建**：`root[1]=BottomPanes(QSplitter Horizontal)`，内部**左右**放 bottomGroup+QuickBar（MainWindow.cpp:404-409,550-559）；且 Search 混在 bottomGroup 5-tab stack（:443-448）。
- **修**：底部改竖排三独立条；SearchPane 移出 5-tab。

### A2. 主窗状态栏命名与内容源双错 [实锤 0x692766 / 0x6933ea / 0x5a4432]
- **二进制**：主窗底栏 = `StatusBar`（objectName `"StatusBar"`），内容 `singleShot(0)` 延迟由 **statusbar.config** 的 7 个 JS applet 生成（模式按钮、Window %1×%2、Ln/Ch、scheme 弹出菜单、2000ms 时钟、Issues 链接、🔒 Lock Screen）。
- **重建**：objectName `"AppletBar"`（MainWindow.cpp:464-487），8 项硬编码（Ready/Remote Mode/静态窗口尺寸/静态行列/主题名/localhost/1000ms 时钟/无图标锁屏）。**AppletBar 之名错置**（那是 pane 内条），statusbar.config 完全未消费。
- **修**：改名 StatusBar；applet_layout_widgets 对接 statusbar.config。

### A3. MenuBarCorner 缺失 [实锤 0x8c9ee4 / 0x8cbffe / 0x85d99e]
- **二进制**：MenuBar 右上角 corner widget（QToolBar objectName `"MenuBarCorner"`）：PaletteButton/FocusModeButton/ManageLayoutButton（+Terminal 版追加 TunnelsButton/XServerButton），king:: 图标。主题 `#MenuBarCorner #FocusModeButton` 等规则佐证。
- **重建**：无。gui.theme 642-647 规则悬空。

### A4. KitGroup 工具栏 objectName 错置 [实锤 0x694276 / 0x8b31b6 / 0x7662e6]
- **二进制**：KitGroup `addToolBar` 的是 `toolbar_build` 产物，objectName **`"ToolBar"`**（title=tr("Standard")）。`KitBar`（objectName `"KitBar"`，Left|Right dock）**只存在于 QuickSwitcher**。
- **重建**：KitGroup 顶工具栏 objectName 命为 `"KitBar"`（MainWindow.cpp:163-167）→ ThemeManager 把主题里 QuickSwitcher 的 `KitBar{}` 规则误配到主窗工具栏。
- **修**：改名 `ToolBar`。

### A5. TabGroup 行组件缺件 [实锤 0x5af896 / 0x5aec28 / 0x8bade2]
- **二进制** TabGroup（QFrame→改名 ViewGroup）行内：`TabScrollLeftButton`(king::arrowLeft) + 自定义 TabBar(ElideMiddle) + `TabScrollRightButton`；`KitGroup_setupBars` 再加 `TabGroupButton`/`TabAddButton`/`TabListButton`(king::listTab)（工厂 0x5acc3e，hover 选中 QTimer 0x5ad4a6，hoverToSelect/showSequenceNumbers 全局设置）。
- **重建**：QTabBar + `+` + `≡`（MuxPaneGroup.cpp:36-79）——缺两枚 scroll 按钮、TabGroupButton、TabListButton；`≡` 是自创 SessionMenuButton（无二进制对应）。
- **修**：按工厂六按钮补齐；TabListButton 走 TabListMenu。

### A6. pane 工具栏缺失 [实锤 0x8c40a6 / 0x8c442e]
- **二进制**：pane 首次 show 时按 **pane 自身 objectName** 读 toolbar.config 同名节（ExplorerPane/FilerPane/OutlinePane/OutputPane/SenderPane/SessionPane 六节）建 pane 内工具栏。
- **重建**：六节零消费（ToolbarConfig.cpp:42-46）；`FilterEdit` 条目类型无解析分支。

### A7. pane objectName/windowTitle 三连缺失 [实锤 0x8c3bbe]
- **二进制**：KitPane 基类构造统一 `setObjectName` → `setWindowIcon(paneIconFactory)` → `setWindowTitle(King_title)`。
- **重建**：SessionPane/OutlinePane/SenderPane/TransferPane/OutputPane/SearchPane/ShellPane **均未 setObjectName**（Pane 清单见 README）→ 主题全部 pane 类规则（ThemeManager 改写为 #objectName 后）不命中，且无窗口标题。

### A8. KitGroup 外层纵向容器缺失 [实锤 0x8cd068]
- **二进制**：`0x60(V)` 纵向包住 `0x48(H)`（KitGroup 容器），再入 `0x58` 主行——KitGroup 上方还预留纵向空间（供 showPane 动态插入）。
- **重建**：CenterColumn 直接 `addWidget(kitGroup)`（MainWindow.cpp:387），少一层。

### A9. TransferBar 缺失 [实锤 0x5858fe / 0x85af56]
- **二进制**：QWidget 子类，CloseButton+OpenButton+TransferLabel，WA_DeleteOnClose，maximumHeight QPropertyAnimation 收展；懒建插入底部。
- **重建**：无此控件（gui.theme 878-880 规则悬空）。

## B. 操作面不一致

| # | 不一致 | 二进制 | 重建 |
|---|---|---|---|
| B1 | 工具栏按钮无下拉 | [实锤 0x694276] type3=QToolButton defaultAction+**可选 popup menu**（toolbar.config `"Menu"` 字段） | ToolbarEntry 无 Menu 成员，字段丢弃（MainWindow.cpp:171-173） |
| B2 | Toggle 无效 | View→Panes 七项 + ToggleMenuBar/StatusBar 均实作（showPane 0x8d0676 / toggleBar 0x85d080） | TogglePaneSearch/ToggleMenuBar/ToggleStatusBar 无分支，点击无效（MainWindow.cpp:275-292） |
| B3 | 底部切页错位 | — | Shell bottomTabIndex=3 落到 Search 页（:287-289 vs :443-448 索引差 1） |
| B4 | Open Recent 空 | menu.config `"Open Rece&nt"` 引用同名节 | 子菜单无 Actions 键→空；独立节 75-81 未挂载 |
| B5 | QuickBar 内容空 | [实锤 0x56e420/0x56e540] quickbar.showCommandsInOrder/showGroupTitle/showMultipleGroups + CTerminalConfig+0xd8 quick.group/uuid/type/text；布局 [QuickButton,分组ActionButton,ConfigButton,CloseButton] 右对齐 | 空态占位（挂账 0x56e420） |
| B6 | 启动会话 | wind.config `terminal.startupSessions=LastSessions` | 代码未读该键，注释断言 NoSessions（MuxPaneGroup.cpp:86） |
| B7 | 地址栏 | toolbar.config AddressBar 类型（toolbar_build 分发中位置未确证） | QLineEdit+内联 QSS 近似（放行，见 §D） |

## C. 主题/卫生

- **C1** 主题 `MuxPaneGroup > TabGroup` 规则永不命中：重建 MuxPaneGroup 内无 TabGroup 类子件（QTabBar 裸放）——A5 补齐后自然修复。
- **C2** 图标 16px 渲染 vs 主题 `qproperty-iconSize:20px`（dige-black:599-601）。
- **C3** `Bars.h` 常量零引用（死文件）；`MuxPaneGroup::addPane` 定义未调用（openSession 复制逻辑）。
- **C4** gui.theme 行号注释过期 8 处（MainWindow.cpp:76,164,177,466；ExplorerPane.cpp:14；TerminalView.cpp:102）。
- **C5** statusbar.config/session.config/triggers.config 三个 uiconfigs 文件零消费（session/triggers 属操作面挂账，不计入本轮）。

## D. 放行（近似正确，不修）

- 1:4:1 主行尺寸 `{1000,4000,1000}`、`0x68=[4000,2000]` ✓ 与 0x8cd068 setSizes 一致。
- 菜单 10 项结构与 menu.config "Kit" 一致 ✓；type0=Separator 原版即无标签 ✓。
- AddressBarEdit（B7）：二进制 toolbar_build 分发未含 AddressBar 类型实锤，保留近似。

## 修复优先级建议

1. **A2**（状态栏）+**B3**（切页错位）——用户可见行为错误，代价小。
2. **A1+A9+B5**（底部三条+QuickBar/TransferBar 内容）——布局大项。
3. **A4+A7**（objectName 批量更正）——主题命中的根，一次 rename 解决。
4. **A3+A5+A6**（MenuBarCorner/TabGroup 行/pane 工具栏）——增量组件。
5. B1/B2/B4/B6 随对应 F 阶段实现。
