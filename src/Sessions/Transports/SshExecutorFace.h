#pragma once

#include <QList>
#include <QObject>
#include <QString>

// SshExecutorFace — SSH 命令执行器(输出回流 + 计时器重启)。
//
// 出处:RTTI "SshExecutor";QMetaObject 0x011a9220
// (rev=8,class="SshExecutor",methods=2,**signals=2**,props=0,superdata=0);
// sizeof = **0x40**(deleting 0x00869f68 的 operator_delete(_,0x40));
// dtor 0x00869e26(322B);信号桥 0x0091827a(102B);
// 计时器腿 0x0086a570(29B);metacast 0x009182e0 / metacall 0x00918322(93B)。
//
// 两条信号(串表实读;形参个数按桥逐个实读):
//   #0 commandOutput(?, ?, ?)   3 参 → 发射器 0x0091823c
//   #1 restartElapsedTimer()    0 参 → 发射器 0x00918228
//
// 字段(dtor 实读):
//   +0x10 void*   上下文(交给 FUN_0086247e 与 +0x18 一起处理)
//   +0x18 <struct> 内联结构(与 +0x10 成对;类型未复原)
//   +0x28 QList<?> 元素各带两个引用计数件(+0x8 / +0x10),
//                 dtor 里从尾向头逐个减引用
//   +0x38 void*    0x10 字节独立块(operator_delete(_, 0x10))
class SshExecutorFace : public QObject {
	Q_OBJECT

public:
	explicit SshExecutorFace(QObject *parent = nullptr);
	~SshExecutorFace() override; // 0x00869e26

signals:
	void commandOutput(const QString &a, const QString &b, const QString &c); // #0
	void restartElapsedTimer();                                                // #1

private:
	void *m_ctx10 = nullptr;   // +0x10
	char m_f18[0x10] = {};     // +0x18 内联结构(类型未复原)
	QList<void *> m_items28;   // +0x28
	void *m_f38 = nullptr;     // +0x38(0x10 字节块)
};
