#include "MenuConfig.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

#include "JsonText.h"

MenuConfig &MenuConfig::instance()
{
    static MenuConfig config;
    return config;
}

bool MenuConfig::load(const QString &path)
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

    m_menuNames.clear();
    m_menus.clear();
    for (const QJsonValue &value : kit) {
        const QString name = value.toObject().value(QStringLiteral("Menu")).toString();
        if (name.isEmpty())
            continue;
        m_menuNames.append(name);
        m_menus.insert(name, parseEntries(root.value(name).toArray()));
    }

    m_valid = !m_menuNames.isEmpty();
    return m_valid;
}

QVector<MenuEntry> MenuConfig::parseEntries(const QJsonArray &array)
{
    QVector<MenuEntry> entries;
    for (const QJsonValue &value : array) {
        const QJsonObject object = value.toObject();
        MenuEntry entry;
        if (object.contains(QStringLiteral("Menu"))) {
            entry.type = MenuEntry::Submenu;
            entry.title = object.value(QStringLiteral("Menu")).toString();
            entry.children = parseEntries(object.value(QStringLiteral("Actions")).toArray());
        } else if (object.contains(QStringLiteral("Separator"))) {
            entry.type = MenuEntry::Separator;
        } else if (object.contains(QStringLiteral("Action"))) {
            entry.type = MenuEntry::Action;
            entry.actionId = object.value(QStringLiteral("Action")).toString();
        } else {
            continue;
        }
        entries.append(entry);
    }
    return entries;
}
