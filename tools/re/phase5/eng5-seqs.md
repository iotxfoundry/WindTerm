# ENG5-SEQS — 编辑引擎行为序列集(批 120,Phase 5b 我方侧)

驱动器 `tests/engtest5.cpp` 按本表产出 `/tmp/opencode/phase5_seq_editor.json`
(每序列一行 `{seq_id, …摘要}`;/tmp/opencode/ 前缀惯例同 engtest4 的
phase5_seq.json — handoff)。原版侧捕获批(环境就绪后)以同序列集对表;
我方断言 = 已定案语义自检(wordsteptest/markerstest/onigtest 同锚),
作为对比前的基线冻结。

## A 族:0x4eff 正则搜索(11 序列)

引擎腿 = OnigSearch 委托(批 116 激活);语法假设 ONIG_SYNTAX_RUBY
(calibration 批 116 五样例对账:A1/A2 = triggers.config,A3/A4/A5 =
linux.lexer)。序列引擎面直呼(与 onigtest 同层),并附 0x4eff
dispatch 占位链快照(needlePair=null → 12665 门 → 0;op+0x3c 不污染)。

| seq_id | 构型 | 期望命中 | 锚 |
|---|---|---|---|
| A1 | triggers.config 解压触发器(possessive ++) | 4 | 批 116 d1 |
| A2 | triggers.config 超链接 (?ix) | 3 | 批 116 d2 |
| A3 | linux.lexer ipv6 \g<X> 子例程(RUBY 唯一上游) | 8 | 批 116 d3 |
| A4 | linux.lexer prompt \x{e0b0}+lookbehind | 1 | 批 116 d4 |
| A5 | linux.lexer datetime 字面基线 | 3 | 批 116 d5 |
| A6 | literal "world" @ "hello world hello" | 6 | onigtest a2 |
| A7 | icase "ab" @ "Ab Ab ab" | 0 | onigtest c2(0xd35f40 折叠表) |
| A8 | 无匹配 | -1 | onigtest b1(ONIG_MISMATCH ≡ -1) |
| A9 | from=7 越过唯一命中 @6 | -1 | onigtest a3(start 下界) |
| A10 | 空域 [len,len) | -1 | onig_search 契约面 |
| A11 | MatchEngine::bufferScan00b422d0 wrapper(icase=false) | 0 | onigtest c1 |

**A11 承载注记**:wrapper 消费 needle->bytes(0x448 conv+0x08)作主题,
与 A 族其余行(setSubject 直喂 doc)等价同相;bufferScan00b422d0 是
0x4eff 段 E 搜索腿真载体(FUN_00b422d0 转写),故单列锚行。

## B 族:0x4f00 词步进(7 序列)

构型与 wordsteptest b/c/c2/d/d2/e1/e2 一比一;当前搜索腿死
(9851-9853 cited 恒 -1)→ 全部 ret=-1 + 选区不变量;段 8 激活后
e1/e2 断言即绊线(wordsteptest 裁决② 同款登记)。

| seq_id | 构型 | 锚 |
|---|---|---|
| B1 | 空文档 type=3 | wordsteptest b(9851-9853 步尽) |
| B2 | "abc" sel=[0,2) | wordsteptest c(段 4 前向门步出) |
| B3 | "abc" sel=[0,3) 覆盖构型 | wordsteptest e1(包夹界面不达) |
| B4 | "abc" sel=[1,2) 界外构型 | wordsteptest e2(9843 单步登记腿) |
| B5 | type=2 后向 | wordsteptest c2(9678-9681 idx=-1) |
| B6 | flags&8 selStore 懒建 | wordsteptest d(13057-13061) |
| B7 | flags&0x20 重试门 | wordsteptest d2(13050 op+0x38|=4) |

## C 族:markers/0x7576 插入样式(3 序列;批 83/115 面)

| seq_id | 构型 | 期望 ret | 锚 |
|---|---|---|---|
| C1 | runvector 空(bare) | 0 | L29033 门(markerstest p) |
| C2 | +charUsedView(RS8 [1,3)=1) | 0(门先于 T 段) | markerstest p 骨架 |
| C3 | +runvector 元素(bankCtorK3+fx vt;props 门跳) | 1(T 段行展开) | markerstest q3 + 0x95c85f |

C3 断言 ret=1 = 0x95c85f(lnA>=lnB 直置)唯一置 1 路径 —— 批 113
ok 语义退出路径勘证的字面;charUsed runs=3 为 T 段 0x95c656 ln 环前提。

## 断言统计

A 族 11×3 = 33;B 族 7×3 + B6/B7 附加 2 = 23;C 族 C1 1 + C2 2 + C3 2 = 5;
合计 **61 断言**。C3 表门承载注记:主循环 props 门(L28813-28821)以
styleProps190.value(sv>>2)≠0 为前提 —— 测试装置注入 {1}(产品侧该表由
0x7543 链路装配,壳期空 → 门跳,markerstest q3 以 0||1 接受两态;本驱动器
为取 T 段展开路径显式承载,快照标注 C3 构型)。
