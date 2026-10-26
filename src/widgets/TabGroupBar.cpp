#include "TabGroupBar.h"

#include <QApplication>
#include <QEvent>
#include <QHBoxLayout>
#include <QLabel>
#include <QMenu>
#include <QMouseEvent>
#include <QPainter>
#include <QStyle>
#include <QTimer>
#include <QToolButton>
#include <QWidgetAction>

#include "ActionIcons.h"
#include "core/ThemeManager.h"

namespace {

// R45：hover 定时区间下限 100ms（0x005ad4a6 cvttsd2si(v*1000) 后 cmovl 0x64 夹取）
constexpr int kMinHoverMs = 100;
// 秒→ms 乘数（0x005ad4a6 mulsd [c8b308]=1000.0）
constexpr double kSecondsToMs = 1000.0;

} // namespace

TabGroupBar::TabGroupBar(QWidget *parent)
    : QTabBar(parent)
{
    // 0x005aec28：TabBar 建面时 setAttribute(WA_Hover)（0x005aef45 段 attribute(2,1)
    // 面）——leaveEvent/MouseMove 原生路径依赖 hover 属性
    setAttribute(Qt::WA_Hover, true);
}

// ── R45 hoverToSelect（0x005ad4a6/0x005aa91e/0x005abfd8）──

void TabGroupBar::setHoverToSelect(double seconds)
{
    if (seconds > 0.0) {
        if (!m_hoverTimer) {
            m_hoverTimer = new QTimer(this);
            connect(m_hoverTimer, &QTimer::timeout, this, [this]() {
                // 0x005aa91e：超时且 hover 位有效（非 -1）→ setCurrentIndex（0x005a6bcc 链）
                if (m_hoverIndex != -1)
                    setCurrentIndex(m_hoverIndex);
            });
        }
        int ms = int(seconds * kSecondsToMs);
        if (ms < kMinHoverMs)
            ms = kMinHoverMs; // 0x005ad4a6 下限夹取
        m_hoverTimer->setInterval(ms);
    } else {
        // ≤0：删定时器（0x005ad4a6 ≤0 分支 delete+0x48 清零）
        delete m_hoverTimer;
        m_hoverTimer = nullptr;
        m_hoverIndex = -1;
    }
}

bool TabGroupBar::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == this) {
        switch (event->type()) {
        case QEvent::MouseMove: {
            // 0x005abfd8 MouseMove(5)：tabAt 变化→记位+start（定时器存在=启用）。
            // 0x005abfd8 反汇编坐标取最近整数（+0x28/+0x20 四分舍入面）
            if (m_hoverTimer) {
                const QPoint pos = static_cast<QMouseEvent *>(event)->pos();
                const int index = tabAt(pos);
                if (index != m_hoverIndex) {
                    m_hoverIndex = index;
                    m_hoverTimer->start();
                }
            }
            break;
        }
        case QEvent::Leave:
            // 0x005abfd8 Leave(0xb)：位清 -1+stop
            m_hoverIndex = -1;
            if (m_hoverTimer)
                m_hoverTimer->stop();
            break;
        case QEvent::EnabledChange:
            // 0x005abfd8 EnabledChange(0x62)：刷新滚动钮可用（0x005aa862 溢出面同源）
            refreshScrollButtons();
            break;
        default:
            break;
        }
    }
    return QTabBar::eventFilter(watched, event);
}

// 鼠标面挂 event()（QTabBar::mouseMoveEvent 基类实现在 event() 层拦截 MouseMove，
// mouseMoveEvent 重写是否被调取决于基类 event 分派——加 qDebug 调试已证实此路）；
// 0x005abfd8 的 eventFilter 是挂 TabBar 上的外部过滤器，同体实现= event 双口同派
bool TabGroupBar::event(QEvent *event)
{
    switch (event->type()) {
    case QEvent::MouseMove:
        mouseMoveEvent(static_cast<QMouseEvent *>(event));
        return true;
    case QEvent::Leave:
        leaveEvent(event);
        return true;
    default:
        return QTabBar::event(event);
    }
}

void TabGroupBar::mouseMoveEvent(QMouseEvent *event)
{
    if (m_hoverTimer) {
        const int index = tabAt(event->pos());
        if (index != m_hoverIndex) {
            m_hoverIndex = index;
            m_hoverTimer->start();
        }
    }
    QTabBar::mouseMoveEvent(event);
}

void TabGroupBar::leaveEvent(QEvent *event)
{
    m_hoverIndex = -1;
    if (m_hoverTimer)
        m_hoverTimer->stop();
    QTabBar::leaveEvent(event);
}

// ── R47 滚动钮（0x005aec28 建面/0x005aa862 溢出态/0x005ab6ee 步进）──

void TabGroupBar::setScrollButtons(QToolButton *left, QToolButton *right)
{
    m_scrollLeft = left;
    m_scrollRight = right;
    for (QToolButton *button : {m_scrollLeft, m_scrollRight}) {
        if (!button)
            continue;
        // 0x005aec28：初始 hide+disabled+autoRepeat；clicked→scroll_step（无动画类）
        button->hide();
        button->setEnabled(false);
        connect(button, &QToolButton::clicked, this, [this, button]() {
            scrollStep(button == m_scrollLeft ? -1 : 1);
        });
    }
    refreshScrollButtons();
}

// 0x005aa862 语义：溢出态刷钮显隐+可用（窄条必显隐 + 可用位双开门）
void TabGroupBar::refreshScrollButtons()
{
    // 溢出判定：QTabBar 无原生 API——sizeHint 宽>实际宽 即需滚动
    const bool overflow = sizeHint().width() > width();
    for (QToolButton *button : {m_scrollLeft, m_scrollRight}) {
        if (!button)
            continue;
        button->setVisible(overflow);
        button->setEnabled(overflow);
    }
}

void TabGroupBar::resizeEvent(QResizeEvent *event)
{
    QTabBar::resizeEvent(event);
    refreshScrollButtons(); // 布局变化同源（0x005aa862 singleShot 触发点等价面）
}

// 0x005ab6ee 步进：反汇编仅 setFocus(3)+centralStack 焦点回授（体 38B 全量）——
// 像素级滚动量静态不可达。QTabBar 无公开滚动 API（内建 usesScrollButtons 箭头已被
// 0x5ac522 裁定永不出现），骨架以 setCurrentIndex 同向步进近似（autoRepeat 连点=
// 逐签切换语义一致）
// shortcut: 步长未逆明(0x5ab6ee 体静态不可达), setCurrentIndex 步进近似挂账,
// 像素级滚动需自定义滚动层(0x5ac522 param_2=1 面), 反汇编升级后替换
void TabGroupBar::scrollStep(int dir)
{
    if (count() == 0)
        return;
    const int current = currentIndex();
    const int target = qBound(0, current + dir, count() - 1);
    if (target != current)
        setCurrentIndex(target);
}

// ── R46 per-tab 色（0x005a7b66/0x005a8b2e）──

void TabGroupBar::tabInserted(int index)
{
    m_tabColors.insert(qBound(0, index, m_tabColors.size()), QColor()); // 0x005a7800 默认无效色占位
}

void TabGroupBar::tabRemoved(int index)
{
    if (index >= 0 && index < m_tabColors.size())
        m_tabColors.remove(index);
}

void TabGroupBar::setTabColor(int index, const QColor &color)
{
    // 0x005a7b66 门卫：-1<index<count；异色才写+update(tabRect)
    if (index < 0 || index >= count() || index >= m_tabColors.size())
        return;
    if (m_tabColors[index] != color) {
        m_tabColors[index] = color;
        update(tabRect(index));
    }
}

QColor TabGroupBar::tabColor(int index) const
{
    return (index >= 0 && index < m_tabColors.size()) ? m_tabColors.at(index) : QColor();
}

// 0x005a8b2e 语义：默认绘制后按 per-tab 色叠 fillRect(tabRect,color)（无效不染）
void TabGroupBar::paintEvent(QPaintEvent *event)
{
    QTabBar::paintEvent(event);
    QPainter painter(this);
    for (int i = 0; i < count() && i < m_tabColors.size(); ++i) {
        if (m_tabColors.at(i).isValid())
            painter.fillRect(tabRect(i), m_tabColors.at(i));
    }
}

// ── TabListMenu（0x005b1c08 TabListMenu_buildItems 照搬）──

// 行件树（0x005b2c26 CloseButtonAction_vt12）：#MenuItemWidget(QHBoxLayout
// contentsMargins/2)[#IconLabel(pixmap 固定方形), #TextLabel(text\t序号),
// #CloseButton(king::close 图标, tooltip, autoRaise, 初始 hide)]
namespace {

QWidget *buildMenuItemWidget(QTabBar *bar, int index, std::function<void(int)> closeHandler,
                             QWidgetAction *action)
{
    auto *widget = new QWidget;
    widget->setObjectName(QStringLiteral("MenuItemWidget")); // 0x005b2450
    auto *iconLabel = new QLabel(widget);
    iconLabel->setObjectName(QStringLiteral("IconLabel")); // 0x005b1cfa
    auto *textLabel = new QLabel(widget);
    textLabel->setObjectName(QStringLiteral("TextLabel")); // 0x005b1d57
    auto *closeButton = new QToolButton(widget);
    closeButton->setObjectName(QStringLiteral("CloseButton")); // 0x005b1db4
    // 0x005b1e16：king::close 主题 SVG；0x005b1ec0 tooltip（tr 面）；
    // 0x005b1eef autoRaise+初始 hide（QSS :hover image 面由 gui.theme 承担）
    const QString theme = ThemeManager::instance().currentTheme();
    closeButton->setIcon(ActionIcons::iconFor(QStringLiteral("CloseButton"),
                                              QStringLiteral("king::close"), theme));
    closeButton->setToolTip(QObject::tr("Close"));
    closeButton->setAutoRaise(true);
    closeButton->hide();
    // 0x005b1f8d 链：clicked→置 action 关闭位（0x005b2bbd +0x32=1）→triggered 分流
    QObject::connect(closeButton, &QToolButton::clicked, action, [action, closeHandler]() {
        action->setProperty("closeRequested", true); // 0x005b2bbd 关闭位面
        emit action->triggered();                    // 0x005b2bbd triggered(SUB81(lVar1,0))
    });
    // 0x005b1fa6：文本 "tabText\t序号"（序号=Fun_005ab180 面，字符串感知）
    textLabel->setText(QStringLiteral("%1\t%2").arg(bar->tabText(index)).arg(index + 1));
    // 0x005b20b3：图标 pixmap 按 style PM_SmallIconSize 方形（0x41=PM_SmallIconSize）
    const int iconSize = bar->style()->pixelMetric(QStyle::PM_SmallIconSize);
    iconLabel->setPixmap(bar->tabIcon(index).pixmap(iconSize, iconSize));
    iconLabel->setFixedSize(iconSize, iconSize); // 0x005b2124 setFixedSize
    // 0x005b2144：action data=签位（0x005aa958 sender→data().toInt() 分流）
    action->setData(index);
    auto *layout = new QHBoxLayout(widget);
    layout->setContentsMargins(iconSize, 0, iconSize, 0); // 0x005b2c83 margins/2 面（16/2=8≈图标宽）
    layout->addWidget(iconLabel);
    layout->addWidget(textLabel, 1);
    layout->addWidget(closeButton);
    // 0x005aa958 行触发：关闭位→closeHandler(index)（0x005aa8c4→0x008fb5e0
    // tabCloseRequested 链；singleShot(0) 时序由菜单关闭后处理等价）
    QObject::connect(action, &QWidgetAction::triggered, action, [action, closeHandler]() {
        if (action->property("closeRequested").toBool() && closeHandler)
            closeHandler(action->data().toInt());
    });
    return widget;
}

} // namespace

QMenu *TabGroupBar::buildTabListMenu(QTabBar *bar, std::function<void(int)> closeHandler)
{
    auto *menu = new QMenu;
    menu->setObjectName(QStringLiteral("TabListMenu")); // 0x005b2918
    const int count = bar->count();
    if (count > 0) {
        // 逐签行（0x005b2399 循环）：当前签行 default 面由 QMenu::setDefaultAction
        // （0x005b2956）+行 state 属性（0x005b28be "Active"）承担
        QWidgetAction *defaultAction = nullptr;
        QVector<QWidgetAction *> rows;
        rows.reserve(count);
        for (int i = 0; i < count; ++i) {
            auto *action = new QWidgetAction(menu);
            action->setDefaultWidget(buildMenuItemWidget(bar, i, closeHandler, action));
            if (i == bar->currentIndex())
                defaultAction = action; // 0x005b216a currentIndex==i 记 default
            rows.append(action);
        }
        // 顶部 FilterEdit 行（0x005b25d4，prepend 到行表）：#CountLabel+FilterEdit
        // HBox；textChanged→过滤行可见+计数（menu_action_timeout_show 面骨架等价直连）
        auto *filterAction = new QWidgetAction(menu);
        auto *countLabel = new QLabel;
        countLabel->setObjectName(QStringLiteral("CountLabel")); // 0x005b2653
        auto *filterEdit = new FilterEdit;
        const int total = rows.size();
        countLabel->setText(QString::number(total)); // 0x005b27a2 初始计数
        auto *filterBox = new QWidget;
        auto *boxLayout = new QHBoxLayout(filterBox);
        boxLayout->setContentsMargins(0, 0, 0, 0);
        boxLayout->addWidget(countLabel);
        boxLayout->addWidget(filterEdit, 1); // 0x005b269d insertRtlAware(box,1)
        filterAction->setDefaultWidget(filterBox);
        // 过滤：textChanged→逐行 setVisible(text in tabText)+计数刷新
        QObject::connect(filterEdit, &QLineEdit::textChanged, menu,
                         [rows, countLabel, total, bar](const QString &text) {
                             int visible = 0;
                             for (QWidgetAction *action : rows) {
                                 const int index = action->data().toInt();
                                 const bool show = text.isEmpty()
                                     || bar->tabText(index).contains(text, Qt::CaseInsensitive);
                                 if (QWidget *w = action->defaultWidget())
                                     w->setVisible(show);
                                 if (show)
                                     ++visible;
                             }
                             countLabel->setText(QString::number(
                                 text.isEmpty() ? total : visible));
                         });
        // 0x005b2946 addActions（FilterEdit 行 prepend 已按构建序）+default action
        menu->addAction(filterAction);
        for (QWidgetAction *action : rows)
            menu->addAction(action);
        if (defaultAction)
            menu->setDefaultAction(defaultAction); // 0x005b2956
    }
    return menu;
}

void TabGroupBar::execTabListMenu(QTabBar *bar, QWidget *anchor,
                                  std::function<void(int)> closeHandler)
{
    if (!bar || !anchor)
        return;
    QMenu *menu = buildTabListMenu(bar, std::move(closeHandler));
    // 0x005b2946/0x005ac790：按钮 mapToGlobal exec，前后 setAutoRaise 按压态；
    // 0x005ac863 结束补发 Leave 刷新 hover 态
    auto *button = qobject_cast<QToolButton *>(anchor);
    if (button)
        button->setAutoRaise(false);
    menu->exec(anchor->mapToGlobal(QPoint(0, anchor->height())));
    if (button)
        button->setAutoRaise(true);
    QEvent leave(QEvent::Leave);
    QApplication::sendEvent(anchor, &leave);
    menu->deleteLater();
}
