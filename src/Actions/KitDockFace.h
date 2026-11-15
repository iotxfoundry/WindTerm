#pragma once

#include <QWidget>

class TabGroup;

// KitDockFace — 语料 KitDock(QWidget 子类,qt_metacast "KitDock" 0091aa00;
// smeta 011ab100)承载面(批 207)。
// ctor FUN_008b81b0(109B,0027.c:75478):
//   QWidget(param_3,0)@008b81b8 → 字段:+0x38 = param_2 = **bool**
//   (ExpandButton 门控;批 216 勘正:s_ExpandButton_8b7dd4 的
//   `if (+0x38 != 0) createButton("ExpandButton")` 与 call site
//   89d860(param_2 = isAncestorOf 结果 bool)双源一致)
//   / +0x39 = 0(浮停旗标,状态面 +0x39 双源:008b86e4 门 + StateStore
//   dock_toggleFloat 注释)/ +0x3c = 0 / +0x44 = -1 / +0x4c = -1
//   → setFocusPolicy(0)@008b8215 → s_ExpandButton_8b7dd4(this) cited
//   → FUN_008b7f60(this) cited(子件装配面未转写)。
// 槽表(0091a844 qt_static_metacall dispatch):case 0xb → FUN_008b86e4
//   (收起行为,本面真身);其余 case cited。
class KitDockFace : public QWidget {
	Q_OBJECT
public:
	// FUN_008b81b0:withExpand = +0x38(ExpandButton 门控),parent = QWidget 父。
	explicit KitDockFace(bool withExpand = false, QWidget *parent = nullptr);

	// FUN_008b86e4(153B,0027.c:75642)收起行为:
	//   非浮停(+0x39 == 0)且父为 QSplitter 且 count() < 2 → 对应槽位
	//   kitslot 隐藏(008ca0b8 反查 id + 008ca168 hideIndex),不删自身;
	//   否则 deleteLater。尾:kit 存在 → FUN_008cb0c0(kit,3)(cited)。
	void closeWithCollapse();

	// FUN_008b7f60(591B,0027.c:75393)四路接线(+0x30 = TabGroup):
	//   tabActivated(idx0)→FUN_008b7d08(本面真身)/
	//   closeRequested(idx7)→FUN_008b86e4(closeWithCollapse)/
	//   configRequested(idx8)→s_ConfigButton_8b877e(cited)/
	//   expandRequested(idx9)→FUN_008b7ca0(本面真身:非浮停才转发
	//   自身信号 idx0,FUN_0091a7d8 实证)。
	void wireTabGroup(TabGroup *tabs);

	// s_ExpandButton_8b7dd4(371B,0027.c:75331)子件装配(名取自函数头,
	//   实为 KitDock 装配):TabGroup(0xa8)@008b7df1 → objectName
	//   "PaneGroup" → (+0x38 非空时)ExpandButton → ConfigButton →
	//   CloseButton(三个 createButton(name,1))→ QVBoxLayout →
	//   addWidget(tabGroup)+ addWidget(tabGroup->stack())→ setLayout。
	void assembleChildren();

	// s_ExpandButton_5ab32a(584B,0018.c:25117)展开钮状态:
	//   findChild<QToolButton>("ExpandButton",递归)空 → 返;图标名
	//   expanded ? "king::expand" : "king::shrink"(0xc8b03a/0xc8aff4 实读)
	//   → ThemeIcons::loadSvg → setIcon;tooltip expanded ? "Shrink" :
	//   "Expand"(0xc8b041/0xc8afe8)→ setToolTip;setProperty("expanded",b)。
	void updateExpandButton(bool expanded);
	TabGroup *tabGroup() const { return m_tabs; } // +0x30

	bool isFloating() const { return m_f39; } // +0x39
	void setFloating(bool on) { m_f39 = on; }

signals:
	// qmeta 索引 idx0(FUN_0091a7d8 activate idx0,实参 bool)——
	//   语料名未取证,按转发面命名为 expandRequested(cited 名)。
	void expandRequested(bool expanding);

private slots:
	// FUN_008b7d08(187B,0027.c:75296)页切换槽:stackWidgetAt(idx) →
	//   cast 011ab690(KitPane)→ setFocus(3)→ 同步 windowIcon/windowTitle。
	void onTabActivated(int index);
	// FUN_008b7ca0(59B)展开转发:+0x39 == 0(非浮停)→ emit expandRequested。
	void onExpandRequested(bool expanding);

private:
	TabGroup *m_tabs = nullptr; // +0x30(语料 4 路接线与页操作共同宿主)
	bool m_withExpand = false; // +0x38 ExpandButton 门控(批 216 勘正)
	bool m_f39 = false;        // +0x39 浮停旗标
};
