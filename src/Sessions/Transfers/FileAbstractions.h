#pragma once

#include <QByteArray>
#include <QObject>
#include <QString>

// FileAbstractions.h — 文件与传输的四个抽象/薄派生件。
//
// 出处(entry 地址逐一列):
//   SuperFile     metacast 0x0091e992(66B)/ 桩 0x0091e9d4(5B) —— 无 dtor entry
//   SftpFile      dtor 0x008e59f2(47B)/ deleting 0x008e5a22(23B,_,**0x70**)
//                 vt12 0x008e5af8(18B)/ vt13 0x00641eee(3B,return 0)
//                 vt14 0x008e5b18(22B)/ vt15 0x008e5b2e(20B)
//   SuperTransfer metacast 0x0091e8c8(66B)/ 桩 0x0091e90a(5B)
//   LocalTransfer QMetaObject 0x011ac500(superdata = SuperTransfer)
//                 dtor 0x008e3934(32B)/ deleting 0x008e3954(23B,_,**0x88**)
//
// **SuperFile / SuperTransfer 在本构建里只有 metacast 与桩,没有 dtor entry**
// ⇒ 二者是纯抽象基座(与 SuperFolder 同性质),零字段、不自己释放任何东西。
//
// SftpFile 的四条虚面全是 libssh 的 SFTP 句柄转发:
//   vt12 → 返回自身(拷贝语义占位)
//   vt13 → **return 0**(纯空实现,3 字节)
//   vt14 → sftp_async_read_begin(+0x60, 实参)     ← 异步读
//   vt15 → sftp_async_write_begin(+0x60)          ← 异步写
//   ⇒ +0x60 是 libssh 的 sftp_file 句柄。**异步**读写在 SFTP 上是很自然的
//     设计,但 WindTerm 把它做成了虚面,说明传输层可切换同步/异步实现。

class SuperFileFace : public QObject {
	Q_OBJECT
public:
	explicit SuperFileFace(QObject *parent = nullptr);
	~SuperFileFace() override;
};

class SftpFileFace : public SuperFileFace {
	Q_OBJECT
public:
	explicit SftpFileFace(QObject *parent = nullptr);
	~SftpFileFace() override; // 0x008e59f2

	// 四条虚面
	QString name() const;                       // vt12 0x008e5af8
	bool isOpen() const;                        // vt13 0x00641eee(恒 0)
	long beginRead(const QByteArray &buf);      // vt14 0x008e5b18
	long beginWrite(const QByteArray &buf);     // vt15 0x008e5b2e

private:
	void *m_sftpFile60 = nullptr; // +0x60(libssh sftp_file)
};

class SuperTransferFace : public QObject {
	Q_OBJECT
public:
	explicit SuperTransferFace(QObject *parent = nullptr);
	~SuperTransferFace() override;
};

class LocalTransferFace : public SuperTransferFace {
	Q_OBJECT
public:
	explicit LocalTransferFace(QObject *parent = nullptr);
	~LocalTransferFace() override; // 0x008e3934

	void *createTransfer(); // vt12 0x008e396c(63B)
};
