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

// js_actionFire(006697b2,2282B)—— cited — wave-2:语料体在案,
// 下一批逐行转写(触发链 FUN_0066a148 的执行位;签名按 0066a148
// 调用形,转写落位时定稿)
QVariant js_actionFire(QAction *action, const QJSValue &arg);

QVariant js_actionFire(QAction *action, const QJSValue &arg)
{
	// cited — wave-2(006697b2 未转写;空实现,宁可留空也不猜)
	Q_UNUSED(action);
	Q_UNUSED(arg);
	return QVariant();
}

// 00669086(1739B):property("dynamic")→ QAction* 门 → 状态镜像。
// 语料锚:属性名 "dynamic"(指针 @0x11821e8,反汇编 6690a3 实证);
// QAction* metatype 一次注册(DAT_011c0b04,006693xx);第二读
// 0066911c(this = cast 后 linked);尾 setProperty 镜像 @006697xx。
void js_actionState(QAction *action, const char *propName)
{
	const QVariant v = action->property("dynamic");
	if (!v.canConvert<QAction *>())
		return;                                   // 语料 canConvert 门
	QAction *linked = v.value<QAction *>();
	if (linked == nullptr)
		return;                                   // 语料 QMetaObject::cast 门(006690f8)
	const QVariant st = linked->property(propName);   // 0066911c
	action->setProperty(propName, st);                // 尾镜像(006697xx)
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
		QVariant result = js_actionFire(action, QJSValue(QJSValue::UndefinedValue));
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
