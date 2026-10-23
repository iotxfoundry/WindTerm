#include "QuickBar.h"

#include <QAction>
#include <QHBoxLayout>
#include <QJsonArray>
#include <QJsonObject>
#include <QLabel>
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

    const QString theme = ThemeManager::instance().currentTheme();

    // 内层 [QuickButton, 各分组 ActionButton…, ConfigButton, CloseButton]
    m_buttons = new QHBoxLayout;
    m_buttons->setContentsMargins(0, 0, 0, 0);
    m_buttons->setSpacing(0);

    auto *quickButton = new QToolButton(this);
    quickButton->setObjectName(QStringLiteral("QuickButton"));
    quickButton->setText(LocaleManager::instance().tr(QStringLiteral("Quick Commands")));
    quickButton->setPopupMode(QToolButton::InstantPopup);
    m_quickMenu = new QMenu(quickButton);
    quickButton->setMenu(m_quickMenu);
    m_buttons->addWidget(quickButton);

    auto *configButton = new QToolButton(this);
    configButton->setObjectName(QStringLiteral("ConfigButton"));
    configButton->setAutoRaise(true);
    configButton->setIcon(ActionIcons::iconFor(QStringLiteral("ConfigButton"),
                                               QStringLiteral("king::config"), theme));
    m_buttons->addWidget(configButton);
    // shortcut: ConfigButton 配置对话框挂账, QuickBar 配置页未实现(0x0056e540)

    auto *closeButton = new QToolButton(this);
    closeButton->setObjectName(QStringLiteral("CloseButton"));
    closeButton->setAutoRaise(true);
    closeButton->setIcon(ActionIcons::iconFor(QStringLiteral("CloseButton"),
                                              QStringLiteral("king::close"), theme));
    m_buttons->addWidget(closeButton);
    connect(closeButton, &QToolButton::clicked, this, [this] {
        emit closeRequested();
        hide(); // 宿主接线前先隐藏本条（0x0056ce72）
    });

    // 0x0056d0ac：整条右对齐
    auto *layout = new QHBoxLayout(this);
    layout->setContentsMargins(4, 2, 4, 2);
    layout->setSpacing(0);
    layout->addStretch();
    layout->addLayout(m_buttons);

    rebuild();
}

void QuickBar::rebuild()
{
    const QString theme = ThemeManager::instance().currentTheme();

    for (QWidget *widget : m_commandWidgets) {
        m_buttons->removeWidget(widget);
        widget->deleteLater();
    }
    m_commandWidgets.clear();
    m_quickMenu->clear();

    QToolButton *configButton = findChild<QToolButton *>(QStringLiteral("ConfigButton"));
    int insertAt = configButton ? m_buttons->indexOf(configButton) : m_buttons->count();
    auto append = [this, &insertAt](QWidget *widget) {
        m_buttons->insertWidget(insertAt++, widget);
        m_commandWidgets.append(widget);
    };

    // 0x008065a2 / 0x0056be56：顶层数组，每命令 {quick.uuid/group/label/icon/text/type}
    const QJsonArray commands = WindConfig::instance().quickCommands();
    for (const QJsonValue &value : commands) {
        const QJsonObject command = value.toObject();
        const QString uuid = command.value(QStringLiteral("quick.uuid")).toString();
        const QString label = command.value(QStringLiteral("quick.label")).toString();
        QAction *action = m_quickMenu->addAction(label.isEmpty() ? uuid : label);
        connect(action, &QAction::triggered, this, [this, uuid] { emit commandTriggered(uuid); });
    }

    // shortcut: showCommandsInOrder=false 原版按使用频率排序，quickbar.config 无计数；暂两种模式均按
    // 配置顺序渲染，usage 统计接入后补 (0x0056e420)
    const bool showGroupTitle = WindConfig::instance().quickShowGroupTitle();
    const bool showMultipleGroups = WindConfig::instance().quickShowMultipleGroups();

    bool started = false;
    QString previousGroup;
    for (const QJsonValue &value : commands) {
        const QJsonObject command = value.toObject();
        const QString uuid = command.value(QStringLiteral("quick.uuid")).toString();
        const QString group = command.value(QStringLiteral("quick.group")).toString();
        const QString label = command.value(QStringLiteral("quick.label")).toString();
        const QString icon = command.value(QStringLiteral("quick.icon")).toString();
        const QString text = command.value(QStringLiteral("quick.text")).toString();

        if (started && group != previousGroup) {
            // shortcut: showMultipleGroups=false 语义简化——仅第一组，其余组整组丢弃，待实测原版
            // 0x0056e540 的组过滤条件后补
            if (!showMultipleGroups)
                break;
            if (showGroupTitle) {
                // shortcut: 主题无 QuickBar #GroupTitle 规则，先不加 objectName；补 QSS 后再挂
                append(new QLabel(group, this));
            }
        }
        started = true;
        previousGroup = group;

        auto *button = new QToolButton(this);
        button->setObjectName(QStringLiteral("ActionButton"));
        button->setAutoRaise(true);
        button->setText(label);
        button->setToolTip(text);
        if (!icon.isEmpty())
            button->setIcon(ActionIcons::iconFor(uuid, icon, theme));
        connect(button, &QToolButton::clicked, this, [this, uuid] { emit commandTriggered(uuid); });
        append(button);
    }
    // 命令为空时保持 [QuickButton, ConfigButton, CloseButton] 空态（原版安装包默认）
}
