#include "MainWindow.h"

#include <QAction>
#include <QCloseEvent>
#include <QDockWidget>
#include <QJsonArray>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QPalette>
#include <QPlainTextEdit>
#include <QSettings>
#include <QStackedWidget>
#include <QStatusBar>
#include <QTabBar>
#include <QTime>
#include <QTimer>
#include <QVBoxLayout>

#include "core/ActionRegistry.h"
#include "core/SchemeManager.h"
#include "core/ThemeManager.h"
#include "core/WindConfig.h"
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_locale(LocaleManager::instance())
    , m_muxPaneGroup(nullptr)
    , m_appletBar(nullptr)
    , m_readyLabel(nullptr)
    , m_clockLabel(nullptr)
    , m_clockTimer(nullptr)
{
    setWindowTitle(tr("WindTerm"));
    resize(1200, 800);
    setAttribute(Qt::WA_DeleteOnClose);

    WindConfig::instance().load(QStringLiteral("assets/config/wind.config"));

    const double opacity = WindConfig::instance().valueToDouble(QStringLiteral("application.windowOpacity"), 1.0);
    if (opacity > 0.0 && opacity < 1.0)
        setWindowOpacity(opacity);

    const QString theme = WindConfig::instance().valueToString(QStringLiteral("application.themeGui"), QStringLiteral("dige-black"));
    ThemeManager::instance().loadTheme(theme);
    ThemeManager::instance().apply();
    SchemeManager::instance().load();

    m_locale.load(QStringLiteral("assets/locales/zh-CN.locale"));

    createStatusBar();
    initActionRegistry();
    createMenus();
    createCentralWidget();

    const QColor terminalBackground = SchemeManager::instance().color(QStringLiteral("line.background"));
    if (terminalBackground.isValid()) {
        for (QPlainTextEdit *edit : m_muxPaneGroup->findChildren<QPlainTextEdit *>()) {
            QPalette palette = edit->palette();
            palette.setColor(QPalette::Base, terminalBackground);
            edit->setPalette(palette);
        }
    }

    createDocks();

    QTimer::singleShot(0, this, &MainWindow::onRestoreLayout);
}

QString MainWindow::makeMenuTitle(const QString &base, int n) const
{
    return n == 0 ? base + QStringLiteral(" (&0)") : base + QStringLiteral(" (&%1)").arg(n);
}

void MainWindow::createMenus()
{
    MenuConfig &menuConfig = MenuConfig::instance();
    if (menuConfig.load(QStringLiteral("assets/config/uiconfigs/menu.config")) && !menuConfig.menuNames().isEmpty()) {
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

void MainWindow::buildMenu(QMenu *menu, const QVector<MenuEntry> &entries)
{
    for (const MenuEntry &entry : entries) {
        switch (entry.type) {
        case MenuEntry::Action: {
            QString text = ActionRegistry::instance().actionText(entry.actionId);
            if (text.isEmpty())
                text = entry.actionId.section(QLatin1Char('.'), -1);
            text.remove(QLatin1Char('&'));

            QAction *action = menu->addAction(m_locale.tr(text));
            const QString iconName = ActionRegistry::instance().actionIcon(entry.actionId);
            if (!iconName.isEmpty()) {
                QString name = iconName;
                if (name.startsWith(QStringLiteral("king::")))
                    name.remove(0, 6);
                action->setIcon(ActionIcons::iconFor(name));
            }
            connect(action, &QAction::triggered, this, &MainWindow::onPlaceholderAction);
            break;
        }
        case MenuEntry::Separator:
            menu->addSeparator();
            break;
        case MenuEntry::Submenu:
            buildMenu(menu->addMenu(entry.title), entry.children);
            break;
        }
    }
}

void MainWindow::createCentralWidget()
{
    auto *central = new QWidget(this);
    auto *layout = new QVBoxLayout(central);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    m_muxPaneGroup = new MuxPaneGroup(central);
    m_appletBar = new AppletBar(QJsonArray(), central);

    layout->addWidget(m_muxPaneGroup, 1);
    layout->addWidget(m_appletBar);

    setCentralWidget(central);
}

void MainWindow::createDocks()
{
    auto *filerDock = new QDockWidget(tr("Filer"), this);
    filerDock->setObjectName(QStringLiteral("FilerDock"));
    filerDock->setWidget(new FilerPane(filerDock));
    addDockWidget(Qt::LeftDockWidgetArea, filerDock);

    auto *explorerDock = new QDockWidget(tr("Explorer"), this);
    explorerDock->setObjectName(QStringLiteral("ExplorerDock"));
    explorerDock->setWidget(new ExplorerPane(explorerDock));
    addDockWidget(Qt::LeftDockWidgetArea, explorerDock);
    splitDockWidget(filerDock, explorerDock, Qt::Vertical);
    explorerDock->hide(); // 初始收起，可从停靠面板菜单恢复

    auto *sessionDock = new QDockWidget(tr("Session"), this);
    sessionDock->setObjectName(QStringLiteral("SessionDock"));
    sessionDock->setWidget(new SessionPane(sessionDock));
    addDockWidget(Qt::RightDockWidgetArea, sessionDock);

    auto *outlineDock = new QDockWidget(tr("Outline"), this);
    outlineDock->setObjectName(QStringLiteral("OutlineDock"));
    outlineDock->setWidget(new OutlinePane(outlineDock));
    addDockWidget(Qt::RightDockWidgetArea, outlineDock);
    splitDockWidget(sessionDock, outlineDock, Qt::Vertical);

    auto *transferDock = new QDockWidget(tr("Sender | Transfer"), this);
    transferDock->setObjectName(QStringLiteral("SenderTransferDock"));
    transferDock->setWidget(createBottomTabs());
    addDockWidget(Qt::BottomDockWidgetArea, transferDock);
}

QWidget *MainWindow::createBottomTabs()
{
    auto *container = new QWidget;
    auto *layout = new QVBoxLayout(container);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    auto *tabs = new QTabBar(container);
    tabs->addTab(tr("Sender"));
    tabs->addTab(tr("Transfer"));
    tabs->addTab(tr("Output"));
    tabs->addTab(tr("Search"));
    tabs->addTab(tr("Shell"));

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
    m_readyLabel = new QLabel(tr("Ready"), this);
    statusBar()->addWidget(m_readyLabel);
    statusBar()->addPermanentWidget(new QLabel(tr("Remote Mode"), this));
    statusBar()->addPermanentWidget(new QLabel(tr("Ln 1 Ch 1"), this));
    statusBar()->addPermanentWidget(new QLabel(tr("localhost"), this));
    statusBar()->addPermanentWidget(new QLabel(ThemeManager::instance().currentTheme(), this));

    m_clockLabel = new QLabel(this);
    statusBar()->addPermanentWidget(m_clockLabel);

    m_clockTimer = new QTimer(this);
    connect(m_clockTimer, &QTimer::timeout, this, &MainWindow::updateClock);
    m_clockTimer->start(1000);
    updateClock();
}

void MainWindow::initActionRegistry()
{
    ActionRegistry &registry = ActionRegistry::instance();
    if (!registry.load(QStringLiteral("assets/config/wind.actions")))
        return;

    m_readyLabel->setText(m_readyLabel->text() + QStringLiteral(" · ")
                          + QString::number(registry.actionIds().size()) + QStringLiteral(" actions"));
}

void MainWindow::onRestoreLayout()
{
    QSettings settings;
    restoreGeometry(settings.value(QStringLiteral("application/windowGeometry")).toByteArray());
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

void MainWindow::onPlaceholderAction()
{
    Q_UNIMPLEMENTED();
}
