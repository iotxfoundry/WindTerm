// TransferTaskFace.cpp — 传输任务。

#include "Sessions/Transfers/TransferTaskFace.h"

static void freeList20(void *list);   // 0x00642480
static void freeList28(void *list);   // 0x006424a0
static void freeSmall(void *p);       // 0x00a80de0

TransferTaskFace::TransferTaskFace(QObject *parent)
    : QObject(parent)
{
}

// 0x0063c630(470B)析构真身 —— 顺序里有两条容易漏的:
//   vptr = &TransferTask_vtable;
//   ① **+0xc0 非 0 → umask(+0xc0)**：这是把构造时保存的进程 umask 还原。
//      本任务改过 umask(传输文件权限),不还原会污染整个进程。
//   ② +0xf0 / +0xf8 两个列表走清理腿 0x006424de;
//   ③ +0x20 列表整体换回 shared_null 后释放;
//   ④ +0xc4 **bit3 → +0x150 套接字**(vtable+0x20 释放,置 0);
//      +0xc4 **bit4 → +0x158 套接字**(同上)。
//      两个套接字是**按标志位分别持有**的,不是一对。
//   ⑤ +0x130 原子引用计数归零 → 0x0063a9a6 释放 + 0x00a80de0 + delete(0x20);
//   ⑥ +0xb0/+0xa8/+0x48/+0x40/+0x38/+0x30 引用计数递减;
//      +0x28 → 0x006424a0,+0x20 → 0x00642480;最后 QObject 析构。
// deleting 0x0063c806(23B):同上 + operator_delete(this, 0x168)。
TransferTaskFace::~TransferTaskFace()
{
	umask(m_umaskC0); // ① 还原进程 umask
}

// ───────── moc 生成面(出处:QMetaObject 元数据) ─────────
// metaObject 0x00902e80 → &PTR_staticMetaObject_011a0220
// qt_metacast 0x00902f48(strcmp "TransferTask" → QObject::qt_metacast)
// qt_metacall 0x00902f8a(93B):2 条记录转发到 0x00902eea 的 switch;
//   slot 0 → 0x00902e98(taskFinished),slot 1 → 0x00902ec0(taskProgress);
//   记录 10 → 反查信号号;超出则返回 (index - 2)。
