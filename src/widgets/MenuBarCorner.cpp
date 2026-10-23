#include "MenuBarCorner.h"

#include <QToolButton>

#include "core/ThemeManager.h"
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

MenuBarCorner::MenuBarCorner(QWidget *parent, bool terminal)
    : QToolBar(parent)
{
    setObjectName(QStringLiteral("MenuBarCorner"));
    setMovable(false);
    setFloatable(false);

    const QString theme = ThemeManager::instance().currentTheme();
    // 图标名来自 king.svg（KingIcons 渲染）；行为挂账，原版弹层未逆完
    addCornerButton(this, QStringLiteral("PaletteButton"),
                    KingIcons::icon(QStringLiteral("anythingPaletteSmall"), theme),
                    QStringLiteral("Palette"));
    // shortcut: 调色板弹出行为（0x008c9ee4 未逆完）, AnythingPalette 接线时补
    addCornerButton(this, QStringLiteral("FocusModeButton"),
                    KingIcons::icon(QStringLiteral("focusModeSmall"), theme),
                    QStringLiteral("Focus Mode"));
    // shortcut: 专注模式切换行为未逆完, 接线时补
    addCornerButton(this, QStringLiteral("ManageLayoutButton"),
                    KingIcons::icon(QStringLiteral("layoutSmall"), theme),
                    QStringLiteral("Manage Layout"));
    // shortcut: 布局管理弹出行为未逆完, 接线时补

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
}
