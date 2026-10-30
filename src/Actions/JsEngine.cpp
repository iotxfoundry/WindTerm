#include "JsEngine.h"

JsEngine::JsEngine(QObject *parent)
	: QObject(parent)
{
}

// 0064abb2(809B):字面 "'use strict'; () => { %1 }" → QString::arg
// (param_3)→ QJSEngine::evaluate(ret, program, name)
QJSValue JsEngine::evaluateArrow(const QString &program, const QString &name)
{
	const QString wrapped =
	    QStringLiteral("'use strict'; () => { %1 }").arg(name);
	// 语料槽位:evaluate(ret, program=@param+0x10, name=包装串)
	// —— Ghidra 槽位歧义,标注不猜改
	return m_engine.evaluate(program, wrapped);
}

// 0064af3c(348B):分配 len(name)+0xd → convertFromAscii
// ("'use strict';",0xd)前缀 + name memcpy(×2 字节)→ resize →
// QJSEngine::evaluate(ret, program, 拼接串)
QJSValue JsEngine::evaluateStrict(const QString &program, const QString &name)
{
	const QString strict = QStringLiteral("'use strict';") + name;
	// 语料槽位同上(标注不猜改)
	return m_engine.evaluate(program, strict);
}

// 0064b0be(18B):QJSEngine::newObject
QJSValue JsEngine::newObject()
{
	return m_engine.newObject();
}

// 0064b0d0(41B):QJSEngine::newQObject
QJSValue JsEngine::newQObject(QObject *obj)
{
	return m_engine.newQObject(obj);
}
