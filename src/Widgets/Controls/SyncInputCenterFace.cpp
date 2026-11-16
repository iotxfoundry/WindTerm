// SyncInputCenterFace.cpp — 多视图同步输入中心。

#include "Widgets/Controls/SyncInputCenterFace.h"

// 出处:QMetaObject 0x011a08e0(class="SyncInputCenter",methods=3,signals=3);
// ctor 内联在调用点,仅转发 QObject 基构造。
SyncInputCenterFace::SyncInputCenterFace(QObject *parent)
    : QObject(parent)
{
}

// 0x00903972(127B)dtor 真身 —— **注意这是手写数组,不是 QList**:
//   vptr = &SyncInputCenter_vtable;
//   for (p = +0x18; p != +0x20; p += **0x20**)
//       每元素 +0x8 处引用计数减一,归零 operator_delete(该件);
//   operator_delete(+0x18)(数组本体);
//   QObject::~QObject
// deleting 0x009038e6(140B):同上 + operator_delete(this, 0x30)。
// 判据:QList 的遍历是"先 detach 再按 d 指针算 begin/end",而这里是
//   两个裸指针相减 + 固定步长 0x20 —— 两者在反编译里长得很像,容易混。
SyncInputCenterFace::~SyncInputCenterFace()
{
	if (m_begin18 != nullptr)
		operator delete[](m_begin18);
}

// ───────── moc 生成面(出处:QMetaObject 元数据) ─────────
// metaObject 0x009036d0 → &PTR_staticMetaObject_011a08e0
// qt_metacast 0x00903846(strcmp "SyncInputCenter" → QObject::qt_metacast)
// qt_metacall 0x00903888(93B):3 条记录转发到 0x009037a8;
//   超出则 index - 3。
