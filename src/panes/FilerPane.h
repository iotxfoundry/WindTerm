#pragma once

#include "KitPane.h"

class FileSystemModel;
class QLabel;
class QLineEdit;
class PaneHeader;
class QStackedWidget;
class QTimer;
class QTreeView;
class SshSession;

// P5 重写（0x731066/0x730d9c）：QStackedWidget 两页（本地视图/远程视图,各 QTreeView 挂
// FileSystemModel）+ 状态 QLabel。KitPane 基类与底部条挂载保持不变。
// shortcut: 终端 cwd 跟踪（0x730d9c +0x208 AutoSync）未接——重建无终端 cwd 跟踪,挂账
class FilerPane : public KitPane
{
    Q_OBJECT

public:
    explicit FilerPane(QWidget *parent = nullptr);

    // 本地/远程切换（0x5773d6 语义）：当前活动会话是 SshSession→远程页（该会话 sftp）,
    // 否则本地页。shortcut: Transfer 对象判型简化为 SshSession 判型,Transfer 体系挂账 P6
    void setRemoteSession(SshSession *session);
    // 会话终局：撤远程句柄（sftp 已随 teardown free,防悬垂）
    void dropRemoteSession(SshSession *session);
    // FilterEdit（toolbar.config FilerPane 节,经 installPaneToolBar 建）→ cd 防抖 250ms
    //（mode 0x10 语义）；MainWindow 在 installPaneToolBar 后调用
    void hookAddressEdit();
    void focusAddressEdit();

    // 浏览动作落点（wind.actions FilerPane.*；上传/下载/Remove/Rename 挂账 P6）
    void reload();
    void cdUp();
    void goBackward();
    void goForward();
    bool canGoBackward() const;
    bool canGoForward() const;
    void toggleHiddenItems();
    bool showHidden() const;
    QString currentPath() const;

signals:
    void closeRequested();

private:
    void cd(const QString &path, bool pushHistory = true);
    FileSystemModel *activeModel() const;
    void applyRemotePage();

    PaneHeader *m_header;
    QStackedWidget *m_stack;
    QTreeView *m_localView;
    QTreeView *m_remoteView;
    FileSystemModel *m_localModel;
    FileSystemModel *m_remoteModel;
    QLabel *m_status;
    QLineEdit *m_address = nullptr;
    QTimer *m_cdDebounce;
    SshSession *m_remoteSession = nullptr;
    QStringList m_history; // 0x578d88：路径历史+游标（idx>0 后退/idx<count-1 前进）
    int m_historyIdx = -1;
    bool m_showHidden;
};
