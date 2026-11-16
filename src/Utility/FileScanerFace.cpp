// FileScanerFace.cpp — 批量查找替换的扫描线程。

#include "Utility/FileScanerFace.h"

// 出处:QMetaObject 0x011aa3a0(methods=2 signals=2);
// ctor 内联在调用点,仅转发 QThread 基构造。
FileScanerFace::FileScanerFace(QObject *parent)
    : QThread(parent)
{
}

// dtor 0x00919fee(19B)真身:只有 QThread::~QThread —— 零字段。
// deleting 0x0091a002(37B)真身:+ operator_delete(_, 0x30)。
FileScanerFace::~FileScanerFace() = default;

// metasurface:metaObject 0x00919e50 → &PTR_staticMetaObject_011aa3a0;
// qt_metacast 0x00919f4a;qt_metacall 0x00919f8c(97B):2 条记录 → 0x00919ede;
// 扫描主体 vt12 0x00885330(2631B)本批 cited —— 锚入口,留替换流程开批。
