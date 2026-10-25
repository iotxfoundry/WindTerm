#include "TransferLabel.h"

#include <QAction>
#include <QFontMetrics>
#include <QHBoxLayout>
#include <QLabel>
#include <QMenu>
#include <QTimer>
#include <QToolButton>

#include "transfer/TransferCenter.h"
#include "core/LocaleManager.h"
#include "core/ThemeManager.h"
#include "widgets/KingIcons.h"

namespace {
// 0x58722a：0x1e（30）空格宽门——超宽 QFontMetrics::horizontalAdvance(' ')*30 elide
constexpr int kElideSpaceCount = 30;
} // namespace

TransferLabel::TransferLabel(TransferCenter *center, const QString &path, bool upload,
                             QWidget *parent)
    : QFrame(parent)
    , m_center(center)
    , m_path(path)
    , m_upload(upload)
{
    setObjectName(QStringLiteral("TransferLabel")); // qFindChildren<TransferLabel*>（0x585c8f）
    setFrameStyle(QFrame::StyledPanel);

    auto *layout = new QHBoxLayout(this);
    layout->setContentsMargins(4, 0, 4, 0);
    m_text = new QLabel(this);
    layout->addWidget(m_text);

    // 内嵌 ActionButton（createLabel 0x5850c6）：方向箭头 + 下拉菜单
    auto *actionButton = new QToolButton(this);
    actionButton->setObjectName(QStringLiteral("ActionButton"));
    actionButton->setIcon(KingIcons::icon(m_upload ? QStringLiteral("up")
                                                   : QStringLiteral("down"),
                                          ThemeManager::instance().currentTheme()));
    actionButton->setAutoRaise(true);
    actionButton->setPopupMode(QToolButton::InstantPopup);
    actionButton->setFocusPolicy(Qt::NoFocus);
    m_menu = new QMenu(actionButton);
    // 暂停/恢复（wind.actions TransferPane.Pause 文案随状态）/移除（0x61b176/0x61b2a8/0x61b206）
    m_pauseAction = m_menu->addAction(LocaleManager::instance().tr(QStringLiteral("Pause")));
    connect(m_pauseAction, &QAction::triggered, this, [this] {
        const QVariantMap map = m_center->taskProperties(m_path);
        if (map.value(QStringLiteral("transfer.state")).toString() == QLatin1String("Paused"))
            m_center->resumeTask(m_path);
        else
            m_center->pauseTask(m_path);
        refresh();
    });
    m_menu->addAction(LocaleManager::instance().tr(QStringLiteral("Remove")));
    connect(m_menu->actions().last(), &QAction::triggered, this,
            [this] { m_center->removeTask(m_path); });
    actionButton->setMenu(m_menu);
    layout->addWidget(actionButton);

    refresh();
}

TransferLabel::~TransferLabel()
{
    // 0x585c8f：找剩余 TransferLabel，空→bar close（经 lastLabelClosed 收口）
    QMetaObject::invokeMethod(this, [this] {
        if (m_center && m_center->findChildren<TransferLabel *>().isEmpty())
            emit lastLabelClosed();
    }, Qt::QueuedConnection);
}

void TransferLabel::refresh()
{
    if (!m_center)
        return;
    const QVariantMap map = m_center->taskProperties(m_path);
    const int percent = map.value(QStringLiteral("transfer.weightPercent")).toInt();
    const QString itemName = map.value(QStringLiteral("transfer.currentItemName")).toString();
    QString name = itemName.isEmpty() ? m_path : itemName;
    // 0x1e 空格宽 elide（0x58722a：仅超宽才 QFontMetrics::elidedText(Qt::ElideMiddle)）
    QFontMetrics fm(m_text->font());
    const int maxWidth = fm.horizontalAdvance(QLatin1Char(' ')) * kElideSpaceCount;
    if (fm.horizontalAdvance(name) > maxWidth)
        name = fm.elidedText(name, Qt::ElideMiddle, maxWidth);

    QString text;
    const QString state = map.value(QStringLiteral("transfer.state")).toString();
    const int failed = map.value(QStringLiteral("transfer.failedCount")).toInt();
    if (percent == 100 && state.isEmpty()) {
        // 完成语（0x58722a：transfer.download→"%1 %2"%downloaded/transfer.upload→uploaded）。
        // 方向二源（行属性为真源——label ctor 形参仅建行时快照,刷新链以属性判）
        const bool upload = map.contains(QStringLiteral("transfer.upload"))
                                ? true
                                : (map.contains(QStringLiteral("transfer.download")) ? false
                                                                                    : m_upload);
        const QString verb = upload ? LocaleManager::instance().tr(QStringLiteral("uploaded"))
                                    : LocaleManager::instance().tr(QStringLiteral("downloaded"));
        text = QStringLiteral("%1 %2").arg(verb, name);
        if (failed > 0) {
            // 失败红字（0x58722a：<font color="red">%1 %2</font>，单/复数两串）
            const QString unit = failed == 1 ? tr("%1 item failed") : tr("%1 items failed");
            text += QStringLiteral(" <font color=\"red\">%1 %2</font>")
                        .arg(unit.arg(failed), name);
        }
        m_text->setText(text);
        if (!m_completed) {
            m_completed = true;
            // 0x58722a：QTimer::singleShot(30000, deleteLater) 实证
            QTimer::singleShot(30000, this, &QObject::deleteLater);
        }
    } else if (!state.isEmpty()) {
        // 运行中状态行（Paused→king::paused 图标；Pausing/Resuming/Removing→对应文案）
        if (state == QLatin1String("Paused")) {
            m_pauseAction->setText(LocaleManager::instance().tr(QStringLiteral("Resume")));
        } else {
            m_pauseAction->setText(LocaleManager::instance().tr(QStringLiteral("Pause")));
        }
        text = QStringLiteral("%1 %2 (%3)").arg(name, state,
            QStringLiteral("%1%").arg(percent));
        m_text->setText(text);
    } else {
        // 运行中（0x58722a："Time left: %1" 0xc8ab43 段）
        const QString left = map.value(QStringLiteral("transfer.leftTime")).toString();
        text = QStringLiteral("%1 (%2%)").arg(name, QString::number(percent));
        if (!left.isEmpty())
            text += QStringLiteral(" %1 %2")
                        .arg(LocaleManager::instance().tr(QStringLiteral("Time left")), left);
        m_pauseAction->setText(LocaleManager::instance().tr(QStringLiteral("Pause")));
        m_text->setText(text);
    }
    // tooltip=属性 map HTML 表（0x617aea propertiesToHtml）
    setToolTip(TransferCenter::propertiesToHtml(map));
}

void TransferLabel::openMenu()
{
    m_menu->popup(mapToGlobal(rect().bottomLeft()));
}
