#include "ActionFactory.h"

#include <QAction>
#include <QCoreApplication>
#include <QFile>
#include <QIcon>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJSValue>
#include <QVariant>
#include <json/json.h>
#include <memory>

// FUN_00668f3a(305B)—— cited — wave-2:按名调用包装。语料体:
//   arg 未定义 → FUN_00767d08(newObject)缓存 host+0x18;参数表
//   = [FUN_00767d2e(newQObject(param_4)), host+0x18/argval];
//   FUN_0076745c 按名调用;isError → undefined。宿主类 =
//   FUN_00665d8a qobject_cast(PTR_011a6c00,Phase 4c 面板层)——
//   待该类落地后以 QJSEngine 直调完成本函数
static QJSValue jsCallOnPane(QObject *target, const char *jsFuncName,
                             QAction *action, const QJSValue &arg)
{
	Q_UNUSED(target);
	Q_UNUSED(jsFuncName);
	Q_UNUSED(action);
	Q_UNUSED(arg);
	return QJSValue(QJSValue::UndefinedValue);
}

// 006697b2(2282B)—— 语料形(批 38 反汇编实证):param = (out,
// target,param_3 名串,param_4 QJSValue);体 = js_actionState
// (target,…)前置(00669834 前)→ target->property("data")
// (名串 @0x1182208 → "data",00669841)→ QAction* 门 → cast(00669890)
// → data() 脚本(006698ad/c2)→ metatype/canConvert 门 →
// FUN_00668f3a 调用(006699xx;依赖 MuxPane +0x48 QJSEngine 面)→
// 错误 setText 尾 → toVariant
void js_actionFire(QVariant &out, QObject *target, const char *jsFuncName,
                   const QJSValue &arg)
{
	// 00669086 前置(批 37 转写)
	js_actionState(target, jsFuncName);
	// property("data")(00669841 名@0x1182208)→ QAction* 门
	// (00669860 canConvert/00669890 cast)
	const QVariant dv = target->property("data");
	if (!dv.canConvert<QAction *>())
		return;
	QAction *linked = dv.value<QAction *>();
	if (linked == nullptr)
		return;
	// data() 脚本(006698ad/c2)+ metatype/canConvert 门(006698d8)
	const QVariant script = linked->data();
	if (!script.canConvert<QJSValue>())
		return;
	// FUN_00668f3a(006699xx 调用点):引擎宿主解析 = 语料
	// FUN_00665d8a(qobject_cast → PTR_011a6c00 类)—— 该类属
	// Phase 4c 面板层,未落地 → cited — wave-2(链接点在案,
	// paneHost 落地后本函数即活)
	QJSValue result = jsCallOnPane(target, jsFuncName, linked, arg);
	if (result.isError())
		return;                              // 语料 isError → undefined
	out = result.toVariant();                // 语料尾 toVariant
}

// 00669086(1739B):property("dynamic")→ QAction* 门 → 状态镜像。
// 语料锚:属性名 "dynamic"(指针 @0x11821e8,反汇编 6690a3 实证);
// QAction* metatype 一次注册(DAT_011c0b04,006693xx);第二读
// 0066911c(this = cast 后 linked);尾 setProperty 镜像 @006697xx。
void js_actionState(QObject *target, const char *propName)
{
	const QVariant v = target->property("dynamic");   // 006690b0 名@0x11821e8
	if (!v.canConvert<QAction *>())
		return;                                   // 语料 canConvert 门(006690cc)
	QAction *linked = v.value<QAction *>();
	if (linked == nullptr)
		return;                                   // 语料 QMetaObject::cast 门(006690f8)
	const QVariant st = linked->property(propName);   // 0066911c(this = cast 后)
	target->setProperty(propName, st);                // 尾镜像(006697xx)
}

// theme_icon_load_svg(00756cd6,1272B)—— cited — wave-2:主题
// SVG 装载(DAT_011c1ce0 主题容器),主题子系统另批转写
static QIcon theme_icon_load_svg(const QString &iconFile)
{
	// cited — wave-2(00756cd6 未转写;空图标,宁可留空也不猜)
	Q_UNUSED(iconFile);
	return QIcon();
}

ActionFactory::ActionFactory(QObject *parent)
	: QObject(parent)
{
}

// 00665dc2(856B):trim → 工厂表查 → 缺则建 QAction + setText(name)
// + connectImpl(triggered → 0066a148,functor 壳 0066b3a0)→ 插表
QAction *ActionFactory::getOrCreate(const QByteArray &name)
{
	const QByteArray trimmed = name.trimmed();   // 00665e5a trim 门
	if (trimmed.isEmpty())
		return nullptr;                          // 语料空名短路(00665e70 前置)
	const auto it = m_actions.constFind(trimmed);
	if (it != m_actions.constEnd())
		return *it;                              // 语料命中直返
	auto *action = new QAction(QString::fromUtf8(trimmed), this);
	action->setText(QString::fromUtf8(trimmed));   // 语料 QAction::setText(00665f98 区)
	// 语料 connectImpl(00665fea-006660f9):triggered → FUN_0066a148
	// (context = 工厂;functor 壳 0066b3a0)
	connect(action, &QAction::triggered, this, [this, action] {
		Q_UNUSED(this);
		// FUN_0066a148(103B):sender() → QAction cast → js_actionFire
		// (语料形:out, target, 名串, QJSValue;target = 触发上下文
		// 对象 —— decomp 歧义,转写批落位)
		QVariant result;
		js_actionFire(result, action, "state",
		              QJSValue(QJSValue::UndefinedValue));
		Q_UNUSED(result);
	});
	m_actions.insert(trimmed, action);             // 语料 QHash 插表(006660f9 区)
	return action;
}

// 0066613a(2882B):四键依序 script/icon/text/tooltip
void ActionFactory::applyEntry(QAction *action, const QVariantMap &entry)
{
	// "script"(006661f7 查键):toString().trimmed();空 → 禁用
	//   (006669e2),非空 → setData(QVariant(script))(006662c5)
	const QString script =
	    entry.value(QStringLiteral("script")).toString().trimmed();
	if (script.isEmpty())
		action->setEnabled(false);
	else
		action->setData(script);
	// "icon"(006662ef 查键):toString;非空(00666344 长度门)→
	//   theme_icon_load_svg → setIcon(00666399)+ setProperty
	//   ("iconFile",s)(006663e1)
	const QString icon = entry.value(QStringLiteral("icon")).toString();
	if (!icon.isEmpty()) {
		const QIcon loaded = theme_icon_load_svg(icon);   // cited — wave-2
		if (!loaded.isNull())
			action->setIcon(loaded);
		action->setProperty("iconFile", icon);
	}
	// "text"(00666436 查键):toString().trimmed().toUtf8() →
	//   QMetaObject::tr(QObject 上下文,00666491)→ setText(00666495 区)
	const QString text =
	    entry.value(QStringLiteral("text")).toString().trimmed();
	if (!text.isEmpty())
		action->setText(QObject::tr(text.toUtf8().constData()));
	// "tooltip"(00666564 查键):同 text 形 → setToolTip
	//   (006665a6-006665e0)
	const QString tooltip =
	    entry.value(QStringLiteral("tooltip")).toString().trimmed();
	if (!tooltip.isEmpty())
		action->setToolTip(QObject::tr(tooltip.toUtf8().constData()));
}

// 00667102(7702B):根 map 空守卫(+0x10)→ 迭代(key→toUtf8,
// value→toMap)→ FUN_0066613a
int ActionFactory::build(const QVariantMap &root)
{
	if (root.isEmpty())
		return 0;                          // 语料 +0x10==0 空守卫
	int n = 0;
	for (auto it = root.begin(); it != root.end(); ++it) {
		QVariantMap entry = it->toMap();   // 语料 QVariant::toMap
		QAction *action =
		    getOrCreate(it.key().toUtf8());   // 语料 key→toUtf8→工厂
		if (action == nullptr)
			continue;
		applyEntry(action, entry);
		++n;
	}
	return n;
}

// s_wind_actions_76b7c0(457B):文件装载入口(语料为 global+user
// 双源各调一次 wind_actions_build;此处单文件版,装载序随调用方)
int ActionFactory::loadActionsFile(const QString &path)
{
	QFile f(path);
	if (!f.open(QIODevice::ReadOnly))
		return 0;
	const QByteArray raw = f.readAll();
	// JSONC 容错解析(CTerminalConfig 同款 jsoncpp)
	Json::CharReaderBuilder b;
	std::unique_ptr<Json::CharReader> reader(b.newCharReader());
	Json::Value root;
	std::string errs;
	if (!reader->parse(raw.constData(), raw.constData() + raw.size(),
	                   &root, &errs))
		return 0;
	QVariantMap entries;
	for (auto it = root.begin(); it != root.end(); ++it) {
		// 语料 value→QVariant→toMap(保全 text/icon/tooltip 全字段)
		QVariantMap entry;
		const Json::Value &v = *it;
		for (auto f = v.begin(); f != v.end(); ++f)
			entry.insert(QString::fromStdString(f.key().asString()),
			             QString::fromStdString(
			                 (*f).isString() ? f->asString()
			                                 : f->toStyledString()));
		entries.insert(QString::fromStdString(it.key().asString()), entry);
	}
	return build(entries);
}
