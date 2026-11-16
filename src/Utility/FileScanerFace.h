#pragma once

#include <QString>
#include <QThread>

// FileScanerFace — 目录/文件扫描线程(QThread 派生,**零字段**)。
//
// 出处:RTTI "FileScaner";QMetaObject 0x011aa3a0
// (rev=8,class="FileScaner",methods=2,**signals=2**,props=0,superdata=0);
// **sizeof = 0x30 且 dtor 只有 QThread::~QThread**(19B)⇒ 零自有字段;
// deleting 0x0091a002(37B,operator_delete(_,0x30));
// 信号桥 0x00919ede(108B);扫描主体 vt12 0x00885330(**2631B**,cited);
// metacast 0x00919f4a / metacall 0x00919f8c(97B)。
//
// 两条信号(串表实读,名字很有意思):
//   #0 `replaceAllInView(...)`    —— 在全视图中替换
//   #1 `takeViewSnapshot(...)`    —— 取视图快照
// ⇒ 这个"扫描器"不是纯目录遍历,而是**批量查找替换的驱动线程**:
//   扫文件 → 命中的在视图里替换 → 需要时拍快照。两条信号就是它的两个外部动作。
//
// ⚠ 与 DirScaner(已落)别混:DirScaner 用三组 QRegExp 过滤 + 999 上限;
//   本类零字段、信号是"替换/快照",是替换流程而不是过滤流程。
class FileScanerFace : public QThread {
	Q_OBJECT

public:
	explicit FileScanerFace(QObject *parent = nullptr);
	~FileScanerFace() override; // 0x00919fee

signals:
	void replaceAllInView(const QString &path); // #0
	void takeViewSnapshot(const QString &path); // #1
};
