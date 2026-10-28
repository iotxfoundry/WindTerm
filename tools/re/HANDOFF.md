# 新会话起点(交接文档)

> 用途:新会话冷启动。先读本文件 + AGENTS.md + docs/PLAN.md,即可无缝续作。

## 一句话状态(2026-10-28 终态)

**CMake 构建体系达成**:静态库(lib/*.a 20MB)入库,CMake 默认直接
链接,增量编译 0.08s。libWindTermRe.so 8.82MB,dlopen OK,三冒烟全绿。

里程碑链:语法自洽 → moc → 编译 → 链接 → dlopen → 元对象活性 →
**CMake 化 + 静态库入库**。下一步:docs/PLAN.md Phase 1(Screen 收口)。

## 目录结构(2026-10-28 归位后)

```
src/
  Sessions/   ← 会话层(Super*族 + TerminalCore + Screen + gen_stubs.cpp)
  Editor/     ← 编辑引擎(EditorEngine 混合层 + ConfigBridge)
  Widgets/    ← 视图壳(Terminal*/Editor*/TextView/TextEdit/Pane*)
  Utility/    ← 通用(KingEnums + Cryptographic + ThreadLocal)
  Protocols/  ← 协议(Telnet)
  Pty/        ← 串口
  libssh/     ← libssh 0.9.6+补丁(源码树)
  Onigmo/     ← Onigmo 5.13.5+迭代器补丁(源码树)
  Scintilla/  ← Scintilla 4.4.6(上游源码树)
  jsoncpp/    ← jsoncpp 1.9.4(上游源码树)
  yaml-cpp/   ← yaml-cpp 0.6.3(上游源码树)
lib/          ← 原版 .so + 预构建 .a(20MB,git 管理)
inc/          ← 运行时配套头(23M;boost/qt5 已删)
docs/         ← 逆向知识文档(18 .md)
tools/re/     ← 逆向工具链 + BUILD.md + AGENTS.md
```

## 构建体系(CMake,2026-10-28)

```bash
# 默认(clone 后直接):
mkdir build && cd build
cmake .. && make -j$(nproc)
# → libWindTermRe.so 8.82MB;增量 0.08s

# 重编外部依赖(仅上游更新时):
cmake .. -DBUILD_DEPS=ON && make rebuild_deps
# → 重编 Scintilla+yaml-cpp+jsoncpp 到 lib/*.a

# 可选测试:
cmake .. -DBUILD_ENGTEST=ON && make engtest
```

lib/ 下预构建 .a(20MB):libscintilla_core(16M)+ libscintilla_qt(754K)
+ libyaml-cpp(923K)+ libjsoncpp(438K)+ libonig(2.1M)。

## 逆向架构总览

### 终端栈(全部真实现)
```
SuperCommander(259/259) → Screen(~95 方法) → TerminalCore(~60 方法)
                                          → 单元格层(0x20 字节/格)
```

### 编辑引擎(混合架构)
```
EditorEngine::dispatch(cmd, a, b)
 ├─ cmd ≥ 20163(EXT/WT)→ customDispatch     ← WindTerm 自有(逆向,22 已真身)
 └─ cmd ≤ 4033(标准 SCI)→ scintillaDelegate  ← 真 Scintilla 4.4.6 静态库
```

### 认证族(混合架构)
```
SuperSession::auth*(14 个)→ SuperSessionPrivate → 真 libssh API
```

### 配置桥(混合架构)
```
ConfigBridge.cpp:yamlToQVariant → vendored yaml-cpp 0.6.3
```

## 环境

| 项 | 值 |
|---|---|
| 目标二进制 | /opt/WindTerm_2.7.0/WindTerm(仓库根有副本) |
| Ghidra 12.1.4 | 自动引擎 |
| IDA Pro 9.1 | 深度;**基址差:IDA = Ghidra − 0x400000** |
| kuna CLI | ~/.local/share/rea/bin/kuna |
| GitHub 代理 | 192.168.1.106:7890(push 必带 `-c http.proxy=…`) |
| 提交规范 | 中文,每轮一条 commit 一条 push |

## 转写方法(AGENTS.md 铁律)

0. 工具优先:tools/re/decomp/(49M 主语料)> kuna > IDA
1. `grep -n "entry=ADDR"` 定位函数 → sed 截函数体
2. 真实现写入正确目录(src/Sessions|Editor|Widgets|Utility)
3. 每行代码引用 `FUN_XXXXXXXX` 或 `// cited` 标记
4. 分批提交(中文信息)

## 已还原资产索引

- `docs/*.md`:SSH-INTERNALS / PROTOCOL-ARCHITECTURE / STATE-MACHINE /
  TERMINAL-CORE / IMPL-ADDRESSES / SUPERCOMMANDER-IMPL /
  EDITOR-ENGINE-COMMANDS(336 命令) / EDITOR-SCINTILLA-MAP(120 真名) /
  SESSION-CONFIG-LAYER / SCREEN-SIGNALS / TEXTVIEW-* / KING-ENUMS /
  CLASSES-SWEEP / MOC-NAMES
- `src/Utility/KingEnums.h`:45 枚举权威值
- `tools/re/`:全部逆向工具 + 49M 反编译语料 + data/(方法表/调用点)
- `AGENTS.md`:完整方法论 + 13 项踩坑
- `docs/PLAN.md`:202 项待收口计划(Phase 1-5)

## 已知开放问题

- `King::DataType`:无 Q_ENUM 注册,值域需代码反推
- keymap 方言表(DECDSR 26):三字节运行期取值,静态封箱
- Screen.cpp 38 cited(Phase 1 目标)
- EditorEngine customDispatch ~40 fork 特性(Phase 3 目标)
- UI 装配(Phase 4-5 目标)
