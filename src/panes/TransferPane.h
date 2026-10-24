#pragma once

#include "KitPane.h"

class QLabel;
class QProgressBar;

class TransferPane : public KitPane
{
    Q_OBJECT

public:
    explicit TransferPane(QWidget *parent = nullptr);

private:
    QLabel *m_fileLabel;
    QProgressBar *m_progressBar;
};
