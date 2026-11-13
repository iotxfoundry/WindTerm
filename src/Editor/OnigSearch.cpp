#include "OnigSearch.h"

// 批 116:0x4eff 引擎腿激活(EXT-BOUNDARY 委托 — 批 102 勘定)。铁律 1
// 出处:语料 = FUN_00b422d0(2750B 缓冲扫描引擎,decomp-part-0037.c:32598,
// Onigmo-改 ≈onig_search)/ 编译栈 = 00a81655 → 00a9c780(22512B 编译本体,
// 6 参 = regex** 出参改返回值 + 无 encoding 形参 — 批 109 改版差异登记)/
// 惰性编译门 = 00ad7360(304B,产物挂对象 +0x20 槽)/ free face =
// 00aa1f80(5B free 尾调用,批 110)/ alloc face = 00aa1f70(malloc)。
// 委托形态:上游 onig_new(7 参,regcomp.c:5941)+ onig_search(regexec.c:
// 3905)。语法假设 ONIG_SYNTAX_RUBY:CALIBRATION 批 116 五样例对账定案
// (possessive ++ / \g<X> 子例程调用同时覆盖 → RUBY 唯一候选;Java 无
// ESC_G_SUBEXP_CALL regsyntax.c:162-182,Perl 同)。编码 UTF-8(0xd35f40
// ASCII 折叠表 + \x{...} 样例域;批 110)。字节承载替 = OnigIterator
// {onig_default_charat, ptr}(regexec.c:4375:*(ptr+pos)— 字节直读同构)。

namespace OnigSearch {

// —— 主题承载缝(setSubject 面;.cpp 文件级 static,登记承载替)——
static const char *s_sub = nullptr;
static qint64     s_subLen = 0;

static UChar charat(OnigPosition pos, const void *ptr)
{
	return onig_default_charat(pos, ptr);        // regexec.c:4375 直通
}

void setSubject(const char *bytes, qint64 len)
{
	s_sub = bytes;
	s_subLen = len;
}

void clearSubject()
{
	s_sub = nullptr;
	s_subLen = 0;
}

OnigRegex compile(const char *pat, int len, bool ignoreCase, int *errOut)
{
	OnigErrorInfo einfo;
	OnigRegex re = nullptr;
	const OnigOptionType opt = ignoreCase ? ONIG_OPTION_IGNORECASE
	                                      : ONIG_OPTION_NONE;
	// onig_new(regcomp.c:5941)上游 7 参形态;RUBY 语法 + UTF-8
	// (批 116 假设行,CALIBRATION 登记)。
	const int r = onig_new(&re, (const OnigUChar *)pat,
	                       (const OnigUChar *)(pat + len), opt,
	                       ONIG_ENCODING_UTF8, ONIG_SYNTAX_RUBY, &einfo);
	if (errOut)
		*errOut = r;
	if (r != ONIG_NORMAL)                       // 失败体内部已 free+置 null
		return nullptr;                         //   (regcomp.c:5955-5958)
	return re;
}

qint64 search(OnigRegex re, qint64 from, qint64 to)
{
	if (re == nullptr || s_sub == nullptr)
		return -1;                              // 门:00a83946 *param_2 同相
	OnigIterator it;                            // testc.c:92 构形
	it.at = charat;
	it.ptr = s_sub;
	OnigRegion *region = onig_region_new();     // oniguruma.h:847
	const OnigPosition r = onig_search(&it, re, 0, s_subLen,
	    from, to, region, ONIG_OPTION_NONE);    // regexec.c:3905
	qint64 hit = -1;
	if (r != ONIG_MISMATCH && region->num_regs > 0)  // ONIG_BADPOS ≡ -1 契约
		hit = (qint64)r;                        // 绝对字节位(region->beg[0] 同值)
	onig_region_free(region, 1);                // oniguruma.h:851
	return hit;
}

void freeRegex(OnigRegex re)
{
	if (re != nullptr)
		onig_free(re);                          // regcomp.c 释放面;00aa1f80 face 同效
}

// —— 惰性编译单槽(00ad7360 产物挂 +0x20 槽承载同相;换 pattern 释旧)——
static OnigRegex s_cached = nullptr;
static QByteArray s_cachedPat;
static bool s_cachedCase = false;

qint64 bufferScan(const char *pat, int len, bool ignoreCase,
                  qint64 from, qint64 to)
{
	if (pat == nullptr || len <= 0)
		return -1;                              // 门:00a83946 *param_2!=0 逆臂同相
	if (!s_cachedPat.isEmpty() && s_cachedCase == ignoreCase
	    && s_cachedPat.size() == len
	    && memcmp(s_cachedPat.constData(), pat, (size_t)len) == 0) {
		// 命中缓存(批 109:编译时机 = 各上游调用点惰性;缓存语义同相)
	} else {
		if (s_cached != nullptr) {
			freeRegex(s_cached);                // 换 pattern 释旧
			s_cached = nullptr;
			s_cachedPat = QByteArray();
		}
		int err = 0;
		s_cached = compile(pat, len, ignoreCase, &err);
		if (s_cached == nullptr)
			return -1;                          // 编译败 → 恒未命中(契约)
		s_cachedPat = QByteArray(pat, len);
		s_cachedCase = ignoreCase;
	}
	return search(s_cached, from, to);
}

} // namespace OnigSearch
