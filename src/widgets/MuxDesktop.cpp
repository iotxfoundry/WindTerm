#include "MuxDesktop.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QMessageBox>
#include <QSplitter>
#include <QStackedWidget>
#include <QTabBar>
#include <QTimer>
#include <QToolButton>
#include <QVBoxLayout>

#include "ActionIcons.h"
#include "MuxPane.h"
#include "MuxPaneGroup.h"
#include "MuxWindow.h"
#include "TerminalView.h"
#include "core/ThemeManager.h"
#include "tmux/Tmux.h"

#include <QAbstractButton>
#include <QHash>
#include <QLineEdit>
#include <QPushButton>
#include <qmath.h>

// ── tmux 布局串解析（0x84b483 splitter_restoreState 输入；LayoutNode 定义在头文件）──
namespace {

bool parseNumber(const QString &s, int &pos, int &out)
{
    const int begin = pos;
    while (pos < s.size() && s.at(pos).isDigit())
        ++pos;
    if (pos == begin)
        return false;
    out = s.mid(begin, pos - begin).toInt();
    return true;
}

bool parseCell(const QString &s, int &pos, LayoutNode &node)
{
    return parseNumber(s, pos, node.w) && pos < s.size() && s.at(pos) == QLatin1Char('x')
           && (++pos, parseNumber(s, pos, node.h)) && pos < s.size()
           && s.at(pos) == QLatin1Char(',') && (++pos, parseNumber(s, pos, node.x))
           && pos < s.size() && s.at(pos) == QLatin1Char(',')
           && (++pos, parseNumber(s, pos, node.y));
}

bool parseNode(const QString &s, int &pos, LayoutNode &node);

bool parseKids(const QString &s, int &pos, bool vertical, LayoutNode &node)
{
    node.vertical = vertical;
    ++pos; // '{' 或 '['
    for (;;) {
        LayoutNode kid;
        if (!parseNode(s, pos, kid))
            return false;
        node.kids.append(kid);
        if (pos < s.size() && s.at(pos) == QLatin1Char(','))
            ++pos;
        else
            break;
    }
    const QChar close = vertical ? QLatin1Char(']') : QLatin1Char('}');
    if (pos >= s.size() || s.at(pos) != close)
        return false;
    ++pos;
    return true;
}

bool parseNode(const QString &s, int &pos, LayoutNode &node)
{
    if (!parseCell(s, pos, node))
        return false;
    if (pos < s.size() && (s.at(pos) == QLatin1Char('{') || s.at(pos) == QLatin1Char('[')))
        return parseKids(s, pos, s.at(pos) == QLatin1Char('['), node);
    if (pos < s.size() && s.at(pos) == QLatin1Char(',')) { // 尾随 pane id（叶）
        ++pos;
        return parseNumber(s, pos, node.id);
    }
    return true;
}

} // namespace

MuxDesktop::MuxDesktop(TerminalView *host, QWidget *parent)
    : QWidget(parent)
    , m_host(host)
    , m_tmux(host ? host->tmux() : nullptr)
    , m_resizeDebounce(new QTimer(this))
{
    setObjectName(QStringLiteral("MuxDesktop")); // 0x8d9be0
    buildUi();
    if (!m_tmux)
        return;
    // ── E：onTmuxWindowsChanged 接线（0x84dd5a，TerminalView Tmux 的 windowsChanged）──
    connect(m_tmux, &Tmux::windowsChanged, this, &MuxDesktop::reconcile);
    connect(m_tmux, &Tmux::windowsRemoved, this, &MuxDesktop::reconcile);
    connect(m_tmux, &Tmux::termsRemoved, this, &MuxDesktop::onTermsRemoved);
    connect(m_tmux, &Tmux::sessionsChanged, this,
            [this](const QStringList &names, const QString &current) {
                m_sessionNames = names;
                m_currentSessionName = current;
            });
    // F：capture-pane 补屏（screenCaptured→pane view 整缓冲替换，0x877610 链）
    connect(m_tmux, &Tmux::screenCaptured, this, &MuxDesktop::onScreenCaptured);
    connect(m_tmux, &Tmux::screenResized, this, &MuxDesktop::onScreenResized);
    // 输出回灌 pane 视图：待激活冲账（outputCached）+活动 pane 流（vtOutput，0x7e6b64）
    connect(m_tmux, &Tmux::outputCached, this,
            [this](int paneId, const QByteArray &data) { feedPaneView(paneId, data); });
    connect(m_tmux, &Tmux::vtOutput, this, [this](const QByteArray &data) {
        if (m_focusedPaneId >= 0)
            feedPaneView(m_focusedPaneId, data);
    });
    // %exit（I：宿主恢复显示）：desktop 隐藏+finished（MainWindow 接线弃件）
    connect(m_tmux, &Tmux::exited, this, [this]() {
        m_tmux = nullptr;
        hide();
        emit finished();
    });
    // 0x8e12c0 分屏树 resize-pane 防抖
    m_resizeDebounce->setSingleShot(true);
    m_resizeDebounce->setInterval(300);
    connect(m_resizeDebounce, &QTimer::timeout, this, &MuxDesktop::sendPendingResizes);
    // G：focusChanged→TabBar state="Active" 刷新（0x8e0bb2）
    connect(qApp, &QApplication::focusChanged, this, [this]() { onFocusChanged(); });
    reconcile();
}

void MuxDesktop::buildUi()
{
    auto *vbox = new QVBoxLayout(this);    vbox->setContentsMargins(0, 0, 0, 0);
    vbox->setSpacing(0);
    m_stack = new QStackedWidget(this); // TabGroup.centralStack（页=MuxWindow）
    vbox->addWidget(m_stack, 1);

    // hbox[TabGroup, stretch]（0x8d98d0：页签行在内容之下）
    auto *hbox = new QHBoxLayout;
    hbox->setContentsMargins(0, 0, 0, 0);
    hbox->setSpacing(0);
    m_tabBar = new QTabBar(this);
    m_tabBar->setExpanding(false);
    m_tabBar->setUsesScrollButtons(false);
    m_tabBar->setElideMode(Qt::ElideRight);
    m_tabBar->setMovable(true);      // D：movable
    m_tabBar->setTabsClosable(true); // D：tabsClosable=true
    hbox->addWidget(m_tabBar);
    auto makeButton = [this, hbox](const QString &name, const QString &iconName) {
        auto *button = new QToolButton(this);
        button->setObjectName(name);
        button->setIcon(
            ActionIcons::iconFor(name, iconName, ThemeManager::instance().currentTheme()));
        button->setAutoRaise(true);
        hbox->addWidget(button);
        return button;
    };
    QToolButton *addButton = makeButton(QStringLiteral("TabAddButton"), QStringLiteral("king::addTab"));
    QToolButton *listButton = makeButton(QStringLiteral("TabListButton"), QStringLiteral("king::listTab"));
    makeButton(QStringLiteral("ConfigButton"), QStringLiteral("king::config"))->hide(); // D：ConfigButton 隐藏
    hbox->addStretch(1);
    vbox->addLayout(hbox);

    connect(m_tabBar, &QTabBar::currentChanged, m_stack, &QStackedWidget::setCurrentIndex);
    // 页切换→该窗活动 pane 设为显示 pane（0x8da43c 链：%window-pane-changed→批→setCurrentIndex；
    // 输出路由随切，Tmux::setActivePane 触发 pendingOut 冲账 0x7e6d78）
    connect(m_tabBar, &QTabBar::currentChanged, this, [this](int) {
        if (!m_tmux)
            return;
        auto *mw = qobject_cast<MuxWindow *>(m_stack->currentWidget());
        if (!mw)
            return;
        const int activePane = m_tmux->windows().value(mw->windowId()).activePaneId;
        if (activePane >= 0 && activePane != m_focusedPaneId) {
            m_focusedPaneId = activePane;
            m_tmux->setActivePane(activePane);
        }
    });
    connect(m_tabBar, &QTabBar::tabCloseRequested, this, &MuxDesktop::onTabCloseRequested);
    connect(addButton, &QToolButton::clicked, this,
            [this, addButton]() { Q_UNUSED(addButton); if (m_tmux) m_tmux->newWindow(); });
    // shortcut: TabListButton 菜单挂账, TabListMenu 未实现(0x5acc3e 同 MuxPaneGroup)
    connect(listButton, &QToolButton::clicked, this, []() { Q_UNIMPLEMENTED(); });
}

// ═══ E：0x84dd5a onTmuxWindowsChanged 全流程 ═══

// 页签位映射：QTabBar 无 indexOf(QWidget)——MuxWindow::tabIndex 同步面
int MuxDesktop::tabIndexOf(MuxWindow *mw) const
{
    return mw ? mw->tabIndex() : -1;
}

void MuxDesktop::reconcile()
{
    if (!m_tmux)
        return;
    const QMap<int, Tmux::Window> &windows = m_tmux->windows();
    for (auto wit = windows.constBegin(); wit != windows.constEnd(); ++wit) {
        // 新窗：new MuxWindow→+0x44=idx→setName→insertTab(idx+1)；已有：移位+改名（变更才发）
        MuxWindow *mw = ensureWindowPage(wit.key(), wit->idx,
                                         wit->name.isEmpty() ? tr("Untitled") : wit->name);
        // pane 组保障（pane→window 归属；标题 "%1:%2" paneId:name）
        for (auto pit = m_tmux->panes().constBegin(); pit != m_tmux->panes().constEnd(); ++pit) {
            if (pit->windowId != wit.key())
                continue;
            const Tmux::Pane &pane = pit.value();
            mw->ensurePaneGroup(pit.key(), wit->attached,
                                QStringLiteral("%1:%2").arg(pit.key()).arg(pane.title));
            // 视图尺寸随 pane 模型（F：满行重建由 loadScreen 承担）
            if (TerminalView *view = mw->viewForPane(pit.key()); view && pane.w > 0 && pane.h > 0)
                view->resizeScreen(pane.w, pane.h);
        }
        // active 窗（rawFlags '*'）且焦点在 desktop 内 → 页切换（0x84dd5a active 段）
        if (wit->rawFlags.contains(QLatin1Char('*'))) {
            QWidget *focus = QApplication::focusWidget();
            if (focus && isAncestorOf(focus))
                m_tabBar->setCurrentIndex(mw->tabIndex());
        }
        // splitter_restoreState(window.layout/visibleLayout, root)（0x84b483）
        restoreSplitterTree(mw, wit->attached ? wit->visibleLayout : wit->layout);
    }
    // 删除 pass：页有而列表无 → close+摘除+cleanupEmptyTree（0x84dd5a 删除段→windowsRemoved）
    const QList<int> pageIds = m_pages.keys();
    for (int id : pageIds)
        if (!windows.contains(id))
            closePage(id);
}

MuxWindow *MuxDesktop::ensureWindowPage(int windowId, int idx, const QString &name)
{
    if (MuxWindow *mw = m_pages.value(windowId)) {
        mw->setWindowIdx(idx);  // +0x44=idx
        mw->setName(name);      // 变更才发 nameChanged
        const int cur = mw->tabIndex();
        // tmux idx 重排：moveTab(页位, idx+1)（0x84dd5a；越界夹取，页签序自洽）
        const int target = qBound(0, idx + 1, m_tabBar->count() - 1);
        if (cur >= 0 && cur != target) {
            m_tabBar->moveTab(cur, target); // moveTab 返回 void（Qt5）：目标位即 target
            mw->setTabIndex(target);
        }
        return mw;
    }
    auto *mw = new MuxWindow(this);
    mw->setWindowId(windowId);
    mw->setWindowIdx(idx);
    mw->setName(name);
    m_pages.insert(windowId, mw);
    m_stack->addWidget(mw);
    const int ti = m_tabBar->insertTab(qMin(idx + 1, m_tabBar->count()), mw->name());
    mw->setTabIndex(ti);
    // 页=stack 对象照旧挂 stack；tabData 存页指针，关闭/状态映射经 tabIndexOf
    m_tabBar->setTabData(ti, QVariant::fromValue<quintptr>(reinterpret_cast<quintptr>(mw)));
    connect(mw, &MuxWindow::nameChanged, this, [this, mw](const QString &tabName) {
        const int i = mw->tabIndex();
        if (i >= 0)
            m_tabBar->setTabText(i, tabName); // TabBar 页文本=window 名
    });
    return mw;
}

void MuxDesktop::closePage(int windowId)
{
    MuxWindow *mw = m_pages.take(windowId);
    if (!mw)
        return;
    const int i = mw->tabIndex();
    if (i >= 0)
        m_tabBar->removeTab(i);
    m_stack->removeWidget(mw);
    mw->deleteLater(); // 空树清理：组随 MuxWindow 树销毁（0x84dd5a 删除段）
}

// ═══ 0x84b483 splitter_restoreState ═══

// paneId 匹配归位；被换出 MuxPaneGroup 摘除 hide（暂存 MuxWindow）；对半只发生在插入
// 引擎（0x84dd5a 注），此处尺寸按 tmux 坐标直设
void MuxDesktop::restoreSplitterTree(MuxWindow *mw, const QString &layout)
{
    if (layout.isEmpty())
        return;
    QSplitter *root = mw->rootSplitter();
    LayoutNode rootNode;
    int pos = 0;
    // tmux 布局串带 4 hex 布局编码前缀（"c08a,100x30,..."）——跳过到首个 WxH
    const int hx = layout.indexOf(QLatin1Char('x'));
    int prefixEnd = 0;
    for (int i = qMax(0, hx - 6); i >= 0 && i < hx; ++i)
        if (layout.at(i) == QLatin1Char(',')) {
            prefixEnd = i + 1;
            break;
        }
    if (!parseNode(layout.mid(prefixEnd), pos, rootNode))
        return; // shortcut: 语法不符容错路径未逆明(0x84b483), 保现状挂账

    // 摘离全部现有子树：组暂存 MuxWindow（hide），旧 splitter 弃
    // 注意 findChildren 递归：deleteLater 未弹出的旧 splitter 仍会再被扫到——先断链
    QList<MuxPaneGroup *> groups = root->findChildren<MuxPaneGroup *>();
    for (MuxPaneGroup *g : groups)
        if (g->parentWidget()) {
            g->setParent(mw);
            g->hide();
        }
    groups.clear();
    QList<QWidget *> tops;
    for (int i = 0; i < root->count(); ++i)
        tops.append(root->widget(i));
    for (QWidget *w : tops) {
        w->setParent(nullptr);
        w->deleteLater();
    }
    QCoreApplication::sendPostedEvents(nullptr, QEvent::DeferredDelete); // 旧树即时销毁

    buildLayoutNode(mw, rootNode, root);

    // 失效 pane：无布局槽的组保持 hide（enable 复活由下次 restore 承担）；空 MuxPaneGroup
    // 关闭走 termsRemoved→removePane→cleanupEmptyTree 链（0x84dd5a 失效段）
}

void MuxDesktop::buildLayoutNode(MuxWindow *mw, const LayoutNode &node, QSplitter *parent)
{
    if (node.kids.isEmpty()) { // 叶：pane 描述→mux_restorePaneSplitter（paneId 匹配归位）
        if (MuxPaneGroup *g = mw->groupForPane(node.id)) {
            g->show();
            parent->addWidget(g);
        }
        // 槽占摘迁：模型缺 pane→跳槽（原版占位语义 shortcut 挂账）
        return;
    }
    auto *sp = new QSplitter(node.vertical ? Qt::Vertical : Qt::Horizontal);
    sp->setChildrenCollapsible(false);
    parent->addWidget(sp);
    sp->show();
    QList<int> sizes;
    for (const LayoutNode &kid : node.kids) {
        buildLayoutNode(mw, kid, sp);
        sizes.append(node.vertical ? kid.h : kid.w);
    }
    if (sizes.size() == sp->count() && !sizes.isEmpty())
        sp->setSizes(sizes); // tmux 坐标直设（对半只在插入引擎）
    sp->show();              // 嵌套插入后补一拍显示（offscreen 无 expose 链）
    hookSplitter(sp);        // 0x8e12c0：root 下全部 QSplitter 接 splitterMoved
}

// ═══ 0x8e12c0 resize-pane 防抖 ═══

void MuxDesktop::hookSplitter(QSplitter *sp)
{
    connect(sp, &QSplitter::splitterMoved, this, [this, sp](int pos, int index) {
        m_handlePrev[sp] = m_handleMove.value(sp, {-1, -1}).pos; // 上一基线
        m_handleMove[sp] = {pos, index};
        m_movedSplitters.insert(sp);
        m_resizeDebounce->start(); // 防抖→批量下发
    });
}

// shortcut: 0x8e12c0 精确方向/计数语义挂账——当前以手柄净增量+首受拉窗格近似
// （L/R/U/D -t %paneId count，0x83eb50 命令面）
void MuxDesktop::sendPendingResizes()
{
    if (!m_tmux) {
        m_movedSplitters.clear();
        m_handleMove.clear();
        m_handlePrev.clear();
        return;
    }
    for (QSplitter *sp : qAsConst(m_movedSplitters)) {
        const HandleMove move = m_handleMove.value(sp, {-1, -1});
        const int prev = m_handlePrev.value(sp, -1);
        if (move.pos < 0 || move.index < 0 || prev < 0)
            continue;
        const int delta = move.pos - prev;
        if (delta == 0)
            continue;
        MuxPaneGroup *group = groupUnder(sp->widget(move.index));
        MuxPane *pane = group ? group->findChild<MuxPane *>() : nullptr;
        TerminalView *view = pane ? pane->view() : nullptr;
        if (!view || pane->paneId() < 0)
            continue;
        // 方向：手柄右/下移（delta>0）→左/上窗格扩大（-R/-D）；反之为 -L/-U
        const int dir = sp->orientation() == Qt::Horizontal ? (delta > 0 ? 1 : 0)
                                                            : (delta > 0 ? 3 : 2);
        const qreal cell = sp->orientation() == Qt::Horizontal ? view->cellSize().width()
                                                               : view->cellSize().height();
        const int count = qMax(1, int(qFabs(qreal(delta)) / qMax<qreal>(1.0, cell)));
        m_tmux->resizePane(pane->paneId(), dir, count);
    }
    m_movedSplitters.clear();
    m_handleMove.clear();
    m_handlePrev.clear();
}

MuxPaneGroup *MuxDesktop::groupUnder(QWidget *w) const
{
    if (!w)
        return nullptr;
    if (auto *g = qobject_cast<MuxPaneGroup *>(w))
        return g;
    return w->findChild<MuxPaneGroup *>();
}

// ═══ G：激活链（0x8e0bb2）═══

void MuxDesktop::onFocusChanged()
{
    QWidget *focus = QApplication::focusWidget();
    const bool inside = focus && isAncestorOf(focus);
    // TabBar state 刷新：活动页 "Active"、Z 窗 "Pinned"、余 "Normal"
    for (int i = 0; i < m_stack->count(); ++i) {
        auto *mw = qobject_cast<MuxWindow *>(m_stack->widget(i));
        if (!mw)
            continue;
        const bool active = inside && mw->isAncestorOf(focus);
        const int ti = mw->tabIndex();
        if (active) {
            if (m_tabBar->currentIndex() != ti)
                m_tabBar->setCurrentIndex(ti); // 页随焦点（0x8e0bb2 Active 驱动）
            m_stack->setCurrentWidget(mw);
        }
        const bool pinned = m_tmux
            && m_tmux->windows().value(mw->windowId()).rawFlags.contains(QLatin1Char('Z'));
        if (ti >= 0) {
            // shortcut: 页 state 属性挂账, QTabBar 无 per-tab property API(0x8e0bb2),
            // state 暂存 tabIndex 邻接 tabData（"Active"/"Pinned"/"Normal" 字符串面）
            const QString state = active   ? QStringLiteral("Active")
                                  : pinned ? QStringLiteral("Pinned")
                                           : QStringLiteral("Normal");
            m_pageStates[mw] = state;
        }
    }
    if (!inside || !m_tmux)
        return;
    // 祖先 MuxPane→currentPaneId!=paneId 时 select-pane（0x8e0bb2）
    const QList<MuxPane *> panes = findChildren<MuxPane *>();
    for (MuxPane *pane : panes) {
        if (!pane->isAncestorOf(focus))
            continue;
        for (QWidget *pw = pane->parentWidget(); pw; pw = pw->parentWidget()) {
            if (auto *mw = qobject_cast<MuxWindow *>(pw)) {
                if (mw->currentPaneId() != pane->paneId()) {
                    mw->setCurrentPaneId(pane->paneId());
                    m_tmux->selectPane(pane->paneId()); // 0x83f830 命令面
                }
                break;
            }
        }
        if (m_focusedPaneId != pane->paneId()) {
            m_focusedPaneId = pane->paneId();
            m_tmux->setActivePane(pane->paneId()); // 路由切位→outputCached 冲账→pane view
        }
        break;
    }
}

// ═══ F：补屏/尺寸/输出回灌 ═══

void MuxDesktop::onScreenCaptured(int paneId, bool altScreen, int historySize,
                                  const QByteArray &data)
{
    Q_UNUSED(altScreen);
    Q_UNUSED(historySize);
    // data 按 \r\n 拆行→TerminalView 整缓冲替换（0x877610 screenCaptured 链）
    if (TerminalView *view = viewForPane(paneId))
        view->loadScreen(QString::fromUtf8(data).split(QStringLiteral("\r\n")));
}

void MuxDesktop::onScreenResized(int paneId)
{
    if (!m_tmux)
        return;
    const Tmux::Pane &pane = m_tmux->panes().value(paneId);
    if (TerminalView *view = viewForPane(paneId); view && pane.w > 0 && pane.h > 0)
        view->resizeScreen(pane.w, pane.h);
}

void MuxDesktop::onTermsRemoved(const QList<int> &paneIds)
{
    for (int paneId : paneIds)
        for (MuxWindow *mw : m_pages)
            mw->removePane(paneId); // 摘除 view+cleanupEmptyTree（F 节）
    reconcile();                    // 空树清理兜底
}

void MuxDesktop::feedPaneView(int paneId, const QByteArray &data)
{
    if (TerminalView *view = viewForPane(paneId))
        view->feedVtData(data);
}

TerminalView *MuxDesktop::viewForPane(int paneId) const
{
    for (MuxWindow *mw : m_pages)
        if (TerminalView *view = mw->viewForPane(paneId))
            return view;
    return nullptr;
}

// ═══ H：关闭三态（0x8dd1b8）═══

void MuxDesktop::onTabCloseRequested(int index)
{
    MuxWindow *mw = nullptr;
    for (auto it = m_pages.constBegin(); it != m_pages.constEnd(); ++it) {
        if (it.value()->tabIndex() == index) {
            mw = it.value();
            break;
        }
    }
    if (!mw || !m_tmux)
        return;
    const Tmux::Window &w = m_tmux->windows().value(mw->windowId());
    // attach 窗→三按钮 &Detach Session/&Kill Session/&Cancel；非 attach→单确认
    if (w.attached) {
        QMessageBox box(this);
        box.setWindowTitle(tr("Close Tmux Window"));
        box.setText(tr("Detach or kill tmux session?"));
        QPushButton *detach = box.addButton(tr("&Detach Session"), QMessageBox::AcceptRole);
        QPushButton *kill = box.addButton(tr("&Kill Session"), QMessageBox::DestructiveRole);
        box.addButton(tr("&Cancel"), QMessageBox::RejectRole);
        box.exec();
        if (box.clickedButton() == detach)
            m_tmux->detachClient(); // broadcast detach-client
        else if (box.clickedButton() == kill)
            m_tmux->killSession(w.sessionName); // broadcast kill-session
        else
            return;
    } else {
        if (QMessageBox::question(this, tr("Close Tmux Window"), tr("Close this tmux window?"))
            != QMessageBox::Yes)
            return;
        m_tmux->killWindow(w.idx);
    }
    // 确认后页移除走 windowsRemoved/windowsChanged→reconcile 删除 pass
}

// ═══ J：wind.actions Tmux.* script 面（desktop 命令桥）═══

QString MuxDesktop::currentTmuxSessionName() const
{
    if (!m_currentSessionName.isEmpty())
        return m_currentSessionName;
    for (const auto &w : m_tmux ? m_tmux->windows() : QMap<int, Tmux::Window>())
        if (!w.sessionName.isEmpty())
            return w.sessionName;
    return QString();
}

void MuxDesktop::attachTmuxSession(const QString &name)
{
    if (m_tmux)
        m_tmux->attachSession(name);
}

void MuxDesktop::detachTmuxClient()
{
    if (m_tmux)
        m_tmux->detachClient();
}

void MuxDesktop::killTmuxSession(const QString &name)
{
    if (m_tmux)
        m_tmux->killSession(name);
}

// QInputDialog 直发（0x83eaa6 sendCommand 面）
void MuxDesktop::executeTmuxCommand()
{
    if (!m_tmux)
        return;
    bool ok = false;
    const QString cmd = QInputDialog::getText(this, tr("Execute Tmux Command"),
                                              tr("Command:"), QLineEdit::Normal, QString(), &ok);
    if (ok && !cmd.trimmed().isEmpty())
        m_tmux->sendCommand(cmd.trimmed());
}

void MuxDesktop::renameTmuxSession()
{
    if (!m_tmux)
        return;
    const QString oldName = currentTmuxSessionName();
    bool ok = false;
    const QString newName = QInputDialog::getText(this, tr("Rename Session"), tr("Name:"),
                                                  QLineEdit::Normal, oldName, &ok);
    if (ok && !newName.trimmed().isEmpty() && !oldName.isEmpty())
        m_tmux->renameSession(oldName, newName.trimmed());
}

void MuxDesktop::selectTmuxLayout(const QString &name)
{
    // wind.actions 7 布局列表→tmux 布局名（mirrored 变体映射基名，镜像差异挂账）
    static const QHash<QString, QString> kMap = {
        {QStringLiteral("Even horizontal"), QStringLiteral("even-horizontal")},
        {QStringLiteral("Even vertical"), QStringLiteral("even-vertical")},
        {QStringLiteral("Main horizontal"), QStringLiteral("main-horizontal")},
        {QStringLiteral("Main horizontal mirrored"), QStringLiteral("main-horizontal")},
        {QStringLiteral("Main vertical"), QStringLiteral("main-vertical")},
        {QStringLiteral("Main vertical mirrored"), QStringLiteral("main-vertical")},
        {QStringLiteral("Tiled"), QStringLiteral("tiled")},
    };
    if (m_tmux)
        m_tmux->selectLayout(kMap.value(name, name.toLower()));
}

void MuxDesktop::synchronizeTmuxPanes(bool on)
{
    if (m_tmux)
        m_tmux->setSynchronize(on);
}
