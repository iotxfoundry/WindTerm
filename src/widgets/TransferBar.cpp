#include "TransferBar.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPropertyAnimation>
#include <QToolButton>

#include "core/LocaleManager.h"

TransferBar::TransferBar(QWidget *parent)
    : QWidget(parent)
    , m_transferLabel(new QLabel(this))
    , m_openButton(new QToolButton(this))
    , m_closeButton(new QToolButton(this))
{
    setObjectName(QStringLiteral("TransferBar"));
    setWindowTitle(LocaleManager::instance().tr(QStringLiteral("Transfer Bar")));
    setAttribute(Qt::WA_StyledBackground, true);
    setAttribute(Qt::WA_DeleteOnClose, true);

    m_transferLabel->setObjectName(QStringLiteral("TransferLabel"));
    m_transferLabel->setText(tr("No transfer tasks"));
    m_openButton->setObjectName(QStringLiteral("OpenButton"));
    m_openButton->setText(tr("Open"));
    m_openButton->setAutoRaise(true);
    m_closeButton->setObjectName(QStringLiteral("CloseButton"));
    m_closeButton->setText(QStringLiteral("×"));
    m_closeButton->setAutoRaise(true);

    auto *layout = new QHBoxLayout(this);
    layout->setContentsMargins(4, 0, 4, 0);
    layout->addWidget(m_transferLabel, 1);
    layout->addWidget(m_openButton);
    layout->addWidget(m_closeButton);

    connect(m_closeButton, &QToolButton::clicked, this, &TransferBar::collapseAndClose);
    // shortcut: OpenButton 打开传输面板行为（0x0085af56 未逆完）, 传输面板接线时补
}

void TransferBar::collapseAndClose()
{
    // 0x005858fe：maximumHeight 动画收展后再关闭
    auto *animation = new QPropertyAnimation(this, "maximumHeight", this);
    animation->setDuration(150);
    animation->setStartValue(height());
    animation->setEndValue(0);
    connect(animation, &QPropertyAnimation::finished, this, &QWidget::close);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
