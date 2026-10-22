#pragma once

#include <QMainWindow>

class QLabel;
class QTimer;
class CommandButtonBar;
class MuxPaneGroup;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void onPlaceholderAction();
    void updateClock();

private:
    void createMenus();
    void createCentralWidget();
    void createDocks();
    void createStatusBar();
    QWidget *createSenderTransferTabs();

    MuxPaneGroup *m_muxPaneGroup;
    CommandButtonBar *m_commandButtonBar;
    QLabel *m_clockLabel;
    QTimer *m_clockTimer;
};
