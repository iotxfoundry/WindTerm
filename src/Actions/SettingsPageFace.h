#pragma once

#include <QDialog>
#include <QString>
#include <QStringList>

class QAbstractButton;
class QDialogButtonBox;
class QListWidgetItem;
class QModelIndex;
class QStandardItem;
class QComboBox;
class QLabel;
class QLineEdit;
class QListWidget;
class QSpinBox;

// SettingsPageFace — 语料"设置行页面"类的字段面(批 246)。
// 证据来源(≥2 独立函数一致):
//   FUN_0072d0f2(242B,0022.c:53821)reset 腿:
//     +0x50 QLineEdit / +0x58 QComboBox / +0x48 QComboBox /
//     +0x70 QSpinBox / +0x60 QLineEdit / +0x68 QSpinBox /
//     +0x38,+0x40 QAbstractButton(勾选)/ +0x98 子件(FUN_0056672a 重置)/
//     +0x30 QLabel(clear)。
//   FUN_0072e4f6(932B,0022.c:54715)loadWidgets 腿:同组槽 + +0xb8 行表。
//   FUN_0072d1e4(112B):+0xb8 行表(0x48 字节/行,首字段 QString 名)线性查。
//   FUN_0072d254(160B):+0xb0 QListWidget 当前项 data(0x101)→ 行索引。
// 注:字段偏移 = 语料直读;本类不复制偏移布局(仅字段族对位)。
//
// SettingsRow — 语料行节点(0x48 字节,批 256 asm 逐字段实证):
//   +0x00 QString 名(0072d1e4 比对;item data(0x101))
//   +0x08 QString 组合框键(combo48 findData,UserRole)
//   +0x10 QString edit50 文本(as `lea 0x10(%rbp)` 实证)
//   +0x18 int(combo58 findData 键;== 1 分支判据)
//   +0x20 4 项子件值(FUN_0056647e(count=4)消费)
//   +0x2c byte → check38/+0x2d byte → check40(`movzbl 0x2c(%rbp)`)
//   +0x30 uint flags((flags<=1) 与 ((flags & ~2)==0) 两腿)
//   +0x34 u16 → spin70 / +0x36 u16 → spin68(`movzwl 0x34/0x36(%rbp)`)
//   +0x38 QString edit60 文本(else 腿 `lea 0x38(%rbp)`)
struct SettingsRow {
	QString name;        // +0x00
	QString comboKey;    // +0x08
	QString edit50Text;  // +0x10
	int kind = 0;        // +0x18
	QStringList childValues; // +0x20(4 项)
	quint8 check38 = 0;  // +0x2c
	quint8 check40 = 0;  // +0x2d
	quint32 flags = 0;   // +0x30
	quint16 spin70 = 0;  // +0x34
	quint16 spin68 = 0;  // +0x36
	QString edit60Text;  // +0x38
};

// loadWidgets 入参面(调用方 item 引用:{int,int,int,QStandardItem*})
struct SettingsItemRef {
	int first = -1;
	int second = -1;
	int pad = 0;
	const QStandardItem *item = nullptr;
};
class SettingsPageFace : public QDialog { // 语料:连接 accept/reject → QDialog
	Q_OBJECT
public:
	explicit SettingsPageFace(QWidget *parent = nullptr) : QDialog(parent) {}

	// FUN_0072d1e4(112B,0022.c:53854)按名查行:
	//   行表(+0xb8)逐行(步长 0x48)取首字段 QString 与 name 比对,
	//   命中 → 行索引;未命中 → -1。
	//   本面以 QStringList 承载"名面"(行内其余 0x40 字节字段 cited)。
	int rowIndexByName(const QString &name) const;

	// FUN_0072bf8a(219B,0022.c:53246)行 → 列表项:
	//   new QListWidgetItem(row.name)(0x30 字节)→ icon =
	//   s_king__tunnelDynamicActive_6a2c16(row)(按行态取图,cited)→
	//   setData(1=DecorationRole, icon)/setData(3, name)/setData(0x101, name)。
	static QListWidgetItem *rowListItem(const SettingsRow &row);

	// FUN_0072eb15(720B,0022.c:54947)kind 组合框变化腿:
	//   kind = currentData()(语料经 QMetaType::registerNormalizedType
	//     动态注册的 4 字节类型取面,等价 toInt)→ edit60->setText(
	//     kind == 1 ? tr("Any")(0xc9d355) : 空串)→ 使能/数值两腿
	//     Ghidra 折叠 → cited → 尾 refreshRows(-1)。
	void onKindComboChanged();

	// FUN_0072dd12(1872B)行表重建(被 0072e49a/0072e4c8 以 -1 调用;
	//   体未转写 → cited 空实现,保留签名)。
	void refreshRows(int index);
	// FUN_0072dd12(1872B)回写段(@0072df57-0x72e116):把当前控件值写回
	//   行节点(kind/组合框 data/两 spin/两 edit/flags/勾选两位)+ FUN_0072d84e
	//   (cited)+ item 名与图标刷新 + FUN_0056642a/FUN_0072d304(cited)。
	//   index 为 -1 时取列表当前行。
	void commitCurrentRow(int index);

	// FUN_0072bbe2(935B,0022.c:53137)设置对话框八路接线真身:
	//   +0x78 QDialogButtonBox accepted/rejected → this accept/reject
	//     (字符串形 "2accepted()"/"1accept()");
	//   +0xa8 两路自定义信号(FUN_008ef798/FUN_008ef7fc,smeta 01193440)
	//     → FUN_0072db3c/FUN_0072e8d2(cited);
	//   +0x50 QLineEdit::textEdited → FUN_0072e49a(= refreshRows(-1));
	//   +0x98 信号(FUN_008faeac)→ FUN_0072e4c8(= refreshRows(-1));
	//   +0x58 QComboBox::currentIndexChanged → FUN_0072eb15(cited 720B);
	//   +0xb0 selectionModel currentChanged → settings_loadWidgets(行装载)。
	void connectSignals();

	// FUN_0072e4f6(932B,0022.c:54715)行装载真身:
	//   alt 有效 → FUN_0072dd12(this)(1872B cited);
	//   item 坐标无效 → resetRow(false),否则 resetRow(item 非空);
	//   坐标仍无效/项空 → 返;
	//   name = item->data(0x101).toString();idx = rowIndexByName;
	//   idx == -1 → resetRow(false);否则逐控件装载(见 .cpp 逐地址)。
	void loadWidgets(const SettingsItemRef &item, const SettingsItemRef &alt);

	// FUN_0072d254(160B,0022.c:53900)当前列表项 → 行索引:
	//   item = QListWidget::item(+0xb0,当前行);空 → -1;
	//   text = item->data(0x101).toString();→ rowIndexByName(text)。
	int currentListRowIndex() const;

	// FUN_0072d0f2(242B,0022.c:53821)整行复位/使能:
	//   !enable → 逐控件清零(edit.clear / combo.setCurrentIndex(0) /
	//   spin.setValue(0) / check.setChecked(false) / +0x98 子件重置
	//   FUN_0056672a(w,0,0,0) cited / label.clear);
	//   然后按 enable 逐控件 setEnabled(实参同值)。
	//   注:各清零调用的实参 Ghidra 丢/折叠,按清零语义 0/false 落并注记。
	void resetRow(bool enable);

	// 语料字段族(供后续 loadWidgets/reset 腿使用)
	QLabel *m_label30 = nullptr;         // +0x30
	QAbstractButton *m_check38 = nullptr; // +0x38
	QAbstractButton *m_check40 = nullptr; // +0x40
	QComboBox *m_combo48 = nullptr;      // +0x48
	QLineEdit *m_edit50 = nullptr;       // +0x50
	QComboBox *m_combo58 = nullptr;      // +0x58
	QLineEdit *m_edit60 = nullptr;       // +0x60
	QSpinBox *m_spin68 = nullptr;        // +0x68
	QSpinBox *m_spin70 = nullptr;        // +0x70
	QWidget *m_widget98 = nullptr;       // +0x98(FUN_0056672a 消费)
	QDialogButtonBox *m_buttons78 = nullptr; // +0x78(accept/reject 面)
	QWidget *m_widgetA8 = nullptr;       // +0xa8(自定义信号宿主,cited 类)
	QListWidget *m_listB0 = nullptr;     // +0xb0
	QList<SettingsRow> m_rowsB8;         // +0xb8 行表(0x48 字节/行)
	// 行节点(0x48 字节)字段证据(待建模,批 246 记录):
	//   +0x00 QString 名(0072d1e4 比对字段)
	//   +0x08 QVariant/值(0072e4f6 组合框 findData 取此行字段)
	//   +0x18 int(0072e4f6:== 1 分支 + 组合框 findData(int) 键)
	//   +0x20 子件值区(FUN_0056647e(+0x98, row+0x20, 4))
	//   → 建模前 loadWidgets(932B)保持未落。
};
