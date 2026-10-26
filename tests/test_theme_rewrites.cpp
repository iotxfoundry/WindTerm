// R17 类名→骨架树改写断言（ThemeManager::apply 文本层，B 项收敛）：
// MuxPaneGroup>TabGroup / ShellPane>TabGroup / MuxDesktop>TabGroup / 裸 TabGroup 后代规则。
#include <QApplication>
#include <cstdio>

#include "core/ThemeManager.h"

static int g_failed = 0;
static void check(bool ok, const char *what)
{
    std::printf("%s %s\n", ok ? "PASS" : "FAIL", what);
    if (!ok)
        ++g_failed;
}

int main(int argc, char *argv[])
{
    qputenv("QT_QPA_PLATFORM", "offscreen");
    QApplication app(argc, argv);

    if (!ThemeManager::instance().loadTheme(QStringLiteral("dige-white"))) {
        std::printf("SKIP: theme assets not found (run from build dir)\n");
        return 0;
    }
    ThemeManager::instance().apply();
    const QString qss = qApp->styleSheet();

    // gui.theme:686 `MuxPaneGroup > TabGroup > QTabBar[state = "Active"]::tab:selected`
    // → 标签行容器实挂 ViewGroup（0x008baf26）→ #ViewGroup 命中
    check(qss.contains(QStringLiteral("MuxPaneGroup > #ViewGroup > QTabBar")),
          "MuxPaneGroup > TabGroup → #ViewGroup (gui.theme:686)");
    // gui.theme:724 ShellPane 链同机制（骨架 ShellPane 暂无标签行,规则文本仍映射）
    check(qss.contains(QStringLiteral("ShellPane > #ViewGroup > QTabBar")),
          "ShellPane > TabGroup → #ViewGroup (gui.theme:724)");
    // gui.theme:676/679 `MuxDesktop > TabGroup > QTabBar::tab:selected`：骨架 MuxDesktop
    // 自持 QTabBar（无容器层）→ 中段剥除
    check(qss.contains(QStringLiteral("MuxDesktop > QTabBar")),
          "MuxDesktop > TabGroup → 容器剥除 (gui.theme:676)");
    check(!qss.contains(QStringLiteral("MuxDesktop > #ViewGroup")),
          "no bogus MuxDesktop > #ViewGroup chain");
    // gui.theme:751+ 裸后代规则
    check(qss.contains(QStringLiteral("#ViewGroup QToolButton")),
          "bare TabGroup descendant → #ViewGroup (gui.theme:751)");
    check(!qss.contains(QStringLiteral("TabGroup")), "no TabGroup token remains");

    std::printf("TEST_THEME_REWRITES %s (%d failures)\n",
                g_failed == 0 ? "PASSED" : "FAILED", g_failed);
    return g_failed == 0 ? 0 : 1;
}
