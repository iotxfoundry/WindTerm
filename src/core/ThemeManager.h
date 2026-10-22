#pragma once

#include <QString>
#include <QStringList>

class ThemeManager
{
public:
    static ThemeManager &instance();

    void setTheme(const QString &name);
    QString theme() const { return m_theme; }
    QStringList images() const { return m_images; }

private:
    ThemeManager() = default;

    QString m_theme;
    QStringList m_images;
};
