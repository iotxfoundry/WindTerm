#pragma once

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

// user.sessions 只读接入（原版 0x00806a9e 启动 yaml_loadFile 存 CTerminalConfig+0xe0，
// 格式实为 JSON 数组）。只读：写盘=原版编辑即写（0x00806958），骨架新建/编辑会话
// 落地时再实现，且需 profile 隔离决策——勿写用户原版 profile。
class SessionStore
{
public:
    static QVector<SessionEntry> load();
};
