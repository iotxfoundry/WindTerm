#pragma once

#include <QDateTime>
#include <QString>
#include <QVector>

// 原版 FileSystemItem（0x634ef0）：type/name/size(链接=-1)/mtime(ms)/permissions/
// owner/group/children/loaded/parent。
// shortcut: 原版手工引用计数简化为父持有（子树随根析构）,挂账；fetching=模型调度标志
struct FileSystemItem
{
    enum Type { Folder, File, Link };

    // 根节点按目录处理（fetchNode 只抓 Folder）；真实条目由后端赋型
    Type type = Folder;
    QString name;
    qint64 size = 0;
    QDateTime mtime;
    QString permissions;
    QString owner;
    QString group;
    bool loaded = false;
    bool fetching = false;
    FileSystemItem *parent = nullptr;
    QVector<FileSystemItem *> children;

    ~FileSystemItem() { qDeleteAll(children); }
};

// ls 风格权限串（"drwxr-xr-x"）。shortcut: 原版权限列逐字格式未逆明,按 ls 惯例,
// RemoteFileSystemModel data 逆明后校准
inline QString fileModeString(QChar typeChar, unsigned int mode)
{
    QString s(1, typeChar);
    const char *rwx = "rwxrwxrwx";
    for (int i = 0; i < 9; ++i)
        s += (mode & (0400u >> i)) ? QChar::fromLatin1(rwx[i]) : QLatin1Char('-');
    return s;
}
