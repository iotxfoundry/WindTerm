#pragma once

#include <QJsonObject>
#include <QString>

class WindConfig
{
public:
    static WindConfig &instance();

    bool load(const QString &path);
    QString valueToString(const QString &key, const QString &defaultValue = QString()) const;
    double valueToDouble(const QString &key, double defaultValue = 0.0) const;

private:
    WindConfig() = default;

    QJsonObject m_root;
};
