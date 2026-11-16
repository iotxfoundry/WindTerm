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


### 批 498:「捡容易的」池实测见底(策略结论,先读这条再开批)

用户要求「不再死磕,先落地容易的」。机械筛完发现**没有大批容易的**:

| 筛选 | 条数 |
|---|---:|
| 语料 `.text` 全部条目 | 38,748 |
| 扣非函数(异常清理块 / Qt 桩) | −15,116 → 真工作 **23,632** |
| WindTerm 区(0x0050–0x0092)+ ≤170B + 直线(无 for/while/goto) | 5,117 |
| 同上再去掉 refcount 释放桩 / invalid-instruction(ud2)桩 | 剩不足 **600** |
| 其中「已被我方引用」(`引用档`)且 ≤260B 且不含未实现调用 | **52** |
| 52 条逐条核实后真正缺实现的 | **≈5** |

52 条的构成(实测,非估计):
- **编译器生成**:空类析构(`vptr=…; ~QWidget();`)、adjustor thunk(`this-0x10`)、
  `operator_delete` 对偶 —— 手写等于抄编译器产物
- **Qt 生成**:`*_metaObject` / `*_qt_metacast` / `*_qt_metacall` —— moc 自己会生成
- **Scintilla/上游**:`Surface*` / `runstyles_*` / `gapbuf_*` / `bytestream_*` / `free`
- **已内联在调用点**:最典型 `style_getPixelMetric`(0x00752766,74B)——
  `ToolBarBuilder.cpp:250` 已内联 `style()->pixelMetric(QStyle::PixelMetric(0x41))`
  并注明了字面 0x41 的理由。**它被记成「引用档」不是因为缺,而是因为内联了。**

⇒ 结论:**「小函数扫尾」不是可批量推进的方向**。剩余真工作集中在
≥1KB 的功能腿与未建子系统,那些不「容易」;而小件里能捡的,我们已经捡完了。

后续只有三条路(需用户定):
A. 开编译期 —— 一次暴露数千条类型/链接错,是当前最大的信息增益;但触铁律 7。
B. 继续功能级啃中/大件(每批 1–3 个,1–4KB),进度慢但都是真代码。
C. 先划第三方区块(boost/libstdc++/Scintilla),把 20,909 的队列洗干净再排产。


### 批 499:按功能面探测(结论:多数目标已被前批覆盖)

按"挑调用方已就位的中件"顺序探了 4 个候选,**3 个已覆盖、1 个缺宿主类型**:

| 候选 | 结论 |
|---|---|
| `theme_icon_load_svg`(1272B) | **已在** `App/ThemeIcons.cpp:140` `loadSvg`(缓存查/`::`与`.svg` 判/SvgIconEngine/recolor 全在) |
| `s_kit_startupSessions_8d2f7e`(3122B) | **已在** `KitWindowAssemblyFace.cpp:131`,只差中段 flags&1/&2 两支(语料注明属 Workspace::kitStartupSessions) |
| 动作配置读入面 `FUN_00a7e75e/00a7fdd8/00a8017e` | **已由** `ActionFactory::loadActionsFile` 承载(StartupChain.cpp:310-316 双源装载序) |
| `statusButton_setState`(895B) | 语义已全解,**缺宿主类**:`param_1` 是 (QToolButton*, host*) 二指针,host+0xa0 判空;metaobject 0x01198d80 解析失败,类名未定 |

`statusButton_setState` 已解出的语义(下一批可直落,只差宿主类):
```
btn = pair[0]; s = state;
if (host->+0xa0 == nullptr) s = QVariant(0);
// 文本(嵌套 compare 直译;注意 2/3 两支在编译产物里不可达 —— 待 quirks 登记)
if (s == 1) { if (s == 2) { if (s == 3) "Unknown" else "Mismatched" } else "Changed" }
else "Known";
btn->setText(text.toUpper());
btn->setStyleSheet("QToolButton { color: %1; }".arg(s == 1 ? "red" : "green"));
```
串实读:`Known`@0xc8ac84 / `Changed`@0xc8ac8a / `Mismatched`@0xc8ac92 /
`Unknown`@0xc8ac9d / `green`@0xc8ac7e / `red`@0xc9e638;
颜色判据 asm 0x0058f546-556:`test al; cmove` → cmp==0(即 s==1)取 **red**。

**LockScreen 全类规模实测**(若下一批整类推):0x0055f130–0x00561xxx 共 29 个具名
函数 ≈ 11KB,含 `s_TitleLabel_560414`(1004B)/`s_LockScreen_560888`(243B 疑 ctor)/
`lockscreen_connectSignals`(883B,6 条 connect,槽 00561492/005614c0/0055fb0b/
0055fa50/00561990)。整类推可在 3–4 批内收口。

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

## 批 494 新落:文件传输子系统(`src/Sessions/Transfers/`)

原版 ZMODEM 传输链从未建模,本批按 0x0079a842..0x007a2720 连续语料段落地:

| 文件 | 类 | 真实现 | 引用档(cited) |
|---|---|---|---|
| `Modem.{h,cpp}` | 基类(QObject):信号 finished/showText/started、进度条、cancel、显示腿 | ctor/wireSignals/appendText/showError/finish/emitStarted/transferProgress/cancel/Progress | 三条接线之一(writer 侧信号名未复原)、槽腿被调 |
| `XYModem.{h,cpp}` | XMODEM/YMODEM 主体 | ctor/resetState/dtor/reset/isRunning/feed/translateInput/appendLf/writeData/writeByte/addSendFiles/checksum/verifyChecksum/openReceiveFile/saveChunk/sendWithRetry/sendSub/retryTimeout/setSubChar | xymodem_recvPkt(2094B)、xymodem_processInput(1030B)、xymodem_sendInit(1954B)、buffer 追加源 |
| `ZModem.{h,cpp}` | 外部进程驱动 | ctor/dtor/reset/isRunning/feed/stateText(6 条 tr 串) | zmodem_init(2636B)、FUN_007a0f86(3062B) |
| `ModemProcess.{h,cpp}` | QProcess 封装(lrzsz) | ctor/dtor/takeStdout/takeStderr/signalFinished/startProcess/writeData | QMetaType 注册、readyRead functor 体 |
| `XModem/YModem.{h,cpp}` | 变体(空派生 + 协议参数) | ctor/dtor | — |
| `Utility/Format.{h,cpp}` | 时长/字节数格式化 | formatDuration(006168b6)、formatByteCount(00616636) | 精度分支 |

关键取证(新):
- 工厂 **0x007e44c0** `s_xmodem_packetSize_7e44c0(session, 0|1)`:0 → XModem
  (`+0x50 = 0`,键 `xmodem.packetSize`);1 → YModem(`+0x50 = 0x101`,即
  **dirOnly + trimSub 两个旗标同处一个 16 位写**,键 `ymodem.packetSize`)。
- 外部程序名实读:`"zsz/sz"@0xca3c3a` / `"rz"@0xca3c50`(ZMODEM 收发两向),
  与 `vendors/lrzsz/{rz,sz}` 落点一致。
- 状态文案 6 条 tr 串全部实读(见 `ZModem::stateText`)。
- 新怪癖 #36:输出换行在 CR 后插 **0x00**(不是 0x0A),asm 0x79b84a 实证。

### 批 495:ZMODEM 启动腿 + 读槽落地(zmodem_init 由 cited 升真)

- `zmodem_init`(0x007a04c2,2636B)→ `ZModem::startTransfer(direction, args)`:
  参数表 `-b -e -v` + (发送:待发文件表 / 接收:接收文件名),reset,
  `m_uploading`,程序名 `/vendors/lrzsz/sz`(发送)/`/vendors/lrzsz/rz`(接收),
  路径 = `toNativeSeparators(applicationDirPath() + 程序名)`,
  三段正则,`new ModemProcess` + `new QThread`,setProgram/setArguments/
  moveToThread,五条 connect,`start(TimeCriticalPriority)`。
- `FUN_007a0f86`(3062B)→ `ZModem::onProcessReadyRead(int channel)`:
  channel 0(stdout)→ writeData 原样上行;channel 1(stderr)→ 累积 +0x88、
  抹程序路径、切行、逐行 `transferedSize/totalSize` → transferProgress、
  `transferFile` → +0x38 + progress.reset(),每行 appendText 显示。
- 字段模型**勘正**:+0x70/+0x78 = `QSharedPointer<ModemProcess>`(d/value),
  不是 QByteArray;`ZModem::isRunning` 读的是进程的 +0x28(命中旗标)取反。
- **方法归属勘正**:writeData/writeByte/translateInput/appendLf/addSendFiles
  只碰 Modem 字段(+0x20/+0x28/+0x48)→ 已从 XYModem 移入 Modem
  (依据是 ZModem 也调 0x0079b858,而 ZModem 与 XYModem 是兄弟不是父子)。
- `ModemProcess::readyRead` 实参是 **int 通道号**(槽里 `**(int**)(param_4+8)`)。
- vt16 两族签名不同(XYModem 无参 / ZModem 双参),故不上升为 Modem 纯虚。

### 批 496-497:XYModem 收发核 + 进程槽

- `xymodem_processInput`(1030B)→ `XYModem::processInput`:逐字节应答状态机
  (状态 +0x58 六档),NAK/CAN/'C'/ACK 四路分发,每字节末 state==6 → finish。
- `FUN_0079eb8c`(388B)→ `XYModem::sendNext(crcMode)`:组块 → 发;失败且有
  接收文件则报错,否则发 EOT(0x04);末尾清重试计数、块号 ++。
- `xymodem_recvPkt`(2094B)→ `XYModem::recvPkt`:SOH/STX 帧解析(序号反码、
  校验、重复块、YMODEM 头块)、EOT 收尾(按 mode88 决定 commit/cancel)、
  CAN 取消。整包长度 `need = packetLen + (crcMode==0 ? 2 : 1)`
  (asm 0x79cf09-0x79cf20 32 位回绕算得)。
- `FUN_0079fb5c`/`007a1d70`/`007a1f07` → ZModem 状态槽 + ModemProcess 两条
  readyRead 槽(见上批)。
- 折叠实参统一回 asm:finish 的 bool(0x79d4fc `mov $1,%esi` / 0x79d25a
  `xor %esi,%esi`)、ACK 字符(0x79d308 `mov $0x6`)、remove 长度
  (0x79ce9d/0x79d2f8 `mov $1,%edx`、0x79d390 `mov %r12d,%edx`)。

仍 cited(收尾期必须先补):
`FUN_0079dc32`(3833B,组帧)/ `FUN_0079cab4`(775B,YMODEM 头块)/
`FUN_0079d680`(1365B)/ `xymodem_sendInit`(1954B)/ `ModemProcess::clearFlag`(18B)。

## 现役队列(批 508 后,按需开批)

> 2026-11-16 起走「整类推」:一个类 ctor→字段→接线→槽→dtor 一次落地,
> 收口判据 = dtor 出现。当前已整类闭合 21 类(见下方进度表)。
> 下一条队列(按"能整类闭合"优先,不按体量):
>
> | 序 | 类 | 规模 | 备注 |
> |---|---|---|---|
> | 1 | `Grep` / `GrepView` | 6/1135B、6/1191B | 搜索视图,信号真名可读 |
> | 2 | `KitView` | 14/2943B max694 | 面板视图基座 |
> | 3 | `SftpTransfer` | 11/1059B | 传输条目 |
> | 4 | `SshAuthOperator` | 8/1026B | 认证算子 |
> | 5 | `SftpFileSystemItem` / `LocalFileSystemItem` | 2/1217B、5/1252B | 与已落的 FileSystemItem 同族 |
> | 6 | `GrepViewConfig` / `TerminalViewConfig` | 4/11680B、2/6005B | 配置面,函数巨大,需分面 |
> | 7 | `MediaCenter` / `ExpectTask` / `TerminalSender` | 6/14499B、5/15741B、7/16722B | **大件**:单函数 6-8KB,需按面拆 |
> | 8 | `Tmux` | 11/18288B | 最大单类,留最后 |
>
> ### ⚠ ActionHandler → SuperCommander(终端内核,单独立项)
>
> - `ActionHandler` 的 metacall 本体 **4022B**(语料名错标成 `ActionHandler_dtor`),
>   是全仓最大的单个 metacall。
> - `SuperCommander` 的 QMetaObject 是 **methods=264**(5 信号 + 259 槽):
>   `adjustScreenAlignment` / `allowScrollback` / `answerBack` /
>   `assignUserPreferredSupplementalSet` … 全部经 metacall 暴露。
> - `SuperCommander::qt_metacast` 先 strcmp "SuperCommander" 再逐字符比
>   **"ActionHandler"** ⇒ **SuperCommander 派生自 ActionHandler**。
> - 结论:**必须从 ActionHandler 基类往上搭**,不能以 QObject 顶着;
>   这批需要独立的 3-4 轮(基类 metacall 分面 → 264 条槽 → 字段),不要塞进
>   普通批次。
>
> ### 不做(已裁定)
>
> `RunStyles` / `Bimap` / `SuperBuffer` 整族 → 归 B 类,委托
> `src/Scintilla/src/RunStyles`,依据见 `docs/ext-boundary.md` 末节。

## 旧队列(批 494,历史保留)

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

## 新增类时的机械自查(2026-11-16,本轮 6 次踩坑后加)

1. **每个 `.cpp` 开头必须有出处行** —— 哪怕文件里只有一个 ctor。
   只写 `XFace::XFace(QObject *p) : Base(p) {}` 的 cpp 会被
   `coverage.py --audit` 判为「无任何出处」。补一行即可:
   ```
   // 出处:QMetaObject 0x…(class="X",methods=N,signals=M,superdata=…);
   // ctor 内联在调用点,仅转发基构造。
   ```
   (本轮 6 次审计报红全是这一个原因。)

2. **写 ctor 之前先量 `sizeof`**:deleting 析构里的
   `operator_delete(_, N)` 就是对象大小。与基类对比即知有没有自有字段
   (本轮靠它一眼判定 LocalFileSystemItem 0xa0 / SftpFileSystemItem 0x98 /
   PasswordMeter 0x30 / OutputPane 零字段)。比读函数体快且不会错。

3. **metaobject 地址用 `mo_find.py` 反查**,不要猜。
   `python3 tools/re/mo_find.py Xxx Yyy` → 打印地址,再喂给 `qmo_class.py`。
   起因:很多类的 metaObject 函数不带类名前缀(KitWindow 就是)。

4. **出处注释必须"地址 + 标记词"两个都有**。
   `coverage.py` 的 `origin_of()` 要求同时满足:
     ① 注释行里有 `.text` 区间的地址;
     ② 该行带标记词 `真身` / `cited` / `FUN_x(NNNB)` / `// ===`。
   只写 `// dtor 0x008e59f2(47B)` 会被判「无出处」——
   写成 `// dtor 0x008e59f2(47B)真身` 才认。本轮为此踩了 3 次。

5. **`.h` 与 `.cpp` 的文件级出处走两条路**。
   `defs_status()` 只扫 `*.cpp`,所以报在 `.h` 上的「无任何出处」不是函数
   标注问题,而是头部声明类的那套检查 —— 在文件顶部加一行
   `// 出处:QMetaObject 元数据(...)` 即过。
   另:`~X() override; // 0x…` 这种**行尾地址不算数**,
   `origin_of()` 只读定义行之前的注释,必须把 `// 0x… 真身` 单独一行放在前面。

6. **先判是不是 B 类**(Scintilla / chardet / libssh 上游件)。
   本轮差点把 Scintilla 的 `Editor` 当自研逆向 —— 函数体里出现
   `editor_textLength` / `runstyles_runnode_init` / `Decoration` 就停手。

7. **建类之前必须查重(本会话唯一一次严重返工)。**
   曾一次性建了六个"新类",其中 **五个已存在**:
   `TriggerActionWidgetFace`(TriggerPageFace.h)、
   `TriggerActionDialogFace`(Dialogs/TriggerActionDialogFace.h)、
   `ShowTooltipTriggerPageFace` / `RunCommandTriggerPageFace` /
   `SendTextTriggerPageFace`(TriggerPageFace.h)
   —— 造成同文件里两份同名 class 定义,只能整批删掉重做。
   **机械前置**(一条都不能省):
   ```bash
   python3 tools/re/coverage.py --what <类名>
   grep -rl "class <类名>" src/          # 必须为空才新建
   ```
   名字相近的族(Trigger* / Category* / *Panel / *View)尤其危险:
   它们往往已经在同一个文件里落过,只是用了不同的分组方式。
