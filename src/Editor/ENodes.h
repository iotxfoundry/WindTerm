#pragma once
// eNodes 节点层建模(批 136,方案书 tools/re/ENODES-RECON.md Q4 直执)。
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
#include <QRunnable>
#include <QtGlobal>

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
	                              //   + FUN_00970850 — cited — wave-2(壳期 nullptr)
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
		inner = nullptr;          // operator_new(0x18)+970850 — cited — wave-2
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
	//   位面(b&1 / b>>1&1 / b>>4&1)—— record 载荷布局未读
	//   (ENODES-RECON 未解 #1)→ 旗位面 cited;尾 FUN_0096f782
	//   (135B)整理面 cited。
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
		// +0x60/61/62 旗位(record 首字节位面)— cited — wave-2
		// FUN_0096f782 — cited — wave-2
	}
	// FUN_0096fb1e(245B)@0031.c:44231:列表清偿(0x20 记录逐项
	//   +0x18/+8 解引用计数链 — record 载荷未读 → cited)+ 尾:
	//   end=begin、*(u16*)(+0x61)=0、FUN_0096f6fe(131B scanner
	//   复位,inner+8 解引面)— 壳态 inner=nullptr → cited。
	void runClear0096fb1e()
	{
		runsSlots.clear();
		anchorRunsFace();         // 语料 end=begin(+0x38=+0x30)
		*reinterpret_cast<quint16 *>(reinterpret_cast<quint8 *>(&f60) + 1) = 0; // +0x61
		// 0x20 记录解引清偿 + 96f6fe scanner 复位 — cited — wave-2
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
