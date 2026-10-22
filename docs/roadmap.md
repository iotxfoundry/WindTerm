# 还原路线 v2 —— 从界面壳到功能实现

日期：2026-10-22 · 前序：Phase 1–8 界面壳已完成（见 docs/ 各 findings 与 visual-acceptance）
转折：界面验收通过，进入**功能实现**阶段。

## 功能地基盘点（证据）

作者开源源码中可直接采用的功能层（Apache-2.0）：

| 源码 | 内容 | 用途 |
|---|---|---|
| `src/Pty/`（56K） | `Pty` 抽象基类 + `UnixPty`（QProcess 派生 ShellProcess + PTY 主从 fd + QSocketNotifier）+ Win/Con（Windows，暂不编译） | 本地终端进程 |
| `src/Protocols/TelnetProtocol` | `Protocol` 抽象 + Telnet 实现 | Telnet 会话 |
| `src/libssh/`（4.7M 完整库源码） | libssh 本体 | SSH/SFTP 依赖（或用系统 libssh-dev） |

闭源部分（需自研或引用第三方）：终端仿真（VT/xterm 解析）、SSH 会话编排、SFTP 界面编排。

## F 阶段计划

### F1 本地终端可用（首个功能里程碑）
1. vendor `src/Pty/{Pty,Pty.cpp,UnixPty,UnixPty.cpp}` + `ptyqt LICENSE`（Windows 文件不编译）
2. `LocalSession`：包装 UnixPty，createProcess("/bin/bash")、readyRead→渲染、键盘→write、视图 resize→resizeWindow
3. **最小 VT 过滤器**（F1 必含，否则 bash 提示符转义码刷屏）：SGR 颜色子集、CR/LF/BS/Tab/BEL、清屏/清行——以 HTML 追加渲染进 TerminalView
4. 会话标签 ↔ LocalSession 生命周期：新建（+ 钮）/关闭（tab close）/切换（stack 切换即前后台保活）
5. 退出检测：进程结束 → 标签标记 [完成]

验收：骨架里点 + 得到**真正可交互的 bash**（ls 彩色、vim 基本可用性不作承诺、resize 生效）。

### F2 终端仿真补全
- 光标定位/滚动区/插入删除行/字符集——按需递进；评估 libvterm（MIT）替换自研解析器
- 主题联动：SGR 缺省色映射 scheme.theme 的 terminal.ansi*

### F3 SSH 会话
- 依赖选型：系统 libssh-dev（已随发行包验证存在 libssh.so.4）或 vendor src/libssh
- `SshSession`：connect/auth(password/key)/shell channel → 与 F1 同一渲染管线
- 连接对话框（host/port/user/auth/记住密码可选），菜单「会话→打开」接入

### F4 会话持久化
- `user.sessions`/`reopen.history` 读写（profile 格式对齐 ~/.wind 实测结构）
- Open Recent 子菜单接真数据

### F5 Telnet
- `TelnetSession` 包装已开源的 TelnetProtocol

### F6 SFTP/传输（远期）
- libssh sftp → FilerPane 实体化（本地/远程双栏）

## 不做（维持）
- Windows 平台（WinPty/ConPty 不编译）；完整 xterm 兼容（目标：日常 shell + ssh 工作流）；JS 脚本引擎（wind.actions 的 script 字段）

## 验证基线（新增）
- F1 起：除离屏断言外，需真机开一个 bash 标签人工验证交互（用户环节）
- 每个功能 commit 附操作说明（如何触发该功能）

## F3 完成记录（2026-10-22）
- SshSession（dlopen libssh.so.4，密码认证→PTY shell→QSocketNotifier 驱动读）
- ConnectDialog + 地址栏 `ssh [user@]host[:port]` 解析接线
- Session 基类解耦（Local/Ssh 共用 TerminalView）
- 已知缺口（F4 处理）：首连不验证主机密钥（MITM 窗口）；connect/auth 阻塞 GUI ≤5s；关标签不销毁会话；仅密码认证
