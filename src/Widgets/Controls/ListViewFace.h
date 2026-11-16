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

class ListViewFace : public QListView {
	Q_OBJECT

public:
	ListViewFace(QWidget *parent, QListView *owner = nullptr); // 00583bac
	~ListViewFace() override;                                 // 00582c72

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
