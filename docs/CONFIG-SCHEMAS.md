# CONFIG-SCHEMAS — 原版配置面资产(global/ + terminal/ + 运行期剖面)

> 调查日期:2026-10-29。资产 = 原版仓库附带(global/ + terminal/,
> Apache-2.0 首方)与 ~/.wind/profiles/default.v10 运行期剖面。
> 结论:**逆向价值极高**——配置键空间权威表、键位/词法/触发器/
> 协议引擎的输入格式全部在此,多数可直读。

## 一、资产清单

| 资产 | 规模 | 内容 | 逆向价值 |
|---|---|---|---|
| **global/wind.config** | 138 行 | 全局默认配置键值表(**权威默认层**) | CTerminalConfig 199 处 optGet 的键空间+默认值+类型,不再猜 |
| **global/wind.keymaps** | 2391 行 | 键位引擎:{keys 正则, modes(command/local), action\|script}——Vim 式键位全集 | **Phase 4a 键盘配置面的权威输入格式** |
| global/wind.variables | 110 行 | 变量替换引擎(AppDir/CaretLine/BufferText…,值为 JS 函数) | 命令/会话路径的 ${Var} 展开 |
| global/wind.actions | 2700 行 | 动作注册表(Window.RepeatLastCommand…,keymap/menu 引用的动作名) | 动作面命名权威 |
| **terminal/configs/session.config** | 88 行 | 终端会话默认键面(session.charset/keepAlive/log*/serial.*/modem.*…)* | 会话默认层(ProfileLoader 对应) |
| **terminal/configs/triggers.config** | 105 行 | 触发器:解压/超链接/auth 自动化(expect 正则) | **user.sessions 的 expect.password 权威来源**;超链接引擎 |
| **terminal/schemes/<shell>/\*.lexer** | 8 shell | TextMate 式词法(prompt 行高亮,scope 如 prompt.line.linux) | **shell 集成/词法引擎输入面**(notify* 通道消费) |
| **terminal/protocols/telnet.protocol** | 20 行 | Telnet 参数:SE/SB/WILL/WONT/DO/DONT 转义引用表 | **Protocols/Telnet 的配置键** |
| menu/toolbar/statusbar.config | — | UI 布局 | Phase 4a UI |
| ~/.wind 运行期剖面 | — | user.config(用户覆写)/onekeys/user.sessions(auth 加密 blobs + expect 模式)/reopen.history | 用户态样本;Cryptographic 面的已知密文样本(masterPassword=false 机器绑定) |

\* session.config 键面示例:session.charset=UTF-8、keepAlive=60、
logPattern=[%Y-%m-%d %H:%M:%S] %v、tcpKeepAlive=false…

## 二、装载顺序(语料+样本互证)

```
global/wind.config(全局默认层)
  → ~/.wind/profiles/<profile>/user.config(用户覆写层)
  → terminal/configs/*.config + schemes(域默认/触发器/词法)
  → user.sessions(会话实例,覆写域默认)
```
CTerminalConfig 现只读单文件——**缺全局默认层**(载入 wind.config
后 value(key,default) 的 default 即有权威来源)。PROFILES 剖析:
user.config 实际只有少量键(fingerprint/language/theme/lockScreen)
= 用户只改了这些,其余全部吃 wind.config 默认 ✓ 与装载顺序互证。

## 三、已发现的具体对应(转写时直接查表)

| 我方面 | wind.config/资产键 |
|---|---|
| terminal.autoComplete.*(visibleRows=7/threshold=1/complete*) | wind.config |
| terminal.commandHistory.*(days 30/size 10000/storage) | wind.config |
| terminal.expect.password/username(正则) | wind.config + triggers.config |
| tabbar.*/quickbar.*/grep.*/outline.* | wind.config |
| terminal.expect → user.sessions 的 expect.* | triggers.config(Hyperlink/Decompressor 样例) |
| telnet 转义(SE/SB/WILL…) | terminal/protocols/telnet.protocol |
| 键位 {keys,modes,action} | wind.keymaps(modes = command/local) |

## 四、行动项(按面转写节奏)

1. **ProfileLoader 补全局默认层**:读 wind.config 为基线,用户配置
   覆写——value(key) 无需 default 参数(有权威默认)
2. ~~**键位引擎**~~ ✅(批 26/27):src/Editor/KeymapEngine —— 523 条
   有效装载 + 锚定正则×mode 匹配 + tests/keymap_test(action 执行面待接)
3. **Telnet 协议** ✅ 骨架(批 27):TelnetCommander IAC 状态机 feed +
   telnet.protocol 装载 + telnet_test(RFC 响应策略待接)
4. **触发器/超链接引擎**:triggers.config 的 {text.pattern, action,
   lineColor} 面与 shell 集成 notify* 通道对接
5. **词法引擎**(schemes/*.lexer):prompt 行识别正则集——shell
   集成通道的输入面;TextMate 子集解析器为独立工程项
6. **Cryptographic 面样本**:user.sessions auth blobs(masterPassword
   =false 路径)= 已知密文样本,可用于验证 Cryptographic 实现
