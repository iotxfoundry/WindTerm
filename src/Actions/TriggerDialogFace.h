#pragma once

#include <QDialog>
#include <QList>
#include <QMap>
#include <QString>

class QDialogButtonBox;
class QGridLayout;
class QModelIndex;
class QLabel;
class QListWidget;
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

	// ---- 记录面(批 349)------------------------------------------------
	// +0x90 QList 元素步长 0x48(006f2d8a 74B 析构循环实测:
	//   逐项 FUN_006f9f0c 后 deallocate(0x48,8));+0x98 = 缺省记录。
	// 字段:+0x10 名字 QString(006f2738 逐项 == 比较)/+0x20 byte(页栈
	//   param_3)/+0x24 int 页 kind(0 = 无页)/+0x28 子结构(页栈 param_4)。
	struct TriggerRecord {          // 总 0x48(与 deallocate(0x48,8) 一致)
		char f00[8] = {};           // +0x00..0x07(未解)
		QString name08;             // +0x08(提示框 "Name" 行,006f2f6x)
		QString key10;              // +0x10(006f2738 逐项 == 的键)
		QString desc18;             // +0x18(提示框 "Description" 行 + 编辑框回填)
		char f20 = 0;               // +0x20(页栈 param_3)
		int kind24 = 0;             // +0x24(页 kind;0 = 无页)
		char f28[0x48 - 0x28] = {}; // +0x28..0x47(页栈 param_4 的宿主)
	};

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
	QWidget *m_f60 = nullptr;             // +0x60(+0x50 件 +0x48,附 "No system available")
	QListWidget *m_triggerList68 = nullptr; // +0x68(new 0x48 + FUN_0055e356(0x143))
	QWidget *m_triggerView70 = nullptr;   // +0x70(+0x68 件 +0x40,附 "No trigger available")
	bool m_f78 = false;                   // +0x78(bool,ctor 清 0)
	QDialogButtonBox *m_buttons80 = nullptr; // +0x80(0x30,flags 0x400400)
	QMap<int, QWidget *> m_pages88;       // +0x88(QMap<int,page*>)
	QList<TriggerRecord> m_records90;     // +0x90(步长 0x48)
	TriggerRecord m_default98;            // +0x98(缺省记录)

	void setPageEnabled(bool on);         // FUN_006f272a(13B)
};
