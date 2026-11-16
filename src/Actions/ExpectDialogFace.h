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
	// 单表收集:col 固定,逐行取 0x100 角色值;空值行跳过。
	static QVariant collectRows(QTableWidget *table, int col);
};
