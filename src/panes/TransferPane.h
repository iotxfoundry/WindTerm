#pragma once

#include <QWidget>

class QLabel;
class QProgressBar;

class TransferPane : public QWidget
{
    Q_OBJECT

public:
    explicit TransferPane(QWidget *parent = nullptr);

private:
    QLabel *m_fileLabel;
    QProgressBar *m_progressBar;
};
