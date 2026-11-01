// runstyles 行为测试批(runstylesUpgrade 迁移分支 + bankCtorK3 + rsFill/rsValue 闭环;
// MarkersStore.h 批 72 现状)。铁律 5:断言语料行为,每条断言带语料锚;逐条手工写。
// 被测面(全头内 inline):bankCtorK3(FUN_009cc22c)/runstylesUpgrade(FUN_009cd554)/
// mkLayer(LAB_009cd775)/rsFill8/16/32(007b7290/007b8000 ≡ RunStyles::FillRange
// RunStyles.cxx:132)/rsValue8/16/32(0088ff00/007b6dd0/007b7b70)。
// RS 模板实例化在预构建 scintilla_core.a(RunStyles.cxx:310-311)→ 链接经 WindTermRe。
// 批 86:值迁移腿六函数已转写(migrateLayer 参数化单体 + migU* 六入口;六体全读 0032.c
//   69181/69265/69501/69585/69669/69753)→ 迁移分支断言翻转:旧槽清零(*param_2=0)/
//   旧层+旧 holder 析构/旧值逐位搬新层/返回值=灌值腿 changed(铁律 5:断言语料行为)。
#include "MarkersStore.h"
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
	// ======== a. bankCtorK3(FUN_009cc22c;initDoc 009a3107 唯一调用点;K3 → Skip u8)====
	{
		wt::ValueTable bank{};                               // 裸内存零化语境(operator_new 0x40)
		wt::RsHolder20 *h = wt::makeHolder0x20(new RS8());   // 009a2ed7 形(u8 层包装)
		wt::bankCtorK3(&bank, h);
		expect(bank.kind == 3, "a: K3 kind==3(009cc22c *p=kind)");
		expect(bank.delegate == h, "a: K3 delegate==rs(+0x08)");
		expect(bank.holders[3] == h, "a: K3 holders[3]==rs(自身路 Skip u8)");
		expect(bank.holders[0] == nullptr && bank.holders[1] == nullptr
		       && bank.holders[2] == nullptr && bank.holders[4] == nullptr
		       && bank.holders[5] == nullptr,
		       "a: K3 其余槽全 0(009cc22c 字面)");
	}

	// ======== b. runstylesUpgrade Skip 梯(FUN_009cd554 case3/4;initDoc 形 kind=3)====
	{
		wt::ValueTable bank{};
		RS8 *rs8 = new RS8();
		rs8->InsertSpace(0, 16);                     // 上游语义:先扩 Length(FillRange 端界判 :138)
		wt::RsHolder20 *h3 = wt::makeHolder0x20(rs8);
		wt::bankCtorK3(&bank, h3);
		// b1 直灌腿:v<0x100 → Uint8SkipRunStyles_h962e10(0032:68227),kind 不迁
		expect(wt::runstylesUpgrade(&bank, 2, 0x7f, 4) == true,
		       "b1: v<0x100 直灌 u8 → true(灌值腿 changed)");
		expect(bank.kind == 3, "b1: 直灌腿 kind 不迁(仍 3)");
		expect(wt::rsValue8(h3->rs, 2) == 0x7f && wt::rsValue8(h3->rs, 5) == 0x7f,
		       "b1: u8 层读回(0088ff00 委托)");
		// b2 判式下边界 v==0x100 → mkU16S(009cebe6 ctor;迁移 009cf0b0 真身)
		const bool r2 = wt::runstylesUpgrade(&bank, 4, 0x100, 2);
		expect(bank.kind == 4, "b2: v==0x100 → kind 3→4(mkU16S)");
		expect(bank.holders[4] != nullptr && bank.holders[4] != h3,
		       "b2: holders[4] 新建(mkLayer LAB_009cd775)");
		expect(bank.holders[3] == nullptr,
		       "b2: 旧槽清零(009cf0b0 尾 *param_2=0,0032:69264)+ 旧 holder 析构 —— 批 86 迁移落地翻转");
		expect(bank.delegate == bank.holders[4], "b2: delegate=新层(LAB_009cd775 字面)");
		// q5:迁移腿不返回 true,返回值=灌值腿结果;迁移保值后新层 Length=旧层 16 →
		// FillRange [4,6)=0x100 changed → true(批 86 翻转;q5 语义不变)。
		expect(r2 == true,
		       "b2: 返回值=灌值腿(q5);迁移扩层后灌值 changed → true");
		void *rsP = *reinterpret_cast<void *const *>(
		    reinterpret_cast<const char *>(bank.holders[4]) + 0x10);  // holder→RS 解引(rsOf 同形)
		expect(wt::rsValue16(rsP, 4) == 0x100,
		       "b2: 触发值落新层 [4,6)=0x100(灌值腿委托 FillRange;holders[4] 经 +0x10 解引)");
		expect(wt::rsValue16(rsP, 2) == 0x7f,
		       "b2: 旧值随迁移保留(pos2 0x7f 搬入 u16 层,009cee86 ⑤逐位搬运)—— 批 86 断言翻转");
		// b3 判式上边界 v==0x10000 → mkU32S(009cf400 ctor;迁移 009cfae6 真身)
		wt::runstylesUpgrade(&bank, 6, 0x10000, 2);
		expect(bank.kind == 5, "b3: v==0x10000 → kind 4→5(mkU32S)");
		expect(bank.holders[3] == nullptr && bank.holders[4] == nullptr
		       && bank.holders[5] != nullptr,
		       "b3: 逐层迁移旧槽清零(*param_2=0 逐腿字面;值已在 5 层)—— 批 86 翻转");
		expect(bank.delegate == bank.holders[5], "b3: delegate=holders[5]");
	}

	// ======== bp. plain 梯(kind0/1/2;语料 case0/1/2 同构;产品 initDoc 仅 K3,夹具态)====
	{
		wt::ValueTable bank{};
		RS8 *rs8 = new RS8();
		rs8->InsertSpace(0, 16);
		wt::RsHolder20 *h0 = wt::makeHolder0x20(rs8);
		bank.kind = 0; bank.delegate = h0; bank.holders[0] = h0;   // plain u8(夹具)
		expect(wt::runstylesUpgrade(&bank, 0, 0xff, 1) == true,
		       "bp: kind0 v<0x100 直灌 u8(gapbuffer 密排路,委托 RS8)");
		expect(wt::rsValue8(h0->rs, 0) == 0xff, "bp: u8 直灌读回");
		const bool r1 = wt::runstylesUpgrade(&bank, 1, 0xffff, 2);
		expect(bank.kind == 1, "bp: v==0xffff → kind 0→1(mkU16,009ceabe+009cee86 真身)");
		expect(bank.holders[1] != nullptr && bank.delegate == bank.holders[1],
		       "bp: holders[1]/delegate 换新(LAB_009cd775)");
		expect(bank.holders[0] == nullptr, "bp: 旧槽清零(*param_2=0,009cee86 尾字面;批 86 翻转)");
		expect(r1 == true, "bp: 迁移保值后灌值 [1,3)=0xffff changed → true(批 86 翻转)");
		{
			void *rsP1 = *reinterpret_cast<void *const *>(
			    reinterpret_cast<const char *>(bank.holders[1]) + 0x10);
			expect(wt::rsValue16(rsP1, 0) == 0xff,
			       "bp: 旧值随迁移保留(pos0 0xff 搬入 u16 层,009cee86 同构)");
		}
		wt::runstylesUpgrade(&bank, 1, 0x10000, 1);
		expect(bank.kind == 2, "bp: kind1 v≥0x10000 → kind 1→2(mkU32,009cf69e 真身)");
		expect(bank.holders[2] != nullptr && bank.delegate == bank.holders[2],
		       "bp: holders[2]/delegate 换新");
	}

	// ======== c. 灌值腿(委托面语义 FUN_007b8000 ≡ FillRange)+ 迁移保值腿(批 86 真身)====
	//   直灌腿真值(委托 FillRange changed/读回)+ 迁移腿断言:旧槽清零/旧值搬新层
	//   (铁律 5:断言语料行为;批 86 断言翻转落定)。
	{
		wt::ValueTable bank{};
		RS8 *rs8 = new RS8();
		rs8->InsertSpace(0, 16);
		wt::RsHolder20 *h3 = wt::makeHolder0x20(rs8);
		wt::bankCtorK3(&bank, h3);
		expect(wt::runstylesUpgrade(&bank, 0, 0x42, 4) == true, "c: 升宽前 u8 灌值 true");
		expect(wt::rsValue8(h3->rs, 3) == 0x42, "c: 旧值在 u8 层(升宽前)");
		wt::runstylesUpgrade(&bank, 8, 0x100, 1);            // 触发 3→4(迁移真身 009cf0b0)
		expect(bank.holders[3] == nullptr,
		       "c: 旧槽清零(009cf0b0 尾 *param_2=0)+ 旧 holder 析构 —— 批 86 翻转");
		void *rsP4 = *reinterpret_cast<void *const *>(
		    reinterpret_cast<const char *>(bank.holders[4]) + 0x10);  // holder→RS 解引(rsOf 同形)
		expect(wt::rsValue16(rsP4, 3) == 0x42,
		       "c: 旧值随迁移保留(pos3 0x42 搬入 u16 层,009cf0b0 ⑤逐位搬运)—— 批 86 断言翻转");
		expect(wt::rsValue16(rsP4, 8) == 0x100,
		       "c: 触发值落新层 [8,9)=0x100(灌值腿委托 FillRange)");

		// 直灌腿真值:kind2 u32 层 Length 预扩(夹具侧上游 InsertSpace 语义)
		wt::ValueTable b2{};
		RS32 *rs32 = new RS32();
		rs32->InsertSpace(0, 8);
		wt::RsHolder20 *hc = wt::makeHolder0x20(rs32);
		b2.kind = 2; b2.delegate = hc; b2.holders[2] = hc;   // plain u32(夹具)
		expect(wt::runstylesUpgrade(&b2, 1, 0x12345678, 3) == true,
		       "c: kind2 直灌 changed=true(FUN_007b8000 ≡ FillRange)");
		expect(wt::rsValue32(rs32, 1) == 0x12345678
		       && wt::rsValue32(rs32, 3) == 0x12345678, "c: u32 直灌读回(委托面)");
		expect(wt::runstylesUpgrade(&b2, 1, 0x12345678, 3) == false,
		       "c: 同值重写 trim → false(委托 FillRange :146-148;"
		       "语料合并吸收逐值同相性=登记点 MarkersStore.h:157)");
	}

	// ======== d. rsFill/rsValue 三宽度写读闭环(0088ff00/007b6dd0/007b7b70)====
	{
		wt::RsHolder20 *h8 = wt::makeHolder0x20(new RS8());
		static_cast<RS8 *>(h8->rs)->InsertSpace(0, 8);
		expect(wt::rsFill8(h8, 2, 0xab, 4), "d: rsFill8 写入 true");
		expect(wt::rsValue8(h8->rs, 2) == 0xab && wt::rsValue8(h8->rs, 5) == 0xab,
		       "d: u8 读回@2/@5");
		expect(wt::rsValue8(h8->rs, 6) == 0, "d: run 内 gap → 0(Length 内零值)");
		expect(wt::rsFill8(h8, 0, 0xff, 1), "d: u8 上界 0xff 写入");
		expect(wt::rsValue8(h8->rs, 0) == 0xff, "d: u8 0xff 读回");
		expect(wt::rsValue8(h8->rs, -1) == 0, "d: 负 pos → 0(DAT_011c1edc 族)");
		expect(wt::rsValue8(h8->rs, 8) == 0, "d: 越界 → 0");

		wt::RsHolder20 *h16 = wt::makeHolder0x20(new RS16());
		static_cast<RS16 *>(h16->rs)->InsertSpace(0, 8);
		expect(wt::rsFill16(h16, 0, 0xffff, 3), "d: u16 0xffff 写入 true");
		expect(wt::rsValue16(h16->rs, 0) == 0xffff && wt::rsValue16(h16->rs, 2) == 0xffff,
		       "d: u16 读回@0/@2");
		expect(wt::rsValue16(h16->rs, 3) == 0, "d: u16 未灌区 → 0");

		wt::RsHolder20 *h32 = wt::makeHolder0x20(new RS32());
		static_cast<RS32 *>(h32->rs)->InsertSpace(0, 8);
		expect(wt::rsFill32(h32, 1, 0xffffffffu, 2), "d: u32 0xffffffff 写入 true");
		expect(wt::rsValue32(h32->rs, 1) == 0xffffffffu,
		       "d: u32 0xffffffff 位型读回(u32 窄存 int,位型等价 mk3 §7)");
		expect(wt::rsValue32(h32->rs, 3) == 0, "d: u32 出 run → 0");
		expect(!wt::rsFill32(h32, 0, 1, 0), "d: len=0 → false(FillRange :134 no-op)");
	}

	// ======== e. 空壳态守卫(!rs/!holder/kind≥6 → 0/false 不崩)====
	{
		expect(wt::rsValue8(nullptr, 0) == 0, "e: rsValue8 !rs → 0(壳期守卫)");
		expect(wt::rsValue16(nullptr, 0) == 0, "e: rsValue16 !rs → 0");
		expect(wt::rsValue32(nullptr, 0) == 0, "e: rsValue32 !rs → 0");
		expect(!wt::rsFill8(nullptr, 0, 1, 1), "e: rsFill8 !holder → false");
		expect(!wt::rsFill16(nullptr, 0, 1, 1), "e: rsFill16 !holder → false");
		expect(!wt::rsFill32(nullptr, 0, 1, 1), "e: rsFill32 !holder → false");
		// holderRs(nullptr) 解引 null+0x10 必 SIGSEGV —— 无意义断言,批 85 删
		{
			wt::RsHolder20 *he = wt::makeHolder0x20(new RS8());  // 空表(Length 0)
			expect(wt::rsValue8(he->rs, 0) == 0, "e: 空表读 → 0(pos≥Length)");
			expect(!wt::rsFill8(he, 0, 1, 1), "e: 空表灌 → false(端界判 :138)");
		}
		expect(wt::MarkersStore::runValueWordAt(nullptr, 0) == 0,
		       "e: runvector 壳期守卫 !b → 0");
		{
			wt::ValueTable bank{};
			bank.kind = 6;
			expect(wt::MarkersStore::runValueWordAt(&bank, 0) == 0,
			       "e: kind≥6 取值 → 0(009cd3da 尾)");
			expect(!wt::runstylesUpgrade(&bank, 0, 1, 1),
			       "e: kind≥6 upgrade → false(default 腿)");
		}
	}

	printf("fail=%d\n", g_fail);
	return g_fail == 0 ? 0 : 1;
}
