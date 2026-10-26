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
    bool valueToBool(const QString &key, bool defaultValue = false) const;

    // R51 设置页写回：内存生效（user.config 写盘链未逆明挂账）。
    // 覆盖语义与 loadProfile 一致——user.config 键压 assets 默认。
    void setValue(const QString &key, const QJsonValue &value);

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
