#pragma once

#include <QDialog>

class QCheckBox;
class QStackedWidget;
class QTabBar;

// 0x006b6676 ctor / 0x006b639e setupUi / 0x006b6156 页填充（addTab("Editor"/"Terminal")）。
class FocusModeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FocusModeDialog(QWidget *parent = nullptr);

    // 接线面：模态弹出；checkbox 落键 focusMode.openFocusModeDialog（wind.config:24）
    static void open(QWidget *parent);

private:
    QTabBar *m_tabBar;         // +0x30
    QStackedWidget *m_stack;   // +0x38
    QCheckBox *m_showDialog;   // +0x40
};
