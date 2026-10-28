#include "ProfileLoader.h"

#include <QDir>
#include <QFile>
#include <QStandardPaths>
#include <QVariantMap>
#include <json/json.h>

QString ProfileLoader::defaultProfilePath()
{
	const QString base =
	    QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
	return base + QStringLiteral("/.wind/profiles/default.v10");
}

ProfileLoader::ProfileLoader(QString profilePath)
	: m_profilePath(std::move(profilePath))
{
}

static bool parseTolerant(const QByteArray &raw, Json::Value &root)
{
	// 原解析器容忍注释与数组缺逗号(见 wind.config 实文件);
	// jsoncpp CharReader 的 collectComments 覆盖注释语义
	Json::CharReaderBuilder b;
	b.settings_["collectComments"] = true;
	b.settings_["failIfExtra"] = false;
	std::unique_ptr<Json::CharReader> reader(b.newCharReader());
	std::string errs;
	return reader->parse(raw.constData(), raw.constData() + raw.size(), &root, &errs);
}

QVariantList ProfileLoader::loadSessions() const
{
	QFile f(m_profilePath + QStringLiteral("/terminal/user.sessions"));
	if (!f.open(QIODevice::ReadOnly))
		return {};
	Json::Value root;
	if (!parseTolerant(f.readAll(), root) || !root.isArray())
		return {};
	QVariantList out;
	for (const Json::Value &v : root) {
		QVariantMap m;
		for (auto it = v.begin(); it != v.end(); ++it) {
			const Json::Value &jv = *it;
			switch (jv.type()) {
			case Json::booleanValue: m.insert(QString::fromStdString(it.name()), jv.asBool()); break;
			case Json::intValue:
			case Json::uintValue:    m.insert(QString::fromStdString(it.name()), (qlonglong)jv.asInt64()); break;
			case Json::realValue:    m.insert(QString::fromStdString(it.name()), jv.asDouble()); break;
			case Json::stringValue:  m.insert(QString::fromStdString(it.name()), QString::fromStdString(jv.asString())); break;
			default: break;
			}
		}
		out.append(m);
	}
	return out;
}

bool ProfileLoader::saveSessions(const QVariantList &sessions) const
{
	Json::Value root(Json::arrayValue);
	for (const QVariant &e : sessions) {
		const QVariantMap m = e.toMap();
		Json::Value jv(Json::objectValue);
		for (auto it = m.begin(); it != m.end(); ++it) {
			switch (it.value().type()) {
			case QVariant::Bool:     jv[it.key().toStdString()] = it.value().toBool(); break;
			case QVariant::LongLong:
			case QVariant::Int:      jv[it.key().toStdString()] = (Json::Int64)it.value().toLongLong(); break;
			case QVariant::Double:   jv[it.key().toStdString()] = it.value().toDouble(); break;
			default:                 jv[it.key().toStdString()] = it.value().toString().toStdString(); break;
			}
		}
		root.append(jv);
	}
	QDir().mkpath(m_profilePath + QStringLiteral("/terminal"));
	QFile f(m_profilePath + QStringLiteral("/terminal/user.sessions"));
	if (!f.open(QIODevice::WriteOnly | QIODevice::Truncate))
		return false;
	Json::StreamWriterBuilder wb;
	wb.settings_["indentation"] = "    ";
	f.write(Json::writeString(wb, root).c_str());
	return true;
}

QVariantMap ProfileLoader::loadConfig(const QString &relPath) const
{
	QFile f(m_profilePath + QLatin1Char('/') + relPath);
	if (!f.open(QIODevice::ReadOnly))
		return {};
	Json::Value root;
	if (!parseTolerant(f.readAll(), root) || !root.isObject())
		return {};
	QVariantMap out;
	for (auto it = root.begin(); it != root.end(); ++it) {
		const Json::Value &jv = *it;
		switch (jv.type()) {
		case Json::booleanValue: out.insert(QString::fromStdString(it.name()), jv.asBool()); break;
		case Json::intValue:
		case Json::uintValue:    out.insert(QString::fromStdString(it.name()), (qlonglong)jv.asInt64()); break;
		case Json::realValue:    out.insert(QString::fromStdString(it.name()), jv.asDouble()); break;
		case Json::stringValue:  out.insert(QString::fromStdString(it.name()), QString::fromStdString(jv.asString())); break;
		default: break;
		}
	}
	return out;
}
