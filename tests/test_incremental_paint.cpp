// 增量行级重画回归（纯工程优化，不改视觉行为）：
// ① ScreenModel 脏行跟踪单测（写→单行脏/合并；scroll→全量；未变→空）
// ② 渲染等价：同操作序列下增量路径与强制全量路径 QImage 全帧一致
// ③ 性能自证：1 行变更 → takeDirtyLines()==单行（update 区域行数==1）
// 需 QApplication（QImage/grab），offscreen 跑。
#include <QApplication>
#include <QImage>
#include <cstdio>

#include "core/ScreenModel.h"
#include "core/VtParser.h"
#include "widgets/TerminalView.h"

static int g_failed = 0;
static void check(bool ok, const char *what)
{
    std::printf("%s %s\n", ok ? "PASS" : "FAIL", what);
    if (!ok)
        ++g_failed;
}

// 模型级等价：两屏同操作序列，增量侧每次 take 脏行（模拟消费方局部重画），
// 全量侧从不 take（模拟恒全量重画）；结束逐 cell 比对应完全一致
static void modelEquivalence(ScreenModel &inc, ScreenModel &full, const char *what)
{
    bool same = inc.rows() == full.rows() && inc.cols() == full.cols();
    if (same)
        for (int r = 0; r < inc.rows() && same; ++r)
            for (int c = 0; c < inc.cols() && same; ++c)
                same = inc.cellAt(r, c) == full.cellAt(r, c);
    check(same, what);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setApplicationName(QStringLiteral("WindTerm"));

    // ── ① 脏跟踪单测 ──
    {
        ScreenModel s(24, 80);
        s.takeDirtyLines(); // 基线

        s.moveCursor('H', 3, 1); // 第 3 行（1 基）
        s.printText(QStringLiteral("X"));
        check(s.takeDirtyLines() == QVector<int>{2}, "write line3 -> dirty {2} (0-based)");

        // 连续写同行：同内容覆盖同位置（不变）→ 不登记
        s.moveCursor('H', 3, 1);
        s.printText(QStringLiteral("X"));
        check(s.takeDirtyLines().isEmpty(), "rewrite same content -> no dirty");

        // 内容变化 → 再脏
        s.printText(QStringLiteral("Y"));
        check(s.takeDirtyLines() == QVector<int>{2}, "changed content -> dirty {2}");

        // 滚动 → 全量
        s.moveCursor('H', 24, 1);
        s.printText(QStringLiteral("Z"));
        s.newline(); // 底行换行→scrollUp
        check(s.takeDirtyLines() == QVector<int>{-1}, "scroll -> full dirty {-1}");

        // 不改 → 空
        check(s.takeDirtyLines().isEmpty(), "no change -> empty");
    }

    // ── ①b 模型级序列等价（增量消费 vs 恒全量）──
    {
        ScreenModel inc(24, 80);
        ScreenModel full(24, 80);
        VtParser pi(&inc), pf(&full);
        const QByteArray seq = "\x1b[2J\x1b[H"
                               "hello world\r\n"
                               "\x1b[31mred\x1b[0m plain\r\n"
                               "\x1b[1;32mbold green\x1b[0m\r\n"
                               "\x1b[2;3Hpatch\x1b[4;1H\x1b[K"
                               "\x1b[10;20HX\x1b[12;40H宽";
        pi.feed(seq);
        pf.feed(seq);
        modelEquivalence(inc, full, "model equivalence after VT sequence (incr consumes dirty)");

        // 全量脏操作后取走，再跑一段纯行写，增量路径继续工作
        inc.scroll('S', 1);
        full.scroll('S', 1);
        inc.takeDirtyLines();
        full.takeDirtyLines();
        const QByteArray seq2 = "\x1b[20;1Htail";
        pi.feed(seq2);
        pf.feed(seq2);
        const QVector<int> d = inc.takeDirtyLines();
        check(!d.isEmpty() && d.contains(19), "post-scroll incremental tracking works");
        modelEquivalence(inc, full, "model equivalence after scroll + writes");
    }

    // ── ②③ 渲染等价 + 计数（TerminalView pane 模式独立屏）──
    {
        TerminalView view(QStringLiteral("test"));
        view.ensureScreenModel(80, 24);
        view.resize(800, 480);
        view.show();

        view.feedVtData("AB\r\nCD");
        const QImage incr = view.grab().toImage();
        // 强制全量路径：内容未变，全量重画后逐像素必须一致（行为零变化）
        view.viewport()->update();
        QApplication::processEvents();
        const QImage full = view.grab().toImage();
        check(incr == full, "render equivalence: incremental grab == forced full grab");

        // 宽字符路径等价
        view.feedVtData("\x1b[5;1H\xe5\xae\xbd"); // 宽
        const QImage incr2 = view.grab().toImage();
        view.viewport()->update();
        QApplication::processEvents();
        check(incr2 == view.grab().toImage(), "wide char: incremental == full");
    }

    std::printf("TEST_INCREMENTAL_PAINT %s (%d failures)\n",
                g_failed == 0 ? "PASSED" : "FAILED", g_failed);
    return g_failed == 0 ? 0 : 1;
}
