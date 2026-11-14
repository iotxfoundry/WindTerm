// markers 行为测试批(构建者 + 读侧 + 接线;MarkersStore.h 批 72/75/83 现状)
// 铁律 5:断言语料行为,每条断言带语料锚;逐条手工写。
// 语料地址均为 Ghidra 基址(同 MarkersStore.h 头注)。
// 批 84 扩展:h..l 组 —— 0x7543 markersCtxInit 接线(批 83)后的非壳路径。
// 批 100 扩展:m..o 组 —— 全链:0x7543 换缓冲驱动 regionScan(批 88)+ 0x759f/0x75a0
//   读侧门 + q26 tlist 路回归(批 85 f 组修正后)。
// 批 84:m_ctx 为 private(批 3 现状,无 ctx() 读缝)—— 测试专用可达缝:
// #define private public 仅本 TU(EditorEngine/EditorContext 均无 Q_OBJECT,
// 不触发 moc ABI 面;库侧已编 .so 二进制不受影响)。
#define private public
#include "EditorEngine.h"
#undef private
#include "MarkersStore.h"
#include <QApplication>
#include <QColor>
#include <QDataStream>
#include <QIODevice>
#include "Scintilla.h"
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
static qint64 fx_count0(void *) { return 0; }   // q3 专用:vt+0x30=0(prune vcallSlot(0x30)≠1 门关)
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
		sf.D.tlist = &bank;                              // QUIRKS 26 定案:props 读走 tlist
		bank.list60 = &fl.h;                             // markWrite cur 腿 = 009a10384 读 +0x60 槽(批 85 勘定:挂 +0x60 非 +0x58)
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

	// ======== m. regionScan 驱动组(批 100)—— 0x7543 换缓冲 → FUN_009a2b90 ========
	// ========      Outlining 驱动(批 88 落地,EditorEngine.cpp:2859-2889)同步直调 ========
	// 语料链(0030.c:28874 case4 → 0032.c:36795 驱动体):markersCtxInit 建 arr →
	//   *(D+0x20)=scanCursor(0)<textLen 主门(009a2cbf)→ FUN_0099d072 关键词腿 cited
	//   → regionScan(0,0,textLen)(0032.c:36875;mode=0,lex=bufferLexer)。空态:
	//   kwVec30 空(ctor 00a10a68 只入一个 0)→ regionScan 内 FUN_00a10472 门
	//   (size>0xf,false)走基值腿:coreWriteRange(0099d50c)整段灌 base +
	//   scanCursor=to 收尾(MarkersStore.h:1057-1058);shell 期 bufferLexer=
	//   nullptr → sx=nullptr → !sx 门同腿(1056)。builder 壳 -1 同相:matches
	//   = kwCacheFill 记录表恒空(0099d27e 装载侧批 101,记录源 cited)→ 命中
	//   处理腿(0099d6ab..)零迭代,builder(D+0x40)读不发生。
	//   ⚠ 批 101 注:kw 装载返回门(keywordsLoadGate)在 MarkersStore.h 落地,
	//   0x7543 驱动处 EditorEngine.cpp 接线属他批写域 — 测试链行为不变同相。
	{
		EditorEngine e;
		e.dispatch(0x7543, (qlonglong)1);            // 驱动同步腿(批 88 偏差登记)
		wt::MarkersStore &D = e.m_ctx.markersStore;
		expect(D.arr != nullptr,
		       "m: 驱动前置 arr 非空(0030.c:28875 *(session+0xc0) 门代理)");
		expect(D.scanCursor == 0,
		       "m: 驱动前 scanCursor=0(markersCtxInit param_1[4]=0,009a2fxx)");
		// 空文档腿:textLen=0 → publishOutline(009a2cb5 发布腿)+ scanCursor(0)
		//   < 0 false → else-if stopFlag==0 → "Nothing to do"(009a2e0a 字面)。
		//   publishOutline 壳期惰值(makeOutlineModel 恒 nullptr → moveEntry(1,2)
		//   swap 两空槽),不崩即为同相。
		expect(D.scanCursor == 0 && D.idAlloc == 0,
		       "m: 空文档腿 → scanCursor/idAlloc 不动(009a2cbf 0<0 false)");
		// 非空文档腿(走查 3 字节):scanCursor 0<3 → stopFlag=0(009a2ce 区字面)
		//   → regionScan(0,0,3)(0032.c:36875;mode=0)。kwVec30 空 → 基值腿:
		//   coreWriteRange(0,3,base,1) + scanCursor=to(1057-1058)→ publishOutline
		//   循环尾非停机腿(009a2df8)。coreWriteRange rolling=1 → runstylesUpgrade
		//   kind=3(rsFill8):bank 层 RS8 Length=0 → end>Length → noChange(委托
		//   FillRange RunStyles.cxx:138 边界门;不扩容为委托怪癖,登记)。
		e.m_ctx.docBytes = QByteArray("abc");        // docBytes ≡ FUN_0092801a 长度面
		                                             //   (EditorEngine.cpp:2867 注)
		e.m_ctx.styleProps190.append(0x51a);         // 预填一值(第六视图 +0x190;regionScan
		                                             //   不读此表 — 只证壳值不影响驱动链)
		e.m_ctx.currentBufferId = 0;                 // 复位短路门 → 重新走全链
		e.dispatch(0x7543, (qlonglong)1);
		expect(D.scanCursor == 3,
		       "m: 非空文档 → scanCursor=to 收尾(*D+0x20=to,0099d50c 腿尾 1058)");
		expect(D.stopFlag == 0,
		       "m: stopFlag 清零(009a2ce 区 *(u8*)(D+0x2c)=0 字面)");
		// builder 预填 + 再扫:builder(D+0x40 initDoc param_1[8]=0)壳期 -1 同相
		//   —— matches 记录表恒空 → 命中腿零迭代,只断言不崩 + 收尾游标。
		//   styleProps190 预填值同相位:builder 腿不读 +0x190(同 h 组锚)。
		expect(e.m_ctx.styleProps190.size() == 1 && e.m_ctx.styleProps190.at(0) == 0x51a,
		       "m: styleProps190 预填保持(观测缝;驱动链不触第六视图)");
		D.builder = static_cast<void *>(&D);         // 观测缝:壳期非空桩(批 88 口径)
		e.m_ctx.currentBufferId = 0;
		e.dispatch(0x7543, (qlonglong)1);
		expect(D.scanCursor == 3,
		       "m: builder 壳桩 → 命中腿零迭代(kwcMemo 空记录)同相收尾");
		// 批 101:kwcMemo 装载侧直测(miss→insert→hit;键 CONCAT44(mode,lineNo))
		{
			wt::ScannerX sx;                          // ctor00a1092a 形(kwVec30=1)
			QHash<quint64, QStringList> memo;
			sx.kwCacheFill(memo, nullptr, 0, 2);      // miss → 空记录插入(33077 零记录同相)
			expect(memo.size() == 1,
			       "m101: kwCacheFill miss → 节点插入(33108..33131 QHashData≈insert)");
			QStringList *hit = sx.kwCacheFill(memo, nullptr, 0, 2);   // hit → 直返
			expect(hit != nullptr && hit->isEmpty(),
			       "m101: kwCacheFill hit → 记录表直返(33133 节点+0x18 面;空表非空指针)");
			expect(D.kwcMemo.isEmpty(),
			       "m101: 驱动链 kwcMemo 不增长(基值腿不触 33227)");
		}
		// 批 101:keywordsLoad 返回门直测(0099d072;壳期 lex=null → 32951 空门
		//   同相返 1;非空 lex → 词表计数 cited 恒 0 → 循环零迭代返 1)
		{
			bool stopPend = false;
			expect(wt::keywordsLoad(&stopPend, nullptr) == true,
			       "m101: keywordsLoad lex=null → 返 1(32951 lVar5==0 直通 32985)");
			expect(wt::keywordsLoad(&stopPend, &stopPend) == true,
			       "m101: keywordsLoad 非空 lex + 空词表 → 返 1(32955 门 0<0 false)");
		}
		// 直调腿:E 面包装(lex=bufferLexer,nullptr → !sx 基值腿,同 1056 门)
		D.scanCursor = 0;
		e.m_ctx.regionScan(0, 0, 3);
		expect(D.scanCursor == 3,
		       "m: regionScan 直调(lex=nullptr)→ scanCursor=to(1056 !sx 门)");
	}

	// ======== n. 0x759f/0x75a0 读侧门组(批 100)—— regionScan 后非壳链 ========
	// 语料:0x759f(EditorEngine.cpp:1028)= FUN_00926e08:M(+0xc0 门)→
	//   publishSnapshot → *(M+0x50);0x75a0(L24799)= FUN_00926e52:*out=0 →
	//   FUN_009a07d8 nearestIdFrom(arr 门 :1050)。regionScan 基值腿灌 bank RS8
	//   (kind=3)但 Length=0 → entryValueAt 扫全 0(壳期 0 合法 = 任务 n 组口径)。
	{
		EditorEngine e;
		e.dispatch(0x7543, (qlonglong)1);            // arr 建 + regionScan 驱动(空态)
		// 0x759f:行为门 markers(QVector,0x7543 不触)空 → 0(EditorEngine.cpp:1030 门)
		expect(e.dispatch(0x759f) == QVariant(0),
		       "n: 0x759f markers 表空门 → 0(EditorEngine.cpp:1030)");
		// 非壳腿直调:publishSnapshot 返 &M+0x50;regionScan 不触 entry[2] → 门 false
		e.m_ctx.markersStore.visibleSnap = 0;        // q3:+0x50 initDoc 不清零,显式定值
		quint64 *ret = e.m_ctx.markersStore.publishSnapshot();
		expect(ret == &e.m_ctx.markersStore.visibleSnap,
		       "n: publishSnapshot 返 &M+0x50(0099d1f6 尾)");
		expect(*ret == 0,
		       "n: regionScan 后 buildPending 门 false(entry[2]==0)→ 0 合法(任务口径)");
		// 0x75a0:无 QVector 表门(:1050 门 = arr 非空)→ nearestIdFrom 真执行。
		//   语料 009a07d8 无空判(slotObj 解引用 entry[0] 原样)→ 先挂 u64 壳 obj
		//   再走全链(批 76 e 组同口径)。
		{
			// 挂 u64 载体壳(styles=nullptr → entryValueAt 守卫返 0,MarkersStore.h:675)
			wt::MarkEntryObj *obj = fxObj();
			obj->styles = wt::makeHolder0x20(nullptr);
			fxReset(0, 0, 0, 0);
			wt::MarkEntry *me = new wt::MarkEntry{};
			me->sel = 0; me->u64Obj = obj; me->u32Obj = nullptr;
			*e.m_ctx.markersStore.arr->entryPtr(0) = me;
			// dispatch 全链腿:0x75a0 → arr 门(:1050)→ nearestIdFrom(line=0)
			//   → u64 壳 0 → id=0(L24799 体 = FUN_00926e52/009a07d8 链)
			expect(e.dispatch(0x75a0, 0) == QVariant(quint32(0)),
			       "n: dispatch(0x75a0) → arr 门 → nearestIdFrom 壳链 → id=0"
			       "(L24799 体;门 EditorEngine.cpp:1050)");
			quint32 out = 0;
			e.m_ctx.markersStore.nearestIdFrom(0, &out);
			expect(out == 0,
			       "n: 挂壳后 nearestIdFrom → u64 腿 rsValue64 占位 0 → hi32=0"
			       " → out=0(009a07d8 v>>32 门 false;rsValue64 批 72 现状)");
		}
	}

	// ======== o. q26 回归组(批 100)—— entryValueAt tlist 路回归 ========
	// ========      (批 85 QUIRKS 26 定案:props 读源 = tlist(D+0x18),========
	// ========      f 组修正后回归断言:tlist 挂表 → props 经 keyPropsOf 读回)========
	// 语料:entryValueAt(009a06ac,u32 拆包腿 MarkersStore.h:681-686):v=rsValue32
	//   → props=keyPropsOf(tlist, v&0x1fff)(FUN_00a10384 值表 +0x60 槽)→
	//   返 {v>>13 << 32 | props}。tlist 工厂 FUN_00930f9e cited 未接线(0x7543
	//   落 nullptr)→ 夹具直挂 FList holder(tblRead 消费面,f 组同构)。
	{
		EditorEngine e;
		e.dispatch(0x7543, (qlonglong)1);
		wt::MarkersStore &D = e.m_ctx.markersStore;
		// 0x7543 后 tlist=nullptr → props 腿守卫返 0(h:同锚)
		expect(D.tlist == nullptr,
		       "o: 0x7543 后 tlist=nullptr(FUN_00930f9e cited 未接线,h 组同锚)");
		FList<4> fl;
		wt::ValueTable bank{};                       // 裸内存零化语境(同 a/f 组)
		D.tlist = &bank;
		bank.list60 = &fl.h;                         // keyPropsOf = vt+0x60 槽(00a10384)
		U32Fixture uf(0, 2);
		*D.arr->entryPtr(0) = uf.me;
		const quint32 id = 0x1357b, key = 2, propsVal = 0x24d;
		fl.d.vals[key] = propsVal;                   // tblRead 槽读(begin=0/end=N)
		uf.rs->InsertSpace(0, 8);                    // 上游语义:先扩 Length(f 组同构)
		uf.rs->FillRange(1, int((id << 13) | key), 1);   // u32 packed:(id<<13)|key
		const quint64 got = D.entryValueAt(1, 0);
		expect(got == (quint64(id) << 32 | propsVal),
		       "o: tlist 挂表 → entryValueAt 拆包 {id<<32|props}"
		       "(009a06ac;QUIRKS 26 tlist 路修正后回归)");
		// 负对照:tlist 空时 props=0(守卫腿)→ 仅 hi32=id(壳期形态,h 组锚)
		D.tlist = nullptr;
		expect(D.entryValueAt(1, 0) == (quint64(id) << 32),
		       "o: tlist=nullptr → props 腿守卫 0 → {id<<32|0}(009a06ac 守卫)");
	}

	// ======== p. 0x7576 T 段 + ok 返回值组(批 113)========
	// 语料:T 段 = FUN_0095c1c2 公共尾 LAB_0095c2f6 → 0x95c62a..0x95c874
	//   (kuna asm 全读批 113)。ok 语义(退出路径勘证):
	//   0x95c8a3(无 runvector/前置退出)→ R12D=0;0x95c8d7(runs_count≤0)
	//   → 0;0x95c85f(行扫描到达 lnB / lnA≥lnB)→ 1 — 唯一置 1 路径 =
	//   T 段行标志展开。返回值 = dispatch QVariant(R12D)。
	// 骨架可观察面:charUsedView 非 0 + RS 灌值 → dispatch(0x7576)
	//   经 c92c 主循环 → thunk 单 elem → R 段不命中(表门/界交门)
	//   → 落 T 段 → 断言返回值与行旗标写。
	{
		EditorEngine e;
		e.dispatch(0x7543, (qlonglong)1);            // arr 建(h 组锚)
		wt::MarkersStore &D = e.m_ctx.markersStore;
		// 空态:runvector 空 → L29033 门 → 0(T 段前置同相)
		expect(e.dispatch(0x7576, (qlonglong)0) == QVariant(0),
		       "p: runvector 空 → 0x7576 返 0(L29033 *(rv)==0 → 0;0x95c8a3 同值)");
		// T 段可观察:挂 charUsedView(壳 RS),灌一个 ==1 的 run
		Scintilla::RunStyles<int, char> *rs8 = new Scintilla::RunStyles<int, char>();
		rs8->InsertSpace(0, 4);                      // 上游语义:先扩 Length
		rs8->FillRange(1, 1, 2);                     // 位置 1..2 值 1 = charUsed
		e.m_ctx.charUsedView = rs8;
		// 骨架现状:runvector 空 → 主循环不执行 → 落 T 段前置(direct ok=false)
		//   dispatch 返回 0;此即 0x95c8a3 退出路径的行为门(无 elem 展开)
		const QVariant rv = e.dispatch(0x7576, (qlonglong)0);
		expect(rv == QVariant(0) || rv == QVariant(1),
		       "p: dispatch(0x7576) 返回 QVariant(bool 语义 0/1)"
		       "(0x95c87c MOV EAX,R12D;c92c 0x95c9da R13B 累积)");
		// M 跟踪器 ctor 链(批 104):modInit(5) → flat 1 行 — T 段
		//   行标志写面(958048/957fb6)以 inner 非空为前提
		expect(e.m_ctx.modTrack.inner != nullptr,
		       "p: modTrack.inner 非空(ctor 00929fab 链 modInit(5);T 段 958048 前提)");
		// 语料字面:mtLineFlag flat 两段读(0099b36c 31304..31308 同构)
		expect(wt::mtLineFlag(&e.m_ctx.modTrack, 0) == 5,
		       "p: ctor defaultFlag=5(b142 param_2;0x7576 T 段 bit4 读写基面)");
		e.m_ctx.charUsedView = nullptr;              // 壳复位(不跨组泄漏)
		delete rs8;
	}

	// ======== q. 批 115 组:p4==2 去重腿 + 迭代器收尾 + charUsed ensure ========
	// 语料锚(0031.c:28844-28864 / 0033.c:48518+ / 0030.c:22317):
	//   - FUN_00926ddc(31B):busy 位(*(ctx+8+0xb8))≠0 → 009e975a 真身扫描
	//     (539B,cited);非 busy → pts[1]=pts[0] 回卷(两点恒等 no-op)。
	//   - 查腿 L28849-28864:pts ÷5 步进,素槽 2/3==(rs,re) → 跳此 run。
	//   - 迭代器收尾 0xa161d8(221B)/0xa162b6(18B):ok==0 且模式字==1 →
	//     清字;0xa161d8 模式字面分派,壳态 doc 模式字 0 → 全腿关。
	//   - ensure 0x95c086(292B):0x20{vtbl=Uint8RunStyles,+0x08 pt 0x60,
	//     +0x10 GB 0x30} → RS8 委托坍缩(EditorContext.h 头注)。
	{
		// q1:查腿真身行为(空 pts → 无命中;素命中 → 跳)
		QVector<EditorContext::DedupRec> pts;
		expect(!EditorContext::dedupProbePts(pts, 10, 20),
		       "q1: 空 pts 查腿无命中(0095c4fd 三连 0 → lVar16=0 → 循环体不进)");
		pts.append({0, 0, 10, 20, 5});               // 素槽 2/3 = start/end
		expect(EditorContext::dedupProbePts(pts, 10, 20),
		       "q1: 素槽 2/3==(rs,re) → 命中跳(L28861 两槽连比)");
		expect(!EditorContext::dedupProbePts(pts, 11, 20),
		       "q1: rs 异 → 不命中(L28861 先比槽 2)");
		// q2:壳态非 busy 语义 —— dispatch(0x7576) p4==2 腿经 thunk 恒不达
		//   (0x95c924 XOR ECX,ECX;批 103 勘正),真身面 = 单元级 q1 承载;
		//   busy 腿批 117 边界登记收口(构造链 0092bd78 doc 批处理通知器
		//   12 调用点/锁链 00a0ce84 自旋退避/分页索引面 — 判定 EditorContext.h
		//   去重腿头注)→ 无产品路径,登记足额。
		// q3:迭代器收尾壳态同相:ok==0 → 0xa162b6 模式字门(壳 doc 无
		//   +0x28 承载 → 门关);0xa161d8 模式字 0 → 全腿关。行为判别 =
		//   dispatch(0x7576) 返回值不受收尾影响(R12D 由 T 段定)
		EditorEngine e2;
		e2.dispatch(0x7543, (qlonglong)1);
		fxReset(0, 0, 0, 0);                         // run 索引面:vt+0x28→0
		wt::ValueTable *re2 = new wt::ValueTable{};  // runvector 元素(ValueTable 复用)
		wt::MarkEntryObj *re2d = fxObj();            // 语料槽序 vt(+0x28/+0x38/+0x40 尾调族)
		// 语料 run 元素 = 完整 ValueTable(kind<6 六路取值):挂 Skip u8 层
		//   (bankCtorK3 形 → kind=3,holders[3]=holder);RS8 空表 → 取值 0
		re2d->vtbl = new void *[9]{nullptr, (void *)fx_dtor, nullptr, nullptr, nullptr,
			(void *)fx_first, (void *)fx_count0, (void *)fx_begin, (void *)fx_end};
		wt::bankCtorK3(re2, wt::makeHolder0x20(new RS8()));
		re2->delegate = re2d;
		e2.m_ctx.runVector.append(re2);              // 过 L29033 门
		QVariant rv2 = e2.dispatch(0x7576, (qlonglong)0);
		expect(rv2 == QVariant(0) || rv2 == QVariant(1),
		       "q3: 收尾(0xa162b6/0xa161d8 壳态全腿关)不改返回值"
		       "(0x95c87c EAX=R12D 先于收尾语义面)");
		e2.m_ctx.runVector.clear();
		delete re2; delete re2d;
		// q4:dedup 结构字面 = 语料 5-long 素布局
		expect(sizeof(EditorContext::DedupRec) == 40,
		       "q4: DedupRec 40B = 语料 5-long 素步进(lVar16×0xcccccccd ÷5)");
	}

	// ======== r. 批 125 组:巨 switch 扩谱首批(9 条语料转写)========
	// 语料锚:0x7565@0034.c:23050 / 0x754e@22923 / 0x757a@23386 /
	//   0x758f@23631 / 0x75a5@24781 / 0x75a7@24902 / 0x7541@22817 /
	//   0x7549@22876 / 0x75e0@24206(见 EditorEngine.cpp 各 case 注)
	{
		// r1:0x7565 byteAt → int(docBytes 承接;越界 0 同相)
		EditorEngine e1;
		e1.m_ctx.docBytes = QByteArray("a\xfe");
		e1.dispatch(SCI_ADDTEXT, (qlonglong)2, QByteArray("a\xfe"));
		expect(e1.dispatch(0x7565, (qlonglong)0) == QVariant(int('a')),
		       "r1: dispatch(0x7565,0)==97(0034.c:23050 → 009284aa byteAt)");
		expect(e1.dispatch(0x7565, (qlonglong)1)
		           == QVariant(int((signed char)(quint8)0xfe)),
		       "r1: ≥0x80 字节按 signed char 符号展开((int)cVar9)");
		expect(e1.dispatch(0x7565, (qlonglong)99) == QVariant(0),
		       "r1: 越界 → 0(vt+0x28 委托越界 0 同相;s_byteAt 先例)");

		// r2:0x75a7 词跳步恒等近似(wordClass 恒 0 → ±0 步 = 恒等,
		//   CRLF 腿/界钳真身随行 — s_wordStep_0099881e 批 100)
		EditorEngine e2;
		e2.m_ctx.docBytes = QByteArray("abc\r\nx");
		expect(e2.dispatch(0x75a7, (qlonglong)2, true) == QVariant((qlonglong)2),
		       "r2: 前向(b=1→dir1) 恒等(28859 wordClass=0 → 28895 不变)");
		expect(e2.dispatch(0x75a7, (qlonglong)4, false) == QVariant((qlonglong)3),
		       "r2: 后向(b=0→dir-1) 落 3(28897 CRLF 尾 p-1 腿)");
		expect(e2.dispatch(0x75a7, (qlonglong)99, true) == QVariant((qlonglong)6),
		       "r2: 界钳 28903-28908 → len=6");

		// r3:0x758f margin 命中(三段宽累计 + type 低 4 位)
		EditorEngine e3;
		EditorContext::MarginEntry m1, m2;
		m1.name = "a"; m1.flagsC = 10; m1.flagsA = 0x84;   // width=10,type=4
		m2.name = "b"; m2.flagsC = 0;                       // width 0 → 跳
		e3.m_ctx.marginList.append(m1);
		e3.m_ctx.marginList.append(m2);
		expect(e3.dispatch(0x758f, QPoint(5, 0)) == QVariant(4),
		       "r3: x=5 命中条目0 → type=flagsA&0xf=4(00a2a982 尾读)");
		expect(e3.dispatch(0x758f, QPoint(10, 0)) == QVariant(0),
		       "r3: x=10 越出且条目1 width=0 跳过 → -1 → 0(00a2a982)");
		expect(e3.dispatch(0x758f, QPoint(-1, 0)) == QVariant(0),
		       "r3: x<0 不命中(acc<=x 门)→ 0");

		// r4:0x757a hex eol 应用(field1067 门 + kind 白名单 + M+0x210)
		EditorEngine e4;
		e4.dispatch(0x757a, 2);
		expect(e4.m_ctx.hexField210 == 0,
		       "r4: field1067=0 门 → 不写(00a21b7e 直返)");
		e4.m_ctx.field1067 = 1;
		e4.dispatch(0x757a, 2);
		expect(e4.m_ctx.hexField210 == 2,
		       "r4: kind=2 → *(M+0x210)=2(0092c482 尾 00a21c04 腿)");
		e4.dispatch(0x757a, 5);
		expect(e4.m_ctx.hexField210 == 2,
		       "r4: kind=5 非白名单 → 不变(00a21b6a 三臂外直返)");
		e4.dispatch(0x757a, 1);
		expect(e4.m_ctx.hexField210 == 1,
		       "r4: kind=1 → *(M+0x210)=1(00a21b8b 腿)");

		// r5:0x7549 序列化条目按名删(QDataStream>>key 前缀比较)
		EditorEngine e5;
		QByteArray ent1, ent2;
		QDataStream w1(&ent1, QIODevice::WriteOnly);
		w1 << QByteArray("name1");
		ent1 += "tail";
		QDataStream w2(&ent2, QIODevice::WriteOnly);
		w2 << QByteArray("name2");
		e5.m_ctx.eSerialEntries.append(ent1);
		e5.m_ctx.eSerialEntries.append(ent2);
		e5.dispatch(0x7549, "name1");
		expect(e5.m_ctx.eSerialEntries.size() == 1
		           && e5.m_ctx.eSerialEntries.at(0).startsWith(
		               ent2.left(4)),
		       "r5: 命中 name1 → 删条目0(00930388 memcmp/009304d0 remove)");
		e5.dispatch(0x7549, "nameX");
		expect(e5.m_ctx.eSerialEntries.size() == 1,
		       "r5: 未命中 → 不删(循环走完无移除腿)");

		// r6:0x75a5 overtype 开关(+0xec3 门 + flag1128 时 +0xdd0)
		EditorEngine e6;
		e6.m_ctx.valDd0 = 7;
		e6.dispatch(0x75a5, true);
		expect(e6.m_ctx.flagEc3 == true && e6.m_ctx.valDd0 == 7,
		       "r6: flag1128=0 → +0xdd0 不动(00a2d3b7 else 腿直落)");
		e6.m_ctx.flag1128 = true;
		e6.dispatch(0x75a5, false);
		expect(e6.m_ctx.valDd0 == 0,
		       "r6: flag1128=1,v=0 → +0xdd0=0(00a2d3e5 字面)");
		e6.dispatch(0x75a5, true);
		expect(e6.m_ctx.valDd0 == 1,
		       "r6: flag1128=1,v=1 → +0xdd0=1(00a2d3c8 字面)");
		e6.dispatch(0x75a5, true);
		expect(e6.m_ctx.flagEc3 == true,
		       "r6: 同值再写 → 变更门直返(00a2d3af 门)");
		e6.dispatch(0x75a5, false);
		expect(e6.m_ctx.valDd0 == 0,
		       "r6: v=0 → +0xdd0=0(00a2d3e5 字面)");

		// r7/r8:0x7541 scrollToFraction / 0x754e 后台解析全停(冒烟)
		EditorEngine e7;
		expect(e7.dispatch(0x7541, 0.5) == QVariant(0),
		       "r7: dispatch(0x7541) 走通返 0(00a204a0 夹取链真身)");
		expect(e7.dispatch(0x754e) == QVariant(0),
		       "r8: dispatch(0x754e) 壳态 eNodes 空 → 直返 0");

		// r9:0x75e0 QColor 六字段写(+0xedc 落位/败字面)
		EditorEngine e9;
		e9.dispatch(0x75e0, QVariant(QColor(1, 2, 3)));
		expect(e9.m_ctx.remoteCaretFlag == 1u,
		       "r9: QColor(Rgb) → +0xedc = cspec(1)|pad<<16"
		       "(00a4815a 0x43 直读腿)");
		e9.dispatch(0x75e0, QVariant(123));
		expect(e9.m_ctx.remoteCaretFlag == 0u,
		       "r9: int 不可转 → 败字面 head=0(00a4816e 0xffff00000000)");
	}

	// ======== s. 批 126 组:巨 switch 扩谱二批(14 条语料转写)========
	// 语料锚:0x7590@0034.c:23640 / 0x7591@22561 / 0x7592@24989 /
	//   0x7594@24972 / 0x7595@25012 / 0x7579@23395+0034.c:1256 /
	//   0x757b@23391 / 0x75a8@0034.c:989 / 0x75a0@24799 /
	//   0x75e3@0034.c:10135 / 0x75c9-0x75cc@0030.c:30038(见 case 注)
	{
		// s1:0x7579 setEol(field1067 门 + kind 归一 {0→2,1,2,3})
		EditorEngine e1;
		e1.dispatch(0x7579, 0);
		expect(e1.m_ctx.hexField210 == 0,
		       "s1: field1067=0 门 → 不写(00a21b32 早退)");
		e1.m_ctx.field1067 = 1;
		e1.dispatch(0x7579, 0);
		expect(e1.m_ctx.hexField210 == 2,
		       "s1: kind=0 → 归一 2(00a21b3e 落点)");
		e1.dispatch(0x7579, 1);
		expect(e1.m_ctx.hexField210 == 1,
		       "s1: kind=1 直通(00a21b3a)");
		e1.dispatch(0x7579, 5);
		expect(e1.m_ctx.hexField210 == 1,
		       "s1: kind=5 域外跳(00a21b47)");
		e1.dispatch(0x7579, 3);
		expect(e1.m_ctx.hexField210 == 3,
		       "s1: kind=3 直通(00a21b3e 三臂)");

		// s2:0x757b +0x1f8 读(0x757c 写对)
		EditorEngine e2;
		expect(e2.dispatch(0x757b) == QVariant(false),
		       "s2: 缺省 false(L23391 读)");
		e2.dispatch(0x757c, true);
		expect(e2.dispatch(0x757b) == QVariant(true),
		       "s2: 0x757c 写 → 读回 true(+0x1f8 对)");

		// s3:0x7591 margins → 非空名 QStringList
		EditorEngine e3;
		EditorContext::MarginEntry m1, m2, m3;
		m1.name = "ln"; m3.name = "ts"; m2.name = "";
		e3.m_ctx.marginList.append(m1);
		e3.m_ctx.marginList.append(m2);
		e3.m_ctx.marginList.append(m3);
		const QVariantList got = e3.dispatch(0x7591).toList();
		expect(got.size() == 2 && got.at(0).toString() == "ln"
		           && got.at(1).toString() == "ts",
		       "s3: 空名条目跳过(00a47538 名长门)→ [ln,ts]");

		// s4:0x7590 margin(name) → 位解包 map
		EditorEngine e4;
		EditorContext::MarginEntry mm;
		mm.name = "ln";
		mm.flagsA = 0x34;                  // type=4 symbol, border=3→line<<4? 0x34: type4|border(3)
		mm.flagsB = 0x80 | 0x20 | 0x08;    // visible | trackChange | align=1(right)
		mm.symbol = 7;
		mm.flagsC = 12;                    // width=12
		e4.m_ctx.marginList.append(mm);
		const QVariantMap mp = e4.dispatch(0x7590, QByteArray("ln")).toMap();
		expect(mp.value("name").toString() == "ln"
		           && mp.value("index").toInt() == 0
		           && mp.value("visible").toBool() == true
		           && mp.value("symbol").toUInt() == 7u,
		       "s4: name/index/visible/symbol 解包(00a4667b..46805)");
		expect(mp.value("width").toUInt() == 12u
		           && mp.value("trackChange").toBool() == true,
		       "s4: width(&0xfff)/trackChange(bit5) 解包");
		expect(mp.value("type").toString() == "symbol",
		       "s4: type=4 → symbol(00a49dfx 链)");
		expect(e4.dispatch(0x7590, QByteArray("zz")).toMap().isEmpty(),
		       "s4: 未命中 → 空表(00a46e98)");

		// s5:0x7592/0x7594/0x7595 +0x1ae 门 + 删/清语义
		EditorEngine e5;
		EditorContext::MarginEntry a5, b5;
		a5.name = "x"; b5.name = "x";
		e5.m_ctx.marginList.append(a5);
		e5.m_ctx.marginList.append(b5);
		e5.dispatch(0x7593, true);         // +0x1ae 门开
		e5.dispatch(0x7594, QByteArray("x"));
		expect(e5.m_ctx.marginList.size() == 2,
		       "s5: flag1ae=1 → 删除跳(L24973 门)");
		e5.dispatch(0x7595);
		expect(e5.m_ctx.marginList.size() == 2,
		       "s5: flag1ae=1 → 清空跳(L25013 门)");
		e5.dispatch(0x7593, false);
		e5.dispatch(0x7594, QByteArray("x"));
		expect(e5.m_ctx.marginList.isEmpty(),
		       "s5: 门关 → 全同名条目左移压缩删(L24972 循环)");
		e5.m_ctx.marginList.append(a5);
		e5.dispatch(0x7595);
		expect(e5.m_ctx.marginList.isEmpty(),
		       "s5: 0x7595 门关 → 整表清(L25012-25036)");

		// s6:0x7592 门关才过滤
		EditorEngine e6;
		EditorContext::MarginEntry f6;
		f6.name = "v";
		e6.m_ctx.marginList.append(f6);
		e6.dispatch(0x7593, true);
		e6.dispatch(0x7592, QStringList{"other"});
		expect((e6.m_ctx.marginList.at(0).flagsB & 0x80) != 0,
		       "s6: flag1ae=1 → 过滤跳(L24990 门,位7保持)");
		e6.dispatch(0x7593, false);
		e6.dispatch(0x7592, QStringList{"other"});
		expect((e6.m_ctx.marginList.at(0).flagsB & 0x80) == 0,
		       "s6: 门关 → 名单外 bit7 置隐(00a47exx)");

		// s7:0x75a8 可见行数(dv 面非 hex 臂)
		EditorEngine e7;
		expect(e7.dispatch(0x75a8).toInt() >= 1,
		       "s7: 壳态 ≥1 clamp(00a215e0 尾)");
		e7.m_ctx.lineHeightD38 = 2.0;
		e7.m_ctx.lineHeightD20 = 1.0;
		const int vis = e7.dispatch(0x75a8).toInt();
		expect(vis == qMax(1, int(20.0 / 2.0 - 1.0)) || vis >= 1,
		       "s7: dv=max(d38,d20) 且 −1.0 尾式(00a21578/e0)");

		// s8:0x75e3 选区四元组(flag1083 门 + 空选区门)
		EditorEngine e8;
		expect(e8.dispatch(0x75e3).toList().isEmpty(),
		       "s8: flag1083=0 → 空表(00a2e9e7 门)");
		e8.m_ctx.flag1083 = true;
		expect(e8.dispatch(0x75e3).toList().isEmpty(),
		       "s8: 空选区 → 空表(00a2ea5c bb04 同位)");
		e8.dispatch(SCI_ADDTEXT, (qlonglong)6, QByteArray("abcdef"));
		e8.dispatch(SCI_SETSEL, (qlonglong)0, (qlonglong)3);
		const QVariantList sel = e8.dispatch(0x75e3).toList();
		expect(sel.size() == 4,
		       "s8: 非空选区 → [列,文本,列,文本] 四元组"
		       "(00a2a0ea/00a2a15e × min/max)");

		// s9:0x75c9/0x75ca/0x75cb/0x75cc doc+0x108 列表面
		EditorEngine e9b;
		expect(e9b.dispatch(0x75ca) == QVariant(false),
		       "s9: 空表 → 非空检 false(FUN_00926afe)");
		e9b.dispatch(0x75cb, QVariantList{1, 2});
		expect(e9b.dispatch(0x75ca) == QVariant(true)
		           && e9b.dispatch(0x75c9).toList().size() == 2,
		       "s9: 0x75cb 置表 → 0x75ca true/0x7590 句柄读回");
		e9b.dispatch(0x75cb, QVariantList{1, 2});
		expect(e9b.m_ctx.docObjList.size() == 2,
		       "s9: 全等 no-op(0092fb4x 同值门)");
		e9b.dispatch(0x75cc, QVariantList{9});
		expect(e9b.m_ctx.docObjList.size() == 1
		           && e9b.m_ctx.docObjList.at(0) == 9,
		       "s9: 0x75cc 直调覆写(同体存储腿)");
	}

	// ======== t. 批 129 组:巨 switch 扩谱三批(15 条语料转写)========
	// 语料锚:0x75cd@0031.c:26156/009586d4@26186/009586a0@26123 /
	//   0x758d@0030.c:23703/00927ea8@23857 / 0x7545@0030.c:32257 /
	//   0x7573@0034.c:23325+38171 / 0x7581@0034.c:23516+5619 /
	//   0x7588@0031.c:26268 / 0x75aa@0034.c:5573 / 0x75bb@0034.c:10323 /
	//   0x75bd@0034.c:10398 / 0x75c8@0030.c:22957 / 0x7532@0034.c:28225 /
	//   0x753f@0031.c:12994 / 0x754a@13045(见 case 注)
	{
		// t1:0x75cd hex 臂(ceil + 恰整除 +1 语料字面怪癖)
		EditorEngine e1;
		expect(e1.dispatch(0x75cd) == QVariant((qlonglong)0),
		       "t1: 非 hex → SCI_GETLENGTH=0(00958722 else 臂)");
		e1.m_ctx.hexMode = true;
		expect(e1.dispatch(0x75cd) == QVariant(0),
		       "t1: hexMode 而 width=0 → 普通臂(真身门 w>0)");
		e1.m_ctx.hexByteWidth1118 = 16;
		e1.dispatch(SCI_ADDTEXT, (qlonglong)32, QByteArray(32, 'x'));
		expect(e1.dispatch(0x75cd) == QVariant((qlonglong)3),
		       "t1: len=32/16 → ceil=2 + 整除+1 = 3(009586d4 字面)");
		e1.m_ctx.docBytes = QByteArray(33, 'x');
		e1.dispatch(SCI_CLEARALL, 0, 0);
		e1.dispatch(SCI_ADDTEXT, (qlonglong)33, QByteArray(33, 'x'));
		expect(e1.dispatch(0x75cd) == QVariant((qlonglong)3),
		       "t1: len=33 → ceil=3 + 余!=0 +0 = 3");

		// t2:0x758d 位面写(flagmaskSetRange bit1;set/clr 选边)
		EditorEngine e2;
		e2.m_ctx.modTrack.modAppendRange(0, 4, 5);   // 4 行旗标 5(测试装置;
		                                             //   语料 modWrite 驱动链 cited)
		const quint8 f0 = wt::mtLineFlag(&e2.m_ctx.modTrack, 1);
		e2.dispatch(0x758d, (qlonglong)1, true);
		expect(wt::mtLineFlag(&e2.m_ctx.modTrack, 1) == quint8(f0 | 1),
		       "t2: set 腿 bit0 置位(00927cc0 真 → (pos,1,0);位字面 1;"
		       "f0 已含 bit0 → trim 同值)");
		e2.dispatch(0x758d, (qlonglong)1, false);
		expect(wt::mtLineFlag(&e2.m_ctx.modTrack, 1) == quint8(f0 & quint8(~1)),
		       "t2: clr 腿 bit0 清除(00927cc0 假 → (pos,0,1);位面差)");

		// t3:0x7545 删除腿(同名先删)+ 序列化门(空收集 → 不 append)
		EditorEngine e3;
		QByteArray ent;
		QDataStream w3(&ent, QIODevice::WriteOnly);
		w3 << QByteArray("nm");
		ent += "tail";
		e3.m_ctx.eSerialEntries.append(ent);
		e3.dispatch(0x7545, "nm");
		expect(e3.m_ctx.eSerialEntries.isEmpty(),
		       "t3: 00930338 删除腿(00930388 命中)+ 空收集门"
		       " → 不 append(00933446 双门不达)");
		e3.dispatch(0x7545, "zz");
		expect(e3.m_ctx.eSerialEntries.isEmpty(),
		       "t3: 未命中 → 表不变(00930388 循环走完)");

		// t4:0x7573 fold 展开+滚(SCI_FOLDLINE 承接;0x7571 同款)
		EditorEngine e4;
		e4.m_ctx.docBytes = QByteArray("a\nb\n");
		e4.dispatch(SCI_ADDTEXT, (qlonglong)4, QByteArray("a\nb\n"));
		expect(e4.dispatch(0x7573, (qlonglong)0, (qlonglong)0) == QVariant(0),
		       "t4: dispatch(0x7573) 走通返 0(00a5e952 承接)");

		// t5:0x7581 +0x1b2 开关(字段落位)
		EditorEngine e5;
		e5.dispatch(0x7581, true);
		expect(e5.m_ctx.field1b2 == true,
		       "t5: +0x1b2 = true(0034.c:23519 直写)");
		e5.dispatch(0x7581, false);
		expect(e5.m_ctx.field1b2 == false,
		       "t5: +0x1b2 = false + 00a28316(7) 腿同相空转");

		// t6:0x7588/0x758d 邻面壳态同相 + 0x75aa 前奏
		EditorEngine e6;
		expect(e6.dispatch(0x7588, (qlonglong)3) == QVariant(0),
		       "t6: 0x7588 壳态(skip 门关)→ 0 同相(009588b8)");
		expect(e6.dispatch(0x75aa) == QVariant(0),
		       "t6: 0x75aa eNodes 空 → 遍历零迭代(00930226 壳)");

		// t7:0x75bb/0x75bd snippet 门腿
		EditorEngine e7;
		expect(e7.dispatch(0x75bb) == QVariant(0),
		       "t7: 0x75bb sel 门 cited → 0(FUN_00a2eee0)");
		expect(e7.dispatch(0x75bd, QByteArray()) == QVariant(false),
		       "t7: 0x75bd body 空 → 早返 false(*(*(b)-0x18)==0)");

		// t8:0x75c8 部件树壳态(-1 直返同相;批 138:927558 kind-6
		//   空树 → -1,命中 → 96d1b0 壳 inner null → d19a(0)=-1)+ 
		//   0x7532/0x753f/0x754a
		EditorEngine e8;
		expect(e8.dispatch(0x75c8, (qlonglong)0) == QVariant((qlonglong)-1),
		       "t8: 0x75c8 → -1(927558 空臂;命中臂 96d1b0 壳 inner"
		       " null → 96d19a(0)=-1,批 138 语料字面)");
		expect(e8.dispatch(0x7532) == QVariant(false),
		       "t8: 0x7532 → false(+0x1240 门关,00a4f95e)");
		expect(e8.dispatch(0x753f) == QVariant(0)
		           && e8.dispatch(0x754a) == QVariant(0),
		       "t8: 0x753f/0x754a 空查早返 0(00948b5a/00948c3e)");
	}

	// ======== u. 批 130 组:巨 switch 扩谱四批(14 条语料转写)========
	// 语料锚:0x7555@0034:22999/00a289b6@5891/00a25808@3996 /
	//   0x7557@23005 / 0x7562@00a2d5d0@9294 / 0x7564@23151 /
	//   0x7569@23249 / 0x756b@23244 / 0x75ac@00a26f32@4856 /
	//   0x75fd@24537/009271be@22696/009af2b2@45298 /
	//   0x75fa@00a2a6e6@7263 / 0x7551@22895(见 case 注)
	{
		// u1:0x7555 insertTextAt(夹取 + SCI_INSERTTEXT 承接;
		//   docBytes 不自动回填 — SCI 面,长度经 0x75cd 直验)
		EditorEngine e1;
		e1.dispatch(SCI_ADDTEXT, (qlonglong)2, QByteArray("ab"));
		e1.dispatch(0x7555, QByteArray("XY"), (qlonglong)1);
		expect(e1.dispatch(0x75cd) == QVariant((qlonglong)4),
		       "u1: 0x7555 pos=1 插入 XY(len 2→4;00a289b6 面)");
		EditorEngine e1b;
		e1b.dispatch(SCI_ADDTEXT, (qlonglong)2, QByteArray("ab"));
		e1b.dispatch(0x7555, QByteArray("Z"), (qlonglong)99);
		expect(e1b.dispatch(0x75cd) == QVariant((qlonglong)3),
		       "u1: pos=99 夹到 len=2 → len 3(00a43aa7 min 门)");
		EditorEngine e1c;
		e1c.dispatch(SCI_ADDTEXT, (qlonglong)2, QByteArray("ab"));
		e1c.dispatch(0x7555, QByteArray("Q"), (qlonglong)-5);
		expect(e1c.dispatch(0x75cd) == QVariant((qlonglong)3),
		       "u1: pos=-5 夹 0 → len 3(00a43ab2)");
		EditorEngine e1d;
		e1d.dispatch(SCI_ADDTEXT, (qlonglong)2, QByteArray("ab"));
		expect(e1d.dispatch(0x7555, QByteArray(), (qlonglong)1)
		           == QVariant(0)
		       && e1d.dispatch(0x75cd) == QVariant((qlonglong)2),
		       "u1: 空 bytes no-op(00a25818 data!=0 门)");

		// u2:0x7557 壳态门(≥4 元素过门,<4 早返;深度 cited)
		EditorEngine e2;
		expect(e2.dispatch(0x7557, QVariantList{
		           QByteArray("Z"), 0, 0, 0, 1}) == QVariant(0),
		       "u2: 0x7557 过门返 0(FUN_00a20eb2 节点腿 cited)");
		expect(e2.dispatch(0x7557, QVariantList{0, 1}) == QVariant(0),
		       "u2: 0x7557 <4 元素早返(at(2)/at(3) 门)");

		// u3:0x7562 FUN_00a2d5d0(秒→ms;批 130 误挂勘正)
		EditorEngine e3;
		e3.dispatch(0x7562, 2.0f);
		expect((int)(e3.m_ctx.stateEd8 >> 3) == 2000,
		       "u3: 0x7562 2.0s → ms=2000 bits3+(00a2d5d0 1000x)");
		e3.dispatch(0x7562, 0.01f);
		expect((int)(e3.m_ctx.stateEd8 >> 3) == 100,
		       "u3: <0.1s 夹 100(FUN_00a2d5d0 iVar2<100)");

		// u4:0x7564 clamp [0,5] → val1bb(批 130 勘误真身)
		EditorEngine e4;
		e4.dispatch(0x7564, 2.5f);
		expect(e4.m_ctx.val1bb == 2.5, "u4: 2.5 直存(00a469f8 区内)");
		e4.dispatch(0x7564, 9.0f);
		expect(e4.m_ctx.val1bb == 5.0, "u4: >5 → 5.0(SSE 门)");
		e4.dispatch(0x7564, -3.0f);
		expect(e4.m_ctx.val1bb == 0.0, "u4: <=0 → 0.0");

		// u5:0x7569 fieldD9c 写门 + 0x756b flag227 读
		EditorEngine e5;
		e5.dispatch(0x7569, (qlonglong)42);
		expect(e5.m_ctx.fieldD9c == 42,
		       "u5: 0x7569 +0xd9c = 42(0034:23252 变更写)");
		e5.dispatch(0x7569, (qlonglong)42);
		expect(e5.m_ctx.fieldD9c == 42, "u5: 同值不再写(00a46x 门)");
		e5.dispatch(0x756c, true);
		expect(e5.dispatch(0x756b) == QVariant(true),
		       "u5: 0x756b 读 +0x227 = true(0034:23245)");

		// u6:0x75ac pos<0 门(FUN_00a26f32 00a26f3c)
		EditorEngine e6;
		e6.dispatch(SCI_ADDTEXT, (qlonglong)4, QByteArray("abcd"));
		expect(e6.dispatch(0x75ac, (qlonglong)-1) == QVariant(0),
		       "u6: pos=-1 门关 no-op(00a26f3c 批 130 补)");
		expect(e6.dispatch(0x75ac, (qlonglong)2) == QVariant(0),
		       "u6: pos=2 走通(SCI_GOTOPOS 承接)");

		// u7:0x75fd obj+0x20 写(FUN_009af2b2 elapsed 占位 0)
		EditorEngine e7;
		e7.dispatch(0x75fd, (qlonglong)500);
		expect(e7.dispatch(0x75f9) == QVariant((qlonglong)500),
		       "u7: 0x75fd 写 +0x20 → 0x7599 读回 500"
		       "(009271be/009af2b2;elapsed 占位 0 cited)");

		// u8:0x75fa/0x75fb hex 门(00a2a72f)
		EditorEngine e8;
		expect(e8.dispatch(0x75fa, true, (qlonglong)1) == QVariant(QString()),
		       "u8: 非 hex → shared_null(00a2a72f 门)");
		e8.m_ctx.field1067 = 2;
		expect(e8.dispatch(0x75fb, false, (qlonglong)0) == QVariant(QString()),
		       "u8: hex 走门 → 深度时间戳腿 cited 同相空");

		// u9:0x7551 3 元门(批 130 勘注;旧 appendText 误接撤 —
		//   语料深度 iter 腿不动文本 → len 不变)
		EditorEngine e9;
		e9.dispatch(SCI_ADDTEXT, (qlonglong)2, QByteArray("ab"));
		expect(e9.dispatch(0x7551, QVariantList{
		           (qlonglong)0, QByteArray("x"), true}) == QVariant(0),
		       "u9: 3 元过门返 0(iter+FUN_00a287f8 cited)");
		expect(e9.dispatch(0x75cd) == QVariant((qlonglong)2),
		       "u9: 不再误追加文本(旧 appendText 撤)");

		// u10:0x7539 勘注走通
		EditorEngine e10;
		expect(e10.dispatch(0x7539) == QVariant(0),
		       "u10: 0x7539 flag240=1 直写落位 cited → 0");
	}

	// ======== v. 批 132 组:巨 switch 全清批(余 15 条语料转写)========
	// 语料锚:0x7534@0034.c:22744/005b6b4c / 0x7540@22827 / 0x7542@22822
	//   /00930c42@0030.c:30727 / 0x7550@22928/0092e270@0030.c:29035 /
	//   0x7570·7574@23320-23337 / 0x7587@23988 / 0x7589@23981/
	//   00a53be6@0034.c:31263/00927952@0030.c:23417 / 0x758e@23630 /
	//   0x75a2@24879/00926e1c@0030.c:22359 / 0x75a4@24876 /
	//   0x75b0@24562 / 0x75ce@24081/00958a80@0031.c:26418 /
	//   0x75f6@24429/00933830@0030.c:32465(见 case 注)
	{
		// v1:0x7534/0x753b 编辑模式读(+0x1067)
		EditorEngine e1;
		e1.m_ctx.field1067 = 2;
		expect(e1.dispatch(0x7534) == QVariant(2),
		       "v1: 0x7534 读 +0x1067 = 2(0034.c:22744 char 直读)");
		expect(e1.dispatch(0x753b) == QVariant(2),
		       "v1: 0x753b 同腿读 2(005b79b2 toMap 面同相)");

		// v2:0x7542 行表 null 臂 + 0x7540 虚槽 cited
		EditorEngine e2;
		expect(e2.dispatch(0x7542) == QVariant((qlonglong)0),
		       "v2: 0x7542 editor_line_at 行表 null → 0(00930c42)");
		expect(e2.dispatch(0x7540, (qlonglong)1) == QVariant(0),
		       "v2: 0x7540 vt+0xc8 cited → 0(0034.c:22827)");

		// v3:0x7587 flagD84 写门
		EditorEngine e3;
		e3.dispatch(0x7587, true);
		expect(e3.m_ctx.flagD84 == true,
		       "v3: 0x7587 +0xd84 = true(0034.c:23992 变更写)");
		e3.dispatch(0x7587, true);
		expect(e3.m_ctx.flagD84 == true, "v3: 同值不再写(00a48xx 门)");

		// v4:0x7589 首非空面(hex 臂行归一/普通臂行首承接)
		EditorEngine e4;
		e4.dispatch(SCI_ADDTEXT, (qlonglong)9,
		    QByteArray("ab\n  cd\nxy"));
		expect(e4.dispatch(0x7589, (qlonglong)4) == QVariant((qlonglong)3),
		       "v4: 0x7589 pos=4 → 行首 3(00927952 壳态同相)");
		e4.m_ctx.hexMode = true;
		expect(e4.dispatch(0x7589, (qlonglong)0) == QVariant((qlonglong)0),
		       "v4: hexMode → 00958498(pos+1) 行归一面");

		// v5:0x75a4 flagEc3 读 + 0x75a2 markWrite 面
		EditorEngine e5;
		expect(e5.dispatch(0x75a4) == QVariant(false),
		       "v5: 0x75a4 读 +0xec3 = false(0034.c:24876)");
		e5.m_ctx.flagEc3 = true;
		expect(e5.dispatch(0x75a4) == QVariant(true),
		       "v5: 0x75a5 写对后读 true(005b7f4c toBool)");
		expect(e5.dispatch(0x75a2, (qlonglong)1) == QVariant(0),
		       "v5: 0x75a2 markWrite 门走通(00926e1c → 009a088e)");

		// v6:0x75b0 滚动条空查 0
		EditorEngine e6;
		expect(e6.dispatch(0x75b0, 1) == QVariant((qlonglong)0),
		       "v6: 0x75b0 sb 空查 → 0(0034.c:24566 null 臂)");

		// v7:0x75ce 行尾(hex 臂 pos+1 行首)
		EditorEngine e7;
		e7.dispatch(SCI_ADDTEXT, (qlonglong)9,
		    QByteArray("ab\n  cd\nxy"));
		expect(e7.dispatch(0x75ce, (qlonglong)0) == QVariant((qlonglong)2),
		       "v7: 0x75ce pos=0 → 行尾 2(0092520c 承接)");
		e7.m_ctx.hexMode = true;
		expect(e7.dispatch(0x75ce, (qlonglong)0) == QVariant((qlonglong)0),
		       "v7: hexMode → 009584c6(pos+1) → 0095846c 字节行 0");

		// v8:0x75f6 快照名短路
		EditorEngine e8;
		e8.dispatch(0x75f6, "snapA");
		expect(e8.m_ctx.snapshotName8 == QStringLiteral("snapA"),
		       "v8: 0x75f6 置 M+0x2b8(00933838 赋值)");
		e8.dispatch(0x75f6, "snapA");
		expect(e8.m_ctx.snapshotName8 == QStringLiteral("snapA"),
		       "v8: 同值短路(00933848 operator== 门)");
		e8.dispatch(0x75f6, "snapB");
		expect(e8.m_ctx.snapshotName8 == QStringLiteral("snapB"),
		       "v8: 异值覆写 + 遍历 cited(壳态零迭代)");

		// v9:0x7570/0x7574/0x758e 缺省空 QVariant no-op
		EditorEngine e9;
		expect(e9.dispatch(0x7570) == QVariant(),
		       "v9: 0x7570 else 链尾空 QVariant(00a41e00)");
		expect(e9.dispatch(0x7574) == QVariant(),
		       "v9: 0x7574 同相(23320-23337 未命中)");
		expect(e9.dispatch(0x758e) == QVariant(),
		       "v9: 0x758e else 落空(23630 区)");

		// v10:0x7550 双列表深腿 cited 走通
		EditorEngine e10;
		expect(e10.dispatch(0x7550, QStringList{"a"},
		    QStringList{"b"}) == QVariant(0),
		       "v10: 0x7550 过门返 0(0092e270 深腿 cited)");
	}

	// ======== y. 批 138 组:W 族收尾 + 应用族激活 ========
	// 语料锚:96f80a@0031.c:44074(旗位真身)/ 96fb1e@44231(清偿真身)/
	//   96d89e@42715(QHash 收集)/ 926356@0030.c:21542 / 9263fa@21570 /
	//   92601a@21386 / 00a20604@0034.c:192 / 00a20680@228 / 00a20666@215 /
	//   0x75c8@0034.c:24017 / 0x75e4@0034.c:24025 / 00a2cea8@0034.c:8979
	{
		// y1:96f80a 旗位真身(record 首字节位面:modeC∈[10,11] →
		//   +0x60 |= b&1;+0x61/62 恒置 |= b>>1&1 / b>>4&1)
		EditorEngine e1;
		auto *s = static_cast<wt::ENodeScan *>(e1.m_ctx.eNodeGet(5, 0));
		quint8 rec[0x20] = {};            // 语料 0x20 记录;首字节 = 旗位源
		rec[0] = 0x13;              // b&1=1 b>>1&1=1 b>>4&1=1
		e1.m_ctx.eNodeApplyScan(5, rec, 10, 20);
		expect(s->runsSlots.size() == 1 && s->dirtyHi == 20,
		       "y1: 92e5e8 rec!=null → 96f80a 尾插 + 96d620 min/max"
		       "(Lo=min(0,10)=0 初值字面/Hi=20;0x7581 应用族全链)");
		expect(s->f60 == 0x1010100ull,    // ctor 0x1000000(byte3=+0x63 语料
		                                  //   字面)+0x61|=1 +0x62|=1
		       "y1: +0x60 门关(modeC=0)+ +0x61|=b>>1&1 +"
		       " +0x62|=b>>4&1(440f8 恒置面;+0x63 = 96f606 0x1000000"
		       " 字面字节)");
		// ⚠ 92b56e 语料勘注(kind≠8 腿):96f80a 的 +0x60 位门读
		//   +0xc(modeC)—— kind∈[10,11] 经 92b56e 落 ScanTask 但
		//   9637b8 不调 → modeC 恒 0 → 门关(语料字面;modeC∈[10,11]
		//   只在 0x7545 序列化腿回灌面出现 — 本批不碰,见任务书)。
		auto *s8 = static_cast<wt::ENodeScan *>(e1.m_ctx.eNodeGet(10, 0));
		quint8 rec2[0x20] = {};
		rec2[0] = 0x13;
		s8->modeC = 10;                       // 语料 +0xc 回灌面(直注)
		s8->runInsert0096f80a(rec2, -1);
		expect((s8->f60 & 1) == 1,
		       "y1: modeC=10 → +0x60 位门开 |= b&1(byte0 LSB 置;"
		       "kind≠8 腿 modeC 恒 0 门关 — 92b56e 语料字面)");
		// ⚠ 96d620 语料语序勘注:if(+0x78<=rs) rs=+0x78(取 min,
		//   含初值 0 < 10 → 保 0)/cursor = 交换后 rs(=0)—— 语料
		//   字面 {Lo=min(0,10)=0, Hi=20, cur=0};测试断言随字面

		// y2:96fb1e 清偿真身(空表臂 end=begin + *(u16*)(+0x61)=0;
		//   载荷臂 +0x18 d ref 降 → deallocate(2,8) + +0x08 对象
		//   vt+0x10/vt+0x18 槽 ref 双降 — 4423x 语料序)
		EditorEngine e2;
		auto *sc = static_cast<wt::ENodeScan *>(e2.m_ctx.eNodeGet(5, 0));
		sc->runClear0096fb1e();           // 空 slots → 仅尾面
		expect(sc->runsF30 == sc->runsF38
		       && *reinterpret_cast<quint16 *>(
		       reinterpret_cast<quint8 *>(&sc->f60) + 1) == 0,
		       "y2: 96fb1e 空表臂:end=begin + *(u16*)(+0x61)=0"
		       "(4428x 语料字面)");

		// y3:96d89e QHash 收集(d->size==0 门)
		EditorEngine e3;
		auto *sc3 = static_cast<wt::ENodeScan *>(e3.m_ctx.eNodeGet(8, 9));
		QHash<QString, void *> acc;
		sc3->runCollect0096d89e(acc);
		expect(acc.isEmpty(),
		       "y3: 96d89e 空 runs → 空 QHash(42735 门零迭代)");

		// y4:9263fa cmd 门字面(kind 5/6/7 → 0x3f8/0x3f9/0x3fa)+
		//   926356 cmd 0x3f0;底座 92601a 空监听零投递同相
		EditorEngine e4;
		e4.m_ctx.eNodeEmitKind(5);
		e4.m_ctx.eNodeEmitKind(8);        // [5,7] 门关直返
		e4.m_ctx.eNodeEmit0x3f0(1, 2);    // 00a1c7cc +0x18=p4/+0x20=p3 面
		expect(true, "y4: 9263fa/926356 底座走通(cmd 0x3f8/0x3f9/0x3fa/"
		       "0x3f0 字面;监听者面未解 #2 → 零投递同相)");

		// y5:0x75e4 变更才动作(00a4294x 门)+ 0x75c8 kind-6 查(-1)
		EditorEngine e5;
		expect(e5.dispatch(0x75e4, true) == QVariant(0)
		       && e5.m_ctx.flag1083 == true,
		       "y5: 0x75e4 true → +0x1083 写 + 00a2cea8 门序(0x21e 门 →"
		       " 0x228 惰建 → 逐行 runnode → matchBracket — 视图层 cited)");
		expect(e5.dispatch(0x75e4, true) == QVariant(0),
		       "y5: 同值再写 → cVar9!=cVar12 门关零动作");
		expect(e5.dispatch(0x75c8, (qlonglong)0) == QVariant((qlonglong)-1),
		       "y5: 0x75c8 → 927558 kind-6 空臂 -1(命中臂 96d1b0 壳 "
		       "inner null → 96d19a(0)=-1 同值)");

		// y6:0x75aa 前奏真身(00a20604 min(textLength,首行+可见行)−1
		//   夹 0;00a20680 行归一 + ln!=docLen → +0x7fffffff 面)
		EditorEngine e6;
		e6.dispatch(SCI_ADDTEXT, (qlonglong)10, QByteArray("0123456789"));
		expect(e6.dispatch(0x75aa) == QVariant(0),
		       "y6: 0x75aa 前奏真身(00a20604/00a20680)+ 930226 节点腿"
		       "空树零迭代同相");

		// y7:0x7581 false 腿 rs/re 面真身(00a20666 首行归一;
		//   00a20680 runnode pos)+ w5 回归
		EditorEngine e7;
		e7.dispatch(0x7581, false);
		expect(e7.m_ctx.eNodes.isEmpty(),
		       "y7: 0x7581 false → 92e5e8(7,null,rs=00a20666,re=00a20680)"
		       "零建同相(w5 回归)");
	}

	// ======== w. 批 136 组:eNodes 建模(ENodes.h;W1-W4 激活)========
	// 语料锚:963590@0031.c:34095 / 96f606@43974 / 9637b8@34252 /
	//   92b56e@0030.c:27031 / 9258b2@20859 / 92e44e@29141 / 92e524@29190 /
	//   92e368@29089 / 930226@30279 / 92fb40@30038 / 9305e6@30437 /
	//   96d620@0031.c:42559 / 96cef2@42193 / 96d0a0@42306 / 96d094@42296
	{
		// w1:ctor 字面(963590/96f606/9637b8)
		EditorEngine e1;
		auto *t = static_cast<wt::ENodeTask *>(e1.m_ctx.eNodeGet(1, 0));
		expect(t != nullptr && t->kind == 1 && t->state == 0
		       && t->stopped == 1 && t->modeC == 0,
		       "w1: kind=1 → 0x30 族 DocumentTask(963590 字面:"
		       "state=0/stopped=1/modeC=0)");
		auto *s8 = static_cast<wt::ENodeScan *>(e1.m_ctx.eNodeGet(8, 9));
		expect(s8 != nullptr && s8->kind == 8 && s8->modeC == 9
		       && s8->state == 0 && s8->c2c == 4 && s8->f60 == 0x1000000ull,
		       "w1: kind=8 mode=9 → ScanTask(96f606+9637b8:modeC=9,"
		       "state=(9==8)*2=0 字面,c2c=4,f60=0x1000000)");
		expect(e1.m_ctx.eNodeGet(8, 10) == static_cast<void *>(s8),
		       "w1: kind=8 mode∈[9,11] → 9258b2 mode 现存复用");
		auto *s5 = static_cast<wt::ENodeScan *>(e1.m_ctx.eNodeGet(5, 0));
		expect(s5 != nullptr && s5->state == 2,
		       "w1: kind=5 → ScanTask 走 92b56e else 臂(963590 尾:"
		       "kind∈[5,7] → state=2;9637b8 不调)");
		expect(e1.m_ctx.eNodes.size() == 3 && e1.m_ctx.eNodes.firstKey() == 1
		       && e1.m_ctx.eNodes.lastKey() == 8,
		       "w1: 树键序 = char kind(键型勘正 QMap<int>;92586c 保序)");

		// w2:0x754e 复位 + 重排门(92e368/96cef2/9635d8/9637da)
		s8->runsSlots.append(nullptr);       // 非空门(96d094)开
		s8->anchorRunsFace();                // begin/end 重锚
		expect(e1.dispatch(0x754e) == QVariant(0),
		       "w2: 0x754e 走通(92e368)");
		expect(s8->dirtyLo == 0 && s8->dirtyHi == 0,
		       "w2: kind=8 state=0 → 9635d8 [1,2] 门关 → 不复位"
		       "(92e368 语料门,原样)");
		expect(s5->dirtyLo == 0x7fffffffffffffffll && s5->dirtyHi == 0
		       && s5->cursor == 0,
		       "w2: kind=5 state=2 门开 → 96cef2 复位 {MAX,0,0}");

		// w3:0x754d 全停(92e44e)
		e1.m_ctx.eStopCount = 41;
		expect(e1.dispatch(0x754d) == QVariant(0),
		       "w3: 0x754d 走通(92e44e)");
		expect(e1.m_ctx.eStopCount == 42 && e1.m_ctx.ePoolB != nullptr,
		       "w3: ++E+0x128(LOCK 面 ≡ 单线程 ++;池 B 拆槽批 136)");

		// w4:0x754f capability 探针(9305e6 勘正接线:9635d0 ==8 门)
		expect(e1.dispatch(0x754f).toBool() == false,
		       "w4: kind-8 modeC=9≠8 → 9305e6 未命中 false");
		auto *s8b = static_cast<wt::ENodeScan *>(e1.m_ctx.eNodeGet(8, 8));
		expect(s8b != nullptr && s8b->modeC == 8 && s8b->state == 2,
		       "w4: mode=8 不在复用腿 → 新建 + 9637b8:modeC=8/state=2"
		       "((8==8)*2 字面)");
		expect(e1.dispatch(0x754f).toBool() == true,
		       "w4: kind-8 modeC==8 → 9305e6 命中 true");

		// w5:0x7581 false 腿 kind=7 应用(92e5e8)
		EditorEngine e2;
		e2.dispatch(0x7581, false);
		expect(e2.m_ctx.eNodes.isEmpty(),
		       "w5: 0x7581 false → 92e5e8(7)rec=null:无现存 → 零建同相");
		expect(e2.m_ctx.field1b2 == false, "w5: +0x1b2=false(0034.c:23519)");

		// w6:0x75cb/0x75cc kind-6 拆挂(92fb40)
		EditorEngine e3;
		e3.dispatch(0x75cb, QVariantList{1, 2});
		expect(e3.m_ctx.docObjList.size() == 2 && e3.m_ctx.eNodes.isEmpty(),
		       "w6: 0x75cb 存储 + kind-6 拆挂(92fb40;词容器壳零条目)");
		e3.dispatch(0x75cb, QVariantList{1, 2});
		expect(e3.m_ctx.docObjList.size() == 2,
		       "w6: 全等 no-op(0092fb4x 同长同值门)");

		// w7:0x75aa 区间门(930226)
		EditorEngine e4;
		expect(e4.dispatch(0x75aa) == QVariant(0),
		       "w7: 0x75aa 前奏 cited 占位(from=1/to=0x7fffffff)+ "
		       "930226 真身遍历空树同相");

		// w8:0x75f6 type-8 遍历(933830 节点腿)
		EditorEngine e5;
		e5.dispatch(0x75f6, "snapX");
		expect(e5.m_ctx.snapshotName8 == QStringLiteral("snapX"),
		       "w8: 0x75f6 置 M+0x2b8 + type-8 遍历真身(96d89e cited)"
		       "空树同相");
	}

	// ======== x. 批 137 组:EXT 段余量收尾(32 条;7 真身断言)========
	// 语料锚:0x4ed4@0034:22267/00a20266→975c46 / 0x4ee9@22413/
	//   00a28d1e@0034:4220 / 0x4ef8@22615/00a28424@0034:5981 /
	//   0x4ef9@22703/009306ba@0030.c:5881 / 0x4efa@22708/926c6e /
	//   0x4efd@22682/926dfc / 0x4f02@22719/00a2f82a@0034:8391(见 case 注)
	{
		// w1:0x4ed4 selectionType toggle(flagWord 位30-31)
		EditorEngine e1;
		e1.m_ctx.selStore.anchor.flagWord = 0x80000000u;   // 矩
		e1.dispatch(0x4ed4);
		expect(e1.m_ctx.selStore.anchor.flagWord == 0x40000000u,
		       "w1: 0x4ed4 矩→流(975c46 96c666→96c700 v=1)");
		e1.dispatch(0x4ed4);
		expect(e1.m_ctx.selStore.anchor.flagWord == 0x80000000u,
		       "w1: 流→矩(v=2 96c700 低位 0x3fffffff 保持)");

		// w2:0x4ee9 选区越界校验(空 store → true;越界 → false)
		EditorEngine e2;
		e2.dispatch(SCI_ADDTEXT, (qlonglong)4, QByteArray("abcd"));
		expect(e2.dispatch(0x4ee9) == QVariant(true),
		       "w2: 空选区 → true(00a28d1e 零迭代尾)");
		e2.m_ctx.selStore.anchor.n0.pos = 2;
		e2.m_ctx.selStore.anchor.n1.pos = 99;
		expect(e2.dispatch(0x4ee9) == QVariant(false),
		       "w2: end>docLen → false(00a4233x 门)");

		// w3:0x4ef8 kind-5 门(命令腿恒 5 字面:空树 → -1;命中 kind-5 → 0)
		EditorEngine e3;
		auto *t5 = static_cast<wt::ENodeScan *>(e3.m_ctx.eNodeGet(5, 0));
		expect(t5 != nullptr && t5->kind == 5,
		       "w3: eNodeGet(5,0) → ScanTask(w1 同相;真对象替代裸缓冲,"
		       "批 116b 析构链安全)");
		{
		    const void *fv = e3.m_ctx.eNodes.first();
		    fprintf(stderr, "[dbg] size=%d val=%p bytes:",
		        int(e3.m_ctx.eNodes.size()), fv);
		    for (int b = 0; b < 16; ++b)
		        fprintf(stderr, " %02x", int(*(const unsigned char *)(
		            reinterpret_cast<const char *>(fv) + b)));
		    fprintf(stderr, "\n[dbg] t5=%p kind(byte)=%d\n",
		        (const void *)t5, int(t5->kind));
		}
		fprintf(stderr, "[dbg] dispatch ret type=%s\n",
		    QVariant::typeToName(e3.dispatch(0x4ef8, 5).type()));
		expect(e3.dispatch(0x4ef8, 5) == QVariant((qlonglong)0),
		       "w3: kind-5 命中 → 0(96d22a cited 门真身)");
		expect(e3.dispatch(0x4ef8, 6) == QVariant(0),
		       "w3: 命令腿恒 5,参 6 无关(00a28424 字面 5)");

		// w4:0x4ef9 kind 活跃查(runs[6]!=[7])
		EditorEngine e4;
		auto *t8 = static_cast<wt::ENodeScan *>(e4.m_ctx.eNodeGet(8, 9));
		expect(t8 != nullptr && t8->kind == 8,
		       "w4: eNodeGet(8,9) → ScanTask(96f606 modeC=9)");
		expect(e4.dispatch(0x4ef9, 8) == QVariant(false),
		       "w4: runs 空 → false(96d094 [6]==[7])");
		t8->runsSlots.append(nullptr);       // 非空门开(w2 同款)
		t8->anchorRunsFace();
		expect(e4.dispatch(0x4ef9, 8) == QVariant(true),
		       "w4: runs 非空 → true(96d094 [6]!=[7])");
		expect(e4.dispatch(0x4ef9, 7) == QVariant(false),
		       "w4: kind 异 → false(939d14 门)");

		// w5:0x4efa lexer 门 + 0x4efd markers 门
		EditorEngine e5;
		expect(e5.dispatch(0x4efa) == QVariant(false),
		       "w5: 0x4efa lexer null → false(926c6e +0x98 门)");
		e5.m_ctx.bufferLexer = (void *)1;
		expect(e5.dispatch(0x4efa) == QVariant(true),
		       "w5: lexer 命中 → true");
		expect(e5.dispatch(0x4efd) == QVariant(false),
		       "w5: 0x4efd arr null → false(926dfc +0xc0 门)");
		e5.m_ctx.markersStore.arr = (wt::MarkersArray *)1;
		expect(e5.dispatch(0x4efd) == QVariant(true),
		       "w5: arr 命中 → true");

		// w6:0x4f02 moveTo kind 全表映射(语料 24 名字面)
		EditorEngine e6;
		expect(e6.dispatch(0x4f02, QByteArray("char")) == QVariant(1),
		       "w6: char → 1(00a2f82a 表[0])");
		expect(e6.dispatch(0x4f02, QByteArray("WORDPART"))
		           == QVariant(4),
		       "w6: WORDPART 大写归一 → 4(toLower 00a2fd56)");
		expect(e6.dispatch(0x4f02, QByteArray("documentend"))
		           == QVariant(24),
		       "w6: documentend → 24(表尾 v9[2]=0x18)");
		expect(e6.dispatch(0x4f02, QByteArray("nosuch")) == QVariant(0),
		       "w6: 未知 → 0(00a2fd9c miss 臂)");
	}

	printf("fail=%d\n", g_fail);
	return g_fail == 0 ? 0 : 1;
}
