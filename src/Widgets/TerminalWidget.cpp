#include "TerminalWidget.h"
#include "Screen.h"

#include <QApplication>
#include <QClipboard>
#include <QTimer>

TerminalWidget::TerminalWidget(QWidget *parent)
	: QWidget(parent)
{
}

// --- 状态查询组 ---

bool TerminalWidget::isAltScreen() const
{
	// 0083c4c8:Screen 栈守卫 → FUN_007e4028(+0x139)
	return m_commander && m_commander->m_screen
	           && m_commander->m_screen->isAltScreenActive();
}

bool TerminalWidget::isMainScreen() const
{
	return !isAltScreen();   // 0083c696
}

bool TerminalWidget::isConnected() const
{
	// 0083c524:+0x118 守卫 → FUN_007d6736
	return m_commander != nullptr;
}

bool TerminalWidget::isUnconnected() const
{
	return m_commander == nullptr;   // 0083c6fc → FUN_007d6722
}

QString TerminalWidget::protocolName() const
{
	return m_commander ? QString() : QString();   // 0083cb0c → FUN_007d5d2a
}

bool TerminalWidget::canWrite() const
{
	// 0083cdcc:状态查询 + 会话栈(+0x1e0/+0x1e8)守卫
	return m_commander != nullptr;
}

// --- 复位组 ---

void TerminalWidget::resetCharacterSet()
{
	if (m_commander && m_commander->m_screen)
		m_commander->m_screen->sendScreenCommand(6);   // 0083cbc8
}

void TerminalWidget::resetHard()
{
	if (m_commander && m_commander->m_screen)
		m_commander->m_screen->sendScreenCommand(7);   // 0083cc00
}

void TerminalWidget::resetSoft()
{
	if (m_commander && m_commander->m_screen)
		m_commander->m_screen->resetSoft();            // 0083cc38 → 007ea7e6
}

// --- 输入/清屏组 ---

void TerminalWidget::write(const QString &text)
{
	// idx 74/75(0083e286):vt14 C1 折叠 → writeText;
	// FUN_009109fa 信号发射(有连接时)— cited
	if (!m_commander || !m_commander->m_screen)
		return;
	const QByteArray folded = m_commander->processOutput(text.toUtf8());
	m_commander->m_screen->writeText(QString::fromUtf8(folded));
}

void TerminalWidget::clearScrollback()
{
	// idx 24(0083fc2c):tmux 态发 'clear-history -t %1',否则 CMD 0x75f1
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
	// idx 22(00840438):光标/提示行比较 → 0x5be68c 发命令 —
	// 提示行跟踪 Phase-4,cited
}

void TerminalWidget::clearScreenAndScrollback()
{
	// idx 23(00840532):clearScreen + 500ms 延迟清滚动(FUN_0083fd35)
	clearScreen();
	QTimer::singleShot(500, this, [this] { clearScrollback(); });
}

// --- CMD 直传组 ---

int TerminalWidget::caretVirtualSpace() const { return m_caretVirtualSpace; }   // CMD 0x75df
int TerminalWidget::promptLine() const { return m_promptLineValue; }            // CMD 0x75dd
int TerminalWidget::promptPosition() const { return m_promptPositionValue; }    // CMD 0x75de
int TerminalWidget::scrollbackLimit() const { return m_scrollbackLimitValue; }  // CMD 0x75f2
int TerminalWidget::scrollbackLines() const { return 0; }                       // CMD 0x75f3(行计数随视图)
long TerminalWidget::localBaseTime() const { return 0; }                        // CMD 0x75f9
void TerminalWidget::setScrollbackLimit(int v) { m_scrollbackLimitValue = v; }  // CMD 0x75f4
void TerminalWidget::setLocalBaseTime(int) {}                                   // CMD 0x75fd
void TerminalWidget::setRemoteBaseTime(int) {}                                  // CMD 0x75ff
void TerminalWidget::setTimestampFormat(const QByteArray &) {}                  // CMD 0x75fc
void TerminalWidget::setTimestampLongFormat(const QByteArray &) {}              // CMD 0x75fe
bool TerminalWidget::isFreeTypeMode() const { return m_freeTypeMode; }          // CMD 0x75e2

// --- FreeType 组 ---

void TerminalWidget::cancelFreeTypeMode()
{
	// idx 18(0083cf68):FUN_0083cee2(this, 0) 共享体 — cited
	m_freeTypeMode = false;
}

void TerminalWidget::eraseFreeTypeRange()
{
	// idx 29(00842d34):Screen 栈守卫 + 光标快照(00840316)复合 — cited
}

// --- 日志组 ---

bool TerminalWidget::isLogFileExists() const
{
	// idx 37(0083c5c8):+0x148 引用守卫 → QFileInfo::exists
	return !m_logFilePath.isEmpty();
}

bool TerminalWidget::isLoggerPaused() const
{
	// idx 38(0083c63a):isConnected 守卫 → 会话协议查询 FUN_007cabf8
	return m_commander && m_loggerPaused;
}

bool TerminalWidget::isLoggerStarted() const
{
	// idx 39(0083c5e6):会话栈守卫 → +0x150 状态
	return m_commander && m_loggerStarted;
}

bool TerminalWidget::isLoginWizardVisible() const
{
	return m_loginWizardVisible;   // idx 40(0083c674):+0x1b8/+0x1c0 指针对
}

void TerminalWidget::openLogFolder()
{
	// idx 46(0083c8b4):无日志 → 全局默认(0x11c2200);有 → 路径 —
	// 桌面打开对话框 Phase-4,cited
}

void TerminalWidget::openLogFile()
{
	// idx 47(0083c970):isModemTransmitting 守卫 → 全局对话框 — cited
}

void TerminalWidget::startLogger(const QString &name)
{
	// idx 70/71(008439ec):会话感知 QString 参复合体 — cited;
	// 状态字段按语料置位
	if (!name.isEmpty())
		m_logFilePath = name;
	m_loggerStarted = true;
	m_loggerPaused = false;
}

void TerminalWidget::stopLogger()
{
	// idx 72(0083dc18):isConnected + FUN_007d377c(+0x118,+0x150,0)
	// + 释放 +0x150 — 会话腿 cited;状态清零
	m_loggerStarted = false;
	m_loggerPaused = false;
}

void TerminalWidget::pauseLogger()
{
	// idx 50(0083c9be):isConnected 守卫 → FUN_007d36a0 — 会话腿 cited
	m_loggerPaused = true;
}

void TerminalWidget::resumeLogger()
{
	// idx 59(0083cc70):isConnected 守卫 → FUN_007d3d28 — 会话腿 cited
	m_loggerPaused = false;
}

// --- modem/zmodem 组 ---

bool TerminalWidget::isModemSupported(const QString &protocol) const
{
	// idx 42(0083cb36):标志 0x160==0 时仅 'Telnet' 支持;带标志走类型
	if (!m_tmuxMode)
		return protocol == QLatin1String("Telnet");
	return true;
}

bool TerminalWidget::isModemTransmitting() const
{
	// idx 43(0083c6a8):+0x120 modem 非空;否则 Screen FUN_007e31ec(命令 3)
	return m_modemActive;
}

void TerminalWidget::cancelModemTransmitting()
{
	// idx 19(00842172):Screen 栈守卫 + FUN_007e318a(取消命令 2)+
	// 释放 +0x120 modem 对象(0x38B)—— 对齐 Screen::zmodemTick
	// 取消语义(transferBinary(2,0))
	if (m_commander && m_commander->m_screen)
		m_commander->m_screen->zmodemTick(1, nullptr);
	m_modemActive = false;
}

void TerminalWidget::receiveBinary(const QByteArray &data)
{
	// idx 54(008496da):FUN_00848d6a(this, data, 0)— cited(zmodem 面)
	Q_UNUSED(data);
}

void TerminalWidget::sendBinary(const QByteArray &data)
{
	// idx 62(008496e2):FUN_00848d6a(this, data, 1)— cited
	Q_UNUSED(data);
}

// --- 会话/命令组 ---

void TerminalWidget::executeCommand(bool disconnected)
{
	// idx 30(0083ffde):+0x118/+0x1e0/+0x1e8 三重守卫 → 会话/文本路径 —
	// 装配组合:命令文本经 write 下行
	Q_UNUSED(disconnected);
}

void TerminalWidget::pasteText(bool disconnected)
{
	// idx 49(00843050):executeCommand 全路径(剪贴板文本装备 + 发送)
	const QString text = QApplication::clipboard()->text();
	write(text);
	Q_UNUSED(disconnected);
}

QString TerminalWidget::commandText(const QString &command) const
{
	// idx 25(0083c7f2):范围 helper FUN_005b8fcc → 005b9110 — cited
	return command;
}

void TerminalWidget::completeHistory()
{
	// idx 27(0083df86):FUN_0083de16(this, 1) — cited
}

void TerminalWidget::detectShellCwd()
{
	// idx 28(0083dc90):QTimer 编排(+0x1a8,栈守卫 + 标志 0x160)— cited
}

bool TerminalWidget::supportsDetectShellCwd() const
{
	// idx 73(0083dc72):方案注册表(FUN_005b97cc)+0x30 标志 — cited
	return false;
}

void TerminalWidget::disconnectSession()
{
	// idx 31(0083c330):全局管理器注册 FUN_00810d6e — cited
	if (m_commander && m_commander->m_screen)
		m_commander->m_screen->sendScreenCommand(0x75e1);
}

void TerminalWidget::reconnectSession()
{
	// idx 55(0083d97a):'SessionErrorMessage' 方案;状态非 0/1/5 分支 — cited
}

void TerminalWidget::setRightClickAction(bool disconnected)
{
	// idx 65(0083d0a6):全局(0x11c2200)查询 → FUN_0083d074 — cited
	Q_UNUSED(disconnected);
}
