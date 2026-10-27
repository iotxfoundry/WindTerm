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

## Tcp/Serial 状态(已定论:死导入)

三路验证(直接调用/数据区函数指针/GOT 间接调用)全部归零:
QSerialPort(13 导入)/QTcpSocket 在主程序中无任何引用 —— 链接
依赖存在但调用代码不在 Linux 主二进制(跨平台构建残留或运行时
模块引用)。Linux 主程序内 Serial/Tcp 会话即纯壳,与还原的薄壳
骨架一致;真正的串口实现走 `src/Pty`(ptyqt)路径。

## 已还原家族对照

| 家族 | 逆向进度 |
|---|---|
| SSH | 深度完成(SSH-INTERNALS.md:分层/认证流/49 API 调用点) |
| Telnet | 架构确认(配置驱动正则分发),协议字节级实现待深入 |
| Tcp/Serial | 薄壳骨架已还原;实现构造路径待查 |
