#include "CGlobalConfigFace.h"

// 批 140 — 两腿 Meyers 单例体(库内唯一副本,判例
// CTerminalConfig::instance();头内 inline static 跨 DSO 会双副本,
// 破坏 menu() 两窗同身份断言面)。

// FUN_005df8d6(121B,0019.c:15746):CEditorConfig Meyers
// DAT_011c1300(guard DAT_011c12e8 + atexit FUN_005dfc04)。
CEditorConfigFace *CEditorConfigFace::instance()
{
	static CEditorConfigFace cfg;
	return &cfg;
}

// FUN_00809d78(121B,0025.c:43289):CTerminalConfig Meyers face 视图
// DAT_011c2220(guard DAT_011c2208 + atexit FUN_0080a0ba;值面真单例
// 同址,KitWindowFactory.cpp terminalConfigAsFace 注记)。
CTerminalConfigFace *CTerminalConfigFace::instance()
{
	static CTerminalConfigFace cfg;
	return &cfg;
}
