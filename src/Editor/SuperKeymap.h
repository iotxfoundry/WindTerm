#ifndef SUPERKEYMAP_H
#define SUPERKEYMAP_H

#pragma once

#include <QList>
#include <QRegularExpression>
#include <QVariant>
#include <QVector>
#include <QObject>

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
