#pragma once

#include <QList>
#include <QObject>
#include <QString>

#include <sys/types.h>

// TransferTaskFace — 单个传输任务(元信息 + 两个套接字 + 进度信号)。
//
// 出处:RTTI "TransferTask";QMetaObject 0x011a0220
// (rev=8,class="TransferTask",methods=2,**signals=2**,props=0,superdata=0);
// sizeof = **0x168**(deleting 0x0063c806 的 operator_delete(_,0x168));
// 析构 0x0063c630(470B);两列表清理腿 0x006424de(49B);
// 信号桥 0x00902eea(94B);metacast 0x00902f48 / metacall 0x00902f8a(93B)。
//
// 两条信号(串表实读):
//   #0 taskFinished(...)  发射器 0x00902e98
//   #1 taskProgress(...)  发射器 0x00902ec0
//
// 字段(析构实读):
//   +0x20 QList<?>      整体换回 shared_null 后释放
//   +0x28 <?>           走 0x006424a0
//   +0x30/+0x38/+0x40 QString
//   +0x48 QSharedDataPointer
//   +0xa8/+0xb0 QString
//   +0xc0 mode_t         **进程 umask 快照** —— 析构时 umask(+0xc0) 还原
//   +0xc4 u8             标志位:bit3 → +0x150 套接字,bit4 → +0x158 套接字
//   +0xf0/+0xf8 QList<?>(清理腿 0x006424de)
//   +0x130 原子引用计数件
//   +0x150/+0x158 两个套接字(走 vtable+0x20 释放)
class TransferTaskFace : public QObject {
	Q_OBJECT

public:
	explicit TransferTaskFace(QObject *parent = nullptr);
	~TransferTaskFace() override; // 0x0063c630

signals:
	void taskFinished();  // #0
	void taskProgress();  // #1

private:
	QList<void *> m_list20;                 // +0x20
	void *m_f28 = nullptr;                  // +0x28
	QString m_f30;                          // +0x30
	QString m_f38;                          // +0x38
	QString m_f40;                          // +0x40
	void *m_shared48 = nullptr;             // +0x48
	QString m_fa8;                          // +0xa8
	QString m_fb0;                          // +0xb0
	mode_t m_umaskC0 = 0;                   // +0xc0
	quint8 m_flagsC4 = 0;                   // +0xc4
	QList<void *> m_listF0;                 // +0xf0
	QList<void *> m_listF8;                 // +0xf8
	void *m_ref130 = nullptr;               // +0x130
	void *m_sock150 = nullptr;              // +0x150
	void *m_sock158 = nullptr;              // +0x158
};
