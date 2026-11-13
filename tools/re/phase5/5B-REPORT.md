# 5B-REPORT — Phase 5b 原版捕获对表(批 121,2026-11-13)

> M3-① 原版侧捕获 + 对表。驱动:`tools/re/phase5/phase5_editor.py`
> (00a418c4 armed 钩通道);我方基线:`/tmp/opencode/phase5_seq_editor.json`
> (engtest5,21 序列 61 断言);原版读数:`/tmp/opencode/phase5_editor_original.json`;
> 一键对表:`phase5_editor_compare.py`。
>
> **环境事件(如实登记)**:捕获中途一次 armed 0x4f00(op 桥面直填
> flags=0/type=3)使目标实例死(脚本 destroyed;根因见下"事故与根因"),
> 按任务书收口条款:已收口 C 族并重启原版一次(专用 Xvfb 实例,无用户
> 日常实例受损;重启流程照 HANDOFF 复现节)。

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
   (vptr = ScintillaQt 0x11ae558,VTABLE-MAP 定案)——0x1270B 表尾
   0x1c0 槽 = 0(rpc 直呼 access violation ×2 实测)。sendEditor
   +0x1c0 形态属 **TextView+0x58 子对象**(TEXTVIEW-IMPL 架构节),
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

## RUBY 语法假设裁决节(任务书指定)

**裁决:维持假设(推演 + 既有字节级对账);原版 dispatch 面直证未获
(见 NOT-RUN 根因),不构成证伪。**

- **推演链**(批 116 CALIBRATION,与本批复核一致): possessive `++`
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
- **原版侧 dispatch 直证缺位原因**:0x4eff 针产腿(FUN_0089a0a0 →
  codec_convCtor 0089c450)的真针对象依赖原版 find 串域(非空 find 串
  且 codec 门过)——壳期原版 find 串空 → 产腿 null → 12665 门 → ret 0
  (该读数本身与"空 find 串域"语义同相,但对 RUBY 语法无判别力)。
  置真 find 串需先解 doc+0xe0 codec memo setter 面批。
- **证伪条件(登记)**:若后续批置真 find 串后,原版对 possessive/子例
  程样例的命中位 ≠ RUBY 推演值(如命中数/位置与 Java/Perl 语法推演
  吻合)→ 证伪;反例清单将随该批对表逐条列。当前零反例。

## QUIRKS 候选(只登记,不修)

- **#29 候选(仪器怪癖)**:0x1270B EditorContext **vtable+0x1c0 = 0**
  (表尾越界槽)— sendEditor 的 +0x1c0 形态属 TextView+0x58 引擎子
  对象;与 VTABLE-MAP 槽表(51 槽 +0x198 止)一致,非缺陷,登记防
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
