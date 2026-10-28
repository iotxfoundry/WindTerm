# Screen 信号表(经 setScreen 安装器布线 + 发射器 activate 索引)

| 信号 idx | 发射器 | 接收槽(TerminalWidget) | 已证名 |
|---|---|---|---|
| 3 | FUN_00913274 | FUN_0083acf4 | - |
| 4 | FUN_0091340c | FUN_0083d8e6 | - |
| 5 | FUN_00913436 | FUN_0083a906 | - |
| 6 | FUN_00913592 | FUN_0083ac06 | - |
| 7 | FUN_00913460 | FUN_0083aa14 | cursorVisible |
| 8 | FUN_009131c8 | FUN_0083a988 | mouseMode |
| 9 | FUN_0091329e | FUN_0083daf6 | - |
| 10 | FUN_00913498 | FUN_008421ec | - |
| 12 | FUN_009132f8 | FUN_0083b8a4 | - |
| 17 | FUN_009136b2 | FUN_00840e66 | - |
| 18 | FUN_009134d0 | FUN_0083ab80 | reverseScreen |
| 19 | FUN_0091318c | FUN_0083fc2c | - |
| 24 | FUN_0091334c | FUN_0083b240 | - |
| 25 | FUN_009131fe | FUN_0083acce | - |
| 26 | FUN_009136dc | FUN_0083af62 | - |
| 27 | FUN_0091370c | FUN_0083af9a | - |
| 28 | FUN_00913760 | FUN_0084dd5a | - |
| 29 | FUN_00913736 | FUN_0083be38 | - |
| 30 | FUN_0091378a | FUN_00848d6a | - |
| 31 | FUN_009137ce | FUN_0083ad32 | - |
| 33 | FUN_009133b2 | FUN_0083d3f6 | - |
| 34 | FUN_00913540 | FUN_0083ac2a | - |
| 35 | FUN_009137f8 | FUN_0083ad60 | - |
| (scrollbar) | FUN_00913508 | FUN_0083aa9a | scrollbarNotify |

Screen 元对象 0x11a82e0 信号索引至少覆盖 1..35(20+ 个已读出索引),
远超此前实证的 5 个;全部经 FUN_008464ec 安装器连接到 TerminalWidget 槽。

## 发射器 ↔ 信号名全对齐(2026-10-28 定案)

**idx = 池序 − 2**(池头多 2 个非信号字符串);四点已证:idx7=
caretVisibleChanged、idx18=screenReversed、idx20=scrollBarVisibleChanged、
idx30=transferBinary(zmodemSend 调 0091378a(2,1) 实锤)。

| 发射器 | idx | 信号名(池序−2) | 参数 |
|---|---|---|---|
| 0091340c | 4 | binaryBytesRead | (qint64) |
| 00913436 | 5 | caretColorChanged | (…) |
| 00913592 | 6 | caretStyleChanged | (bool, int) |
| 00913460 | 7 | caretVisibleChanged ✅ | (bool) |
| 00913498 | 10 | messageNotified | (bool/int) |
| 009135d8 | 13 | requestMapToScreenColumn | (pos, int&) |
| 00913638 | 14 | requestMapToScreenPoint | (QPoint&) |
| 00913608 | 15 | requestMapToScreenRow | (pos, int&) ← locatorRowFromPixel |
| 00913668 | 16 | requestMapToWindowColor | (const char*, bool, QColor&) |
| 009136b2 | 17 | screenChanged | (…) |
| 009134d0 | 18 | screenReversed ✅ | (bool) |
| 00913508 | 20 | scrollBarVisibleChanged ✅ | (bool) |
| 009136dc | 26 | tmuxSessionsChanged | (…) |
| 0091370c | 27 | tmuxTermsRemoved | (…) |
| 00913760 | 28 | tmuxWindowsChanged | (…) |
| 00913736 | 29 | tmuxWindowsRemoved | (…) |
| 0091378a | 30 | transferBinary ✅ | (int, int) ← notifyZmodem |
| 009137ce | 31 | windowMoved | (…) |
| 00913540 | 34 | windowSizeChanged | (int, int, bool) |
| 009137f8 | 35 | windowTitleChanged | (int/QString) |

其余小发射器(0091318c/9131c8/9131fe/913274/91329e/9132f8/91334c/
9133b2/9133e2)按同式可对齐,待调用点出现再定名。

## 互证与遗留(2026-10-27)

- metaobject 结构(0x11a82e0,delta 0x600000 区)读出 metacall=0x91382e
  —— 即 Screen::qt_static_metacall(位于发射器簇中,实锤归属);
  data[4]=37 = 方法总数,与 25 信号 + 槽计数互证。
- 结构定位定案:QMetaObject 结构体就在 0x11a82e0(Ghidra
  PTR_ 标签指向它),{super=0, strd=0xce0960(rodata 区,非
  .text —— 此前误判), data=0xce0420, metacall=0x91382e};
  strd/data 指向 rodata 中的 moc rev-9 表,多次移位假设未完全
  对齐(Qt 5.15.2 私有格式细节),名字解码判停(ponytail)。
- 名字获取推荐路径:Frida 一次 dump
  metaObject()->method(i).name()(i=0..36),分钟级完成,
  替代继续静态格式考古。

## 真名全解(2026-10-27 终,字符串池 0xce0960 区直读)

**Screen 类真名 = SuperTerm**(池首类名;此前工程代号 Screen 保留)。
信号声明序(池序 = moc 序,39 个信号名):

 1. ansiModeEntered
 2. ansiModeExited
 3. asyncMessage
 4. termMessage
 5. bellRequested
 6. binaryBytesRead
 7. caretColorChanged
 8. caretStyleChanged
 9. caretVisibleChanged
10. cursorShapeChanged
11. messageNotified
12. modemFinished
13. modemStarted
14. remoteDirectoryNotified
15. requestMapToScreenColumn
16. requestMapToScreenPoint
17. requestMapToScreenRow
18. requestMapToWindowColor
19. screenChanged
20. screenReversed
21. scrollbackErased
22. scrollBarVisibleChanged
23. tmuxControlModeEntered
24. tmuxControlModeExited
25. tmuxErrorOccurred
26. tmuxPaneCwdChanged
27. tmuxScreenChanged
28. tmuxSessionsChanged
29. tmuxTermsRemoved
30. tmuxWindowsChanged
31. tmuxWindowsRemoved
32. transferBinary
33. windowMoved
34. windowSelectionsRead
35. windowSelectionsWritten
36. windowSizeChanged
37. windowStateChanged
38. windowTitleChanged

已证索引对齐:idx7=caretVisibleChanged(原 cursorVisible)、
idx18=screenReversed(原 reverseScreen)、scrollBarVisibleChanged=
滚动条通知、ansiModeEntered/Exited=DEC 12/DECANM 路径的信号面。

**交互请求信号族**(带引用出参 —— 视图必须响应):
requestMapToScreenColumn(globalPosition, int& column)
requestMapToScreenRow(..., row)、requestMapToScreenPoint(QPoint&)
requestMapToWindowColor(const char* style, fore, QColor&)

**tmux 信号族**:tmuxControlMode/Pane/Screen/Sessions/Windows/…(10 个)
**窗口信号族**:windowMoved/SelectionsRead/SelectionsWritten/
SizeChanged/StateChanged/TitleChanged
**调制解调器**:modemStarted(downloadFileName)/modemFinished(success)
transferBinary(King::ModemType, King::TransmitType)

紧随其后的相邻池 = TerminalView 的 moc 表(propertyChanged/
transferCreated/activate/close/closeMessageBar/groupName/isLoaded/
path/setTabIcon/setTabText/showMessageBar/tabIcon/tabText/url/
disconnectSession/displayUrl/isPermanentSession ...)。
