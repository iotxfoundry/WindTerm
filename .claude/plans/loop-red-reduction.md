# Loop Runbook — 98 序列红消减(sequential / safe)

> 起点:96/98(批 23)。目标:98/98 或全部定性挂账。
> 分支:dev(本地);**只提交不推送**(push 仅用户明示,带 proxy)。

## 安全检查(2026-10-30 已过)
- [x] ctest:6 测试,engtest3 ctest 态间歇(Xvfb 竞争)——**直接运行
      exit=0 全 OK**(wide right-half 4px ✓),判环境性例外,逐轮直跑复核
- [x] ECC_HOOK_PROFILE=standard(未禁用)
- [x] 停止条件显式:98/98 或 2 连续轮零红数下降且全部定性
- [x] 用户数据不碰(user.sessions 已还原;测试 sshd 已撤)

## 迭代协议(每轮,上限 6 轮)
1. 选 1 红(顺序见下)
2. 取证:语料 grep entry / frida probe(隔离纪律:probe 后不 dump)
3. 修复(语料锚注释)或定性挂账(CALIBRATION/QUIRKS 登记)
4. 验证:ctest(engtest3 直跑复核)+ phase5_diff.py ours
5. 文档同步(PHASE5 批次 + QUIRKS 如涉)+ commit(中文,不推送)

## 迭代清单
1. **tbc3**:glitch 重试未中(随机)→ 强化:重试 3 次 + 前置 sleep
   1.0s;仍中则 orig 侧连读 3 次取众数(读数级仲裁)
2. **decstbm_ri**:probe 矩阵 3 微实验裁决排空分相假说
   (a) 单批 [DECSTBM,CUP] 后读光标(CUP 是否已应用)
   (b) [DECSTBM,CUP,M] 批内 M 是否滚动
   (c) [CUP,M] 跨批 M 生效时点 → 按结果修 v7 调度或定性挂账
3. **E2-bits{} 异常复验**(如有余量):HTS miss 假说下重验 bits 读法

## 停止条件
- 98/98 ✅
- 或连续 2 轮红数无下降 且 剩余红全部定性挂账(当前 2/2 已定性)

## 监控
- 差分:python3 tools/re/phase5/phase5_diff.py [-ours|-orig]
- 轮迹:git log --oneline;红清单:diff 尾行 "PHASE5: n/98"
