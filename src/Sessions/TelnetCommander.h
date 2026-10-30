#ifndef TELNETCOMMANDER_H
#define TELNETCOMMANDER_H

#pragma once

#include "SuperCommander.h"

#include <QVector>

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// No new meta methods beyond SuperCommander.
//
// 协商槽体(批 41 语料转写):metacall 00917e20(93B)→ 槽 0 =
// FUN_008606fe(460B)/ 槽 1 = FUN_00860642(188B),均收
// (command,option)双字节;策略 = CTerminalConfig 单例 +0xb0 表
// (FUN_00860a50 访问器;12 字节条目)查表分发 —— 捕获表(批 33)
// 由该配置面驱动,非硬编码。
class TelnetCommander : public SuperCommander
{
	Q_OBJECT

public:
	TelnetCommander(QObject *parent = nullptr);
	virtual ~TelnetCommander(void) = default;
public slots:
	// 槽 0 = FUN_008606fe(460B):表查 option 匹配 → 响应链
	//   FUN_0085e2de/0085e308/0085fa60(+0x128 向量门)
	void negotiateOption(unsigned char command, unsigned char option);
	// 槽 1 = FUN_00860642(188B):表 flag==1 条目 → FUN_0085e326
	//   匹配 → s_session_term_72014e
	void negotiateSubOption(unsigned char command, unsigned char option);

private:
	QVector<int> m_optionStates;   // +0x128 选项状态向量(语料成员)
	Q_DISABLE_COPY(TelnetCommander)
};

#endif // TELNETCOMMANDER_H
