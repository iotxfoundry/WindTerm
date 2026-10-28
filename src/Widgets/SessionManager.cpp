#include "SessionManager.h"

#include <QVariantMap>

SessionManager::SessionManager(QObject *parent)
	: QObject(parent)
{
}

QJsonObject SessionManager::toJsonObject(const QVariant &elem)
{
	// 会话元素:扁平点号键("session.uuid" 等)或嵌套 "session" 对象
	if (elem.canConvert<QJsonObject>())
		return elem.toJsonObject();
	const QVariantMap flat = elem.toMap();
	if (flat.contains("session.uuid"))
		return QJsonObject::fromVariantMap(flat);
	return QJsonObject::fromVariantMap(flat.value("session").toMap());
}

QString SessionManager::sessionGroup(const QJsonObject &elem)
{
	// s_session_group_805a3e (195B):"session.group" 默认 "";
	// 非空时 replace(配置 +0xc8 串)——替换源 Phase-4 cited
	return elem.value("session.group").toString();
}

QString SessionManager::sessionLabel(const QJsonObject &elem)
{
	// s_session_label_8062b6 (180B):"session.label" 默认 "";
	// 空则回退 s_session_target_8061a0(目标描述构建 — cited)
	return elem.value("session.label").toString();
}

QStandardItemModel *SessionManager::buildModel(const QVariant &filter)
{
	QStandardItemModel *model = new QStandardItemModel(this);
	for (const QVariant &elemVar : m_sessions) {
		const QJsonObject elem = toJsonObject(elemVar);
		const QString uuid = elem.value("session.uuid").toString();
		const QString iconKey = elem.value("session.icon").toString();
		const QString group = sessionGroup(elem);
		QString label = sessionLabel(elem);
		if (uuid.isEmpty() || label.isEmpty())
			continue;

		QIcon icon;   // 空 iconKey → 主题默认图标;否则 SVG 按 key 加载
		              // (FUN_0075727c / theme_icon_load_svg — Phase-4c cited)
		QString text = label;
		if (!group.isEmpty())
			text.prepend(QStringLiteral("%1 / ").arg(group));

		QStandardItem *item = new QStandardItem(icon, text);
		item->setData(uuid);                     // UserRole+1 携带 uuid
		const bool matched = filter.type() == QVariant::String
		                     && filter.toString() == uuid;   // FUN_0069a216 相等路径
		if (matched)
			item->setFlags(item->flags() & ~Qt::ItemIsEnabled);
		model->appendRow(item);
	}
	// view_connectModelReset(view, model, 1) + FUN_005d688e(view)
	// —— 视图挂接 — Phase-4c cited
	return model;
}
