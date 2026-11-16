#include "SshBridge.h"

#include <QList>
#include <QString>

#include <functional>

// Implementation notes reconstructed from the signal-routing hub
// FUN_007bc21e (see ssh-internals.md "signal routing"):
//
// commandOutput is distributed to subscribers after stripping a trailing
// "###" prompt marker (FUN_007bebdc: QString::endsWith("###") -> chop),
// which is how the commander detects completion.

SshBridge::SshBridge(QObject *parent)
	: SuperBridge(parent)
{
}

// 0x00866c36(508B)析构真身。逐句:
//   vptr = &SshBridge_vtable;
//   ① 若 +0x30 非空 且 其引用计数(+4)非 0 且 +0x38 非空
//        → (*(**(+0x38) + 0x20))()        即 vtable+0x20 释放
//   ② +0x40/+0x48 一对同构,同样条件同样动作
//   ③ SerialBridge_h7c83c6(this)(0x007c83c6,271B)—— 基链上的公共清理
//   ④ +0x160 引用计数减一,归零 operator_delete
//   ⑤ +0x150 引用计数减一,归零 operator_delete
//   ⑥ 其余字段(见后续批次)继续释放,最后落 SuperBridge 析构
// deleting 0x00866e32(23B):同上 + operator_delete(this, 0x170)。
SshBridge::~SshBridge()
{
	if (m_pair30 != nullptr
	    && *reinterpret_cast<int *>(static_cast<char *>(m_pair30) + 4) != 0
	    && m_pair38 != nullptr) {
		// cited:vtable+0x20 的释放腿(件类型未复原)
	}
	if (m_pair40 != nullptr
	    && *reinterpret_cast<int *>(static_cast<char *>(m_pair40) + 4) != 0
	    && m_pair48 != nullptr) {
		// cited:同上
	}
	// ③ SerialBridge_h7c83c6(this)—— 基链公共清理(0x007c83c6)
}

// 0x00864630(437B)ensureShared 真身。逐句:
//   门:+0x160 为空 或 其引用计数(+4)为 0 或 +0x168 为空 → 需要新建
//   obj = new 0x40 字节件(FUN_00869f80)        ← 共享对象的构造
//   d   = ExternalRefCountData::getAndRef(obj)   ← 建外部引用计数块
//   旧 (d, obj) 换出并 atomic_refptr_delete
//   若新建失败(计数仍为 0)→ 传 nullptr
//   然后 connectImpl(obj 的某个信号, this, functor 0x0091823c)
// 说明:这就是"第一次用到才建、建完把信号接到自己身上"的惰性装配。
void SshBridge::ensureShared()
{
	if (!m_shared160.isNull())
		return; // 门:已有且计数非 0

	// cited:FUN_00869f80(0x40B 件构造)+ getAndRef + atomic_refptr_delete
	//       + connectImpl(obj, …, this, 0x0091823c)
}

void SshBridge::distributeCommandOutput(const QString &output)
{
	// FUN_007bebdc transcribed
	QString text = output;
	if (text.endsWith(QLatin1String("###")))
		text.chop(3);

	// FUN_007baf70: fan out to every subscribed term/commander
	for (const auto &subscriber : m_subscribers)
		subscriber(text);

	emit commandOutput(QString(), QString(), text);
}

// ───────── 三个取用器(虚面 vt13/vt14/vt15)─────────
// 三个函数同构:只读 +0x50/+0x58 那一对,并在"计数为 0"时退化为传 0。
//   vt13 0x00862692(52B) → FUN_0086c20a(this, +0x58 | 0)
//   vt14 0x008626c6(52B) → FUN_0086c312(this, +0x58 | 0)
//   vt15 0x0086270a(58B) → 先门:+0x70 非空且 FUN_00627600() != 0 则直接返回;
//                          否则 FUN_0086bf84(+0x58 | 0)
void SshBridge::takeWith086c20a(void *out) const
{
	Q_UNUSED(out);
	// cited:FUN_0086c20a(this, 有效则 m_pair58, 否则 0)
}

void SshBridge::takeWith086c312(void *out) const
{
	Q_UNUSED(out);
	// cited:FUN_0086c312(this, 有效则 m_pair58, 否则 0)
}

void SshBridge::takeWith086bf84() const
{
	if (m_f70 != nullptr && /* FUN_00627600() */ false)
		return;
	// cited:FUN_0086bf84(有效则 m_pair58, 否则 0)
}

// ───────── moc 生成面(出处:QMetaObject 元数据) ─────────
// metaObject 0x00918010 → &PTR_PTR_011a9020(class="SshBridge")
// qt_metacast 0x0091810a(strcmp "SshBridge" → SuperBridge::qt_metacast)
// qt_metacall 0x0091814c(97B):基类 SuperBridge::qt_metacall 之后
//   两条记录(两条信号)转发到 0x0091809e 的 switch:
//     slot 0 → FUN_00918028(57B,activate idx 0)   sftpCreated
//     slot 1 → FUN_00918062(60B,activate idx 1)   shellCreated
//   记录 10 → 反查信号号(0 / 1);超出则返回 (index - 2)。
