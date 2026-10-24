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

## 行序与 bars/panes 系统（行序矫正反哺）
| # | 规则 | 证据 | 代码落点 |
|---|---|---|---|
| R24 | 行序：标签条(TabGroup)经 QMainWindow::setMenuWidget **占菜单槽** → 标签行在工具栏行之上；AddressBar 非 pane 子件，是 toolbar_build(0x00694276) 按 toolbar.config 类型码(AddressBar=5)装入 KitBar QToolBar 的构件 | 0x008bade2 / 0x00694276 / toolbar.config | `createCentral` VBox[标签行,KitBar 行,root] |
| R25 | bars/panes 注册系统：registerBarsAndPanes(0x008a1106)=7 bars(Applet/Kit/Menu/Quick/Status/Tool/Transfer)+9 panes(Explorer/Filer/Outline/Output/Sender/Session/Transfer/Search/Shell)；底部命令条=SenderPane（无 SenderBar 类），动作 Window.ShowPaneSender/TogglePaneSender/Dock.TogglePaneSender；TransferBar 懒创建 | 0x008a1106 + wind.actions:2484-2665 | 面板显隐动作映射 |

## 双层 QMainWindow 嵌套（KitGroup 机制反哺）
| # | 规则 | 证据 | 代码落点 |
|---|---|---|---|
| R26 | 主窗=双层 QMainWindow：顶层 KitWindow(menuBar/statusBar/central=root splitter 树) + 中部单元嵌入 **KitGroup(QMainWindow 子类, 0x008bb360)**——其 menuWidget 槽=标签行 TabGroup(**objectName="ViewGroup"** 0x008baf26)、toolBar 区=toolbar_build(0x00694276，Kit/Standard，含 AddressBar)、central=TabGroup 的 QStackedWidget(0x005ab6e8)。QToolBar 只占 KitGroup 宽→地址栏不横跨侧栏 | 0x008bade2 逐条+调用者 0x008bb360 | `KitGroup` 类 / `createCentral` 装配 |
| R27 | 0x007662e6 的 MainWindow=隐藏 quick-switcher 宿主（addToolBar+stack+末尾 hide()），**非可见主窗**——可见树全在 KitWindow 内（修此前误读） | 0x007662e6 末段 hide | 骨架不做 |

## BSim 函数特征匹配（开源参考库管线）
| # | 规则 | 证据 | 代码落点 |
|---|---|---|---|
| R28 | BSim 管线：开源仓库 src（Protocols/Utility/Widgets）qmake 编译带符号 so → import → BSimApply.java add 入 H2 库 → apply（sim≥0.7 sig≥5.0 唯一最佳，前缀 BSim_ 保诚实）→ 运行时 stub 黑名单滤除；单文件 87 签名解锁 1658 名、全量 315 签名累计 1762 净真名（Qt/std 内联同源 + Splitter/Telnet 真身） | libwindtermopen.so 89 符号 + splitter.hdb | tools/BSimApply.java |

## 状态栏 JS 化与 QuickBar 逐行重写（2026-10-23/24 反哺）
| # | 规则 | 证据函数 | 代码落点 |
|---|---|---|---|
| R29 | StatusBar=QStatusBar 子类(objectName StatusBar→注册名 AppletBar)，ctor setSizeGripEnabled(false)+margins(字体pt,0,字体pt,0)；内容=statusbar.config 7 applets 经 QJSEngine 真跑 JS init（populate singleShot(0)→applet_layout_widgets）；button=QToolButton 子类(TextOnly+AutoRaise)、label=QLabel(InteractionFlags 0xf+OpenExternalLinks+PointingHand)、无 objectName、addPermanentWidget(w,0)、常驻消息 label insertPermanentWidget(0,stretch=1) 最左 | 0x005a2d26/0x005a2e58/0x00692766/0x006933ea/0x005a4432/0x005a333e/0x005a3156 | `widgets/StatusBar.{h,cpp}`/`core/ScriptHost.{h,cpp}` |
| R30 | QJSEngine 宿主面：installExtensions(All)+newQMetaObject(King/MuxPane) frozen+newQObject(application/window)+defineProperties(this,{editor,terminal})（global `terminal` 即 window.terminal getter）；runInit="'use strict;'+init"拼接 evaluate→isCallable→newQObject(widget,CppOwnership)→callWithInstance(undefined,[widget])；King.KeyMode 枚举值 Unknown=0/Widget=1/Normal=2/Command=4/Remote=8/Local=16/Any=31（0xccbc40 metaobject 解码） | 0x0064b102/0x0064af3c/0x0064b0d0 | `core/ScriptHost.{h,cpp}` |
| R31 | QuickBar refresh=菜单重建+工具条重建：菜单序=配置动作(king::config)+Quick 组平铺(大小写不敏感,QWidgetAction 包 QLabel 标题 tr("Quick"))+组集合字典序可勾选(setData("group"))；工具条=findChildren<QToolBar*> deleteLater 后按可见组序 buildGroupBar insertWidget；showMultipleGroups=false 可见组截断 list[0]；toggleGroup=清空+append(单组=替换)+checked 同步；buildGroupBar 按 group 全局聚合(线性收集非相邻归并)+组条 windowTitle=组名无 objectName+PM_ToolBarIconSize+TextBesideIcon；单命令 uuid 空 skip、label>18 空格宽×36 ElideMiddle(菜单不截)、tooltip HTML table 4 行(Label/Group/Type/Text) | 0x0056f866/0x0056e540/0x0056e420/0x0056be56/0x0056f476/0x0056f5c5/0x0056f262 | `widgets/QuickBar.{h,cpp}` |
| R32 | quick 执行链在 QuickBar 内聚：QAction::data=uuid→线性扫描配置→type 仅 =="Send Text"(0x6d09f6 唯一枚举)→text 空返回→qstring_unescape(\0 \\ \a \b \cX \f \m \n \r \t \xHH \uXXXX \v，未知=字面字符)→焦点终端写入(0x8cabee/0x8d9764)；右键两项 Modify/Remove(king::close)，删除=0x00570970 删配置+0x00806700 回写+refresh（骨架回写挂账） | 0x0056d890/0x006d09f6/0x007b8726/0x0056a10a/0x00570970 | `widgets/QuickBar.cpp` |

## R33-R37（2026-10-24 补记：popup/reopen.history/SSH/终端渲染/quickbar 管线）
| # | 规则 | 证据 | 代码落点 |
|---|---|---|---|
| R33 | popup 通用机制：pane vtable+0x110 contextMenuEvent→pane_showPopupMenu，节名 `"<objectName 去 Pane> <修饰键>Popup"`；ViewTab Popup=标签条 customContextMenuRequested(0x8ba130)；TabGroup Popup=TabGroupButton 下拉非标签右键(0x8ca002)；工具栏子 widget 装 pane 过滤器(0x8c40a6) | 0x008c3c6a/0x008c3684 | MainWindow showPopupMenu/KitPane |
| R34 | reopen.history：magic 0xB9E7E626(QDataStream 大端 Qt_5_15)+每窗口[geometry/state/maximized]；state=[pageCount/index/pageName+pageBlob]；pageBlob=[innerMagic/docks 多轮连排/right BFS/bars/tail];bars 3×bool=hidden 取反应用(第3字节仅 magic>0x21)；tail=状态栏 message 区；LastSessions 真重连 uuid→user.sessions→按 protocol 建(0x833db4) | 0x005dd560/0x0075ffcc/0x0076073a/0x008cf0c8/0x008d2f7e | core/ReopenHistory/MainWindow |
| R35 | SSH 会话链：QThread+moveToThread worker(00864972)；认证=SshAuthOperator 队列(none 探测→userauth_list 掩码→cfg 入队 Password/PubKey 两步 try→real/KbdInt,0086adc4/00869602)；known_hosts=<profileRoot>/ssh/<id>/known_hosts(opt 8=ssh-dir 语义)；host key 接受=先删旧指纹行再 write(0086410a)；drain 数据泵+poll 就绪探测 | 0x0086597e/0x008689b7/0x006293dc/0x00806382 | core/SshSession |
| R36 | 终端渲染=自研文档引擎（非 cell 网格非 QTextDocument）：VT u64 属性(fg24@bit14/bg24@bit39+bold→bright 自动)→行快照 run styles 入 doc(分块+zstd)→自绘 painter 逐可见行(0xa64cea)+光标覆盖式(0xa64838);滚回=文档历史行(window.scrollbackLimit);字符宽逐字符 horizontalAdvance 缓存 | 0x007ef95c/0x00a40876/0x00a64cea/0x00a52aa8/0x007cc8aa | widgets/TerminalView(自绘网格等效) |
| R37 | 鼠标上报位级方言(0x7ebdfc)：运动恒+32 且后缀 'm' 非 'M'；修饰 Meta=8(Alt 不编码)；滚轮只取符号每事件恒 1 条(delta==0 丢弃)；同格去重；SGR '<%d;%d;%d%c' 坐标 y;x 1 基 | 0x007ebdfc | TerminalView sendMouseEvent/wheelEvent |

| R38 | sftp 通道双约束（实现实证）：sftp_attributes 布局两库一致（mirror+static_assert 自证）；libssh session 非线程安全——后台 sftp 操作必须与主线程事件循环互斥（挂泵护栏），并发踩 packet 链段错 | 0x00627efc 实现/段错实测 | src/core/SshSession.cpp |

| R39 | CommandPalette mode7=palette 文件模式：`global/palettes/*.palette`（{trigger,comment,filterable,events,script}）——trigger（':' goto-line/'=' calculator）即前缀路由 DAT 常量；script(event,filter,selection)=>items[{title,subtitle,icon}] 四事件 enter/filter/commit/leave；filterable=false 时 items 全权 JS；activeText 依赖 API：lineCount/gotoLine/scrollTop(行)/setRegister/getRegister/removeRegister/screenLineCapacity | 0x0053feaa/0x0054334c + palettes 一手文件 | widgets/CommandPalette、TerminalView |
