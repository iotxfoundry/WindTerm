# Attempt 001 (2026-10-30)

## Dispatch
@fixer ses_e757355e7ffeXY55EgdUYSJWOe,全目标(优先级 A 会话管理 → B tbc3 众数 → C probe38b 矩阵)。

## Result: PARTIAL
- **A 会话管理 ✅**:ShellSession::stop(pty.stop public 化+断连+清挂钩)/TelnetSession(QTcpSocket+TelnetCommander,RFC 默认拒绝 DO→WONT/WILL→DONT)/双测试(telnetsocket_test 回环 fffc18fffe03+hello;shellsession stop 冒烟)。注册表插入侧 = cited 挂账(语料无直呼者,xref_scan numpy2 溢出改 objdump 交叉)。**ctest 11/11 全绿**(主会话复核 ✓,commit 7aa34bbb)。
- **B tbc3 ⏳ 未变绿(97/98)**:mode-of-N(N=5,双 settle)→ 1 干净/4 字面;**字面格 = 27,91,50,74 = "ESC[2J" = 驱动基线自身**(非 tbc3 的 ESC[3g)→ 新证据双解:①驱动基线污染(工具 bug,修仪器归绿);②原版流内确定语义(QUIRKS 20/21 pending-tail,我方需补语义)。非时序(settle 1.0/2.0 同果)。
- **C probe38b ✅ 终裁**:d1 批内 DECSTBM+CUP+M → CUP 生效 M 未执行;d2/d5 字面先行动作批尾;d4 组合注入 M 丢失(QUIRKS 13 实锤);e E2-bits 干净。per-action 排空边界四层结论入 PHASE5 批 29/QUIRKS 13。

## Verdict: FAIL(criteria 未全达:变绿 ✗ / 会话管理集成+测试过 ✓)
Attempt 2:tbc3 终裁 v2——判 ① vs ②;若 ② 则我方 writeSplitData 补 pending-tail 语义归绿(语料行为,非造假);若 ① 修 dump 驱动仪器。
