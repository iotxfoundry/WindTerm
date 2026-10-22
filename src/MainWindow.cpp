#include "MainWindow.h"

#include <QAction>
#include <QCloseEvent>
#include <QJsonArray>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QProxyStyle>

// 原版菜单图标列 ~20px（反汇编+截图对照）；仅作用于菜单实例
class MenuIconStyle : public QProxyStyle {
public:
    int pixelMetric(PixelMetric metric, const QStyleOption *option,
                    const QWidget *widget) const override {
        if (metric == QStyle::PM_SmallIconSize)
            return 20;
        return QProxyStyle::pixelMetric(metric, option, widget);
    }
};
#include <QMenuBar>
#include <QPushButton>
#include <QSettings>
#include <QSplitter>
#include <QStackedWidget>
#include <QStatusBar>
#include <QTabBar>
#include <QTabWidget>
#include <QTime>
#include <QTimer>
#include <QToolBar>
#include <QVBoxLayout>

#include "core/ActionRegistry.h"
#include "core/KeymapConfig.h"
#include "core/Assets.h"
#include "core/SchemeManager.h"
#include "core/SshSession.h"
#include "core/ThemeManager.h"
#include "core/ToolbarConfig.h"
#include "core/WindConfig.h"
#include "dialogs/ConnectDialog.h"
#include "panes/ExplorerPane.h"
#include "panes/FilerPane.h"
#include "panes/OutlinePane.h"
#include "panes/OutputPane.h"
#include "panes/SearchPane.h"
#include "panes/SenderPane.h"
#include "panes/SessionPane.h"
#include "panes/ShellPane.h"
#include "panes/TransferPane.h"
#include "widgets/ActionIcons.h"
#include "widgets/AppletBar.h"
#include "widgets/MuxPaneGroup.h"
#include "widgets/PaneManager.h"
#include "widgets/Splitter.h"

namespace {

const QString LAYOUT_VERSION = QStringLiteral("v2");

QString splitterSettingsKey(const QString &objectName)
{
    return QStringLiteral("layout.%1/splitter_%2").arg(LAYOUT_VERSION, objectName);
}

} // namespace

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_locale(LocaleManager::instance())
    , m_muxPaneGroup(nullptr)
    , m_appletBar(nullptr)
    , m_addressBar(nullptr)
    , m_readyLabel(nullptr)
    , m_clockLabel(nullptr)
    , m_clockTimer(nullptr)
{
    setWindowTitle(tr("WindTerm"));
    // 原版 TerminalWindow（QSS #CategoryLabel 前缀，gui.theme:447）
    setObjectName(QStringLiteral("TerminalWindow"));
    resize(1200, 800);
    setAttribute(Qt::WA_DeleteOnClose);

    KeymapConfig::instance().load(Assets::dir() + QStringLiteral("/config/wind.keymaps"));
    WindConfig::instance().load(Assets::dir() + QStringLiteral("/config/wind.config"));

    const double opacity = WindConfig::instance().valueToDouble(QStringLiteral("application.windowOpacity"), 1.0);
    if (opacity > 0.0 && opacity < 1.0)
        setWindowOpacity(opacity);

    const QString theme = WindConfig::instance().valueToString(QStringLiteral("application.themeGui"), QStringLiteral("dige-black"));
    ThemeManager::instance().loadTheme(theme);
    ThemeManager::instance().apply();
    SchemeManager::instance().load();

    m_locale.load(Assets::dir() + QStringLiteral("/locales/zh-CN.locale"));

    createStatusBar();
    initActionRegistry();
    createMenus();
    createToolBar();
    createCentral();

    QTimer::singleShot(0, this, &MainWindow::onRestoreLayout);
}

QString MainWindow::makeMenuTitle(const QString &base, int n) const
{
    Q_UNUSED(n);
    // 原版 2.7.0 中文菜单无编号（"(&%1)" 仅见于 2020 EN 截图，docs/visual-acceptance 修正）
    return base;
}

void MainWindow::createMenus()
{
    MenuConfig &menuConfig = MenuConfig::instance();
    if (menuConfig.load(Assets::dir() + QStringLiteral("/config/uiconfigs/menu.config")) && !menuConfig.menuNames().isEmpty()) {
        const QStringList names = menuConfig.menuNames();
        for (int i = 0; i < names.size(); ++i) {
            const int n = (i == names.size() - 1) ? 0 : i + 1;
            QMenu *menu = menuBar()->addMenu(makeMenuTitle(m_locale.tr(names.at(i)), n));
            buildMenu(menu, menuConfig.menu(names.at(i)));
        }
        return;
    }

    createFallbackMenus();
}

void MainWindow::createFallbackMenus()
{
    auto addMenu = [this](const QString &title, int n, const QStringList &items) {
        QString plain = title;
        plain.remove(QLatin1Char('&')); // locale key 不含助记符 &
        QMenu *menu = menuBar()->addMenu(makeMenuTitle(m_locale.tr(plain), n));
        for (const QString &item : items) {
            QAction *action = menu->addAction(m_locale.tr(item));
            connect(action, &QAction::triggered, this, &MainWindow::onPlaceholderAction);
        }
    };

    addMenu(QStringLiteral("&Session"), 1, {QStringLiteral("New Session"), QStringLiteral("Open Session"), QStringLiteral("Close Session")});
    addMenu(QStringLiteral("&Edit"), 2, {QStringLiteral("Copy"), QStringLiteral("Paste"), QStringLiteral("Select All")});
    addMenu(QStringLiteral("&Search"), 3, {QStringLiteral("Find"), QStringLiteral("Find Next"), QStringLiteral("Find Previous")});
    addMenu(QStringLiteral("Se&lection"), 4, {QStringLiteral("Select Line"), QStringLiteral("Select Word")});
    addMenu(QStringLiteral("&Goto"), 5, {QStringLiteral("Next Tab"), QStringLiteral("Previous Tab")});
    addMenu(QStringLiteral("&View"), 6, {QStringLiteral("Toggle Filer"), QStringLiteral("Toggle Session"), QStringLiteral("Full Screen")});
    addMenu(QStringLiteral("&Mode"), 7, {QStringLiteral("Normal Mode"), QStringLiteral("Remote Mode")});
    addMenu(QStringLiteral("&Window"), 8, {QStringLiteral("New Window"), QStringLiteral("Close Window")});
    addMenu(QStringLiteral("&Help"), 0, {QStringLiteral("Help"), QStringLiteral("About")});
}

void MainWindow::createToolBar()
{
    ToolbarConfig &config = ToolbarConfig::instance();
    if (!config.load(Assets::dir() + QStringLiteral("/config/uiconfigs/toolbar.config")))
        return;

    const QString name = config.toolbarName();
    if (name.isEmpty())
        return;

    auto *toolBar = addToolBar(name);
    // 原版工具栏类 KitBar（QToolBar 子类，0x008b31b6）；gui.theme:583 qproperty-iconSize:20px
    toolBar->setObjectName(QStringLiteral("KitBar"));
    toolBar->setMovable(false);
    toolBar->setIconSize(QSize(16, 16));

    for (const ToolbarEntry &entry : config.entries(name)) {
        switch (entry.type) {
        case ToolbarEntry::Action:
            toolBar->addAction(makeAction(entry.actionId));
            break;
        case ToolbarEntry::AddressBar: {
            m_addressBar = new QLineEdit(toolBar);
            m_addressBar->setObjectName(QStringLiteral("AddressBarEdit"));
            // gui.theme:467 AddressBar > QLineEdit{...}：骨架地址栏无 BreadCrumb 容器，后代选择器不命中，
            // 内联同值复刻；多主题支持时移入 ThemeManager 适配段（shortcut）
            m_addressBar->setStyleSheet(QStringLiteral(
                "padding:4px;border:1px solid silver;background-color:white;"));
            m_addressBar->setPlaceholderText(QStringLiteral("ssh user@host"));
            m_addressBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
            connect(m_addressBar, &QLineEdit::returnPressed, this, &MainWindow::onAddressBarReturn);
            toolBar->addWidget(m_addressBar);
            break;
        }
        case ToolbarEntry::Separator:
            toolBar->addSeparator();
            break;
        }
    }
}

void MainWindow::onAddressBarReturn()
{
    if (!m_addressBar || !m_muxPaneGroup)
        return;
    const QString text = m_addressBar->text().trimmed();
    if (!text.startsWith(QStringLiteral("ssh "), Qt::CaseInsensitive))
        return;

    QString user;
    QString host;
    int port = 22;
    ConnectDialog::parseSpec(text, &user, &host, &port);

    ConnectDialog dialog(this);
    dialog.setSpec(user, host, port);
    if (dialog.exec() != QDialog::Accepted || dialog.host().isEmpty())
        return;

    auto *session = new SshSession(24, 80, m_muxPaneGroup);
    m_muxPaneGroup->openSession(session, QStringLiteral("ssh %1").arg(dialog.host()), Qt::red);
    session->start(dialog.host(), dialog.user(), dialog.password(), dialog.port());
}

QAction *MainWindow::makeAction(const QString &actionId)
{
    QString en = ActionRegistry::instance().actionText(actionId);
    if (en.isEmpty())
        en = actionId.section(QLatin1Char('.'), -1);

    QString key = en;
    key.remove(QLatin1Char('&'));
    if (key.endsWith(QStringLiteral("...")))
        key.chop(3);

    auto *action = new QAction(this);
    action->setText(displayActionText(en, m_locale.tr(key)));

    // 原版行为：带 icon 字段的动作用 king.svg 矢量（其余纯文字，docs/phase12）
    const QIcon ic = ActionIcons::iconFor(actionId, ActionRegistry::instance().actionIcon(actionId),
                                          ThemeManager::instance().currentTheme());
    if (!ic.isNull())
        action->setIcon(ic);

    // 快捷键 = keymaps 显示规则解析（docs/phase12：空modes=全局/含remote，滤Meta，取最后）
    const QString keys = KeymapConfig::instance().shortcut(actionId);
    if (!keys.isEmpty())
        action->setShortcut(QKeySequence(keys));

    action->setData(actionId);
    connect(action, &QAction::triggered, this, [this, actionId]() {
        if (actionId == QStringLiteral("Window.TogglePaneExplorer"))
            togglePane(findChild<ExplorerPane *>());
        else if (actionId == QStringLiteral("Window.TogglePaneFiler"))
            togglePane(findChild<FilerPane *>());
        else if (actionId == QStringLiteral("Window.TogglePaneSession"))
            togglePane(findChild<SessionPane *>());
        else if (actionId == QStringLiteral("Window.TogglePaneOutline")) {
            QWidget *pane = findChild<QWidget *>(QStringLiteral("OutlineTabs"));
            togglePane(pane ? pane : findChild<OutlinePane *>());
        } else
            Q_UNIMPLEMENTED();
    });
    return action;
}

QString MainWindow::displayActionText(const QString &en, const QString &translated)
{
    if (translated.isEmpty())
        return en;

    QString text = translated;
    if (en.endsWith(QStringLiteral("...")))
        text += QStringLiteral("...");
    const int ampersand = en.indexOf(QLatin1Char('&'));
    if (ampersand >= 0 && ampersand + 1 < en.size())
        text += QStringLiteral("(%1)").arg(en.at(ampersand + 1));
    return text;
}

void MainWindow::buildMenu(QMenu *menu, const QVector<MenuEntry> &entries)
{
    static MenuIconStyle menuIconStyle;
    menu->setStyle(&menuIconStyle);
    // 图标尺寸走 PM_SmallIconSize(16)：裁剪图字形已满幅，无需调整
    for (const MenuEntry &entry : entries) {
        switch (entry.type) {
        case MenuEntry::Action:
            menu->addAction(makeAction(entry.actionId));
            break;
        case MenuEntry::Separator:
            menu->addSeparator();
            break;
        case MenuEntry::Submenu: {
            // 子菜单标题走同款 locale 管线（原版：最近打开/日志/首选项…）+ 裁剪图标（slug 键）
            QString key = entry.title;
            key.remove(QLatin1Char('&'));
            if (key.endsWith(QStringLiteral("...")))
                key.chop(3);
            QMenu *sub = menu->addMenu(displayActionText(entry.title, m_locale.tr(key)));
            sub->setStyle(&menuIconStyle);
            buildMenu(sub, entry.children);
            break;
        }
        }
    }
}

void MainWindow::createCentral()
{
    // 反汇编骨架（FUN_008cd068）保留 root；面板由移植的插入引擎 FUN_005a277a 相对 Mux 生成
    auto *root = new Splitter(this);
    root->setOrientation(Qt::Vertical);
    root->setObjectName(QStringLiteral("RootSplitter"));

    auto *muxRow = new QSplitter(Qt::Horizontal, root);
    muxRow->setObjectName(QStringLiteral("CenterSplitter"));
    muxRow->setChildrenCollapsible(false);

    m_muxPaneGroup = new MuxPaneGroup(muxRow);
    muxRow->addWidget(m_muxPaneGroup);

    auto *tabsGroup = new QTabWidget;
    tabsGroup->addTab(new ExplorerPane(tabsGroup), m_locale.tr(QStringLiteral("Explorer")));
    tabsGroup->addTab(new SessionPane(tabsGroup), m_locale.tr(QStringLiteral("Session")));
    PaneManager::insert(root, m_muxPaneGroup, tabsGroup, Dir::Left);

    auto *filerPane = new FilerPane;
    PaneManager::insert(root, tabsGroup, filerPane, Dir::Bottom);

    auto *outlineTabs = new QTabWidget;
    outlineTabs->setObjectName(QStringLiteral("OutlineTabs"));
    outlineTabs->addTab(new OutlinePane(outlineTabs), m_locale.tr(QStringLiteral("Outline")));
    PaneManager::insert(root, m_muxPaneGroup, outlineTabs, Dir::Right);
    outlineTabs->hide();

    auto *bottomGroup = createBottomTabs();
    PaneManager::insert(root, m_muxPaneGroup, bottomGroup, Dir::Bottom);
    bottomGroup->hide();

    m_appletBar = new AppletBar(QJsonArray(), root);
    root->addWidget(muxRow);
    root->addWidget(m_appletBar);
    setCentralWidget(root);

    // 比例：Mux 4 份、左右侧列各 1 份；Mux 所在纵向 splitter 中 Mux 4 : 底栏 1
    muxRow->setSizes({1000, 4000, 1000});
    if (auto *muxParent = qobject_cast<QSplitter *>(m_muxPaneGroup->parentWidget()))
        muxParent->setSizes({4000, 1000});
    root->setSizes({4000, 2000});

    // 移动分割条即持久化；所有具名 splitter（含 PaneManager 动态嵌套）统一接入
    for (QSplitter *splitter : findChildren<QSplitter *>()) {
        if (splitter->objectName().isEmpty())
            continue;
        connect(splitter, &QSplitter::splitterMoved, this, [splitter]() {
            QSettings settings;
            settings.setValue(splitterSettingsKey(splitter->objectName()), splitter->saveState());
        });
    }
}

QWidget *MainWindow::createBottomTabs()
{
    auto *container = new QWidget;
    auto *layout = new QVBoxLayout(container);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    auto *tabs = new QTabBar(container);
    tabs->addTab(m_locale.tr(QStringLiteral("Sender")));
    tabs->addTab(m_locale.tr(QStringLiteral("Transfer")));
    tabs->addTab(m_locale.tr(QStringLiteral("Output")));
    tabs->addTab(m_locale.tr(QStringLiteral("Search")));
    tabs->addTab(m_locale.tr(QStringLiteral("Shell")));

    auto *stack = new QStackedWidget(container);
    stack->addWidget(new SenderPane(stack));
    stack->addWidget(new TransferPane(stack));
    stack->addWidget(new OutputPane(stack));
    stack->addWidget(new SearchPane(stack));
    stack->addWidget(new ShellPane(stack));

    connect(tabs, &QTabBar::currentChanged, stack, &QStackedWidget::setCurrentIndex);

    layout->addWidget(tabs);
    layout->addWidget(stack);
    return container;
}

void MainWindow::createStatusBar()
{
    // 原版 AppletBar 继承 StatusBar 并覆盖名（0x00526a7c）；gui.theme:493 AppletBar QToolButton
    statusBar()->setObjectName(QStringLiteral("AppletBar"));
    m_readyLabel = new QLabel(tr("Ready"), this);
    statusBar()->addWidget(m_readyLabel);
    statusBar()->addPermanentWidget(new QLabel(tr("Remote Mode"), this));
    statusBar()->addPermanentWidget(new QLabel(tr("窗口 53×193"), this));
    statusBar()->addPermanentWidget(new QLabel(tr("行 1 字符 1"), this));
    statusBar()->addPermanentWidget(new QLabel(ThemeManager::instance().currentTheme(), this));
    statusBar()->addPermanentWidget(new QLabel(tr("localhost"), this));

    m_clockLabel = new QLabel(this);
    statusBar()->addPermanentWidget(m_clockLabel);

    auto *lockButton = new QPushButton(tr("锁屏"), this);
    statusBar()->addPermanentWidget(lockButton);
    connect(lockButton, &QPushButton::clicked, this, []() { Q_UNIMPLEMENTED(); });

    m_clockTimer = new QTimer(this);
    connect(m_clockTimer, &QTimer::timeout, this, &MainWindow::updateClock);
    m_clockTimer->start(1000);
    updateClock();
}

void MainWindow::initActionRegistry()
{
    ActionRegistry &registry = ActionRegistry::instance();
    if (!registry.load(Assets::dir() + QStringLiteral("/config/wind.actions")))
        return;

    m_readyLabel->setText(m_readyLabel->text() + QStringLiteral(" · ")
                          + QString::number(registry.actionIds().size()) + QStringLiteral(" actions"));
}

void MainWindow::onRestoreLayout()
{
    QSettings settings;
    restoreGeometry(settings.value(QStringLiteral("application/windowGeometry")).toByteArray());

    for (QSplitter *splitter : findChildren<QSplitter *>()) {
        const QString name = splitter->objectName();
        if (name.isEmpty())
            continue;
        const QByteArray state = settings.value(splitterSettingsKey(name)).toByteArray();
        if (state.isEmpty() || !splitter->restoreState(state))
            continue;
    }

    Q_UNIMPLEMENTED();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings;
    settings.setValue(QStringLiteral("application/windowGeometry"), saveGeometry());
    QMainWindow::closeEvent(event);
}

void MainWindow::updateClock()
{
    m_clockLabel->setText(QTime::currentTime().toString(QStringLiteral("HH:mm:ss")));
}

void MainWindow::togglePane(QWidget *pane)
{
    if (!pane)
        return;
    if (pane->isHidden())
        pane->show();
    else
        pane->hide();
}

void MainWindow::onPlaceholderAction()
{
    Q_UNIMPLEMENTED();
}
