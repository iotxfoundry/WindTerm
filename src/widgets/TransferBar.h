#pragma once

#include <QWidget>

class QLabel;
class QToolButton;

// 原版 TransferBar（0x005858fe）：CloseButton+OpenButton+TransferLabel，
// WA_DeleteOnClose，maximumHeight QPropertyAnimation 收展；懒建插入底部（0x0085af56）。
class TransferBar : public QWidget
{
    Q_OBJECT

public:
    explicit TransferBar(QWidget *parent = nullptr);

private:
    void collapseAndClose();

    QLabel *m_transferLabel;
    QToolButton *m_openButton;
    QToolButton *m_closeButton;
};
