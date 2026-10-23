#pragma once

#include <QByteArray>
#include <QString>

#include "Session.h"

class UnixPty;

class LocalSession : public Session
{
    Q_OBJECT

public:
    explicit LocalSession(int rows, int columns, QObject *parent = nullptr);
    ~LocalSession() override;

    bool start(const QString &program = QStringLiteral("/bin/bash"));
    void write(const QByteArray &data) override;
    void resize(int rows, int columns) override;
    // UnixPty::stop() 已有杀进程/断 notifier/关 fd 的清理路径（terminate→kill -9），
    // close() 复用之（原版链 0x008df6c0 确认后 close+deleteLater）
    void close() override;

private:
    UnixPty *m_pty;
    int m_rows;
    int m_columns;
};
