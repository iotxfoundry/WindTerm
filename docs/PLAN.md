# 逆向完成计划(plan)

> 目标:编译出与 /opt/WindTerm_2.7.0/WindTerm 行为一致的程序。
> 每阶段完成打 ✅,进行中标 ⏳,未开始标 ⬜。
> 完成判定:所有已实现功能在离屏/实机下行为与原二进制一致。

---

## Phase 0 — 已完成 ✅

- [x] 语法自洽(Sessions/Widgets/Protocols/Utility 全 .cpp 0 错)
- [x] moc 22/22 零错
- [x] libWindTermRe.so 8.82MB,dlopen OK
- [x] 三冒烟全绿(engtest2/engtest/sshsmoke)
- [x] 五源码树入库(libssh/Onigmo/Scintilla/jsoncpp/yaml-cpp)
- [x] Scintilla 静态库(16.5+0.6MB)混合架构验证
- [x] King 45 枚举权威值域
- [x] 终端栈 Commander→Screen→TerminalCore 全真实现
- [x] 编辑引擎 336 命令混合架构(真 Scintilla + 自研 EXT/WT)
- [x] 目录归位(Sessions 60→48;Editor/Widgets/Utility/docs 分立)
- [x] CMake 构建体系(静态库 lib/*.a 20MB 入库;增量 0.08s)
- [x] AGENTS.md 方法论(4 铁律 + 13 踩坑)
- [x] stubs 统一为 gen_stubs.cpp(~70 行;SuperSession 认证族真身化)

---

## Phase 1 — Screen 层收口 ⏳(38 cited 空体)

**文件**:`src/Sessions/Screen.cpp`(~2700 行)
**方法**:每函数 grep 语料 entry → 转写真身 → 删 cited 标记

### 1a. DEC/VT 报告族 ✅(2026-10-28)
| 函数 | 地址 | 体量 | 语义 |
|---|---|---|---|
| requestDecMode(int) | 0x007f13a0 | 1033B | DECRQM-DEC;与 queryDecMode 同体(respond 标志区分);ext 快路径 17 模式 + 大 switch |
| requestTerminalStateReport | 0x007f0434 | 228B | DECRQTSR:回 DCS 1$s ST + unsupported |
| requestUserPreferredSupplementalSet | 0x007ed7f6 | 248B | DECRQUPSS:DCS + ("0!u%5"/"1!uA") |
| requestXtermTerminfoData | 0x007f3518 | 1784B | XTGETTCAP:92 项表 dump(terminfo_caps.inc)+ DCS 0/1+r 应答;keymap 解析腿 cited ✅ |
| requestLocatorPosition | 0x007ebd6a | 145B | DECLRP:QCursor::pos + mouseButtons → reportLocatorEvent |
| requestDisplayedExtent | 0x007ed148 | 282B | DECRQDE:CSI rows;cols;1;1;1"w |
| requestKeyModifier | 0x007ed282 | 200B | CSI >key;state m(keymap 槽 007a2bd4) |
| selectStatusLineType | 0x007f0346 | 232B | DECSSSL:命名属性存 key=0x910265f6a06002be |

**附带战果**:
- 命名属性键体系破解:splitmix64(0x396cfeb8 ^ 0xbe4ba423 ^ 站点字面量);
  attrKey=0xdca26230091f1ca6(0x71220271)、conformanceKey=0x5b3b8ddd279e6bf4(0x70222070)、
  sgrKey=FUN_007e2123("m")——与旧注释 magic 常量三键全对上
- notifyNamedAttribute/applyNamedAttribute 真身(QMap<quint64,QByteArray> +0x78,空值擦除)
- markLocatorChanged + locator 状态机结构体(+0x160:flags/mode/units/rect)
- reportLocatorEvent(007eb4d6)真身;像素映射三函数(007e3136/30f4/3114→0091xxxx 视图层)留 cited
- setUserDefinedKeys(007ef0e8)、setUserPreferredCharset(00801a3e)真身
- 修正 requestMode 两处转写错误:格式应为 "%d;%d$y"(无 ?);SRM 状态应为 (m_srmModeInv!=0)+1

### 1b. 配置/通知族 ⏳
| 函数 | 语义 | 状态 |
|---|---|---|
| notifyZmodem(a,b) | 0091378a 信号30 transferBinary 发射点 | ✅ |
| notifyCursorStyle(c,s) | 00913592 信号6 caretStyleChanged 发射点 | ✅ |
| markRowErased(row) | 007e41ca:行标志字节 &=0xc5 \| 2 | ✅ |
| zmodemTick(event,ctx) | 007e22fa:事件0删上下文/事件1报(2,0) | ✅ |
| notifyNamedAttribute | ✅(1a 完成) | ✅ |
| markLocatorChanged | ✅(1a 完成) | ✅ |
| notifyMessageEx | =00913540 信号34 windowSizeChanged(resizeScreen 尾实锤) | ✅(1d) |
| highlightTracking | 007eac52:+0x158 4-int 追踪矩形,mode 0 释放;spec 4 整数(首段 1-based 递减) | ✅(近似:语料变体解包以 splitParams 等价) |
| notifyOsc / notifyCommand | body 未定位;XTWINOPS(007f298e)族发 windowTitleChanged 状态码 1-7,OSC 解析在 processData 侧 | ⬜ |
| setWindowIconAndTitle / setWindowTitleBuffer | 007cd902/007cd366:标题经 +0xe0 缓冲编解码、+0x120 自旋锁、+0x118 交换;宿主对象(Screen vs view)待适配器反汇编定 | ⬜ |

### 1c. 解码/样式族 ⏳
| 函数 | 地址 | 语义 | 状态 |
|---|---|---|---|
| attrKey / sgrKey | 007eebd4/7ef95c | splitmix64 哈希键 | ✅(1a) |
| conformanceKey | 007eecc0 | 同上 | ✅(1a) |
| charsetDisabled | 008034a4 | 注册表行 +0x11 位 | ✅ |
| charsetLookup | 00802a26 | 注册表名+标志匹配→id | ✅ |
| charset 注册表 | 00801a58 | 31 条 {id,name,set96,disabled}(charset_registry.inc) | ✅ |
| widthFromTables | 007a4692 | 7 张区间表级联二分(1307 条,width_tables.inc) | ✅ |
| splitParams | 调用点内联 | QByteArray::split(';') 重建缝 | ✅ |
| keymapSetModifier | 007a2c94 | 槽 +0x14/18/1c/20,INT_MAX=默认 | ✅ |
| keymapResetModifier | 007a2c02 | -1 全重置(+0x18 压包{2,2}) | ✅ |
| scrollbackModeCheck | 007e4028 | =isAltScreenActive(+0x139,同一函数) | ✅ |
| queryProtocolLevelProxy | 007e2e42 | 94 槽→strtol(text+2)/100;否则 ext?4:-1 | ✅(参数对象路径 cited) |
| codecFromUnicode / codecToUnicode | ? | body 未定位(0091318c 实为 scrollbackErased 信号) | ⬜ |
| requestXtermTerminfoData | 007f3518 | XTGETTCAP(92 项表 @0x117fea0 可 dump) | ⬜ |

### 1d. 滚动/区域 ⏳
| 函数 | 语义 | 状态 |
|---|---|---|
| resizeScreen(rows,cols,flag) | 007e5688:收缩先滚历史,history/saved 双核 resize,+0x1c0/1c4 缓存,尾部发 windowSizeChanged | ✅(RAII 守卫 cited) |
| scrollbackModeCheck | ✅(1c) | ✅ |
| selectActiveStatusDisplay | 007ef86e:键 0x151373d5c3e56760 + unsupported | ✅ |
| selectNumberOfLinesOnScreen | 007e5ba2:直连 core resize(FUN_007a604a,非 resizeBuffer) | ✅ |
| setColumnsPerPage | 007e61fa:DECCOLM 门(+0x11d),80/132 | ✅ |
| setLinesPerPage | 007e5eb2:掩码 0x1000001001003→24/25/36/48/72+0x90 | ✅ |
| mediaCopyDec | 007f063a:4/5→+0x11e DEC 打印锁,其余 unsupported | ✅ |
| zmodemTick | ✅(1b) | ✅ |
| appendHistoryBlock | 007e4368:+0x1d0 连续段合并;007e42da=sink 广播(同 7eefbe 形) | ✅(sink 注册表 Phase-4 cited) |
| convertRowToHistory | 007a9582(1262B):单元格级行→历史转换器(FUN_007a3d72/3c52/3c42/3c84/3ff8 链) | ⬜(移 Phase 2 TerminalCore 单元格层) |
| filterRectangle | PLAN 旧注 007eb2ac 错——那是 reverseAttributesInRectangularArea(已实现);真 body 未定位 | ⬜ |

**完成标准**:Screen.cpp grep "cited" = 0。

---

## Phase 2 — TerminalCore / SuperSession 收口 ⏳(主体完成)

### 2a. TerminalCore 剩余 cited ⏳
| 函数 | 地址 | 语义 | 状态 |
|---|---|---|---|
| resetCharsetSlots | 0x00802baa | 槽 {2,2,2,2}(打包 0x200000002×2) | ✅ |
| rowHasContent | 0x007a4a06 | rowUsedWidth(007a41d6)包脏标志+clamp | ✅(cell 走查 cited) |
| resetWrap | 0x007a45f6 | =setSgrState(重复声明,已并) | ✅ |
| rowUsedWidth | 0x007a41d6 | SSE 尾扫最后非零 head;0x40+payload 走查 cited | ✅ 标量等价 |
| copyState | 0x007aa2e2 | 字段拷贝+0x18 节点释放真身;节点克隆 cited | ✅ |
| charsetConfigRoot | 0x00802bda | id→entry 槽表访问器;cited | ⬜(语义并入 charsetDisabled/slot0Allowed) |
| cursorUpdated→cursorStyleBit | 0x007a44c0 | (0x2b>>style)&1 闪烁位;007e51e6 实为 setScrollbarVisible | ✅(标签纠错) |
| markLine(int) | 0x007a463c | row+rowHook,+0xa8 缓存/清零 | ✅ |
| slot0Allowed(int) | 0x00802c96 | userPreferredSet==1 或 tableId==6 | ✅ |
| resizeCore | 0x007a604a | 967B:重包装/增删行/默认 tabstop;行 ctor 007a5670 + Tabstops::resizeDefault 真身 | ✅ |
| lastNonEmptyRow | 0x007a5618 | =lastContentRowCount 别名(真身已有) | ✅ |
| writeText(QString) | 007e7b88 | 清+0x178→主循环→换回尾 | ✅ |
| setWindowTitleBuffer/IconAndTitle | 007cd366/7cd902 | view-settings(+0x10)对象上 +0xe0/118/120 | ✅(发射器 cited) |

### 2b. SuperSession 管家真链 ⏳
四注册表 QMap<QUuid,obj> 落 SuperSessionPrivate(dtor 走查 7d7096 实证
+0x18 注册表、逐对象 vtable+0x20 拆除);removeRegistry → loggerRemoved
信号已发;loggerOp 对象面(spdlog sink)Phase-4 cited。
open/drop/12 getter:metacall(ShellSession_h912400)已抽到函数簇
FUN_007d42d6-7d694e——全部转发协议对象(+0x10 dynamic_cast + vtable
查询 0x68/0x80 槽),属 Phase-4 协议布线;列表留 stub。
行为回归:engtest×2/sshsmoke/recheck(13 例)全绿。

### 2c. TextView 收口 ✅
property/setProperty 换原生 QMap<QString,QVariant>(原 qmap thunk 桩
有 nullptr 解引用 UB,已消除);schemeName "Plain Text" 默认真身;
find 种子/引擎面 Phase-4 cited。

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
| Screen.cpp | 1 | 38 行级标注 | 随各函数真身化消除 |
| TerminalCore.cpp | 1 | 5 | → 0 |
| EditorEngine.cpp | 1 | ~40 桩 | → 22 (真身) |
| SuperSessionPrivate.cpp | 1 | 6 | → 0 |
| gen_stubs.cpp | 1 | 27 | → 0 |
| Widgets/TextView.h | 1 | 1 | → 0 |

| **总计** | ~6 | **~160** | → **0** |

## Phase 2 收尾补记(2026-10-28 晚)

- **resizeCore(007a604a)真身**:TerminalCore 构造器补齐(原为无构造
  裸类,m_rows 野指针);makeRow(007a5670)、Tabstops::resizeDefault
  (每 8 列默认 tabstop)落地;recheck 16 例全过
- **convertRowToHistory(007a9582)结构定案但留 cited**:它是行→历史
  文档模型桥——容器四槽(+8 Uint64RunStyles 样式 / +0x10 Uint16
  PieceTable / +0x18 Uint32RunStyles / +0x20 尾槽)全部懒初始化;
  行样式游程(007a3d72/3c52/3c42/3c84)逐段插入。RunStyles 即
  Scintilla 的 RunStyles 类 —— 与 Phase 4 文档模型一体,届时以
  src/Scintilla 的 RunStyles 源码直接对接
- lastNonEmptyRow = lastContentRowCount(同体别名,已并)
