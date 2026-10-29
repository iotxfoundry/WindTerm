#include "KeymapEngine.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

// 装载:wind.keymaps 为 JSON 数组;个别 keys 内嵌原始控制字符
// (如 ESC 字面),QJsonDocument 严格模式拒收 → 先把裸控制字节
// 转义成 \uXXXX 再解析(正则语义不变)。
static QByteArray sanitizeControlChars(const QByteArray &raw)
{
    QByteArray out;
    out.reserve(raw.size() + 64);
    for (char c : raw) {
        const unsigned char u = (unsigned char)c;
        if (u < 0x20 && u != '\t' && u != '\n' && u != '\r')
            out += QString("\\u%1").arg(u, 4, 16, QLatin1Char('0')).toLatin1();
        else
            out += c;
    }
    return out;
}

KeymapEngine &KeymapEngine::instance()
{
    static KeymapEngine s_engine;
    return s_engine;
}

bool KeymapEngine::load(const QString &path)
{
    QFile f(path);
    if (!f.open(QIODevice::ReadOnly))
        return false;
    const QJsonDocument doc =
        QJsonDocument::fromJson(sanitizeControlChars(f.readAll()));
    if (!doc.isArray())
        return false;

    QVector<Entry> parsed;
    const QJsonArray arr = doc.array();
    parsed.reserve(arr.size());
    for (const QJsonValue &v : arr) {
        const QJsonObject o = v.toObject();
        Entry e;
        e.keys = o.value(QLatin1String("keys")).toString();
        e.modes = o.value(QLatin1String("modes")).toString();
        e.action = o.value(QLatin1String("action")).toString();
        e.script = o.value(QLatin1String("script")).toString();
        if (e.keys.isEmpty())
            continue;
        // 锚定匹配:keys 正则描述"一段按键"的整体
        e.re = QRegularExpression(
            QRegularExpression::anchoredPattern(e.keys));
        if (!e.re.isValid()) {
            // PCRE2 语义差(如重复命名组):量化留证,条目跳过
            ++m_invalid;
            continue;
        }
        parsed.append(e);
    }
    m_entries = parsed;
    return true;
}

QVector<KeymapEngine::Entry> KeymapEngine::match(const QString &key,
                                                 const QString &mode) const
{
    QVector<Entry> hits;
    for (const Entry &e : m_entries) {
        if (!e.re.match(key).hasMatch())
            continue;
        if (!e.modes.isEmpty()) {
            const QStringList modes =
                e.modes.split(QLatin1Char(','), Qt::SkipEmptyParts);
            bool ok = false;
            for (QString m : modes) {
                if (m.trimmed() == mode) {
                    ok = true;
                    break;
                }
            }
            if (!ok)
                continue;
        }
        hits.append(e);
    }
    return hits;
}
