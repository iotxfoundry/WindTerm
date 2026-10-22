#include "AppletBar.h"

#include <QFrame>
#include <QHBoxLayout>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>

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
    for (const QJsonValue &value : groups) {
        const QJsonObject group = value.toObject();

        auto *label = new QLabel(group.value(QStringLiteral("group")).toString(), content);
        contentLayout->addWidget(label);

        const QJsonArray groupActions = group.value(QStringLiteral("actions")).toArray();
        for (const QJsonValue &actionValue : groupActions) {
            auto *button = new QPushButton(actionValue.toString(), content);
            button->setFlat(true);
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
