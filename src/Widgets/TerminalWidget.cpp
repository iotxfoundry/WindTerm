#include "TerminalWidget.h"
#include "Screen.h"
#include <QTimer>

TerminalWidget::TerminalWidget(QWidget *parent)
	: QWidget(parent)
{
}

bool TerminalWidget::isAltScreen() const
{
	// 0083c4c8:Screen 栈守卫 → FUN_007e4028(+0x139)
	return m_commander && m_commander->m_screen
	           && m_commander->m_screen->isAltScreenActive();
}

bool TerminalWidget::isMainScreen() const
{
	// 0083c696:isAltScreen 取反
	return !isAltScreen();
}

bool TerminalWidget::isConnected() const
{
	// 0083c524:+0x118 守卫 → FUN_007d6736(协议查询;无对象=未连)
	return m_commander != nullptr;
}

bool TerminalWidget::isUnconnected() const
{
	// 0083c6fc:+0x118 守卫 → FUN_007d6722
	return m_commander == nullptr;
}

QString TerminalWidget::protocolName() const
{
	// 0083cb0c:+0x118 守卫 → FUN_007d5d2a
	return m_commander ? QString() : QString();
}

void TerminalWidget::resetCharacterSet()
{
	// 0083cbc8:Screen 栈守卫 → sendScreenCommand(6)
	if (m_commander && m_commander->m_screen)
		m_commander->m_screen->sendScreenCommand(6);
}

void TerminalWidget::resetHard()
{
	// 0083cc00:Screen 栈守卫 → sendScreenCommand(7)
	if (m_commander && m_commander->m_screen)
		m_commander->m_screen->sendScreenCommand(7);
}

void TerminalWidget::resetSoft()
{
	// 0083cc38:Screen 栈守卫 → FUN_007e33ea
	if (m_commander && m_commander->m_screen)
		m_commander->m_screen->resetSoft();
}

// --- 输入/清屏组 ---

void TerminalWidget::write(const QString &text)
{
	// idx 74/75(0083e286):会话栈守卫 + 文本 marshal → 视图写。
	// 4b 装配:vt14 C1 折叠 → writeText(语料经会话写通道,此处
	// 直接组合两端,门控随 Commander 状态面补)。
	if (!m_commander || !m_commander->m_screen)
		return;
	const QByteArray folded = m_commander->processOutput(text.toUtf8());
	m_commander->m_screen->writeText(QString::fromUtf8(folded));
	// FUN_009109fa writeText 信号发射(有连接时)— cited
}

void TerminalWidget::clearScrollback()
{
	// idx 24(0083fc2c):tmux 态发 'clear-history -t %1' 经 Screen;
	// 否则 CMD 0x75f1
	if (m_tmuxMode) {
		if (m_commander && m_commander->m_screen)
			m_commander->m_screen->writeText(
			    QStringLiteral("clear-history -t %1"));
		return;
	}
	if (m_commander && m_commander->m_screen)
		m_commander->m_screen->sendScreenCommand(0x75f1);
}

void TerminalWidget::clearScreen()
{
	// idx 22(00840438):光标位置(008403a6)与提示行(0083c9e2)
	// 比较后经 0x5be68c 发命令 —— 提示行跟踪 Phase-4,cited
}

void TerminalWidget::clearScreenAndScrollback()
{
	// idx 23(00840532):clearScreen + 500ms 延迟清滚动缓冲
	// (QTimer::singleShot, FUN_0083fd35)
	clearScreen();
	QTimer::singleShot(500, this, [this] { clearScrollback(); });
}
