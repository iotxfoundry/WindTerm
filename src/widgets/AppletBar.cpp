#include "AppletBar.h"

#include <QFile>
#include <QFrame>
#include <QHBoxLayout>
#include <QIcon>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>

#include "core/ThemeManager.h"

namespace {

QJsonArray defaultActions()
{
    const QByteArray json = R"([
        {"group": "File", "actions": ["Copy", "Move", "Remove"]},
        {"group": "Network", "actions": ["ping", "traceroute"]},
        {"group": "Shell", "actions": ["ls", "cat", "vi"]},
        {"group": "System", "actions": ["reboot"]}
    ])";
    return QJsonDocument::fromJson(json).array();
}

} // namespace

AppletBar::AppletBar(const QJsonArray &actions, QWidget *parent)
    : QWidget(parent)
{
    auto *content = new QWidget;
    auto *contentLayout = new QHBoxLayout(content);
    contentLayout->setContentsMargins(4, 2, 4, 2);
    contentLayout->setSpacing(6);

    const QJsonArray groups = actions.isEmpty() ? defaultActions() : actions;
    const QStringList iconDirs{
        QStringLiteral("assets/themes/%1/images").arg(ThemeManager::instance().currentTheme()),
        QStringLiteral("assets/themes/default/images")
    };

    for (const QJsonValue &value : groups) {
        const QJsonObject group = value.toObject();

        auto *label = new QLabel(group.value(QStringLiteral("group")).toString(), content);
        contentLayout->addWidget(label);

        const QJsonArray groupActions = group.value(QStringLiteral("actions")).toArray();
        for (const QJsonValue &actionValue : groupActions) {
            const QString name = actionValue.toString();

            QIcon icon;
            const QString fileName = name.toLower() + QStringLiteral(".svg");
            for (const QString &dir : iconDirs) {
                const QString path = dir + QLatin1Char('/') + fileName;
                if (QFile::exists(path)) {
                    icon = QIcon(path);
                    break;
                }
            }
            if (icon.isNull())
                icon = style()->standardIcon(standardIconFor(name));

            auto *button = new QPushButton(icon, name, content);
            button->setFlat(true);
            button->setIconSize(QSize(16, 16));
            connect(button, &QPushButton::pressed, this, &AppletBar::onActionPressed);
            contentLayout->addWidget(button);
        }
    }
    contentLayout->addStretch();

    auto *scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(content);
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(scrollArea);
}

void AppletBar::onActionPressed()
{
    Q_UNIMPLEMENTED();
}

QStyle::StandardPixmap AppletBar::standardIconFor(const QString &actionIdOrName)
{
    const QString name = actionIdOrName.toLower();

    if (name.contains(QStringLiteral("remove")) || name.contains(QStringLiteral("delete"))
        || name.contains(QStringLiteral("close")) || name.contains(QStringLiteral("trash")))
        return QStyle::SP_TrashIcon;
    if (name.contains(QStringLiteral("add")) || name.contains(QStringLiteral("new"))
        || name.contains(QStringLiteral("create")))
        return QStyle::SP_FileIcon;
    if (name.contains(QStringLiteral("search")) || name.contains(QStringLiteral("find")))
        return QStyle::SP_FileDialogContentsView;
    if (name.contains(QStringLiteral("ping")) || name.contains(QStringLiteral("network"))
        || name.contains(QStringLiteral("traceroute")))
        return QStyle::SP_ComputerIcon;
    if (name.contains(QStringLiteral("reboot")) || name.contains(QStringLiteral("restart"))
        || name.contains(QStringLiteral("system")))
        return QStyle::SP_BrowserReload;
    if (name.contains(QStringLiteral("copy")))
        return QStyle::SP_DialogApplyButton;
    if (name.contains(QStringLiteral("move")))
        return QStyle::SP_ArrowRight;
    if (name.contains(QStringLiteral("open")))
        return QStyle::SP_DialogOpenButton;
    if (name.contains(QStringLiteral("save")))
        return QStyle::SP_DialogSaveButton;
    if (name.contains(QStringLiteral("folder")) || name.contains(QStringLiteral("dir")))
        return QStyle::SP_DirIcon;
    if (name.contains(QStringLiteral("help")))
        return QStyle::SP_DialogHelpButton;
    if (name.contains(QStringLiteral("about")) || name.contains(QStringLiteral("info")))
        return QStyle::SP_MessageBoxInformation;
    if (name.contains(QStringLiteral("refresh")) || name.contains(QStringLiteral("reload")))
        return QStyle::SP_BrowserReload;
    if (name.contains(QStringLiteral("back")))
        return QStyle::SP_ArrowBack;
    if (name.contains(QStringLiteral("forward")))
        return QStyle::SP_ArrowForward;
    if (name.contains(QStringLiteral("up")))
        return QStyle::SP_ArrowUp;
    if (name.contains(QStringLiteral("down")))
        return QStyle::SP_ArrowDown;
    if (name.contains(QStringLiteral("settings")) || name.contains(QStringLiteral("config")))
        return QStyle::SP_FileDialogDetailedView;

    return QStyle::SP_FileIcon;
}
