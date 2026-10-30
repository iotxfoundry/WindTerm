# Attempt 002 (2026-10-30)

## Dispatch
@fixer 派发失败(API Insufficient Balance)→ **主会话亲自执行**(降级,目标不变):
tbc3 终裁 v2(判「仪器污染」vs「原版流语义」)。

## Result: PASS(criteria 全达)

### 发现与裁决(核心)
- 批 29 的"停手"结论**测于未复位流态**:p5tbc3_mode.py 直注基线、未调
  resetState(驱动已有,主路径 baseline() 已接)。
- 带复位重测 tbc3 ×5:**5/5 干净**(cur (0,6), row0 全零,确定性)。
- 机制实锤:**+0x101 流回显**(ESC-single 动作置位 checkControlCharacter
  007cadda → 下一 writeSplitData 首个匹配序列回显成字面字形,
  007d1f5a@7d2077→007cc1fa→writeText)→ 基线自身 ESC[2J 字面化 = 污染
  唯一源。原版语义、驱动侧流态,非我方缺陷、非随机。
- 修复 = 仪器卫生:baseline() resetState(suite 语义 = 每序列净基线,
  与 probe39 隔离锚一致)。

### 验证
- 全量差分:run1 **98/98**;run2 96/98(残余 glitch 族随机:tab_matrix/
  decom,decom 光标 (4,0) = decstbm_ri CUP 落点残留);run3 **98/98**
  (零重试);驱动加**稳定性复读网**(复读不稳 → mode-of-5)后 run4
  **98/98**(网零触发)。
- ctest 11/11 ✓(attempt 1 已建);engtest3 直跑复核 OK。

### 落地(commit db37e38f)
- tools/re/phase5/phase5_dump.py:稳定性复读网(非 0x1b 流态噪声也自动众数)
- QUIRKS 22(+0x101 流回显;我方未实现,净基线永不触发,挂账)
- PHASE5 批 30(tbc3 归绿终裁 + 批 29 更正标注)/ HANDOFF 第六次交接 /
  PLAN 98/98+ctest 11/11 / AGENTS 踩坑 #20(仪器前提未核即裁决)

## Verdict: **PASS — loop 停止(attempt 2/10)**
- 变绿 ✅(98/98,批 30 收官,Phase 5 完成)
- 会话管理集成+测试过 ✅(批 29/A1-A2-A4,ctest 11/11,commit 7aa34bbb)
- decstbm_ri 机制终裁 ✅(批 29 probe38b per-action 排空边界)
