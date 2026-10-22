#pragma once

#include <QColor>
#include <QHash>
#include <QString>

class SchemeManager
{
public:
    static SchemeManager &instance();

    bool load(const QString &path = QString());
    bool isValid() const { return m_valid; }
    QColor color(const QString &styleName) const { return m_colors.value(styleName); }

private:
    SchemeManager() = default;

    QHash<QString, QColor> m_colors;
    bool m_valid = false;
};
