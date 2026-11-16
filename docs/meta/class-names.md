# 类名与二进制的一致性审计

> **结论先行**:二进制里 **不存在 `Face` 这个词**(`strings -a WindTerm | grep -c Face` = 0)。
> `*Face` 是**我方的重建命名空间后缀**,不是原版类名。
> 去掉 `Face` 后,63/87 与二进制的 RTTI 类名**逐字符相同** —— 即后缀是我们加的,
> 基名是真实的。另有 24 个基名在二进制里找不到,其中 3 个已证实是**重复建模**。

## 1. 判定方法(可复现)

Qt/C++ 的类名在 stripped 二进制里仍有两条留存路径:

| 路径 | 覆盖 | 取法 |
|---|---|---|
| **moc QMetaObject** | 210 个带 `Q_OBJECT` 的类 | `tools/re/qmo_extract.py WindTerm --json` |
| **RTTI typeinfo** | **380 个多态类**(含无 `Q_OBJECT` 的) | vtable[1] → typeinfo+8 → `"<len><Name>"` |
| 成员函数名 | **只有 moc 信号/槽**;普通成员函数名已彻底剥离 | 同上,`qmo_extract` 的方法表 |

RTTI 链:ctor 写 `vptr` → `vptr-8` 是 `&typeinfo` → `typeinfo+8` 是名字串。
工具:`tools/re/vtable_scan.py`(本次新增)。

```bash
tools/re/vtable_scan.py WindTerm                    # 715 条 vtable → 类名
tools/re/vtable_scan.py WindTerm --vtable 0x11a2788 # 查单个 vtable
tools/re/vtable_scan.py WindTerm --addr 0x6b35a6    # 查某个 ctor 写的是哪个 vtable
```

产物:`tools/re/data/rtti_classes.txt`(380 真名)、`tools/re/data/vtable_map.txt`(715 条)。

## 2. 我方 166 个具名类的归属

| 判定 | 数量 | 含义 |
|---|---|---|
| **A 精确命中** | 48 | 我方类名 = 二进制 RTTI 名,一字不差 |
| **B 基名命中 + Face 后缀** | 63 | 真类名 + 我方后缀 |
| **C Face 基名不命中** | 24 | 名字无二进制证据(见 §3) |
| **D 非 Face 且不命中** | 31 | 多为组件/内部拆分(见 §4) |

**A 精确命中(48)**:`ApplicationTheme, CTerminalConfig, EditorWindow, FilerPane, JsEngine, KitBar, MuxPane, MuxPaneGroup, MuxWindow, OutputPane, PopupWidget, ProxyCommandSocket, QJSValue, ScintillaEditBase, ScrollBar, SerialBridge, SerialCommander, SerialSession, SessionLogger, SessionPane, ShellBridge, ShellCommander, ShellProcess, ShellSession, Splitter, SplitterGroup, SshBridge, SshCommander, SshSession, SuperBridge, SuperCommander, SuperKeymap, SuperSession, TabBar, TabGroup, TcpBridge, TcpCommander, TcpSession, TelnetCommander, TelnetProtocol, TelnetSession, TerminalView, TerminalWidget, TerminalWindow, TextEdit, TextView, TransferPane, UnixPty

**B 基名命中(63)**:`AddressBar, BreadCrumb, CEditorConfig, CGlobalConfig, CTerminalConfig, CaptureGroupsButton, CheckList, ColorButton, CustomLinkTriggerPage, CustomMenuTriggerPage, DefaultEditorDialog, EditorWindow, EnvironmentDialog, ExplorerList, FilterEdit, FocusModeDialog, HighlightTextBarAction, HighlightTextDialog, HighlightTextTriggerPage, InsertFileDialog, KitDock, KitWindow, LogDialog, LoginWizard, MainWindow, MarkStyleWidget, MasterPasswordDialog, MessageBar, NameDialog, OneKeyDialog, PasswordDialog, PasteDialog, PlaySoundDialog, PlaySoundTriggerPage, ProfileDialog, RemoteFileDialog, RunCommandTriggerPage, RunToolDialog, SearchEdit, SearchEngineDialog, SendTextTriggerPage, SessionDialog, SessionGroupDialog, SessionTriggerDialog, SettingDialog, SharedConfigHandler, ShowTooltipTriggerPage, SlipButton, StatusBar, SuperApplication, SyncInputDialog, TableItemDialog, TerminalWindow, TextMarkDialog, TextMarkTablePanel, TransferBar, TriggerActionDialog, TriggerActionEditPanel, TriggerActionWidget, TriggerDialog, TriggerPage, TunnelDialog, WindowOpacityDialog`

## 3. C 类:24 个无二进制证据的 Face 类

去后缀后的基名在 380 个 RTTI 名里**查无此名**。分三种成因:

### 3.1 已证实重复建模(3 处,应合并)

| 我方类 | 实际二进制类 | 证据 |
|---|---|---|
| `EnvDialogFace` | **EnvironmentDialog** | `FUN_0075d6e8` 是对话框公共腿;`EnvironmentDialogFace` 已用 ctor `FUN_006b35a6`(vtable `0x11a2788` → typeinfo `17EnvironmentDialog`)完整建模。前者是批 313 的局部件,批 429 找到 ctor 后未合并 |
| `SettingsFace` | **TextMarkDialog**(壳 ctor) | `FUN_006f1036` 同时被 `SettingsFace` 与 `TextMarkDialogFace` 实现(需人工裁定归属) |
| `SettingsPageFace` ↔ `TunnelDialogFace` | 归属错案 | 共引 `0056672a/006a4d90/0072bf8a/0072d0f2/0072edfe`,已登记 `docs/pending-attribution.md` §1 |

### 3.1b 同名双建:真类与 Face 壳并存(3 处,应合并)

同一个二进制类被我方建了**两个 C++ 类**(一个用真名,一个加 `Face`):

| 真名类 | 并存的 Face 壳 | 说明 |
|---|---|---|
| `CTerminalConfig`(`src/Editor/CTerminalConfig.h`) | `CTerminalConfigFace`(`src/Editor/CGlobalConfigFace.h`) | 壳是单例子对象,注释自述"合一后由 `CTerminalConfig::face()` 承载" |
| `EditorWindow`(`src/Widgets/EditorWindow.h`) | `EditorWindowFace`(`src/Actions/KitWindowFactory.h`) | 壳只做基类构造 + `setObjectName("EditorWindow")` |
| `TerminalWindow`(`src/Widgets/TerminalWindow.h`) | `TerminalWindowFace`(`src/Actions/KitWindowFactory.h`) | 同上 + 原生事件过滤器 |

> 收尾期编译前必须二选一;否则同一 vtable/ctor 有两份实现,`--as-needed` 不报错但行为会分叉。

### 3.2 伞形/装配容器名(我方为组织代码而设,非原版类)

`ActionRegistryFace`(同文件里真正的类是 `HighlightTextBarActionFace`)、
`SettingsPageFace`、`KitWindowAssemblyFace`、`CGlobalConfigFace`(基名其实命中)、
`DeepEngineFace`、`TriggerPageStackFace`、`TermViewFace`(真名 **TerminalView**)、
`SearchPanelFace`(真名 **SearchPane**?)

### 3.3 无定论(待核)

`ActionButtonFace, ActionToolBarFace, BackwardShortcutFace, CloseButtonFace, CompleterButtonFace, CountSpinboxFace, CrumbEditFace, CursorShapeFace, ExpandButtonFace, ExpandToggleFace, ExpectDialogFace, HelpDialogFace, PasteSettingsPageFace, ProfileDirDialogFace, SessionProtocolFace, TransferAskFace, TriggerTableWidgetFace`

## 4. D 类:31 个非 Face 且不命中的类

**组件/工具库(本来就没有原版类名对应,属正常)**:
`CircularBuffer` `Cryptographic` `ScopeGuard` `SpinMutex` `ThreadLocker` `ThreadLocal`
`ThreadLocalWatcher` `Int64CircularBuffer` `Pty` `ConPty` `WinPty` `PipeThread`
`Protocol` `CodecMemo` `LoaderResult` `MuxPaneJs`

**我方对一个原版类做的内部拆分(结构性偏离,需在文档标注)**:
`Screen`(→ 二进制 **SuperTerm**)、`EditorContext`(→ **Editor**)、
`TerminalCore`、`EditorEngine`、`SuperSessionPrivate`、`SessionManager`、
`SessionTransfer`、`TelnetBridge`、`ViewBase`、`MuxPaneView`、`FileOps`、
`KeymapEngine` `ProfileLoader` `ActionFactory` `GrepNeedle448`

> 这类拆分本身可用,但**必须写明映射**,否则"每行有出处"在类粒度上失效。

## 5. 命名政策(建议)

1. **`Face` 定义为"重建件标记"**,写进 `src/README.md` 与 `AGENTS.md`:
   凡 `*Face` = 我方在 `src/` 里承接口语料函数体的类,**不是**二进制类名;
   去后缀后若命中本文件 §2-B,则该基名即二进制真名。
2. **A/B 两类保持不变**(基名已与二进制一致,改后缀纯属churn)。
3. **§3.1 / §3.1b 六处重复/双建必须先清**(收尾期编译前,否则同一 ctor 两份定义)。
4. 新增类时:**先在 `tools/re/data/rtti_classes.txt` 里查**,命中就用真名(+`Face`
   与否按仓库惯例);不命中则必须在头注释写"无 RTTI 对应"。
5. 每批收尾可跑一遍本审计脚本,防止新造的类名悄悄偏离。

## 6. 已知局限

- **普通成员函数名不可验证**:stripped 后只留 moc 信号/槽名;非槽成员只能按
  vtable 槽位语义命名,属推断。
- 无 `Q_OBJECT` 且非多态(无 vtable)的辅助类**完全没有名字痕迹**。
- 380 个 RTTI 名包含 STL/Qt 依赖类;本表只用于比对,不代表都要建模。
