#include "ActionRegistry.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QRegularExpression>

#include "JsonText.h"

ActionRegistry &ActionRegistry::instance()
{
    static ActionRegistry registry;
    return registry;
}

bool ActionRegistry::load(const QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
        return false;

    QByteArray data = file.readAll();
    if (data.startsWith("\xEF\xBB\xBF"))
        data.remove(0, 3);

    data = JsonText::replaceControlCharsInStrings(JsonText::stripLineComments(data));

    m_actions.clear();
    const QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isObject()) {
        const QJsonObject root = doc.object();
        for (auto it = root.constBegin(); it != root.constEnd(); ++it) {
            if (!it.value().isObject())
                continue;
            const QJsonObject object = it.value().toObject();
            Action action;
            action.text = object.value(QStringLiteral("text")).toString();
            action.icon = object.value(QStringLiteral("icon")).toString();
            // 0x66613a：state（JS 串）随 text/icon 同点读出；正则校验略（原版直接存）
            action.state = object.value(QStringLiteral("state")).toString();
            m_actions.insert(it.key(), action);
        }
    } else {
        parseFallback(QString::fromUtf8(data));
    }

    m_valid = !m_actions.isEmpty();
    return m_valid;
}

QString ActionRegistry::actionText(const QString &id) const
{
    return m_actions.value(id).text;
}

QString ActionRegistry::actionIcon(const QString &id) const
{
    return m_actions.value(id).icon;
}

QString ActionRegistry::actionState(const QString &id) const
{
    return m_actions.value(id).state;
}

QMap<QString, QStringList> ActionRegistry::groups() const
{
    QMap<QString, QStringList> result;
    for (auto it = m_actions.constBegin(); it != m_actions.constEnd(); ++it)
        result[it.key().section(QLatin1Char('.'), 0, 0)].append(it.key());
    return result;
}

void ActionRegistry::parseFallback(const QString &text)
{
    static const QRegularExpression re(QStringLiteral(
        "\"([A-Za-z0-9_.]+)\"\\s*:\\s*\\{[^{}]*?\"text\"\\s*:\\s*\"((?:[^\"\\\\]|\\\\.)*)\""));

    auto it = re.globalMatch(text);
    while (it.hasNext()) {
        const QRegularExpressionMatch match = it.next();
        Action action;
        action.text = match.captured(2);
        m_actions.insert(match.captured(1), action);
    }
}
