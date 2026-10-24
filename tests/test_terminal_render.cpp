// TerminalView 自绘网格回归（原 /tmp/opencode/tvtest/tvtest.cpp）：
// offscreen + TerminalView + LocalSession(bash) → grab() 像素断言。bash 缺则 SKIP。
#include <QApplication>
#include <QFile>
#include <QImage>
#include <QRegularExpression>
#include <QTimer>
#include <cstdio>

#include "core/Assets.h"
#include "core/LocalSession.h"
#include "core/SchemeManager.h"
#include "core/ThemeManager.h"
#include "core/WindConfig.h"
#include "widgets/TerminalView.h"

static int g_failures = 0;
static void check(bool ok, const char *what)
{
    printf("%s: %s\n", ok ? "PASS" : "FAIL", what);
    if (!ok)
        ++g_failures;
}

// 像素断言：图中存在与 target RGB 欧氏距离 < tol 的像素
static bool hasPixelNear(const QImage &img, const QColor &target, int tol)
{
    const int tr = target.red(), tg = target.green(), tb = target.blue();
    for (int y = 0; y < img.height(); ++y)
        for (int x = 0; x < img.width(); ++x) {
            const QRgb px = img.pixel(x, y);
            const int dr = qRed(px) - tr, dg = qGreen(px) - tg, db = qBlue(px) - tb;
            if (dr * dr + dg * dg + db * db < tol * tol)
                return true;
        }
    return false;
}

// vim 波浪行：左缘窄条内多行亮色 glyph（~ 打在 col 0）
static int leftGlyphBands(const QImage &img)
{
    int bands = 0;
    const int bandH = 12;
    for (int y0 = 8; y0 + bandH < img.height() - 8; y0 += bandH) {
        bool lit = false;
        for (int y = y0; y < y0 + bandH && !lit; ++y)
            for (int x = 0; x < 30 && !lit; ++x) {
                const QRgb px = img.pixel(x, y);
                if (qGray(px) > 0x60)
                    lit = true;
            }
        bands += lit;
    }
    return bands;
}

int main(int argc, char *argv[])
{
    if (!QFile::exists(QStringLiteral("/bin/bash"))) {
        printf("SKIP: /bin/bash not available\n");
        return 0;
    }
    QApplication app(argc, argv);
    QApplication::setApplicationName(QStringLiteral("WindTerm"));

    // 与主程序相同的资源加载次序（Assets::dir 依赖 CWD=build 目录或 bin/../assets）
    WindConfig::instance().load(Assets::dir() + QStringLiteral("/config/wind.config"));
    ThemeManager::instance().loadTheme(
        WindConfig::instance().valueToString(QStringLiteral("application.themeGui"), QStringLiteral("dige-black")));
    ThemeManager::instance().apply();
    SchemeManager::instance().load();

    TerminalView *view = new TerminalView(QStringLiteral("test"));
    view->resize(1000, 800);

    // 应用流次序：session start 先于 attach（MuxPaneGroup::addPane 前 MainWindow 已 start）
    auto *session = new LocalSession(24, 80, view);
    check(session->start(), "local session started");
    view->attachSession(session);
    view->show();

    QString allOutput;
    QObject::connect(session, &Session::output, [&allOutput](const QByteArray &d) {
        allOutput += QString::fromUtf8(d);
    });

    auto step = new int(0);
    QTimer *timer = new QTimer(view);
    timer->setInterval(900);
    QObject::connect(timer, &QTimer::timeout, [&, timer, step]() {
        switch ((*step)++) {
        case 0: {
            // 断言 3：resize 协商——view 1000x800 → pty rows/cols 为新尺寸
            session->write("stty size\n");
            break;
        }
        case 1: {
            // stty 输出 = 最后一个 "rows cols" 行
            QRegularExpression re(QStringLiteral("(?:^|\r|\n)\\s*(\\d+)\\s+(\\d+)\\s*(?:\r|\n|$)"));
            QRegularExpressionMatch m;
            auto it = re.globalMatch(allOutput);
            while (it.hasNext())
                m = it.next();
            const int rows = m.captured(1).toInt();
            const int cols = m.captured(2).toInt();
            printf("stty size: %d x %d (view reports %d x %d)\n", rows, cols,
                   view->windowRows(), view->windowColumns());
            check(rows > 24 && cols > 80, "resize negotiated: stty rows>24 cols>80");
            check(rows == view->windowRows() && cols == view->windowColumns(),
                  "stty matches view cell math");

            session->write("printf '\\e[31mRED\\e[0m \\e[1;32mBOLDGREEN\\e[0m done\\n'\n");
            break;
        }
        case 2: {
            const QImage img = view->grab().toImage();
            img.save(QStringLiteral("test_render_step2.png"));
            // dige-black scheme：ansiRed=#C4265E，bold+green 自动 bright=#A6E22E
            check(hasPixelNear(img, QColor(QStringLiteral("#C4265E")), 40), "RED pixels present");
            check(hasPixelNear(img, QColor(QStringLiteral("#A6E22E")), 40), "BOLDGREEN pixels present");
            session->write("vim -u NONE /etc/hostname\n");
            break;
        }
        case 3: {
            const QImage img = view->grab().toImage();
            img.save(QStringLiteral("test_render_step3.png"));
            check(leftGlyphBands(img) >= 5, "vim tilde rows rendered in left gutter");
            session->write("ZZ");
            break;
        }
        case 4: {
            const QImage img = view->grab().toImage();
            img.save(QStringLiteral("test_render_step4.png"));
            // alt 屏退出恢复主屏：printf 的 RED/BOLDGREEN 内容回来
            check(hasPixelNear(img, QColor(QStringLiteral("#C4265E")), 40), "exit restores main screen (RED back)");
            break;
        }
        default:
            timer->stop();
            delete step;
            printf("TEST_TERMINAL_RENDER %s (%d failures)\n",
                   g_failures == 0 ? "PASSED" : "FAILED", g_failures);
            app.exit(g_failures == 0 ? 0 : 1);
        }
    });
    timer->start();

    return app.exec();
}
