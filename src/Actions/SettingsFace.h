#pragma once

#include <QDialog>

class QButtonGroup;
class QComboBox;
class QDialogButtonBox;
class QLineEdit;
class QStandardItem;
class QTreeView;
class QWidget;

// === SettingsFace — 设置页族语料面(批 191,M24-③;⑤ 设置页族,GUI-MAP.md)===
// 铁律 6:全语料转写,零自研行为。三段(出处=decomp-part-0022.c 行号+汇编):
//   S1 TextMarkDialog 壳 ctor FUN_006f1036(175B,0022:18703;汇编
//      006f1036-006f10ce 全读):QDialog(param_2,0)@006f1043 → setWindowTitle
//      (tr "Text Mark"@0xc9faaa)@006f1089 → setAttribute(0x37=
//      WA_DeleteOnClose,1)@006f10b1 → search_page_build_layout@006f10b9 →
//      options_connectSignals@006f10c1(cited:006edc90 八路 connect 依赖
//      ColorButton/panel 自有信号面,未建模不落)。
//   S2 settings_category_tree_create 006e9cd8(1520B,0022:14175)数据面:
//      s_TreeView_58c362(p2=1,p3=1,0018:4344)语料面(NoFrame/editTriggers 0/
//      ExpandsOnDoubleClick 0/frameStyle 0x36/SingleSelection/objectName
//      "TreeView")+ QStandardItemModel + FUN_006e97f0(1162B,0022:13994)
//      递归装配:type-10 行(tr 名 + setData(name,0x101)@006e996f)、type-9
//      嵌套容器;数据项集出自汇编 LEA 序列(006e9daa-006e9fb2):
//      外层单 QVariant 包 [13 项] = 8 分类名 + 3 容器(AC/CH/MT、
//      Binary..Wrap×7、Filer/QuickBar)+ "Text"/"Widgets";外层 prepend
//      (@006ea290/00544fc0 双路)。域过滤(Editor/Terminal 域名哈希剔除,
//      FUN_006ec73a + _display 门控 X Server/Extensions)属 dialog 域名
//      分支 → cited,本面全量。FUN_0058c856(model,0)+expandAll@
//      006ea117-120;blockSignals+setCurrentIndex(index(0,0))+select
//      0x12@006ea1b7-232;currentChanged→FUN_006ebcc6(panes_switchToWidget
//      006eb952 域)→ cited;深 QTreeWidget 构建域(委托/动画 0058a3f6/
//      0058c152/0058c20c)→ cited 空缺,不猜。
//   S3 search_page_build_layout 006f09ba(1498B,0022:18501;汇编
//      006f09ba-006f0ea4)布局面:QVBoxLayout→QFormLayout×2→QGroupBox
//      tr"Match"(0xc9dfcb)/tr"Style"(0xd0c6c2)→ TriggerActionEditPanel
//      (0xe000 字面,0056376e)→+0x38、QLineEdit→+0x48、ColorButton×3
//      (0053904e)→+0x50/+0x58/+0x60、searchCombo(FUN_006f088a 271B,
//      FUN_0094e9cc 14 项枚举+byte data)→+0x68、preview(0055a260,
//      setText "Preview"@0xd0e5bf)→+0x70、QDialogButtonBox(0x400400=
//      Ok|Cancel)→+0x30;线色钮 setEnabled(false)@006f0b90;Ok enable=
//      preview 文本非空@006f0bc0-0x6f0bd3;form1 行:"&Pattern:"(0xc9dfd1)
//      →panel、"&Description:"(0xc9dfdb)→+0x48(@006f0bf6-0c6b);form2 行:
//      "&Text Color:"/"&Background Color:"/"&Line Style:"/"&Line Color:"
//      (0xc9fa70..0xc9fa9d)→+0x50/+0x58/+0x68/+0x60 + addRow(preview)
//      @006f0dbd;setLayout 序/addWidget×3/tabOrder 链(+0x40→+0x48→+0x50→
//      +0x58→+0x68→+0x60)@006f0dcc-0e59;singleShot(0,this,FUN_006edad0:
//      setFocus(+0x40,3))@006f0e5e-87;FUN_0075c132(145B,0023:25826)以
//      (0,0) 调用 → 最小宽高分支跳过(JBE@0075c160/0x75c189),仅
//      setSizeGripEnabled(1)@0075c1a3。深控件类本体(ColorButton/
//      FontPreviewWidget/TriggerActionEditPanel)与信号腿(cited)。
class SettingsFace : public QDialog {
	Q_OBJECT
public:
	// FUN_006f1036(175B)壳真身:S1 装配序。
	explicit SettingsFace(QWidget *parent = nullptr);

	// 语料:3 元素表(每项 0x18 字节 = int id + QString text + QString
	//   工具提示),id/串出自 asm 立即数+.rodata 实读(见 .cpp)。
	static QButtonGroup *buildRadioGroup(QWidget *parent);

	// S2 数据面:FUN_006e97f0 递归语义(外层单容器 13 项;0x101 role)。
	static QStandardItem *categoryDataRoot();

	// FUN_006e9cd8(1520B)分类树:语料面+模型+数据装配+expandAll+选中行 0。
	// 宿主持有返回值;深构建域 cited。
	static QTreeView *categoryTreeDataFace(QWidget *host);

	// S3:FUN_006f09ba(1498B)布局结构面真身。
	void searchPageBuildLayout();

private:
	QDialogButtonBox *m_buttons = nullptr; // +0x30(0x400400 Ok|Cancel)
	QWidget *m_panel = nullptr;            // +0x38 TriggerActionEditPanel(cited 壳)
	QWidget *m_panelField = nullptr;       // +0x40(panel+0x40 转发)
	QLineEdit *m_pattern = nullptr;        // +0x48
	QWidget *m_textColor = nullptr;        // +0x50 ColorButton(cited)
	QWidget *m_bgColor = nullptr;          // +0x58 ColorButton(cited)
	QWidget *m_lineColor = nullptr;        // +0x60 ColorButton(cited)
	QComboBox *m_searchCombo = nullptr;    // +0x68
	QLineEdit *m_preview = nullptr;        // +0x70 FontPreviewWidget(cited 壳)
};
