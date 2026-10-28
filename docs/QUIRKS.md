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

## 裁决流程(测试失败时)

1. grep 语料 `entry=地址` → 读原版真实行为
2. 我们的代码 ≠ 语料 → **修代码**(转写错误)
3. 我们的代码 == 语料但测试期望"教科书行为" → **修测试**,并把该
   行为登记到本清单
4. 语料不可读(优化糊掉/间接跳转)→ 测试标 cited-skip,不猜
