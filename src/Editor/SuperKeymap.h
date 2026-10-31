#ifndef SUPERKEYMAP_H
#define SUPERKEYMAP_H

#pragma once

#include <QList>
#include <QRegularExpression>
#include <QVariant>
#include <QVector>
#include <QObject>

#include <memory>
#include <set>
#include <utility>

// KeymapCtrlPtr —— ctrl 块承载(km3 定案:ctrl = boost::xpressive
// 编译产物 —— 分派体 FUN_0068aaf0(4118B,0021.c 12163)= xpressive
// 动态编译器(0068dd28 "expression cannot be quantified" 路径串 =
// boost/xpressive/detail/dynamic/dynamic.hpp 铁证);boost 边界不逆向,
// EXT-BOUNDARY)。语料对应体 = FUN_00681a40 产的 0x18 ctrl 块
// (PTR_FUN_011895b0,use 初 0x100000001,LOCK use++ 4649-4651):
// 委托 boost、永不解引 —— _Sp_counted_base 计数面(use/weak)由
// std::shared_ptr<void> 标准库委托承接;编译腿 cited — wave-2,
// 块体不伪造。
using KeymapCtrlPtr = std::shared_ptr<void>;

// TrieCtrlLess —— FUN_006857f4(137B,0021.c 8233-8282)比较器承载:
// get_insert_hint 探测键序 = 读 value.second(+0x28)即 ctrl 指针
// (62858 实证 `local_370 < *(node+0x28)`),非 pair 全序。
// shared_ptr 载形:语料裸指针 <(同块等价/异块地址序)→ owner_before
// (管控块序;别名序为裸指针序的超集严格弱化,"同键不重插" 契约
// 不变);weak 侧同 owner_before(同 _Sp_counted_base 管控块)。
struct TrieCtrlLess {
	bool operator()(const std::pair<void *, KeymapCtrlPtr> &a,
	                const std::pair<void *, KeymapCtrlPtr> &b) const
	{
		return a.second.owner_before(b.second);
	}
	bool operator()(const std::pair<void *, std::weak_ptr<void>> &a,
	                const std::pair<void *, std::weak_ptr<void>> &b) const
	{
		return a.second.owner_before(b.second);
	}
};

// KeymapChildGroup —— TrieNode +0x78..+0xb0 组域(p3_notes_km2 §6 定案,
// 8 qword;FUN_00681a40 00681b0a-00681b7a 布局 + §6 组交换 62781-62797):
//   +0x78 pred QSlotObjectBase*(ref@+4;§4 门谓词槽;qslotobject_release_destroy2)
//   +0x80/+0x88 slotA/slotB(use@+8;vptr+8 dispose,62816-62833)
//   +0x90..+0xa0 children vector<pair<wstring,X>>(COW 16B/元素 62738-62777;
//       rep[-8]++/clone —— Qt QVector COW 同契约承载)
//   +0xa8 记录向量预算(§9 need = +0xb0 + 1 + +0xa8,63245)
//   +0xb0 记录写入下标(63381 plVar40 = begin + [+0xb0]*5)
struct KeymapChildGroup {
	void *pred = nullptr;                    // +0x78
	void *slotA = nullptr;                   // +0x80
	void *slotB = nullptr;                   // +0x88
	QVector<QPair<QString, void *>> children; // +0x90..+0xa0(COW 承载)
	quint64 xA8 = 0;                         // +0xa8
	quint64 xB0 = 0;                         // +0xb0
};

// TrieNode —— FUN_00681a40 0xb8 节点域转写(decomp-part-0021.c 4622-4643):
//   +0x08 树1 {color@8,parent@0x10,left@0x18,right@0x20,count@0x28}
//     值 = {payload raw@0x20, ctrl@0x28}(shared:FUN_00686134 克隆 use@+8++,
//     FUN_0067faa0 释放 refcounted_vt_destroy);装载腿 cited — wave-2
//   +0x30 树2 {color@0x30,parent@0x38,left@0x40,right@0x50,count@0x58}
//     值 = {payload raw@0x20, ctrl@0x28}(weak:§7 插入 weak@+0xc++,
//     §8 死引用裁剪)—— std::set<pair,CtrlLess> 承载
//   +0x60 payload self / +0x68 ctrl(shared;ctrl 挂接 cited)
//   +0x70 use(LOCK 原子)
//   +0x78..+0xb0 KeymapChildGroup
struct TrieNode {
	std::set<std::pair<void *, KeymapCtrlPtr>, TrieCtrlLess> keyTree;  // +0x08 树1
	std::set<std::pair<void *, std::weak_ptr<void>>, TrieCtrlLess> refTree;  // +0x30 树2(weak 载形)
	quint64 refCount = 0;        // +0x58 树2 侧挂计数(§7 ++/§8 --)
	TrieNode *payloadSelf = nullptr;   // +0x60
	KeymapCtrlPtr payloadCtrl;         // +0x68 ctrl(km3:shared_ptr 承载;
	                                   //   语料 0x18 ctrl 块 use@+8/weak@+0xc
	                                   //   计数面由 shared_ptr 标准库委托)
	quint64 use = 0;                   // +0x70
	KeymapChildGroup group;            // +0x78..+0xb0
};

// KeymapEntry —— 00677d7e 0x50 节点域转写(operator_new(0x50),
// vtable PTR_FUN_01189508;shared 头@+0..+0xf → 条目域自 +0x10 起):
//   +0x10 keys 编码 wstring(keys_parseAngleNotation 00674cdc 产物)
//   +0x18 regexSource(onig 编译腿 00678295-006783fe,cited)
//   +0x20 repeatable byte(map["repeatable"] toBool,00678618)
//   +0x24 modesMask u32(modes 位掩码;split 空 → 0x1f,0067803b)
//   +0x28 actionType(0=action/1=map/2=script,qstrcmp 序,00678801)
//   +0x30 payload QVariant(action/map/script toByteArray().trimmed(),006787d1)
//   +0x40 when QVariant(map["when"] 无条件 assign,006785ae)
struct KeymapEntry {
	QString keysEncoded;        // +0x10
	QString regexSource;        // +0x18(cited — wave-2:编译腿未转写,域留置)
	bool repeatable = false;    // +0x20
	quint32 modesMask = 0;      // +0x24
	int actionType = 0;         // +0x28
	QVariant payload;           // +0x30
	QVariant when;              // +0x40
	// +0x08 槽承载 —— Trie 根(FUN_00681a40 换入槽;§4 门 00675296
	//   读 *(lVar7+8):根空或 *(根+0x78)==0 即出)。onig 编译腿
	//   00678295-006783fe → FUN_00687320 建树换入,cited — wave-2。
	//   km3 装载腿语义:root 空 = 装载腿未建 → §4 门短路即语料
	//   "无条目" 语义(装载 KeymapEngine::loadKeymapSources 建条目时
	//   root 恒空,匹配恒短路 —— 现状即语料语义,不伪造根)。
	//   shared_ptr<TrieNode> 承载(语料槽项 = shared 头 + 节点;
	//   槽项计数面由标准库委托)。编译腿落地后由装载翼换入真根。
	std::shared_ptr<TrieNode> trieRoot;   // +0x08 槽
};

// 匹配上下文记录 —— FUN_006741a0(55B)转写:{QList*@0, wstring@8,
// int=2@0x10, wstring@0x18};006777e6 param_4;mode=2 匹配走 +0 清单
// (§15:完全命中 erase 槽项 006751ce;前缀走查 0067df30 append 槽项)。
struct KeymapInputRecord {
	QList<KeymapEntry> m_chords;   // +0(mode=2 学习弦槽;7500e 命中后 erase;
	                               //   前缀走查 0067df30 append 槽项)
	QString m_buffer;              // +8(累计键串;feedKey append)
	int m_flags = 2;               // +0x10(语料初值 2)
	QString m_pending;             // +0x18(语料第二 wstring;006745b0 不触及)

	// FUN_006745b0(106B):槽清 + +8 键串复位(0x18 域不动 —— 语料;
	//   0067500e §13 命中分发 00677258 消费面)
	void clearBuffer()
	{
		m_chords.clear();   // FUN_0067ce4c(*param_1)
		m_buffer.clear();   // 00674580 段 wstring 复位
	}
};

// KeymapMatchRecord —— §9-10 记录条目(p3_notes_km2 §9 定案,0x28B/条,
// 5 qword;初始化式 00676e5f-00676e77 / joined_r0x00675bbc 63369-63378):
//   {rep, tail, flag, pad, rep2, flag2}
//   初始 = {owner=token rep, owner, 0, 0, owner, 0};叶写(谓词 false,
//   63429-63433)= rec[0]=rec[3](rep←rep2)、rec[1]=token 尾指针(63432
//   local_248=p_Var3)、rec[2]byte=0。命中 token {rep,tail} 裸视图,
//   非拥有(生命周期依赖 token 存活;疑似悬伏点,原样保留不修)。
//   §13 QString::fromUcs4(63533)以 rep 消费。
struct KeymapMatchRecord {
	const wchar_t *rep = nullptr;    // +0x00
	const wchar_t *tail = nullptr;   // +0x08
	bool flag = false;               // +0x10
	quint32 pad = 0;                 // +0x14
	const wchar_t *rep2 = nullptr;   // +0x18(谓词调用前先行写,63426)
	bool flag2 = false;              // +0x20
};

// 记录宿主容器 —— local_90 0x38 形(63148-63163){strong 计数@+0(LOCK++),
//   当前向量节点@+8/begin@+0x10/end@+0x18/cap@+0x20 内联缓存,+0x28/+0x30
//   双向链头(空形自指)};节点 0x28 = {begin,end,cap,next,prev}(63308-63335
//   双向链挂历史向量)。外层身份(list vs Qt 节点形)未解 —— 承载 = 计数 +
//   当前向量 + 0x28 节点链,偏移注释照抄,行为面(当前向量重挂/历史换出
//   63219-63242)随消费腿(§13)cited。
struct KeymapRecordSink {
	int refcount = 0;                       // +0(63161-63163 LOCK++)
	void *curNode = nullptr;                // +8 当前向量节点(0x28 形)
	KeymapMatchRecord *begin = nullptr;     // +0x10
	KeymapMatchRecord *end = nullptr;       // +0x18
	quint64 cap = 0;                        // +0x20
	void *listFwd = nullptr;                // +0x28(空形自指,63159)
	void *listBwd = nullptr;                // +0x30(空形自指,63160)

	KeymapRecordSink()
	{
		listFwd = &listFwd;   // 63159:piVar35+10 = piVar35 + 10
		listBwd = &listFwd;   // 63160:piVar35+0xc = piVar35 + 10
		refcount = 1;         // 63161-63163 LOCK;+0 += 1
	}
};

// FUN_0067500e param_1 out 结构转写:{+0 flags u32, +6 结果 int};
// param_1 = 006777e6 栈上指针数组(local_78..local_48,六槽),各槽指向
// {flags, 上下文对象×2, 记录, …, 结果}——槽间址逐槽对位 wave-2(cited);
// 语料消费面:*param_1=flags、param_1[3]→记录(006745b0/0067df30)、
// param_1[6]=结果(00675d97/00675e70 写 1/2)。
struct MatchOut {
	quint32 flags = 0;
	int result = 0;    // 0=未竟 1=前缀 2=完全命中(006777e6 消费面)
	QObject *ctxWhen = nullptr;          // 语料 *[1](JS when/脚本宿主,cited)
	QObject *ctxDispatch = nullptr;      // 语料 *[2](命中分发 mainPane cast 上下文,cited)
	KeymapInputRecord *record = nullptr; // 语料 *[3](006745b0/0067df30)
	KeymapRecordSink *sink = nullptr;    // §9 记录宿主(local_90;§13 消费,cited)
};

// SuperKeymap —— 语料转写(批 46/47 + 本批:编解码真身 + 匹配翼
// 辅助真身;铁律 6)。
// 语料:FUN_00674648(161B,ctor)—— QObject(parent)→
//   SuperKeymap_vtable → +0x10 = 槽列表(FUN_0067db7c init,容量 2)→
//   +0x18 = QRegularExpression("meta\\+|\\+meta", CaseInsensitive)
//   (006746b9 字面实证)。
// 引擎复位 FUN_0067461a(45B):FUN_0067db40(+0x10)(容量确保)→
//   FUN_0067ce4c(+0x10 + mode*8)(mode 槽清)。
// 装载翼:00678a56(4985B,条目循环)→ 00677d7e(3031B,单条目);
// 匹配翼:006777e6(1347B,增量键串)→ 0067500e(9978B,15 段,
//   §6-§8 注记级/§12 cited;Trie 根 = entry+0x18 槽,装载腿 cited);
//   角括号解析 keys_parseAngleNotation 00674cdc(753B);
//   合成键事件 FUN_0075debe(529B)/动作分发 0066a116(49B)+007682c0
//   (18B)真身在 .cpp(调用面 mainPane cast cited 短路)。
// 键码双向编解码全局表 —— 语料 DAT_011c1960(_INIT_62 初始化
// FUN_006741ec(26B):{u32@0, QList@8, root@0x10};decomp-part-0016.c
// 13587-13588)。读侧 00674206/006742d2(正)、00674b1e/00674cce(反);
// 全库唯一写入口 = 00674b1e 自身(列表 append + FUN_006804ac 查/插,
// decomp-part-0020.c 62270-62276;xref --callers/--refs:无其他调用点,
// 表内容运行期惰性生成,无静态数据可读)。C++ 承载:QList<uint> 槽表
// (权威 序→键,00674206 体)+ QHash<uint,int> 键→槽(00674b1e 体的
// boost-trie 查/插可观测契约同构;trie 机械本体 006804ac 701B 不转写
// —— 存储载体等价替换,契约行为逐行有落点)。
uint keymapKeyForward(uint slot);      // 00674206/006742d2(thunk)
uint keymapKeyReverse(int key);        // 00674b1e/00674cce(thunk)

class SuperKeymap : public QObject {
	Q_OBJECT

public:
	explicit SuperKeymap(QObject *parent = nullptr);   // FUN_00674648

	// FUN_0067461a(45B):mode 索引槽清
	void reset(int mode);

	const QRegularExpression &metaRegex() const { return m_metaRe; }   // +0x18

	// 装载翼 ──
	void loadEntries(const QVariantList &list, int mode);   // FUN_00678a56
	void parseEntry(const QVariantMap &map, int mode);      // FUN_00677d7e

	// 匹配翼 ──
	int feedKey(KeymapInputRecord &record, uint key, int flags);   // FUN_006777e6
	int matchTrie(MatchOut &out, QList<KeymapEntry> &slotList,
	              const QVector<QString> &tokens, int mode);        // FUN_0067500e

private:
	QList<QList<KeymapEntry>> m_slots;   // +0x10(FUN_0067db7c 容量 2;mode*8 寻址)
	QRegularExpression m_metaRe;         // +0x18
};
#endif // SUPERKEYMAP_H
