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
QVariant ExpectDialogFace::collectRows(QTableWidget *table, int col)
{
	QMap<QString, QVariant> out;                 // local_80(QMap shared_null)
	if (table == nullptr)
		return QVariant(out);

	const int rows = table->rowCount();           // @006bfb8c
	for (int i = 0; i < rows; ++i) {
		QTableWidgetItem *it = table->item(col, i); // @006bfdbb
		const QString v = (it == nullptr)
			? QString()
			: it->data(Qt::UserRole).toString();   // data(0x100)
		if (v.isEmpty())                           // +4 == 0 → 跳过
			continue;
		// key = FUN_006bdd62(col, i, 0, 0).toLower() — cited(列取面)
		const QString key = QString();             // 占位:取面未转写 ⇒ 不写键
		if (key.isEmpty())
			continue;                              // 不发明键(铁律 3)
		out.insert(QStringLiteral("%1.path").arg(key), QVariant(v)); // @006bfcd0
		// out.insert(QStringLiteral("%1.pass").arg(key), …)@006bfdxx
		//   — 值取 FUN_006bdd62(col, i, 0, 0x100),cited
	}
	return QVariant(out);                          // @006bfdxx
}
