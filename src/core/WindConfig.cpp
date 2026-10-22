#include "WindConfig.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonValue>

#include "JsonText.h"

WindConfig &WindConfig::instance()
{
    static WindConfig config;
    return config;
}

bool WindConfig::load(const QString &path)
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

    m_root = doc.object();
    return true;
}

QString WindConfig::valueToString(const QString &key, const QString &defaultValue) const
{
    const QJsonValue value = m_root.value(key);
    return value.isString() ? value.toString() : defaultValue;
}

double WindConfig::valueToDouble(const QString &key, double defaultValue) const
{
    const QJsonValue value = m_root.value(key);
    return value.isDouble() ? value.toDouble() : defaultValue;
}
