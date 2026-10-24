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

## F4 完成记录（2026-10-23）
- 关标签销毁链：确认框(0x008df6c0)→view close+deleteLater(0x005ab2cc)→Session::close()（LocalSession=pty stop；SshSession=channel/ssh teardown）→session deleteLater；焦点恢复；组保留无空态
- user.sessions 只读：SessionStore（启动读 ~/.wind profile，写盘挂账+profile 隔离决策）；SessionPane 分组树+双击连 SSH（真数据验证）
- selfcheck：开标签→关标签→QPointer 失效断言
- 缺口：新建/编辑会话（写盘）、reopen.history 二进制格式（Qt 序列化，后续）、tmux 面板 kill-pane 分支
- 挂账撤销：侧栏左窄图标列经像素裁剪证明不存在（docs/imgs 裁剪 x0-60 全内容），上轮 explorer"AppletBar 图标列"措辞误读，挂账撤销。

---

# 未实现清单与计划（2026-10-24 反汇编对照盘点）

来源：symbols.tsv 7,697 条已逆明符号 × src/ 消费对照 + 全部 shortcut 挂账注释 + docs 审计挂账节。

## P1 终端可用性小件群（小，1 批）
| 项 | 证据 | 现状 |
|---|---|---|
| 恢复标签色持久化 | 0x8bbab6 QColor 字段 | closeEvent 未存，恢复统一暗色 |
| 恢复标签 currentIndex 应用 | 0x8bbab6 current 字段 | 读出未 setCurrentIndex |
| paneIconFactory | KitPane ctor 三连 0x8c3bbe | 4 处 setWindowIcon 挂账 |
| scheme 切换链 | Terminal.SchemeList 动态 action | 状态栏菜单仅改文本不应用 |
| keyMode 真实存储 | 0x8cb962 焦点过滤回写 | setter 仅置位 |
| 串口设备错误 UI 提示 | — | 仅 qWarning |

## P2 Pane 生命周期引擎补半（中）
insert 已移植（0x5a277a）；缺：remove/close 链（0x5a29e6 Splitter_cleanupEmptyTree 递归清空树、0x5a236c TabGroup_restoreFocus）；SplitViewHorizontally/Vertically+Merge To Group 菜单动作（现占位无接线）。

## P3 QuickSwitcher 命令面板（中）
0x7662e6 隐藏宿主（addToolBar(KitBar)+QStackedWidget+hide）+0x7664a2 每页一 Kit 按钮+0x8b346e QButtonGroup 切换；Editor/Terminal 页体系；Ctrl+Shift+P 入口。重建零实现（KitBar 名已预留）。

## P4 终端搜索/高亮（中大）
0x8f0c56 searchpanel_apply（正则→结果树）+0x55aeb0/0x6f68de HighlightText 触发规则引擎+0x55025c；TerminalView 需补 find/highlight API（滚回+活动屏匹配→选区/色层）；SearchPane 现空壳。

## P5 SFTP + FilerPane 实体化（大）
类族 0x8e59f2/0x8e6840/0x8e72e8（SftpFileSystemItem/SftpFile/SftpFolder/SftpTransfer）+0x91e918+0x6351c0（uid/gid 表单）；SshSession 补 sftp channel（绑定表已有 sftp_new2/sftp_init2）；FilerPane 硬编码假目录项换真数据（本地/远程双栏）。

## P6 传输实体化（大）
TransferModel 0x621a3e+传输进度消息 0x8f17c0+XYModem 收发 0x79cde6/0x79ed2e/0x79f1ac+0x79d680 send_file+0x585af56 TransferBar 懒建；TransferPane 假进度条换 TransferModel；TransferBar 接传输事件。

## P7 tmux control 集成（中大）
0x878fee tmux_parse_notify（begin/end/output/exit/layout-change）+Tmux 类族 0x7fd670/0x919180+0x8d9786 MuxDesktop；kill-pane 挂账并入本批。

## P8 端口转发中心（中）
ForwardingCenter/ForwardingHandler 0x5ecd00/0x5f1838+forwarding_server_listen 0x5ece74 QTcpServer 监听+0x718996 表单；菜单 ManageTunnels 现占位。

## 持续线（随相关批次带）
- 性能：增量行级重画（原版脏行范围）；同色 run 合并；UCS4 精确宽度表（双宽阈值近似升级）
- Mouse X10/1005/1015 形态（0x7ebdfc 有完整实现可抄）
- kbdint 答案 UI（原版 GUI 分片缺失，需补逆）
- 会话 id 派生规则校准（0x806382 逆明后）
- 快捷命令编辑对话框（0x6d36be 独立类族待确认）
- 0x8d2e46 建树链重逆（right 树布局互通）
- resize→pty 原版链补逆（现 QFontMetrics 等效）

## 批次依赖
P1 独立可先行；P2 是 P4/P5/P7 的布局基座（分屏后才有跨 pane 搜索/多 pane tmux）；P3 独立；P5→P6（SFTP 传输依赖 sftp channel）；P8 依赖 P5 的 ssh channel 扩展面（可并行做 UI）。
