#pragma once

#include <QList>
#include <QObject>
#include <QString>

// TunnelCenterFace — 隧道(端口转发)会话中心。
//
// 出处:RTTI "TunnelCenter";QMetaObject 0x011a0a60
// (rev=8,class="TunnelCenter",methods=6,**signals=6**,props=0,superdata=0);
// sizeof = **0x70**(deleting 0x006a51da 的 operator_delete(_,0x70));
// dtor 0x006a4f28(689B);eventFilter = vt6 0x006a5434(236B);
// 槽分发 0x00903d9c(301B);metacast 0x00903eca / metacall 0x00903f0c(97B);
// 列表清理腿 0x006a92b7(222B)。
//
// 六条信号(串表实读;emit 包装按 dispatch 的实参个数逐个对上):
//   #0 errorOccurred(...)         3 参 → 0x00903ce6
//   #1 sessionDisconnected()      0 参 → 0x00903c78
//   #2 sessionError(...)          2 参 → 0x00903c8c
//   #3 sessionReady(...)          2 参 → 0x00903d24
//   #4 toggled(bool)              2 参(末参为字节) → 0x00903d60
//   #5 tunnelChanged(...)         1 参 → 0x00903cbc
//
// 字段(dtor 实读):
//   +0x50 QString
//   +0x60 void*     一个可被 FUN_006a285c 整体释放的件
//   +0x68 QList<TunnelSession*>  (元素就是 TunnelSession 对象本体)
class TunnelCenterFace : public QObject {
	Q_OBJECT

public:
	explicit TunnelCenterFace(QObject *parent = nullptr);
	~TunnelCenterFace() override; // 0x006a4f28

signals:
	void errorOccurred();        // #0
	void sessionDisconnected();  // #1
	void sessionError();         // #2
	void sessionReady();         // #3
	void toggled(bool on);       // #4
	void tunnelChanged();        // #5

protected:
	bool eventFilter(QObject *watched, QEvent *event) override; // vt6 0x006a5434

private:
	QString m_f50;      // +0x50
	void *m_f60 = nullptr; // +0x60
	QList<void *> m_sessions68; // +0x68(元素类型 TunnelSession*,未建模时用 void*)
};
