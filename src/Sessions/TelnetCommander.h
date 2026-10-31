#ifndef TELNETCOMMANDER_H
#define TELNETCOMMANDER_H

#pragma once

#include "SuperCommander.h"

#include <QVector>

class SuperSession;

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// No new meta methods beyond SuperCommander.
//
// ctor 装配(FUN_0085f520,172B;new 0x140;工厂 007d9776,参数 =
// (this, session, *(session+0x10)=bridge, 0)):
//   SuperCommander 基(007cf02c)→ +0x10 = PTR_FUN_011a8de8
//   (Telnet 专属指令表指针,树面 SuperCommander 不建模 +0x10,存注)
//   → +0x88 = *(DAT_011c2200+0xb0)(FUN_007cc8a2;批 41 勘正:协商
//   表实为静态单例 00860a50,此槽为 Ghidra 调用描述符混淆)→
//   FUN_0085f446:+0x128 向量 resize 11 + 表 flag 列装载 →
//   QTimer::singleShotImpl(0,0,this,{008608e0,0085fbd6})初始 burst。
// 协商槽体(批 41 语料转写):metacall 00917e20(93B)→ 槽 0 =
// FUN_008606fe(460B)/ 槽 1 = FUN_00860642(188B),均收
// (command,option)双字节;策略 = CTerminalConfig 单例 +0xb0 表
// (FUN_00860a50 访问器;12 字节条目)查表分发 —— 捕获表(批 33)
// 由该配置面驱动,非硬编码。
// 勘正(批 70,ts 笔记 §4):negotiationReply 语料无同名/同位信号
// —— 协商写出 = 直调非信号(Commander 经 term_processCR;会话侧
// vt15 直调桥写)。本信号保留为架构化替代,待 Commander→socket
// 落地(未解清单 #2)收口后裁撤。
class TelnetCommander : public SuperCommander
{
	Q_OBJECT

public:
	// FUN_0085f520 语料形态:(session, bridge, parent=0)
	TelnetCommander(SuperSession *session, QObject *bridge,
	                QObject *parent = nullptr);
	virtual ~TelnetCommander(void) = default;
public slots:
	// 槽 0 = FUN_008606fe(460B):表查 option 匹配 → 响应链
	//   FUN_0085e2de/0085e308/0085fa60(+0x128 向量门)
	void negotiateOption(unsigned char command, unsigned char option);
	// 槽 1 = FUN_00860642(188B):表 flag==1 条目 → FUN_0085e326
	//   匹配 → s_session_term_72014e
	void negotiateSubOption(unsigned char command, unsigned char option);

private slots:
	// FUN_0085fbd6(155B)初始 burst:singleShot(0) 仿函数真身
	void initialBurst();

signals:
	// 勘正见类注:语料为直调写出,此信号 = 架构化替代(消费者 =
	// 会话传输层,随 TelnetSession 批接线)
	void negotiationReply(const QByteArray &data);

private:
	QVector<int> m_optionStates;   // +0x128 选项状态向量(语料成员)
	QObject *m_bridge = nullptr;   // +0x40 = param_3(FUN_007cf02c 存槽;
	                               // Commander→socket 落地未解 #2,仅存)
private:
	Q_DISABLE_COPY(TelnetCommander)
};

#endif // TELNETCOMMANDER_H
