#pragma once

#include <QDialog>
#include <QHash>
#include <QList>
#include <QMap>
#include <QString>

class QDialogButtonBox;
class QGridLayout;
class QModelIndex;
class QLabel;
class QListWidget;
class QStandardItemModel;
class QStackedLayout;
class QStackedWidget;
class QTabBar;
class QVBoxLayout;

// TriggerDialogFace — 语料 TriggerDialog(批 346 归属勘定完成)。
//
// ctor FUN_006f2dd4(236B,0022.c:20034) asm 实测(0x6f2dd4..0x6f2eb5):
//   QDialog(parent, 0) → vptr = 0x11a4a00(asm: mov $0x11a49f0 + lea 0x10)/
//   副 vptr = 0x11a4bd8(0x11a49f0 + 0x1e8)→ +0x78 = byte 0(bool)→
//   +0x88 = QMapDataBase::shared_null → +0x90 = QArrayData::shared_null →
//   +0x98 经 FUN_00698fb2 构造 → setWindowTitle(tr("Triggers")(0xc9e4d3)) →
//   setAttribute(0x37, true) → assemble()(FUN_006f2036) →
//   wire()(dialog_connectAcceptReject2,006f2852)→ QTimer::singleShot(0,闭包
//   FUN_006f62db)。dtor_deleting 实测对象尺寸 **0xe0**。
//
// 归属实证:本类字段与另两支完全吻合 —— 页栈 panes_stackInit(006f440e) 用
//   +0x30 QTabBar / +0x40 QStackedLayout / +0x88 QMap<int,page*>;
//   接线 dialog_connectAcceptReject2(006f2852) 用 +0x30/+0x38/+0x68/+0x70/+0x80。
class TriggerDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit TriggerDialogFace(QWidget *parent = nullptr); // FUN_006f2dd4

	void assemble();   // FUN_006f2036(580B)
	// FUN_006f32e0(451B,0022.c:20195)编辑当前触发器:
	//   item = +0x68 currentItem();空 → 返;row = currentRow();
	//   dlg = new 0x58 NameDialog(tr("trigger")(0xc8c40c), this)(FUN_006bd7f6);
	//   field = new 0x70 + searchEdit_init(field, dlg);
	//   connect(dlg finished → 闭包 impl FUN_006f34dd(259B));
	//   filterline_setText(field, 当前行记录(+0x18))(FUN_006f3286 89B:
	//     row → FUN_006f27d4 查下标;==-1 → this+0x98 缺省记录;否则
	//     +0x90 QList 第 idx 项,步长 0x48);
	//   FUN_006bd250(dlg, tr("&Description:")(0xc9dfdb), field)(加行 + Tab 链);
	//   FUN_006bd960(dlg, item->data(0).toString())(553B,回填);
	//   (**(*dlg + 0x1a0))(dlg)(显示/打开腿,cited 未定名)。
	void editSelectedTrigger();

	// FUN_006f409a(790B,0022.c:20068 邻)新增触发器(与编辑腿同型):
	//   dlg = NameDialog(tr("trigger")(0xc8c40c), this)(FUN_006bd7f6, 0x58);
	//   field = 0x70 + searchEdit_init(field, dlg);
	//   combo = 0x48 + combo_makeSearchCombo(combo, dlg);
	//   kinds = FUN_0069c3c8(&map)(种类注册表,键值 = kind);逐项:
	//     **text = tr(QString::number(kind))** —— tr 实参是动态串
	//     (先 QVariant(kind).toString().toUtf8() 再 QMetaObject::tr,
	//     即翻译表以数字源串为键);
	//     icon = kindIcon(kind, false);combo->insertItem(count, icon,
	//       text, QVariant(kind));
	//   combo->model()->(vt+0x138)(0, 0)(排序);   // 0x138 = sort 槽
	//   connect(dlg finished → 闭包 impl FUN_006f4ed6(0x30,
	//     捕获 combo/dlg/field/this));
	//   nameDialogAddFormRow(dlg, tr("&Description:")(0xc9dfdb), field);
	//   nameDialogAddFormRow(dlg, tr("&Type:")(0xc9fb1a), combo);
	//   (**(*dlg + 0x1a0))(dlg)(显示腿,cited 未定名)。
	void addTrigger();

	// ---- 记录面(批 349)------------------------------------------------
	// +0x90 QList 元素步长 0x48(006f2d8a 74B 析构循环实测:
	//   逐项 FUN_006f9f0c 后 deallocate(0x48,8));+0x98 = 缺省记录。
	// 字段:+0x10 名字 QString(006f2738 逐项 == 比较)/+0x20 byte(页栈
	//   param_3)/+0x24 int 页 kind(0 = 无页)/+0x28 子结构(页栈 param_4)。
	// 布局由 448B ctor(s_terminal_ansiBrightBlack_699c2a,批 361)逐字段实测:
	//   +0x00 byte=0 / +0x08 name / +0x10 key / +0x18 空 QString /
	//   +0x20 + 0x21 都置 1(0x0101 一次写;+0x20 = 启用/图标 active,
	//   +0x21 = 入列表)/ +0x24 kind / +0x28 默认样式(QVariant)/
	//   +0x30 未定(初值 0x80000000)/ +0x38 QMap / +0x40 QHash。
	//   总 0x48 —— 与 deallocate(0x48,8) 一致。
	struct TriggerRecord {
		char f00 = 0;                            // +0x00
		char pad01[7] = {};                      // +0x01..0x07
		QString name08;                          // +0x08(建项/提示框 "Name")
		QString key10;                           // +0x10(UserRole 键)
		QString desc18;                          // +0x18(提示框 "Description"/编辑回填)
		char f20 = 1;                            // +0x20(启用;图标 active 位)
		char f21 = 1;                            // +0x21(入列表;0 = 隐藏)
		char pad22[2] = {};                      // +0x22..0x23
		int kind24 = 0;                          // +0x24(页 kind;0 = 无页)
		QVariant f28;                            // +0x28(默认样式 map)
		char f30[8] = {};                        // +0x30(未定;初值 0x80000000)
		QMap<QString, QVariant> f38;             // +0x38
		QHash<QString, QVariant> f40;            // +0x40
	};

	// s_terminal_ansiBrightBlack_699c2a(448B,0021.c:24341)**名不副实**:
	//   实为 TriggerRecord 构造函数。逐字段见上;尾部:
	//   key 空 && kind == 0 → 直返;key 空 → FUN_00698ffc(缺省化);
	//   kind ∉ [5..] 且 != 12 → 直返;否则置默认样式:
	//     map["text.lineStyle"] = QVariant(QMetaEnum::valueToKey(
	//        enumerator(0x1180860), kind));
	//     map["text.lineColor"] = QVariant("terminal.ansiBrightBlack")
	//        ← **函数名即由此字面而来**;
	//     → +0x28 = QVariant(map)。
	static TriggerRecord makeRecord(int kind, const QString &name, const QString &key);

	// FUN_00698fb2(73B,0021.c:23754)记录缺省构造:
	//   +0x00=0 / +0x08,+0x10,+0x18 空 QString / **+0x20..0x21 = 0x0100**
	//   (低字节 f20=0 未启用,高字节 f21=1 入列表)/ +0x24 kind=0 /
	//   +0x28 起清 / +0x38 QMap / +0x40 QHash。
	static TriggerRecord defaultRecord();

	// FUN_00698ffc(80B)重生成唯一键:**+0x10 = QUuid::createUuid()
	//   .toString(WithoutBraces)** —— 故 +0x10 是 uuid(即 UserRole 存的键),
	//   不是"名字"。
	static void regenerateKey(TriggerRecord &rec);

	// FUN_0069904c(50B)设样式:若 +0x28 QVariant 与入参不同 →
	//   +0x28 = 入参;+0x00 = 1(样式已设 flag)。
	static void setStyle(TriggerRecord &rec, const QVariant &style);

	// FUN_0069907e(10B)是否连接类 kind:`kind - 1 < 4` ⇒ 1..4。
	static bool isConnectionKind(int kind) { return static_cast<unsigned>(kind - 1) < 4; }

	// FUN_006f35fe(192B,0022.c:20306)追加记录(新增腿的落库步):
	//   item = makeItemForRecord(rec)(FUN_006f263e);null → 返;
	//   row = +0x68 currentRow();+0x90 在 row+1 处插入 rec(FUN_006a0090);
	//   +0x68 insertItem(row+1, item);setCurrentItem(item, 0x13);
	//   QTimer::singleShot(0, this, 闭包 FUN_006f1387)(延迟刷新)。
	void appendRecord(const TriggerRecord &rec);

	// FUN_006f4ed6(324B,0022.c:20176 邻)新增完成闭包:
	//   which==0 → 释放闭包(0x30);which==1 且 args[1](finished)==1:
	//     kind = combo->currentData().toInt()(userType/convert 双路);
	//     name = NameDialog 文本(FUN_006bd94e);key = 空串;
	//     rec = makeRecord(kind, name, key)(448B ctor,空 key → 缺省化);
	//     appendRecord(rec);setNextMode(true)(→ "&Next");
	//     FUN_0069f90c(rec)(记录析构)。
	void onAddFinished(int kind, const QString &name, int result);

	// FUN_006f6304(483B,0022.c:20336)删除所选触发器:
	//   selectionModel()->hasSelection() 为真才动作;
	//   QMessageBox::warning(this, tr("Remove triggers")(0xc9fb89),
	//     tr("Do you want to remove the selected triggers?")(0xca0090),
	//     0x14000 /*Yes|No*/, 0);结果 == 0x4000(Yes)才删:
	//   blockSignals(selectionModel);
	//   FUN_006f36be(this, -1)(提交当前编辑,行 -1);FUN_0055efe8(+0x70,&list)
	//     (取走选中项);count == 0 → setPageEnabled(false) + 空表页腿
	//     (kind 8 + 缺省记录,cited);否则维持当前项。
	void removeSelectedTriggers();

	// FUN_006f3d98(655B,0022.c:20567)复制所选触发器:
	//   row = currentRow;idx = currentRecordIndex(row);-1 → 返;
	//   FUN_006f36be(this, row)(提交);copy = +0x90[idx](拷贝构造);
	//   把现有记录名(+0x21 非 0 者)收进 QHash;
	//   从 n = 2 起试 copy.name + " (%1)".arg(n)(十进制),首次未被占用即用
	//     (**格式串 " (%1)" 实读**);
	//   copy.+0x00..(名) = 新名;FUN_00698ffc(copy)(重生成唯一键);
	//   copy.+0x18..? 清;appendRecord(copy)(FUN_006f35fe);
	//   editSelectedTrigger()(FUN_006f32e0,复制后直接进编辑)。
	void duplicateSelectedTrigger();

	// FUN_006f22b2(193B,0022.c:19621)按键选中行:
	//   遍历 +0x68 列表项(i = 0..count-1),逐项 data(0x100).toString()
	//   与 key 比较,相等 → setCurrentItem(item, 0x13) 并返回。
	void selectByKey(const QString &key);

	// FUN_006f36be(1608B,0022.c:20336 邻)提交当前页到记录:
	//   row == -1 → row = +0x68 currentRow();
	//   item = +0x68 item(row);idx = currentRecordIndex(row);任一无效 → 返;
	//   rec = +0x90[idx];
	//   page = +0x40 currentWidget();非空 →
	//     ok = FUN_006f1b46(page)(20B:page->+0x30 的 bit0 = 该页"启用"态);
	//     (**(*page + 0x1a8))(&val, page)(**页面的值读取纯虚槽** —— 与
	//       +0x1a0 同族的另一纯虚;各页覆写,cited);
	//   把 val 并入 rec 的 +0x38 QMap / +0x40 QHash 并回写(cited);
	//   末尾按 row 刷新列表项/提示框(006f2ed8 面)。
	void commitCurrentPage(int row);

	// FUN_006f3286(89B,0022.c:20176)当前行记录:
	//   row = +0x68 currentRow();idx = currentRecordIndex(row);
	//   idx == -1 → 返回 +0x98 缺省记录;否则 +0x90 第 idx 项。
	TriggerRecord *currentRecord();

	// FUN_006f27d4(110B,0022.c:...):当前行下标:
	//   item = +0x68 ->item(row);空 → -1;name = item->data(0x100).toString()
	//   → rowIndexByName(name)。
	int currentRecordIndex(int row) const;

	// FUN_006f2738(155B)名字 → 下标:遍历 +0x90(步长 0x48),逐项比较 +0x10
	//   QString;命中返回下标,否则 -1。
	int rowIndexByName(const QString &name) const;

	// FUN_006f2384(156B)确定键文案切换(+0x78 态):
	//   与 +0x78 相同 → 直返;Ok 按钮(+0x80, 0x400)文案 =
	//   on ? tr("&Next")(0xc9fb14) : tr("&Ok")(0xc9e1cc);+0x78 = on。
	void setNextMode(bool on);

	// FUN_006f60a8(139B)"当前触发器换行"槽(接线里的 selectionModel
	//   currentChanged 腿):
	//   rec = currentRecord();
	//   索引有效(row≥0 && col≥0 && 内部指针非空)→ FUN_006f36be(this)(1608B
	//     提交腿,cited);
	//   rec->+0x24 != 0 → setPageEnabled(true);panes_stackInit(this,
	//     rec->+0x24, rec->+0x20, &rec->+0x28);FUN_006f5b42(this, rec)(1264B
	//     cited);setNextMode(false);
	//   否则 setPageEnabled(false);setNextMode(false)。
	void onTriggerIndexChanged(const QModelIndex &current);

	// FUN_006f2ed8(821B,0022.c:20068)列表项提示框(接线里 itemEntered 腿):
	//   name = item->data(0x100).toString();idx = rowIndexByName(name);
	//   idx == -1 → 返;
	//   name = rec->+0x08;desc = rec->+0x18;
	//   name 非空:desc 空 → 提示 = name;否则按模板逐行拼:
	//     "<tr style=\"white-space: nowrap;\"><td style=\"text-align:right;\">%1: </td><td><b>%2</b></td></tr>"
	//     行标签 tr("Name")(0xc9e6e7)/tr("Description")(0xc8a3a0),
	//     外层 qstring_prepend_utf8("<table>") + append("</table>");
	//   与 item->data(3)(ToolTipRole) 比较,不同才 setData(3, 结果)。
	void updateItemTooltip(class QListWidgetItem *item);

	// FUN_006f6134(415B,0022.c:...)初始装载/刷新列表(ctor 的
	//   QTimer::singleShot(0) 腿,闭包 FUN_006f62db 41B → 本函数):
	//   @006f6134 list->clear();
	//   @006f61xx 全局表取面 FUN_0069d59e(DAT_011c1a60);与 +0x90 不同 →
	//     引用计数换手(旧表经 FUN_006f2d8a 释放);
	//   @006f61xx 逐记录(步长 0x48):+0x21 == 0 跳过;FUN_006f263e(this, rec)
	//     (199B 过滤)返 0 跳过;否则 insertItem(count, …)(实参折叠,cited);
	//   @006f6219 count == 0 → setPageEnabled(false);panes_stackInit(this,
	//     **8**(= HighlightText), 1, &QVariant())(空参);FUN_006f5b42(this,
	//     &+0x98 缺省记录)(1264B,cited);
	//   否则 → setPageEnabled(true);list->setFocus(3);item(0) 非空 →
	//     setCurrentItem(item, 0x13 = ClearAndSelect|Current)。
	void reloadList();

	// FUN_006f5b42(1264B,0022.c:21635)动作下拉模型重建 + 记录装载:
	//   @006f5b75 model = new QStandardItemModel(0x10, 父 = +0x60 视图);
	//   @006f5b9x names = FUN_008086d0(DAT_011c2200)(全局动作名表)→ 头插 "*";
	//   逐名:item = new QStandardItem(0x10, 名);setData(名, 0);按可用性
	//     setEnabled;model->appendRow(item);
	//   connect(model itemChanged → this, 闭包);
	//   @006f5e1x view_connectModelReset(+0x60, model, 1);
	//   @006f5e6x m = FUN_005d68a8(+0x60)->model(),dynamic_cast 到
	//     QStandardItemModel;item(0)->data(0) == "*" → blockSignals(m);
	//     item(0)->setData(tr("all systems")(0xc9fb7d), 0);解除 block;
	//   @006f60xx s_session_uuid_6f571a(&this, rec)(927B 逐字段装载)— cited。
	void rebuildActionModel(struct TriggerRecord *rec);

	// s_session_uuid_6f571a(927B,0022.c:21521)会话范围模型重建(父 = +0x58):
	//   model = new QStandardItemModel(0x10, +0x58);
	//   arr = DAT_011c2200->+0xe0(全局会话表);n = 元素数;
	//   defIcon = FUN_0075727c(DAT_011c1ce0, +0x58)(主题缺省图标);
	//   逐项 i:[uuid = "session.uuid" / icon = "session.icon" 默认空串]
	//     group = s_session_group_805a3e(DAT_011c2200, obj);
	//     label = s_session_label_8062b6(DAT_011c2200, obj, 1);
	//     uuid/label 皆非空才建项:
	//       icon 空 → 用 defIcon;否则 theme_icon_load_svg(icon);
	//       group 非空 → label = "%1 / " .arg(group) + label(头插);
	//       item = QStandardItem(icon, label);item->setData(uuid, 0);
	//       matched = FUN_0069a216(rec, uuid, 1);
	//       FUN_006f7184(item, matched ? 2 : 0)(item 标志位);appendRow;
	//   尾:view_connectModelReset(+0x58, model, 1);FUN_005d688e(+0x58)。
	void rebuildSessionScopeModel(struct TriggerRecord *rec);

	// FUN_006f263e(199B,0022.c:19746)记录 → 列表项:
	//   icon = FUN_006994ca()(缺省图标);
	//   item = new QListWidgetItem(0x30, icon, rec->+0x08 /*名*/, 0, 0);
	//   rec->+0x20 == 0 → FUN_006f2460(this, item, 0)(425B 项外观/态,cited);
	//   item->setData(0x100 /*UserRole*/, rec->+0x10 /*键*/)—— 与
	//   rowIndexByName 用 +0x10 比较互证。
	// s_king__beforeDisconnection_69934c(365B,0021.c:23917)触发器种类图标(名不副实:
	//   Ghidra 取了首个 case 的字面当函数名,实为"kind → 主题图标"):
	//   name 按 kind 取:
	//     1 king::afterConnection / 2 king::afterDisconnection /
	//     3 king::beforeConnection / 4 king::beforeDisconnection /
	//     5 king::customLink / 6 king::customMenu / 8 king::highlightText /
	//     9 king::playSound / 10 king::runCommand / 11 king::sendText /
	//     12 king::showTooltip(7 无 case ⇒ 空名)
	//   active 且名非空 → 追加 "Active"("king::customLinkActive");
	//   → theme_icon_load_svg(名)(= ThemeIcons::loadSvg)。
	//   **与 006f440e 的 kind 语义完全一致 —— 两独立源互证。**
	static QIcon kindIcon(int kind, bool active);

	// FUN_006994ca(21B)记录图标:+0x24 kind / +0x20 active。
	static QIcon recordIcon(const struct TriggerRecord &rec);

	class QListWidgetItem *makeItemForRecord(const struct TriggerRecord &rec);

	// FUN_006f2460(425B,0022.c:20141)列表项禁用外观:
	//   f = item->data(6 /*FontRole*/).value<QFont>()(缺省 QFont);
	//   f.setStrikeOut(on);item->setData(6, QVariant(f));
	//   on == false → item->setData(9 /*ForegroundRole*/,
	//     QBrush(QColor::setNamedColor("Gray")))(.rodata 0xd0d152 = "Gray");
	//   on == true  → setData(9, 空 QVariant)(清除画笔)。
	static void applyItemGrayed(class QListWidgetItem *item, bool on);

	// FUN_006f34dd(259B,0022.c:20259)NameDialog 编辑完成闭包:
	//   which==0 → 释放闭包(0x38);which==1 且 args[1](finished 结果)==1
	//   (Accepted)→ 取对话框输入文本(FUN_006bd94e 18B = QLineEdit::text);
	//   idx = FUN_006f27d4(this, 行);idx != -1 →
	//     rec->+0x08 = 输入名;rec->+0x18 = 描述;
	//   捕获项(+0x30)->setData(0, 输入名)。
	void applyEditedName(class QListWidgetItem *item, int row, const QString &name,
	                     const QString &desc, int result);
	void wire();       // dialog_connectAcceptReject2(006f2852,916B)

	QTabBar *tabBar30() const { return m_tabBar30; }
	QStackedWidget *stack38() const { return m_stack38; }
	QStackedLayout *pageStack40() const { return m_pageStack40; }
	QDialogButtonBox *buttons80() const { return m_buttons80; }
	QMap<int, QWidget *> &pages88() { return m_pages88; } // 页栈缓存

protected:
	void buildTriggerList();   // FUN_006f1c74(257B)
	void buildSettingsTab();   // FUN_006f1f68(182B)
	void buildSessionsTab();   // FUN_006f1d86(425B)

	QTabBar *m_tabBar30 = nullptr;        // +0x30(0x30)
	QStackedWidget *m_stack38 = nullptr;  // +0x38(0x30)
	QStackedLayout *m_pageStack40 = nullptr; // +0x40(0x20,"&Settings" 页容器)
	QWidget *m_sessions48 = nullptr;      // +0x48(new 0x50 + FUN_00535a76)
	QWidget *m_systems50 = nullptr;       // +0x50(同上)
	QWidget *m_f58 = nullptr;             // +0x58(+0x48 件 +0x48,附 "No session available")
	QWidget *m_actionView60 = nullptr;    // +0x60(+0x50 件 +0x48,附 "No system available";
	                                      //   同时是动作模型宿主视图)
	QListWidget *m_triggerList68 = nullptr; // +0x68(new 0x48 + FUN_0055e356(0x143))
	QWidget *m_triggerView70 = nullptr;   // +0x70(+0x68 件 +0x40,附 "No trigger available")
	bool m_f78 = false;                   // +0x78(bool,ctor 清 0)
	QDialogButtonBox *m_buttons80 = nullptr; // +0x80(0x30,flags 0x400400)
	QMap<int, QWidget *> m_pages88;       // +0x88(QMap<int,page*>)
	QList<TriggerRecord> m_records90;     // +0x90(步长 0x48)
	TriggerRecord m_default98;            // +0x98(缺省记录)

	void setPageEnabled(bool on);         // FUN_006f272a(13B)
};
