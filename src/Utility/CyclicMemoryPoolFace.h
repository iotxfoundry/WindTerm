#pragma once

#include <QObject>

// CyclicMemoryPoolFace — 循环内存池(QObject 派生,1 条槽)。
//
// 出处:RTTI "CyclicMemoryPool";QMetaObject 0x011a0160
// (rev=8,class="CyclicMemoryPool",methods=1,**signals=0**,**props=0**);
// sizeof = **0x28**(deleting 0x00902e2c 的 operator_delete(_,0x28));
// dtor 0x00902de8(67B)/deleting 0x00902e2c(80B);
// metacast 0x00902d52 / metacall 0x00902d94(84B)。
//
// 唯一元方法:`freeUnusedMemoryBlocks()` 槽 —— 名字即语义。
//
// 字段(dtor 实读):**+0x20 一个 0x20 字节的池体**
//   (dtor 里 `operator_delete(+0x20, **0x20**)` ⇒ 池体本身 0x20)。
//   0x20(池偏移) + 0x20(池大小)= 0x40,但 sizeof 是 0x28 ——
//   ⇒ +0x20 处是指针,指向另行分配的 0x20 块。**又是"末尾指针"结构**,
//   与 TriggerData 的 +0x18 同一模式。
class CyclicMemoryPoolFace : public QObject {
	Q_OBJECT

public:
	explicit CyclicMemoryPoolFace(QObject *parent = nullptr);
	~CyclicMemoryPoolFace() override; // 0x00902de8

public slots:
	void freeUnusedMemoryBlocks(); // 唯一槽

private:
	void *m_pool20 = nullptr; // +0x20 指向 0x20 字节池体
};
