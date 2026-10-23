#include "StatusBar.h"

#include <QLabel>
#include <QTimer>
#include <QToolButton>

#include "core/LocaleManager.h"
#include "core/ScriptHost.h"

namespace {

// 0x005a2e32/0x005a2e58：默认状态文本（0x5a2e58 空文本→tr("Ready")，rodata 0xc8b211 "Ready"）
QString defaultStatusText()
{
    return LocaleManager::instance().tr(QStringLiteral("Ready"));
}

} // namespace

// 0x005a2d26 StatusBar_ctor：objectName "StatusBar"（注册名 AppletBar 经 R17 改写命中
// gui.theme AppletBar 规则）+ setSizeGripEnabled(false) + setContentsMargins(font pt,0,font pt,0)
StatusBar::StatusBar(QWidget *parent)
    : QStatusBar(parent)
{
    setObjectName(QStringLiteral("StatusBar"));
    setSizeGripEnabled(false);
    setContentsMargins(qRound(font().pointSizeF()), 0, qRound(font().pointSizeF()), 0);

    // 0x005a2e58：常驻状态文本 label insertPermanentWidget(0, stretch=1) 最左
    m_statusLabel = new QLabel(this);
    insertPermanentWidget(0, m_statusLabel, 1);
    m_defaultStatusText = defaultStatusText();
    m_statusLabel->setText(m_defaultStatusText);
}

// 0x005a2e58 statusbar_showMessage：设文本 + timeout QTimer（<1 清 timer），超时恢复默认文本。
// messageLevel 动态属性+king_refreshWidgetStyle 挂账（颜色刷新链未逆明）
void StatusBar::showMessageEx(const QString &text, int timeoutMs)
{
    if (timeoutMs < 1) {
        if (m_messageTimer) {
            m_messageTimer->stop();
            m_messageTimer->deleteLater();
            m_messageTimer = nullptr;
        }
    } else {
        if (!m_messageTimer) {
            m_messageTimer = new QTimer(this);
            connect(m_messageTimer, &QTimer::timeout, this, [this] {
                m_statusLabel->setText(m_defaultStatusText);
            });
        }
        m_messageTimer->start(timeoutMs);
    }
    const QString shown = text.isEmpty() ? m_defaultStatusText : text;
    if (m_statusLabel->text() != shown)
        m_statusLabel->setText(shown);
}

// 0x005a4432 applet_layout_widgets / 0x005a333e statusbar_buildApplet
void StatusBar::populate(const QVariantList &applets, ScriptHost *host)
{
    setUpdatesEnabled(false); // 0x005a4432 首行 setUpdatesEnabled(0)
    for (const QVariant &entry : applets) {
        const QVariantMap map = entry.toMap();
        const QString type = map.value(QStringLiteral("type")).toString();

        QWidget *widget = nullptr;
        if (type == QLatin1String("button")) {
            // 自定义 QToolButton 子类（vtable 0x5d4e80）骨架用裸 QToolButton 等价：
            // TextOnly+AutoRaise；无 objectName（原版恒空）
            auto *button = new QToolButton(this);
            button->setToolButtonStyle(Qt::ToolButtonTextOnly);
            button->setAutoRaise(true);
            widget = button;
        } else if (type == QLatin1String("label")) {
            // QLabel：InteractionFlags 0xf(TextSelectableByMouse|LinksAccessibleByMouse|
            // LinksAccessibleByKeyboard)+OpenExternalLinks+PointingHandCursor；无 objectName
            auto *label = new QLabel(this);
            label->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::LinksAccessibleByMouse
                                           | Qt::LinksAccessibleByKeyboard);
            label->setOpenExternalLinks(true);
            label->setCursor(Qt::PointingHandCursor);
            widget = label;
        }
        // progressBar/slider：原版仅类型比较无实现（0x005a333e），骨架同——跳过
        else {
            continue;
        }

        addPermanentWidget(widget, 0); // 0x005a333e addPermanentWidget(w,0)
        // 0x005a3156 runInit：init 源串（map["init"]）真跑 QJSEngine
        if (host)
            host->runInit(widget, map.value(QStringLiteral("init")).toString());
    }
    setUpdatesEnabled(true); // 0x005a4432 尾行 setUpdatesEnabled(1)
}
