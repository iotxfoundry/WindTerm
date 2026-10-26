#pragma once

#include <QString>
#include <QVector>

struct FileSystemItem;

// 原版 SftpFolder_listDir（0x8e8d36，R49）：async_readdir 同线程忙泵——
// opendir→sftp_async_readdir_begin→循环 sftp_async_readdir 收 attr（-2=SSH_AGAIN 时
// QThread::yieldCurrentThread 让步）→sftp_dir_eof 判续→sftp_async_closedir_begin→
// sftp_async_closedir。一次调用内全量收齐返回（无信号批次/无专用线程），上层对结果
// 整表逆序插入。opendir 失败→空表。绑定/attr 布局全在 core/SshSession.cpp
class SftpFolder
{
public:
    static QVector<FileSystemItem *> list(void *sftp, const QString &path, bool showHidden);
};
