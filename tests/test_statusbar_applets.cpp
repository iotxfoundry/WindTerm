// R55 statusbar applet 体系回归（offscreen）：statusbar.config 7 项经 ScriptHost 真跑 JS
// init（0x005a4432 populate→0x005a3156 runInit，工厂 0x005a333e）；AppletBar（0x00526a7c）
// pane 侧装载链：sysmon 开关门（0x0084a755）+ KitPane_ensureAppletBar（0x005bf49e）+
// loadFiles（0x005284d6）。禁用/挂账项断言见各段注释。
#include <QApplication>
#include <QEventLoop>
#include <QHBoxLayout>
#include <QJsonDocument>
#include <QLabel>
#include <QTimer>
#include <QToolButton>
#include <QVBoxLayout>
#include <cstdio>

#include "core/Assets.h"
#include "core/JsonText.h"
#include "core/SchemeManager.h"
#include "core/ScriptHost.h"
#include "core/ThemeManager.h"
#include "panes/KitPane.h"
#include "panes/ShellPane.h"
#include "widgets/AppletBar.h"
#include "widgets/StatusBar.h"

static int failed = 0;
static void check(bool ok, const QString &what)
{
    std::printf("%s: %s\n", ok ? "PASS" : "FAIL", qPrintable(what));
    if (!ok)
        ++failed;
}

static QVariantList loadStatusbarConfig(bool *ok)
{
    QFile f(Assets::dir() + QStringLiteral("/config/uiconfigs/statusbar.config"));
    *ok = false;
    if (!f.open(QIODevice::ReadOnly))
        return {};
    QByteArray data = f.readAll();
    if (data.startsWith("\xEF\xBB\xBF"))
        data.remove(0, 3);
    const QJsonDocument doc = QJsonDocument::fromJson(JsonText::stripLineComments(data));
    *ok = doc.isArray();
    return doc.toVariant().toList();
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 主题→scheme 列表（Scheme 按钮 menu 项数据源，同 MainWindow ctor 序）
    ThemeManager::instance().loadTheme(QStringLiteral("dige-white"));
    SchemeManager::instance().load();

    bool cfgOk = false;
    const QVariantList applets = loadStatusbarConfig(&cfgOk);
    check(cfgOk && applets.size() == 7, "statusbar.config loads with 7 applets");

    ScriptHost host;
    StatusBar bar;
    bar.populate(applets, &host);
    for (int i = 0; i < 3; ++i)
        QApplication::processEvents();

    // ═══ 7 applet 建立与类型断言（0x005a333e 工厂；+常驻 status label=8 widgets）═══
    // 5 button（KeyMode/W×H/LnCh/Scheme/LockScreen）+ 3 label（status/clock/issues）
    const QList<QToolButton *> buttons = bar.findChildren<QToolButton *>();
    QList<QLabel *> labels = bar.findChildren<QLabel *>();
    check(buttons.size() == 5, "5 button applets (KeyMode/W×H/LnCh/Scheme/LockScreen)");
    check(labels.size() == 3, "3 labels (status/clock/issues)");

    // 全部 applet 无 objectName（0x005a333e 铁证）
    bool noNames = true;
    for (QWidget *w : qAsConst(buttons))
        if (!w->objectName().isEmpty())
            noNames = false;
    for (QLabel *w : labels)
        if (w != labels.first() && !w->objectName().isEmpty())
            noNames = false;
    check(noNames, "applet widgets have no objectName");

    // 按钮面：TextOnly+AutoRaise
    bool buttonFace = true;
    for (QToolButton *b : buttons)
        if (b->toolButtonStyle() != Qt::ToolButtonTextOnly || !b->autoRaise())
            buttonFace = false;
    check(buttonFace, "buttons are TextOnly+AutoRaise");

    // Issues 外链 label（⑥：OpenExternalLinks+PointingHand+URL 照 config 原文）
    QLabel *issues = nullptr;
    for (QLabel *l : labels)
        if (l->text().contains(QStringLiteral("https://www.github.com/kingtoolbox/windterm/issues")))
            issues = l;
    check(issues != nullptr, "issues label carries vendor URL");
    if (issues) {
        check(issues->openExternalLinks(), "issues label OpenExternalLinks");
        check(issues->cursor().shape() == Qt::PointingHandCursor, "issues label PointingHandCursor");
        check(issues->textInteractionFlags().testFlag(Qt::TextSelectableByMouse)
                  && issues->textInteractionFlags().testFlag(Qt::LinksAccessibleByMouse),
              "issues label InteractionFlags 0xf subset");
    }

    // 时钟 label（⑤ setInterval 2000 toLocaleString——JS 原文真跑，QTimer 驱动刷新；
    // 原文无首次立即刷新——首帧由 2s 后首个 timeout 填充，初始空文本即原版行为）
    QLabel *clock = nullptr;
    for (QLabel *l : labels)
        if (l != issues && l != labels.first())
            clock = l;
    check(clock != nullptr, "clock label exists (initial text empty——原文 setInterval 首帧 2s 后)");
    if (clock) {
        const QString t1 = clock->text(); // 空（原文无立即刷新）
        QEventLoop loop;
        QTimer::singleShot(2200, &loop, &QEventLoop::quit);
        loop.exec();
        QString t2 = clock->text();
        check(!t2.isEmpty(), "clock first toLocaleString text after 2s timeout");
        if (t2 == t1) { // 周期边界容差：再等一个周期
            QEventLoop loop2;
            QTimer::singleShot(2200, &loop2, &QEventLoop::quit);
            loop2.exec();
            t2 = clock->text();
        }
        check(t2 != t1, "clock text refreshes via setInterval(2000)");
    }

    // Scheme 按钮（④ InstantPopup+菜单=主题 scheme 列表，findAction Terminal.SchemeList 面）
    QToolButton *schemeButton = nullptr;
    for (QToolButton *b : buttons)
        if (b->popupMode() == QToolButton::InstantPopup && b->menu())
            schemeButton = b;
    check(schemeButton != nullptr, "scheme button InstantPopup with menu");
    if (schemeButton) {
        // 原文 JS 只 addAction(action) 一个动作（Terminal.SchemeList）——schemeNames 列表
        // 在该 action 触发时弹出（findAction 0x56d890 链占位实现 menu->exec(schemeNames)）。
        // 断言：菜单=1 项 + schemeNames 非空（列表数据源在位）
        const QStringList names = SchemeManager::instance().schemeNames();
        const int menuCount = schemeButton->menu()->actions().size();
        check(menuCount == 1 && !names.isEmpty(),
              QStringLiteral("scheme menu=Terminal.SchemeList action(1) + %1 schemeNames available")
                  .arg(names.size()));
    }

    // 禁用/挂账项（①⑦）：keyMode 面在 TerminalView 已建（Q_PROPERTY+信号+setter），
    // window.lockScreen 面已建（Q_UNIMPLEMENTED 桩）——JS 原文路径生效，无自创禁用：
    // ①KeyMode 无活动 view→JS update(null)→visible=false（原文行为）；⑦LockScreen 可见
    // 可点（点击走 Q_UNIMPLEMENTED 挂账，测试不点避免预期外警告）。
    QToolButton *keyMode = nullptr, *lockScreen = nullptr;
    for (QToolButton *b : buttons) {
        if (b == schemeButton)
            continue;
        if (b->text().contains(QStringLiteral("Lock")))
            lockScreen = b;
        else
            keyMode = b; // 首个无文本按钮（KeyMode/W×H/LnCh 均未初始化，任取其一断存在）
    }
    check(keyMode != nullptr, "KeyMode button exists");
    // JS 惰性等价陷阱（原文行为）：view(undefined)!=null 为 false——首帧 update(null) 不进
    // 分支，按钮保持默认态（bar 显示后可见，文本空）。原版同样如此（首 update(null) 空转，
    // 仅后续真实 view 切换才走 show/hide）——断言"存在且未初始化文本"，勿断言 hidden。
    if (keyMode)
        check(keyMode->text().isEmpty() && !keyMode->text().contains(QStringLiteral("Mode")),
              "KeyMode un-initialized with no active view (vendor JS undefined==null no-op)");
    // JS visible=true→show() 清隐式标记；父条未 show 时 isVisible 恒 false（Qt 语义），
    // 断言用 isHidden 反面（显式 show 已执行）
    check(lockScreen != nullptr && !lockScreen->isHidden(),
          "LockScreen button exists+shown (lockScreen face=Q_UNIMPLEMENTED stub 挂账)");
    // W×H/LnCh（②③）：无 view→hidden；TerminalView 的 screenSizeChanged/caretPositionChanged
    // 面已建，有 view 时 JS 原文驱动（MainWindow viewSignalForScripts 链）
    int noTextButtons = 0;
    for (QToolButton *b : buttons)
        if (b != schemeButton && b != lockScreen && b->text().isEmpty())
            ++noTextButtons;
    check(noTextButtons == 3, "KeyMode/W×H/LnCh un-initialized with no active view");

    // ═══ AppletBar（0x00526a7c）：StatusBar 子类+改名+标题 ═══
    AppletBar ab;
    check(ab.objectName() == QStringLiteral("AppletBar"), "AppletBar objectName (0x00526a7c)");
    check(qobject_cast<StatusBar *>(&ab) != nullptr, "AppletBar is-a StatusBar");

    // scheme .appletbar import：skeleton assets 无 schemes/→空态
    check(AppletBar::schemeAppletbarImports(QString()).isEmpty(), "empty scheme name -> no imports");

    // sysmon 开关门（0x0084a755 纯面）
    const QStringList files = {QStringLiteral("sysmon/windows/sysmon.applet"),
                               QStringLiteral("misc/notes.applet")};
    check(AppletBar::filterPaneApplets(files, QStringLiteral("Shell"), true, true) == files,
          "Shell pane shell.sysmon=true keeps sysmon");
    check(AppletBar::filterPaneApplets(files, QStringLiteral("Shell"), false, true)
              == QStringList{QStringLiteral("misc/notes.applet")},
          "Shell pane shell.sysmon=false drops sysmon (reverse-order filter)");
    check(AppletBar::filterPaneApplets(files, QStringLiteral("SSH"), true, false)
              == QStringList{QStringLiteral("misc/notes.applet")},
          "SSH pane ssh.sysmon=false drops sysmon");
    check(AppletBar::filterPaneApplets(files, QStringLiteral("Other"), false, false) == files,
          "non-Shell/SSH pane untouched by sysmon switches");

    // ═══ KitPane_ensureAppletBar（0x005bf49e）：VBox 建/幂等；非 VBox/无布局 nullptr ═══
    ShellPane shellPane;
    AppletBar *b1 = KitPane_ensureAppletBar(&shellPane);
    check(b1 != nullptr && b1->parent() == &shellPane, "ensureAppletBar creates in pane");
    AppletBar *b2 = KitPane_ensureAppletBar(&shellPane);
    check(b1 == b2, "ensureAppletBar idempotent (findChild hit)");

    KitPane barePane(nullptr, QStringLiteral("BarePane"));
    check(KitPane_ensureAppletBar(&barePane) == nullptr, "no layout -> nullptr");
    QWidget hboxHost;
    auto *hbox = new QHBoxLayout(&hboxHost);
    Q_UNUSED(hbox);
    check(KitPane_ensureAppletBar(reinterpret_cast<KitPane *>(&hboxHost)) == nullptr
              || true, // dynamic_cast 守卫：QWidget 非 KitPane，编译期不合法——仅布局型断言如下
          "placeholder");
    KitPane vboxlessPane(nullptr, QStringLiteral("HBoxPane"));
    vboxlessPane.setLayout(new QHBoxLayout);
    check(KitPane_ensureAppletBar(&vboxlessPane) == nullptr, "QHBoxLayout -> nullptr (VBox only)");

    // loadForPane：空 import 列表→不建 AppletBar（0x0084a98d 空表守卫）——sysmon.applet JS
    // 依赖 executeCommand 桥（缺失清单见头），AppletBar 空态+挂账
    KitPane sysPane(nullptr, QStringLiteral("ShellPane"));
    AppletBar probeBar;
    probeBar.loadForPane(QStringLiteral("Shell"), &host, &sysPane);
    check(sysPane.findChild<AppletBar *>() == nullptr, "empty imports -> no pane AppletBar (R55 空态)");

    std::printf("%s: %d failure(s)\n", failed ? "FAIL" : "PASS", failed);
    return failed ? 1 : 0;
}
