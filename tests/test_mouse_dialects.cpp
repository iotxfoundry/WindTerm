// 鼠标上报方言编码断言（0x7ebdfc mouse_xterm_seq_build 分支照搬，纯函数无 IO）：
// X10 默认 / UTF8(1005) / SGR(1006) / urxvt(1015) + 形态优先级 + 运动位 + clamp。
#include <QCoreApplication>
#include <cstdio>

#include "widgets/MouseEncode.h"

using MouseEncode::Dialect;
using MouseEncode::dialectFor;

static int g_failed = 0;
static void check(bool ok, const char *what)
{
    std::printf("%s %s\n", ok ? "PASS" : "FAIL", what);
    if (!ok)
        ++g_failed;
}

static QByteArray esc(const QByteArray &body)
{
    return "\x1b[" + body; // 调用侧统一补前缀（同现状 SGR 链）
}

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    // ── 形态优先级（0x7ebdfc 嵌套分支序：1006 > 1015 > 1005 > X10）──
    check(dialectFor(false, false, false) == Dialect::X10, "no ext modes → X10 default");
    check(dialectFor(true, false, false) == Dialect::Utf8, "1005 → UTF8");
    check(dialectFor(false, true, false) == Dialect::Sgr, "1006 → SGR");
    check(dialectFor(true, true, true) == Dialect::Sgr, "priority 1006 first");
    check(dialectFor(true, false, true) == Dialect::Urxvt, "priority 1015 over 1005");

    // ── SGR 基线（0x7ec253 '<%d;%d;%d%c'，与骨架 sendMouseEvent 现网格式一致）──
    check(esc(MouseEncode::body(Dialect::Sgr, 0, 4, 9, true))
              == QByteArray("\x1b[<0;10;5M"),
          "SGR press cb=0 x=4 y=9 → <0;10;5M (y;x 1-based, R37)");
    check(esc(MouseEncode::body(Dialect::Sgr, 35, 4, 9, false))
              == QByteArray("\x1b[<35;10;5m"),
          "SGR motion cb=35 → suffix 'm'");

    // ── X10（0x7ec5e7-0x7ec634 'M%c%c%c'：cb+0x20；坐标 +0x21 clamp 255；序 cb,y,x）──
    check(esc(MouseEncode::body(Dialect::X10, 0, 4, 9, true))
              == QByteArray("\x1b[M\x20\x2a\x25"),
          "X10 press: 0x20 cb / y+33=0x2a / x+33=0x25");
    check(esc(MouseEncode::body(Dialect::X10, 4, 4, 9, true))
              == QByteArray("\x1b[M\x24\x2a\x25"),
          "X10 Shift 修饰位入 cb 字节（+0x20 后 0x24）");
    check(esc(MouseEncode::body(Dialect::X10, 9, 400, 9, true))
              == QByteArray("\x1b[M\x29\x2a\xff"),
          "X10 coord clamp 0xff（cmp 0xfe 超界）");  // x=400→433 超界落 0xff；y=9→0x2a
    check(esc(MouseEncode::body(Dialect::X10, 0, 222, 9, true))
              == QByteArray("\x1b[M\x20\x2a\xff"),
          "X10 coord clamp: x=222 → 0x21+222=255 → 0xff");    check(esc(MouseEncode::body(Dialect::X10, 35, 4, 9, false))
              == QByteArray("\x1b[M\x43\x2a\x25"),
          "X10 motion: uVar14 已含运动位 +0x20，分支再 +0x20 → 0x43（原版行为照搬）");

    // ── UTF8(1005)（0x7ec3e3-0x7ec45e 'M%1%2%3' arg 链 toUtf8；无 clamp；序 cb,y,x）──
    check(esc(MouseEncode::body(Dialect::Utf8, 0, 4, 9, false))
              == QByteArray("\x1b[M\x20\x2a\x25"),
          "1005: %1=cb+0x20 %2=y+0x21 %3=x+0x21（ASCII 段，序同 SGR）");
    check(esc(MouseEncode::body(Dialect::Utf8, 0, 4, 210, false))
              == QByteArray("\x1b[M\x20\xc3\xb3\x25"),
          "1005 coord 243 (0xf3) → UTF-8 双字节 0xc3 0xb3");

    // ── urxvt(1015)（0x7ec707 '%d;%d;%dM'：cb+0x20、y+1、x+1 十进制）──
    check(esc(MouseEncode::body(Dialect::Urxvt, 0, 4, 9, false))
              == QByteArray("\x1b[32;10;5M"),
          "1015: 32;10;5M（cb+32 十进制，y;x 1-based）");
    check(esc(MouseEncode::body(Dialect::Urxvt, 3, 400, 9, false))
              == QByteArray("\x1b[35;10;401M"),
          "1015 no-button 3 +32 = 35");

    std::printf("TEST_MOUSE_DIALECTS %s (%d failures)\n",
                g_failed == 0 ? "PASSED" : "FAILED", g_failed);
    return g_failed == 0 ? 0 : 1;
}
