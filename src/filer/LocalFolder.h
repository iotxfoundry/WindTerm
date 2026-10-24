#pragma once

#include <QVector>
#include <QString>

struct FileSystemItem;

// 原版 LocalFolder（0x8e8d36 QDir 后端）：同步列目录,由 FileSystemModel 在后台线程调用。
// hidden 按 showHidden 过滤（QDir::Hidden）,排序由模型逆序处理（此处 Unsorted）
class LocalFolder
{
public:
    static QVector<FileSystemItem *> list(const QString &path, bool showHidden);
};
