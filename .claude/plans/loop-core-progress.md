# Loop Runbook — 核心面推进(sequential / safe)

> 起点:96/98 + 6 组件校准闭环。目标:校准成果转化为实现推进。
> 分支:dev;只提交不推送。

## 安全检查(2026-10-30)
- [x] ctest 6/6(engtest3 直跑段错误 ~2/6 = **既有间歇**:A/B 对照
      d211baf8(换序前)5/6 崩 vs 当前 2/6——非本轮回归,疑似
      Xvfb/GL 资源竞争;逐轮直跑复核)
- [x] ECC_HOOK_PROFILE=standard
- [x] 停止条件:4 迭代完成,或单项 blocked(定性挂账)

## 迭代清单
1. **decstbm_ri probe 矩阵**(probe38 已备):X 落点/CUP-M 跨批/E2-bits
   复验 → 排空分相裁决 → 修复(冲 97/98)或终定性
2. **键位引擎**:wind.keymaps 解析器({keys,modes,action|script})+
   action 路由骨架(Phase 4a 主菜;CONFIG-SCHEMAS 行动项 2)
3. **Telnet 会话链**:TelnetProtocol(已验同版)+ telnet.protocol 正则
   解释器 + TelnetCommander 协商槽(CALIBRATION 集成面)
4. **Pty 会话装配**:UnixPty(已验同版)接 Sessions(注意第 5 纯虚)

## 监控
- phase5_diff.py;ctest(engtest3 直跑复核);git log
