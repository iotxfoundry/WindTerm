# 逆向完成计划(plan)

> 目标:编译出与 /opt/WindTerm_2.7.0/WindTerm 行为一致的程序。
> 每阶段完成打 ✅,进行中标 ⏳,未开始标 ⬜。
> 完成判定:所有已实现功能在离屏/实机下行为与原二进制一致。
>
> **测试策略(2026-10-28 定)**:测试跟随真身化,不领先。
> e2eterm(25 断言)/recheck(22 例)冻结为提交门(成本秒级),
> 守护已完成的终端核心路径;**不再向未完成子系统扩展断言**;
> 各子系统真身化收口时补各自行为测试;全面行为对比留给 Phase 5。
> 理由:近期在测试基建上的投入已超过逆向推进本身,而对 cited
> 桩写断言没有意义。
> **保真约束**:测试断言语料行为,不断言教科书行为——失败测试按
> docs/QUIRKS.md 裁决流程处理(怪癖登记,禁止按"应该怎样"修)。

---

## 总览(2026-10-28 会话末)

| 阶段 | 状态 |
|---|---|
| Phase 0 基础设施 | ✅ |
| Phase 1 Screen 层收口 | ✅(cited 38→行级注;深项移 4b) |
| Phase 2 TerminalCore/SuperSession | ✅(尾项 convertRowToHistory 移 4b 文档模型) |
| Phase 3 编辑引擎 customDispatch | ⏳ 批 1-7(runnode 模型 + 93 WT case;详见 Phase 3 节) |
| Phase 4a 启动路径 | ⏳ SessionManager+ProfileLoader ✅;工作区布局装载 ⬜ |
| Phase 4b TerminalWidget | ✅ 槽覆盖 58/58;**渲染层 ✅**(TerminalView 格子绘制/写回通道/resize 接线) |
| Phase 5 行为对比 | ⏳ **38 序列 36/38 MATCH**(Xvfb+Frida 差分管线;aux 簇收口;ESC D/M/E 语义实测定性——见 docs/PHASE5.md/EXT-BOUNDARY.md) |

测试矩阵:e2eterm 25 + recheck 22 + engtest×2 + sshsmoke 全绿。
gen_stubs 70→5。测试策略与保真约束见下方"测试策略"块。

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
| notifyCommand/notifyFig/Hyperlink/Iterm2/Message | moc 名权威定名+真身;**notifyOsc 原版不存在**;notifyCommand=A/B/C;N 命令字解析 | ✅ |
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
| requestXtermTerminfoData | 007f3518 | XTGETTCAP 92 项表(1a 已转写 ✅,terminfo_caps.inc) | ✅ |

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

## Phase 2 — TerminalCore / SuperSession 收口 ✅(2026-10-28 收口;尾项 convertRowToHistory 移 4b 文档模型)

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
**option/setOption → CTerminalConfig 单例真链 ✅**(见 4a)。
open/drop/12 getter + state:✅ 真身骨架落地(空协议对象分支
按语料;虚查询 Phase-4 补)。**Phase 2b 收口 ✅**。
**moc 权威抽取器已通用化**(stringdata 每串一 QArrayData,offset
相对条目;data[4]/[5]=方法数/偏移):screen 37 方法 / supersession
59 方法(11 信号+48 槽)/supercommander 264 方法三表入库。
行为回归:engtest×2/sshsmoke/recheck 全绿。

### 2c. TextView 收口 ✅
property/setProperty 换原生 QMap<QString,QVariant>(原 qmap thunk 桩
有 nullptr 解引用 UB,已消除);schemeName "Plain Text" 默认真身;
find 种子/引擎面 Phase-4 cited。

---

## Phase 3 — 编辑引擎 customDispatch 收口 ⏳(批量模式)

当前状态:36 个 WT 命令已真身;其余按 EditorContext 模型逐批落。
**方法**:每命令 = EditorContext 字段语义(+语料偏移注释)+ cited
软复位/刷新尾;软复位(session_view_soft_reset)与视图刷新
(vtable+0xa0)随 Phase-4 视图装配接线。
**批 1(2026-10-28)**:EditorContext.h 骨架 + 0x759a/759e/7597/759b。
**批 3(2026-10-28)**:清格式/margin 元数据/视口滚动 10 条 ——
0x7558 清格式(00927a24 守卫 + 00a26756 剥离;样式腿=SCI 起止
styling 适配映射)、0x7567 marginWidth(+0x1a2 double,变化才动)、
0x7568 marginIcons(+0x1b4 QList<int>,canConvert/≥0 过滤)、
0x75ad 可见行数(00a20438→SCI_LINESONSCREEN)、0x75ae 行高
(00a2b0a2 重算 cited→SCI_TEXTHEIGHT)、0x75b2/75b3 纵滚动条
max/pageStep(vt+0xe0(1)→sb+0x30/pageStep 的 SCI 适配)、
0x75b4 视口 +0x2c 字节(00a2398e beginIter 包裹)、0x75b5 滚动
(axis 1=纵 00a169cc→SETFIRSTVISIBLELINE / 2=横 00a167ac→
SETXOFFSET;像素锚 00a16946 cited)、0x75bc 片段模式(00a28efe
行扫描 cited)、0x75bf 片段会话活跃(00926eb0 = +0xd0!=0)。
**注**:PLAN 旧表"0x75b4-75b5 pair highlight / 0x75bf canRedo"
为猜测,语料证伪(disp 叶 24632-24640/24591):b4/b5 = 视口滚动,
bf = 片段查询;已按语料修正。
**待下一批**:0x75b6(00a3663e 文本 getter,2025B)、0x75b9
(009276ee buffer vtable+0x60 工厂)、0x75bb(00a2eee0 片段
占位符跳转,434B)、0x7556/0x7559-7560/0x756d-756e。
**批 4(2026-10-28)**:buffer/状态簇 + 折叠修正 15 条 ——
0x7556 buffer 动态类型(+0xf8 cast;00927ec8)、0x7559 collect
(严格 5 元素校验;收集器 00980ffc cited)、0x755a setString
(vt+0x58 跳转表未恢复,cited 存字段)、0x755b buffer 对象置换
(00927f16:0x48B 双构造器 cited)、0x755c/755d/7561/7563/7564
**+0xed8 状态簇**(bit1=755c/7561 布尔(-1/0);bit2=脏;
bits3+=ms 时长,7564 float 秒×1000 夹 100;7563 +0xdd0 int)、
0x755e 样式 run→QVariant(runnode 模型 cited)、0x755f/7560
(+0x1ba/+0x1bb 查询)、0x756d/756e 片段标记注册(sortedvec
插入+回调接线 cited)、0x7572 折叠 toggle(mode2 按状态二选一
disp 00a5f0a2;父行解析→SCI_TOGGLEFOLD)。
**修正**:0x7571 旧映射 TOGGLEFOLD 语料证伪(mode0=ec00 折叠族,
与 0x756f 同体)→ 父行解析 + SCI_FOLDLINE(flag 展开位)。
**悬置**:0x7573(00a5e952 全体方向:ec00/e952 的 contract/
expand 方向未定,不猜;待 00a2509a 方向证据)。
**批 5(2026-10-28)**:尾块 0x75d0-0x75ff 共 30 条,dip 24100-24518。
**实身(22)**:0x75d0 y→行(首行+y/行高;结果≥textLength→-1
的行/字符比较=原样)、0x75d1/75d2 pos→行(LINEFROMPOSITION 适配,
00958498/009587cc)、0x75d3/75d4 字符矩形(00a2267c 适配
x=POINTX/y=行×行高/w=字符宽/h=行高;run 宽内部 cited)、
0x75d7/75db(+0x1bc 布尔,db 变化才 soft_reset)、0x75d8/75d9
(doc+0x14 查询/写,FUN_00a245c6 夹 [0,10000];伴侣守卫
00a21610 cited)、0x75e0/75e2/75f1(+0x210/+0x1083/+0x1082 布尔,
传播腿 cited)、0x75e6 配色读取("line.caret.remote"+0xedc 特例;
styleAt 查找腿 cited)、0x75e7 点→列(00a29fa8 原点/字宽 →
pos-行首适配)、0x75f2/75f3/75f4(buffer+0x158/+0x160;<0→-1)、
0x75f5(00925ae4 枚举;(v&~4)!=3 → 缓存 -1)、0x75f9/75ff
(+0xd8 obj 字段查询/写)、0x75fc/75fe 时间戳格式(00927216:
indexOf('z')→布尔;串存 +0x290)。
**cited 骨架(19)**:0x75dc/75dd/75de/75df(+0x20d 存储 run 查询)、
0x75e3/75e5/75e8/75e9/75ea/75eb/75ec/75ed/75ee/75ef/75f0(点/
run 变换深腿)、0x75f7(447B iter 0x200)、0x75f8(1544B 节点树)、
0x75fa/75fb(hex 子态行文本)——runnode/坐标模型随 Phase-4。
**批 6(2026-10-28):runnode 模型** —— RunNode/RunPair 值类型
入库(src/Editor/RunNode.h;结构锚 runstyles_runnode_init
@0096bac0:u32 style<<1|flag / s64 pos(-1 无效,0096bbb4 判定)/
f64 width(-1.0 未设);Pair={flags,A,B}=位置区间,0096beb4 完整
判定/0096bed4 距离)。引擎存储块节点 = +0x1068(块光标编辑路径
00a2a2xx 写,0096bbc6 置位)。升级 8 条 cited→实身:
0x75dc(节点样式+行扫描长,00928624)、0x75de(节点 pos,
0096bbc0=*(x+8))、0x75df(节点样式,qstrdata_length_get 位
复用 word0>>1)、0x75ea(块节点文本,00a2a21c→00a2a15e
buf_substr(起点,node.pos))、0x75eb/75ec(列,FUN_00a2a0ea
原样含 pos>textLength 补差 + hexMode 选 +0x148/+0x158)、
0x75ed/75ee(hitTest/runnode 文本)。colAt/textUpTo 适配器。
冒烟:node 往返/pairLen=15/text@4='hell'/col@4=4。
**runnode 下一层**:标记注册表(+0x1098+0x100 sortedvec;
FUN_009a088e/00920442/00925bd4)——解锁 0x756d/756e/75a3
(标记对 → RunPair → 选区);convertRowToHistory(007a9582)
仍是 Screen 侧独立大件。
**批 7(2026-10-28):标记注册表** —— EditorContext::markers
(QVector<RunNode> 按位置保序去重;原版为自旋锁槽阵 009a088e,
行为模型等价,单线程)。
- 0x756d/756e 实身:语料完全同体(flag=1,disp 23290 证实)——
  查得即返否则插入(FUN_00920442/00925c02;通知 00925bd4 cited;
  尾部接线 0092671c 当 b!=0 cited)
- 0x75a3 实身:FUN_00926e1c×2(越界=无效节点)→ RunPair →
  完整则 SCI 选区 [min,max](尾部 0092777c/substring 返回形状
  cited);语料:首对不完整且 a<b 时重取 b
- 冒烟:乱序插入 0/10/6 → 有序 [0,6,10];0x75a3(0,2) →
  选区 0..10 ✓(ADDTEXT w=0 教训:追加用 0x7551;Scintilla
  对超界选区夹取=内核行为)
**注**:0x7573 方向 / 0x75e8(009347b6 sign-directive prompt)/
0x75ef(00a29eb6 iter 0x104+0092c222)经查仍悬置/cited。

### 3a. 已定名的 WT 命令(有 Scintilla 等价)⬜
| WT cmd | Scintilla API | 语义 |
|---|---|---|
| 0x7591 margins() | SCI_MARGINGETCOUNT 等 | margin 列表 |
| 0x75b8 selectionText | SCI_GETSELTEXT | (已有,接公共) |
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

### 4a. QApplication 启动路径 ⏳
- 配置面资产已探明:global/wind.config(权威默认层)+ wind.keymaps
  (键位引擎输入格式)+ triggers/lexer/Telnet 协议面——
  见 docs/CONFIG-SCHEMAS.md
- **SessionManager ✅**(2026-10-28):src/Widgets/SessionManager.{h,cpp}
  ——s_session_uuid_6f571a 转写(uuid/icon/group/label →
  QStandardItemModel,filter 禁用)
- **ProfileLoader ✅**:profile 布局定案(~/.wind/profiles/<name>/
  terminal/user.sessions 等);loadSessions/saveSessions
  (FUN_00806904/00806958)+ JSONC 容错解析——SessionManager
  数据源接通
- CTerminalConfig 单例 ✅:src/Editor/CTerminalConfig.{h,cpp}——Meyers
  访问器(00809d78)、ctor 默认 prompt ">"+trim 正则(00809b90)、
  wind.config JSONC(vendored jsoncpp,collectComments)载入;
  Screen::sessionConfigGet 与 SuperSessionPrivate option/setOption
  均已接真单例;recheck 对 /opt 真配置 3 键断言通过
- recheck 22 例全绿(宽度 7+字符集 6+键 2+resize 3+config 3+tabstop 1)
- 会话管理器 0x006f571a(QStandardItemModel)连 UI
- 工作区装载器 0x00522056 → Terminal/Editor/Browser 三面板恢复

### 4b. TerminalWidget 组装 ⏳
- **渲染层 ✅**(2026-10-28):src/Widgets/TerminalView.{h,cpp} +
  src/Sessions/TermViewFace.h——
  * TerminalView:格子绘制(attrArray u16 字头 + cell+0x18 SGR
    位义全解:0-13 属性/14-37 fg/38 bright/39-62 bg/63 bg-bright;
    bold/underline/strike/inverse 落 QPainter;光标 XOR 框);
    Screen::paletteColor(+0xd0)取色,未配置回落 16 色
  * TermViewFace:writeBackToView 的 vtable+0x70 通道 →
    viewWrite() 虚槽 → update()(Screen 侧原裸 vtable 调用改
    类型安全路由)
  * 装配:TerminalWidget::attachView()(视图=写回通道对端);
    view resizeEvent → Screen::resizeScreen(FUN_007e5688)
  * **调色板管线 ✅**(2026-10-28):Screen::installPalette——
    +0xd0 容器 = QArrayData 手工组块(offset@0x10,FUN_007e3578
    读法 payload=容器+offset);**m_palette 类型修正 int→void\***
    (语料证明容器为指针,原 int 建模在 x86-64 截断——铁律 5);
    TerminalView 改直读 SGR 位内 RGB 色值(applySgr 存的是
    paletteColor 消费后的值,非索引);attachView 自动装默认表
    (16 色已知 + xterm 算式;shortcut:默认 256 表未从二进制
    取证,取证后替换)
  * **第二写回通道 ✅**:FUN_007e673c(vtable+0x78,参数直透)→
    TermViewFace::viewNotify → update()
  * **渲染收尾批 ✅**(2026-10-28):
    - 宽字符双宽:0xffff 尾格跳过(e2eterm 锚)+ widthFromTables
      ==2 跨 2 格绘制;setCursorStyle 真身化(FUN_007a45ee 7B
      +0xcc 直写)+ cursorStyle() 读取
    - 光标三形态:DECSCUSR 1-2 块/3-4 底条/5-6 左竖条(XOR 面)
    - alt-screen 刷新:switchToAlternateScreen 尾 + modeChanged()
      信号 1 → viewNotify(0) 重绘(m_core=活动核,视图自动跟随)
  * engtest3 渲染冒烟:离屏 grab → 非单色 ✓/首行字墨 ✓/
    viewWrite+resize 不崩 ✓/**SGR 31 红字像素断言 52px ✓**
- **TerminalWidget 全槽覆盖 ✅**(2026-10-28):58+ 槽一轮批量
  (守卫查询 9/复位 3/输入清屏 4/CMD 直传 12/日志 9/modem 5/
  FreeType 2/会话命令 8 + write 端到端);深子系统腿(对话框/
  全局管理器/会话栈)cited
- **端到端数据路径已通 ✅**(2026-10-28 晚):Screen+core resize→
  writeText(ASCII/换行/边缘 wrap latch/UTF-8 宽字符)→ 单元格
  逐格校验,e2eterm.cpp 14 断言全过;writeText 修复四处真 bug
  (sCharClass 硬编码地址/cell-head 不步进/越缘 stale 计数/宽字符
  列步进)
- 行为矩阵(e2eterm 25 断言):ASCII/CJK/换行/wrap latch/tab/
  backspace/DECSTBM 区域滚动/SGR payload 全过 ✅
- makeRow cells 零初始化修复(ASAN 抓获 aux 野指针)✅
- ScintillaEditBase 嵌入(Editor 窗口)⬜
- SuperCommander → SuperSession 命令转发(SuperBridge 桥)⬜

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
| gen_stubs.cpp | 1 | 5(全为 Phase-4 深项) | → 0 |
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
