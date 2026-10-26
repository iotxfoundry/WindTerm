// P4 终端搜索/高亮回归（offscreen + LocalSession bash 输出已知文本→断言 find/高亮链）：
// 1) SearchPane 选项钮 7 个  2) findNext("aaa") 选中第一处  3) 再 findNext 到第二处
// 4) findPrevious 回第一处  5) 未命中→状态栏消息含"未找到"  6) setHighlightRange 后
// grab 存在 Royalblue 系像素  7) HighlightTextBar 8 按钮存在+点击 Red 后选区高亮
#include <QApplication>
#include <QComboBox>
#include <QFile>
#include <QImage>
#include <QLineEdit>
#include <QPushButton>
#include <QStackedWidget>
#include <QTemporaryDir>
#include <QTimer>
#include <QToolButton>

#include "core/Assets.h"
#include "core/LocalSession.h"
#include "core/SchemeManager.h"
#include "core/Session.h"
#include "core/ThemeManager.h"
#include "core/WindConfig.h"
#include "panes/SearchPane.h"
#include "widgets/HighlightTextBar.h"
#include "widgets/TerminalView.h"

static int failed = 0;
static void check(bool ok, const char *what)
{
    std::printf("%s: %s\n", ok ? "PASS" : "FAIL", what);
    if (!ok)
        ++failed;
}

// 高亮像素断言：40% alpha 叠加深色底后主通道仍占优（Royalblue/Red 混色后非纯色）
static bool hasDominantChannel(const QImage &img, int channel) // 0=R 1=G 2=B
{
    for (int y = 0; y < img.height(); ++y)
        for (int x = 0; x < img.width(); ++x) {
            const QRgb px = img.pixel(x, y);
            const int c[3] = { qRed(px), qGreen(px), qBlue(px) };
            if (c[channel] > 90 && c[channel] > 2 * c[(channel + 1) % 3]
                && c[channel] > 2 * c[(channel + 2) % 3])
                return true;
        }
    return false;
}

int main(int argc, char *argv[])
{
    if (!QFile::exists(QStringLiteral("/bin/bash"))) {
        std::printf("SKIP: /bin/bash not available\n");
        return 0;
    }
    QApplication app(argc, argv);
    QApplication::setApplicationName(QStringLiteral("WindTerm"));

    WindConfig::instance().load(Assets::dir() + QStringLiteral("/config/wind.config"));
    ThemeManager::instance().loadTheme(
        WindConfig::instance().valueToString(QStringLiteral("application.themeGui"), QStringLiteral("dige-black")));
    ThemeManager::instance().apply();
    SchemeManager::instance().load();

    // ── 1) SearchPane 选项钮 7 个 ──
    SearchPane pane;
    const QList<QPushButton *> options = pane.findChildren<QPushButton *>();
    check(options.size() == 7, "SearchPane has 7 option buttons");
    bool allCheckable = options.size() == 7;
    for (QPushButton *b : options)
        allCheckable = allCheckable && b->isCheckable() && !b->text().isEmpty();
    check(allCheckable, "option buttons all checkable+named (0x74d90c table)");

    // ── TerminalView + bash 已知文本 ──
    auto *view = new TerminalView(QStringLiteral("test"));
    view->resize(600, 400);
    auto *session = new LocalSession(24, 80, view);
    check(session->start(), "local session started");
    view->attachSession(session);
    view->show();

    QString allOutput;
    QObject::connect(session, &Session::output, [&allOutput](const QByteArray &d) {
        allOutput += QString::fromUtf8(d);
    });

    // 状态栏消息捕获（showMessageEx 链——测试注入 handler 计数）
    static QString lastMessage;
    static int messageCount = 0;
    TerminalView::statusMessageHandler = [](TerminalView *, const QString &text, int) {
        lastMessage = text;
        ++messageCount;
    };

    auto *timer = new QTimer(view);
    timer->setInterval(700);
    int step = 0;
    QPoint firstSelCell; // 第一处命中（case2 记录，case3/4 复用）
    QObject::connect(timer, &QTimer::timeout, [&]() {
        switch (step++) {
        case 0:
            session->write("echo aaa bbb aaa\n");
            break;
        case 1: {
            // 输出齐了：两行 aaa（echo 命令回显行 + 输出行）
            const int aaaCount = allOutput.count(QLatin1String("aaa"));
            std::printf("  output aaa occurrences: %d\n", aaaCount);
            check(aaaCount >= 2, "bash echoed known text (aaa...bbb...aaa)");

            // ── 2) findNext("aaa") 选中第一处 ──
            view->setFindPattern(QStringLiteral("aaa"));
            view->setFindOptions({ false, false, false, true, false });
            view->findNext(false);
            check(view->hasSel() && view->selectionText() == QStringLiteral("aaa"),
                  "findNext selects first 'aaa' (selection text == aaa)");
            firstSelCell = view->selectionAnchor();
            break;
        }
        case 2: {
            // ── 3) 再 findNext 到第二处（选区位置变化）──
            const QPoint firstSel = view->selectionAnchor();
            view->findNext(false);
            check(view->hasSel() && view->selectionText() == QStringLiteral("aaa"),
                  "second findNext still selects 'aaa'");
            check(view->selectionAnchor() != firstSel, "selection moved to second occurrence");
            break;
        }
        case 3: {
            // ── 4) findPrevious 回第一处 ──
            const QPoint secondSel = view->selectionAnchor();
            view->findPrevious(false);
            check(view->selectionAnchor() != secondSel, "findPrevious moved back");
            check(view->selectionAnchor() == firstSelCell, "findPrevious back to first cell");
            break;
        }
        case 4: {
            // ── 5) 未命中→状态栏消息含"未找到" ──
            view->setFindPattern(QStringLiteral("zzznotfound"));
            view->findNext(false);
            check(lastMessage.contains(QStringLiteral("未找到")),
                  "no-match posts '未找到' status message");
            // ── 6) setHighlightRange → Royalblue 像素 ──
            view->setFindPattern(QStringLiteral("aaa"));
            // 全局位置=line*10000+col：第一处 [col, col+2]
            view->setHighlightRange(firstSelCell.y() * 10000 + firstSelCell.x(),
                                    firstSelCell.y() * 10000 + firstSelCell.x() + 2,
                                    QStringLiteral("Royalblue"));
            const QImage img = view->grab().toImage();
            img.save(QStringLiteral("test_search_highlight_step4.png"));
            check(hasDominantChannel(img, 2), "highlight paint shows Royalblue-dominant pixels");
            break;
        }
        case 5: {
            // ── 7) HighlightTextBar 8 按钮 + 点击 Red 高亮选区 ──
            HighlightTextBar barAction;
            QWidget *row = barAction.createWidgetForTest(nullptr);
            const QList<QPushButton *> colorButtons = row->findChildren<QPushButton *>();
            check(colorButtons.size() == 8, "HighlightTextBar creates 8 color buttons");
            // 先造选区：选中第二处 aaa（用 findNext 两次）
            view->setFindPattern(QStringLiteral("aaa"));
            view->findNext(false);
            view->findNext(false);
            check(view->hasSel(), "selection present before highlight click");
            const int spansBefore = view->highlightCount();
            // 点 Red 按钮（第 2 个=第 1 个命名色）
            if (colorButtons.size() >= 2) {
                colorButtons.at(1)->setChecked(true);
                for (int i = 0; i < 3; ++i)
                    QApplication::processEvents();
                check(view->highlightCount() > spansBefore, "Red click adds highlight span");
                const QImage img = view->grab().toImage();
                check(hasDominantChannel(img, 0), "highlight paint shows Red-dominant pixels");
            }
            delete row;
            timer->stop();
            session->close();
            QApplication::quit();
            break;
        }
        default:
            break;
        }
    });
    timer->start();

    app.exec();
    delete view;

    std::printf("TEST_SEARCH_HIGHLIGHT %s (%d failures)\n", failed == 0 ? "PASSED" : "FAILED", failed);
    return failed == 0 ? 0 : 1;
}
