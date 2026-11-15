#pragma once

#include <QString>
#include <QStringList>
#include <QWidget>

class QAbstractButton;
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
class SettingsPageFace : public QWidget {
	Q_OBJECT
public:
	explicit SettingsPageFace(QWidget *parent = nullptr) : QWidget(parent) {}

	// FUN_0072d1e4(112B,0022.c:53854)按名查行:
	//   行表(+0xb8)逐行(步长 0x48)取首字段 QString 与 name 比对,
	//   命中 → 行索引;未命中 → -1。
	//   本面以 QStringList 承载"名面"(行内其余 0x40 字节字段 cited)。
	int rowIndexByName(const QString &name) const;

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
	QListWidget *m_listB0 = nullptr;     // +0xb0
	QStringList m_rowNamesB8;            // +0xb8 行表名面(行节点 0x48 字节)
};
