#pragma once

#include <QList>
#include <QObject>
#include <QString>

// SessionConnectorFace — 会话连接器(QObject 派生,零元接口)。
//
// 出处:RTTI "SessionConnector";QMetaObject 0x011a7220
// (**methods=0 / signals=0 / props=0 / superdata=0**);
// sizeof = **0x60**(deleting 0x007be08e 的 operator_delete(_,0x60));
// dtor 0x007be004(138B)/deleting 0x007be08e(23B);
// 列表清空腿 0x007bdf66(158B);metacast 0x0090ed38 / metacall 0x0090ed7a(5B)。
//
// 字段(dtor 实读,释放顺序从低到高再回低):
//   +0x10 子对象(0x007c06f0)
//   +0x18 引用计数件(归零 operator_delete)
//   +0x30 QString
//   +0x48 QList<?>(0x007c0710 清空)
//   +0x58 子对象(0x007c0730)
//
// ⚠ 注意 dtor 里 **+0x58 与 +0x48 先释放、+0x10 最后释放** ——
//   不是单调从高到低。这类"两段式"顺序(先外层后内层)很常见,
//   按偏移排序去写就会错。
class SessionConnectorFace : public QObject {
	Q_OBJECT

public:
	explicit SessionConnectorFace(QObject *parent = nullptr);
	~SessionConnectorFace() override; // 0x007be004

private:
	char m_f10[0x08] = {};      // +0x10 子对象
	void *m_ref18 = nullptr;    // +0x18 引用计件
	QString m_f30;              // +0x30
	QList<void *> m_list48;     // +0x48
	char m_f58[0x08] = {};      // +0x58 子对象
};
