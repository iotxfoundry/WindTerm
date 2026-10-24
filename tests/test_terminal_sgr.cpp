// colon 形式 38:5:n 归一 + 滚回上限 单测（原 /tmp/opencode/f2diag/sgrtest.cpp；纯函数无环境依赖）
#include <QCoreApplication>
#include "core/ScreenModel.h"
#include <cstdio>

static int g_failed = 0;
static void check(bool ok, const char *what)
{
    std::printf("%s %s\n", ok ? "PASS" : "FAIL", what);
    if (!ok)
        ++g_failed;
}
int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);
    {
        ScreenModel s(24, 80);
        s.selectGraphicRendition("38:5:196");
        s.printText("X");
        const QColor fg = s.cellAt(0, 0).fg;
        std::printf("colon 38:5:196 fg=%s\n", qPrintable(fg.name()));
        check(fg == QColor(255, 0, 0), "colon 38:5:196 -> color256(196)=#ff0000");
        s.carriageReturn();
        s.selectGraphicRendition("0");
        s.selectGraphicRendition("48:2:10:20:30");
        s.printText("Y");
        const QColor bg = s.cellAt(0, 0).bg;
        std::printf("colon 48:2 bg=%s (expect #0a141e)\n", qPrintable(bg.name()));
        check(bg == QColor(10, 20, 30), "colon 48:2:10:20:30 -> rgb(10,20,30)");
        s.carriageReturn();
        s.selectGraphicRendition("0");
        s.selectGraphicRendition("38;5:46");  // 混合形式也应工作
        s.printText("Z");
        const QColor mixed = s.cellAt(0, 0).fg;
        std::printf("mixed 38;5:46 fg=%s\n", qPrintable(mixed.name()));
        check(mixed == QColor(0, 255, 0), "mixed 38;5:46 -> color256(46)=#00ff00");
    }
    {
        ScreenModel s(24, 80, QColor("#e3e3dd"), QColor("#1c1c1c"), 5);  // 上限 5
        for (int i = 0; i < 40; ++i) { s.newline(); s.printText(QString(QChar('0' + i % 10))); }
        const int actual = s.scrollback().size();
        std::printf("scrollback limit=5 actual=%d (expect <=5)\n", actual);
        check(actual <= 5, "scrollback respects limit");
        check(actual == 5, "scrollback reaches limit 5");
    }
    std::printf("TEST_TERMINAL_SGR %s (%d failures)\n",
                g_failed == 0 ? "PASSED" : "FAILED", g_failed);
    return g_failed == 0 ? 0 : 1;
}
