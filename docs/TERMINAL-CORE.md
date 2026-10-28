# TerminalCore 结构体重建(进行中)

> 方法:SuperCommander VT 槽 → +0x80 → Screen 中层 → +0x80 → TerminalCore(0x7a4-0x7b3)。
> 偏移统计来自 20 个 TerminalCore 函数的批量反编译。

## 已确认成员(语义锚定)

| 偏移 | 证据 | 推断 |
|---|---|---|
| `+0x00` | bit6 (0x40) 参与 DECOM 滚区判定(VT100 语义) | 状态标志位域 |
| `+0x00` | `*param = 7` 重置写入(FUN_007a4b0a) | 复位默认值 |
| `+0x50/0x58/0x5c/0x66` | 重置函数清零/置 2 | 滚区/样式状态 |
| `+0x78` | **最热**(16 次引用/5 函数) | 屏幕 buffer 或渲染器指针 |
| `+0xc4` | `newY = this[0xc4] + n`(moveCursorDown) | **cursorY** ✅ |
| `+0xc8` | `cur = this[0xc8] + n`(moveCursorForward,列限钳制) | **cursorX** ✅ |
| `+0xd0` | `this[0xd0] = top`(setTopBottomMargins) | **scrollRegionTop** ✅ |
| `+0xd4` | `this[0xd4] = bottom` + `min(top, bottom-2)` 合法性钳制 | **scrollRegionBottom** ✅ |
| `+0xdc` | 4 次/2 函数 | 光标 X 或滚区底(与 getScrollBottom 相邻) |
| `+0x10` | 9 次/3 函数 | 文档/缓冲指针 |

## 调用链(已证)

```
SuperCommander::moveCursorDown(n)   0x7c8cc6   (参数包装,1 行)
  → Screen::moveCursorDown(+0x80)   0x7e483e   (1 行转发)
    → TerminalCore::moveCursorDown  0x7a5588   ★ 真逻辑(含 DECOM 钳制)
       cursorY(0xc4) += n; if (flags&0x40) clamp to scrollBottom;
       → moveCursorToY               0x7a5570
```

## 还原的原始实现(可直转 C++)

```cpp
// 0x7a54b4: X 方向前进(与 Y 完全同构 —— 该类用 X/Y 两套镜像成员)
void TerminalCore::cursorForward(int n) {
    if (n < 1) return;
    int newX = cursorX /*+0xc8*/ + n;
    if (flags /*+0x00*/ & 0x40) {            // DECOM 列限模式
        int right = columnLimit();            // FUN_007a490e
        if (cursorX <= right && right < newX) newX = right;
    }
    setCursorX(newX);                         // FUN_007a5452
}

// 0x7a4672: DECSTBM 滚动区设置(完整还原)
void TerminalCore::setTopBottomMargins(int top, int bottom) {
    scrollRegionTop    /*+0xd0*/ = top;
    scrollRegionBottom /*+0xd4*/ = bottom;
    if (bottom > 0)
        scrollRegionTop = min(top, bottom - 2);
}
```

## +0x78 定性完成(FUN_007a4332)

`+0x78` = **行对象指针数组**(屏幕行表),`+0x74` = 行数;每个 Row:
`+0xc` = 单元格数,`+0x10` = 单元格数组(步长 0x20 = 32 字节/格:
字符 + SGR 属性 + 标志),`+0x40` = 析构时释放的备用缓冲。
已落码:`TerminalCore.h/.cpp`(结构体 + 6 个已还原方法)。

## 待锚定

- [ ] `+0x2c/0x44/0x5c/0x66/0xdc` 等次级成员
- [ ] 与 TextView 层(0x5b5-0x5c6)的衔接点
- [ ] 通用规律:`每个 VT 命令 = 1 个 TerminalCore 函数写 1-2 个成员`,
      按 moveCursorDown/Forward/setMargins 的同构性即可批量还原
