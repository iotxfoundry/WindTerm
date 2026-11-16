// ExpectDialogFace.cpp — expect 对话框数据面(批 357)
#include "ExpectDialogFace.h"

#include <QTableWidget>
#include <QTableWidgetItem>

// expectDialog_collectRows(984B,0021.c:...)真身(主表分支):
//   @006bfb8c rows = table->rowCount();
//   @006bfcxx 逐行:item(列, i);空 → 空串;否则 item->data(0x100).toString();
//   @006bfc85 v 非空 → key = FUN_006bdd62(列, i, 0, 0).toLower()(cited);
//   @006bfcd0 map["%1.path".arg(key)] = v(键模板实读);
//   @006bfdxx map["%1.pass".arg(key)] = FUN_006bdd62(列, i, 0, 0x100)(键模板实读);
//   @006bfdxx return QVariant(map)。
//   副表分支(+0xb0 != col)结构同型,键面 cited。
// FUN_006bdd62(102B)单元格取文本真身
QString ExpectDialogFace::cellText(QTableWidget *table, int row, int col, int role)
{
	if (table == nullptr)
		return QString();
	QTableWidgetItem *it = table->item(row, col);   // @006bdd62
	if (it == nullptr)
		return QString();                            // *param_1 = shared_null
	return it->data(role).toString();                // vt+0x18(item->data)
}

QVariant ExpectDialogFace::collectRows(QTableWidget *table, int fixedRow)
{
	QMap<QString, QVariant> out;                 // local_80(QMap shared_null)
	if (table == nullptr)
		return QVariant(out);

	const int cols = table->columnCount();        // @006bfb8c(遍历列)
	for (int i = 0; i < cols; ++i) {
		const QString v = cellText(table, fixedRow, i, Qt::UserRole); // data(0x100)
		if (v.isEmpty())                           // +4 == 0 → 跳过
			continue;
		const QString key = cellText(table, fixedRow, i, Qt::DisplayRole).toLower(); // @006bfc85
		if (key.isEmpty())
			continue;                              // 无键 → 不入表
		out.insert(QStringLiteral("%1.path").arg(key), QVariant(v)); // @006bfcd0
		out.insert(QStringLiteral("%1.pass").arg(key),
		           QVariant(cellText(table, fixedRow, i, Qt::UserRole))); // @006bfdxx
	}
	return QVariant(out);                          // @006bfdxx
}

// expectDialog_saveRows(997B)映射 → 表回填真身(结构段)
void ExpectDialogFace::saveRows(QTableWidget *table, int col, const QVariantMap &map)
{
	if (table == nullptr)
		return;
	// 主表腿:逐行由已有单元格文本 toLower 组键,再到映射取值
	const int rows = table->rowCount();               // @006bfxxx
	for (int i = 0; i < rows; ++i) {
		QTableWidgetItem *it = table->item(col, i);
		if (it == nullptr)
			continue;
		const QString key = QStringLiteral("%1.path")
			.arg(it->data(Qt::DisplayRole).toString().toLower()); // @006bfxxx(arg)
		if (!map.contains(key))
			continue;
		// 命中 → 以映射值重建单元格并 setItem(row, col, item)
		//   (@006bfxxx setItem 实参 Ghidra 折叠)— cited
	}
	// 副表腿:FUN_006c7280(&list, table) 取行源 → setRowCount(n) → 逐格 setItem
	//   — cited
	Q_UNUSED(col);
}
