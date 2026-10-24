#pragma once

#include <QVariantMap>
#include <QString>
#include <QVector>

struct SessionEntry
{
    QString uuid;
    QString group;
    QString label;
    QString icon;
    QString protocol;
    QString target;
    int port = 0;
};

// user.sessions 接入（原版 0x00806a9e 启动 yaml_loadFile 存 CTerminalConfig+0xe0，
// 格式实为 JSON 数组）。读=load；写=原版编辑即写（0x00806958）：写前备份
// user.sessions.bak（用户真数据保护），键序=Qt5 QJsonObject 恒字母序（与真数据一致）。
class SessionStore
{
public:
    static QVector<SessionEntry> load();
    // 0x833db4 恢复链：按 session.uuid 查单条（未命中返回空 map）
    static QVariantMap sessionByUuid(const QString &uuid);
    // 0x806958 对齐：按 uuid 合并写回（既有条目未知名键原样保留，新 uuid 追加末尾）
    static bool saveFile(const QVector<SessionEntry> &entries);
    // 对话框入口：按 session.uuid 替换/追加（map 携全键——对话框已拷贝原条目未编辑键）
    static bool appendOrReplace(const QVariantMap &entry);
};
