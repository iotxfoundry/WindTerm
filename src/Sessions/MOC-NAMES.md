# MOC 真名总表(全类字符串池直读,2026-10-27)

来源:moc 元数据字符串池(长度前缀类名标记池边界)。

## 关键确认

**SuperCommander 五信号真名**(与还原顺序 0-4 对齐):
- asyncMessage(commanderMessage, wParam, lParam)
- charsetChanged(name) / error(code, info)
- shellCwdChanged(shellCwd) / syncMessage(QVariant& result)

**SuperSession 78 名**:SSH 认证信号族 14 个(authAgent/authNone/
authGssapiWithMic/authInteractive×3/authOneKey/authPassword/
authPublicKey/autoLogin/drop)+ term/logger/transfer 生命周期 +
槽族(removeTerm/removeTransfer/verifyKnownHost/writeKnownHost/
serverBanner/opensshVersion...)

**SuperTerm(Screen)89 名**:39 信号(见 SCREEN-SIGNALS.md)

**SuperBridge 真信号名**:commanderCreated(QPointer<SuperCommander>)/
commandOutput/aboutToConnect/aboutToDisconnect/disconnected/
mouse(mouseEvent,row,column)/ready/screenSizeChanged(rows,columns)/
sessionStateChanged(King::SessionState)/shellCwdChanged/stateChanged/
textWritten(text,King::WriteReason)/tmuxCommandWritten/
tmuxPaneNameChanged(notification)/windowTitleChanged(name)/
writeRemote(bytes)/writeRemoteSingal(const char* signal)

**新枚举引用**:King::WriteReason / King::CaretShape /
King::ModemType / King::TransmitType / King::FingerprintType /
King::ServerKnownState / King::DataType(池内类型名)

## 各类池名数

- EditorView: 37 名
- EditorWindow: 15 名
- FilerPane: 40 名
- GrepView: 31 名
- OutlinePane: 12 名
- OutputPane: 13 名
- SearchPane: 18 名
- SenderPane: 26 名
- SessionPane: 13 名
- SuperBridge: 78 名
- SuperCommander: 247 名
- SuperSession: 78 名
- SuperTerm: 89 名
- TerminalView: 37 名
- TerminalWidget: 114 名
- TerminalWindow: 26 名
- TextEdit: 73 名
- TextView: 488 名
- TransferPane: 9 名
- UndoList: 2 名
- ZModem: 8 名

机读版:tools/re/data/moc_names.json(全池名序列)。
注:池链边界按标记推断,SuperBridge/TextView 用显式区间修正;
名字序列 = moc 声明序(信号先于槽,参数名跟随信号名)。
