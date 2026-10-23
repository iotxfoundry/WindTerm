#include "TransferPane.h"

#include <QLabel>
#include <QProgressBar>
#include <QVBoxLayout>

#include "core/LocaleManager.h"

TransferPane::TransferPane(QWidget *parent)
    : QWidget(parent)
    , m_fileLabel(new QLabel(tr("windterm-2.7.0.tar.gz"), this))
    , m_progressBar(new QProgressBar(this))
{
    // KitPane 三连 0x008c3bbe：objectName → setWindowIcon（挂账）→ setWindowTitle(King_title 0x008a1106)
    setObjectName(QStringLiteral("TransferPane"));
    setWindowTitle(LocaleManager::instance().tr(QStringLiteral("Transfer")));
    // shortcut: setWindowIcon 挂账, paneIconFactory 未实现
    m_progressBar->setRange(0, 100);
    m_progressBar->setValue(100);
    m_progressBar->setFormat(tr("100%"));

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(m_fileLabel);
    layout->addWidget(m_progressBar);
    layout->addStretch();
}
