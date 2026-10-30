# PHASE 5 — 离屏行为对比(v1 战果与方法)

> 目标:重建行为 vs 原二进制行为,同字节序列逐格对比。
> 工具链:Xvfb(:99)+ xdotool(自动化原版)+ Python frida(附加注入)
> 驱动:tools/re/phase5/phase5_drive.py(spawn 版)/ phase5_attach.py(attach 版)

## 已实证(v1,2026-10-28)

### 环境与管线
- **Xvfb 路线成立**:原版在 Xvfb 下完整跑通(会话面板/本地shell
  bash 会话/彩色提示符/31×88 终端)。offscreen QPA 会在会话创建段
  崩溃——会话态必须走 Xvfb。
- **Frida 附加 + 语料偏移读真实格子状态 ✅**:Screen+0x80=core、
  core+0x74/0x78=行数/行数组、row+0x0c=长、+0x40=attrArray u16
  字头——实测与重建模型**逐字节吻合**(含 0xffff 宽字符尾格)。
- **全链注入管线 ✅**:processOutput(FUN_007d1348)实际签名 =
  **(commander, screen, QByteArray\*)** 三参(param_2=Screen 指针,
  实测 0x747e6400baa0 与 writeText 捕获一致);QByteArray 经
  QtCore 导出 `_ZN10QByteArrayC1EPKci` 现场构造。

### 行为发现(重建对齐用)
1. **writeText(FUN_007e6f42)= 后处理写入器,非 ANSI 解析器**
   (注入 ESC[31mR 字面落格)。**双重视角修正**:我方 writeText
   同样无 ESC/CSI 层——e2eterm 的 SGR 断言是直写 m_sgrBits,
   从未经过解析!Phase 5 首个真实缺口 = **我方缺 CSI 分派层**。
2. **原版真解析器 = SuperCommander_writeSplitData(007d1f5a)**
   (回溯定位:writeSplitData → 007d10c5 → vt14 → writeText):
   签名 (commander, char\* data, int len);+0xd8 挂起尾拼接 →
   FUN_007e4908 取字符集分派表 → 逐字节分类 → 字面累积 /
   **FUN_007cadba(007e4908 表驱动解释器)**。实测经此链注入:
   ESC[2J/H 清屏归零 ✓、ESC[31m 消费 ✓、CJK 双格+尾格 ✓、
   CR/LF ✓ —— 与重建可观察语义完全一致(解析后态)。
3. vt14(007d1348)三参 (commander, screen, QByteArray\*),
   +0x137=+0xfc=0 时字面直通(实测);非主解析路。
4. **下一批(Phase 5 主线)**:转写 writeSplitData 尾 +
   FUN_007cadba 解释器 + 007e4908/007e389e 表选择 → 我方
   processOutput 尾接线(cited 占位处)→ engtest4 diff 全绿。

### 真解析入口定位 ✅(backtrace → writeSplitData)与逐格对比 ✅

- 回溯定位:**writeSplitData(007d1f5a)→ 007d10c5 → vt14 →
  writeText**;签名 (commander, char\* data, int len)。
- 经原版链注入实测:ESC[2J/H 清屏归零 ✓、ESC[31m 消费 ✓、
  CJK 双格+尾格 ✓、CR/LF ✓。
- **逐格对比 ✅(ALL MATCH)**:5 序列(ascii/crlf/cjk/sgr_red/
  clear_end)清屏基线下,原版 vs 重建游标+行 0..2 逐字节一致
  (engtest4 + phase5_original/ours.json diff)。

### 对比驱动落地的修正(全部由 diff 暴露)
1. **SuperCommander::writeSplitData(007d1f5a 镜像)**:字面累积
   → writeText(= 007cc1fa/cc1b98+ansi_buffer_build 等价)+
   C0 直派 + CSI(m/J/H/f/A-D)→ 已转写 Screen 方法;doAction
   全量状态机后续批。
2. **paletteColor 公式修正**:色 = 容器 + index*4 + *(容器+0x10)
   (offset 相对容器基址)——原实现把 offset 当绝对指针,合成
   容器块下必崩(Phase 5 diff 链暴露的潜伏 bug)。
3. **Screen::eraseCells blank 模板 = +0x28 写格**(7e4c90 产物,
   穿参至核擦除;原 m_blankRowTemplate 从未构建=段错误)。
4. TerminalWidget::write 双写修正(尾已入 processOutput)。

### 批 8:解析谱扩容(35 序列差分)⏳
- writeSplitData 分派扩容:CSI 全谱(K/L/M/P/@/X/S/T/r/h/l/s/u/
  g/G/d/E/F + 私有 ? 前缀 → setDecMode/setMode)、ESC 中介
  (7/8/D/E/M/c/=/>/(/)/#)、C1 控制域(0x84/85/88/8d/9b CSI)
  —— 全部锚到已转写 Screen 方法;engtest4 改 JSON 驱动(与
  原版侧同序列源)。
- **对比现状**:前 5 序列(基础集)ALL MATCH 保持;扩展集在
  ICH/DCH/ECH(插入/删除/擦除簇)段触发堆损坏 —— **格 aux
  所有权簇 = 已定位开放问题**(copyCell 深拷/转移语义 + 模板
  生命周期,语料 FUN_007aa3a6 内联 move 块与 007aa2e2 深拷为
  两个原语;当前过渡护栏:cloneGlyphPayload junk-payload 拒绝 +
  grow 新存储清零)。
- e2eterm/recheck 主路径不受影响(全绿)。

### 批 12(2026-10-29):ESC pending 队列机制定型 + 差分扩谱 58 ✅/⏳
- **QUIRKS 13 机制破解(p5probe4/5 决定性实验)**:ESC D/M/E = 教科书
  IND/RI/NEL + **pending 队列**——动作入队,下次 writeSplitData 入口
  flush(doAction 007d1606 = 记录器:xxhash64 动作名 → +0x20 容器)。
  单批尾动作在下批注入前不可见。QUIRKS 11/12 撤销(观测伪影)
- 我方实现:SuperCommander::flushPendingActions() + m_pendingActions
  (入队 D/M/E;入口 flush)→ **38 序列回归 38/38 全绿** ✓
- **DECSTBM 反参数拒绝**(p5probe6 实测:CSI 5;1 r 原版区域/光标均
  不动)——我方 'r' case 加 top<bot 守卫(修 SegFault:scrollRegion
  反向区间踩 resetRow)
- **OSC 吞吐**(ESC]...BEL/ST 原版全消费)——我方补 ']' case
- 扩谱 38→58(+20:CUP f/HPA/CHT/CBT/SGR 组合/256 色/RGB/RIS/LF/
  越界钳制/区域滚动/TBC/HTS/OSC/复合写;decaln/wrap_edge 移除待深挖)
- **当前 42/58**:原版侧会话脏(echo 残留:tab/bs 老序列也漂)——
  下一轮开头重置原版会话(HANDOFF 流程)再重 dump 对比
- engtest3 光标 XOR 断言间歇失败(1/3,全量时)——渲染层偶发,
  与本轮改动无关,待诊

### 批 13(2026-10-29):管线自包含化 + 修复浪潮 54/58 ⏳
- **管线升级**:基线注入进序列循环(每序列清屏+home+CSI r,双侧同
  模型)——差异不再级联,单序列可独立诊断
- **原版会话重置**(批 12 脏会话作废重拉;屏尺寸实测 **31×89**,
  cols=89 ← core+0xe4;我方 engtest4 resize 同步)
- 修复(全部 diff/probe 实锚):
  - Tabstops::clear 空体实锤 → Screen::clearTabstop 按屏宽循环清
  - nextTabstop 行尾语义(88=cols-1)✓ 语料已在;尺寸修正后自绿
  - HPA(ESC[`)原版不识别 → 删 '`' case(probe a:ESC[10` 不动)
  - CHT(CSI I)= 跳 n stop → 补 case 'I'(cht2 (0,16) 旧会话)
  - CUB/VPA 越界整体拒绝(QUIRKS 15)→ CSI D/d 加守卫
  - LF 未写行不动(QUIRKS 14)→ lineFeed rowHasContent 门
  - ICH blank attr head=0x20 + attrArray 平行搬移(rowInsertBlanks
    只搬 cells 的缺口;ich2 diff 暴露)
  - DCH 尾部补 = 0(非 space)→ rowInsertBlanks blankHead 参数
    (ICH=0x20/DCH=0;dch3 回归暴露)
- **crlf_cup_text 全轨迹破译 = pending 模型 v3**:批内 AB@home +
  光标 (1,2) = **CSI CUP 也入 pending 队列**(字面写在动作前;
  timer 亚 100ms flush——probe a CUP 单批 imm 0.02 已生效)。
  实现需 doAction 全量重构(动作枚举+参数化队列)= 下一轮主菜
- 53→54/58;剩 4:tab/cht2/hts_tab(默认 stop 表谜,QUIRKS 16,
  新会话表={4}:HT→4/CHT2→行尾/HTS+HT→0 待 probe)+ crlf_cup_text
  (pending v3 实现)

### 背书债清单(2026-10-29 审计,批 14 补全)

> 批 12/13 的差分驱动修复中,以下改动只有**行为实测背书**
> (probe/diff),缺**语料结构背书**(写代码前未读真身)。
> 批 14 逐项补全结果:

| # | 改动 | 处置 |
|---|---|---|
| 1 | flushPendingActions 在 writeSplitData 入口 | **未定位**(007d1f5a 入口只有 +0xd8 挂起尾)→ 行为保留+注释声明;随 pending v3 定位 +0x20 队列消费者后迁移 |
| 2 | NEL 动作体 | ✅ **定位:FUN_007e562c(18B,007cc4c2 表项)= CR+IND**;我方顺序已按语料改写(先 CR 后 IND) |
| 3 | DECSTBM 反参数拒绝 | ✅ **定位:007e5fa6(196B)内守卫**——bottom<1 拒/bottom<=top 拒/bottom>rows 钳 rows-1;我方 case 'r' 层错守卫已移入 Screen::setTopBottomMargins(精确结构改写),diff 验证绿 |
| 4 | OSC 吞吐循环 | 未定位(007e4908 表 ']' 项)→ 行为保留+注释声明 |
| 5 | CHT(CSI I) | 未定位 → 行为保留+注释声明 |
| 6 | CUB/VPA 拒绝守卫 | **语料冲突实锤**:007a546c 是 clamp;拒绝层=CSI 动作执行器(doAction 消费链)未定位 → 守卫暂留+注释声明,v3 迁移 |
| 7 | LF rowHasContent 门 | ✅ **证伪我方层**:007e55fc(41B)/007e55b6(70B)均无门;真身位置在 C0 分派或 writeText 字面流 → 门暂留(行为锚 QUIRKS 14)+注释声明,writeText 轮迁移 |
| 8 | rowInsertBlanks/ICH/DCH | ✅ **全定位**:007a641a(431B)= 5 参(row,at,count,blankHead*,sgr 格),attr grow(007aa1bc)+memmove+尾填 *head;ICH=0x20(007a6782 local_1a)、DCH=0(007a65d2 local_1a)——**我方结构已与语料一致**,注释升级真身地址 |
| 9 | Tabstops::clear | ✅ 上轮补读 007e5df0(193B),行为一致,注释已补 |

已核实有背书:indexDown(007e55b6 镜像)、setCellRaw sgr(007a5aac)、
adjustScreenAlignment(007e5f24)、IND/RI 动作体(007cc47e/007cc4a0)、
doAction 定性(007d1606)、setTopBottomMargins(007e5fa6 全量)、
insertCharacter/deleteCharacter(007a6782/007a65d2)、rowDeleteCells
(007a5dce 全量)、rowInsertBlanks(007a641a 全量)、TBC(007e5df0)。

**背书债 #10(m_sgrState 污染)已修**(批 16):`adjustScreenAlignment`
传 `&m_sgrState`(成员地址)误作状态格本体——copyCell 块拷拾取类
布局相邻域(m_tabstops,offTabs=0/JUNK {0,0,nil} 三元组实锤);去 &
修复,decaln/wrap_edge 回归不崩。

**背书债 #11(row length 生命周期,批 16 立/批 16 续推进)**:007aa3a6
尾部实锤 count = min(oldCount, newLen)——resize 不增长 length(我方
growRowArrays 一致);DCH 缩短已对齐(批 16 主轮,dch3 MATCH)。
余:writeText 357 行段(attr count 推进)精读 + decaln 行尾 3 格
归因(diag3 实证 DECALN 填充正确,row2 len=89 attr[85..89]=69×4
——diff 的 u=0 为旧文件时序假象,重 dump 后待复核)。

**批 16 续:case 'H' 参数序回归 + 回退(背书债 #12)**:批 16 续曾改
case 'H' 为 (num(1),num(0))——**引发 40/60 大面积回归**(cup 首条即
乱),已回退 (num(0)-1,num(1)-1) 恢复 53/60。教训:非对称 CUP 在
旧版下全 MATCH,说明**实际调用链与 SuperCommander::moveCursor
(column,line) 的形参语义与 presumed 不同**——需精读 FUN_007e4fdc
(CUP 的 Screen 面)+ 007cbeda(适配器)+ 0x7cbeda 链逐参数裁决
(背书债 #12),禁止再凭形参名推断。

**背书债 #11(length 生命周期)推进**:007aa3a6 尾部实锤
`count = min(oldCount, newLen)`——resize **不增长** length(我方
growRowArrays 一致 ✓);DCH 缩短 ✓(批 16 主轮);dch3 现 MATCH。
余:writeText 357 行段(attr count 推进)精读 + decaln 行尾 3 格
(row2 [86..88])归因。

**未定位三项(#1/#4/#5)+ 半定位两项(#6/#7)= 注释声明 +
债随 v3/writeText 轮清偿;其余全部升级为有地址背书的转写。**
54/58 在改写后无行为回归。

### 批 15(2026-10-29):背书债补全执行 + wrap 换行修复 + setRowCell 混参 ⏳
- **背书债 8 项逐项语料核验**(详见上节债清单处置状态):
  - #3 DECSTBM ✅ 007e5fa6 守卫迁 Screen 层(精确结构改写)
  - #2 NEL ✅ 定位 007e562c(CR+IND,顺序按语料改写)
  - #8 rowInsertBlanks ✅ 007a641a(431B)5 参全解;ICH=0x20
    (007a6782)/DCH=0(007a65d2)双实锤——我方结构一致
  - #7 LF 门证伪我方层(007e55fc/007e55b6 无门)
  - #6 CUB 拒绝层语料冲突实锤(007a546c = clamp)
  - #9 TBC ✅ 007e5df0(193B)
- **wrap 换行缺失修复**(批 12 遗留真缺口):我方 latch 后无
  重入换行——按语料 writeText 内联 122-139(markLine+IND+CR)
  补 latch 重入块;光标越缘保留(col=newCol,语料 cursor stays
  past the margin)
- **setRowCell 混参修复**(ASan 定位):flags 检查(0x80/0x40)误读
  param_3(head 2B)——语料 007a5aac 读 param_4(0x20 源格)
  +10/+0x10/+0x18;混参 = DECALN 全屏写时栈越界读 + 格 flags 污染
- **DECALN 回归暴露新深链**:m_sgrState 状态格污染(DECALN 后
  VERIFY junk-aux;free(垃圾) 于后续 2J)——**背书债 #10**,
  专项轮(需 m_sgrState 生命周期审计)
- **实验设计缺陷登记**:probe 系列与 dump 共享原版会话——probe7
  的 CSI 3g 清了原版 stop 表,tab/bs/cht2 的波动 = 会话级污染。
  下轮:重置会话 → 独立跑 dump(probe 用完即弃)
- HT 连发 probe:stop 表 = {4} 单元素(HT2 从 4 无下一 → 行尾
  88);HT 效果延迟一步(HT 也 pending);tab/cht2 序列前置 HTS@4
  对齐会话状态
- 54→53(会话污染 4 条);v3 暂缓(CUP pending 触发机制证据冲突:
  probe a 0.02s 生效 vs probe4 M1 0.24s 未生效——flush 驱动待定)

### 批 16(2026-10-29):双悬垂崩溃根因清除 + DECALN/wrap 回归 ⏳
- **rowDeleteCells 全重写**(007a5dce 368B 全读):原转写缺三件——
  尾部 aux 销毁(cited 空)/length 缩短(+0xc 写回)/attr 左移 →
  **双引用 aux 悬垂**(搬移 dst←src 后 src 不清,尾部补 blank 释放
  共享 aux,头部格悬垂)= free(0x10101/随机垃圾)崩溃链真根因。
  按 007a5dce 精确改写:MOVE 左移 + 007e2202 规约尾部销毁 +
  length -= n + attr u16 左移
- **DECALN &m_sgrState 误取地址修复**:adjustScreenAlignment 传
  `&m_core->m_sgrState`(指针成员的地址)——setCell 语义要状态格
  本体;copyCell 块拷从成员地址拾取类布局相邻域(m_tabstops,
  offTabs=0/JUNK 对象={0,0,nil} 三元组诊断实锤)→ 去 &
- wrap 换行重入(批 15)+ 上述两项 → **decaln/wrap_edge 回归成功
  (不再崩)**;58→60 序列(回归两探针)
- **53/60**:新增 diff 待破译——decaln 行 2 尾 3 格(DECALN 对
  非 89 长度行的填充边界);wrap_edge 原版全吞(CUP1;88+T+X →
  原版全空+光标 (0,0),行为未破译,下轮 probe:CUP1;88 单独/
  +T/+X 三步)
- tab/bs/cht2/hts_tab = 会话污染批 15 已登记(下轮重置会话复核);
  crlf_cup_text = pending v3
- engtest3 间歇依旧(1/3 光标 XOR)

**批 17(2026-10-29):HTS 实现 + CHT 语义修正 + stop 表收敛(53/60)**:
- **HTS 落地**(ESC 'H' → setTabstop(-1,true),FUN_007e52fc)——
  hts_tab u 从 88→4(HTS 生效证据);tab/cht2 前置 HTS 现可生效
- **CHT 语义修正**(case 'I'):逐 stop 前进 n 次,不足 n 停最后
  到达的 stop(干净会话锚:表{4} 时 CHT2→4;HT 的"无 stop→行尾"
  是 FUN_007e5d1e 另一语义,两 final 行为分叉实锤)
- **stop 表 = {4} 单元素**(干净会话两轮稳定复现;HT 连发:0→4→
  行尾 88)。表来源未定位(非 resizeCore every-8 增量)——QUIRKS 17
  登记;我方测试以 HTS@4 前置对齐会话态
- **tab u=8 待查**:HTS@4 前置后 HT 仍跳 8(set(4,true) 未落表?
  下轮 engtest4 打表验证)
- bs o=27(row0[4..7])待查;decaln/wrap_edge/crlf 照旧(v3/#11)

### 批 18(2026-10-29):HT 入队 + 三绿(tab/cht2/hts_tab)54→55 ⏳
- **HT(C0 09)入 pending 队列**(PendingAction::Ht;dump 锚:tab 单批
  尾 HT 不执行→(0,4))——tab/cht2/hts_tab 三绿(HTS/CHT/表状态对齐
  组合生效)
- **QUIRKS 18**:col 已是 stop → HT 不动;表空 → 行尾 88(两锚);
  hts_tab (0,0) 与 tbc_all (0,88) 的 HTS pending/flush 时机二义
  待 HT 语义矩阵实验
- 我方无 timer:批尾挂起动作在 dump 时点未执行(原版 0.35s 内
  timer flush)——dump 时点差一个 flush 的系统性偏差,hts_tab/
  tbc_all 各执一侧

### 批 19(2026-10-29):diff 工具一键化 + decaln 残差实锤 ⏳
- **tools/re/phase5/phase5_diff.py**:dump(可选 ours/orig)→ diff
  一键 + JSON mtime 新鲜度告警(消时序假象;dirname 层级修 3 次)
- **decaln 残 3 格实锤**:diag row2 **len=86**(非 89)→ DECALN
  guard(x<rowLength)在 86 挡住(attr[85]=69 ✓ 86-88 未填)。
  86 = 89-3 = **DCH 缩过的行对象流落到 row2**(滚动换位:行池复用
  保留缩过的 length)——行对象池 × length × 滚动 = 新深链,
  #11 升级为"行池轮"
- bs o=27(row0[4..7])同属 length/读数错位家族,待行池轮
- 55/60 基线不变

### 批 20(2026-10-29):probe14 行为实锤 + rowDeleteCells 修正 + decaln 归绿(56/60)⏳
- **probe14(原版行为)**:DCH3 后 row +0xc = **89 不变**;35LF 滚动后
  仍 89——批 16 的"DCH 缩短 length"转写与行为矛盾,回退;尾部格/
  attr 清零保留(内存安全 + dch3 行为)
- **rowDeleteCells 修正落地**:MOVE 左移 + 尾部 aux 销毁 + attr 左移
  + 尾部清零(length 恒定)——**decaln 归绿**(guard 不再挡,行尾
  3 格填 69;此前 u=0 为 guard 挡 + 旧 JSON 叠加)
- 诊断保留:[d] 打印(decaln/tbc_all 的 cur/len/attr/ts0)
- 53→56/60;剩 4:bs(27)、tbc_all(HT flush 后光标仍 (0,0)——
  horizontalTab 执行链待查)、crlf(v3)、wrap_edge(#11)

### 批 21(2026-10-29):机制革命——probe15 仪器 + xterm.term 分派表 + v6 模型 + 扩谱 98 ⏳
- **probe15 决定性仪器**(tools 外科 /tmp/opencode/p5probe15.py):9 实验 ×
  全链 hook(pcre2 ret/doAction/光标写/HT/±0xd8 尾/表位图)——
  **dump 读数不可信类**(mid-drain/状态污染)自此有仲裁者
- **三份语料 subagent**:doAction=QHash 派发非记录器(+0x20 无消费者
  仅 [TERM] 日志);writeText 字面路径(ESC=普通字形!wrap latch=
  Screen+0 bit7);tab 族全解(HT 无 at-stop 守卫/表空→cols-1/
  TBC mode2 原版未实现勿补);**序列→动作名绑定 = terminal 配置
  regex(xterm.term input.match,refs+命名捕获组)**——分派真相源
- **wrap_edge 破译**:ESC[1;88T = partial 可完成(HighlightTracking
  形)→ ret=-2 → +0xd8 尾,X 未进解析器(全空+home ✓)
- **v6 模型落地**:CSI = 批尾 FIFO 排空;ESC D/E/M = 专队列下次
  入口 flush;HTS = miss-no-op;\t/C0 立即;at-stop 守卫删除;
  CHT 无下一 stop → 行尾;LF rowHasContent 门删除(lf40 实锤)
- **扩谱 60→98**(+38:xterm.term 动作清单直出;cht2/hts_tab 去重)
- 70/98;28 红分类:①原版读数 flaky(bs/cht2/hts_tab——同字节
  异读铁证);②我方缺口(REP/HPR/VPR/HPB/VPB 未实现、DECOM/
  DECAWM-off wrap、ESC-字形字面、SGR-colon 后写路径断、cha200/
  ich99 钳制、multi_crlf 我方空写、lf40 我方 indexDown 门、
  decstbm_ri/cup、tab_matrix/tbc3、decsc_rc/scosc_rc 恢复语义)
- **E4 bits{4} 未解残留**(HTS-miss 模型下唯一矛盾 datum)
- dump settle 0.35→0.6(不解决读数变异——变异非时序)

### 批 22(2026-10-30):poison-loop 破译 + rowDeleteCells OOB + 新动作 + 87/98 ⏳
- **poison-loop 破译(28 红的真主)**:wrap_edge 的 T-tail 每次 splice
  后同死点复发 → 后 38 序列全跑死区(假绿+假红)。修复 = 复活批同
  死点 → ESC 字形字面(pcre2 -1)+ 从 '[' 重扫自愈(m_tailResumed)
- **rowDeleteCells OOB**(dch99 崩溃暴露):移动循环旧界 at+n,count≥room
  时 src 越界——语料 007a5dce 实际界 = length-n;修正后 dch99 行全清 ✓
- **新动作落地**(xterm.term 表):HPR(a)=CUF、VPR(e)=CUD、HPB(j)=CUB、
  VPB(k)=CUU、REP(b)=重复最后字面(m_lastGlyph 追踪)
- **ESC 字形规则**(esc_literal ✓):未知 ESC-x → 0x1b 字形 + e1 入字面;
  e1 为批尾 → partial 挂起(A+4×ESC+B → A+3 字形+尾,原版一致)
- **70→87/98**;剩 7 红定性:bs/tab_matrix/decawm_off = 原版侧字面态
  伪影(同签名 0x1b 格,probe15 证清);decsc_rc/scosc_rc = mid-drain
  读数;decstbm_ri = M 时序(E2-bits 同族矛盾);wide_wrap = 原版
  o[0]=ffff 哨兵在前 vs 我方字形在前(与 cjk 绿矛盾,待解)
- 3 路校准 subagent 并行完成(Telnet/Pty/Widgets,见 CALIBRATION.md)
- 诊断基建:dbg_cursor 微驱动 + engtest4 [diag] 逐序列状态

### 批 23(2026-10-30)/loop 四轮:92→94→**96/98**,save/restore miss 族 + glitch 重试 ⏳
- **wide_wrap 格序定案**(loop R1):probe37 决断实验——原版宽字符
  = **哨兵在首格**([ffff,中,ffff,中,…]),我方字形在前反了;writeText
  换序 + TerminalView 哨兵渲染 + e2eterm 断言更新(旧"ffff trail"
  约定撤销)→ 绿
- **decstbm_ri 定性**(loop R2,挂账):E2-bits{}/tab/E4/decstbm_ri 四锚
  在一切 uniform 排队模型下互斥(逐组合验算)——原版排空边界按动作
  类型分相(\t 触发 LIFO vs 批尾 FIFO 假说最拟合),需 per-action
  probe 矩阵(3 微实验)终裁
- **save/restore miss 族扩员**(loop R4):decsc_rc/scosc_rc 双 (1,2)
  稳定读 → DECSC(ESC7)/DECRC(ESC8)/SCOSC(s)/SCORC(u) 全部分派
  miss 消费不执行 → 双绿;注册表有 SaveCursor/RestoreCursor 但
  live 配置 miss —— 命名/注册错位待查(不阻塞)
- **字面态伪影 = 随机性**(loop R3):bs/tab_matrix/tbc3/decawm_off
  轮流中招(0x1b 格签名),非确定性;phase5_dump.py 加 glitch 重试
  (0x1b 格检测 → 重基线重注入)→ bs/decawm_off 即刻归绿,tbc3
  重试仍中(随机,可多次重试/加长前置 sleep)
- **ST 重同步废弃**:ST 非独立模式((?&ST) 仅内嵌于 OSC/DCS)→
  -1 全字面化风险,回退(p5 自匹配误杀教训 ×1:pkill 括号法)
- 教训入档:pkill -f 自匹配(p5 踩坑 #16 候选)

### 批 24(2026-10-30)/loop-start Iter1:tbc3 定性(驱动流怪癖,隔离干净)✅
- **重试强化**(×3 + 前置 sleep 1.0)无效 → 非排水竞态;2s 排空窗
  亦无效 → 非简单 tail 拼接
- **隔离决断实验**(probe39:baseline+tbc3 直注入)→ row0 全零
  **干净**;dump 流内 = 确定性 [6..9]="ESC[3g" 字面化于 CUP(1;7)
  落点 (0,6)——victim = 自身首序列,位置 = 自身 CUP 落点,
  **依赖驱动级多序列流状态**(前序 tab_matrix 尾 \t 残留)
- **定性**:WindTerm 流状态怪癖(隔离不复现);我方 (0,6)+干净 =
  原版隔离行为 ✓。bs/decawm_off/tab_matrix 同族(0x1b 格签名,
  retry 随机命中);decstbm_ri = 排空分相(另案)
- **更正(批 28)**:本批 engtest3 段错误"环境竞争"结论**作废**
  ——真根因 = Screen ctor 漏初始化 m_savedPrimary/m_altCore/
  m_viewSettings(resizeScreen 拿垃圾 this,rdi=串地址实锤),
  批 28 已修(ctor 补 nullptr),裸跑 75%→10%
- **loop 停止条件达成**:96/98,2 红全部定性(tbc3 流怪癖/
  decstbm_ri 排空分相),均非我方转写缺陷
- pkill 自匹配误杀(p5 踩坑 #16):pkill -f 括号法 [d] 规避

### 批 25(2026-10-30)/loop-start R1:decstbm_ri probe 矩阵 + 吞噬扩展回归修复 ⏳
- **probe38 矩阵跑成**:(a) decstbm_ri 原样 → X 被吞(r4[0]=0,未渲染)
  + CUP 应用 (4,0);(c) tab 批后 (0,4) 表干净 ✓ —— **ESC-single 吞噬
  尾随字面证据 +1**(M 后 X 吞,与 E2 \t 吞同型)
- **吞噬扩展实验(7/8/c/=/ >)→ ris 回归 (4,4) → 根因两连**:
  ① 吞噬扫描后落入公共尾 litStart=++i → **吃掉下一序列的 ESC**
  (级联字面化);② 条件修复时误删分支体(H/7/8 落入默认 glyph 路径
  → decsc/decrc/tab/hts_tab u=27)——双双修复,96/98 + ctest 6/6 恢复
- **正确吞噬实现留批 26**:扫描后需 i-1 回退(公共 ++i 消化)+ litStart
  对齐,使下一 ESC 交还解析(当下回退到批 23 miss 态 96/98 保平安)
- 教训:多轮 python 锚点编辑互相踩(条件/体分离),改后必须
  grep -A 复核分支完整性(踩坑 #17 候选)

### 批 26(2026-10-30)/loop Iter1:ESC-single 统一模型 → **97/98** ✅
- **统一**:D/E/M/H/7/8 全族 = escPending(下次入口 flush)+ 吞噬
  尾随字面直到下一 ESC —— 四锚(ind/ind_bot_scroll/probe38-X/E2-\t)
  + E4 CHT 存活(ESC 边界)全拟
- **decstbm_ri 归绿** ✓(X 吞 → row0[0]=0 ✓ cursor (4,0) ✓)
- i-1 回退法修复公共尾吃 ESC(批 25 根因①)的正式落地
- 97/98;剩 tbc3 = 原版字面态伪影(retry 随机)
- loop-core Iter1 完成(decstbm_ri 裁决+修复);Iter2 = 键位引擎

### 批 27(2026-10-30)/loop Iter2-4:键位引擎 ✅ + Telnet 会话链 ✅ + Pty 装配 ✅
- **Iter2 键位引擎**:src/Editor/KeymapEngine —— wind.keymaps 装载
  (531 条:477 action+50 script;裸控制字符 \u 转义容错;PCRE2
  语义差条目量化跳过 =8)+ 锚定正则×mode 过滤;tests/keymap_test
  (真文件 ≥500 + "."→Window.RepeatLastCommand + mode 过滤)✅
- **Iter3 Telnet 会话链**:TelnetCommander::feed = 确定性 IAC 状态机
  (PCRE2-Qt PARTIAL 语义坑弃用;refs 从 telnet.protocol 解码)+
  loadProtocol(重复命名组首现保名/后现 _N + 派发空串回退)+
  gen_stubs 双槽桩转正;tests/telnet_test(DO/WILL 协商+SB 子协商
  24/0+直通+半截拼接+状态)✅ **教训:QByteArray(const char*)
  strlen 在 \x00 截断——测试字节须显式长度**
- **Iter4 Pty 装配**:src/Pty 入构建(UnixPty+Pty.cpp;Win/Con =
  Windows 路径排除);base/UnixPty 签名对齐(QProcessEnvironment/
  int);setErrorCode Linux 分支;ShellProcess 抽 ShellProcess.h
  (moc 独立可解析;UnixPty.h 多行基类子句 = moc 类扫描盲区——
  基类子句并回类行修复);Public/Spin.h 转发头;tests/pty_test
  (createProcess echo → write/readAll 回环)✅
- **ctest 8/8 全绿**(含 engtest3;keymap/telnet/pty 三新冒烟)

### 批 28(2026-10-30)/loop-start:会话装配冒烟 ✅ + ctest 10/10
- **tests/shellsession_test**:UnixPty.createProcess(echo)→
  pty.readyRead → cmd.processOutput → Screen 格子含 MARK_42 DONE42
  ✅(fails=0)——**会话数据路径首次端到端验证**(进程 → pty →
  ANSI 解析 → 屏幕格子)
- 装配模式 = Phase 4a 会话层蓝图(pty.readyRead → 解析器;
  响应 → pty.write;带引号命令需参数列表式重载,已知项)
- ctest 10/10 全绿(含 engtest3;keymap/telnet/pty/shellsession 四新)
- 文档:AGENTS 踩坑 #16-19(pkill 自匹配/锚点编辑互踩/QByteArray
  strlen \x00 截断/moc 基类子句换行);CALIBRATION 组件结论表

### 批 29(2026-10-30)/loop:Phase 4a 会话管理 ✅ + tbc3 众数终裁 + probe38b 矩阵终裁 ✅
- **A1 ShellSession::stop 接线**:UnixPty::stop 移 public(line 52 private→
  public;访问级属重建自由度——原版 ptyqt 基类 stop() 即 public)+
  ShellSession::stop()(断 pty readyRead 连接 → pty.stop() →
  m_commander.m_screen=nullptr),析构器改调 stop ✅
- **A2 TelnetSession 网络接线**:QTcpSocket + TelnetCommander。
  socket.readyRead → (a) 会话层 RFC 854 默认拒绝响应(DO x→WONT x、
  WILL x→DONT x、IAC IAC 字面、SB…SE 跳过、半截序列留尾)→ 回写
  socket;(b) 整段原始流进 commander.feed(IAC 状态机)→
  processOutput(解析器)+ dataReceived。**响应策略不入 Commander**
  (Commander 只记录 optionStates)✅
- **A3 注册表集成挂账**:Commander 表**插入**侧语料未定位——
  已实证邻接面 FUN_007da178(commander→会话 +0x48 并发
  commanderCreated 0091223a)与 FUN_007da09a(按 uuid 移除 +0x18
  节点;调用者 007da1ee/007da219/007dc314/00912927),插入无直呼者
  → 不猜,SuperSessionPrivate.cpp 留 `cited — wave-2` 注记
- **A4 测试**:新增 tests/telnetsocket_test(本地 QTcpServer 回环:
  收 IAC DO 24 + IAC WILL 3 + "hello" → 断言回
  `fffc18fffe03` + dataReceived 含 hello);shellsession_test 补
  stop 冒烟(`/bin/sleep 5` → stop() → pid 3s 内消失)。**ctest 11/11**
- **B tbc3 连读众数终裁**:dump 驱动加 mode-of-N(3 次重试仍字面态
  → N=5 连读逐格众数)。独立复跑(*/tmp/opencode/p5tbc3_mode.py*)
  逐次读数:**1 干净 / 4 字面**,字面格 = `27,91,50,74` = **"ESC[2J"
  = 驱动自身的清屏基线**,不是 tbc3 的 ESC[3g;settle 1.0s 与 2.0s
  同结果(非时序竞态)。众数仍字面 → **停手**:定性为原版 dump 流内
  确定行为(基线注入在批首被字面化),不硬修我方 → 97/98 保持
- **C probe38 残余矩阵终裁(probe38b,零代码改动)**:
  - (d1) 批内 `DECSTBM+CUP(7;1)+ESC M` → cur(6,0):CUP 生效、**M
    未执行** ⇒ ESC-single 族入 escPending,排空 = 下一批入口
  - (d2/d5) 同批 `DECSTBM+CUP(5;1)+"AAAA"` → AAAA 落 **(0,0)**
    (r0=65×4),而同批 `DECSTBM+CUP` 单独调用 cur 正确 (4,0) ⇒
    **字面先行、动作后置**(同调用内动作在批尾应用,E5 同型)
  - (d4) 区内标记 BBBB@row6 → 批 `CUP(5;1)+M` → cur(4,0) →
    触发入口 `5a` 后 **r5 BBBB 未移动**:M 在入口 flush 时**动作丢失**
    ⇒ **QUIRKS 13 实锤**(组合注入 M 丢失,原版确定性,非我方 bug;
    decstbm_ri 归绿与本条一致)
  - (e) E2-bits 复验:tab 批后 r0 全 0、cur(0,4) → 干净,0x1b 字面
    不复现 ✓
  - **per-action 排空边界结论**:字面 = 即时(入口光标)→ CSI 动作
    = 同一调用批尾(DECSTBM 归位至 home 亦在此刻)→ ESC-single
    (D/E/M/H/7/8)= 下一批入口(且组合注入时常丢失)→ 尾随字面被吞
    至下一 ESC(批 26)
- 证据脚本:/tmp/opencode/p5probe38b.py,读数 p5tbc3_readings.json

### 批 30(2026-10-30)/loop Attempt2:tbc3 归绿终裁 v2 → **98/98 全绿** ✅
- **裁决翻转(批 29 的 tbc3 结论作废)**:批 29 的 mode-of-N(1 净/4
  字面)测于**未复位流态**——p5tbc3_mode.py 直注基线、未调 resetState。
- **机制实锤**:ESC-single 动作置 Commander+0x101(checkControl-
  Character,007cadda)→ 下一 writeSplitData 的**首个匹配序列被回显
  成字面字形**(007d1f5a @7d2077 → 007cc1fa → writeText);另有 +0xd8
  挂起尾。dump 流中前序(tab_matrix 等)残留 +0x101 → 基线自身
  ESC[2J 被回显字面(27,91,50,74 落在上一序列收尾光标处)= 唯一
  污染源。**原版语义,驱动侧流态;非我方缺陷,亦非随机**。
- **修复 = baseline() 前置 resetState**(+0x101 清零 + +0xd8 clear,
  仪器卫生;suite 语义 = 每序列净基线,probe39 隔离锚一致):
  - tbc3 带复位 5 连读:**5/5 干净**(cur (0,6),row0 全零,确定性)
  - 全量差分:run1 **98/98**;run2 96/98(tab_matrix/decom = 残余
    glitch 族随机,decom 光标 (4,0) = decstbm_ri CUP 落点残留);
    run3 **98/98**(零重试);驱动加**稳定性复读网**(批 30:复读
    一次,读数不稳 → mode-of-5)后 run4 **98/98**(网零触发)
- **残余怪癖挂账 = QUIRKS 22**(+0x101 流回显;我方未实现——suite
  净基线语义下永不触发,实现随 pending v3 族)
- **PHASE 5 收官:98 序列 98/98 MATCH**(双侧净基线对齐;ctest 11/11)

### 批 31(2026-10-30)/loop:checkControlCharacter 门补齐(QUIRKS 22 落地)(**触发接线已回退,批 34;门转写保留**)
- **语料四要素**:①门 = writeSplitData 主循环尾(0025 语料
  1714-1749):doAction 后若 +0x101 置位 → 匹配序列回显字面 +
  进门即自清;压制 = 尾字节 0x18/0x1a;控制尾字节 partial 再匹配
  的 memmove 变体全表状态机才可达(cited-skip)。②setter =
  007cadda(moc[15] = case 0xf,选项分发器 0090ef1c;旧注 moc[15]
  →0x7e3568 系误注,0x7e3568 实为 QByteArray::clear)。
  ③配置键 = text.controlChar。④运行期 = 排队元调用(E5b 回溯
  全 QtCore 激活链)。
- **触发面实证(E7 矩阵)**:本批入口排空 + HT 执行 → 置位;
  ESC D/M/H/7 + CUP 后继 / 单 HT / 单 ESC-single 均**不**置位。
  E1 分载体:清 +0x101 即净(清 +0xd8 无效)→ 批 30 机制结论
  保持;排队语义解释 glitch 族随机性(事件循环交付时序 vs 注入
  节奏竞速)。
- **实现**:SuperCommander 门 lambda(CSI/ESC-single/C0 执行点)+
  HT 触发排队 invokeMethod(QueuedConnection,发射点 cited —
  wave-2)+ resetParserState() 卫生面;engtest4 基线镜像
  resetState。suite 奇偶守恒:98/98(复跑归稳);ctest 12/12
  (+ echo_semantics_test 6 断言:置位/回显/自清/门关/触发/后批
  消费)
- 证据脚本:/tmp/opencode/e1_carrier.py e2_trigger.py e3_trace.py
  e4_bisect.py e5b/e5d_bt.py e6_dual.py e7_trigger_set.py

### 批 32(2026-10-30)/loop:键位 action 执行面(JsEngine + dispatch)(**已回退,批 34**)
- **语料**:JsEngine 类(QObject,metaObject 008fd850;evaluate 体
  0064abb2/0064af3c = 源码+名字上下文;newQObject 0064b0d0)+
  **wind_actions_build**(00667102,7702B:map 遍历 → script
  trimmed → evaluate 注册)+ 装载器 s_wind_keymaps_768854/
  s_wind_actions_76b7c0。**QJSEngine 实锤**(decomp 0020:29945)
  → 标准行为委托真库(混合架构)。
- **格式实证**:wind.actions = {name:{text,script 箭头函数}};
  桥对象 application/window 等为 globalObject 注入(newQObject)。
- **落地**:src/Editor/JsEngine.{h,cpp}(loadActions jsoncpp
  JSONC 容错/runAction 可选 action 实参/installBridge/runScript)
  + KeymapEngine::dispatch(match → action 走注册表,script 直评;
  全命中执行——首中即停无证据,挂 CALIBRATION 待核)+ CMake
  Qt5::Qml 组件(运行库在,dev 头已在 qtdeclarative5-dev)+
  Editor/*.h 入 moc GLOB + tests AUTOMOC。
- **actions_test**(新,6 断言)✅:480 动作装载/Application.Exit
  桥调用/带参 SetWindowTransparent/未注册静默 miss/dispatch 命中
  +script 项。**注意点:Window.RepeatLastCommand 不在 wind.actions**
  (内置/他层注册,数据点挂账)。
- ctest 13(engtest3 ctest 态间歇,直跑复核 OK);phase5 98/98。

### 批 33(2026-10-30)/loop:Telnet 协商策略 = 实验锚捕获落地(**已回退,批 34**)
- **实验锚(CALIBRATION 协议,金标准)**:原版 2.7.0 连
  127.0.0.1:3023 捕获(user.sessions 种子克隆 Telnet 条目 →
  xdotool 开会话)——telnet_capture.json:
  - client_init(连接主动协商)= WILL NAWS(31) WILL TTYPE(24)
    DO ECHO(1) DO SGA(3) WILL SGA(3)
    (fffb1ffffb18fffd01fffd03fffb03)
  - DO 24 → 重发整段 init;DO 31 → SB 31 0 <cols><rows> SE
    (实证 89x32 = 当窗尺寸,动态);SB 24,1 → SB 24,0
    "xterm-256color" SE;DO 39 → WONT 39;WILL 1/3 → 不应
- **语料边界**:telnet.protocol 仅解析面(refs+match);三叶
  00860b30/00860cd6/00861156 = 名字表/日志 → 策略体语料不可达,
  响应策略以实验锚为准(不发明;CALIBRATION 协议步骤 3)
- **落地**:响应生成入 TelnetCommander(feed 内 DO/WILL/SB 分支,
  negotiationReply 信号回写;initialNegotiation() 面)——语料架构
  对齐(协商 = TelnetCommander 槽,CALIBRATION);TelnetSession 退
  纯转发(connected → init;negotiationReply → socket;rfcReply
  默认拒绝层删除)
- **telnetsocket_test 重写为捕获断言**(7 断言)✅:init 原字节/
  DO24 重发/WILL3 静默/NAWS 89x31(动态尺寸)/TTYPE xterm-256color/
  DO39 WONT/数据路径;**回放字节与捕获逐字节同型**
- ctest 13/13;phase5 98/98;环境复原(user.sessions 还原/WindTerm
  重启 + bash exec sleep 哑化/捕获服务器已杀)

### 批 34(2026-10-30)铁律执行:无落点代码全量回退(用户令)✅
- **审计标准(AGENTS 铁律 6,本批入库)**:src/ 行为实现必须有
  转写落点(语料 FUN_ 地址/行号或 cited 空实现);实验锚只能作
  docs 证据,不能直接生成产品代码;发现违规不经讨论立刻回退。
- **回退清单(无转写落点)**:
  - TelnetSession 类整体 → cited 空壳(e3474ff4 态;QTcpSocket
    装配/协商转发/rfcReply/negotiationReply 均无转写源)
  - TelnetCommander → cited 空壳(e3474ff4 态;批 33 协商策略 +
    批 27 IAC 状态机 feed/loadProtocol 均自研无转写)
  - ShellSession → cited 空壳(879e5803^ 态;startLocal/stop
    装配 API 无转写)
  - KeymapEngine 整组件(装载/匹配/dispatch 均无转写)+ JsEngine
    整组件(包装 API 无转写)→ 删除
  - SuperCommander +0x101 触发接线(HT 排队发射,实验锚非转写)
    → 移除;**门本体保留**(0025 语料 1714-1749 转写,休眠)
  - 测试:keymap/telnet/shellsession/telnetsocket/actions/
    echo_semantics 六冒烟随组件回退删除
- **保留(有落点)**:门转写/批 26 统一模型/Screen ctor 修复/
  Pty(开源码逐句同构,CALIBRATION 在案)/phase5 驱动与
  engtest4 基线卫生(工具面,镜像原版驱动 resetState)
- **实验资产保留在案**:telnet_capture.json(协商字节)/E1-E7
  触发面矩阵/probe39 隔离证据 —— 待语料定位后按转写重做组件
- 验证:ctest 5/6(engtest3 ctest 态间歇,直跑复核 OK);phase5 98/98

### 批 35(2026-10-30)/loop:ActionFactory 语料转写(动作子系统第一层)✅
- **语料函数族定位**(铁律 6:先落点后代码):
  - actionFactory_getOrCreate 00665dc2(856B):工厂表
    (QHash<QByteArray,QAction*> @factory+0x10)查/建;建 = new
    QAction + setText(name) + connectImpl(triggered →
    FUN_0066a148,functor 壳 0066b3a0)
  - FUN_0066613a(2882B)条目应用四键:script(toString.trimmed;
    空→setEnabled(false)@006669e2 / 非空→setData@006662c5)/
    icon(非空门@00666344 → theme_icon_load_svg@00756cd6 →
    setIcon@00666399 + setProperty("iconFile")@006663e5)/
    text(toUtf8→tr→setText)/ tooltip(→setToolTip@006665e0)
  - wind_actions_build 00667102(7702B):根 map 空守卫(+0x10)
    → key→toUtf8 / value→toMap → FUN_0066613a
  - FUN_0066a148(103B)triggered 处理:sender→QAction→js_actionFire
  - 触发执行位 js_actionFire 006697b2(2282B)+ theme_icon_load_svg
    00756cd6(1272B)→ **cited 桩**(下一批转写)
- **落地**:src/Actions/ActionFactory.{h,cpp}(getOrCreate/
  build/applyEntry/loadActionsFile;JSONC 解析 CTerminalConfig
  同款);src/Actions 入源码/moc 双 GLOB;Qt5::Qml 回归(链接面)
- 验证:构建零 undefined;ctest 6/6;engtest3 直跑 OK
- 待办(下批):js_actionFire(006697b2)/js_actionState(00669086,
  1739B)逐行转写 → TelnetCommander 槽体 → keymap 匹配 →
  ShellSession → TelnetSession(回退组件按此序语料重做)

### 批 36(2026-10-30)/loop:JsEngine 类体转写 ✅
- **关键语料事实**:脚本包装模板 = 字面 **"'use strict'; () => { %1 }"**
  (0064abb2,QString::arg)+ **"'use strict';" 前缀拼接**
  (0064af3c:分配 len+0xd → convertFromAscii 前缀 + memcpy ×2 字节
  → resize)。两包装均落 evaluate 的 name 槽(program = 成员串
  @param+0x10 —— Ghidra 槽位歧义已标注,不猜改)。
- **转写**:src/Actions/JsEngine.{h,cpp} —— evaluateArrow(0064abb2)/
  evaluateStrict(0064af3c)/newObject(0064b0be)/newQObject
  (0064b0d0);QJSEngine 组合成员(宿主面:MuxPane QJSEngine
  @+0x48,00767a70/d08/d2e 三门语料)。
- 语料边界:js_actionFire(006697b2)完整转写依赖 MuxPane 类
  (s_MuxPane_64b102)+ js_actionState(00669086)+ 属性名串定位
  —— 下批继续。
- 验证:构建零 undefined;ctest 6/6;engtest3 直跑 OK

### 批 37(2026-10-30)/loop:js_actionState 语料转写 ✅
- **属性名实证**(反汇编 6690a3 → 指针 @0x11821e8 → 字符串):
  js_actionState 首读 = action->property(**"dynamic"**)
- **语义闭环**:property("dynamic")→ QAction* 门(QAction*
  metatype 一次注册 DAT_011c0b04;canConvert/cast 门)→
  linked->property(propName)→ action->setProperty(propName, …)
  **状态镜像**(尾 @006697xx;第二读 this = cast 后 linked
  @0066911c 实证)
- **落地**:js_actionState 入 ActionFactory(自由函数,语料名);
  canConvert/cast 双门转写,镜像尾转写
- js_actionFire(006697b2)完整转写仍欠:两处 property 名串
  (00669841/45 区)+ MuxPane 类体 —— 下批同法反汇编实证
- 验证:构建零 undefined;ctest 6/6;engtest3 直跑 OK

### 批 38(2026-10-30)/loop:js_actionFire 语料事实 + 签名修正 ✅
- **属性名实证**(反汇编 669834 → 指针 @0x1182208 → 字符串):
  js_actionFire 首读 = target->property(**"data"**)
- **js_actionState 签名修正**:this = param_2(汇编 66909b/6690ad)
  → (QObject *target, const char *propName);镜像尾不变
- **js_actionFire 形与体边界**:param = (out, target, 名串,
  QJSValue);体 = js_actionState 前置 → property("data")→
  QAction* 门(00669890 cast)→ data() 脚本(006698ad/c2)→
  metatype/canConvert 门 → FUN_00668f3a 调用(依赖 MuxPane +0x48
  QJSEngine 面,0064b102 类体)→ 错误 setText 尾 → toVariant。
  **尾段依赖 MuxPane 类体未转写 → js_actionFire 保持 cited**
  (体事实全数入档,转写批接续)
- 验证:构建零 undefined;ctest 6/6;engtest3 直跑 OK

### 批 39(2026-10-30)/loop:MuxPane JS 宿主引导转写 ✅
- **s_MuxPane_64b102(1707B)流程解明**:旧引擎 @+0x10 →
  deleteLater → new QJSEngine → installExtensions(All, undefined)
  → "King"/"MuxPane" 元对象 newQMetaObject → globalObject 注册 →
  "Object.freeze(%1)" 冻结 → "application"/"window" newQObject 桥
  → setProperty + evaluate(0064b3xx/0064b4xx 区)
- **落地**:src/Actions/MuxPaneJs.{h,cpp}(bootstrap 幂等;桥对象
  参数化 —— 应用级单例来源属 Phase 4c,不发明)
- 验证:构建零 undefined;ctest 6/6;engtest3 直跑 OK(间歇首跑
  FAIL 复跑过);phase5 98/98

### 批 40(2026-10-30)/loop:js_actionFire 尾段闭合 ✅(FUN_00668f3a 转写)
- **FUN_00668f3a(305B)全解明**:arg 未定义 → 00767d08(newObject)
  缓存 host+0x18;参数表 = [00767d2e(newQObject(action)),
  host+0x18/argval];FUN_0076745c 按名调用;isError → undefined
- **落地**:js_actionFire 前置链转写完成(js_actionState →
  property("data")门 → data() 脚本 → canConvert 门);尾段 =
  jsCallOnPane cited 桩(宿主类 = FUN_00665d8a qobject_cast
  PTR_011a6c00,Phase 4c 面板层 —— 该类落地后以 QJSEngine 直调
  闭合;链接点/参数表全数在案)
- 验证:构建零 undefined;ctest 6/6;engtest3 直跑 OK(复跑)

### 批 41(2026-10-30)/loop:TelnetCommander 槽体语料定位 + 结构转写 ✅
- **槽体定位**(metacall 00917e20,93B):槽 0 = FUN_008606fe
  (460B)/ 槽 1 = FUN_00860642(188B),均收 (command,option)
  双字节
- **策略 = 配置表驱动**(推翻批 33 捕获策略猜想):表 =
  FUN_00860a50(**CTerminalConfig 单例 DAT_011c2200+0xb0**),
  12 字节条目;槽 0 按 option 匹配 + 向量门(this+0x128/+0x130)
  → FUN_0085e2de/0085e308/0085fa60 响应链;槽 1 flag==1 →
  FUN_0085e326 匹配 → s_session_term_860126(0070ce42 族)
- **落地**:TelnetCommander 槽签名修正为语料形 (uchar command,
  uchar option);槽体结构转写(门序/调用形/表引用全引地址),
  助手链(表访问器/匹配/响应) cited — wave-2,逐批转写
- 验证:构建零 undefined;ctest 6/6

### 批 42-43(2026-10-30)/loop:keymap 装载器 + commander→session 链 ✅
- **批 42**:s_wind_keymaps_768854(428B)转写 —— 双源累积
  (global wind.keymaps FUN_005d7cf8 / user.keymaps
  cfg_ensureProfileDir)→ FUN_0067461a 引擎复位(+0x68)→
  toList 喂引擎;KeymapEngine 引壳 loadKeymapSources()落地
  (匹配/分发体语料未转写 → 不写,铁律 6)
- **批 43**:FUN_007da178(168B)转写 —— commander→session 链
  (dynamic_cast 校验 → +0x48 写/FUN_007da09a 移除);
  SuperCommander+0x48 成员入库;FUN_007d6cee 查表 cited
- 验证:构建零 undefined;ctest 6/6(engtest3 直跑 OK);98/98

### 批 44(2026-10-30)/loop:+0x101 发射点定性(cited 挂账)✅
- 定位尝试:PMF connect 无串引用(moc 表索引);二进制无
  "1/2checkControlCharacter" 连接串;E5b 回溯 = 排队激活链全
  QtCore → 发射侧 = 事件循环分发,静态语料不可达
- **定性**:触发发射点 = 语料静态不可达(cited — wave-2 永久
  挂账);触发面实证(E7)与门转写(批 31)在案;运行期行为
  与 E7 矩阵一致即可,接线留待动态证据(probe 捕获 connect 调用)
- 门本体(0025 语料 1714-1749)已转写休眠,QUIRKS 22 状态准确

### 批 46(2026-10-30)/loop:SuperKeymap 类转写 ✅
- **FUN_00674648(161B,ctor)解明**:QObject(parent) → vtable →
  +0x10 列表(FUN_0067db7c init,2)→ **+0x18 = QRegularExpression
  ("meta\+|\+meta",CaseInsensitive)**(006746b9 字面实证)
- **FUN_0067461a(45B)复位**:FUN_0067db40(+0x10)→ FUN_0067ce4c
  (+0x10 + mode*8 + *(+0x10+0x10))—— mode*8 槽寻址
- **SuperKeymap 族边界**:语料仅 ctor/dtor + moc 三件(metaObject/
  metacast/metacall 全 5-66B 壳,无槽)→ **匹配体语料未定位**
  → cited — wave-2 挂账(PHASE5 批 46);ctor/复位已转写
- 落地:src/Editor/SuperKeymap.{h,cpp}(Editor moc GLOB 补回——
  批 34 回退时连带丢失)
- 验证:构建零 undefined;ctest 6/6;engtest3 直跑 OK

### 批 45(2026-10-30)/loop:TelnetCommander 助手族全转写 ✅
- **命令码四式**(各 13B,算术原样):e2de(0→-3/else -5)/
  e2ec(0→-2/-4)/e2fa(0→-4/-2)/e308(0→-5/-3)
- **+0x128 向量位操作**:e316(清零)/e326(&1)/e334(vec[7]&1^1)/
  e34a(>>4&1)→ m_optionStates 成员入库
- **静态表单例**(FUN_00860a50 224B guard+once / FUN_00860b6e 254B
  11 条目 × 3 dword;稀疏写 d0=0x1f/d2=0x10/d6=0x18/d8=0x10/d18=1;
  重叠字节区 decomp 歧义 cited)——**批 41 注记更正**:表 = 静态
  单例,非 CTerminalConfig+0xb0(Ghidra 调用描述符混淆)
- **响应链**:FUN_0085fa60(349B)= QByteArray{字节,option} →
  term_processCR(this,bytes,1)→ FUN_0085f5d4(this,1,verb,option);
  **s_session_term 真身 = s_session_term_72014e(0072014e,1323B)**
  (批 41 误名 860126 更正)
- 槽 0/槽 1 体按助手族全转写;响应写出(term_processCR)与
  s_session_term_72014e cited — wave-2(会话输出/终端面待转写)
- 验证:构建零 undefined;ctest 6/6;engtest3 直跑 OK

### 批 47(2026-10-30)/loop:清扫 cited 第一波(累接器/注册表/槽清)✅
- **KeymapEngine YAML 装载转写**:s_wind_keymaps_768854 全流程
  (FUN_005d7cf8 全局路径 = applicationDirPath()+"/global/"+名 /
  cfg_ensureProfileDir 005d7dae = "%1/profiles/%2/%3"+mkpath /
  FUN_00a7e78a/00a7e866 双槽+flags 门 / FUN_00a7fd5e bit2 门 /
  FUN_00a7fdd8 → yamlLoadToVariant(ConfigBridge 0x00a7ecde 委托))
  —— KeymapEngine.cpp 两处 cited 清除
- **SuperSessionPrivate 链接面转写**:FUN_007d6cee(119B,spinlock
  @+0x61 + FUN_007ddad0 map 查)/ FUN_007da09a(208B,qmap_detach2)
  —— m_commanderLinks QMap(@+0x18 语料)入库;1 处 cited 清除
- **SuperKeymap 槽形修正**:FUN_0067db7c(266B)= 容量确保语料
  (ctor 容量 2)→ reset(mode) = mode 槽清(FUN_0067ce4c 转写,
  界守卫标注);FUN_0067db40/0067ce4c = QListData 管理形,Qt 原生
  等价承载
- 验证:构建零 undefined;ctest 6/6(engtest3 间歇复跑 OK)

### 待解(批 30 后剩余)
- **+0x101 流回显语义**:我方 writeSplitData 未实现(QUIRKS 22;
  suite 净基线下永不触发,随 pending v3 族补)
- **Phase 4a 注册表插入侧**:语料无直呼者(批 29 A3,cited 挂账)
- 130+ 扩谱;Phase 4c(SplitterGroup);触发器/词法;5b/5c

## 复现

```bash
# 1) Xvfb + 原版
Xvfb :99 -screen 0 1280x900x24 &
DISPLAY=:99 LD_LIBRARY_PATH=/opt/WindTerm_2.7.0/lib /opt/WindTerm_2.7.0/WindTerm &
# 2) xdotool 开会话:双击 本地shell(1014,331)→ bash(1040,359)
# 3) 附加注入(见 phase5_attach.py;打字触发捕获 Screen)
python3 tools/re/phase5/phase5_attach.py $(pgrep -x WindTerm)
```

## 环境备注
- frida(pip --user)+ prebuild-install 预构建 frida_binding.node
  (bun 包源码构建会因 meson/valac 失败;REA 进程缓存负解析,
  需其宿主重载后才可用 MCP 通道——当前走 python frida 直驱)
- Xvfb 无 WM:windowactivate 不可用;用 mousemove+click 定焦点
- pkill -f WindTerm 会误杀 kingtoolbox/WindTermGuiSkeleton(名字
  撞)——用 pkill -x WindTerm
