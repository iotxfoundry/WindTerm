#include "TransferPane.h"

#include <QLabel>
#include <QProgressBar>
#include <QVBoxLayout>

TransferPane::TransferPane(QWidget *parent)
    : QWidget(parent)
    , m_fileLabel(new QLabel(tr("windterm-2.7.0.tar.gz"), this))
    , m_progressBar(new QProgressBar(this))
{
    m_progressBar->setRange(0, 100);
    m_progressBar->setValue(100);
    m_progressBar->setFormat(tr("100%"));

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(m_fileLabel);
    layout->addWidget(m_progressBar);
    layout->addStretch();
}
