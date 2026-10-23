#include "LocalSession.h"

#include <QDir>
#include <QProcessEnvironment>

#ifdef Q_OS_UNIX
#include "pty/UnixPty.h"
#endif
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

bool LocalSession::start(const QString &program)
{
#ifdef Q_OS_UNIX
    return m_pty->createProcess(program, QString(), QDir::homePath(),
                                QProcessEnvironment::systemEnvironment(), m_rows, m_columns);
#else
    Q_UNUSED(program);
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
