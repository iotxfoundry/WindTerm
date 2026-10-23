#pragma once

#include <QJsonArray>
#include <QJsonObject>
#include <QString>

class WindConfig
{
public:
    static WindConfig &instance();

    bool load(const QString &path);
    QString valueToString(const QString &key, const QString &defaultValue = QString()) const;
    double valueToDouble(const QString &key, double defaultValue = 0.0) const;

    // 0x008065a2 / 0x0056be56：~/.wind/profiles/<profile>/terminal/quickbar.config 顶层命令数组；
    // 文件缺失=空数组（原版默认空 QuickBar）。
    QJsonArray quickCommands() const;

    // 0x0056e420：三个显示开关，默认 false/true/true（wind.config:30-32）
    bool quickShowCommandsInOrder() const;
    bool quickShowGroupTitle() const;
    bool quickShowMultipleGroups() const;

private:
    WindConfig() = default;
    static QString profileDir();
    void loadProfile();
    void loadQuickBar();

    QJsonObject m_root;
    QJsonArray m_quickCommands;
};
