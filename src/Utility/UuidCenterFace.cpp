// UuidCenterFace.cpp — UUID 注册表。

#include "Utility/UuidCenterFace.h"

// 出处:QMetaObject 0x011a0b20(methods=0 signals=0);
// ctor 内联在调用点,仅转发 QObject 基构造。
UuidCenterFace::UuidCenterFace(QObject *parent)
    : QObject(parent)
{
}

// dtor 0x00904046(115B)真身:+0x18 QMap 引用计数归零 →
// QMapDataBase::freeTree(根)+ freeData → QObject 析构。
// deleting 0x00903fd0(118B)真身:+ operator_delete(_, 0x20)。
UuidCenterFace::~UuidCenterFace() = default;
