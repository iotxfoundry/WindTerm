#include "JsEngine.h"

#include <QFile>
#include <QJSValueList>
#include <QVariant>
#include <json/json.h>
#include <memory>

JsEngine &JsEngine::instance()
{
	static JsEngine s_engine;
	return s_engine;
}

int JsEngine::loadActions(const QString &path)
{
	m_actions.clear();
	QFile f(path);
	if (!f.open(QIODevice::ReadOnly))
		return 0;
	// JSONC 容错解析(CTerminalConfig 同款 jsoncpp collectComments)
	const QByteArray raw = f.readAll();
	Json::CharReaderBuilder b;
	std::unique_ptr<Json::CharReader> reader(b.newCharReader());
	Json::Value root;
	std::string errs;
	if (!reader->parse(raw.constData(), raw.constData() + raw.size(),
	                   &root, &errs))
		return 0;
	// wind_actions_build(00667102):map 遍历 → script trimmed →
	// evaluate 注册(空脚本跳过,FUN_0066613a 的 trimmed 空门)
	for (auto it = root.begin(); it != root.end(); ++it) {
		const std::string key = it.key().asString();
		const QString script =
		    QString::fromStdString(
		        (*it).get("script", "").asString())
		        .trimmed();
		if (script.isEmpty())
			continue;
		const QJSValue fn =
		    m_engine.evaluate(script, QString::fromStdString(key));
		if (fn.isError())
			continue;
		m_actions.insert(QString::fromStdString(key), fn);
	}
	return m_actions.size();
}

bool JsEngine::hasAction(const QString &name) const
{
	return m_actions.contains(name);
}

QVariant JsEngine::runAction(const QString &name, QObject *actionArg)
{
	const auto it = m_actions.constFind(name);
	if (it == m_actions.constEnd())
		return QVariant();
	QJSValueList args;
	if (actionArg != nullptr)
		args << m_engine.newQObject(actionArg);
	QJSValue fn = *it;
	const QJSValue r = fn.call(args);
	return r.isError() ? QVariant() : r.toVariant();
}

void JsEngine::installBridge(const QString &name, QObject *obj)
{
	m_engine.globalObject().setProperty(name,
	                                    m_engine.newQObject(obj));
}

QVariant JsEngine::runScript(const QString &source, const QString &name)
{
	const QJSValue r = m_engine.evaluate(source, name);
	return r.isError() ? QVariant() : r.toVariant();
}
