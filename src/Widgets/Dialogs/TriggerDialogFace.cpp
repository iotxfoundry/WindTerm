// TriggerDialogFace.cpp — 触发器管理对话框(批 346)
#include "Widgets/Dialogs/TriggerDialogFace.h"

#include "Widgets/Dialogs/NameDialogFace.h"
#include "Widgets/Controls/SearchEditFace.h"
#include "App/ThemeIcons.h"

#include <QAbstractButton>
#include <QDialogButtonBox>
#include <QHash>
#include <QMessageBox>
#include <QFormLayout>
#include <QItemSelectionModel>
#include <QModelIndex>
#include <QGridLayout>
#include <QLabel>
#include <QListWidget>
#include <QBrush>
#include <QCoreApplication>
#include <QFont>
#include <QStandardItemModel>
#include <QUuid>
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

	form->setContentsMargins(px, 0, 0, 0);                          // @006f211x(QMargins{px,0,0,0})
	// **form->addRow 共 2 行(asm 计数,修复 409)** —— 实参被 Ghidra 折叠,
	//   保留 cited(不造空行,空行会改行距)。

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
	auto *field = new SearchEditFace(dlg);          // @006f336c(0x70,searchEdit_init)
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
		// panes_stackInit(this, rec->kind24, rec->f20, &rec->f28)
		//   — 见 TriggerPageStackFace::showPage(修复 405:调用序按语料)
		rebuildActionModel(rec);           // @FUN_006f5b42(this, rec)
		setNextMode(false);                // @FUN_006f2384(this,0)
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
		rebuildActionModel(&m_default98);              // @006f62xx(FUN_006f5b42 缺省记录)
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
	item->setData(Qt::UserRole, rec.uuid10);                        // @006f26c3(0x100)
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

// FUN_006f409a(790B)新增触发器真身(结构段)
void TriggerDialogFace::addTrigger()
{
	auto *dlg = new NameDialogFace(QStringLiteral("trigger"), this); // @006f40e7(0x58)
	auto *field = new SearchEditFace(dlg);          // @006f4107(0x70,searchEdit_init)
	auto *combo = new QComboBox(dlg);               // @006f411f(0x48 combo_makeSearchCombo)

	// kinds = FUN_0069c3c8(&map)(种类注册表 QMap<kind, …>) — cited
	// 逐项(kind = 节点 +0x20):
	for (int kind : {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12}) { // 注册表内容 cited;kind 面见 006f440e/69934c
		const QIcon icon = kindIcon(kind, false);              // @006f4196
		const QString text = QCoreApplication::translate(       // @006f41d2(动态 tr)
			"TriggerDialog", QString::number(kind).toUtf8().constData());
		combo->insertItem(combo->count(), icon, text, QVariant(kind)); // @006f41da
	}
	combo->model()->sort(0);                                   // @006f426a(vt+0x138)

	// connect(dlg QDialog::finished → 闭包 impl FUN_006f4ed6(0x30))@006f4280 — cited
	nameDialogAddFormRow(dlg, QStringLiteral("&Description:"), field); // @006f4324(0xc9dfdb)
	nameDialogAddFormRow(dlg, QStringLiteral("&Type:"), combo);        // @006f4358(0xc9fb1a)
	// (**(*dlg + 0x1a0))(dlg)@006f43xx — 显示腿(cited 未定名)
}

// s_terminal_ansiBrightBlack_699c2a(448B,0021.c:24341)TriggerRecord ctor 真身
TriggerDialogFace::TriggerRecord TriggerDialogFace::makeRecord(int kind, const QString &name,
                                                               const QString &key)
{
	TriggerRecord r;                       // @00699c2a *param_1 = 0;逐字段落
	r.name08 = name;                       // +0x08
	r.uuid10 = key;                         // +0x10
	r.desc18 = QString();                  // +0x18(shared_null)
	r.f20 = 1;                             // +0x20 ┐ 0x0101 一次写
	r.f21 = 1;                             // +0x21 ┘
	r.kind24 = kind;                       // +0x24
	// +0x28 = 空;+0x30 = 0x80000000;+0x38 QMap / +0x40 QHash 空(成员默认)

	if (key.isEmpty()) {
		// @00699cb2 key 空:kind == 0 → 直返;否则 FUN_00698ffc(&r) 缺省化 — cited
		if (kind == 0)
			return r;
	}
	// @00699ccx 语料:if (1 < (unsigned)(kind - 5) && kind != 0xc) return;
	//   ⇒ 只有 kind ∈ {5, 6, 12} 落默认样式腿。
	if ((kind < 5 || kind >= 7) && kind != 12)
		return r;

	if (kind == 5 || kind == 6 || kind == 12) { // @00699cxx 默认样式腿
		QMap<QString, QVariant> style;
		// enumKey = QMetaEnum::valueToKey(enumerator(0x1180860), kind) — cited
		style.insert(QStringLiteral("text.lineStyle"), QVariant());  // 值 cited
		style.insert(QStringLiteral("text.lineColor"),
		             QVariant(QStringLiteral("terminal.ansiBrightBlack"))); // @00699d64
		r.f28 = QVariant(style);           // +0x28 = QVariant(map)
	}
	return r;
}

// FUN_006f35fe(192B,0022.c:20306)追加记录真身
void TriggerDialogFace::appendRecord(const TriggerRecord &rec)
{
	QListWidgetItem *item = makeItemForRecord(rec);   // @006f35fe(FUN_006f263e)
	if (item == nullptr)
		return;
	const int row = m_triggerList68 ? m_triggerList68->currentRow() : -1;
	m_records90.insert(row + 1, rec);                 // +0x90 在 row+1 插入
	m_triggerList68->insertItem(row + 1, item);       // @006f36xx
	m_triggerList68->setCurrentItem(item,
		QItemSelectionModel::ClearAndSelect | QItemSelectionModel::Current); // 0x13
	// QTimer::singleShot(0, this, 闭包 FUN_006f1387)@006f36xx — 延迟刷新,cited
}

// FUN_006f4ed6(324B)新增完成闭包真身(结构段)
void TriggerDialogFace::onAddFinished(int kind, const QString &name, int result)
{
	if (result != 1)                                  // 仅 Accepted
		return;
	const TriggerRecord rec = makeRecord(kind, name, QString()); // 空 key → 缺省化
	appendRecord(rec);                                // @006f35fe
	setNextMode(true);                                // @006f35xx(FUN_006f2384(this,1))
	// FUN_006f9f0c(rec)(临时记录析构)@006f35xx — Qt 成员自洽承接
}

// FUN_006f6304(483B,0022.c:20336)删除所选触发器真身(结构段)
void TriggerDialogFace::removeSelectedTriggers()
{
	if (m_triggerList68 == nullptr)
		return;
	if (!m_triggerList68->selectionModel()->hasSelection())       // @006f6304
		return;
	const int r = QMessageBox::warning(
		this,
		QStringLiteral("Remove triggers"),                        // tr(0xc9fb89)
		QStringLiteral("Do you want to remove the selected triggers?"), // tr(0xca0090)
		QMessageBox::Yes | QMessageBox::No,                      // 0x14000
		QMessageBox::NoButton);                                   // @006f638f
	if (r != QMessageBox::Yes)                                    // 0x4000
		return;
	if (QItemSelectionModel *sel = m_triggerList68->selectionModel())
		sel->blockSignals(true);                                  // @006f63d5
	// FUN_006f36be(this, -1)(提交当前编辑;行 -1)@006f63fe — cited
	// FUN_0055efe8(+0x70, &list)(取走选中项)@006f64xx — cited
	if (m_triggerList68->count() == 0) {                          // @006f64xx
		setPageEnabled(false);                                    // @FUN_006f272a(this,0)
		// 空表页腿:panes_stackInit(this, 8, 1, &空 QVariant) + 缺省记录装载
		//   — 同 reloadList 空表分支,cited
	}
}

// FUN_006f3d98(655B,0022.c:20567)复制所选触发器真身
void TriggerDialogFace::duplicateSelectedTrigger()
{
	if (m_triggerList68 == nullptr)
		return;
	const int row = m_triggerList68->currentRow();
	const int idx = currentRecordIndex(row);          // @006f3d98
	if (idx < 0 || idx >= m_records90.size())
		return;
	// FUN_006f36be(this, row)(提交当前编辑)@006f3dbx — cited

	TriggerRecord copy = m_records90.at(idx);         // FUN_0069f970 拷贝构造

	QHash<QString, int> used;                         // local_b0(QHash)
	for (const TriggerRecord &r : m_records90) {
		if (r.f21 != 0)                               // 只统计入列者
			used.insert(r.name08, 0);                 // FUN_006a2140 插入
	}
	QString cand;                                     // local_b8
	for (int n = 2;; ++n) {                           // @006f3edd(lVar4 从 2 起)
		cand = copy.name08 + QStringLiteral(" (%1)").arg(n, 0, 10); // 格式串实读
		if (!used.contains(cand))                     // while (*node != hash_null)
			break;
	}
	copy.name08 = cand;                               // QString::operator=(local_80,…)
	// FUN_00698ffc(copy)(重生成唯一键)@006f3ff0 — cited
	copy.uuid10 = QString();                           // local_88[0] = 0
	appendRecord(copy);                               // @006f4011(FUN_006f35fe)
	editSelectedTrigger();                            // @006f401x(FUN_006f32e0)
}

// FUN_006f22b2(193B,0022.c:19621)按键选中行真身
void TriggerDialogFace::selectByKey(const QString &key)
{
	if (m_triggerList68 == nullptr)
		return;
	const int n = m_triggerList68->count();            // @006f22b2
	for (int i = 0; i < n; ++i) {
		QListWidgetItem *item = m_triggerList68->item(i);
		if (item == nullptr)
			continue;
		if (item->data(Qt::UserRole).toString() == key) { // data(0x100)
			m_triggerList68->setCurrentItem(item,
				QItemSelectionModel::ClearAndSelect | QItemSelectionModel::Current); // 0x13
			return;
		}
	}
}

// FUN_006f36be(1608B,0022.c:20336 邻)提交当前页真身(结构段)
void TriggerDialogFace::commitCurrentPage(int row)
{
	if (m_triggerList68 == nullptr)
		return;
	if (row == -1)                                    // @006f36be(param_2 == -1)
		row = m_triggerList68->currentRow();
	const int idx = currentRecordIndex(row);           // FUN_006f27d4
	if (m_triggerList68->item(row) == nullptr || idx < 0 || idx >= m_records90.size())
		return;                                       // 双重门
	TriggerRecord &rec = m_records90[idx];             // +0x90 第 idx 项

	QWidget *page = m_pageStack40 ? m_pageStack40->currentWidget() : nullptr; // +0x40
	if (page != nullptr) {
		// ok = FUN_006f1b46(page)@006f37xx — 20B:page->+0x30 的 bit0(页启用态)
		// (**(*page + 0x1a8))(&val, page)@006f37xx — 页面的值读取纯虚槽
		//   (各页覆写;cited)
		// 并入 rec:+0x38 QMap / +0x40 QHash,并回写(实参 Ghidra 折叠)— cited
	}
	// 末尾按 row 刷新列表项文本/提示框(006f2ed8 / 006f2460 面)— cited
}

// FUN_00698fb2(73B,0021.c:23754)记录缺省构造真身
TriggerDialogFace::TriggerRecord TriggerDialogFace::defaultRecord()
{
	TriggerRecord r;
	r.f00 = 0;                            // +0x00
	r.f20 = 0;                            // +0x20 ┐ 0x0100 一次写
	r.f21 = 1;                            // +0x21 ┘
	r.kind24 = 0;                         // +0x24
	// +0x28.. 清;+0x38 QMap / +0x40 QHash 空(成员默认)
	return r;
}

// FUN_00698ffc(80B)重生成唯一键真身
void TriggerDialogFace::regenerateKey(TriggerRecord &rec)
{
	rec.uuid10 = QUuid::createUuid().toString(QUuid::WithoutBraces); // +0x10
}

// FUN_0069904c(50B)设样式真身
void TriggerDialogFace::setStyle(TriggerRecord &rec, const QVariant &style)
{
	if (rec.f28 == style)                 // QVariant::cmp == 0
		return;
	rec.f28 = style;                      // +0x28
	rec.f00 = 1;                          // +0x00(样式已设)
}

// FUN_006f1387(105B,0022.c:18947)延迟聚焦真身
void TriggerDialogFace::focusCurrentPage()
{
	if (m_pageStack40 == nullptr)
		return;
	QWidget *page = m_pageStack40->currentWidget();     // +0x40 currentWidget
	if (page == nullptr)
		return;
	if (dynamic_cast<TriggerPageFace *>(page) != nullptr) // 0x11a47b0(typeinfo)
		page->setFocus(Qt::OtherFocusReason);            // setFocus(3)
}

// FUN_006f5474(319B,0022.c:21425)记录定稿真身
void TriggerDialogFace::finalizeRecords()
{
	for (TriggerRecord &rec : m_records90) {
		if (rec.f21 != 0 && rec.f00 != 0) {   // pcVar3[0x21] && *pcVar3
			regenerateKey(rec);               // @FUN_00698ffc
			rec.f00 = 0;                      // *pcVar3 = 0
		}
	}
	// 语料随后对 +0x90 再取一次并继续遍历(第二段,内容 cited)
}

// ───────── 析构 0x00909354(250B)/deleting 0x0090963e(271B) ─────────
// 逐段实读:
//   vptr = &TriggerDialog_vtable;
//   +0x98 的子对象先收尾(经 0x00698fxx 族的析构腿);
//   +0x90 QList 逐元素释放;
//   +0x88 QMap:引用计数归零 → QMapDataBase::freeTree(根)+ freeData;
//   QDialog::~QDialog
// deleting 0x0090963e(271B):末尾 operator_delete(this, **0xe0**)
//   —— 与头注里"dtor_deleting 实测尺寸 0xe0"一致,字段上界 +0x98 也自洽。
//
// ───────── moc 生成面(出处:QMetaObject 元数据) ─────────
// QMetaObject 0x011a4c20:**methods=0 / signals=0 / props=0 / superdata=0**
//   —— 本对话框没有任何元接口,全部信息在 ctor 装配腿与 dtor 里。
// metaObject 0x0090907a → &PTR_staticMetaObject_011a4c20
// qt_metacast 0x0090930c(strcmp "TriggerDialog" → QDialog::qt_metacast)
// qt_metacall 0x0090934e(5B)= 纯转发 QDialog::qt_metacall。
