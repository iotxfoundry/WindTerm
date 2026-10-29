// Spot check: width tables + charset registry + named-attribute keys
#include "Screen.h"
#include "TerminalCore.h"
#include "CTerminalConfig.h"
#include <QFile>
#include <cstdio>

int main()
{
	// widthFromTables (FUN_007a4692 semantics): ASCII 1, combining 0,
	// CJK 2, emoji 2, PUA 1
	Screen s;
	struct { unsigned cp; int want; } w[] = {
		{ 'A', 1 }, { 0x300, 0 }, { 0x4e00, 2 }, { 0x1f004, 2 },
		{ 0xe000, 1 }, { 0x1f1e6, 2 }, { 0x200b, 0 },
	};
	int fails = 0;
	for (auto &t : w) {
		const int got = s.widthFromTables(t.cp);
		printf("width U+%04X -> %d (want %d)%s\n", t.cp, got, t.want,
		       got == t.want ? "" : "  FAIL");
		fails += got != t.want;
	}
	// charsetLookup: "B"/false -> 2 (ASCII); "A"/false -> 8; "A"/true -> 23
	struct { const char *n; bool s96; int want; } c[] = {
		{ "B", false, 2 }, { "A", false, 8 }, { "A", true, 23 },
		{ "R", false, 11 }, { "%5", false, 6 }, { "M", true, 25 },
	};
	for (auto &t : c) {
		const int got = s.charsetLookup(QString::fromLatin1(t.n), t.s96);
		printf("charset \"%s\" set96=%d -> %d (want %d)%s\n", t.n, t.s96,
		       got, t.want, got == t.want ? "" : "  FAIL");
		fails += got != t.want;
	}
	// named-attribute keys vs binary constants (verified earlier)
	Screen s2;
	printf("attrKey  = %llx (want dca26230091f1ca6)%s\n",
	       (unsigned long long)s2.attrKey(),
	       s2.attrKey() == 0xdca26230091f1ca6ULL ? "" : "  FAIL");
	fails += s2.attrKey() != 0xdca26230091f1ca6ULL;
	printf("confKey  = %llx (want 5b3b8ddd279e6bf4)%s\n",
	       (unsigned long long)s2.conformanceKey(),
	       s2.conformanceKey() == 0x5b3b8ddd279e6bf4ULL ? "" : "  FAIL");
	fails += s2.conformanceKey() != 0x5b3b8ddd279e6bf4ULL;
	// resizeCore: 24x80 build, dims + default tabstops every 8th
	TerminalCore core;
	core.resizeCore(24, 80);
	printf("resize 24x80 -> rows=%d cols=%d%s\n", core.rowCount(),
	       core.columnCount(),
	       (core.rowCount() == 24 && core.columnCount() == 80) ? "" : "  FAIL");
	fails += !(core.rowCount() == 24 && core.columnCount() == 80);
	for (int c = 0; c < 80; c += 8) {
		if (!core.isTabstop(c)) { printf("tabstop %d missing FAIL\n", c); ++fails; }
		if (c + 1 < 80 && core.isTabstop(c + 1)) {
			printf("tabstop %d unexpectedly set FAIL\n", c + 1); ++fails;
		}
	}
	printf("tabstops every-8th OK\n");
	// CTerminalConfig: load the real wind.config (JSONC) and spot keys
	CTerminalConfig::instance()->setConfigPath(
	    QStringLiteral("/opt/WindTerm_2.7.0/global/wind.config"));
	const QVariant tab = CTerminalConfig::instance()->value(QStringLiteral("text.tabSize"));
	printf("config text.tabSize = %lld (want 4)%s\n", (long long)tab.toLongLong(),
	       tab.toLongLong() == 4 ? "" : "  FAIL");
	fails += tab.toLongLong() != 4;
	const QVariant lang = CTerminalConfig::instance()->value(QStringLiteral("application.language"));
	printf("config application.language = \"%s\" (want auto)%s\n",
	       lang.toString().toUtf8().constData(),
	       lang.toString() == QLatin1String("auto") ? "" : "  FAIL");
	fails += lang.toString() != QLatin1String("auto");
	const QVariant missing = CTerminalConfig::instance()->value(
	    QStringLiteral("no.such.key"), QVariant(123));
	printf("config missing-key default = %lld (want 123)%s\n", (long long)missing.toLongLong(),
	       missing.toLongLong() == 123 ? "" : "  FAIL");
	fails += missing.toLongLong() != 123;
	// 覆写层:用户 user.config 同名键覆盖基线(wind.config → user.config)
	{
		const QString overridePath = QStringLiteral("/tmp/opencode/recheck_user.config");
		QFile ov(overridePath);
		ov.open(QIODevice::WriteOnly | QIODevice::Truncate);
		ov.write("{\n  \"text.tabSize\": 8,\n  \"user.only.key\": \"on\"\n}\n");
		ov.close();
		CTerminalConfig::instance()->setOverridePath(overridePath);
		const QVariant t8 = CTerminalConfig::instance()->value(QStringLiteral("text.tabSize"));
		printf("config override text.tabSize = %lld (want 8)%s\n", (long long)t8.toLongLong(),
		       t8.toLongLong() == 8 ? "" : "  FAIL");
		fails += t8.toLongLong() != 8;
		const QVariant lang2 = CTerminalConfig::instance()->value(QStringLiteral("application.language"));
		fails += lang2.toString() != QLatin1String("auto");   // 基线键不被覆写层清除
		if (lang2.toString() != QLatin1String("auto"))
			printf("config baseline key after override FAIL\n");
		else
			printf("config baseline key survives override OK\n");
		const QVariant ukey = CTerminalConfig::instance()->value(QStringLiteral("user.only.key"));
		fails += ukey.toString() != QLatin1String("on");
		printf("config user-only key = \"%s\" (want on)%s\n", ukey.toString().toUtf8().constData(),
		       ukey.toString() == QLatin1String("on") ? "" : "  FAIL");
		CTerminalConfig::instance()->setOverridePath(QString());   // 还原单层
	}
	printf(fails ? "RESULT: %d FAILS\n" : "RESULT: ALL PASS\n", fails);
	return fails != 0;
}
