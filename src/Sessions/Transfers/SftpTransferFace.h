#pragma once

#include <QVariant>

#include "Sessions/Transfers/FileAbstractions.h"

// SftpTransferFace — SFTP 传输(SuperTransfer 派生,4 条虚面)。
//
// 出处:RTTI "SftpTransfer";QMetaObject 0x011ac6a0
// (rev=8,class="SftpTransfer",**methods=0 / signals=0 / props=0**,
//  superdata=0x011acb00 = **SuperTransfer**);
// sizeof = **0x88**(deleting 0x008e7308 的 operator_delete(_,0x88));
// dtor 0x008e72e8(32B)/deleting 0x008e7308(23B);
// 前置清理腿 0x008e72d6(18B);
// 四条虚面:vt12 0x008e7320(63B)/ vt13 0x008e7368(45B)/
//           vt14 0x0057cc5e(3B)/ vt15 0x0057cc62(3B)
//
// **本批解掉一个此前的疑点**:语料里 `SftpTransfer_qt_metacall` 是
// **5 字节纯转发** ⇒ 本类 0 条自有信号槽;而同名 777B 的分发函数
// `SftpTransfer_h91ecb4` 因此**不属于本类**(它分 15 条记录,与
// methods=0 矛盾)。已按"5 字节 metacall 为准"处置,不再追那个 777B。
//
// 四条虚面(全部实读):
//   vt12 0x008e7320(63B):`new 0x70` 件 → FUN_008e5eac(件, 3 实参) → 返回件
//   vt13 0x008e7368(45B):`new 0x70` 件 → FUN_008e6524(件, 2 实参) → 返回件
//   vt14 0x0057cc5e(**3B**):`return 0`      ← 纯空实现
//   vt15 0x0057cc62(**3B**):`return 0`      ← 纯空实现
//   ⇒ 两个"造传输件"的工厂 + 两个恒 0 的空实现。
//
// dtor 0x008e72e8(32B)真身:
//   vptr = &SftpTransfer_vtable → 0x008e72d6(前置清理:FUN_008ecc38 +
//   FUN_008e72c2)→ FUN_008ec2d6(this)(基链收尾)。
//   **本类不自己释放字段**(字段全在 SuperTransfer 链上),0x88 全来自基类。
class SftpTransferFace : public SuperTransferFace {
	Q_OBJECT
public:
	explicit SftpTransferFace(QObject *parent = nullptr);
	~SftpTransferFace() override; // 0x008e72e8

	void *makeTransferA(const QVariant &a, const QVariant &b);        // vt12
	void *makeTransferB(const QVariant &a, int b);                    // vt13
	long noopA();   // vt14(恒 0)
	long noopB();   // vt15(恒 0)
};
