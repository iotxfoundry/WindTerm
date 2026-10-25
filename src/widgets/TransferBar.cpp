#include "TransferBar.h"

#include <QHash>
#include <QHBoxLayout>
#include <QLabel>
#include <QPropertyAnimation>
#include <QShowEvent>
#include <QToolButton>
#include <QVBoxLayout>

#include <QEasingCurve>

#include "core/LocaleManager.h"
#include "core/ThemeManager.h"
#include "panes/TransferPane.h"
#include "transfer/TransferCenter.h"
#include "widgets/KingIcons.h"

TransferBar::TransferBar(QWidget *parent)
    : QWidget(parent)
    , m_layout(nullptr)
    , m_openButton(new QToolButton(this))
    , m_closeButton(new QToolButton(this))
{
    setObjectName(QStringLiteral("TransferBar"));
    setWindowTitle(LocaleManager::instance().tr(QStringLiteral("Transfer Bar")));
    setAttribute(Qt::WA_StyledBackground, true);
    setAttribute(Qt::WA_DeleteOnClose, true);

    // 0x585528 HBox margins 0；序 [TransferLabel...(insertWidget 0 最左), stretch, Open, Close]
    m_layout = new QHBoxLayout(this);
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addStretch();
    // 0x5850c6：OpenButton 纯文字（无 icon、无 AutoRaise）+ NoFocus；文本="Show All"（0xc8aa78）
    m_openButton->setObjectName(QStringLiteral("OpenButton"));
    m_openButton->setText(LocaleManager::instance().tr(QStringLiteral("Show All")));
    m_openButton->setFocusPolicy(Qt::NoFocus);
    // 0x585f10：clicked→关 bar+开 TransferPane（原版经 slot 切 pane——骨架 findChild 懒路径）
    connect(m_openButton, &QToolButton::clicked, this, [this]() {
        close();
        if (QWidget *pane = window()->findChild<QWidget *>(QStringLiteral("TransferPane")))
            pane->show();
    });

    // 0x5850c6：CloseButton icon king::close + tooltip "Close" + AutoRaise + NoFocus；
    // clicked→bar->close()
    m_closeButton->setObjectName(QStringLiteral("CloseButton"));
    m_closeButton->setIcon(KingIcons::icon(QStringLiteral("close"),
                                           ThemeManager::instance().currentTheme()));
    m_closeButton->setToolTip(tr("Close"));
    m_closeButton->setAutoRaise(true);
    m_closeButton->setFocusPolicy(Qt::NoFocus);
    connect(m_closeButton, &QToolButton::clicked, this, &QWidget::close);

    m_layout->addWidget(m_openButton);
    m_layout->addWidget(m_closeButton);
}

void TransferBar::hookTransferCenter(TransferCenter *center)
{
    if (!center || m_center)
        return;
    m_center = center;
    // 懒建触发：kind 0=建标签（0x5850c6 createLabel;方向读行属性 transfer.upload——
    // ensureTaskRow 后 setTaskProperty 已在行内）;kind 4=刷新（0x58722a）;
    // kind 2=删行（label 随行键定位 deleteLater——0x61b206 收口末端）
    connect(center, &TransferCenter::taskEvent, this,
            [this](const QString &path, int kind) {
        if (kind == TransferCenter::LabelCreate) {
            const bool upload = m_center->taskProperties(path)
                                    .contains(QStringLiteral("transfer.upload"));
            m_uploadByPath.insert(path, upload);
            createLabel(path, upload);
        } else if (kind == TransferCenter::Refresh) {
            refreshLabel(path);
        } else if (kind == TransferCenter::LabelRemove) {
            if (TransferLabel *label = labelFor(path))
                label->deleteLater();
        }
    });
}

TransferLabel *TransferBar::labelFor(const QString &path) const
{
    // 0x585d68 同构：qFindChildren<TransferLabel*> 线性按 path 匹配
    const auto labels = findChildren<TransferLabel *>();
    for (TransferLabel *label : labels)
        if (label->path() == path)
            return label;
    return nullptr;
}

// 0x5850c6 createLabel 原样复刻：new TransferLabel(center,path,this)→insertWidget(0)→show；
// destroyed（无剩余）→close（0x585c8f）
void TransferBar::createLabel(const QString &path, bool upload)
{
    if (labelFor(path) || !m_center)
        return;
    auto *label = new TransferLabel(m_center, path, upload, this);
    connect(label, &TransferLabel::lastLabelClosed, this, &QWidget::close);
    m_layout->insertWidget(0, label); // 0x5850c6 insertWidget(layout,0,label,0,0)
    label->show();
    // 0x585c8f：label destroyed→查剩余,空→close（Queued 延迟查,析构链内安全）
    connect(label, &QObject::destroyed, this, [this]() {
        if (findChildren<TransferLabel *>().isEmpty())
            close();
    });
}

// 0x58722a 刷新链落点：taskEvent(4)→行 label refresh()
void TransferBar::refreshLabel(const QString &path)
{
    if (TransferLabel *label = labelFor(path))
        label->refresh();
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
