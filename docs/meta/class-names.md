# 类名与二进制的一致性审计

> **结论先行**:二进制里 **不存在 `Face` 这个词**(`strings -a WindTerm | grep -c Face` = 0)。
> `*Face` 是**我方的重建命名空间后缀**,不是原版类名。
> 去掉 `Face` 后,63/87 与二进制的 RTTI 类名**逐字符相同** —— 即后缀是我们加的,
> 基名是真实的。另有 24 个基名在二进制里找不到,其中 3 个已证实是**重复建模**。

> **本文是 2026-11-16 的快照**:§2 的 A/B/C/D 计数会随新增类漂移。
> 现行分类计数以 `python3 tools/re/coverage.py --audit` 为准;类名清单本身
> (380 个 RTTI 名 / 715 条 vtable)由 `vtable_scan.py` 与
> `tools/re/data/rtti_classes.txt` 再生,不随批次变。

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

## 2. 我方 162 个具名类的归属

| 判定 | 数量 | 含义 |
|---|---|---|
| **A 精确命中** | 46 | 我方类名 = 二进制 RTTI 名,一字不差 |
| **B 基名命中 + Face 后缀** | 63 | 真类名 + 我方后缀 |
| **C Face 基名不命中** | 22 | 名字无二进制证据(见 §3) |
| **D 非 Face 且不命中** | 31 | 多为组件/内部拆分(见 §4) |

**A 精确命中(46)**:`ApplicationTheme, CTerminalConfig, FilerPane, JsEngine, KitBar, MuxPane, MuxPaneGroup, MuxWindow, OutputPane, PopupWidget, ProxyCommandSocket, QJSValue, ScintillaEditBase, ScrollBar, SerialBridge, SerialCommander, SerialSession, SessionLogger, SessionPane, ShellBridge, ShellCommander, ShellProcess, ShellSession, Splitter, SplitterGroup, SshBridge, SshCommander, SshSession, SuperBridge, SuperCommander, SuperKeymap, SuperSession, TabBar, TabGroup, TcpBridge, TcpCommander, TcpSession, TelnetCommander, TelnetProtocol, TelnetSession, TerminalView, TerminalWidget, TextEdit, TextView, TransferPane, UnixPty`

**B 基名命中(63)**:`AddressBar, BreadCrumb, CEditorConfig, CGlobalConfig, CTerminalConfig, CaptureGroupsButton, CheckList, ColorButton, CustomLinkTriggerPage, CustomMenuTriggerPage, DefaultEditorDialog, EditorWindow, EnvironmentDialog, ExplorerList, FilterEdit, FocusModeDialog, HighlightTextBarAction, HighlightTextDialog, HighlightTextTriggerPage, InsertFileDialog, KitDock, KitWindow, LogDialog, LoginWizard, MainWindow, MarkStyleWidget, MasterPasswordDialog, MessageBar, NameDialog, OneKeyDialog, PasswordDialog, PasteDialog, PlaySoundDialog, PlaySoundTriggerPage, ProfileDialog, RemoteFileDialog, RunCommandTriggerPage, RunToolDialog, SearchEdit, SearchEngineDialog, SendTextTriggerPage, SessionDialog, SessionGroupDialog, SessionTriggerDialog, SettingDialog, SharedConfigHandler, ShowTooltipTriggerPage, SlipButton, StatusBar, SuperApplication, SyncInputDialog, TableItemDialog, TerminalWindow, TextMarkDialog, TextMarkTablePanel, TransferBar, TriggerActionDialog, TriggerActionEditPanel, TriggerActionWidget, TriggerDialog, TriggerPage, TunnelDialog, WindowOpacityDialog`

## 3. C 类:22 个无二进制证据的 Face 类

去后缀后的基名在 380 个 RTTI 名里**查无此名**。分三种成因:

### 3.1 已证实重复建模(3 处;2 处已清,1 处待清)

| 我方类 | 实际二进制类 | 状态 |
|---|---|---|
| `EnvDialogFace` | **EnvironmentDialog**（ctor `FUN_006b35a6`，vtable `0x11a2788` → typeinfo `17EnvironmentDialog`） | ✅ **已合并**(2026-11-16)：`envDialog_setupUi`(1109B,入口 `0x006b3100`)的装配体并入 `EnvironmentDialogFace::build()`，原文件删除 |
| `SettingsFace` | **TextMarkDialog**（`FUN_006f1036` 内直接调 `search_page_build_layout`） | ✅ **已拆分**：ctor + `searchPageBuildLayout` + 9 个 `+0x30..+0x70` 成员归位到 `TextMarkDialogFace`；`SettingsFace` 降为**纯静态工具 struct**（`categoryDataRoot`/`categoryTreeDataFace`/`buildRadioGroup` 三个自由形态函数，无 QDialog/Q_OBJECT） |
| `SettingsPageFace` ↔ `TunnelDialogFace` | 归属错案 | ⏳ **待清**：两者对同一 0x48 行结构给出**冲突**布局（见 `docs/pending-attribution.md` §1） |

### 3.1b 同名双建(3 处;1 处勘正,2 处已合并)

| 真名类 | 并存件 | 状态 |
|---|---|---|
| `CTerminalConfig` | `CTerminalConfigFace`(`CGlobalConfigFace.h`) | ✅ **勘正：不是重复** —— 批 142 的**私有基类设计**（`class CTerminalConfig : private CTerminalConfigFace`，`face()` 返回同一单例对象），故意为 face 子对象形态 |
| `EditorWindow`(`src/Widgets/EditorWindow.h`) | `EditorWindowFace`(`Actions/Kit/KitWindowFactory.h`) | ✅ **已合并**：`src/Widgets/EditorWindow.h`（header-only、无人 include）的 4 个槽体并入 `EditorWindowFace` 的 `public slots:`（cited 空体），原文件删除 |
| `TerminalWindow`(`src/Widgets/TerminalWindow.h`) | `TerminalWindowFace` | ✅ **已合并**：8 个槽体并入 `TerminalWindowFace`（`container`/`applyFlag` 两个未定义私有 helper 未随迁，避免引入链接期未定义符号），原文件删除 |

### 3.2 伞形/装配容器名(我方为组织代码而设,非原版类)

`ActionRegistryFace`(同文件里真正的类是 `HighlightTextBarActionFace`)、
`SettingsPageFace`、`KitWindowAssemblyFace`、`CGlobalConfigFace`(基名其实命中)、
`DeepEngineFace`、`TriggerPageStackFace`、`TermViewFace`(真名 **TerminalView**)、
`SearchPanelFace`(真名 **SearchPane**?)

### 3.3 无定论(待核)

`ActionButtonFace, ActionToolBarFace, BackwardShortcutFace, CloseButtonFace, CompleterButtonFace, CountSpinboxFace, CrumbEditFace, CursorShapeFace, ExpandButtonFace, ExpandToggleFace, ExpectDialogFace, HelpDialogFace, PasteSettingsPageFace, ProfileDirDialogFace, SessionProtocolFace, TransferAskFace, TriggerTableWidgetFace`

> 这些基名在 380 个 RTTI 名里查无此名,**也没有相近真名**(difflib 最近邻为空)。
> 两种可能:①原版确实没有对应类,我方为承载装配而设的局部类;②我方命名偏离。
> 逐个确认需要读各自 ctor 的 vtable 写点(`vtable_scan.py --addr`),留待下批。

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
3. **§3.1 仅剩 1 处**(SettingsPage↔TunnelDialog,卡在行结构取证);
   §3.1b 已全部处置(1 处勘正「非重复」,2 处合并)。收尾期编译前必须清零。
4. 新增类时:**先在 `tools/re/data/rtti_classes.txt` 里查**,命中就用真名(+`Face`
   与否按仓库惯例);不命中则必须在头注释写"无 RTTI 对应"。
5. 每批收尾可跑一遍本审计脚本,防止新造的类名悄悄偏离。

## 6. 已知局限

- **普通成员函数名不可验证**:stripped 后只留 moc 信号/槽名;非槽成员只能按
  vtable 槽位语义命名,属推断。
- 无 `Q_OBJECT` 且非多态(无 vtable)的辅助类**完全没有名字痕迹**。
- 380 个 RTTI 名包含 STL/Qt 依赖类;本表只用于比对,不代表都要建模。
