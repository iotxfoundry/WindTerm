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
| 13 | **ESC-single 统一模型(批 26 终版)**:D/E/M/H/7/8 全族 = escPending(下次 writeSplitData **入口 flush**)+ **吞噬尾随字面直到下一 ESC**(probe38 X 吞/E2 \t 吞/E4 CHT 存活于 ESC 边界)。四锚:ind 单批 (0,0)/ind_bot_scroll follower (5,0)/probe38 X 吞/E2 bits{}。ESC c(RIS)= 应用型(ris 锚,批 23 误吞回归已裁);CSI = 批尾 FIFO。doAction 007d1606 = QHash 派发,非记录器(+0x20 无消费者,仅 [TERM] 调试日志);**批 29 补**:同批字面先行(写在入口光标)、CSI 动作批尾应用;CUP+M 组合注入时 M 在入口 flush **丢失**(区内标记不滚动) | 批 26 + probe38 + probe38b |
| 14 | ~~LF 未写行不动~~ **撤销(批 21 lf40 实锤)**:空屏 40×LF → (30,0),原版无 rowHasContent 门(007e55fc 语料本就无门,我方门已删)。单 LF 序列原版 (1,0) ✓ 无门一致 | lf40 dump |
| 15 | **CUB/VPA 越界整体拒绝**:CSI 99 D 从 col=4 不动、CSI 99 d 不动(p5probe7 e);CUP 越界却是钳制(99;99→右下)——同批序列不同策略 | p5probe7 e |
| 16 | **HT/CHT 的默认 stop 表(新会话)= {4}**:HT→4、CHT 2 无下一 stop→行尾 88(=cols-1);旧会话曾现 every-8(表随会话/配置变)——resizeDefault(007a604a)语料精读待做 | p5 58 序列 tab/cht2 diff |

## 裁决流程(测试失败时)

1. grep 语料 `entry=地址` → 读原版真实行为
2. 我们的代码 ≠ 语料 → **修代码**(转写错误)
3. 我们的代码 == 语料但测试期望"教科书行为" → **修测试**,并把该
   行为登记到本清单
4. 语料不可读(优化糊掉/间接跳转)→ 测试标 cited-skip,不猜
| 17 | **初始 tabstop 表 = {4} 单元素**(干净会话两轮复现:HT 0→4→行尾 88;3g 后 HT→88 表空);来源未定位(非 resizeCore every-8 增量,疑运行期 HTS——shell 集成/prompt 通道) | p5probe9 + 干净会话 dump(tab/cht2) |
| 18 | **HT(C0 09)= C0 直派立即**(批 21 v6 修订,原"入队+at-stop 守卫"废弃);无 at-stop 守卫(语料 007e5d7c/007e5d1e 全读无);表空 → 行尾 cols-1;tab (0,4)/tbc_all (0,88) 双锚在 v6 下不需守卫 | probe15 + 007e5d7c 语料 |
| 19 | **DCH 不缩 row length**(+0xc 恒 89;批 16 的缩短转写被 probe14 行为否定);尾部格清零呈现空 | probe14(原版 DCH3 后 +0xc=89) |
| 20 | **CSI 参数形不配 → pcre2 PARTIAL → +0xd8 挂起尾**:ESC[1;88T 不匹配 ScrollDown(单参 \d+)也不匹配 HighlightTracking(type;d;d;d;d;)但可完成 → ret=-2 → 整段入尾本批不执行(wrap_edge 全空+home 实锤);下一批入口前拼 | probe15 E7 ret=-2 + xterm.term 模式表 |
| 21 | **字面流 ESC = 普通 1 列字形**(0x1b 写进格子,宽度 1,attr 照抄 SGR;ansi_buffer_build 无 0x1b 分支);4 连 ESC → 前 3 格字面 + 第 4 入尾(pcre2 PARTIAL[3,4)) | 语料 B(19281-19291)+ esc_literal dump(o=65,27,27,27) |
| 22 | **+0x101 流回显(批 30 实锤)**:ESC-single 动作置 Commander+0x101(checkControlCharacter,007cadda)→ 下一 writeSplitData 首个匹配序列被回显成字面字形(007d1f5a @7d2077 → 007cc1fa → writeText)。dump 流污染唯一源(基线 ESC[2J 字面化);我方未实现(净基线语义下永不触发,挂账) | 批 30 + baseline() 注释 |
