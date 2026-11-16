# quirks.md — 原版怪癖清单(测试必须原样编码,禁止"修复")

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
| 22 | **checkControlCharacter 门(+0x101,门已转写保留;触发未接线——批 34 回退自造接线,cited — wave-2)**:槽 checkControlCharacter(007cadda,moc[15]=case 0xf,配置键 text.controlChar)置位 → writeSplitData 主循环尾门(0025 语料 1714-1749)把**刚执行动作的匹配序列**回显字面(quirks 21)并**自清一次**;压制 = 尾字节 0x18/0x1a。触发面(实证 E7):**本批入口排空 + HT 执行**→ 排队元调用置位(发射点语料不可达,cited — wave-2;运行期 = 事件循环交付,批后生效 → 门由后批消费)。dump 流污染唯一源(批 30);suite 净基线两侧同构复位(resetState/resetParserState)永不触发 | 批 30/31 + E1-E7 |

23. **0x7576 char-used 视图 ret 相位不同相**(批 75 勘察):语料
   gapbuffer_get_chars_locked 返回 1=吸收/0=新写,与 Scintilla
   RunStyles FillRange 的 changed 语义不同相(吸收腿 ret1/changed1);
   RS8 委托承接时 ret 映射需翻转 —— 行为门裁决点(76c 笔记)。

24. **0x7547 S6 hasNext 耗尽哨兵恒真风险**(批 76 勘察):语料
   CSuperBuffer hasNext 耗尽哨兵 pend=-1 与 pend!=0 判定相乘,畸形流
   上原版有长循环风险 —— 转写逐字保留,未修。
25. **0x7547 S6 fstep=0 SIGFPE 同原版**(批 76):语料直除 fstep,
   畸形参数原版即崩 —— 原样保留未修。

26. **markers markWrite cur 读源 —— 已定案: = tlist(D+0x18)**(批 85
   三源复核):39463 `*param_1+0x18` 的 param_1=A→*A=D 回指;"bank 说"
   源于 mk2 把 param_1 误当 D;bank=0x40 分配无 FUN_00a10384 所读
   +0x60 槽不可能作 arg;恒同值条件 = A+0x08 ≡ D+0x18 同值双槽(initDoc
   唯一写)。修正已落:entryValueAt keyPropsOf(tlist 守卫版)。
27. **markWrite u32 载体写腿 rsFill32 —— 登记撤销**(批 85 定案):
   u32Obj = 复合载体{vtbl;runs@+0x08;styles@+0x10},读腿 39462 收
   *(+0x10)=styles,landed holderRs=*(+0x10) 与语料同解引,形态正确;
   补出处 39486/39462。残余 GB-vs-RS 差异维持原登记委托怪癖。
28. **MuxWindow +0x40/+0x41 BYTE 双旗标(批 108 定案,勘误登记)**:
   ctor s_MuxWindow_8e0938 asm 008e0980/84 = byte 写(+0x40←1、+0x41←
   param_2),Ghidra 反编译语料 QString 型系 8B 槽对齐误型(实参 ESI
   8B 截 R12B,五调用点全 0/1 字面);原 m_f40 QString("标题")建模系
   误型转写,已勘正为 bool m_f40(=1)/m_f41(=param_2)。S9 门
   008e0f87/92 为原地 byte cmp(非 QString 解引用);setPaneZoom S7
   gate 体 = FUN_008dfd9b/d93 只翻 +0x40(0↔1),+0x41 不触。
   裁决 = **错转写修正**(非怪癖登记);本条留档 Ghidra 误型模式。
29. **0x1270B EditorContext vtable+0x1c0 = 0(批 121 仪器登记)**:
   0x1270B 对象(ScintillaQt vptr 0x11ae558)表尾 +0x1c0 槽 = 0;
   sendEditor +0x1c0 尾调形态属 **TextView+0x58 引擎子对象**(VTABLE-
   MAP 槽表 51 槽 +0x198 止一致)——非缺陷;phase5 仪器经 0x1c0 直呼
   0x1270B 即 access violation,改走 00a418c4 armed 钩(批 121)。
30. **runvector/charUsed 宿主 = c92c 对象(批 121 实测勘正)**:原版
   runvector(charUsed)挂 *(editor+0x10a0) 的槽 [0x2f]/[0x30]
   (FUN_009585a2 ctor 26062/26063 清零面;0x4f00 22852 param_2[0x214]
   = c92c 载体);我方 EditorContext 平铺 ctx+0x178/0x180 = 承载替
   (消费面全走 case 内,行为同相布局不同构)。editor+0x178 直读 =
   垃圾(批 121 0x1000d0000 实锤)— 仪器读格必须经 c92c obj。
31. **0x7545 varint 承载替 8B 值序怪癖(批 143 登记)**:语料序列化
   = LEB128 变体(v=x*2+1<<sh,00a92326);我方 WBuffer 承载替 delta
   链输出 24B 与原版字节序存在值序差(遍历序同相,断言按承载替字面
   钉住);原版字节级对表待 5c 期仪器复核。
   **批 146 trie 分裂同相性补证(93f250 1369B 全读,0031.c:4687)**:
   trie_insert_node30(叶满 0x1e)/FUN_0093f7aa 5069-5096(半满晋升换
   根)只重排内存布局(节点新建 0x1f8/0x208 + 0093d5a0 逐槽交换 +
   子指针 0x100 区迁移),产出序列恒升序 — 5026-5032 查找门
   `slot<=line` 前进、5117-5124 右移批插钉住插入序 = upper_bound
   (等值随后)。我方 WNodeTrie QVector 保序承载 + 有序插入
   (ENodes.h insert0093f7aa)遍历序与语料分裂后走查(00933472
   do-while 逐槽 + 子链)同相;分裂本身(布局重排)对序列化输出
   无观测差 → 不落真分裂,承载替证据登记于此。
32. **a837f6 styled 臂哨兵 UB(批 146 登记)**:styled=1 尾臂掩码比
   双臂解引 styler+0xc(0xa83859/60)无哨兵旁路;0xa83874 CMP y58,
   0x11befa0 → JZ 命中即返 eq —— y58==哨兵(语料空 styler 单例
   0x11befa0)时若另一侧非哨兵,解引哨兵页(+0xc)为仪器级 UB
   (哨兵页可读性随进程状态)。我方按字面转写(同解引序),测试
   只构造安全构型(双堆掩码腿 + 裸腿互补;哨兵+堆 UB 构型不写,
   本条登记)。75df8d(MOV EDX,1 @FUN_0074dda2 尾)= styled=1
   唯一调用面(0x96d06d 恒 0 腿已由 aa3 钉)。
33. **toggleZoomPage unzoom 腿死路(批 148 登记,原样未修)**:unzoom
   腿 `ph->parentWidget()` = 本组自身(stack reparent 后非 splitter)
   → cast null → 整腿跳过 → m_f40 不清 → isZoomed 恒真。Qt5.15
   本机 probe 实测同相;原版同构推测同死(5c 期仪器可裁)。转写按
   语料字面,守门断言钉住(sgtest zoom 怪癖守门)。
34. **loadViews tail 22 字符截断(批 147 strace 实证)**:views 腿
   配置路径尾截 22 字符 → "toolbar.confi"(尾 g 丢失);groups 腿
   无此截断。转写原样保留;消费腿按路径匹配时须知此怪癖。
35. **词法栈 Runs 计数底座异计(批 152 登记)**:语料 9cc3a0 =
   delegate vt+0x30(runs 计数底座 — 96cbb8 调面 runstyles_runs_count
   值游程族);我方委托 Scintilla RunStyles::Runs() = 分区数含哨兵
   (空栈=1,值游程≥1 时=分区数)。同物异计(96f782 |4 链迭代上界
   视角不同);灌值腿 FillRange 空栈端界门(end>Length→no-change)
   为上游语义,rsprobe 实钉。96f6fe 重建腿 glibc 可复址(旧/新
   scanner 同指概率高)— 指针恒等非语料违例,cc5 不比指针。
   深引擎(editctx_initThread 0x50/piecetable_init 96a2f8/
   gapbuffer_reallocate 88e5a0/93fc60)承 cited — 批 111 判例。
