// 批 160(M17-③):DeepEngineFace ODR 定义 — 调面声明接实现体。
// 判例链:批 156 底座头(DeepEngineFace.h 声明层)/ 批 111 深引擎
// 分段判例(改版底座不在库 → 可读段真身、密排/正则腿 cited)。
// 语料地址均为 Ghidra 基址;逐行出处标注。
#include "DeepEngineFace.h"
#include <QThread>
#include <sched.h>
#include <errno.h>
#include <stdexcept>
#include <time.h>

#include <cstring>
#include <cstdlib>

namespace wt {

// 97142a(123B)@0031.c:45510 — 尾真身面:970850 调面早退门/尾槽清零消费。
//   语料 44940 调 93fc60 后 puVar8[5]=0(44993)/[2]=0(44995,= f10 槽)/
//   mask(44996)— 我方 lexStackClear 尾 5347 清零同槽。
// FUN_0097142a(123B @0031.c:45510)全读 — 尾真身(批 164 升真):
//   45516 (+0x28)+1 / 45518-45521 ptA D1 / 45522 清零 / 45523-45527 ptB D1 /
//   45528-45531 piecetable_init(0x60) / 45534 runstyles_insert_space_b
//   (深引擎灌链 cited — RS 插空委托面不在承载)/ 45535 (+8)=1。
void tail97142a(SkipPartition50 *sp, quint64 seed)
{
	sp->seedCnt28 = sp->seedCnt28 + 1;            // 45516 [5]+1
	if (sp->ptA != nullptr)                       // 45518 (**ptA+8)() D1 虚链
		delete static_cast<RS8 *>(sp->ptA);       //   承载 = RS8(97142a ptA=RS 槽 45523 重建写面同族)
	sp->ptA = nullptr;                            // 45522
	if (sp->ptB != nullptr)                       // 45523
		delete static_cast<RS8 *>(sp->ptB);
	sp->ptB = nullptr;                            // 45527
	PieceTable60 *pt = new PieceTable60{};        // 45528 operator_new(0x60)
	pieceTableInit(pt, seed);                     // 45530-45531
	sp->ptB = pt;                                 // 45532
	// 45534 runstyles_insert_space_b(*(sp+0x20),0,*(+0x10)*2>>1) — cited
	//   (RS 灌链深引擎;RS8 InsertSpace 值面委托 = 45536 调面同族,批 152 #35)
	sp->flag08 = 1;                               // 45535 (+8)=1
}

// --- 批 164:vt 槽承载(DeepEngineFace.h 声明面落定义)---
// 00889860/00889872(18B 同体 @0027.c:39335/39347):runstyles_runs_count
//   (param_1+8)尾调面 — 承载 = RS8::Runs()(怪癖 #35 同物异计;恒等
//   检查对象 = 具名槽指针)。
qint64 lexDelegateRuns00889872(void *self)
{
	LexDelegate20 *d = static_cast<LexDelegate20 *>(self);
	if (d->rs == nullptr)                        // 39349 *(param_1+8) 解引面;
		return 0;                                //   空 RS 壳态防御同相(ENodes 判例)
	return qint64(static_cast<RS8 *>(d->rs)->Runs());
}
// Uint8RunStyles_vt14(96B @0027.c:39381 字面):换面 vt13 + RS D1(vt+8)
//   + GB free(+8)/delete 0x20 + 本体 operator_delete 0x20。
void lexDelegateDtor008898d0(void *self)
{
	LexDelegate20 *d = static_cast<LexDelegate20 *>(self);
	if (d == nullptr)
		return;
	d->vtbl = nullptr;                           // 39384 → &PTR_vt13(承载 = cited)
	if (d->rs != nullptr)                        // 39385-39387 (**rs+8)() D1
		delete static_cast<RS8 *>(d->rs);        //   承载 = RS8 dtor(RunStyles
	d->rs = nullptr;                             //   39390 清零)
	if (d->gb != nullptr) {                      // 39391-39394
		free(static_cast<GB20 *>(d->gb)->data);  // 39392 free(*(gb+8))
		delete static_cast<GB20 *>(d->gb);       // 39393 operator_delete(gb,0x20)
		d->gb = nullptr;                         // 39394 清零
	}
	delete d;                                    // 39396 operator_delete(self,0x20)
}
// 恒等检查槽定义(5262 CMP 0x889872 / 5311 CMP vt14 — kuna asm 判例;
//   语料 CMP 立即数 = .text 地址,我方 = 具名函数指针同一)。
qint64 (*lexVtRunsSlot)(void *) = &lexDelegateRuns00889872;   // vt+0x30
void   (*lexVtDtorSlot)(void *) = &lexDelegateDtor008898d0;   // vt+8

// 条目释放臂(5301-5304 逐字面):~RWLock(+0x20)/free(+8)/delete 0x30
void cacheEntryRelease(void *ent)
{
	CacheEntry30 *e = static_cast<CacheEntry30 *>(ent);
	e->~CacheEntry30();                          // 5301 ~QReadWriteLock(+0x20 就地)
	free(e->data);                               // 5302 free(*(ent+8))
	operator delete(e, sizeof(CacheEntry30));    // 5303 operator_delete(ent,0x30)
}

// gapbuf_shrink(95B @0027.c:39714)8B 版逐字面 — gap 位移动两臂
void gbShrink00889e2e(GB20 *g, int to)
{
	int gp = int(g->gapPos18);                   // 39717 *(g+0x18)
	if (to < gp) {                               // 39719 门
		memmove(reinterpret_cast<char *>(g->data) + to + g->gapLen1c,
		        reinterpret_cast<char *>(g->data) + to, size_t(gp - to));
		g->gapPos18 = quint32(to);               // 39722/39729
		return;
	}
	memmove(reinterpret_cast<char *>(g->data) + gp,
	        reinterpret_cast<char *>(g->data) + gp + g->gapLen1c,
	        size_t(to - gp));
	g->gapPos18 = quint32(to);                   // 39726
}

// FUN_0088a016(221B @0027.c:39819)realloc 扩容逐字面(8B 版;增长
//   步进 cap<0x2000001 ? cap>>1 : cap>>2,负长 runtime_error 面,43248/
//   43305/43403 调面)。
void gbGrow0088a016(GB20 *g, int grow)
{
	int cap = int(g->f10);                       // 39826 *(g+0x10)
	int step = cap < 0x2000001 ? cap >> 1 : cap >> 2;   // 39828-39831
	for (;;) {                                   // 39833 while(true)
		int want = cap + grow + step;            // 39835 iVar2+param_2+iVar3
		if (want < 1) {                          // 39836 负长门
			if (want != 0)                       // 39839 ==0 静默重来
				throw std::runtime_error(        // 39841-39845 字面
				    "GapBuffer::ReAllocate: negative size.");
		} else {
			void *p = realloc(g->data, size_t(want));   // 39848
			if (p != nullptr) {                  // 39849
				g->data = p;                     // 39850-39852
				g->f10 = quint32(want);
				int shift = step + grow + int(g->gapLen1c);   // 39853
				int gp = int(g->gapPos18);
				memmove(reinterpret_cast<char *>(p) + shift + gp,
				        reinterpret_cast<char *>(p) + int(g->gapLen1c) + gp,
				        size_t(int(g->len14) - gp));          // 39854-39855
				g->gapLen1c = quint32(shift);    // 39856
				return;                          // 39857
			}
		}
		step = step >> 2;                        // 39860 步进减半重来
		if (step < 9)                            // 39861 收敛门
			return;                              // 39863(静默失败同相)
		cap = int(g->f10);                       // 39864
	}
}

// FUN_007b5270(601B)@0024.c:21889 — GB 段删除骨架门真身:
//   21910 (bank+0x18)==0 门 / 21912-21915 (0<=pos<len 总量)/0<len 门;
//   门内段插体(delegate vt+0x28 fill_range 007a9c50 恒等/vt+0x40
//   run_start_at 007a9d82/007a7d76 拆段/007b3960 325B/RunStyles32_
//   removeRange 007ae172 564B/f10 尾计 21973-21977 + 0x2000001 分臂
//   007b4c50/007b4e70)深族 cited(铁律 3;970850/96a280 调面 len=len*2>>1
//   同字面 — 39045/45047)。0x18!=0 臂(FUN_007abef6 324B GB 删段)同 cited。
void sectionRemove007b5270(Bank30 *bank, qint64 pos, qint64 len)
{
	if (bank->inner20 == nullptr)                // 21910 *(param_1+0x18)==0
		return;
	qint64 len10 = qint64((quint64(bank->f10) * 2 >> 1));   // 21913 (+0x10)*2>>1
	if (pos < 0 || pos >= len10 || len <= 0)     // 21912-21915 三门
		return;
	// 门内段插体 — cited(delegate vt 深族 + GB 删段臂;见上注)
}

// FUN_0096a2f8 piecetable_init(248B)@0031.c:39050 全读 + 种子腿
// FUN_0096a280(120B)@0031.c:39032 全读 — 结构初始化/种子字段面真身;
//   尾 FUN_007b5270(39045 bank GB face insert_space)/FUN_0096a400
//   (39046-39048 段插入 ×2)深引擎腿 cited(批 111 判例)。
void pieceTableInit(PieceTable60 *pt, quint64 seed)
{
	pt->vtbl = nullptr;                                 // 39056 Partitioning_vtable — cited
	pt->bank30 = makeBank30();                          // 39060-39077 operator_new(0x30)+
	                                                    //   0x20 内层(Uint32PieceTable
	                                                    //   vt 39077 — cited)
	pt->cnt38 = 1;                                      // 39078
	pt->tid40 = quint64(QThread::currentThreadId());    // 39082
	pt->f48 = 0;                                        // 39084
	pt->spin58 = 0;                                     // 39086
	static quint64 s_serialPt = 0;                      // DAT_011be6f0 面
	pt->serial50 = s_serialPt++;                        // 39090-39092 LOCK 自增序
	// --- 种子腿 FUN_0096a280(pt,seed)@39032 全读 ---
	pt->cnt38 = pt->cnt38 + 1;                          // 39034 [7]+1 → 2
	pt->v10 = qint64(-1);                               // 39035 字面 -1
	pt->v18 = 0;                                        // 39036 字面 0
	pt->v20 = 0;                                        // 39037 字面 0
	pt->seed28 = seed;                                  // 39039 [5]=param_2
	pt->b08 = seed < 0x100000000ull;                    // 39040 bool:tag<0x100000000
	// 批 164:FUN_007b5270 骨架门真身升真(39045 调面字面 len*2>>1 —
	//   0024.c:21889 601B;门内段插体 cited)
	sectionRemove007b5270(pt->bank30, 0,
	    qint64((quint64(pt->bank30->f10) * 2) >> 1));
	// FUN_0096a400(pt,0,0) / FUN_0096a400(pt,1,seed) — cited(39046-39048)
}

// FUN_0088e5a0 gapbuffer_reallocate(3525B)@0027.c:43226 — 可达面真身
//   (GB face 判空/容量门/守卫早退);门内重排体(gapbuf_shrink/
//   FUN_0088a016/memset 灌 +0x14/+0x18/+0x1c 计数 ±)与超门
//   styles_cache_create8 + 0x3fffff runstyles 段 cited(批 111 判例)。
//   批 164:43240-43246 守卫(len<1/pos<0)后 43247 `*(gb+0x14)<pos` 补门
//   + 43249-43310 门内重排体升真(gbShrink00889e2e/gbGrow0088a016
//   真身 + memset 灌 + 计数 ± 字面);超门 0x3fffff 分段深族
//   (runbounds_get_a/gapbuf_insert 1897B/新条目 0x30 构造+hash 登记
//   43523-43530)仍 cited(铁律 3;超门臂构造三源 f10<0x4000000 不达)。
void gapBufferReallocate(Bank30 *gb, quint64 pos, quint8 w, quint64 len)
{
	void *gbFace = gb->inner20;                         // 43235 *(param_1+0x18)
	if (gbFace == nullptr) {
		// 43236-43237 空面 fallthrough → styles_cache_create8() +
		//   0x3fffff runstyles 段(43314+)— cited(深引擎;构造三源
		//   bank 内层分配字面非空,空面臂同相不达)
		return;
	}
	// 43239 容量门:(*(long*)(param_1+0x10)*2>>1)+param_4 < 0x4000000
	//   (+0x10 8B 载荷 = f10|mask14<<32;构造三源 mask14 恒 0 → f10)
	if (qint64((quint64(gb->f10) * 2 >> 1) + len) < 0x4000000) {
		if (int(len) < 1)                               // 43240-43243 (int)uVar24<1
			return;
		if (int(pos) < 0)                               // 43244-43246 (int)param_2<0
			return;
		GB20 *g = static_cast<GB20 *>(gbFace);
		if (int(g->len14) < int(pos))                   // 43247 *(lVar22+0x14)<iVar7
			return;
		// 43249-43310 门内重排体逐字面(gapbuf_shrink/FUN_0088a016/
		//   memset 灌 + 计数 ±;early return 43259 (pos==gapPos)/43253
		//   (pos>gapPos)+shrink 臂汇 LAB_0088e8d8 同形)
		int iGap = int(g->gapPos18);                    // 43252 iVar27
		if (iGap < int(pos)) {                          // 43253 门
			gbShrink00889e2e(g, int(pos));              // 43254 gapbuf_shrink
			if (int(g->gapLen1c) < int(w))              // 43255 门
				gbGrow0088a016(g, int(w & 0xffffffff)); // 43256/43257
			iGap = int(g->gapPos18);                    // 43259 LAB_0088e8d8
		} else {                                        // 43260 else 臂
			if (int(g->gapLen1c) < int(w))              // 43262 门
				gbGrow0088a016(g, int(w & 0xffffffff)); // 43263
			iGap = int(g->gapPos18);                    // 43265 iVar27 重读
			if (int(pos) == iGap)                       // 43266 早退门
				goto fill;                              //   → LAB_0088e8d8 灌面
			gbShrink00889e2e(g, int(pos));              // 43269
		}
		iGap = int(g->gapPos18);                        // 43270 lVar9 重读
fill:
		char *base = reinterpret_cast<char *>(g->data) + iGap;   // 43271 lVar9+(lVar22+8)
		if (w == 1)                                     // 43273 uVar24==1 单字节
			*base = char(0);                            // 43274(语料灌 param_3;
			                                            //   44945/45047 调面 w=0)
		else                                            // 43275-43276 memset
			memset(base, 0, size_t(int(w)));            //   (调用面 w 恒 0)
		iGap = int(g->gapPos18);                        // 43278 iVar7
		g->len14 = quint32(int(g->len14) + int(w));     // 43279 +0x14+len
		g->gapPos18 = quint32(iGap + int(w));           // 43280 +0x18+len
		g->gapLen1c = quint32(int(g->gapLen1c) - int(w));   // 43281 +0x1c-len
		if (qint64(iGap) + qint64(reinterpret_cast<intptr_t>(g->data)) == 0)
			return;                                     // 43282-43283 data==0 门
		quint64 cnt = quint64(len) + (quint64(gb->f10) * 2 >> 1);   // 43285
		gb->f10 = quint32(cnt);                         // 43286 +0x10 计
		gb->mask14 = (quint32(cnt >> 32) & 0x7fffffff)  // 43287-43288 +0x14 高半
		           | (gb->mask14 & 0x80000000);
		return;
	}
	// 43311-43312 超容量门 → styles_cache_create8() — cited
}

// FUN_0093fc60(546B)@0031.c:5247 全读 — 词法栈老 runs/线程缓存清偿
//   walker(批 164 升真:vt 槽承载后全臂转写):
//   5257-5259 早退门 / 5260-5266 计数源(delegate vt+0x30 CMP 0x889872
//   恒等快路:runstyles_runs_count(dlg+8)→ 我方 RS Runs() 怪癖 #35;
//   慢路 vcall 同槽 — 承载恒等恒真,注记)/ 5268-5284 逐槽 GB 密排选取
//   + spin 锁字节 backoff(LOCK/UNLOCK 坍缩注记:单线程常 0 直落,批 145
//   spinlock 判例)/ 5286-5290 hash remove(*(pc+0x40)+0x14!=0 → FUN_
//   00933738 hash remove 240B cited — QHashData::freeNode/rehash 深面)/
//   5292 *pc=0 / 5294-5296 条目释放(~RWLock(+0x20)/free(+8)/delete 0x30,
//   cacheEntryRelease 真身)/ 5307-5345 尾 vt 换面析构链(vt+8 CMP vt14
//   恒等:换面→RS D1→GB free/delete 0x20→本体 delete 0x20 = vt14 字面
//   真身 lexDelegateDtor008898d0;非恒等臂 vcall 同槽注记)/ 5347 尾清零。
//   GB 密排选取(i<gapPos 直臂 / i<len gap 偏移臂 / 越界 null)逐字面。
void lexStackClear(Bank30 *gb)
{
	LexDelegate20 *dlg = static_cast<LexDelegate20 *>(gb->f20);   // 5247 *(p+0x20)
	if (dlg == nullptr)                                 // 5258 null → 字面早返
		return;
	int iVar5 = 0;                                      // 5261 语料槽计数
	if (lexVtRunsSlot == &lexDelegateRuns00889872)      // 5262 CMP 0x889872
		iVar5 = int(static_cast<RS8 *>(dlg->rs)->Runs()); //   快路 5263(dlg+8;
		                                                  //   怪癖 #35 计数)
	else                                                // 5265-5266 慢路 vcall
		iVar5 = int(vcallSlot(dlg, 0x30));
	if (iVar5 > 0) {                                    // 5267 门
		GB20 *gbFace = dlg->gb
		    ? static_cast<GB20 *>(dlg->gb) : nullptr;   // 5269 *(dlg+0x10)
		for (quint64 u = 0; u != quint64(iVar5 - 1) + 1; ++u) {   // 5343 闭环
			int i = int(u);                             // 5270 (int)uVar9
			void *pv = nullptr;                         // 5283 越界臂字面
			if (gbFace != nullptr && i < int(gbFace->gapPos18)
			    && gbFace->data != nullptr) {           // 5272/5276 门(+data 卫)
				pv = *reinterpret_cast<void **>(
				    reinterpret_cast<char *>(gbFace->data) + u * 8);  // 5278 密排
			} else if (gbFace != nullptr && gbFace->data != nullptr
			    && i < int(gbFace->len14)) {            // 5279 门
				pv = *reinterpret_cast<void **>(
				    reinterpret_cast<char *>(gbFace->data)
				    + size_t(i + int(gbFace->gapLen1c)) * 8);          // 5281 gap 偏移
			}
			void *pvLocal = pv;                         // 5284 local_50(条目)
			// 5286-5299 spin 锁字节 backoff(0093fce1):
			//   单线程坍缩:c=0 → 5299 JZ 直落(锁争用臂 5301 backoff/
			//   sched_yield/nanosleep 100ns/10us cited — 批 145 判例;字节
			//   置 1/清 0 由 pc 槽消费,CacheEntry30.f28 同位)
			// 5298-5290 hash remove 门(*(pc+0x40)+0x14)!=0 → FUN_00933738
			//   (240B @0030.c:32409)QHashData::freeNode/rehash 深面 cited
			if (pvLocal != nullptr)                     // 5294 门
				cacheEntryRelease(pvLocal);             // 5295-5296 释放臂真身
		}
	}
	// --- 尾 vt 换面析构链(5308-5345)---
	LexDelegate20 *dlg2 = static_cast<LexDelegate20 *>(gb->f20);   // 5311 重读
	if (dlg2 != nullptr) {                              // 5312 门
		if (lexVtDtorSlot == &lexDelegateDtor008898d0)  // 5313 CMP vt14 恒等
			lexDelegateDtor008898d0(dlg2);              // 5314-5329 恒等快路真身
		else                                            // 5331-5333 vcall 慢路
			vcallSlotVoid(dlg2, 0x08);
	}
	gb->f20 = nullptr;                                  // 5347 尾 *(param_1+0x20)=0
}

} // namespace wt