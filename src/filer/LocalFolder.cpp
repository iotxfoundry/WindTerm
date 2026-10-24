#include "filer/LocalFolder.h"

#include <QDir>
#include <QFileInfo>

#include "filer/FileSystemItem.h"

namespace {

// QFileInfo 权限旗标 → POSIX 低九位（fileModeString 输入）
unsigned int posixMode(const QFileInfo &fi)
{
    const QFile::Permissions p = fi.permissions();
    unsigned int m = 0;
    if (p & QFile::ReadOwner) m |= 0400;
    if (p & QFile::WriteOwner) m |= 0200;
    if (p & QFile::ExeOwner) m |= 0100;
    if (p & QFile::ReadGroup) m |= 0040;
    if (p & QFile::WriteGroup) m |= 0020;
    if (p & QFile::ExeGroup) m |= 0010;
    if (p & QFile::ReadOther) m |= 0004;
    if (p & QFile::WriteOther) m |= 0002;
    if (p & QFile::ExeOther) m |= 0001;
    return m;
}

} // namespace

QVector<FileSystemItem *> LocalFolder::list(const QString &path, bool showHidden)
{
    QDir::Filters filters = QDir::AllEntries | QDir::NoDotAndDotDot;
    if (showHidden)
        filters |= QDir::Hidden;
    const QFileInfoList infos = QDir(path).entryInfoList(filters, QDir::Unsorted);

    QVector<FileSystemItem *> items;
    items.reserve(infos.size());
    for (const QFileInfo &fi : infos) {
        auto *item = new FileSystemItem;
        item->type = fi.isSymLink() ? FileSystemItem::Link
                     : fi.isDir()   ? FileSystemItem::Folder
                                    : FileSystemItem::File;
        item->name = fi.fileName();
        // 链接 size=-1（0x634ef0 语义）
        item->size = item->type == FileSystemItem::Link ? -1
                     : item->type == FileSystemItem::Folder
                         ? 0
                         : static_cast<qint64>(fi.size());
        item->mtime = fi.lastModified();
        const QChar typeChar = item->type == FileSystemItem::Folder ? QLatin1Char('d')
                               : item->type == FileSystemItem::Link ? QLatin1Char('l')
                                                                    : QLatin1Char('-');
        item->permissions = fileModeString(typeChar, posixMode(fi));
        item->owner = fi.owner();
        item->group = fi.group();
        items.append(item);
    }
    return items;
}
