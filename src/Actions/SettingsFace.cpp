#include "SettingsFace.h"

#include <QAbstractItemModel>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QFrame>
#include <QGroupBox>
#include <QIcon>
#include <QLineEdit>
#include <QPushButton>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QTimer>
#include <QTreeView>
#include <QVariantList>
#include <QVBoxLayout>
#include <functional>

// 语料锚:见 SettingsFace.h 头注(逐段地址/字面/出处;铁律 1)。
// 结构面照汇编序列;深类域(cited)空缺不猜(铁律 3)。

// === S1 FUN_006f1036(175B,0022:18703;汇编 006f1036-006f10ce)===
SettingsFace::SettingsFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags())   // QDialog(param_2,0)@006f1043
{
	setWindowTitle(tr("Text Mark"));           // tr 0xc9faaa @006f106d-89
	setAttribute(Qt::WA_DeleteOnClose, true);  // (0x37,1)@006f10b1
	searchPageBuildLayout();                   // @006f10b9
	// options_connectSignals @006f10c1 → cited:006edc90(0022:16933)
}

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

// === S3 FUN_006f09ba(1498B,0022:18501;汇编 006f09ba-006f0ea4)===
void SettingsFace::searchPageBuildLayout()
{
	QVBoxLayout *vbox = new QVBoxLayout;                       // @006f09db
	QFormLayout *form1 = new QFormLayout;                      // @006f09f4
	QFormLayout *form2 = new QFormLayout;                      // @006f0a0b
	QGroupBox *gMatch = new QGroupBox(tr("Match"));            // 0xc9dfcb@006f0a3b
	QGroupBox *gStyle = new QGroupBox(tr("Style"));            // 0xd0c6c2@006f0a85

	// +0x38 TriggerActionEditPanel(0xe000 字面@006f0ad3)→ 类本体 cited。
	m_panel = new QWidget;
	m_panelField = m_panel;                                    // panel+0x40→+0x40@006f0ae4
	m_pattern = new QLineEdit;                                 // @006f0afe
	m_textColor = new QWidget;   // ColorButton cited@006f0b19
	m_bgColor = new QWidget;     // ColorButton cited@006f0b34
	m_lineColor = new QWidget;   // ColorButton cited@006f0b4f
	// +0x68 searchCombo(FUN_006f088a 271B;FUN_0094e9cc 14 项枚举,
	// data=int(byte@item+8)@006f0906;逐项 0xca0371..0xce8d85):
	m_searchCombo = new QComboBox;
	static const struct { const char *name; int id; } kItems[] = {
		{"None", 0},           // 0xca0371
		{"Solid", 2},          // 0xce8d32
		{"Double", 3},         // 0xce8d38
		{"Thick", 4},          // 0xce8d3f
		{"Strike", 10},        // 0xce8d45
		{"Wavy", 11},          // 0xce8d4c
		{"Dot", 6},            // 0xce8d51
		{"Dash", 7},           // 0xce8d55
		{"Dash dot", 8},       // 0xce8d5a
		{"Dash dot dot", 9},   // 0xce8d63
		{"Box", 15},           // 0xceeac4
		{"Round box", 16},     // 0xce8d70
		{"Dashed box", 17},    // 0xce8d7a
		{"Dotted box", 18},    // 0xce8d85
	};
	for (const auto &it : kItems)
		m_searchCombo->addItem(QIcon(), QLatin1String(it.name), it.id); // @006f0930-45
	// +0x70 preview(FUN_006ee0b8 134B;0055a260 p2=1 类本体 cited;
	// setText "Preview"@006ee0df-0fb):
	m_preview = new QLineEdit;
	m_preview->setText(QStringLiteral("Preview"));
	m_buttons = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel);      // 0x400400@006f0b7f
	m_lineColor->setEnabled(false);                            // @006f0b90-96
	// Ok enable = preview 文本非空(语料 document()->toPlainText() 空
	// 测试@006f0bb0-0x6f0bd3;preview 域 QLineEdit → text() 语义)。
	m_buttons->button(QDialogButtonBox::Ok)->setEnabled(
		!m_preview->text().isEmpty());

	// form1 行(@006f0bf6-0c6b):&Pattern:→panel(语料 R15=+0x38@006f0bf6)、
	// &Description:→+0x48@006f0c42:
	form1->addRow(tr("&Pattern:"), m_panel);
	form1->addRow(tr("&Description:"), m_pattern);
	// form2 行(@006f0c8e-0d93):&Text Color:→+0x50、&Background Color:
	// →+0x58、&Line Style:→+0x68、&Line Color:→+0x60:
	form2->addRow(tr("&Text Color:"), m_textColor);
	form2->addRow(tr("&Background Color:"), m_bgColor);
	form2->addRow(tr("&Line Style:"), m_searchCombo);
	form2->addRow(tr("&Line Color:"), m_lineColor);
	form2->addRow(m_preview);                                  // addRow(QWidget)@006f0dbd
	gMatch->setLayout(form1);                                  // @006f0dcf(RSP+0x8)
	gStyle->setLayout(form2);                                  // @006f0dcc(RSP+0x10)
	vbox->addWidget(gMatch);                                   // @006f0dee
	vbox->addWidget(gStyle);                                   // @006f0dfd
	vbox->addWidget(m_buttons);                                // +0x30@006f0e0a
	setLayout(vbox);                                           // @006f0e18
	QWidget::setTabOrder(m_panelField, m_pattern);             // @006f0e1d(+0x40,+0x48)
	QWidget::setTabOrder(m_pattern, m_textColor);              // @006f0e32
	QWidget::setTabOrder(m_textColor, m_bgColor);              // @006f0e3f
	QWidget::setTabOrder(m_bgColor, m_searchCombo);            // (+0x58,+0x68)@006f0e44
	QWidget::setTabOrder(m_searchCombo, m_lineColor);          // (+0x68,+0x60)@006f0e4c
	// singleShot(0,this,FUN_006edad0):闭包体 setFocus(+0x40,3)@006edad0-0x6f0e87:
	QTimer::singleShot(0, this, [this]() {
		if (m_panelField)
			m_panelField->setFocus(Qt::BacktabFocusReason);    // 3@006edad8
	});
	// FUN_0075c132(app,0.0,0.0,this)@006f0e8c-0x6f0e9f:实参 (0,0) →
	// width/height 分支均 JBE 跳过(@0075c160/@0075c189),仅
	// setSizeGripEnabled(1)@0075c1a3:
	setSizeGripEnabled(true);
}
