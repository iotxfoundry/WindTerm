#include "Screen.h"
#include "SuperSession.h"
#include "TerminalCore.h"
#include "TextView.h"
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
void TelnetCommander::negotiateSubOption(QString const&) {  } // stub
void Screen::zmodemTick() {  } // stub
void Screen::currentPage() {  } // stub
int Screen::containerEnd(void*) { return 0; } // stub
void * Screen::defaultStyle(int) { return nullptr; } // stub
void Screen::mediaCopyDec(int) {  } // stub
void Screen::notifyZmodem(int, int) {  } // stub
void Screen::resizeScreen(int, int, int) {  } // stub
int Screen::charsetLookup(QString const&, bool) { return 0; } // stub
void Screen::markRowErased(int) {  } // stub
void Screen::notifyCommand(QString const&) {  } // stub
const char * Screen::conformanceKey() { return nullptr; } // stub
void Screen::requestDecMode(int) {  } // stub
bool Screen::charsetDisabled(int) { return false; } // stub
void Screen::filterRectangle(int, int, int, int) {  } // stub
void Screen::notifyMessageEx(int, int, int) {  } // stub
void Screen::setLinesPerPage(int) {  } // stub
int Screen::widthFromTables(unsigned int) { return 0; } // stub
void Screen::codecFromUnicode(QString const&) {  } // stub
void * Screen::historyContainer(void*) { return nullptr; } // stub
void Screen::highlightTracking(int, int) {  } // stub
void Screen::keymapSetModifier(void*) {  } // stub
void Screen::notifyCursorStyle(void*, int) {  } // stub
void Screen::setColumnsPerPage(int) {  } // stub
void Screen::appendHistoryBlock(int, int, void*, bool, bool) {  } // stub
void Screen::markLocatorChanged() {  } // stub
void Screen::requestKeyModifier(int) {  } // stub
void Screen::setUserDefinedKeys() {  } // stub
void Screen::applyNamedAttribute(char const*, QString const&) {  } // stub
int Screen::convertRowToHistory(TerminalCore*, Row*, void*, int) { return 0; } // stub
void Screen::keymapResetModifier(void*) {  } // stub
void Screen::notifyNamedAttribute(char const*, QString const&) {  } // stub
void Screen::selectStatusLineType(int) {  } // stub
void Screen::setWindowTitleBuffer(QString const&) {  } // stub
void Screen::setWindowIconAndTitle(QString const&) {  } // stub
void Screen::requestDisplayedExtent() {  } // stub
void Screen::requestLocatorPosition(int) {  } // stub
int Screen::queryProtocolLevelProxy() { return 0; } // stub
void Screen::setUserPreferredCharset(int) {  } // stub
void Screen::requestXtermTerminfoData(QString const&) {  } // stub
void Screen::selectActiveStatusDisplay(int) {  } // stub
void Screen::requestTerminalStateReport() {  } // stub
void Screen::selectNumberOfLinesOnScreen(int) {  } // stub
void Screen::requestUserPreferredSupplementalSet() {  } // stub
const char * Screen::sgrKey() { return nullptr; } // stub
const char * Screen::attrKey() { return nullptr; } // stub
void Screen::notifyOsc(int, QString const&) {  } // stub
void Screen::writeText(QString const&) {  } // stub
bool Screen::scrollbackModeCheck() const { return false; } // stub

#include "SuperSessionPrivate.h"

QString SuperSession::serverBanner() const { return m_d ? QString() : QString(); }
QString SuperSession::opensshVersion() const { return QString(); }
QString SuperSession::protocolName() const { return QString(); }
QString SuperSession::hostName() const { return QString(); }
QString SuperSession::hostAddress() const { return QString(); }
QString SuperSession::lastError() const { return QString(); }
QString SuperSession::lastErrorString() const { return QString(); }
QString SuperSession::name() const { return QString(); }
bool SuperSession::isConnected() const { return false; }
bool SuperSession::isUnconnected() const { return true; }
bool SuperSession::isDuplicable() const { return false; }
bool SuperSession::needVerifyServerFingerprint() const { return false; }
King::SessionState SuperSession::state() const { return King::Unconnected; }
QString SuperSession::fingerprint(King::FingerprintType type) const { (void)type; return QString(); }
void SuperSession::open() {}
void SuperSession::drop() {}
#include "TerminalCore.h"

bool TerminalCore::rowHasContent(struct Row *row) const
{
	// FUN_007a4a06: any cell has non-zero attr or content
	if (!row) return false;
	return *(const unsigned char *)((const char *)row + 0);
}

int TerminalCore::cellFlags(struct Row *row, int i) const
{
	// FUN_007a3c68: attr head bits
	if (!row || i < 0) return 0;
	return *(const unsigned short *)((const char *)row + 0x40 + i * 2);
}

void TerminalCore::resetCharsetSlots() { m_charsetSlots[0] = m_charsetSlots[1] = m_charsetSlots[2] = m_charsetSlots[3] = 0; }
void TerminalCore::copyState(void **dst, void **src) { if (dst && src) *dst = *src; }
void TerminalCore::resetWrap(int y) { if (y >= 0 && y < rowCount()) m_rows[y]->flags &= ~0x80; }
#include "Screen.h"
QStringList Screen::splitParams(const QString &params) const
{
	return params.split(';', Qt::SkipEmptyParts);
}
#include "TelnetCommander.h"
void TelnetCommander::negotiateOption(const QString &command) { (void)command; }
