#include "MainWindow.h"

#include <QAction>
#include <QJsonArray>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QStackedWidget>
#include <QStatusBar>
#include <QTabBar>
#include <QTime>
#include <QTimer>
#include <QVBoxLayout>
#include <QDockWidget>

#include "core/ThemeManager.h"
#include "panes/FilerPane.h"
#include "panes/OutlinePane.h"
#include "panes/SenderPane.h"
#include "panes/SessionPane.h"
#include "panes/TransferPane.h"
#include "widgets/CommandButtonBar.h"
#include "widgets/MuxPaneGroup.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_muxPaneGroup(nullptr)
    , m_commandButtonBar(nullptr)
    , m_clockLabel(nullptr)
    , m_clockTimer(nullptr)
{
    setWindowTitle(tr("WindTerm"));
    resize(1200, 800);

    ThemeManager::instance().setTheme(QStringLiteral("default"));

    createMenus();
    createCentralWidget();
    createDocks();
    createStatusBar();
}

void MainWindow::createMenus()
{
    auto addMenu = [this](const QString &title, const QStringList &items) {
        QMenu *menu = menuBar()->addMenu(title);
        for (const QString &item : items) {
            QAction *action = menu->addAction(item);
            connect(action, &QAction::triggered, this, &MainWindow::onPlaceholderAction);
        }
    };

    addMenu(tr("&Session"), {tr("New Session"), tr("Open Session"), tr("Close Session")});
    addMenu(tr("&Edit"), {tr("Copy"), tr("Paste"), tr("Select All")});
    addMenu(tr("&Search"), {tr("Find"), tr("Find Next"), tr("Find Previous")});
    addMenu(tr("Se&lection"), {tr("Select Line"), tr("Select Word")});
    addMenu(tr("&Goto"), {tr("Next Tab"), tr("Previous Tab")});
    addMenu(tr("&View"), {tr("Toggle Filer"), tr("Toggle Session"), tr("Full Screen")});
    addMenu(tr("&Mode"), {tr("Normal Mode"), tr("Remote Mode")});
    addMenu(tr("&Window"), {tr("New Window"), tr("Close Window")});
    addMenu(tr("&Help"), {tr("Help"), tr("About")});
}

void MainWindow::createCentralWidget()
{
    auto *central = new QWidget(this);
    auto *layout = new QVBoxLayout(central);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    m_muxPaneGroup = new MuxPaneGroup(central);
    m_commandButtonBar = new CommandButtonBar(QJsonArray(), central);

    layout->addWidget(m_muxPaneGroup, 1);
    layout->addWidget(m_commandButtonBar);

    setCentralWidget(central);
}

void MainWindow::createDocks()
{
    auto *filerDock = new QDockWidget(tr("Filer"), this);
    filerDock->setObjectName(QStringLiteral("FilerDock"));
    filerDock->setWidget(new FilerPane(filerDock));
    addDockWidget(Qt::LeftDockWidgetArea, filerDock);

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
    transferDock->setWidget(createSenderTransferTabs());
    addDockWidget(Qt::BottomDockWidgetArea, transferDock);
}

QWidget *MainWindow::createSenderTransferTabs()
{
    auto *container = new QWidget;
    auto *layout = new QVBoxLayout(container);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    auto *tabs = new QTabBar(container);
    tabs->addTab(tr("Sender"));
    tabs->addTab(tr("Transfer"));

    auto *stack = new QStackedWidget(container);
    stack->addWidget(new SenderPane(stack));
    stack->addWidget(new TransferPane(stack));

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

void MainWindow::updateClock()
{
    m_clockLabel->setText(QTime::currentTime().toString(QStringLiteral("HH:mm:ss")));
}

void MainWindow::onPlaceholderAction()
{
    Q_UNIMPLEMENTED();
}
