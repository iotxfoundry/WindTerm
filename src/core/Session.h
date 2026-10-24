#pragma once

#include <QByteArray>
#include <QObject>
#include <QString>

// 会话通用接口：LocalSession(pty) 与 SshSession(libssh) 共用。
// TerminalView 只依赖本基类，新增协议会话无需再动视图层。
class Session : public QObject
{
    Q_OBJECT

public:
    explicit Session(QObject *parent = nullptr)
        : QObject(parent)
    {
    }
    ~Session() override = default;

    virtual void write(const QByteArray &data) = 0;
    virtual void resize(int rows, int columns) = 0;
    // 原版停止=置标志+wait（SessionThread 0x007c7e8e）；默认空实现供未启动会话
    virtual void close() {}

    // user.sessions 的 session.uuid（0x833db4 恢复重连查询键）；新建本地会话无键留空
    QString uuid() const { return m_uuid; }
    // 外部组装点（MainWindow openSession 链）写入；子类/外部均经此入口
    void setUuid(const QString &uuid) { m_uuid = uuid; }

signals:
    void output(const QByteArray &data);
    void finished();

private:
    QString m_uuid;
};
