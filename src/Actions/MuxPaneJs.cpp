#include "MuxPaneJs.h"

#include <QJSValue>
#include <QObject>

// 0064af3c(348B)—— 语料 evaluateStrict("use strict';" 前缀拼接;
// JsEngine 批 36 已转写同形)—— 此处直用 QJSEngine 等价调用,
// 拼接形见 JsEngine::evaluateStrict
static QJSValue evaluateStrictOn(QJSEngine *engine, const QString &name)
{
	// 语料:"Object.freeze(%1)".arg(obj) 拼于 name;此处 name 已
	// 为完整表达式串,前缀语义由调用方保证(见 bootstrap 内构造)
	return engine->evaluate(name,
	                        QStringLiteral("Object.freeze(%1)").arg(name));
}

MuxPaneJs::MuxPaneJs(QObject *pane)
	: m_pane(pane)
{
}

MuxPaneJs::~MuxPaneJs()
{
	// 语料:引擎随 pane 生命周期(+0x10 槽);QObject 父子管理
	// 由 new QJSEngine(pane) 达成,此处无额外拆除
}

void MuxPaneJs::bootstrap(QObject *kingMeta, QObject *muxPaneMeta,
                          QObject *applicationBridge, QObject *windowBridge)
{
	// 1) 旧引擎非空 → deleteLater(0064b12x)
	if (m_engine != nullptr) {
		m_engine->deleteLater();
		m_engine = nullptr;
	}
	// 2) new QJSEngine → +0x10(0064b134);父链挂 pane
	m_engine = new QJSEngine(m_pane);
	// 3) installExtensions(All, undefined)(0064b15a)
	m_engine->installExtensions(QJSEngine::AllExtensions,
	                            QJSValue(QJSValue::UndefinedValue));
	// 4) "King" 元对象注册 + 冻结(0064b1a8-0064b218)
	QJSValue king =
	    m_engine->newQMetaObject(kingMeta ? kingMeta->metaObject() : nullptr);
	m_engine->globalObject().setProperty(QStringLiteral("King"), king);
	m_engine->evaluate(QStringLiteral("Object.freeze(King)"));
	Q_UNUSED(evaluateStrictOn);
	// 5) "MuxPane" 元对象注册 + 冻结(0064b2ab-0064b2e2)
	QJSValue paneMeta = m_engine->newQMetaObject(
	    muxPaneMeta ? muxPaneMeta->metaObject() : nullptr);
	m_engine->globalObject().setProperty(QStringLiteral("MuxPane"),
	                                     paneMeta);
	m_engine->evaluate(QStringLiteral("Object.freeze(MuxPane)"));
	// 6) "application" 桥(0064b3xx 区:newQObject → setProperty →
	//    evaluate 冻结/初始化)
	if (applicationBridge != nullptr) {
		m_engine->globalObject().setProperty(
		    QStringLiteral("application"),
		    m_engine->newQObject(applicationBridge));
		m_engine->evaluate(QStringLiteral("Object.freeze(application)"));
	}
	// 7) "window" 桥(0064b4xx 区)
	if (windowBridge != nullptr) {
		m_engine->globalObject().setProperty(
		    QStringLiteral("window"),
		    m_engine->newQObject(windowBridge));
		m_engine->evaluate(QStringLiteral("Object.freeze(window)"));
	}
}
