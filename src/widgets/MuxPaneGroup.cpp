#include "MuxPaneGroup.h"

#include <QHBoxLayout>
#include <QIcon>
#include <QMessageBox>
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
    // 原版 TabGroup（QFrame：标签条+右侧按钮，0x005af896）以类名挂 objectName；
    // 骨架标签行容器实挂 "ViewGroup"（0x008bade2: 0x008baf26 setObjectName("ViewGroup")），
    // 供 gui.theme 改写后的 #ViewGroup 规则命中
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
    // 按钮无显式尺寸：gui.theme TabGroup QToolButton 无尺寸规则，TabBar_ctor(0x005a859a) 无尺寸常量 → 内容自适应
    m_menuButton->setObjectName(QStringLiteral("SessionMenuButton"));
    m_menuButton->setText(QStringLiteral("\u2261"));
    m_menuButton->setToolButtonStyle(Qt::ToolButtonTextOnly);

    auto *tabRow = new QHBoxLayout;
    tabRow->setContentsMargins(0, 0, 0, 0);
    tabRow->setSpacing(0);
    tabRow->addWidget(m_tabBar, 1);
    tabRow->addWidget(m_addButton);
    tabRow->addWidget(m_menuButton);
    m_tabBarRow = new QWidget(this);
    // 原版 setObjectName="ViewGroup"（KitWindow_setupBars 0x008bade2，0x008baf26，
    // 此前误记 TabGroup）；QMainWindow::setMenuWidget 挂 KitGroup 的 menuWidget 槽
    m_tabBarRow->setObjectName(QStringLiteral("ViewGroup"));
    m_tabBarRow->setLayout(tabRow);

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(m_tabBarRow);
    layout->addWidget(m_stack, 1);

    connect(m_tabBar, &QTabBar::currentChanged, m_stack, &QStackedWidget::setCurrentIndex);
    connect(m_tabBar, &QTabBar::tabCloseRequested, this, &MuxPaneGroup::onTabCloseRequested);
    connect(m_addButton, &QToolButton::clicked, this, &MuxPaneGroup::onAddSession);
    connect(m_menuButton, &QToolButton::clicked, this, []() { Q_UNIMPLEMENTED(); });

    // profile terminal.startupSessions=NoSessions：原版启动无标签（空 tabBar 仅 + ≡）
}

void MuxPaneGroup::addPane(const QString &title, const QColor &color)
{
    m_tabBar->addTab(dotIcon(color), title);
    m_stack->addWidget(new TerminalView(title, m_stack));
}

void MuxPaneGroup::onTabCloseRequested(int index)
{
    // 原版 pane_confirmClose(0x008df6c0) 有确认框；zh-CN.locale 有 "关闭会话" 键
    if (m_confirmClose
        && QMessageBox::question(this, tr("Close Session"), tr("Close this session?"))
               != QMessageBox::Yes)
        return;

    // 原版链：确认 → close+deleteLater → removeWidget（0x005ab2cc）
    auto *view = qobject_cast<TerminalView *>(m_stack->widget(index));
    if (view && view->session()) {
        view->session()->close();
        // 会话父挂 MuxPaneGroup，不随 view 销毁——显式 deleteLater 修泄漏
        view->session()->deleteLater();
    }
    if (view)
        view->deleteLater();
    m_tabBar->removeTab(index);
    m_stack->removeWidget(view);

    // 原版关闭后回焦相邻标签（FUN_005a236c）——最小实现：聚焦前一标签
    m_tabBar->setCurrentIndex(qMax(0, index - 1));
    // 组保留（原版 MuxDesktop 布局 0x008d9be0）：最后一个标签关闭后仅空栈，无占位
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
