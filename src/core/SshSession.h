#pragma once

#include <QByteArray>
#include <QString>

#include "Session.h"

class QSocketNotifier;

// 最小可用 SSH 远程会话：dlopen("libssh.so.4")，密码认证 + PTY shell。
//
// 之所以走 dlopen：本机只有 libssh 运行库、无开发头文件（同 KingIcons.h 的
// QSvgRenderer 折衷）。libssh 是纯 C 库，符号无 C++ 名字修饰，直接 dlsym 即可；
// 不需要 KingIcons 那种“预分配对象 + 显式传 this”的构造函数 ABI 处理。
class SshSession : public Session
{
    Q_OBJECT

public:
    explicit SshSession(int rows, int columns, QObject *parent = nullptr);
    ~SshSession() override;

    // 阻塞式连接（见 cpp 内的 shortcut 注释）。失败时先 emit output(错误文本) 再 emit finished()。
    bool start(const QString &host, const QString &user, const QString &password, int port = 22);

    void write(const QByteArray &data) override;
    void resize(int rows, int columns) override;
    // teardown() 已含 notifier 断开+deleteLater、channel close/free、ssh_free/disconnect
    void close() override;

    bool isConnected() const;

    // 自检用：libssh 是否加载且所有必需符号非空
    static bool symbolsAvailable();

private slots:
    void readChannel();

private:
    void fail(const QString &stage);
    void teardown();

    void *m_session; // ssh_session（不透明指针，避免依赖头文件）
    void *m_channel; // ssh_channel
    QSocketNotifier *m_notifier;
    int m_rows;
    int m_columns;
    bool m_finished;
};
