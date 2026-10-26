#pragma once

#include <QJsonArray>
#include <QMap>
#include <QString>
#include <QStringList>
#include <QVector>

struct MenuEntry
{
    enum Type { Action, Separator, Submenu };

    Type type = Action;
    QString actionId;
    QString title;
    QVector<MenuEntry> children;
};

class MenuConfig
{
public:
    static MenuConfig &instance();

    bool load(const QString &path);
    bool isValid() const { return m_valid; }
    QStringList menuNames() const { return m_menuNames; }
    QVector<MenuEntry> menu(const QString &name) const { return m_menus.value(name); }

private:
    MenuConfig() = default;
    static QVector<MenuEntry> parseEntries(const QJsonArray &array);

    QStringList m_menuNames;
    QMap<QString, QVector<MenuEntry>> m_menus;
    bool m_valid = false;
};
