#pragma once

#include <QList>
#include <QString>
#include <QWidget>

// MessageBarFace — 语料 MessageBar(QWidget 子类,qt_metacast "MessageBar"
// 008f7f28;smeta 0119a2e0)承载面(批 244)。
// ctor FUN_0059af30(262B,0018.c:14395):
//   QWidget(parent,0) → 字段:+0x48 = 0 / +0x50 byte & 0xfc /
//   +0x58 QString shared_null / +0x60 QList shared_null
//   → objectName "MessageBar" → setAttribute(0x5d, true)@0059afd9 →
//   setAttribute(0x37, true)(WA_DeleteOnClose)→
//   setSizePolicy(0x5d0000)(**与状态栏 ctor 同常量,第二源**)@0059affx →
//   s_ExpandButton_5984be(this) + FUN_0059834c(this)(子件装配 cited)。
// 信号:idx0 = FUN_008f7e38(56B,0028.c:6832)activate(int, arg)——
//   槽 0/1 均走该发射体(008f7e70 static_metacall);信号名/参数语义
//   未取证 → 本面不声明信号(cited,防造签名)。
class QAbstractButton;
class QToolButton;
class QVBoxLayout;

class MessageBarFace : public QWidget {
	Q_OBJECT
public:
	explicit MessageBarFace(QWidget *parent = nullptr); // FUN_0059af30

signals:
	// 信号 idx0(FUN_008f7e38 56B activate(smo 0119a2e0,idx0,{int,QString})):
	//   实参实证 = (0x80, "") @005981fc;语料名未取证 → 本面命名
	//   messageSignal(cited 名,参数形态 = int + QString)。
	void messageSignal(int code, const QString &text);

public:
	// FUN_0059834c(369B,0018.c:12556)三路接线:
	//   +0x40 clicked → FUN_005981c1(162B:emit(0x80,"") → close());
	//   +0x38 clicked → FUN_0059ced9(58B:s_king__expand_59c9e2(this,
	//     !(+0x50 >>1 &1)) cited);
	//   destroyed → FUN_0059814a(119B:父链找 MuxPane 011a69d0 →
	//     FUN_00767b4a(pane),cited)。
	void wireButtons();

	// s_ExpandButton_5984be(1021B,0018.c:12599)子件装配(名误导,实为 bar 装配):
	//   +0x40 = QToolButton "CloseButton"(tooltip tr("Close") 0xc89b49/
	//     focusPolicy(0));+0x38 = QToolButton "ExpandButton"(tooltip
	//     tr("Expand") 0xc8afe8/focusPolicy(0)/icon "king::shrink");+0x30 =
	//     QVBoxLayout;hbox = QHBoxLayout(边距 = style pixelMetric 0x4e/0x50;
	//     间距 folded)→ addLayout(+0x30)+addWidget(+0x38)+addWidget(+0x40)
	//     → setLayout(hbox)。
	void assembleChildren();

	// FUN_008f7e38(56B,0028.c:6832)信号发射体:activate(smo 0119a2e0,
	//   idx0, {int code, QString text})—— 本面 = emit messageSignal。
	void emitMessage(int code, const QString &text);

	// s_king__expand_59c9e2(882B,0018.c:15301)展开/收起:
	//   +0x60 子件表(QList<QMap<QString,QVariant>>)逐项改 "visible" 键
	//   (cited 深面);+0x38 钮 tooltip = tr("Shrink")/tr("Expand")
	//   (0xc8b041/0xc8afe8)→ show();尾 s_IconLabel_59b1e0(this)(cited)。
	void setExpanded(bool expanded);

	// FUN_0059b046(393B,0018.c:14437)按文本查按钮:
	//   findChildren<QPushButton>(空名, 递归=1)逐个 text() 比对;
	//   命中返回按钮,否则 nullptr。
	class QPushButton;
	QPushButton *findButtonByText(const QString &text) const;

private:
	QToolButton *m_f38 = nullptr; // +0x38 ExpandButton
	QToolButton *m_f40 = nullptr; // +0x40 CloseButton
	QVBoxLayout *m_f30 = nullptr; // +0x30(内容竖排;标签加入点 cited)
	void *m_f48 = nullptr;   // +0x48(ctor 清零,语义 cited)
	quint8 m_flags50 = 0;    // +0x50(低 2 位清零)
	QString m_f58;           // +0x58 shared_null 初值
	QList<void *> m_f60;     // +0x60 QList shared_null 初值(元素面 cited)
};
