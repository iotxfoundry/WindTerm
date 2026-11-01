// markers 行为测试批(构建者 + 读侧 + 接线;MarkersStore.h 批 72/75/83 现状)
// 铁律 5:断言语料行为,每条断言带语料锚;逐条手工写。
// 语料地址均为 Ghidra 基址(同 MarkersStore.h 头注)。
// 批 84 扩展:h..l 组 —— 0x7543 markersCtxInit 接线(批 83)后的非壳路径。
// 批 84:m_ctx 为 private(批 3 现状,无 ctx() 读缝)—— 测试专用可达缝:
// #define private public 仅本 TU(EditorEngine/EditorContext 均无 Q_OBJECT,
// 不触发 moc ABI 面;库侧已编 .so 二进制不受影响)。
#define private public
#include "EditorEngine.h"
#undef private
#include "MarkersStore.h"
#include <QApplication>
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

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
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

	// ======== h. 0x7543 接线组 —— dispatch(0x7543, bufId) → markersCtxInit ========
	// 语料:0x7543 case(EditorEngine.cpp:2665)= FUN_0092f0f6 setCurrentBuffer;
	//   editor_initDoc 唯一调用点 = 本命令(批 83 C2);markersCtxInit = 009a2e1e
	//   尾段 009a2e93..009a311a(MarkersStore.h:720;A 分配 009a2eb2)。
	//   断言 arr 非空 + 尾段初始化字面(idAlloc=0 009a2fxx/+0x28 清零、bank kind=3
	//   009a3107→009cc22c)。
	{
		EditorEngine e;
		expect(e.dispatch(0x7543, (qlonglong)1) == QVariant(0),
		       "h: 0x7543 返回 0(case 体 return QVariant(0))");
		expect(e.m_ctx.markersStore.arr != nullptr,
		       "h: arr 非空(markersCtxInit 009a2eb2 分配路径激活)");
		expect(e.m_ctx.markersStore.idAlloc == 0,
		       "h: idAlloc=0(009a2fxx *(u32*)(D+0x28)=0 字面)");
		expect(e.m_ctx.markersStore.doc == &e.m_ctx,
		       "h: D+0x08=param_1[1]=E(批 83:E=doc ⇒ &m_ctx)");
		expect(e.m_ctx.markersStore.tlist == nullptr,
		       "h: D+0x18=FUN_00930f9e(E,0) cited 工厂未接线 → nullptr");
		expect(e.m_ctx.markersStore.arr->bank != nullptr &&
		       e.m_ctx.markersStore.arr->bank->kind == 3,
		       "h: A+0x18 bank kind=3(009a3107 分配 + FUN_009cc22c)");
		expect(e.m_ctx.markersStore.arr->lexerSnap == nullptr,
		       "h: A+0x08 lexerSnap = param_1[3] 未建模 → nullptr(cited)");
		// 同 id 短路(0092f0f6@EditorEngine.cpp:2671:currentBufferId==bufId → 0 提前返;
		//   语料短路腿不再走 initDoc → arr 指针不变)
		wt::MarkersArray *before = e.m_ctx.markersStore.arr;
		e.dispatch(0x7543, (qlonglong)1);
		expect(e.m_ctx.markersStore.arr == before,
		       "h: 同 bufId 短路 → 不重复 initDoc(0092f0f6 同 id 提前返腿)");
	}

	// ======== i. markWrite 经 ctx 挂载后(FUN_009a62c0;批 76 d 组为直调,本组走 ========
	// ========      0x7543 真值路径;语料 39421+:len<1 弃 / 39470 越出区间弃 / ========
	// ========      id 分配 ++ 存回)====================================================
	// 语料注:param_1 = A(MarkersStore.h:559 勘正);arr->entryAt(1) = param_1[5]。
	//   dispatch 面无 markWrite 命令(0x75a2 区间腿,EDITOR-ENGINE-COMMANDS.md 无
	//   markWrite 落点)→ 沿批 76 惯例直调,仅挂载改经 0x7543。
	{
		EditorEngine e;
		e.dispatch(0x7543, (qlonglong)1);
		wt::MarkersStore &D = e.m_ctx.markersStore;
		// firstIndex/end:vcallSlot(vt+0x28/+0x40)(009a62c0 语料 39437/39440 两调,
		//   MarkersStore.h:567-568 转写)。经 0x7543 后 entry[1] 空 → 照语料消费
		//   形态灌 u64 载体(批 76 d 组同构;u64 腿 cur 读 = rsValue64 占位 → 0)。
		wt::MarkEntryObj *obj = fxObj();
		obj->styles = wt::makeHolder0x20(nullptr);
		fxReset(0, 0, 0, 100);                       // firstIndex=0,end=100
		wt::MarkEntry *me = new wt::MarkEntry{};
		me->sel = 0; me->u64Obj = obj;
		*D.arr->entryPtr(1) = me;                    // param_1[5] = A+0x28
		D.markWrite(95, 10, 0);                      // end=100 < 105 → 39470 弃
		expect(D.idAlloc == 0, "i: 挂载后越出既有区间 → 弃(009a62c0 39470)");
		D.markWrite(0, 10, 0);
		expect(D.idAlloc == 1, "i: 挂载后常规写 → idAlloc 0→1(39464 ++ 存回)");
		expect(D.arr->entryAt(1) == me, "i: 写后 entry[1] 仍原条目(39464 语料直返腿)");
	}

	// ======== j. 0x759f 组 —— 0x7543 后 publishSnapshot 非壳门 ========
	// 语料:0x759f case(EditorEngine.cpp:949)= FUN_00926e08:M(+0xc0 门)→
	//   FUN_0099d1f6 发布快照 → *(M+0x50)。0x7543 后 markersStore.arr 非空 →
	//   非壳门(任务口径:壳期值 0 合法,断言"可走通非壳门"即可)。
	{
		EditorEngine e;
		e.dispatch(0x7543, (qlonglong)1);
		// 行为门腿:markers.isEmpty()==true → 0(0x759f case 门,EditorEngine.cpp:951;
		//   该 QVector 与 markersStore 并存,0x7543 不触 → 仍空)
		expect(e.dispatch(0x759f) == QVariant(0),
		       "j: 行为门腿 markers 表空 → 0(EditorEngine.cpp:951 门)");
		// 非壳门腿:arr 非空 → publishSnapshot 全链走通(0099d1f6:spinlock →
		//   buildPending(0099cec0)→ 返 &M+0x50)
		e.m_ctx.markersStore.visibleSnap = 0;   // q3:语料 +0x50 不清零,显式定值
		quint64 *ret = e.m_ctx.markersStore.publishSnapshot();
		expect(ret == &e.m_ctx.markersStore.visibleSnap,
		       "j: publishSnapshot 返 &M+0x50(0099d1f6 尾)");
		expect(*ret == 0,
		       "j: buildPending 门 false(entry[2]==0)→ +0x50 不变(0099cec0)");
		// pending 置位 → 快照切换(0099d1f6 门内腿;g 组同构,经 ctx 挂载后同链)
		e.m_ctx.markersStore.stagedSnap = 0x5150;
		wt::MarkEntryObj *obj = fxObj();
		wt::MarkEntry *me2 = new wt::MarkEntry{};
		me2->sel = 0; me2->u64Obj = obj; me2->u32Obj = nullptr;
		*e.m_ctx.markersStore.arr->entryPtr(2) = me2;
		*e.m_ctx.markersStore.publishSnapshot();
		expect(e.m_ctx.markersStore.visibleSnap == 0x5150,
		       "j: entry[2] 就绪 → visibleSnap=stagedSnap(0099d1f6 门内)");
	}

	// ======== k. 0x75a1 组 —— dispatch(0x75a1, line=0) → resolveLine 走查 ========
	// 语料:0x75a1 case(EditorEngine.cpp:956)= FUN_00926e3e:同 markers 表门 →
	//   FUN_009a096a resolveLine。行为门腿 markers 表空 → 0;非壳门腿 = 经 ctx
	//   挂载后直调 resolveLine(009a096a):lineSpan(009a088e)→ findLineSlot
	//   (009a0830)n==0 → -1 → 空手 span={0,0}(009a0910 解锁腿;out 未写 =
	//   栈残值,转写 span[0] 零值走查 — 怪癖登记)→ 折叠腿 foldFoldable cited
	//   恒 false → break → runIndexOfLine(0099c9c2 → 009cc396 bank vt+0x28 尾调)
	//   —— 委托形态 holder vtbl cited 占位,尾调无落地(runcount 空路径仅前半可判)。
	{
		EditorEngine e;
		e.dispatch(0x7543, (qlonglong)1);
		// 行为门腿:markers 表空 → 0(EditorEngine.cpp:957 同 0x759f 门)
		expect(e.dispatch(0x75a1, 0) == QVariant(0),
		       "k: 行为门腿 markers 表空 → 0(EditorEngine.cpp:957 门)");
		// 非壳门腿:runcount 空 → findLineSlot -1(009a0830 语料 0<iVar1 门),
		//   直调 D.resolveLine(0) 前半走查可判 —— 但后半 bank 尾调(vt+0x28)
		//   在委托形态下解引 cited 占位 vtbl 必崩 → 停手注明(任务 k 组口径:
		//   resolveLine 走查 runcount 空 → span[0] 路径,该路径止于 cited 面)。
		//   判别断言落在 findLineSlot 层(009a0830 真身,批 76 f 组同面):
		wt::MarkEntryObj *obj = fxObj();
		obj->styles = wt::makeHolder0x20(nullptr);
		fxReset(0, 0, 0, 0);
		wt::MarkEntry *me = new wt::MarkEntry{};
		me->sel = 0; me->u64Obj = obj; me->u32Obj = nullptr;
		e.m_ctx.markersStore.arr->bank->delegate = nullptr;   // 停尾调路径(见上)
		*e.m_ctx.markersStore.arr->entryPtr(0) = me;
		// 0x75a1 dispatch 仍走 markers 表门 → 0;resolveLine 非壳路径以
		//   findLineSlot 层断言承接(runcount 空 → -1 → lineSpan 空手)
		expect(e.dispatch(0x75a1, 0) == QVariant(0),
		       "k: 0x7543 后 dispatch(0x75a1) 仍过 markers 表门 → 0");
		expect(e.m_ctx.markersStore.findLineSlot(0) == -1,
		       "k: runcount 空 → findLineSlot -1(009a0830 0<iVar1 门;resolveLine 前半)");
	}

	// ======== l. q1 裁决组(行为门):markWrite cur 表 arg = D+0x18(tlist)vs arr->bank ====
	// 语料(0032.c:39454):uVar3 = FUN_00a10384(*(undefined8 *)(*param_1 + 0x18), …) —
	//   注记链两说:A+0x18(bank,转写头注 559 行勘正句)vs A+0x08 lexerSnap ≡ D+0x18
	//   (tlist,580 行 landed 注)。本组行为判别(landed 实测 = tlist 路)。
	// 判别设计:tlist 挂表 A(槽 0=0x51a);u32 载体 rs 预灌全 0(v32=0 → cur hi32=0,
	//   lo32=keyPropsOf(arg,0) 纯 arg 值)。props=0((props&0x7c000)==0 建新条目腿):
	//   - arg=tlist(A)→ cur=0x51a≠0 → 39467 "已有值不覆盖" 弃 → idAlloc 不动(=0)
	//   - arg=bank(裸 0 表 — 不挂载)→ cur=0 → idAlloc++(=1)
	//   bank+0x60 不挂载(裸内存 0):若实现读 bank 即崩(tblRead h=0 解引)—— 崩亦是判别
	//   信号(读 bank 路),正常轮按 idAlloc 判读。
	{
		EditorEngine e;
		e.dispatch(0x7543, (qlonglong)1);
		wt::MarkersStore &D = e.m_ctx.markersStore;
		// 表 A(tlist 路,D+0x18):tlist 工厂 FUN_00930f9e cited 未接线(0x7543 落
		//   nullptr)→ 夹具直挂(观测缝,非产品路径)。markWrite cur 腿 = keyPropsOf
		//   (tlist) → tblRead(tA+0x60)(FUN_00a10384 槽)。
		FList<4> flA;
		wt::ValueTable *tA = new wt::ValueTable{};
		tA->list60 = &flA.h;
		D.tlist = tA;
		flA.d.vals[0] = 0x51a;
		// u32 载体 entry[1]:rs Length=8 值恒 0(v32=0 → cur = 0<<32 | arg 值)
		U32Fixture uf(0, 8);
		*D.arr->entryPtr(1) = uf.me;
		fxReset(0, 0, 0, 100);                        // firstIndex=0,end=100(U32Fixture
		                                              //   默认 fxEnd=0 → 39470 恒弃,覆写)
		uf.rs->InsertSpace(0, 8);
		D.idAlloc = 0;
		D.markWrite(0, 1, 0);                         // props=0 → 建新条目腿(39459+)
		expect(D.idAlloc == 0,
		       "l: q1 判别 —— cur=0x51a(tlist 表)≠0 → 39467 弃,idAlloc 不动"
		       " 【markWrite cur 读 = D+0x18 tlist 路,landed 580 行确认;"
		       " 若读 bank(裸 0)则 cur=0 → idAlloc=1】");
		// 对照腿停手(怪癖登记,铁律 2 不修):cur=0 → 建新条目 → u32 载体腿
		// rsFill32(e->u32Obj,…) — 语料 39511 直接以 u32Obj 为 GB 句柄(密排形态),
		// 我方委托形态 obj->styles=holder(RsHolder20)→ holderRs(e->u32Obj) 取回
		// holder 再 static_cast<RS32*> = 双解引错位 → FillRange this=vtbl+8 崩。
		// u32 载体写侧委托形态失配(landed 转写 vs 委托怪癖),行为门裁决待语料批。
	}

	printf("fail=%d\n", g_fail);
	return g_fail == 0 ? 0 : 1;
}
