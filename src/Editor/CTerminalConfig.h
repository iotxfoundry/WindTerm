#ifndef CTERMINALCONFIG_H
#define CTERMINALCONFIG_H

#pragma once

// Reconstructed from WindTerm 2.7.0 (SESSION-CONFIG-LAYER.md ①):
// DAT_011c2200 = the terminal-config singleton. FUN_00809d78 (121B) is
// the Meyers accessor (guard + __cxa_atexit dtor FUN_0080a0ba); the
// ctor FUN_00809b90 (432B) sets the vtable, the default prompt ">",
// a prompt-trim regex "^\\s++|\\s++(?=%1)|(?<=%1)\\s++|\\s++$" over
// QRegularExpression::escape(">"), and the 0x128 protocol/grammar
// table (FUN_00860b30). 199 use sites read dotted keys
// ("application.language", "text.tabSize", "terminal.*", ...).
// wind.config is JSON-with-comments (JSONC) — parsed with the
// vendored jsoncpp 1.9.4.

#include <QMap>
#include <QRegularExpression>
#include <QString>
#include <QVariant>

#include "CGlobalConfigFace.h"

// 批 142 双 Meyers 合一形态:CTerminalConfig 私有继承 CTerminalConfigFace
// (组合/包装形态 — 不发明虚继承树;语料 = 基构造 + vtable 换写,即
// CTerminalConfig IS-A CGlobalConfig,这里以 face 私有基承载同一事实)。
// 值面(m_values 族,SESSION-CONFIG-LAYER 先批)与容器面(+0x28/+0x60
// handler、+0xa8 entries)共存于同一对象,menu() 容器 = 单例本体。
class CTerminalConfig : private CTerminalConfigFace
{
public:
	static CTerminalConfig *instance();   // FUN_00809d78

	// 批 142 双 Meyers 合一(KITWINDOW-RECON §未解 1 收口):语料
	// CTerminalConfig 单例对象 IS-A CGlobalConfig 基(两 ctor 首句同
	// FUN_008a71e4,CGlobalConfigFace.h 头注)→ 值面单例私有继承
	// CTerminalConfigFace,face() 返回同一对象的 face 面(menu() 容器 =
	// 值面单例本体,FUN_00858fce/DAT_011c2200 同址语义)。
	static class CTerminalConfigFace *face();

	// wind.config 位置(空 = appdir/global/wind.config 全局默认层自动层,
	// 批 150;显式注入 = 测试/宿主缝优先 — setConfigPath 契约保持)
	void setConfigPath(const QString &path);
	void setOverridePath(const QString &path);   // user.config 覆写层(CONFIG-SCHEMAS 装载顺序)
	void reload();
	QVariant value(const QString &key, const QVariant &defaultValue = QVariant()) const;
	bool contains(const QString &key) const { return m_values.contains(key); }
	void setValue(const QString &key, const QVariant &value);   // SuperSession::setOption 下层

	// 批 169:FUN_008cbb2e(242B,0028.c:12894)现役 setter face 键面
	// (toLower + 剥 "kit." 前缀,760b2c @00760b86/bf1)→ 值面写。
	void setValueKitScoped(const QByteArray &key, const QVariant &value);
	// 批 169:s_kit_startupSessions_6e6e75(340B,0022.c:12550)写端
	// 三态单选钮腿(逐钮 isChecked 序:首钮→"SpecificSessions"/
	// 次钮→"NoSessions"/末钮→"LastSessions")。
	void setStartupSessions(bool specificChecked, bool noSessionsChecked,
	                        bool lastChecked);

	// ctor defaults (FUN_00809b90)
	QString defaultPrompt() const { return m_defaultPrompt; }
	const QRegularExpression &promptTrimRegex() const { return m_trimRegex; }

private:
	CTerminalConfig();

	QVariantMap m_values;   // dotted key -> value
	QString m_configPath;
	QString m_overridePath;   // user.config 覆写层(空 = 不叠加)
	QString m_defaultPrompt = QStringLiteral(">");
	QRegularExpression m_trimRegex;
	bool m_loaded = false;
};

#endif // CTERMINALCONFIG_H
