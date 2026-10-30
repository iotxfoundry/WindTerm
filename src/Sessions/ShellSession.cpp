#include "ShellSession.h"
#include "SuperCommander.h"
#include "Screen.h"

#include <QMetaObject>

ShellSession::ShellSession(QObject *parent)
	: SuperSession(parent)
	, m_commander()
{
	m_commander.m_screen = nullptr;
}

ShellSession::~ShellSession()
{
	stop();
}

void ShellSession::stop()
{
	// 先断数据路径再停 pty:否则终止期间的输出仍进解析器
	if (m_ptyConn)
		QObject::disconnect(m_ptyConn);
	m_pty.stop();
	m_commander.m_screen = nullptr;   // 断视图挂钩
}

void ShellSession::attachScreen(Screen *screen)
{
	m_commander.m_screen = screen;
}

bool ShellSession::startLocal(const QString &shell, const QString &arguments,
                              const QString &workingDirectory)
{
	if (!m_pty.createProcess(shell, arguments, workingDirectory,
	                         QProcessEnvironment(), 31, 89))
		return false;
	m_ptyConn = QObject::connect(&m_pty, &Pty::readyRead, this, [this] {
		const QByteArray d = m_pty.readAll();
		m_commander.processOutput(d);   // 会话数据路径:pty → 解析器
		emit dataReceived(d);
	});
	return true;
}

bool ShellSession::write(const QByteArray &data)
{
	return m_pty.write(data);
}
