#include "TransferBar.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPropertyAnimation>
#include <QShowEvent>
#include <QToolButton>

#include <QEasingCurve>

#include "core/LocaleManager.h"
#include "core/ThemeManager.h"
#include "widgets/KingIcons.h"

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

    // 0x585528 HBox margins 0；序 [TransferLabel(insertWidget 0 最左), addStretch, Open, Close]
    m_transferLabel->setObjectName(QStringLiteral("TransferLabel"));
    // 0x585c8f：TransferLabel 由传输内容存在性驱动（label destroyed→bar close）；重建无传输
    // 内容，bar 常空隐藏即可，label 占位留待传输功能接入
    m_transferLabel->setText(tr("No transfer tasks"));

    // 0x5850c6：OpenButton 纯文字（无 icon、无 AutoRaise）+ NoFocus；点击打开 transfer pane
    // （重建无 transfer pane 切换，Q_UNIMPLEMENTED 挂账）
    m_openButton->setObjectName(QStringLiteral("OpenButton"));
    m_openButton->setText(tr("Open"));
    m_openButton->setFocusPolicy(Qt::NoFocus);

    // 0x5850c6：CloseButton icon king::close + tooltip "Close" + AutoRaise + NoFocus；
    // clicked→bar->close()
    m_closeButton->setObjectName(QStringLiteral("CloseButton"));
    m_closeButton->setIcon(KingIcons::icon(QStringLiteral("close"),
                                           ThemeManager::instance().currentTheme()));
    m_closeButton->setToolTip(tr("Close"));
    m_closeButton->setAutoRaise(true);
    m_closeButton->setFocusPolicy(Qt::NoFocus);

    auto *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_transferLabel, 0);
    layout->addStretch();
    layout->addWidget(m_openButton);
    layout->addWidget(m_closeButton);

    connect(m_openButton, &QToolButton::clicked, this, []() {
        Q_UNIMPLEMENTED(); // shortcut: 打开 transfer pane（0x0085af56）挂账, 传输面板接线时补
    });
    connect(m_closeButton, &QToolButton::clicked, this, &QWidget::close);
}

// 0x585b26：show 时 maximumHeight 动画 0→sizeHint().height()，OutQuad（duration 未恢复，
// 取 200 挂账）
void TransferBar::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    auto *animation = new QPropertyAnimation(this, "maximumHeight", this);
    animation->setDuration(200);
    animation->setStartValue(0);
    animation->setEndValue(sizeHint().height());
    animation->setEasingCurve(QEasingCurve::OutQuad);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
