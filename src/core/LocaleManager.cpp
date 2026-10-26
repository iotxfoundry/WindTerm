#include "LocaleManager.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

LocaleManager &LocaleManager::instance()
{
    static LocaleManager manager;
    return manager;
}

bool LocaleManager::load(const QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
        return false;

    const QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    if (!doc.isObject())
        return false;

    m_translations.clear();
    const QJsonArray entries = doc.object().value(QStringLiteral("translations")).toArray();
    for (const QJsonValue &value : entries) {
        const QJsonObject entry = value.toObject();
        const QString en = entry.value(QStringLiteral("en")).toString();
        if (!en.isEmpty())
            m_translations.insert(en, entry.value(QStringLiteral("tr")).toString());
    }
    return true;
}

QString LocaleManager::tr(const QString &en) const
{
    return m_translations.value(en, en);
}
