#pragma once

#include <QIODevice>
#include <QObject>
#include <QString>

// LocalFileFace — 本地文件传输用的文件句柄(同步 / POSIX AIO 双模)。
//
// 出处:RTTI "LocalFile";sizeof = **0x90**
// (deleting 0x008e22d2 的 operator_delete(_,0x90));
// 元对象 0x0091e97a(24B)→ &PTR_staticMetaObject_011ac800;
// 析构 0x008e22a0(49B);四条虚面:
//   vt12 0x008e20e6(219B) errorString()
//   vt13 0x008e1da6(87B)  map(offset, size)
//   vt14 0x008e2736(201B) readAsync(buf, len)
//   vt15 0x008e2800(201B) writeAsync(buf, len)
// 状态判定 0x008ea054(37B)。
//
// **两条腿的分叉判据(读三个 flag 位)**:
//   byte(+0x8c) & 0x04 → 走"无设备"分支(vt13 直接 malloc,vt14/vt15 直接返回 len)
//   byte(+0x8c) & 0x20 → 长度按 int(+0x88) 的块大小**向上取整**
//   int(+0x54) != -1    → 该字段是 AIO 回调队列下标,非 -1 表示启用 POSIX AIO
//                          (aio_read / aio_write,见 vt14/vt15)
//   否则走 QIODevice 同步路径(+0x68 为 QFileDevice)
//
// 字段(实读):
//   +0x10  char    同步路径就绪标志(== 1 才允许 QIODevice::read/write)
//   +0x38  size_t  map 缓存长度
//   +0x40  char    状态(6 = 特殊态,走 0x008ea054 的虚面 0xb0;4 = 另一态)
//   +0x54  int     AIO 队列下标(-1 = 未启用)
//   +0x68  QFileDevice*
//   +0x78  qint64  map 上限
//   +0x80  void*   map 结果缓存(尺寸匹配时复用)
//   +0x88  int     块大小(flag&0x20 时用于向上取整)
//   +0x8c  byte    行为标志位
class LocalFileFace : public QObject {
	Q_OBJECT

public:
	explicit LocalFileFace(QObject *parent = nullptr);
	~LocalFileFace() override; // 0x008e22a0

	QString errorString() const;        // vt12 0x008e20e6
	void *map(qint64 offset, qint64 size); // vt13 0x008e1da6
	qint64 readAsync(void *buf, qint64 len);  // vt14 0x008e2736
	qint64 writeAsync(const void *buf, qint64 len); // vt15 0x008e2800

	bool isSpecialState() const; // 0x008ea054(37B)

private:
	char m_syncReady10 = 0;   // +0x10
	size_t m_mapLen38 = 0;    // +0x38
	char m_state40 = 0;       // +0x40
	int m_aioSlot54 = -1;     // +0x54
	QFileDevice *m_dev68 = nullptr; // +0x68
	qint64 m_mapMax78 = 0;    // +0x78
	void *m_mapCache80 = nullptr; // +0x80
	int m_blockSize88 = 0;    // +0x88
	quint8 m_flags8c = 0;     // +0x8c
};
