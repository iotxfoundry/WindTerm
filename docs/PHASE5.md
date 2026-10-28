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

### 待解(下一轮)
- **真解析入口定位**:实机 +0x137=0/+0xfc=0 下 pty 数据(含彩色
  提示符转义)必然经另一解析路。方法:hook writeText,待
  ESC 含量 >0 的写入时 Thread.backtrace() 回溯调用链 → 找真解析器。
- 差异化对比序列(CUP/ED/EL/SGR/DECSC…)——解析入口定位后
  逐序列落格对比(格式化管线已通,见 phase5_original.json)。

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
