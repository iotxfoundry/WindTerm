#include "WindConfig.h"

#include <QDir>
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
    loadProfile();
    loadQuickBar();
    return true;
}

QString WindConfig::profileDir()
{
    return QDir::homePath() + QStringLiteral("/.wind/profiles/default.v10");
}

void WindConfig::loadProfile()
{
    QFile file(profileDir() + QStringLiteral("/user.config"));
    if (!file.open(QIODevice::ReadOnly))
        return;

    QByteArray data = file.readAll();
    if (data.startsWith("\xEF\xBB\xBF"))
        data.remove(0, 3);

    const QJsonDocument doc = QJsonDocument::fromJson(JsonText::stripLineComments(data));
    if (!doc.isObject())
        return;

    const QJsonObject profile = doc.object();
    for (auto it = profile.constBegin(); it != profile.constEnd(); ++it)
        m_root.insert(it.key(), it.value());
}

void WindConfig::loadQuickBar()
{
    m_quickCommands = QJsonArray();
    // 0x0080647e：profiles/<profile>/terminal/quickbar.config（与 user.config 同一 profile 根）
    QFile file(profileDir() + QStringLiteral("/terminal/quickbar.config"));
    if (!file.open(QIODevice::ReadOnly))
        return; // 0x008065a2：文件缺失=空数组

    QByteArray data = file.readAll();
    if (data.startsWith("\xEF\xBB\xBF"))
        data.remove(0, 3);

    const QJsonDocument doc = QJsonDocument::fromJson(JsonText::stripLineComments(data));
    if (doc.isArray())
        m_quickCommands = doc.array();
}

QJsonArray WindConfig::quickCommands() const
{
    return m_quickCommands;
}

bool WindConfig::quickShowCommandsInOrder() const
{
    return m_root.value(QStringLiteral("quickbar.showCommandsInOrder")).toBool(false);
}

bool WindConfig::quickShowGroupTitle() const
{
    return m_root.value(QStringLiteral("quickbar.showGroupTitle")).toBool(true);
}

bool WindConfig::quickShowMultipleGroups() const
{
    return m_root.value(QStringLiteral("quickbar.showMultipleGroups")).toBool(true);
}

QString WindConfig::valueToString(const QString &key, const QString &defaultValue) const
{
    const QJsonValue value = m_root.value(key);
    return value.isString() ? value.toString() : defaultValue;
}

double WindConfig::valueToDouble(const QString &key, double defaultValue) const
{
    const QJsonValue value = m_root.value(key);
    // 原 global_setting 数值读取不拒 bool（JSON true/false 即 1/0）——Opacity/FocusMode 初值走此路径
    if (value.isDouble())
        return value.toDouble();
    if (value.isBool())
        return value.toBool() ? 1.0 : 0.0;
    return defaultValue;
}

bool WindConfig::valueToBool(const QString &key, bool defaultValue) const
{
    const QJsonValue value = m_root.value(key);
    return value.isBool() ? value.toBool() : defaultValue;
}

void WindConfig::setValue(const QString &key, const QJsonValue &value)
{
    m_root.insert(key, value);
    // shortcut: user.config 写盘链挂账——原版 setValue 落 ~/.wind/user.config 的函数未逆明，
    // 先内存生效；逆明后在此补写盘
}
