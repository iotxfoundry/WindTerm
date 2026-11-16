#ifndef WIDGETS_CONTROLS_COMPLETERFACE_H
#define WIDGETS_CONTROLS_COMPLETERFACE_H

#pragma once

// Completer — 补全下拉浮层(自绘列表 + 布局,装成无边框 ToolTip 窗)。
// RTTI 类名 "Completer";ctor 0x005518d8(247B);视图装配 0x005517e2(229B);
// 接线 0x005516fe(227B);activated 槽腿 0x0055169b;事件过滤 vt6 0x00551ada(642B)。
//
// 字段:
//   +0x00 vptr(主)   +0x10 vptr(第二多态基,PTR_FUN_0119ba48)
//   +0x30 视图(0x78B 自绘 item view,构造 FUN_00583bac(this, 0))
//   +0x38 QObject *host —— 沿 parent 链 dynamic_cast 找到的事件过滤宿主
//
// 说明:属性号 0x37/0x62、窗口标志 0x200c0b、行内标志 0x800、尺寸约束 2
// 均按语料字面保留,不映射到 Qt 枚举名(版本表差,字面权威)。

#include <QWidget>

class QListView;

class CompleterFace : public QWidget {
	Q_OBJECT

public:
	explicit CompleterFace(QWidget *parent = nullptr); // 005518d8

protected:
	bool eventFilter(QObject *watched, QEvent *event) override; // vt6 00551ada

private:
	void buildView(); // 005517e2
	void wire();      // 005516fe
	void onActivated(); // 0055169b
	void dismissPopup(); // 00551a7c

	QListView *m_view30 = nullptr; // +0x30(0x78B 自绘列表件)
	QObject *m_host38 = nullptr;           // +0x38
};

#endif // WIDGETS_CONTROLS_COMPLETERFACE_H
