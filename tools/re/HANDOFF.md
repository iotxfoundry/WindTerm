# 新会话起点(交接文档)

> 用途:新会话冷启动。先读 AGENTS.md → 本文件 → docs/PLAN.md →
> docs/QUIRKS.md(13 条)→ docs/PHASE5.md(差分对比专篇),即可续作。

## 一句话状态(2026-10-29 第三次交接,批 13 更新)

**Phase 0/1/2 ✅;Phase 4b 渲染层+键盘闭环 ✅;Phase 5 差分管线通:
自包含基线 + 原版会话重置后 **58 序列 54/58 MATCH**;38 序列回归
全绿(pending 队列);Phase 3 WT 分派 93/149 case;配置面资产已
探明(CONFIG-SCHEMAS);ProfileLoader 全局层 ✅。** QUIRKS 16 条。

**本地领先远端 12 个提交(未推送,遵"只提交不主动推送"规范)**。
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

1. **会话污染清除 + 58 干净 diff**(批 15 教训):重置原版会话
   (probe 用完即弃/独立会话)→ tab/bs/cht2/hts_tab 复核
2. **m_sgrState 污染专项**(背书债 #10):DECALN 后 junk-aux 链,
   审计 m_sgrState 0x20 块 +0x10/+0x18 域的写入者 → decaln/
   wrap_edge 回归
3. **HT pending 证据**(批 15 probe9):HT 效果延迟一步;stop 表
   {4} 单元素来源未定位;hts_tab→0 待裁决
4. **pending 模型 v3**:证据冲突(probe a 0.02s vs probe4 0.24s)
   ——flush 驱动(GUI paint?入口?timer?)probe 定型后实现
5. 格体 aux 深水区余项;doAction 全量(v3 伴生);58→100+ 扩谱
6. **键位引擎**(Phase 4a):wind.keymaps;动作查 wind.actions
7. 渲染层余项;engtest3 光标 XOR 间歇;Phase 4a 启动路径

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
- 测试:`cd build && ctest`(行为门 6 测试,环境已封装;见
  tests/README.md)。RE 探针:tools/re/metatest/(手工 g++;改
  头文件后必须重编,踩坑 15)
- ptrace_scope=0(已设,重启后需重设:sysctl -w)
- libssh-dev/patchelf/Xvfb 已装

## 提交规范(2026-10-29 修订)

- 中文 commit;**只提交,不主动推送**(push 仅在用户明示时执行,
  届时必带 `-c http.proxy=http://192.168.1.106:7890`)
- 每轮:改动 + 对应 .md 更新,一条 commit
