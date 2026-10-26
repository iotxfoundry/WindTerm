#include "QuickBar.h"

#include <QAction>
#include <algorithm>
#include <set>
#include <QContextMenuEvent>
#include <QHBoxLayout>
#include <QFontMetrics>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLabel>
#include <QMenu>
#include <QStyle>
#include <QToolBar>
#include <QToolButton>
#include <QWidgetAction>

#include "ActionIcons.h"

#include "core/LocaleManager.h"
#include "core/ThemeManager.h"
#include "core/WindConfig.h"

namespace {

// 0x007b8726 qstring_unescape：C 风格转义还原（\0 \\ \a \b \cX \f \m \n \r \t \xHH \uXXXX \v；
// 未知转义=字面字符）。\cX=Ctrl(X)=toUpper(X)-0x40；\mX=Meta(X)=X|0x80；\u/\x 按 hex toUShort。
QString unescape(const QString &text)
{
    QString out = text;
    for (int i = 0; i + 1 < out.size();) {
        if (out.at(i) != QLatin1Char('\\')) {
            ++i;
            continue;
        }
        const QChar c = out.at(i + 1);
        int width = 2;   // 替换长度（含反斜杠）
        ushort value = c.unicode(); // default/未知：还原字面字符
        switch (c.unicode()) {
        case '0': value = 0; break;
        case '\\': value = '\\'; break;
        case 'a': value = 7; break;
        case 'b': value = 8; break;
        case 'f': value = 12; break;
        case 'n': value = 10; break;
        case 'r': value = 13; break;
        case 't': value = 9; break;
        case 'v': value = 11; break;
        case 'c': { // \cX = Ctrl-X
            if (i + 2 >= out.size()) { i += 2; continue; }
            const ushort x = out.at(i + 2).toUpper().unicode();
            value = x - 0x40;
            width = 3;
            if (value > 0x1f) { i += width; continue; } // 原版超界跳过
            break;
        }
        case 'm': { // \mX = Meta-X
            if (i + 2 >= out.size()) { i += 2; continue; }
            const ushort x = out.at(i + 2).unicode();
            value = x | 0x80;
            width = 3;
            if (x > 0x7f) { i += width; continue; }
            break;
        }
        case 'u': { // \uXXXX
            if (i + 6 > out.size()) { i += 2; continue; }
            bool ok = false;
            value = out.mid(i + 2, 4).toUShort(&ok, 16);
            if (!ok) { i += 2; continue; }
            width = 6;
            break;
        }
        case 'x': { // \xHH
            if (i + 4 > out.size()) { i += 2; continue; }
            bool ok = false;
            value = out.mid(i + 2, 2).toUShort(&ok, 16);
            if (!ok) { i += 2; continue; }
            width = 4;
            break;
        }
        default:
            break;
        }
        out.replace(i, width, QChar(value));
    }
    return out;
}

} // namespace

QuickBar::QuickBar(QWidget *parent)
    : QWidget(parent)
{
    setObjectName(QStringLiteral("QuickBar"));
    // 注册名 "&Quick Bar"；locale 查表键不含 & 助记符（AGENTS.md #14），缺键回退英文
    setWindowTitle(LocaleManager::instance().tr(QStringLiteral("Quick Bar")));
    // 0x0056e26e: setAttribute(0x5d,1)=WA_StyledBackground，gui.theme 的 QuickBar 规则背景方可生效
    setAttribute(Qt::WA_StyledBackground, true);

    const QString theme = ThemeManager::instance().currentTheme();

    // 0x0056d0ac 装配序：CloseButton(king::close)/ConfigButton(king::config)/QuickButton
    // (king::monoLogo, InstantPopup+QMenu tooltipsVisible) 三按钮 + 0x68 内层横布局；
    // 总布局=外层[stretch, 0x68, ConfigButton, CloseButton]，margins 原版显式清零
    auto *closeButton = new QToolButton(this);
    closeButton->setObjectName(QStringLiteral("CloseButton"));
    closeButton->setAutoRaise(true);
    closeButton->setFocusPolicy(Qt::NoFocus); // 0x0056d0ac setFocusPolicy(0)
    closeButton->setIcon(ActionIcons::iconFor(QStringLiteral("CloseButton"),
                                              QStringLiteral("king::close"), theme));
    connect(closeButton, &QToolButton::clicked, this, [this] {
        emit closeRequested();
        hide(); // 宿主接线前先隐藏本条（0x0056ce72 → QWidget::close）
    });

    auto *configButton = new QToolButton(this);
    configButton->setObjectName(QStringLiteral("ConfigButton"));
    configButton->setAutoRaise(true);
    configButton->setIcon(ActionIcons::iconFor(QStringLiteral("ConfigButton"),
                                               QStringLiteral("king::config"), theme));
    // shortcut: ConfigButton 打开快捷命令编辑对话框挂账（0x0056efde 建命令对话框），对话框未逆明
    connect(configButton, &QToolButton::clicked, this, [] { Q_UNIMPLEMENTED(); });

    auto *quickButton = new QToolButton(this);
    quickButton->setObjectName(QStringLiteral("QuickButton"));
    quickButton->setAutoRaise(true);
    quickButton->setIcon(ActionIcons::iconFor(QStringLiteral("QuickButton"),
                                              QStringLiteral("king::monoLogo"), theme));
    m_quickMenu = new QMenu(quickButton);
    m_quickMenu->setToolTipsVisible(true); // 0x0056d0ac setToolTipsVisible(1)
    quickButton->setMenu(m_quickMenu);
    quickButton->setPopupMode(QToolButton::InstantPopup);

    m_buttons = new QHBoxLayout;
    m_buttons->setContentsMargins(0, 0, 0, 0);
    m_buttons->setSpacing(0);
    m_buttons->addWidget(quickButton); // 组工具条由 rebuild() insertWidget 到 QuickButton 之后

    auto *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addStretch(); // 0x0056d0ac：stretch 在前=整条右对齐
    layout->addLayout(m_buttons);
    layout->addWidget(configButton);
    layout->addWidget(closeButton);

    rebuild();
}

QList<QJsonObject> QuickBar::loadCommands() const
{
    // 0x008065a2：顶层命令数组，每条 {quick.uuid/group/label/icon/text/type}；缺失=空数组
    QList<QJsonObject> commands;
    const QJsonArray array = WindConfig::instance().quickCommands();
    for (const QJsonValue &value : array) {
        const QJsonObject command = value.toObject();
        // 0x0056be56：uuid 空直接跳过
        if (!command.value(QStringLiteral("quick.uuid")).toString().isEmpty())
            commands.append(command);
    }
    return commands;
}

// 0x0056e420：仅 showCommandsInOrder=true 时按 quick.label 升序排序（区分大小写）；false 原样。
// 无 usage 计数（quickbar.config 无该字段）
void QuickBar::sortCommands(QList<QJsonObject> &commands) const
{
    if (!WindConfig::instance().quickShowCommandsInOrder())
        return;
    std::sort(commands.begin(), commands.end(),
              [](const QJsonObject &a, const QJsonObject &b) {
                  return a.value(QStringLiteral("quick.label")).toString()
                       < b.value(QStringLiteral("quick.label")).toString();
              });
}

// 0x0056be56：单命令 QAction。param_4=2 工具条模式（label>18 按空格宽×36 ElideMiddle 截断）；
// =3 菜单模式（不截断）。icon=quick.icon 走 king.svg 工厂（空 icon→QAction 无图标=纯文字）；
// tooltip=HTML <table> 4 行（Label/Group/Type/Text，0xd0e72f/0xcb9f5f/0xc9e5fe/0xc9fb6a）；
// uuid 存 QAction::data；triggered→0x0056d890 execCommand。
QAction *QuickBar::createCommandAction(const QJsonObject &command, int elideMode) const
{
    const QString uuid = command.value(QStringLiteral("quick.uuid")).toString();
    if (uuid.isEmpty())
        return nullptr;
    const QString group = command.value(QStringLiteral("quick.group")).toString();
    QString label = command.value(QStringLiteral("quick.label")).toString();
    const QString icon = command.value(QStringLiteral("quick.icon")).toString();
    const QString text = command.value(QStringLiteral("quick.text")).toString();
    const QString type = command.value(QStringLiteral("quick.type")).toString();

    auto *self = ActionIcons::host(this);

    if (elideMode != 3 && label.size() > 18)
        label = self->fontMetrics().elidedText(
            label, Qt::ElideMiddle,
            self->fontMetrics().horizontalAdvance(QLatin1Char(' ')) * 36);

    auto *action = new QAction(self);
    action->setText(label);
    const QIcon ic = ActionIcons::iconFor(uuid, icon, ThemeManager::instance().currentTheme());
    if (!ic.isNull())
        action->setIcon(ic);
    action->setToolTip(tr("<table style='white-space:pre'>"
                          "<tr><td align=right>%1:</td><td><b>%2</b></td></tr>"
                          "<tr><td align=right>%3:</td><td><b>%4</b></td></tr>"
                          "<tr><td align=right>%5:</td><td><b>%6</b></td></tr>"
                          "<tr><td align=right>%7:</td><td><b>%8</b></td></tr>"
                          "</table>")
                           .arg(tr("Label"), label,
                                tr("Group"), group,
                                tr("Type"), type,
                                tr("Text"), text));
    action->setData(uuid);
    // 0x0056d890：按 uuid 线性扫描配置 → type 仅 =="Send Text"（0x006d09f6，其余静默返回）
    // → text 空返回 → unescape → 焦点终端写入。原版写入焦点终端（0x8cabee 链），骨架经
    // sendTextRequested 由 MainWindow 接 TerminalView::sendText（仅宿主层差异，0x833db4 挂账）
    connect(action, &QAction::triggered, this, [this, self, uuid] {
        for (const QJsonObject &command : loadCommands()) {
            if (command.value(QStringLiteral("quick.uuid")).toString() != uuid)
                continue;
            if (command.value(QStringLiteral("quick.type")).toString()
                != QStringLiteral("Send Text"))
                return;
            const QString text = command.value(QStringLiteral("quick.text")).toString();
            if (text.isEmpty())
                return;
            emit static_cast<QuickBar *>(self)->sendTextRequested(unescape(text));
            return;
        }
    });
    return action;
}

// 0x0056e540 buildGroupBar：new QToolBar(groupName, this)——windowTitle=组名、无 objectName、
// layout margins 0、iconSize=style PM_ToolBarIconSize、TextBesideIcon；showGroupTitle=true 时
// 首件=QLabel(组名原文) 无 objectName；按 group 全局聚合（配置数组序线性收集，非相邻归并）；
// 每条经 sortCommands 后逐条建 QAction→addAction→widgetForAction 强转 QToolButton→
// setObjectName("ActionButton")；label 空→IconOnly；AutoRaise；CustomContextMenu→右键菜单。
QToolBar *QuickBar::buildGroupBar(const QString &groupName) const
{
    auto *toolBar = new QToolBar(groupName, const_cast<QuickBar *>(this));
    toolBar->layout()->setContentsMargins(0, 0, 0, 0);
    const int iconPx = style()->pixelMetric(QStyle::PM_ToolBarIconSize);
    toolBar->setIconSize(QSize(iconPx, iconPx));
    toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    if (WindConfig::instance().quickShowGroupTitle()) {
        auto *title = new QLabel(groupName, toolBar);
        toolBar->addWidget(title);
    }

    QList<QJsonObject> commands;
    for (const QJsonObject &command : loadCommands()) {
        if (command.value(QStringLiteral("quick.group")).toString() == groupName)
            commands.append(command);
    }
    sortCommands(commands);
    for (const QJsonObject &command : commands) {
        QAction *action = createCommandAction(command, 2);
        if (!action)
            continue;
        toolBar->addAction(action);
        if (auto *button = qobject_cast<QToolButton *>(toolBar->widgetForAction(action))) {
            button->setObjectName(QStringLiteral("ActionButton"));
            if (action->text().isEmpty())
                button->setToolButtonStyle(Qt::ToolButtonIconOnly);
            button->setAutoRaise(true);
            button->setContextMenuPolicy(Qt::CustomContextMenu);
            connect(button, &QWidget::customContextMenuRequested, this,
                    [this, button](const QPoint &pos) {
                // 0x0056a10a：右键两项[编辑命令(Q_UNIMPLEMENTED), 删除(king::close 图标)]
                QMenu menu(const_cast<QuickBar *>(this));
                QAction *edit = menu.addAction(tr("Modify"));
                QAction *remove = menu.addAction(
                    ActionIcons::iconFor(QStringLiteral("ActionButton"),
                                         QStringLiteral("king::close"),
                                         ThemeManager::instance().currentTheme()),
                    tr("Remove"));
                QAction *chosen = menu.exec(button->mapToGlobal(pos));
                if (chosen == edit) {
                    Q_UNIMPLEMENTED(); // 编辑命令=0x0056efde 命令对话框，挂账
                    return;
                }
                if (chosen != remove)
                    return;
                // 删除=0x00570970：按 uuid 从配置删 + 整份回写 quickbar.config（0x00806700
                // QuickBar_configSave）+ refresh。保存回写本批挂账——先只从内存删+refresh
                Q_UNIMPLEMENTED(); // 挂账：quickbar.config 回写（0x00806700）+ WindConfig 内存删除后接
            });
        }
    }
    return toolBar;
}

// 0x0056f866 QuickBar_refresh：
// 1. showMultipleGroups=false → 可见组列表恒 ≤1：已有组则整表替换为首组（不是"只留首组丢弃
//    其余渲染"——是后续点击 toggleGroup 时"清空再 append（替换）"的数据前提）；
// 2. 菜单重建（clear 后自上而下）：配置动作(king::config, tr("Config")) → Quick 组平铺（若存在，
//    大小写不敏感，前置 QWidgetAction 包 QLabel 标题 tr("Quick")）→ 组集合 QLabel 标题(tr("Groups"))
//    + 每组一个可勾选 QAction(setData("group"), triggered→toggleGroup) → 0x0056f262 同步 checked；
// 3. 工具条重建：qFindChildren<QToolBar*> 逐个 layout()->removeWidget + deleteLater，
//    再按可见组顺序逐组 buildGroupBar，insertWidget(idx) 到 0x68 内层布局。
void QuickBar::rebuild()
{
    // 初始可见组列表 = 配置顺序去重；showMultipleGroups=false 截断 list[0]（0x0056f866）
    QStringList visibleGroups;
    for (const QJsonObject &command : loadCommands()) {
        const QString group = command.value(QStringLiteral("quick.group")).toString();
        if (!visibleGroups.contains(group))
            visibleGroups.append(group);
    }
    if (!WindConfig::instance().quickShowMultipleGroups() && visibleGroups.size() > 1)
        visibleGroups = QStringList{visibleGroups.first()};
    m_visibleGroups = visibleGroups;

    // —— 菜单重建 ——
    m_quickMenu->clear();
    const QString theme = ThemeManager::instance().currentTheme();

    QAction *configAction = m_quickMenu->addAction(
        ActionIcons::iconFor(QStringLiteral("ConfigButton"), QStringLiteral("king::config"), theme),
        tr("Config"));
    // shortcut: 打开快捷命令配置对话框挂账（同 ConfigButton，0x0056efde）
    connect(configAction, &QAction::triggered, this, [] { Q_UNIMPLEMENTED(); });

    const QList<QJsonObject> commands = loadCommands();
    bool hasQuickGroup = false;
    for (const QJsonObject &command : commands) {
        if (command.value(QStringLiteral("quick.group")).toString().compare(
                QStringLiteral("Quick"), Qt::CaseInsensitive) == 0) {
            hasQuickGroup = true;
            break;
        }
    }
    if (hasQuickGroup) {
        auto *titleAction = new QWidgetAction(m_quickMenu);
        auto *titleLabel = new QLabel(tr("Quick"), m_quickMenu);
        titleLabel->setAlignment(Qt::AlignCenter); // 0x0056f866 setAlignment(1)
        titleAction->setDefaultWidget(titleLabel);
        m_quickMenu->addAction(titleAction);
        QList<QJsonObject> quickCommands;
        for (const QJsonObject &command : commands) {
            if (command.value(QStringLiteral("quick.group")).toString().compare(
                    QStringLiteral("Quick"), Qt::CaseInsensitive) == 0)
                quickCommands.append(command);
        }
        sortCommands(quickCommands);
        for (const QJsonObject &command : quickCommands) {
            if (QAction *action = createCommandAction(command, 3))
                m_quickMenu->addAction(action);
        }
    }

    // 组集合（std::set 字典序）：QLabel 标题 + 每组一个可勾选 QAction
    std::set<QString> groupSet(visibleGroups.cbegin(), visibleGroups.cend());
    if (!groupSet.empty()) {
        auto *groupsTitle = new QWidgetAction(m_quickMenu);
        auto *groupsLabel = new QLabel(tr("Groups"), m_quickMenu);
        groupsLabel->setAlignment(Qt::AlignCenter);
        groupsTitle->setDefaultWidget(groupsLabel);
        m_quickMenu->addAction(groupsTitle);
        for (const QString &group : groupSet) {
            QAction *action = m_quickMenu->addAction(group);
            action->setData(QStringLiteral("group"));
            connect(action, &QAction::triggered, this, [this, action] {
                // 0x0056f476/0x0056f5c5 toggleGroup：不包含则 append（单组模式先清空=替换），
                // 已包含则 removeOne；随后 0x0056f262 同步 checked + 工具条重建（refresh 后半段）
                const QString group = action->text();
                if (!m_visibleGroups.contains(group)) {
                    if (!WindConfig::instance().quickShowMultipleGroups())
                        m_visibleGroups.clear(); // 单组模式：替换
                    m_visibleGroups.append(group);
                } else {
                    m_visibleGroups.removeOne(group);
                }
                for (QAction *groupAction : m_quickMenu->actions()) {
                    if (groupAction->data().toString() == QLatin1String("group"))
                        groupAction->setChecked(m_visibleGroups.contains(groupAction->text()));
                }
                rebuildToolBars();
            });
        }
        // 0x0056f262：菜单组动作 checked = 组名 ∈ 可见组列表
        for (QAction *action : m_quickMenu->actions()) {
            if (action->data().toString() != QLatin1String("group"))
                continue;
            action->setCheckable(true);
            action->setChecked(m_visibleGroups.contains(action->text()));
        }
    }

    rebuildToolBars();
}

// 0x0056f866 后半段：qFindChildren<QToolBar*> 逐个 layout()->removeWidget + deleteLater，
// 再按可见组顺序逐组 buildGroupBar，insertWidget 到 0x68 内层布局 QuickButton 之后
void QuickBar::rebuildToolBars()
{
    for (QToolBar *toolBar : findChildren<QToolBar *>()) {
        m_buttons->removeWidget(toolBar);
        toolBar->deleteLater();
    }
    int index = 0;
    for (const QString &group : m_visibleGroups) {
        if (QToolBar *toolBar = buildGroupBar(group))
            m_buttons->insertWidget(index++, toolBar);
    }
}
