# AGENTS.md — WindTerm 逆向工程指南

> 目标:完全逆向 WindTerm 2.7.0(含 bug 原封不动)。所有代码必须有出处
> (逆向地址),禁止捏造。本文件是 agent 会话必读,总结了多轮反复
> 踩坑后的方法论与约束。
>
> 冷启动顺序:本文件 → `tools/re/HANDOFF.md`(状态快照)→ `docs/PLAN.md`(待收口清单)。

## 铁律

1. **每行代码有出处**:真实现引用 `FUN_XXXXXXXX` 或 `name@地址`;
   thunk 引用反向表项;文档引用 docs/IMPL-*.md。没地址不写。
2. **bug 原封不动**:不修、不美化、不"顺手改进"。原版有 bug 就是
   我们的 bug。发现疑似 bug 时**记录**到对应的 .md,**不修**。
3. **禁止捏造**:反编译语料里没有的行不写。不确定时用
   `/* cited — wave-2 */` 标记空实现,宁可留空也不猜。
4. **禁用脚本批量替换 case 体**。每条 case 手工读语料、手工写。
   脚本只做机械收尾(如 sed 行号定位、重复检查)。
5. **测试断言语料行为,不断言教科书行为**(2026-10-28 增):失败的
   测试按 docs/QUIRKS.md 裁决流程处理——语料证明转写错则修代码,
   原版怪癖则修测试并登记怪癖清单。禁止按"终端应该怎样"修。

## 分层体系(三档)

| 档 | 标记 | 何时升级 |
|---|---|---|
| 真实现 | 无标注(默认) | 反编译已解、语义可写 |
| 转发 | `→ FUN_XXXX(…)` | 目标已被真身化,此函数仅重定向 |
| 引用(cited) | `// FUN_XXXX — cited` | 体量 >500B 或下行层未开,标注入口地址即可 |

引用档到真实现的升级 = 读语料 entry → 转写为代码 → 删除 cited 标记。

## 构建(CMake,2026-10 起)

```bash
mkdir build && cd build
cmake .. && make -j$(nproc)   # → libWindTermRe.so;增量 <2s
```

- **外部静态库已预构建入库** `lib/*.a`(20MB:scintilla_core 16M +
  scintilla_qt 754K + yaml-cpp 923K + jsoncpp 438K + onig 2.1M)。
  默认直接链接,不重编。仅上游更新时 `cmake .. -DBUILD_DEPS=ON
  && make rebuild_deps` 重编入 lib/。
- **新增 .cpp/.h 后必须重跑 `cmake ..`**:GLOB 无 CONFIGURE_DEPENDS,
  make 不会自动发现新文件。
- moc 自动检测(CMakeLists 内 grep Q_OBJECT),新 Q_OBJECT 头零配置。
- 环境:系统 Qt 头 5.15.13 × 仓库 lib/ Qt 5.15.2 = ABI 同代直接链;
  `inc/qt5`(转发头)与 `inc/boost`(残缺)已删,**一律用系统头**。
- 手工 g++ 配方(不走 CMake 时)见 `tools/re/BUILD.md`。
- Scintilla 混合:src/Scintilla(4.4.6)承接标准 SCI_*;
  WindTerm EXT/WT(≥20163)在 EditorEngine::customDispatch。

## 验证管线(每轮必须跑)

```bash
# 编译+链接(CMake 一条覆盖)
cmake --build build

# 加载零 undefined
LD_LIBRARY_PATH=build:lib QT_QPA_PLATFORM=offscreen \
  python3 -c "import ctypes; ctypes.CDLL('build/libWindTermRe.so'); print('dlopen OK')"
```

冒烟源码在 `tools/re/metatest/`(engtest/engtest2/sshsmoke/scismoke,
需离屏 QApplication),未接 CMake,手工 g++ 按需编。全绿才提交。

## 工具优先

| 工具 | 用途 |
|---|---|
| `tools/re/decomp/*.c`(49M) | **主语料**:每函数有 `entry=ADDR name=NAME size=N` 头,`grep -n "entry=..."` 直达 |
| `tools/re/xref_scan.py` | 交叉引用:调用者/导入 |
| `tools/re/ehframe_fdes.py` | 30566 函数边界(零重叠) |
| `tools/re/qmo_extract.py` | QMetaObject:类/方法/Q_ENUM(值权威) |
| `tools/re/gen_stubs.py` | 链接器 mangled → stub 定义 |
| kuna CLI(`~/.local/share/rea/bin/kuna`) | 反编译(优于 grep 语料,支持 `--addr`);Ghidra 12.1.4 包装 |
| IDA(若开着) | **基址差:IDA = Ghidra − 0x400000**;仅 spot check |

反编译语料优先于 kuna(免重复反编译),kuna 优先于 IDA(免基址差)。

## 已踩坑(每次重复同样的错就在此追加)

### 1. 变量偏移猜错 → 回归二进制
- **+0xb8**:曾以为是 "style 字符串指针",实际是 `m_sgrBits`
  (SGR 64 位属性状态)。三源互证(0x7e2e2 调用/0x8a5 写/0x7f8
  读)后才定案。**教训**:偏移语义必须 ≥2 源一致才可写。

### 2. 同一偏移挂两个成员
- **+0xb8** 曾同时挂 `m_stateB8(void*)` 和 `m_sgrBits(u64)`。
  后者才是正确的。**教训**:新成员先 `grep "0xXXX"` 查是否已有。

### 3. 函数声明顺序:静态函数必须先声明后使用
- `eA235ce` 在 editorSelDtor 之后定义,调用编译错。
  **对策**:文件头部集中前向声明区(已制度化,见 EditorEngine.cpp
  `// fwd:` 段)。新增静态函数写在这里。

### 4. 重复定义:stub 与真实现共文件
- 真身化一个函数前,先 `grep -n "函数名" src/Sessions/*.cpp`
  (尤其 gen_stubs.cpp),有旧 stub 则删该行再加真身。

### 5. 头文件函数签名不一致
- `option()` 三个重载与 `remove*` 族在 SuperSession.h 有过两份。
  **教训**:修改头文件先 `grep -n "函数名"` 确认唯一声明点。

### 6. 嵌入字符串≠库版本
- 主二进制含 spdlog/jsoncpp/yaml-cpp 特征串 ≠ 用了同版本源码。
  **对策**:拉上游源码后 `diff` 其 Scintilla.h / 特征串
  与仓库头;或用源码唯一串命中二进制(69/278,56/114
  命中率定版本)。零 diff 才入库。

### 7. 反编译 warning 不是 error
- `warning: cast to pointer from integer` 等存在(如 Screen.cpp
  paletteColor)。**不修**——原封不动原则;确认不阻塞编译即可。

### 8. bash 引号嵌套
- `'` 内嵌 `'` 会 break。**对策**:长命令用 heredoc 或
  分号拆短命令;`awk` 变量用 `-v`;`sed` 大段用 `python3 - <<EOF`。

### 9. undefined symbol 迭代
- 链接报 undefined → `gen_stubs.py` 生成 stub → 重链 → 可能
  又报新 symbol。**这是正常流程**。收敛条件:dlopen OK。

### 10. 全局作用域污染
- 生成器曾把 stub 写到全局作用域,与真实现撞名。
  **对策**:同第 4 条——写 stub 前先 grep 真实现。

### 11. EditorEngine 混合架构边界
- 标准 SCI_* (≤4033) 走 scintillaDelegate(真 Scintilla);
  WindTerm EXT/WT (≥20163) 走 customDispatch(逆向实现)。
  **不要把 SCI_* 移入 customDispatch**——那是重复 Scintilla。
  fork 独有特性才写 custom。

### 12. QMetaObject 枚举值权威
- Q_ENUM 注册表(qmo_extract.py)> 声明池字符串。
  曾把声明序当值(全错),后从 QMetaObject 精确读回。

### 13. CASE 注释勿丢:标签行是唯一溯源
- EDITOR-ENGINE-COMMANDS.md 的 case 标签注释是**唯一
  反向溯源**(没有函数名只有 cmd)。改代码时 case 标签
  行绝对不能删。

### 14. moc 的两个坑
- moc 不支持同名同参、仅返回类型不同的重载(`void option(QString)`
  与 `QVariant option(QString)` 共存 → moc 生成 `QVariant _r =`
  编译错)。删 void 版或改名。
- 头文件的方法签名用到 QVariant/QByteArray 等作参数或返回时,
  必须 `#include <完整头>`;前置声明不够——moc 生成的
  `reinterpret_cast` 需要完整类型。

### 15. 手工编的测试二进制会因 ABI 失配崩溃
- `tools/re/metatest/` 下的测试是手工 g++ 编的;改了含内联成员
  访问的头(如 EditorEngine 加成员)后,旧二进制按旧偏移读新库
  → 段错误,极易误判为库回归。
- **对策**:改头文件后必须重编测试二进制再跑;判断法——崩溃
  先重编测试,若仍崩才是真回归。
- **补充(2026-10-28)**:测试结果**时好时坏**时,优先怀疑重构
  类的构造器漏初始化成员(如 TerminalCore m_flags、Screen
  m_insertMode)——垃圾位使 wrap/IRM 等检查非确定翻转;ASLR 会
  让它看起来像"陈旧二进制"。两类问题都要排:重编测试 + 全成员
  显式清零。

## 反编译语料结构

```
tools/re/decomp/decomp-part-NNNN.c
// ==== entry=00XXXXXX name=FUN_00XXXXXX size=N ====
<类型> FUN_00XXXXXX(...)
```

- 每个 `.c` 文件按地址升序排 entry
- `grep -n "entry=ADDR"` 拿行号,`sed -n` 截函数体
- 反编译器:Ghidra 12.1.4(-revoke 不可重入,生成一次性导出)

## 逆向领域知识锚点(文档在 docs/)

| 子系统 | 关键文件/文档 |
|---|---|
| 终端状态机 | docs/STATE-MACHINE.md;Screen.cpp(SGR/DECSM 等) |
| SSH 认证 | docs/SSH-INTERNALS.md;SuperSessionPrivate.cpp |
| Scintilla 内核 | src/Scintilla/src/(上游源码)+ docs/EDITOR-ENGINE-COMMANDS.md(336 命令) |
| 会话/工作区 | docs/SESSION-CONFIG-LAYER.md(装载器/管理器/schema) |
| 终端配置 | CTerminalConfig 单例(0x00809d78,199 处);wind.config=JSON |
| King 枚举 | src/Utility/KingEnums.h(45 枚举全值域,QMetaObject 权威) |
| 三大静态库 | spdlog(+fmt)/jsoncpp 1.9.4/yaml-cpp 0.6.3(BUILD.md 审计表) |

## 混合架构边界(不要越线)

```
QVariant dispatch(cmd, a, b)
 ├─ cmd ≥ 20163 (EXT/WT)  → customDispatch     ← WindTerm 自有(逆向)
 └─ cmd ≤ 4033 (标准 SCI) → scintillaDelegate  ← 真 Scintilla 4.4.6
                             ↑
               不要把 SCI_* 移入 customDispatch
               不要把 EXT/WT 移入 scintillaDelegate
```

同一策略适用于 libssh(认证族委托真 libssh)与 yaml-cpp(ConfigBridge
委托真库):**标准行为委托真库,fork 特性才逆向自研**。

### 16. 参考材料删除判据:复刻完成前不动(2026-10-29)
- **错**:"构建未引用 = 可删"——曾据此删 inc/(23MB 头文件快照)
  与 Onigmo/libonig.a,用户复核后恢复。
- **判据**:inc/ 类参考材料的价值在逆向参考,不在构建。未复刻
  子系统的头文件/API 快照 = 该子系统复刻时的版本对齐锚点
  (如 spdlog/fmt 之于 loggerOp 面)。
- **原则**:参考性材料删除 = 该子系统复刻完成并通过行为对比
  之后;提交前自问"复刻时是否需要它当 API 文档"。

## 提交规范

- 中文 commit,force push 需覆盖远端 dev
- push 必带 `-c http.proxy=http://192.168.1.106:7890`
- 每轮:改动 + 对应 .md 更新,**一条 commit 一条 push**
