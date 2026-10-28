// 58 槽全量映射(idx=moc 序号,metacall 0x910a98 case 表)

| idx | 方法 | 实现 VA | 形态/证据 |
|---|---|---|---|
| 18 | cancelFreeTypeMode() | 0x0083cf68 | resetHard/resetSoft 共享 FUN_0083cee2(this, 0|1) |
| 19 | cancelModemTransmitting() | 0x00842172 | Screen 栈守卫 + FUN_007e318a(取消 modem 命令 2) + 释放 +0x120 modem 对象(0x38 字节) |
| 20 | canWrite() | 0x0083cdcc | canWrite:FUN_0083cdb8 状态查询 + 会话栈(+0x1e0/+0x1e8)守卫 |
| 21 | caretVirtualSpace() | 0x0083c710 | CMD 0x75df(int) |
| 22 | clearScreen() | 0x00840438 | 复合体:光标位置(0x8403a6/0x5b8576)与提示行(0x83c9e2)比较后经 0x5be68c 发命令 |
| 23 | clearScreenAndScrollback() | 0x00840532 | clearScreen(FUN_00840438) + QTimer::singleShot(500ms, FUN_0083fd35) 延迟清滚动缓冲 |
| 24 | clearScrollback() | 0x0083fc2c | tmux 特例:标志 0x160==1 发 'clear-history -t %%1' 经 Screen;否则 CMD 0x75f1 |
| 25 | commandText(command) | 0x0083c7f2 | 范围 helper FUN_005b8fcc -> FUN_005b9110 |
| 27 | completeHistory() | 0x0083df86 | FUN_0083de16(this, 1) |
| 28 | detectShellCwd() | 0x0083dc90 | QTimer 编排(+0x1a8,栈守卫 + 标志 0x160) |
| 29 | eraseFreeTypeRange() | 0x00842d34 | Screen 栈守卫 + 光标快照(0x840316)复合判断 |
| 30 | executeCommand(disconnected) | 0x0083ffde | +0x118/+0x1e0/+0x1e8 三重守卫 -> 会话/文本路径 |
| 31 | disconnectSession(commanderCreated) | 0x0083c330 | 全局管理器注册:FUN_00810d6e(this, 0x11c2200, this+0x1b0, 0) |
| 34 | isAltScreen() | 0x0083c4c8 | Screen 栈守卫 -> FUN_007e4028(+0x139 备用屏标志) |
| 35 | isConnected() | 0x0083c524 | +0x118 守卫 -> 会话查询 FUN_007d6736 |
| 36 | isFreeTypeMode() | 0x0083c538 | CMD 0x75e2(bool) |
| 37 | isLogFileExists() | 0x0083c5c8 | +0x148 引用守卫 -> QFileInfo::exists |
| 38 | isLoggerPaused() | 0x0083c63a | isConnected 守卫 -> 会话协议查询 FUN_007cabf8(+0x1e8) |
| 39 | isLoggerStarted() | 0x0083c5e6 | 会话栈守卫 -> +0x150 状态 |
| 40 | isLoginWizardVisible() | 0x0083c674 | +0x1b8/+0x1c0 智能指针对守卫 |
| 41 | isMainScreen() | 0x0083c696 | FUN_0083c4c8 取反(主屏) |
| 42 | isModemSupported(?,modemType) | 0x0083cb36 | 标志 0x160==0 时仅 'Telnet'(QString::compare)支持 modem;带标志走类型范围 |
| 43 | isModemTransmitting() | 0x0083c6a8 | +0x120 modem 非空 -> 1;否则 Screen FUN_007e31ec(命令 3) |
| 44 | isUnconnected() | 0x0083c6fc | +0x118 守卫 -> FUN_007d6722 |
| 45 | localBaseTime() | 0x0083c822 | CMD 0x75f9 |
| 46 | openLogFolder() | 0x0083c8b4 | 无日志 -> 全局默认(0x11c2200);有 -> QFileInfo(+0x148).absolutePath() |
| 47 | openLogFile() | 0x0083c970 | isModemTransmitting 守卫 -> FUN_0083c616 -> 全局对话框(0x11c1680, +0x148 参) |
| 48 | openSessionTriggersDialog() | 0x0083c9a4 | 全局 FUN_00699088(0x11c1a60, this+0x1b0, this) |
| 49 | pasteText(disconnected) | 0x00843050 | executeCommand 全路径:光标/编辑器文本装备 + 发送 |
| 50 | pauseLogger() | 0x0083c9be | isConnected 守卫 -> FUN_007d36a0(+0x118, +0x150) |
| 51 | promptLine() | 0x0083c9e2 | CMD 0x75dd(int) |
| 52 | promptPosition() | 0x0083ca74 | CMD 0x75de(int) |
| 53 | protocolName() | 0x0083cb0c | +0x118 守卫 -> FUN_007d5d2a(协议名) |
| 54 | receiveBinary(?) | 0x008496da | FUN_00848d6a(this, data, 0)(发送二进制) |
| 55 | reconnectSession() | 0x0083d97a | 'SessionErrorMessage' 方案显示;状态非 0/1/5 分支 |
| 56 | resetCharacterSet() | 0x0083cbc8 | Screen 栈守卫 -> sendScreenCommand(6) 清屏 |
| 57 | resetHard() | 0x0083cc00 | Screen 栈守卫 -> sendScreenCommand(7) 清滚动缓冲 |
| 58 | resetSoft() | 0x0083cc38 | Screen 栈守卫 -> FUN_007e33ea(日志暂停命令) |
| 59 | resumeLogger() | 0x0083cc70 | isConnected 守卫 -> FUN_007d3d28(+0x118, +0x150) |
| 60 | scrollbackLimit() | 0x0083cc94 | CMD 0x75f2 |
| 61 | scrollbackLines() | 0x0083cd26 | CMD 0x75f3 |
| 62 | sendBinary(?) | 0x008496e2 | FUN_00848d6a(this, data, 1)(接收二进制,与发送共享) |
| 63 | setLocalBaseTime(command) | 0x0083cf70 | CMD 0x75fd(int 参) |
| 64 | setRemoteBaseTime(command) | 0x0083cff2 | CMD 0x75ff(int 参) |
| 65 | setRightClickAction(disconnected) | 0x0083d0a6 | 全局(0x11c2200)查询 -> FUN_0083d074 |
| 67 | setScrollbackLimit(?) | 0x0083d0c6 | CMD 0x75f4(int 参) |
| 68 | setTimestampFormat(QMouseEvent*) | 0x0083d2cc | CMD 0x75fc(QByteArray 参) |
| 69 | setTimestampLongFormat(QMouseEvent*) | 0x0083d34e | CMD 0x75fe(QByteArray 参) |
| 70 | startLogger(disconnected) | 0x008439ec | 会话感知的 QString 参复合体 |
| 71 | startLogger() | 0x008439ec | 会话感知的 QString 参复合体 |
| 72 | stopLogger() | 0x0083dc18 | isConnected + 会话 FUN_007d377c(+0x118, +0x150, 0) + 释放 +0x150 |
| 73 | supportsDetectShellCwd() | 0x0083dc72 | 方案注册表(FUN_005b97cc) +0x30 标志 getter |
| 74 | write(disconnected,text) | 0x0083e286 | 静态初始化守卫 + FUN_009109fa 信号接线 |
| 75 | write(disconnected) | 0x0083e286 | 静态初始化守卫 + FUN_009109fa 信号接线 |
