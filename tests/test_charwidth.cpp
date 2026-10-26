// 0x005f5450 utf8_decode_char_width 边界向量（深逆报告）+ 渲染级断言
#include <QCoreApplication>
#include "terminal/CharWidth.h"
#include "core/ScreenModel.h"
#include <cstdio>

static int g_failed = 0;
static void check(bool ok, const char *what)
{
    std::printf("%s %s\n", ok ? "PASS" : "FAIL", what);
    if (!ok)
        ++g_failed;
}
static void checkEq(int actual, int expected, const char *what)
{
    std::printf("%s U+%04X width=%d (expect %d) — %s\n",
                actual == expected ? "PASS" : "FAIL", expected, actual, expected, what);
    if (actual != expected)
        ++g_failed;
}

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    // ── 边界向量（来自深逆报告）──
    static const struct { uint cp; int w; const char *name; } cases[] = {
        {0x1100, 2, "Hangul Jamo"}, {0x115F, 2, ""}, {0x1160, 1, ""},
        {0x2329, 2, ""}, {0x232A, 2, ""}, {0x232B, 1, ""},
        {0x303F, 1, "IDEOGRAPHIC SPACE hole"},
        {0x2E80, 2, ""}, {0xA4CF, 2, ""}, {0xAC00, 2, "Hangul"},
        {0xD7A3, 2, ""}, {0x1F300, 2, ""}, {0x1F600, 2, ""},
        {0x1F64F, 2, ""}, {0x1F650, 1, ""}, {0x1F8FF, 1, ""},
        {0x1F900, 2, ""}, {0x1F9FF, 2, ""}, {0x1FA00, 1, ""},
        {0x20000, 2, "Ext-B"}, {0x2FFFD, 2, ""},
        {0x30000, 2, "Ext-G mask hit"}, {0x3FFFD, 2, "Ext-G mask hit"},
        {0xFF61, 1, "halfwidth"}, {0xFFE0, 2, ""}, {0xFFE7, 2, ""}, {0xFFE8, 1, ""},
        {'A', 1, "ASCII"}, {0x4E2D, 2, "CJK 中"}, {0xFE0F, 1, "VS16 自然窄"},
        {0x200D, 1, "ZWJ 自然窄"}, {0x1F3FB, 2, "肤色修饰终端层=2"},
    };
    for (const auto &c : cases) {
        const int w = CharWidth::widthOfChar(c.cp);
        std::printf("U+%05X -> %d %s\n", c.cp, w, c.name);
        checkEq(w, c.w, c.name);
    }

    // ── 渲染级：20 列屏 "中"×9 + 边界 ──
    {
        ScreenModel s(3, 20);
        QString text;
        for (int i = 0; i < 9; ++i)
            text += QChar(0x4E2D);
        s.printText(text);
        check(s.cursorX() == 18, "9 wide chars -> cursor col 18");
        s.printText(QStringLiteral("AB")); // 18+1='A' 后 B 在 19，换行由下一宽字符触发
        check(s.cursorX() == 20 && s.cursorY() == 0, "col 19 'B' -> deferred wrap (cursor 20)");
        s.printText(QString(QChar(0x4E2D))); // 行尾放不下→整体换行
        check(s.cursorX() == 2 && s.cursorY() == 1, "wide char at col19 wraps whole to next line col2");
    }
    {
        // 宽字符占 2 cell：第二 cell continuation
        ScreenModel s(3, 20);
        s.printText(QString(QChar(0x4E2D)));
        const Cell &c0 = s.cellAt(0, 0);
        const Cell &c1 = s.cellAt(0, 1);
        check(c0.ch == QChar(0x4E2D) && !c0.wideCont, "cell0 holds wide char");
        check(c1.wideCont, "cell1 continuation flag");
        // 擦除不拆半：erase-to-end 落在 continuation 格→起点前移清主格
        s.moveCursor('G', 2);
        s.erase('K', 0);
        check(s.cellAt(0, 0).ch == QChar(0x4E2D), "erase from cont cell keeps main cell");
        check(s.cellAt(0, 1).ch == QLatin1Char(' ') && !s.cellAt(0, 1).wideCont,
              "cont cell blanked");
        // 擦除落主格→continuation 一并清
        s.printText(QStringLiteral("中"));
        s.moveCursor('G', 3);
        s.erase('K', 0);
        check(s.cellAt(0, 2).ch == QLatin1Char(' ') && !s.cellAt(0, 2).wideCont
              && s.cellAt(0, 3).ch == QLatin1Char(' ') && !s.cellAt(0, 3).wideCont,
              "erase main cell clears continuation");
    }
    {
        // 选中列计算不拆半：宽字符主格选中→continuation 同色层（占位断言：两格均含非空属性）
        ScreenModel s(3, 20);
        s.printText(QString(QChar(0x4E0D)));
        const Cell &c0 = s.cellAt(0, 0);
        const Cell &c1 = s.cellAt(0, 1);
        check(c0.ch == QChar(0x4E0D) && c1.wideCont && c1.bg == c0.bg,
              "selection/erase width-2 occupancy both cells");
    }
    std::printf("TEST_CHARWIDTH %s (%d failures)\n",
                g_failed == 0 ? "PASSED" : "FAILED", g_failed);
    return g_failed == 0 ? 0 : 1;
}
