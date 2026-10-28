# TextView(编辑器核心)方法 → 实现地址映射

来源:TextView::qt_static_metacall(0x8f3a74)反编译,case 索引 = moc 方法表序号。
kind '?' = 信号(emit 桩),其余为可调用方法。地址为 WindTerm 主程序 VA。

| # | 方法签名 | 实现 |
|---|---|---|
| 0 | aboutToCopy(?) | 0x008f2ea0 |
| 1 | aboutToDrop(?,move,source,text) | - |
| 2 | aboutToImeCommit(move) | - |
| 3 | aboutToPaste(move) | - |
| 4 | callTipClicked(?) | 0x008f2fda |
| 5 | caretPositionChanged() | 0x008f2d38 |
| 6 | charAdded(?,data,position) | 0x008f30e8 |
| 7 | completerCanceled() | 0x008f2d4c |
| 8 | completerCharDeleted() | 0x008f2d60 |
| 9 | completerSelected(data,aboutToPaste,position,text) | 0x008f34f4 |
| 10 | containerChanged(?) | 0x008f3010 |
| 11 | decorationChanged(data,start) | 0x008f313c |
| 12 | decorationDoubleClicked(containerChanged,?,position) | 0x008f360a |
| 13 | decorationPressed(containerChanged,?,position) | 0x008f3654 |
| 14 | decorationReleased(containerChanged,?,position) | 0x008f369e |
| 15 | encodingChanged(move) | 0x008f38f4 |
| 16 | eolChanged(?) | 0x008f391e |
| 17 | focusIn() | 0x008f2d74 |
| 18 | focusOut() | 0x008f2d88 |
| 19 | highlightFoldRequested() | 0x008f2d9c |
| 20 | highlightFound() | 0x008f2db0 |
| 21 | highlightMarked() | 0x008f2dc4 |
| 22 | highlightOutlineRequested() | 0x008f2dd8 |
| 23 | highlightPairRequested() | 0x008f2dec |
| 24 | highlightSelection() | 0x008f2e00 |
| 25 | hotSpotDoubleClicked(containerChanged,?,position) | 0x008f36e8 |
| 26 | hotSpotPressed(containerChanged,?,position) | 0x008f3732 |
| 27 | hotSpotReleased(containerChanged,?,position) | 0x008f377c |
| 28 | hoverEnter(containerChanged,data,position) | 0x008f357a |
| 29 | hoverLeave(containerChanged,data,position) | 0x008f35c2 |
| 30 | indentChanged(?,?,indentSize) | 0x008f3954 |
| 31 | keyModeChanged(?) | 0x008f39a6 |
| 32 | macroRecorded(?,focusOut,wParam) | 0x008f353a |
| 33 | marginClicked(?,?,line) | 0x008f37c6 |
| 34 | marginMarkerAdded(data) | 0x008f3180 |
| 35 | marginMarkerRemoved(data) | 0x008f31b8 |
| 36 | marginStyleChanged(data) | 0x008f31f0 |
| 37 | marginTextChanged(data) | 0x008f3228 |
| 38 | mouseDoubleClicked(containerChanged,?,position) | 0x008f3816 |
| 39 | mousePressed(containerChanged,?,position) | 0x008f3860 |
| 40 | mouseReleased(containerChanged,?,position) | 0x008f38aa |
| 41 | navigated(data,data,rangeStart) | 0x008f3260 |
| 42 | outlineModelChanged() | 0x008f2e14 |
| 43 | outlineModelCleared() | 0x008f2e28 |
| 44 | painted() | 0x008f2e3c |
| 45 | pasted(data,position) | 0x008f32b6 |
| 46 | saveStateChanged(aboutToCopy) | 0x008f2fa2 |
| 47 | schemeAnsiStyleChanged(data,start) | 0x008f32fa |
| 48 | schemeChanged(move) | - |
| 49 | schemeFoldChanged() | 0x008f2e50 |
| 50 | schemeOutlineChanged() | 0x008f2e64 |
| 51 | schemePairChanged() | 0x008f2e78 |
| 52 | schemeScopeChanged(data,start) | 0x008f333e |
| 53 | shownLinesChanged(data,topLine) | 0x008f3382 |
| 54 | textChanged(data,data,position,removed) | 0x008f33c6 |
| 55 | textClientResized(completerCharDeleted,oldSize) | 0x008f39dc |
| 56 | textMultiChanged(data,data,data,start,inserted,lines) | 0x008f3428 |
| 57 | tryModifyReadOnly() | 0x008f2e8c |
| 58 | userListCanceled(?) | 0x008f3046 |
| 59 | userListCharDeleted(?) | 0x008f307c |
| 60 | userListSelected(?,aboutToPaste,listType,name) | 0x008f34a8 |
| 61 | zoomed(?) | 0x008f30b2 |
| 62 | activateNextSelection() | 0x005b5d7e |
| 63 | activatePreviousSelection() | 0x005b5df4 |
| 64 | addScrollBarMark(move,text,style) | 0x005c4c68 |
| 65 | appendText(data,aboutToCopy,text) | 0x005c4d5e |
| 66 | appendText(data,position) | 0x005c4d5e |
| 67 | cancelAutoComplete() | 0x005c0782 |
| 68 | cancelMultipleSelections() | 0x005b6006 |
| 69 | cancelSelection() | 0x005b607c |
| 70 | cancelSnippetMode() | 0x005b60f2 |
| 71 | canExpandSnippet() | - |
| 72 | canRedo() | - |
| 73 | canUndo() | - |
| 74 | charAt(data) | - |
| 75 | charCodeAt(data) | - |
| 76 | commitAutoComplete() | 0x005b6968 |
| 77 | copy() | 0x005b69de |
| 78 | discardAutoComplete() | 0x005b6a54 |
| 79 | dropSelection(?) | 0x005b6aca |
| 80 | dropSelection() | 0x005b6aca |
| 81 | encoding() | - |
| 82 | eol() | - |
| 83 | eolString(data) | 0x005b6f3c |
| 84 | eolString() | 0x005b6f3c |
| 85 | exchangeCaretAnchor() | 0x005b6fde |
| 86 | expandSnippet() | - |
| 87 | findNext(aboutToCopy) | 0x005c6834 |
| 88 | findNext() | 0x005c6834 |
| 89 | findPrevious(aboutToCopy) | 0x005c6842 |
| 90 | findPrevious() | 0x005c6842 |
| 91 | fold(data,line) | 0x005b70e4 |
| 92 | fold(data) | 0x005b70e4 |
| 93 | fold(data,start) | 0x005b7160 |
| 94 | fold(move) | 0x005b71dc |
| 95 | getRegister(move) | 0x005c4c0a |
| 96 | gotoLine(data,line) | 0x005b725e |
| 97 | gotoLine(data) | 0x005b725e |
| 98 | gotoPosition(data) | 0x005b72da |
| 99 | hasFocus() | - |
| 100 | hasNextSnippetStop() | - |
| 101 | hasPreviousSnippetStop() | - |
| 102 | indentSize() | - |
| 103 | indexOf(move,data,?,start,matchOptions) | 0x005c51aa |
| 104 | indexOf(move,data,pattern,end) | 0x005c51aa |
| 105 | invertSelection() | 0x005b7ae6 |
| 106 | isAutoCompletePreselected() | - |
| 107 | isAutoCompleteVisible() | - |
| 108 | isBinary() | - |
| 109 | isHexMode() | - |
| 110 | isOvertypeEnabled() | - |
| 111 | isReadOnly() | - |
| 112 | isSelectionEmpty() | - |
| 113 | isSnippetMode() | - |
| 114 | jumpToNextSnippetStop() | 0x005b821c |
| 115 | jumpToPreviousSnippetStop() | 0x005b82a2 |
| 116 | lineEnd(data) | - |
| 117 | lineFromPoint(containerChanged) | - |
| 118 | lineFromPosition(data) | - |
| 119 | lineHome(data) | - |
| 120 | lineStart(data) | - |
| 121 | lineText(data) | 0x005c0ccc |
| 122 | lockSelection() | 0x005b8adc |
| 123 | margin(aboutToPaste) | 0x005b8b52 |
| 124 | marginFromPoint(containerChanged) | - |
| 125 | margins() | 0x005b8bf4 |
| 126 | marginUnderMouse() | - |
| 127 | movePosition(data,position) | - |
| 128 | movePositionOutsideChar(data,position) | - |
| 129 | moveTo(aboutToPaste,type) | 0x005b8dac |
| 130 | moveTo(aboutToPaste) | 0x005b8dac |
| 131 | openHighlightTextDialog() | 0x005c3320 |
| 132 | paste() | 0x005b9274 |
| 133 | positionFromLine(data,line) | - |
| 134 | positionFromPoint(containerChanged) | - |
| 135 | removeMargin(aboutToPaste) | 0x005b9532 |
| 136 | removeRegister(move) | - |
| 137 | removeScrollBarMark(move) | 0x005b962a |
| 138 | resetZoom() | 0x005bf47e |
| 139 | save() | - |
| 140 | saveAs(move) | - |
| 141 | saveAs() | - |
| 142 | saveCopyAs(move) | - |
| 143 | saveCopyAs() | - |
| 144 | saveSelectionAs(move) | - |
| 145 | saveSelectionAs() | - |
| 146 | scheme() | 0x005b985e |
| 147 | scrollLineDown() | 0x005b9b0e |
| 148 | scrollLineUp() | 0x005b9b84 |
| 149 | searchOnline(move,engine) | - |
| 150 | searchOnline(move) | - |
| 151 | selectColumnTo(aboutToPaste,type) | 0x005b9e42 |
| 152 | selectColumnTo(aboutToPaste) | 0x005b9e42 |
| 153 | selectionAnchorP(?) | - |
| 154 | selectionAnchorP() | - |
| 155 | selectionCaretP(?) | - |
| 156 | selectionCaretP() | - |
| 157 | selectionCount() | - |
| 158 | selectionEndP(?) | - |
| 159 | selectionEndP() | - |
| 160 | selectionStartP(?) | - |
| 161 | selectionStartP() | - |
| 162 | selectionText(move,separator) | 0x005ba71c |
| 163 | selectionText(move) | 0x005ba71c |
| 164 | selectionText() | - |
| 165 | selectAll() | 0x005baabc |
| 166 | selectCommand() | 0x005bab32 |
| 167 | selectFold() | 0x005babb8 |
| 168 | selectIndentation() | 0x005bac3e |
| 169 | selectLine() | 0x005bacc4 |
| 170 | selectPair() | 0x005bad4a |
| 171 | selectParagraph() | 0x005badd0 |
| 172 | selectScope() | 0x005bae56 |
| 173 | selectTo(aboutToPaste,type) | 0x005baedc |
| 174 | selectTo(aboutToPaste) | 0x005baedc |
| 175 | selectWord() | 0x005bafd2 |
| 176 | setEol(?) | 0x005bcf78 |
| 177 | setEolVisible(aboutToCopy) | 0x005bd03a |
| 178 | setHexBase(?) | 0x005bd0e8 |
| 179 | setHexMode(aboutToCopy) | 0x005bd350 |
| 180 | setIndentSize(?) | 0x005c1416 |
| 181 | setMargin(focusOut) | 0x005bdc2e |
| 182 | setMarginTrackChange(aboutToCopy) | 0x005bdc82 |
| 183 | setOvertypeEnabled(aboutToCopy) | 0x005be2f8 |
| 184 | setRegister(move,key) | 0x005c6fae |
| 185 | setSelection(data) | 0x005be704 |
| 186 | setSelection(data,anchor) | 0x005be77e |
| 187 | setSelectionType(?,type) | 0x005bec4c |
| 188 | setSelectionType(?) | 0x005bec4c |
| 189 | setTabSize(?) | 0x005c1504 |
| 190 | setUseTabPosition(?) | 0x005c15f2 |
| 191 | setUseTabStop(aboutToCopy) | 0x005befd8 |
| 192 | setWordSeparators(move,separators) | 0x005bf1ae |
| 193 | setWordSeparators(move) | 0x005bf1ae |
| 194 | setZoomFactor(?) | 0x005bf3fc |
| 195 | splitSelection() | 0x005bf76a |
| 196 | subData(data,start) | 0x005c63d8 |
| 197 | subData(data) | 0x005c63d8 |
| 198 | subString(data,start) | 0x005c0c32 |
| 199 | subString(data) | 0x005c0c32 |


## 编辑器引擎(渲染层)锚定(2026-10-28)

**引擎 = Scintilla 系**(RTTI 实证:`SciCalltipClickEvent_vtable` /
`SciCompleterEvent_vtable` @ 0xa524cf/0xa524e7 析构)。TextView+0x58 的
后端对象 ≥0x1248 字节,两级命令分派:

| 级 | 地址 | 体量 | 覆盖 |
|---|---|---|---|
| 1 | **0x00a5205e** `props_getValueById` | 1113B | SCI 快速段 0x833-0x8a6 + WT 0x7531/0x7532,直接读写引擎成员 |
| 2 | **0x00a418c4** `s_line_caret_remote` | **37,951B** | 全命令空间(SCI/EXT 20173-20228/WT 30001-30166),0x7545 实现内联可见(FUN_00933366) |

签名一致:`QVariant* f(QVariant *ret, Engine*, uint cmd, QVariant *a, QVariant *b)`
——正是 sendEditor vtable+0x1c0 尾调用的落点形态。

引擎成员锚点(0xa5205e 段):+0x1148(子对象,FUN_00a74088/c4/c8/a0 簇)、
+0x11e8(bool)、+0x11f0(u64)、+0x1238/+0x123c(int 对)、+0x1240(ptr)、
+0x1098/+0x10a8(param_2[0x213]/[0x215],0x7545/0x7548 路径)。
0x7545(addScrollBarMark)实现 = FUN_00933366;0x7548 经引擎虚表 +0xe8 槽。

**38K 分派器 = 下一个 SuperCommander 级矿**,逐 case 提取待专项。

## 架构定性(2026-10-27 补,28 日修正)

TextView = 命令转发壳:方法体仅 QVariant 装配后经 sendEditor
(FUN_005b5d68,**22 字节纯 vtable 尾调用** —— `(*(void***)m_editor)[
0x1c0/8](ret, editor, cmd, a, b)`)分发 this+0x58 编辑器对象。
两种装配形态(调用方实证):
- ≤2 参:直接 QVariant 形参(如 FUN_005b99de cmd 0x75ad)
- >2 参:QList\<QVariant\> 打包进一个 QVariant
  (qlist_variant_append_heap,如 FUN_005c4c68 cmd 0x7545)
61 个命令号全解见 TEXTVIEW-COMMANDS.md(11 标准 SCI + 40 自定义:
扩展块 20173-20228 / WindTerm 命令空间 30001-30166)。
属性存储 +0xf8 = **QMap(有序,lower_bound 查找)**,非哈希;
节点 0x30 字节:key QString@+0x18(引用计数复制)、value QVariant@+0x20;
CoW:共享(ref>1)时 qmap_detach_copy_nodes 再写(FUN_005c6fae 全身已还原)。
方案名默认 "Plain Text";注册表 FUN_005b97cc 命中项 +8 = char* 名
(strlen 回退),fromUtf8 转换(FUN_005b985e 全身已还原);
注册表项 +0xa8 = 方案能力位(text.highlightCaretWord 经 session_optGet
读默认再与能力位与)。
find 引擎链:取选中文本(0x5c6448)-> 会话(0x5b3e46)-> 执行
(0x910 簇 FUN_0091b198);findReplace 对话框经 QDialog::finished
接线(FUN_005c3320)。TextView.h 为还原骨架。
