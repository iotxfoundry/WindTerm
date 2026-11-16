#pragma once

#include <QWidget>

class QComboBox;
class QLabel;

// TransferAskFace — 传输确认对话框的"目标已存在"策略下拉(批 385)。
//
// dialog_add_yn_combo(1482B,0021.c:47258) 实测(实参为 `QWidget **host`,
//   语料 `*param_1 + 0x40` 即宿主 +0x40 槽):
//   label = QLabel(0x30, tr("When destination file &exists:")(0xc9d920));
//   combo = new QComboBox(0x30, *host) → host->+0x40 = combo;
//   选项(data → 文案,.rodata 逐项实读):
//     "-y" → "Overwrite"                        (0xc9da0a)
//     "-n" → "Overwrite when source file newer" (0xc9d940)
//     "-N" → "Overwrite when source file newer or longer" (0xc9d968)
//     "-+" → "Append"     **仅 withAppend 为真时插入** (0xc9da1d)
//     "-E" → "Rename"     (0xc9da27)
//     "-r" → "Resume"     (0xc8ab2f)
//     ""   → "Skip"       (0xc9da2e)
//   label->setBuddy(combo);行加入由调用方完成(本函数不 addRow)。
class TransferAskFace {
public:
	// 返回 combo(宿主 +0x40);label 由 outLabel 带出(可空)。
	static QComboBox *addOverwriteCombo(QWidget *host, bool withAppend, QLabel **outLabel = nullptr);
};
