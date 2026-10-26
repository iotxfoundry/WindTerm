#pragma once

#include <QTreeWidget>
#include <QVariantMap>

class SessionPane : public QTreeWidget
{
    Q_OBJECT

public:
    explicit SessionPane(QWidget *parent = nullptr);

    // 选中子条目全键 map（SessionStore::sessionByUuid；组行/无选中=空 map）
    QVariantMap selectedEntry() const;

public slots:
    // 重新 load + 重建树（新建/编辑写盘后刷新）
    void reload();

signals:
    // 双击 SSH 子项 → MainWindow 接：ConnectDialog 预填 → SshSession 开标签
    void sessionActivated(const QString &target, int port, const QString &label);
};
