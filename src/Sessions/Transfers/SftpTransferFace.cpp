// SftpTransferFace.cpp — SFTP 传输。

#include "Sessions/Transfers/SftpTransferFace.h"

// 同族件构造(0x008exxxx 区,尚未开批):
static void *newTransfer5eac(void *self, void *a, void *b); // 0x008e5eac(0x70B 件)
static void *newTransfer6524(void *self, void *a);          // 0x008e6524(0x70B 件)

// 出处:QMetaObject 0x011ac6a0(methods=0,signals=0,superdata=SuperTransfer);
// ctor 内联在调用点。
SftpTransferFace::SftpTransferFace(QObject *parent)
    : SuperTransferFace(parent)
{
}

// dtor 0x008e72e8(32B)真身:vptr 复位 → 0x008e72d6(前置清理)→
// FUN_008ec2d6(this)(基链收尾);deleting 0x008e7308(23B):
// + operator_delete(this, **0x88**)。
SftpTransferFace::~SftpTransferFace() = default;

// vt12 0x008e7320(63B)真身:new 0x70 件 → FUN_008e5eac(件, 3 实参)。
void *SftpTransferFace::makeTransferA(const QVariant &, const QVariant &)
{
	return newTransfer5eac(this, nullptr, nullptr);
}

// vt13 0x008e7368(45B)真身:new 0x70 件 → FUN_008e6524(件, 2 实参)。
void *SftpTransferFace::makeTransferB(const QVariant &, int)
{
	return newTransfer6524(this, nullptr);
}

// vt14 0x0057cc5e(**3B**)/ vt15 0x0057cc62(**3B**)真身:均 `return 0`。
long SftpTransferFace::noopA() { return 0; }
long SftpTransferFace::noopB() { return 0; }

static void *newTransfer5eac(void *, void *, void *) { return nullptr; }
static void *newTransfer6524(void *, void *) { return nullptr; }
