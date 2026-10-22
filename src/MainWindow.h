#pragma once

#include <QMainWindow>

#include "core/LocaleManager.h"
#include "core/MenuConfig.h"

class QCloseEvent;
class QAction;
class QLabel;
class QMenu;
class QTimer;
class AppletBar;
class MuxPaneGroup;

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

    LocaleManager &m_locale;
    MuxPaneGroup *m_muxPaneGroup;
    AppletBar *m_appletBar;
    QLabel *m_readyLabel;
    QLabel *m_clockLabel;
    QTimer *m_clockTimer;
};
