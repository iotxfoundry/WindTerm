#pragma once

#include <QJsonArray>
#include <QMap>
#include <QString>
#include <QVector>

struct ToolbarEntry
{
    enum Type { Action, AddressBar, Separator };

    Type type = Action;
    QString actionId;
};

class ToolbarConfig
{
public:
    static ToolbarConfig &instance();

    bool load(const QString &path);
    bool isValid() const { return m_valid; }
    QString toolbarName() const { return m_toolbarName; }
    QVector<ToolbarEntry> entries(const QString &name) const { return m_toolbars.value(name); }

private:
    ToolbarConfig() = default;
    static QVector<ToolbarEntry> parseEntries(const QJsonArray &array);

    QString m_toolbarName;
    QMap<QString, QVector<ToolbarEntry>> m_toolbars;
    bool m_valid = false;
};
