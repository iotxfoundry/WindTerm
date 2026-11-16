// SshExecutorFace.cpp — SSH 命令执行器。

#include "Sessions/Transports/SshExecutorFace.h"

// 出处:QMetaObject 0x011a9220(class="SshExecutor",methods=2,signals=2,
// superdata=0);ctor 内联在调用点,仅转发 QObject 基构造。
SshExecutorFace::SshExecutorFace(QObject *parent)
    : QObject(parent)
{
}

// 0x00869e26(322B)dtor 真身。逐段:
//   vptr = &SshExecutor_vtable;
//   ① FUN_0086247e(+0x10, &+0x18)          ← 先拆上下文对
//   ② +0x28 QList:从尾向头逐元素释放
//      (每元素在 +0x8 / +0x10 各带一个引用计数件,两个都要减)
//   ③ +0x38 独立块 operator_delete(_, 0x10)
//   ④ 0x0086a570(&+0x28)                    ← 列表本体清理(29B)
//   ⑤ QObject::~QObject
// deleting 0x00869f68(23B):同上 + operator_delete(this, 0x40)。
SshExecutorFace::~SshExecutorFace()
{
	// ① 上下文对(0x0086247e)
	m_items28.clear(); // ②③④ 由容器与调用方衔接
}

// ───────── moc 生成面(出处:QMetaObject 元数据) ─────────
// metaObject 0x00918210 → &PTR_staticMetaObject_011a9220
// qt_metacast 0x009182e0(strcmp "SshExecutor" → QObject::qt_metacast)
// qt_metacall 0x00918322(93B):2 条记录转发到 0x0091827a;
//   槽 0 → 0x0091823c(commandOutput,3 参);槽 1 → 0x00918228(restartElapsedTimer);
//   记录 10 反查信号号;超出则 index - 2。
