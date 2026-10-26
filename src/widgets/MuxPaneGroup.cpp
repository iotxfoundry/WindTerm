#include "MuxPaneGroup.h"

#include <QHBoxLayout>
#include <QIcon>
#include <QMessageBox>
#include <QPainter>
#include <QPixmap>
#include <QSplitter>
#include <QStackedWidget>
#include <QTabBar>
#include <QTimer>

#include <QAction>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QMenu>
#include <QToolButton>
#include <QVBoxLayout>

#include <QDir>

#include "ActionIcons.h"
#include "KitGroup.h"
#include "MuxDesktop.h"
#include "MuxPane.h"
#include "MuxWindow.h"
#include "PaneManager.h"
#include "TabGroupBar.h"
#include "TerminalView.h"

#include "core/Assets.h"
#include "core/JsonText.h"
#include "core/LocalSession.h"
#ifdef WINDTERM_HAVE_SERIALPORT
#include "core/SerialSession.h"
#endif
#include "core/MenuConfig.h" // MenuEntry（R50 键解析与骨架 menu.config 管线同型）
#include "core/Session.h"
#include "core/SessionStore.h"
#include "core/TelnetSession.h"
#include "core/ThemeManager.h"
#include "core/WindConfig.h"

std::function<QWidget *()> MuxPaneGroup::s_createGroup;

namespace {

// 本组焦点 view（0x8d4166 targetWidget=无参取焦点 view；0x8ca6ca 缓存链骨架等价：
// focusWidget 沿父链属本组即取，否则退栈当前）
TerminalView *focusViewOf(const MuxPaneGroup *group)
{
    if (TerminalView *view = TerminalView::activeView(); view && group->isAncestorOf(view))
        return view;
    if (auto *stack = group->findChild<QStackedWidget *>())
        return qobject_cast<TerminalView *>(stack->currentWidget());
    return nullptr;
}

} // namespace

// 原版无 icon 缺失回退（0x5acaba：icon 缺失=空按钮），iconOrText 回退按逆明删除
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
    , m_tabBar(new TabGroupBar(this))
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
    // 0x5ac522 裁定（2026-10-24）：setUsesScrollButtons(false) 无条件调用；param_2 是
    // 自定义滚动层开关(+0x68)——KitGroup(ViewGroup) 场景 param_2=1 启用自定义 btnL/btnR，
    // MuxPaneGroup(0x8de936→param_2=0) 不启用：按钮保持初始 hide+disable（本类现状即对），
    // Qt 内置箭头两场景均不出现
    m_tabBar->setUsesScrollButtons(false);
    m_tabBar->setElideMode(Qt::ElideRight);
    m_tabBar->setMovable(true);
    m_tabBar->setTabsClosable(true);
    // 标签样式全部交 gui.theme（QTabBar::tab #dcdcdc/选中 #f5f5f5）；GUI 主题与终端 scheme 独立，
    // 原版无"终端暗色→标签变暗"联动（R16），勿在控件级内联 QSS 覆盖主题

    m_addButton->setObjectName(QStringLiteral("TabAddButton"));
    // king::addTab（0x005acc3e TabAddButton）
    m_addButton->setIcon(ActionIcons::iconFor(QStringLiteral("TabAddButton"),
                                              QStringLiteral("king::addTab"),
                                              ThemeManager::instance().currentTheme()));
    // TabGroupButton（组切换）本场景无组概念
    // shortcut: TabGroupButton 组切换挂账, MuxPaneGroup 多组模式未实现(0x8bade2 工厂第4项)
    // 按钮无显式尺寸：gui.theme TabGroup QToolButton 无尺寸规则，TabBar_ctor(0x005a859a) 无尺寸常量 → 内容自适应
    m_listButton->setObjectName(QStringLiteral("TabListButton"));
    m_listButton->setIcon(ActionIcons::iconFor(QStringLiteral("TabListButton"),
                                               QStringLiteral("king::listTab"),
                                               ThemeManager::instance().currentTheme()));
    // 两个滚动按钮行为挂账：滚动动画未实现
    // shortcut: TabScrollLeft/RightButton 行为挂账, 标签滚动动画未实现(0x005aec28)
    // 0x5acaba：scroll 按钮=内部 QAction（text=tooltip 同串、icon king::arrowLeft/Right、
    // property("iconFile")）+setDefaultAction+IconOnly+AutoRaise+SizePolicy(Preferred, Fixed)；
    // 原版无 icon 缺失文字回退，icon 缺失=空按钮
    auto makeScrollAction = [](const QString &text, const QIcon &icon, const QString &iconFile) {
        auto *action = new QAction(text, nullptr);
        action->setIcon(icon);
        action->setProperty("iconFile", iconFile);
        return action;
    };
    m_scrollLeftButton->setObjectName(QStringLiteral("TabScrollLeftButton"));
    m_scrollLeftButton->setDefaultAction(makeScrollAction(
        QStringLiteral("TabScrollLeftButton"),
        ActionIcons::iconFor(QStringLiteral("TabScrollLeftButton"),
                             QStringLiteral("king::arrowLeft"),
                             ThemeManager::instance().currentTheme()),
        QStringLiteral("king::arrowLeft")));
    m_scrollRightButton->setObjectName(QStringLiteral("TabScrollRightButton"));
    m_scrollRightButton->setDefaultAction(makeScrollAction(
        QStringLiteral("TabScrollRightButton"),
        ActionIcons::iconFor(QStringLiteral("TabScrollRightButton"),
                             QStringLiteral("king::arrowRight"),
                             ThemeManager::instance().currentTheme()),
        QStringLiteral("king::arrowRight")));
    for (auto *button : {m_scrollLeftButton, m_scrollRightButton}) {
        button->setToolButtonStyle(Qt::ToolButtonIconOnly);
        button->setAutoRaise(true);
        button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    }
    // 0x5aee00：AutoRepeat 仅 btnL/btnR 单独设；初始隐藏禁用（无溢出时）
    m_scrollLeftButton->hide();
    m_scrollLeftButton->setEnabled(false);
    m_scrollLeftButton->setAutoRepeat(true);
    m_scrollRightButton->hide();
    m_scrollRightButton->setEnabled(false);
    m_scrollRightButton->setAutoRepeat(true);
    // R47（0x005aec28/0x005ab6ee）：滚动钮挂标签条（autoRepeat 连点步进、溢出态刷
    // 显隐可用、无动画——原版实证）
    m_tabBar->setScrollButtons(m_scrollLeftButton, m_scrollRightButton);
    // QTabBar 内建箭头冲突已裁定（0x5ac522 逐行）：setupUi 末尾与 MuxPaneGroup 均
    // param_2=0——内建箭头永不出现（setUsesScrollButtons(false) 无条件），前证据 B 的
    // 分拣过滤器在无箭头状态下白装；保持 false 正确

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
    // R47 TabListMenu（0x005b1c08）：平铺行+FilterEdit+CountLabel；行关闭→本类关闭链
    connect(m_listButton, &QToolButton::clicked, this, [this]() {
        TabGroupBar::execTabListMenu(m_tabBar, m_listButton,
                                     [this](int index) { onTabCloseRequested(index); });
    });

    // R45 hoverToSelect（0x008dea8d MuxPaneGroup_setupUi 末段：QVariant("tabbar.
    // hoverToSelect").toDouble()→0x005ad4a6 建/删定时器；wind.config:34=0.2s）
    m_tabBar->setHoverToSelect(
        WindConfig::instance().valueToDouble(QStringLiteral("tabbar.hoverToSelect"), 0.0));

    // profile terminal.startupSessions=NoSessions：原版启动无标签（空 tabBar 仅按钮组）
}

// ── P7b：tmux pane 组模式（0x8de936/0x8dece0 结构差异点修正，KitGroup 场景不受影响）──

void MuxPaneGroup::initTmuxMode(bool attached)
{
    // 0x8de936：TabGroup objectName "PaneGroup"（KitGroup 场景保持 "ViewGroup" 0x8bade2
    // ——同名互斥，tmux 模式改挂）
    m_tabBarRow->setObjectName(QStringLiteral("PaneGroup"));
    m_tabBar->setTabsClosable(false); // 0x8dece0：tabsClosable=false
    setFocusPolicy(Qt::NoFocus);
    setProperty("doubleClickAction", QStringLiteral("RenameTab"));
    // attached=[ConfigButton] / 非 attached=[TabAddButton,TabListButton,ConfigButton]；
    // CloseButton visible=false（0x8dece0）。scroll 按钮 0x5ac522 裁定：初始隐藏禁用（维持）
    m_addButton->setVisible(!attached);
    m_listButton->setVisible(!attached);
    m_configButton = new QToolButton(this);
    m_configButton->setObjectName(QStringLiteral("ConfigButton"));
    m_configButton->setIcon(ActionIcons::iconFor(QStringLiteral("ConfigButton"),
                                                 QStringLiteral("king::config"),
                                                 ThemeManager::instance().currentTheme()));
    m_tabBarRow->layout()->addWidget(m_configButton);
    // R50（0x008de2d4）：clicked→menu.config "MuxPaneGroup" 键构 QMenu→按钮 mapToGlobal
    // exec（0x005ac790 前后 setAutoRaise 按压态）
    connect(m_configButton, &QToolButton::clicked, this, &MuxPaneGroup::showConfigMenu);
    // shortcut: hoverToSelect 延时未逆明(0x8de936 段), 挂账
}

void MuxPaneGroup::attachTmuxPane(MuxPane *pane, const QString &title)
{
    const int index = m_tabBar->addTab(title);
    m_stack->addWidget(pane);
    m_tabBar->setCurrentIndex(index);
    m_stack->setCurrentWidget(pane);
}

void MuxPaneGroup::setPaneTitle(const QString &title)
{
    if (m_tabBar->count() > 0)
        m_tabBar->setTabText(0, title);
}

// ── R50：ConfigButton→menu.config "MuxPaneGroup" 键弹菜单（0x008de2d4 照搬）──

// 0x00692ef0 menuconfig_build_menu：菜单配置系统按路径键构 QMenu；骨架 MenuConfig
// 只收 Kit 菜单名（menu("MuxPaneGroup") 空）→按 MainWindow::menuSection 同源解析
// （assets /config/uiconfigs/menu.config 的 "MuxPaneGroup" 数组；terminal/configs 同源）
static QVector<MenuEntry> muxPaneGroupMenuEntries()
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
    const QJsonArray array = doc.object().value(QStringLiteral("MuxPaneGroup")).toArray();
    QVector<MenuEntry> entries;
    for (const QJsonValue &value : array) {
        const QJsonObject object = value.toObject();
        if (object.contains(QStringLiteral("Separator")))
            entries.append(MenuEntry{MenuEntry::Separator, QString(), QString(), {}});
        else if (object.contains(QStringLiteral("Action")))
            entries.append(MenuEntry{MenuEntry::Action,
                                     object.value(QStringLiteral("Action")).toString(),
                                     QString(), {}});
    }
    return entries;
}

void MuxPaneGroup::showConfigMenu()
{
    if (!m_configButton)
        return;
    if (!m_configMenu) {
        m_configMenu = new QMenu(m_configButton);
        m_configMenu->setObjectName(QStringLiteral("MuxPaneGroupMenu"));
        // 0x00692ef0 建面：QAction 组（TogglePaneZoom/MovePaneToNewWindow|Split 四向|
        // RenamePane/RenameWindow/Tmux.RenameSession，2 分隔）；标题走 locale+ActionRegistry
        const QVector<MenuEntry> entries = muxPaneGroupMenuEntries();
        for (const MenuEntry &entry : entries) {
            if (entry.type == MenuEntry::Separator) {
                m_configMenu->addSeparator();
                continue;
            }
            QAction *action = m_configMenu->addAction(entry.actionId);
            action->setData(entry.actionId); // 0x00692ef0 面：动作带 id，触发按 id 分派
        }
        connect(m_configMenu, &QMenu::triggered, this, [this](QAction *action) {
            dispatchConfigAction(action->data().toString());
        });
    }
    // 0x005ac790：按钮 mapToGlobal exec，前后 setAutoRaise 按压态；结束补发 Leave
    m_configButton->setAutoRaise(false);
    m_configMenu->exec(m_configButton->mapToGlobal(QPoint(0, m_configButton->height())));
    m_configButton->setAutoRaise(true);
    QEvent leave(QEvent::Leave);
    QCoreApplication::sendEvent(m_configButton, &leave);
}

// R50 动作分派：已接线项落 desktop 命令桥/窗格引擎；其余空槽挂账（menu.config
// "MuxPaneGroup" 9 动作原样，0x008de2d4 键面）
void MuxPaneGroup::dispatchConfigAction(const QString &actionId)
{
    // tmux 桥（0x008de2d4 段 dynamic_cast<KitWindow> 后走 menuconfig，Tmux.RenameSession
    // 由 desktop 命令桥承接——骨架找宿主 MuxDesktop）
    if (actionId == QLatin1String("Tmux.RenameSession")) {
        // 宿主 desktop：沿父链 MuxWindow→desktop
        MuxDesktop *desktop = nullptr;
        for (QWidget *w = parentWidget(); w; w = w->parentWidget()) {
            if (auto *mw = qobject_cast<MuxWindow *>(w)) {
                desktop = mw->desktop();
                break;
            }
        }
        if (desktop)
            desktop->renameTmuxSession();
        else
            Q_UNIMPLEMENTED(); // 非 tmux 宿主无 desktop（挂账：原版 activeMuxDesktop 面）
        return;
    }
    // 其余 8 动作未接线（TogglePaneZoom/MovePaneToNewWindow/SplitPane*|RenamePane/
    // RenameWindow）——原版走 TabGroup pane 引擎对应槽，骨架对应体挂账
    Q_UNIMPLEMENTED();
}

// 测试驱动面：menu.config "MuxPaneGroup" 键动作集比对（showConfigMenu 同源 entries）
bool MuxPaneGroup::configMenuActionsForTest(const QStringList &expectedActionIds) const
{
    const QVector<MenuEntry> entries = muxPaneGroupMenuEntries();
    QStringList actual;
    for (const MenuEntry &entry : entries)
        if (entry.type == MenuEntry::Action)
            actual << entry.actionId;
    return actual == expectedActionIds;
}

void MuxPaneGroup::addPane(Session *session, const QString &title, const QColor &color)
{
    auto *view = new TerminalView(title, m_stack);
    view->attachSession(session);

    const int index = m_tabBar->addTab(dotIcon(color), title);
    // R46（0x5a7b66/0x7503a0）：per-tab 色面（dotIcon 既有面保留；无效色不染）
    m_tabBar->setTabColor(index, color);
    m_stack->addWidget(view);
    m_tabBar->setCurrentIndex(index);
    m_stack->setCurrentWidget(view);
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
    addPane(session, title, color);
}

void MuxPaneGroup::onAddSession()
{
    auto *session = new LocalSession(24, 80, this);
    addPane(session, tr("Local"), Qt::gray);

    session->start();
}

// 新组 view 重建（0x0089e9e0"用旧 view url/状态"语义）：uuid→SessionStore 查→按 protocol 分派
void MuxPaneGroup::openRebuiltSession(TerminalView *old)
{
    const QString uuid = old->session() ? old->session()->uuid() : QString();
    const QVariantMap entry = uuid.isEmpty() ? QVariantMap() : SessionStore::sessionByUuid(uuid);
    const QString protocol = entry.value(QStringLiteral("session.protocol")).toString();
    const QString target = entry.value(QStringLiteral("session.target")).toString();
    // R46（0x7503a0）：条目 session.color 命名色（缺键=无效不染）
    const QColor color = QColor(entry.value(QStringLiteral("session.color")).toString());
    const QString title = m_tabBar->tabText(m_stack->indexOf(old));

    if (protocol == QLatin1String("Shell")) {
        auto *local = new LocalSession(24, 80, this);
        local->start(target,
                     entry.value(QStringLiteral("process.arguments")).toString(),
                     entry.value(QStringLiteral("process.workingDirectory"))
                         .toString()
                         .replace(QStringLiteral("${HomeDir}"), QDir::homePath()));
        openSession(local, title, color);
    } else if (protocol.compare(QLatin1String("Telnet"), Qt::CaseInsensitive) == 0) {
        openSession(new TelnetSession(target, entry.value(QStringLiteral("session.port")).toInt(),
                                      24, 80, this),
                    title, color);
    } else if (protocol.compare(QLatin1String("Serial"), Qt::CaseInsensitive) == 0) {
#ifdef WINDTERM_HAVE_SERIALPORT
        openSession(new SerialSession(target,
                                      entry.value(QStringLiteral("serial.baudRate")).toInt(),
                                      entry.value(QStringLiteral("serial.dataBits")).toInt(),
                                      entry.value(QStringLiteral("serial.parity")).toString(),
                                      entry.value(QStringLiteral("serial.stopBits")).toInt(),
                                      entry.value(QStringLiteral("serial.flowControl")).toString(),
                                      this),
                    title, color);
#endif
    } else if (!entry.isEmpty()) {
        // shortcut: SSH 会话分屏重建挂账(认证链),新组空开
    } else {
        // shortcut: 无 uuid 本地会话参数未持久化(0x0089e9e0 旧 view 状态未接),开新空 bash
        auto *local = new LocalSession(24, 80, this);
        local->start();
        openSession(local, title, color);
    }
}

// A(0x8d4166) splitView：父 splitter（MuxRow）里再插新 KitGroup+新 MuxPaneGroup（落点 1）
void MuxPaneGroup::splitView(int dir)
{
    auto *row = qobject_cast<QSplitter *>(parentWidget());
    if (!row || !s_createGroup)
        return;

    // wanted 原式 2-(dir<2)：Left/Right→Horizontal(1)，Top/Bottom→Vertical(2)
    const Qt::Orientation wanted = static_cast<Qt::Orientation>(2 - (dir < 2));
    if (row->orientation() != wanted) {
        const int idx = row->indexOf(this);
        auto *ns = new QSplitter(wanted);
        ns->setChildrenCollapsible(false);
        row->replaceWidget(idx, ns);
        ns->addWidget(this);
        ns->show(); // 无父新建被收养后不自动显示（同 PaneManager::insert）
        row->show(); // 包裹替换后父 splitter 刷新（offscreen 无 expose 路径靠它落布局）
        row = ns;
    }

    TerminalView *old = focusViewOf(this);
    const int idx = row->indexOf(this);
    QWidget *newGroup = s_createGroup();
    newGroup->show(); // 新组先显示再插入（隐藏件插入 QSplitter 不分份）
    // Left/Top→插锚点前，Right/Bottom→插锚点后（0x8d4166）
    const bool before = (dir == 0 || dir == 2);
    row->insertWidget(before ? idx : idx + 1, newGroup);
    // 对半（各减 handleWidth 后 /2，0x8d4166）： sizes() 首拍未落（422,0）——先
    // show + processEvents 一拍再 setSizes（offscreen 无 expose 链，尺寸事件靠显式泵）
    QCoreApplication::processEvents();
    QList<int> sizes = row->sizes();
    if (sizes.size() == 2) {
        const int total = sizes.at(0) + sizes.at(1);
        if (total > row->handleWidth()) {
            const int half = qMax(1, (total - row->handleWidth()) / 2);
            sizes[0] = half;
            sizes[1] = half;
            row->setSizes(sizes);
        }
    }
    // 新组里重建焦点 view（0x0089e9e0）→激活焦点归新 view（0x8ba0f6 第三参=1）
    if (auto *newMux = newGroup->findChild<MuxPaneGroup *>()) {
        if (old)
            newMux->openRebuiltSession(old);
        if (TerminalView *fresh = newMux->findChild<TerminalView *>())
            fresh->setFocus(Qt::OtherFocusReason);
    }
}

// B(0x8d42e8) splitGroup：insertPaneSplitter 引擎（0x8d3e3c/0x5a277a 同款）组内再插一窗格，
// 旧组焦点 view 迁移到新组并激活（blockSignals 包裹）
void MuxPaneGroup::splitGroup(int dir)
{
    // 0x8d42e8 组内 view 数检查（<2 语义）：无可迁移即不拆
    if (m_stack->count() < 2)
        return;

    auto *newMux = new MuxPaneGroup;
    PaneManager::insert(nullptr, this, newMux, static_cast<Dir>(dir));

    auto *nstack = newMux->findChild<QStackedWidget *>();
    auto *ntab = newMux->findChild<QTabBar *>();
    if (TerminalView *view = focusViewOf(this); view && nstack && ntab) {
        const int idx = m_stack->indexOf(view);
        if (Session *session = view->session())
            session->setParent(newMux); // 会话随迁（原挂旧组，旧组销毁不牵连）
        {
            const QSignalBlocker b1(m_tabBar), b2(ntab), b3(m_stack), b4(nstack);
            const QString title = m_tabBar->tabText(idx);
            // R46：标签色随迁（0x5a7b66 per-tab 列表面；ntab 可能是裸 QTabBar——
            // 仅当同为 TabGroupBar 才带色迁移）
            const QColor color = m_tabBar->tabColor(idx);
            const int newIndex = ntab->addTab(dotIcon(color), title);
            if (auto *ntgb = qobject_cast<TabGroupBar *>(ntab))
                ntgb->setTabColor(newIndex, color);
            nstack->addWidget(view); // addWidget 重挂父=迁移
            m_tabBar->removeTab(idx);
            m_stack->removeWidget(view);
            ntab->setCurrentIndex(newIndex);
            nstack->setCurrentWidget(view);
        }
        view->setFocus(Qt::OtherFocusReason); // 0x8d42e8 迁移后激活
    }
}

// canCloseGroup 0x8cc916：全窗 KitGroup 数>1
bool MuxPaneGroup::canCloseGroup() const
{
    return window()->findChildren<KitGroup *>().count() > 1;
}

// closeGroup 0x8cc99c：QTimer::singleShot(0)→清理（0x8cee89 sweep + PaneManager 树清理）→焦点回归
void MuxPaneGroup::closeGroup()
{
    if (!canCloseGroup())
        return;
    // 本组 KitGroup（0x8c52fa 沿父链找）
    QWidget *grp = parentWidget();
    while (grp && !qobject_cast<KitGroup *>(grp))
        grp = grp->parentWidget();
    auto *kit = qobject_cast<KitGroup *>(grp);
    if (!kit)
        return;
    // 嵌套重建注记：外层 kit 含子组时只摘本 pane（原版兄弟结构无此分支）
    QWidget *unit
        = kit->findChildren<KitGroup *>().isEmpty() ? static_cast<QWidget *>(kit) : this;
    QWidget *top = window();
    QTimer::singleShot(0, this, [top, unit]() {
        for (TerminalView *view : unit->findChildren<TerminalView *>())
            if (Session *s = view->session())
                s->close(); // 组关随 view 级 close 链（防 pty 残留）
        // D(0x5a29e6)：结构化清理（尺寸移交/单子提升/向上递归/脱离件删除）
        PaneManager::cleanupEmptyTree(unit, unit);
        // 0x8cee89：残余空 splitter 扫除
        const auto splitters = top->findChildren<QSplitter *>();
        for (QSplitter *sp : splitters)
            if (sp->count() == 0)
                sp->deleteLater();
        // 焦点回归：剩余首 view
        const auto views = top->findChildren<TerminalView *>();
        if (!views.isEmpty())
            views.first()->setFocus(Qt::OtherFocusReason);
    });
}

// F(0x8ce784) 链：全 splitter 树深度优先收集 view → indexOf(当前)→±1 取模循环
// →setCurrentIndex+setFocus(OtherFocusReason)
static void collectViews(QWidget *w, QList<TerminalView *> &out)
{
    if (auto *sp = qobject_cast<QSplitter *>(w)) {
        for (int i = 0; i < sp->count(); ++i)
            collectViews(sp->widget(i), out);
    } else if (auto *kit = qobject_cast<KitGroup *>(w)) {
        collectViews(kit->centralWidget(), out); // 嵌套 QMainWindow：走 central 树
    } else if (auto *mux = qobject_cast<MuxPaneGroup *>(w)) {
        collectViews(mux->findChild<QStackedWidget *>(), out); // 组：走其 view 堆栈
    } else if (auto *st = qobject_cast<QStackedWidget *>(w)) {
        for (int i = 0; i < st->count(); ++i)
            collectViews(st->widget(i), out);
    } else if (auto *view = qobject_cast<TerminalView *>(w)) {
        out.append(view); // 叶（0x8ce784 收集面：QSplitter 树下的 view）
    }
}

void MuxPaneGroup::activateNextView(bool next)
{
    QList<TerminalView *> views;
    collectViews(window(), views);
    if (views.isEmpty())
        return;

    const int current = qMax(0, views.indexOf(focusViewOf(this)));
    TerminalView *target = views.at((current + (next ? 1 : -1) + views.size()) % views.size());
    if (auto *stack = qobject_cast<QStackedWidget *>(target->parentWidget())) {
        if (auto *tabBar = stack->parentWidget()->findChild<QTabBar *>())
            tabBar->setCurrentIndex(stack->indexOf(target)); // 0x8ce784 setCurrentIndex
    }
    target->setFocus(Qt::OtherFocusReason);
}
