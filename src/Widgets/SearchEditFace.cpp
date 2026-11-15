// SearchEditFace.cpp — 语料 SearchEdit / FilterEdit 两个 ctor(批 255)
#include "SearchEditFace.h"

#include <QTimer>

// searchEdit_init(131B,0018.c:5832)ctor 真身:
//   @0058e0ce QLineEdit(parent);字段 +0x30/38/40=0、+0x48=0x7fffffff、
//   +0x50 QList 空、+0x58 byte=0、+0x68=0;
//   @0058e12x FUN_0075c6c6(app,this) + FUN_0058e028(this) + FUN_0058d818(this)
//   — 三条子件/注册腿未转写,cited。
SearchEditFace::SearchEditFace(QWidget *parent)
	: QLineEdit(parent) // @0058e0ce
{
	// 字段族按语料初值(见头注);注意 m_f48 初值 0x7fffffff 已在成员初始化。
}

// FUN_0057eb0c(200B,0017.c:55458)FilterEdit ctor 真身:
//   @0057eb0c searchEdit_init(this,parent)→ vtable FilterEdit;
//   @0057eb47 +0x78 = operator_new(0x20)+QTimer(this);
//   @0057eb5c timer 内部 +0x1c |= 1(cited:QTimer 私有单发位);
//   @0057eb5c FUN_0057eb02(this,300)(cited 延时面);
//   @0057eb83 tr(0xc893d4)+FUN_0058dac2(this,文本)(cited 提示面);
//   @0057eba8 s_king__clear_57e86e(this)(cited)+FUN_0057e662(this)(cited)。
FilterEditFace::FilterEditFace(QWidget *parent)
	: SearchEditFace(parent) // @0057eb0c
{
	m_timer78 = new QTimer(this); // @0057eb47(0x20 字节)
	// timer 自身 +0x1c |= 1(QTimer 私有单发位)→ cited 不落。
	m_timer78->setInterval(300); // FUN_0057eb02(9B)= QTimer::setInterval(+0x78, 300)
	setPlaceholder(tr("Filter")); // tr(0xc893d4)= "Filter"+FUN_0058dac2(批 268)
	// s_king__clear_57e86e(this) + FUN_0057e662(this) → cited(清除钮/子件)。
}

// FUN_0058dac2(18B,0018.c:5565)真身:
//   QLineEdit::setPlaceholderText(text)+ FUN_0058d4dc(this)(后续腿,cited)。
void SearchEditFace::setPlaceholder(const QString &text)
{
	setPlaceholderText(text); // @0058dac2
	// FUN_0058d4dc(this)@0058dac2 — cited(体未转写)
}
