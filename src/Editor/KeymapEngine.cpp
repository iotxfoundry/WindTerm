#include "KeymapEngine.h"

#include "ProfileLoader.h"

#include <QFileInfo>

// ConfigBridge(0x00a7ecde yaml_toQVariant 转写,批 34 前入库)
QVariant yamlLoadToVariant(const QString &path);

#include <QCoreApplication>
#include <QDir>

KeymapEngine &KeymapEngine::instance()
{
	static KeymapEngine s_engine;
	return s_engine;
}

// s_wind_keymaps_768854(00768854,428B)语料转写
int KeymapEngine::loadKeymapSources()
{
	m_sources.clear();
	// FUN_005d7cf8(174B):applicationDirPath() + "/global/" + 名
	const QString globalPath = QCoreApplication::applicationDirPath()
	                               + QStringLiteral("/global/")
	                               + QStringLiteral("wind.keymaps");
	m_sources.append(globalPath);
	// FUN_00a7e78a(12B):全局槽 + flags &= ~0x04(语料)
	// cfg_ensureProfileDir(005d7dae,438B):"%1/profiles/%2/%3"
	//   (.wind 根/profile/名)→ absolutePath → mkpath
	const QString userPath = ProfileLoader::defaultProfilePath()
	                             + QStringLiteral("/user.keymaps");
	QDir().mkpath(QFileInfo(userPath).absolutePath());   // 语料 ensure 段
	m_sources.append(userPath);
	// FUN_00a7e866(12B):用户槽 + flags &= ~0x01(语料)
	// FUN_0067461a(m_keymap@+0x68,0)—— 引擎复位(批 46)
	m_keymap.reset(0);
	// FUN_00a7fd5e(113B)bit2 门 → FUN_00a7fdd8(71B)→
	//   yaml_toQVariant(ConfigBridge 委托,0x00a7ecde 族)
	int parsed = 0;
	m_loaded = QVariant();
	for (const QString &p : m_sources) {
		const QVariant root = yamlLoadToVariant(p);
		if (!root.isNull()) {
			++parsed;
			m_loaded = root;   // 语料双源累积(后源覆写/合并面待转写)
		}
	}
	return parsed;
}
