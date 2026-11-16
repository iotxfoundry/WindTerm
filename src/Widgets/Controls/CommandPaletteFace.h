#pragma once

#include <QFrame>

// CommandPaletteFace — 命令面板(QFrame 派生)。
//
// 出处:RTTI "CommandPalette";QMetaObject 0x01197cc0
// (**methods=0 / signals=0 / props=0** —— 零元接口,metacall 5B 纯转发);
// dtor 0x0053fbfc(51B)/deleting 0x0053fc36(23B);
// eventFilter = vt6 0x00540500(51B)。
//
// 字段(dtor 实读):**+0x78 一个子对象**(走 FUN_005446d0 释放)。
// (dtor 末句 QFrame::~QFrame;因本类无中间基,可直接认。)
//
// eventFilter 语义(vt6 实读):
//   只处理 **Resize(0xe = 14)**;命中时取 FUN_0053ecae() 的返回与该事件
//   比较,相等才调 FUN_005401d6(this)。
//   **两条 return 0 分支都在**(非 Resize 返回 0;Resize 且不等也返回 0)
//   ⇒ 这个 eventFilter **永不吞事件**,只做副作用。
class CommandPaletteFace : public QFrame {
	Q_OBJECT

public:
	explicit CommandPaletteFace(QWidget *parent = nullptr);
	~CommandPaletteFace() override; // 0x0053fbfc

protected:
	bool eventFilter(QObject *watched, QEvent *event) override; // vt6 0x00540500

private:
	char m_f78[0x10] = {}; // +0x78 子对象(类型未复原)
};
