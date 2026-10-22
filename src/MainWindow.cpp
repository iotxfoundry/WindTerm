#include "MainWindow.h"

#include <QAction>
#include <QCloseEvent>
#include <QDockWidget>
#include <QJsonArray>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QSettings>
#include <QStackedWidget>
#include <QStatusBar>
#include <QTabBar>
#include <QTime>
#include <QTimer>
#include <QVBoxLayout>

#include "core/ThemeManager.h"
#include "panes/ExplorerPane.h"
#include "panes/FilerPane.h"
#include "panes/OutlinePane.h"
#include "panes/OutputPane.h"
#include "panes/SearchPane.h"
#include "panes/SenderPane.h"
#include "panes/SessionPane.h"
#include "panes/ShellPane.h"
#include "panes/TransferPane.h"
#include "widgets/AppletBar.h"
#include "widgets/MuxPaneGroup.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_locale(LocaleManager::instance())
    , m_muxPaneGroup(nullptr)
    , m_appletBar(nullptr)
    , m_clockLabel(nullptr)
    , m_clockTimer(nullptr)
{
    setWindowTitle(tr("WindTerm"));
    resize(1200, 800);
    setAttribute(Qt::WA_DeleteOnClose);

    const double opacity = QSettings().value(QStringLiteral("application/windowOpacity"), 1.0).toDouble();
    if (opacity > 0.0 && opacity < 1.0)
        setWindowOpacity(opacity);

    ThemeManager::instance().setTheme(QStringLiteral("default"));
    m_locale.load(QStringLiteral("assets/locales/zh-CN.locale"));

    createMenus();
    createCentralWidget();
    createDocks();
    createStatusBar();

    QTimer::singleShot(0, this, &MainWindow::onRestoreLayout);
}

void MainWindow::createMenus()
{
    auto addMenu = [this](const QString &title, const QStringList &items) {
        QString plain = title;
        plain.remove(QLatin1Char('&')); // locale key 不含助记符 &
        QMenu *menu = menuBar()->addMenu(m_locale.tr(plain));
        for (const QString &item : items) {
            QAction *action = menu->addAction(m_locale.tr(item));
            connect(action, &QAction::triggered, this, &MainWindow::onPlaceholderAction);
        }
    };

    addMenu(QStringLiteral("&Session"), {QStringLiteral("New Session"), QStringLiteral("Open Session"), QStringLiteral("Close Session")});
    addMenu(QStringLiteral("&Edit"), {QStringLiteral("Copy"), QStringLiteral("Paste"), QStringLiteral("Select All")});
    addMenu(QStringLiteral("&Search"), {QStringLiteral("Find"), QStringLiteral("Find Next"), QStringLiteral("Find Previous")});
    addMenu(QStringLiteral("Se&lection"), {QStringLiteral("Select Line"), QStringLiteral("Select Word")});
    addMenu(QStringLiteral("&Goto"), {QStringLiteral("Next Tab"), QStringLiteral("Previous Tab")});
    addMenu(QStringLiteral("&View"), {QStringLiteral("Toggle Filer"), QStringLiteral("Toggle Session"), QStringLiteral("Full Screen")});
    addMenu(QStringLiteral("&Mode"), {QStringLiteral("Normal Mode"), QStringLiteral("Remote Mode")});
    addMenu(QStringLiteral("&Window"), {QStringLiteral("New Window"), QStringLiteral("Close Window")});
    addMenu(QStringLiteral("&Help"), {QStringLiteral("Help"), QStringLiteral("About")});
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
    statusBar()->addWidget(new QLabel(tr("Ready"), this));
    statusBar()->addPermanentWidget(new QLabel(tr("Remote Mode"), this));
    statusBar()->addPermanentWidget(new QLabel(tr("Ln 1 Ch 1"), this));
    statusBar()->addPermanentWidget(new QLabel(tr("localhost"), this));

    m_clockLabel = new QLabel(this);
    statusBar()->addPermanentWidget(m_clockLabel);

    m_clockTimer = new QTimer(this);
    connect(m_clockTimer, &QTimer::timeout, this, &MainWindow::updateClock);
    m_clockTimer->start(1000);
    updateClock();
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
