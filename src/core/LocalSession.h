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
    // tmux control 触发谓词已关闭（R44 2026-10-26：0x7e9a06 谓词=输出流检测，见
    // TerminalView::detectTmuxControl）；m_tmuxControl/tmuxControl() 过渡面保留恒 false。
    static bool isTmuxControlCommand(const QString &program, const QString &args);
    bool tmuxControl() const { return m_tmuxControl; } // 过渡面：R44 后恒 false，勿再接线
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
