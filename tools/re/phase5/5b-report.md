# 5b-report — Phase 5b 原版捕获对表(批 121/122,2026-11-13)

> M3-① 原版侧捕获 + 对表。驱动:`tools/re/phase5/phase5_editor.py`
> (00a418c4 armed 钩通道);我方基线:`/tmp/opencode/phase5_seq_editor.json`
> (engtest5,21 序列 61 断言);原版读数:`/tmp/opencode/phase5_editor_original.json`;
> 一键对表:`phase5_editor_compare.py`。
>
> **环境事件(如实登记)**:捕获中途一次 armed 0x4f00(op 桥面直填
> flags=0/type=3)使目标实例死(脚本 destroyed;根因见下"事故与根因"),
> 按任务书收口条款:已收口 C 族并重启原版一次(专用 Xvfb 实例,无用户
> 日常实例受损;重启流程照 handoff 复现节)。

## 对表结果(3 族 21 序列)

| 族 | 序列数 | MATCH | MISMATCH | NOT-RUN |
|---|---|---|---|---|
| A 0x4eff 正则搜索 | 11 | — | — | 11 |
| B 0x4f00 词步进 | 7 | — | — | 7 |
| C 0x7576 插入样式 | 3 | 1(C1) | 2(C2/C3) | 0 |
| **合计** | **21** | **1** | **2** | **18** |

### C 族逐序列

| seq | 我方 | 原版 | 判定 |
|---|---|---|---|
| C1 bare(runvector 空) | ret=0,rv=0 | ret=0,userType=1(bool),rv=0 | **MATCH**(L29033 `*(rv)==0→0` 双侧同相) |
| C2 +charUsedView(RS8 [1,3)=1) | ret=0,rv=0,charUsedRuns=3 | ret=0,rv=0,charUsedPtr=null | **MISMATCH(仪器非行为)**:原版 c92c+0x180(槽[0x30])壳期 null → charUsed runs 不可读;ret/ rv 两可读字段同相。原版 C2 构型(runvector 空门先于 T 段)与我方断言同相 — **ret 维 MATCH**,差异仅在测试装置注入面(我方测试装置显式建 RS8,原版壳态无) |
| C3 +runvector 元素(q3 构型) | ret=1,rv=1,charUsedRuns=3 | ret=0,rv=0,charUsedPtr=null | **MISMATCH(构型不可达,非行为差异)**:原版 C3 构型需 runvector 非空 + styleProps 表(0x7543 链路装配 + ctx+0x190 bimap)— 壳期原版编辑器未打开文档/runvector 空 → L29033 门即 0;ENG5-SEQS C3 注记已预告"原版对表需等价装配"。原版读数 = 语料"无 runvector→0"门语义,与我方 C1 同相;C3 的 ret=1 路径(0x95c85f)双侧同相推演维持,等价装配批再对 |

### A/B 族 NOT-RUN 事故与根因(铁律 5 裁决材料)

1. **vtable+0x1c0 直呼不可行**:钩捕获的 a[1] = 0x1270B EditorContext
   (vptr = ScintillaQt 0x11ae558,vtable-map 定案)——0x1270B 表尾
   0x1c0 槽 = 0(rpc 直呼 access violation ×2 实测)。sendEditor
   +0x1c0 形态属 **TextView+0x58 子对象**(textview-impl 架构节),
   非 0x1270B 本体。改走 00a418c4 五参直呼(ret,editor,cmd,a,b)。
2. **armed 钩通道成立**:rpc.arm → 下一自然 dispatch(xdotool 空格回显
   触发)钩内消费 = GUI 线程;C 族 0x7576 三序列全链通(ret/userType/
   ctx 读格回读成功)。
3. **0x4f00/0x4eff op 桥面直填 = 目标死**(一次 armed 0x4f00 flags=0/
   type=3 后 script destroyed)。根因(语料静读,铁律 1 落点):
   - 0x4f00(0034:12825-12871)canOld = FUN_0089a756(op,findStr):
     op 桥面 flags=0 → `op+0xc&5==0` → FUN_0089a0a0(产腿,真 0x448
     针对象)—— 手填 op 无 codec memo 缓存,产腿返回壳态后 canOld 腿
     取 `local_178 = FUN_0089a0a0 出参`;canOld=true → `lVar10 =
     local_188`(codec_canEncode 产物)→ FUN_0089ab22(3300B 重编码)
     + **cursorSearch 段 9:FUN_0092547e(doc,lo,hi,ctx[4],runEnd) →
     FUN_00a83946(needle[0]!=0 门)→ FUN_00b42e10 → FUN_00b422d0**:
     param_2 = 针对象被当 **Onigmo-改 regex_t** 解引(批 110/116 定案
     +0x48/+0x70..0x80 优化域)— 桥面 0x40 字节 op 的 +0x48 以远 =
     堆垃圾 → 00b422d0 优化域野读 → 段错误。**手填 op = 仪器假针**,
     铁律 6 同款"实验锚非产品码"风险在仪器侧复现。
   - 结论:原版侧 A/B 族安全通道 = **先经原版 find/replace 串域
     (doc+0xe0 codec memo setter,查找 UI 命令面)置真 find 串,再
     dispatch 0x4eff/0x4f00**——本批超出安全门未走,留后续批(需先
     定位 doc+0xe0 find/replace setter 命令号,0x4ee 域候选)。
4. **C 族 ctx 读格勘正**:runvector/charUsed 挂 **c92c 对象 =
   *(editor+0x10a0)**(param_2[0x214],0034:23364 面;FUN_009585a2
   ctor 26049:槽[0x2f]=runvector 清零/槽[0x30]=charUsed 清零),
   非 EditorContext+0x178/0x180(我方模型偏移)— editor+0x178 直读
   得 0x1000d0000 垃圾,批 121 实测勘正(语料 c92c obj 独立承载,
   我方 EditorContext 平铺 = 承载替,语义同相)。

## RUBY 语法假设裁决节(任务书指定;批 122 终裁)

**裁决:维持假设(推演 + 字节级对账;批 122 原版 dispatch 面直证仍未获,
证伪条件未触发,零反例)。**直证缺位根因与安全通道状态见
"批 122 安全通道侦察节"——A 族原版命中位读数在本批未取得,
Ruby 推演值(engtest5 A1-A5 hit,与 b116/drive 六样例 OnigSearch
委托逐样例同源)维持为唯一可对账锚;证伪条件登记保持原样
(置真 find 串后原版命中位 ≠ RUBY 推演 → 列反例)。

- **推演链**(批 116 calibration,批 122 复核一致): possessive `++`
  (OP2_PLUS_POSSESSIVE_REPEAT)+ `\g<X>` 子例程(ESC_G_SUBEXP_CALL)
  同时被 triggers.config/linux.lexer 真实样例要求 → 上游 Onigmo 语法规
  格中 **RUBY 是唯一同时覆盖二者的语法**(Java regsyntax.c:162-182 /
  Perl :244-279 均缺 ESC_G_SUBEXP_CALL);`(?ix)` 内联选项/命名组/
  `\x{e0b0}` HEX8/lookbehind 逐域比对零冲突。
- **字节级直证(既有资产,批 116 落地)**:`/tmp/opencode/b116/drv3`
  六样例(libonig 委托,RUBY+UTF-8)全 OK(literal 6/possessive 4/
  hyperlink 3/subexp-call 8/brace-hex 1/datetime 3)— 我方引擎腿
  OnigSearch 委托与上游 onig_search RUBY 语义逐样例同相;engtest5
  A1-A5 的 hit 值与此同源。
- **批 122 新增证据(非判别)**:原版侧 Grep op 运行期构造
  (operator_new(0x68)+FUN_00899fba ctor)打通且实例稳定;0x4eff
  段 A 的 find 串源 = doc+0xe0 memo +0x28(FUN_009276e2,corpus
  12551/12816/30059 三面同读)— 通道形态成立但对语法无判别力
  (find 串 setter 面未收敛,A 族 11 序列原版读数缺位)。
- **证伪条件(登记,批 121 原文保持)**:后续批置真 find 串后,原版
  对 possessive/子例程样例的命中位 ≠ RUBY 推演值(如命中数/位置与
  Java/Perl 语法推演吻合)→ 证伪;反例清单随该批对表逐条列。
  当前零反例。

## 批 122 安全通道侦察节(M3-① 收官批,2026-11-13)

**目标**(批 121 遗留):定位 doc+0xe0 find/replace setter 命令面 →
安全注入 A/B 18 序列 → 5b 终版。

**通道形态三层定案(语料 + 运行期双面)**:

1. **find/replace 串源(语料三面同读)**:0x4eff(editor_replaceAll
   12551)/0x4f00(editor_replaceText 12856)/FUN_00a31966(0x757e
   Grep,11986)的 find 串实参全部 = **FUN_009276e2(*(ed+0x1098))**
   = doc+0xe0 memo +0x28;replace 串 = FUN_00927600 = memo +0x20
   (00927600/009276e2 = 009975c2/009975c8 五字节 thunk,0032:27846/
   27855)。⇒ 0x4eff/0x4f00 的针语料面是 **doc 级持久搜索状态**,
   非 dispatch 实参携带。
2. **op 构造腿(语料 + 运行期直证)**:SearchPane 消费链 =
   s_SearchPane_5bdda6(0034:39873,signal searchRequest 槽)→ op
   以 QVariant(qint64)入 0x4f00/0x4eff;op 本体 = SearchPane 成员
   +0x110(ctor 0074efe6 0034:14860 operator_new(0x68)+FUN_00899fba
   Grep ctor;填充 = FUN_0074e9cc 1084B 0034:14590:op+0x0c flags/
   +0x10 type byte(DAT_00ca2356[param_2] 表)/+0x18 find/+0x20
   replace/+0x28 where,00899d2c reset 复位)。terminal 路线 =
   dispatch 0x757e case 内联同构构造(0034:23476,operator_new(0x68)
   +00899fba+flags 位映射+FUN_00a31966)。**运行期实测**:
   frida 内 operator_new(0x68)+FUN_00899fba 构造成功、实例稳定
   (批 121 手填 op 桥面死道正式闭合 —— 安全通道 = 真 ctor op)。
3. **setter 面未收敛(30 分钟门触发,收口)**:
   - 静态:无独立 "写 memo+0x28/+0x20" 命令号(EDITOR-ENGINE-
     COMMANDS 0x4ee/0x4ef 段零命中);写路径候选 = SearchPane
     FUN_0074e9cc(UI 对话框装配,非 dispatch 命令)。
   - 运行期:terminal 会话 doc 的 +0xe0 对象转储与 text-editor doc
     假设布局不同构(+0x28 槽指向 codec 名对象"WindTerm",非
     QString shared_null 形态;批 121 c92c 同款会话差异)——
     memo+0x28 直写 QString::operator= 触发 Qt abort(目标非
     QString 承载),op 桥面写 +0x18/+0x20 腿未走完。
   - doc 文本注入腿:dispatch SCI_ADDTEXT(2001)/INSERTTEXT(2003)/
     SETTEXT(2181)/CLEARALL(2004) 在 terminal 会话 engine 上
     返回 void 且不落 doc(docLen 恒 ~553 会话回显态;0x7d3 不在
     00a418c4 case 树,SCI 文本变异走 vtable+0x1c0 嵌套对象腿,
     直呼不达)。

**结论**:A/B 18 维持 NOT-RUN;通道剩余工作已收窄为「editor 型
doc(非 terminal 会话 doc)上经 0x757e case 同构构造 op + find 串
写入(0x757e/FUN_00a31966 路线 op+0x18 直挂,绕 memo)」一条腿 —
探针资产 tools/re/phase5/phase5_editor_b122_op.js(frida agent,
Grep op ctor 腿)留后续批。原版实例全程存活(零重启,批 121 事故
不复现 — 手填桥面已弃用)。

## 批 123 双路实验终局节(2026-11-14,A/B 终局收口)

**目标**:editor 型 doc + find 串写入 → A/B 18 序列原版捕获。双路全败,
判死证据如下(任务书预授权收口)。

**路 a(setter 路)判死**:
- 全命令空间核对无 memo 写命令(editor-engine-commands 0x4ee/0x4ef/
  0x4f 段零命中;批 122 setter 面侦察结论维持)。
- terminal 会话 doc+0xe0 memo 运行期实锤(批 123 转储,doc=0x348c2090、
  memo=0x352ce290):+0x20=0x11bf0e0(PTR_FUN UTF-16LE codec face)、
  +0x28=0x347a0790(QHash 型,"WindTerm"/"1"/"compose" 表)——与
  text-editor 假设布局(两槽 QString)**不同构**,QString 直写必 abort
  (批 121/122 已复现两枪)。

**路 b(ctor op 路)判死**:
- 0x757e case(0034:23445)实参形态 = QList\<QVariant\> **长度恰 5**
  (非 op 针;op 作 a 传入 → access violation 0x5,偏移解引所致)。
- 运行期构造 QList:经 `qlist_variant_append_heap`(0x00545120)尝试 →
  "abort was called";复跑 AV 0x5。QList 元数据不可在原版进程内自建,
  腿封死。

**关键语料新证(批 123 终局;推翻批 122 收窄腿)**:0x757e case 把 find
写入 op+0x18,但 `FUN_00a31966`/0x4eff/0x4f00 的 find 串一律从
memo+0x28 读(FUN_009276e2→009975c8),**op+0x18 无任何消费**——即
dispatch 不存在任何注入 find 的通道,memo 是唯一串源。批 122 收窄腿
「op+0x18 直挂绕 memo」被本批证伪;memo 不可注入(路 a)+ editor 型
doc 无 factory 落点(00a418c4 全 case 树无创建命令;SearchPane 死路)
⇒ **A/B 18 通道封闭,NOT-RUN 即终局**。

**UI 路判死(侦察留档)**:SearchPane 全钩(0074efe6 ctor/0074e9cc
fill/005bdda6/005ea304/0090b4c6/0090b492/0090b55a)零命中;ctrl+f
键盘事件确达 app(dispatch 监控 44 cmds,无 0x4f00/0x4eff/0x757e;
Xvfb 无 WM,windowactivate 不可用,windowfocus 可用)。

**A/B 18 维持 NOT-RUN**;对表 1/21 MATCH / 2 MISMATCH / 18 NOT-RUN
不变。**RUBY 终裁:维持假设**(零反例;证伪条件未触发;原版 dispatch
面读数缺位,批 121/122 登记原文保持)。

**运行期实锤补登**(批 123):ctx=0x352d1820(vptr 0x11ae558)、
ScintillaEditBase=0x352ca8b0(+0x400→ctx,+0x1098=0);针消费形态 =
00a83946 解引 *param_2 一次,regex 模式针 = codec_canEncode 输出对
[0]、literal 模式针 = grepNeedle 输出对 [0](批 116b 模型一致)。
探针资产:`/tmp/opencode/b123/`(b123a.js/drive.py/dispall.js/
peek*.js/spy*.js)。原版实例零事故(pid 1377053 全程存活)。

## quirks 候选(只登记,不修)

- **#29 候选(仪器怪癖)**:0x1270B EditorContext **vtable+0x1c0 = 0**
  (表尾越界槽)— sendEditor 的 +0x1c0 形态属 TextView+0x58 引擎子
  对象;与 vtable-map 槽表(51 槽 +0x198 止)一致,非缺陷,登记防
  后续批再踩。
- **#30 候选(承载替差异)**:我方 EditorContext 将 runvector/
  charUsed 平铺(ctx+0x178/0x180);原版独立 c92c 对象(*(editor+
  0x10a0),槽[0x2f]/[0x30])。行为同相(消费面全走 case 内),布局
  不同构 — 登记(批 82"runvector = ctx+0x178"勘察注记的宿主面勘正:
  0x178 偏移值正确,宿主 = c92c obj 而非 editor 本体)。

## 验证门

- worktree ctest:**19/19**(0.31s;零产品码改动,与主线同相)
- engtest5 直跑:61 断言 fail=0;`/tmp/opencode/phase5_seq_editor.json`
  覆盖重生成(21 序列,同基线)
- 产物:phase5_editor.py / phase5_editor_compare.py(本目录)+
  /tmp/opencode/phase5_editor_original.json(21 行)
