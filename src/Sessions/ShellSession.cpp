#include "ShellSession.h"
#include "SuperCommander.h"
#include "Screen.h"

ShellSession::ShellSession(QObject *parent)
	: SuperSession(parent)
	, m_commander()
{
	m_commander.m_screen = nullptr;
}

ShellSession::~ShellSession()
{
	// 子进程随 pty 析构自行退出(-c 型);交互 shell 的 stop 接线
	// 随 Phase 4a 会话管理补(UnixPty::stop 为 private)
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
	QObject::connect(&m_pty, &Pty::readyRead, this, [this] {
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
