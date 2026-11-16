// SettingsFace.cpp — 设置页族工具函数(伞形,非原版类;见头注)
#include "Widgets/Settings/SettingsFace.h"

#include <QAbstractItemModel>
#include <QButtonGroup>
#include <QFrame>
#include <QItemSelectionModel>
#include <QObject>
#include <QRadioButton>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QTimer>
#include <QTreeView>
#include <QVariantList>
#include <functional>

// === S2 数据面 FUN_006e97f0(1162B,0022:13994;汇编 006e97f0-006e9cc7)===
// 外层单容器 13 项(@006ea018-006ea06a:prepend 到 invisibleRoot 下,
// 项序=汇编 LEA 序),type-10 行 setData(name,0x101),type-9 嵌套。
QStandardItem *SettingsFace::categoryDataRoot()
{
	// 逐串出处(汇编 LEA RSI 序列 006e9daa-006e9fb2):
	const char *items[] = {
		"Application",       // 0xca04b0 @006e9daa
		"Appearance",        // 0xc9e6a1 @006e9dc2
		"Editor",            // 0xc9d4e3 @006e9dd7
		"Proxy",             // 0xc9f059 @006e9dec
		"Search",            // 0xc9f05f @006e9e01
		"Security",          // 0xc9f01f @006e9e16
		"Tabs",              // 0xc9f066 @006e9e2b
		"Terminal",          // 0xcb9e4d @006e9e40
		"Auto Completion",   // 0xc9f028 @006e9e59 (list1)
		"Command History",   // 0xc9e53c @006e9e71
		"Mouse Tracking",    // 0xc9f038 @006e9e86
		"Text",              // 0xc9fb6a @006e9ec7
		"Binary",            // 0xc9e8da @006e9edb (list2)
		"Caret",             // 0xca1ad3 @006e9eee
		"Font",              // 0xc9e93e @006e9efe
		"Highlight",         // 0xc9e9c2 @006e9f0e
		"Indentation",       // 0xd0c7d1 @006e9f1e
		"Line Ending",       // 0xc9eaf2 @006e9f2e
		"Wrap",              // 0xca2317 @006e9f3e
		"Widgets",           // 0xc9f047 @006e9f7f (list3)
		"Filer",             // 0xc89afa @006e9f98
		"Quick Bar",         // 0xc9f04f @006e9fab
	};

	const auto str = [](const char *s) { return QVariant(QString::fromUtf8(s)); };
	// 嵌套容器序(汇编 006e9e9e-006ea013):
	QVariantList list1{str(items[8]), str(items[9]), str(items[10])};
	QVariantList list2{str(items[13]), str(items[14]), str(items[15]),
		str(items[16]), str(items[17]), str(items[18])};
	// list2 @RBP+0x10..0x60:Caret,Font,Highlight,Indentation,LineEnding,Wrap
	list2.insert(0, str(items[12]));   // "Binary"@006e9edb 为 list2 首项(RBP+0)
	QVariantList list3{str(items[20]), str(items[21])};   // Filer,Quick Bar
	QVariantList outer{                    // 006e9e9e-006ea013 打包序
		str(items[1]),                     // Appearance+list1@006e9e9e
		list1,
		str(items[11]),                    // Text@006e9ec0
		list2,
		str(items[19]),                    // Widgets@006e9f78
		list3,
	};
	QVariantList root;
	root.append(QVariant(outer));          // 单项容器@006ea018-006ea06a
	for (int i = 0; i <= 7; ++i)           // 8 分类名@006ea037-006ea06a
		root.append(str(items[i]));
	// 注:语料外层 = [Appearance+list1, Text+list2, Widgets+list3,
	// Application…Terminal](006e9ffb qlist_fill 打包;单项包 prepend)。

	QStandardItem *rootItem = new QStandardItem;
	// FUN_006e97f0 递归(data==9 容器 → 子级;data==10 → tr 行 + 0x101 role):
	std::function<void(QStandardItem *, const QVariantList &)> fill =
		[&fill](QStandardItem *parent, const QVariantList &rows) {
			for (const QVariant &v : rows) {
				if (v.type() == QVariant::List) {              // ==9 @006e987f
					QStandardItem *child = new QStandardItem;
					fill(child, v.toList());                   // @006e99e9-0a01
					parent->appendRow(child);
				} else if (v.type() == QVariant::String) {     // ==10 @006e987a
					QStandardItem *child = new QStandardItem(v.toString());
					child->setData(v.toString(), 0x101);       // @006e996f EDX=0x101
					parent->appendRow(child);                  // @006e9992-9cd
				}
			}
		};
	fill(rootItem, root);
	return rootItem;
}

// === S2 FUN_006e9cd8(1520B,0022:14175;汇编 006e9cd8-006ea294)===
QTreeView *SettingsFace::categoryTreeDataFace(QWidget *host)
{
	// s_TreeView_58c362(p2=1,p3=1)语料面(0018:4344;@006e9cf9 调用):
	QTreeView *tree = new QTreeView(host);
	tree->setObjectName(QStringLiteral("TreeView"));            // @0058c431
	tree->setFrameShape(QFrame::NoFrame);                       // (0)@006e9d2b
	tree->setEditTriggers(QAbstractItemView::NoEditTriggers);   // (0)@006e9d35
	tree->setExpandsOnDoubleClick(false);                       // @006e9d42
	tree->setFrameStyle(0x36);                                  // 字面@006e9d4b
	tree->setSelectionMode(QAbstractItemView::SingleSelection); // (1)@006e9d5c
	// CategoryTree 换绑/深构建域(0058a3f6/0058c152/0058c20c)→ cited。
	QStandardItemModel *model = new QStandardItemModel(tree);   // @006e9d7f
	QStandardItem *root = model->invisibleRootItem();           // @006e9d87
	QStandardItem *data = categoryDataRoot();                   // FUN_006e97f0@006ea107
	while (data->rowCount())
		root->appendRow(data->takeChild(0));
	delete data;
	tree->setModel(model);                                      // 0058c856(model,0)@006ea117
	tree->expandAll();                                          // @006ea120
	// currentChanged→FUN_006ebcc6(panes_switchToWidget 域)→ cited。
	if (tree->selectionModel()) {
		const bool blocked = tree->selectionModel()->blockSignals(true); // @006ea1b7
		const QModelIndex idx = tree->model()->index(0, 0);              // @006ea1e7-232
		tree->selectionModel()->setCurrentIndex(idx,
			QItemSelectionModel::SelectionFlags(0x12));                  // 语料字面 0x12@006ea227
		tree->selectionModel()->blockSignals(blocked);
	}
	// stack currentWidget CategoryPage setFocus(7)@006ea235-26e → cited
	// (m_stack 未建模,006ea37a 域)。
	return tree;
}

// settings_buildRadioGroup — FUN_0070bb32(836B,0022.c:35463)真身:
//   QButtonGroup(0x10 字节)@0070bb55(父 = 实参指针 *param_1)+ 3 元素静态表
//   (每项 0x18 字节:int id + QString text + QString toolTip,
//    asm 立即数 0 / 8 / 0x7f @0070bb6a/0070bb83/0070bb95)+ 循环:
//   QRadioButton(0x30 字节,text,父)@0070bdd7 → setToolTip @0070bde3 →
//   addButton(btn, id)@0070bdf4。三串 .rodata 实读:
//     0xca04fa "&Automatic" / 0xca04fb "Automatic"
//     0xca0505 "&Backspace" / 0xca0510 "Ctrl+H (Ascii 0x08)"
//     0xca0524 "&Delete"    / 0xca052c "Ctrl+? (Ascii 0x7F)"
//   tr 上下文语料 = metaobject 011a2240(cited:本类上下文 ≠ 该 metabo,
//   无翻译资源时同相;字符串本体已实读,不发明)。
QButtonGroup *SettingsFace::buildRadioGroup(QWidget *parent)
{
	struct Entry {
		int id;
		const char *text;
		const char *toolTip;
	};
	static const Entry entries[] = {
	    {0, "&Automatic", "Automatic"},                    // @0xca04fa/0xca04fb
	    {8, "&Backspace", "Ctrl+H (Ascii 0x08)"},          // @0xca0505/0xca0510
	    {0x7f, "&Delete", "Ctrl+? (Ascii 0x7F)"},          // @0xca0524/0xca052c
	};
	QButtonGroup *group = new QButtonGroup(parent);         // @0070bb55
	for (const Entry &e : entries) {
		QRadioButton *btn = new QRadioButton(QObject::tr(e.text), parent); // @0070bdd7
		btn->setToolTip(QObject::tr(e.toolTip));                     // @0070bde3
		group->addButton(btn, e.id);                        // @0070bdf4
	}
	return group;                                           // @0070be4a
}
