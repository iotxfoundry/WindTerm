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
1. **writeText(FUN_007e6f42)= 后处理写入器,非 ANSI 解析器**:
   注入 `ESC[31mR` 后格子字面落 `ESC[31mR`,游标逐字节推进。
   ——我方 writeText 内嵌解析(e2eterm 路径),**架构分歧已锁定**:
   原版解析在 vt14 支路或更上游(见 3)。
2. **vt14 门语义(实测)**:
   - commander+0xfc = 0(实机会话态)
   - screen+0x137 = 0 → vt14 不折不析(字面);
     = 1 → ESC 折叠/解析支路(indexOf(0x1b) + case 0x44…)
   - screen+0x12c ≠ 门(翻转无效);FUN_007cba64 = +0x137 读
3. **宽字符/换行/回车行为与重建一致**:`\r` 归零、CJK 双格 +
   0xffff 尾、world 写行首——字面态下与 e2eterm 断言同构。

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
