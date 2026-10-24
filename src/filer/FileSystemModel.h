#pragma once

#include <QAbstractItemModel>
#include <QString>
#include <QVector>

struct FileSystemItem;

// 对齐原版 RemoteFileSystemModel（0x634ef0/0x624eae）：5 列（名称/大小/修改时间/权限/属主）；
// 目录懒加载=后台线程列目录→queued 回 UI 线程 beginInsertRows。
// shortcut: 原版 busy 自旋门（0x624eae yield/nanosleep）未照搬——Qt 信号回调等效
//（自旋门在 UI 线程属忙等反模式,语义=UI 等后台加载完成）；引用计数简化为父持有
//（原版手工引用计数挂账）；排序=结果整表逆序 append（按名排序未找到,挂账）
class FileSystemModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    enum Column { Name, Size, Modified, Permissions, Owner, ColumnCount };

    explicit FileSystemModel(QObject *parent = nullptr);
    ~FileSystemModel() override;

    void setRootPath(const QString &path);
    void setShowHidden(bool show);
    // 非空=远程后端（SftpFolder）,空=本地（QDir）；切换即 reload
    void setSftp(void *sftp);

    QString rootPath() const { return m_rootPath; }
    bool showHidden() const { return m_showHidden; }

    QString pathFor(const QModelIndex &index) const;
    FileSystemItem *itemFor(const QModelIndex &index) const;

    // QAbstractItemModel
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    bool hasChildren(const QModelIndex &parent = QModelIndex()) const override;

signals:
    void loadStarted(const QString &path);
    void loadFinished(const QString &path);

private:
    void reload();
    void fetchNode(FileSystemItem *node);
    void finishLoad(FileSystemItem *node, quint64 generation, QVector<FileSystemItem *> items);
    QString pathOfItem(const FileSystemItem *item) const;
    QModelIndex indexOfItem(FileSystemItem *item) const;

    FileSystemItem *m_root;
    QString m_rootPath;
    void *m_sftp = nullptr;
    bool m_showHidden = false;
    quint64 m_generation = 0; // reload/reset 递增:陈旧后台结果按代丢弃
};
