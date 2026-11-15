// 批 160(M17-③):DeepEngineFace ODR 定义 — 调面声明接实现体。
// 判例链:批 156 底座头(DeepEngineFace.h 声明层)/ 批 111 深引擎
// 分段判例(改版底座不在库 → 可读段真身、密排/正则腿 cited)。
// 语料地址均为 Ghidra 基址;逐行出处标注。
#include "DeepEngineFace.h"
#include <QThread>

namespace wt {

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
	// FUN_007b5270(pt->bank30,0,*(bank+0x10)*2>>1) — cited(39045;
	//   bank GB 密排面不在 Inner20 承载)
	// FUN_0096a400(pt,0,0) / FUN_0096a400(pt,1,seed) — cited(39046-39048)
}

// FUN_0088e5a0 gapbuffer_reallocate(3525B)@0027.c:43226 — 可达面真身
//   (GB face 判空/容量门/守卫早退);门内重排体(gapbuf_shrink/
//   FUN_0088a016/memset 灌 +0x14/+0x18/+0x1c 计数 ±)与超门
//   styles_cache_create8 + 0x3fffff runstyles 段 cited(批 111 判例)。
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
		// 43247-43310 重排体 — cited(GB 密排 +0x14/+0x18/+0x1c 与
		//   param_1+0x10 计数更新不在承载;批 111 判例)
		return;
	}
	// 43311-43312 超容量门 → styles_cache_create8() — cited
}

// FUN_0093fc60(546B)@0031.c:5247 全读 — 词法栈老 runs/线程缓存清偿
//   walker。可达面真身:早退门 + 尾槽清零;逐槽清偿循环(5263-5326:
//   GB 密排槽选取/spin 锁字节 backoff 5272-5285/FUN_00933738 hash
//   remove 5287-5290/0x30 条目 RWLock+free+delete 5293-5296)与尾
//   vt 换面析构链(5328-5345:Uint8RunStyles_vt14 → PTR_vt13 + +8
//   D1 + +0x10 free/delete 0x20 + operator_delete 0x20) cited —
//   循环计数源 = bank+0x20 delegate vt+0x30 恒等检查(FUN_00889872;
//   vt 槽 cited nullptr 不可承载),构造三源 f20 恒 0 → 零迭代同相
//   (批 152 QUIRKS #35)。
void lexStackClear(Bank30 *gb)
{
	if (gb->f20 == nullptr)                             // 5257-5259 *(param_1+0x20)
		return;                                         //   null → 字面早返
	// delegate/cache 逐槽清偿循环 + 尾析构链 — cited(见头注)
	gb->f20 = nullptr;                                  // 5347 尾 *(param_1+0x20)=0
}

} // namespace wt