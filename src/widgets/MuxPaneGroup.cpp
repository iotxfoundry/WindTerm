#include "MuxPaneGroup.h"

#include <QHBoxLayout>
#include <QIcon>
#include <QPainter>
#include <QPixmap>
#include <QStackedWidget>
#include <QTabBar>

#include "core/SchemeManager.h"
#include <QToolButton>
#include <QVBoxLayout>

#include "ActionIcons.h"
#include "TerminalView.h"

#include "core/LocalSession.h"

namespace {

QIcon dotIcon(const QColor &color)
{
    QPixmap pixmap(10, 10);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(color);
    painter.drawEllipse(0, 0, 9, 9);
    return QIcon(pixmap);
}

} // namespace

MuxPaneGroup::MuxPaneGroup(QWidget *parent)
    : QWidget(parent)
    , m_tabBar(new QTabBar(this))
    , m_stack(new QStackedWidget(this))
    , m_addButton(new QToolButton(this))
    , m_menuButton(new QToolButton(this))
{
    m_tabBar->setExpanding(false);
    m_tabBar->setUsesScrollButtons(true);
    m_tabBar->setElideMode(Qt::ElideRight);
    m_tabBar->setMovable(true);
    m_tabBar->setTabsClosable(true);
    // 标签色取自当前主题背景（line.background）判明暗——QSS 主题不改 QPalette，勿用调色板判断
    const QColor bg = SchemeManager::instance().color(QStringLiteral("line.background"));
    const bool dark = !bg.isValid() || bg.lightness() < 128;
    const QString hover = dark ? QStringLiteral("#2a2a2a") : QStringLiteral("#e0e0e0");
    const QString selected = dark ? QStringLiteral("#333333") : QStringLiteral("#c8c8c8");
    const QString tabText = dark ? QStringLiteral("#bbbbbb") : QStringLiteral("#333333");
    m_tabBar->setStyleSheet(QStringLiteral(
        "QTabBar::tab { padding: 2px 10px; max-height: 24px; margin-right: 1px;"
        " background: transparent; color: %1; }"
        "QTabBar::tab:hover { background: %2; }"
        "QTabBar::tab:selected { background: %3; }")
        .arg(tabText, hover, selected));

    m_addButton->setObjectName(QStringLiteral("AddSessionButton"));
    m_addButton->setIcon(ActionIcons::paintIcon(QStringLiteral("add"), QColor(QStringLiteral("#007acc")), 24));
    m_addButton->setIconSize(QSize(24, 24));
    m_addButton->setFixedSize(24, 24);
    m_menuButton->setObjectName(QStringLiteral("SessionMenuButton"));
    m_menuButton->setIcon(ActionIcons::paintIcon(QStringLiteral("menu"), QColor(QStringLiteral("#007acc")), 24));
    m_menuButton->setIconSize(QSize(24, 24));
    m_menuButton->setFixedSize(24, 24);

    auto *tabRow = new QHBoxLayout;
    tabRow->setContentsMargins(0, 0, 0, 0);
    tabRow->setSpacing(0);
    tabRow->addWidget(m_tabBar, 1);
    tabRow->addWidget(m_addButton);
    tabRow->addWidget(m_menuButton);

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addLayout(tabRow);
    layout->addWidget(m_stack, 1);

    connect(m_tabBar, &QTabBar::currentChanged, m_stack, &QStackedWidget::setCurrentIndex);
    connect(m_tabBar, &QTabBar::tabCloseRequested, this, &MuxPaneGroup::onTabCloseRequested);
    connect(m_addButton, &QToolButton::clicked, this, &MuxPaneGroup::onAddSession);
    connect(m_menuButton, &QToolButton::clicked, this, []() { Q_UNIMPLEMENTED(); });

    addPane(tr("Local SSH"), Qt::red);
    addPane(tr("Local Telnet"), Qt::green);
    addPane(tr("Ubuntu"), Qt::blue);
}

void MuxPaneGroup::addPane(const QString &title, const QColor &color)
{
    m_tabBar->addTab(dotIcon(color), title);
    m_stack->addWidget(new TerminalView(title, m_stack));
}

void MuxPaneGroup::onTabCloseRequested()
{
    Q_UNIMPLEMENTED();
}

void MuxPaneGroup::onAddSession()
{
    auto *session = new LocalSession(24, 80, this);
    auto *view = new TerminalView(tr("Local"), this);
    view->attachSession(session);

    const int index = m_tabBar->addTab(dotIcon(Qt::gray), tr("Local"));
    m_stack->addWidget(view);
    m_tabBar->setCurrentIndex(index);
    m_stack->setCurrentWidget(view);

    session->start();
}
