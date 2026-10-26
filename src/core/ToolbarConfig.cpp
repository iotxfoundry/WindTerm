#include "ToolbarConfig.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

#include "JsonText.h"

ToolbarConfig &ToolbarConfig::instance()
{
    static ToolbarConfig config;
    return config;
}

bool ToolbarConfig::load(const QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
        return false;

    QByteArray data = file.readAll();
    if (data.startsWith("\xEF\xBB\xBF"))
        data.remove(0, 3);

    const QJsonDocument doc = QJsonDocument::fromJson(JsonText::stripLineComments(data));
    if (!doc.isObject())
        return false;

    const QJsonObject root = doc.object();
    const QJsonArray kit = root.value(QStringLiteral("Kit")).toArray();

    m_toolbarName.clear();
    m_toolbars.clear();
    for (const QJsonValue &value : kit) {
        const QString name = value.toObject().value(QStringLiteral("ToolBar")).toString();
        if (!name.isEmpty()) {
            m_toolbarName = name;
            break;
        }
    }

    for (auto it = root.constBegin(); it != root.constEnd(); ++it) {
        if (it.key() == QStringLiteral("Kit") || !it.value().isArray())
            continue;
        m_toolbars.insert(it.key(), parseEntries(it.value().toArray()));
    }

    m_valid = !m_toolbarName.isEmpty();
    return m_valid;
}

QVector<ToolbarEntry> ToolbarConfig::parseEntries(const QJsonArray &array)
{
    QVector<ToolbarEntry> entries;
    for (const QJsonValue &value : array) {
        const QJsonObject object = value.toObject();
        ToolbarEntry entry;
        if (object.contains(QStringLiteral("Action"))) {
            entry.type = ToolbarEntry::Action;
            entry.actionId = object.value(QStringLiteral("Action")).toString();
        } else if (object.contains(QStringLiteral("AddressBar"))) {
            entry.type = ToolbarEntry::AddressBar;
        } else if (object.contains(QStringLiteral("Separator"))) {
            entry.type = ToolbarEntry::Separator;
        } else if (object.contains(QStringLiteral("FilterEdit"))) {
            entry.type = ToolbarEntry::FilterEdit;
        } else {
            continue;
        }
        // 仅 Action 条目带 Menu（toolbar.config Standard/FilerPane/… 各节）
        entry.menu = object.value(QStringLiteral("Menu")).toString();
        entries.append(entry);
    }
    return entries;
}
