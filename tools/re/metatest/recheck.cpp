// Spot check: width tables + charset registry + named-attribute keys
#include "Screen.h"
#include "TerminalCore.h"
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
	printf(fails ? "RESULT: %d FAILS\n" : "RESULT: ALL PASS\n", fails);
	return fails != 0;
}
