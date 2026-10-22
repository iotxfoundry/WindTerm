#pragma once

#include <QMainWindow>

#include "core/LocaleManager.h"

class QCloseEvent;
class QLabel;
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

private:
    void createMenus();
    void createCentralWidget();
    void createDocks();
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
