#include "LocalSession.h"

#include <QDir>
#include <QProcessEnvironment>

#ifdef Q_OS_UNIX
#include "pty/UnixPty.h"
#endif

bool LocalSession::isTmuxControlCommand(const QString &program, const QString &args)
{
    // 0x7e9a06 谓词挂账已关闭（R44 2026-10-26）：原版启用判定=VT 输出流通知行特征检测
    // （0x7e9a32 泵），非 session 参数判定——判定已迁 TerminalView::detectTmuxControl。
    // 本函数保留空实现为过渡面；唯一调用点已删。
    Q_UNUSED(program);
    Q_UNUSED(args);
    return false;
}

LocalSession::LocalSession(int rows, int columns, QObject *parent)
    : Session(parent)
#ifdef Q_OS_UNIX
    , m_pty(new UnixPty(this))
#else
    , m_pty(nullptr)
#endif
    , m_rows(rows)
    , m_columns(columns)
{
#ifdef Q_OS_UNIX
    connect(m_pty, &Pty::readyRead, this, [this]() {
        const QByteArray data = m_pty->readAll();
        if (!data.isEmpty())
            emit output(data);
    });
    connect(m_pty, &Pty::finished, this, &LocalSession::finished);
#endif
}

LocalSession::~LocalSession() = default;

bool LocalSession::start(const QString &program, const QString &args, const QString &workDir)
{
#ifdef Q_OS_UNIX
    // tmux control 模式检测接线段（R44：判定迁 TerminalView 输出泵检测，此处恒 false）
    m_tmuxControl = isTmuxControlCommand(program, args);
    // workDir 空 → home（原版 ${HomeDir} 宏展开等价回退）；args 空白分隔由 UnixPty 拆成 argv
    return m_pty->createProcess(program, args,
                                workDir.isEmpty() ? QDir::homePath() : workDir,
                                QProcessEnvironment::systemEnvironment(), m_rows, m_columns);
#else
    Q_UNUSED(program);
    Q_UNUSED(args);
    Q_UNUSED(workDir);
    m_tmuxControl = isTmuxControlCommand(program, args);
    return false;
#endif
}

void LocalSession::write(const QByteArray &data)
{
#ifdef Q_OS_UNIX
    m_pty->write(data);
#else
    Q_UNUSED(data);
#endif
}

void LocalSession::resize(int rows, int columns)
{
#ifdef Q_OS_UNIX
    m_pty->resizeWindow(rows, columns);
#else
    Q_UNUSED(rows);
    Q_UNUSED(columns);
#endif
}

void LocalSession::close()
{
#ifdef Q_OS_UNIX
    delete m_pty; // UnixPty::~UnixPty → stop()：terminate→kill -9、断 notifier、关 fd
    m_pty = nullptr;
#endif
}
