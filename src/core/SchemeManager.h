#pragma once

#include <QColor>
#include <QHash>
#include <QString>
#include <QStringList>

class SchemeManager
{
public:
    static SchemeManager &instance();

    bool load(const QString &path = QString());
    bool isValid() const { return m_valid; }
    QColor color(const QString &styleName) const { return m_colors.value(styleName); }
    // 当前 scheme.theme 的 styles[].name（终端 scheme 列表）
    QStringList schemeNames() const { return m_names; }

private:
    SchemeManager() = default;

    QHash<QString, QColor> m_colors;
    QStringList m_names;
    bool m_valid = false;
};
