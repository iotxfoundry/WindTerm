#pragma once

#include <QString>

class ThemeManager
{
public:
    static ThemeManager &instance();

    bool loadTheme(const QString &name);
    void apply() const;
    QString currentTheme() const { return m_currentTheme; }
    QString qss() const { return m_qss; }

private:
    ThemeManager() = default;

    QString m_currentTheme;
    QString m_qss;
};
