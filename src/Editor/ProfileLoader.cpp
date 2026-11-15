#include "ProfileLoader.h"

#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>
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
	// 批 171 序列化同构(config_saveFile 底座 00a801c6 → FUN_00aef8c0
	// ctor → 00d38620 vtable[2]=FUN_00afc1b0 0035.c:75571):
	//   缩进 = FUN_00af8810(0035.c:73112)流态 0x40000004a(asm 0xaef849
	//   movabs 实读)→ +0x34=4 空格(FUN_00af8a00 0035.c:73222 缩进串)/
	//   +0x30=74 rightMargin;键值分隔 " : "(json_toStream 00afb830
	//   0035.c:75489 区段 append);中文原样 UTF-8(jsoncpp_writeString
	//   00afa810 0035.c:74563 全 >0x1f raw 直包 → emitUTF8=true);
	//   尾换行(FUN_00afc1b0 @00afc1d6 append "\n");profiles.config
	//   原版产物样本实证同相({\n    "path" : "~"\n})。
	// 键序差 cited:jsoncpp std::map 字典序 vs 原版成员向量插入序
	//   (FUN_00af34a0 直扫)——读回等价,无键序语义消费实证。
	Json::StreamWriterBuilder wb;
	wb.settings_["indentation"] = "    ";   // +0x34 = 4(0xaef849)
	wb.settings_["emitUTF8"] = true;        // 00afa810 raw-emit 形态
	std::string doc = Json::writeString(wb, root);
	doc += '\n';                            // FUN_00afc1b0 尾 \n
	f.write(doc.data(), (qint64)doc.size());
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

// === 批 169:s_profiles_config_5d8c30(979B,0019.c:10368)写侧真身 —
// 调用点 sub_75bcd3+0x72 / sub_7625b6+0x9f(kuna xrefs;profile 目录
// 变更交互腿)。语料序:
//   @005d8c69  fromNativeSeparators(入参);
//   @005d8ca6  == 旧值(+0x30)→ 短路直返(仅改路径时回写语义);
//   @005d8cc7  applicationDirPath() + QDir(入参);
//   @005d8cf9  入参空或目录不存在 → "."(0xc9dabd 单字符实读);
//   @005d8d2b  QDir==appdir → "." 同串(005d8f15 区段);
//   @005d8d53  homePath 前缀 → "~"(0x7e)折叠(@005d8f99);
//   @005d8d86  拼串 appdir + "/" + "profiles.config"(0x88c3c3 字面);
//   @005d8e25  json root + "path" 键赋值(json_value_assign_stdstring
//              @005d8e94 / json_assign_cstring "path")→ config_saveFile
//              (00a801c6,0034.c:59978;序列化底座 std::ofstream,
//              jsoncpp 委托 EXT-BOUNDARY 判例)。
bool ProfileLoader::saveConfigPath(const QString &dirAbs,
                                   const QString &oldDir) const
{
	QString dir = QDir::fromNativeSeparators(dirAbs);        // @005d8c69
	if (dir == oldDir)                                       // @005d8ca6 短路
		return true;                                         // 不回写同相
	const QString appDir = QCoreApplication::applicationDirPath();
	// 目录存在性腿(@005d8cf9 QDir::exists 门)转写:空/不存在 → "."。
	// 语料 QDir(local_c0, param_2) 后 exists 检查 — 折叠腿(~)对存在
	// 与否同相(本函数只归一存储形,不建目录 — 005d8d27 QDir ctor 面)。
	if (dir.isEmpty() || !QDir(dir).exists())                // @005d8cf9 门
		dir = QStringLiteral(".");                           // 0xc9dabd "."
	else if (QDir(dir) == QDir(appDir))                      // @005d8d2b
		dir = QStringLiteral(".");                           // @005d8f15 区段
	else if (dir.startsWith(QDir::homePath())) {             // @005d8d53
		dir.replace(QDir::homePath(), QStringLiteral("~"));  // @005d8f99 "0x7e"
	}
	const QString cfgPath = QCoreApplication::applicationDirPath()
	                        + QStringLiteral("/profiles.config"); // @005d8d86-0x88c3c3
	Json::Value root(Json::objectValue);   // json_value_init_by_type(,7)→object
	root["path"] = dir.toStdString();      // json_assign_cstring "path" + assign
	QDir().mkpath(QFileInfo(cfgPath).path());   // config_saveFile mkpath 腿 @00a80499
	QFile f(cfgPath);
	if (!f.open(QIODevice::WriteOnly | QIODevice::Truncate))
		return false;                       // config_saveFile open 失败腿
	                                        //   (QMessageBox 交互腿不落 — 宿主域 cited)
	// 批 171 同构(批 169 注升级):缩进 4 空格/" : "/尾 \n 同
	// config_saveFile 底座(0035.c:73112+75571;profiles.config 原版
	// 产物样本 {"path" : "~"} 4 空格实证)。
	Json::StreamWriterBuilder wb;            // FUN_00aef8c0 序列化底座 jsoncpp 委托
	wb.settings_["indentation"] = "    ";    // +0x34 = 4(0xaef849)
	wb.settings_["emitUTF8"] = true;         // 00afa810 raw-emit
	std::string doc = Json::writeString(wb, root);
	doc += '\n';                             // FUN_00afc1b0 尾 \n
	f.write(doc.data(), (qint64)doc.size());
	return true;                            // @00a803b4 尾返 1
}
