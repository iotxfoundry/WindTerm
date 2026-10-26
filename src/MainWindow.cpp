#include "MainWindow.h"

#include <QAction>
#include <QApplication>
#include <QCloseEvent>
#include <QDir>

#include <QContextMenuEvent>
#include <QCursor>
#include <QEventLoop>
#include <QInputDialog>
#include <QMessageBox>
#include <QPointer>

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLabel>
#include <QLineEdit>
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
#include "core/ReopenHistory.h"
#include "core/SchemeManager.h"
#include "core/LocalSession.h"
#ifdef WINDTERM_HAVE_SERIALPORT
#include "core/SerialSession.h"
#endif
#include "core/Session.h"
#include "core/SessionStore.h"
#include "core/SshSession.h"
#include "core/TelnetSession.h"
#include "core/ThemeManager.h"
#include "core/ToolbarConfig.h"
#include "core/WindConfig.h"
#include "dialogs/ConnectDialog.h"
#include "dialogs/SessionSettingsDialog.h"
#include "panes/ExplorerPane.h"
#include "panes/FilerPane.h"
#include "panes/KitPane.h"
#include "panes/OutlinePane.h"
#include "panes/OutputPane.h"
#include "panes/SearchPane.h"
#include "panes/SenderPane.h"
#include "panes/SessionPane.h"
#include "panes/ShellPane.h"
#include "panes/TransferPane.h"
#include "transfer/TransferCenter.h"
#include "widgets/ActionIcons.h"
#include "widgets/CommandPalette.h"
#include "widgets/HighlightTextBar.h"
#include "widgets/KitGroup.h"
#include "widgets/MenuBarCorner.h"
#include "widgets/MuxPaneGroup.h"
#include "widgets/MuxDesktop.h"
#include "widgets/PaneHeader.h"
#include "widgets/QuickBar.h"
#include "widgets/Splitter.h"
#include "widgets/StatusBar.h"
#include "widgets/TerminalView.h"
#include "widgets/TransferBar.h"

namespace {

// P4 find 状态栏消息 thunk（0x74f5ac 执行链：状态栏 4s 消息——showMessageEx 已有；
// 静态函数指针收 MainWindow 实例——单窗骨架，最后建的 MainWindow 持有 m_statusBar）
static MainWindow *g_statusBarHost = nullptr;
static void statusMessageThunk(TerminalView *, const QString &text, int timeoutMs)
{
    if (g_statusBarHost) {
        if (StatusBar *sb = g_statusBarHost->findChild<StatusBar *>())
            sb->showMessageEx(text, timeoutMs);
    }
}

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

    // 分屏工厂注入（MuxPaneGroup::splitView 经此回调新建 KitGroup，widgets 层不依赖宿主）
    MuxPaneGroup::s_createGroup = [this]() { return createKitGroup(); };

    // P4 find 状态栏消息挂接（单窗骨架：thunk 取最后建的 MainWindow）
    g_statusBarHost = this;
    TerminalView::statusMessageHandler = &statusMessageThunk;

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
        auto *edit = new QLineEdit(toolBar);
        edit->setObjectName(QStringLiteral("AddressBarEdit"));
        // dige-black gui.theme:492 AddressBar > QLineEdit{...}：骨架地址栏无 BreadCrumb 容器，后代选择器不命中，
        // 内联同值复刻；多主题支持时移入 ThemeManager 适配段（shortcut）
        edit->setStyleSheet(QStringLiteral(
            "padding:4px;border:1px solid silver;background-color:white;"));
        edit->setPlaceholderText(QStringLiteral("ssh user@host"));
        edit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        connect(edit, &QLineEdit::returnPressed, this, &MainWindow::onAddressBarReturn);
        // 分屏新组各带地址框，m_addressBar 锚主组框（脚本/逻辑单指针）
        if (!m_addressBar)
            m_addressBar = edit;
        toolBar->addWidget(edit);
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

    // 原版 KitGroup 的 toolBar 区（工具栏行：标签行之下、终端之上，只占中部宽）。
    // 经 KitGroup::addToolBar 挂入（setupBars 0x008bade2 → QMainWindow::addToolBar 0x008bb07d）；
    // createCentral 里装配；分屏新组经 buildGroupToolBar 各建一份
    m_toolBar = buildGroupToolBar();
}

// 工具栏行构建（toolbar.config Standard 节；主组分屏新组共用，0x008bade2 addToolBar per group）
QToolBar *MainWindow::buildGroupToolBar()
{
    ToolbarConfig &config = ToolbarConfig::instance();
    const QString name = config.toolbarName();
    if (name.isEmpty())
        return nullptr;

    auto *toolBar = new QToolBar(name, this);
    // 原版 toolbar_build 产物 objectName="ToolBar"（0x00694276，title=tr("Standard")）；
    // "KitBar" 只属 QuickSwitcher（0x008b31b6），不得用于主窗工具栏
    toolBar->setObjectName(QStringLiteral("ToolBar"));
    toolBar->setMovable(false);

    for (const ToolbarEntry &entry : config.entries(name))
        addToolBarEntry(toolBar, entry);
    return toolBar;
}

// 焦点 view 沿父链找 MuxPaneGroup（0x8ca6ca kit_focus_widget 骨架等价）；无焦点回退主组
MuxPaneGroup *MainWindow::activeMuxGroup() const
{
    if (TerminalView *view = TerminalView::activeView()) {
        for (QWidget *w = view->parentWidget(); w; w = w->parentWidget())
            if (auto *group = qobject_cast<MuxPaneGroup *>(w))
                return group;
    }
    return m_muxPaneGroup;
}

// ── P7b：tmux 会话 GUI（I 节挂载）──

// shortcut: MuxDesktop 落位挂账(原版 TerminalWidget+0x1d0 关联),当前以 activeMuxGroup
// 当前页 stack 插页替换待真机定：tmux 模式启用时 MuxDesktop 顶替 TerminalView 显示
void MainWindow::attachMuxDesktop(TerminalView *view)
{
    if (!view || m_muxDesktops.contains(view))
        return;
    auto *desktop = new MuxDesktop(view, this);
    m_muxDesktops.insert(view, desktop);
    // %exit（tmuxModeExited）→恢复 TerminalView 显示并弃 desktop
    connect(desktop, &MuxDesktop::finished, this, [this, view]() { detachMuxDesktop(view); });
    if (auto *stack = qobject_cast<QStackedWidget *>(view->parentWidget())) {
        stack->addWidget(desktop);
        stack->setCurrentWidget(desktop);
    }
    view->hide(); // TerminalView 隐藏不销毁（%exit 恢复显示）
}

void MainWindow::detachMuxDesktop(TerminalView *view)
{
    auto it = m_muxDesktops.find(view);
    if (it == m_muxDesktops.end())
        return;
    MuxDesktop *desktop = it.value();
    m_muxDesktops.erase(it);
    if (auto *stack = qobject_cast<QStackedWidget *>(desktop->parentWidget())) {
        stack->setCurrentWidget(view);
        stack->removeWidget(desktop);
    }
    view->show();
    desktop->deleteLater();
}

MuxDesktop *MainWindow::activeMuxDesktop() const
{
    if (QWidget *focus = QApplication::focusWidget())
        for (auto it = m_muxDesktops.cbegin(); it != m_muxDesktops.cend(); ++it)
            if ((*it)->isAncestorOf(focus))
                return it.value();
    return m_muxDesktops.isEmpty() ? nullptr : m_muxDesktops.cbegin().value();
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
    // 地址栏新连非 user.sessions 条目，无 uuid（0x833db4 恢复仅对存量会话）
    m_muxPaneGroup->openSession(session, QStringLiteral("ssh %1").arg(dialog.host()), Qt::red);
    hookSshSession(session);
    // F3：start 立即返回，worker 线程跑连接链；对话框停留到 connected/failed 再关（保持原 UX 最小改）
    QPointer<SshSession> guard(session);
    QEventLoop wait;
    QObject::connect(session, &SshSession::connected, &wait, &QEventLoop::quit);
    QObject::connect(session, &Session::finished, &wait, &QEventLoop::quit);
    session->start(dialog.host(), dialog.port(), dialog.user(), dialog.password());
    wait.exec(); // 事件循环活着（UI 不卡）；finished 路径标签已由视图标退出
    if (guard && guard->isConnected())
        dialog.accept();
}

// user.sessions 双击接入（原版编辑即写 0x00806958，骨架只读）：user 无键 → user 留空
// F5：SSH 走原路径；Telnet/Shell/Serial 按 protocol 分派（真数据 protocol 有 "serial" 小写变体）
void MainWindow::connectSessionPane(SessionPane *pane)
{
    connect(pane, &SessionPane::sessionActivated, this,
            [this](const QString &host, int port, const QString &label) {
        if (!m_muxPaneGroup)
            return;

        Session *session = nullptr;
        QVariantMap entry;
        for (const SessionEntry &e : SessionStore::load()) {
            if (e.label == label) {
                entry = SessionStore::sessionByUuid(e.uuid);
                break;
            }
        }
        const QString protocol = entry.value(QStringLiteral("session.protocol")).toString();
        const QString uuid = entry.value(QStringLiteral("session.uuid")).toString();

        if (protocol == QLatin1String("Telnet")) {
            session = new TelnetSession(host, port > 0 ? port : 23, 24, 80, m_muxPaneGroup);
        } else if (protocol == QLatin1String("Shell")) {
            auto *local = new LocalSession(24, 80, m_muxPaneGroup);
            // ${HomeDir} → QDir::homePath()；args 空白分隔由 UnixPty 拆 argv
            QString workDir = entry.value(QStringLiteral("process.workingDirectory")).toString();
            workDir.replace(QStringLiteral("${HomeDir}"), QDir::homePath());
            if (local->start(host, entry.value(QStringLiteral("process.arguments")).toString(),
                             workDir)) {
                session = local;
            } else {
                delete local;
                return;
            }
        } else if (protocol.compare(QLatin1String("Serial"), Qt::CaseInsensitive) == 0) {
#ifdef WINDTERM_HAVE_SERIALPORT
            // serial.* 值字符串/数字混型——QVariant::toString 统一解析
            const QVariantMap &m = entry;
            auto *serial = new SerialSession(
                host,
                m.value(QStringLiteral("serial.baudRate")).toInt(),
                m.value(QStringLiteral("serial.dataBits")).toInt(),
                m.value(QStringLiteral("serial.parity")).toString(),
                m.value(QStringLiteral("serial.stopBits")).toInt(),
                m.value(QStringLiteral("serial.flowControl")).toString(),
                m_muxPaneGroup);
            session = serial;
            // 1d 串口打开失败状态栏瞬态提示（0x5a2e58 showMessageEx 机制）
            connect(serial, &SerialSession::openFailed, this, [this](const QString &message) {
                m_statusBar->showMessageEx(tr("串口打开失败: %1").arg(message), 4000);
            });
#else
            return; // 系统无 Qt SerialPort 组件，Serial 条目不接（挂账）
#endif
        } else {
            ConnectDialog dialog(this);
            dialog.setSpec(QString(), host, port > 0 ? port : 22);
            if (dialog.exec() != QDialog::Accepted || dialog.host().isEmpty())
                return;
            // F3：对话框停留到 connected/failed 再关（同 onAddressBarReturn 最小改）
            auto *ssh = new SshSession(24, 80, m_muxPaneGroup);
            hookSshSession(ssh);
            QPointer<SshSession> sshGuard(ssh);
            QEventLoop wait;
            QObject::connect(ssh, &SshSession::connected, &wait, &QEventLoop::quit);
            QObject::connect(ssh, &Session::finished, &wait, &QEventLoop::quit);
            ssh->start(dialog.host(), dialog.port(), dialog.user(), dialog.password());
            wait.exec();
            if (sshGuard && sshGuard->isConnected())
                dialog.accept();
            session = ssh;
        }

        // 0x833db4：恢复/重连以 session.uuid 查 user.sessions；双击条目按 label 匹配带 uuid
        session->setUuid(uuid);
        m_muxPaneGroup->openSession(session,
                                    label.isEmpty()
                                        ? QStringLiteral("telnet %1:%2").arg(host).arg(port)
                                        : label,
                                    Qt::red);
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

    // 0x66613a：wind.actions "state" JS 串存 property("state")，菜单 aboutToShow 时求值驱动
    // checked/checkable/enabled（ScriptHost::updateActionState 0x669086）
    const QString state = ActionRegistry::instance().actionState(actionId);
    if (!state.isEmpty())
        action->setProperty("state", state);

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
    // F4 写盘：新建会话=SessionSettingsDialog（空）→OK→appendOrReplace→SessionPane 刷新。
    // Terminal.NewSession（menu.config Session 节/toolbar）原走 ConnectDialog 的路径不动
    // （ConnectDialog 连接不落盘）；SessionPane.NewSession（Session Popup 节）同走此对话框
    if (actionId == QStringLiteral("Terminal.NewSession")
        || actionId == QStringLiteral("SessionPane.NewSession")) {
        connect(action, &QAction::triggered, this, [this]() {
            SessionSettingsDialog dialog(this);
            if (dialog.exec() != QDialog::Accepted)
                return;
            if (!SessionStore::appendOrReplace(dialog.entryValue()))
                return;
            if (auto *pane = findChild<SessionPane *>())
                pane->reload();
        });
        return action;
    }
    // ── P7b J 节：Tmux.* 7 动作（wind.actions script 面落 desktop 命令桥；原版经
    // window.activeMuxDesktop 直调——骨架以 activeMuxDesktop() 取件）──
    if (actionId.startsWith(QStringLiteral("Tmux."))) {
        connect(action, &QAction::triggered, this, [this, actionId, action]() {
            MuxDesktop *desktop = activeMuxDesktop();
            if (!desktop || !desktop->tmux())
                return;
            if (actionId == QStringLiteral("Tmux.AttachSession")
                || actionId == QStringLiteral("Tmux.KillSession")) {
                const QStringList names = desktop->tmuxSessionNames();
                if (names.isEmpty())
                    return; // wind.actions '[Session list is empty]'
                bool ok = false;
                const QString name = QInputDialog::getItem(
                    this, action->text().remove(QLatin1Char('&')), tr("Session:"), names, 0,
                    false, &ok);
                if (!ok)
                    return;
                if (actionId == QStringLiteral("Tmux.AttachSession"))
                    desktop->attachTmuxSession(name);
                else
                    desktop->killTmuxSession(name);
            } else if (actionId == QStringLiteral("Tmux.DetachClient")) {
                desktop->detachTmuxClient();
            } else if (actionId == QStringLiteral("Tmux.ExecuteTmuxCommand")) {
                desktop->executeTmuxCommand();
            } else if (actionId == QStringLiteral("Tmux.RenameSession")) {
                desktop->renameTmuxSession();
            } else if (actionId == QStringLiteral("Tmux.SelectLayout")) {
                // wind.actions text：7 布局列表（原文）
                const QStringList layouts = {
                    QStringLiteral("Even horizontal"), QStringLiteral("Even vertical"),
                    QStringLiteral("Main horizontal"), QStringLiteral("Main horizontal mirrored"),
                    QStringLiteral("Main vertical"), QStringLiteral("Main vertical mirrored"),
                    QStringLiteral("Tiled")};
                bool ok = false;
                const QString name = QInputDialog::getItem(this, action->text().remove(QLatin1Char('&')),
                                                           tr("Layout:"), layouts, 0, false, &ok);
                if (ok)
                    desktop->selectTmuxLayout(name);
            } else if (actionId == QStringLiteral("Tmux.SynchronizePanes")) {
                // wind.actions text：['On','Off'] 子菜单面——骨架以选择对话框等价（挂账）
                bool ok = false;
                const QString pick = QInputDialog::getItem(
                    this, action->text().remove(QLatin1Char('&')), tr("Synchronize panes:"),
                    {QStringLiteral("On"), QStringLiteral("Off")}, 0, false, &ok);
                if (ok)
                    desktop->synchronizeTmuxPanes(pick == QLatin1String("On"));
            }
        });
        return action;
    }
    // SessionPane.Property（Session Popup 节，wind.actions state=hasSelection）：
    // 编辑当前选中会话——条目动作 makeAction 无个体参数，特判从 SessionPane 取选中
    if (actionId == QStringLiteral("SessionPane.Property")) {
        connect(action, &QAction::triggered, this, [this]() {
            auto *pane = findChild<SessionPane *>();
            if (!pane)
                return;
            const QVariantMap entry = pane->selectedEntry();
            if (entry.isEmpty())
                return;
            SessionSettingsDialog dialog(this, entry);
            if (dialog.exec() != QDialog::Accepted)
                return;
            if (!SessionStore::appendOrReplace(dialog.entryValue()))
                return;
            pane->reload();
        });
        return action;
    }
    // P3 命令面板入口（0x768dfa 调用点传 ""/">"/"m"）；wind.keymaps Alt+S/Alt+;/Alt+B
    // 经上方 shortcut 机制自动携带
    if (actionId == QStringLiteral("Window.ShowPaletteAnything")
        || actionId == QStringLiteral("Window.ShowPaletteCommand")
        || actionId == QStringLiteral("Window.ShowPaletteMultiplexer")) {
        connect(action, &QAction::triggered, this, [this, actionId]() {
            QString prefix;
            if (actionId == QStringLiteral("Window.ShowPaletteCommand"))
                prefix = QStringLiteral(">");
            else if (actionId == QStringLiteral("Window.ShowPaletteMultiplexer"))
                prefix = QStringLiteral("m");
            openCommandPalette(prefix);
        });
        return action;
    }
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
    // 批 2 分屏/窗格生命周期接线（0x8d4166/0x8d42e8/0x8cc99c/0x8ce784）：
    // dir 0=Left/1=Right/2=Top/3=Bottom；动作经 activeMuxGroup() 落到焦点组
    if (actionId == QStringLiteral("Window.SplitViewHorizontally")
        || actionId == QStringLiteral("Window.SplitViewVertically")
        || actionId == QStringLiteral("Window.SplitGroupHorizontally")
        || actionId == QStringLiteral("Window.SplitGroupVertically")
        || actionId == QStringLiteral("Window.CloseActiveGroup")
        || actionId == QStringLiteral("Window.ActivateNextView")
        || actionId == QStringLiteral("Window.ActivatePreviousView")) {
        connect(action, &QAction::triggered, this, [this, actionId]() {
            auto *group = activeMuxGroup();
            if (!group)
                return;
            if (actionId == QStringLiteral("Window.SplitViewHorizontally"))
                group->splitView(0);
            else if (actionId == QStringLiteral("Window.SplitViewVertically"))
                group->splitView(3);
            else if (actionId == QStringLiteral("Window.SplitGroupHorizontally"))
                group->splitGroup(0);
            else if (actionId == QStringLiteral("Window.SplitGroupVertically"))
                group->splitGroup(3);
            else if (actionId == QStringLiteral("Window.CloseActiveGroup"))
                group->closeGroup();
            else if (actionId == QStringLiteral("Window.ActivateNextView"))
                group->activateNextView(true);
            else
                group->activateNextView(false);
        });
        return action;
    }
    // shortcut: Window.MoveGroupToGroup（Merge To Group 子菜单,按 allGroupNames 组名）挂账,
    // allGroupNames 动态列表未逆完（0x8cc994 text JS 动态生成,0x76cb16 动态项体系未接）
    if (actionId == QStringLiteral("Window.MoveGroupToGroup"))
        action->setEnabled(false);

    // ═══ P4 终端搜索/高亮接线（D 节）═══
    // Text.Find→显示 SearchPane 底部条（TogglePaneSearch 同路径；showPane 语义：显示+聚焦
    // find 编辑框——wind.actions script "window.activeKit.showPane('FindPane')"）
    if (actionId == QStringLiteral("Text.Find")) {
        connect(action, &QAction::triggered, this, [this]() {
            if (!m_searchPane)
                return;
            if (m_searchPane->isHidden())
                togglePane(m_searchPane);
            m_searchPane->focusFindEdit();
        });
        return action;
    }
    // Text.FindNext/FindPrevious/FindNextSelection/FindPreviousSelection→activeMuxGroup
    // 当前 view 的 findNext/Previous(useSelection)（wind.actions script 面）
    if (actionId == QStringLiteral("Text.FindNext")
        || actionId == QStringLiteral("Text.FindPrevious")
        || actionId == QStringLiteral("Text.FindNextSelection")
        || actionId == QStringLiteral("Text.FindPreviousSelection")) {
        connect(action, &QAction::triggered, this, [this, actionId]() {
            auto *stack = activeMuxGroup() ? activeMuxGroup()->findChild<QStackedWidget *>() : nullptr;
            auto *view = stack ? qobject_cast<TerminalView *>(stack->currentWidget()) : nullptr;
            if (!view)
                return;
            view->setFindPattern(m_searchPane ? m_searchPane->pattern() : QString());
            if (m_searchPane)
                view->setFindOptions({ m_searchPane->options().regex,
                                       m_searchPane->options().caseSensitive,
                                       m_searchPane->options().wholeWord,
                                       m_searchPane->options().wrap,
                                       false });
            const bool useSelection = actionId.endsWith(QLatin1String("Selection"));
            if (actionId.contains(QLatin1String("Previous")))
                view->findPrevious(useSelection);
            else
                view->findNext(useSelection);
        });
        return action;
    }
    // Text.HighlightText→openHighlightTextDialog() 挂账（script 原文：
    // "() => { window.activeText.openHighlightTextDialog() }"）
    if (actionId == QStringLiteral("Text.HighlightText")) {
        connect(action, &QAction::triggered, this, []() {
            Q_UNIMPLEMENTED();
        });
        return action;
    }
    // Text.HighlightTextBar（menu.config:252 View Popup 位置——QWidgetAction 插入）
    if (actionId == QStringLiteral("Text.HighlightTextBar")) {
        action->setEnabled(false); // 菜单位占位；真 QWidgetAction 经 buildMenu 特判插入（见 buildMenu）
        return action;
    }
    // ═══ P6 传输接线（wind.actions FilerPane.Download/Upload→FilerPane 收口方法）═══
    if (actionId == QStringLiteral("FilerPane.Download")) {
        connect(action, &QAction::triggered, this,
                [this]() { if (m_filerPane) m_filerPane->download(); });
        return action;
    }
    if (actionId == QStringLiteral("FilerPane.Upload")) {
        connect(action, &QAction::triggered, this,
                [this]() { if (m_filerPane) m_filerPane->upload(); });
        return action;
    }
    // ═══ P5 FilerPane 浏览动作（wind.actions/keymaps 同 id；0x731066/0x5773d6/0x578d88）═══
    // 其余（Open/Remove/Rename/MakeDir/MakeFile/CopyTo/...）保持无分支占位（P7 批）
    if (actionId == QStringLiteral("FilerPane.Refresh")
        || actionId == QStringLiteral("FilerPane.Cdup")
        || actionId == QStringLiteral("FilerPane.GoBackward")
        || actionId == QStringLiteral("FilerPane.GoForward")
        || actionId == QStringLiteral("FilerPane.GotoAddressBar")
        || actionId == QStringLiteral("FilerPane.ToggleHiddenItems")) {
        if (actionId == QStringLiteral("FilerPane.ToggleHiddenItems")) {
            // wind.actions:355 state JS=window.option('filer.hiddenItemsVisible'),
            // script=window.toggleOption(...)——option 求值/持久化挂账,checked 初始读 wind.config
            action->setCheckable(true);
            if (m_filerPane)
                action->setChecked(m_filerPane->showHidden());
        }
        connect(action, &QAction::triggered, this, [this, actionId]() {
            if (!m_filerPane)
                return;
            if (actionId == QStringLiteral("FilerPane.Refresh"))
                m_filerPane->reload();
            else if (actionId == QStringLiteral("FilerPane.Cdup"))
                m_filerPane->cdUp();
            else if (actionId == QStringLiteral("FilerPane.GoBackward"))
                m_filerPane->goBackward();
            else if (actionId == QStringLiteral("FilerPane.GoForward"))
                m_filerPane->goForward();
            else if (actionId == QStringLiteral("FilerPane.GotoAddressBar"))
                m_filerPane->focusAddressEdit();
            else
                m_filerPane->toggleHiddenItems();
        });
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
    // 0x8c40a6：toolbar_build 产物逐个 hbox->addWidget(w,0,0) 后对工具栏子 widget
    // installEventFilter(pane)（右键 popup 过滤链）——骨架对每个子件挂本窗过滤器
    for (QWidget *child : toolBar->findChildren<QWidget *>())
        child->installEventFilter(this);
    box->insertWidget(0, toolBar);
}

QWidget *MainWindow::paneHost(QWidget *pane)
{
    // 原版 KitPane 本身是 QWidget 容器（0x008c3bbe）；骨架 item view 类 pane 无法直接插布局，补一层同名容器
    auto *host = new QWidget;
    host->setObjectName(QStringLiteral("PaneHost"));
    // 0x8c3a70：换新 VBox margins 0/spacing 0（+0x38 null 才建 HBox→toolbar_build 产物
    // addWidget(w,0,0)→addLayout 到 VBox 末尾=内容 addWidget 之前，视觉顶部）。
    // 重建在构造期建齐（原版子类初始化期开头 onShown(true)→visible 门卫→每次 show 换新 VBox，
    // 0x8c442e）——均为内容之前插入，结构/视觉等价，保留构造期+两版证据注释
    auto *layout = new QVBoxLayout(host);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(pane);
    return host;
}

// 0x76cb16 菜单动态更新 + 0x76c3ee aboutToHide 清理。update：①文本刷新（"text\tshortcut"
// 拼接，当前 text 无 \t 时重建）②逐 action 调 scriptHost.updateActionState（0x669086，
// property("state") JS 求值驱动 checked/checkable/enabled）③递归子菜单。
// 0x76c3ee dynamic 清理：本项目暂无动态项（ExternalToolList/SchemeToolList 类重建挂账），
// 空实现占位
void MainWindow::hookMenuUpdate(QMenu *menu)
{
    connect(menu, &QMenu::aboutToShow, this, [menu, this] {
        for (QAction *action : menu->actions()) {
            if (QMenu *sub = action->menu())
                emit sub->aboutToShow(); // 子菜单同处理（原版逐级递归 update）
            const QString id = action->data().toString();
            if (id.isEmpty())
                continue;
            // ①文本刷新：ActionRegistry actionText 重建 "text\tshortcut"（原版比对后 setText+
            // property("oldText") 缓存；简化：当前无 \t 才 setText，比对语义不变）
            QString text = ActionRegistry::instance().actionText(id);
            if (text.isEmpty())
                continue;
            QString key = text;
            key.remove(QLatin1Char('&'));
            if (key.endsWith(QStringLiteral("...")))
                key.chop(3);
            text = displayActionText(text, m_locale.tr(key));
            const QString keys = KeymapConfig::instance().shortcut(id);
            if (!keys.isEmpty())
                text += QLatin1Char('\t') + keys;
            if (!action->text().contains(QLatin1Char('\t')) && action->text() != text)
                action->setText(text);
            // ②状态刷新：property("state") JS 求值（0x669086）
            m_scriptHost.updateActionState(action);
        }
    });
    // 0x76c3ee：property("dynamic") 非空→deleteLater。骨架无动态项（menu 类
    // ExternalToolList/SchemeToolList 动态重建挂账）
    connect(menu, &QMenu::aboutToHide, menu, []() {
        // 挂账 0x76c3ee：dynamic 动作清理待 ExternalToolList/SchemeToolList 接入
    });
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
    // 0x76cb16：每个 QMenu（含子菜单）创建后连 aboutToShow→update/aboutToHide→清理
    hookMenuUpdate(menu);
    for (const MenuEntry &entry : entries) {
        switch (entry.type) {
        case MenuEntry::Action:
            // menu.config:252 Text.HighlightTextBar：QWidgetAction（0x55c246/0x665dc2 特判）
            // ——经 addAction(QWidgetAction) 时菜单自建工具按钮项（8 色钮条）
            if (entry.actionId == QLatin1String("Text.HighlightTextBar")) {
                menu->addAction(HighlightTextBar::instance());
                break;
            }
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

// 原版 pane_showPopupMenu 0x8c3c6a：节名 "%1 %2Popup"，%1=pane objectName 去 "Pane" 后缀（0x8c3684），
// %2=修饰键串（无修饰键为空）；挂各 pane 的 contextMenuEvent。ViewTab Popup 走标签条 0x8ba130。
void MainWindow::showPopupMenu(QWidget *paneLike, Qt::KeyboardModifiers mods)
{
    if (!paneLike)
        return;

    QString section;
    if (paneLike == m_viewTabBar) {
        section = QStringLiteral("ViewTab Popup");
    } else {
        QString base = paneLike->objectName();
        // 原版 TerminalWidget pane 名 "View"(0x84005a 硬编码),重建 objectName TextView 特判
        if (base == QStringLiteral("TextView"))
            base = QStringLiteral("View");
        else if (base.endsWith(QStringLiteral("Pane")))
            base.chop(4);
        QString mod;
        if (mods & Qt::ShiftModifier)
            mod = QStringLiteral("Shift ");
        else if (mods & Qt::ControlModifier)
            mod = QStringLiteral("Ctrl ");
        else if (mods & Qt::AltModifier)
            mod = QStringLiteral("Alt ");
        else if (mods & Qt::MetaModifier)
            mod = QStringLiteral("Meta ");
        section = QStringLiteral("%1 %2Popup").arg(base, mod);
    }

    QVector<MenuEntry> entries = MenuConfig::instance().menu(section);
    if (entries.isEmpty())
        entries = menuSection(section); // popup 节不在 MenuConfig（只收 Kit 菜单），按同名顶层节补取
    if (entries.isEmpty())
        return; // 原版空节不弹项

    QMenu menu(this);
    // 条目动作走 makeAction：已接线的 Toggle 类生效，其余占位（与主菜单同限制）
    buildMenu(&menu, entries);
    menu.exec(QCursor::pos()); // 0x8ba130 同款
}

// 0x834f2c TerminalView contextMenuEvent → 0x8c3c6a pane_showPopupMenu；
// 原版用事件位置弹菜单，此处与 0x8ba130 同用 QCursor::pos()
void MainWindow::onTerminalContextMenu(const QPoint &globalPos, Qt::KeyboardModifiers mods)
{
    Q_UNUSED(globalPos);
    showPopupMenu(qobject_cast<QWidget *>(sender()), mods);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::ContextMenu) {
        auto *context = static_cast<QContextMenuEvent *>(event);
        showPopupMenu(qobject_cast<QWidget *>(watched), context->modifiers());
        return true;
    }
    return QMainWindow::eventFilter(watched, event);
}

// KitGroup 装配（setupBars 0x008bade2 同款，自 createCentral 抽出供分屏复用——落点 1）：
// 标签行占 menuWidget 槽、ToolBar 占 toolBar 区（QToolBar 只占中部宽，不横跨侧栏）、
// central=muxRow（setMenuWidget 0x008bb044 → TabGroup_buildCentral 0x005ab6e8 return +0x60
// → addToolBar 0x008bb07d）。首调=主组（挂 m_muxPaneGroup/m_viewTabBar/m_toolBar）
QWidget *MainWindow::createKitGroup()
{
    const bool primary = m_muxPaneGroup == nullptr;
    auto *mux = new MuxPaneGroup;
    if (primary)
        m_muxPaneGroup = mux;
    // 终端区右键（0x84005a TerminalWidget/0x834f2c TerminalView contextMenuEvent）：
    // view 由 MuxPaneGroup::addPane 内部创建（addPane 私有、无 paneAdded 信号），故借 stack
    // currentChanged 兜住每个新建/激活的 view；UniqueConnection 去重避免反复连
    if (auto *muxStack = mux->findChild<QStackedWidget *>()) {
        auto link = [this, mux]() {
            for (TerminalView *view : mux->findChildren<TerminalView *>()) {
                connect(view, &TerminalView::contextMenuRequested, this,
                        &MainWindow::onTerminalContextMenu, Qt::UniqueConnection);
                // P7b：tmux 会话 GUI 挂载/恢复（0x8d9be0 链）
                connect(view, &TerminalView::tmuxModeEntered, this, [this, view]() {
                    attachMuxDesktop(view);
                }, Qt::UniqueConnection);
                connect(view, &TerminalView::tmuxModeExited, this, [this, view]() {
                    detachMuxDesktop(view);
                }, Qt::UniqueConnection);
            }
        };
        // statusbar.config JS 链：view 切换 → terminal.viewActivated 转发
        // （0x8d9764 焦点终端链骨架等价；无 view 时发 nullptr——config JS 据 null 隐藏按钮）
        connect(muxStack, &QStackedWidget::currentChanged, this, [this, mux, link](int) {
            link();
            auto *stack = mux->findChild<QStackedWidget *>();
            QObject *view = stack ? stack->currentWidget() : nullptr;
            emit viewSignalForScripts(view);
        });
        link(); // 兜底：装配时若已有 view 立即连
    }

    auto *muxRow = new QSplitter(Qt::Horizontal);
    muxRow->setChildrenCollapsible(false);
    // 持久化键只挂主组行（次组行动态生成，不参与 QSettings splitter 持久化）
    if (primary)
        muxRow->setObjectName(QStringLiteral("MuxRow"));
    muxRow->addWidget(mux);

    // 中央列 = KitGroup（嵌套 QMainWindow，ctor 0x008bb360）
    auto *kitGroup = new KitGroup;
    if (mux->tabBarRow()) {
        kitGroup->setMenuWidget(mux->tabBarRow());
        if (primary) {
            // 原版 ViewTab Popup：标签条 customContextMenuRequested（0x8ba130）；标签条无 objectName，存指针特判
            m_viewTabBar = mux->findChild<QTabBar *>();
            if (m_viewTabBar)
                m_viewTabBar->installEventFilter(this);
        }
    }
    QToolBar *toolBar = nullptr;
    if (primary) {
        toolBar = m_toolBar; // createToolBar 已建（createCentral 前）；脱离 MainWindow 改挂 KitGroup
    } else {
        toolBar = buildGroupToolBar(); // 每组自带 ToolBar 行（0x008bade2 addToolBar per group）
    }
    if (toolBar) {
        toolBar->setParent(kitGroup); // objectName ToolBar 保持主题规则
        kitGroup->addToolBar(toolBar);
    }
    kitGroup->setCentralWidget(muxRow);
    return kitGroup;
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
    m_filerPane = filerPane;
    // PaneHeader closeRequested → hide pane（对齐 Dock.TogglePaneFiler toggle 语义）
    connect(filerPane, &FilerPane::closeRequested, this, [this, filerPane]() { togglePane(filerPane); });
    left->addWidget(tabsGroup);
    left->addWidget(filerPane);
    // shortcut: 原版运行时按均分插入，此处按实机侧栏截图约 2:1 定格；动态插入改走 PaneManager 时恢复均分
    left->setSizes({2000, 1000});

    // 原版 root 中央单元 0x60=QSplitter 子类 H（childrenCollapsible(false)），
    // 内装 TabGroup_buildCentral(0x005ab6e8) 的返回件（原版 return +0x60 = 该 splitter）
    auto *kitGroup = static_cast<KitGroup *>(createKitGroup());

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

    // P6 传输接线（0x85af56 懒建点/0x85a7a6 顺序=SearchPane 之后）：TransferBar 懒建锚
    // （首个 taskEvent(kind 0) 时建+hook）;TransferPane 挂 TransferCenter::model
    m_transferCenter = TransferCenter::instance();
    if (TransferPane *transferPane = findChild<TransferPane *>()) {
        transferPane->hookModel(m_transferCenter->model());
    }
    connect(m_transferCenter, &TransferCenter::taskEvent, this, [this](const QString &, int kind) {
        if (kind == TransferCenter::LabelCreate)
            ensureTransferBar();
    });
    // P4 执行链（0x74f5ac/0x74d488）：SearchPane findRequested→活动 view findNext/Previous
    // （pattern/options 随调随传）；状态栏 4s 消息经 TerminalView::statusMessageHandler
    connect(m_searchPane, &SearchPane::findRequested, this, [this](bool useSelection, bool backward) {
        auto *stack = activeMuxGroup() ? activeMuxGroup()->findChild<QStackedWidget *>() : nullptr;
        auto *view = stack ? qobject_cast<TerminalView *>(stack->currentWidget()) : nullptr;
        if (!view)
            return;
        view->setFindPattern(m_searchPane->pattern());
        const SearchPane::Options o = m_searchPane->options();
        view->setFindOptions({ o.regex, o.caseSensitive, o.wholeWord, o.wrap, false });
        if (backward)
            view->findPrevious(useSelection);
        else
            view->findNext(useSelection);
    });

    // QuickBar/TransferBar 懒建（证据 0x85ad2e lazyCreateQuickBar / 0x85af56：

    // v5：中央 widget 即 root splitter（中部单元=KitGroup 嵌套窗口，标签行/工具栏不横跨侧栏）
    setCentralWidget(centralVSplitter);

    col->setSizes({1000, 4000, 1000});
    // 原 CenterGroup VBox 期 setSizes({4000,2000}) 双值随 KitGroup 化失效移除（muxRow 内部
    // childrenCollapsible(false) 语义不变，运行时无需预分配份额）
    root->setSizes({4000, 2000});

    // A6（0x008c40a6/0x008c442e）：pane 工具栏按 toolbar.config 同名节建；pane 装配完成后一次建齐
    // （原版子类初始化期开头 onShown(true) 建——0x8c442e/0x8c3a70/0x8c40a6：visible 门卫→新
    // VBox(0/0)→HBox→toolbar_build→子件装过滤→addLayout 先于内容；重建保留构造期建齐，时序
    // 语义等价：工具栏先于内容，两版证据见 installPaneToolBar/paneHost 注释）
    for (const char *name : {"ExplorerPane", "SessionPane", "FilerPane", "OutlinePane",
                             "OutputPane", "SenderPane"}) {
        if (QWidget *pane = findChild<QWidget *>(QString::fromLatin1(name)))
            installPaneToolBar(pane);
    }
    // P5：FilterEdit（toolbar.config FilerPane 节,上方 installPaneToolBar 已建）→地址条 cd 防抖
    if (m_filerPane)
        m_filerPane->hookAddressEdit();
    // P5（0x5773d6）：本地/远程页随活动会话类型——view 切换转发链（viewSignalForScripts）
    // 已在每个 muxStack currentChanged 发出,此处挂 FilerPane 判型（SshSession→远程页）
    connect(this, &MainWindow::viewSignalForScripts, this, [this](QObject *viewObj) {
        if (!m_filerPane)
            return;
        auto *view = qobject_cast<TerminalView *>(viewObj);
        auto *ssh = view ? qobject_cast<SshSession *>(view->session()) : nullptr;
        m_filerPane->setRemoteSession(ssh);
    });
    // 右键上下文菜单管线（pane_showPopupMenu 0x8c3c6a）：KitPane 基类经基类
    // contextMenuEvent（0x8c3bbe vtable+0x110）发 popupRequested；item view 类 pane
    // （Session/Outline/Output）无法继承 KitPane，保留 eventFilter 路径
    //（原版 SessionPane 等 item view 子类同样经 KitPane，重建 Qt 单继承限制）
    for (const char *name : {"ExplorerPane", "FilerPane", "SenderPane", "TransferPane", "SearchPane", "ShellPane"}) {
        if (KitPane *pane = findChild<KitPane *>(QString::fromLatin1(name))) {
            connect(pane, &KitPane::popupRequested, this, [this, pane](Qt::KeyboardModifiers mods) {
                showPopupMenu(pane, mods);
            });
        }
    }
    for (const char *name : {"SessionPane", "OutlinePane"}) {
        if (QWidget *pane = findChild<QWidget *>(QString::fromLatin1(name)))
            pane->installEventFilter(this);
    }
    // shortcut: View Popup 终端区右键挂账,TerminalView 属独立组件文件,下批接入(0x84005a)
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
    // 证据 0x008c9f8c KitWindow_createStatusBar / 0x00692766：主窗底栏=StatusBar（QStatusBar 子类，
    // objectName "StatusBar"/注册名 AppletBar）；内容=statusbar.config 7 applets 经 QJSEngine
    // 真跑 JS init（0x006933ea populate singleShot(0) → 0x005a4432 applet_layout_widgets）。
    // 骨架同构：StatusBar::populate(配置数组, &m_scriptHost)——模式按钮/窗口尺寸/LnCh/scheme/
    // 时钟/Issues/锁屏全部由 statusbar.config JS 驱动（硬编码 Qt 手写代码已删）
    m_statusBar = new StatusBar(this);
    setStatusBar(m_statusBar);

    QFile file(Assets::dir() + QStringLiteral("/config/uiconfigs/statusbar.config"));
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        if (data.startsWith("\xEF\xBB\xBF"))
            data.remove(0, 3);
        // 0x008a5c98 statusbar 配置读取路径 → QVariant::toList（0x006933ea）
        const QJsonDocument doc = QJsonDocument::fromJson(JsonText::stripLineComments(data));
        if (doc.isArray()) {
            // 0x006933ea：singleShot(0) 延迟 populate（等窗口装配完成）
            const QVariantList applets = doc.toVariant().toList();
            QTimer::singleShot(0, this, [this, applets] {
                m_statusBar->populate(applets, &m_scriptHost);
            });
        }
    }

    // view 切换 → terminal.viewActivated / window.viewActivated 转发（createCentral stack
    // currentChanged 处 emit viewSignalForScripts；此处接到脚本宿主）
    connect(this, &MainWindow::viewSignalForScripts, this, [this](QObject *view) {
        emit m_scriptHost.terminal()->viewActivated(view);
        emit m_scriptHost.window()->viewActivated(view);
    });
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
        // shortcut: LastSessions 真重连挂账, 需 uuid 重连(0x8d2e46/0x833db4); 避免实现期自动外连用户真机会话
    } else if (!startupSessions.isEmpty() && startupSessions != QStringLiteral("NoSessions")) {
        // shortcut: startupSessions 其他取值语义未逆, 逆出会话集存储/启动策略后补
    }

    // reopen.history 读侧（0x75ffcc：窗口几何+布局**无条件**恢复，不受 startupSessions 约束；
    // 仅会话重连受 kit.startupSessions 约束——上面 QSettings 恢复保留并存，本块叠加）。
    // 只消费 geometry/maximized/bars/currentIndex/tabList；docks/right 在 ReopenHistory::load
    // 内读入即弃，splitter 树持久化仍归 QSettings layout.v5（两体系并存挂账）
    ReopenState st;
    if (ReopenHistory::load(ReopenHistory::defaultPath(), st)) {
        restoreGeometry(st.geometry);
        if (st.maximized)
            showMaximized();
        // bars 语义=hidden 取反应用（0x8d2f7e 实证，真样例 000→三栏全可见）
        menuBar()->setVisible(st.menuBarVisible);
        statusBar()->setVisible(st.statusBarVisible);
        if (m_toolBar) {
            m_toolBar->setVisible(st.toolBarVisible);
        }
        // LastSessions 真重连（0x8d2f7e→0x8d2e46→0x833db4）：uuid→SessionStore 查→按
        // protocol 建会话→openSession。查不到→原版标 Error/Discarded，此处跳过+告警。
        // C7 后 SSH 走认证队列（见下方恢复分支）。双键说明：
        // 0x8d2f7e 读 kit.startupSessions（三处配置文件均无值=默认），
        // terminal.startupSessions 为 TerminalWindow 级；本处按用户可见键语义分派
        if (startupSessions == QStringLiteral("LastSessions")) {
            for (const ReopenTabEntry &t : st.tabs) {
                if (!t.url.startsWith(QStringLiteral("$")))
                    continue;
                const QString uuid = t.url.mid(1);
                const QVariantMap entry = SessionStore::sessionByUuid(uuid);
                if (entry.isEmpty()) {
                    qWarning() << "reopen.history: session" << uuid
                               << "not in user.sessions (原版标 Discarded, 0x833db4)";
                    continue;
                }
                const QString protocol = entry.value(QStringLiteral("session.protocol")).toString();
                const QString target = entry.value(QStringLiteral("session.target")).toString();
                const QString label = entry.value(QStringLiteral("session.label")).toString();
                // 1b 标签色恢复（0x8bbab6 QColor 字段）
                if (protocol == QStringLiteral("Shell")) {
                    auto *session = new LocalSession(24, 80, this);
                    session->setUuid(uuid);
                    session->start(target,
                                   entry.value(QStringLiteral("process.arguments")).toString(),
                                   entry.value(QStringLiteral("process.workingDirectory"))
                                       .toString()
                                       .replace(QStringLiteral("${HomeDir}"), QDir::homePath()));
                    m_muxPaneGroup->openSession(session, label, t.color);
                } else if (protocol.compare(QStringLiteral("Telnet"), Qt::CaseInsensitive) == 0) {
                    auto *session = new TelnetSession(target,
                        entry.value(QStringLiteral("session.port")).toInt(), 24, 80, this);
                    session->setUuid(uuid);
                    m_muxPaneGroup->openSession(session, label, t.color);
                } else if (protocol.compare(QStringLiteral("Serial"), Qt::CaseInsensitive) == 0) {
                    auto *session = new SerialSession(target,
                        entry.value(QStringLiteral("serial.baudRate")).toInt(),
                        entry.value(QStringLiteral("serial.dataBits")).toInt(),
                        entry.value(QStringLiteral("serial.parity")).toString(),
                        entry.value(QStringLiteral("serial.stopBits")).toInt(),
                        entry.value(QStringLiteral("serial.flowControl")).toString(), this);
                    session->setUuid(uuid);
                    m_muxPaneGroup->openSession(session, label, t.color);
                } else {
                    // C7：SSH 恢复走认证队列——无密码=Password op 跳过→PublicKey cfg 开→
                    // 两步 try/real→KbdInt；全失败 failed→关标签。真数据 user.sessions
                    // 条目键为 "session.target"/"session.port"/扁平键（无 session.user——
                    // 实测 grep 只有 autoLogin/target/port/protocol/uuid 等扁平键），
                    // user 留空走 libssh 默认（当前用户）。
                    auto *session = new SshSession(24, 80, this);
                    session->setUuid(uuid);
                    hookSshSession(session);
                    m_muxPaneGroup->openSession(session, label, t.color);
                    connect(session, &Session::finished, this, [uuid]() {
                        // shortcut: 原版失败弹密码窗,弹窗体系未接
                        qWarning() << "reopen.history: ssh session" << uuid
                                   << "restore failed (原版失败弹密码窗, 弹窗体系未接)";
                    });
                    connect(session, &SshSession::failed, this, [this, session]() {
                        // C7：认证队列全失败→关标签
                        auto *stack = m_muxPaneGroup->findChild<QStackedWidget *>();
                        const auto views = m_muxPaneGroup->findChildren<TerminalView *>();
                        for (TerminalView *view : views) {
                            if (view->session() == session && stack) {
                                m_muxPaneGroup->setConfirmClose(false); // 恢复路径无确认框应答者
                                m_muxPaneGroup->onTabCloseRequested(stack->indexOf(view));
                                m_muxPaneGroup->setConfirmClose(true);
                                break;
                            }
                        }
                    });
                    session->start(target,
                                   entry.value(QStringLiteral("session.port")).toInt(), QString());
                }
            }
        }
        // 1c 恢复 currentIndex（0x7669b2/0x8bbab6 双层索引；MuxPaneGroup 无公开 setCurrentIndex，
        // 走标签条最小可行）
        if (m_muxPaneGroup) {
            if (auto *tabBar = m_muxPaneGroup->findChild<QTabBar *>())
                tabBar->setCurrentIndex(st.currentIndex);
        }
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings;
    settings.setValue(QStringLiteral("application/windowGeometry"), saveGeometry());

    // reopen.history（原版 global/reopen.history 体系）：接管窗口几何+bars 可见性+tabList；
    // 上面 QSettings windowGeometry 与 splitter_*=layout.v5 体系保留并存（splitter 树持久化
    // 仍是 layout.v5——两体系并存挂账，docs/reopen-history.md 挂账节）
    ReopenState st;
    st.geometry = saveGeometry(); // 0x76073a：QWidget::saveGeometry 透传
    st.maximized = isMaximized();
    st.menuBarVisible = menuBar()->isVisible();
    st.statusBarVisible = statusBar()->isVisible();
    // 0x8cf0c8 barsBlob 第三位=ToolBar 可见性；骨架 ToolBar 挂 KitGroup（可能未建）
    st.toolBarVisible = m_toolBar ? m_toolBar->isVisible() : false;
    if (m_muxPaneGroup) {
        // 0x8bbab6：每 view 持久化 url="$<uuid>"（uuid=会话 session.uuid，0x833db4 恢复时
        // QUuid 查 user.sessions）；无 uuid（本地会话）→空串
        const auto views = m_muxPaneGroup->findChildren<TerminalView *>();
        st.tabs.reserve(views.size());
        for (TerminalView *view : views) {
            ReopenTabEntry entry;
            const QString uuid = view->sessionUuid();
            if (!uuid.isEmpty())
                entry.url = QStringLiteral("$") + uuid;
            // shortcut: view 色属性未接(MuxPaneGroup 建标签处 QColor 参数),先灰色
            entry.color = QColor(Qt::gray);
            st.tabs.append(entry);
        }
        if (auto *stack = m_muxPaneGroup->findChild<QStackedWidget *>())
            st.currentIndex = stack->currentIndex();
    }
    ReopenHistory::save(ReopenHistory::defaultPath(), st);

    QMainWindow::closeEvent(event);
}

// 0x005a2e58 面移交 StatusBar（showMessageEx）；主窗 resize 不再驱动窗口尺寸 label
// （statusbar.config JS screenSizeChanged 链驱动）——旧 updateWindowSizeLabel/resizeEvent
// 挂钩随硬编码 applet 删除

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
// F3：SSH host key 确认/警告接线。信号 queued 到主线程；回执走 hostKeyAnswer()
// （worker 无事件循环，QWaitCondition 等待——槽本身不 join 线程，无死锁）。
void MainWindow::hookSshSession(SshSession *session)
{
    connect(session, &SshSession::hostKeyUnknown, this,
            [this, session](const QString &host, const QString &fingerprint, bool changed) {
        const QString msg = changed
            ? tr("远程主机 %1 的主机密钥已变更！\n\n可能是中间人攻击（MITM），也可能\n"
                 "是服务器重装/换钥。指纹 (MD5)：\n%2\n\n拒绝连接？")
                  .arg(host, fingerprint.isEmpty() ? QStringLiteral("(不可用)") : fingerprint)
            : tr("主机 %1 的真实性无法确认。\n\n指纹 (MD5)：\n%2\n\n"
                 "接受并保存到 known_hosts？")
                  .arg(host, fingerprint.isEmpty() ? QStringLiteral("(不可用)") : fingerprint);
        const bool accept = changed
            ? (QMessageBox::warning(this, tr("主机密钥警告"), msg,
                                    QMessageBox::Yes | QMessageBox::No, QMessageBox::No)
               == QMessageBox::No) // changed 警告默认拒绝；选 No=坚持拒绝，Yes=冒险接受
            : (QMessageBox::question(this, tr("主机密钥确认"), msg,
                                     QMessageBox::Yes | QMessageBox::No, QMessageBox::No)
               == QMessageBox::Yes);
        session->hostKeyAnswer(accept);
    });
    // P5：会话终局→FilerPane 撤远程句柄（sftp 已随 teardown free,防悬垂）
    connect(session, &Session::finished, this, [this, session] {
        if (m_filerPane)
            m_filerPane->dropRemoteSession(session);
    });
}

QuickBar *MainWindow::ensureQuickBar()
{
    if (!m_quickBar) {
        m_quickBar = new QuickBar;
        // 0x0056d890 在 QuickBar 内聚（按 uuid 匹配+unescape），此处仅接终端写入宿主层
        // （原版写焦点终端 0x8cabee 链；骨架写当前活动 view——仅宿主层差异，0x833db4 挂账）
        connect(m_quickBar, &QuickBar::sendTextRequested, this, [this](const QString &text) {
            if (!m_muxPaneGroup)
                return;
            auto *stack = m_muxPaneGroup->findChild<QStackedWidget *>();
            if (auto *view = stack ? qobject_cast<TerminalView *>(stack->currentWidget()) : nullptr)
                view->sendText(text);
        });
        m_quickBar->hide();
        QWidget *central = centralWidget();
        if (auto *vs = qobject_cast<QSplitter *>(central)) {
            const int at = m_transferBar ? vs->indexOf(m_transferBar) : vs->indexOf(m_searchPane) + 1;
            vs->insertWidget(at, m_quickBar);
        }
    }
    return m_quickBar;
}

// P6（0x85af56 懒建/0x85a7a6 顺序）：TransferBar 懒建——首个 taskEvent(kind 0) 触发
// （createCentral 连线）;插入位=SearchPane 之后（0x0085a7a6 [Search,QuickBar,TransferBar] 序）
void MainWindow::ensureTransferBar()
{
    if (m_transferBar || !m_transferCenter)
        return;
    m_transferBar = new TransferBar(this);
    m_transferBar->hookTransferCenter(m_transferCenter);
    m_transferBar->hide();
    if (QWidget *central = centralWidget(); central) {
        if (auto *vs = qobject_cast<QSplitter *>(central)) {
            const int at = m_quickBar ? vs->indexOf(m_quickBar) + 1 : vs->indexOf(m_searchPane) + 1;
            vs->insertWidget(at, m_transferBar);
        }
    }
    m_transferBar->show();
}

// 0x768dfa window_openCommandPalette：懒建 CommandPalette（挂活动窗格 currentWidget）→
// 0x53fc54 设初值 → show。QPointer 承接 WA_DeleteOnClose——关后下次懒重建
void MainWindow::openCommandPalette(const QString &prefix)
{
    QWidget *host = nullptr;
    if (MuxPaneGroup *group = activeMuxGroup()) {
        if (auto *stack = group->findChild<QStackedWidget *>())
            host = stack->currentWidget();
        if (!host)
            host = group; // 无会话时回退组容器（原版 mainPane_currentWidgetCast 空路径——挂账）
    }
    if (!host)
        return;
    if (!m_commandPalette) {
        m_commandPalette = new CommandPalette([this](const QString &id) {
            // 原版 actionFactory_getOrCreate（0x665dc2）共享缓存——骨架 makeAction 临时新建；
            // 剥 shortcut 防与菜单动作重复注册产生歧义快捷键
            QAction *action = makeAction(id);
            action->setShortcut(QKeySequence());
            return action;
        }, host);
        // mode7 palette JS 面注入（0x54334c：panel script 经 MainWindow ScriptHost 引擎求值
        // ——QJSValue 不可跨引擎；注入即扫 assets/palettes/*.palette）
        m_commandPalette->setScriptHost(&m_scriptHost);
    }
    m_commandPalette->open(prefix);
    m_commandPalette->show();
    m_commandPalette->raise();
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
