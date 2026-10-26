#pragma once

#include <QMap>
#include <QString>
#include <QWidget>

class QSplitter;
class QStackedLayout;
class MuxDesktop;
class MuxPaneGroup;
class TerminalView;

// P7b MuxWindow（0x8e0938/0x8dffa0/0x5a2314 照搬）：
// QWidget objectName "MuxWindow"；布局 QVBoxLayout(0,0)[SplitterGroup]；
// SplitterGroup=QWidget 包[QSplitter(Vertical,childrenCollapsible=false)+
// QStackedLayout(0,0) 包 splitter]（stack.currentWidget()=当前根 splitter）。
// 字段：paneId→MuxPaneGroup 表、windowIdx、currentPaneId(-1 初)、
// name 属性（signal nameChanged，缺省 tr"Untitled"）、desktop 指针。
class MuxWindow : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit MuxWindow(MuxDesktop *desktop, QWidget *parent = nullptr);

    MuxDesktop *desktop() const { return m_desktop; }
    int windowId() const { return m_windowId; }
    void setWindowId(int id) { m_windowId = id; }
    int windowIdx() const { return m_windowIdx; } // +0x44=idx
    void setWindowIdx(int idx) { m_windowIdx = idx; }
    int tabIndex() const { return m_tabIndex; } // MuxDesktop 页签位（QTabBar 无 indexOf(QWidget)）
    void setTabIndex(int i) { m_tabIndex = i; }
    int currentPaneId() const { return m_currentPaneId; }
    void setCurrentPaneId(int paneId) { m_currentPaneId = paneId; }

    QString name() const { return m_name; }
    void setName(const QString &name);

    // SplitterGroup stack 当前件=根 splitter（zoom 换出槽挂账）
    QSplitter *rootSplitter() const { return m_root; }

    MuxPaneGroup *groupForPane(int paneId) const { return m_paneGroups.value(paneId); }
    const QMap<int, MuxPaneGroup *> &paneGroups() const { return m_paneGroups; }
    // 新建组（tmux 模式 attached 按钮面）+MuxPane+TerminalView（0x8de1a8 语义）
    MuxPaneGroup *ensurePaneGroup(int paneId, bool attached, const QString &title);
    TerminalView *viewForPane(int paneId) const;
    // pane 摘除（termsRemoved 链 0x84dd5a 删除段）：cleanupEmptyTree
    void removePane(int paneId);

signals:
    void nameChanged(const QString &name);

private:
    MuxDesktop *m_desktop;
    QWidget *m_splitterGroup;
    QStackedLayout *m_stackLayout;
    QSplitter *m_root;
    QMap<int, MuxPaneGroup *> m_paneGroups;
    int m_windowId = -1;
    int m_windowIdx = -1;
    int m_tabIndex = -1;
    int m_currentPaneId = -1;
    QString m_name;
};
