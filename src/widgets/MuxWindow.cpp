#include "MuxWindow.h"

#include <QSplitter>
#include <QStackedLayout>
#include <QVBoxLayout>

#include "MuxDesktop.h"
#include "MuxPane.h"
#include "MuxPaneGroup.h"
#include "PaneManager.h"
#include "TerminalView.h"

MuxWindow::MuxWindow(MuxDesktop *desktop, QWidget *parent)
    : QWidget(parent)
    , m_desktop(desktop)
    , m_splitterGroup(new QWidget(this))
    , m_stackLayout(new QStackedLayout(m_splitterGroup))
    , m_root(new QSplitter(Qt::Vertical))
{
    setObjectName(QStringLiteral("MuxWindow")); // 0x8e0938
    m_splitterGroup->setObjectName(QStringLiteral("SplitterGroup"));
    m_stackLayout->setContentsMargins(0, 0, 0, 0);
    m_stackLayout->setSpacing(0);
    m_root->setChildrenCollapsible(false);
    m_stackLayout->addWidget(m_root); // stack.currentWidget()=当前根 splitter

    auto *vbox = new QVBoxLayout(this);
    vbox->setContentsMargins(0, 0, 0, 0);
    vbox->setSpacing(0);
    vbox->addWidget(m_splitterGroup);

    setName(tr("Untitled")); // 缺省（0x8e0938 name 属性）
}

void MuxWindow::setName(const QString &name)
{
    if (m_name == name)
        return;
    m_name = name;
    emit nameChanged(m_name); // 变更才发（0x84dd5a 改名段）
}

MuxPaneGroup *MuxWindow::ensurePaneGroup(int paneId, bool attached, const QString &title)
{
    if (MuxPaneGroup *group = m_paneGroups.value(paneId))
        return group;
    auto *group = new MuxPaneGroup(this);
    group->initTmuxMode(attached);
    // pane 视图（0x8de1a8 内嵌 TerminalWidget 语义）：MuxPane 包 TerminalView（F 节）
    auto *pane = new MuxPane(paneId, group);
    auto *view = new TerminalView(QStringLiteral("tmux"), pane);
    view->ensureScreenModel(80, 24); // 无会话独立缓冲；尺寸随 pane 模型 resizeScreen 修正
    pane->setView(view);
    group->attachTmuxPane(pane, title); // 标题 "%1:%2" paneId:name（0x84b483 链）
    m_paneGroups.insert(paneId, group);
    group->show();
    if (m_root->count() == 0)
        m_root->addWidget(group); // 首组兜底挂根；树形由 MuxDesktop restoreSplitterTree 重排
    return group;
}

TerminalView *MuxWindow::viewForPane(int paneId) const
{
    const MuxPaneGroup *group = m_paneGroups.value(paneId);
    const MuxPane *pane = group ? group->findChild<MuxPane *>() : nullptr;
    return pane ? pane->view() : nullptr;
}

void MuxWindow::removePane(int paneId)
{
    MuxPaneGroup *group = m_paneGroups.take(paneId);
    if (!group)
        return;
    // 0x84dd5a 摘除 pass：组在 splitter 树→cleanupEmptyTree（0x5a29e6 引擎）；
    // 未挂树（尚未 restore）→直接弃
    if (qobject_cast<QSplitter *>(group->parentWidget()))
        PaneManager::cleanupEmptyTree(group, group);
    else
        group->deleteLater();
}
