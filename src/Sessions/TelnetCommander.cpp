#include "TelnetCommander.h"

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

TelnetCommander::TelnetCommander(QObject *parent)
	: SuperCommander(parent)
{
}

// 槽 0 = FUN_008606fe(460B)语料转写:
//   FUN_0085f5d4(this,0,command,option)(记录面;cited — wave-2)
//   表 = FUN_00860a50 单例;+0x128 向量非空门(this+0x128 != +0x130)
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

// 槽 1 = FUN_00860642(188B)语料转写:
//   表 = FUN_00860a50 单例;迭代:entry.flag(+4)==1 →
//     FUN_0085e326(this,i)&1 → s_session_term(this,command,option)
//     (真身 s_session_term_72014e,1323B)即返
void TelnetCommander::negotiateSubOption(unsigned char command,
                                         unsigned char option)
{
	const auto &table = telnetOptionTable();
	for (int i = 0; i < table.size(); ++i) {
		if (table[i].flag != 1)
			continue;
		if ((m_optionStates.value(i) & 1) != 0) {   // FUN_0085e326
			// s_session_term_72014e(1323B)—— cited — wave-2
			// (会话终端面,1323B 待转写)
			return;
		}
	}
}
