// ForwardingHandlerFace.cpp — 转发处理器。

#include "Sessions/Tunnels/ForwardingHandlerFace.h"

// 注销腿 / 元素释放(同族地址,尚未开批):
static void unregisterFromCenter(void *global, void *self); // 0x005eda26
static void releaseElem(void *list, void *elem);            // 0x005f2480

ForwardingHandlerFace::ForwardingHandlerFace(QObject *parent)
    : QObject(parent)
{
}

// 0x005f1838(367B)析构真身。逐句:
//   vptr = &ForwardingHandler_vtable;
//   FUN_005eda26(DAT_011c13e0, this)   ← 从全局中心(DAT_011c13e0)注销
//   +0x18 QList:引用计数 > 1 时先 detach(FUN_005f2480(list, 1)),
//                再逐个元素调 FUN_005f2480(list, elem) 释放,
//                最后 QListData::dispose。
// deleting 0x005f19a8(23B):同上 + operator_delete(this, size)。
ForwardingHandlerFace::~ForwardingHandlerFace()
{
	unregisterFromCenter(nullptr, this);
	m_f18.clear();
}

// 0x008fceb0(740B)信号桥真身。三路:
//   op=0(invoke):index 0 → 0x008fcdf8(this, handler)(emit startX11Server)
//                 index 1 → 0x008fce2c(this, 7 个实参)(emit startForwardingServer)
//   op=10(反查):args[1] 指向 {fn,0};fn 命中上面两个之一 → 写回 0 / 1
//   op=0xc(**属性面**):本类有一个运行期属性,index 0/1 两条;
//        值非 0 时走 `if (DAT_011c1454 != 0) goto …` 的全局分支,
//        为 0 时用 QMetaObject::className() 拼一个类名串 ——
//        这段是"按类名缓存属性值"的实现,细节待该层开批。
//
// ───────── moc 生成面(出处:QMetaObject 元数据) ─────────
// metaObject 0x008fcde0 → &PTR_staticMetaObject_0119f400
// qt_metacast 0x008fd1a4(strcmp "ForwardingHandler" → QObject::qt_metacast)
// qt_metacall 0x008fd1e6(109B):**op=0 与 op=0xc 两条都转给同一个桥**
//   (语料里 param_2 == 0 与 == 0xc 各调一次 0x008fceb0),
//   超出两条则返回 (index - 2)。
