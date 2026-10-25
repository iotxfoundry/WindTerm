#include "LocalSession.h"

#include <QDir>
#include <QFileInfo>
#include <QProcessEnvironment>

#ifdef Q_OS_UNIX
#include "pty/UnixPty.h"
#endif

bool LocalSession::isTmuxControlCommand(const QString &program, const QString &args)
{
    // shortcut: 0x7e9a06 触发谓词未逆明，按 session 参数近似（target 基名 tmux 且 args 含 -CC）
    return QFileInfo(program).fileName() == QLatin1String("tmux")
        && args.split(QLatin1Char(' '), Qt::SkipEmptyParts).contains(QLatin1String("-CC"));
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
    // tmux control 模式检测接线段（0x7e9a06 挂账谓词，见 isTmuxControlCommand）
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
