#pragma once

#include <QMap>
#include <QString>
#include <QStringList>

class ActionRegistry
{
public:
    static ActionRegistry &instance();

    bool load(const QString &path);
    bool isValid() const { return m_valid; }
    QStringList actionIds() const { return m_actions.keys(); }
    QString actionText(const QString &id) const;
    QString actionIcon(const QString &id) const;
    // wind.actions "state" JS 串（0x66613a：state 字段随 text/icon 同点读取）
    QString actionState(const QString &id) const;
    QMap<QString, QStringList> groups() const;

private:
    struct Action
    {
        QString text;
        QString icon;
        QString state;
    };

    ActionRegistry() = default;
    void parseFallback(const QString &text);

    QMap<QString, Action> m_actions;
    bool m_valid = false;
};
