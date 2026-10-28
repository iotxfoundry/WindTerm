# TextEdit 命令分派表(metacall 0x8f267a,66 槽)

同 TextView 架构:方法体经 sendEditor(FUN_005b5d68)转发。

| # | 方法 | 实现 VA | 命令 | 段 | SCI 名 |
|---|---|---|---|---|---|
| 0 | cancelSnippet() | 0x5cac40 | 0x75ba | WT |  |
| 1 | canExpandSnippet() | 0x5cacb6 | 0x75bb | WT |  |
| 2 | canSelectSnippetStop(cancelSnippet) | 0x5cad46 | 0x75bc | WT |  |
| 3 | comment() | 0x5cade2 | 0x4e4b | EXT |  |
| 4 | convertSpaceToTab() | 0x5cae58 | 0x4ee5 | EXT |  |
| 5 | convertTabToSpace() | 0x5caece | 0x4ee6 | EXT |  |
| 6 | cut() | 0x5cafba | 0x881 | SCI | SCI_CUT |
| 7 | decreaseLineIndent(canSelectSnippetStop) | 0x5cb030 | 0x4e2f | EXT |  |
| 8 | decreaseLineIndent() | 0x5cb030 | 0x4e2f | EXT |  |
| 9 | deleteBack() | 0x5cb0b2 | 0x916 | SCI | SCI_DELETEBACK |
| 10 | deleteChar() | 0x5cb128 | 0x884 | SCI | SCI_CLEAR |
| 11 | deleteLine() | 0x5cb19e | 0x4ed9 | EXT |  |
| 12 | deleteLineToEnd() | 0x5cb214 | 0x4edb | EXT |  |
| 13 | deleteLineToStart() | 0x5cb28a | 0x4eda | EXT |  |
| 14 | deleteWord() | 0x5cb300 | 0x4edc | EXT |  |
| 15 | deleteWordToEnd() | 0x5cb376 | 0x4ede | EXT |  |
| 16 | deleteWordToStart() | 0x5cb3ec | 0x4edd | EXT |  |
| 17 | duplicate() | 0x5cb462 | 0x9a5 | EXT | SCI_SELECTIONDUPLICATE |
| 18 | expandSnippet(deleteBack) | 0x5cb54e | 0x75bd | WT |  |
| 19 | expandSnippet() | 0x5cb54e | 0x75bd | WT |  |
| 20 | formatSelection() | 0x5cb662 | 0x4e26 | EXT |  |
| 21 | increaseLineIndent(canSelectSnippetStop) | 0x5cb6d8 | 0x4e2e | EXT |  |
| 22 | increaseLineIndent() | 0x5cb6d8 | 0x4e2e | EXT |  |
| 23 | insert(canSelectSnippetStop,position) | 0x5cb7d4 | - | LOGIC | (真逻辑体) |
| 24 | insertData(canSelectSnippetStop,position) | 0x5cb75a | 0x7555 | WT |  |
| 25 | isSnippetMode() | 0x5cba16 | 0x75bf | WT |  |
| 26 | isTextMultiChangeEventEnabled() | 0x5cbaa6 | 0x757b | WT |  |
| 27 | makeInverseCase() | 0x5cbbc6 | 0x4e22 | EXT |  |
| 28 | makeLowerCase() | 0x5cbc3c | 0x924 | SCI | SCI_LOWERCASE |
| 29 | makeTitleCase() | 0x5cbcb2 | 0x4e21 | EXT |  |
| 30 | makeUpperCase() | 0x5cbd28 | 0x925 | SCI | SCI_UPPERCASE |
| 31 | newLine() | 0x5cbd9e | 0x919 | SCI | SCI_NEWLINE |
| 32 | redo(?) | 0x5cbe14 | 0x7db | SCI | SCI_REDO |
| 33 | redo() | 0x5cbe14 | 0x7db | SCI | SCI_REDO |
| 34 | redoList() | 0x5cc4d4 | - | LOGIC | (真逻辑体) |
| 35 | removeDuplicateLines(?) | 0x5cc94e | - | LOGIC | (真逻辑体) |
| 36 | replace(canSelectSnippetStop,decreaseLineIndent,end) | 0x5cc7f6 | - | LOGIC | (真逻辑体) |
| 37 | replaceData(canSelectSnippetStop,deleteBack,end) | 0x5cc6f0 | 0x7557 | WT |  |
| 38 | reverseLines() | 0x5d0a4e | - | LOGIC | (真逻辑体) |
| 39 | selectSnippetStop(cancelSnippet) | 0x5cbf24 | 0x75c0 | WT |  |
| 40 | selectSnippetStop() | 0x5cbf24 | 0x75c0 | WT |  |
| 41 | setTextMultiChangeEventEnabled(cancelSnippet) | 0x5cc026 | 0x757c | WT |  |
| 42 | setUndoEnabled(cancelSnippet) | 0x5cc0ac | - | LOGIC | (真逻辑体) |
| 43 | shuffleLines() | 0x5cebe6 | - | LOGIC | (真逻辑体) |
| 44 | sortLines(?) | 0x5d28b6 | - | LOGIC | (真逻辑体) |
| 45 | tabify() | 0x5cc0b6 | 0x4ee3 | EXT |  |
| 46 | transposeChar(?) | 0x5cc188 | 0x4ed6 | EXT |  |
| 47 | transposeChar() | 0x5cc188 | 0x4ed6 | EXT |  |
| 48 | transposeWord(?) | 0x5cc20a | 0x4ed7 | EXT |  |
| 49 | transposeWord() | 0x5cc20a | 0x4ed7 | EXT |  |
| 50 | transposeLine(?) | 0x5cc28c | 0x4ed8 | EXT |  |
| 51 | transposeLine() | 0x5cc28c | 0x4ed8 | EXT |  |
| 52 | trim(canSelectSnippetStop,startLine) | 0x5cc406 | - | LOGIC | (真逻辑体) |
| 53 | trim(canSelectSnippetStop) | 0x5cc406 | - | LOGIC | (真逻辑体) |
| 54 | trim() | 0x5cc406 | - | LOGIC | (真逻辑体) |
| 55 | trimLeading(canSelectSnippetStop,startLine) | 0x5cc30e | 0x4e37 | EXT |  |
| 56 | trimLeading(canSelectSnippetStop) | 0x5cc30e | 0x4e37 | EXT |  |
| 57 | trimLeading() | 0x5cc30e | 0x4e37 | EXT |  |
| 58 | trimTrailing(canSelectSnippetStop,startLine) | 0x5cc38a | - | LOGIC | (真逻辑体) |
| 59 | trimTrailing(canSelectSnippetStop) | 0x5cc38a | - | LOGIC | (真逻辑体) |
| 60 | trimTrailing() | 0x5cc38a | - | LOGIC | (真逻辑体) |
| 61 | uncomment() | 0x5cc42a | 0x4e4c | EXT |  |
| 62 | undo(?) | 0x5cc4de | 0x880 | SCI | SCI_UNDO |
| 63 | undo() | 0x5cc4de | 0x880 | SCI | SCI_UNDO |
| 64 | undoList() | 0x5cc578 | - | LOGIC | (真逻辑体) |
| 65 | untabify() | 0x5cc61e | 0x4ee4 | EXT |  |

真逻辑体:0x5cb7d4、0x5cc4d4、0x5cc7f6、0x5cc0ac、0x5cc578、
0x5cc406(组合)、0x5cc94e、0x5cebe6、0x5d28b6、0x5d0a4e(31K 大件)。
