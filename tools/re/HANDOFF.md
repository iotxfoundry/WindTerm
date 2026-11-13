# 新会话起点(交接文档)

> 用途:新会话冷启动。先读 AGENTS.md → 本文件 → docs/PLAN.md →
> docs/QUIRKS.md(22 条)→ docs/PHASE5.md(差分对比专篇),即可续作。

## 一句话状态(2026-11-13 第十九次交接,批 122 · M3 收官)

**M3「Phase 5b 行为对比 + vtable 清偿」收官**:② vtable 转储定案 ✅
(批 119:scanMask 双 cited 清偿,engVt50Block/engVt28Class 真身,
三 vtable 两源身份);① Phase 5b **通道与构造双突破但 A/B 对表未满**:
armed 0x418c4 钩 + editor ctx 桥(批 121)/ frida 真 ctor op 运行期
构造成功(批 122,Grep 0x68 体 FUN_00899fba)/ C 族 1 MATCH(C2/C3
仪器性)/**A/B 18 NOT-RUN 维持** — 解锁路径已钉死:terminal 与
editor 两种 doc +0xe0 承载不同构(QString 直写 abort),欠「editor
型 doc + find 串写入」一次实验(phase5_editor_b122_op.js ctor 腿
资产已留)。RUBY 终裁:**维持假设,零反例**(字节级六样例直证我方
侧;原版侧直证随 A/B)。QUIRKS #29/#30 新增。此前:M2「编辑器残项
清零」达成(批 117/118);M1「编辑器搜索链闭环」达成(批 116b)。
本会话累计批 102-122 共 **21 个实现批**,ctest
**18/18** + dlopen OK,本地领先远端未推。**批 107-109 第二轮三车道并行**:批 107 M 跟踪器写侧(0099b152/
0099b15e + 两段容量机 0088a016/00889e2e 真身;0xfffff 迁移腿/
灌值腿仍 cited 外库链;车道首轮输出耗尽零产物,原会话复活+范围
降档救回);批 108 MuxWindow BYTE 旗标勘误(**错转写修正**:m_f40
QString = Ghidra 8B 槽误型 → bool 双旗标,S7/S9 落码,QUIRKS #28);
批 109 FindContext 取证未激活(编译栈全图 00a81655→00a9c780←
00ad7360;双卡点 = 改版语法/编码 face 静态转储完成,布局对照需
改版头,激活入口改为读 00aa1f70/00aa1f80 函数体)。**批 104-106**:M 跟踪器
建模(ModTrack.h;ctor 链 editor_engineCtor 00929bf8 破案,+0xf0 消解)
+ markerBand 00927a78 升真身 + modtracktest 17 断言;批 105 0x4eff
取证未激活(针对象无编译产物字段勘正,正则住 FindContext 深腿,
选项不可达不猜,CALIBRATION 激活清单);批 106 四槽 3/4 真身
(confirmPaneClose/setPaneZoom/renamePane;showConfigMenu KitWindow
无承载),MuxWindow BYTE 旗标勘误挂账。**批 103 三 lane**:c91e thunk 寄存器洗牌勘正(p4=0/p5=0/p6=i,
批 83 三处纠错,elem 门=j==i 单元素,p4==1/2 腿经 thunk 恒不达);
M 跟踪器七函数全读 + 布局定案(RS8 游程面/flat 两段文档面/zstd
压缩腿新发现,建模留批 104);Onigmo 激活勘察(src/Onigmo 全树 +
libonig 委托面就绪,业务区零 onig 直调)。**批 102 四 lane**:00b422d0 边界定案(Onigmo-改 搜索驱动,停逆向,
src/Onigmo 委托,EXT-BOUNDARY 登记);scannerResetState 009cc2d4
真身(prune 腿闭环);upgrade len 参残寄 kuna asm 破案(RCX=re−rs,
壳期同相零改动);markerBand 00927a78 桩回填前置登记(七函数族
未建模);0x75dc 全二进制扫描闭环(间接面 0 命中)。np/re 37MB 误
入库 git rm。**批 79-99 二十一连批闭环**:markers 全链闭环(D 0x70 布局/读侧 16/
构建者六方法+markersCtxInit/迁移腿 6/6 migrateLayer/regionScan 1407B
/0x7543 驱动装配+wireSlot10/QUIRKS 26·27 定案+entryValueAt 修正);
渲染核全链(S1-S6 全/a66ae8 骨架+0x7547 接线/hotSpot/parsePairDef/
68b18/selection 三函数+Span56 成员化/PairColor zstd 委托+ZstdFace/
M3 26 槽/codec memo CodecMemo 五真身);keymap 双翼+matchTrie
§4-§15(§4-10 真身/§11 谓词 boost/§12 宿主=Qt 导入 QMainWindow
破案/§13-15 真身);Telnet 全链(装配五元组/头勘正/ProxyCommandSocket/
spawn S1-S5/onReadyRead=纯转发破案);UI 界面五级装配链运行验证
(15/15);replaceText 0x4f00·0x4eff 真身;phase5_px 像素差分骨架
(单点探针全链实证);King 面+ApplicationTheme;测试 15 项
(markerstest 70 断言/runstyles 41/rendermath 14/renderpix 11/
keymap 19/proxysock 5/uiassemble 17/kitbar 11/mwctest 4/
renderpixtest 11)。

**EXT-BOUNDARY 定案累积**:0x11a6c00 = Qt 导入 QMainWindow::staticMetaObject
(三勘)/keymap 谓词+挂链 = boost xpressive matchable_ex/PairColor
zstd 委托/libssh 117/QJSEngine 45/regex Onigmo 前置。

## 终点条件(2026-11-13 用户定:达成里程碑 M1 即停,不再无限续杯)

**里程碑 M1「编辑器搜索链闭环」**——以下四项全部定案(真身或登记边界)即达成,主控做终局总结并停止开车道:
1. 0x4eff 正则搜索激活:新形态 = 缺省语法预编译 + onig 委托搜索(批 110 定案:语法硬编码无参数化入口),行为断言钉住
2. c1c2 剩余 cited 全定案:p4==2 去重 store(ctx+8)/入口 0095c086/迭代器 00a162b6·00a161d8
3. M+0x28 行槽 + flagmask_set_range(0099b740)建模 → b740 位掩码腿回归(消解批 113 风险:整字节写 vs 逐位面)
4. M 迁移腿 0099bc2c 裁决:转写或登记外库边界(piecetable/线程池链)

## 终点条件(2026-11-13 用户定:M1 已达成(批 116b);M2「编辑器残项清零」亦已达成(批 118),车道停开)

后续会话拿新终点条件再开批;余项队列(批 117 队列 + M2 登记项)如下。

## 下一批队列(批 119 入口 — 余项,新会话按需开批)

1. **Onigmo-改 buffer vtable 槽转储批**(.data.rel.ro +0x50/+0x28
   块语义两证 — scanMask 双 cited 清偿唯一路径,批 118 登记)
2. **0x4eff 激活余项**:RUBY 语法假设的原版行为对比(phase5 管线
   扩谱)/DAT_011becc8 运行时观察(批 110 观察项)
3. **c1c2 busy 腿重开条件**:改版线程底座头到手(批 117 登记)
4. **showConfigMenu KitWindow 承载**(011ab390;批 112 已取消,重派
   需先主控侦察承载面再发窄任务书)
5. Phase 4a 注册表插入侧 / Phase 4c SplitterGroup 余项 / 130+ 扩谱 /
   Phase 5b/5c(编辑引擎与会话持久化行为对比 — PLAN 终点)
6. ~~行槽~~(117)~~busy 腿~~(117,登记)~~scanMask cited 定案~~(118)
   ~~0x75dc~~(102)~~KitBar~~(98)~~四槽~~(106)~~p6 残寄~~(103)~~MuxWindow BYTE~~(108)
   ~~M 写侧~~(107)~~markerBand~~(104)~~0x4eff 激活~~(116)

## 车道方法论沉淀(2026-11-13,三轮 10 车道实战)

- worktree 隔离 + 写域互斥任务书 + 主控统一 docs = 零写冲突(三轮验证)
- 大语料读取型任务书**必须带输出上限**(批 107 首轮教训)+ **边读边落**
  (批 112 500+ shell 零产物教训,已取消重派)+ shell 预算上限(批 114-116)
- 取证型车道配失败条款有效:批 105/109/110 三次正确拒绝无证激活
- 权限审批:车道 worktree 路径用 reply always 预放行,减少打断
- 车道越权写 docs(PHASE5)两起(111/115):内容合格保留,主控合流时核对

## 一句话状态(2026-11-01 第十次交接)## 一句话状态(2026-10-30 第九次交接)## 一句话状态(2026-10-29 第四次交接)

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

1. **keymap 匹配体转写**(已定位+勘察批 54):FUN_0067500e(9978B
   递归树行走,0067 包装族依赖)+ keys_parseAngleNotation 00674cdc
   (753B,结构已读)—— 包装族逐个转写前置
1b. **Phase 3 命令补全**(批 57 精确清单):语料 dispatch
   s_line_caret_remote_a418c4(00a418c4,37951B)= 151 命令;缺失
   70(清单在 PHASE5 批 57)—— 每条 = 巨 switch 内体读取+转写
2. **TelnetSession 装配重做**:语料面已侦察 —— TelnetSession 族 =
   vt15(008616ea,303B,协商响应构建)+ metaObject 00917f76/
   metacast 00917f8e/metacall 00917fd0(5B 无槽壳);QTcpSocket
   使用面在 decomp 0001-0003 部(Qt 库区,装配点待定位);
   negotiationReply 写出点已备(批 48b)
3. **MuxPane 面板装配**(Phase 4c):ThemeIcons::setThemeDir 装配
   期接线 + 面板 QWidget 面语料定位
4. **+0x101 发射点动态证据**(QUIRKS 22:门已转写;connect probe
   捕获激活链 = 静态不可达的动态补充)
5. **Telnet 助手深链**:s_session_term_72014e(1323B)/
   term_processCR 写出面 / FUN_0085f5d4 日志体(1108B)
6. 98→130+ 扩谱;Phase 4c;Phase 5b/5c

## 已知开放问题

- ESC M 组合注入动作丢失(QUIRKS 13,异步排队/合并语义)
- IND/RI/NEL 滚动区外钳制(DECSTBM 后区外行为,32/35 的 3 差异
  已随 exec-sleep 哑化消解,待复核)
- m_writeTemplate 生命周期(payload 域 0x10101 junk 写入者)
- convertRowToHistory(007a9582)RunStyles 文档桥
- ~~REA 的 MCP 通道~~已解决(2026-11-13):项目级 opencode.json 配置 rea(stdio,207 工具,含 Ghidra/Kuna/JADX env)+ ida(remote localhost:13337/mcp,ida-pro-mcp 1.4.0;IDA 开着才连得上);python frida 直驱仍可作备用

## 环境速查

- frida:pip --user(17.24.3);REA binding 已修(bun prebuild-install
  走代理)但需宿主重载
- 测试:`cd build && ctest`(**13 测试**:行为门 6 + keymap/
  telnet/pty/shellsession/telnetsocket/echo_semantics/actions 七冒烟;engtest3 ctest 态间歇——直跑复核;
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
