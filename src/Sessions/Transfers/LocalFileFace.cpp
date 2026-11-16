// LocalFileFace.cpp — 本地文件句柄(同步 / AIO 双模)。

#include "Sessions/Transfers/LocalFileFace.h"

#include <QFileDevice>

#include <aio.h>
#include <cerrno>
#include <cstdlib>
#include <cstring>

static void *aioAcquireSlot(LocalFileFace *self, qint64 len); // 0x008e24d0
static void aioReleaseSlot(LocalFileFace *self, void *slot);    // 0x008e25bc
static bool specialQuery(LocalFileFace *self);                  // 0x008ea054

LocalFileFace::LocalFileFace(QObject *parent)
    : QObject(parent)
{
}

// 0x008e22a0(49B)dtor 真身:
//   vptr = &LocalFile_vtable;
//   若 byte(+0x40) == 6 → 调状态清理(0x008ea054 同族)
//   然后落基类析构。
// deleting 0x008e22d2(23B):同上 + operator_delete(this, 0x90)。
LocalFileFace::~LocalFileFace() = default;

// vt12 0x008e20e6(219B)errorString 真身:
//   +0x68 非空 → 取 QIODevice::errorString();
//   结果为空 → **回落到 strerror(errno)**(QString::fromUtf8_helper)
// 返回 QString(引用计数语义按语料:换出旧值再析构旧的)。
QString LocalFileFace::errorString() const
{
	QString msg;
	if (m_dev68 != nullptr)
		msg = m_dev68->errorString();
	if (msg.isEmpty()) {
		char *const s = std::strerror(errno);
		if (s != nullptr)
			msg = QString::fromUtf8(s);
	}
	return msg;
}

// vt13 0x008e1da6(87B)map 真身。逐句:
//   flag & 0x04 → 直接 malloc(size) 返回
//   +0x68 为空 → 返回 0
//   offset == 0 且 +0x80 有缓存:
//       len = min(+0x38, +0x78);清 +0x80;若 size 恰好等于该 len 则**复用缓存**
//   否则 QFileDevice::map(+0x68, offset, size, 0)
void *LocalFileFace::map(qint64 offset, qint64 size)
{
	if (m_flags8c & 0x04)
		return std::malloc(size_t(size));
	if (m_dev68 == nullptr)
		return nullptr;

	if (offset == 0 && m_mapCache80 != nullptr) {
		size_t reuse = m_mapLen38;
		if (qint64(m_mapLen38) > m_mapMax78)
			reuse = size_t(m_mapMax78);
		m_mapCache80 = nullptr;
		if (qint64(size) == qint64(reuse))
			return m_mapCache80; // 语料:尺寸相符即复用(此时已置空,语义待核)
	}
	return m_dev68->map(offset, size);
}

// vt14 0x008e2736(201B)readAsync 真身。逐句:
//   flag & 0x04 → 直接返回 len(视为"已读满")
//   +0x54 != -1(AIO 已启用):
//       slot = aioAcquireSlot(this, len);slot 为空 → 返回 slot
//       slot->buf = buf;若 flag & 0x20 → len 按 +0x88 向上取整
//       slot->len = len;aio_read(slot);失败 → aioReleaseSlot + 返回 -1
//       成功返回 slot
//   否则 +0x68 非空 且 +0x10 == 1 → QIODevice::read(buf, len)
//   否则返回 len
qint64 LocalFileFace::readAsync(void *buf, qint64 len)
{
	if (m_flags8c & 0x04)
		return len;
	if (m_aioSlot54 != -1) {
		void *const slot = aioAcquireSlot(this, len);
		if (slot == nullptr)
			return 0;
		auto *cb = reinterpret_cast<aiocb *>(slot);
		cb->aio_buf = buf;
		qint64 n = len;
		if (m_flags8c & 0x20)
			n = ((m_blockSize88 - 1 + len) / m_blockSize88) * m_blockSize88;
		cb->aio_nbytes = size_t(n);
		if (aio_read(cb) < 0) {
			aioReleaseSlot(this, slot);
			return -1;
		}
		return qint64(reinterpret_cast<qintptr>(slot));
	}
	if (m_dev68 != nullptr && m_syncReady10 == 1)
		return m_dev68->read(static_cast<char *>(buf), len);
	return len;
}

// vt15 0x008e2800(201B)writeAsync 真身 —— 与 readAsync **逐句同构**,
//   唯一差异是 aio_read → aio_write、QIODevice::read → write。
qint64 LocalFileFace::writeAsync(const void *buf, qint64 len)
{
	if (m_flags8c & 0x04)
		return len;
	if (m_aioSlot54 != -1) {
		void *const slot = aioAcquireSlot(this, len);
		if (slot == nullptr)
			return 0;
		auto *cb = reinterpret_cast<aiocb *>(slot);
		cb->aio_buf = const_cast<void *>(buf);
		qint64 n = len;
		if (m_flags8c & 0x20)
			n = ((m_blockSize88 - 1 + len) / m_blockSize88) * m_blockSize88;
		cb->aio_nbytes = size_t(n);
		if (aio_write(cb) < 0) {
			aioReleaseSlot(this, slot);
			return -1;
		}
		return qint64(reinterpret_cast<qintptr>(slot));
	}
	if (m_dev68 != nullptr && m_syncReady10 == 1)
		return m_dev68->write(static_cast<const char *>(buf), len);
	return len;
}

// 0x008ea054(37B)真身:状态查询 ——
//   byte(+0x40) != 6 → 返回 (byte(+0x40) == 4);
//   == 6 → 转调虚面 vtable+0xb0(未复原的判定)。
bool LocalFileFace::isSpecialState() const
{
	if (m_state40 != 6)
		return m_state40 == 4;
	return specialQuery(const_cast<LocalFileFace *>(this));
}

static void *aioAcquireSlot(LocalFileFace *, qint64) { return nullptr; }
static void aioReleaseSlot(LocalFileFace *, void *) { }
static bool specialQuery(LocalFileFace *) { return false; }
