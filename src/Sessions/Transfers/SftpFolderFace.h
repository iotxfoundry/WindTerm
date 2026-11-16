#pragma once

#include <QList>
#include <QString>

#include "Sessions/Transfers/SuperFolderFace.h"

// SftpFolderFace — SFTP 目录(SuperFolder 派生,4 条虚面全是目录操作)。
//
// 出处:RTTI "SftpFolder";sizeof = **0x70**
// (deleting 0x008e690e 的 operator_delete(_,0x70));
// dtor 0x008e6840(206B);
//   vt12 0x008e611a(38B) / vt13 0x008e6140(32B) /
//   vt14 0x008e6160(29B) / vt15 0x008e617e(24B)
// 列表清理腿 0x008e6c2e(49B) / 元素释放 0x008e6db0(119B) / 0x008ea316(60B)。
//
// **四条虚面共用同一个门 `+0x58 != 0`(= libssh 的 sftp 会话仍有效)**:
//   vt12 → FUN_00629854(+0x58)                 取路径串,无效则返回空串
//   vt13 → +0x60 也非空才算,返回 FUN_00627f36(+0x58),否则 **1**
//   vt14 → FUN_00628080(+0x58, &+0x28, 实参)    带子路径
//   vt15 → FUN_00628430(+0x58, &+0x28)          不带实参
//
// 字段(dtor 实读):
//   +0x28 路径串(传给 vt14/vt15 的第二个实参,即 QString 的地址)
//   +0x30 u8 状态:**2 或 5 时**才走 0x008ea316 的额外清理
//   +0x58 void* sftp 会话(libssh)
//   +0x60 void* 伴生指针(vt13 要求它非空)
//   +0x68 QList<sftp_attributes*>(dtor 里逐元素 **sftp_attributes_free**)
//
// ⚠ +0x68 的元素是 **libssh 的 `sftp_attributes`**,释放用 libssh 自己的
//   `sftp_attributes_free`,不是 operator_delete —— 这是外部库所有权边界,
//   不能改写成 delete。
class SftpFolderFace : public SuperFolderFace {
	Q_OBJECT

public:
	explicit SftpFolderFace(QObject *parent = nullptr);
	~SftpFolderFace() override; // 0x008e6840

	QString path() const;              // vt12 0x008e611a
	bool hasEntries() const;           // vt13 0x008e6140
	QVariant openChild(const QVariant &arg); // vt14 0x008e6160
	QVariant reopen();                 // vt15 0x008e617e

private:
	QString m_path28;      // +0x28
	quint8 m_state30 = 0;  // +0x30(2 / 5 触发额外清理)
	void *m_sftp58 = nullptr;    // +0x58
	void *m_peer60 = nullptr;    // +0x60
	QList<void *> m_attrs68;     // +0x68(sftp_attributes*)
};
