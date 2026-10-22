#pragma once

#include <QByteArray>
#include <QObject>

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

signals:
    void output(const QByteArray &data);
    void finished();
};
