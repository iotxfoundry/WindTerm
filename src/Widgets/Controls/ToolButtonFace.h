#pragma once

#include <QToolButton>

#include "Utility/KingEnums.h"

class QTextDocument;

// ToolButtonFace — 支持富文本提示 + 富文本写入的工具栏按钮。
//
// 出处:RTTI "ToolButton";sizeHint = vt14 0x005d5588(229B);
// dtor 0x008fbb66(29B)/deleting 0x008fbba4(47B,operator_delete(_,**0x40**));
// metaObject 0x008fb9d0(→ PTR_staticMetaObject_0119e100)/
// metacast 0x008fbaac / metacall 0x008fbaee(119B);属性桥 0x008fb9e8(196B)。
//
// QMetaObject 实读(rev=8,class="ToolButton",methods=0,props=3):
//   prop #0 `elideMode` : King::TextElideMode → 字段 +0x30(int)
//   prop #1 `menu`      : Menu*              → QToolButton::menu() 经
//                        __dynamic_cast<Menu*>(0x01199e50) 取;写入 = setMenu
//   prop #2 `text`      : QString            → 读 QAbstractButton::text();
//                        写时先判 Qt::mightBeRichText,是则建富文本文档
//
// 字段:
//   +0x30 int              elideMode(King::TextElideMode 值域)
//   +0x38 QTextDocument*   惰建,只服务于富文本 sizeHint 量宽
class ToolButtonFace : public QToolButton {
	Q_OBJECT

	Q_PROPERTY(King::TextElideMode elideMode MEMBER m_elideMode30)
	Q_PROPERTY(QString text MEMBER m_textProxy)

public:
	explicit ToolButtonFace(QWidget *parent = nullptr);
	~ToolButtonFace() override; // 008fbb66

	QSize sizeHint() const override; // vt14 0x005d5588

	// 0x008fb9e8(196B)属性桥:op=1 读 / op=2 写,index 0..2 对应上表。
	void metaDispatch(int op, int index, void **args);

signals:
	// 语料:QAbstractButton::setText 由本类接管(见 setText)
	void textChanged();

public slots:
	void setText(const QString &text); // 0x005d4f90(54B)

private:
	void ensureDoc(const QString &html); // 0x005d4eb2(141B)

	int m_elideMode30 = 0;          // +0x30
	QTextDocument *m_doc38 = nullptr; // +0x38
	QString m_textProxy;            // Q_PROPERTY 需要
	QString m_richHtml;             // 富文本原文
};
