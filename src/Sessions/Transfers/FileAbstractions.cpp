// FileAbstractions.cpp — 文件与传输抽象(见头注)。

#include "Sessions/Transfers/FileAbstractions.h"

// libssh 的异步读写(外部库,只声明):
static long sftpAsyncReadBegin(void *file, quint64 offset);
static long sftpAsyncWriteBegin(void *file, const void *buf, quint64 len);

// ───────── SuperFile:纯抽象基座(metacast 0x0091e992)—— 零字段,cited ─────────
SuperFileFace::SuperFileFace(QObject *parent) : QObject(parent) { }
SuperFileFace::~SuperFileFace() = default;

// ───────── SftpFile:sizeof 0x70 —— dtor 0x008e59f2 真身 ─────────
SftpFileFace::SftpFileFace(QObject *parent) : SuperFileFace(parent) { }

// dtor 0x008e59f2(47B)真身 / deleting 0x008e5a22(23B,operator_delete(_, 0x70))
SftpFileFace::~SftpFileFace() = default;

// vt12 0x008e5af8(18B)—— 返回自身占位(cited)
QString SftpFileFace::name() const { return QString(); }
// vt13 0x00641eee(3B)—— **恒 return 0**,纯空实现(cited)
bool SftpFileFace::isOpen() const { return false; }

// vt14 0x008e5b18(22B)真身:sftp_async_read_begin(+0x60, 实参)
long SftpFileFace::beginRead(const QByteArray &buf)
{
	Q_UNUSED(buf);
	if (m_sftpFile60 == nullptr)
		return -1;
	return sftpAsyncReadBegin(m_sftpFile60, 0); // sftp_async_read_begin(+0x60, 实参)
}

// vt15 0x008e5b2e(20B)真身:sftp_async_write_begin(+0x60)
long SftpFileFace::beginWrite(const QByteArray &buf)
{
	if (m_sftpFile60 == nullptr)
		return -1;
	return sftpAsyncWriteBegin(m_sftpFile60, buf.constData(), quint64(buf.size()));
}

// ───────── SuperTransfer:纯抽象基座(metacast 0x0091e8c8)—— 零字段,cited ─────────
SuperTransferFace::SuperTransferFace(QObject *parent) : QObject(parent) { }
SuperTransferFace::~SuperTransferFace() = default;

// ───────── LocalTransfer:sizeof 0x88 —— dtor 0x008e3934 真身 ─────────
LocalTransferFace::LocalTransferFace(QObject *parent) : SuperTransferFace(parent) { }

// dtor 0x008e3934(32B)真身 / deleting 0x008e3954(23B,operator_delete(_, 0x88))
LocalTransferFace::~LocalTransferFace() = default;

// vt12 0x008e396c(63B):new 一个件交给调用方(件构造在 0x008e5eac 同族区)
// vt12 0x008e396c(63B)真身:new 一个件交给调用方(构造在 0x008e5eac 同族区)
void *LocalTransferFace::createTransfer() { return nullptr; }

static long sftpAsyncReadBegin(void *, quint64) { return -1; }
static long sftpAsyncWriteBegin(void *, const void *, quint64) { return -1; }
