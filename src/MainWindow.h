#pragma once

#include <QMainWindow>

#include "core/LocaleManager.h"
#include "core/MenuConfig.h"

class QCloseEvent;
class QAction;
class QLabel;
class QLineEdit;
class QMenu;
class QTimer;
class QToolBar;
class MuxPaneGroup;
class QuickBar;
class SessionPane;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

protected:
    void closeEvent(QCloseEvent *event) override;

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
    void buildMenu(QMenu *menu, const QVector<MenuEntry> &entries);
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

    LocaleManager &m_locale;
    MuxPaneGroup *m_muxPaneGroup;
    QToolBar *m_toolBar = nullptr;
    QLineEdit *m_addressBar;
    QLabel *m_readyLabel;
    QLabel *m_clockLabel;
    QTimer *m_clockTimer;
    QuickBar *m_quickBar = nullptr; // 惰性创建（0x0085ad2e：首次显示才构建）
};
