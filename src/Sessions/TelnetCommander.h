#ifndef TELNETCOMMANDER_H
#define TELNETCOMMANDER_H

#pragma once

#include "SuperCommander.h"
#include "TelnetProtocol.h"

#include <QHash>
#include <QJsonParseError>
#include <QRegularExpression>

// Reconstructed from WindTerm 2.7.0 (libWindTerm) QMetaObject metadata.
// Negotiation is config-driven: terminal/protocols/telnet.protocol defines an
// IAC grammar as named capture groups; matched groups dispatch to these slots
// by name (see PROTOCOL-ARCHITECTURE.md).
class TelnetCommander : public SuperCommander
{
	Q_OBJECT

public:
	TelnetCommander(QObject *parent = nullptr);
	virtual ~TelnetCommander(void) = default;
public slots:
	void negotiateOption(const QString &command);
	void negotiateSubOption(const QString &option);

signals:
	void optionNegotiated(const QString &command, int option);
	void subOptionReceived(int option, int action);
	void negotiationReply(const QByteArray &data);   // 协商回写字节

public:
	// 装载 terminal/protocols/telnet.protocol(refs + match 编译)
	bool loadProtocol(const QString &path);
	// 字节流入解析:IAC 握手 → 槽/信号;非协议字节直通返回
	QByteArray feed(const QByteArray &in);

	// 选项状态(NegotiateOption 记录面)
	QHash<int, QString> optionStates;

	// 协商响应字节(实验锚 telnet_capture.json 2026-10-30:原版
	// 2.7.0 连 127.0.0.1:3023 捕获;语料无策略体——三叶
	// 00860b30/00860cd6/00861156 = 名字表/日志,telnet.protocol
	// 仅解析面 → 响应策略以实验锚为准)
	QByteArray initialNegotiation() const;

private:
	Q_DISABLE_COPY(TelnetCommander)

	QRegularExpression m_re;      // telnet.protocol match 编译
	QJsonParseError m_parseError;
	int m_refIAC = 0xff;   // telnet.protocol refs 解码字节(默认 RFC)
	int m_refSB = 0xfa;
	int m_refSE = 0xf0;
	TelnetProtocol m_proto;       // 命令/选项名表(开源同版)
	QByteArray m_pending;         // 尾部半截序列(partial)
};

#endif // TELNETCOMMANDER_H
