#pragma once

#include <QHash>
#include <QString>

class LocaleManager
{
public:
    static LocaleManager &instance();

    bool load(const QString &path);
    QString tr(const QString &en) const;

private:
    LocaleManager() = default;

    QHash<QString, QString> m_translations;
};
