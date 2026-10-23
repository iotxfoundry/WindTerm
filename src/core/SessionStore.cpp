#include "SessionStore.h"

#include <QDir>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

QVector<SessionEntry> SessionStore::load()
{
    QVector<SessionEntry> entries;
    const QString path = QDir::homePath() + QStringLiteral(
                             "/.wind/profiles/default.v10/terminal/user.sessions");
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
        return entries; // 空文件/不存在：空列表不报错

    QByteArray data = file.readAll();
    if (data.startsWith("\xEF\xBB\xBF"))
        data.remove(0, 3); // 剥 BOM
    const QJsonDocument doc = QJsonDocument::fromJson(data);
    const QJsonArray array = doc.array();
    entries.reserve(array.size());
    for (const QJsonValue &v : array) {
        const QJsonObject o = v.toObject();
        SessionEntry e;
        e.uuid = o.value(QStringLiteral("session.uuid")).toString();
        e.group = o.value(QStringLiteral("session.group")).toString();
        e.label = o.value(QStringLiteral("session.label")).toString();
        e.icon = o.value(QStringLiteral("session.icon")).toString();
        e.protocol = o.value(QStringLiteral("session.protocol")).toString();
        e.target = o.value(QStringLiteral("session.target")).toString();
        e.port = o.value(QStringLiteral("session.port")).toInt();
        entries.append(e);
    }
    return entries;
}
