// KeymapConfig — wind.keymaps 快捷键数据（原版菜单右列来源）
// 只取带修饰键的映射（Ctrl/Alt/Shift/Meta 或 F 键）；单键 vim 模式映射不用于菜单。
// 同一 actionId 多条时取首条。
#pragma once
#include <QHash>
#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QRegularExpression>

class KeymapConfig {
public:
    static KeymapConfig &instance() {
        static KeymapConfig s;
        return s;
    }

    void load(const QString &path) {
        QFile f(path);
        if (!f.open(QIODevice::ReadOnly))
            return;
        QString raw = QString::fromUtf8(f.readAll());
        raw.remove(QChar(0xFEFF));
        QString out;
        for (const QString &line : raw.split(QLatin1Char('\n'))) {
            const int i = line.indexOf(QStringLiteral("//"));
            out += (i >= 0 ? line.left(i) : line) + QLatin1Char('\n');
        }
        const QJsonDocument doc = QJsonDocument::fromJson(out.toUtf8());
        if (!doc.isArray())
            return;
        // 原版规则（反汇编+截图 7 样本验证）：同一 action 多条绑定时，
        // 取【最后一个 modes 含 remote 且非 Meta 开头】的条目（远端终端可用的首选键）
        for (const QJsonValue &v : doc.array()) {
            const QJsonObject o = v.toObject();
            const QString action = o.value(QStringLiteral("action")).toString();
            const QString keys = o.value(QStringLiteral("keys")).toString();
            if (action.isEmpty() || keys.isEmpty())
                continue;
            QString bare = keys;
            bare.remove(QLatin1Char('<')).remove(QLatin1Char('>'));
            if (bare.startsWith(QStringLiteral("Meta")))
                continue;
            // 空 modes = 全局绑定（如 Alt+F4→Exit、Ctrl+Shift+N→NewWindow）；否则需含 remote
            static const QRegularExpression remote(QStringLiteral("\\bremote\\b"));
            const QString modes = o.value(QStringLiteral("modes")).toString();
            if (!modes.isEmpty() && !remote.match(modes).hasMatch())
                continue;
            m_map.insert(action, bare);  // 顺序遍历，后写覆盖 = 取最后一条
        }
    }

    QString shortcut(const QString &actionId) const { return m_map.value(actionId); }

    int count() const { return m_map.size(); }

private:
    QHash<QString, QString> m_map;
};
