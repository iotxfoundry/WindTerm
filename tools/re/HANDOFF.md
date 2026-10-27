# 新会话起点(交接文档)

> 用途:新会话冷启动。让 agent 先读本文件 + 本目录其余文档,即可无缝续作。

## 一句话状态

WindTerm 2.7.0 逆向:API/架构/状态机全部打通,**当前任务 = 把
`SuperCommander.cpp` 的 179 个占位实现体变成真实现**(分批转写,
工具与数据全部就绪,见下)。

## 环境状态(新会话先核对)

| 项 | 值 |
|---|---|
| 引擎 | Ghidra 12.1.4(自动)/ IDA Pro 9.1(深度,GUI 需手动开)/ kuna |
| IDA MCP | `~/.config/rea/ida-mcp.json`(stdio);IDA GUI 里需 Ctrl+Alt+M 启动插件服务 |
| GitHub 代理 | `192.168.1.106:7890`(push 必带 `-c http.proxy=…`) |
| 提交规范 | 中文,force 推送需覆盖远端 dev |
| ptrace_scope | 已恢复 1(动态分析时临时置 0) |
| 远端 dev | 已同步(本地=远端=同一链) |

## 当前任务(三批转写,~216 个函数)

`src/Sessions/SuperCommander.cpp` 中 179 个函数体目前是**地址注释占位**。
批量转写方法(已验证):

1. 查 `SUPERCOMMANDER-IMPL.md`(237 行,方法→实现地址→模板 T1/T2/T3)
2. `procedure_pseudo_code(<实现地址>)`(Ghidra)反编译目标
3. 按模板转写:
   - T1 纯转发 → 调用对应的 TerminalCore/Screen 层函数(多数可对接
     `TerminalCore.h` 已还原方法)
   - T2 参数守卫 → n<0 拒绝,n==0 置 1
   - T3 复合 → 人工核对(全表仅 2 个)
4. 分批提交(中文信息)

建议批次:①光标移动/擦除/滚动族(同构多,快) ②DEC 模式/字符集/SGR
③报告类/locator/zmodem。

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
