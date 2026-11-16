# AGENTS.md — WindTerm 逆向工程指南

> 目标:完全逆向 WindTerm 2.7.0(含 bug 原封不动)。每行代码必须有出处
> (逆向地址 / 语料行),禁止捏造。
>
> **冷启动顺序**:见 §2「会话重启加载顺序」(必读 6 份 + 3 条状态核对命令)。

## 0. 目标与基线(**以二进制为准**)

| 项 | 位置 | 说明 |
|---|---|---|
| **基线二进制** | **`./WindTerm`** | 仓库内副本,2.7.0,`sha256 9491b87e…7469f54`,与 `/opt/WindTerm_2.7.0/WindTerm` **逐字节同一** |
| 主反编译语料 | `tools/re/decomp/*.c` | 49M,每函数带 `entry=ADDR name= size=N` 头 |
| 数据面参考 | `terminal/` `global/` | `global/wind.actions` = 动作配置源 |
| 运行时依赖库 | `/opt/WindTerm_2.7.0/lib` | Qt5 运行库(跑原版取证时需要) |

**口径纪律**:

- 一切结论以 **二进制 + 反编译语料** 为准;文档与代码冲突时**回二进制取证**,
  不许以"文档这么写"为依据。
- IDA 若使用:**IDA 地址 = Ghidra − 0x400000**。
- `.rodata` 取串:`file_offset = addr − 0x400000`(readelf 实测
  `.rodata` addr `0xc89000` ↔ off `0x889000`);`.data.rel.ro` 段偏移不同,
  用 `readelf -SW` 现算段偏移读取,**勿手算**。

## 1. 仓库根目录布局

| 路径 | 体量 | 类型 | 用途 / 规则 |
|---|---|---|---|
| `AGENTS.md` | 13K | 文件 | **本文件**:规则与基线(每次开工先读) |
| `README.md` | 2K | 文件 | 仓库入口:这是什么、三条纪律、目录速览 |
| **`WindTerm`** | 12M | 文件 | **基线二进制**(RE 唯一事实源;sha256 见 §0) |
| `src/` | 19M | 目录 | 重建代码 + 第三方库 + 第一方开源件 → **架构分层见 §1.1;三类归属见 `src/README.md`** |
| `tools/` | 51M | 目录 | `decomp/`(**主语料 49M**)+ 取证脚本 + `handoff.md`/`gui-map.md` |
| `docs/` | 576K | 目录 | 文档总目录 → 入口 `docs/index.md` |
| `lib/` | 86M | 目录 | 预构建静态库(`libscintilla_core.a` 等)+ 运行时 so + Qt 插件目录 —— **构建期才用** |
| `inc/` | 21M | 目录 | 上游头文件快照 = **版本对齐锚点,复刻完成前勿删**(踩坑 14) |
| `global/` | 8M | 目录 | 原版数据面:**`wind.actions`(② 动作配置源)**、`wind.config`、`wind.keymaps`、locales/palettes/themes |
| `terminal/` | 17M | 目录 | 原版数据面:`commands/`(命令表)`configs/` `protocols/` `schemes/` `terms/` `applets/` |
| `images/` | 1.1M | 目录 | 图标 + **`screenshots/`(截图对表证据)** |
| `vendors/` | 164K | 目录 | 原版捆绑的**运行时可执行文件**(`lrzsz/{rz,sz}`,无源码;运行时 spawn,字符串 `/vendors/lrzsz/*` 实证) |
| `benchmark/` | 8K | 目录 | 上游遗留脚本(`urandom_test.sh`),非逆向资产 |
| `license.txt` | 52K | 文件 | 原版(WindTerm)许可证文本 |
| `profiles.config` | 21B | 文件 | 原版启动配置 `{"path":"~"}`(跑原版时用) |
| `qt.conf` | 26B | 文件 | 跑原版用的 Qt 插件路径 `[Paths] Plugins=./lib` |
| `windterm.desktop` / `windterm.png` | 414B / 12K | 文件 | 原版 Linux 桌面项与图标 |
| `opencode.json` | 626B | 文件 | REA MCP 配置(207 工具) |
| `CMakeLists.txt` | 9K | 文件 | 构建脚本 —— **构建期才用**(平时不跑,铁律 7) |
| `.gitignore` | 176B | 文件 | 忽略 `build/`、编译产物、IDA 库(`*.i64/.id*/.nam`)、`__pycache__`、`frida_binding.node` |
| `.claude/` `.opencode/` | — | 目录 | agent 本地状态(**gitignored**,不入库) |
| `compile_commands.json` / `WindTerm.til` | — | 文件 | 构建 / IDA 残留(untracked、gitignored,可随时重建) |

> 「体量」列是**量级参考**,随清理/增长漂移,不作判据。

**判据速记**:改行为 → `src/`;找出处 → `tools/re/decomp`;查结论 → `docs/`;
验事实 → `./WindTerm`;**删东西前先看 `docs/cleanup.md` 与踩坑 14**。

### 1.1 src/ 架构分层(**新增代码必须归位,防止漂移**)

| 层 | 职责 | 内含 |
|---|---|---|
| `src/App/` | 应用与启动 | SuperApplication / StartupChain / StateStore / JsEngine / ThemeIcons / ApplicationTheme |
| `src/Windows/` | 窗口系统 | `Kit/`(KitWindow·KitDock·KitBar·MainWindow·Factory)`Mux/`(MuxWindow·MuxPane*) |
| `src/Widgets/` | UI 控件 | `Dialogs/` `Settings/` `Bars/` `Controls/` `Panes/` `Views/`;根目录 = B 类开源件 |
| `src/Actions/` | 命令层 | ActionFactory / ActionRegistry / ToolBarBuilder / SlipButton / BackwardShortcut |
| `src/Sessions/` | 连接与传输 | `Core/` `Transports/` `Bridges/` `Commanders/` `Transfers/`(XMODEM/YMODEM/ZMODEM 协议族 + 外部进程封装) |
| `src/Terminal/` | 终端内核 | Screen / ScreenData / TerminalCore / TermViewFace |
| `src/Editor/` | 编辑器 | `Engine/` `Config/` |
| `src/Utility/` `src/Ext/` `src/Stubs/` | 基元 / 外部库**声明面** / 生成桩 | KingEnums;Zstd;gen_stubs |
| `src/Protocols/` `src/Pty/` | **第一方开源(B 类)** | 见 §11,勿逆向 |

**归位判据(三步,不许靠"像哪个已有文件")**

1. **先判层**:它是窗口容器 / 可复用控件 / 对话框 / 连接 / 终端模型 / 编辑引擎?
   对应 `Windows` / `Widgets` / `Sessions` / `Terminal` / `Editor`。
2. **再判组**:同组 = 同一装配链上一起出现的类(例:`TriggerPage` 归 `Widgets/Settings`,
   而 `TriggerDialog` 归 `Widgets/Dialogs` —— 页与对话框不同层)。
3. **最后查重**:`python3 tools/re/coverage.py --addr <地址>` —— 已存在就改它,**不新建**。

**禁止(会立刻造成漂移)**

- ❌ 建按**命名后缀**分的桶(`Faces/`、`*Faces.h` 混装、`Misc*`、`Utils/`)
- ❌ 按**"是否逆向过"**分目录(B 类不得单独挪出去 —— 见 §11)
- ❌ 把**不同层的类塞进同一个文件**(一个文件一个架构角色;拆开)
- ❌ 在 `Actions/` 放控件、在 `Widgets/` 放业务逻辑、在 `Sessions/` 放 QWidget

**动手前先判「这文件是什么」—— 一条命令**

```bash
python3 tools/re/coverage.py --what <文件或类名>
```

按序判定,先命中先定(**Qt 不在本仓,不算任何一类**):

| 序 | 类 | 命中条件 | 处置 |
|---|---|---|---|
| 1 | C 第三方 | 路径在 `Scintilla/jsoncpp/yaml-cpp/spdlog/fmt/dtl/libssh/Onigmo` | 不逆向不改 |
| 2 | D 外库接口面 | `Ext/` | 只声明,委托真库 |
| 3 | E 生成桩 | `Stubs/` | cited 空实现,转写后删行 |
| 4 | B 第一方开源 | `[B-OPENSOURCE]` 或清单命中 | **勿逆向**,按 calibration 移植 |
| 5 | A 已逆向 | 有 `FUN_`/裸地址/`s_符号`/`cited`/「出处:QMetaObject」 | 正常逆向,先 `--addr` 查重 |
| — | 未分类 | 都不命中 | 违规,`--audit` 报 |

Qt 的边界:`#include <Q...>` 是外部头;`class QFoo;` 只是我们的前置声明;
`class XFace : public QDialog` 里**反的是 XFace**,Qt 基类行为不转写。

**反漂移检查(改完目录/新增文件后跑)**

```bash
python3 tools/re/coverage.py --audit    # 每个文件必须有归属(A 出处 / B 标记),0 未标注
python3 tools/re/coverage.py --addr X   # 查重:该函数是否已有实现
grep -rn '#include "' src/ | ...        # include 必须能按 src/ 根相对路径解析
```
> moc 头与源文件通配都是 `GLOB_RECURSE`(新子目录零配置);若新增 **顶层目录**,
> 必须同时加进 `CMakeLists.txt` 的 `WT_SOURCES` 与 `WT_MOC_HEADERS`。
>
> 详细清单(每目录逐文件)见 **`src/README.md` §1**;本节只记**分层与判据**。
> **各层当前文件数/地址数见 `docs/meta/coverage-map.md`(每次 `coverage.py --write` 重生成)**
> —— 本文与 README 都不写死数字,避免随批次腐化。


## 2. 会话重启加载顺序

### 2.1 必读(按序,合计约 700 行)

| # | 文件 | 读完应知道 |
|---|---|---|
| 1 | `AGENTS.md`(本文件) | 规则、基线、工具、踩坑 |
| 2 | `tools/re/handoff.md` | **单页当前态**:七节覆盖表 / 勘正谱系 / 现役队列 |
| 3 | `docs/index.md` | 文档索引(后续按需跳转的唯一入口) |
| 4 | `docs/plan.md` | 阶段总览(现在在哪一阶段) |
| 5 | `docs/phase5.md` 顶部「结论快照」 | 里程碑 / 编辑引擎真值 / 5b 终局 / 开放风险 |
| 6 | `docs/quirks.md` | 原版怪癖(**动代码前扫一遍,别把怪癖当 bug 修**) |

### 2.2 转写前必查(防止在已有代码上重复新增)

```bash
python3 tools/re/coverage.py --addr 006b35a6   # 这个函数全仓在哪?已有实现则改它,不新建
python3 tools/re/coverage.py                   # 全视图:各目录规模 / 地址数 / cited 数
```

全量索引见 **`docs/meta/coverage-map.md`**(自动生成)。**动笔前先查**,这是
"不要重复造已有实现"的机械保证,不靠记忆。

### 2.3 状态核对(3 条命令,再做任何改动)

```bash
git log --oneline -5                    # 最近 5 批做了什么
git status --short                      # 应为空;有残留先问清再动
git rev-list --count origin/dev..dev    # 领先量(只提交不推送,勿惯性 push)
```

然后读 `handoff.md`「现役队列」第 1 条 —— 那即是下一批起点。

### 2.4 按任务取(不必全读)

| 任务 | 读什么 |
|---|---|
| 界面/对话框/菜单 | `tools/re/gui-map.md`(七节)+ `docs/pending-attribution.md`(归属工作单) |
| 某子系统 | `docs/subsystems/<名字>.md`(state-machine / terminal-core / ssh-internals / editor-engine-commands …) |
| vtable / 枚举 / 函数地址 | `docs/meta/{vtable-map,king-enums,impl-addresses}.md` |
| 原版 bug 判定 | `docs/quirks.md` |
| 外部库行为 | `docs/ext-boundary.md`(不逆向清单 + 版本) |
| 某批的取证细节 | `docs/history/*`(检索用,**结论以现行文档为准**) |
| src 里某文件属于哪一类 | `src/README.md`(逆向 / 第一方开源 / 第三方) |
| **新增类该放哪** | **§1.1 归位判据**(先判层 → 再判组 → 最后查重) |

### 2.5 冷启动禁忌

- **不要全量读 `docs/history/`**(phase5-log 3000+ 行):只在追问具体批次时 `grep`。
- **不要把覆盖率当完成度**:`handoff.md` 的百分比是**转写覆盖**,
  可编译/可运行另有口径(见 §3 末「构建与测试不在本文件范围」)。
- **不要以文档为依据反驳二进制**:文档与语料冲突 → 回 `./WindTerm` 取证
  再改文档(§0 口径纪律)。
- **不要因为"构建未引用"就删参考材料**(踩坑 14;删除动作必须登记 `docs/cleanup.md`)。

## 3. 铁律

1. **每行代码有出处**:真实现引用 `FUN_XXXXXXXX` / `name@地址`;thunk 引反向
   表项;文档引用 `docs/meta/impl-addresses.md`。**没地址不写**。
   **出处三种写法都算数,且都会被 `coverage.py` 索引**:
   `FUN_0064ab10` / 裸地址 `0064ab10`(`@addr` 内部标号亦可)/ 符号名
   `s_CheckList_534e62`。纯 moc 声明类(无独立函数体)用一句
   「出处:QMetaObject 元数据」说明。**既无地址也无说明 = 违规**,
   `tools/re/coverage.py --audit` 会报出来。
2. **bug 原封不动**:不修、不美化、不"顺手改进"。原版有 bug 就是我们的 bug。
   发现疑似 bug 只**记录**到 `docs/quirks.md`,**不修**。
3. **禁止捏造**:语料里没有的行不写。不确定时用 `// cited` 标记空实现,
   宁可留空也不猜。
4. **禁用脚本批量替换 case 体**:每条 case 手工读语料、手工写。脚本只做机械
   收尾(行号定位、重复检查、括号平衡)。
5. **以语料裁决,不按教科书**:出现"这里好像不对"时,先回语料确认原版就是
   这样;是原版怪癖 → 记 `docs/quirks.md` 并保持原样。**禁止**按"终端/编辑器
   应该怎样"改代码。
6. **产品代码零自研**:`src/` 内每一行为必须有落点 —— 语料函数转写(引地址/
   行号)或 `cited` 空实现;开源码移植须 `docs/calibration.md` 逐句同构记录。
   **由实验、推测或工程便利引出的行为代码一律禁止入库**;组件类无转写则整体
   退回 `cited` 空壳,宁可空缺不可自造。
7. **不编译、不测试(最高优先级)**:每批只做**语料转写 + 引用出处 + commit**。
   禁止 `cmake`/`make`、禁止写测试、禁止跑任何测试二进制。语法/类型/链接
   错误一律留到构建期集中处理。背景:编译+测试周期曾占 ~90%,拖死推进。
8. **只提交,不主动推送**:push 仅在用户明示时执行,届时必带
   `-c http.proxy=http://192.168.1.106:7890`。commit 与 push 永不同命令。

> 构建与测试**不在本文件范围**:何时编译、如何链接、收尾期顺序,一律按用户
> 当时的指令执行。`tests/` 已删除,不恢复、不新增。

## 4. 工作重心

- **重心 = 逆向代码落地**(语料 → `src/`),不是写文档、不是写测试。
- 文档按**里程碑**更新(不逐批流水);结论只进 `docs/`。
- 取证优先于猜测:语料 > kuna 反编译 > IDA spot check。

## 5. 分层体系(三档)

| 档 | 标记 | 何时升级 |
|---|---|---|
| 真实现 | 无标注(默认) | 反编译已解、语义可写 |
| 转发 | `→ FUN_XXXX(…)` | 目标已被真身化,此函数仅重定向 |
| 引用(cited) | `// FUN_XXXX — cited` | 体量 >500B 或下行层未开,标注入口地址即可 |

引用档 → 真实现 = 读语料 entry → 转写为代码 → 删除 cited 标记。

## 6. 工具优先

| 工具 | 用途 |
|---|---|
| `tools/re/decomp/*.c`(49M) | **主语料**:每函数有 `entry=ADDR name=NAME size=N` 头,`grep -n "entry=..."` 直达 |
| `tools/re/xref_scan.py` | 交叉引用:调用者 / 导入 |
| `tools/re/ehframe_fdes.py` | 30566 函数边界(零重叠) |
| `tools/re/qmo_extract.py` | QMetaObject:类/方法/Q_ENUM(**值权威**) |
| `tools/re/vtable_scan.py` | vtable → typeinfo → **真实类名**(715 条);`--vtable`/`--addr` 查单体 |
| `tools/re/coverage.py` | **全仓覆盖索引**:`--addr <地址>` 查该函数是否已转写;`--dups` 重复实现;`--check` 出处有效性 |
| kuna CLI(`~/.local/share/rea/bin/kuna`) | 反编译(支持 `--addr`);Ghidra 12.1.4 包装 |
| `objdump -d --start-address=… --stop-address=…` | **折叠实参必回 asm 取寄存器**(踩坑 18) |
| `pkill -f 'pat[t]ern'` | 杀进程用括号法,避免自匹配(踩坑 15) |
| IDA(若开着) | 基址差 `−0x400000`;仅 spot check |

## 7. 已踩坑(重复同样的错就在这里追加)

> 2026-11-16 重整:构建/测试类条目已移除(不再适用),余下按出现序重编号 1-18。

### 1. 变量偏移猜错 → 回归二进制
- **+0xb8** 曾以为是 "style 字符串指针",实际是 `m_sgrBits`(SGR 64 位属性
  状态)。三源互证(0x7e2e2 调用 / 0x8a5 写 / 0x7f8 读)后才定案。
- **教训**:偏移语义必须 **≥2 源一致** 才可写。

### 2. 同一偏移挂两个成员
- **+0xb8** 曾同时挂 `m_stateB8(void*)` 和 `m_sgrBits(u64)`,后者才对。
- **教训**:新成员先 `grep "0xXXX"` 查是否已有。

### 3. 静态函数必须先声明后使用
- `eA235ce` 曾定义在 `editorSelDtor` 之后导致编译错。
- **对策**:文件头部集中前向声明区(`// fwd:` 段)。

### 4. 重复定义:stub 与真实现共文件
- 真身化前先 `grep -n "函数名" src/Sessions/*.cpp`(尤其 `gen_stubs.cpp`),
  有旧 stub 则删该行再加真身。

### 5. 头文件函数签名不一致
- `option()` 三个重载与 `remove*` 族在 `SuperSession.h` 曾有两份。
- **教训**:改头文件先 `grep -n "函数名"` 确认唯一声明点。

### 6. 嵌入字符串 ≠ 库版本
- 主二进制含 spdlog/jsoncpp/yaml-cpp 特征串 ≠ 用了同版本源码。
- **对策**:拉上游源码后 `diff` 头文件/特征串与仓库,或用源码唯一串命中二进制
  定版本(69/278、56/114 命中率)。**零 diff 才入库**。

### 7. 反编译 warning 不是 error
- `warning: cast to pointer from integer` 等(如 `Screen.cpp` paletteColor)
  **不修** —— 原封不动原则;语料里的 Ghidra 告警只是反编译器痕迹。

### 8. bash 引号嵌套
- `'` 内嵌 `'` 会 break。**对策**:长命令用 heredoc;`awk` 变量用 `-v`;
  `sed` 大段用 `python3 - <<EOF`。反引号 `` ` `` 会被求值 —— commit message
  里含 `` `ret` `` 这类内容时用单引号包裹整条 message。

### 9. 全局作用域污染
- 生成器曾把 stub 写到全局作用域,与真实现撞名。
- **对策**:同第 4 条 —— 写 stub 前先 grep 真实现。

### 10. EditorEngine 混合架构边界
- 标准 `SCI_*`(≤4033)走 `scintillaDelegate`(真 Scintilla);
  WindTerm EXT/WT(≥20163)走 `customDispatch`(逆向实现)。
- **不要把 `SCI_*` 移入 customDispatch**,那是重复 Scintilla;fork 独有特性
  才写 custom。

### 11. QMetaObject 枚举值权威
- Q_ENUM 注册表(`qmo_extract.py`)> 声明池字符串。
- 曾把声明序当值(全错),后从 QMetaObject 精确读回。

### 12. CASE 注释勿丢:标签行是唯一溯源
- `docs/subsystems/editor-engine-commands.md` 的 case 标签注释是**唯一反向
  溯源**(没有函数名只有 cmd)。改代码时 case 标签行**绝对不能删**。

### 13. 规范执行惯性:修订后首轮必自查
- **错**:"只提交不主动推送"修订落库后,下一轮收尾仍惯性 push 一次
  (且报告称"补执行纪律条目"实际未补 —— 两次失守)。
- **对策**:每轮 commit 后 `git status` + `git log origin/dev..dev` 自查领先量;
  push 仅以用户明示为触发词。修订类指令生效的第一轮,收尾前**显式复述该指令**
  一遍再提交。
- **机械对策**:commit 与 push 永不在同一条命令行;push 前必须能在本轮用户
  消息里找到"推送/push"字样,找不到 = 不执行。

### 14. 参考材料删除判据:复刻完成前不动
- **错**:"构建未引用 = 可删" —— 曾据此删 `inc/`(23MB 头文件快照)与
  Onigmo/libonig.a,用户复核后恢复。
- **判据**:`inc/` 类参考材料的价值在**逆向参考**,不在构建。未复刻子系统的
  头文件/API 快照 = 该子系统复刻时的**版本对齐锚点**。
- **原则**:参考性材料删除 = 该子系统复刻完成并通过行为对比之后;提交前自问
  "复刻时是否需要它当 API 文档"。
- **例外口径**:`docs/ext-boundary.md` 登记的外部库(yaml-cpp/jsoncpp/libssh/
  Onigmo/spdlog/fmt/dtl)**不逆向**,其上游 `test/`/`examples/` 树不属反向
  参考 → 已按 `docs/cleanup.md` 移除;库**实现源码与头**保留。

### 15. pkill -f 自匹配误杀自身命令
- **错**:`pkill -f phase5_dump` 连自己 shell 一并 SIGTERM(命令行含同串)。
- **对策**:括号法 `pkill -f 'phase5_[d]ump'`(正则不匹配字面括号串)。

### 16. 连续锚点编辑互相踩 + 分支体误删
- **错**:多轮 python 锚点编辑同一分支,条件修复时误删分支体(H/7/8 落入
  默认 glyph 路径 → u=27 族),数轮修改互相覆盖。
- **对策**:每轮编辑后 `grep -n -A14` 复核分支完整性;连续编辑同一函数时改用
  **单次全函数重写**。
- **补充**:模板式 `replace()` 会静默不命中 —— 改完必须 `cat`/`sed -n` 复核
  (2026-11-16 两次因未复核漏改头文件)。

### 17. QByteArray(const char*) 在 \x00 截断
- **错**:`QByteArray("\xff\xfa\x18\x00...")` 被 strlen 截断于 `\x00`,
  只进 3 字节(曾致 telnet 子协商不触发的假象)。
- **对策**:含 `\x00` 的字节流用显式长度构造 `QByteArray(lit, sizeof(lit)-1)`。

### 18. 折叠实参必须回 asm(2026-11-16)+ 仪器前提未核即裁决
- **折叠实参**:Ghidra 把 `QFormLayout::addRow(（QWidget *）this)` 这类输出的
  实参吞掉,按"最合理"猜会错(曾致八页 `setFocusProxy` 目标全错、`addRow`
  源对象错位)。**对策**:凡折叠实参,**回 `objdump` 取寄存器**,不许猜。
- **仪器前提**:tbc3 连读众数"停手"裁决曾测于**未复位流态**,结论与带复位
  重测相反。**对策**:任何"原版确定行为"裁决前,先核对测量脚本的状态前提
  (reset/基线/会话隔离),实验脚本尽量 import 主驱动的 baseline()。

## 8. 反编译语料结构

```
tools/re/decomp/decomp-part-NNNN.c
// ==== entry=00XXXXXX name=FUN_00XXXXXX size=N ====
<类型> FUN_00XXXXXX(...)
```

- 每个 `.c` 文件按地址升序排 entry;
- `grep -n "entry=ADDR"` 拿行号,`sed -n` 截函数体;
- 反编译器:Ghidra 12.1.4(`-revoke` 不可重入,一次性导出);
- 源二进制 = `./WindTerm`(见 §0)。

## 9. 领域知识锚点(索引见 `docs/index.md`)

| 子系统 | 关键文件/文档 |
|---|---|
| 终端状态机 | `docs/subsystems/state-machine.md`;`Screen.cpp`(SGR/DECSM 等) |
| SSH 认证 | `docs/subsystems/ssh-internals.md`;`SuperSessionPrivate.cpp` |
| Scintilla 内核 | `src/Scintilla/src/`(上游源码)+ `docs/subsystems/editor-engine-commands.md` |
| 会话/工作区 | `docs/subsystems/session-config-layer.md` |
| 终端配置 | `CTerminalConfig` 单例(0x00809d78);`wind.config`=JSON |
| King 枚举 | `src/Utility/KingEnums.h`(45 枚举全值域,QMetaObject 权威) |
| 外部库边界 | `docs/ext-boundary.md`(不逆向清单 + 版本) |
| 界面重建 | `tools/re/gui-map.md`(七节总账)+ `docs/pending-attribution.md` |
| 语料怪癖 | `docs/quirks.md`(原版 bug 台账,勿修) |
| src 三类归属 | `src/README.md`(逆向重建 / 第一方开源 / 第三方库) |

## 10. 混合架构边界(不要越线)

```
QVariant dispatch(cmd, a, b)
 ├─ cmd ≥ 20163 (EXT/WT)  → customDispatch     ← WindTerm 自有(逆向)
 └─ cmd ≤ 4033 (标准 SCI) → scintillaDelegate  ← 真 Scintilla 4.4.6
                             ↑
               不要把 SCI_* 移入 customDispatch
               不要把 EXT/WT 移入 scintillaDelegate
```

同一策略适用于 **libssh**(认证族委托真库)与 **yaml-cpp**(ConfigBridge
委托真库):**标准行为委托真库,fork 特性才逆向自研**。

## 11. 外部库边界

- **第一方开源件(B 类)与逆向代码混放,不做物理分目录**。识别靠三条显式标记:
  文件头 `// [B-OPENSOURCE] …`、清单 `tools/re/data/open_source_files.txt`、
  校验 `tools/re/coverage.py --audit`。**看到标记就别逆向** —— 直接按
  `docs/calibration.md` 移植。新增/移动文件后跑一次 `--audit`。
- **外部资产三归属**:被编译的源码进 `src/<lib>/`;只对齐 API 的头快照进 `inc/<lib>/`;
  运行时才用的程序/数据留 `vendors/<name>/`(如 lrzsz)。判据与清单见
  `docs/ext-boundary.md`。
- 静态嵌入的开源库(boost/yaml-cpp/jsoncpp/dtl/zstd/fmt+spdlog)
  **实现不逆向**;命中见 `docs/ext-boundary.md` → 标记边界、转写调用接口面
  (`src/Ext/` 声明层),行为由委托真库或 no-op 承接。
- 例外:外库数据布局被 WindTerm 业务消费的部分(SGR 位/行格)仍属逆向范围。

## 12. 提交规范

- **中文 commit**;一条 commit 对应一批改动 + 相应 `.md` 更新。
- **只提交,不主动推送**(push 仅用户明示 + 代理参数,见铁律 8)。
- 收尾前自查:`git status` 干净 + `git diff --shortstat` 与报告一致。
