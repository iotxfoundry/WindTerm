#ifndef PROFILELOADER_H
#define PROFILELOADER_H

#pragma once

// 工作区 profile 装载(~/.wind/profiles/<name>/):
//   terminal/user.sessions  会话数组(FUN_00806904 路径拼接;
//   FUN_00806958 = saveSessions:config_saveFile("/user.sessions", +0xe0))
//   terminal/session.config 等 = 扁平键配置
// 格式为带注释/容错的 JSON(与 wind.config 同族,QUIRKS:数组元素
// 逗号缺失也被原解析器容忍)。

#include <QVariantList>
#include <QVariantMap>

class ProfileLoader
{
public:
	static QString defaultProfilePath();   // ~/.wind/profiles/default.v10

	explicit ProfileLoader(QString profilePath = defaultProfilePath());

	void setProfilePath(const QString &path) { m_profilePath = path; }
	QString profilePath() const { return m_profilePath; }

	QVariantList loadSessions() const;                  // terminal/user.sessions
	bool saveSessions(const QVariantList &sessions) const;  // FUN_00806958 对偶
	QVariantMap loadConfig(const QString &relPath) const;   // 任意 profile 内 JSON

private:
	QString m_profilePath;
};

#endif // PROFILELOADER_H
