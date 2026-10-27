# 新会话起点(交接文档)

> 用途:新会话冷启动。让 agent 先读本文件 + 本目录其余文档,即可无缝续作。

## 一句话状态

WindTerm 2.7.0 逆向:API/架构/状态机全部打通。**第一/二批转写已完成**:SuperCommander.cpp 158 个真实现体,Screen 层
~80 方法,TerminalCore ~45 方法。批次②内容:DECSM/DECRM 完整 case 表
(备用屏双缓冲 1046/1047/1049、鼠标 9/1000-1007/1015/2004)、SCS 94/96
字符集槽、SGR 64 位属性状态机(core+0xb8 位域)、ICH/DCH/IL/DL/DECIC/
DECDC、DECDWL/DHL 行标志。**剩余 ~101 占位体:批次③报告类/locator/
zmodem/杂项**。

## 环境状态(新会话先核对)

| 项 | 值 |
|---|---|
| 引擎 | Ghidra 12.1.4(自动)/ IDA Pro 9.1(深度,GUI 需手动开)/ kuna |
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
