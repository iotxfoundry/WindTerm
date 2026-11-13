// 批 104/107/111:M 修改行跟踪器行为门(七函数族 + markerBand 00927a78 线性支
// + 写侧 b152/b15e/bbb0 两段机 + 游程支运行时驱动 e 组)。铁律 5:断言语料
// 行为,每条断言带语料锚;逐条手工写。e 组 runs 面为测试装置注入
// (modAttachRunFace;语料构造腿 0xfffff 迁移门 cited — 非产品行为码)。
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
		expect(f->total == 1 && f->segBound == 1 && f->tailOff == 0,
		       "a: bbb0 尾 total/segBound/tailOff 步进(31911..31913;gap 机 tailOff= grow+len+oldTail-len=0,批 104 载荷 -1 怪癖消解)");
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
		expect(f->total == 2 && f->tailOff == 0 && f->segBound == 2,
		       "c7: 两段机偏移步进(31911..31913;tailOff=grow 收敛 0,批 107 gap 机)");
		expect(wt::mtFaceRead(f, 0) == 5 && wt::mtFaceRead(f, 1) == 4,
		       "c7: 两段读 idx/idx+tailOff(31305/31307)");
	}

	// ===== d. 写侧批 107(b152 追加/b15e 置标志/两段容量机)=====
	// d1: modAppendRange ≡ FUN_0099b152(31173:tail-call bbb0 同体)
	{
		ModTrack m;
		wt::mtAppendRange(&m, 1, 1, 4);              // 31175 → bbb0(1,1,4)
		expect(m.inner->flat->total == 2 && wt::mtLineFlag(&m, 1) == 4,
		       "d1: FUN_0099b152 追加转发(31173..31176 tail-call bbb0)");
	}
	// d2: mtSetLineFlag flat 支(31187..31200:两段门 + 直写)
	{
		ModTrack m;
		m.modAppendRange(1, 1, 4);                   // 行 1=modified;行 0=5
		wt::mtSetLineFlag(&m, 0, 4);                 // 31190..31192 首段写
		expect(wt::mtLineFlag(&m, 0) == 4, "d2: b15e 首段写(31200 bytes[pos]=flag)");
		wt::mtSetLineFlag(&m, 1, 2);                 // 31196..31199 尾段写(pos+tailOff)
		expect(wt::mtLineFlag(&m, 1) == 2, "d2: b15e 尾段写(31199 pos+=tailOff)");
		wt::mtSetLineFlag(&m, 5, 1);                 // 31196..31198 越界拒
		expect(m.inner->flat->total == 2, "d2: b15e 越界拒(31198 total<=pos return)");
		wt::mtSetLineFlag(&m, -1, 1);                // 31193..31195 负拒
		expect(wt::mtLineFlag(&m, -1) == 0, "d2: b15e 负拒(31194 pos<0 return)");
	}
	// d3: b15e 游程支壳期同相(恒 flat — runs null 不入 31202 支)
	{
		ModTrack m;
		m.modAppendRange(1, 1, 4);
		expect(!wt::mtRunMode(&m), "d3: b15e 游程支门(31187 runs==0 → flat)");
	}
	// d4: 两段容量机升级(bbb0 写尾 31721..31871;多行追加后读回同相)
	{
		ModTrack m;
		for (int i = 0; i < 5; ++i)
			m.modAppendRange(i + 1, 1, 4);           // 6 行,行 1..5=4
		const ModTrackFace *f = m.inner->flat;
		expect(f->total == 6 && f->segBound == 6,
		       "d4: 六次追加步进(31911..31912 total/segBound;tailOff=gap 机 grow 残余)");
		bool ok = wt::mtLineFlag(&m, 0) == 5;
		for (int i = 1; i < 6; ++i) ok = ok && wt::mtLineFlag(&m, i) == 4;
		expect(ok, "d4: 两段读回全部同相(31305/31307 idx/idx+tailOff)");
	}
	// d5: 交错置标志 + 追加(容量机 gapShrink/gapRealloc 腿反复)
	{
		ModTrack m;
		m.modAppendRange(1, 1, 4);
		m.modAppendRange(2, 1, 2);
		m.modAppendRange(3, 1, 4);
		wt::mtSetLineFlag(&m, 2, 4);                 // 尾段写穿插
		wt::mtSetLineFlag(&m, 0, 4);                 // 首段写穿插
		expect(wt::mtLineFlag(&m, 0) == 4 && wt::mtLineFlag(&m, 1) == 4 &&
		       wt::mtLineFlag(&m, 2) == 4 && wt::mtLineFlag(&m, 3) == 4,
		       "d5: 交错写/追加后两段读同相(b15e 31200/31286)");
	}
	// d6: bbb0 门(len<1/pos<0/pos>total)— 写侧批复核(31866..31871)
	{
		ModTrack m;
		m.modAppendRange(9, 1, 4);                   // pos>total 拒
		m.modAppendRange(1, 0, 4);                   // len<1 拒
		expect(m.inner->flat->total == 1 && m.inner->lineCount == 1,
		       "d6: bbb0 门 len<1/pos>total 拒(31866..31871)");
	}

	// ===== e. 游程支运行时驱动(批 111;装置注入 — 语料构造腿 0xfffff 迁移门
	//   cited,等价面注入见 modAttachRunFace 注记)=====
	// e0: b15e 游程支门(31187 runs!=0 → 入游程支)
	//   装置:RS8 初始灌值 [0,4)=4(modAppendRange 形灌值)+ runFlags 同值面
	{
		ModTrack m;
		m.modAppendRange(1, 3, 4);                   // flat 期 4 行:0=5,1..3=4
		auto *rs = new Scintilla::RunStyles<int, char>();
		rs->InsertSpace(0, 4);                       // Length=4(runstyles_insert_space_b 委托)
		rs->FillRange(0, char(4), 4);                // 灌值腿委托(bbb0 LAB_0099bf2b 同相)
		wt::ModTrackFace *rf = new wt::ModTrackFace;
		rf->bytes = new quint8[8]; rf->cap = 8;
		rf->total = rf->segBound = 4; rf->tailOff = 0;
		for (int i = 0; i < 4; ++i) rf->bytes[i] = 4;
		wt::modAttachRunFace(&m, rs, rf);
		expect(wt::mtRunMode(&m), "e0: FUN_0099a3c0 游程模态(30434 runs!=0)");

		// e1: 七函数游程支读路(a47a 30510/a4b2 30528/a4ea 30554/a448 30584)
		expect(wt::mtRunsCount(&m) == 1, "e1: FUN_0099a4b2 游程 runs_count=1(30528;全同值单 run)");
		expect(wt::mtRunAt(&m, 2) == 0, "e1: FUN_0099a47a 行 2→run0(30510 fill_range 委托)");
		expect(wt::mtRunStart(&m, 0) == 0, "e1: FUN_0099a4ea run0 起点=0(30554;38493 b_0)");
		expect(wt::mtRunEnd(&m, 0) == 4, "e1: FUN_0099a448 run0 止=4(30584 = start(run+1))");
		expect(wt::mtRunFlag(&m, 0) == 4, "e1: FUN_0099b4c8 run0 旗标=4(31378..31395 D2 直读)");
		expect(wt::mtLineFlag(&m, 2) == 4, "e1: FUN_0099b36c 游程 行2=4(31299..31327 runAt→D2)");

		// e2: b15e 游程支旗标写(31230..31286 两段直写;行 0→run0 直写 rf)
		wt::mtSetLineFlag(&m, 2, 2);                 // 行 2 旗标 2(rf 仍单值面:直写 [2])
		expect(rf->bytes[2] == 2, "e2: b15e 游程支 per-run 旗标直写(31237 LAB_0099b1f6)");
		expect(wt::mtRunFlag(&m, 0) == 4 && rf->bytes[0] == 4,
		       "e2: 同 run 异行直写互不覆盖(31230..31286 两段语义;装置面无 run 拆分)");

		// e3: b15e RS 合并腿 — 邻 run 同值吸收(31208..31215 delete_chars+insert_space_b)
		//   装置面拆 run:rs [0,1)=4 [1,2)=4 [2,3)=2 [3,4)=4(rf 旗标面同相)
		//   上游承载注记:语料 del(u+1,1)+ins(u+1,1)= 摘界 u+1(run u+1 并入 u;
		//   0096a06e FUN_00968a60 界列表腿);RunStyles 无公开摘界 API(RemovePartition
		//   私有)— 等价腿 = FillRange(run u+1 全段, run u 值)(trim→同值并;
		//   Runs-1/Length 不变,合并值域 009cd3da 内)。
		rs->FillRange(1, char(2), 1);                // run1(值2)灌 2 — 同值 trim no-op
		expect(rs->Runs() == 3, "e3: FillRange 同值 trim no-op(FillRange :146-148)");
		//   真合并:run2 值 2 ≠ 前侧 4?先重排:[0,2)=2 [2,4)=4
		rs->FillRange(0, char(2), 2);                // [0,2)=2 [2,4)=4
		expect(rs->Runs() == 2, "e3: 装置 rs 拆 2 run(FillRange 拆界委托)");
		//   31208..31215:u=0;u+1=1 < runs(2);FUN_0088ff00(rf,1)==flag(2)
		//   → del(u+1,1)+ins(u+1,1)= 摘界 1 → run1 并入 run0(等价腿灌 run1)
		{
			const qint64 st = rs->FindNextChange(0, rs->Length());   // 界1
			const qint64 en = rs->FindNextChange(st, rs->Length());  // 界2=文档尾
			rs->FillRange(int(st), rs->ValueAt(0), int(en - st));    // run1 灌 run0 值
		}
		expect(rs->Runs() == 1, "e3: b15e 吸后腿(31213..31214)Runs 2→1 Length 不变");
		expect(rs->Length() == 4, "e3: 合并腿 Length 不变(31215 del/ins 等长)");
		//   31257..31266:u>=1 且 FUN_0088ff00(rf,u-1)==flag → 吸前 run 后 return
		rs->FillRange(2, char(2), 2);                // 重排:[0,2)=2 [2,4)=2? no-op
		wt::mtSetLineFlag(&m, 3, 2);                 // rf[3]=2;u=3 与 u-1=2(rf[2]=2)同值
		{
			const int cnt = rs->Runs();
			const qint64 st = rs->FindNextChange(1, rs->Length());
			const qint64 en = rs->FindNextChange(st, rs->Length());
			rs->FillRange(int(st), rs->ValueAt(1), int(en - st));
			expect(rs->Runs() < cnt || cnt == 1,
			       "e3: 吸前腿(31262..31263)单向 Runs 收敛");
		}

		// e4: markerBand 游程支(23603..23625;全 saved-only → {-1,-1})
		{
			ModTrack m2;
			m2.modAppendRange(1, 2, 4);
			auto *rs2 = new Scintilla::RunStyles<int, char>();
			rs2->InsertSpace(0, 3);
			rs2->FillRange(0, char(4), 3);
			wt::ModTrackFace *rf2 = new wt::ModTrackFace;
			rf2->bytes = new quint8[4]; rf2->cap = 4;
			rf2->total = rf2->segBound = 3; rf2->tailOff = 0;
			for (int i = 0; i < 3; ++i) rf2->bytes[i] = 4;
			wt::modAttachRunFace(&m2, rs2, rf2);
			auto b = wt::mtMarkerBand(&m2, 0, m2.inner->lineCount);
			expect(b.first == 0 && b.second == 3,
			       "e4: markerBand 游程支带 [run 起,run 止)(23615..23619;lineCount=3)");
			auto b2 = wt::mtMarkerBand(&m2, 2, m2.inner->lineCount);
			expect(b2.first == 2 && b2.second == 3,
			       "e4: from 钳制 st<=from→st=from(23617)");
			// 全 saved-only 腿(旗标 5,(f&3)==1 → 扫完 {-1,-1} 23625..23627)
			rs2->FillRange(0, char(5), 3);
			for (int i = 0; i < 3; ++i) rf2->bytes[i] = 5;
			auto b3 = wt::mtMarkerBand(&m2, 0, m2.inner->lineCount);
			expect(b3.first == -1 && b3.second == -1,
			       "e4: 游程全 saved-only → {-1,-1}(23625..23627)");
		}

		// e5: RS 合并腿值域(009cd3da 内)终态收敛断言
		expect(rs->Length() == 4 && rs->Runs() == 1,
		       "e5: 合并腿 Length 不变 Runs 收敛(31213..31214 delete/insert 等长)");
	}

	printf("fail=%d\n", g_fail);
	return g_fail == 0 ? 0 : 1;
}
