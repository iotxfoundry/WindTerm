#include "filer/SftpFolder.h"

#include "core/SshSession.h"
#include "filer/FileSystemItem.h"

QVector<FileSystemItem *> SftpFolder::list(void *sftp, const QString &path, bool showHidden)
{
    // 绑定/dlsym/sftp_attributes_struct 布局全在 SshSession.cpp（api() 单点）
    return SshSession::sftpList(sftp, path, showHidden);
}
