# src/ 目录说明

本目录混放**三类不同来源**的代码。改动前必须先确认文件属于哪一类，
因为三类的规则完全不同(见文末「改动规则」)。

| 类 | 含义 | 有 `FUN_`/`cited` 转写标记 |
|---|---|---|
| **A 逆向重建** | 我方按反编译语料逐函数转写;每行有出处 | ✅ 有 |
| **B 第一方开源** | WindTerm 作者以 Apache-2.0 开源的部分(上游仓库中的一手组件),我方**移植/校准** | ❌ 无(以原码为准) |
| **C 第三方库** | 外部开源库;上游原样或作者改进分支 | ❌ 无(不逆向) |

判据:`grep -c "FUN_\|cited" <文件>` —— 命中即 A 类。

## 1. 逐目录状态

| 目录 | 类 | 说明 |
|---|---|---|
| `Actions/` | **A** | 主窗装配、菜单/动作、dock、标签、设置页、对话框(128 文件中 124 有转写标记) |
| `Editor/` | **A** | 编辑器桥、`EditorEngine` 分派、`CTerminalConfig`(26/26) |
| `Sessions/` | **A** + B | 会话/SSH 管家为 A;`SuperSessionPrivate` 认证族**委托 libssh**(边界) |
| `Widgets/` | **A** 为主 | `*Face.*`/`EditorWindow`/`FilerPane`/`TerminalView` 为 A;**例外见 §2** |
| `Protocols/` | **B** | `TelnetProtocol.*`/`Protocol.h` 为作者开源组件(非逆向) |
| `Utility/` | **A** + B | `KingEnums.h`/`ApplicationTheme.*` 为 A;**其余见 §2** |
| `Pty/` | **B** | 基于 [ptyqt](https://github.com/kafeg/ptyqt) **几乎全部重写**(作者自述);`Pty/UnixPty` 为我方平台分叉 |
| `Ext/` | **A**(边界声明层) | `SpdlogFace.h` / `ZstdFace.h`:外部库的**接口面**,不含库实现 |
| `Scintilla/` | **C** | 上游 Scintilla **4.4.6**(`version.txt` = `446`);标准 `SCI_*` 全委托 |
| `jsoncpp/` | **C** | **1.9.4**(`JSONCPP_VERSION_STRING`) |
| `yaml-cpp/` | **C** | **0.6.3**(`project(YAML_CPP VERSION 0.6.3)`) |
| `spdlog/` | **C** | **1.9.2**(header-only) |
| `fmt/` | **C** | **8.1.1**(header-only;spdlog 依赖) |
| `dtl/` | **C** | diff-template-library(header-only,无版本宏) |
| `libssh/` | **C**(作者改进分支) | 基于 **libssh 0.9.6**;作者加了 pageant/external socket/hmac-*-96 等。**认证族委托** |
| `Onigmo/` | **C**(作者改进分支) | 基于 **Onigmo 5.13.5**;作者加了 iterator(gap buffer 匹配)。**正则引擎停逆向**(`docs/ext-boundary.md` 批 102) |

## 2. 混合目录的文件级归属

**`Utility/` —— 作者开源组件(移植,勿逆向)**

`CircularBuffer.h`(环形缓冲模板)、`Cryptographic.{h,cpp}`(PBKDF2/RFC 8018)、
`MemoryPointer.h`、`ScopeGuard.h`、`Spin.h`、`ThreadLocal.{h,cpp}`

**`Widgets/` —— 作者开源组件(移植,勿逆向)**

`PopupWidget.{h,cpp}`、`ScrollBar.{h,cpp}`(支持 64 位范围)、`Splitter.h`

> 依据:上游 `src/README.md`(已移除此处原文)自述"These are first-party
> components";移植/校准记录见 `docs/calibration.md`(第一方 6 组件:保持移植,
> 对应子系统**停止逆向**)。

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

## 4. 改动规则(按类分)

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
