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

// FUN_0076b430(68B,decomp-part-0023.c 36366-36392)语料转写:
// 懒建门(*(this+0x68)==0 → ctor)—— 我方 m_keymap 内嵌成员,
// 构造期即等价(懒建注记,勿增行为);→ s_wind_keymaps_768854 →
// FUN_0076aee6(JSON 腿)
void KeymapEngine::load()
{
	loadKeymapSources();
	loadJsonLeg();
}

// FUN_0076b430 ctor 注入点对位(0023.c 36366-36392:operator_new(0x20)
// → FUN_00674648(engine, host)第二参 = QObject parent → *(host+0x68)=engine):
// 我方懒建形态 = m_keymap 内嵌成员(头注),ctor 注入等价转 setParent(host)。
// 调用点 = 宿主装配批(mainWindow_connectSignals 0076b9ec 时序位)— cited。
void KeymapEngine::attachHost(QObject *host)
{
	m_keymap.setParent(host);
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
	// 双源各自独立装载(00768927 全局 / 0076895e 用户,均 mode=0):
	//   FUN_00a7fdd8(71B)bit2 门 → yaml_toQVariant(00a7ecde 族)
	//   FUN_00a8017e(71B)FUN_00a7fe20 门 → yaml_toQVariant
	//   → QVariant::toList → FUN_00678a56(engine, list, 0)
	int parsed = 0;
	m_loaded = QVariant();
	for (const QString &p : m_sources) {
		const QVariant root = yamlLoadToVariant(p);
		if (!root.isNull()) {
			++parsed;
			m_loaded = root;   // 语料逐源产物(无跨源合并面)
			m_keymap.loadEntries(root.toList(), 0);   // FUN_00678a56
		}
	}
	return parsed;
}

// FUN_0076aee6(1185B,decomp-part-0023.c 36216-36365)— cited — wave-2:
// 遍历 DAT_011c1240+0x10 容器(工具清单,面未转写)逐项建 QJsonObject:
//   无 scheme → script = "window.activeKit.startTool('%1')";
//   有 scheme → when = "window.activeView().scheme() == '%1'" +
//   script = "window.activeKit.startTool('%1', '%2')";keys = 工具名;
//   toVariantMap append → FUN_0067461a(engine,1)复位 →
//   FUN_00678a56(engine, list, 1)。可见腿仅复位(下),装载体 cited。
void KeymapEngine::loadJsonLeg()
{
	m_keymap.reset(1);   // FUN_0067461a(engine,1)(0067b346)
}
