#pragma once

#include <QLineEdit>
#include <QList>

class QHBoxLayout;
class QTimer;

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

private:
	QTimer *m_timer78 = nullptr; // +0x78
};
