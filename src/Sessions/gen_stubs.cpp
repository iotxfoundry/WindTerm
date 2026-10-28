// 自动生成 cited-stub(链接器 mangled 名 + 头文件返回类型)
// 转写真身时删除对应行。生成器:tools/re/gen_stubs.py

#include "SuperSession.h"
#include "SuperBridge.h"
#include "TerminalCore.h"
#include "Screen.h"
#include "TextView.h"
#include "TelnetCommander.h"
#include "Screen.h"
#include "SuperSession.h"
#include "TerminalCore.h"

SuperBridge::SuperBridge(QObject*) {}   // ctor/dtor stub
void SuperSession::drop() {  } // stub
void SuperSession::open() {  } // stub
void TelnetCommander::negotiateOption(QString const&) {  } // stub
void TelnetCommander::negotiateSubOption(QString const&) {  } // stub
void Screen::filterRectangle(int, int, int, int) {  } // stub
void Screen::codecFromUnicode(QString const&) {  } // stub
int Screen::convertRowToHistory(TerminalCore*, Row*, void*, int) { return 0; } // stub
QString SuperSession::fingerprint(King::FingerprintType) const { return QString(); } // stub
QString SuperSession::hostAddress() const { return QString(); } // stub
bool SuperSession::isConnected() const { return false; } // stub
bool SuperSession::isDuplicable() const { return false; } // stub
QString SuperSession::protocolName() const { return QString(); } // stub
QString SuperSession::serverBanner() const { return QString(); } // stub
bool SuperSession::isUnconnected() const { return false; } // stub
QString SuperSession::opensshVersion() const { return QString(); } // stub
QString SuperSession::lastErrorString() const { return QString(); } // stub
bool SuperSession::needVerifyServerFingerprint() const { return false; } // stub
QString SuperSession::name() const { return QString(); } // stub
QString SuperSession::hostName() const { return QString(); } // stub
QString SuperSession::lastError() const { return QString(); } // stub
#include "TerminalCore.h"
int TerminalCore::cellFlags(struct Row *row, int i) const
{
	// FUN_007a3c68: attr head bits at +0x40 + i*2
	if (!row || i < 0) return 0;
	return *(const unsigned short *)((const char *)row + 0x40 + i * 2);
}
