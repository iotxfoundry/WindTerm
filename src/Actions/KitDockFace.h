#pragma once

#include <QWidget>

// KitDockFace — 语料 KitDock(QWidget 子类,qt_metacast "KitDock" 0091aa00;
// smeta 011ab100)承载面(批 207)。
// ctor FUN_008b81b0(109B,0027.c:75478):
//   QWidget(param_3,0)@008b81b8 → 字段:+0x38 = param_2(实参槽,cited 语义)
//   / +0x39 = 0(浮停旗标,状态面 +0x39 双源:008b86e4 门 + StateStore
//   dock_toggleFloat 注释)/ +0x3c = 0 / +0x44 = -1 / +0x4c = -1
//   → setFocusPolicy(0)@008b8215 → s_ExpandButton_8b7dd4(this) cited
//   → FUN_008b7f60(this) cited(子件装配面未转写)。
// 槽表(0091a844 qt_static_metacall dispatch):case 0xb → FUN_008b86e4
//   (收起行为,本面真身);其余 case cited。
class KitDockFace : public QWidget {
	Q_OBJECT
public:
	// FUN_008b81b0:param_2 = +0x38 实参槽(语义 cited),parent = QWidget 父。
	explicit KitDockFace(QWidget *slot38 = nullptr, QWidget *parent = nullptr);

	// FUN_008b86e4(153B,0027.c:75642)收起行为:
	//   非浮停(+0x39 == 0)且父为 QSplitter 且 count() < 2 → 对应槽位
	//   kitslot 隐藏(008ca0b8 反查 id + 008ca168 hideIndex),不删自身;
	//   否则 deleteLater。尾:kit 存在 → FUN_008cb0c0(kit,3)(cited)。
	void closeWithCollapse();

	bool isFloating() const { return m_f39; } // +0x39
	void setFloating(bool on) { m_f39 = on; }

private:
	QWidget *m_f38 = nullptr; // +0x38(ctor 实参槽,语义 cited)
	bool m_f39 = false;       // +0x39 浮停旗标
};
