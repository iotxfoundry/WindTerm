#include "KeymapEngine.h"

// 语料依赖(00768854 区;cited — wave-2,待转写):
//   FUN_00a7e75e/FUN_00a7e78a/FUN_00a7e866/FUN_00a7fdd8 —— 累积器
//   FUN_005d7cf8 —— global 配置解析(DAT_011c1240 配置层)
//   cfg_ensureProfileDir —— user 侧 profile 目录确保
//   FUN_0067461a —— 引擎复位(engine @+0x68)
// 路径解析复用本树 ProfileLoader 面(开源/语料锚见 CALIBRATION)。

KeymapEngine &KeymapEngine::instance()
{
	static KeymapEngine s_engine;
	return s_engine;
}

int KeymapEngine::loadKeymapSources()
{
	// 语料:累积器 = [global/wind.keymaps, user.keymaps] 双源
	m_sources.clear();
	m_sources.append(QStringLiteral("wind.keymaps"));
	m_sources.append(QStringLiteral("user.keymaps"));
	// 语料:FUN_0067461a(engine@+0x68,0)—— 引擎复位
	// cited — wave-2(复位体待转写)
	return m_sources.size();
}
