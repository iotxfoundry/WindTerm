# 逆向完成计划(plan)

> 目标:编译出与 /opt/WindTerm_2.7.0/WindTerm 行为一致的程序。
> 每阶段完成打 ✅,进行中标 ⏳,未开始标 ⬜。
> 完成判定:所有已实现功能在离屏/实机下行为与原二进制一致。

---

## Phase 0 — 已完成 ✅

- [x] 语法自洽(Sessions/Widgets/Protocols/Utility 全 .cpp 0 错)
- [x] moc 22/22 零错
- [x] libWindTermRe.so 9.08MB,dlopen OK
- [x] 三冒烟全绿(engtest2/engtest/sshsmoke)
- [x] 五源码树入库(libssh/Onigmo/Scintilla/jsoncpp/yaml-cpp)
- [x] Scintilla 静态库(16.5+0.6MB)混合架构验证
- [x] King 45 枚举权威值域
- [x] 终端栈 Commander→Screen→TerminalCore 全真实现
- [x] 编辑引擎 336 命令混合架构(真 Scintilla + 自研 EXT/WT)

---

## Phase 1 — Screen 层收口 ⏳(38 cited 空体)

**文件**:`src/Sessions/Screen.cpp`(~2700 行)
**方法**:每函数 grep 语料 entry → 转写真身 → 删 cited 标记

### 1a. DEC/VT 报告族 ⬜
| 函数 | 地址 | 体量 | 语义 |
|---|---|---|---|
| requestDecMode(int) | 0x00a5? | ~200B | DECRQM 查询/设置 |
| requestTerminalStateReport | 0x007f0d7c | 1482B | DECDSR 主报告 |
| requestUserPreferredSupplementalSet | 0x007e4ac2 | ~80B | SCUSS |
| requestXtermTerminfoData | 0x007e66? | ~100B | XTGETTCAP |
| requestLocatorPosition | 0x007e2f3e | 20B | DECLRP |
| requestDisplayedExtent | 0x007e5b96 | 12B | DECRQDE |
| requestKeyModifier | 0x007e5152 | ~40B | DSR modifier |
| selectStatusLineType | 0x007e87c8 | 232B | DECLTLM |

### 1b. 配置/通知族 ⬜
| 函数 | 语义 |
|---|---|
| notifyOsc(kind, payload) | OSC 终端操作(0x4c3290 split PLT 路径) |
| notifyZmodem(state, dir) | FUN_0091378a → 信号 |
| notifyCommand / notifyCursorStyle / notifyMessageEx | Screen 信号族(moc 权威) |
| notifyNamedAttribute | FUN_007ee9e2 |
| markLocatorChanged | FUN_007e2f3e(20B)→ 信号 |
| setWindowIconAndTitle / setWindowTitleBuffer | 窗口元数据 |

### 1c. 解码/样式族 ⬜
| 函数 | 地址 | 语义 |
|---|---|---|
| attrKey / sgrKey | 0x007e515e | 属性→key 映射(缓存) |
| charsetDisabled / charsetLookup | 0x008034a4 | 字符集校验/查找 |
| conformanceKey | 0x007e5ad0 | 协议级(已解:cached+0x124) |
| codecFromUnicode / codecToUnicode | 0x0091318c | 超级编解码器桥 |
| widthFromTables | 0x007a4692 | 宽度双表查找 |
| splitParams | 0x007e5c98 → | QByteArray::split(';') |

### 1d. 滚动/区域 ⬜
| 函数 | 语义 |
|---|---|
| resizeScreen(rows, cols, flag) | FUN_007e5688 |
| scrollbackModeCheck | FUN_007e4028 |
| selectActiveStatusDisplay | 状态行选择 |
| selectNumberOfLinesOnScreen | 行数设置 |
| setColumnsPerPage | FUN_007e61fa(DECSCPP) |
| setLinesPerPage | FUN_007e62? (DECSLPP) |
| filterRectangle | FUN_007eb2ac |
| convertRowToHistory | FUN_007a9582 |
| appendHistoryBlock | FUN_007e4368 |
| mediaCopyDec | FUN_007eb20a |
| zmodemTick | FUN_0091378a |

**完成标准**:Screen.cpp grep "cited" = 0。

---

## Phase 2 — TerminalCore / SuperSession 收口 ⬜

### 2a. TerminalCore 剩余 cited(5 个)⬜
| 函数 | 地址 | 语义 |
|---|---|---|
| charsetConfigRoot | 0x00802bda | 字符集管理器根 |
| cursorUpdated | 0x007e51e6 | 光标更新信号 |
| markLine(int) | ? | 行标记 |
| setCursorStyle(int, bool) | 0x007e4ffa | DECSCUSR |
| slot0Allowed(int) | 0x00802c80 | G0 校验 |

### 2b. SuperSession 管家真链 ⬜
当前 SuperSessionPrivate 中 removeRegistry/loggerOp 是最小可用空实现。
需接真下层:四注册表(QHash<QUuid, obj>)→ 信号发射(commanderCreated 等)。
option/setOption → CTerminalConfig 单例读写(SESSION-CONFIG-LAYER.md ①)。

### 2c. TextView 收口 ⬜
TextView.h 中 `property()/setProperty()/schemeName()/find()` 4 函数
(cited 档,上游接口已定,真实现可用 Qt 原生容器替代)。

---

## Phase 3 — 编辑引擎 customDispatch 收口 ⬜

当前状态:22 个 WT 命令已真身;其余 ~40 个 fork 特性返回 0。
**方法**:EDITOR-ENGINE-COMMANDS.md 逐条对照 Scintilla 公共 API,
有等价则接 `scintillaDelegate`,无等价则写真逻辑。

### 3a. 已定名的 WT 命令(有 Scintilla 等价)⬜
| WT cmd | Scintilla API | 语义 |
|---|---|---|
| 0x7591 margins() | SCI_MARGINGETCOUNT 等 | margin 列表 |
| 0x75b8 selectionText | SCI_GETSELTEXT | (已有,接公共) |
| 0x75bf canRedo | SCI_CANREDO | (已有) |
| 0x75c1 tabSize | SCI_GETTABWIDTH | (已有) |
| 0x75c4 setTabSize | SCI_SETTABWIDTH | (已有) |

### 3b. fork 特有(需逆向转写)⬜
0x7545 scrollbar mark / 0x7551 appendText / 0x7556 charsetDisabled /
0x7559 collect / 0x755a setString / 0x755c-0x7560 元数据 /
0x7567 zoom real / 0x758a type chain / 0x7594 removeMarginByName /
0x7595 clearMargins / 0x75a3 select line range /
0x75b4-0x75b5 pair highlight / 0x75d6 word separators / 0x75e6-0x75fe
(色读出/点变换/runnode/int-QString/后扫描/时间戳/buffer 字段)

---

## Phase 4 — UI 装配 ⬜

### 4a. QApplication 启动路径 ⬜
- CTerminalConfig 单例初始化(FUN_00809d78 + 构造 432B)
- 会话管理器 0x006f571a(QStandardItemModel)连 UI
- 工作区装载器 0x00522056 → Terminal/Editor/Browser 三面板恢复

### 4b. TerminalWidget 组装 ⬜
- ScintillaEditBase 嵌入(Editor 窗口)
- Screen.cpp 接 TerminalCore(SGR/DECSM 状态机→Scintilla 或自研)
- SuperCommander → SuperSession 命令转发(SuperBridge 桥)

### 4c. 主窗口(Kit/TerminalWindow)⬜
- MenuBar/ToolBar/StatusBar 恢复(0x8d2f7e 启动恢复)
- TabGroup/Splitter 联动
- King::Protocol 五态路由(Serial/Shell/Ssh/Tcp/Telnet)

---

## Phase 5 — 行为一致验证 ⬜

### 5a. 离屏终端渲染 ⬜
- 加载 wind.config → CTerminalConfig 填充
- 新建 SuperSession(offscreen)→ 终端渲染序列
- 对比原二进制 offscreen 输出

### 5b. 编辑引擎行为对比 ⬜
- 对同一输入文本:EditorEngine 336 命令 vs 原二进制
  (需原二进制同一 SCI 消息序列回放)

### 5c. 会话持久化对比 ⬜
- .wind/ 目录生成与加载对比

---

## 追踪

| 阶段 | 文件数 | cited 数 | 目标 |
|---|---|---|---|
| Screen.cpp | 1 | 38 | → 0 |
| TerminalCore.cpp | 1 | 5 | → 0 |
| EditorEngine.cpp | 1 | ~40 桩 | → 22 (真身) |
| SuperSessionPrivate.cpp | 1 | 6 | → 0 |
| stubs_remaining.cpp | 1 | 112 行 | → 0 |
| TextView.h | 1 | 1 | → 0 |

| **总计** | ~6 | **~202** | → **0** |
