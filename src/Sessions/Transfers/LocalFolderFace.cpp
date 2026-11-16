// LocalFolderFace.cpp — 本地目录。

#include "Sessions/Transfers/LocalFolderFace.h"

#include <QVariant>

// 出处:RTTI "LocalFolder";ctor 内联在调用点,仅转发基构造。
LocalFolderFace::LocalFolderFace(QObject *parent)
    : SuperFolderFace(parent)
{
}

// dtor 0x008e2c9c(58B)真身:唯一字段 +0x58 QDir* 释放(0x008e2c60,59B:
//   QDir::~QDir → operator_delete(_, 8) → 置 0)
// deleting 0x008e2cd6(23B)真身:+ operator_delete(this, 0x60)。
LocalFolderFace::~LocalFolderFace() = default;

// vt12 0x00642020(33B)真身:返回自身(占位语义)。
QString LocalFolderFace::name() const { return QString(); }

// vt13 0x00641efe(**6B**)真身:`return 1` —— 本地目录恒"存在"。
// 注意与 SftpFolder 的 vt13 不同:那是"会话不在时才 1",这是无条件 1。
bool LocalFolderFace::exists() const { return true; }

// vt14 0x008e3078(952B)/ vt15 0x008e2e06(593B):两个目录操作实体,
// 本批只锚入口(cited),留文件系统开批。
QVariant LocalFolderFace::list() { return QVariant(); }
QVariant LocalFolderFace::reopen() { return QVariant(); }
