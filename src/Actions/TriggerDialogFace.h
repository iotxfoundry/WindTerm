#pragma once

#include <QDialog>
#include <QMap>

class QDialogButtonBox;
class QGridLayout;
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
	QWidget *m_f90 = nullptr;             // +0x90(QList 面)
	QWidget *m_f98 = nullptr;             // +0x98(FUN_00698fb2 构造成员)
};
