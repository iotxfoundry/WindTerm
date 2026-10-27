# 新会话起点(交接文档)

> 用途:新会话冷启动。让 agent 先读本文件 + 本目录其余文档,即可无缝续作。

## 一句话状态(2026-10-28)

**编译验证达成**:src 全量(Sessions/Widgets/Protocols/Utility)+ moc(22/22)
编译零错误,链接为 `libWindTermRe.so`(775KB),**dlopen 加载通过**,
`SuperSession::staticMetaObject` 运行时活性验证:className=
"SuperSession",signals=61/方法表完整。构建配方见 BUILD.md。

里程碑链:语法自洽 ✅ → moc 全过 ✅ → 全量编译 ✅ → 链接 ✅ →
dlopen ✅ → 元对象活性 ✅。下一步:UI 装配(QApplication + TerminalWidget)
或继续 D 类按需深挖。


WindTerm 2.7.0 逆向:API/架构/状态机全部打通。**第一/二/三 a 批转写已完成**:SuperCommander.cpp 170 个真实现体,Screen
层 ~95 方法,TerminalCore ~47 方法。批次②:DECSM/DECRM 完整 case 表
(备用屏双缓冲、鼠标族、2004)、SGR 64 位状态机、SCS 字符集、ICH/DCH/
IL/DL/DECIC/DECDC、DECDWL/DHL。批次③a:DECALN、VT52 四槽、DA/DSR 报告、
zmodem、movePage 页面调度。**SuperCommander.cpp 转写完成:259/259(100%),行级 worker 已落码至
单元格字节层。** 剩余 cited-stub 精确清单(下会话按此逐个击破):
**writeText 主循环(0x7e6f42,终端心脏)与 DECDSR(0x7f0d7c)已完整
转写 —— cited-stub 清单清零。** 终端栈 Commander→Screen→core→单元格
四层全部真实现。纯引用级清单已清(TerminalCore 六项全落码:copyRect/
collectRectCells/parseAttrCells/resetRow 模板尾/cloneGlyphPayload/
取格取头 0x7a3c1a·0x7a3c2a;IDA MCP + kuna 语料双源,IDA 基址 =
Ghidra - 0x400000)。仍剩:
- Screen: writeText 内层 helper ✅、剩余视图桩 ✅;键盘方言表(动态路线)
- 编辑器引擎(Scintilla 系,两级分派 0xa5205e/0xa418c4):336 命令
  100% 接线(131 手工语义 + 228 生成层,EditorEngine.h/.cpp);
  分层图:分派器 → doc(+0x1098)→ GapBuffer(+0xf8)→ 行索引
  (自适应自旋惰性重算 FUN_00a62f52);复杂叶 104 个 + t_call 110
  个按家族换真身推进中(见 EDITOR-ENGINE-COMMANDS.md)

## 环境状态(新会话先核对)

| 项 | 值 |
|---|---|
| 引擎 | Ghidra 12.1.4(自动)/ IDA Pro 9.1(深度,GUI 需手动开)/ **kuna CLI(就绪)** |
| | kuna 路径:~/.local/share/rea/bin/kuna(decompile/xrefs/functions/strings/disassemble),2026-10-27 验证:反编译 0x7a5588 与还原转写逐字段吻合,connectImpl 交叉引用 1016 处全解 |
| IDA MCP | `~/.config/rea/ida-mcp.json`(stdio);IDA GUI 里需 Ctrl+Alt+M 启动插件服务 |
| GitHub 代理 | `192.168.1.106:7890`(push 必带 `-c http.proxy=…`) |
| 提交规范 | 中文,force 推送需覆盖远端 dev |
| ptrace_scope | 已恢复 1(动态分析时临时置 0) |
| 远端 dev | 已同步(本地=远端=同一链) |

## 当前任务(批次 ②,剩余 ~168 占位体)

第一批(光标/擦除/滚动族)已完成,方法学验证有效:
适配器(0x7c 段)→ Screen(0x7e 段)→ TerminalCore(0x7a 段)三层各归其位。
`SuperCommander.cpp` 由 `/tmp/opencode/gen_sc.py` 生成(B 表按 (名,参数数)
键控;生成脚本在会话 /tmp,重写很快——B 表映射见 cpp 内注释即可重建)。

批次 ③(剩余):报告类(reportDevice*/request* 0x7ea8-0x7f35 段)、
locator 交互、zmodem(0x7e67/0x7e68)、mediaCopy、notify* 家族、
setColumnsPerPage/refreshScreen 等杂项。

转写方法(已验证):
0. 工具优先(tools/re/README.md):xref_scan.py 查调用者、fdes.json
   权威边界、qmo_extract.py 枚举表;反编译语料已入库
   tools/re/decomp(`grep -n "entry=007xxxxx"` 直达函数,免 grep 全库)
1. 查 `SUPERCOMMANDER-IMPL.md`(264 行,方法→实现地址→模板)
2. `procedure_pseudo_code(<实现地址>)`(Ghidra)反编译目标
3. Screen 层逻辑落 `Screen.cpp`,core 层逻辑落 `TerminalCore.cpp`,
   槽体只留守卫 + `m_screen->` 调用
4. 分批提交(中文信息)

## 已还原资产索引

- `src/Sessions/*.md`:SSH-INTERNALS(SSH 深度)/ PROTOCOL-ARCHITECTURE
  (Telnet 配置驱动 + Tcp/Serial 死导入定论)/ STATE-MACHINE(Frida 实测
  状态机)/ TERMINAL-CORE(结构体 + 调用链)/ IMPL-ADDRESSES 与
  SUPERCOMMANDER-IMPL(方法→地址表)
- `src/Sessions/KingEnums.h`:45 枚举权威值
- `src/Sessions/TerminalCore.h/.cpp`:屏幕核心结构体 + 6 方法(已转写)
- `src/libssh`:0.9.6+补丁精确源码;`src/Onigmo`:5.13.5+迭代器补丁
- `tools/re`:qmo_extract.py(QMetaObject 提取)/ xref_scan.py(numpy
  交叉引用引擎)/ ehframe_fdes.py(函数边界)/ frida_statechanged.js
  (动态状态机钩子)/ data(49 API 调用点、30566 FDE、方法表等)

## 已知开放问题

- Tcp/Serial:死导入已定论(Linux 主程序为纯壳),串口走 src/Pty
- TelnetProtocol 构造地址未精确锚定(0x7065aa 是 UI 字符串用户)
- TerminalCore `+0x78/+0x10` 热成员类型已定性(行表/文档指针),
  其余次级成员(+0x2c 等)按需
- `King::DataType`(SuperCommander 参数类型):无 Q_ENUM 注册,值域需从
  使用处代码反推——45 枚举表之外唯一已知缺口
  (枚举权威 = QMetaObject 表直读,见 KING-ENUMS-AUTHORITATIVE.md 更正)
