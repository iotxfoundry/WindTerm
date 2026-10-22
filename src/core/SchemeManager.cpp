#include "SchemeManager.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include "Assets.h"
#include "JsonText.h"
#include "ThemeManager.h"

SchemeManager &SchemeManager::instance()
{
    static SchemeManager manager;
    return manager;
}

bool SchemeManager::load(const QString &path)
{
    QString filePath = path;
    if (filePath.isEmpty()) {
        const QString theme = ThemeManager::instance().currentTheme();
        if (theme.isEmpty())
            return false;
        filePath = Assets::dir() + QStringLiteral("/themes/%1/scheme.theme").arg(theme);
    }

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
        return false;

    QByteArray data = file.readAll();
    if (data.startsWith("\xEF\xBB\xBF"))
        data.remove(0, 3);

    const QJsonDocument doc = QJsonDocument::fromJson(JsonText::stripLineComments(data));
    if (!doc.isObject())
        return false;

    m_colors.clear();
    const QJsonArray styles = doc.object().value(QStringLiteral("styles")).toArray();
    for (const QJsonValue &value : styles) {
        const QJsonObject style = value.toObject();
        const QString name = style.value(QStringLiteral("name")).toString();
        if (name.isEmpty())
            continue;

        const QJsonObject colors = style.value(QStringLiteral("style")).toObject();
        QString text = colors.value(QStringLiteral("background")).toString();
        if (text.isEmpty())
            text = colors.value(QStringLiteral("foreground")).toString();

        const QColor color(text.section(QLatin1Char(','), 0, 0).trimmed());
        if (color.isValid())
            m_colors.insert(name, color);
    }

    m_valid = !m_colors.isEmpty();
    return m_valid;
}
