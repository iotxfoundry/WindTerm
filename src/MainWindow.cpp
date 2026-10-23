#include "MainWindow.h"

#include <QAction>
#include <QCloseEvent>

#include <QLabel>
#include <QLineEdit>
#include <QMenu>

// 菜单图标列尺寸：原版无 QProxyStyle/PM 覆盖痕迹（rg 0 命中）→ 回退 Qt 默认 PM_SmallIconSize；
// King::iconFactory(0x007572ac) 的渲染 rect 由动态调用方传入，静态不可达（挂账）
#include <QMenuBar>
#include <QPushButton>
#include <QSettings>
#include <QSignalBlocker>
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
#include "core/SessionStore.h"
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
#include "widgets/KitGroup.h"
#include "widgets/MuxPaneGroup.h"
#include "widgets/QuickBar.h"
#include "widgets/Splitter.h"

namespace {

// v5：中部单元改为嵌套 QMainWindow（KitGroup，ctor 0x008bb360）——标签行=menuWidget、
// KitBar=addToolBar、MuxPaneGroup=central（setupBars 0x008bade2）；v4 的 CenterGroup
// VBox 旧状态必须失效
const QString LAYOUT_VERSION = QStringLiteral("v5");

QString splitterSettingsKey(const QString &objectName)
{
    return QStringLiteral("layout.%1/splitter_%2").arg(LAYOUT_VERSION, objectName);
}

} // namespace

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_locale(LocaleManager::instance())
    , m_muxPaneGroup(nullptr)
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

    // 原版 KitBar 在 KitGroup 的 toolBar 区（工具栏行：标签行之下、终端之上，只占中部宽）。
    // 经 KitGroup::addToolBar 挂入（setupBars 0x008bade2 → QMainWindow::addToolBar 0x008bb07d）；
    // createCentral 里装配
    auto *toolBar = new QToolBar(name, this);
    // 原版工具栏类 KitBar（QToolBar 子类，0x008b31b6）；gui.theme:583 qproperty-iconSize:20px
    toolBar->setObjectName(QStringLiteral("KitBar"));
    toolBar->setMovable(false);
    m_toolBar = toolBar;

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

// user.sessions 双击接入（原版编辑即写 0x00806958，骨架只读）：user 无键 → user 留空
void MainWindow::connectSessionPane(SessionPane *pane)
{
    connect(pane, &SessionPane::sessionActivated, this,
            [this](const QString &host, int port, const QString &label) {
        if (!m_muxPaneGroup)
            return;
        ConnectDialog dialog(this);
        dialog.setSpec(QString(), host, port > 0 ? port : 22);
        if (dialog.exec() != QDialog::Accepted || dialog.host().isEmpty())
            return;

        auto *session = new SshSession(24, 80, m_muxPaneGroup);
        m_muxPaneGroup->openSession(session, label.isEmpty()
                                                ? QStringLiteral("ssh %1").arg(dialog.host())
                                                : label,
                                    Qt::red);
        session->start(dialog.host(), dialog.user(), dialog.password(), dialog.port());
    });
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
    // Window.ToggleQuickBar（wind.actions: checkable，state=isHidden?false:true，script=toggleBar）
    if (actionId == QStringLiteral("Window.ToggleQuickBar")) {
        action->setCheckable(true);
        connect(action, &QAction::triggered, this, &MainWindow::toggleQuickBar);
        return action;
    }
    // wind.actions Dock.TogglePane* 与 Window.TogglePane*：toggle 对应容器。
    // 映射按骨架合并形态：原版 Session 独立 pane 与 Explorer 合并为 tabsGroup（QTabWidget），shortcut 挂账
    connect(action, &QAction::triggered, this, [this, actionId]() {
        QString pane = actionId.section(QLatin1Char('.'), -1);
        pane.remove(QStringLiteral("TogglePane"));
        QWidget *target = nullptr;
        int bottomTabIndex = -1;
        if (pane == QStringLiteral("Explorer") || pane == QStringLiteral("Session"))
            target = findChild<QWidget *>(QStringLiteral("ExplorerTabs"));
        else if (pane == QStringLiteral("Filer"))
            target = findChild<FilerPane *>();
        else if (pane == QStringLiteral("Outline"))
            target = findChild<QWidget *>(QStringLiteral("OutlineTabs"));
        else if (pane == QStringLiteral("Sender") || pane == QStringLiteral("Transfer")
                 || pane == QStringLiteral("Output") || pane == QStringLiteral("Shell")) {
            // 五页共用 bottomGroup：toggle 整组可见并切到对应页（Sender/Transfer/Output/Search/Shell 顺序）
            target = findChild<QWidget *>(QStringLiteral("BottomPanes"));
            static const QStringList order = {QStringLiteral("Sender"), QStringLiteral("Transfer"),
                                              QStringLiteral("Output"), QStringLiteral("Shell")};
            bottomTabIndex = order.indexOf(pane);
        }
        if (!target)
            return;
        if (bottomTabIndex < 0) {
            togglePane(target);
            return;
        }
        // 五页共用 bottomGroup：显示整组并切到对应页
        const bool showing = target->isHidden();
        togglePane(target);
        if (showing) {
            if (auto *tabs = target->findChild<QTabBar *>())
                tabs->setCurrentIndex(bottomTabIndex);
        }
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
            buildMenu(sub, entry.children);
            break;
        }
        }
    }
}

void MainWindow::createCentral()
{
    // 0x008cd068 显式装配：0x38/0x40/0x48/0x50 为裸 QSplitter，0x58/0x60/0x68 为 Splitter 子类。
    // 仅 0x38/0x40/0x60/0x68 设 V(=2)，0x58 保持默认 H；0x48 设 childrenCollapsible(false)
    auto *root = new Splitter(this);
    root->setOrientation(Qt::Vertical);
    root->setObjectName(QStringLiteral("RootSplitter"));

    auto *col = new Splitter;
    col->setObjectName(QStringLiteral("CenterColumn")); // 0x58：未 setOrientation，默认 H（左中右三列）

    auto *left = new QSplitter(Qt::Vertical);
    left->setObjectName(QStringLiteral("LeftPanes"));

    auto *tabsGroup = new QTabWidget;
    tabsGroup->setObjectName(QStringLiteral("ExplorerTabs"));
    tabsGroup->addTab(new ExplorerPane(tabsGroup), m_locale.tr(QStringLiteral("Explorer")));
    auto *sessionPane = new SessionPane(tabsGroup);
    tabsGroup->addTab(sessionPane, m_locale.tr(QStringLiteral("Session")));
    connectSessionPane(sessionPane);

    auto *filerPane = new FilerPane;
    left->addWidget(tabsGroup);
    left->addWidget(filerPane);
    // shortcut: 原版运行时按均分插入，此处按实机侧栏截图约 2:1 定格；动态插入改走 PaneManager 时恢复均分
    left->setSizes({2000, 1000});

    // 原版 root 中央单元 0x60=QSplitter 子类 H（childrenCollapsible(false)），
    // 内装 TabGroup_buildCentral(0x005ab6e8) 的返回件（原版 return +0x60 = 该 splitter）
    auto *muxRow = new QSplitter(Qt::Horizontal);
    muxRow->setObjectName(QStringLiteral("MuxRow"));
    muxRow->setChildrenCollapsible(false);
    m_muxPaneGroup = new MuxPaneGroup;
    muxRow->addWidget(m_muxPaneGroup);

    // 中央列 = KitGroup（嵌套 QMainWindow，ctor 0x008bb360）：标签行占 menuWidget 槽、
    // KitBar 占 toolBar 区（QToolBar 只占中部宽，不横跨侧栏）、central=MuxPaneGroup
    // 的堆栈（对应 setupBars 0x008bade2：setMenuWidget 0x008bb044 → TabGroup_buildCentral
    // 0x005ab6e8 return +0x60 → addToolBar 0x008bb07d）
    auto *kitGroup = new KitGroup;
    if (m_muxPaneGroup->tabBarRow())
        kitGroup->setMenuWidget(m_muxPaneGroup->tabBarRow());
    if (m_toolBar) {
        m_toolBar->setParent(kitGroup); // 脱离 MainWindow，改挂 KitGroup；objectName KitBar 保持主题规则
        kitGroup->addToolBar(m_toolBar);
    }
    kitGroup->setCentralWidget(muxRow);

    auto *right = new QSplitter(Qt::Vertical);
    right->setObjectName(QStringLiteral("RightPanes"));

    auto *outlineTabs = new QTabWidget;
    outlineTabs->setObjectName(QStringLiteral("OutlineTabs"));
    outlineTabs->addTab(new OutlinePane(outlineTabs), m_locale.tr(QStringLiteral("Outline")));
    right->addWidget(outlineTabs);

    auto *bottom = new QSplitter(Qt::Horizontal);
    bottom->setObjectName(QStringLiteral("BottomPanes"));

    auto *bottomGroup = createBottomTabs();
    bottom->addWidget(bottomGroup);
    bottomGroup->hide();

    col->addWidget(left);
    col->addWidget(kitGroup);
    col->addWidget(right);
    root->addWidget(col);
    root->addWidget(bottom);

    // v5：中央 widget 即 root splitter（中部单元=KitGroup 嵌套窗口，标签行/工具栏不横跨侧栏）
    setCentralWidget(root);

    col->setSizes({1000, 4000, 1000});
    // 原 CenterGroup VBox 期 setSizes({4000,2000}) 双值随 KitGroup 化失效移除（muxRow 内部
    // childrenCollapsible(false) 语义不变，运行时无需预分配份额）
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

    // 右列 Outline 默认隐藏（phase8：运行时插入后 hideIndex）。必须等首次布局完成再折叠，
    // 否则 QSplitter 会把右列份额重新归一化，左列从 1/6 变成 1/5
    if (auto *outline = findChild<QWidget *>(QStringLiteral("OutlineTabs")))
        outline->hide();
    if (auto *col = findChild<Splitter *>(QStringLiteral("CenterColumn"))) {
        QSignalBlocker blocker(col); // 程序性折叠不写入 QSettings，否则每次启动左列按比例继续缩水
        col->hideIndex(2);
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
    const bool showing = pane->isHidden();
    pane->setVisible(showing);
    if (showing)
        for (QWidget *p = pane->parentWidget(); p; p = p->parentWidget())
            p->setVisible(true);
}

// 惰性创建：原版首次显示时才构建（0x0085ad2e）并 insertWidget 进中央底部区 QSplitter，
// 排序键 [SearchPane, QuickBar, TransferBar] → bottomGroup 前插（index 0，骨架近似）
QuickBar *MainWindow::ensureQuickBar()
{
    if (m_quickBar)
        return m_quickBar;
    m_quickBar = new QuickBar(this);
    if (auto *bottom = findChild<QSplitter *>(QStringLiteral("BottomPanes")))
        bottom->insertWidget(0, m_quickBar);
    // QSplitter::insertWidget 会自动显示新槽（PaneManager 同款坑）；原版创建时不可见，由首次 toggle 接管
    m_quickBar->hide();
    return m_quickBar;
}

void MainWindow::toggleQuickBar()
{
    QuickBar *bar = ensureQuickBar();
    // wind.actions state 勾选态与可见性同步；QSplitter 收养后 insertWidget 即显示
    bar->setVisible(bar->isHidden());
}

void MainWindow::onPlaceholderAction()
{
    Q_UNIMPLEMENTED();
}
