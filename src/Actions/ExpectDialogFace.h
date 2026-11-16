#pragma once

#include <QMap>
#include <QString>
#include <QVariant>

class QTableWidget;

// ExpectDialogFace — 语料 expect 对话框(表格 ⇄ 配置映射)的数据面(批 357)。
// 归属:本簇函数以 `expectDialog_*` 命名(Ghidra 符号恢复),宿主为带
//   +0x40 QTableWidget 的对话框;`collectRows`/`saveRows` 成对
//   (表 → QMap 与 表 → 配置)。
//
// expectDialog_collectRows(984B,0021.c:...) 实测:
//   两个表分支(门 = `*(this+0xb0) == param_3`;命中走主表,否则走副表);
//   主表逐行 i(0..rowCount-1):
//     v = item(列, i);空项 → 空串;否则 item->data(0x100).toString();
//     v 非空 →
//       key = FUN_006bdd62(param_3, i, 0, 0).toLower()(列取面,cited);
//       map[ QString("%1.path").arg(key) ] = QVariant(v);
//       map[ QString("%1.pass").arg(key) ] = QVariant(FUN_006bdd62(
//                                             param_3, i, 0, 0x100));
//   返 QVariant(map)。
//   **键模板 "%1.path" / "%1.pass" 为 .rodata 实读**(fromAscii_helper n=7)。
class ExpectDialogFace {
public:
	// FUN_006bdd62(102B,0021.c:50520)单元格取文本:
	//   it = table->item(row, col);空 → 空串;否则 it->data(role).toString()。
	//   ⇒ 即"列取面",先前 cited 处全部可落真。
	static QString cellText(QTableWidget *table, int row, int col, int role);

	// expectDialog_collectRows(984B)**名不副实**:语料 `QTableWidget::item(
	//   iVar3, iVar4)` 的 iVar3 = 传入的固定索引、iVar4 迭代 →
	//   **固定一行、遍历各列**收集(不是"收集多行")。键 = 该格 data(0).toLower()。
	static QVariant collectRows(QTableWidget *table, int fixedRow);

	// expectDialog_saveRows(997B,0021.c:...)表 ⇄ 映射回填(名不副实:
	//   实际方向是"映射 → 表"):
	//   门 `*(this+0xb0) == table`:
	//   主表腿 —— 逐行 i:item(col, i)→data(0).toString().toLower()
	//     → key = "%1.path".arg(该值) → 映射查 → 取 .toString() 组 QVariant
	//     → `QTableWidget::setItem(row, col, item)` 写回(实参 Ghidra 折叠);
	//   副表腿 —— `FUN_006c7280(&list, table)` 取行源 → setRowCount(n) →
	//     逐格 setItem(…)(实参折叠)。
	//   复用 collectRows 的键模板("%1.path"/"%1.pass" 实读)。
	static void saveRows(QTableWidget *table, int col, const QVariantMap &map);
};
