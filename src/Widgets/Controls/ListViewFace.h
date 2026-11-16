#ifndef WIDGETS_CONTROLS_LISTVIEWFACE_H
#define WIDGETS_CONTROLS_LISTVIEWFACE_H

#pragma once

// ListView — 自绘列表视图(带自研 delegate + 装饰模型)。
// RTTI 类名 "ListView";ctor FUN_00583bac(0x00583bac,703B);dtor 0x00582c72(718B)。
// 该件即 Completer 里那个「0x78B 列表」的实际类型。
//
// 字段(ctor 实读):
//   +0x30 void*   0
//   +0x31 QListView  owner(ctor 第 2 实参,为 0 则跳过尾段)
//   +0x32 u16     = 0x101(两个字节旗标,原样)
//   +0x34 int     = 1
//   +0x38 void*   0
//   +0x40 QByteArray 空
//   +0x48/+0x50 void* 0
//   +0x58 void*   new 0x98B 件(FUN_00581260(this))—— 自研 delegate
//   +0x60 int     0
//   +0x68 void*   0
//   +0x70 void*   new 0xb0B 件(FUN_00a8ec9c(_, 4))—— 装饰/桶
//
// 注:与该类同级的 HtmlList **不是**它的派生(见 HtmlListFace 头)。

#include <QListView>
#include <QString>

class ListViewFace : public QListView {
	Q_OBJECT

public:
	ListViewFace(QWidget *parent, QListView *owner = nullptr); // 00583bac
	~ListViewFace() override;                                 // 00582c72

	// ───────── 元接口(出处:QMetaObject 0x0119b720) ─────────
	// rev=8,class="ListView",methods=3 **signals=2 props=1**:
	//   #0 modelChanged()          信号
	//   #1 filterFinished()        信号
	//   #2 updateFilterString(?)   槽 → 0x008f8d2e 分发
	//   prop #0 `singleLine` —— 注意它**没有独立字段**(见下 +0x32 位旗标)
	signals:
	void modelChanged();   // #0
	void filterFinished(); // #1

public slots:
	void updateFilterString(const QString &text); // #2

public:
	// eventFilter = vt6 0x005843b0(461B):**与 ListWidget 的键位表逐条同构**
	//   三连门(可见 && watched == +0x38 && KeyPress)+
	//   0x1000013/15/16/17 → moveCursor(MoveUp=0 / MoveDown=1 /
	//   MovePageUp=6 / MovePageDown=7) → setCurrentIndex
	//   0x1000004/0x1000005 → activated(currentIndex())
	//   **另有 ListWidget 没有的一支**:modifiers == ControlModifier(0x8000000)
	//   且 key - 0x31 >= 0(model 非空)→ 走 model 的快捷选择
	// sizeHint = vt14 0x00583ace(157B):
	//   宽 = min(model->rowCount, +0x60) * 单行高(moveCursor 取)+ frameWidth*2
	//   高 = (viewport bottom - top) + 1
	QSize sizeHint() const override;
	bool eventFilter(QObject *watched, QEvent *event) override;

private:
	void *m_f30 = nullptr;            // +0x30
	QListView *m_owner31 = nullptr;   // +0x31(原始参数)
	quint16 m_flags32 = 0x101;        // +0x32
	int m_f34 = 1;                    // +0x34
	void *m_f38 = nullptr;            // +0x38
	QByteArray m_f40;                 // +0x40
	void *m_f48 = nullptr;            // +0x48
	void *m_f50 = nullptr;            // +0x50
	void *m_delegate58 = nullptr;     // +0x58(0x98B 自研 delegate)
	int m_f60 = 0;                    // +0x60
	void *m_f68 = nullptr;            // +0x68
	void *m_f70 = nullptr;            // +0x70(0xb0B 件)
};

#endif // WIDGETS_CONTROLS_LISTVIEWFACE_H
