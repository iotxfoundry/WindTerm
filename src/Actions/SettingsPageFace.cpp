// SettingsPageFace.cpp — 设置行页面两索引腿(批 246)
#include "SettingsPageFace.h"

#include <QAbstractButton>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QSpinBox>
#include <QListWidgetItem>

// FUN_0072d1e4(112B,0022.c:53854)按名查行真身:
//   lVar3 = *(this+0xb8)(行表);iVar1 = 元素数(+4 槽);
//   逐 i:operator==(行首 QString(行基址 + i*0x48 + 数组偏移), name)
//   命中 → i;走到末位仍未命中 → 0xffffffff(-1)。
int SettingsPageFace::rowIndexByName(const QString &name) const
{
	const int n = m_rowNamesB8.size(); // 行表元素数
	for (int i = 0; i < n; ++i) {
		if (m_rowNamesB8.at(i) == name) // 行首 QString 比对 @0072d1e4
			return i;
	}
	return -1; // 0xffffffff
}

// FUN_0072d254(160B,0022.c:53900)当前列表项 → 行索引真身:
//   item = QListWidget::item(this+0xb0, 当前行)(实参 Ghidra 丢,按
//     QListWidget::currentRow() 同相);空 → -1;
//   text = item->data(0x101).toString()(vtable+0x20 = QListWidgetItem::data)
//   → rowIndexByName(text)。
int SettingsPageFace::currentListRowIndex() const
{
	if (m_listB0 == nullptr)
		return -1;
	QListWidgetItem *item = m_listB0->item(m_listB0->currentRow()); // @0072d254
	if (item == nullptr)
		return -1;
	const QString text = item->data(0x101).toString(); // @0072d284
	return rowIndexByName(text);                       // @0072d2a4
}

// FUN_0072d0f2(242B,0022.c:53821)复位/使能真身:
//   @0072d0f2 uVar1 = *(byte*)(this+0x50);
//   if (!enable) { QLineEdit::clear@0072d0f2;QComboBox::setCurrentIndex(+0x58/
//     +0x48)@0072d10x;QSpinBox::setValue(+0x70/+0x68)@0072d12x;
//     QAbstractButton::setChecked(+0x38/+0x40)@0072d15x;
//     FUN_0056672a(+0x98,0,0,0)(cited);QLabel::clear@0072d1bx }
//   then QWidget::setEnabled 逐个(+0x50/+0x58/+0x48/+0x70/+0x60/+0x68/
//     +0x38/+0x40)@0072d1cx-1fx(实参 = 上面读出的 uVar1 同值)。
void SettingsPageFace::resetRow(bool enable)
{
	if (!enable) {
		if (m_edit50 != nullptr)
			m_edit50->clear(); // @0072d0f2
		if (m_combo58 != nullptr)
			m_combo58->setCurrentIndex(0); // 实参丢,按清零
		if (m_combo48 != nullptr)
			m_combo48->setCurrentIndex(0);
		if (m_spin70 != nullptr)
			m_spin70->setValue(0);
		if (m_edit60 != nullptr)
			m_edit60->clear();
		if (m_spin68 != nullptr)
			m_spin68->setValue(0);
		if (m_check38 != nullptr)
			m_check38->setChecked(false);
		if (m_check40 != nullptr)
			m_check40->setChecked(false);
		// FUN_0056672a(m_widget98,0,0,0)@0072d1bx — cited(子件重置体未转写)
		if (m_label30 != nullptr)
			m_label30->clear();
	}
	// setEnabled 组(实参 = enable 同值)@0072d1cx-1fx
	const QList<QWidget *> group = {
	    m_edit50, m_combo58, m_combo48, m_spin70,
	    m_edit60, m_spin68,  m_check38, m_check40};
	for (QWidget *w : group) {
		if (w != nullptr)
			w->setEnabled(enable);
	}
}
