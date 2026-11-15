#include "CTerminalConfig.h"

#include <QCoreApplication>
#include <QFile>
#include <json/json.h>

CTerminalConfig::CTerminalConfig()
{
	// FUN_00809b90 tail: the trim regex over escape(">")
	m_trimRegex.setPattern(QStringLiteral(
		"^\\s++|\\s++(?=%1)|(?<=%1)\\s++|\\s++$")
		.arg(QRegularExpression::escape(m_defaultPrompt)));
}

CTerminalConfig *CTerminalConfig::instance()
{
	// FUN_00809d78: guard-protected Meyers singleton at DAT_011c2220.
	// 批 142:同一对象承载值面 + CGlobalConfigFace 容器面(私有基),
	// DAT_011c2220 双面同址语料形态。
	static CTerminalConfig cfg;
	return &cfg;
}

// CTerminalConfig::face — FUN_00858fce 对位真身(FUN_00858fce 39B,
// 0026.c:50296:DAT_011c2200 懒缓存 ← FUN_00809d78):合一后 = 同一单例
// 的 face 基面(无第二静态对象;upcast 同址)。
CTerminalConfigFace *CTerminalConfig::face()
{
	return CTerminalConfig::instance(); // IS-A CTerminalConfigFace(私有基)
}

void CTerminalConfig::setConfigPath(const QString &path)
{
	if (m_configPath == path)
		return;
	m_configPath = path;
	m_loaded = false;
}

void CTerminalConfig::setOverridePath(const QString &path)
{
	// 用户覆写层(~/.wind/.../user.config);装载顺序见
	// docs/CONFIG-SCHEMAS.md 二节:wind.config 基线 → user.config 覆盖
	if (m_overridePath == path)
		return;
	m_overridePath = path;
	m_loaded = false;
}

static void parseInto(const QByteArray &raw, QVariantMap &out)
{
	Json::CharReaderBuilder b;
	b.settings_["collectComments"] = true;   // wind.config 带 // 注释
	std::unique_ptr<Json::CharReader> reader(b.newCharReader());
	Json::Value root;
	std::string errs;
	if (!reader->parse(raw.constData(), raw.constData() + raw.size(), &root, &errs)
	    || !root.isObject())
		return;
	// 扁平点号键,直接进 map(二进制的 session_optGet 家族语义)
	for (auto it = root.begin(); it != root.end(); ++it) {
		const Json::Value &v = *it;
		const QString key = QString::fromStdString(it.name());
		switch (v.type()) {
		case Json::booleanValue: out.insert(key, v.asBool()); break;
		case Json::intValue:
		case Json::uintValue:    out.insert(key, (qlonglong)v.asInt64()); break;
		case Json::realValue:    out.insert(key, v.asDouble()); break;
		case Json::stringValue:  out.insert(key, QString::fromStdString(v.asString())); break;
		default: break;   // 复杂值:数组/对象按需扩展
		}
	}
}

void CTerminalConfig::reload()
{
	m_values.clear();
	m_loaded = true;
	// 全局默认层(s_wind_config_5d7f8e,782B,0019.c:9781):
	//   @005d80f1 appdir + "/global/wind.config"(FUN_005d7cf8 174B 拼
	//   序:applicationDirPath + "/" + "global/" + "wind.config" 字面
	//   @005d80fa-d8)→ 源 1 槽(FUN_00a7e78a);值面加载序 = wind.config
	//   基线 → user.config 覆写(005d8180,CONFIG-SCHEMAS 装载顺序;
	//   yaml_loadFile 三层源链 FUN_00a7fe9a @59852:源0 → 源4 → 源8 →
	//   缺省参,miss 链逐层回落)。配置路径未显式注入时自动拼全局层
	//   (configPath 语义同相;m_configPath 显式注入 = 测试缝优先)。
	if (!m_configPath.isEmpty()) {
		QFile f(m_configPath);
		if (f.open(QIODevice::ReadOnly))
			parseInto(f.readAll(), m_values);
	} else {
		QFile g(QCoreApplication::applicationDirPath()
		        + QStringLiteral("/global/wind.config")); // @005d80fa-d8
		if (g.open(QIODevice::ReadOnly))
			parseInto(g.readAll(), m_values);   // 默认层基线(权威默认)
	}
	if (!m_overridePath.isEmpty()) {
		QFile u(m_overridePath);
		if (u.open(QIODevice::ReadOnly))
			parseInto(u.readAll(), m_values);   // 后写覆盖 = 覆写层
	}
}

QVariant CTerminalConfig::value(const QString &key, const QVariant &defaultValue) const
{
	if (!m_loaded)
		const_cast<CTerminalConfig *>(this)->reload();
	return m_values.value(key, defaultValue);
}

void CTerminalConfig::setValue(const QString &key, const QVariant &value)
{
	if (!m_loaded)
		reload();
	m_values.insert(key, value);
}

// === 批 169:FUN_008cbb2e setter face 键面 — s_kit_startupSessions_6e6e75
// 三写腿共经此(FUN_006e6c46 入 config 对象 +0x30 → 8cbb2e):键串
// fromAscii(760b2c @00760b86 toLower + @00760bf1 正则 "^kit(?=\.)" 剥
// "kit." 前缀)→ 值面写(@008cbbf5→0075c480 global_setting_get 同址
// 通路 → CTerminalConfig::value 判例对偶)。timer 延写腿(6e6c46
// param_4!=0,QTimer 批存)cited — 写侧节流宿主域,值面即刻写同相。
void CTerminalConfig::setValueKitScoped(const QByteArray &key,
                                        const QVariant &value)
{
	QString k = QString::fromUtf8(key);          // @008cbbad-cc 键面
	k = k.toLower();                            // @00760b86
	k.remove(QRegularExpression(QStringLiteral("^kit\\."))); // @00760bf1-216("^kit(?=\.)" lookahead 剥 "kit." 前缀;PCRE 前瞻零宽 → consume "kit." 整段)
	setValue(k, value);                         // @008cbbf5→0075c480 写通路
}

// === 批 169:s_kit_startupSessions_6e6e75(340B,0022.c:12550)写端
// 真身 — 三态单选钮组槽(@006e6f8e 尾段 setEnabled 循环 = 组兄弟钮
// 消偿面,宿主槽位,不落)。语料逐钮 isChecked 序与键值:
//   首钮真 → "SpecificSessions"(@006e6f81);
//   次钮真 → "NoSessions"(@006e6ee0);
//   末钮真 → "LastSessions"(@006e6f29)。
void CTerminalConfig::setStartupSessions(bool specificChecked,
                                         bool noSessionsChecked,
                                         bool lastChecked)
{
	const char *mode = nullptr;
	if (specificChecked)                        // @006e6f6x 首钮腿
		mode = "SpecificSessions";              // @006e6f81 字面
	else if (noSessionsChecked)                 // @006e6ecx 次钮腿
		mode = "NoSessions";                    // @006e6ee0 字面
	else if (lastChecked)                       // @006e6f2x 末钮腿
		mode = "LastSessions";                  // @006e6f29 字面
	if (mode == nullptr)
		return;                                 // 三钮皆假 → LAB_006e6f8e 直过
	setValueKitScoped(QByteArrayLiteral("kit.startupSessions"),
	                  QVariant(QString::fromLatin1(mode))); // QVariant(char*) 面
}
