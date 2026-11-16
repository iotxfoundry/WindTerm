// TriggerDialogFace.cpp — 触发器管理对话框(批 346)
#include "TriggerDialogFace.h"

#include "NameDialogFace.h"
#include "ThemeIcons.h"

#include <QAbstractButton>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QItemSelectionModel>
#include <QModelIndex>
#include <QGridLayout>
#include <QLabel>
#include <QListWidget>
#include <QBrush>
#include <QFont>
#include <QStandardItemModel>
#include <QStackedLayout>
#include <QStackedWidget>
#include <QTabBar>
#include <QVBoxLayout>
#include <QVariant>

// FUN_006f2dd4(236B,0022.c:20034)ctor 真身
TriggerDialogFace::TriggerDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @006f2dd4
{
	// vptr 0x11a4a00 / 副 0x11a4bd8(C++ 自洽);+0x78 bool / +0x88 QMap /
	//   +0x90 QList / +0x98 成员由成员声明承接。
	setWindowTitle(QStringLiteral("Triggers")); // tr(0xc9e4d3)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true); // @006f2e72(setAttribute 0x37,1)
	assemble();                                  // @006f2e7a FUN_006f2036
	wire();                                      // @006f2e82 FUN_006f2852
	// QTimer::singleShot(0, this, 闭包 FUN_006f62db)@006f2eb0 — cited(槽体未转写)
}

// FUN_006f2036(580B,0022.c:19516)装配真身:
//   form = new QFormLayout(0x20,父 0);grid = new QGridLayout(0x20);
//   px = style()->(vt+0xe0)(0x52, 0, 0)(QStyle::pixelMetric(PM_SmallIconSize));
//   +0x30 = new QTabBar(0x30,父 0);+0x38 = new QStackedWidget(0x30,父 0);
//   +0x80 = new QDialogButtonBox(0x30, 0x400400 /*Ok|Cancel*/, 0);
//   buildTriggerList()/buildSettingsTab()/buildSessionsTab();
//   form->setContentsMargins(QMargins(px,0,0,0))(asm 0x6f21xx: local_48=px,
//     其余 3 个 int 清 0);form->addRow ×2(实参折叠);
//   buttons->button(0x400 /*Ok*/)->setText(tr("Ok")(0xc9e1cd));
//   buttons->button(0x400000 /*Cancel*/)->setText(tr("Cancel")(0xc8a1b5));
//   grid->addWidget(+0x68, 0,0,1,2,0);
//   grid->addLayout(form, 0,2,1,6,0);
//   grid->addWidget(+0x80, 1,6,1,2,0);
//   setLayout(grid);FUN_0075c132(0.6 /*0x3fe3333333333333*/,
//     0.74 /*0x3fe7ae147ae147ae*/, qApp, this)。
void TriggerDialogFace::assemble()
{
	auto *form = new QFormLayout;                                  // @006f2059
	auto *grid = new QGridLayout;                                  // @006f206e
	const int px = style()->pixelMetric(QStyle::PM_SmallIconSize, nullptr, nullptr); // @006f208x(0x52)

	m_tabBar30 = new QTabBar;                                      // @006f20a6(0x30)
	m_stack38 = new QStackedWidget;                                // @006f20c1(0x30)
	m_buttons80 = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel); // @006f20e1(0x400400)

	buildTriggerList();                                            // @006f20e9
	buildSettingsTab();                                            // @006f20ee
	buildSessionsTab();                                            // @006f20f4

	form->setContentsMargins(px, 0, 0, 0);                          // @006f211x
	// form->addRow ×2 — 语料实参折叠,cited

	if (QAbstractButton *ok = m_buttons80->button(QDialogButtonBox::Ok))
		ok->setText(QStringLiteral("Ok"));                          // tr(0xc9e1cd)
	if (QAbstractButton *cancel = m_buttons80->button(QDialogButtonBox::Cancel))
		cancel->setText(QStringLiteral("Cancel"));                  // tr(0xc8a1b5)

	grid->addWidget(m_triggerList68, 0, 0, 1, 2);                   // @006f21xx
	grid->addLayout(form, 0, 2, 1, 6);                              // @006f21xx
	grid->addWidget(m_buttons80, 1, 6, 1, 2);                       // @006f21xx
	setLayout(grid);                                                // @006f22xx
	// FUN_0075c132(0.6, 0.74, qApp, this)@006f22xx — cited(窗口尺寸比例腿)
}

// FUN_006f1c74(257B,0022.c:19367)触发器列表:
//   +0x68 = new 0x48 + FUN_0055e356(w, 0x143, 0);+0x70 = w+0x40;
//   setAttribute(+0x70, 2 /*WA_Resized*/, true);
//   FUN_0055f224(+0x70, tr("No trigger available")(0xc9e4dc))(占位文案);
//   connect(+0x70 QListWidget::itemEntered → 闭包 impl FUN_006f2ed8(821B))。
void TriggerDialogFace::buildTriggerList()
{
	m_triggerList68 = new QListWidget;       // @006f1c98(0x48 + FUN_0055e356(0x143))
	m_triggerView70 = m_triggerList68;       // +0x70 = w+0x40(同族子件)
	m_triggerView70->setAttribute(Qt::WA_Resized, true); // @006f1cxx(2,1)
	// FUN_0055f224(+0x70, "No trigger available") — cited(占位文案设置腿)
	// connect(itemEntered → FUN_006f2ed8) — cited
}

// FUN_006f1f68(182B,0022.c:19471)"&Settings" 页容器:
//   page = new QWidget(0x30, 父 0);+0x40 = new QStackedLayout(0x20);
//   stacked->setContentsMargins(QMargins 全零,asm 16 字节清零);
//   page->setLayout(stacked);
//   +0x30 tabBar->addTab(tr("&Settings")(0xc9fb0a));
//   +0x38 stackedWidget->addWidget(page)。
void TriggerDialogFace::buildSettingsTab()
{
	auto *page = new QWidget;                 // @006f1f89(0x30,父 0)
	m_pageStack40 = new QStackedLayout;       // @006f1f9e(0x20)
	m_pageStack40->setContentsMargins(0, 0, 0, 0);
	page->setLayout(m_pageStack40);
	m_tabBar30->addTab(QStringLiteral("&Settings")); // tr(0xc9fb0a)
	m_stack38->addWidget(page);               // @006f1fxx
}

// FUN_006f1d86(425B,0022.c:19405)"S&essions" 页:
//   page = new QWidget(0x30, 父 0);
//   l1 = new QLabel(0x30, tr("Target &Sessions:")(0xc9fadd));
//   l2 = new QLabel(0x30, tr("Target &Systems:")(0xc9faef));
//   vbox = new QVBoxLayout(0x20);
//   FUN_006f1b74(+0x48 = new 0x50 + FUN_00535a76;+0x58 = w+0x48;
//     FUN_005d6878(+0x58, tr("No session available")(0xc9fab4)));
//   FUN_006f1bf4(+0x50 = 同构造;+0x60 = w+0x48;
//     FUN_005d6878(+0x60, tr("No system available")(0xc9fac9)));
//   l1/l2 setBuddy;vbox margins 全零;
//   addWidget(l2,0) → addWidget(+0x50,1) → addWidget(l1,0) → addWidget(+0x48,2);
//   page->setLayout(vbox);tabBar->addTab(tr("S&essions")(0xc9fb00));
//   stackedWidget->addWidget(page)。
void TriggerDialogFace::buildSessionsTab()
{
	auto *page = new QWidget;                                       // @006f1dab(0x30)
	auto *l1 = new QLabel(QStringLiteral("Target &Sessions:"));     // tr(0xc9fadd)
	auto *l2 = new QLabel(QStringLiteral("Target &Systems:"));      // tr(0xc9faef)
	auto *vbox = new QVBoxLayout;                                   // @006f1e47(0x20)

	m_sessions48 = new QWidget;            // @006f1b91(0x50 + FUN_00535a76) cited
	m_systems50 = new QWidget;             // @006f1c11(同上) cited
	// +0x58/+0x60 占位文案 "No session available"/"No system available" — cited

	l2->setBuddy(m_systems50);             // setBuddy
	l1->setBuddy(m_sessions48);
	vbox->setContentsMargins(0, 0, 0, 0);   // 全零
	vbox->addWidget(l2, 0, Qt::Alignment());        // @006f1exx
	vbox->addWidget(m_systems50, 1, Qt::Alignment());
	vbox->addWidget(l1, 0, Qt::Alignment());
	vbox->addWidget(m_sessions48, 2, Qt::Alignment());
	page->setLayout(vbox);                 // @006f1exx
	m_tabBar30->addTab(QStringLiteral("S&essions")); // tr(0xc9fb00)
	m_stack38->addWidget(page);            // @006f1fxx
}

// dialog_connectAcceptReject2(916B,0022.c:19855)八路接线真身(结构段):
//   @006f287x buttons(+0x80) "2accepted()" → this "1accept()";
//   @006f289x buttons(+0x80) "2rejected()" → this "1reject()";
//   @006f28bx tabBar(+0x30) currentChanged → 闭包 impl FUN_006f2435;
//   @006f28ex tabBar(+0x30) currentChanged → stacked(+0x38) setCurrentIndex
//     (闭包 impl FUN_006b6730,QTabBar smeta);
//   @006f29xx +0x68 的 4 路信号(FUN_008ef798 idx1 / 8ef7c0 idx4 /
//     8ef7fc idx0xc / 8ef810 idx0xd,smeta 01193440)→ 槽 FUN_006f409a(790B)/
//     FUN_006f3d98(655B)/FUN_006f6304(483B)/FUN_006f32e0(451B)(经
//     FUN_006f9535 143B 闭包转发,槽体均 cited);
//   @006f2axx listView(+0x70) doubleClicked → 闭包 FUN_006f6dd0 → FUN_006f32e0;
//   @006f2bxx listView(+0x70)->selectionModel() currentChanged → 闭包
//     FUN_006f6e40 → FUN_006f60a8(74B)。
void TriggerDialogFace::wire()
{
	connect(m_buttons80, &QDialogButtonBox::accepted, this, &QDialog::accept);
	connect(m_buttons80, &QDialogButtonBox::rejected, this, &QDialog::reject);
	connect(m_tabBar30, &QTabBar::currentChanged, this, [this](int) {
		// 闭包 impl FUN_006f2435 — cited
	});
	connect(m_tabBar30, &QTabBar::currentChanged, m_stack38, &QStackedWidget::setCurrentIndex);
	// +0x68 四路信号(FUN_008ef798/8ef7c0/8ef7fc/8ef810,smeta 01193440)
	//   → FUN_006f409a/006f3d98/006f6304/006f32e0 — cited(槽体未转写)
	connect(m_triggerList68, &QListWidget::doubleClicked, this, [this](const QModelIndex &) {
		// 闭包 FUN_006f6dd0 → FUN_006f32e0 — cited
	});
	// listView->selectionModel() currentChanged → FUN_006f60a8 — cited
}

// FUN_006f32e0(451B,0022.c:20195)编辑当前触发器真身(结构段)
void TriggerDialogFace::editSelectedTrigger()
{
	QListWidgetItem *item = m_triggerList68 ? m_triggerList68->currentItem() : nullptr; // @006f32e0
	if (item == nullptr)
		return;                                     // 无当前项 → 直返
	const int row = m_triggerList68->currentRow();  // @006f32exx

	auto *dlg = new NameDialogFace(QStringLiteral("trigger"), this); // @006f334c(0x58,FUN_006bd7f6)
	auto *field = new QWidget(dlg);                 // @006f336c(0x70 + searchEdit_init)— cited
	// connect(dlg QDialog::finished → 闭包 impl FUN_006f34dd(0x38,捕获
	//   dlg/field/row/this/item))@006f33xx — cited
	// filterline_setText(field, 当前行记录 +0x18)@006f3411 — cited
	//   (记录面 = FUN_006f3286:row → FUN_006f27d4 查下标;-1 → +0x98 缺省;
	//    否则 +0x90 QList 第 idx 项,步长 0x48)
	nameDialogAddFormRow(dlg, QStringLiteral("&Description:"), field); // @006f3445(tr 0xc9dfdb)
	// FUN_006bd960(dlg, item->data(0).toString())@006f347a — cited(553B 回填)
	// (**(*dlg + 0x1a0))(dlg)@006f34xx — 显示/打开腿(cited 未定名)
	Q_UNUSED(row);
}

// FUN_006f272a(13B)页容器启停:0x6f272a 单条 setEnabled(asm 里被调为 (this,on));
//   语料 Ghidra 把实参折成 SUB81(*(this+0x38),0),按 +0x38 页容器承接(cited)。
void TriggerDialogFace::setPageEnabled(bool on)
{
	if (m_stack38)
		m_stack38->setEnabled(on);
}

// FUN_006f2738(155B)名字 → 下标
int TriggerDialogFace::rowIndexByName(const QString &name) const
{
	const int n = m_records90.size();     // +0x90 size(@*+4)
	for (int i = 0; i < n; ++i) {
		if (m_records90.at(i).name10 == name) // @record+0x10 逐项 ==
			return i;
	}
	return -1;                            // @006f27cb
}

// FUN_006f27d4(110B)当前行 → 记录下标
int TriggerDialogFace::currentRecordIndex(int row) const
{
	if (m_triggerList68 == nullptr)
		return -1;
	QListWidgetItem *item = m_triggerList68->item(row); // +0x68 ->item(row)
	if (item == nullptr)
		return -1;
	const QString name = item->data(Qt::UserRole).toString(); // data(0x100)
	return rowIndexByName(name);
}

// FUN_006f3286(89B)当前行记录指针
TriggerDialogFace::TriggerRecord *TriggerDialogFace::currentRecord()
{
	const int row = m_triggerList68 ? m_triggerList68->currentRow() : -1;
	const int idx = currentRecordIndex(row);
	if (idx < 0 || idx >= m_records90.size())
		return &m_default98;              // == -1 → this+0x98
	return &m_records90[idx];             // +0x90 第 idx 项(步长 0x48)
}

// FUN_006f2384(156B)确定键文案切换
void TriggerDialogFace::setNextMode(bool on)
{
	if (m_f78 == on)                      // +0x78 同态 → 直返
		return;
	if (m_buttons80) {
		if (QAbstractButton *ok = m_buttons80->button(QDialogButtonBox::Ok)) { // 0x400
			ok->setText(on ? QStringLiteral("&Next")   // tr(0xc9fb14)
			               : QStringLiteral("&Ok"));   // tr(0xc9e1cc)
		}
	}
	m_f78 = on;                           // +0x78 = on
}

// FUN_006f60a8(139B)当前触发器换行槽真身
void TriggerDialogFace::onTriggerIndexChanged(const QModelIndex &current)
{
	TriggerRecord *rec = currentRecord();  // FUN_006f3286
	if (current.row() >= 0 && current.column() >= 0 && current.internalPointer() != nullptr)
		; // FUN_006f36be(this, ?)(1608B 提交腿)— cited
	if (rec->kind24 != 0) {                // +0x24
		setPageEnabled(true);              // @FUN_006f272a(this,1)
		// panes_stackInit(this, rec->kind24, rec->f20, &rec->f28) — 见 TriggerPageStackFace::showPage
		setNextMode(false);                // @FUN_006f2384(this,0)
		// FUN_006f5b42(this, rec)(1264B,记录装载进页)— cited
	} else {
		setPageEnabled(false);             // @FUN_006f272a(this,0)
		setNextMode(false);
	}
}

// FUN_006f2ed8(821B,0022.c:20068)列表项提示框真身
void TriggerDialogFace::updateItemTooltip(QListWidgetItem *item)
{
	if (item == nullptr)
		return;
	const QString name = item->data(Qt::UserRole).toString(); // data(0x100)
	const int idx = rowIndexByName(name);                     // @006f2f37
	if (idx < 0 || idx >= m_records90.size())
		return;                                               // -1 → 直返
	const TriggerRecord &rec = m_records90.at(idx);

	QString tip;                                              // local_78
	if (!rec.name08.isEmpty()) {                              // @006f2fxx(+0x08 非空)
		if (rec.desc18.isEmpty()) {                           // +0x18 空
			tip = rec.name08;                                 // @006f2fxx
		} else {
			// 模板串 @006f3000(实读,含内联样式)
			const QString rowFmt = QStringLiteral(
				"<tr style=\"white-space: nowrap;\"><td style=\"text-align:right;\">%1: </td><td><b>%2</b></td></tr>");
			tip += rowFmt.arg(QStringLiteral("Name")).arg(rec.name08);         // tr(0xc9e6e7)
			tip += rowFmt.arg(QStringLiteral("Description")).arg(rec.desc18);  // tr(0xc8a3a0)
			tip.prepend(QStringLiteral("<table>"));           // @006f30e1
			tip.append(QStringLiteral("</table>"));           // @006f30xx
		}
	}
	if (item->data(Qt::ToolTipRole).toString() != tip)         // data(3) 比较
		item->setData(Qt::ToolTipRole, tip);                   // @006f315x(vt+0x28)
}

// FUN_006f6134(415B)初始装载/刷新列表真身(结构段)
void TriggerDialogFace::reloadList()
{
	if (m_triggerList68 == nullptr)
		return;
	m_triggerList68->clear();                          // @006f6134

	// 全局触发表换手:FUN_0069d59e(DAT_011c1a60) → +0x90
	//   (引用计数换手;旧表 FUN_006f2d8a(74B) 逐项释放后 deallocate(0x48,8))
	//   — cited
	for (const TriggerRecord &rec : m_records90) {
		if (rec.f21 == 0)                              // +0x21 关 → 不进列表
			continue;
		// FUN_006f263e(this, rec)(199B 过滤;返 0 → 跳过) — cited
		// insertItem(count, …)@006f61xx — 实参 Ghidra 折叠,cited
	}

	if (m_triggerList68->count() == 0) {               // @006f6219
		setPageEnabled(false);                         // @FUN_006f272a(this,0)
		QVariant none;                                 // local_38 空 QVariant
		// panes_stackInit(this, 8 /*HighlightText*/, 1, &none)@006f6253
		// — 见 TriggerPageStackFace::showPage
		// FUN_006f5b42(this, &m_default98)@006f62xx(1264B 缺省记录装载) — cited
	} else {
		setPageEnabled(true);                          // @FUN_006f272a(this,1)
		m_triggerList68->setFocus(Qt::OtherFocusReason); // @006f622x(setFocus 3)
		if (QListWidgetItem *first = m_triggerList68->item(0)) {
			m_triggerList68->setCurrentItem(
				first, QItemSelectionModel::ClearAndSelect | QItemSelectionModel::Current); // 0x13
		}
	}
}

// FUN_006f5b42(1264B,0022.c:21635)动作下拉模型重建 + 记录装载真身(结构段):
//   本面落「模型构建 + "*"→"all systems" 改写」两段;逐字段装载腿
//   (s_session_uuid_6f571a 927B)cited。
void TriggerDialogFace::rebuildActionModel(TriggerRecord *rec)
{
	auto *model = new QStandardItemModel(m_actionView60);   // @006f5b75(0x10)

	// names = FUN_008086d0(DAT_011c2200)(全局动作名表,QList<QVariant>)
	//   → 头插 "*"(@006f5ba3/5bc2;引用计数换手)→ 逐名 QStandardItem。—— cited
	// 逐名(setEnabled 按可用性)@006f5cd1..5f:
	//   item = new QStandardItem(0x10, name);item->setData(name, 0);
	//   item->setEnabled(…);model->appendRow(item)(@006f5dxx)。

	connect(model, &QStandardItemModel::itemChanged, this, [this](QStandardItem *) {
		// 闭包槽体 — cited
	});

	if (m_actionView60) {
		// view_connectModelReset(+0x60, model, 1)@006f5e1x — cited(视图置模型)
		// m = +0x60->model() → dynamic_cast<QStandardItemModel*>;item(0)
		if (QStandardItem *first = model->item(0)) {         // @006f5e8x
			if (first->data(Qt::DisplayRole).toString() == QStringLiteral("*")) { // @006f5efe
				model->blockSignals(true);                   // @006f5f3d
				first->setData(QStringLiteral("all systems"), Qt::DisplayRole); // tr(0xc9fb7d)
				model->blockSignals(false);                  // @006f5fxx
			}
		}
	}

	// s_session_uuid_6f571a(this, rec)(927B,记录逐字段装入各页)— cited
	Q_UNUSED(rec);
}

// s_session_uuid_6f571a(927B,0022.c:21521)会话范围模型重建真身(结构段):
//   逐会话取键 "session.uuid"/"session.icon"(实读),组名/标签经
//   s_session_group_805a3e / s_session_label_8062b6 取面(cited)。
void TriggerDialogFace::rebuildSessionScopeModel(TriggerRecord *rec)
{
	auto *model = new QStandardItemModel(m_f58);            // @006f5751(0x10,父 +0x58)
	// defIcon = FUN_0075727c(DAT_011c1ce0, +0x58) — cited(主题缺省图标)
	// arr = DAT_011c2200->+0xe0;n = 元素数(json_size_or_int_get) — cited
	// 逐项(0..n-1):
	//   uuid  = json_get_string_default(obj, "session.uuid", "")   // 键实读
	//   icon  = json_get_string_default(obj, "session.icon", "")   // 键实读
	//   group = s_session_group_805a3e(DAT_011c2200, obj)          // cited
	//   label = s_session_label_8062b6(DAT_011c2200, obj, 1)       // cited
	//   uuid/label 皆非空才建项;group 非空则 label = "%1 / ".arg(group)+label;
	//   item = new QStandardItem(icon, label)@006f5862;setData(uuid, 0);
	//   matched = FUN_0069a216(rec, uuid, 1)@006f589b;
	//   FUN_006f7184(item, matched ? 2 : 0)@006f58xx(item 标志);
	//   model->appendRow(item)@006f58xx。
	Q_UNUSED(rec);

	if (m_f58) {
		// view_connectModelReset(+0x58, model, 1)@006f5axx — cited
		// FUN_005d688e(+0x58)@006f5axx — cited
	}
}

// FUN_006f263e(199B,0022.c:19746)记录 → 列表项真身
QListWidgetItem *TriggerDialogFace::makeItemForRecord(const TriggerRecord &rec)
{
	const QIcon icon = recordIcon(rec);                            // FUN_006994ca(21B)
	auto *item = new QListWidgetItem(icon, rec.name08);            // @006f2670(0x30)
	if (rec.f20 == 0)                                              // +0x20 == 0
		applyItemGrayed(item, false);                              // FUN_006f2460(this,item,0)
	item->setData(Qt::UserRole, rec.key10);                        // @006f26c3(0x100)
	return item;
}

// FUN_006f34dd(259B,0022.c:20259)编辑完成闭包真身
void TriggerDialogFace::applyEditedName(QListWidgetItem *item, int row, const QString &name,
                                        const QString &desc, int result)
{
	if (result != 1)                     // 仅 Accepted(args[1] == 1)才落库
		return;
	const int idx = currentRecordIndex(row); // FUN_006f27d4(this, 行)
	if (idx >= 0 && idx < m_records90.size()) {
		TriggerRecord &rec = m_records90[idx];   // +0x90 第 idx 项
		rec.name08 = name;                       // +0x08 = 输入名
		rec.desc18 = desc;                       // +0x18 = 描述
	}
	if (item)
		item->setData(Qt::DisplayRole, name);    // 捕获项 setData(0, 名)
}

// FUN_006f2460(425B,0022.c:20141)列表项禁用外观真身
void TriggerDialogFace::applyItemGrayed(QListWidgetItem *item, bool on)
{
	if (item == nullptr)
		return;
	QFont f = item->data(Qt::FontRole).value<QFont>(); // @006f24xx(data(6))
	f.setStrikeOut(on);                                // @006f24e5
	item->setData(Qt::FontRole, f);                    // @006f2508(setData(6))
	if (!on) {
		item->setData(Qt::ForegroundRole,
		              QBrush(QColor(QStringLiteral("Gray")))); // @006f25b4(0xd0d152)
	} else {
		item->setData(Qt::ForegroundRole, QVariant()); // @006f255e(空 → 清画笔)
	}
}

// s_king__beforeDisconnection_69934c(365B,0021.c:23917)kind → 主题图标真身
QIcon TriggerDialogFace::kindIcon(int kind, bool active)
{
	QString name;                                  // local_38(空串起始)
	switch (kind) {                                // @0069938e switch 逐 case
	case 1:  name = QStringLiteral("king::afterConnection"); break;
	case 2:  name = QStringLiteral("king::afterDisconnection"); break;
	case 3:  name = QStringLiteral("king::beforeConnection"); break;
	case 4:  name = QStringLiteral("king::beforeDisconnection"); break;
	case 5:  name = QStringLiteral("king::customLink"); break;
	case 6:  name = QStringLiteral("king::customMenu"); break;
	case 8:  name = QStringLiteral("king::highlightText"); break;
	case 9:  name = QStringLiteral("king::playSound"); break;
	case 10: name = QStringLiteral("king::runCommand"); break;
	case 11: name = QStringLiteral("king::sendText"); break;
	case 12: name = QStringLiteral("king::showTooltip"); break;
	default: break;                                // 7 等无 case → 空名
	}
	if (active && !name.isEmpty())                 // @006993ed(flag 且非空)→ 追加
		name.append(QStringLiteral("Active"));     // FUN_0069e842(append "Active")
	return ThemeIcons::loadSvg(name, QString());   // @006993c0(theme_icon_load_svg)
}

// FUN_006994ca(21B)记录图标
QIcon TriggerDialogFace::recordIcon(const TriggerRecord &rec)
{
	return kindIcon(rec.kind24, rec.f20 != 0);     // +0x24 kind / +0x20 active
}
