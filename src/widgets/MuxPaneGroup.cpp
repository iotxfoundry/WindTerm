#include "MuxPaneGroup.h"

#include <QHBoxLayout>
#include <QIcon>
#include <QPainter>
#include <QPixmap>
#include <QStackedWidget>
#include <QTabBar>

#include <QToolButton>
#include <QVBoxLayout>

#include "ActionIcons.h"
#include "TerminalView.h"

#include "core/LocalSession.h"
#include "core/Session.h"

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
    // 原版 TabGroup（QFrame：标签条+右侧按钮，0x005af896）以类名挂 objectName
    setObjectName(QStringLiteral("TabGroup"));
    m_tabBar->setExpanding(false);
    m_tabBar->setUsesScrollButtons(true);
    m_tabBar->setElideMode(Qt::ElideRight);
    m_tabBar->setMovable(true);
    m_tabBar->setTabsClosable(true);
    // 标签样式全部交 gui.theme（QTabBar::tab #dcdcdc/选中 #f5f5f5）；GUI 主题与终端 scheme 独立，
    // 原版无"终端暗色→标签变暗"联动（R16），勿在控件级内联 QSS 覆盖主题

    m_addButton->setObjectName(QStringLiteral("AddSessionButton"));
    // 原版 king::add 无图标文件 → 空图标回退文字（docs/phase10-findings.md §2）
    m_addButton->setText(QStringLiteral("+"));
    m_addButton->setToolButtonStyle(Qt::ToolButtonTextOnly);
    // shortcut: 24px 无数据证据，实机截图对照值；升级条件=反编译 TabBar 按钮创建点尺寸（0x005a859a）
    m_addButton->setFixedSize(24, 24);
    m_menuButton->setObjectName(QStringLiteral("SessionMenuButton"));
    m_menuButton->setText(QStringLiteral("\u2261"));
    m_menuButton->setToolButtonStyle(Qt::ToolButtonTextOnly);
    // shortcut: 24px 无数据证据，实机截图对照值；升级条件=反编译 TabBar 按钮创建点尺寸（0x005a859a）
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

void MuxPaneGroup::openSession(Session *session, const QString &title, const QColor &color)
{
    auto *view = new TerminalView(title, m_stack);
    view->attachSession(session);

    const int index = m_tabBar->addTab(dotIcon(color), title);
    m_stack->addWidget(view);
    m_tabBar->setCurrentIndex(index);
    m_stack->setCurrentWidget(view);
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
