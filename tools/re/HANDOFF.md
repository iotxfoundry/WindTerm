# 新会话起点(交接文档)

> 用途:新会话冷启动。先读 AGENTS.md → 本文件 → docs/PLAN.md →
> docs/QUIRKS.md(22 条)→ docs/PHASE5.md(差分对比专篇),即可续作。

## 一句话状态(2026-10-30 第六次交接)

**Phase 5 收官:98 序列 98/98 MATCH 全绿**(批 30:tbc3 归绿终裁
v2——批 29 的"停手"结论**作废**:其 1 净/4 字面测于未复位流态;
机制实锤 = **+0x101 流回显**(ESC-single → 下批首序列回显字面,
QUIRKS 22),baseline() resetState 后 tbc3 5/5 干净,全量差分
98/98 ×2 + 稳定性复读网)。**Phase 4a 会话管理 A1/A2 ✅**:
ShellSession::stop(pty+断链+清 screen 挂钩)、**TelnetSession 网络
接线**(QTcpSocket + RFC 854 默认拒绝响应在会话层 + IAC 状态机);
注册表**插入**侧语料未定位 → wave-2 挂账。**ctest 11/11 全绿**
(+telnetsocket_test 回环 +shellsession stop 冒烟)。probe38b 矩阵
终裁见 PHASE5 批 29(字面先行/动作批尾/ESC-single 入口 flush 且
组合注入 M 丢失)。**本地领先 48 提交**(未推送,遵规范)。

**engtest3 段错误根因已修**(5b773aec,推翻批 24"环境竞争"结论):
Screen ctor 漏初始化 m_savedPrimary/m_altCore/m_viewSettings →
resizeScreen 拿垃圾指针当核(rdi="QPolygon" 串地址实锤);ctor 补
nullptr 后裸跑 75%→10%(残余 = 另一类间歇,直跑复核通过即例外)。

## 一句话状态(2026-10-29 第四次交接)

**Phase 0/1/2 ✅;Phase 4b 渲染层+键盘闭环 ✅;Phase 5 差分管线:
自包含基线 + 60 序列(含 decaln/wrap_edge 回归)** 56/60 MATCH;
**批 14-20:背书债清偿(#2/#3/#7/#8/#9/#10)+ HTS/CHT/HT 入队 +
rowDeleteCells 修正(probe14:DCH 不缩 length)**;Phase 3 WT
分派 93/149;配置面资产探明(CONFIG-SCHEMAS);ProfileLoader
全局层 ✅。QUIRKS 19 条。**剩余 4 diffs 全部定性**:bs(27)/
tbc_all(HT flush 链)/crlf(v3)/wrap_edge(行池)。

**本地领先远端 22 个提交(未推送,遵"只提交不主动推送"规范)**。
用户说"推送"时一次性 push。

## 里程碑链(全部 ✅)

语法/moc/构建/dlopen → 三层真实现 → CMake → moc 权威抽取器 →
行为测试矩阵 → 配置层贯通 → 端到端写路径 → Phase 4b TerminalWidget
58 槽 + **渲染层(TerminalView 格子/SGR/光标/调色板管线)+ 键盘
闭环** → **Phase 5:Xvfb + Frida 差分管线,38 序列 36/38 MATCH**。

## Phase 5 差分管线(核心资产,详见 docs/PHASE5.md)

- **原版驱动**:tools/re/phase5/phase5_dump.py(附加运行中的
  原版,Xvfb + bash 会话;xdotool 打字触发捕获;writeSplitData
  007d1f5a 注入;core +0xc4/+0xc8 光标、行 +0x74/+0x78、
  row +0x0c/+0x40 读格)→ phase5_original.json
- **我方驱动**:engtest4.cpp(writeText/processOutput → 同格式
  phase5_ours.json)+ python diff(游标+行 0..2 逐字节)
- **环境**:Xvfb :99 + 原版(bundled Qt;offscreen QPA 会话段崩
  不可用)+ xdotool(点击开 bash:双击 1014,331 → 1040,359;
  打字触发回显捕获 Screen)+ **exec sleep 100000 哑化 shell**
  (防提示符重绘干扰,ALL MATCH 基线前提)
- 链接测试二进制:无 LD_LIBRARY_PATH + `-Wl,-rpath-link,/
  usr/lib/x86_64-linux-gnu`;运行时 bundled Qt(/opt lib)

## 关键发现(逆向对齐用,详见 PHASE5/BUILD-AUDIT/EXT-BOUNDARY)

1. **writeText(007e6f42)= 后处理写入器,非 ANSI 解析器**(双侧
   实证);真解析链 = writeSplitData(007d1f5a)→ 007d10c5 →
   vt14 → writeText
2. **ESC D/E = 光标不动;ESC M = 下移 1 行**(QUIRKS 11-13,
   per-key 实测);ESC M 组合注入(CUP+M)动作丢失语义待定型
3. **RunNode 值类型**(0096bac0):{style<<1|flag, pos, width};
   RunPair 区间;标记注册表 = 有序去重表
4. 原版静态嵌入:boost 1.78(xpressive,**未复刻差距**)/yaml-cpp
   0.7.0/jsoncpp/dtl/zstd;spdlog 0 符号;onig 0(已删误判)
5. paletteColor 公式 = 容器 + index*4 + *(容器+0x10)(QArrayData
   offset 域);malloc/free 家族统一(makeRow/growRowArrays)
6. **配置面资产已探明(docs/CONFIG-SCHEMAS.md)**:global/wind.config
   = 权威默认层(138 行全键表);装载顺序 wind.config → user.config
   (运行期样本互证);wind.keymaps = 键位引擎输入格式(2391 行,
   {keys 正则, modes, action|script});triggers.config = expect
   正则权威来源;schemes/*.lexer = TextMate 式 prompt 识别;
   telnet.protocol = 转义引用表;user.sessions auth blobs =
   Cryptographic 已知密文样本

## 下一步(按优先级)

1. **+0x101 流回显语义补齐**(QUIRKS 22,挂账):我方 writeSplitData
   未实现 ESC-single → 下批首序列回显字面(007cadda/@7d2077→
   007cc1fa→writeText);suite 净基线永不触发,随 pending v3 族
2. **Phase 4a 收尾**:Commander UUID 表**插入**侧(wave-2 挂账,
   插入函数语料未定位;邻接面 007da178/007da09a 已记)
3. **键位 action 执行面**:KeymapEngine 命中 → wind.actions 分发
4. **TelnetSession RFC 策略细化**:按 telnet.protocol refs 对已知
   option 回 WILL/DO(现全默认拒绝);触发器/词法引擎
5. 98→130+ 扩谱;Phase 4c 主窗口(SplitterGroup 补类)
6. Phase 5b(编辑引擎行为对比)/5c(会话持久化对比)

## 已知开放问题

- ESC M 组合注入动作丢失(QUIRKS 13,异步排队/合并语义)
- IND/RI/NEL 滚动区外钳制(DECSTBM 后区外行为,32/35 的 3 差异
  已随 exec-sleep 哑化消解,待复核)
- m_writeTemplate 生命周期(payload 域 0x10101 junk 写入者)
- convertRowToHistory(007a9582)RunStyles 文档桥
- REA 的 MCP 通道需宿主重载(当前用 python frida 直驱)

## 环境速查

- frida:pip --user(17.24.3);REA binding 已修(bun prebuild-install
  走代理)但需宿主重载
- 测试:`cd build && ctest`(**11 测试**:行为门 6 + keymap/
  telnet/pty/shellsession/telnetsocket 五冒烟;engtest3 ctest 态间歇——直跑复核;
  见 tests/README.md)。RE 探针:tools/re/metatest/(手工 g++;改
  头文件后必须重编,踩坑 15)
- ptrace_scope=0(已设,重启后需重设:sysctl -w)
- libssh-dev/patchelf/Xvfb 已装

## 服务器/环境重启恢复流程(批 20 实战)

1. `sudo sysctl -w kernel.yama.ptrace_scope=0`(**须 sudo**;非
   sudo sysctl -w 静默不生效→frida attach PermissionDenied)
2. Xvfb :99 + WindTerm 重拉 + 双击开 bash(1014,331→1040,359)+
   `exec sleep 100000` 哑化
3. **build 树重建**(/tmp 全清):cmake <repo> -B /tmp/opencode/
   wtbuild2 + make -j;**engtest4 硬编码读 /tmp/opencode/
   phase5_seq.json——从仓库恢复副本**
4. **probe 与 dump 会话隔离**:probe 注入污染 stop 表等会话态,
   probe 后必须重开会话再 dump
5. engtest3 光标 XOR 间歇(~1/3)已知非阻断

## 提交规范(2026-10-29 修订)

- 中文 commit;**只提交,不主动推送**(push 仅在用户明示时执行,
  届时必带 `-c http.proxy=http://192.168.1.106:7890`)
- 每轮:改动 + 对应 .md 更新,一条 commit
