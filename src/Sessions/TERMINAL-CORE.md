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

## 待锚定

- [ ] 0x78 与 0x10 的具体类型(反编译其消费函数)
- [ ] cursorX 偏移(moveCursorForward 的实现会暴露)
- [ ] 滚区 top/bottom 成对偏移(setTopBottomMargins 实现)
- [ ] 与 TextView 层(0x5b5-0x5c6)的衔接点
