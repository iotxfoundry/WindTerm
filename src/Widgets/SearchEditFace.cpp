// SearchEditFace.cpp — 语料 SearchEdit / FilterEdit 两个 ctor(批 255)
#include "SearchEditFace.h"

#include <QCursor>

#include "Actions/ThemeIcons.h"

#include <QHBoxLayout>
#include <QStyle>
#include <QTimer>
#include <QToolButton>

// searchEdit_init(131B,0018.c:5832)ctor 真身:
//   @0058e0ce QLineEdit(parent);字段 +0x30/38/40=0、+0x48=0x7fffffff、
//   +0x50 QList 空、+0x58 byte=0、+0x68=0;
//   @0058e12x FUN_0075c6c6(app,this) + FUN_0058e028(this) + FUN_0058d818(this)
//   — 三条子件/注册腿未转写,cited。
SearchEditFace::SearchEditFace(QWidget *parent)
	: QLineEdit(parent) // @0058e0ce
{
	// 字段族按语料初值(见头注);注意 m_f48 初值 0x7fffffff 已在成员初始化。
	buildLayout();  // FUN_0058e028 @0058e13x
	wireSignals();  // FUN_0058d818 @0058e14x
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
	buildClearButton(); // s_king__clear_57e86e @0057eba8(批 272)
	// FUN_0057e662(this)@0057ebbx — cited(体未转写)。
}

// FUN_0058dac2(18B,0018.c:5565)真身:
//   QLineEdit::setPlaceholderText(text)+ FUN_0058d4dc(this)(后续腿,cited)。
void SearchEditFace::setPlaceholder(const QString &text)
{
	setPlaceholderText(text); // @0058dac2
	// FUN_0058d4dc(this)@0058dac2 — cited(体未转写)
}

// FUN_0058e028(158B,0018.c:5803)布局真身:
//   @0058e028 margin = style()->pixelMetric(5,0,0) 经 FUN_0075263e 换算
//     (double→int;换算面 cited);
//   +0x60 = new QHBoxLayout @0058e07b → setContentsMargins(m,m,m,m)
//     → setSpacing(折叠,cited) → addStretch @0058e09x → setLayout(this)
//     → FUN_0058dff2(this)(cited)。
void SearchEditFace::buildLayout()
{
	const int metric =
	    style()->pixelMetric(static_cast<QStyle::PixelMetric>(5)); // @0058e028
	// FUN_0075263e((double)metric, app, this) 换算 → int — cited(换算体未转写)
	const int margin = metric;
	m_f60 = new QHBoxLayout(); // @0058e07b
	m_f60->setContentsMargins(margin, margin, margin, margin);
	m_f60->addStretch(); // @0058e09x
	setLayout(m_f60);
	// FUN_0058dff2(this)@0058e0c0 — cited。
}

// FUN_0058d818(296B,0018.c:5421)接线真身:
//   connect(this, textChanged, this, FUN_0058d4dc);
//   connect(this, 信号 FUN_008f6d88(smeta 01198660), this, FUN_0058e159,
//     flags 0x82 = UniqueConnection|QueuedConnection)。
void SearchEditFace::wireSignals()
{
	connect(this, &QLineEdit::textChanged, this, [this](const QString &) {
		/* FUN_0058d4dc(this)@0058d818 — cited(体未转写) */
	});
	// connect(this, FUN_008f6d88, this, FUN_0058e159, flags 0x82)@0058d8xx —
	//   信号/槽体未转写,cited 不落接线。
}

// FUN_0058d940(47B,0018.c:5459)真身:
//   +0x30 串非空 且 +0x38 非空 → FUN_00551a7c(+0x38);否则 FUN_00551a7c(0)。
void SearchEditFace::updateAssociatedModel()
{
	// FUN_00551a7c(关联件|0)@0058d940 — cited(体未转写)
}

// FUN_0058d970(82B,0018.c:5482)真身:
//   child 非空 → i = vcall(child|+0x60, +0xa8)(计数面);0 <= i < +0x68 →
//   +0x68--;removeWidget(child);child->hide();发 FUN_008f6d88(this)。
void SearchEditFace::removeChildWidget(QWidget *child)
{
	if (child == nullptr)
		return;
	// vcall(+0xa8) 计数面 + FUN_008f6d88 发射 — cited(体未转写)
	if (m_f60 != nullptr)
		m_f60->removeWidget(child); // @0058d9xx
	child->hide();
}

// FUN_0058dff2(54B,0018.c:5788)真身:
//   l = FUN_0058de52(this,0);r = FUN_0058de52(this,1);
//   QLineEdit::setTextMargins(l, 0, r)。
void SearchEditFace::applyTextMargins()
{
	const int left = 0;  // FUN_0058de52(this,0) — cited(子件宽度面)
	const int right = 0; // FUN_0058de52(this,1) — cited
	setTextMargins(left, 0, right);
}

// s_king__clear_57e86e(442B,0017.c:55328)清除钮真身:
//   @0057e892 +0x70 = new QToolButton(this)(0x30 字节);
//   @0057e8xx setAutoRaise(实参 Ghidra 丢→按 false,cited);
//   @0057e8c1 setCursor(QCursor(0));@0057e914 icon "king::clear";
//   @0057e98x tooltip tr("&Clear")(0xc9e7b8 实读)@0057e990;
//   @0057e9ab hide();@0057e9c0 boxlayout_insertRtlAware(this, btn, 1)(cited)。
void FilterEditFace::buildClearButton()
{
	m_clear70 = new QToolButton(this); // @0057e892
	m_clear70->setAutoRaise(false);    // 实参丢 — cited(按 false)
	m_clear70->setCursor(QCursor());   // QCursor(0) @0057e8c1
	m_clear70->setIcon(ThemeIcons::loadSvg(QStringLiteral("king::clear"),
	                                       QString())); // @0057e914
	m_clear70->setToolTip(tr("&Clear"));               // 0xc9e7b8 @0057e990
	m_clear70->hide();                                 // @0057e9ab
	// boxlayout_insertRtlAware(this, m_clear70, 1)@0057e9c0 — cited。
}
