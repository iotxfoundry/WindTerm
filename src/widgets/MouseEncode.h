#pragma once

#include <QByteArray>

// 原版鼠标上报 X10/UTF8(1005)/SGR(1006)/urxvt(1015) 四形态编码器（0x7ebdfc
// mouse_xterm_seq_build 逐分支照搬；反编译 reference/full/decomp-part-0025.c:22573）。
// 语义（全部出自 0x7ebdfc，分支机器码地址见 .cpp 注释）：
//   cb 完整按钮字节=btn(0/1/2/无键3)|mods Shift4/Meta8/Ctrl16|运动+32|滚轮64/65
//   （调用侧已按位级规则算好——R37）；坐标 x/y 0 基。
//   形态优先级（0x7ebdfc 嵌套分支序）：1006 > 1015 > 1005 > X10(默认)。
//   序列体不含 ESC[ 前缀（调用侧统一补 "\x1b["，同 SGR 现状）。
namespace MouseEncode {

enum class Dialect { X10, Utf8, Sgr, Urxvt };

// DECSET 模式 → 编码形态（分支嵌套序）。m1005/m1006/m1015=screen->mode(...)，
// 对应原版视图对象字段 +0x143/+0x144/+0x145（分支语义=各 DEC 编码定义，唯一推断步
// 是字段↔DEC 号对应——0x144 分支吐 '<…M/m'=SGR=1006 已由 Tmux.cpp mouse_sgr_flag 侧证）
inline Dialect dialectFor(bool m1005, bool m1006, bool m1015)
{
    if (m1006)
        return Dialect::Sgr;
    if (m1015)
        return Dialect::Urxvt;
    if (m1005)
        return Dialect::Utf8;
    return Dialect::X10;
}

// 序列体。sgrSuffixM 仅 SGR 消费（press/dblclick/wheel='M'，release/motion='m'——
// 0x7ebdfc uVar15 判定）；其余形态无后缀分岔，形参忽略。
QByteArray body(Dialect dialect, int cb, int x, int y, bool sgrSuffixM);

} // namespace MouseEncode
