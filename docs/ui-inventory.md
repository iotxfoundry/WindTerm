# UI 清单（自二进制与资产提取的证据）

来源：`strings WindTerm`（RTTI/Qt 元对象）、`global/locales/zh-CN.locale`、`images/screenshots/WindTerm.png`。
类名按原名保留；标注 (s) 为截图可见、(b) 为二进制字符串可见。

## 主窗口结构 (s)
```
MainWindow
├─ MenuBar: Session | Edit | Search | Selection | Goto | View | Mode | Window | Help
├─ LeftDock:  FilerPane (s)(b)         文件树 + 路径面包屑
├─ Center:    MuxPaneGroup (b)         彩色会话标签 + 终端视图
├─ RightDock: SessionPane (s)          会话树（Putty sessions / Shell sessions）
│             OutlinePane (s)(b)        命令历史
├─ BottomDock: SenderPane | TransferPane (s)(b)   传输进度条
├─ CommandButtonBar (s)                动作按钮组 ← global/wind.actions
└─ StatusBar (s)                       Ready · Remote Mode · Ln/Ch · host · 时间 · WindTerm
```

## 二进制可见的界面类（节选，全部原名）
窗口/视图：`MainWindow` `MuxWindow` `CommanderWindow` `BrowserWindow` `EditorWindow` `KitWindow` `BrowserView` `EditorView` `GrepView` `FileView` `CommanderView`
面板：`FilerPane` `FilerPaneCorner` `ExplorerPane` `KitPane` `KitView` `FindPane` `FindInFilesPane` `OutlinePane` `OutputPane` `MuxPane` `MuxPaneGroup`
面板控件：`ButtonBarPanel` `CheckListPanel` `ListPanel` `PlainTextEditPanel` `AutoSyncTerminalFolderButton` `CopyDirectoryPathToTerminalButton`
会话域（UI 存根即可）：`SshBridge` `SshSession` `SshCommander` `SshOperator` `SshOneKey` `SerialSession` `SerialBridge` `SerialCommander` `TelnetCommander` `ShellSession` `ShellBridge` `SftpTransfer` `LastSessions` `MultiWindows` `Panes` `MasterPasswordDialog` `SessionSettingsDialog`(推断名)

## 文案目录
- `global/locales/*.locale`：JSON `{"en":…, "tr":…}`，zh-CN 含 1,414 条，即完整英文界面文案
- 菜单类文案（节选）：File / Edit / Connection / Session / Panes / Layout / Keyboard / Help

## 主题资产
- `global/themes/{default,dige-white,dige-black,dige-black-and-white}/`
- images/*.svg（checkbox/radiobox/close/logo/warning…）、fonts/*.ttf、audios/*.mp3
- 接入方式：`tools/fetch-assets.sh` 复制子集到 `assets/`，运行时 `ThemeManager` 加载
