// 键码双向编解码行为测试批(keymapKeyForward/Reverse 真身,批 79)
// 铁律 5:断言语料行为,每条断言带语料锚;逐条手工写。
// 语料:FUN_00674206(正)/ FUN_00674b1e(反),decomp-part-0020.c 61673-62282。
// 表 DAT_011c1960 = 进程内全局惰性表,用例顺序即状态序(空表断言排最前;
// 反向未命中会占槽,顺序不可重排)。parseAngleNotation(keysParseAngleNotation
// 00674cdc)为 SuperKeymap.cpp 内 static,无公共入口 → 本批停手,见报告。
#include "SuperKeymap.h"
#include <cstdio>

static int g_fail = 0;
static void expect(bool ok, const char *name)
{
	printf("%s: %s\n", ok ? "OK" : "FAIL", name);
	if (!ok)
		g_fail++;
}

int main()
{
	// ======== a. forward 透传:(int)code < 0xff → 原样(61685)========
	expect(keymapKeyForward(0) == 0, "a: forward 0 透传(61685)");
	expect(keymapKeyForward(0xfe) == 0xfe, "a: forward 0xfe 透传(61685)");

	// ======== b. forward 空表越界:槽序 = code-0xff(61688)≥ size →
	//             0x1ffffff(61690 门;须先于任何 reverse 未命中占槽)========
	expect(keymapKeyForward(0xff) == 0x1ffffff,
	       "b: forward 0xff 空表槽序 0 越界 → 0x1ffffff(61688/61690)");
	expect(keymapKeyForward(0xabcdef) == 0x1ffffff,
	       "b: forward 0xabcdef 空表越界 → 0x1ffffff(61690)");
	expect(keymapKeyForward(0x1ffffffu) == 0x1ffffff,
	       "b: forward 0x1ffffff → 0x1ffffff(61690 门原值不变)");

	// ======== c. reverse 透传:key < 0xff → 原样(62187)========
	expect(keymapKeyReverse(0xfe) == 0xfe, "c: reverse 0xfe 透传(62187)");

	// ======== d. reverse 0x1ffffff → 0xffff(62190)========
	expect(keymapKeyReverse(0x1ffffff) == 0xffff,
	       "d: reverse 0x1ffffff → 0xffff(62190)");

	// ======== e. reverse 未命中占槽:append 槽表 + trie 插 →
	//             槽序 0 + 0xff(62272/62275/62276)========
	expect(keymapKeyReverse(0x1234) == 0xff,
	       "e: reverse 0x1234 首占槽 0 → 0xff(62272-62276)");

	// ======== f. reverse 命中:entry 值 + 0xff,不占新槽(62281)========
	expect(keymapKeyReverse(0x1234) == 0xff,
	       "f: reverse 0x1234 再调命中槽 0 → 0xff(62281)");

	// ======== g. reverse 新键续槽:槽序 1 → 0x100(62272-62276)========
	expect(keymapKeyReverse(0x5678) == 0x100,
	       "g: reverse 0x5678 新键占槽 1 → 0x100(62272-62276)");

	// ======== h. 闭环:forward(槽值)读回原键(61694 槽表读;槽序 =
	//             reverse 返回 - 0xff)========
	expect(keymapKeyForward(0xff) == 0x1234,
	       "h: forward(0xff) 闭环读回 0x1234(61694)");
	expect(keymapKeyForward(0x100) == 0x5678,
	       "h: forward(0x100) 闭环读回 0x5678(61694)");
	expect(keymapKeyForward(0x102) == 0x1ffffff,
	       "h: forward 空槽 idx 2 越界 → 0x1ffffff(61690)");

	// ======== i. reverse 槽表饱和门:槽表 ≥ 0xff00 → 0xffff(62270);
	//             先灌满至 0xff00 槽(键域 0x60000+i,避开已有/哨兵)========
	for (int i = 0; i < 0xff00 - 2; ++i)
		keymapKeyReverse(0x60000 + i);
	expect(keymapKeyReverse(0x70000) == 0xffff,
	       "i: 槽表满 0xff00 → reverse 未命中返 0xffff(62270 门)");
	expect(keymapKeyReverse(0x70001) == 0xffff,
	       "i: 饱和后门持续 → 0xffff(62270 门)");

	// ======== j. 饱和后正侧不变式:既有槽读回稳定 + 越界哨兵不变 ========
	expect(keymapKeyForward(0xff) == 0x1234,
	       "j: 饱和后 forward(0xff) 槽 0 读回稳定(61694)");
	expect(keymapKeyForward(0xff + 0xff00) == 0x1ffffff,
	       "j: forward 槽序恰 0xff00 越界 → 0x1ffffff(61690)");

	printf("fail=%d\n", g_fail);
	return g_fail == 0 ? 0 : 1;
}
