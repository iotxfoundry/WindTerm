// FileReaderFace.cpp — 文件加载线程。

#include "Editor/Config/FileReaderFace.h"

FileReaderFace::FileReaderFace(QObject *parent)
    : QThread(parent)
{
}

// 0x00647c66(123B)dtor 真身 —— **先停线程再拆字段**:
//   vptr = &FileReader_vtable;
//   若 isRunning() → requestInterruption() + wait(INT64_MAX)
//   +0x20 QString 引用计数递减,归零即释放 d
//   QThread::~QThread
// deleting 0x00647ce2(23B):同上 + operator_delete(this, 0x30)。
// 注:与 FileWatcher 的 dtor 同一套纪律(先 wait 再释放),这条不是巧合 ——
//   线程持有字段期间释放会踩到 run()。
FileReaderFace::~FileReaderFace()
{
	if (isRunning()) {
		requestInterruption();
		wait();
	}
}

// ───────── moc 生成面(出处:QMetaObject 元数据) ─────────
// metaObject 0x009030b0 → &PTR_staticMetaObject_011a06a0
// qt_metacast 0x009034b4(strcmp "FileReader" → QThread::qt_metacast)
// qt_metacall 0x009034f6(93B):8 条记录转发到 0x009032ee 的 switch
//   (0..7 逐条 emit,记录 10 反查发射器,超出则 index - 8)。
