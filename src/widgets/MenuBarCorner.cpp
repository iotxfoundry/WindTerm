#include "MenuBarCorner.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMenu>
#include <QToolButton>

#include "core/ActionRegistry.h"
#include "core/Assets.h"
#include "core/JsonText.h"
#include "core/ThemeManager.h"
#include "widgets/ActionIcons.h"
#include "widgets/KingIcons.h"

namespace {

QToolButton *addCornerButton(QToolBar *bar, const QString &objectName, const QIcon &icon,
                             const QString &toolTip)
{
    auto *button = new QToolButton(bar);
    button->setObjectName(objectName);
    button->setIcon(icon);
    button->setToolTip(toolTip);
    button->setAutoRaise(true);
    bar->addWidget(button);
    return button;
}

} // namespace

// 0x0085d99e：Tunnels/XServer insertWidget 到已有 action 之前 → 最终顺序
// Tunnels → XServer → Palette → FocusMode → ManageLayout
MenuBarCorner::MenuBarCorner(QWidget *parent, bool terminal)
    : QToolBar(parent)
{
    setObjectName(QStringLiteral("MenuBarCorner"));
    setMovable(false);
    setFloatable(false);

    const QString theme = ThemeManager::instance().currentTheme();
    if (terminal) {
        addCornerButton(this, QStringLiteral("TunnelsButton"),
                        KingIcons::icon(QStringLiteral("tunnelSmall"), theme),
                        QStringLiteral("Tunnels"));
        // shortcut: 隧道列表弹出行为未逆完, 接线时补
        addCornerButton(this, QStringLiteral("XServerButton"),
                        ActionIcons::iconFor(QStringLiteral("XServerButton"),
                                             QStringLiteral("king::xServerSmall"),
                                             ThemeManager::instance().currentTheme()),
                        QStringLiteral("X Server"));
        // king::xServerSmall：king.svg id="xServerSmall" 实存（0x85d99e TerminalWindow 版追加项）
    }

    // 图标名来自 king.svg（KingIcons 渲染）；行为挂账，原版弹层未逆完
    addCornerButton(this, QStringLiteral("PaletteButton"),
                    KingIcons::icon(QStringLiteral("anythingPaletteSmall"), theme),
                    QStringLiteral("Palette"));
    // shortcut: 调色板弹出行为（0x008c9ee4 未逆完）, AnythingPalette 接线时补
    auto *focus = addCornerButton(this, QStringLiteral("FocusModeButton"),
                                  KingIcons::icon(QStringLiteral("focusModeSmall"), theme),
                                  QStringLiteral("Focus Mode"));
    // 0x8cbc86：FocusModeButton checkable + TextBesideIcon
    focus->setCheckable(true);
    focus->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    // shortcut: 专注模式切换行为未逆完, 接线时补
    auto *manage = addCornerButton(this, QStringLiteral("ManageLayoutButton"),
                                   KingIcons::icon(QStringLiteral("layoutSmall"), theme),
                                   QStringLiteral("Manage Layout"));
    // 0x8cbc86：ManageLayoutButton InstantPopup + Layout 菜单（menu.config "Layout" 节，
    // 条目构建与 showPopupMenu 同款；动态项挂账）
    manage->setPopupMode(QToolButton::InstantPopup);
    auto *menu = new QMenu(manage);
    const QString key = QStringLiteral("Layout");
    QFile file(Assets::dir() + QStringLiteral("/config/uiconfigs/menu.config"));
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        if (data.startsWith("\xEF\xBB\xBF"))
            data.remove(0, 3);
        const QJsonDocument doc = QJsonDocument::fromJson(JsonText::stripLineComments(data));
        if (doc.isObject()) {
            const QJsonArray array = doc.object().value(key).toArray();
            for (const QJsonValue &value : array) {
                const QJsonObject object = value.toObject();
                if (object.contains(QStringLiteral("Separator"))) {
                    menu->addSeparator();
                    continue;
                }
                const QString actionId = object.value(QStringLiteral("Action")).toString();
                if (actionId.isEmpty())
                    continue;
                // 条目动作与主菜单同源 ActionRegistry（text/icon/shortcut 管线同 showPopupMenu）
                QString text = ActionRegistry::instance().actionText(actionId);
                if (text.isEmpty())
                    text = actionId.section(QLatin1Char('.'), -1);
                QAction *action = menu->addAction(text);
                const QIcon ic = ActionIcons::iconFor(actionId,
                                                      ActionRegistry::instance().actionIcon(actionId),
                                                      ThemeManager::instance().currentTheme());
                if (!ic.isNull())
                    action->setIcon(ic);
            }
        }
    }
    // shortcut: Layout 菜单动作触发行为挂账（与 showPopupMenu 同限制, 占位无接线）
    manage->setMenu(menu);
}
