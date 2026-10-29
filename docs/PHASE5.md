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

### 待解(下一轮首任务)
- **pending 模型 v3 实现**:CSI 全动作(CUP/CNL/CPL/CHA/VPA/CUU/
  CUD/CUF/CUB…)入 pending 队列(动作枚举+参数),flush = 入口 +
  timer;对齐后 crlf_cup_text 归绿
- **tabstop 默认表**:resizeDefault(007a604a tail)语料精读
  (every-4?单元素 {4}?);HTS(ESC H)pending 疑云(hts_tab →0)
  probe 裁决
- 格体 aux 深水区(DECALN/wrap,批 12 定位)仍在队列
- 58→100+ 扩谱(doAction 全量伴生)

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
