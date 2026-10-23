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
#include "core/ThemeManager.h"

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

// king.svg 元素缺失时回退纯文字，避免零尺寸空按钮
void setIconOrText(QToolButton *button, const QIcon &icon, const QString &text)
{
    button->setIcon(icon);
    button->setText(icon.isNull() ? text : QString());
    button->setToolButtonStyle(icon.isNull() ? Qt::ToolButtonTextOnly : Qt::ToolButtonIconOnly);
}

} // namespace

MuxPaneGroup::MuxPaneGroup(QWidget *parent)
    : QWidget(parent)
    , m_tabBar(new QTabBar(this))
    , m_stack(new QStackedWidget(this))
    , m_scrollLeftButton(new QToolButton(this))
    , m_scrollRightButton(new QToolButton(this))
    , m_addButton(new QToolButton(this))
    , m_listButton(new QToolButton(this))
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

    m_addButton->setObjectName(QStringLiteral("TabAddButton"));
    // king::addTab（0x005acc3e TabAddButton）
    setIconOrText(m_addButton, ActionIcons::iconFor(QStringLiteral("TabAddButton"),
                                                   QStringLiteral("king::addTab"),
                                                   ThemeManager::instance().currentTheme()),
                  QStringLiteral("+"));
    // TabGroupButton（组切换）本场景无组概念
    // shortcut: TabGroupButton 组切换挂账, MuxPaneGroup 多组模式未实现(0x8bade2 工厂第4项)
    // 按钮无显式尺寸：gui.theme TabGroup QToolButton 无尺寸规则，TabBar_ctor(0x005a859a) 无尺寸常量 → 内容自适应
    m_listButton->setObjectName(QStringLiteral("TabListButton"));
    setIconOrText(m_listButton, ActionIcons::iconFor(QStringLiteral("TabListButton"),
                                                    QStringLiteral("king::listTab"),
                                                    ThemeManager::instance().currentTheme()),
                  QStringLiteral("\u2261"));
    // 两个滚动按钮行为挂账：滚动动画未实现
    // shortcut: TabScrollLeft/RightButton 行为挂账, 标签滚动动画未实现(0x005aec28)
    m_scrollLeftButton->setObjectName(QStringLiteral("TabScrollLeftButton"));
    setIconOrText(m_scrollLeftButton, ActionIcons::iconFor(QStringLiteral("TabScrollLeftButton"),
                                                          QStringLiteral("king::arrowLeft"),
                                                          ThemeManager::instance().currentTheme()),
                  QString());
    m_scrollRightButton->setObjectName(QStringLiteral("TabScrollRightButton"));
    setIconOrText(m_scrollRightButton, ActionIcons::iconFor(QStringLiteral("TabScrollRightButton"),
                                                           QStringLiteral("king::arrowRight"),
                                                           ThemeManager::instance().currentTheme()),
                  QString());

    auto *tabRow = new QHBoxLayout;
    tabRow->setContentsMargins(0, 0, 0, 0);
    tabRow->setSpacing(0);
    tabRow->addWidget(m_scrollLeftButton);
    tabRow->addWidget(m_tabBar, 1);
    tabRow->addWidget(m_scrollRightButton);
    tabRow->addWidget(m_addButton);
    tabRow->addWidget(m_listButton);
    m_tabBarRow = new QWidget(this);
    // 原版 setObjectName="ViewGroup"（KitWindow_setupBars 0x008bade2，0x008baf26，
    // 此前误记 TabGroup）；QMainWindow::setMenuWidget 挂 KitGroup 的 menuWidget 槽
    m_tabBarRow->setObjectName(QStringLiteral("ViewGroup"));
    // shortcut: ThemeManager 改写后 MuxPaneGroup>TabGroup 类规则仍不命中(无 TabGroup 类), 挂账
    m_tabBarRow->setLayout(tabRow);

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(m_tabBarRow);
    layout->addWidget(m_stack, 1);

    connect(m_tabBar, &QTabBar::currentChanged, m_stack, &QStackedWidget::setCurrentIndex);
    connect(m_tabBar, &QTabBar::tabCloseRequested, this, &MuxPaneGroup::onTabCloseRequested);
    connect(m_addButton, &QToolButton::clicked, this, &MuxPaneGroup::onAddSession);
    // TabListMenu 菜单本体挂账
    // shortcut: TabListButton 菜单挂账, TabListMenu 未实现(0x005acc3e)
    connect(m_listButton, &QToolButton::clicked, this, []() { Q_UNIMPLEMENTED(); });

    // profile terminal.startupSessions=NoSessions：原版启动无标签（空 tabBar 仅按钮组）
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
