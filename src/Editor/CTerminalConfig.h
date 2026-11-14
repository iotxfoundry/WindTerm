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

	void setConfigPath(const QString &path);   // wind.config 位置
	void setOverridePath(const QString &path);   // user.config 覆写层(CONFIG-SCHEMAS 装载顺序)
	void reload();
	QVariant value(const QString &key, const QVariant &defaultValue = QVariant()) const;
	bool contains(const QString &key) const { return m_values.contains(key); }
	void setValue(const QString &key, const QVariant &value);   // SuperSession::setOption 下层

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
