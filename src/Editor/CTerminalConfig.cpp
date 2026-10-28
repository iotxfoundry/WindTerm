#include "CTerminalConfig.h"

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
	// FUN_00809d78: guard-protected Meyers singleton at DAT_011c2220
	static CTerminalConfig cfg;
	return &cfg;
}

void CTerminalConfig::setConfigPath(const QString &path)
{
	if (m_configPath == path)
		return;
	m_configPath = path;
	m_loaded = false;
}

void CTerminalConfig::reload()
{
	m_values.clear();
	m_loaded = true;
	QFile f(m_configPath);
	if (!f.open(QIODevice::ReadOnly))
		return;
	const QByteArray raw = f.readAll();
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
		case Json::booleanValue: m_values.insert(key, v.asBool()); break;
		case Json::intValue:
		case Json::uintValue:    m_values.insert(key, (qlonglong)v.asInt64()); break;
		case Json::realValue:    m_values.insert(key, v.asDouble()); break;
		case Json::stringValue:  m_values.insert(key, QString::fromStdString(v.asString())); break;
		default: break;   // 复杂值:数组/对象按需扩展
		}
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
