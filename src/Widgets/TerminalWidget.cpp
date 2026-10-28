#include "TerminalWidget.h"
#include "Screen.h"

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
