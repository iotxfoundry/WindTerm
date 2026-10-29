# QUIRKS.md — 原版怪癖清单(测试必须原样编码,禁止"修复")

> 铁律 2(bug 原封不动)的行为化延伸:下列行为**看起来像 bug 但就是
> 原版行为**,e2e/行为测试必须按原样断言。任何"顺手修正"都破坏
> 逆向保真度。新增怪癖按序号追加,附语料地址。

| # | 怪癖 | 语料锚 |
|---|---|---|
| 1 | selectStatusLineType(DECSSSL)广播串写的是 "…(DECSSDT)" | 007f0346 → 串 0xcaae48 |
| 2 | DECRQM-DEC ext 快路径:模式 1008~1014 全部读 +0x141(mouseAltScroll 槽) | 007f13a0 else 链 `if (mode != 0x3ef) goto switch` |
| 3 | requestMode(ANSI DECRQM)default 分支:先报 unsupported,**仍回 state 0 应答**(不 return) | 007f17c2 |
| 4 | requestTerminalStateReport:回 `DCS 1$s ST` 空帧后再报 unsupported(类回声) | 007f0434 |
| 5 | appendHistoryBlock 连续段合并用 `QByteArray::append((char)at)`——位置参数按 char 截断语义 | 007e4368 |
| 6 | markRowErased:`flags = (flags & 0xc5) \| 2`——置 bit1 同时清 bit1/bit3(读改写蒙版不对称) | 007e41ca |
| 7 | DECRQM-DEC 模式 66(DECNKM):仅 +0xf0 == 1 回 state 1,其余(0/2/…)一律 state 2 | 007f13a0 case 0x42 |
| 8 | sgrKey = FUN_007e2123("m",1) 四字变形哈希;调用点 RSI(长度参)未显式置位,按 strlen=1 取值 | 007ef95c guard |
| 9 | markLine(line,0):arg==0 时缓存指针清零(工作行缓存语义,而非"标记清零") | 007a463c |
| 10 | XTGETTCAP "Co" 恒答 256(0x100),不读真实色数配置 | 007f3518 |
| 11 | ~~ESC D/E = 光标不动~~ **撤销(2026-10-29 伪影)**:实为教科书 IND/NEL + pending 队列延迟——单批尾动作待下次 writeSplitData 才 flush,旧 dump 读不到效果 | p5probe4/5 实测 |
| 12 | ~~ESC M = 下移 1 行~~ **撤销(伪影)**:实为教科书 RI(上移 1,p5probe4 实测 4→3) + pending 延迟 | p5probe4 实测 |
| 13 | **ESC 单字符动作(D/M/E)= pending 队列**:不立即执行,下次 writeSplitData 入口 flush(doAction 007d1606 记录器 → +0x20 容器);单批尾动作在下批注入前不可见——组合注入"CUP+M 只见 CUP"即此机制 | p5probe4/5 + doAction 语料 |
| 14 | **LF 在未写入行上不动**:CUP 到空行后 LF 无效;字面写入后 LF 才下移(rowHasContent 门;批 13 crlf_cup_text 全轨迹实锤)。教科书 LF 无条件换行 | p5probe7 f + crlf_cup_text |
| 15 | **CUB/VPA 越界整体拒绝**:CSI 99 D 从 col=4 不动、CSI 99 d 不动(p5probe7 e);CUP 越界却是钳制(99;99→右下)——同批序列不同策略 | p5probe7 e |
| 16 | **HT/CHT 的默认 stop 表(新会话)= {4}**:HT→4、CHT 2 无下一 stop→行尾 88(=cols-1);旧会话曾现 every-8(表随会话/配置变)——resizeDefault(007a604a)语料精读待做 | p5 58 序列 tab/cht2 diff |

## 裁决流程(测试失败时)

1. grep 语料 `entry=地址` → 读原版真实行为
2. 我们的代码 ≠ 语料 → **修代码**(转写错误)
3. 我们的代码 == 语料但测试期望"教科书行为" → **修测试**,并把该
   行为登记到本清单
4. 语料不可读(优化糊掉/间接跳转)→ 测试标 cited-skip,不猜
| 17 | **初始 tabstop 表 = {4} 单元素**(干净会话两轮复现:HT 0→4→行尾 88;3g 后 HT→88 表空);来源未定位(非 resizeCore every-8 增量,疑运行期 HTS——shell 集成/prompt 通道) | p5probe9 + 干净会话 dump(tab/cht2) |
| 18 | **HT(C0 09)入 pending 队列**(与 D/M/E 同);col 已是 stop → HT 不动(tab 表{4} col=4 不动 (0,4))、表空 → 行尾 88(tbc_all (0,88));两锚下 HTS pending/flush 时机仍有二义(hts_tab (0,0) vs tbc_all 88)——HT 语义矩阵实验待做 | 批 18 dump tab/tbc_all/hts_tab |
| 19 | **DCH 不缩 row length**(+0xc 恒 89;批 16 的缩短转写被 probe14 行为否定);尾部格清零呈现空 | probe14(原版 DCH3 后 +0xc=89) |
