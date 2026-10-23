#include "PaneHeader.h"

#include <QEvent>
#include <QHBoxLayout>
#include <QLabel>
#include <QStyle>
#include <QToolButton>
#include <QVariant>

PaneHeader::PaneHeader(const QString &title, QWidget *parent)
    : QWidget(parent)
{
    setObjectName(QStringLiteral("PaneHeader"));
    auto *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(4);

    m_state = new QLabel(this);
    m_state->setObjectName(QStringLiteral("StateLabel"));

    auto *icon = new QLabel(this);
    icon->setObjectName(QStringLiteral("IconLabel"));

    auto *title1 = new QLabel(title, this);
    title1->setObjectName(QStringLiteral("TitleLabel"));

    // CloseButton 默认隐藏，hover 头部行显隐（0x55332c/0x553354）；点击只发信号（0x008f0512）
    m_closeButton = new QToolButton(this);
    m_closeButton->setObjectName(QStringLiteral("CloseButton"));
    m_closeButton->setText(QStringLiteral("\u2715"));
    m_closeButton->setVisible(false);
    m_closeButton->setAutoRaise(true);

    layout->addWidget(m_state);
    layout->addWidget(icon);
    layout->addWidget(title1);
    layout->addStretch();
    layout->addWidget(m_closeButton);

    connect(m_closeButton, &QToolButton::clicked, this, &PaneHeader::closeRequested);
}

void PaneHeader::state(const QString &state)
{
    m_state->setProperty("state", state);    m_state->style()->unpolish(m_state);
    m_state->style()->polish(m_state);
}

bool PaneHeader::event(QEvent *event)
{
    if (event->type() == QEvent::Enter)
        m_closeButton->setVisible(true);
    else if (event->type() == QEvent::Leave)
        m_closeButton->setVisible(false);
    return QWidget::event(event);
}
