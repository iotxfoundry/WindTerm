#pragma once

#include <QString>
#include <QWidget>

// MuxWindowFace — 分屏窗口(QWidget 派生,1 信号 / 0 槽)。
//
// 出处:RTTI "MuxWindow";QMetaObject 0x011ac2a0
// (rev=8,class="MuxWindow",methods=1,**signals=1**,props=0,superdata=0);
// sizeof = **0x88**(deleting 0x0091e740 的 operator_delete(_,0x88));
// dtor 0x0091e4ca(196B)/deleting 0x0091e740(209B);
// metacast 0x0091e42c / metacall 0x0091e46e(91B)。
//
// 唯一条信号(串表实读):`nameChanged(?)` 1 参 → 发射器 0x0091e3c8。
//
// 字段(dtor 实读):
//   +0x30 QString
//   +0x58 QString
//   +0x60 QString
//   +0x78 引用计数件(减一归零 operator_delete)
class MuxWindowFace : public QWidget {
	Q_OBJECT

public:
	explicit MuxWindowFace(QWidget *parent = nullptr);
	~MuxWindowFace() override; // 0x0091e4ca

signals:
	void nameChanged(const QString &name); // #0

private:
	QString m_f30;      // +0x30
	QString m_f58;      // +0x58
	QString m_f60;      // +0x60
	void *m_ref78 = nullptr; // +0x78
};
