#include "MuxPane.h"

#include "TerminalView.h"

MuxPane::MuxPane(int paneId, QWidget *parent)
    : QWidget(parent)
    , m_layout(new QVBoxLayout(this))
    , m_paneId(paneId)
{
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->setSpacing(0);
}

void MuxPane::setView(TerminalView *view)
{
    // 0x8de1a8 addChildWidget：旧子 deleteLater→addWidget+setFocusProxy
    if (m_view == view)
        return;
    if (m_view)
        m_view->deleteLater();
    m_view = view;
    m_layout->addWidget(view);
    setFocusProxy(view);
}
