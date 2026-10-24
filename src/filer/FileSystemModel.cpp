#include "filer/FileSystemModel.h"

#include <QDateTime>
#include <QDir>

#ifdef WINDTERM_HAVE_CONCURRENT
#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrentRun>
#endif

#include "core/LocaleManager.h"
#include "filer/FileSystemItem.h"
#include "filer/LocalFolder.h"
#include "filer/SftpFolder.h"

namespace {

// 列目录后端分派（sftp 非空=远程,空=本地）——运行于 QtConcurrent IO 线程
QVector<FileSystemItem *> loadListing(void *sftp, const QString &path, bool showHidden)
{
    return sftp ? SftpFolder::list(sftp, path, showHidden) : LocalFolder::list(path, showHidden);
}

} // namespace

FileSystemModel::FileSystemModel(QObject *parent)
    : QAbstractItemModel(parent)
    , m_root(new FileSystemItem)
{
}

FileSystemModel::~FileSystemModel()
{
    // 在途后台结果按 generation 丢弃（退出路径可能漏收,挂账）
    delete m_root;
}

void FileSystemModel::setRootPath(const QString &path)
{
    m_rootPath = path;
    reload();
}

void FileSystemModel::setShowHidden(bool show)
{
    if (m_showHidden == show)
        return;
    m_showHidden = show;
    reload();
}

void FileSystemModel::setSftp(void *sftp)
{
    if (m_sftp == sftp)
        return;
    m_sftp = sftp;
    reload();
}

void FileSystemModel::reload()
{
    beginResetModel();
    ++m_generation;
    qDeleteAll(m_root->children);
    m_root->children.clear();
    m_root->loaded = false;
    m_root->fetching = false;
    endResetModel();
    if (!m_rootPath.isEmpty()) // 空 root（未 init）不加载
        fetchNode(m_root);
}

FileSystemItem *FileSystemModel::itemFor(const QModelIndex &index) const
{
    return index.isValid() ? static_cast<FileSystemItem *>(index.internalPointer()) : m_root;
}

QString FileSystemModel::pathOfItem(const FileSystemItem *item) const
{
    QStringList names;
    for (const FileSystemItem *it = item; it && it != m_root; it = it->parent)
        names.prepend(it->name);
    QString path = m_rootPath;
    if (!path.endsWith(QLatin1Char('/')))
        path += QLatin1Char('/');
    return path + names.join(QLatin1Char('/'));
}

QString FileSystemModel::pathFor(const QModelIndex &index) const
{
    FileSystemItem *item = itemFor(index);
    if (!item || item == m_root)
        return m_rootPath;
    return pathOfItem(item);
}

QModelIndex FileSystemModel::indexOfItem(FileSystemItem *item) const
{
    if (!item || item == m_root)
        return {};
    FileSystemItem *p = item->parent;
    const int row = (p ? p : m_root)->children.indexOf(item);
    if (row < 0)
        return {};
    const QModelIndex parentIdx = p == m_root ? QModelIndex() : indexOfItem(p);
    return createIndex(row, 0, item);
}

QModelIndex FileSystemModel::index(int row, int column, const QModelIndex &parent) const
{
    FileSystemItem *p = itemFor(parent);
    if (row < 0 || column < 0 || column >= ColumnCount || row >= p->children.size())
        return {};
    return createIndex(row, column, p->children.at(row));
}

QModelIndex FileSystemModel::parent(const QModelIndex &child) const
{
    FileSystemItem *item = itemFor(child);
    if (!child.isValid() || !item || !item->parent || item->parent == m_root)
        return {};
    FileSystemItem *p = item->parent;
    const int row = (p->parent ? p->parent : m_root)->children.indexOf(p);
    return row < 0 ? QModelIndex() : createIndex(row, 0, p);
}

int FileSystemModel::rowCount(const QModelIndex &parent) const
{
    return itemFor(parent)->children.size();
}

int FileSystemModel::columnCount(const QModelIndex &) const
{
    return ColumnCount;
}

QVariant FileSystemModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return {};
    FileSystemItem *item = itemFor(index);
    switch (index.column()) {
    case Name:
        return item->name;
    case Size:
        return item->type == FileSystemItem::File ? QString::number(item->size) : QString();
    case Modified:
        return item->mtime.toString(QStringLiteral("yyyy-MM-dd hh:mm"));
    case Permissions:
        return item->permissions;
    case Owner:
        return item->group.isEmpty() ? item->owner
                                     : item->owner + QLatin1Char('.') + item->group;
    }
    return {};
}

QVariant FileSystemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole || section < 0
        || section >= ColumnCount)
        return {};
    // 列头文案：旧 QTreeWidget 版实存 tr 键 "Name"/"Date mod"；后三列文案无证据,英文占位挂账
    static const char *kCols[ColumnCount] = {"Name", "Size", "Date mod", "Permissions", "Owner"};
    return LocaleManager::instance().tr(QString::fromLatin1(kCols[section]));
}

bool FileSystemModel::hasChildren(const QModelIndex &parent) const
{
    FileSystemItem *item = itemFor(parent);
    // 0x624eae：未 loaded 的目录行触发异步加载（Qt fetchMore 语义同位点）
    if (item->type == FileSystemItem::Folder && !item->loaded)
        const_cast<FileSystemModel *>(this)->fetchNode(item);
    return !item->children.isEmpty() || item->type == FileSystemItem::Folder;
}

void FileSystemModel::fetchNode(FileSystemItem *node)
{
    if (!node || node->type != FileSystemItem::Folder || node->loaded || node->fetching)
        return;
    node->fetching = true;
    const quint64 generation = m_generation;
    const QString path = node == m_root ? m_rootPath : pathOfItem(node);
    emit loadStarted(path);
#ifdef WINDTERM_HAVE_CONCURRENT
    auto *watcher = new QFutureWatcher<QVector<FileSystemItem *>>(this);
    connect(watcher, &QFutureWatcherBase::finished, this, [this, watcher, node, generation] {
        const QVector<FileSystemItem *> items = watcher->result();
        watcher->deleteLater();
        finishLoad(node, generation, items);
    });
    watcher->setFuture(QtConcurrent::run(loadListing, m_sftp, path, m_showHidden));
#else
    finishLoad(node, generation, loadListing(m_sftp, path, m_showHidden));
#endif
}

void FileSystemModel::finishLoad(FileSystemItem *node, quint64 generation,
                                 QVector<FileSystemItem *> items)
{
    if (node)
        node->fetching = false;
    if (!node || generation != m_generation) {
        qDeleteAll(items); // 陈旧结果（reset/reload 已换代）
        return;
    }
    node->loaded = true;
    emit loadFinished(node == m_root ? m_rootPath : pathOfItem(node));
    if (items.isEmpty())
        return;
    const QModelIndex parentIdx = indexOfItem(node);
    beginInsertRows(parentIdx, 0, items.size() - 1);
    // 原版只见整表逆序（按名排序未找到,0x634ef0）——结果逆序 append+挂账
    for (int i = items.size() - 1; i >= 0; --i) {
        items[i]->parent = node;
        node->children.append(items[i]);
    }
    endInsertRows();
}
