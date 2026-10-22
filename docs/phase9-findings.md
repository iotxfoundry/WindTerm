# Phase 9 发现 — 原版终端仿真器操作表完整提取（F2 权威规格）

日期：2026-10-22 · 方法：XTerm 操作名格式串 → lea 反查 → FUN_007ce254 注册函数反编译（REA 已 close）

## 1. 定位链

`"XTerm Set Window Attributes {}"` 等格式串 → 0x7f07d8/0x7f24ae/0x7f298e（窗口操作执行层，含 QColor::rgba / "4;%d;%d" 应答）→ 同区域操作注册函数 **FUN_007ce254**（0x7ce254–0x7cf016，52KB，QHash 操作表构建）。

## 2. 原版 VT 操作全表（53 项，名称→实现地址）

MoveCursor 系（14）：Up/Down/Forward/Backward/NextLine/PrecedingLine/NextTabstop/PrecedingTabstop/Column(+Backward/Relative)/Line(+Backward/Relative)/PagePositionAbsolute/Backward/Relative
Erase 系（8）：Screen/Line/Character/SelectiveLine/SelectiveScreen/RectangularArea/SelectiveRectangularArea
Insert/Delete（6）：InsertLine/DeleteLine/InsertCharacter/DeleteCharacter/InsertColumn/DeleteColumn
Scroll（6）：Up/Down/Left/Right/ScrollCursorUp/ScrollCursorDown/ScrollNextLine
Mode（8）：SetMode/ResetMode/RequestMode/SetDecMode/ResetDecMode/RequestDecMode/SaveDecMode/RestoreDecMode
SGR：SelectGraphicRendition
光标：SaveCursor/RestoreCursor
其它：RepeatCharacter(REP)/NotifyCommand/ClearTabstop/BackIndex/ForwardIndex

## 3. 处理器架构（样例 EraseScreen @0x7c9ae8 反编译）

```
handler(args) {
  n = parseParam(args, default=0);        // FUN_00646088 参数解析
  screenModel->eraseTo(n);                // FUN_007c8c68 屏幕模型方法
}
```
即 **parser → 参数提取 → 屏幕模型方法** 三段式；屏幕模型（TermBuffer 类）承载格子/光标/滚动区。

## 4. F2 实施规格（替代原"猜测最小子集"）

按上表**逐操作实现**，分两批：
- 批1（日常 shell 必需）：MoveCursor 系全部、EraseScreen/Line、InsertLine/DeleteLine、ScrollUp/Down、SelectGraphicRendition、Save/RestoreCursor、SetMode/ResetMode(常用 DEC: 25 光标/1049 altscreen/2004 bracketed paste)、RepeatCharacter
- 批2（按需）：矩形擦除/列插删/Tabstop 系/Selective 变体/NotifyCommand —— 先留枚举与桩
- 屏幕模型：格子数组（cells: [ch, fg, bg, flags]）+ 光标 + 滚动区 + scrollback；渲染从 HTML 追加改为**全量重绘**模型（这是与 F1 临时方案的架构分界）
- 解析器：CSI 私有标记 ? $ ! ' 的参数处理；OSC 吞掉；DCF 忽略

## 5. 边界

- 键盘编码（"CSI 27;<mod>;<char>~"）属输入层，F2 二批
- 双向编码/Termcap 查询（XTerm Set/Request Termcap）仅记录
