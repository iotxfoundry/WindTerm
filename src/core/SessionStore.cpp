#include "SessionStore.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSet>
#include <QUuid>

namespace {

QString sessionsPath()
{
    return QDir::homePath() + QStringLiteral(
               "/.wind/profiles/default.v10/terminal/user.sessions");
}

// 写前备份（用户真数据保护，覆盖旧备份）+ 4 空格缩进写回（0x806958 落盘段）
bool writeArray(const QJsonArray &array)
{
    const QString path = sessionsPath();
    QFile::remove(path + QStringLiteral(".bak"));
    if (!QFile::copy(path, path + QStringLiteral(".bak")) && QFile::exists(path))
        qWarning() << "SessionStore: backup" << path + ".bak" << "failed";

    QFile out(path);
    if (!out.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qWarning() << "SessionStore: cannot write" << path << ":" << out.errorString();
        return false;
    }
    QByteArray data = QJsonDocument(array).toJson(QJsonDocument::Indented);
    if (!data.endsWith('\n'))
        data += '\n';
    return out.write(data) == data.size();
}

} // namespace

QVector<SessionEntry> SessionStore::load()
{
    QVector<SessionEntry> entries;
    QFile file(sessionsPath());
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

QVariantMap SessionStore::sessionByUuid(const QString &uuid)
{
    // 全键返回（含 process.*/serial.*/ssh.* 等扩展键）——编辑对话框以此为 base，
    // 未编辑键写盘时不丢；既有调用方均按 .value() 取键，扩展键无影响
    QFile file(sessionsPath());
    if (!file.open(QIODevice::ReadOnly))
        return {};
    QByteArray data = file.readAll();
    if (data.startsWith("\xEF\xBB\xBF"))
        data.remove(0, 3);
    const QJsonArray array = QJsonDocument::fromJson(data).array();
    for (const QJsonValue &v : array) {
        const QJsonObject o = v.toObject();
        if (o.value(QStringLiteral("session.uuid")).toString() == uuid)
            return o.toVariantMap();
    }
    return {};
}

// 0x806958 对齐：JSON 数组写回。读原文件在条目粒度重建（未在 entries 的原条目保留），
// entries 命中原条目则替换、新 uuid 追加末尾。键序：Qt5 QJsonObject 恒字母序
// （实测 insert 顺序也不保留），恰与真数据键已字母序一致；条目间顺序=原文件顺序+追加。
bool SessionStore::saveFile(const QVector<SessionEntry> &entries)
{
    QJsonArray original;
    QFile in(sessionsPath());
    if (in.open(QIODevice::ReadOnly)) {
        QByteArray data = in.readAll();
        if (data.startsWith("\xEF\xBB\xBF"))
            data.remove(0, 3);
        original = QJsonDocument::fromJson(data).array();
    }

    auto uuidOf = [](const QJsonObject &o) {
        return o.value(QStringLiteral("session.uuid")).toString();
    };

    QSet<QString> known;
    for (const QJsonValue &v : original)
        known.insert(uuidOf(v.toObject()));

    QJsonArray array;
    for (const QJsonValue &v : original) {
        const QJsonObject o = v.toObject();
        const QString oldUuid = uuidOf(o);
        const SessionEntry *hit = nullptr;
        for (const SessionEntry &e : entries) {
            if (!e.uuid.isEmpty() && e.uuid == oldUuid) {
                hit = &e;
                break;
            }
        }
        if (!hit) {
            array.append(o);
            continue;
        }
        // 原条目未知名键（session.dataType/session.oneKey/ssh.* 等）原样保留
        QJsonObject merged = o;
        merged.insert(QStringLiteral("session.group"), hit->group);
        merged.insert(QStringLiteral("session.icon"), hit->icon);
        merged.insert(QStringLiteral("session.label"), hit->label);
        merged.insert(QStringLiteral("session.protocol"), hit->protocol);
        merged.insert(QStringLiteral("session.target"), hit->target);
        merged.insert(QStringLiteral("session.port"), hit->port);
        array.append(merged);
    }
    for (const SessionEntry &e : entries) {
        if (e.uuid.isEmpty() || known.contains(e.uuid))
            continue;
        QJsonObject o;
        o.insert(QStringLiteral("session.group"), e.group);
        o.insert(QStringLiteral("session.icon"), e.icon);
        o.insert(QStringLiteral("session.label"), e.label);
        o.insert(QStringLiteral("session.port"), e.port);
        o.insert(QStringLiteral("session.protocol"), e.protocol);
        o.insert(QStringLiteral("session.target"), e.target);
        o.insert(QStringLiteral("session.uuid"), e.uuid);
        array.append(o);
    }
    return writeArray(array);
}

// map 载全键（对话框 entryValue 已拷贝原条目未编辑键；串口/Shell 扩展键 process.* /
// serial.* 不降维丢失）：按 uuid 在原条目上覆盖同名键（未知名键双保险保留），新条目
// fromVariantMap 直写（QJsonObject 字母序=真数据键序）
bool SessionStore::appendOrReplace(const QVariantMap &entry)
{
    const QString uuid = entry.value(QStringLiteral("session.uuid")).toString();
    if (uuid.isEmpty())
        return false;

    QJsonArray original;
    QFile in(sessionsPath());
    if (in.open(QIODevice::ReadOnly)) {
        QByteArray data = in.readAll();
        if (data.startsWith("\xEF\xBB\xBF"))
            data.remove(0, 3);
        original = QJsonDocument::fromJson(data).array();
    }

    const QJsonObject patch = QJsonObject::fromVariantMap(entry);
    QJsonArray array;
    bool replaced = false;
    for (const QJsonValue &v : original) {
        QJsonObject o = v.toObject();
        if (o.value(QStringLiteral("session.uuid")).toString() == uuid) {
            for (auto it = patch.constBegin(); it != patch.constEnd(); ++it)
                o.insert(it.key(), it.value());
            replaced = true;
        }
        array.append(o);
    }
    if (!replaced)
        array.append(patch);
    return writeArray(array);
}
