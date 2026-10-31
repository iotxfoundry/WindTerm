#include "TelnetCommander.h"
#include "../Editor/CTerminalConfig.h"
#include "SuperCommander.h"
#include "SuperSession.h"

#include <QTimer>
#include <QVector>

// ── Telnet 协商助手族(批 45 语料转写,铁律 6)────────────────
// 语料函数族(0085e2xx-00860b6e,decomp-part-0027):
//   命令字节→内部码(各 13B,this 未用):
//     FUN_0085e2de: b==0 → -3, else -5
//     FUN_0085e2ec: b==0 → -2, else -4
//     FUN_0085e2fa: b==0 → -4, else -2
//     FUN_0085e308: b==0 → -5, else -3
//   选项状态向量(this+0x128,按 option 索引):
//     FUN_0085e316: vec[i]=0    FUN_0085e326: vec[i]&1
//     FUN_0085e334: vec[7]&1^1  FUN_0085e34a: (vec[i]>>4)&1
//   静态选项表(11 条目 × 3 dword):
//     FUN_00860a50(224B):guard+pthread_once 单例 → DAT_011c2470
//     FUN_00860b6e(254B):resize 11 条目 + 稀疏写(d0=0x1f, d2=0x10,
//       d6=0x18, d8=0x10, d18=1;重叠字节/双字写区 decomp 歧义,cited)
//   响应 FUN_0085fa60(349B):QByteArray{字节,option}→
//     term_processCR(this,bytes,1)→ FUN_0085f5d4(this,1,verb,option)
// 批 41 注记更正:表 = 静态单例(FUN_00860a50),非 CTerminalConfig
// +0xb0(该参数为 Ghidra 调用描述符混淆);s_session_term 真身 =
// s_session_term_72014e(0072014e,1323B)。
// ─────────────────────────────────────────────────────────────

namespace {
// 命令字节→内部码(语料算术原样转写)
inline int verbE2de(unsigned char b) { return b == 0 ? -3 : -5; }   // FUN_0085e2de
inline int verbE2ec(unsigned char b) { return b == 0 ? -2 : -4; }   // FUN_0085e2ec
inline int verbE2fa(unsigned char b) { return b == 0 ? -4 : -2; }   // FUN_0085e2fa
inline int verbE308(unsigned char b) { return b == 0 ? -5 : -3; }   // FUN_0085e308

// FUN_00860a50/00860b6e:静态选项表单例(11 条目 × 3 dword)
struct TelnetOptionEntry
{
	int option;   // 条目 +0(槽 0 比对:u32)
	int verb;     // 条目 +4(经 FUN_0085e2de 映射后与 command 比对)
	int flag;     // 条目 +8
};

const QVector<TelnetOptionEntry> &telnetOptionTable()
{
	static const QVector<TelnetOptionEntry> s_table = {
	    {0x1f, 0, 0x10},   // FUN_00860b6e:d0=0x1f, d2=0x10
	    {0, 0, 0},
	    {0x18, 3, 0x10},   // d6=0x18, d7=3, d8=0x10(TTYPE)
	    {0, 0, 0},
	    {0, 0, 0},
	    {0, 0, 0x10},      // d5=0x10(重叠区标注见头注)
	    {0, 0, 0},
	    {0, 0, 0},
	    {0, 0, 0},
	    {0, 0, 0},
	    {1, 0, 0},         // d18=1
	};
	return s_table;
}
} // namespace

// ctor = FUN_0085f520(172B)转写:
//   007cf02c(SuperCommander 基;+0x40 = param_3 = bridge 存槽)
//   +0x10 = PTR_FUN_011a8de8(Telnet 指令表指针,树面不建模,存注)
//   FUN_007cc8a2:this+0x88 = *(DAT_011c2200+0xb0)(描述符混淆,批 41)
//   FUN_0085f446:+0x128 向量 resize(0xb)+ 表 option 列装载
//     (步进 3 dword:entries[i].option → vec[i],FUN_0085f446 体)
//   QTimer::singleShotImpl(0,0,this,{ref=1,008608e0,0085fbd6,0})
//     → 事件循环首轮 FUN_0085fbd6 initial burst
// 勘正(批 41/48,原样保留):工厂参数 (session, bridge, 0);
// session 存 SuperCommander::m_session(+0x48 链,007da178 面)。
TelnetCommander::TelnetCommander(SuperSession *session, QObject *bridge,
                                 QObject *parent)
	: SuperCommander(parent)
{
	m_session = session;   // FUN_007cf02c +0x48(会话链)
	m_bridge = bridge;     // FUN_007cf02c +0x40;Commander→socket
	                       // 落地未解 #2,仅存槽
	// FUN_0085f446(217B):resize 0xb + 表 option 列拷入向量
	m_optionStates.resize(0xb);
	const auto &table = telnetOptionTable();
	for (int i = 0; i < table.size() && i < m_optionStates.size(); ++i)
		m_optionStates[i] = table[i].option;
	// QTimer::singleShotImpl(0, …, FUN_0085fbd6):初始 burst
	QTimer::singleShot(0, this, &TelnetCommander::initialBurst);
}

// 槽 0 = FUN_008606fe(460B)语料转写:
//   FUN_0085f5d4(1108B)= ostream 调试记录面(telnet_cmdName
//   00861156 格式化;[TERM] 通道宿主调试输出,无终端行为 ——
//   树内无宿主调试汇,记录面定性 no-op,批 48)
//   迭代:option==entry.option → verbE2de(entry.verb)==command →
//     向量[i]==0 → verbE308(entry.flag 域)→ FUN_0085fa60 响应
void TelnetCommander::negotiateOption(unsigned char command,
                                      unsigned char option)
{
	const auto &table = telnetOptionTable();
	if (m_optionStates.isEmpty())
		return;                                   // 语料向量空门
	for (int i = 0; i < table.size(); ++i) {
		if (option != table[i].option)
			continue;
		if (command == verbE2de(table[i].verb)) {
			if (i < m_optionStates.size()
			    && m_optionStates[i] == 0) {
				const int resp = verbE308(table[i].flag);
				// FUN_0085fa60(this,resp,option):响应字节 →
				// term_processCR(0076 族;会话输出面,cited —
				// wave-2:写出通道随 TelnetSession 批接)
				Q_UNUSED(resp);
			}
		}
	}
}

// s_session_term_860126(00860126,1251B)TTYPE 分支语料转写
// (批 48):command==0x18 && option==1 → 响应 = [0x18 前导]
//   config("session.term")(config getter 族;终类型值随配置,
//   捕获 xterm-256color = 原版配置值实证)
static QByteArray sessionTermResponse(unsigned char lead,
                                      const QByteArray &termType)
{
	QByteArray r;
	r.append(lead);
	r.append(termType);
	return r;
}

// 槽 1 = FUN_00860642(188B)语料转写:
//   表 = FUN_00860a50 单例;迭代:entry.flag(+4)==1 →
//     FUN_0085e326(this,i)&1 → s_session_term_860126
//     (00860126,1251B)即返
void TelnetCommander::negotiateSubOption(unsigned char command,
                                         unsigned char option)
{
	const auto &table = telnetOptionTable();
	for (int i = 0; i < table.size(); ++i) {
		if (table[i].flag != 1)
			continue;
		if ((m_optionStates.value(i) & 1) != 0) {   // FUN_0085e326
			// s_session_term_860126 TTYPE 分支:config
			// "session.term"(0x00a7ecde 族 config getter 面;
			// 经 CTerminalConfig 委托)→ negotiationReply 写出
			// (term_processCR 承载 = 会话输出通道;勘正见头注
			// —— 语料为直调,信号 = 架构化替代)
			if (command == 0x18 && option == 1) {
				// config 值(CTerminalConfig 委托);缺省 =
				// 捕获实证值(xterm-256color)
				const QString term = CTerminalConfig::instance()
				                         ->value(QStringLiteral(
				                                     "session.term"),
				                                 QStringLiteral(
				                                     "xterm-256color"))
				                         .toString();
				emit negotiationReply(
				    sessionTermResponse(0x18, term.toUtf8()));
			}
			return;
		}
	}
}

// FUN_0085fbd6(155B)初始 burst 转写(singleShot(0) 仿函数真身,
// 仿函数壳 008608e0 = metacall 适配):表单例 → 迭代向量:
//   FUN_0085e34a(vec[i]>>4)&1 非零 → entry=表[i] →
//   FUN_0085fa60(this, verbE308(entry.verb 域), entry.option 字节)
void TelnetCommander::initialBurst()
{
	const auto &table = telnetOptionTable();
	if (m_optionStates.isEmpty())   // 语料 0x128/0x130 指针对空门
		return;
	for (int i = 0; i < m_optionStates.size() && i < table.size(); ++i) {
		if (((m_optionStates[i] >> 4) & 1) != 0) {   // FUN_0085e34a
			const int resp = verbE308(static_cast<unsigned char>(
			    table[i].verb));   // puVar1[4]=entry.verb 域
			// FUN_0085fa60(param_1,uVar4,uVar2):{verb 字节,
			// option} 2B 响应 → term_processCR(写出腿 cited —
			// wave-2,未解 #2;信号替代与 negotiateSubOption 同面)
			QByteArray burst;
			burst.append(static_cast<char>(resp));
			burst.append(static_cast<char>(table[i].option));
			emit negotiationReply(burst);
		}
	}
}
