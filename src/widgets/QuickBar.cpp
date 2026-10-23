#include "QuickBar.h"

#include <QHBoxLayout>
#include <QMenu>
#include <QToolButton>

#include "ActionIcons.h"

#include "core/LocaleManager.h"
#include "core/ThemeManager.h"
#include "core/WindConfig.h"

QuickBar::QuickBar(QWidget *parent)
    : QWidget(parent)
{
    setObjectName(QStringLiteral("QuickBar"));
    // 注册名 "&Quick Bar"；locale 查表键不含 & 助记符（AGENTS.md #14），缺键回退英文
    setWindowTitle(LocaleManager::instance().tr(QStringLiteral("Quick Bar")));
    // 0x0056e26e: setAttribute(0x5d,1)=WA_StyledBackground，gui.theme 的 QuickBar 规则背景方可生效
    setAttribute(Qt::WA_StyledBackground, true);

    // quick 命令数据源：原版 CTerminalConfig+0xd8 的 quick.group/uuid/type/text。
    // 已查 wind.config 与 ~/.wind/profiles/*/user.config：只有三个显示开关，无 quick 命令表 → 空态，
    // 仅建 [QuickButton, ConfigButton, CloseButton]，不造假命令。
    // 数据源确证（2026-10-23 strace+反汇编）：~/.wind/profiles/<profile>/terminal/quickbar.config，
    // JSON 顶层数组、每命令 {quick.uuid/group/label/icon/text/type}；安装包不预置（原版默认空数组），
    // 本空态即原版默认。加载 0x8064d2/懒加载 0x8065a2/保存 0x806700——命令渲染接入时实现读写。
    // 三个开关（wind.config:30-32 实际值 false/true/true），命令数据源定位后用于排序/分组显示
    const bool showCommandsInOrder =
        WindConfig::instance().valueToString(QStringLiteral("quickbar.showCommandsInOrder"),
                                             QStringLiteral("false")) == QLatin1String("true");
    const bool showGroupTitle =
        WindConfig::instance().valueToString(QStringLiteral("quickbar.showGroupTitle"),
                                             QStringLiteral("true")) == QLatin1String("true");
    const bool showMultipleGroups =
        WindConfig::instance().valueToString(QStringLiteral("quickbar.showMultipleGroups"),
                                             QStringLiteral("true")) == QLatin1String("true");
    Q_UNUSED(showCommandsInOrder)
    Q_UNUSED(showGroupTitle)
    Q_UNUSED(showMultipleGroups)

    const QString theme = ThemeManager::instance().currentTheme();

    // 内层 [QuickButton, 各分组 ActionButton…, ConfigButton, CloseButton]
    auto *buttons = new QHBoxLayout;
    buttons->setContentsMargins(0, 0, 0, 0);
    buttons->setSpacing(0);

    auto *quickButton = new QToolButton(this);
    quickButton->setObjectName(QStringLiteral("QuickButton"));
    quickButton->setText(LocaleManager::instance().tr(QStringLiteral("Quick Commands")));
    quickButton->setPopupMode(QToolButton::InstantPopup);
    // 空菜单：命令数据源定位后填（0x0056e420）
    quickButton->setMenu(new QMenu(quickButton));
    buttons->addWidget(quickButton);

    auto *configButton = new QToolButton(this);
    configButton->setObjectName(QStringLiteral("ConfigButton"));
    configButton->setAutoRaise(true);
    configButton->setIcon(ActionIcons::iconFor(QStringLiteral("ConfigButton"),
                                               QStringLiteral("king::config"), theme));
    buttons->addWidget(configButton);
    // shortcut: ConfigButton 配置对话框挂账, QuickBar 配置页未实现(0x0056e540)

    auto *closeButton = new QToolButton(this);
    closeButton->setObjectName(QStringLiteral("CloseButton"));
    closeButton->setAutoRaise(true);
    closeButton->setIcon(ActionIcons::iconFor(QStringLiteral("CloseButton"),
                                              QStringLiteral("king::close"), theme));
    buttons->addWidget(closeButton);
    connect(closeButton, &QToolButton::clicked, this, [this] {
        emit closeRequested();
        hide(); // 宿主接线前先隐藏本条（0x0056ce72）
    });

    // 0x0056d0ac：整条右对齐
    auto *layout = new QHBoxLayout(this);
    layout->setContentsMargins(4, 2, 4, 2);
    layout->setSpacing(0);
    layout->addStretch();
    layout->addLayout(buttons);
}
