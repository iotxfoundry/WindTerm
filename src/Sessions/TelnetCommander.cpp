#include "TelnetCommander.h"

// 语料依赖面(批 41 定位;逐个转写 = 后续批):
//   FUN_00860a50(config+0xb0 访问器)—— CTerminalConfig 单例的
//     telnet 选项表(12 字节条目 {option u32, ?, flag/cmd u8})
//   FUN_0085e2de / FUN_0085e308 / FUN_0085e326 / FUN_0085fa60 /
//     s_session_term_860126(0070ce42 族)—— 匹配与响应链
//   FUN_0085f5d4 —— 槽 0 首调(记录面)
// 表/助手未转写前,槽体按语料结构走 cited 空转写(铁律 3:
// 宁可留空也不猜)—— 结构、门序与调用形均为语料事实。

TelnetCommander::TelnetCommander(QObject *parent)
	: SuperCommander(parent)
{
}

// 槽 0 = FUN_008606fe(460B)语料结构转写:
//   FUN_0085f5d4(this,0,command,option)
//   表 = FUN_00860a50(DAT_011c2200+0xb0)(this+0x128/+0x130 向量门)
//   迭代条目(步长 0xc):option==entry[0](u32)→
//     FUN_0085e2de(this,entry[1]) == command →
//       向量[i]==0 → FUN_0085e308(this,entry[+4])→ FUN_0085fa60
//       (this,ret,option)
void TelnetCommander::negotiateOption(unsigned char command,
                                      unsigned char option)
{
	// FUN_0085f5d4(this,0,command,option)—— cited — wave-2
	// 表访问器 FUN_00860a50(DAT_011c2200+0xb0)—— cited — wave-2
	// (config 表待转写;向量门 this+0x128/+0x130)
	Q_UNUSED(command);
	Q_UNUSED(option);
}

// 槽 1 = FUN_00860642(188B)语料结构转写:
//   表 = FUN_00860a50(DAT_011c2200+0xb0)
//   迭代条目(步长 0xc):entry.flag(+4)==1 →
//     FUN_0085e326(this,i) → s_session_term_860126
//     (this,command,option) 即返
void TelnetCommander::negotiateSubOption(unsigned char command,
                                         unsigned char option)
{
	// 表访问器 FUN_00860a50 —— cited — wave-2
	// flag==1 → FUN_0085e326 匹配 → s_session_term_860126
	//   —— cited — wave-2(响应链待转写)
	Q_UNUSED(command);
	Q_UNUSED(option);
}
