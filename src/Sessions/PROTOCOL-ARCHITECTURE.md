# 协议架构(Telnet/Tcp/Serial/SSH 逆向笔记)

> 数据来源:telnet.protocol 配置、PLT/GOT 交叉引用扫描、QMetaObject 元数据、
> Ghidra 反编译。地址均为 WindTerm 2.7.0 主程序 VA。

## 核心发现:Telnet 是配置驱动的

`terminal/protocols/telnet.protocol` 用 **PCRE 正则定义协议**(命名捕获组):

```
IAC ( (?<NegotiateOption> (?<command> DO|DONT|WILL|WONT) (?<option> .))
    | (?<NegotiateSubOption> (?<SB) (?<option> .) (?<action> .) (?&IAC) (?&SE))
    | (?<IgnoreWrongIAC> (?<command> .)) )
```

匹配后**按命名捕获组分发到同名槽**:

- `NegotiateOption` → `TelnetCommander::negotiateOption(command, option)`
- `NegotiateSubOption` → `TelnetCommander::negotiateSubOption(option, action)`

这解释了三个前作设计:**Onigmo 迭代器补丁**(跨 gap buffer 匹配)、
**boost::xpressive 内嵌**(正则 DSL)、**JS 引擎内嵌**(动作脚本)。
WindTerm 的协议层是「正则协议引擎 + 配置文件」而非硬编码状态机。

配置键:`telnet.port`、`telnet.target`(wind.config 家族)。

## 二进制锚点

| 锚点 | 地址 | 说明 |
|---|---|---|
| TelnetProtocol 构造(m_name="Telnet") | 未精确定位 | 0x7065aa 为 UI 字符串用户,非构造 |
| King 协议类 QMetaObject | 0x11a7440/0x11a8140/0x11a8220 | Commander/Bridge/Session 三基类 |
| TerminalWidget 元数据串 | 0x8dde40 起 | QPointer\<SuperCommander\> 持有证据 |

## Tcp/Serial 状态(开放问题)

- 主程序 .text 中**未发现** QSerialPort/QTcpSocket 构造的直接调用
  (QSerialPort 13 个导入存在,但构造函数零交叉引用)
- 推测:构造经 metacall/QMetaObject::newInstance 工厂、虚表、或
  实际实现在运行时模块 —— 待查
- Serial 对应 `src/Pty`(ptyqt 重写版)的串口分支,部分开源已在库

## 已还原家族对照

| 家族 | 逆向进度 |
|---|---|
| SSH | 深度完成(SSH-INTERNALS.md:分层/认证流/49 API 调用点) |
| Telnet | 架构确认(配置驱动正则分发),协议字节级实现待深入 |
| Tcp/Serial | 薄壳骨架已还原;实现构造路径待查 |
