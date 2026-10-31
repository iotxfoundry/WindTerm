// markers 行为测试批(构建者 + 读侧;MarkersStore.h 批 72/75 现状)
// 铁律 5:断言语料行为,每条断言带语料锚;逐条手工写。
// 语料地址均为 Ghidra 基址(同 MarkersStore.h 头注)。
#include "MarkersStore.h"
#include <cstdio>

static int g_fail = 0;
static void expect(bool ok, const char *name)
{
	printf("%s: %s\n", ok ? "OK" : "FAIL", name);
	if (!ok)
		g_fail++;
}

// ============ 夹具(测试专用;槽序/布局全部语料锁定,数值由用例注入)============

// MarkEntryObj vtable 槽值图(只读侧尾调族消费;dtor 槽计数供 moveEntry 验证)。
// 槽位图:vt[1]=+0x08 D1 dtor(0099cecc);vt[5..8]=+0x28 firstIndex/+0x30 count/
// +0x38 begin/+0x40 end(0099cf3e/5c/7a/98 尾调族,MarkersStore.h 槽注释)。
static qint64 fxFirstIndex, fxCount, fxBegin, fxEnd;
static int    fxDtorCalls;
static qint64 fx_first(void *) { return fxFirstIndex; }
static qint64 fx_count(void *) { return fxCount; }
static qint64 fx_begin(void *) { return fxBegin; }
static qint64 fx_end(void *)   { return fxEnd; }
static void   fx_dtor(void *)  { ++fxDtorCalls; }
static void  *fx_vtable[9] = {
	nullptr, (void *)fx_dtor, nullptr, nullptr, nullptr,
	(void *)fx_first, (void *)fx_count, (void *)fx_begin, (void *)fx_end,
};
static void fxReset(qint64 first, qint64 count, qint64 begin, qint64 end)
{
	fxFirstIndex = first; fxCount = count;
	fxBegin = begin; fxEnd = end; fxDtorCalls = 0;
}
static wt::MarkEntryObj *fxObj()   // makeU64Styles(009a6452 形)壳 + 语料槽序 vt
{
	wt::MarkEntryObj *o = new wt::MarkEntryObj{};
	o->vtbl = fx_vtable;
	o->styles = nullptr;
	return o;
}

// A 头 0x38 分配 + 三 entry 槽清零 — markersCtxInit 009a2eb2 字面(MarkersStore.h 724-730)
static wt::MarkersArray *mkArr()
{
	auto *A = static_cast<wt::MarkersArray *>(::operator new(0x38));
	A->core = nullptr;
	A->lexerSnap = nullptr;
	A->_r10[0] = A->_r10[1] = A->_r10[2] = A->_r10[3] = 0;
	*A->entryPtr(0) = nullptr;
	*A->entryPtr(1) = nullptr;
	*A->entryPtr(2) = nullptr;
	return A;
}

// M 壳(构造器 POD 全零;arr 由用例挂)
struct StoreFix {
	wt::MarkersStore  D;
	wt::MarkersArray *A;
	StoreFix() : A(mkArr()) { D.arr = A; }
};

// u32 载体条目(sel!=0 → +0x08 槽,MarkEntry 注释):obj->styles 挂 holder,
// holder+0x10 直存 RS32(mk3 §1 委托形态;rsOf 读侧单解引用 009cd3da 同构)
struct U32Fixture {
	wt::RsHolder20  *holder;
	RS32            *rs;
	wt::MarkEntryObj *obj;
	wt::MarkEntry   *me;
	U32Fixture(qint64 first, qint64 count)
	{
		fxReset(first, count, 0, 0);
		rs = new RS32();
		holder = wt::makeHolder0x20(rs);
		obj = fxObj();
		obj->styles = holder;      // entryValueAt:rsOf(obj->styles)→holder->rs
		me = new wt::MarkEntry{};
		me->sel = 1; me->u32Obj = obj; me->u64Obj = nullptr;
	}
};

// QListData 形 holder(tblRead 解引用面 — FUN_00a101a0/00a10384 twin 语料:
// holder+0xc 自旋字节、holder+0x10=Data*;Data+8=begin/+0xc=end/+0x10=槽 0,
// Qt5 QListData::Data 内部布局)
template <int N> struct FList {
	struct Data {
		int ref = 1; int alloc = N; int begin = 0; int end = N;
		quint64 vals[N] = {};
	};
	struct Holder {
		quint8 _r00[0x0c] = {};
		quint8 spin = 0;
		quint8 _r0d[3] = {};
		Data  *data;
	};
	Data  d;
	Holder h;
	FList() { h.data = &d; }
};
static_assert(offsetof(FList<4>::Holder, spin) == 0x0c, "tblRead holder+0xc 自旋");
static_assert(offsetof(FList<4>::Holder, data) == 0x10, "tblRead holder+0x10=Data*");
static_assert(offsetof(FList<4>::Data, begin) == 8, "QListData Data+8=begin");
static_assert(offsetof(FList<4>::Data, end) == 0x0c, "QListData Data+0xc=end");
static_assert(offsetof(FList<4>::Data, vals) == 0x10, "QListData Data+0x10=槽0");

int main()
{
	// ======== a. bankCtor K3(FUN_009cc22c;initDoc 009a3107 只调 K3)========
	{
		wt::ValueTable bank{};                       // 裸内存零化语境(operator_new 0x40)
		wt::RsHolder20 *h = wt::makeHolder0x20(new RS8());   // 009a2ed7 形
		wt::bankCtorK3(&bank, h);
		expect(bank.kind == 3, "a: K3 kind==3");
		expect(bank.delegate == h, "a: K3 delegate==rs");
		expect(bank.holders[3] == h, "a: K3 holders[3]==rs");
		expect(bank.holders[0] == nullptr && bank.holders[1] == nullptr
		       && bank.holders[2] == nullptr && bank.holders[4] == nullptr
		       && bank.holders[5] == nullptr, "a: K3 其余槽全空(009cc22c 字面)");
	}

	// ======== b. rsValue8/16/32 委托读(007b7b70/007b6dd0/0088ff00;
	//             灌值腿 007b7290/007b8000 ≡ FillRange,EXT-BOUNDARY 委托)========
	{
		wt::RsHolder20 *h8 = wt::makeHolder0x20(new RS8());
		static_cast<RS8 *>(h8->rs)->InsertSpace(0, 8);       // 上游 RunStyles 语义:先扩 Length(FillRange 端界判)
		expect(wt::rsFill8(h8, 2, 0xab, 4), "b: rsFill8 写入真");
		expect(wt::rsValue8(h8->rs, 2) == 0xab, "b: rsValue8 读回@2");
		expect(wt::rsValue8(h8->rs, 5) == 0xab, "b: rsValue8 读回@5");
		expect(wt::rsValue8(h8->rs, 6) == 0, "b: rsValue8 run 内 gap 值→0(Length 内零值)");
		expect(wt::rsValue8(h8->rs, 8) == 0, "b: rsValue8 越界→0(DAT_011c1edc 族)");
		expect(wt::rsValue8(h8->rs, -1) == 0, "b: rsValue8 负越界→0");
		expect(wt::rsValue8(nullptr, 0) == 0, "b: rsValue8 !rs 壳期守卫→0");
		{
			wt::RsHolder20 *e8 = wt::makeHolder0x20(new RS8());
			expect(wt::rsValue8(e8->rs, 0) == 0, "b: 空表(Length 0)读→0");
		}
		wt::RsHolder20 *h16 = wt::makeHolder0x20(new RS16());
		static_cast<RS16 *>(h16->rs)->InsertSpace(0, 8);
		expect(wt::rsFill16(h16, 0, 0x1234, 3), "b: rsFill16 写入真");
		expect(wt::rsValue16(h16->rs, 0) == 0x1234, "b: rsValue16 读回@0");
		expect(wt::rsValue16(h16->rs, 2) == 0x1234, "b: rsValue16 读回@2");
		expect(wt::rsValue16(h16->rs, 3) == 0, "b: rsValue16 未灌值→0");
		wt::RsHolder20 *h32 = wt::makeHolder0x20(new RS32());
		static_cast<RS32 *>(h32->rs)->InsertSpace(0, 8);
		expect(wt::rsFill32(h32, 1, 0xdeadbeefu, 2), "b: rsFill32 写入真");
		expect(wt::rsValue32(h32->rs, 1) == 0xdeadbeefu, "b: rsValue32 读回@1");
		expect(wt::rsValue32(h32->rs, 2) == 0xdeadbeefu, "b: rsValue32 读回@2");
		expect(wt::rsValue32(h32->rs, 3) == 0, "b: rsValue32 越界→0");
	}

	// ======== c. entryValueAt sel==0 u64 原值路(009a06ac;
	//             RS64 占位返 0 现状登记 — rsValue64 批 72 裁决)========
	{
		StoreFix sf;
		wt::MarkEntryObj *obj = fxObj();
		obj->styles = wt::makeHolder0x20(nullptr);   // holder+0x10=rs=nullptr — rsValue64 占位消费前不解引
		wt::MarkEntry *me = new wt::MarkEntry{};
		me->sel = 0; me->u64Obj = obj; me->u32Obj = nullptr;
		*sf.A->entryPtr(0) = me;
		expect(sf.D.entryValueAt(3, 0) == 0,
		       "c: entryValueAt sel==0 → RS64 占位返 0(现状登记)");
	}

	// ======== d. markWrite id 分配(FUN_009a62c0 39464+:idAlloc ++ /
	//             bits28-31==0xd 不占 id;39470 越出区间弃)========
	{
		StoreFix sf;
		wt::MarkEntryObj *obj = fxObj();
		obj->styles = wt::makeHolder0x20(nullptr);   // 同 c:u64 腿 cur 读 = rsValue64 占位 → cur=0
		fxReset(0, 0, 0, 100);                       // firstIndex=0,end=100
		wt::MarkEntry *me = new wt::MarkEntry{};
		me->sel = 0; me->u64Obj = obj;               // u64 载体腿(sel==0)
		*sf.A->entryPtr(1) = me;                     // param_1[5]=A+0x28
		sf.D.markWrite(95, 10, 0);                   // end=100 < 105
		expect(sf.D.idAlloc == 0, "d: 越出既有区间 → 弃,idAlloc 不动(39470)");
		sf.D.markWrite(0, 10, 0);
		expect(sf.D.idAlloc == 1, "d: 常规写 → idAlloc 0→1(++ 存回)");
		sf.D.markWrite(10, 10, Q_UINT64_C(0xd0000000));
		expect(sf.D.idAlloc == 1, "d: bits28-31==0xd → 不占 id");
		sf.D.markWrite(20, 10, 0);
		expect(sf.D.idAlloc == 2, "d: 后续常规写续号(不重置)");
	}

	// ======== e. nearestIdFrom 反向扫(FUN_009a07d8;id=v>>32 hi32;
	//             入口 00926e52 *out=0 — cited 未落地,测试按调用者预清零)========
	{
		StoreFix sf;                                 // 空 store:sel==0 → RS64 占位恒 0
		wt::MarkEntryObj *obj = fxObj();
		obj->styles = wt::makeHolder0x20(nullptr);   // 同 c:占位前不解引 nullptr
		fxReset(0, 0, 0, 0);
		wt::MarkEntry *me = new wt::MarkEntry{};
		me->sel = 0; me->u64Obj = obj;
		*sf.A->entryPtr(0) = me;
		quint32 out = 0;
		sf.D.nearestIdFrom(0, &out);
		expect(out == 0, "e: 空 store → 0(扫至 i=-1 出 loop)");
	}
	{
		StoreFix sf;
		FList<4> fl;
		wt::ValueTable bank{};
		sf.A->bank = &bank;
		bank.list60 = &fl.h;                         // keyPropsOf=vt+0x60 槽(FUN_00a10384)
		U32Fixture uf(3, 4);                         // firstIndex=3,反向扫 3→2→1 命中
		*sf.A->entryPtr(0) = uf.me;
		const quint32 id = 0x12345, key = 2;
		uf.rs->InsertSpace(0, 8);                        // 上游语义:先扩 Length
		uf.rs->FillRange(1, int((id << 13) | key), 1);   // u32 packed:(id<<13)|key
		                                                 // (≡ 灌值腿 007b8000 委托)
		quint32 out = 0;
		sf.D.nearestIdFrom(0, &out);
		expect(out == id, "e: 反向扫命中 → hi32=id(v>>32)");
	}

	// ======== f. findLineSlot 低 32 位字面怪癖(FUN_009a0830:
	//             比较 RAX 低 32 位 == target — 语料字面,原样)========
	{
		StoreFix sf;
		FList<4> fl;
		wt::ValueTable bank{};
		sf.A->bank = &bank;
		bank.list60 = &fl.h;
		U32Fixture uf(0, 2);
		*sf.A->entryPtr(0) = uf.me;
		const quint32 id = 0x2468a, key = 3, propsVal = 0x51a;
		fl.d.vals[key] = propsVal;
		uf.rs->InsertSpace(0, 8);                        // 上游语义:先扩 Length
		uf.rs->FillRange(1, int((id << 13) | key), 1);
		expect(sf.D.entryValueAt(1, 0) == (quint64(id) << 32 | propsVal),
		       "f: entryValueAt 拆包 {id<<32|props}(009a06ac)");
		// 全值(id<<32|propsVal)≠ 目标,低 32 位 == 目标 → 仍命中 = 怪癖登记
		expect(sf.D.findLineSlot(int(propsVal)) == 1,
		       "f: 低 32 位命中(全值≠目标,hi32=id 不参比)");
		expect(sf.D.findLineSlot(int(propsVal) + 1) == -1, "f: 未命中 → -1");
		expect(sf.D.findLineSlot(-1) == -1, "f: 无匹配行(0xffffffff)→ -1");
	}

	// ======== g. publishSnapshot buildPending 门(FUN_0099d1f6;
	//             门 = FUN_0099cec0 entry[2]!=0)========
	{
		StoreFix sf;
		sf.D.visibleSnap = 0x1234;                   // initDoc 不清零 +0x50(q3)
		quint64 *ret = sf.D.publishSnapshot();
		expect(ret == &sf.D.visibleSnap, "g: 返回 &M+0x50(0099d1f6 尾)");
		expect(*ret == 0x1234, "g: 无 pending → visibleSnap 不变(0099cec0 门 false)");
		// 正向对照:entry[2] 就绪 → 门开,快照切换 + moveEntry(2,0)
		sf.D.stagedSnap = 0x5150;
		wt::MarkEntryObj *obj = fxObj();
		wt::MarkEntry *me = new wt::MarkEntry{};
		me->sel = 0; me->u64Obj = obj; me->u32Obj = nullptr;
		*sf.A->entryPtr(2) = me;
		sf.D.publishSnapshot();
		expect(sf.D.visibleSnap == 0x5150, "g: buildPending → visibleSnap=stagedSnap");
		expect(sf.A->entryAt(2) == nullptr && sf.A->entryAt(0) == me,
		       "g: moveEntry(2,0) 搬移(0099cecc)");
	}

	printf("fail=%d\n", g_fail);
	return g_fail == 0 ? 0 : 1;
}
