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

### 待解(下一轮首任务)
- **格体 aux 深水区**(decaln/wrap_edge 触发):adjustScreenAlignment
  的 setCell(y,x,0x45,m_sgrState) 把状态格当 MOVE 源 → 格体四域语义
  错位 → junk aux(0x10101 = m_sgrBits 值被当指针)→ free 崩。
  wrap_edge = writeText wrap 路径同簇(HANDOFF 开放问题 m_writeTemplate
  实锤)。需精读 FUN_007a5aac(setRowCell)/FUN_007e4916(setCell)/
  007e515e(wrap-pending)语料 + aux 对象布局
- 原版侧会话重置 + 58 序列干净对比 → 目标 58/58
- hpa(`)/cht2(I)/cubOob/vpaOob/osc 的我方分派逐条对原版裁决
  (hpa 原版读数 (4,4) = CUP 生效 HPA 忽略?待干净会话复核)
- 我方 sgr_rgb 后 X 残留 row1(ris 读数 row1[0]=88)——writeText 写入
  位置或 ESC[2J 清除范围待查

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
