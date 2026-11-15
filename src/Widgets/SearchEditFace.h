#pragma once

#include <QLineEdit>
#include <QList>

class QHBoxLayout;
class QFocusEvent;
class QTimer;
class QToolButton;

// SearchEditFace — 语料 SearchEdit : QLineEdit 基面(批 255)。
// ctor = searchEdit_init(131B,0018.c:5832):
//   QLineEdit(parent)@0058e0ce → +0x30/+0x38/+0x40 = 0 /
//   +0x48 int = 0x7fffffff / +0x50 QList 空 / +0x58 byte = 0 / +0x68 = 0
//   → FUN_0075c6c6(app, this)(注册面,cited)→ FUN_0058e028(this)/
//   FUN_0058d818(this)(子件,cited)。
class SearchEditFace : public QLineEdit {
	Q_OBJECT
public:
	explicit SearchEditFace(QWidget *parent = nullptr); // searchEdit_init

	// FUN_0058dac2(18B,0018.c:5565)占位文案:QLineEdit::setPlaceholderText
	//   + FUN_0058d4dc(this)(后续(sub-assembly cited))。
	void setPlaceholder(const QString &text);

	// FUN_0058e028(158B,0018.c:5803)布局:+0x60 QHBoxLayout(边距 =
	//   style pixelMetric(5) 经 FUN_0075263e 换算,cited)→ addStretch →
	//   setLayout → FUN_0058dff2(this)(cited)。
	void buildLayout();
	// FUN_0058d818(296B,0018.c:5421)接线:this textChanged → FUN_0058d4dc
	//   (cited);this 信号 FUN_008f6d88(smeta 01198660)→ FUN_0058e159(cited)。
	void wireSignals();
	// FUN_0058d940(47B):+0x30 串非空 且 +0x38 非空 → FUN_00551a7c(+0x38);
	//   否则 FUN_00551a7c(0)(关联件置空)。
	void updateAssociatedModel();
	// FUN_0058d970(82B)移除子件:子件非空 → count(vcall +0xa8) 有效且 < +0x68
	//   → +0x68-- → removeWidget(+0x60 子件)→ hide → 发 FUN_008f6d88。
	void removeChildWidget(QWidget *child);
	// FUN_0058dff2(54B)边距:setTextMargins(l, 0, r)(l/r = FUN_0058de52(0/1),
	//   子件宽度面,cited)。
	void applyTextMargins();
	// FUN_0058e159(59B,0018:5824)文本同步腿:私有位(d+9&0x80)==0
	//   (疑未隐藏)→ applyTextMargins()。
	void onTextReverted();

protected:
	void *m_f30 = nullptr;  // +0x30
	void *m_f38 = nullptr;  // +0x38
	void *m_f40 = nullptr;  // +0x40
	int m_f48 = 0x7fffffff; // +0x48(限值面)
	QList<void *> m_f50;    // +0x50 QList
	quint8 m_f58 = 0;       // +0x58 byte
	void *m_f68 = nullptr;  // +0x68
	QHBoxLayout *m_f60 = nullptr; // +0x60(布局)
};

// FilterEditFace — 语料 FilterEdit : SearchEdit(toolbar kind 6)。
// ctor FUN_0057eb0c(200B,0017.c:55458):
//   searchEdit_init(this,parent)→ vtable FilterEdit →
//   +0x78 = new QTimer(this)(0x20 字节;timer 自身 +0x1c |= 1 单发位,
//   内部字段 → cited)→ FUN_0057eb02(this,300)(延时面,cited)→
//   tr(0xc893d4)→ FUN_0058dac2(this,文本)(占位/提示面,cited)→
//   s_king__clear_57e86e(this)(清除钮 cited)→ FUN_0057e662(this)(cited)。
class FilterEditFace : public SearchEditFace {
	Q_OBJECT
public:
	explicit FilterEditFace(QWidget *parent = nullptr); // FUN_0057eb0c

protected:
	// FUN_0057ea5e(120B,0017.c:55411)focusIn:基类 → reason 非 4(Popup)
	//   非 7(MenuBar) → singleShot(0,FUN_0057e55a cited);
	//   FUN_008f92e2(this,1,reason)(cited)。
	void focusInEvent(QFocusEvent *event) override;

	// s_king__clear_57e86e(442B,0017.c:55328)清除钮:
	//   +0x70 = new QToolButton(this)(0x30)→ setAutoRaise(cited 实参)→
	//   setCursor(QCursor(0))→ icon "king::clear"→ tooltip tr("&Clear")
	//   (0xc9e7b8 实读)→ hide()→ boxlayout_insertRtlAware(this, btn, 1)
	//   (布局插入辅助,cited)。
	void buildClearButton();

private:
	QTimer *m_timer78 = nullptr;   // +0x78
	QToolButton *m_clear70 = nullptr; // +0x70(清除钮)
};
