# 逆向完成计划(plan)

> 目标:编译出与 ./WindTerm 行为一致的程序。
> 每阶段完成打 ✅,进行中标 ⏳,未开始标 ⬜。
> 完成判定:所有已实现功能在离屏/实机下行为与原二进制一致。
>
> **测试策略(2026-10-28 定)**:测试跟随真身化,不领先。
> e2eterm(25 断言)/recheck(22 例)冻结为提交门(成本秒级),
> 守护已完成的终端核心路径;**不再向未完成子系统扩展断言**;
> 各子系统真身化收口时补各自行为测试;全面行为对比留给 Phase 5。
> 理由:近期在测试基建上的投入已超过逆向推进本身,而对 cited
> 桩写断言没有意义。
> **保真约束**:测试断言语料行为,不断言教科书行为——失败测试按
> docs/quirks.md 裁决流程处理(怪癖登记,禁止按"应该怎样"修)。

---

## 总览(2026-11-16 批 493;历史明细见 `docs/history/plan-detail.md`(Phase 0-3 细节)与 `docs/history/phase5-log.md`(批次流水))

| 阶段 | 状态 |
|---|---|
| Phase 0 基础设施 | ✅ |
| Phase 1 Screen 层收口 | ✅(cited 38→行级注;深项移 4b) |
| Phase 2 TerminalCore/SuperSession | ✅(尾项 convertRowToHistory 移 4b 文档模型) |
| Phase 3 编辑引擎 customDispatch | ⏳ **巨 switch 全清**(WT+EXT)+ eNodes 节点层 20/20 含深层 + **0x7545 真值路径开通**/搜索链激活;详见 phase5 结论快照 |
| Phase 4a 启动路径 | ⏳ SessionManager+ProfileLoader ✅;注册表四表插入侧全定案(141/144/151);启动链+恢复门真身(149/150);**WorkspaceLoader:522056 骨架/收集器/defaultDir/扫描/protocolUrl/trie 键值域/掩盖腿/挂页槽真身(154/159/163)**;分裂腿/实机对证 ⬜ |
| Phase 4b TerminalWidget | ✅ 槽覆盖 58/58;**渲染层 ✅**(TerminalView 格子绘制/写回通道/resize 接线) |
| Phase 4c 主窗口/界面 | ⏳ **界面七节加权 ≈95%**(342-493):①主窗装配 90% /②菜单·动作 **95%(数据源 wind.actions+user.actions 两层 + 执行链到 js_actionFire)** /③工具栏状态栏 80% /④对话框 95%(**29 个 QDialog 全清**) /⑤设置页·触发器页 93%(八页装配全落) /⑥dock·标签 85%(关钮机制闭环) /5c 写 95%·读 85%;**全部未编译(铁律 7)**,收尾期先清 `docs/pending-attribution.md` 归属工作单再编译 |
| Phase 5 行为对比 | ✅ 终端栈 98 序列 98/98(批 30);**5b 编辑引擎终局**(批 123:A/B 通道封闭 NOT-RUN 即终局,总表 1/21;RUBY 假设永久化,批 124)| **5c 会话持久化 ⏳(M19 起步)**:盘面矩阵 ✅(盘点)/我方载体 ✅(appboot 166)/reopen 写读闭环 ✅(167)/三件套+kit+profiles 写侧 ✅(168/169);字节级对表 ⬜(需原版侧环境) |
| 会话装配 | ✅ 管理收口(批 29) |
| 新组件四件 | ✅ KeymapEngine/TelnetCommander/UnixPty/TelnetProtocol(见 docs/calibration.md) |
| 组件重做(铁律 6) | ⏳ M1-M22:ModTrack 全建模/搜索链激活/位面机/scanMask 活性/eNodes 节点层全清+词法重建+底座头 ODR+vt 承载+清偿臂+RS 灌链/0x7545 真值/排序真身(std::sort 承接 178)+hash remove 分离担查+rehash 注记(178);余:busy 腿(外库登记)/超门分段族(外库边界 178 定性) |

(原"测试矩阵"一节随 `tests/` 删除已移除;判据改为收尾期 dlopen + 截图对表。)
里程碑 M1-M7 达成记录:tools/re/handoff.md「里程碑总账」。

---


## Phase 0-3(细节已归 history/plan-detail.md)

| 阶段 | 状态 |
|---|---|
| Phase 0 基础设施 | ✅ 语法自洽 / moc 零错 / `libWindTermRe.so` dlopen OK |
| Phase 1 Screen 层收口 | ⏳ 主体完成,DEC/VT 报告族与配置/通知族余 cited 空体(38 行级标注) |
| Phase 2 TerminalCore / SuperSession | ✅ 收口(resizeCore/makeRow/Tabstops 真身;`convertRowToHistory` 结构定案留 cited) |
| Phase 3 编辑引擎 customDispatch | ⏳ 巨 switch 全清(WT+EXT)+ eNodes 节点层 + 0x7545 真值 + 搜索链激活;详见 `phase5.md` |

## Phase 4 — UI 装配 ⏳(转写 ≈95%;**未编译** — 收尾期第 ① 步清归属工作单)

> 覆盖口径:按 `tools/re/gui-map.md` 七节条目加权;细分与逐批证据见
> phase5「批 342-493 收官段」与 handoff 一句话状态表。
> **注意:转写覆盖 ≠ 可运行**。当前 `可编译 0% / 可运行 0%`,
> 因为铁律 7 全程未编译;收尾期顺序见 handoff 现役队列第 8 条。

### 4a. QApplication 启动路径 ⏳
- 配置面资产已探明:global/wind.config(权威默认层)+ wind.keymaps
  (键位引擎输入格式)+ triggers/lexer/Telnet 协议面——
  见 docs/subsystems/config-schemas.md
- **SessionManager ✅**(2026-10-28):src/Widgets/SessionManager.{h,cpp}
  ——s_session_uuid_6f571a 转写(uuid/icon/group/label →
  QStandardItemModel,filter 禁用)
- **ProfileLoader ✅**:profile 布局定案(~/.wind/profiles/<name>/
  terminal/user.sessions 等);loadSessions/saveSessions
  (FUN_00806904/00806958)+ JSONC 容错解析——SessionManager
  数据源接通
- CTerminalConfig 单例 ✅:src/Editor/CTerminalConfig.{h,cpp}——Meyers
  访问器(00809d78)、ctor 默认 prompt ">"+trim 正则(00809b90)、
  wind.config JSONC(vendored jsoncpp,collectComments)载入;
  Screen::sessionConfigGet 与 SuperSessionPrivate option/setOption
  均已接真单例;recheck 对 /opt 真配置 3 键断言通过
- recheck 22 例全绿(宽度 7+字符集 6+键 2+resize 3+config 3+tabstop 1)
- 会话管理器 0x006f571a(QStandardItemModel)连 UI
- 工作区装载器 0x00522056 → Terminal/Editor/Browser 三面板恢复

### 4b. TerminalWidget 组装 ⏳
- **渲染层 ✅**(2026-10-28):src/Widgets/TerminalView.{h,cpp} +
  src/Sessions/Terminal/TermViewFace.h——
  * TerminalView:格子绘制(attrArray u16 字头 + cell+0x18 SGR
    位义全解:0-13 属性/14-37 fg/38 bright/39-62 bg/63 bg-bright;
    bold/underline/strike/inverse 落 QPainter;光标 XOR 框);
    Screen::paletteColor(+0xd0)取色,未配置回落 16 色
  * TermViewFace:writeBackToView 的 vtable+0x70 通道 →
    viewWrite() 虚槽 → update()(Screen 侧原裸 vtable 调用改
    类型安全路由)
  * 装配:TerminalWidget::attachView()(视图=写回通道对端);
    view resizeEvent → Screen::resizeScreen(FUN_007e5688)
  * **调色板管线 ✅**(2026-10-28):Screen::installPalette——
    +0xd0 容器 = QArrayData 手工组块(offset@0x10,FUN_007e3578
    读法 payload=容器+offset);**m_palette 类型修正 int→void\***
    (语料证明容器为指针,原 int 建模在 x86-64 截断——铁律 5);
    TerminalView 改直读 SGR 位内 RGB 色值(applySgr 存的是
    paletteColor 消费后的值,非索引);attachView 自动装默认表
    (16 色已知 + xterm 算式;shortcut:默认 256 表未从二进制
    取证,取证后替换)
  * **第二写回通道 ✅**:FUN_007e673c(vtable+0x78,参数直透)→
    TermViewFace::viewNotify → update()
  * **渲染收尾批 ✅**(2026-10-28):
    - 宽字符双宽:0xffff 尾格跳过(e2eterm 锚)+ widthFromTables
      ==2 跨 2 格绘制;setCursorStyle 真身化(FUN_007a45ee 7B
      +0xcc 直写)+ cursorStyle() 读取
    - 光标三形态:DECSCUSR 1-2 块/3-4 底条/5-6 左竖条(XOR 面)
    - alt-screen 刷新:switchToAlternateScreen 尾 + modeChanged()
      信号 1 → viewNotify(0) 重绘(m_core=活动核,视图自动跟随)
  * engtest3 渲染冒烟:离屏 grab → 非单色 ✓/首行字墨 ✓/
    viewWrite+resize 不崩 ✓/**SGR 31 红字像素断言 52px ✓**
- **TerminalWidget 全槽覆盖 ✅**(2026-10-28):58+ 槽一轮批量
  (守卫查询 9/复位 3/输入清屏 4/CMD 直传 12/日志 9/modem 5/
  FreeType 2/会话命令 8 + write 端到端);深子系统腿(对话框/
  全局管理器/会话栈)cited
- **端到端数据路径已通 ✅**(2026-10-28 晚):Screen+core resize→
  writeText(ASCII/换行/边缘 wrap latch/UTF-8 宽字符)→ 单元格
  逐格校验,e2eterm.cpp 14 断言全过;writeText 修复四处真 bug
  (sCharClass 硬编码地址/cell-head 不步进/越缘 stale 计数/宽字符
  列步进)
- 行为矩阵(e2eterm 25 断言):ASCII/CJK/换行/wrap latch/tab/
  backspace/DECSTBM 区域滚动/SGR payload 全过 ✅
- makeRow cells 零初始化修复(ASAN 抓获 aux 野指针)✅
- ScintillaEditBase 嵌入(Editor 窗口)⬜
- SuperCommander → SuperSession 命令转发(SuperBridge 桥)⬜

### 4c. 主窗口(Kit/TerminalWindow)⬜
- MenuBar/ToolBar/StatusBar 恢复(0x8d2f7e 启动恢复)
- TabGroup/Splitter 联动
- King::Protocol 五态路由(Serial/Shell/Ssh/Tcp/Telnet)

---

## Phase 5 — 行为一致验证 ⏳(终端栈 98/98 ✅ 批 30;5b 终局批 123;5c ⬜——见 docs/phase5.md)

### 5a. 离屏终端渲染 ✅(批 30:98 序列 98/98 MATCH;管线与复现见 docs/phase5.md「复现」节)

### 5b. 编辑引擎行为对比 🟥 终局(批 121-123)
- 通道定案:armed 0x418c4 钩 + editor ctx 桥 + frida 真 ctor op(批
  121/122);**find 注入通道不存在**(memo 唯一串源,op+0x18 零消费)
  + UI 向量判死(批 124)→ **A/B 18 序列 NOT-RUN 即终局**
- 总表 1/21 MATCH、2 MISMATCH(仪器性);工具资产:phase5_editor.py/
  phase5_editor_compare.py/phase5_editor_b122_op.js(免侦察重开)
- RUBY 语法假设永久化(批 124 终裁;理论备选 = SearchPane UI 自动化,未试)

### 5c. 会话持久化对比 ⬜
- .wind/ 目录生成与加载对比(需我方可运行应用 — Phase 4c 前置)

---

## 追踪

| 阶段 | 文件数 | cited 数 | 目标 |
|---|---|---|---|
| Screen.cpp | 1 | 38 行级标注 | 随各函数真身化消除 |
| TerminalCore.cpp | 1 | 5 | → 0 |
| EditorEngine.cpp | 1 | ~40 桩 | → 22 (真身) |
| SuperSessionPrivate.cpp | 1 | 6 | → 0 |
| gen_stubs.cpp | 1 | 5(全为 Phase-4 深项) | → 0 |
| Widgets/TextView.h | 1 | 1 | → 0 |

| **总计** | ~6 | **~160** | → **0** |
