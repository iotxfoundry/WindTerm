#pragma once
// eNodes 节点层建模(批 136,方案书 docs/history/enodes-recon.md Q4 直执)。
// 载体两级:Map = E+0x2d8 QMap(键 = char kind;EditorContext.h 承接)·
// 值 = 多态任务两族。基类 DocumentTask(TI 0x11ad4b0,0x30B,ctor
// FUN_00963590 64B @0031.c:34095)/ 派生 ScanTask(TI 0x11ad588,
// 0xB0,ctor FUN_0096f606 229B @0031.c:43974)。dynamic_cast 语义由
// C++ 继承复刻(KitWindow 批 131 判例;不复刻 TI 地址)。
// 无 Q_OBJECT(坑 14/19 规避);虚 D1 槽 = virtual ~ENodeTask()
// (engine dtor FUN_0092f62e 逐值虚 D1 + freeTree,C++ 析构链同构)。
//
// 布局勘注(语料实读勘正方案书骨架):
//  - +0x20 = 自旋锁字节(9637ea LOCK 面),+0x24 = int 分发计数
//    (9637da),+0x28 = stopped 字节 —— 非 u64 槽。
//  - ctor 963590 第三参 = E 指针(92b56e 传 param_1;9635e6 消费
//    *(p+0x18)+0x12c 计数),非 0。
//  - 96f606 不调 9637b8;92b56e 落 kind==8 才调(方案书骨架笔误)。
#include <QVector>
#include <QHash>
#include <QString>
#include <QByteArray>
#include <QArrayData>
#include <QRunnable>
#include <QThread>
#include <QtGlobal>
#include "MarkersStore.h"   // 批 152:RsHolder20/makeHolder0x20 承载复用(词法栈 0x20 holder)
#include "Editor/Config/DeepEngineFace.h" // 批 156:深引擎底座头(API 面;偏移锁+调面声明,实现 cited)

class EditorContext; // ENodeRunner 前向(仅存指针)

namespace wt {

// ENodeTask — 语料 DocumentTask(TI 0x11ad4b0,0x30B)
// ⚠ 布局勘正(批 136b):本类含虚 D1 → 编译器 vptr 占 +0x00 = 语料
//   +0x00 vtable 槽(原显式 vtbl 成员双计 vptr 致全字段 +8 漂移,已删)。
//   static_assert 锁定语料偏移于类尾。
struct ENodeTask {
	qint8 kind = 0;               // +0x08 kind 键值(0x754d [5,8] 门;92e524 匹配键;raw 门读 +8)
	qint32 modeC = 0;             // +0x0c(9637b8 kind==8 腿 = mode;9635d0 ==a2 门)
	quint8 state = 0;             // +0x10 kind∈[5,7]→2;9637b8 重置;9635d8 门 ∈[1,2]
	quint8 _r11[3] = {};
	quint64 p18 = 0;              // +0x18 ctor 参 = E(92b56e param_1;9635e6 +0x12c 计数)
	quint8 spin20 = 0;            // +0x20 自旋锁字节(9637ea LOCK 面;我方单线程 → 常 0)
	quint8 _r21[3] = {};
	quint32 p24 = 0;              // +0x24(9637da 分发门 ==0;9635e6 进出 ±1)
	quint8 stopped = 1;           // +0x28 963590 字面 1;9264ba 非零跳;9637ea 置 1;9637da 清 0
	virtual ~ENodeTask() = default; // 虚 D1 槽(语料 slot0=0x9638a6 D1/slot1 D0;
	                                //   编译器 vptr = 语料 +0x00 vtable 槽)

	// FUN_00963590(64B)@0031.c:34095 — 全字面转写(vtbl 槽 = 编译器
	//   vptr 承接,语料 ctor 写真 vtable 地址 — 同位同语义)
	void ctor00963590(qint8 k, quint64 e)
	{
		kind = k;
		modeC = 0;
		state = 0;
		p18 = e;
		spin20 = 0;
		p24 = 0;
		stopped = 1;
		if (quint8(k - 5) < 3)                // 963590 尾:kind∈[5,7] → 2
			state = 2;
	}
	// FUN_009635d0(7B)@0031.c:34115:+0xc == a2
	bool gate009635d0(int a2) const { return modeC == a2; }
	// FUN_009635d8(13B)@0031.c:34124:+0x10 ∈ [1,2]
	bool gate009635d8() const { return quint8(state - 1) < 2; }
	// FUN_009637da(16B)@0031.c:34267:清 stopped,返可分发(p24==0)
	bool dispGate009637da()
	{
		stopped = 0;
		return p24 == 0;
	}
	// FUN_009637ea(188B)@0031.c:34277:stopped=1 + +0x20 锁自旋等待
	//   (sched_yield/nanosleep 退避面)—— 我方单线程:锁恒无主,
	//   语料首循环 cVar1==0 腿直落(置 1/清 0 返)→ 坍缩两行,同相
	void stop009637ea()
	{
		stopped = 1;
		spin20 = 0;
	}
};

// WNodeInner — 语料 ScanTask::inner(0x18;96f606 尾 44000-44005:
//   operator_new(0x18){+0x0=回指 task,+0x8=scanner,+0x10=0} +
//   FUN_00970850(inner) 词法重建)。批 152 重建面真身(00970850 746B
//   @0031.c:44895 kuna 全读):
//   {puVar6=operator_new(0x20) Uint8SkipRunStyles holder{vt,+8=0x50
//   threadCtx,+0x10=0};editctx_initThread(pvVar7,tag) 建 0x50
//   SkipPartition(9714b6 全读:{0..3=0,+4=piecetable(new 0x60
//   piecetable_init(96a2f8 全读;尾 96a280 种子)),+5=1,+6=tid,+7=0,
//   +8 自增序,+0x28 锁};97142a 尾 runstyles_insert_space_b 灌满);
//   93fc60 清老 runs(空表同相零迭代);gapbuffer_reallocate(pvVar8,
//   0,0,2) 重排;puVar9=operator_new(0x20){0,0,0,0} 换 inner 词法栈
//   (puVar8[3]);scanner=new(0x40) FUN_009cc22c(holder) = ValueTable
//   K3 形}. 深引擎腿(piecetable_init 种子 96a280/gapbuffer_reallocate
//   3525B 重排/runstyles_insert_space_b 灌链)= 外库边界 cited(批 111
//   piecetable/线程缓存同族判例 — 改版底座头不在库,缺证不转写);
//   承载替:RsHolder20(MarkersStore §makeHolder0x20 同款)+ RS8 直存
//   (怪癖登记 — 布局不同构,值面同相)。
//   scanner = wt::ValueTable(bankCtorK3) — 9cc22c 55B 全读 = MarkersStore
//   bankCtorK3 同体(kind=3,{3,styler,0,0,0,styler,0,0})→ 词法引擎
//   9cd3da/9cd91e 走 MarkersStore 六路取值/upgrade 同构面。
struct WNodeInner {
	void *back = nullptr;        // +0x00 回指 task(96f606 字面 *puVar1=param_1)
	void *scanner = nullptr;     // +0x08 00970850 产物(0x40,9cc22c
	                             //   {3,styler,0,0,0,styler,0,0})
	quint64 f10 = 0;             // +0x10 96f606 字面 0
	// FUN_00970850(746B)@0031.c:44895 — 重建面真身(控制流 + 栈字段
	//   面;深引擎腿 cited 见头注):holder=makeHolder0x20(RS8);
	//   threadCtx=editctx_initThread 承载(0x50 面 cited — 布局怪癖
	//   登记);旧词法栈 93fc60 清偿(空表零迭代同相);scanner 换新
	//   ValueTable(9cc22c);+0x10 槽 = operator_new(0x20){0,0,0,0}
	//   → 承载 = RsHolder20(空)—— 承载替字段(类尾追加,0x18 语料
	//   分配尾外 — quirks 怪癖登记)。
	wt::RsHolder20 *holder = nullptr;   // puVar6 — 00970850 词法栈栈面
	// 批 156:009708a1 0x50 SkipPartition 字段真身(编辑底座头
	//   DeepEngineFace::SkipPartition50 — 偏移锁+prologue;97142a 尾
	//   深引擎腿 cited 不落,字段停 prologue 同相)。承载于 holder
	//   (RsHolder20.threadCtx 槽 = 语料 puVar6[1] 同槽 — 44924 写)。
	wt::SkipPartition50 *sp50 = nullptr;
	// 析构清偿(承载替生命周期;语料 970850 产物处置权在消费链 D1:
	//   97142a 45523/45527 虚 D1 ptA/ptB + 44945-44950 bank30 逐槽
	//   QMap/QHash/QList 清偿 + operator_delete 0x50 — inner D1 面)。
	~WNodeInner()
	{
		delete sp50;             // SkipPartition50(含 bank30/inner20 逐级)
		delete holder;
	}
	// 00970850 真身(consumes back==this;called from ctor0096f606/
	// runReset0096f6fe — f10 槽语料语义未触,原样保留)
	void rebuild00970850()
	{
		// 00970887:puVar6 = operator_new(0x20){vt cited,+8=0,+0x10=0}
		//   语料 970850 直建新栈(无旧栈持有面;holder 处置权 = WNodeInner
		//   承载替生命周期 — 类尾字段,quirks 承载替登记)
		if (holder == nullptr)
			holder = wt::makeHolder0x20(new RS8());
		else
			static_cast<RS8 *>(wt::holderRs(holder))->DeleteAll();
		// 009708a1:pvVar7 = operator_new(0x50);editctx_initThread —
		//   cited(0x50 SkipPartition 布局 + piecetable/gapbuffer 深引擎;
		//   9714b6 全读,承载 = holder.threadCtx 置位同相)
		holder->threadCtx = holder;          // cited — editctx_initThread 面
		// 批 156:editctx_initThread 字段前奏真身(9714b6 45556-45596
		//   逐字面 → DeepEngineFace;tail 97142a 深引擎腿 cited)
		sp50 = wt::editctxInitThread009714b6();
		// 009708bd:puVar8 = operator_new(0x30){vt 01192288,+8 旗,+0x14
		//   mask,+0x18..0x28 0} → 44940 FUN_0093fc60 清偿(批 160 ODR
		//   真身;新栈 f20 恒 0 → 零迭代早退同相)+ 45047 gapbuffer_
		//   reallocate(批 160 ODR 真身可达面;GB face 密排 cited)→
		//   产出 0x30 消费面 = 词法栈本体(970bb0 D1 面逐槽析构)→
		//   我方承载 = holder.rs RS8 直存(值面同相怪癖)。
		//   批 156:0x30 构造字段真身 → DeepEngineFace::makeBank30
		//   (逐字面)
		// 00970a5b:puVar9 = operator_new(0x20){0,0,0,0} → puVar8[3] —
		//   词法栈内层换新(cited 同上;RS8 重开 = gapbuffer_reallocate
		//   (0,0,2) 值面同相;批 156:Inner20 字段真身落 sp50->bank->
		//   inner20 — 词法栈 0x30 本体 = editctx 产物 sp50[4] 同一
		//   face(44924 puVar6[1]=pvVar7 + 44945 puVar8[5] 清偿链互证)
		sp50->bank->inner20 = new wt::Inner20{};   // 44974-44979 {0,0,0,0}
		// 44940 FUN_0093fc60(批 160 ODR 真身;新栈零迭代早退同相)
		wt::lexStackClear(sp50->bank);
		static_cast<RS8 *>(wt::holderRs(holder))->DeleteAll();
		// 45047 gapbuffer_reallocate(bank,0,0,2)(批 160 ODR 真身可达面;
		//   初始 2 块初始灌 — GB face 重排密排腿 cited;承载 RS8 空栈)
		wt::gapBufferReallocate(sp50->bank, 0, 0, 2);
		// 00970a82:scanner = operator_new(0x40);FUN_009cc22c(scanner,
		//   holder) — 55B 全读 = bankCtorK3(MarkersStore 同体真身)。
		//   ⚠ 旧 scanner 处置权在调用方(96f6fe 先 9cc2d4+delete 0x40
		//   才尾调 970850;ctor 面旧槽恒 null)— 970850 本体不 delete,
		//   此处原样(承载替无旧持有面)。
		wt::ValueTable *sc = new wt::ValueTable{};
		wt::bankCtorK3(sc, holder);
		scanner = sc;
	}
};

// ENodeScan — 语料 ScanTask(TI 0x11ad588,0xB0;ctor = 963590 + 扩展段)
struct ENodeScan : ENodeTask {
	quint32 c2c = 0;              // +0x2c 96f606 字面 4(GCC dsize:基尾垫承接)
	                              //   ⚠ 勿加占位数组 — 会把 runs face 顶出语料 +0x30
	void *runsF30 = nullptr;      // +0x30 语料 runs face begin(96d094 [6];
	                              //   96fb1e 清偿 end=begin)
	void *runsF38 = nullptr;      // +0x38 语料 runs face end(96d094 [7];
	                              //   非空门 = [6]!=[7])
	quint64 f40 = 0, f48 = 0, f50 = 0, f58 = 0;   // +0x40..+0x58(0x4c 覆 f48 高半)
	quint64 f60 = 0x1000000;      // +0x60 96f606 字面(0x60/61/62 旗位字节)
	quint64 f68 = 0;
	quint8 spin = 0;              // +0x70 自旋字节(单线程 → 常 0,锁面坍缩)
	quint8 _r71[7] = {};
	qint64 dirtyLo = 0;           // +0x78 96d620 min;96cef2 → INT64_MAX
	qint64 dirtyHi = 0;           // +0x80 96d620 max;96cef2 → 0
	qint64 cursor = 0;            // +0x88 96d620 = rs;96cef2 → 0
	quint64 f90 = 0, f98 = 0, fa0 = 0;
	void *inner = nullptr;        // +0xa8 operator_new(0x18){回指,+0x10:0}
	                              //   + FUN_00970850 — WNodeInner 承载
	                              //   (ctor 真身;scanner 面 cited — wave-2)
	// D1 尾(inner 清偿)= FUN_0096d684(kuna @0x96d684 全读;基类 9638a6
	//   D1 → 9637ea 同构析构链):inner 非空 → +8 非空 → 9cc2d4+delete 0x40
	//   (批 152:scanner_resetState 140B@0032.c:67038 六槽释放面 —
	//   MarkersStore scannerResetState 同体真身)→ delete 0x18 → +0xa8=0。
	~ENodeScan() override
	{
		if (inner == nullptr)
			return;
		WNodeInner *in = static_cast<WNodeInner *>(inner);
		// 9cc2d4 scanner_resetState 六槽 D1(bank holders 全 null 门关)+ operator delete(+8,0x40)
		wt::ValueTable *sc = static_cast<wt::ValueTable *>(in->scanner);
		if (sc != nullptr) {
			wt::scannerResetState(sc);          // 9cc2d4 — 批 152 真身复用
			delete sc;                          // operator delete(sc,0x40)
		}
		delete in;                              // operator delete(inner,0x18)
		inner = nullptr;
	}
	QVector<void *> runsSlots;    // 槽承载替(语料 0x20 记录槽数组;类尾
	                              //   追加 — 不挤真身字段;begin/end 指向其
	                              //   首尾,QVector 重排失效 → anchorRunsFace
	                              //   重锚;壳态单线程同相,登记承载替)

	// runs face 重锚(槽承载替;语料 begin/end 指向槽数组首尾)
	void anchorRunsFace()
	{
		runsF30 = slotsData();
		runSetEnd();
	}
	void *slotsData() const
	{
		return const_cast<void *>(static_cast<const void *>(runsSlots.constData()));
	}
	void runSetEnd()
	{
		runsF38 = reinterpret_cast<void *>(reinterpret_cast<char *>(runsF30)
		    + runsSlots.size() * sizeof(void *));
	}

	// FUN_0096f606(229B)@0031.c:43974 — 全字面转写(不调 9637b8:
	//   92b56e 落 kind==8 才尾调)
	void ctor0096f606(qint8 k)
	{
		ctor00963590(k, 0);       // E 由 92b56e 调面补(eNodeGet 写 p18)
		c2c = 4;
		runsSlots.clear();
		anchorRunsFace();         // 语料 end=begin
		f40 = f48 = f50 = f58 = 0;
		f60 = 0x1000000;
		f68 = 0;
		spin = 0;
		dirtyLo = dirtyHi = cursor = 0;
		f90 = f98 = fa0 = 0;
		inner = new WNodeInner{this, nullptr, 0}; // 96f606 尾 44000-44005
		                                          //   {回指,+0x10:0} +
		static_cast<WNodeInner *>(inner)->rebuild00970850(); // 00970850
		                                          //   词法重建(批 152:
		                                          //   栈面真身/深引擎 cited)
	}
	// FUN_009637b8(33B)@0031.c:34252:+0xc=mode;+0x10 分派。
	//   ⚠ (mode==8)*'\x02' 字面:非 [5,6]/≠0xc 且 mode!=8 → 0(原样勿"修")
	void mode009637b8(qint32 mode)
	{
		modeC = mode;
		if (quint32(mode - 5) >= 2 && mode != 0xc)
			state = quint8((mode == 8) * 2);
		else
			state = 1;
	}
	// FUN_0096d094(12B)@0031.c:42296:[+0x38]!=[+0x30] 非空门
	bool runsNonEmpty0096d094() const { return runsF30 != runsF38; }
	// FUN_0096d0a0(61B)@0031.c:42306:非空门 ∧ (+0x78==rs → +0x80!=re)
	bool dirtyTest0096d0a0(qint64 rs, qint64 re) const
	{
		if (!runsNonEmpty0096d094())
			return false;
		return (dirtyLo == rs) ? (dirtyHi != re) : true;
	}
	// FUN_0096d620(76B)@0031.c:42559:min/max 收敛 + 游标 = rs
	void dirtyClamp0096d620(qint64 rs, qint64 re)
	{
		if (dirtyLo <= rs)
			rs = dirtyLo;
		dirtyLo = rs;
		if (re <= dirtyHi)
			re = dirtyHi;
		dirtyHi = re;
		cursor = rs;
	}
	// FUN_0096cef2(40B)@0031.c:42193:{+0x78=MAX,+0x80=0,+0x88=0}
	void dirtyReset0096cef2()
	{
		dirtyLo = 0x7fffffffffffffffll;
		dirtyHi = 0;
		cursor = 0;
	}
	// FUN_0096f80a(306B)@0031.c:44074:run 列表插入(idx=-1 尾插;
	//   kind==7 → +0x4c 计数)+ 0x60/61/62 旗位 |= record 首字节
	//   位面(b&1 / b>>1&1 / b>>4&1;批 138 旗位真身:@44074 语料
	//   `pbVar2=(byte*)*param_2; bVar1=*pbVar2` — modeC∈[10,11]
	//   才 +0x60 |= b&1;+0x61/62 恒置)。尾 FUN_0096f782
	//   (135B 整理面;批 146 runRefresh 真身 — cb3c/b6c/b84 链落位)。
	void runInsert0096f80a(const void *rec, int idx)
	{
		if (rec == nullptr)
			return;               // *param_2==0 → FUN_0096ca00 — cited
		if (idx == -1)            // (end-begin)>>5 尾插(语料 0x20 记录步进)
			idx = runsSlots.size();
		runsSlots.insert(idx, const_cast<void *>(rec)); // 96c868 尾插/9701b0 扩容 → slots 承载
		anchorRunsFace();
		if (modeC == 7)
			*(reinterpret_cast<quint32 *>(&f48) + 1) = quint32(runsSlots.size()); // +0x4c
		const quint8 b = *static_cast<const quint8 *>(rec);   // 440e4 bVar1
		quint8 *fb = reinterpret_cast<quint8 *>(&f60);        // 0x60/61/62 旗位字节
		if (quint32(modeC) - 10 < 2)                          // [10,11] 门
			fb[0] |= quint8(b & 1);                           // +0x60
		fb[1] |= quint8((b >> 1) & 1);                        // +0x61(恒)
		fb[2] |= quint8((b >> 4) & 1);                        // +0x62(恒)
		runRefresh0096f782();          // 440f8 尾 FUN_0096f782(批 143 真身)
	}
	// FUN_0096c934(46B)@0031.c:41686(kuna @0x96c934):词法刷新门
	//   — kind==7 ‖ modeC∈[9,11](u32(u−9)<=2)
	bool gateLex0096c934() const
	{
		return kind == 7 || quint32(modeC - 9) <= 2;
	}
	// FUN_0096cb9a(13B)kuna @0x96cb9a:+0x50 = tag(run 列表 tag 面)
	void lexTag0096cb9a(quint64 tag) { f50 = tag; }
	// FUN_0096cba2(31B)kuna @0x96cba2:+0x68 收敛(tag<=旧 且不强制 → 跳)
	void lexClamp0096cba2(quint64 tag, bool force)
	{
		if (f68 <= tag && !force)
			return;
		f68 = tag;
	}
	// FUN_0096cb3c(24B)@0031.c:41946(kuna @0x96cb3c 全读):词法重扫
	//   计数 = inner+8 非空 → 尾调 009cc3a0(`(**(styler+1)+0x30)()`
	//   jump-as-call;批 146 真身)。009cc3a0(10B@0032.c:67145)=
	//   delegate(styler+0x08)vt+0x30 尾调 — MarkersStore runIndexOfLine
	//   同面(vcallSlotArg(delegate,0x28));语料 delegate = Uint8SkipRun
	//   Styles 0x20 obj(vt+0x30 = runs 计数 — 0096cbb8 调面同构);
	//   我方 vt 面 = MarkersStore 槽尾调承载。null 臂 0 同相。
	int lexRescanCount0096cb3c() const
	{
		if (inner == nullptr)            // 语料首行解引 — 壳态防御同相
			return 0;
		const WNodeInner *in =
		    static_cast<const WNodeInner *>(inner);
		if (in->scanner == nullptr)
			return 0;
		// 009cc3a0:(**(scanner+0x08)+0x30)() — runs 计数虚槽;
		//   语料 delegate vt+0x30 = 00889872(runstyles_runs_count 路面)
		//   → 我方委托 RS Runs()(96f782 |4 链零 run 同相;承载替怪癖)
		const wt::ValueTable *sc = static_cast<const wt::ValueTable *>(
		    in->scanner);
		return int(static_cast<const RS8 *>(wt::holderRs(sc->delegate))
		    ->Runs());                       // vt+0x30 尾调承载(批 152)
	}
	// FUN_0096cb6c(24B)@0031.c:41976(kuna @0x96cb6c 全读):第 i 重扫
	//   项 = inner+8 → 009cd3da(155B@0032.c:68073 全读:switch kind
	//   [0,5] 逐路 *holder→+0x10 RS valueAt — MarkersStore runValueWordAt
	//   同体六路真身)。null 臂字面 0 同相。
	int lexItemAt0096cb6c(int i) const
	{
		if (inner == nullptr)
			return 0;
		const WNodeInner *in =
		    static_cast<const WNodeInner *>(inner);
		if (in->scanner == nullptr)
			return 0;
		return int(wt::MarkersStore::runValueWordAt(   // 009cd3da 六路(批 152)
		    static_cast<const wt::ValueTable *>(in->scanner), i));
	}
	// FUN_0096cb84(22B)@0031.c:41991(kuna @0x96cb84 全读):第 i 重扫
	//   项置 style = inner+8 → 009cd91e(1221B@0032.c:68292 全读:switch
	//   kind 逐路 runstyles 置值(009cf5e2 族 = FillRange(pos,v,1) 单点
	//   灌)相邻同值 run 拆面/升宽迁移 — MarkersStore runstylesUpgrade
	//   同构面;升级腿 = MarkersStore migU* 同族)。null 臂直返。
	void lexSetItemAt0096cb84(int i, int v)
	{
		if (inner == nullptr)
			return;
		WNodeInner *in = static_cast<WNodeInner *>(inner);
		if (in->scanner == nullptr)
			return;
		// 009cd91e 逐路置值(批 152):delegate = SkipRunStyles 0x20
		//   (holders[kind]);单点灌 = runstylesUpgrade(pos=i,v,len=1)
		wt::runstylesUpgrade(static_cast<wt::ValueTable *>(in->scanner),
		    i, quint32(v), 1);
	}
	// FUN_0096f782(135B)@0031.c:44042 — 真身(控制流 + 节点字段面):
	//   词法门开:tag = 0096c912→0092801a(*(E+0xf8)+0x28) — CSuperBuffer
	//   体段面,我方 +0xf8 平铺 docBytes 不可达 → 0 同相(cited);
	//   scanner 逐项 |4(0096cb3c/b6c/b84 → inner+8 解引)→ 批 152 起
	//   inner scanner 非恒 null — n=Runs() 面可走非退化路径(初始 RS8
	//   空 → n=0 零迭代同相;真引擎面 970850 深引擎 cited);f68 收敛
	//   (强制)+ f50=tag。门关:runReset0096f6fe()。
	//   (0096cb3c/b6c/b84 → inner+8 解引)→ 批 152 起 scanner 非恒 null:
	//   初始空 RS8 → n=Runs()=0 零迭代同相;灌值后走真迭代(lexSetItem
	//   → runstylesUpgrade 单点灌)。

	void runRefresh0096f782()
	{
		if (gateLex0096c934()) {
			const quint64 tag = 0;       // 0096c912 — cited(+0xf8 平铺)
			const int n = lexRescanCount0096cb3c();   // 4405c|44065 门
			for (int i = 0; i < n; ++i) {
				lexSetItemAt0096cb84(    // 4406c/44077:cb6c |4 → cb84
				    i, lexItemAt0096cb6c(i) | 4);
			}
			lexClamp0096cba2(tag, true); // 0096cba2(tag,1)
			lexTag0096cb9a(tag);         // 0096cb9a
			return;
		}
		runReset0096f6fe();
	}
	// FUN_0096f6fe(131B)@0031.c:44010 — 真身(节点字段面):inner+8
	//   scanner 复位(009cc2d4 六槽释放 + delete 0x40 — 批 152 真身复用
	//   scannerResetState)+ 00970850 词法重建(rebuild00970850 批 152
	//   栈面真身/深引擎 cited);f68 ← 0(0096cba2(0,0) 真身:旧值>0
	//   才写,语义等价收敛);9635d8 门开 → 尾组播 926356(0x3f0,0,tag)/
	//   9263fa(kind)— 底座 92601a 监听者表未建模(enodes-recon 未解 #2)
	//   零投递同相;p18=E 调面在案(cited)。
	void runReset0096f6fe()
	{
		// 96f6fe 44021-44027:inner+8 复位 + 00970850 重建(批 152 真身)
		if (inner != nullptr) {
			WNodeInner *in = static_cast<WNodeInner *>(inner);
			wt::ValueTable *sc = static_cast<wt::ValueTable *>(in->scanner);
			if (sc != nullptr) {
				wt::scannerResetState(sc);   // 009cc2d4(140B)真身复用
				delete sc;                   // operator delete(sc,0x40)
				sc = nullptr;                // 悬垂守卫(承载替字面)
			}
			in->scanner = nullptr;           // *(lVar1+8)=0
			in->rebuild00970850();           // 00970850(746B;批 152)
		}
		lexClamp0096cba2(0, false);      // 0096cba2(this,0,0)
		if (!gate009635d8())
			return;
		// 00926356(E,0,tag=cited 0)/ 009263fa(E,kind)— cited(未解 #2)
	}
	// FUN_0096d022(108B)@0031.c:42268(kuna 全读):run 列表逐项
	//   (0x20 步进)payload(+0x10)比对 00a837f6(...,0) — 命中返 1;
	//   走完无命中返 0(rec!=null 调面;rec==0 臂 = 语料字面真,
	//   调用方 92e5e8 已门 *a2!=0 — 原样不达)。
	bool runMatch0096d022(const void *rec) const
	{
		if (rec == nullptr)              // v3==0 尾返(92e5e8 门后不达)
			return true;
		for (void *slot : runsSlots) {
			const char *r = static_cast<const char *>(slot);
			if (r == nullptr)            // 空槽防御(壳态承载替)
				continue;
			if (payloadEq00a837f6(
			        *reinterpret_cast<void *const *>(r + 0x10),
			        *reinterpret_cast<void *const *>(
			            static_cast<const char *>(rec) + 0x10),
			        false))
				return true;             // 42276 命中即返
		}
		return false;
	}
	// FUN_00a837f6(157B)@0035.c:346(kuna 全读 + 0xa837f6 反汇编逐指令
	//   对表):payload 相等 — 同指 1;均非空:+0x08 size 相等 ∧ memcmp
	//   (+0x00 data,size)==0 ∧ +0x48 相等 → 尾臂:a3!=0(styled 腿,
	//   调用面 74df8d MOV EDX,1 = FUN_0074dda2 尾二次编译比对腿):
	//   ~*(u32*)(x58+0xc)&x50 == ~*(u32*)(y58+0xc)&y50(CMP 后)
	//   ∧ y58==0x11befa0(哨兵命中即返)‖ x58==0x11befa0(SETZ);
	//   a3==0(裸;96d022 调面恒 0):u32 +0x50 相等 ∧ +0x58 相等
	//   (0xa83883 CMP R8D,EDI / CMP RSI,RCX — u32/u64 精确)。
	//   ⚠ styled 臂 y58==哨兵时仍解引 y58+0xc — 语料仪器级 UB 字面
	//   (0xa83859 无哨兵旁路),转写原样不防御(测试哨兵腿走 cmp 前
	//   短路构型避免踩 UB;见 markerstest bb1 构型注)。
	static bool payloadEq00a837f6(const void *x, const void *y, bool styled)
	{
		if (x == y)
			return true;
		if (x == nullptr || y == nullptr)
			return false;
		const char *cx = static_cast<const char *>(x);
		const char *cy = static_cast<const char *>(y);
		const quint32 sx = *reinterpret_cast<const quint32 *>(cx + 8);
		if (sx != *reinterpret_cast<const quint32 *>(cy + 8))
			return false;
		if (memcmp(*reinterpret_cast<const void *const *>(x),
		           *reinterpret_cast<const void *const *>(y), sx) != 0)
			return false;
		if (*reinterpret_cast<const quint64 *>(cx + 0x48)
		    != *reinterpret_cast<const quint64 *>(cy + 0x48))
			return false;
		const quint64 x58 = *reinterpret_cast<const quint64 *>(cx + 0x58);
		const quint64 y58 = *reinterpret_cast<const quint64 *>(cy + 0x58);
		if (!styled)
			return *reinterpret_cast<const quint64 *>(cx + 0x50)
			    == *reinterpret_cast<const quint64 *>(cy + 0x50)
			    && x58 == y58;
		quint32 v = ~*reinterpret_cast<const quint32 *>(x58 + 0xc)
		    & *reinterpret_cast<const quint32 *>(cx + 0x50);
		// 0xa8386d-0xa8387f 字面:掩码比后 CMP RCX(=y58)哨兵 → 命中
		//   即返 eq(JZ 0xa83840);未命中再比 RSI(=x58)==哨兵 SETZ。
		//   ⚠ 掩码比双臂都解引(+0xc)→ y58==哨兵时解引哨兵 — 语料
		//   仪器级 UB(哨兵页可读性随进程状态),字面转写不防御。
		const bool eq = (~*reinterpret_cast<const quint32 *>(y58 + 0xc)
		                    & *reinterpret_cast<const quint32 *>(cy + 0x50))
		    == v;
		if (y58 == 0x11befa0)            // 0xa83874 CMP RCX 哨兵
			return eq;
		return eq && x58 == 0x11befa0;   // 0xa83879/7c SETZ DL
	}
	// FUN_0096fb1e(245B)@0031.c:44231:列表清偿(0x20 记录逐项:
	//   +0x18 QArrayData qatomic_int_deref → 0 → QArrayData::
	//   deallocate(2,8);+0x08 对象 ref@+8 降 0 → vt+0x10 槽、
	//   ref@+0xc 降 0 → vt+0x18 槽 — 批 138 清偿真身 @4423x)+
	//   尾:end=begin、*(u16*)(+0x61)=0、FUN_0096f6fe(131B scanner
	//   复位;首行解引 inner(+0xa8)→ 壳态 null 不可达 → cited,
	//   其尾 926356/9263fa 组播已真身化见 EditorContext 广播族)。
	void runClear0096fb1e()
	{
		for (void *slot : runsSlots) {   // 0x20 步进(承载替 slots)
			char *rec = static_cast<char *>(slot);
			if (rec == nullptr)          // 语料槽恒记录;空槽防御同相
				continue;
			void *d = *reinterpret_cast<void **>(rec + 0x18);
			if (d != nullptr && --*static_cast<int *>(d) == 0)
				QArrayData::deallocate(static_cast<QArrayData *>(d),
				    2, 8);                   // 44247 语料字面
			void *o = *reinterpret_cast<void **>(rec + 0x08);
			if (o == nullptr)
				continue;
			int *r8 = reinterpret_cast<int *>(static_cast<char *>(o) + 8);
			if (*r8-- == 1) {        // 旧值==1 → vt+0x10 槽(4425x)
				using Fn = void (*)(void *);
				reinterpret_cast<Fn>(*reinterpret_cast<void **>(
				    *static_cast<void **>(o) + 0x10))(o);
				int *rc = reinterpret_cast<int *>(
				    static_cast<char *>(o) + 0xc);
				if (*rc-- == 1)      // 旧值==1 → vt+0x18 槽(4427x)
					reinterpret_cast<Fn>(*reinterpret_cast<void **>(
					    *static_cast<void **>(o) + 0x18))(o);
			}
		}
		runsSlots.clear();
		anchorRunsFace();         // 语料 end=begin(+0x38=+0x30)
		*reinterpret_cast<quint16 *>(reinterpret_cast<quint8 *>(&f60) + 1) = 0; // +0x61
		runReset0096f6fe();       // 44247 尾 0096f6fe(批 143:节点字段面真身;
		                          //   inner 词法腿批 152 真身(9cc2d4 六槽+
		                          //   00970850 rebuild — 深引擎 cited))
	}
	// FUN_0096d89e(357B)@0031.c:42715:run 列表 → QHash<QString,dptr>
	//   收集(0x75f6/0x7545 消费面)。0x20 记录 +0x18 = QString::d;
	//   d->size(+4)==0 跳过(42735 门);键/值同 d(QHash 插入共享
	//   引用,d unref 面由 QHash 键析构承接 — QString 单指针 Qt5
	//   布局,dptr 重建同构)。消费腿 933830 词表差分仍 cited。
	void runCollect0096d89e(QHash<QString, void *> &out) const
	{
		for (void *slot : runsSlots) {
			const char *rec = static_cast<const char *>(slot);
			if (rec == nullptr)          // 空槽防御(壳态承载替)
				continue;
			void *d = *reinterpret_cast<void *const *>(rec + 0x18);
			if (d == nullptr)
				continue;
			if (*reinterpret_cast<const int *>(
			        static_cast<const char *>(d) + 4) == 0)
				continue;                // 42735 d->size==0 门
			out.insert(*reinterpret_cast<const QString *>(
			    static_cast<const void *>(&d)), d);   // 4274x 插入
		}
	}
};


// 语料偏移锁(批 136b:vptr 双计勘正后锁定;ENodeTask 含虚 D1 →
//   编译器 vptr = 语料 +0x00 vtable 槽;offsetof 于多态类为 GCC 扩展,
//   警告 -Winvalid-offsetof 预期内)
static_assert(offsetof(wt::ENodeTask, kind) == 0x08, "corpus +0x08 kind");
static_assert(offsetof(wt::ENodeTask, modeC) == 0x0c, "corpus +0x0c modeC");
static_assert(offsetof(wt::ENodeTask, state) == 0x10, "corpus +0x10 state");
static_assert(offsetof(wt::ENodeTask, p18) == 0x18, "corpus +0x18 p18");
static_assert(offsetof(wt::ENodeTask, spin20) == 0x20, "corpus +0x20 spin");
static_assert(offsetof(wt::ENodeTask, p24) == 0x24, "corpus +0x24 p24");
static_assert(offsetof(wt::ENodeTask, stopped) == 0x28, "corpus +0x28 stopped");
static_assert(offsetof(wt::ENodeScan, c2c) == 0x2c, "corpus +0x2c c2c");
static_assert(offsetof(wt::ENodeScan, runsF30) == 0x30, "corpus +0x30 runs begin");
static_assert(offsetof(wt::ENodeScan, runsF38) == 0x38, "corpus +0x38 runs end");
static_assert(offsetof(wt::ENodeScan, f40) == 0x40, "corpus +0x40");
static_assert(offsetof(wt::ENodeScan, f60) == 0x60, "corpus +0x60 flags");
static_assert(offsetof(wt::ENodeScan, spin) == 0x70, "corpus +0x70 spin");
static_assert(offsetof(wt::ENodeScan, dirtyLo) == 0x78, "corpus +0x78 dirtyLo");
static_assert(offsetof(wt::ENodeScan, dirtyHi) == 0x80, "corpus +0x80 dirtyHi");
static_assert(offsetof(wt::ENodeScan, cursor) == 0x88, "corpus +0x88 cursor");
static_assert(offsetof(wt::ENodeScan, inner) == 0xa8, "corpus +0xa8 inner");

// ENodeRunner — 语料 DocumentTaskRunner(0x28,TI 0x11ad4c0,vptr
//   0x11ad508;ctor FUN_009638d2 33B @0031.c:34356:{+0x08=0,
//   +0x10=E,+0x18=node,+0x20=serial})→ QRunnable 委托(外库
//   边界惯例;run 槽 = vtable slot10 0x96aca0 1357B piece-table
//   面 — cited — wave-2,壳态 no-op)。
struct ENodeRunner : QRunnable {
	EditorContext *e = nullptr;
	wt::ENodeTask *t = nullptr;
	int serial = 0;
	ENodeRunner(EditorContext *e_, wt::ENodeTask *t_, int s)
	    : e(e_), t(t_), serial(s)
	{
		setAutoDelete(true);
	}
	void run() override {}        // 0x96aca0 — cited — wave-2
};

} // namespace wt

// --- 0x7545 record 载荷面(批 143;语料 CSuperBufferBase 族,0035.c)---
namespace wt {

// FUN_00a92326 varint_append(143B)@0035.c:11411(kuna 反汇编 @0xa92326
//   全读):LEB128 变体 — v = x*2+1(奇尾标非末字节);n = 64-BSR(x|1)
//   逆前导;n=字节序号(≥57 特例:x 原样 1B)。append(v<<((63-n)/7*7? —
//   语料乘链 = (63-n)/7*511*...*4*8·3f7 分解 → 等价移位 s=(63-n)/7*7)。
//   x=0 → v=1,BSR 未定义保护(语料 (x|1) 面同相)。
inline void varintAppend00a92326(QByteArray &out, quint64 x)
{
	int n = 0;
	quint64 probe = x | 1;
	while (probe != 1) {             // BSR(x|1) 循环形(==1 → 63-n=0)
		probe >>= 1;
		++n;
	}
	// 63-n = 63-n … 语料 n = 63-BSR → 我方 BSR 循环计 n' = BSR;
	//   uVar2 = 0x3f ^ BSR = 63-BSR;EAX = 0x40-uVar2 = BSR+1;
	//   JG 0x38 → BSR+1 > 56(x 高位满 8B)特例:x 原样 1B
	const int bsr = n;               // BSR(x|1)
	if (bsr + 1 > 0x38) {            // 0xa9234c JG → 特例臂
		out.append(char(quint8(x)));
		return;
	}
	const int sh = ((0x3f - bsr) / 7) * 7;   // 0xa92357-0xa9237d 乘链 = /7*7
	const quint64 v = (x * 2 + 1) << sh;     // 0xa92387 LEA v=x*2+1
	out.append(reinterpret_cast<const char *>(&v), 8);  // CALL 0x4bf640(8B append)
}
// FUN_00a924ba CSuperBuffer ctor(35B)@0035.c:11528:{d=shared_null,
//   off=-1,last=0,cnt=0} — 承载替:offset 流,语料 0x20 头 + QByteArray
//   体 → 我方 QByteArray data + qint64 off/last 字段(怪癖登记)
struct WBuffer {
	QByteArray data;                 // +0x00 d(shared_null ≡ 空)
	qint64 off = -1;                 // +0x08 last 写入行(ctor -1)
	quint64 last = 0;                // +0x10 语料 last 行游标
	quint64 cnt = 0;                 // +0x18 run 计数(bit63 = 直写旗)
	// FUN_00a925d0(102B)@0035.c:11575(kuna 全读):off 相同 → cnt++;
	//   否则 flush00a92502() + off=v + cnt=1(bit63 保持)
	void sameOff00a925d0(qint64 v)
	{
		if (off == v) {
			cnt = (cnt & 0x8000000000000000ull)
			    | ((cnt + 1) & 0x7fffffffffffffffull);
			return;
		}
		flush00a92502();
		off = v;
		cnt = (cnt & 0x8000000000000000ull) | 1;
	}
	// FUN_00a92636(32B)@0035.c:11614:delta 编码 — sameOff(v-(off))+
	//   last=v(偏移面:语料 +0x10 last;调面 = trie 行值)
	void delta00a92636(quint64 line)
	{
		sameOff00a925d0(qint64(line) - last);   // ⚠ 语料 off 面 = last
		last = line;                            //   游标差(delta 链真身
		                                        //   a92636 v-(+0x10);+0x08
		                                        //   语义 = delta 差)
	}
	// FUN_00a92502(109B)@0035.c:11554(kuna 全读):cnt==0 → 直返;
	//   bit63=0 → varint(off)/bit63=1 → varint(zigzag(off)) 00a923b5
	//   (00a922f0 zigzag = x*2^x>>63 — kuna 全读);cnt≥2 → append('\0')
	//   + varint(cnt)。
	void flush00a92502()
	{
		if ((cnt & 0x7fffffffffffffffull) == 0)
			return;
		if (cnt & 0x8000000000000000ull)      // +0x1f 符号字节面
			varintAppend00a92326(data,        // 00a923b5:zigzag 先
			    (quint64(off) * 2) ^ quint64(off >> 63));
		else
			varintAppend00a92326(data, quint64(off));
		if ((cnt & 0x7fffffffffffffffull) < 2)
			return;
		data.append(char(0));                 // QByteArray::append('\0')
		varintAppend00a92326(data, cnt & 0x7fffffffffffffffull);
	}
};
// FUN_0093f7aa trie(707B)@0031.c:4985(kuna 全读;0030.c:32257 语料
//   同体)— B 树形行集合(0x30 根:{flag,tag,depth,data*} + 槽数组
//   0x10 起 8B/槽 + 0x100 子指针区);插入腿 0x30 容量 30 满 → 0093f250
//   分裂 + 0093d5a0 交换(承载替:QVector<qint64> 有序集 — 槽语义
//   [v4*8+0x10]=line 序列,插入序保持;分裂面 = QVector 内部重排,
//   怪癖登记;遍历序 = 行升序 — 0x7545 walk 走查同序)。
//   消费面(9334x 走查)只读行值序列 → 承载替同相;0x1e 容量常量字面。
struct WNodeTrie {
	QVector<qint64> lines;           // 0x30 根槽面承载(升序;语料叶槽
	                                 //   有序 B 树 — 有序遍历不变量)
	bool root00933366() const { return !lines.isEmpty(); }  // 0093334x 根非空门
	// 0093f7aa 插入腿(5026-5032 首个 >line 的槽位查找 + 5117-5124
	//   右移批插):叶槽有序 → 插入序 = upper_bound(等值随后,语料
	//   `<=` 门同相)。分裂面 trie_insert_node30(1369B,0031.c:4687
	//   全读:叶满 0x1e → 96f21c 换根/9cc22c 族)/FUN_0093f7aa 5069-5096
	//   半满晋升只重排内存布局,产出序列恒升序 — QVector 保序承载
	//   遍历序同相(quirks #31 同族承载替证据;5c 期字节级对表待)。
	void insert0093f7aa(qint64 line)        // 0093f7aa(有序插入腿)
	{
		int i = 0;
		while (i < lines.size() && lines.at(i) <= line)
			++i;                     // 5026-5032 值 <= line 继续走
		lines.insert(i, line);       // 5117-5124 右移批插(承载替)
	}
	// 009334x 全走查(语料 do-while:pcVar4=+8 首,0x10+v14*8 逐槽,
	//   00a92636(line) — 子树跳面 0x100 链 = 承载替直序遍历)
	template <typename F>
	void walk00933472(F &&emitLine) const
	{
		for (qint64 v : lines)
			emitLine(quint64(v));
	}
};

} // namespace wt
