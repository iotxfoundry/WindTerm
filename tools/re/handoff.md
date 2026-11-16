# 新会话起点(交接文档 · 单页当前态)

> 用途:新会话冷启动。冷启动顺序:AGENTS.md → 本文件 → docs/plan.md →
> docs/phase5.md(**顶部「结论快照」节 = 当前真值,正文批次流水为审计
> 轨迹,冲突时以快照为准**)→ docs/quirks.md。
> 本文件 2026-11-14 重构:旧 24 层堆叠交接删除(历史在 git log,
> 检索关键词"第 X 次交接");永续内容(环境/恢复/提交规范)保留。

> 目标:编译出与 ./WindTerm 行为一致的程序。

## 一句话状态(2026-11-16 第五十八次交接,批 493 — 文档重整)

**规模**:自基线 `3b7a774f` 起 **330 提交 / 139 文件 / +11816 行**,
新增 **59 个 `*Face` 头**(`src/Actions` + `src/Widgets`)。
**纪律**:铁律 7(零编译零测试)贯穿全部批次 —— **可编译 / 可运行仍为 0%**。

**七节覆盖率(按 gui-map 条目加权 ≈ 95%)**

| 节 | 覆盖 | 已落锚点(逐批判据见 `tools/re/gui-map.md`) |
|---|---|---|
| ① 主窗装配 | 90% | `008d3cc2` 全链 + 中央七槽树(`0x68[0x58[0x38,0x60[0x48],0x40],0x50]`)+ 槽位族 + 焦点链 |
| ② 菜单 / 动作 | 95% | **数据源** `wind.actions` + `user.actions` 两层 → 整树装载 7702B → 六属性应用(`script/text/tooltip/state/icon/kits`)→ `actions_from_config_list` → QAction 树 → 懒构建(`aboutToShow`)/ 触发 → **`js_actionFire`** |
| ③ 工具栏 / 状态栏 | 80% | 七 kind 全真身(含 `AddressBar` / `SearchEdit` / `FilterEdit` / Ready 染色) |
| ④ 对话框 | 95% | **29 个 QDialog 全清**(含 1 个工厂型 `TriggerActionDialog`)+ 10 个对话框 build/wire 分工与装配面落真 |
| ⑤ 设置页 / 触发器页 | 93% | 行模型 `SettingsRow` 0x48 + 八路接线 + **八个触发器页装配全落** + 线型表 14 项 + `ColorButton` |
| ⑥ dock / 标签 | 85% | KitDock 全套 + **页签关钮机制闭环**(只当前页有钮 / 空名·`Pinned` 无钮 / 三平行表 move) |
| 5c 状态存取 | 写 95% / 读 85% | blobA/B/C 真身 + QuickBar/TransferBar 读写四腿 + 尾钩默认腿定案 |

**收尾期第一步**:`docs/pending-attribution.md`(归属工作单)——
`SettingsPageFace ↔ TunnelDialog` 的 6 项函数迁移,清完再编译;
否则语法错与模型错混在一起,无法定位。

此前里程碑:M24(192 前五腿)、M23(180-184)、M22(177-179)、M21(173-176)、
M20(170-172)、M19(166-169)、M18(162-165)、M17(158-161)、M16(154-157)、
M15(150-153)、M14(145-149)、M13(142-144)、M12(138-141)、
M11(136/137/136b)、M10(134/135)、M9(132/133)、M8、M1-M7。

## 里程碑总账(全部 ✅,定义均为用户终点条件)

| 里程碑 | 内容 | 达成批 |
|---|---|---|
| M1 | 编辑器搜索链闭环:0x4eff onig 委托激活/c1c2 剩余定案/M+0x28 flagmask/迁移腿裁决 | 116b/115/114+114b/111 |
| M2 | 编辑器残项清零:行槽接线真身/busy 腿边界登记/scanMask 定案 | 117/118 |
| M3 | vtable 清偿 + 5b 通道与构造(原版捕获对表部分完成) | 119/121/122 |
| M4 | RUBY 直证终局(UI 向量判死 → 假设永久化)+ 扩谱首批 9 条 | 124/125 |
| M5 | 扩谱二批 14 条 + scanMask 活性接线(buffer 承载建模) | 126/127 |
| M6 | initDoc 挂线零点定案 + transient 根治 + 扩谱三批 15 条 | 128/129 |
| M7 | 扩谱四批 14 条 + KitWindow 侦察方案书 | 130/131 |

## 已定案边界与永久假设(新会话勿重开)

- **RUBY 语法假设(永久化,批 124 终裁)**:0x4eff onig 委托以
  ONIG_SYNTAX_RUBY 预编译(批 116 五真实样例对账);两条证伪通道
  实证封闭——注入通道(memo 唯一串源,dispatch 无 find 写命令,
  批 123 op+0x18 零消费证伪批 122 绕行)与 UI 向量(quick-find ≠
  SearchPane 三框面,批 124 frida 双钩零命中)。理论备选 =
  SearchPane UI 自动化输入(未试,需 SearchPane 弹出条件侦察)。
- **外库边界登记**:busy 腿 009e975a(doc 批处理通知器 + 线程池
  底座,批 117)/迁移腿 0099bc2c(piecetable 链,批 111)/
  Onigmo-改(ext-boundary 第一方组件,批 102 定案:00b4xxxx 停
  逆向,src/Onigmo 委托)。
- **scanMask 活性接线 ✅**(批 127:buffer 承载建模 + s_scanCarrier
  缝;残项 0x7543 initDoc 驱动挂线经批 128 定案 = **零接线点**,
  RAII 即语料挂线,FUN_0092ef06 拆建腿不含 +0xf8)。
- **KitWindow = 抽象基类**(menu() 槽 62 纯虚,showConfigMenu 消费
  = 零字段 + 一虚调用);转写车道照 docs/history/kitwindow-recon.md
  方案书**免侦察直执**(批 131)。

## 勘正谱系(现结论 ← 被勘正;新会话读到旧结论先查此表)

| 现结论 | 勘正来源 | 被勘正旧结论 |
|---|---|---|
| `TriggerDialog`(0xe0) = 页栈 006f440e / 接线 006f2852 **同一宿主** | 批 346(ctor 字段三源吻合) | 批 343 记"宿主类名未定" |
| `nameDialogAddFormRow` 为 **三实参**(dlg/标签/字段) | 批 347b(asm 0x6bd25c/5f) | 批 347 两实参落 |
| pane 菜单前缀 **0x04000000=Ctrl / 0x02000000=Shift** | 批 355(asm 0x8c3cbf 分支序) | 批 336 二者写反 |
| `TriggerRecord` 语义:+0x08 名 / +0x10 UserRole 键 / +0x18 描述 | 批 354(34dd 回写 + 263e setData 0x100 互证) | 批 349 首判 +0x10=名 |
| `+0x10` = **uuid**(`QUuid::toString(WithoutBraces)`) | 批 368(80B regenerateKey) | 批 354 "UserRole 键" |
| `TriggerActionEditPanel`(`0056376e`) = **动作文本面板 0x68**(非"编辑面板") | 批 377(ctor 字段 + 五页 +0x38 用法) | 名不副实 |
| TabBar `005a80f8` = **`QTabBar::setTabButton` 等价**(非私有面) | 批 472(函数体 +0x78/+0x80 两槽) | 批 46–190 "QTabBarPrivate cited" |
| 对话框共 **29 个**(含 1 个工厂型 `TriggerActionDialog`) | 批 476(工厂型扫描 + 全库复查) | 批 438 记 28 个 |
| `s_ActionButton_56e540` 基类 = **QToolBar**;`s_BackwardButton_53e936` 基类 = **QShortcut** | 批 488/493(基类调用实读) | 字面"Button"误导 |
| 表件基类 = **QTableWidget**(非 QWidget) | 批 387(语料直接 rowCount/setColumnCount/paintEvent) | 批 382 按 QWidget 建模 |
| 动作表 `+0x10` = **QHash**<QByteArray,QAction*>(非 QMap) | 批 391(qHash/FUN_0066b584 查) | 批 391 初稿措辞 |
| `006926c2` = **按名线性扫表**(memcmp),非 QMap 查 | 批 397(逐项内存比较) | 批 356 "QMap 查" 注 |
| 3404B 建造 / 935B 接线 / 0xa8·0xb0 列表 **属 TunnelDialog** | 批 415/417(ctor 0072cf44 调用链) | 批 258/414 记在 SettingsPageFace 名下 |
| 设置行 widget `+0x30` = **QLabel** | 批 417(`0072d0f2` 调 QLabel::clear) | 批 414 误记 QGridLayout |
| **归属判定法**:0x72xxxx 区间仅 4 个 ctor,看"ctor 调用谁"即可定类 | 批 420-428(四 ctor 全读) | 批 246/258 按地址邻近猜归属 |
| `getOrCreate` 特例条件是 **qstrcmp(name,"Text.HighlightTextBar")**,非 "::" | 批 392(asn 0x665f2x) | 批 391 首判 "::" |
| `NameDialog +0x30` = **允许空名旗标**(置位写 tr("Optional")) | 批 390(`006bdbe4` 249B) | 批 386 首判"默认态" |
| `s_terminal_ansiBrightBlack_699c2a` = **记录构造函数** / `s_king__beforeDisconnection_69934c` = **kind→图标** / `expectDialog_saveRows` = **映射→表** | 批 359/361/365(函数体实测) | 名不副实(3 例新增) |

| c1c2 p4/p5/p6 = 0/0/i( thunk 0095c91e 寄存器洗牌) | 批 103(kuna asm) | 批 83:p4=i/p5=sv/p6=-1 |
| T 段 fA/fB = bit4 位 + mtBit4SetClr 位面写 | 批 114b(asm 三源) | 批 113:整字节写 |
| wordsteptest transient 真因 = i3 simdBlocks 0x10 应为 len<<4 | 批 128 | 批 126:"未定位" |
| UI quick-find ≠ SearchPane 三框面 | 批 124(frida 双钩零命中) | 批 123:UI 误读 |
| GrepNeedle448 无 regex 编译产物字段 | 批 105(kuna 全读) | 批 93 假定 |
| 0x4eff 激活形态 = 预编译缺省语法(引擎硬编码,无参数化入口) | 批 110(face 定案) | 批 109 传参假定 |
| 0x7555/7557 非批 77 同体 | 批 130(清点) | 批 77 清点 |
| dat_d15860 = 编译环境 face(fold 表非恒等) | 批 110 | 主控批 109 静态转储初判 |
| FUN_007da228 = +0x40 **Logger** 表插入侧(三源:ctor vtable/loggerRemoved 配对/qmo idx5) | 批 141 | 批 141 任务书判读"Term 表" |
| 两 Config 单例基构造 = FUN_008a71e4 **CGlobalConfig**;SharedConfig = 独立 0x18B 小类非基类 → face 平铺 | 批 140(ctor 首句实读) | 批 138 侦察:SharedConfig 基类候选 |
| 0x4ec2(20162)落 SCI/EXT 边界下沿,dispatch 门 cmd≥20163 漏叶 → 已截获 | 批 139 | 批 137 前"门 20163 全含"假定 |
| configPath = DAT_00cba75c "/" 单字符 | 批 147(二进制实读) | 批 140 "/configs/"(槽内嵌串误读) |
| `smeta 011a2240` = **SessionDialog**(设置对话框族) | 批 204/207(metaObject 反查) | 批 191 前"未知设置类" |
| **KitGroup(011ab130) ≡ MuxPaneGroup**(同址 +0x38 TabGroup) | 批 223(blobB 组块 + 008b9890) | 批 191 前"KitGroup 独立类" |
| TabBar "Qt 私有面" 实为 **公开 API**(`setTabButton`/`tabButton`) | 批 208(005a80f8/005a6c0e 全读) | 批 46–190 全部"QTabBarPrivate cited" |
| `SettingsPageFace` 基类 = **QDialog**(accept/reject 直连自身) | 批 258(0072bbe2 字符串形) | 批 246 按 QWidget 建模 |
| `pasteDialog_6dfd9e` = **设置分类页**(CategoryPage) | 批 318(vtable 实证) | 名不副实 |
| `dirCompareDialog` = **配置目录选择框** | 批 321(文案实读) | 名不副实 |
| `TunnelDialog_h9097b0` = **隧道行表析构** | 批 325(0x48 步长释放序) | 名不副实 |
| `msgbox_buildRich` = **上传确认富文本框** | 批 317(文案实读) | 名不副实 |
| `s_ExpandButton_8b7dd4` = **KitDock 装配** | 批 212 | 名不副实 |
| `s_tabbar_selectionBehaviorOnRemove_89d860` = **KitDock 创建腿** | 批 213 | 名不副实 |
| KitDock `+0x38` = **bool withExpand**(非 widget) | 批 216(三源) | 批 207 首判 |
| `dock_toggleFloat` 几何 = **QRect(mapToGlobal,size)**,非私有位 | 批 232(asm 公式) | 批 180 前"私有面不可移植" |

## 现役队列(批 493 后,按需开批)

> ⚠ 测试冻结令 + 铁律 7 生效:各批只做转写 + 引用 + commit,不编译不测试。

1. **④ 对话框腿内部体**:构造骨架(ctor/vtable/字段/标题/腿指针)已全清,
   剩 ~18 条 `build()` 的内部逐句(装配布局/信号槽体)。
2. **② 动作配置的磁盘读入面**:`wind.actions` / `user.actions` 已定位到
   `s_wind_actions_76b7c0`,但其上游 `FUN_00a7e75e` / `00a7fdd8` / `00a8017e`
   族(配置读入器)未转写。
3. **⑤ 触发器页字段装配余段**:八页外层已落,页内 `+0x38..+0x60` 字段的
   逐件装配仍有 cited。
4. **⑥ 标签页写腿尾部**:`insertTabWithMeta` 的 icon/属性写面、节点表建立。
5. **5c 读侧余段**:帧解析细节(`parseSessionRestoreBlob` 深层)、旧格式尾部差异。
6. **自绘控件族**:全库 463 个 `s_*` 处理器(250–1600B)中约 **60 个控件 ctor**
   尚未落(CheckList/ExplorerList/ActionButton/CloseButton/ExpandButton 等已落 11 个)。
7. **大件**:`KitBar::addKit`(9743B,需分 3-4 面)、`FUN_008cf0c8`(2233B)、
   `RemoteFileDialog` 装配体 7811B 的内部。
8. **收尾期**(语料锚定段全清后):
   **① 清 `docs/pending-attribution.md` 的 6 项归属迁移 → ② 全量编译修错 →
   ③ 25 个测试二进制全量回归 → ④ 装配 `main` → ⑤ Xvfb 截图 vs `/opt` 对表**。

## 已知开放问题

- wordsteptest transient 已根治(批 128,i3 simdBlocks 勘误);
  若复现超 1/20 失败率须重开排查。
- 0x7545 真值路径已开通(批 143;varint 承载替值序怪癖 quirks #31,
  字节级对表留 5c 期)。
- editor 型 doc +0xe0 承载与 terminal 型不同构,未建模(批 122 登记)。
- 0x7564 勘正(批 130)的他处 dispatch 消费者 xref 未查。

## 环境速查

- **测试已删除**:`tests/` 与 `add_subdirectory(tests)` 已按用户令移除
  (2026-11-16),`ctest` 门不再存在;收尾期改为 dlopen 零 undefined + 截图对表。
- **基线二进制 = `./WindTerm`**(仓库内副本,sha256 与 `/opt` 同;运行时库仍取
  `/opt/WindTerm_2.7.0/lib`)。
- RE 探针:`tools/re/metatest/`(手工 g++;**改含内联成员的头后必须重编探针**,
  否则旧探针按旧偏移读新库会段错误)。它不是测试,不参与构建。
- frida:pip --user;REA MCP 已配置(项目 opencode.json,207 工具);
  ida-pro-mcp 1.4.0 已装(原版开启时 localhost:13337)。
- kuna CLI:`~/.local/share/rea/bin/kuna`(优于语料 grep,支持
  --addr;批 103/128 两次实战破案)。
- libssh-dev/patchelf/Xvfb 已装;ptrace_scope 重启后回 1,frida 前
  需 `sudo sysctl -w kernel.yama.ptrace_scope=0`。
- **清理台账见 `docs/cleanup.md`**(批 493 后):已删 IDA 库 / node 版 frida /
  `build/` / 上游库 test-example ≈11M;**保留** decomp 语料、`inc/`、数据面、
  `./WindTerm` 副本(判据 = AGENTS 条 16 + 构建引用分析)。

## 原版环境拉起流程(5b/对比批用;批 121-123 实战)

1. `sudo sysctl -w kernel.yama.ptrace_scope=0`(须密码,主控代输)
2. `Xvfb :99 -screen 0 1280x900x24 &`(日志 /tmp/opencode/xvfb.log)
3. `DISPLAY=:99 nohup ./WindTerm`(约 10s 起窗)
4. xdotool 双击开会话:1014,331 → 1040,359;打字触发回显;
   `exec sleep 100000` 哑化 shell(ALL MATCH 基线前提)
5. `python3 tools/re/phase5/phase5_attach.py $(pgrep -x WindTerm)`
   验证附加;**一次挂上复用,勿竞态**(批 98 事故)
6. 收尾:拆原版/Xvfb,ptrace 恢复 1(批 123 后惯例)

## 提交规范(2026-10-29 修订)

- 中文 commit;**只提交,不主动推送**(push 仅在用户明示时执行,
  届时必带 `-c http.proxy=http://192.168.1.106:7890`)
- commit 与 push 永远不在同一条命令行;每轮改动 + 对应 .md 更新,
  一条 commit
- 车道批次:worktree 隔离 + 恰好一个 commit + 绝不 push(详见
  下方车道方法论)

## 车道方法论(硬护栏,四轮 12 车道实战沉淀)

- worktree 隔离 + 写域互斥任务书 + 主控统一 docs(phase5/handoff
  主控写;车道越权写 phase5 两起,内容合格保留,主控核对)
- 大语料读取型任务书**必须带输出上限**(批 107 首轮零产物教训)
- **边读边落 + shell 预算 ≤60**(批 112 500+ shell 零产物教训;
  批 129 ~70 超限如实自报)
- 落条前 case/符号唯一性自查(批 129 重复 case 事故)
- 取证型车道配失败条款:批 105/109/110/115/118/122/123 七次正确
  拒绝无证激活/发明
- 权限审批:车道 worktree 路径 reply always 预放行
- 勘正谱系见上表;新会话读到与谱系冲突的旧结论,以谱系为准
