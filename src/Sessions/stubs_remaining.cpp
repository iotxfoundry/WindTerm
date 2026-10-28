#include "Screen.h"
#include "SuperSession.h"
#include "TerminalCore.h"
// 自动生成 cited-stub(链接器 mangled 名 + 头文件返回类型)
// 转写真身时删除对应行。生成器:tools/re/gen_stubs.py

#include "SuperSession.h"
#include "SuperBridge.h"
#include "TerminalCore.h"
#include "Screen.h"
#include "TelnetCommander.h"
#include "Screen.h"
#include "SuperSession.h"
#include "TerminalCore.h"


int TerminalCore::cellFlags(struct Row *row, int i) const
{
	// FUN_007a3c68: attr head bits
	if (!row || i < 0) return 0;
	return *(const unsigned short *)((const char *)row + 0x40 + i * 2);
}

#include "TelnetCommander.h"