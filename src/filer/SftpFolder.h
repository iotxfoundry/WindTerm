#pragma once

#include <QString>
#include <QVector>

struct FileSystemItem;

// 原版 SftpFolder（0x8e8d36）：同步列目录后端,由 FileSystemModel 在后台 IO 线程调用
//（sftp 句柄只归 worker/IO 线程,UI 线程只读——SshSession 类注释线程边界）。
// shortcut: 原版 async_readdir 泵（0x8e8d36）未照搬,阻塞 readdir 在独立线程等效
class SftpFolder
{
public:
    // sftp 句柄=libssh sftp_session（不透明）;绑定与 attr 结构布局全在 core/SshSession.cpp
    static QVector<FileSystemItem *> list(void *sftp, const QString &path, bool showHidden);
};
