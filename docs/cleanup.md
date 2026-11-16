# 代码库清理记录(2026-11-16 / 批 493 后)

> 用户指令:"重新整理当前代码库,去掉逆向中用不到的内容"。
> 本文档 = **判据 + 台账 + 保留理由**,供日后复核;**不做 git 历史重写**
> (会破坏 341 提交的溯源链,铁律 1 的出处链依赖它)。

## 判据(按优先级)

1. **构建是否引用?**(看 `CMakeLists.txt` 的 `GLOB` / `add_subdirectory` /
   `COMMAND ... -c ${CMAKE_SOURCE_DIR}/...`)—— 不引用 = 可从构建角度移除。
2. **是否外部库边界?**(`docs/ext-boundary.md`:yaml-cpp / jsoncpp / libssh /
   Onigmo / spdlog / fmt / dtl 一律**不逆向,委托真库**)—— 其上游**自测/示例**
   代码与 WindTerm 行为复刻无关,可移除;库**实现源码**保留(需要时重编)。
3. **是否逆向参考材料?**(主语料 `tools/re/decomp`、数据面 `terminal/`、
   `global/`、头文件快照 `inc/`)—— **AGENTS.md 条 16:复刻完成并通过行为
   对比之前不动**。本次全部保留。
4. **是否可无损重建?** 可重建者即便删除,必须在台账写明重建命令。

## A 组:已删除的未跟踪大件(不可从 git 恢复)

> 这些文件在 `.gitignore` 内,从未入库。删除前无副本备份,已确认工作区
> 与本机其他位置均无留存。

| 项 | 体积 | 删除理由 | 重建方式 |
|---|---|---|---|
| `build/` | 29M | 批 189 时代的陈旧产物;铁律 7 收尾期才编译 | `mkdir build && cd build && cmake .. && make -j$(nproc)` |
| `frida_binding.node` | 132M | frida 的 **Node 绑定**;本项目用 **python frida + REA MCP**,仓库内零代码引用 | `npm i frida` 或 `prebuild-install`(见 phase5 原文记载) |
| `WindTerm.i64` `.id1` `.id0` `.nam` | 136M | **IDA 数据库**;主语料是 `tools/re/decomp`(49M),IDA 仅作 spot check(且需基址差 `−0x400000`) | **只能重跑 IDA 自动分析;人工标注(若有)不可恢复** |
| `tools/re/phase5/__pycache__` | ~1M | python 字节码缓存 | 自动重建 |

工作树 641M → 340M。

## B1 组:已删除的上游测试/示例(5 个提交,可单独 revert)

| 提交 | 路径 | 体积 | 依据 |
|---|---|---|---|
| G1 | `src/yaml-cpp/test` + `util` | 6.9M + 28K | CMake 只编 `src/yaml-cpp/src/*.cpp` |
| G2 | `src/libssh/tests` + `examples` | 1.4M + 188K | 不编源码,链系统 `libssh`(认证族委托) |
| G3 | `src/Scintilla/test` + `src/Scintilla/lexilla/` | 912K + 696K | CMake 只编 `src/{src,lexlib,lexers,include,qt/ScintillaEditBase}`;**lexilla 全库零引用** |
| G4 | `src/jsoncpp/test` + `example` + `src/test_lib_json` | 748K + 52K + 180K | CMake 只编 `src/jsoncpp/src/lib_json/*.cpp` |
| G5 | `src/Scintilla/tgzsrc.orig` + `qt/ScintillaEdit/WidgetGen.pyc` | 4K + 12K | 上游 tar 解包残留 / 编译产物误入库 |

合计约 **11.1M**。

### 复核方式(执行后已跑)

```bash
# 1) 被删路径零引用
grep -rl --exclude-dir=.git "yaml-cpp/test\|Scintilla/lexilla\|test_lib_json" \
  CMakeLists.txt tools/re/*.py tools/re/*.md tests/ docs/*.md
# 2) CMake 引用的源路径全部在位
for d in src/Scintilla/{src,lexlib,lexers,include,qt/ScintillaEditBase} \
         src/yaml-cpp/{src,include} src/jsoncpp/{src/lib_json,include} \
         src/{Actions,Widgets,Editor,Sessions,Protocols,Utility,Pty}; do
  [ -d "$d" ] || echo "缺失: $d"; done
```

## 明确保留(不得以"体积"为由删除)

| 路径 | 体积 | 理由 |
|---|---|---|
| `tools/re/decomp/` | 49M | **主语料**,全部转写的唯一出处来源(铁律 1) |
| `lib/*.a` | 86M | 预构建静态库,构建直接链接(重编需 `-DBUILD_DEPS=ON`) |
| `src/{Actions,Sessions,Editor,Widgets,Protocols,Utility,Pty,Ext}` | ~30M | 转写产物本体 |
| `inc/` | 21M | **AGENTS 条 16**:头文件版本对齐锚点,复刻完成前不动 |
| `terminal/` `global/` `vendors/` `images/` | ~26M | **数据面参考**:`global/wind.actions` = ② 的配置源、`terminal/commands` = 命令表、`images/screenshots` = 唯一对表证据 |
| `tests/` | 460K | 25 个测试二进制 = **收尾期回归网** |
| `docs/` | 468K | 全部结论 / 工作单 |
| `./WindTerm` | 12M | **基线二进制**(仓库内副本,sha256 与 `/opt/WindTerm_2.7.0/WindTerm` 同一)。2026-11-16 用户令:逆向基线改用此副本,工具/文档路径已统一改指 |
| `.git/` | 125M | 历史与出处链,禁止重写 |

## C 组:2026-11-16 第二批(用户令:删 tests + 基线切本地副本)

| 动作 | 内容 | 依据 |
|---|---|---|
| 删除 `tests/` | 20 个 cpp + `CMakeLists.txt`(460K);同步删 `CMakeLists.txt` 的 `add_subdirectory(tests)` 与 `enable_testing()` | 用户令「删除所有 tests」;工作重心转向逆向代码落地,不编译不测试 |
| 基线二进制改本地副本 | 文档/工具中 `/opt/WindTerm_2.7.0/WindTerm` → **`./WindTerm`**(9 处);`sha256 9491b87e…` 与 /opt 逐字节同一 → **语料地址不变** | 用户令「以二进制为准;改为本地库的」 |
| 保留 | `/opt/WindTerm_2.7.0/lib` 引用(运行时 Qt 依赖,6 处)、`tools/re/metatest/`、`tools/re/phase5/` | 前者是运行依赖;后两者是取证探针,非测试 |

## 未做(明确排除)

- **git 历史重写**(`filter-repo` / `BFG`):会破坏 341 提交的溯源链。
- **删除 `inc/`、数据面、语料**:违反 AGENTS 条 16。
- **删除 `./WindTerm` 副本**(B2):用户未批准。
