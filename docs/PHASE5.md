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

### 待解(后续轮)
- **格 aux 所有权簇收口**(ICH/DCH/ECH 堆损坏):按语料双原语
  语义(007aa3a6 move+release / 007aa2e2 deep)重排擦除/插入族
  的模板生命周期,再跑 35 序列 diff。
- **ASan 精确定位 ✅(下一轮首任务)**:heap-buffer-overflow
  READ@copyCell(TerminalCore.cpp:984)← rowInsertBlanks:926
  (move-shift 搬移循环);被越界读的缓冲 = **Tabstops::
  resizeDefault 的 payload(new[] 11B)**——即某行 cells 指针与
  制表位缓冲混叠。根因指向 growRowArrays 的 CellArray 覆盖
  {cap,count,data} 写 row+8/+12/+16:我方 C Row 结构(编译器
  布局 length@+8/_pad0@+0xc/cells@+0x10)与语料 Row(0x58,
  length@+0x0c/cells@+0x10)偏移不一致,覆盖写把 length 当
  cap、_pad0 当 count 使用, cells 指针与行内其他域的相对关
  系错位。修法:growRowArrays/rowInsertBlanks 按语料偏移直接
  编址(不依赖 C 结构布局),35 序列 diff 后全绿收口。
- doAction(007d1606,2292B)全量 + 状态机表 dump。
- C1 折叠开态对比;multibyte 挂起尾态对比。

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
