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

// CTerminalConfig::face — **单例的 face 视图转换**,不是独立二进制函数。
// 语料 39B 懒缓存函数(0026.c:50296)的实现属 TerminalWindowFace::menu()
// (Windows/Kit/KitWindowFactory.cpp),本函数只是同址 upcast(批 142 合一)。
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
	// docs/subsystems/config-schemas.md 二节:wind.config 基线 → user.config 覆盖
	if (m_overridePath == path)
		return;
	m_overridePath = path;
	m_loaded = false;
}

// 批 174 复合缺口收口:yaml_toQVariant(FUN_00a7ecde,1302B,
// 0034.c:59107)真身转写 — Json::Value → QVariant 全型面
// (jsoncpp ValueType 0-7 + default):
//   case0 null   → 空 QVariant(parseInto 不落:FUN_00a7fe9a miss 链
//                  @00a7ff03/@00a7ff52 json_isNullType → 下一源/缺省,
//                  平铺 map 承载 = null 即未在此层设定);
//   case1/2      → int64(case2 语料 QVariant(u64),现役 (qlonglong)
//                  批 150 形态保持 — 值域同相);case3 real;
//                  case4 string fromUtf8;case5 bool;
//   case6 array  → 递归 QVariantList(@00a7ed2d qlist 循环 append);
//   case7 object → 递归 QVariantMap(@00a7edd0 成员向量 FUN_00af34a0
//                  + QMap 插入);
//   default      → json_value_as_string → QByteArray(@00a7f0f4)。
// 消费面现无(searchEngines/margins 族现役读点零;wind.config 五复合
// 键盘点见 5c-report 批 171 矩阵)→ 承载档,cited 待消费点开批。
static QVariant jsonValueToVariant(const Json::Value &v)
{
	switch (v.type()) {
	case Json::nullValue:    return QVariant();   // case0
	case Json::intValue:
	case Json::uintValue:    return (qlonglong)v.asInt64();   // case1/2
	case Json::realValue:    return v.asDouble();             // case3
	case Json::stringValue:
		return QString::fromStdString(v.asString());          // case4 @00a7efeb
	case Json::booleanValue: return v.asBool();               // case5
	case Json::arrayValue: {                       // case6 @00a7ed2d
		QVariantList list;
		for (const Json::Value &e : v)
			list.append(jsonValueToVariant(e));    // 递归同相
		return list;
	}
	case Json::objectValue: {                      // case7 @00a7edd0
		QVariantMap map;
		for (auto it = v.begin(); it != v.end(); ++it)
			map.insert(QString::fromStdString(it.name()),
			           jsonValueToVariant(*it));
		return map;
	}
	default:                                       // @00a7f0f4
		return QVariant(QByteArray(v.asString().c_str()));
	}
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
	// 扁平点号键,直接进 map(二进制的 session_optGet 家族语义);
	// 值面 = yaml_toQVariant 全型(批 174 jsonValueToVariant)。
	for (auto it = root.begin(); it != root.end(); ++it) {
		const QVariant val = jsonValueToVariant(*it);
		if (!val.isValid())
			continue;   // case0 null → miss 链不落(FUN_00a7fe9a)
		out.insert(QString::fromStdString(it.name()), val);
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
	//   基线 → user.config 覆写(005d8180,config-schemas 装载顺序;
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
