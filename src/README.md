# src/ 目录说明

本目录混放**三类不同来源**的代码。改动前必须先确认文件属于哪一类，
因为三类的规则完全不同(见文末「改动规则」)。

| 类 | 含义 | 有 `FUN_`/`cited` 转写标记 |
|---|---|---|
| **A 逆向重建** | 我方按反编译语料逐函数转写;每行有出处 | ✅ 有 |
| **B 第一方开源** | WindTerm 作者以 Apache-2.0 开源的部分(上游仓库中的一手组件),我方**移植/校准** | ❌ 无(以原码为准) |
| **C 第三方库** | 外部开源库;上游原样或作者改进分支 | ❌ 无(不逆向) |

判据:`grep -c "FUN_\|cited" <文件>` —— 命中即 A 类。

## 1. 目录结构(2026-11-16 按角色重组)

**分组判据 = 职责不同、改动规则不同**,不是体积、不是字母表。

```
src/
├── Actions/            126 文件  界面装配(动作/菜单/对话框/主窗)
│   ├── Dialogs/         33    全部 *DialogFace + MsgBoxFace
│   ├── Settings/         4    Settings* / *SettingsPageFace / TriggerPageFace
│   ├── Kit/             12    KitWindow* / MainWindow / StatusBar / TabGroup / KitBar
│   ├── Menu/             4    ActionFactory / ActionRegistry / ToolBarBuilder / ThemeIcons
│   ├── Mux/              5    MuxWindow / MuxPane* 
│   └── (根)              6    StartupChain / StateStore / JsEngine / SearchPanelFace …
├── Editor/              26   编辑器引擎与配置
│   ├── Engine/           17    EditorContext / EditorEngine / ENodes / MatchEngine / SuperKeymap …
│   └── Config/            8    CGlobalConfigFace / CTerminalConfig / CEditorConfig / ConfigBridge …
├── Sessions/            51   会话层
│   ├── Bridges/         15    SuperBridge + Ssh/Tcp/Telnet/Serial/Shell 五种
│   ├── Commanders/      12    SuperCommander + 五种
│   ├── Protocols/       10    SshSession/TcpSession/TelnetSession/ShellSession/SerialSession
│   ├── Terminal/         6    Screen / ScreenData / TerminalCore / TermViewFace
│   └── Core/             7    SuperSession / SuperSessionPrivate / WorkspaceLoader / FileOps
├── Widgets/             37   Qt 控件
│   ├── Faces/           15    自绘控件族(ActionButton/Bar/BreadCrumb/ColorButton/Expand/List …)
│   ├── Panels/          13    FilerPane / OutputPane / SessionPane / TerminalView / TextView …
│   └── (根)              5    PopupWidget / ScrollBar / Splitter  ← **B 类,勿逆向**
├── Utility/             11   共享基元
│   └── (根)             11    KingEnums / ApplicationTheme(A)+ CircularBuffer / Cryptographic /
│                              ScopeGuard / Spin / ThreadLocal …(← **B 类,勿逆向**)
├── Pty/                 10   第一方开源(基于 ptyqt 重写)
├── Protocols/            3   第一方开源(Telnet)
├── Ext/                  2   外部库接口面(Spdlog/Zstd,不含实现)
└── Stubs/                1   gen_stubs.cpp(自动生成的 cited-stub,随转写递减)
```

**出处写法**(三种均可,机器统一索引):`FUN_0064ab10` / 裸 `0064ab10` /
`s_Name_534e62`;纯 moc 声明类写「出处:QMetaObject 元数据」。

**动手前先查**:`python3 tools/re/coverage.py --addr <地址>` —— 该函数全仓是否
已有实现。全量索引 `docs/meta/coverage-map.md`(自动生成)。

**include 约定**:`src/` 是 include 根 → 跨目录一律写根相对路径
`#include "Sessions/Core/SuperSession.h"`;同目录才可用裸文件名。

## 1b. 三类来源(与上面结构正交)

| 目录 | 类 | 说明 |
|---|---|---|
| `Actions/` `Editor/` `Sessions/` `Widgets/` `Stubs/` | **A** | 逆向重建;每行有 `FUN_`/`cited` |
| `Utility/` `Widgets/` 内的 `[B-OPENSOURCE]` 文件,`Protocols/` `Pty/` | **B** | 作者 Apache-2.0 开源件,移植须 `docs/calibration.md` 逐句同构 |
| `Scintilla/` `jsoncpp/` `yaml-cpp/` `spdlog/` `fmt/` `dtl/` `libssh/` `Onigmo/` | **C** | 第三方库,不逆向不改 |
| `Ext/` | A | 外部库的**接口面**声明(Spdlog/Zstd) |

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

- **去掉 `Face` 后命中二进制 RTTI 真名 → 基名可信**(当前 63/87;
  全量对照见 `docs/meta/class-names.md`)。
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
