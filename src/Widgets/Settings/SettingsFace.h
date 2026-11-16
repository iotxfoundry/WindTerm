#pragma once

#include <QWidget>

class QButtonGroup;
class QStandardItem;
class QTreeView;

// SettingsFace — **伞形工具集合,非原版类**(二进制无此 RTTI 名,勿当类建模)。
// 原本是批 191 的"设置页族"承载类,批 191 误把 TextMarkDialog 的 ctor 与
// search_page_build_layout 收进来;2026-11-16 归位到 TextMarkDialogFace。
// 余下三段是**独立函数**,与任何原版类都不构成成员关系:
//   FUN_006e97f0(1162B,0022:13994) —— 分类树数据面(13 项)
//   FUN_006e9cd8(1520B,0022:14175) —— 分类树装配(settings_category_tree_create)
//   FUN_0070bb32(836B,0022:35463)  —— settings_buildRadioGroup(3 项)
// 三个函数在语料中均无直接调用者记录 → 宿主类未定,先以自由函数形态保留。
struct SettingsFace {
	// S2 数据面:FUN_006e97f0 递归语义(外层单容器 13 项;0x101 role)。
	static QStandardItem *categoryDataRoot();

	// FUN_006e9cd8(1520B)分类树:语料面+模型+数据装配+expandAll+选中行 0。
	// 宿主持有返回值;深构建域 cited。
	static QTreeView *categoryTreeDataFace(QWidget *host);

	// FUN_0070bb32(836B)三选一组:语料 3 元素表(int id + text + toolTip)。
	static QButtonGroup *buildRadioGroup(QWidget *parent);
};
