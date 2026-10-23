#include "MainWindow.h"

#include <QAction>
#include <QCloseEvent>

#include <QDateTime>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLabel>
#include <QLineEdit>
#include <QLocale>
#include <QMenu>

// 菜单图标列尺寸：原版无 QProxyStyle/PM 覆盖痕迹（rg 0 命中）→ 回退 Qt 默认 PM_SmallIconSize；
// King::iconFactory(0x007572ac) 的渲染 rect 由动态调用方传入，静态不可达（挂账）
#include <QMenuBar>
#include <QPushButton>
#include <QResizeEvent>
#include <QSettings>
#include <QSignalBlocker>
#include <QSplitter>
#include <QStackedWidget>
#include <QStatusBar>
#include <QTabBar>
#include <QTabWidget>
#include <QTimer>
#include <QToolBar>
#include <QToolButton>
#include <QVBoxLayout>

#include "core/ActionRegistry.h"
#include "core/KeymapConfig.h"
#include "core/Assets.h"
#include "core/JsonText.h"
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
#include "widgets/MenuBarCorner.h"
#include "widgets/MuxPaneGroup.h"
#include "widgets/PaneHeader.h"
#include "widgets/QuickBar.h"
#include "widgets/Splitter.h"
#include "widgets/TransferBar.h"

namespace {

// v5：中部单元改为嵌套 QMainWindow（KitGroup，ctor 0x008bb360）——标签行=menuWidget、
// KitBar=addToolBar、MuxPaneGroup=central（setupBars 0x008bade2）；v4 的 CenterGroup
// VBox 旧状态必须失效
const QString LAYOUT_VERSION = QStringLiteral("v5");

QString splitterSettingsKey(const QString &objectName)
{
    return QStringLiteral("layout.%1/splitter_%2").arg(LAYOUT_VERSION, objectName);
}

// B4：menu.config 顶层独立节（如 "Open Recent"）不在 MenuConfig::m_menus（只收集 Kit 菜单），
// 按同名节补取 Actions。解析规则与 MenuConfig::parseEntries 一致。
QVector<MenuEntry> parseMenuSection(const QJsonArray &array)
{
    QVector<MenuEntry> entries;
    for (const QJsonValue &value : array) {
        const QJsonObject object = value.toObject();
        MenuEntry entry;
        if (object.contains(QStringLiteral("Menu"))) {
            entry.type = MenuEntry::Submenu;
            entry.title = object.value(QStringLiteral("Menu")).toString();
            entry.children = parseMenuSection(object.value(QStringLiteral("Actions")).toArray());
        } else if (object.contains(QStringLiteral("Separator"))) {
            entry.type = MenuEntry::Separator;
        } else if (object.contains(QStringLiteral("Action"))) {
            entry.type = MenuEntry::Action;
            entry.actionId = object.value(QStringLiteral("Action")).toString();
        } else {
            continue;
        }
        entries.append(entry);
    }
    return entries;
}

QVector<MenuEntry> menuSection(const QString &name)
{
    QFile file(Assets::dir() + QStringLiteral("/config/uiconfigs/menu.config"));
    if (!file.open(QIODevice::ReadOnly))
        return {};
    QByteArray data = file.readAll();
    if (data.startsWith("\xEF\xBB\xBF"))
        data.remove(0, 3);
    const QJsonDocument doc = QJsonDocument::fromJson(JsonText::stripLineComments(data));
    if (!doc.isObject())
        return {};
    return parseMenuSection(doc.object().value(name).toArray());
}

} // namespace

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_locale(LocaleManager::instance())
    , m_muxPaneGroup(nullptr)
    , m_addressBar(nullptr)
{
    setWindowTitle(tr("WindTerm"));
    // 原版 TerminalWindow（QSS #CategoryLabel 前缀，dige-black gui.theme:472）
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
    // 证据 0x008c9ee4/0x0085d99e：MenuBar 右上角 MenuBarCorner（Terminal 版含 Tunnels/XServer）
    menuBar()->setCornerWidget(new MenuBarCorner(this, true), Qt::TopRightCorner);

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

void MainWindow::addToolBarEntry(QToolBar *toolBar, const ToolbarEntry &entry)
{
    switch (entry.type) {
    case ToolbarEntry::Action: {
        QAction *action = makeAction(entry.actionId);
        if (entry.menu.isEmpty()) {
            toolBar->addAction(action);
            break;
        }
        // 0x00694276：type3=QToolButton（defaultAction）+ 可选 popup menu（toolbar.config "Menu" 字段）。
        // popup 语义未细逆，取 MenuButtonPopup：主区触发 action，箭头展开 menu.config 同名节
        auto *button = new QToolButton(toolBar);
        button->setDefaultAction(action);
        button->setPopupMode(QToolButton::MenuButtonPopup);
        auto *menu = new QMenu(button);
        buildMenu(menu, menuSection(entry.menu));
        button->setMenu(menu);
        toolBar->addWidget(button);
        break;
    }
    case ToolbarEntry::AddressBar: {
        m_addressBar = new QLineEdit(toolBar);
        m_addressBar->setObjectName(QStringLiteral("AddressBarEdit"));
        // dige-black gui.theme:492 AddressBar > QLineEdit{...}：骨架地址栏无 BreadCrumb 容器，后代选择器不命中，
        // 内联同值复刻；多主题支持时移入 ThemeManager 适配段（shortcut）
        m_addressBar->setStyleSheet(QStringLiteral(
            "padding:4px;border:1px solid silver;background-color:white;"));
        m_addressBar->setPlaceholderText(QStringLiteral("ssh user@host"));
        m_addressBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        connect(m_addressBar, &QLineEdit::returnPressed, this, &MainWindow::onAddressBarReturn);
        toolBar->addWidget(m_addressBar);
        break;
    }
    case ToolbarEntry::FilterEdit: {
        auto *filter = new QLineEdit(toolBar);
        filter->setObjectName(QStringLiteral("FilterEdit"));
        filter->setPlaceholderText(m_locale.tr(QStringLiteral("Filter")));
        filter->setFixedWidth(150);
        toolBar->addWidget(filter);
        break;
    }
    case ToolbarEntry::Separator:
        toolBar->addSeparator();
        break;
    }
}

void MainWindow::createToolBar()
{
    ToolbarConfig &config = ToolbarConfig::instance();
    if (!config.load(Assets::dir() + QStringLiteral("/config/uiconfigs/toolbar.config")))
        return;

    const QString name = config.toolbarName();
    if (name.isEmpty())
        return;

    // 原版 KitGroup 的 toolBar 区（工具栏行：标签行之下、终端之上，只占中部宽）。
    // 经 KitGroup::addToolBar 挂入（setupBars 0x008bade2 → QMainWindow::addToolBar 0x008bb07d）；
    // createCentral 里装配
    auto *toolBar = new QToolBar(name, this);
    // 原版 toolbar_build 产物 objectName="ToolBar"（0x00694276，title=tr("Standard")）；
    // "KitBar" 只属 QuickSwitcher（0x008b31b6），不得用于主窗工具栏
    toolBar->setObjectName(QStringLiteral("ToolBar"));
    toolBar->setMovable(false);
    m_toolBar = toolBar;

    for (const ToolbarEntry &entry : config.entries(name))
        addToolBarEntry(toolBar, entry);
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
    // Window.ToggleMenuBar / Window.ToggleStatusBar（wind.actions:2614/2683 script=toggleBar）
    if (actionId == QStringLiteral("Window.ToggleMenuBar")) {
        connect(action, &QAction::triggered, this, [this]() { menuBar()->setVisible(!menuBar()->isVisible()); });
        return action;
    }
    if (actionId == QStringLiteral("Window.ToggleStatusBar")) {
        connect(action, &QAction::triggered, this, [this]() { statusBar()->setVisible(!statusBar()->isVisible()); });
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
        else if (pane == QStringLiteral("Search"))
            target = m_searchPane;
        else if (pane == QStringLiteral("Sender") || pane == QStringLiteral("Transfer")
                 || pane == QStringLiteral("Output") || pane == QStringLiteral("Shell")) {
            // 四页共用 bottomGroup：toggle 整组可见并切到对应页（Sender/Transfer/Output/Shell 顺序）
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
        // 四页共用 bottomGroup：显示整组并切到对应页
        const bool showing = target->isHidden();
        togglePane(target);
        if (showing) {
            if (auto *tabs = target->findChild<QTabBar *>())
                tabs->setCurrentIndex(bottomTabIndex);
        }
    });
    return action;
}

// A6（0x008c40a6/0x008c442e）：按 pane 自身 objectName 读 toolbar.config 同名节建 pane 内工具栏
// （原版首次 show 建；骨架无 pane 生命周期钩子，createCentral 装配完成后一次建齐）
void MainWindow::installPaneToolBar(QWidget *pane)
{
    const QVector<ToolbarEntry> entries = ToolbarConfig::instance().entries(pane->objectName());
    if (entries.isEmpty())
        return;

    // item view 类 pane（SessionPane/OutlinePane/OutputPane）自带 scrollarea 布局，工具栏挂在 PaneHost 容器布局上
    QWidget *host = pane;
    if (QWidget *parent = pane->parentWidget();
        parent && parent->objectName() == QStringLiteral("PaneHost"))
        host = parent;

    auto *box = qobject_cast<QBoxLayout *>(host->layout());
    if (!box) {
        // shortcut: pane 无 QBoxLayout 挂点, 待 pane 改为 KitPane QWidget 容器后补
        return;
    }

    auto *toolBar = new QToolBar(host);
    // 原版 toolbar_build 产物 objectName="ToolBar"（每 pane 一个同名实例，主题 #ToolBar 全命中）
    toolBar->setObjectName(QStringLiteral("ToolBar"));
    toolBar->setMovable(false);
    for (const ToolbarEntry &entry : entries) {
        // ExplorerPane 已有自带 FilterEdit，避免出现两行过滤框
        if (entry.type == ToolbarEntry::FilterEdit
            && pane->findChild<QLineEdit *>(QStringLiteral("FilterEdit")))
            continue;
        addToolBarEntry(toolBar, entry);
    }
    if (toolBar->actions().isEmpty()) {
        delete toolBar; // 条目全被跳过（如 ExplorerPane 自带 FilterEdit）则不占位
        return;
    }
    box->insertWidget(0, toolBar);
}

QWidget *MainWindow::paneHost(QWidget *pane)
{
    // 原版 KitPane 本身是 QWidget 容器（0x008c3bbe）；骨架 item view 类 pane 无法直接插布局，补一层同名容器
    auto *host = new QWidget;
    host->setObjectName(QStringLiteral("PaneHost"));
    auto *layout = new QVBoxLayout(host);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(pane);
    return host;
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
            if (!entry.children.isEmpty()) {
                buildMenu(sub, entry.children);
                break;
            }
            // 证据 menu.config:75-81：独立 "Open Recent" 节；menu.config:423 的 "Open Rece&nt" 无 Actions 键
            QString section = entry.title;
            section.remove(QLatin1Char('&'));
            const QVector<MenuEntry> derived = menuSection(section);
            if (!derived.isEmpty())
                buildMenu(sub, derived);
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
    tabsGroup->addTab(paneHost(sessionPane), m_locale.tr(QStringLiteral("Session")));
    connectSessionPane(sessionPane);

    auto *filerPane = new FilerPane;
    // PaneHeader closeRequested → hide pane（对齐 Dock.TogglePaneFiler toggle 语义）
    connect(filerPane, &FilerPane::closeRequested, this, [this, filerPane]() { togglePane(filerPane); });
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
    // ToolBar 占 toolBar 区（QToolBar 只占中部宽，不横跨侧栏）、central=MuxPaneGroup
    // 的堆栈（对应 setupBars 0x008bade2：setMenuWidget 0x008bb044 → TabGroup_buildCentral
    // 0x005ab6e8 return +0x60 → addToolBar 0x008bb07d）
    auto *kitGroup = new KitGroup;
    if (m_muxPaneGroup->tabBarRow())
        kitGroup->setMenuWidget(m_muxPaneGroup->tabBarRow());
    if (m_toolBar) {
        m_toolBar->setParent(kitGroup); // 脱离 MainWindow，改挂 KitGroup；objectName ToolBar 保持主题规则
        kitGroup->addToolBar(m_toolBar);
    }
    kitGroup->setCentralWidget(muxRow);

    // 证据 0x008cd068：0x60 纵向 splitter 包住 0x48（KitGroup 容器）再入 0x58 主行；
    // 上方预留纵向空间供 showPane 动态插入，单子件不 setSizes
    auto *kitColumn = new QSplitter(Qt::Vertical);
    kitColumn->addWidget(kitGroup);

    auto *right = new QSplitter(Qt::Vertical);
    right->setObjectName(QStringLiteral("RightPanes"));

    auto *outlineTabs = new QTabWidget;
    outlineTabs->setObjectName(QStringLiteral("OutlineTabs"));
    outlineTabs->addTab(paneHost(new OutlinePane(outlineTabs)), m_locale.tr(QStringLiteral("Outline")));
    right->addWidget(outlineTabs);

    auto *bottom = new QSplitter(Qt::Horizontal);
    bottom->setObjectName(QStringLiteral("BottomPanes"));

    auto *bottomGroup = createBottomTabs();
    bottom->addWidget(bottomGroup);
    bottomGroup->hide();

    col->addWidget(left);
    col->addWidget(kitColumn);
    col->addWidget(right);
    root->addWidget(col);
    root->addWidget(bottom);

    // 证据 0x0085a7a6：+0xc8 竖向 splitter 包住整个中央树，底部按
    // [SearchPane, QuickBar, TransferBar] 顺序 insertWidget —— 三条全宽独立条，上下堆叠。
    auto *centralVSplitter = new QSplitter(Qt::Vertical);
    centralVSplitter->addWidget(root);

    m_searchPane = new SearchPane;
    centralVSplitter->addWidget(m_searchPane);
    m_searchPane->hide();

    m_searchPane = new SearchPane;
    centralVSplitter->addWidget(m_searchPane);
    m_searchPane->hide();

    // QuickBar/TransferBar 懒建（证据 0x85ad2e lazyCreateQuickBar / 0x85af56：
    // 原版首次显示才建，显隐分发 0x85d080），ensureQuickBar 插在本条之后

    // v5：中央 widget 即 root splitter（中部单元=KitGroup 嵌套窗口，标签行/工具栏不横跨侧栏）
    setCentralWidget(centralVSplitter);

    col->setSizes({1000, 4000, 1000});
    // 原 CenterGroup VBox 期 setSizes({4000,2000}) 双值随 KitGroup 化失效移除（muxRow 内部
    // childrenCollapsible(false) 语义不变，运行时无需预分配份额）
    root->setSizes({4000, 2000});

    // A6（0x008c40a6/0x008c442e）：pane 工具栏按 toolbar.config 同名节建；pane 装配完成后一次建齐
    // （原版首次 show 建，骨架无 pane 生命周期钩子，提前建等价且免 Show 序依赖）
    for (const char *name : {"ExplorerPane", "SessionPane", "FilerPane", "OutlinePane",
                             "OutputPane", "SenderPane"}) {
        if (QWidget *pane = findChild<QWidget *>(QString::fromLatin1(name)))
            installPaneToolBar(pane);
    }
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
    tabs->addTab(m_locale.tr(QStringLiteral("Shell")));

    auto *stack = new QStackedWidget(container);
    stack->addWidget(new SenderPane(stack));
    stack->addWidget(new TransferPane(stack));
    stack->addWidget(paneHost(new OutputPane(stack)));
    stack->addWidget(new ShellPane(stack));

    connect(tabs, &QTabBar::currentChanged, stack, &QStackedWidget::setCurrentIndex);

    layout->addWidget(tabs);
    layout->addWidget(stack);
    return container;
}

void MainWindow::createStatusBar()
{
    // 证据 0x00692766：主窗底栏 = StatusBar（objectName "StatusBar"），
    // 内容来自 assets/config/uiconfigs/statusbar.config 的 7 个 applet（0x006933ea）。
    statusBar()->setObjectName(QStringLiteral("StatusBar"));

    // 证据: statusbar.config:2-25 模式按钮（Remote/Local）
    m_modeButton = new QToolButton(this);
    m_modeButton->setObjectName(QStringLiteral("ModeButton"));
    m_modeButton->setAutoRaise(true);
    m_modeButton->setText(m_locale.tr(m_localMode ? QStringLiteral("Local Mode") : QStringLiteral("Remote Mode")));
    connect(m_modeButton, &QToolButton::clicked, this, [this]() {
        m_localMode = !m_localMode;
        m_modeButton->setText(m_locale.tr(m_localMode ? QStringLiteral("Local Mode") : QStringLiteral("Remote Mode")));
        // shortcut: 终端 view keyMode 切换未接（terminal.activeView/keyModeChanged）, TerminalView 接入后同步
    });
    statusBar()->addPermanentWidget(m_modeButton);

    // 证据: statusbar.config:26-43 Window %1×%2（骨架无终端 windowRows/Columns，按主窗 size() 更新）
    m_windowSizeLabel = new QLabel(this);
    m_windowSizeLabel->setObjectName(QStringLiteral("WindowSizeLabel"));
    statusBar()->addPermanentWidget(m_windowSizeLabel);
    updateWindowSizeLabel();

    // 证据: statusbar.config:44-65 Ln/Ch（无终端 caret 数据前占位 1:1）
    m_caretLabel = new QLabel(this);
    m_caretLabel->setObjectName(QStringLiteral("CaretPositionLabel"));
    m_caretLabel->setText(m_locale.tr(QStringLiteral("Ln %1 Ch %2")).arg(1).arg(1));
    statusBar()->addPermanentWidget(m_caretLabel);

    // 证据: statusbar.config:66-90 scheme 按钮（InstantPopup 菜单，选中仅更新 label）
    m_schemeButton = new QToolButton(this);
    m_schemeButton->setObjectName(QStringLiteral("SchemeButton"));
    m_schemeButton->setAutoRaise(true);
    m_schemeButton->setPopupMode(QToolButton::InstantPopup);
    m_schemeButton->setText(ThemeManager::instance().currentTheme());
    auto *schemeMenu = new QMenu(m_schemeButton);
    const QStringList schemes = SchemeManager::instance().schemeNames();
    for (const QString &scheme : schemes) {
        QAction *action = schemeMenu->addAction(scheme);
        connect(action, &QAction::triggered, this, [this, scheme]() {
            m_schemeButton->setText(scheme);
            // shortcut: 仅更新 label，未调用 setScheme 应用配色（原版 Terminal.SchemeList script）, 终端配色切换接入后补
        });
    }
    m_schemeButton->setMenu(schemeMenu);
    statusBar()->addPermanentWidget(m_schemeButton);

    // 证据: statusbar.config:91-98 时钟（window.setInterval 2000ms，toLocaleString 等效）
    m_clockLabel = new QLabel(this);
    m_clockLabel->setObjectName(QStringLiteral("ClockLabel"));
    statusBar()->addPermanentWidget(m_clockLabel);

    // 证据: statusbar.config:99-103 Issues 链接
    auto *issuesLabel = new QLabel(this);
    issuesLabel->setObjectName(QStringLiteral("IssuesLabel"));
    issuesLabel->setTextFormat(Qt::RichText);
    issuesLabel->setText(QStringLiteral(
        "<a href=\"https://www.github.com/kingtoolbox/windterm/issues\" style=\"text-decoration:none;\">🐛 WindTerm Issues</a>"));
    issuesLabel->setOpenExternalLinks(true);
    statusBar()->addPermanentWidget(issuesLabel);

    // 证据: statusbar.config:104-113 锁屏按钮
    auto *lockButton = new QToolButton(this);
    lockButton->setObjectName(QStringLiteral("LockScreenButton"));
    lockButton->setAutoRaise(true);
    lockButton->setText(QStringLiteral("🔒 ") + m_locale.tr(QStringLiteral("Lock Screen")));
    connect(lockButton, &QToolButton::clicked, this, []() { Q_UNIMPLEMENTED(); });
    statusBar()->addPermanentWidget(lockButton);

    m_clockTimer = new QTimer(this);
    connect(m_clockTimer, &QTimer::timeout, this, &MainWindow::updateClock);
    m_clockTimer->start(2000);
    updateClock();
}

void MainWindow::initActionRegistry()
{
    ActionRegistry::instance().load(Assets::dir() + QStringLiteral("/config/wind.actions"));
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

    // B6：terminal.startupSessions（wind.config:69 当前 LastSessions）。
    // 自动恢复会话需先逆上次会话集存储位置；实现期只读不连，避免自动外连用户真机会话
    const QString startupSessions = WindConfig::instance().valueToString(
        QStringLiteral("terminal.startupSessions"), QStringLiteral("NoSessions"));
    if (startupSessions == QStringLiteral("LastSessions")) {
        // shortcut: LastSessions 自动恢复会话挂账,需先逆上次会话集存储位置;避免实现期自动外连用户真机会话
    } else if (!startupSessions.isEmpty() && startupSessions != QStringLiteral("NoSessions")) {
        // shortcut: startupSessions 其他取值语义未逆, 逆出会话集存储/启动策略后补
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings;
    settings.setValue(QStringLiteral("application/windowGeometry"), saveGeometry());
    QMainWindow::closeEvent(event);
}

// 证据: statusbar.config:29-31 Window %1×%2：无终端 screenSizeChanged，按主窗 resize 更新
void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    updateWindowSizeLabel();
}

void MainWindow::updateWindowSizeLabel()
{
    if (!m_windowSizeLabel)
        return;
    m_windowSizeLabel->setText(
        m_locale.tr(QStringLiteral("Window %1×%2")).arg(size().width()).arg(size().height()));
}

void MainWindow::updateClock()
{
    // 证据: statusbar.config:95 date.toLocaleString() → system locale 短格式
    m_clockLabel->setText(QLocale::system().toString(QDateTime::currentDateTime(), QLocale::ShortFormat));
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

// 懒建+插入（证据 0x85ad2e lazyCreateQuickBar、0x85a7a6 顺序：SearchPane 之后、TransferBar 之前）
QuickBar *MainWindow::ensureQuickBar()
{
    if (!m_quickBar) {
        m_quickBar = new QuickBar;
        m_quickBar->hide();
        QWidget *central = centralWidget();
        if (auto *vs = qobject_cast<QSplitter *>(central)) {
            const int at = m_transferBar ? vs->indexOf(m_transferBar) : vs->indexOf(m_searchPane) + 1;
            vs->insertWidget(at, m_quickBar);
        }
    }
    return m_quickBar;
}

void MainWindow::toggleQuickBar()
{
    QuickBar *bar = ensureQuickBar();
    bar->setVisible(bar->isHidden());
}

void MainWindow::onPlaceholderAction()
{
    Q_UNIMPLEMENTED();
}
