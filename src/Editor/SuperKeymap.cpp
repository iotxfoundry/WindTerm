#include "SuperKeymap.h"

// 00674648(161B)语料转写:
//   QObject(parent) → SuperKeymap_vtable → +0x10 列表
//   (FUN_0067db7c init,容量 2)→ +0x18 = QRegularExpression
//   ("meta\\+|\\+meta",CaseInsensitive)(006746b9 字面实证)
SuperKeymap::SuperKeymap(QObject *parent)
	: QObject(parent)
	, m_metaRe(QStringLiteral("meta\\+|\\+meta"),
	           QRegularExpression::CaseInsensitiveOption)
{
	m_sources.reserve(2);   // 语料 FUN_0067db7c(+0x10,2)
}

// 0067461a(45B):FUN_0067db40(+0x10)→ FUN_0067ce4c
//   (+0x10 + mode*8 + *(+0x10+0x10))—— mode 索引切换
void SuperKeymap::reset(int mode)
{
	Q_UNUSED(mode);
	// cited — wave-2:FUN_0067db40/0067ce4c 内部结构待转写
	// (mode*8 槽寻址语料在案)
}
