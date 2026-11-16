#pragma once

#include <QVariant>

#include "Widgets/Panes/KitPaneFace.h"

// SenderPaneFace — 发送器面板(KitPane 直接派生,16 条槽 / 0 信号)。
//
// 出处:RTTI "SenderPane";QMetaObject 0x011a5c00
// (rev=8,class="SenderPane",methods=16,**signals=0**,props=0,
//  superdata=0x011ab900 = **KitPane**);
// dtor 0x0073591c(164B)/deleting 0x007359ca(23B);
// 槽分发 0x0090a378(953B);vt6 0x0073558e(226B);
// metacast 0x0090a76a / metacall 0x0090a7ac(97B)。
//
// 十六条槽(串表真名;同名多条 = 重载,索引序即契约):
//   #0 addSender(3 参)   #1 addSender(2 参)   #2 addSender(1 参)
//   #3 clearSender(...)  #4 clearSender()
//   #5 isSending(...)    #6 isSending()
//   #7 removeSender(...) #8 removeSender()
//   #9 sender(...)       #10 sender()
//   #11 senderCount()
//   #12 startSender(...) #13 startSender()
//   #14 stopSender(...)  #15 stopSender()
class SenderPaneFace : public KitPaneFace {
	Q_OBJECT

public:
	explicit SenderPaneFace(QWidget *parent = nullptr);
	~SenderPaneFace() override; // 0x0073591c

public slots:
	void addSender(const QVariant &a, const QVariant &b, const QVariant &c); // #0
	void addSender(const QVariant &a, const QVariant &b);                   // #1
	void addSender(const QVariant &a);                                      // #2
	void clearSender(const QVariant &a);                                    // #3
	void clearSender();                                                     // #4
	bool isSending(const QVariant &a);                                      // #5
	bool isSending();                                                       // #6
	void removeSender(const QVariant &a);                                   // #7
	void removeSender();                                                    // #8
	QVariant sender(const QVariant &a);                                     // #9
	QVariant sender();                                                      // #10
	int senderCount();                                                      // #11
	void startSender(const QVariant &a);                                    // #12
	void startSender();                                                     // #13
	void stopSender(const QVariant &a);                                     // #14
	void stopSender();                                                      // #15
};
