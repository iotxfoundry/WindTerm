#pragma once

#include <QList>
#include <QRegExp>
#include <QString>
#include <QThread>

// DirScanerFace — 目录扫描线程(按正则过滤文件/目录)。
//
// 出处:RTTI "DirScaner";QMetaObject 0x011aa2e0
// (**rev=8,methods=0,props=0,superdata=0** ⇒ 无信号无槽,直接派生 QThread);
// run() = vt12 0x00898396(804B);dtor 0x00919c70(229B)/
// deleting 0x00919d60(238B);metacast 0x00919ba2(strcmp "DirScaner" → QThread);
// metacall 0x00919be4(5B,纯基类转发)。
//
// 字段(dtor/run 双向实读):
//   +0x10 u8        停止标志(run 每轮开头查)
//   +0x18 QList<Pat> 过滤规则组 1(dtor 走 DirScaner_h919bea)
//   +0x20 QList<Pat> 过滤规则组 2
//   +0x28 QList<Pat> 过滤规则组 3
//   +0x34 int       运行期累加计数(命中文件数 / 字节数,由 run 自增)
//   +0x38 QString   扫描根路径(由它构造 QFileInfo)
//
// Pat 结构(0x10 字节,release 时 QRegExp::~QRegExp + operator_delete(_,0x10)):
//   +0x00 QRegExp*  规则
//   +0x08 int       kind:0 = 目录规则,1 = 文件规则(run 里两路分支)
class DirScanerFace : public QThread {
	Q_OBJECT

public:
	struct Pattern {
		QRegExp *re = nullptr; // +0x00
		int kind = 0;          // +0x08(0 目录 / 1 文件)
	};

	explicit DirScanerFace(QObject *parent = nullptr);
	~DirScanerFace() override; // 00919c70

	void setRootPath(const QString &path); // +0x38
	void addPattern(const Pattern &p);     // 加入 +0x18 组

protected:
	void run() override; // vt12 0x00898396

private:
	static void freeList(QList<Pattern> &list); // 00919bea

	quint8 m_stop10 = 0;     // +0x10
	QList<Pattern> m_pats18; // +0x18
	QList<Pattern> m_pats20; // +0x20
	QList<Pattern> m_pats28; // +0x28
	int m_count34 = 0;       // +0x34
	QString m_root38;        // +0x38
};
