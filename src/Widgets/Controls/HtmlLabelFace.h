#pragma once

#include <QLabel>
#include <QString>

// HtmlLabelFace — 富文本标签(QLabel 派生,富文本缓存一份)。
//
// 出处:RTTI "HtmlLabel";QMetaObject 0x0119ca20
// (**methods=0 / signals=0 / props=0 / superdata=0**);
// sizeof = **0x48**(deleting 0x008fa306 的 operator_delete(_,0x48));
// dtor 0x008fa41a(86B)/deleting 0x008fa306(92B)。
//
// 字段:+0x30 QString —— 富文本原文(QLabel 自身 +0x30 之后,本类追加)
class HtmlLabelFace : public QLabel {
	Q_OBJECT

public:
	explicit HtmlLabelFace(QWidget *parent = nullptr);
	~HtmlLabelFace() override; // 0x008fa41a

private:
	QString m_html30; // +0x30
};
