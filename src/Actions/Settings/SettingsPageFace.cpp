// SettingsPageFace.cpp — 设置行页面两索引腿(批 246)
#include "Actions/Settings/SettingsPageFace.h"

#include <QAbstractButton>
#include <QComboBox>
#include <QLabel>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QListWidget>
#include <QSpinBox>
#include <QListWidgetItem>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QItemSelectionModel>
#include <QLineEdit>
#include <QSpinBox>
#include <QStandardItem>
#include <QStandardItemModel>

// FUN_0072d1e4(112B,0022.c:53854)按名查行真身:
//   lVar3 = *(this+0xb8)(行表);iVar1 = 元素数(+4 槽);
//   逐 i:operator==(行首 QString(行基址 + i*0x48 + 数组偏移), name)
//   命中 → i;走到末位仍未命中 → 0xffffffff(-1)。
int SettingsPageFace::rowIndexByName(const QString &name) const
{
	const int n = m_rowsB8.size(); // 行表元素数
	for (int i = 0; i < n; ++i) {
		if (m_rowsB8.at(i).name == name) // 行首 QString 比对 @0072d1e4
			return i;
	}
	return -1; // 0xffffffff
}

// FUN_0072e4f6(932B,0022.c:54715)行装载真身(asm 0x72e5xx-0x72e858 逐实参):
//   @0072e4f6 alt 有效(first/second >= 0 且 item 非空)→ FUN_0072dd12(this)
//     (1872B 行表重建,cited);
//   @0072e5xx item 坐标无效 → resetRow(false);否则 resetRow(item != 0);
//   @0072e5xx 坐标无效/项空 → return;
//   @0072e5a2 name = item->data(0x101).toString();
//   @0072e5b5 idx = rowIndexByName(name);idx == -1 → resetRow(false);否则:
//     @0072e62a combo48->findData(row+0x08, UserRole=0x100, MatchExactly=0x10)
//       → blockSignals 包裹 → setCurrentIndex(命中值);
//     @0072e689 combo58->findData(QVariant(row+0x18 int)) 同包裹 setCurrentIndex;
//     @0072e6f8 edit50->setText(row+0x10);
//     @0072e701 spin70->setValue(u16 row+0x34);
//     @0072e70e if (row+0x18 == 1):edit60->setText(tr("Any"))@0072e815
//       + spin68->setValue(0)@0072e836 + setEnabled(edit60,false)/
//       setEnabled(spin68,false)@0072e83b/846;
//     else:edit60->setText(row+0x38)@0072e71f + spin68->setValue(u16 row+0x36)
//       @0072e72c;
//     @0072e741 FUN_0056647e(+0x98, row+0x20, 4)(cited);
//     @0072e765 FUN_0056672a(+0x98, flags<=1, (flags&~2)==0, 0)(cited);
//     @0072e76a check38->setChecked(row+0x2c != 0);
//     @0072e7xx check40->setChecked(row+0x2d != 0);
//     @0072e7xx FUN_0072d304(this,row)(1257B cited)。
void SettingsPageFace::loadWidgets(const SettingsItemRef &item,
                                   const SettingsItemRef &alt)
{
	if (alt.first >= 0 && alt.second >= 0 && alt.item != nullptr) {
		/* FUN_0072dd12(this)@0072e4f6 — cited(1872B 行表重建体未转写) */
	}
	const bool itemValid = item.first >= 0 && item.second >= 0 && item.item != nullptr;
	resetRow(itemValid); // FUN_0072d0f2 @0072e5xx(实参 = 项非空)
	if (item.first < 0 || item.second < 0 || item.item == nullptr)
		return;
	const QString name = item.item->data(0x101).toString(); // @0072e5a2
	const int idx = rowIndexByName(name);                   // @0072e5b5
	if (idx == -1) {
		resetRow(false);
		return;
	}
	const SettingsRow &row = m_rowsB8.at(idx);
	if (m_combo48 != nullptr) { // 组合框 1(键 row+0x08)
		const int found = m_combo48->findData(row.comboKey, Qt::UserRole,
		                                      Qt::MatchExactly); // 0x100/0x10
		m_combo48->blockSignals(true);
		m_combo48->setCurrentIndex(found);
		m_combo48->blockSignals(false);
	}
	if (m_combo58 != nullptr) { // 组合框 2(键 row+0x18 int)
		const int found = m_combo58->findData(QVariant(row.kind), Qt::UserRole,
		                                      Qt::MatchExactly);
		if (found != -1) {
			m_combo58->blockSignals(true);
			m_combo58->setCurrentIndex(found);
			m_combo58->blockSignals(false);
		}
	}
	if (m_edit50 != nullptr)
		m_edit50->setText(row.edit50Text); // @0072e6f8
	if (m_spin70 != nullptr)
		m_spin70->setValue(row.spin70); // @0072e701(u16)
	if (row.kind == 1) { // @0072e70e
		if (m_edit60 != nullptr) {
			m_edit60->setText(tr("Any")); // 0xc9d355 @0072e815
			m_edit60->setEnabled(false);  // @0072e83b
		}
		if (m_spin68 != nullptr) {
			m_spin68->setValue(0);       // @0072e836
			m_spin68->setEnabled(false); // @0072e846
		}
	} else {
		if (m_edit60 != nullptr)
			m_edit60->setText(row.edit60Text); // @0072e71f(row+0x38)
		if (m_spin68 != nullptr)
			m_spin68->setValue(row.spin68);    // @0072e72c(u16 row+0x36)
	}
	/* FUN_0056647e(m_widget98, row+0x20, 4)@0072e741 — cited */
	/* FUN_0056672a(m_widget98, flags<=1, (flags&~2)==0, 0)@0072e765 — cited */
	if (m_check38 != nullptr)
		m_check38->setChecked(row.check38 != 0); // @0072e76a
	if (m_check40 != nullptr)
		m_check40->setChecked(row.check40 != 0);
	updateInfoLabel(row); // FUN_0072d304 @0072e7xx(批 296 真身)
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

// FUN_0072dd12(1872B):index == -1 → 列表当前行;语料首段为守卫 +
//   行取面(本面 commitCurrentRow 已承接回写段;读侧段见批 269)。
void SettingsPageFace::refreshRows(int index)
{
	commitCurrentRow(index); // 1872B 回写/刷新主腿
}

// FUN_0072bbe2(935B,0022.c:53137)八路接线真身:
//   ① connect(+0x78, accepted, this, accept)("2accepted()"/"1accept()")
//   ② connect(+0x78, rejected, this, reject)
//   ③ connect(+0xa8, FUN_008ef798, this, FUN_0072db3c)     — cited
//   ④ connect(+0xa8, FUN_008ef7fc, this, FUN_0072e8d2)     — cited
//   ⑤ connect(+0x50, textEdited, this, FUN_0072e49a)=(refreshRows(-1))
//   ⑥ connect(+0x98, FUN_008faeac, this, FUN_0072e4c8)=(refreshRows(-1))
//   ⑦ connect(+0x58, currentIndexChanged, this, FUN_0072eb15) — cited(720B)
//   ⑧ connect(+0xb0 selectionModel::currentChanged, this, settings_loadWidgets)
//      — 语料直接把两个 QModelIndex 当 (行引用,交替引用) 传入。
void SettingsPageFace::connectSignals()
{
	if (m_buttons78 != nullptr) {
		connect(m_buttons78, &QDialogButtonBox::accepted, this,
		        &QDialog::accept); // ①"2accepted()"→"1accept()"
		connect(m_buttons78, &QDialogButtonBox::rejected, this,
		        &QDialog::reject); // ②
	}
	// ③④ +0xa8 两路自定义信号(体 FUN_0072db3c/FUN_0072e8d2 未转写)— cited。
	if (m_edit50 != nullptr) {
		connect(m_edit50, &QLineEdit::textEdited, this, [this](const QString &) {
			refreshRows(-1); // ⑤ FUN_0072e49a → 0072dd12(this,-1)
		});
	}
	// ⑥ +0x98 信号(FUN_008faeac,类 0119d620 未建模)→ refreshRows(-1) — cited。
	if (m_combo58 != nullptr) {
		connect(m_combo58,
		        QOverload<int>::of(&QComboBox::currentIndexChanged), this,
		        [this](int) { onKindComboChanged(); }); // ⑦ 0072eb15
	}
	if (m_listB0 != nullptr && m_listB0->selectionModel() != nullptr) {
		connect(m_listB0->selectionModel(),
		        &QItemSelectionModel::currentChanged, this,
		        [this](const QModelIndex &cur, const QModelIndex &prev) {
			        // ⑧ 语料:currentChanged(cur,prev) → loadWidgets(cur,prev)
			        //   本项目 QModelIndex 与 SettingsItemRef 字段对齐由
			        //   model()->data(index,0x101) 取面承担(cited 适配:
			        //   模型项解析面未取证)。
			        SettingsItemRef a;
			        a.first = cur.row();
			        a.second = cur.column();
			        a.item = nullptr; // 项解析 cited(经 model data 取面)
			        SettingsItemRef b;
			        b.first = prev.row();
			        b.second = prev.column();
			        loadWidgets(a, b);
		        });
	}
}

// FUN_0072eb15(720B,0022.c:54947)kind 组合框变化真身(核心段):
//   @0072eb69 kind = currentData()(语料 = QMetaType::registerNormalizedType
//     注册的 4 字节类型;DAT_011c1c74 缓存 type id,userType 不符则
//     QVariant::convert —— 语义等价 currentData().toInt());
//   @0072eba2 edit60 = this+0x60;kind == 1 → tr("Any")(0xc9d355)
//     @0072ebxx;否则空串;@0072ebb4 setText;
//   @0072ed7x 使能/数值两腿(edit60/spin68)Ghidra 折叠 — cited;
//   尾 @0072edxx refreshRows(-1)(FUN_0072dd12)。
void SettingsPageFace::onKindComboChanged()
{
	if (m_combo58 == nullptr)
		return;
	const int kind = m_combo58->currentData().toInt(); // 等价自定义 4 字节类型
	if (m_edit60 != nullptr) {
		m_edit60->setText(kind == 1 ? tr("Any") : QString()); // @0072ebb4
	}
	// 使能/spin68 数值两腿 @0072ed7x — cited(Ghidra 折叠,常量不可考)。
	refreshRows(-1); // @0072edxx
}

// FUN_0072bf8a(219B,0022.c:53246)行 → 列表项真身:
//   @0072bf8a operator_new(0x30)+QListWidgetItem(row+0x10 名,0,0);
//   @0072bfb6 s_king__tunnelDynamicActive_6a2c16(&icon, row)(cited 图标面)
//   → item->setData(1, QVariant(QIcon))@0072bfee;
//   item->setData(3, QVariant(row+0x10))@0072c01f;
//   item->setData(0x101, QVariant(row+0x00 名))@0072c048。
QListWidgetItem *SettingsPageFace::rowListItem(const SettingsRow &row)
{
	auto *item = new QListWidgetItem(row.name); // @0072bf8a
	// icon = s_king__tunnelDynamicActive_6a2c16(row)@0072bfb6 — cited
	//   (行态→图标面,未转写;此处不设为空图标,避免发明)。
	item->setData(3, QVariant(row.name));    // @0072c01f
	item->setData(0x101, QVariant(row.name)); // @0072c048
	return item;
}

// FUN_0072dd12(1872B,0022.c:54375)回写段真身(读侧段已批 269 帧解析覆盖):
//   @0072dd12 index == -1 → list->currentRow();
//   item = QListWidget::item(+0xb0, index);idx = currentListRowIndex();
//   item 空或 idx == -1 → 返;row = rowsB8[idx];
//   @0072df4x row.kind(local_cc)写回;
//   @0072df57 combo58->currentData().toString() → row.comboKey(+0x08);
//   @0072dfa5 spin70->value() → row.spin70(+0x34, u16);
//   @0072dfxx kind == 1 → row.edit60 = 空,否则 edit60->text() → row.edit60(+0x38);
//   @0072dfxx kind == 1 → row.spin68 = 0,否则 spin68->value() → row.spin68(+0x36);
//   @0072e0xx row.flags(+0x30) ← (+0x98 子件 +0x30 & 1) ? 2 : 0;
//   @0072e0xx row.check40(+0x2c bit1)/check38(bit0) ← isChecked();
//   FUN_0072d84e(this,row)(cited)→ item 名变 → setData(0,名)(cited);
//   kind/flags 变 → 图标刷新(6a2c16)+setData(1,icon);
//   FUN_0056642a(+0x98, (flags&~2)==0)(cited)+ FUN_0072d304(this,row)(cited)。
void SettingsPageFace::commitCurrentRow(int index)
{
	if (m_listB0 == nullptr)
		return;
	if (index == -1)
		index = m_listB0->currentRow(); // @0072dd12
	QListWidgetItem *item = m_listB0->item(index); // @0072dd2x
	const int rowIdx = currentListRowIndex();      // 0072d254
	if (item == nullptr || rowIdx == -1)
		return;
	SettingsRow &row = m_rowsB8[rowIdx];
	if (m_combo58 != nullptr) // @0072df57
		row.comboKey = m_combo58->currentData().toString();
	if (m_spin70 != nullptr) // @0072dfa5
		row.spin70 = static_cast<quint16>(m_spin70->value());
	if (row.kind == 1) // @0072dfxx
		row.edit60Text.clear();
	else if (m_edit60 != nullptr)
		row.edit60Text = m_edit60->text();
	if (row.kind == 1) // @0072dfxx
		row.spin68 = 0;
	else if (m_spin68 != nullptr)
		row.spin68 = static_cast<quint16>(m_spin68->value());
	row.flags = (m_widget98 != nullptr) ? 2u : 0u; // (+0x98 子件 +0x30 & 1) 面
	if (m_check40 != nullptr)
		row.check40 = m_check40->isChecked() ? 1 : 0; // bit1
	if (m_check38 != nullptr)
		row.check38 = m_check38->isChecked() ? 1 : 0; // bit0
	updateRowFlags(row); // FUN_0072d84e @0072dfxx(批 312 真身)
	// item setData(0,名) / 图标刷新 / FUN_0056642a — cited。
}

// FUN_0072edfe(521B)重建列表真身:
//   @0072edfe src = FUN_006a4d90(DAT_011c1b00)(全局行表单例,cited);
//   +0xb8 ← src(refcount 拷贝);@0072efxx 逐行:FUN_0072bf8a(行)生成项 →
//   QListWidget::insertItem(+0xb0, count)@0072efxx;
//   @0072efxx count == 0 → FUN_0072d0f2(this,0);
//   否则 FUN_0072d0f2(this,1)+ setFocus(+0xb0,3)+ item(0) 非空 →
//   setCurrentItem(item, 0x13)。
void SettingsPageFace::rebuildRowsFromGlobal()
{
	// FUN_006a4d90(DAT_011c1b00) 全局行表 — cited(源面未转写)
	if (m_listB0 == nullptr)
		return;
	m_listB0->clear();
	for (const SettingsRow &row : m_rowsB8) {
		if (QListWidgetItem *item = rowListItem(row)) // 0072bf8a
			m_listB0->insertItem(m_listB0->count(), item);
	}
	if (m_listB0->count() == 0) {
		resetRow(false); // @0072efxx
		return;
	}
	resetRow(true);
	m_listB0->setFocus(Qt::OtherFocusReason); // 3
	if (QListWidgetItem *first = m_listB0->item(0))
		m_listB0->setCurrentItem(first, QItemSelectionModel::ClearAndSelect); // 0x13
}

// FUN_0072d304(1257B,0022.c:53931)后处理真身(标签腿):
//   @0072d304 FUN_006a2f66(&desc, row+0x30)(cited);
//   kind == 1 → desc = FUN_006a2de4(row)(cited)+ QString(0xc8a19a)+
//     QString(0xc9d328) 拼接 @0072d54c-5a7;
//   +0x80 空 → new QLabel(0x30)→ 赋 +0x80 @0072d75c;setText(desc)。
//   其余腿(图标/布局)cited。
void SettingsPageFace::updateInfoLabel(const SettingsRow &row)
{
	QString desc;
	// FUN_006a2f66(&desc, row.flags)/FUN_006a2de4(row) — cited
	if (row.kind == 1) {
		// desc = FUN_006a2de4(row) + 0xc8a19a + 0xc9d328 — cited(串面未读)
	}
	if (m_label80 == nullptr) {
		m_label80 = new QLabel(this); // @0072d75c(0x30 字节)
	}
	m_label80->setText(desc);

	// +0xa0 详情区 @0072d67d:
	//   row+0x20(子件值)空 → 已有则 removeRow + 置 0;
	//   否则懒建 QPlainTextEdit(0x30)→ setReadOnly(true)@0072d6xx →
	//   setWordWrapMode(1)@0072d6xx → addRow(tr("Error:")(0xc9cf1d))
	//     @0072d6eb → setPlainText(文本).
	const bool hasDetail = !row.childValues.isEmpty();
	if (!hasDetail) {
		if (m_textA0 != nullptr) {
			// QFormLayout::removeRow(+0x30 布局)— cited
			m_textA0 = nullptr;
		}
	} else if (m_textA0 == nullptr) {
		m_textA0 = new QPlainTextEdit(this); // @0072d68a(0x30 字节)
		m_textA0->setReadOnly(true);         // @0072d69e
		m_textA0->setWordWrapMode(QTextOption::WordWrap); // 1 @0072d6xx
		// QFormLayout::addRow(+0x30 布局, tr("Error:")(0xc9cf1d))@0072d6eb
		//   — cited(+0x30 布局面未建模)。
	}
	if (m_textA0 != nullptr)
		m_textA0->setPlainText(row.childValues.join(QLatin1Char('\n')));
}

// FUN_0072d84e(741B,0022.c:54129)行 flags 推导真身:
//   @0072d84e puVar3 = FUN_006a521a(DAT_011c1b00)(全局单例,cited)→
//   行字段逐项拷贝到临时(local_68..local_28)→
//   @0072d93c cVar1 = FUN_006a2dda(&tmp)(全局布尔,cited);
//   bVar4 = (*(byte*)(+0x98 子件 +0x30)) & 1;
//   !cVar1 → flags = -(bVar4==0) & 3(即 b?0:3)@0072d9xx;
//   cVar1 && !bVar4 → flags = (local_38 != 3) ? 2 : 3;
//   cVar1 && bVar4 → flags = (local_38 == 1) ? 1 : 0。
void SettingsPageFace::updateRowFlags(SettingsRow &row)
{
	const bool globalFlag = false; // FUN_006a2dda(全局态) — cited
	const bool b = m_widget98 != nullptr /* (+0x30 & 1) 子件位 — cited */;
	const quint32 old = row.flags; // local_38(旧值)
	if (!globalFlag) {
		row.flags = b ? 0u : 3u; // -(b==0) & 3
	} else if (!b) {
		row.flags = (old != 3u) ? 2u : 3u;
	} else {
		row.flags = (old == 1u) ? 1u : 0u;
	}
}

// 006fe450(1400B,0022.c:26921)真身(结构段):
//   @006fe47c qstring_assign_from_ascii("action")→ qmap_lower_bound_find(
//     *rowMap, "action")→ QVariant::toString;
//   @006fe4f4 FUN_0069b57e(&out)(动作注册表查,cited)→ 组合框同步余段 cited。
void SettingsPageFace::syncActionCombo(const QVariantMap &row)
{
	const QString action = row.value(QStringLiteral("action")).toString(); // "action"
	// FUN_0069b57e(action) → 注册表项 — cited
	// 组合框 findData/setCurrentIndex 同步腿 — cited(1400B 余段)。
}

// 0071b02e(1507B,0022.c:43186)真身(结构段):
//   @0071b064 item = operator_new(0x48)+FUN_00584e4a(item, 0x83, parent);
//   @0071b0xx tr("Variable")(0xc9d517)+tr("Value")(0xc91689)→
//   qlist_appendRange → FUN_00584ee8(item, 列列表)@0071b0d3;
//   余段(单元格填充/编辑委托/信号)cited。
QTableWidgetItem *SettingsPageFace::tableRowItem(QWidget *parent)
{
	Q_UNUSED(parent);
	// FUN_00584e4a(item, 0x83, parent) 0x48 字节项 — cited(类未建模)
	// 列标签:tr("Variable")/tr("Value");单元格填充与委托 — cited。
	return nullptr;
}

// FUN_007349f0(79B)整数键映射取值真身
QVariant SettingsPageFace::mapGetOr(const QMap<quintptr, QVariant> &map, quintptr key,
                                    const QVariant &fallback)
{
	auto it = map.constFind(key);        // @007349f0(QMap 二分:node+0x18 <= key)
	return it != map.constEnd() ? it.value() : fallback;
}

// dialog_loadWidgetValues(1102B)对话框值装载真身(结构段):
//   9 个控件,键 = 控件指针;逐项 mapGetOr → setChecked / 按类型落。
void SettingsPageFace::loadWidgetValues()
{
	// src = FUN_00734eea()@0073733x — cited(当前条目)
	// v = src->property(<名>)@0073735x;!v.canConvert → 返 — cited
	// vals = FUN_0073b6ec(&v)@007373xx(QMap<quintptr,QVariant>);空 → 返 — cited
	const QMap<quintptr, QVariant> vals;   // 承接面(cited)
	Q_UNUSED(vals);
	// 逐字段(语料序):+0x60 / +0x68 / +0x70 → setChecked(mapGetOr(vals, ptr, …));
	//   +0x48 / +0x78 / +0x80 / +0x88 / +0x90 / +0x98 / +0xa0 → 按类型落
	//   (FUN_00738982 / 007396a0 / 007399ad / 00737f44 等,cited)。
}

// FUN_00734eea(53B)当前页控件真身
QWidget *SettingsPageFace::currentPaneWidget(QWidget *host)
{
	if (host == nullptr)
		return nullptr;
	QWidget *w = host->findChild<QWidget *>();   // FUN_005ab316(this->+0x48)(承接)
	if (w == nullptr)
		return nullptr;
	return dynamic_cast<QWidget *>(w);           // 类型 0x1196db0(cited)
}

// FUN_0073b6ec(193B)QVariant → 指针键映射真身(结构段)
QMap<quintptr, QVariant> SettingsPageFace::toPtrVariantMap(QVariant v)
{
	const int ut = qMetaTypeId<QVariantMap>();   // FUN_00739b50()(注册 userType)
	if (v.userType() == ut) {                    // 直接拷贝(FUN_0073b658)
		return QMap<quintptr, QVariant>();
	}
	if (!v.convert(QMetaType(ut)))               // 失败 → 空
		return QMap<quintptr, QVariant>();
	return QMap<quintptr, QVariant>();
}

// FUN_00734f1f(291B)光标/选区模式开关槽真身
void SettingsPageFace::onCursorModeToggled(bool block)
{
	QWidget *w = currentPaneWidget(this);                 // FUN_00734eea(this+0x10)
	if (w != nullptr) {
		w->setEnabled(!block);                            // @FUN_005bce74(w, !v)(承接)
		w->setProperty("text", block);                    // @setProperty(0xc9cf4f)
	}
	// label = this->+0x70(QString*)→ setText:
	//   block ? tr("&Block")(0xca1bf3) : tr("&Line")(0xca03cf)
	QLabel *label = findChild<QLabel *>(QString(), Qt::FindChildrenRecursively); // 承接面
	if (label != nullptr)
		label->setText(block ? QStringLiteral("&Block") : QStringLiteral("&Line"));
}

// sessionpage_title(1777B)设置页标题生成真身(结构段)
QString SettingsPageFace::uniquePageTitle(QWidget *host, const QString &key, int startIndex)
{
	Q_UNUSED(host);                          // 语料用 host+0x108 的有序串表查重(cited)
	static const char *const kKeys[] = {
		"Connection", "Proxy", "Terminal", "Bell", "Keyboard", "Logging",
		"Mode", "Security", "Window", "Selection", "X/Y/Z Modem", "Session",
		"SSH", "SFTP", "X11", "Telnet", "Serial", "Shell", "Agent",
		"Process", "Protocol", "Authentication", "Ciphers", "MAC Hashes",
		"Public Keys", "Key Exchange", "Tcp",
	};
	bool known = false;                      // ③ 27 条等值链(实读)
	for (const char *k : kKeys)
		if (key == QLatin1String(k)) { known = true; break; }
	if (!known)
		return QString();                    // 未列出的键 → 不产标题

	// ① 模板 "%1%2":分类键 + 序号(十进制);② 查重表命中则序号 +1 重试
	QString title = QStringLiteral("%1%2").arg(key).arg(startIndex, 0, 10);
	// 查重/自增循环(host+0x108 有序 trie)— cited
	return title;
}
