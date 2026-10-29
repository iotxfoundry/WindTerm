#pragma once

#include <QRegularExpression>
#include <QString>
#include <QVector>

// 键位引擎(Phase 4a):装载 global/wind.keymaps({keys,modes,action|script}
// 数组),提供 key×mode 匹配面。action = 动作注册表名(wind.actions);
// script = JS 体(执行面 Phase 4a 后续)。模式表为逗号分隔
// (normal/command/local/remote/widget);空 modes = 全模式命中。
class KeymapEngine {
public:
    struct Entry {
        QString keys;     // PCRE 命名组正则(原样)
        QString modes;    // 原样逗号串
        QString action;
        QString script;
        QRegularExpression re;   // 预编译(锚定)
    };

    static KeymapEngine &instance();

    bool load(const QString &path);   // 全量装载;重复调用 = 重载
    int entryCount() const { return m_entries.size(); }
    int invalidCount() const { return m_invalid; }   // keys 编译失败条数
    const QVector<Entry> &entries() const { return m_entries; }

    // key 全串锚定匹配 keys 正则,且 mode 命中该条 modes 表
    QVector<Entry> match(const QString &key, const QString &mode) const;

private:
    KeymapEngine() = default;
    QVector<Entry> m_entries;
    int m_invalid = 0;
};
