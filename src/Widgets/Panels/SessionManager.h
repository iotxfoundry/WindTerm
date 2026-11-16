#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#pragma once

// 会话面板模型构建(重建 s_session_uuid_6f571a,927B):
// 从会话数组逐项取 "session.uuid"/"session.icon"/"session.group"/
// "session.label",组装 QStandardItemModel;uuid 存 item 数据
// (UserRole+1),文本 = "group / label"(group 空则仅 label),
// 过滤命中项禁用(flag bit1)。会话数组来源为运行期工作区
// (~/.wind/profiles),经 setSessions 注入。

#include <QJsonObject>
#include <QStandardItemModel>
#include <QVariantList>

class SessionManager : public QObject
{
	Q_OBJECT

public:
	explicit SessionManager(QObject *parent = nullptr);

	void setSessions(const QVariantList &sessions) { m_sessions = sessions; }
	const QVariantList &sessions() const { return m_sessions; }

	// s_session_uuid_6f571a:filter 命中的 uuid 项被禁用
	// (FUN_0069a216(item-filter, uuid, 1));图标加载
	// (FUN_0075727c/theme_icon_load_svg)与视图挂接
	// (view_connectModelReset/FUN_005d688e)— Phase-4c cited。
	QStandardItemModel *buildModel(const QVariant &filter = {});

	static QString sessionGroup(const QJsonObject &elem);   // s_session_group_805a3e
	static QString sessionLabel(const QJsonObject &elem);   // s_session_label_8062b6
	static QJsonObject toJsonObject(const QVariant &elem);

private:
	QVariantList m_sessions;
};

#endif // SESSIONMANAGER_H
