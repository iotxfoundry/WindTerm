#pragma once

#include <QMainWindow>
#include <QPoint>

#include "core/LocaleManager.h"
#include "core/MenuConfig.h"

struct ToolbarEntry;

class QCloseEvent;
class QAction;
class QEvent;
class QLabel;
class QLineEdit;
class QMenu;
class QResizeEvent;
class QTabBar;
class QTimer;
class QToolBar;
class QToolButton;
class MuxPaneGroup;
class QuickBar;
class SearchPane;
class SessionPane;
class TerminalView;
class TransferBar;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

protected:
    void closeEvent(QCloseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void onPlaceholderAction();
    void onRestoreLayout();
    void updateClock();
    void togglePane(QWidget *pane);
    void onAddressBarReturn();

private:
    void createMenus();
    void createFallbackMenus();
    void createToolBar();
    void addToolBarEntry(QToolBar *toolBar, const ToolbarEntry &entry);
    void installPaneToolBar(QWidget *pane);
    QWidget *paneHost(QWidget *pane);
    void buildMenu(QMenu *menu, const QVector<MenuEntry> &entries);
    void showPopupMenu(QWidget *paneLike, Qt::KeyboardModifiers mods);
    // TerminalView::contextMenuRequested 落点：sender() 即 view（UniqueConnection 去重连）
    void onTerminalContextMenu(const QPoint &globalPos, Qt::KeyboardModifiers mods);
    QAction *makeAction(const QString &actionId);
    static QString displayActionText(const QString &en, const QString &translated);
    void createCentral();
    void createStatusBar();
    QWidget *createBottomTabs();
    QString makeMenuTitle(const QString &base, int n) const;
    void initActionRegistry();
    void connectSessionPane(SessionPane *pane);
    QuickBar *ensureQuickBar();
    void toggleQuickBar();
    void updateWindowSizeLabel();

    LocaleManager &m_locale;
    MuxPaneGroup *m_muxPaneGroup;
    QToolBar *m_toolBar = nullptr;
    QLineEdit *m_addressBar;
    QLabel *m_windowSizeLabel = nullptr;
    QLabel *m_caretLabel = nullptr;
    QLabel *m_clockLabel = nullptr;
    QTimer *m_clockTimer = nullptr;
    QToolButton *m_modeButton = nullptr;
    QToolButton *m_schemeButton = nullptr;
    bool m_localMode = false;
    QTabBar *m_viewTabBar = nullptr; // MuxPaneGroup 标签条（无 objectName），"ViewTab Popup" 映射用
    QuickBar *m_quickBar = nullptr; // 懒建（0x85ad2e），toggleQuickBar 首次创建
    SearchPane *m_searchPane = nullptr;
    TransferBar *m_transferBar = nullptr; // shortcut: 懒建点挂账（0x85af56 传输启动时建），传输功能实现时接入
};
