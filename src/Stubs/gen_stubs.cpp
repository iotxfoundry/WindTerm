// 自动生成 cited-stub(链接器 mangled 名 + 头文件返回类型)
// 转写真身时删除对应行。生成器:tools/re/gen_stubs.py

#include "Sessions/Core/SuperSession.h"
#include "Sessions/Bridges/SuperBridge.h"
#include "Sessions/Terminal/TerminalCore.h"
#include "Sessions/Terminal/Screen.h"
#include "Widgets/Panels/TextView.h"
#include "Sessions/Terminal/Screen.h"
#include "Sessions/Core/SuperSession.h"
#include "Sessions/Terminal/TerminalCore.h"

SuperBridge::SuperBridge(QObject*) {}   // ctor/dtor stub

void Screen::filterRectangle(int, int, int, int) {  } // stub
void Screen::codecFromUnicode(QString const&) {  } // stub
int Screen::convertRowToHistory(TerminalCore*, Row*, void*, int) { return 0; } // stub
#include "Sessions/Terminal/TerminalCore.h"
int TerminalCore::cellFlags(struct Row *row, int i) const
{
	// FUN_007a3c68: attr head bits at +0x40 + i*2
	if (!row || i < 0) return 0;
	return *(const unsigned short *)((const char *)row + 0x40 + i * 2);
}
