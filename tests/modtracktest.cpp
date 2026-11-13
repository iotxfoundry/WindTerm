// 批 104:M 修改行跟踪器行为门(七函数族 + markerBand 00927a78 线性支)
// 铁律 5:断言语料行为,每条断言带语料锚;逐条手工写。游程支(wt 侧 run 迁移
// 写腿未落地)仅测 flat 路径语义 — 与语料 flat 分支同相。
#include "ModTrack.h"
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
	using wt::ModTrack;
	using wt::ModTrackFace;

	// ===== a. ctor 链(00929fab..00929fe1:b142(,5)→ b07a → bbb0(0,1,5))=====
	// 旗标 5 = bit0|bit2(bit0=saved);(f&3)==1 → saved-only = skip 带
	{
		ModTrack m;
		expect(m.inner != nullptr && m.inner->flat != nullptr && !wt::mtRunMode(&m),
		       "a: ctor 建 flat 面(0099b142(,5)→0099b07a)");
		expect(m.inner->lineCount == 1, "a: bbb0 头 *(inner+8)+=1(0032.c:31718)");
		ModTrackFace *f = m.inner->flat;
		expect(f->total == 1 && f->segBound == 1 && f->tailOff == -1,
		       "a: bbb0 尾 total/segBound/tailOff 步进(0032.c:31911..31913)");
		expect(f->bytes[0] == 5, "a: 首行旗标 = 5(bbb0 memset 腿 0032.c:31906)");

		// a3c0 模态(0032.c:30434):inner+0x10 == 0 → flat
		expect(!wt::mtRunMode(&m), "a: FUN_0099a3c0 flat 模态(30434)");

		// 行标志读(0099b36c flat 支 31298..31308)
		expect(wt::mtLineFlag(&m, 0) == 5, "a: FUN_0099b36c(0)=5(31305 首段读)");
		// 越界 → 0(31306..31308;idx>=total)
		expect(wt::mtLineFlag(&m, 1) == 0, "a: FUN_0099b36c 越界=0(31308)");
		// 负 idx → 0(31304 语料字面)
		expect(wt::mtLineFlag(&m, -1) == 0, "a: FUN_0099b36c 负 idx=0(31304)");
	}

	// ===== b. bbb0 追加腿(31866..31913 门+步进;语料可直推语义)=====
	// 门:len<1 / pos<0 / pos>total → no-op
	{
		ModTrack m;   // total=1
		m.modAppendRange(2, 1, 1);   // pos(2) > total(1) → 拒
		expect(m.inner->flat->total == 1, "b: 追加门 pos>total 拒(31868..31871)");
		m.modAppendRange(1, 1, 2);   // 追行 1,旗标 2
		expect(m.inner->flat->total == 2 && m.inner->lineCount == 2,
		       "b: 追加步进 total/lineCount(31718/31911)");
		expect(wt::mtLineFlag(&m, 1) == 2, "b: 行 1 旗标读回(31305)");
		m.modAppendRange(-1, 1, 2);  // 负 pos 拒(31867)
		expect(m.inner->flat->total == 2, "b: 追加门 pos<0 拒(31866..31867)");
	}

	// ===== c. markerBand 00927a78 线性支(0030.c:23572..23601)=====
	// c1:全 skip(旗标 5,(f&3)==1)→ 扫完无带 {-1,-1}(23625..23627)
	{
		ModTrack m;   // 1 行旗标 5
		auto b = wt::mtMarkerBand(&m, 0, m.inner->lineCount);
		expect(b.first == -1 && b.second == -1,
		       "c1: 空日志(全 saved-only)→ {-1,-1}(23625..23627)");
	}
	// c2:单行 modified(旗标 4 = bit2,(f&3)!=1 开带)→ [line,line+1)
	{
		ModTrack m;
		m.modAppendRange(1, 1, 4);   // 行 1 = modified
		quint8 saved = 0, unsaved = 0;
		auto b = wt::mtMarkerBand(&m, 0, m.inner->lineCount, &saved, &unsaved);
		expect(b.first == 1 && b.second == 2,
		       "c2: 单行标志 → [line,line+1)(23589/23599 半开收尾)");
		expect(saved == 0 && unsaved == 0,
		       "c2: saved=f&1/unsaved=(f>>1)&1 出参(23586..23587)");
	}
	// c3:from >= lineCount 门 → {-1,-1}(23566)
	{
		ModTrack m;
		auto b = wt::mtMarkerBand(&m, 5, m.inner->lineCount);
		expect(b.first == -1 && b.second == -1,
		       "c3: from>=行数 → {-1,-1}(23566 param_2<FUN_00925570 门)");
	}
	// c4:多行同旗标连带(23577..23593 do-while:值同 → en 延至断点/文档尾)
	{
		ModTrack m;
		m.modAppendRange(1, 2, 4);   // 行 1,2 = modified(行 0 = 5 skip)
		auto b = wt::mtMarkerBand(&m, 0, m.inner->lineCount);
		expect(b.first == 1 && b.second == 3,
		       "c4: 两行同旗标 → [1,3)(23581 en 延 + 23599 收尾)");
	}
	// c5:旗标变 → 带断(23580 v!=band → goto 收尾)
	{
		ModTrack m;
		m.modAppendRange(1, 1, 2);   // 行 1 unsaved
		m.modAppendRange(2, 1, 4);   // 行 2 modified
		auto b = wt::mtMarkerBand(&m, 0, m.inner->lineCount);
		expect(b.first == 1 && b.second == 2,
		       "c5: 旗标变带断 → [1,2)(23580 v!=band)");
		quint8 saved = 0, unsaved = 0;
		auto b2 = wt::mtMarkerBand(&m, b.second, m.inner->lineCount, &saved, &unsaved);
		expect(b2.first == 2 && b2.second == 3 && saved == 0 && unsaved == 0,
		       "c5: 次带续扫 → [2,3) 旗标4 → unsaved=(4>>1)&1=0");
	}
	// c6:七函数 flat 直通(a47a/a4b2/a4ea/a448 30505/30524/30549/30580)
	{
		ModTrack m;
		m.modAppendRange(1, 1, 4);
		expect(wt::mtRunAt(&m, 7) == 7, "c6: FUN_0099a47a flat 直通(30505)");
		expect(wt::mtRunsCount(&m) == 2, "c6: FUN_0099a4b2 flat=*(doc+0x14)(30524)");
		expect(wt::mtRunStart(&m, 3) == 3, "c6: FUN_0099a4ea flat 直通(30549)");
		expect(wt::mtRunEnd(&m, 3) == 3, "c6: FUN_0099a448 flat 直通(30580)");
		expect(wt::mtRunFlag(&m, 0) == 5, "c6: FUN_0099b4c8 flat 直读(31373..31376)");
	}
	// c7:两段读(bbb0 追加腿后 segBound/total/tailOff 语义 — 31304..31308)
	{
		ModTrack m;
		m.modAppendRange(1, 1, 4);
		ModTrackFace *f = m.inner->flat;
		expect(f->total == 2 && f->tailOff == -2 && f->segBound == 2,
		       "c7: 两段机偏移步进(31911..31913)");
		expect(wt::mtFaceRead(f, 0) == 5 && wt::mtFaceRead(f, 1) == 4,
		       "c7: 两段读 idx/idx+tailOff(31305/31307)");
	}

	printf("fail=%d\n", g_fail);
	return g_fail == 0 ? 0 : 1;
}
