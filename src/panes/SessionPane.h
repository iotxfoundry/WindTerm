#pragma once

#include <QTreeWidget>

class SessionPane : public QTreeWidget
{
    Q_OBJECT

public:
    explicit SessionPane(QWidget *parent = nullptr);

signals:
    // 双击 SSH 子项 → MainWindow 接：ConnectDialog 预填 → SshSession 开标签
    void sessionActivated(const QString &target, int port, const QString &label);
};
