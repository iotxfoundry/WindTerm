// SettingsPageFace.cpp — 设置行页面两索引腿(批 246)
#include "SettingsPageFace.h"

#include <QListWidget>
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
