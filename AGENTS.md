# AGENTS.md — WindTerm 逆向工程指南

> 目标:完全逆向 WindTerm 2.7.0(含 bug 原封不动)。每行代码必须有出处
> (逆向地址 / 语料行),禁止捏造。
>
> **冷启动顺序**:本文件 → `tools/re/handoff.md`(当前态)→ `docs/index.md`
> (文档总目录)→ `docs/plan.md`(阶段)→ `docs/phase5.md` 顶部「结论快照」。

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
  用段感知读取(`tools/re/rd.py` 或 `readelf -SW` 现算),**勿手算**。

## 1. 铁律

1. **每行代码有出处**:真实现引用 `FUN_XXXXXXXX` / `name@地址`;thunk 引反向
   表项;文档引用 `docs/meta/impl-addresses.md`。**没地址不写**。
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

## 2. 工作重心

- **重心 = 逆向代码落地**(语料 → `src/`),不是写文档、不是写测试。
- 文档按**里程碑**更新(不逐批流水);结论只进 `docs/`。
- 取证优先于猜测:语料 > kuna 反编译 > IDA spot check。

## 3. 分层体系(三档)

| 档 | 标记 | 何时升级 |
|---|---|---|
| 真实现 | 无标注(默认) | 反编译已解、语义可写 |
| 转发 | `→ FUN_XXXX(…)` | 目标已被真身化,此函数仅重定向 |
| 引用(cited) | `// FUN_XXXX — cited` | 体量 >500B 或下行层未开,标注入口地址即可 |

引用档 → 真实现 = 读语料 entry → 转写为代码 → 删除 cited 标记。

## 4. 工具优先

| 工具 | 用途 |
|---|---|
| `tools/re/decomp/*.c`(49M) | **主语料**:每函数有 `entry=ADDR name=NAME size=N` 头,`grep -n "entry=..."` 直达 |
| `tools/re/xref_scan.py` | 交叉引用:调用者 / 导入 |
| `tools/re/ehframe_fdes.py` | 30566 函数边界(零重叠) |
| `tools/re/qmo_extract.py` | QMetaObject:类/方法/Q_ENUM(**值权威**) |
| `tools/re/rd.py` | 段感知地址读取(`q`/`d`/`cstr`) |
| kuna CLI(`~/.local/share/rea/bin/kuna`) | 反编译(支持 `--addr`);Ghidra 12.1.4 包装 |
| `objdump -d --start-address=… --stop-address=…` | **折叠实参必回 asm 取寄存器**(踩坑 18) |
| `pkill -f 'pat[t]ern'` | 杀进程用括号法,避免自匹配(踩坑 15) |
| IDA(若开着) | 基址差 `−0x400000`;仅 spot check |

## 5. 已踩坑(重复同样的错就在这里追加)

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

## 6. 反编译语料结构

```
tools/re/decomp/decomp-part-NNNN.c
// ==== entry=00XXXXXX name=FUN_00XXXXXX size=N ====
<类型> FUN_00XXXXXX(...)
```

- 每个 `.c` 文件按地址升序排 entry;
- `grep -n "entry=ADDR"` 拿行号,`sed -n` 截函数体;
- 反编译器:Ghidra 12.1.4(`-revoke` 不可重入,一次性导出);
- 源二进制 = `./WindTerm`(见 §0)。

## 7. 领域知识锚点(索引见 `docs/index.md`)

| 子系统 | 关键文件/文档 |
|---|---|
| 终端状态机 | `docs/subsystems/state-machine.md`;`Screen.cpp`(SGR/DECSM 等) |
| SSH 认证 | `docs/subsystems/ssh-internals.md`;`SuperSessionPrivate.cpp` |
| Scintilla 内核 | `src/Scintilla/src/`(上游源码)+ `docs/subsystems/editor-engine-commands.md` |
| 会话/工作区 | `docs/subsystems/session-config-layer.md` |
| 终端配置 | `CTerminalConfig` 单例(0x00809d78,199 处);`wind.config`=JSON |
| King 枚举 | `src/Utility/KingEnums.h`(45 枚举全值域,QMetaObject 权威) |
| 外部库边界 | `docs/ext-boundary.md`(不逆向清单 + 版本) |
| 界面重建 | `tools/re/gui-map.md`(七节总账)+ `docs/pending-attribution.md` |
| 语料怪癖 | `docs/quirks.md`(原版 bug 台账,勿修) |
| src 三类归属 | `src/README.md`(逆向重建 / 第一方开源 / 第三方库) |

## 8. 混合架构边界(不要越线)

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

## 9. 外部库边界

- 静态嵌入的开源库(boost/yaml-cpp/jsoncpp/dtl/zstd/fmt+spdlog)
  **实现不逆向**;命中见 `docs/ext-boundary.md` → 标记边界、转写调用接口面
  (`src/Ext/` 声明层),行为由委托真库或 no-op 承接。
- 例外:外库数据布局被 WindTerm 业务消费的部分(SGR 位/行格)仍属逆向范围。

## 10. 提交规范

- **中文 commit**;一条 commit 对应一批改动 + 相应 `.md` 更新。
- **只提交,不主动推送**(push 仅用户明示 + 代理参数,见铁律 8)。
- 收尾前自查:`git status` 干净 + `git diff --shortstat` 与报告一致。
