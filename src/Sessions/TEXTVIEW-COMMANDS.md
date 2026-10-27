# TextView 命令分派表(方法 -> 编辑器命令)

架构:TextView 是命令转发壳 —— 每个方法经 sendEditor(FUN_005b5d68)

分发:虚调用 this+0x58 编辑器对象的虚表槽 0x1c0。命令号分三段:

- SCI:标准 Scintilla 消息(<=2400)
- EXT:扩展命令块 20173-20228
- WT:WindTerm 自定义命令 30001-30166

| # | 方法 | 体 VA | 命令 | 段 | 名称 |
|---|---|---|---|---|---|
| 62 | activateNextSelection() | 0x5b5d7e | 0x4ecd | EXT | CMD_20173 |
| 63 | activatePreviousSelection() | 0x5b5df4 | 0x4ece | EXT | CMD_20174 |
| 64 | addScrollBarMark(move,text,style) | 0x5c4c68 | 0x7545 | WT | CMD_30021 |
| 65 | appendText(data,aboutToCopy,text) | 0x5c4d5e | 0x7551 | WT | CMD_30033 |
| 66 | appendText(data,position) | 0x5c4d5e | 0x7551 | WT | CMD_30033 |
| 67 | cancelAutoComplete() | 0x5c0782 | 0x835 | SCI | SCI_AUTOCCANCEL |
| 68 | cancelMultipleSelections() | 0x5b6006 | 0x4f04 | EXT | CMD_20228 |
| 69 | cancelSelection() | 0x5b607c | 0x4ed1 | EXT | CMD_20177 |
| 70 | cancelSnippetMode() | 0x5b60f2 | 0x75ba | WT | CMD_30138 |
| 76 | commitAutoComplete() | 0x5b6968 | 0x837 | SCI | SCI_AUTOCPOSSTART |
| 77 | copy() | 0x5b69de | 0x882 | SCI | SCI_COPY |
| 78 | discardAutoComplete() | 0x5b6a54 | 0x7531 | WT | CMD_30001 |
| 79 | dropSelection(?) | 0x5b6aca | 0x4ed0 | EXT | CMD_20176 |
| 80 | dropSelection() | 0x5b6aca | 0x4ed0 | EXT | CMD_20176 |
| 83 | eolString(data) | 0x5b6f3c | 0x7577 | WT | CMD_30071 |
| 84 | eolString() | 0x5b6f3c | 0x7577 | WT | CMD_30071 |
| 85 | exchangeCaretAnchor() | 0x5b6fde | 0x4ed5 | EXT | CMD_20181 |
| 91 | fold(data,line) | 0x5b70e4 | 0x7571 | WT | CMD_30065 |
| 92 | fold(data) | 0x5b70e4 | 0x7571 | WT | CMD_30065 |
| 93 | fold(data,start) | 0x5b7160 | 0x756f | WT | CMD_30063 |
| 94 | fold(move) | 0x5b71dc | 0x7570 | WT | CMD_30064 |
| 96 | gotoLine(data,line) | 0x5b725e | 0x75ab | WT | CMD_30123 |
| 97 | gotoLine(data) | 0x5b725e | 0x75ab | WT | CMD_30123 |
| 98 | gotoPosition(data) | 0x5b72da | 0x75ac | WT | CMD_30124 |
| 103 | indexOf(move,data,?,start,matchOptions) | 0x5c51aa | 0x757e | WT | CMD_30078 |
| 104 | indexOf(move,data,pattern,end) | 0x5c51aa | 0x757e | WT | CMD_30078 |
| 105 | invertSelection() | 0x5b7ae6 | 0x4ed3 | EXT | CMD_20179 |
| 114 | jumpToNextSnippetStop() | 0x5b821c | 0x75c0 | WT | CMD_30144 |
| 115 | jumpToPreviousSnippetStop() | 0x5b82a2 | 0x75c0 | WT | CMD_30144 |
| 122 | lockSelection() | 0x5b8adc | 0x4ecf | EXT | CMD_20175 |
| 123 | margin(aboutToPaste) | 0x5b8b52 | 0x7590 | WT | CMD_30096 |
| 125 | margins() | 0x5b8bf4 | 0x7591 | WT | CMD_30097 |
| 129 | moveTo(aboutToPaste,type) | 0x5b8dac | 0x4f02 | EXT | CMD_20226 |
| 130 | moveTo(aboutToPaste) | 0x5b8dac | 0x4f02 | EXT | CMD_20226 |
| 132 | paste() | 0x5b9274 | 0x883 | SCI | SCI_PASTE |
| 135 | removeMargin(aboutToPaste) | 0x5b9532 | 0x7594 | WT | CMD_30100 |
| 137 | removeScrollBarMark(move) | 0x5b962a | 0x7549 | WT | CMD_30025 |
| 147 | scrollLineDown() | 0x5b9b0e | 0x926 | SCI | SCI_LINESCROLLDOWN |
| 148 | scrollLineUp() | 0x5b9b84 | 0x927 | SCI | SCI_LINESCROLLUP |
| 151 | selectColumnTo(aboutToPaste,type) | 0x5b9e42 | 0x4f02 | EXT | CMD_20226 |
| 152 | selectColumnTo(aboutToPaste) | 0x5b9e42 | 0x4f02 | EXT | CMD_20226 |
| 162 | selectionText(move,separator) | 0x5ba71c | 0x75b8 | WT | CMD_30136 |
| 163 | selectionText(move) | 0x5ba71c | 0x75b8 | WT | CMD_30136 |
| 165 | selectAll() | 0x5baabc | 0x7dd | SCI | SCI_SELECTALL |
| 166 | selectCommand() | 0x5bab32 | 0x4edf | EXT | CMD_20191 |
| 167 | selectFold() | 0x5babb8 | 0x4edf | EXT | CMD_20191 |
| 168 | selectIndentation() | 0x5bac3e | 0x4edf | EXT | CMD_20191 |
| 169 | selectLine() | 0x5bacc4 | 0x4edf | EXT | CMD_20191 |
| 170 | selectPair() | 0x5bad4a | 0x4edf | EXT | CMD_20191 |
| 171 | selectParagraph() | 0x5badd0 | 0x4edf | EXT | CMD_20191 |
| 172 | selectScope() | 0x5bae56 | 0x4edf | EXT | CMD_20191 |
| 173 | selectTo(aboutToPaste,type) | 0x5baedc | 0x4f02 | EXT | CMD_20226 |
| 174 | selectTo(aboutToPaste) | 0x5baedc | 0x4f02 | EXT | CMD_20226 |
| 175 | selectWord() | 0x5bafd2 | 0x4edf | EXT | CMD_20191 |
| 176 | setEol(?) | 0x5bcf78 | 0x7579 | WT | CMD_30073 |
| 177 | setEolVisible(aboutToCopy) | 0x5bd03a | 0x934 | SCI | SCI_SETVIEWEOL |
| 178 | setHexBase(?) | 0x5bd0e8 | 0x759a | WT | CMD_30106 |
| 179 | setHexMode(aboutToCopy) | 0x5bd350 | 0x759e | WT | CMD_30110 |
| 180 | setIndentSize(?) | 0x5c1416 | 0x7585 | WT | CMD_30085 |
| 181 | setMargin(focusOut) | 0x5bdc2e | 0x7596 | WT | CMD_30102 |
| 182 | setMarginTrackChange(aboutToCopy) | 0x5bdc82 | 0x7597 | WT | CMD_30103 |
| 183 | setOvertypeEnabled(aboutToCopy) | 0x5be2f8 | 0x75a5 | WT | CMD_30117 |
| 185 | setSelection(data) | 0x5be704 | 0xa0c | SCI | SCI_SETSELECTION |
| 186 | setSelection(data,anchor) | 0x5be77e | 0xa0c | SCI | SCI_SETSELECTION |
| 187 | setSelectionType(?,type) | 0x5bec4c | 0xa20 | SCI | SCI_SETRECTANGULARSELECTIONCARETVIRTUALSPACE |
| 188 | setSelectionType(?) | 0x5bec4c | 0xa20 | SCI | SCI_SETRECTANGULARSELECTIONCARETVIRTUALSPACE |
| 189 | setTabSize(?) | 0x5c1504 | 0x75c4 | WT | CMD_30148 |
| 190 | setUseTabPosition(?) | 0x5c15f2 | 0x75c5 | WT | CMD_30149 |
| 191 | setUseTabStop(aboutToCopy) | 0x5befd8 | 0x75c6 | WT | CMD_30150 |
| 192 | setWordSeparators(move,separators) | 0x5bf1ae | 0x75d6 | WT | CMD_30166 |
| 193 | setWordSeparators(move) | 0x5bf1ae | 0x75d6 | WT | CMD_30166 |
| 194 | setZoomFactor(?) | 0x5bf3fc | 0x945 | SCI | SCI_SETZOOM |
| 195 | splitSelection() | 0x5bf76a | 0x4ed2 | EXT | CMD_20178 |
| 198 | subString(data,start) | 0x5c0c32 | 0x7554 | WT | CMD_30036 |
| 199 | subString(data) | 0x5c0c32 | 0x7554 | WT | CMD_30036 |

9 个真逻辑体(非命令转发):findNext/findPrevious(0x5c6834/42)、
0x5b985e、0x5bf47e、0x5c0ccc、0x5c3320、0x5c4c0a、0x5c63d8、0x5c6fae 待转写。

## TerminalWidget 命令(共用 sendEditor 命令空间)

TerminalWidget 槽体同样经 FUN_005b5d68 分发,新增 WT 段命令:
0x75dd(promptPosition) 0x75de(promptLine) 0x75df(scrollbackLines)
0x75e2(isUnconnected) 0x75f9(caretVirtualSpace)。
槽体 case 表:tools/re/data/terminalwidget_cases.json(72 项)。
非命令槽走会话栈守卫(+0x1f0/+0x1f8)直调 Screen 层 0x7e33xx 簇
(clearScreen/clearScrollback/resetHard 等)。
