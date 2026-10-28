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

class CTerminalConfig
{
public:
	static CTerminalConfig *instance();   // FUN_00809d78

	void setConfigPath(const QString &path);   // wind.config 位置
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
	QString m_defaultPrompt = QStringLiteral(">");
	QRegularExpression m_trimRegex;
	bool m_loaded = false;
};

#endif // CTERMINALCONFIG_H
