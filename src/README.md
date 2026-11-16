# src/ 目录说明

本目录混放**三类不同来源**的代码。改动前必须先确认文件属于哪一类，
因为三类的规则完全不同(见文末「改动规则」)。

| 类 | 含义 | 有 `FUN_`/`cited` 转写标记 |
|---|---|---|
| **A 逆向重建** | 我方按反编译语料逐函数转写;每行有出处 | ✅ 有 |
| **B 第一方开源** | WindTerm 作者以 Apache-2.0 开源的部分(上游仓库中的一手组件),我方**移植/校准** | ❌ 无(以原码为准) |
| **C 第三方库** | 外部开源库;上游原样或作者改进分支 | ❌ 无(不逆向) |

判据:`grep -c "FUN_\|cited" <文件>` —— 命中即 A 类。

## 1. 目录结构(按软件架构分层)

**判据 = 软件自身的分层与子系统**,不按"是否逆向过"、不按类名后缀。
新增类时先问:它在架构里属于哪一层,而不是"它像哪个已有文件"。

> 树中列的是**代表类**,不是全部;各层当前文件数/地址数以
> **`docs/meta/coverage-map.md`** 为准(自动生成)。本文**不写死任何计数**。

```
src/
├── App/               应用层(启动 / 全局状态 / 脚本 / 主题)
│                        SuperApplication StartupChain StateStore JsEngine
│                        ThemeIcons ApplicationTheme
├── Windows/           窗口系统
│   ├── Kit/            主窗与 Kit 体系:KitWindow KitWindowAssembly KitDock KitBar
│   │                   KitWindowFactory MainWindow
│   └── Mux/            多路窗口:MuxWindow MuxPane MuxPaneGroup MuxPaneView MuxPaneJs
├── Widgets/           UI 控件
│   ├── Dialogs/           全部对话框 + MsgBox + LoginWizard + Tunnel/TransferAsk
│   ├── Settings/          设置页:Settings SettingsPage PasteSettingsPage TriggerPage
│   ├── Bars/              条状容器:ActionToolBar StatusBar MessageBar
│   │                       Quick/TransferBar AddressBar+BreadCrumb
│   ├── Controls/          原子控件:按钮( Action/Color/Expand/Close/Completer )/
│   │                       输入( SearchEdit/FilterEdit/CrumbEdit/CountSpinbox/CursorShape )/
│   │                       列表( CheckList/ExplorerList )/容器组( TabGroup/SplitterGroup )
│   ├── Panes/             FilerPane OutputPane SessionPane TransferPane ViewBase SearchPanel
│   ├── Views/             TerminalView TerminalWidget TextEdit TextView
│   └── (根)               PopupWidget ScrollBar Splitter   ← **B 类,勿逆向**
├── Actions/           命令层(动作 / 菜单 / 工具栏 / 快捷键)
│                        ActionFactory ActionRegistry ToolBarBuilder
│                        SlipButton(菜单行) BackwardShortcut(快捷键绑定)
├── Sessions/          传输与连管
│   ├── Core/            SuperSession SuperSessionPrivate WorkspaceLoader
│   │                    FileOps SessionManager
│   ├── Transports/      Ssh / Tcp / Telnet / Shell / Serial Session
│   ├── Bridges/         SuperBridge + 五种
│   └── Commanders/      SuperCommander + 五种
├── Terminal/          终端内核:Screen ScreenData TerminalCore TermViewFace
├── Editor/            编辑器
│   ├── Engine/          EditorContext EditorEngine ENodes MatchEngine MarkersStore
│   │                    ModTrack OnigSearch RunNode Keymap SuperKeymap CodecMemo
│   └── Config/          CGlobalConfig CTerminalConfig CEditorConfig ProfileLoader ConfigBridge
├── Utility/           共享基元:KingEnums + B 类组件(见 §2)
├── Protocols/         Telnet 协议(**B 类**)
├── Pty/               伪终端(**B 类**,基于 ptyqt 重写)
├── Ext/               外部库接口面(Spdlog / Zstd)
└── Stubs/             gen_stubs.cpp(自动生成 cited-stub,随转写递减)
```

分层要点(改代码时别越线):

| 层 | 只做 | 不要放 |
|---|---|---|
| `App/` | 启动装配、全局单例、脚本桥 | 具体控件 |
| `Windows/` | 窗口/停靠/多路容器 | 窗内控件本体(→ `Widgets/`) |
| `Widgets/` | 可复用 UI 控件、对话框、页面 | 业务逻辑(→ `Sessions/` `Editor/`) |
| `Actions/` | 动作/菜单/快捷键构建 | 控件实现 |
| `Sessions/` | 连接、传输、命令分发 | Qt 控件 |
| `Terminal/` | 终端数据模型与状态机 | 渲染控件(→ `Widgets/Views/`) |
| `Editor/` | 编辑引擎与配置 | 通用控件 |

## 1b. 五类代码 —— 判定流程(按序问,先命中先定)

| # | 类 | 判据 | 怎么处理 |
|---|---|---|---|
| 1 | **C 第三方库** | 路径在 `Scintilla/` `jsoncpp/` `yaml-cpp/` `spdlog/` `fmt/` `dtl/` `libssh/` `Onigmo/` | **不逆向、不改**;只转写 WindTerm 侧调用面(`src/Ext/`) |
| 2 | **D 外部库接口面** | 路径在 `Ext/` | 只有声明;实现委托真库或 no-op |
| 3 | **E 生成桩** | 路径在 `Stubs/` | `gen_stubs.py` 生成的 cited 空实现;转写出真身后删该行 |
| 4 | **B 第一方开源** | 文件头有 `[B-OPENSOURCE]`,或在 `tools/re/data/open_source_files.txt` | **勿逆向**;移植须 `docs/calibration.md` 逐句同构 |
| 5 | **A 已逆向** | 有出处 —— `FUN_xxxxxxxx` / 裸地址 `00xxxxxx`(在 `.text` 内)/ `s_名_xxxxxx` / `// cited` / 「出处:QMetaObject」 | 正常逆向;`coverage.py --addr` 查重后再动 |
| — | *未分类* | 以上都不命中 | **违规**;`coverage.py --audit` 会报 |

**一条命令搞定**:

```bash
python3 tools/re/coverage.py --what src/Widgets/Bars/StatusBarFace.h
python3 tools/re/coverage.py --what TunnelDialogFace        # 也收类名
```

输出:类别 / 依据(出处计数)/ Q_OBJECT / 基类 / Qt 前置声明数。

### Qt 接口怎么算?

Qt **不在本仓**(用系统 Qt5,`lib/` 只放运行时 so)。所以:

- `#include <QWidget>` = 外部头,不是我们的代码;
- `class QComboBox;` = 我们的**前置声明**,只为省编译;
- `class FooFace : public QDialog` = **我们的类**,基类是 Qt 的,派生类是本仓的 ——
  逆向对象是 `FooFace`(基类行为不转写,直接委托 Qt)。

判定口诀:**尖括号里的是 Qt,`src/` 里 `Q*` 开头的只是前向声明。**

### 函数级判定

文件级看上面;函数级问「这条地址做过没有」:

```bash
python3 tools/re/coverage.py --addr 006b35a6     # → 2 个文件(已做)
python3 tools/re/coverage.py --addr 00abcdef     # → 0 个文件(未做)
```

## 2. 第一方开源件(勿逆向)—— 混放 + 文件级标记

**不与逆向代码物理分目录**。理由:分目录会破坏与上游项目的结构对应(移位置即
改结构),还会让"这一坨是开源的"变成只存在于目录名里的隐含知识 —— 一旦有人
把文件挪回去或新建同族文件,就再也认不出来,进而**重复逆向已有开源实现**。

改为三条**显式标记**,任一即可识别:

1. **文件头标记**(最直接):每个 B 类文件首行都是

   ```
   // [B-OPENSOURCE] 第一方开源件 —— **勿逆向**。
   ```

2. **清单**(机器可读):`tools/re/data/open_source_files.txt`
3. **校验**(防漂移):`python3 tools/re/coverage.py --audit`
   —— 清单内缺标记、有标记不在清单,都会报错。

| 位置 | 文件 |
|---|---|
| `Utility/` | `CircularBuffer.h` `Cryptographic.{h,cpp}` `MemoryPointer.h` `ScopeGuard.h` `Spin.h` `ThreadLocal.{h,cpp}` |
| `Widgets/` | `PopupWidget.{h,cpp}` `ScrollBar.{h,cpp}`(64 位范围)`Splitter.h` |
| `Protocols/` | `Protocol.h` `TelnetProtocol.{h,cpp}` |
| `Pty/` | `Pty.{h,cpp}` `UnixPty.{h,cpp}` `WinPty.{h,cpp}` `ConPty.{h,cpp}` `ShellProcess.h` `Public/Spin.h`(ptyqt 兼容壳) |
| `Pty/ptyqt LICENSE` | 上游许可原文 |

> 依据:上游 README 自述"These are first-party components";移植/校准记录见
> `docs/calibration.md`(第一方 6 组件:保持移植,对应子系统**停止逆向**)。

## 3. 第三方库:版本、许可、构建参与

| 库 | 版本 | 许可 | 构建参与 |
|---|---|---|---|
| Scintilla | 4.4.6 | `src/Scintilla/License.txt`(HPND) | 源码在树;`lib/libscintilla_core.a`(16.6M)+`libscintilla_qt.a`(754K)预构建,默认直链 |
| jsoncpp | 1.9.4 | `src/jsoncpp/LICENSE`(MIT) | 源码在树;`lib/libjsoncpp.a`(438K)预构建 |
| yaml-cpp | 0.6.3 | `src/yaml-cpp/LICENSE`(MIT) | 源码在树;`lib/libyaml-cpp.a`(923K)预构建 |
| Onigmo(改) | 5.13.5 | `src/Onigmo/COPYING`(BSD) | 源码在树;`lib/libonig.a`(2.1M)预构建,**委托** |
| libssh(改) | 0.9.6 | `src/libssh/COPYING`(LGPL-2.1) | **不编源码**;`lib/libssh.so.4.8.7` 运行时链,认证族委托 |
| spdlog | 1.9.2 | MIT(头注) | header-only,无预构建;经 `src/Ext/SpdlogFace.h` 使用 |
| fmt | 8.1.1 | MIT(头注) | header-only(spdlog 内部依赖) |
| dtl | 无版本宏 | 头注(MIT) | header-only |

重编第三方库:`cmake .. -DBUILD_DEPS=ON && make rebuild_deps`
(仅上游更新时才需要;平时直接用 `lib/*.a`)。

> 删除纪律:这些库的**实现源码与头一律保留**(重编时才用);其上游
> `test/`/`examples/` 树已于 2026-11-16 移除(属外部库边界,非逆向参考),
> 需要时按上表版本重新拉取。见 `docs/cleanup.md`。

## 4. 命名:`*Face` 是重建标记,不是原版类名

二进制里 **没有 `Face` 这个词**(`strings -a WindTerm | grep -c Face` = 0)。
`*Face` = 我方在 `src/` 里承接语料函数体的类,用来和第三方/第一方开源件区分。

- **去掉 `Face` 后命中二进制 RTTI 真名 → 基名可信**(统计见
  `docs/meta/class-names.md`)。
- **去后缀不命中 → 需查证**:可能是伞形容器名(`ActionRegistry`/`Settings`)、
  我方内部拆分(`Screen`→二进制 `SuperTerm`、`EditorContext`→`Editor`)、
  或重复建模。
- 新增类前先查 `tools/re/data/rtti_classes.txt`(380 个真名);
  命中就用真名,不命中必须在头注释写"无 RTTI 对应"。

## 5. 改动规则(按类分)

| 类 | 规则 |
|---|---|
| **A 逆向重建** | 必须回 `tools/re/decomp` 语料取出处(`FUN_XXXXXXXX` / 行号);不许凭记忆改;不确定就 `cited`。见 `AGENTS.md` 铁律 1/3/6 |
| **B 第一方开源** | 以原码为准移植,**逐句同构**记录进 `docs/calibration.md`;不得混入逆向推测 |
| **C 第三方库** | **不逆向、不改**;只转写 WindTerm 侧的调用接口面(`src/Ext/`),行为委托真库。见 `docs/ext-boundary.md` |

边界速查(不要越线):

```
标准 SCI_* (≤4033) → scintillaDelegate(真 Scintilla)
WindTerm EXT/WT (≥20163) → EditorEngine::customDispatch(逆向)
libssh 认证族 / yaml-cpp / Onigmo / spdlog → 委托真库
```
