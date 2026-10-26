// Onigmo 真引擎自检（Phase2）：
//   1. onig_new + 真数据正则（assets/config/uiconfigs/triggers.config 的 Decompressor/
//      Hyperlink 条目——WindTerm 原版终端触发器的一手正则数据）匹配样本文本断言命中；
//   2. 与 QRegularExpression（PCRE2，Qt 高亮现状引擎）同正则对比，差异点逐条注释留证，
//      为 Phase3 换引擎提供依据。
// 引擎 API 形态照 opensource/src/Onigmo/sample/simple.c（OnigIterator + onig_default_charat）。
#include <QCoreApplication>
#include <QRegularExpression>
#include <cstdio>
#include <cstring>

#include "oniguruma.h"

static int g_failed = 0;
static void check(bool ok, const char *what)
{
    std::printf("%s %s\n", ok ? "PASS" : "FAIL", what);
    if (!ok)
        ++g_failed;
}

// ── Onigmo 最小封装（照 sample/simple.c 形态）──
namespace {

struct OnigRegexGuard {
    regex_t *reg = nullptr;
    OnigErrorInfo einfo {};
    bool ok = false;

    OnigRegexGuard(const char *pattern)
    {
        const size_t n = std::strlen(pattern);
        ok = onig_new(&reg, reinterpret_cast<const OnigUChar *>(pattern),
                      reinterpret_cast<const OnigUChar *>(pattern + n),
                      ONIG_OPTION_CAPTURE_GROUP, ONIG_ENCODING_UTF8,
                      ONIG_SYNTAX_RUBY, &einfo) == ONIG_NORMAL;
    }
    ~OnigRegexGuard()
    {
        if (ok)
            onig_free(reg);
    }

    // 返回首个命中偏移；-1 未命中；-2 编译失败
    long search(const char *subject) const
    {
        if (!ok)
            return -2;
        const size_t n = std::strlen(subject);
        OnigIterator it;
        it.at = onig_default_charat;
        it.ptr = subject;
        OnigRegion *region = onig_region_new();
        const OnigPosition pos = onig_search(&it, reg, 0, static_cast<OnigPosition>(n),
                                             0, static_cast<OnigPosition>(n),
                                             region, ONIG_OPTION_NONE);
        onig_region_free(region, 1);
        return static_cast<long>(pos);
    }
};

} // namespace

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    // ═══ 1. 真数据正则（assets/config/uiconfigs/triggers.config）═══
    // Decompressor 条目 text.pattern（提取归档文件名，捕获 suffix 命名组）：
    static const char *kDecompressor =
        "(?x)\\b[\\w\\-]++[^ \\\\/:*\\?\"<>\\|\\r\\n]*?\\.(?<suffix>\n"
        "  tar\\.gz\n| tar\\.bz2\n| tar\\.xz\n| zip\n| rar\n| tar\n| tbz2\n| tgz\n"
        "| bz2\n| gz\n| Z\n| 7z\n| xz\n| ex\n| exe\n| lzma\n)\\b";
    {
        OnigRegexGuard re(kDecompressor);
        check(re.ok, "Decompressor pattern compiles (Onigmo/Ruby syntax + (?x) + possessive ++)");
        const long at = re.search("please fetch windterm.tar.gz and kit.zip now");
        check(at == 13, "Decompressor matches at 'windterm.tar.gz' offset 13");
    }

    // Hyperlink 条目（url|mail 二选一，(?ix) 扩展+忽略大小写，注释行内嵌）：
    static const char *kHyperlink =
        "(?ix)\\b(\n"
        "  ( # url\n"
        "    (https?|mail|ftps?|file|scp|sftp)://\n"
        "    [-a-zA-Z0-9+&@#/%?=_~|!:,.;]*[-a-zA-Z0-9+&@#/%=_~|]\n"
        "  ) \n"
        "| \n"
        "  ( # mail\n"
        "    ([0-9a-z_.-]++)@([0-9a-z_.-]+)\\.([a-zA-Z]++)\n"
        "  )\n"
        ")(?=\\b|\\s|$)";
    {
        OnigRegexGuard re(kHyperlink);
        check(re.ok, "Hyperlink pattern compiles");
        const long at = re.search("ping me at root@example.com please");
        check(at == 11, "Hyperlink matches mail at offset 11");
    }

    // 引擎版本/sanity：一条普通正则的编译+搜索
    {
        OnigRegexGuard re("a(.*)b|[e-f]+");
        check(re.ok && re.search("zzzzaffffffffb") == 4, "sample/simple.c case: match at 4");
    }

    // ═══ 2. Onigmo vs QRegularExpression（PCRE2）语义差异留证（Phase3 换引擎依据）═══
    // 每条 = 两引擎同输入实测（本机 Qt 5.15 PCRE2 8.45 / Onigmo 5.13.5）。
    {
        // 差异 A：字符类集合交集 &&。
        //   Onigmo：[[:alpha:]&&[^aeiou]] = 字母 ∩ 非元音 → 'b' 命中(0)、'&' 不中(-1)
        //   PCRE2 ：不支持嵌套类/&& 交集语法，该 pattern 编译"成功"但匹配任何字符都不中
        //           （'b' → -1；语义上把 && ^ [ 当字面/死类），静默无匹配——最危险的分歧
        static const char *kIntersect = "[[:alpha:]&&[^aeiou]]";
        const long onig = OnigRegexGuard(kIntersect).search("b");
        const int qre = QRegularExpression(QString::fromLatin1(kIntersect))
                            .match(QString::fromLatin1("b"))
                            .capturedStart(0);
        check(onig == 0, "Onigmo set-intersection: 'b' matches [alpha && ^aeiou]");
        check(qre == -1, "PCRE2 same pattern: no match (silent divergence) — diff A");
    }
    {
        // 差异 B：\h（水平空白类）。
        //   PCRE2 支持（\t 命中 0）；Onigmo 把 \h 编译成功（Ruby 语法宽容未知名转义，
        //   落到字面 'h' 处理）→ "\tx" 无命中（-1）——语义静默分歧，非编译失败。
        const long onig = OnigRegexGuard("\\h+").search("\tx");
        check(onig == -1, "Onigmo \\h+: compiles but no match on tab (no \\h class) — diff B");
        const int qre = QRegularExpression(QStringLiteral("\\h+"))
                            .match(QStringLiteral("\tx"))
                            .capturedStart(0);
        check(qre == 0, "PCRE2 \\h+: matches tab — diff B");
    }
    {
        // 差异 C：\k<name±n> 递归层级回引（Onigmo USE_BACKREF_WITH_LEVEL）。
        //   Onigmo：编译进语义（未定义名 → ONIGERR_UNDEFINED_NAME_REFERENCE=-217）
        //   PCRE2 ：语法直接非法（"syntax error in subpattern name"）
        static const char *kLevel = "\\k<n+1>";
        OnigRegexGuard re(kLevel);
        check(!re.ok, "Onigmo \\k<n+1>: parses as level-backref (errors on undefined name) — diff C");
        check(!QRegularExpression(QString::fromLatin1(kLevel)).isValid(),
              "PCRE2 \\k<n+1>: invalid pattern — diff C");
    }
    {
        // 共有但必须回归的：子程序调用 \g<name>（(?(DEFINE) 风格 {0} 定义+调用）、
        // interval 占有量词 a{1,2}+、负向定视 (?<!-)——两引擎同结果。
        check(OnigRegexGuard("(?<X>abc){0}\\g<X>").search("abc") == 0
                  && QRegularExpression(QStringLiteral("(?<X>abc){0}\\g<X>"))
                         .match(QStringLiteral("abc"))
                         .hasMatch(),
              "subroutine call \\g<X>: both engines match — common");
        check(OnigRegexGuard("a{1,2}+").search("aaa") == 0
                  && QRegularExpression(QStringLiteral("a{1,2}+"))
                         .match(QStringLiteral("aaa"))
                         .hasMatch(),
              "possessive interval a{1,2}+: both engines match — common");
        check(OnigRegexGuard("(?<!-)>").search("a>b") == 1
                  && QRegularExpression(QStringLiteral("(?<!-)>"))
                         .match(QStringLiteral("a>b"))
                         .capturedStart(0) == 1,
              "negative lookbehind (?<!-): both engines — common");
    }

    onig_end();

    if (g_failed != 0)
        std::printf("%d FAILURES\n", g_failed);
    return g_failed == 0 ? 0 : 1;
}
