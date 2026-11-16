#pragma once

#include <QProcess>

// ProcessFace — 子进程封装(QProcess 派生,**零字段**)。
//
// 出处:RTTI "Process";dtor 0x0065ccfe(19B)/deleting 0x0065cd12(37B)
//   —— dtor 只有 QProcess::~QProcess ⇒ 零字段;
// 元接口:语料无 metaObject / metacast entry,且 RTTI 有 "Process" ⇒
//   **有 Q_OBJECT 但没有新增信号槽**(否则会有 metacast entry)。
class ProcessFace : public QProcess {
	Q_OBJECT

public:
	explicit ProcessFace(QObject *parent = nullptr);
	~ProcessFace() override; // 0x0065ccfe
};
