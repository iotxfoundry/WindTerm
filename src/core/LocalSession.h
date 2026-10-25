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

    bool start(const QString &program = QStringLiteral("/bin/bash"),
               const QString &args = {}, const QString &workDir = {});
    // tmux control 模式触发谓词（0x7e9a06 触发谓词未逆明挂账：仅按本地 session 参数判定
    // ——target 基名=="tmux" 且 args 含 "-CC"（用户真数据条目形态））
    static bool isTmuxControlCommand(const QString &program, const QString &args);
    bool tmuxControl() const { return m_tmuxControl; }
    void write(const QByteArray &data) override;
    void resize(int rows, int columns) override;
    // UnixPty::stop() 已有杀进程/断 notifier/关 fd 的清理路径（terminate→kill -9），
    // close() 复用之（原版链 0x008df6c0 确认后 close+deleteLater）
    void close() override;

private:
    UnixPty *m_pty;
    int m_rows;
    int m_columns;
    bool m_tmuxControl = false;
};
