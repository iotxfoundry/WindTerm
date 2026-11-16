#pragma once

#include <QBrush>
#include <QFrame>
#include <QString>

// TransferLabelFace — 传输条上的进度标签(QFrame 派生)。
//
// 出处:RTTI "TransferLabel";QMetaObject 0x01196540
// (rev=8,class="TransferLabel",**methods=0 signals=0 props=1**,superdata=0);
// sizeof = **0x88**(deleting 0x008f1a88 的 operator_delete(_,0x88));
// dtor 0x008f193a(104B)/deleting 0x008f1a88(110B);
// 属性桥 0x008f17d8(167B);metacast 0x008f1880 / metacall 0x008f18c2(120B)。
//
// **唯一属性**:`progressColor` : QBrush → 字段 +0x38
//   读:把 +0x38 的 14 字节整体拷出(源 = 指针 +8 起,私有区);
//   写:QBrush clone 后 copy-and-swap。
//
// 字段(dtor 实读):
//   +0x30 QString
//   +0x38 QBrush  progressColor(**唯一暴露给元调用的**)
//   +0x40 QBrush  第二个画刷(dtor 里同样析构,**未暴露** —— 不是漏,
//                 元对象只有 1 个属性)
class TransferLabelFace : public QFrame {
	Q_OBJECT

	Q_PROPERTY(QBrush progressColor MEMBER m_progress38)

public:
	explicit TransferLabelFace(QWidget *parent = nullptr);
	~TransferLabelFace() override; // 0x008f193a

private:
	QString m_f30;        // +0x30
	QBrush m_progress38;  // +0x38
	QBrush m_f40;         // +0x40
};
