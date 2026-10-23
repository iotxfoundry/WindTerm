#pragma once

#include <QWidget>

class QLabel;
class QShowEvent;
class QToolButton;

// 原版 TransferBar（0x005858fe）：[TransferLabel, stretch, OpenButton, CloseButton]，
// WA_DeleteOnClose，maximumHeight QPropertyAnimation 收展（0x585b26）；懒建插入底部
// （0x0085af56）。
class TransferBar : public QWidget
{
    Q_OBJECT

public:
    explicit TransferBar(QWidget *parent = nullptr);

protected:
    void showEvent(QShowEvent *event) override;

private:
    QLabel *m_transferLabel;
    QToolButton *m_openButton;
    QToolButton *m_closeButton;
};
