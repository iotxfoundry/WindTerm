#include "JsEngine.h"

// 0064ab10(33B):QObject(parent) + m_engine 置空(引擎创建收进
// bootstrap;语料 0020:29875)
JsEngine::JsEngine(QObject *parent)
	: QObject(parent)
{
}

// dtor 0064ab32/0064ab46:零额外拆除 —— 引擎父链挂 this,由 QObject
// 父子拆除(0020:29887/29898)
JsEngine::~JsEngine() = default;

// s_MuxPane_64b102(0064b102,1707B)引导体(与 MuxPaneJs::bootstrap
// 同体;本实现父链挂 this —— 语料 QJSEngine::QJSEngine(this,param_1)
// @0020:30179)
void JsEngine::bootstrap(QObject *kingMeta, QObject *paneMeta,
                         QObject *appBridge, QObject *windowBridge)
{
	// 0064b12x:旧引擎非空 → deleteLater
	if (m_engine != nullptr) {
		m_engine->deleteLater();
		m_engine = nullptr;
	}
	// 0064b134:new QJSEngine,父链 = this(JsEngine)
	m_engine = new QJSEngine(this);
	// 0064b15a:installExtensions(All, undefined)
	m_engine->installExtensions(QJSEngine::AllExtensions,
	                            QJSValue(QJSValue::UndefinedValue));
	// 0064b1a8-0064b218:"King" 元对象注册 + 冻结
	QJSValue king = m_engine->newQMetaObject(
	    kingMeta ? kingMeta->metaObject() : nullptr);
	m_engine->globalObject().setProperty(QStringLiteral("King"), king);
	m_engine->evaluate(QStringLiteral("Object.freeze(King)"));
	// 0064b2ab-0064b2e2:"MuxPane" 元对象注册 + 冻结
	QJSValue pane = m_engine->newQMetaObject(
	    paneMeta ? paneMeta->metaObject() : nullptr);
	m_engine->globalObject().setProperty(QStringLiteral("MuxPane"), pane);
	m_engine->evaluate(QStringLiteral("Object.freeze(MuxPane)"));
	// 0064b3xx:"application" 桥
	if (appBridge != nullptr) {
		m_engine->globalObject().setProperty(
		    QStringLiteral("application"), m_engine->newQObject(appBridge));
		m_engine->evaluate(QStringLiteral("Object.freeze(application)"));
	}
	// 0064b4xx:"window" 桥
	if (windowBridge != nullptr) {
		m_engine->globalObject().setProperty(
		    QStringLiteral("window"), m_engine->newQObject(windowBridge));
		m_engine->evaluate(QStringLiteral("Object.freeze(window)"));
	}
}

// 0064abb2(809B):program = "'use strict'; () => { %1 }".arg(code)
// → evaluate → isError → tr 文本(0xc91268)…arg(lineNumber)…
// arg(正文);非 error 返空串(0020:29924-30006)
QString JsEngine::runScript(const QString &code)
{
	QJSValue r = m_engine->evaluate(
	    QStringLiteral("'use strict'; () => { %1 }").arg(code));
	if (!r.isError())
		return QString();
	// tr 文本批 69 取证:"Line %1: %2"(ASCII @0xc91268,LOAD1
	//   file = vaddr-0x400000;0xc91268 即字面首地址,NUL@0xc91274)
	//   → .arg(lineNumber).arg(正文)
	const int line = r.property(QStringLiteral("lineNumber")).toInt();
	return tr("Line %1: %2").arg(line).arg(r.toString());
}

// 0064af3c(348B):"'use strict';" + code → evaluate(0020:30070;
//   convertFromAscii 前缀 + UTF-16 memcpy = QString 拼接同构)
// 槽位勘正(批 68):program 走 rdx 槽(引擎 this = *(this+0x10)),
//   旧实现把 program 塞 fileName 槽 = 错位
QJSValue JsEngine::evaluateStrict(const QString &code)
{
	return m_engine->evaluate(QStringLiteral("'use strict';") + code);
}

// 0064ab5e(76B):undefined instance 承载 + callWithInstance
// (形参按调用者 0076745c 重构)
QJSValue JsEngine::call(const QString &name, const QJSValueList &args)
{
	return m_engine->globalObject().property(name).callWithInstance(
	    QJSValue(QJSValue::UndefinedValue), args);
}

// 0064b0be(18B):QJSEngine::newObject 直调
QJSValue JsEngine::newObject()
{
	return m_engine->newObject();
}

// 0064b0d0(41B):newQObject → setObjectOwnership(CppOwnership)
QJSValue JsEngine::newQObjectCppOwned(QObject *obj)
{
	QJSValue v = m_engine->newQObject(obj);
	QQmlEngine::setObjectOwnership(obj, QQmlEngine::CppOwnership);
	return v;
}
