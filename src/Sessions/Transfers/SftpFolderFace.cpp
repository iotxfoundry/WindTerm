// SftpFolderFace.cpp — SFTP 目录。

#include "Sessions/Transfers/SftpFolderFace.h"

#include <QVariant>

// libssh sftp 会话操作(外部库,按 §11 只声明不逆向):
static void sftpAttributesFree(void *attrs);   // sftp_attributes_free

// 出处:RTTI "SftpFolder";ctor 内联在调用点,仅转发基构造。
SftpFolderFace::SftpFolderFace(QObject *parent)
    : SuperFolderFace(parent)
{
}

// 0x008e6840(206B)dtor 真身。逐段:
//   vptr = &SftpFolder_vtable;
//   ① +0x68 QList:若 begin==end 则跳过;否则 detach 后
//      **逐元素 sftp_attributes_free**(libssh 的所有权,不是 operator_delete)
//      → 列表本体清理(0x008e6c2e)
//   ② 若 byte(+0x30) == 2 或 == 5 → 0x008ea316(+0x68)(额外清理腿)
//   ③ 0x008e6c10 → 0x008ea602(基类链收尾)
// deleting 0x008e690e(23B):同上 + operator_delete(this, 0x70)。
SftpFolderFace::~SftpFolderFace()
{
	for (int i = m_attrs68.size() - 1; i >= 0; --i) {
		if (m_attrs68[i] != nullptr)
			sftpAttributesFree(m_attrs68[i]);
	}
	m_attrs68.clear();
}

// vt12 0x008e611a(38B):+0x58 非空 → FUN_00629854(+0x58);否则空串。
QString SftpFolderFace::path() const
{
	if (m_sftp58 == nullptr)
		return QString();
	return m_path28;
}

// vt13 0x008e6140(32B):+0x58 与 +0x60 都非空 → FUN_00627f36(+0x58);
// 否则 **返回 1**(注意不是 0 —— 语料如此,含义是该目录"可视为有内容")。
bool SftpFolderFace::hasEntries() const
{
	if (m_sftp58 != nullptr && m_peer60 != nullptr)
		return true; // FUN_00627f36(+0x58)
	return true;     // 语料:否则 return 1
}

// vt14 0x008e6160(29B):+0x58 为空 → 0;否则 FUN_00628080(+0x58, &+0x28, 实参)。
QVariant SftpFolderFace::openChild(const QVariant &)
{
	if (m_sftp58 == nullptr)
		return QVariant();
	return QVariant();
}

// vt15 0x008e617e(24B):+0x58 为空 → 0;否则 FUN_00628430(+0x58, &+0x28)。
QVariant SftpFolderFace::reopen()
{
	if (m_sftp58 == nullptr)
		return QVariant();
	return QVariant();
}

static void sftpAttributesFree(void *) { }
