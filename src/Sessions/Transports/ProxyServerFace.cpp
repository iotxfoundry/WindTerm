// ProxyServerFace.cpp — 代理监听器。

#include "Sessions/Transports/ProxyServerFace.h"

// 出处:QMetaObject 0x0119f340(class="ProxyServer",methods=2,signals=2);
// ctor 内联在调用点,仅转发 QTcpServer 基构造。
ProxyServerFace::ProxyServerFace(QObject *parent)
    : QTcpServer(parent)
{
}

// 0x008fcc98(160B)dtor 真身:
//   vptr = &ProxyServer_vtable;
//   +0x28 QMap 引用计数归零 → QMapDataBase::freeTree(根)+ freeData
//   +0x18 QString 引用计数递减
//   QTcpServer::~QTcpServer
// deleting 0x008fcd38(161B):同上 + operator_delete(this, 0x30)。
ProxyServerFace::~ProxyServerFace() = default;

// ───────── moc 生成面(出处:QMetaObject 元数据) ─────────
// metaObject 0x008fcaf0 → &PTR_staticMetaObject_0119f340
// qt_metacast 0x008fcbf8(strcmp "ProxyServer" → QTcpServer::qt_metacast)
// qt_metacall 0x008fcc3a(93B):2 条记录转发到 0x008fcb80;
//   槽 0 → 0x008fcb32(newTcpSocket,4 参);槽 1 → 0x008fcb08(proxyError,1 参);
//   记录 10 反查信号号;超出则 index - 2。
